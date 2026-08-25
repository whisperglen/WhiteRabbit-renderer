
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <intrin.h>
#include <detours.h>
#include "alice_renderer_api.h"

extern "C" void* __cdecl GetRefAPI(int apiVersion, void* imports);
extern "C" void GLW_GetValidModes();
extern "C" void GLW_GetValidModes_Override();
extern "C" void RB_StageIteratorSky();
extern "C" void R_Sky_Reset();
extern "C" void R_Sky_AddSurf();
extern "C" void R_Sky_Render();
extern "C" int SurfIsOffscreen();
extern "C" void RendererInitSkyPortalOptions(void);

extern "C" refimport_t ri;

static void logInit();
static void logClose();
extern "C" void RendererLogPrintf(const char* fmt, ...);
int hook_unprotect(void* ptr, int size, unsigned long* restore);
int hook_protect(void* ptr, int size, unsigned long restore);

/*
 * Keep the renderer's original GetRefAPI as the call target, but interpose the
 * import table immediately afterwards.  This lets the BSP read probe observe
 * the exact bytes that the renderer later gives to ParseFace.
 */
typedef void* (__cdecl *GetRefAPIFn)(int apiVersion, void* imports);
static GetRefAPIFn s_originalGetRefAPI = GetRefAPI;

static void* __cdecl GetRefAPI_ImportTraceHook(int apiVersion, void* imports)
{
    void* exports = s_originalGetRefAPI(apiVersion, imports);
    /* Created after the import table becomes valid; see sky portal hook. */
    RendererInitSkyPortalOptions();
    return exports;
}

/*
 * The remaster only recognizes ` and ~ as console keys. VorpalFix solves
 * that by observing the bind command and replacing its hard-coded key tests
 * with the key that was actually bound. Keep this one patch local to the
 * renderer DLL, so VorpalFix itself does not need to be loaded.
 */
static const uintptr_t EXE_KEY_STRING_TO_KEYNUM = 0x004076F0;
static const uintptr_t EXE_KEY_SET_BINDING = 0x00407870;
static const uintptr_t EXE_CONSOLE_KEY_CHECK = 0x0040823A;
static const int DEFAULT_CONSOLE_KEY_GRAVE = 96;
static const int DEFAULT_CONSOLE_KEY_TILDE = 126;

typedef int (__cdecl *KeySetBindingFn)(int keyId, char* command);
typedef int (__cdecl *KeyStringToKeynumFn)(const char* keyName);

static KeySetBindingFn s_originalKeySetBinding =
    (KeySetBindingFn)EXE_KEY_SET_BINDING;
static bool s_consoleBindHooked = false;
static bool s_consoleKeyCheckPatched = false;
static byte s_originalConsoleKeyCheck[12];

static bool patch_console_key_check(int keyId)
{
    byte* code = (byte*)EXE_CONSOLE_KEY_CHECK;
    const byte compareRegisterWithImmediate[] = { 0x81, 0xFF };
    unsigned long restore;

    if (!s_consoleKeyCheckPatched)
        memcpy(s_originalConsoleKeyCheck, code, sizeof(s_originalConsoleKeyCheck));

    if (!hook_unprotect(code, (int)sizeof(s_originalConsoleKeyCheck), &restore))
        return false;

    /* cmp edi, keyId; nop the old second key comparison (VorpalFix patch). */
    memcpy(code, compareRegisterWithImmediate, sizeof(compareRegisterWithImmediate));
    memcpy(code + 2, &keyId, sizeof(keyId));
    memset(code + 6, 0x90, 6);
    FlushInstructionCache(GetCurrentProcess(), code, sizeof(s_originalConsoleKeyCheck));
    hook_protect(code, (int)sizeof(s_originalConsoleKeyCheck), restore);

    s_consoleKeyCheckPatched = true;
    RendererLogPrintf("Developer console enabled on key id %d\n", keyId);
    return true;
}

static int __cdecl KeySetBinding_ConsoleHook(int keyId, char* command)
{
    if (command && strcmp(command, "toggleconsole") == 0)
    {
        if (keyId == DEFAULT_CONSOLE_KEY_GRAVE || keyId == DEFAULT_CONSOLE_KEY_TILDE)
        {
            KeyStringToKeynumFn keyStringToKeynum =
                (KeyStringToKeynumFn)EXE_KEY_STRING_TO_KEYNUM;
            keyId = keyStringToKeynum("F2");
            RendererLogPrintf("Console default key remapped to F2 (key id %d)\n", keyId);
        }

        patch_console_key_check(keyId);
    }

    return s_originalKeySetBinding(keyId, command);
}

static void install_console_fix()
{
    LONG status;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalKeySetBinding,
                              KeySetBinding_ConsoleHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_consoleBindHooked = true;
        RendererLogPrintf("Developer console bind hook installed at %p\n",
                          (void*)EXE_KEY_SET_BINDING);
    }
    else
    {
        RendererLogPrintf("WARN: failed to install developer console bind hook: %ld\n",
                          status);
    }
}

static void uninstall_console_fix()
{
    LONG status;
    unsigned long restore;
    byte* code = (byte*)EXE_CONSOLE_KEY_CHECK;

    if (s_consoleBindHooked)
    {
        status = DetourTransactionBegin();
        if (status == NO_ERROR)
            status = DetourUpdateThread(GetCurrentThread());
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalKeySetBinding,
                                  KeySetBinding_ConsoleHook);
        if (status == NO_ERROR)
            status = DetourTransactionCommit();
        else
            DetourTransactionAbort();

        if (status != NO_ERROR)
            RendererLogPrintf("WARN: failed to remove developer console bind hook: %ld\n",
                              status);
        s_consoleBindHooked = false;
    }

    if (s_consoleKeyCheckPatched &&
        hook_unprotect(code, (int)sizeof(s_originalConsoleKeyCheck), &restore))
    {
        memcpy(code, s_originalConsoleKeyCheck, sizeof(s_originalConsoleKeyCheck));
        FlushInstructionCache(GetCurrentProcess(), code, sizeof(s_originalConsoleKeyCheck));
        hook_protect(code, (int)sizeof(s_originalConsoleKeyCheck), restore);
        s_consoleKeyCheckPatched = false;
    }
}

/*
 * Ritual's sky portal is independent of RB_StageIteratorSky.  A world sky
 * surface is redirected to R_Sky_AddSurf, then R_Sky_Render creates the
 * portal view only if at least one collected surface is on screen.  Counting
 * those hand-offs identifies the exact early-out without guessing at the
 * private tr.portalsky layout.
 */
typedef void (__cdecl *RSkyResetFn)();
typedef void (__cdecl *RSkyAddSurfFn)(void* surface);
typedef void (__cdecl *RSkyRenderFn)();
typedef int (__cdecl *SurfIsOffscreenFn)(const void* surface, void* shader,
                                         int entityNum);
/* cvar_t::integer is at 0x20 in Alice's 32-bit game ABI. */
typedef struct renderer_cvar_s {
    byte reserved[0x20];
    int integer;
} renderer_cvar_t;

static RSkyResetFn s_originalRSkyReset = R_Sky_Reset;
static RSkyAddSurfFn s_originalRSkyAddSurf = (RSkyAddSurfFn)R_Sky_AddSurf;
static RSkyRenderFn s_originalRSkyRender = R_Sky_Render;
static SurfIsOffscreenFn s_originalSurfIsOffscreen =
    (SurfIsOffscreenFn)SurfIsOffscreen;
static const uintptr_t s_rSkyRenderAddress = (uintptr_t)R_Sky_Render;
static bool s_skyPortalTraceHooked = false;
static unsigned int s_skyPortalSurfaceCount = 0;
static int s_lastSkyPortalSurfaceCount = -1;
static int s_lastSkyPortalReportTime = -0x3fffffff;
static unsigned int s_skyRenderDepth = 0;
static bool s_skyPortalViewInvoked = false;
static bool s_insideSkyPortalRender = false;
static renderer_cvar_t* s_forceSkyPortal = nullptr;
static unsigned int s_forcedSkyPortalTraceCount = 0;

extern "C" void RendererInitSkyPortalOptions(void)
{
    if (!s_forceSkyPortal && ri.Cvar_Get)
    {
        s_forceSkyPortal = (renderer_cvar_t*)ri.Cvar_Get(
            "r_forceSkyPortal", "1", 1 /* CVAR_ARCHIVE */);
        RendererLogPrintf("r_forceSkyPortal initialized to %d\n",
                          s_forceSkyPortal ? s_forceSkyPortal->integer : -1);
    }
}

static int __cdecl SurfIsOffscreen_SkyPortalHook(const void* surface,
                                                 void* shader, int entityNum)
{
    const int originalResult = s_originalSurfIsOffscreen(surface, shader, entityNum);

    /*
     * R_Sky_Render uses ENTITYNUM_WORLD (1022) solely as a gate before it
     * launches its separate sky-portal view.  Forcing only this call preserves
     * all normal mirror/portal culling and still lets Alice render the genuine
     * portal world from its authored sky origin.
     */
    const uintptr_t caller = (uintptr_t)_ReturnAddress();
    const bool calledBySkyPortalGate =
        caller >= s_rSkyRenderAddress && caller < s_rSkyRenderAddress + 0x1000;

    if (calledBySkyPortalGate && s_forceSkyPortal && s_forceSkyPortal->integer &&
        entityNum == 1022)
    {
        return 0;
    }

    return originalResult;
}

static void install_sky_portal_trace()
{
    LONG status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalSurfIsOffscreen,
                              SurfIsOffscreen_SkyPortalHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_skyPortalTraceHooked = true;
        RendererLogPrintf("Sky portal trace installed\n");
    }
    else
        RendererLogPrintf("WARN: failed to install sky portal trace: %ld\n", status);
}

static void uninstall_sky_portal_trace()
{
    LONG status;

    if (!s_skyPortalTraceHooked)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalSurfIsOffscreen,
                              SurfIsOffscreen_SkyPortalHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove sky portal trace: %ld\n", status);
    s_skyPortalTraceHooked = false;
}

int hook_unprotect(void* ptr, int size, unsigned long* restore)
{
    DWORD error;
    DWORD dwOld = 0;
    if (!VirtualProtect(ptr, size, PAGE_EXECUTE_READWRITE, &dwOld)) {
        error = GetLastError();
        RendererLogPrintf("VirtualProtect failed RW for %p with 0x%x\n", ptr, error);
        return FALSE;
    }
    if (restore)
        *restore = dwOld;

    return TRUE;
}

int hook_protect(void* ptr, int size, unsigned long restore)
{
    DWORD error;
    DWORD dwOld = 0;
    if (!VirtualProtect(ptr, size, restore, &dwOld)) {
        error = GetLastError();
        RendererLogPrintf("VirtualProtect failed op:%x for %p with 0x%x\n", restore, ptr, error);
        return FALSE;
    }
    return TRUE;
}

static void install_getrefapi()
{
    //0040a145: e8 f6 50 06 00
    byte* code = (byte*)0x0040a145;
    if (code[0] == 0xe8)
    {
        intptr_t fnoff = 0x000650f6;
        if (!memcmp(&code[1], &fnoff, sizeof(fnoff)))
        {
            fnoff = (intptr_t)GetRefAPI_ImportTraceHook - (intptr_t)(&code[5]);

            unsigned long restore;
            if (hook_unprotect(code, 5, &restore))
            {
                memcpy(&code[1], &fnoff, sizeof(fnoff));
                hook_protect(code, 5, restore);
            }
        }
        else RendererLogPrintf("WARN: call offset mismatch %x %x %x %x\n", code[1], code[2], code[3], code[4]);
    }
    else RendererLogPrintf("WARN: call code mismatch %x\n", code[0]);
}

static void uninstall_getrefapi()
{
    //0040a145: e8 f6 50 06 00
    byte* code = (byte*)0x0040a145;
    if (code[0] == 0xe8)
    {
        intptr_t fnoff = 0x000650f6;
        unsigned long restore;
        if (hook_unprotect(code, 5, &restore))
        {
            memcpy(&code[1], &fnoff, sizeof(fnoff));
            hook_protect(code, 5, restore);
        }
    }
}

static byte s_originalGLWGetValidModes[5];
static bool s_glwGetValidModesHooked = false;
static byte* s_glwGetValidModesTarget = nullptr;

/*
 * Debug builds resolve static-library functions through an ILT entry.  That
 * entry is an E9 jump by design, so patch the implementation it reaches
 * rather than mistaking the linker thunk for a pre-existing hook.
 */
static byte* resolve_local_jump(byte* code, const char* name)
{
    for (int hop = 0; hop != 4 && code[0] == 0xe9; ++hop)
    {
        int32_t offset;
        byte* target;

        memcpy(&offset, &code[1], sizeof(offset));
        target = &code[5] + offset;
        RendererLogPrintf("%s: following E9 thunk %p -> %p\n", name, code, target);

        if (target == (byte*)GLW_GetValidModes_Override)
        {
            RendererLogPrintf("%s is already detoured\n", name);
            return nullptr;
        }

        code = target;
    }

    if (code[0] == 0xe9)
    {
        RendererLogPrintf("WARN: %s jump chain is too deep\n", name);
        return nullptr;
    }

    return code;
}

/*
 * renderer.lib keeps GLW_GetValidModes in the same object as GLimp_Init, so
 * defining a second linker symbol produces LNK2005. Detouring the resolved
 * library function retains its globals while allowing src/win_glimp.c to
 * supply the implementation.
 */
static void install_glw_getvalidmodes()
{
    byte* code = resolve_local_jump((byte*)GLW_GetValidModes, "GLW_GetValidModes");
    int32_t offset;
    unsigned long restore;

    if (!code)
        return;

    offset = (int32_t)((intptr_t)GLW_GetValidModes_Override - (intptr_t)(&code[5]));

    if (!hook_unprotect(code, 5, &restore))
        return;

    memcpy(s_originalGLWGetValidModes, code, sizeof(s_originalGLWGetValidModes));
    code[0] = 0xe9;
    memcpy(&code[1], &offset, sizeof(offset));
    hook_protect(code, 5, restore);
    s_glwGetValidModesTarget = code;
    s_glwGetValidModesHooked = true;
    RendererLogPrintf("GLW_GetValidModes detoured %p -> %p\n", code,
                      (void*)GLW_GetValidModes_Override);
}

static void uninstall_glw_getvalidmodes()
{
    unsigned long restore;

    if (!s_glwGetValidModesHooked || !s_glwGetValidModesTarget ||
        !hook_unprotect(s_glwGetValidModesTarget, 5, &restore))
        return;

    memcpy(s_glwGetValidModesTarget, s_originalGLWGetValidModes, sizeof(s_originalGLWGetValidModes));
    hook_protect(s_glwGetValidModesTarget, 5, restore);
    s_glwGetValidModesTarget = nullptr;
    s_glwGetValidModesHooked = false;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID )
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        logInit();
        install_console_fix();
        install_sky_portal_trace();
        install_glw_getvalidmodes();
        install_getrefapi();
        break;
    case DLL_PROCESS_DETACH:
        uninstall_glw_getvalidmodes();
        uninstall_getrefapi();
        uninstall_sky_portal_trace();
        uninstall_console_fix();
        logClose();
        break;
    default:
        break;
    }
    return TRUE;
}

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

static FILE* g_fpLog = nullptr;
static const char s_szLogFileName[] = TOSTRING(PROJECT_NAME) ".log";
static char* log_string = nullptr;
static const size_t c_LogStringSize = 8192; //8 kbytes

// Define 10 MB in bytes
#define MAX_LOG_SIZE (10 * 1024 * 1024) 

// Helper function to get the current file size
static long get_file_size(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        // File doesn't exist yet, or we don't have permission to read it.
        // Returning 0 ensures we will create it using append mode later.
        return 0;
    }

    // Jump to the end of the file
    fseek(fp, 0, SEEK_END);

    // Get the current byte offset (which equals the file size)
    long size = ftell(fp);

    fclose(fp);
    return size;
}

static void logInit()
{
    if (g_fpLog)
        return;

    if (!log_string)
    {
        log_string = (char*)malloc(c_LogStringSize);
    }
    if (!log_string) return;

    log_string[c_LogStringSize - 1] = 0;

    // Check the current size of the log file
    long current_size = get_file_size(s_szLogFileName);

    // Determine the correct file mode
    // If it's 10MB or larger, use "w" (overwrite). Otherwise, use "a" (append).
    const char* mode = (current_size >= MAX_LOG_SIZE) ? "w" : "a";

    if (fopen_s(&g_fpLog, s_szLogFileName, mode))
        return;

    char timeBuf[64];
    time_t t;
    memset(&t, 0, sizeof(t));
    time(&t);
    memset(timeBuf, 0, sizeof(timeBuf));
    ctime_s(timeBuf, sizeof(timeBuf), &t);

    fprintf(g_fpLog, "=======================================================================\n");
    fprintf(g_fpLog, " " TOSTRING(PROJECT_NAME) " initialized at %s", timeBuf);
    fprintf(g_fpLog, "=======================================================================\n");

    fprintf(g_fpLog, "\n");
    fflush(g_fpLog);
}

static void logClose()
{
    if (g_fpLog) {
        time_t t;
        memset(&t, 0, sizeof(t));
        time(&t);
        char timeBuf[64];
        memset(timeBuf, 0, sizeof(timeBuf));
        ctime_s(timeBuf, sizeof(timeBuf), &t);

        fprintf(g_fpLog, "=======================================================================\n");
        fprintf(g_fpLog, " " TOSTRING(PROJECT_NAME) " shutdown at %s", timeBuf);
        fprintf(g_fpLog, "=======================================================================\n");

        fclose(g_fpLog);
        g_fpLog = NULL;
    }

    if (log_string)
    {
        free(log_string);
        log_string = NULL;
    }
}

extern "C" void RendererLogPrintf(const char* fmt, ...)
{
    if (!g_fpLog)
        return;

    va_list argptr;
    va_start(argptr, fmt);
    _vsnprintf_s(log_string, c_LogStringSize, c_LogStringSize - 2, fmt, argptr);
    va_end(argptr);

    fprintf(g_fpLog, "%s", log_string);
    fflush(g_fpLog);
}
