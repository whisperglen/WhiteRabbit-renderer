
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>

extern "C" void* GetRefAPI();

static void logInit();
static void logClose();
void logPrintf(const char* fmt, ...);

int hook_unprotect(void* ptr, int size, unsigned long* restore)
{
    DWORD error;
    DWORD dwOld = 0;
    if (!VirtualProtect(ptr, size, PAGE_EXECUTE_READWRITE, &dwOld)) {
        error = GetLastError();
        logPrintf("VirtualProtect failed RW for %p with 0x%x\n", ptr, error);
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
        logPrintf("VirtualProtect failed op:%x for %p with 0x%x\n", restore, ptr, error);
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
            fnoff = (intptr_t)GetRefAPI - (intptr_t)(&code[5]);

            unsigned long restore;
            if (hook_unprotect(code, 5, &restore))
            {
                memcpy(&code[1], &fnoff, sizeof(fnoff));
                hook_protect(code, 5, restore);
            }
        }
        else logPrintf("WARN: call offset mismatch %x %x %x %x\n", code[1], code[2], code[3], code[4]);
    }
    else logPrintf("WARN: call code mismatch %x\n", code[0]);
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

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID )
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        logInit();
        install_getrefapi();
        break;
    case DLL_PROCESS_DETACH:
        uninstall_getrefapi();
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

void logPrintf(const char* fmt, ...)
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