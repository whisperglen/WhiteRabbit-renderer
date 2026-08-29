
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <intrin.h>
#include <detours.h>
#include "alice_renderer_api.h"

extern "C" refimport_t ri;

extern "C" void* __cdecl GetRefAPI(int apiVersion, void* imports);
extern "C" void GLW_GetValidModes();
extern "C" void GLW_GetValidModes_Override();
extern "C" void RB_StageIteratorSky();
extern "C" void R_Sky_Reset();
extern "C" void R_Sky_AddSurf();
extern "C" void R_Sky_Render();
extern "C" int SurfIsOffscreen();
extern "C" void R_SepiaScreenShot();
extern "C" void RendererInitSkyPortalOptions(void);
extern "C" int __cdecl VertexLightingModeHook(void);
extern "C" void __cdecl RendererInitVertexLightingModeHook(
    void* unfoggedStages, void* shader, void* rVertexLightSlot,
    void* originalVertexLightingCollapse);
extern "C" void __cdecl RendererShutdownVertexLightingModeHook(void);

/* Game EXE allocator; recovered from the Z_Free error-string xref. */
static const uintptr_t EXE_Z_FREE = 0x0041E000;

typedef void (APIENTRY *QglPixelStoreiFn)(unsigned int pname, int param);
extern "C" QglPixelStoreiFn qglPixelStorei;

static void logInit();
static void logClose();
extern "C" void RendererLogPrintf(const char* fmt, ...);
int hook_unprotect(void* ptr, int size, unsigned long* restore);
int hook_protect(void* ptr, int size, unsigned long restore);

static HMODULE s_rendererModule = nullptr;

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
 * R_SepiaScreenShot allocates exactly width * height * 3 bytes, then calls
 * glReadPixels(GL_RGB).  With GL_PACK_ALIGNMENT at its default 4, widths not
 * divisible by four acquire 1-3 padding bytes per row.  At 1366x768 that is
 * 1,536 bytes beyond the allocation, corrupting the game Z_Free trailer when
 * a save thumbnail is made.  Read the pixels tightly packed for this one
 * path; the sepia conversion already expects a contiguous RGB buffer.
 */
typedef void (__cdecl *RSepiaScreenShotFn)(void* filename, int width, int height);
static RSepiaScreenShotFn s_originalRSepiaScreenShot =
    (RSepiaScreenShotFn)R_SepiaScreenShot;
static bool s_sepiaScreenshotFixHooked = false;
static const unsigned int GL_PACK_ALIGNMENT = 0x0D05;

static void __cdecl RSepiaScreenShot_PackAlignmentHook(void* filename,
                                                        int width, int height)
{
    QglPixelStoreiFn pixelStorei = qglPixelStorei;
    if (pixelStorei)
        pixelStorei(GL_PACK_ALIGNMENT, 1);

    s_originalRSepiaScreenShot(filename, width, height);

    /* Alice otherwise relies on OpenGL's default packing state. */
    if (pixelStorei)
        pixelStorei(GL_PACK_ALIGNMENT, 4);
}

static void install_sepia_screenshot_fix()
{
    LONG status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRSepiaScreenShot,
                              RSepiaScreenShot_PackAlignmentHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_sepiaScreenshotFixHooked = true;
        RendererLogPrintf("Save-thumbnail GL_PACK_ALIGNMENT fix installed\n");
    }
    else
        RendererLogPrintf("WARN: failed to install save-thumbnail fix: %ld\n", status);
}

static void uninstall_sepia_screenshot_fix()
{
    if (!s_sepiaScreenshotFixHooked)
        return;

    LONG status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRSepiaScreenShot,
                              RSepiaScreenShot_PackAlignmentHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove save-thumbnail fix: %ld\n", status);
    s_sepiaScreenshotFixHooked = false;
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

/*
 * FinishShader knows that renderer.lib's original VertexLightingCollapse
 * always leaves exactly one stage.  MSVC consequently emits `mov edi, 1`
 * after its call and jumps over CollapseMultitexture.  r_vertexLight 2 keeps
 * several non-lightmap stages, so replace that one call-site sequence rather
 * than detouring the collapse function globally.
 */
static byte* s_vertexLightingCallSite = nullptr;
static byte s_originalVertexLightingCallSite[14];
static bool s_vertexLightingModeHooked = false;

static bool address_in_renderer_image(const void* address)
{
    const byte* image = (const byte*)s_rendererModule;
    const IMAGE_DOS_HEADER* dos;
    const IMAGE_NT_HEADERS* nt;
    const byte* ptr = (const byte*)address;

    if (!image || !address)
        return false;

    dos = (const IMAGE_DOS_HEADER*)image;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE)
        return false;

    nt = (const IMAGE_NT_HEADERS*)(image + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE)
        return false;

    return ptr >= image && ptr < image + nt->OptionalHeader.SizeOfImage;
}

static byte* find_vertex_lighting_finishshader_call()
{
    const byte* image = (const byte*)s_rendererModule;
    const IMAGE_DOS_HEADER* dos;
    const IMAGE_NT_HEADERS* nt;
    size_t imageSize;
    size_t offset;

    if (!image)
        return nullptr;

    dos = (const IMAGE_DOS_HEADER*)image;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE)
        return nullptr;

    nt = (const IMAGE_NT_HEADERS*)(image + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE)
        return nullptr;

    imageSize = nt->OptionalHeader.SizeOfImage;
    for (offset = 0x15; offset + 40 <= imageSize; ++offset)
    {
        byte* code = (byte*)image + offset;

        /* call; mov edi,1; xor ebp,ebp; jmp; then CollapseMultitexture */
        if (code[0] != 0xe8 ||
            code[5] != 0xbf || code[6] != 1 || code[7] != 0 ||
            code[8] != 0 || code[9] != 0 ||
            code[10] != 0x33 || code[11] != 0xed ||
            code[12] != 0xeb || code[13] != 0x1a ||
            code[14] != 0x83 || code[15] != 0x3d || code[20] != 0 ||
            code[21] != 0x74 || code[22] != 0x11 ||
            code[23] != 0x8d || code[24] != 0x44 ||
            code[25] != 0x24 || code[26] != 0x10 || code[27] != 0x50 ||
            code[28] != 0xe8 ||
            code[33] != 0x8b || code[34] != 0x7c ||
            code[35] != 0x24 || code[36] != 0x14 ||
            code[37] != 0x83 || code[38] != 0xc4 || code[39] != 0x04 ||
            code[-21] != 0x8b || code[-20] != 0x15 ||
            code[-15] != 0x83 || code[-14] != 0x7a ||
            code[-13] != 0x20 || code[-12] != 0 ||
            code[-11] != 0x75 || code[-10] != 0x09)
        {
            continue;
        }

        return code;
    }

    return nullptr;
}

static void install_vertex_lighting_mode_hook()
{
    byte* callSite = find_vertex_lighting_finishshader_call();
    int32_t originalCallOffset;
    int32_t hookCallOffset;
    byte* originalCollapse;
    uint32_t shaderAddress;
    uint32_t stagesAddress;
    uint32_t vertexLightSlotAddress;
    unsigned long restore;
    static const byte continuationPatch[9] = {
        0x89, 0x44, 0x24, 0x10, /* mov [esp+10h], eax */
        0x89, 0xc7,             /* mov edi, eax */
        0x33, 0xed,             /* xor ebp, ebp */
        0x90                    /* fall through to CollapseMultitexture */
    };

    if (!callSite)
    {
        RendererLogPrintf("WARN: FinishShader vertex-light call site not found\n");
        return;
    }

    memcpy(&originalCallOffset, &callSite[1], sizeof(originalCallOffset));
    originalCollapse = callSite + 5 + originalCallOffset;
    if (!address_in_renderer_image(originalCollapse) ||
        originalCollapse[0] != 0xd9 || originalCollapse[1] != 0x05 ||
        originalCollapse[6] != 0x56 ||
        originalCollapse[7] != 0xd8 || originalCollapse[8] != 0x1d ||
        originalCollapse[13] != 0x57 || originalCollapse[14] != 0xdf ||
        originalCollapse[15] != 0xe0 || originalCollapse[16] != 0xf6 ||
        originalCollapse[17] != 0xc4 || originalCollapse[18] != 0x44 ||
        originalCollapse[0x1b] != 0xbb)
    {
        RendererLogPrintf("WARN: FinishShader collapse target signature mismatch at %p\n",
                          originalCollapse);
        return;
    }

    /* fcomp [_shader+4c], mov ebx, offset _unfoggedStages. */
    memcpy(&shaderAddress, &originalCollapse[9], sizeof(shaderAddress));
    shaderAddress -= 0x4c;
    memcpy(&stagesAddress, &originalCollapse[0x1c], sizeof(stagesAddress));
    memcpy(&vertexLightSlotAddress, &callSite[-19], sizeof(vertexLightSlotAddress));

    if (!address_in_renderer_image((void*)(uintptr_t)shaderAddress) ||
        !address_in_renderer_image((void*)(uintptr_t)stagesAddress) ||
        !address_in_renderer_image((void*)(uintptr_t)vertexLightSlotAddress))
    {
        RendererLogPrintf("WARN: FinishShader recovered state lies outside renderer image\n");
        return;
    }

    hookCallOffset = (int32_t)((intptr_t)VertexLightingModeHook -
                               (intptr_t)(callSite + 5));
    if (!hook_unprotect(callSite, (int)sizeof(s_originalVertexLightingCallSite),
                        &restore))
    {
        return;
    }

    memcpy(s_originalVertexLightingCallSite, callSite,
           sizeof(s_originalVertexLightingCallSite));
    memcpy(&callSite[1], &hookCallOffset, sizeof(hookCallOffset));
    memcpy(&callSite[5], continuationPatch, sizeof(continuationPatch));
    FlushInstructionCache(GetCurrentProcess(), callSite,
                          sizeof(s_originalVertexLightingCallSite));
    hook_protect(callSite, (int)sizeof(s_originalVertexLightingCallSite), restore);

    RendererInitVertexLightingModeHook((void*)(uintptr_t)stagesAddress,
                                       (void*)(uintptr_t)shaderAddress,
                                       (void*)(uintptr_t)vertexLightSlotAddress,
                                       originalCollapse);
    s_vertexLightingCallSite = callSite;
    s_vertexLightingModeHooked = true;
    RendererLogPrintf("r_vertexLight 2 hook installed at %p; collapse %p, stages %p, shader %p\n",
                      callSite, originalCollapse, (void*)(uintptr_t)stagesAddress,
                      (void*)(uintptr_t)shaderAddress);
}

static void uninstall_vertex_lighting_mode_hook()
{
    unsigned long restore;

    if (s_vertexLightingModeHooked && s_vertexLightingCallSite &&
        hook_unprotect(s_vertexLightingCallSite,
                       (int)sizeof(s_originalVertexLightingCallSite), &restore))
    {
        memcpy(s_vertexLightingCallSite, s_originalVertexLightingCallSite,
               sizeof(s_originalVertexLightingCallSite));
        FlushInstructionCache(GetCurrentProcess(), s_vertexLightingCallSite,
                              sizeof(s_originalVertexLightingCallSite));
        hook_protect(s_vertexLightingCallSite,
                     (int)sizeof(s_originalVertexLightingCallSite), restore);
    }

    RendererShutdownVertexLightingModeHook();
    s_vertexLightingCallSite = nullptr;
    s_vertexLightingModeHooked = false;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID )
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        s_rendererModule = hModule;
        logInit();
        install_sepia_screenshot_fix();
        install_console_fix();
        install_sky_portal_trace();
        install_glw_getvalidmodes();
        install_vertex_lighting_mode_hook();
        install_getrefapi();
        break;
    case DLL_PROCESS_DETACH:
        uninstall_vertex_lighting_mode_hook();
        uninstall_glw_getvalidmodes();
        uninstall_getrefapi();
        uninstall_sky_portal_trace();
        uninstall_console_fix();
        uninstall_sepia_screenshot_fix();
        logClose();
        s_rendererModule = nullptr;
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
