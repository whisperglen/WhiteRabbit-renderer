#include <Windows.h>

/*
 * These are defined by renderer.lib.  The original renderer code treats the
 * display-mode storage as global renderer state, so this replacement must
 * retain that storage rather than allocate a second copy in the DLL.
 */
#define MAX_DEVICE_MODES 1024

extern int g_NumDeviceModes;
extern int g_NumValidRes;
extern DEVMODEA g_DeviceModes[MAX_DEVICE_MODES];
extern int g_ValidResolutions[MAX_DEVICE_MODES][2];

/*
 * The HD executable's menu code reads its former in-process renderer data
 * directly.  Keep that view synchronized with renderer.lib's authoritative
 * display-mode list.
 *
 * These addresses apply to the supported Alice.exe build, the same build
 * already assumed by symbols.asm and the GetRefAPI detour.
 */
#define EXE_NUM_DEVICE_MODES_ADDR 0x007D40C4u
#define EXE_NUM_VALID_RES_ADDR    0x007D40C8u
#define EXE_VALID_RES_ADDR        0x01C1D2E0u

static void GLW_MirrorValidModesToExe(void)
{
    int i;
    int validCount = g_NumValidRes;
    volatile int* const exeNumDeviceModes = (volatile int*)EXE_NUM_DEVICE_MODES_ADDR;
    volatile int* const exeNumValidRes = (volatile int*)EXE_NUM_VALID_RES_ADDR;
    volatile int* const exeValidResolutions = (volatile int*)EXE_VALID_RES_ADDR;

    if (validCount < 0)
        validCount = 0;
    else if (validCount > MAX_DEVICE_MODES)
        validCount = MAX_DEVICE_MODES;

    *exeNumDeviceModes = g_NumDeviceModes;
    *exeNumValidRes = validCount;

    for (i = 0; i < validCount; ++i)
    {
        exeValidResolutions[i * 2] = g_ValidResolutions[i][0];
        exeValidResolutions[i * 2 + 1] = g_ValidResolutions[i][1];
    }
}

/*
 * Runtime replacement for renderer.lib's GLW_GetValidModes implementation.
 * It is reached through the small in-DLL detour installed in _dllmain.cpp.
 * The Ghidra export has the same algorithm, but its EnumDisplaySettingsA
 * prototype was not recovered correctly.  Using DEVMODEA preserves the
 * original 0x9c-byte records on Win32 while making the API calls type-correct.
 */
void GLW_GetValidModes_Override(void)
{
    int modeIndex;
    int validIndex;

    /* Make enumeration safe when a video restart invokes it more than once. */
    g_NumDeviceModes = 0;
    g_NumValidRes = 0;

    for (modeIndex = 0; modeIndex < MAX_DEVICE_MODES; ++modeIndex)
    {
        DEVMODEA mode = { 0 };

        mode.dmSize = sizeof(mode);
        if (!EnumDisplaySettingsA(NULL, modeIndex, &mode))
            break;

        g_DeviceModes[g_NumDeviceModes++] = mode;

        if (mode.dmPelsWidth < 640 || mode.dmPelsHeight < 480)
            continue;

        for (validIndex = 0; validIndex < g_NumValidRes; ++validIndex)
        {
            if (g_ValidResolutions[validIndex][0] == (int)mode.dmPelsWidth &&
                g_ValidResolutions[validIndex][1] == (int)mode.dmPelsHeight)
            {
                break;
            }
        }

        if (validIndex == g_NumValidRes)
        {
            g_ValidResolutions[validIndex][0] = (int)mode.dmPelsWidth;
            g_ValidResolutions[validIndex][1] = (int)mode.dmPelsHeight;
            ++g_NumValidRes;
        }
    }

    GLW_MirrorValidModesToExe();
}
