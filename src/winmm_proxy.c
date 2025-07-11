
#include <Windows.h>
#include <tchar.h>

static HMODULE g_winmm_h = NULL;

static void ensure_load_dll()
{
    if ( g_winmm_h == NULL )
    {
        g_winmm_h = LoadLibraryEx(_T(".\\winmm.dll"), NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    }
}

#define ENSURE_LOAD_FUNC() \
    static void* indir = NULL; \
    if( !indir ) \
    { \
        ensure_load_dll(); \
        indir = GetProcAddress( g_winmm_h, __func__ ); \
    }


MMRESULT
WINAPI
timeBeginPeriod(
    _In_ UINT uPeriod
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(UINT))indir)(uPeriod);
}

MMRESULT
WINAPI
timeEndPeriod(
    _In_ UINT uPeriod
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(UINT))indir)(uPeriod);
}

DWORD
WINAPI
timeGetTime(
    void
)
{
    ENSURE_LOAD_FUNC();
    return ((DWORD (WINAPI *)(void))indir)();
}

MMRESULT
WINAPI
joyGetDevCapsA(
    _In_ UINT_PTR uJoyID,
    _Out_writes_bytes_( cbjc ) LPJOYCAPSA pjc,
    _In_ UINT cbjc
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(UINT_PTR,LPJOYCAPSA,UINT))indir)(uJoyID, pjc, cbjc);
}

UINT
WINAPI
joyGetNumDevs(
    void
)
{
    ENSURE_LOAD_FUNC();
    return ((UINT (WINAPI *)(void))indir)();
}

MMRESULT
WINAPI
joyGetPosEx(
    _In_ UINT uJoyID,
    _Out_ LPJOYINFOEX pji
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(UINT,LPJOYINFOEX))indir)(uJoyID,pji);
}

MMRESULT
WINAPI
midiInClose(
    _In_ HMIDIIN hmi
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(HMIDIIN))indir)(hmi);
}

MMRESULT
WINAPI
midiInGetDevCapsA(
    _In_ UINT_PTR uDeviceID,
    _Out_writes_bytes_( cbmic ) LPMIDIINCAPSA pmic,
    _In_ UINT cbmic
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(UINT_PTR,LPMIDIINCAPSA,UINT))indir)(uDeviceID,pmic,cbmic);
}

UINT
WINAPI
midiInGetNumDevs(
    void
)
{
    ENSURE_LOAD_FUNC();
    return ((UINT (WINAPI *)(void))indir)();
}

MMRESULT
WINAPI
midiInOpen(
    _Out_ LPHMIDIIN phmi,
    _In_ UINT uDeviceID,
    _In_opt_ DWORD_PTR dwCallback,
    _In_opt_ DWORD_PTR dwInstance,
    _In_ DWORD fdwOpen
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(LPHMIDIIN,UINT,DWORD_PTR,DWORD_PTR,DWORD))indir)(phmi,uDeviceID,dwCallback,dwInstance,fdwOpen);
}

MMRESULT
WINAPI
midiInStart(
    _In_ HMIDIIN hmi
)
{
    ENSURE_LOAD_FUNC();
    return ((MMRESULT (WINAPI *)(HMIDIIN))indir)(hmi);
}