/*
 * Small, EXE-side compatibility fixes ported from VorpalFix.
 *
 * WhiteRabbit owns its small, renderer-adjacent compatibility set here.
 * Version-sensitive gameplay/UI fixes outside this set remain VorpalFix's
 * responsibility when its companion ASI is present.
 */

#include <Windows.h>
#include <detours.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" void RendererLogPrintf(const char* fmt, ...);

namespace {

constexpr uintptr_t EXE_GET_SAVE_PATH = 0x00417400;
constexpr uintptr_t EXE_FS_FOPEN_FILE_READ = 0x0041A590;
constexpr uintptr_t EXE_STR_TO_LOWER = 0x004256E0;
constexpr uintptr_t EXE_DISK_FREE_CALL = 0x0042A5CE;
constexpr uintptr_t EXE_CL_PARSE_PACKET_ENTITIES = 0x0040C1B0;
constexpr uintptr_t EXE_CL_DRAW_3D_MODEL = 0x00446050;
constexpr uintptr_t EXE_RENDER_WIDTH = 0x011C02CC;
constexpr uintptr_t EXE_RENDER_HEIGHT = 0x011C02D0;

/* Renderer-library symbols: link-time relocation keeps these current. */
extern "C" void __cdecl Draw_StretchPic(float x, float y, float width, float height,
                                         float s1, float t1, float s2, float t2,
                                         int shader);
extern "C" void __cdecl RE_StretchRaw(int x, int y, int width, int height,
                                       int columns, int rows, int data);
extern "C" void __cdecl R_DrawString(void* font, char* text, float x, float y,
                                      float angle, float characterSpacing,
                                      float lineSpacing, float widthScale,
                                      float heightScale, int maxChars);

typedef char* (__cdecl* GetSavePathFn)();
typedef int (__cdecl* FSFOpenFileReadFn)(char*, int*, int, int);
typedef BYTE (__cdecl* StrToLowerFn)(char*);
typedef void (__cdecl* CLParsePacketEntitiesFn)(int, int, int);
typedef int (__cdecl* CLDraw3DModelFn)(float, float, float, float, int,
                                       float*, float*, float*, int, const char*, __int16,
                                       float*, float*, float, float, int);
typedef void (__cdecl* DrawStretchPicFn)(float, float, float, float, float,
                                         float, float, float, int);
typedef void (__cdecl* REStretchRawFn)(int, int, int, int, int, int, int);
typedef void (__cdecl* RDrawStringFn)(void*, char*, float, float, float, float,
                                      float, float, float, int);

static GetSavePathFn s_getSavePath = reinterpret_cast<GetSavePathFn>(EXE_GET_SAVE_PATH);
static FSFOpenFileReadFn s_originalFSFOpenFileRead =
    reinterpret_cast<FSFOpenFileReadFn>(EXE_FS_FOPEN_FILE_READ);
static StrToLowerFn s_originalStrToLower = reinterpret_cast<StrToLowerFn>(EXE_STR_TO_LOWER);
static CLParsePacketEntitiesFn s_originalCLParsePacketEntities =
    reinterpret_cast<CLParsePacketEntitiesFn>(EXE_CL_PARSE_PACKET_ENTITIES);
static CLDraw3DModelFn s_originalCLDraw3DModel =
    reinterpret_cast<CLDraw3DModelFn>(EXE_CL_DRAW_3D_MODEL);
static DrawStretchPicFn s_originalDrawStretchPic = Draw_StretchPic;
static REStretchRawFn s_originalREStretchRaw = RE_StretchRaw;
static RDrawStringFn s_originalRDrawString = R_DrawString;

static bool s_diskFreePatched = false;
static BYTE s_originalDiskFreeCall[5] = {};
static bool s_strToLowerHooked = false;
static bool s_pak5Hooked = false;
static bool s_widescreenHooksInstalled = false;
static float s_lastGameplayFov = 90.0f;
static bool s_haveLastGameplayFov = false;

struct WidescreenMetrics {
    int width;
    int height;
    float scaledWidth;
    float scaleFactor;
    float widthDifference;
    bool widerThanFourByThree;
};

static const char* const kPak5CorrectPaths[] = {
    "models/characters/cheshire/skin01.ftx",
    "models/characters/cheshire/skin02.ftx",
    "models/characters/cheshire/skin02g.ftx",
    "models/characters/cardguard_club/skin01.ftx",
    "models/characters/cardguard_diamond/skin02.ftx",
    "models/characters/cardguard_heart/skin04.ftx",
    "models/characters/cardguard_spade/skin03.ftx",
    "models/characters/mock_turtle/mshell.ftx",
    "models/characters/mock_turtle/mturt.ftx"
};

static const char* const kPak5BrokenPaths[] = {
    "models/characters/cheshire_cat/skin01.ftx",
    "models/characters/cheshire_cat/skin02.ftx",
    "models/characters/cheshire_cat/skin02g.ftx",
    "models/characters/cardguard/cardguard_club/skin01.ftx",
    "models/characters/cardguard/cardguard_diamond/skin02.ftx",
    "models/characters/cardguard/cardguard_heart/skin04.ftx",
    "models/characters/cardguard/cardguard_spade/skin03.ftx",
    "models/characters/morckturtle/mshell.ftx",
    "models/characters/morckturtle/mturt.ftx"
};

static bool write_memory(void* address, const void* bytes, size_t size)
{
    DWORD oldProtect;
    if (!VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        RendererLogPrintf("WARN: compatibility patch could not make %p writable (%lu)\n",
                          address, GetLastError());
        return false;
    }

    memcpy(address, bytes, size);
    FlushInstructionCache(GetCurrentProcess(), address, size);

    DWORD unused;
    if (!VirtualProtect(address, size, oldProtect, &unused)) {
        RendererLogPrintf("WARN: compatibility patch could not restore protection at %p (%lu)\n",
                          address, GetLastError());
        return false;
    }
    return true;
}

static bool commit_detour(bool attach, PVOID* target, PVOID hook, const char* name)
{
    LONG status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = attach ? DetourAttach(target, hook) : DetourDetach(target, hook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: %s %s failed: %ld\n", attach ? "installing" : "removing",
                          name, status);
    return status == NO_ERROR;
}

static int __cdecl check_disk_free_space()
{
    ULARGE_INTEGER available = {};
    ULARGE_INTEGER total = {};
    ULARGE_INTEGER freeBytes = {};
    const char* savePath = s_getSavePath ? s_getSavePath() : nullptr;

    if (savePath && GetDiskFreeSpaceExA(savePath, &available, &total, &freeBytes)) {
        const unsigned long long kib = available.QuadPart >> 10;
        return kib >= 0x80000000ULL ? 0x7fffffff : static_cast<int>(kib);
    }
    return 2048;
}

static void install_hard_disk_full_fix()
{
    BYTE* callSite = reinterpret_cast<BYTE*>(EXE_DISK_FREE_CALL);
    if (callSite[0] != 0xE8) {
        RendererLogPrintf("WARN: FixHardDiskFull skipped: expected CALL at %p\n", callSite);
        return;
    }

    const int32_t oldDisplacement = *reinterpret_cast<const int32_t*>(callSite + 1);
    const uintptr_t oldTarget = EXE_DISK_FREE_CALL + 5 + oldDisplacement;
    if (oldTarget != 0x0041D1E0) {
        RendererLogPrintf("WARN: FixHardDiskFull skipped: call target %p is not 0041D1E0\n",
                          reinterpret_cast<void*>(oldTarget));
        return;
    }

    BYTE patch[5] = { 0xE8 };
    const intptr_t relative = reinterpret_cast<const BYTE*>(&check_disk_free_space) -
                              (callSite + sizeof(patch));
    const int32_t displacement = static_cast<int32_t>(relative);
    memcpy(&patch[1], &displacement, sizeof(displacement));

    memcpy(s_originalDiskFreeCall, callSite, sizeof(s_originalDiskFreeCall));
    if (write_memory(callSite, patch, sizeof(patch))) {
        s_diskFreePatched = true;
        RendererLogPrintf("FixHardDiskFull installed\n");
    }
}

static int __cdecl fs_fopen_file_read_pak5_hook(char* source, int* handle, int a3, int a4)
{
    const char* redirect = source;
    if (source) {
        for (size_t i = 0; i < _countof(kPak5CorrectPaths); ++i) {
            if (_stricmp(source, kPak5CorrectPaths[i]) == 0) {
                redirect = kPak5BrokenPaths[i];
                break;
            }
        }
    }
    return s_originalFSFOpenFileRead(const_cast<char*>(redirect), handle, a3, a4);
}

static void install_pak5_open_hook()
{
    if (s_pak5Hooked)
        return;
    if (commit_detour(true, reinterpret_cast<PVOID*>(&s_originalFSFOpenFileRead),
                      reinterpret_cast<PVOID>(fs_fopen_file_read_pak5_hook), "FixPak5")) {
        s_pak5Hooked = true;
        RendererLogPrintf("FixPak5 installed for the detected original pak5_mod.pk3 paths\n");
    }
}

/*
 * Do not redirect all model loads blindly. VorpalFix first observes a known
 * misspelled pak5 path, then enables this redirect only for the original pak.
 */
static BYTE __cdecl str_to_lower_pak5_probe(char* buffer)
{
    const BYTE result = s_originalStrToLower(buffer);
    if (!s_pak5Hooked && buffer && _stricmp(buffer, kPak5BrokenPaths[0]) == 0)
        install_pak5_open_hook();
    return result;
}

static void install_pak5_fix()
{
    if (commit_detour(true, reinterpret_cast<PVOID*>(&s_originalStrToLower),
                      reinterpret_cast<PVOID>(str_to_lower_pak5_probe), "FixPak5 probe")) {
        s_strToLowerHooked = true;
        RendererLogPrintf("FixPak5 probe installed\n");
    }
}

static WidescreenMetrics get_widescreen_metrics()
{
    WidescreenMetrics metrics = {};
    metrics.width = *reinterpret_cast<const int*>(EXE_RENDER_WIDTH);
    metrics.height = *reinterpret_cast<const int*>(EXE_RENDER_HEIGHT);
    if (metrics.width <= 0 || metrics.height <= 0)
        return metrics;

    const float aspectRatio = static_cast<float>(metrics.width) / metrics.height;
    metrics.widerThanFourByThree = aspectRatio > (4.0f / 3.0f);
    if (metrics.widerThanFourByThree) {
        metrics.scaledWidth = metrics.height * (4.0f / 3.0f);
        metrics.scaleFactor = metrics.scaledWidth / metrics.width;
        metrics.widthDifference = (metrics.width - metrics.scaledWidth) * 0.5f;
    } else {
        metrics.scaledWidth = static_cast<float>(metrics.width);
        metrics.scaleFactor = 1.0f;
    }
    return metrics;
}

/* Unstretch HUD models and preserve their original left/centre/right placement. */
static int __cdecl cl_draw_3d_model_widescreen_hook(
    float x, float y, float width, float height, int a5, float* a6, float* a7,
    float* a8, int a9, const char* a10, __int16 a11, float* a12, float* a13,
    float a14, float a15, int a16)
{
    const WidescreenMetrics metrics = get_widescreen_metrics();
    if (metrics.widerThanFourByThree) {
        const float originalX = (x * 640.0f) / width;
        width *= metrics.scaleFactor;
        x = metrics.width / 640.0f * originalX;
        x = (x - metrics.width * 0.5f) * metrics.scaleFactor + metrics.width * 0.5f;
        if (originalX > 0.0f)
            x += metrics.widthDifference;
        else if (originalX < 0.0f)
            x -= metrics.widthDifference;
    }
    return s_originalCLDraw3DModel(x, y, width, height, a5, a6, a7, a8, a9, a10,
                                    a11, a12, a13, a14, a15, a16);
}

/* Keep 2D menu art at a centred 4:3 presentation width on widescreen displays. */
static void __cdecl draw_stretch_pic_widescreen_hook(float x, float y, float width,
                                                      float height, float s1, float t1,
                                                      float s2, float t2, int shader)
{
    const WidescreenMetrics metrics = get_widescreen_metrics();
    if (metrics.widerThanFourByThree) {
        width *= metrics.scaleFactor;
        x = x * metrics.scaleFactor + metrics.widthDifference;
    }
    s_originalDrawStretchPic(x, y, width, height, s1, t1, s2, t2, shader);
}

/* Font glyphs bypass Draw_StretchPic and write their quads directly to tess. */
static void __cdecl r_draw_string_widescreen_hook(void* font, char* text, float x,
                                                   float y, float angle,
                                                   float characterSpacing,
                                                   float lineSpacing,
                                                   float widthScale,
                                                   float heightScale, int maxChars)
{
    const WidescreenMetrics metrics = get_widescreen_metrics();
    if (metrics.widerThanFourByThree) {
        x = x * metrics.scaleFactor + metrics.widthDifference;
        characterSpacing *= metrics.scaleFactor;
        widthScale *= metrics.scaleFactor;
    }
    s_originalRDrawString(font, text, x, y, angle, characterSpacing, lineSpacing,
                          widthScale, heightScale, maxChars);
}

/* FMVs are 4:3 assets: pillarbox instead of horizontally stretching them. */
static void __cdecl re_stretch_raw_widescreen_hook(int x, int y, int width, int height,
                                                    int a5, int a6, int a7)
{
    const WidescreenMetrics metrics = get_widescreen_metrics();
    if (metrics.widerThanFourByThree) {
        x = static_cast<int>(metrics.widthDifference);
        width = static_cast<int>(metrics.scaledWidth);
    }
    s_originalREStretchRaw(x, y, width, height, a5, a6, a7);
}

/*
 * The server marks cinematic snapshots with a letterbox flag and narrows the
 * FOV for that presentation. Clear the flag and compensate for the narrower
 * cinematic FOV, restoring the last gameplay FOV when the cinematic ends.
 */
static void __cdecl cl_parse_packet_entities_letterbox_hook(int message, int oldFrame,
                                                             int newFrame)
{
    float* newFov = reinterpret_cast<float*>(newFrame + 0x418);
    const float* oldFov = oldFrame ? reinterpret_cast<const float*>(oldFrame + 0x418) : nullptr;
    const bool cinematic = *reinterpret_cast<const int*>(newFrame + 0x104) != 0;
    const bool wasCinematic = oldFrame && *reinterpret_cast<const int*>(oldFrame + 0x104) != 0;
    const bool fovChanged = !oldFov || *newFov != *oldFov;

    if (fovChanged && !cinematic) {
        s_lastGameplayFov = *newFov;
        s_haveLastGameplayFov = true;
    }
    if (wasCinematic && !cinematic && s_haveLastGameplayFov)
        *newFov = s_lastGameplayFov;

    *reinterpret_cast<int*>(newFrame + 0x10C) = 0;
    if (cinematic && (!wasCinematic || fovChanged))
        *newFov /= 1.11f;

    s_originalCLParsePacketEntities(message, oldFrame, newFrame);
}

static void install_widescreen_and_letterbox_fixes()
{
    LONG status = DetourTransactionBegin();
    if (status == NO_ERROR) status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR) status = DetourAttach(
        reinterpret_cast<PVOID*>(&s_originalCLParsePacketEntities),
        reinterpret_cast<PVOID>(cl_parse_packet_entities_letterbox_hook));
    if (status == NO_ERROR) status = DetourAttach(
        reinterpret_cast<PVOID*>(&s_originalCLDraw3DModel),
        reinterpret_cast<PVOID>(cl_draw_3d_model_widescreen_hook));
    if (status == NO_ERROR) status = DetourAttach(
        reinterpret_cast<PVOID*>(&s_originalDrawStretchPic),
        reinterpret_cast<PVOID>(draw_stretch_pic_widescreen_hook));
    if (status == NO_ERROR) status = DetourAttach(
        reinterpret_cast<PVOID*>(&s_originalRDrawString),
        reinterpret_cast<PVOID>(r_draw_string_widescreen_hook));
    if (status == NO_ERROR) status = DetourAttach(
        reinterpret_cast<PVOID*>(&s_originalREStretchRaw),
        reinterpret_cast<PVOID>(re_stretch_raw_widescreen_hook));
    if (status == NO_ERROR) status = DetourTransactionCommit(); else DetourTransactionAbort();

    if (status == NO_ERROR) {
        s_widescreenHooksInstalled = true;
        RendererLogPrintf("Menu/HUD/FMV aspect-ratio and cinematic-letterbox fixes installed\n");
    } else {
        RendererLogPrintf("WARN: installing widescreen/letterbox fixes failed: %ld\n", status);
    }
}

static void uninstall_widescreen_and_letterbox_fixes()
{
    if (!s_widescreenHooksInstalled)
        return;

    LONG status = DetourTransactionBegin();
    if (status == NO_ERROR) status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR) status = DetourDetach(
        reinterpret_cast<PVOID*>(&s_originalREStretchRaw),
        reinterpret_cast<PVOID>(re_stretch_raw_widescreen_hook));
    if (status == NO_ERROR) status = DetourDetach(
        reinterpret_cast<PVOID*>(&s_originalRDrawString),
        reinterpret_cast<PVOID>(r_draw_string_widescreen_hook));
    if (status == NO_ERROR) status = DetourDetach(
        reinterpret_cast<PVOID*>(&s_originalDrawStretchPic),
        reinterpret_cast<PVOID>(draw_stretch_pic_widescreen_hook));
    if (status == NO_ERROR) status = DetourDetach(
        reinterpret_cast<PVOID*>(&s_originalCLDraw3DModel),
        reinterpret_cast<PVOID>(cl_draw_3d_model_widescreen_hook));
    if (status == NO_ERROR) status = DetourDetach(
        reinterpret_cast<PVOID*>(&s_originalCLParsePacketEntities),
        reinterpret_cast<PVOID>(cl_parse_packet_entities_letterbox_hook));
    if (status == NO_ERROR) status = DetourTransactionCommit(); else DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: removing widescreen/letterbox fixes failed: %ld\n", status);
    s_widescreenHooksInstalled = false;
}

static void install_dpi_scaling_fix()
{
    typedef BOOL (WINAPI* SetProcessDpiAwarenessContextFn)(HANDLE);
    typedef HRESULT (WINAPI* SetProcessDpiAwarenessFn)(int);
    typedef BOOL (WINAPI* SetProcessDPIAwareFn)();

    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    if (user32) {
        const auto setContext = reinterpret_cast<SetProcessDpiAwarenessContextFn>(
            GetProcAddress(user32, "SetProcessDpiAwarenessContext"));
        if (setContext && setContext(reinterpret_cast<HANDLE>(-4))) {
            RendererLogPrintf("FixDPIScaling: per-monitor v2 awareness enabled\n");
            return;
        }
    }

    HMODULE shcore = LoadLibraryW(L"shcore.dll");
    if (shcore) {
        const auto setAwareness = reinterpret_cast<SetProcessDpiAwarenessFn>(
            GetProcAddress(shcore, "SetProcessDpiAwareness"));
        if (setAwareness && SUCCEEDED(setAwareness(2))) {
            FreeLibrary(shcore);
            RendererLogPrintf("FixDPIScaling: per-monitor awareness enabled\n");
            return;
        }
        FreeLibrary(shcore);
    }

    if (user32) {
        const auto setAware = reinterpret_cast<SetProcessDPIAwareFn>(
            GetProcAddress(user32, "SetProcessDPIAware"));
        if (setAware && setAware()) {
            RendererLogPrintf("FixDPIScaling: system DPI awareness enabled\n");
            return;
        }
    }
    RendererLogPrintf("WARN: FixDPIScaling could not enable a DPI-awareness mode\n");
}

static char* trim_ini_text(char* text)
{
    while (*text == ' ' || *text == '\t' || *text == '\r' || *text == '\n')
        ++text;
    char* end = text + strlen(text);
    while (end > text && (end[-1] == ' ' || end[-1] == '\t' ||
                          end[-1] == '\r' || end[-1] == '\n'))
        *--end = '\0';
    return text;
}

static int read_vorpal_ini_integer(const char* wantedSection, const char* wantedKey,
                                   int defaultValue, bool* explicitlySet)
{
    FILE* file = nullptr;
    char line[512];
    char section[64] = {};
    if (explicitlySet)
        *explicitlySet = false;
    if (fopen_s(&file, "VorpalFix.ini", "r") != 0 || !file)
        return defaultValue;

    while (fgets(line, sizeof(line), file)) {
        char* text = trim_ini_text(line);
        char* comment = strpbrk(text, ";#");
        if (comment)
            *comment = '\0';
        text = trim_ini_text(text);
        if (!*text)
            continue;

        const size_t length = strlen(text);
        if (text[0] == '[' && length > 2 && text[length - 1] == ']') {
            text[length - 1] = '\0';
            strncpy_s(section, text + 1, _TRUNCATE);
            continue;
        }

        char* equals = strchr(text, '=');
        if (!equals || _stricmp(section, wantedSection) != 0)
            continue;
        *equals = '\0';
        char* key = trim_ini_text(text);
        char* value = trim_ini_text(equals + 1);
        if (_stricmp(key, wantedKey) == 0) {
            if (explicitlySet)
                *explicitlySet = true;
            fclose(file);
            return static_cast<int>(strtol(value, nullptr, 0));
        }
    }

    fclose(file);
    return defaultValue;
}

struct VorpalIniConflict {
    const char* section;
    const char* key;
    int vorpalDefault;
    int requiredValue;
};

static void audit_vorpal_companion_ini()
{
    static const VorpalIniConflict conflicts[] = {
        { "Fixes", "FixDisplayModeBufferOverflow", 1, 0 },
        { "Fixes", "FixFullscreenSetting", 1, 0 },
        { "Fixes", "FixResolutionModeOOB", 1, 0 },
        { "Display", "ForceBorderlessFullscreen", 0, 0 },
        { "Display", "FirstAutoResolution", 1, 0 },
        { "Display", "AutoResolution", 0, 0 },
        { "Display", "CustomResolution", 0, 0 },
        { "Graphics", "MaxAnisotropy", 16, 0 },
        { "Graphics", "MultiSampleAntiAliasing", 8, 0 },
        { "Graphics", "TrilinearTextureFiltering", 1, 0 },
        { "Graphics", "ForceBatchedRendering", 1, 0 },
        { "Graphics", "EnhancedLOD", 1, 0 },
        { "Graphics", "OverrideFPSLimit", 1, 0 },
        { "Graphics", "EnableVsyncAsDefault", 1, 0 },
        { "Graphics", "AutoFOV", 1, 0 },
        //{ "General", "DisableRemasteredModels", 0, 0 },
    };

    FILE* file = nullptr;
    if (fopen_s(&file, "VorpalFix.ini", "r") != 0 || !file) {
        RendererLogPrintf("WARN: VorpalFix companion mode: VorpalFix.ini was not found; "
                          "Vorpal defaults include renderer-conflicting options\n");
        return;
    }
    fclose(file);

    bool anyConflicts = false;
    for (size_t i = 0; i < _countof(conflicts); ++i) {
        bool explicitlySet = false;
        const int value = read_vorpal_ini_integer(conflicts[i].section, conflicts[i].key,
                                                  conflicts[i].vorpalDefault, &explicitlySet);
        if (value != conflicts[i].requiredValue) {
            if (!anyConflicts) {
                RendererLogPrintf("WARN: VorpalFix companion configuration has renderer-conflicting options:\n");
                anyConflicts = true;
            }
            RendererLogPrintf("  [%s] %s = %d%s; set it to %d\n",
                              conflicts[i].section, conflicts[i].key, value,
                              explicitlySet ? "" : " (Vorpal default)",
                              conflicts[i].requiredValue);
        }
    }

    if (!anyConflicts)
        RendererLogPrintf("VorpalFix companion configuration audit passed\n");
}

} // namespace

extern "C" void InstallVorpalCompatibilityFixes(void)
{
    install_dpi_scaling_fix();
    install_hard_disk_full_fix();
    install_pak5_fix();
    install_widescreen_and_letterbox_fixes();
}

extern "C" void UninstallVorpalCompatibilityFixes(void)
{
    uninstall_widescreen_and_letterbox_fixes();
    if (s_pak5Hooked) {
        commit_detour(false, reinterpret_cast<PVOID*>(&s_originalFSFOpenFileRead),
                      reinterpret_cast<PVOID>(fs_fopen_file_read_pak5_hook), "FixPak5");
        s_pak5Hooked = false;
    }
    if (s_strToLowerHooked) {
        commit_detour(false, reinterpret_cast<PVOID*>(&s_originalStrToLower),
                      reinterpret_cast<PVOID>(str_to_lower_pak5_probe), "FixPak5 probe");
        s_strToLowerHooked = false;
    }
    if (s_diskFreePatched) {
        write_memory(reinterpret_cast<void*>(EXE_DISK_FREE_CALL), s_originalDiskFreeCall,
                     sizeof(s_originalDiskFreeCall));
        s_diskFreePatched = false;
    }
}

extern "C" void AuditVorpalFixCompanionSettings(void)
{
    audit_vorpal_companion_ini();
}
