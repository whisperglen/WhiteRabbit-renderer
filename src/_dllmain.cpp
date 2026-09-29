
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <intrin.h>
#include <detours.h>
#include "alice_renderer_api.h"
#define RMX_ADD_IMPL
#include "qindie_rmx.h"

#define EXEC_APPEND 2

extern "C" refimport_t ri;
extern "C" byte tess[];

extern "C" void* __cdecl GetRefAPI(int apiVersion, void* imports);
extern "C" void GLW_GetValidModes();
extern "C" void GLW_GetValidModes_Override();
extern "C" void RB_StageIteratorSky();
extern "C" void R_AddWorldSurfaces();
extern "C" void R_Sky_Reset();
extern "C" void R_Sky_AddSurf();
extern "C" void R_Sky_Render();
extern "C" void R_SortDrawSurfs();
extern "C" int SurfIsOffscreen();
extern "C" void R_SepiaScreenShot();
extern "C" void RE_LoadWorldMap(const char* mapName);
extern "C" void R_Register();
extern "C" void RE_Shutdown(int destroyWindow);
extern "C" void RE_AddLightToScene(const vec3_t org, float intensity,
                                    float r, float g, float b, int type);
extern "C" void RE_AddRefEntityToScene(const refEntity_t* ent);
extern "C" void RE_BeginFrame(int stereoFrame);
extern "C" void RE_RenderScene(const refdef_t* fd);
extern "C" void RB_BeginSurface(void* shader, void* fog);
extern "C" void RB_SurfaceFace(void* surface);
extern "C" void RB_SurfaceGrid(void* surface);
extern "C" void RB_SurfaceTriangles(void* surface);
extern "C" void RendererInitSkyPortalOptions(void);
extern "C" void RendererInitRemixShaderOptions(void);
extern "C" void __cdecl RemixComputeColorsHook(void* stage);
extern "C" void __cdecl RemixComputeTexCoordsHook(void* stage);
extern "C" void __cdecl RemixTurbulentTexCoordsHook(const void* waveform,
                                                      float* destination);
extern "C" void __cdecl RemixScaleTexCoordsHook(const void* scale,
                                                  float* destination);
extern "C" void __cdecl RemixScrollTexCoordsHook(const void* scrollSpeed,
                                                   float* destination);
extern "C" void __cdecl RemixOffsetTexCoordsHook(const void* offset,
                                                   float* destination);
extern "C" void __cdecl RemixTransformTexCoordsHook(const void* modifier,
                                                      float* destination);
extern "C" void __cdecl RemixStageIteratorGenericHook(void);
extern "C" void __cdecl RendererInitRemixShaderHooks(
    void* originalComputeColors, void* originalComputeTexCoords,
    void* originalTurbulentTexCoords, void* backEndProjection2D);
extern "C" void __cdecl RendererInitRemixGpuUvTransformHooks(
    void* originalScaleTexCoords, void* originalScrollTexCoords,
    void* originalOffsetTexCoords, void* originalTransformTexCoords,
    void* originalStageIteratorGeneric);
extern "C" void __cdecl RendererSetRemixShaderTime(int milliseconds);
extern "C" void __cdecl RendererShutdownRemixShaderHooks(void);
extern "C" void __cdecl RB_CalcTurbulentTexCoords(const void* waveform,
                                                    float* destination);
extern "C" void __cdecl RB_CalcScaleTexCoords(const void* scale,
                                                float* destination);
extern "C" void __cdecl RB_CalcScrollTexCoords(const void* scrollSpeed,
                                                 float* destination);
extern "C" void __cdecl RB_CalcOffsetTexCoords(const void* offset,
                                                 float* destination);
extern "C" void __cdecl RB_CalcTransformTexCoords(const void* modifier,
                                                    float* destination);
extern "C" void __cdecl RB_StageIteratorGeneric(void);
extern "C" int __cdecl VertexLightingModeHook(void);
extern "C" void __cdecl RendererInitVertexLightingModeHook(
    void* unfoggedStages, void* shader, void* rVertexLightSlot,
    void* originalVertexLightingCollapse);
extern "C" void __cdecl RendererShutdownVertexLightingModeHook(void);
extern "C" void __cdecl StableDrawSurfQsortFastHook(void* base,
                                                       uint32_t count,
                                                       uint32_t elementSize);
extern "C" void __cdecl RendererInitStableDrawSurfSort(void* originalQsortFast);
extern "C" void __cdecl RendererShutdownStableDrawSurfSort(void);

/* Game EXE allocator; recovered from the Z_Free error-string xref. */
static const uintptr_t EXE_Z_FREE = 0x0041E000;

typedef void (APIENTRY *QglPixelStoreiFn)(unsigned int pname, int param);
typedef void (APIENTRY *QglGetIntegervFn)(unsigned int pname, int* values);
typedef unsigned char (APIENTRY *QglIsEnabledFn)(unsigned int cap);
typedef void (APIENTRY *QglActiveTextureFn)(unsigned int texture);
typedef void (APIENTRY *QglBindTextureFn)(unsigned int target, unsigned int texture);
typedef void (APIENTRY *QglGenTexturesFn)(int count, unsigned int* textures);
typedef void (APIENTRY *QglDeleteTexturesFn)(int count, const unsigned int* textures);
typedef void (APIENTRY *QglTexParameteriFn)(unsigned int target, unsigned int pname,
                                             int param);
typedef void (APIENTRY *QglTexImage2DFn)(unsigned int target, int level,
                                         int internalFormat, int width, int height,
                                         int border, unsigned int format,
                                         unsigned int type, const void* pixels);
typedef void (APIENTRY *QglEnableDisableFn)(unsigned int cap);
typedef void (APIENTRY *QglBeginFn)(unsigned int mode);
typedef void (APIENTRY *QglEndFn)(void);
typedef void (APIENTRY *QglTexCoord2fFn)(float s, float t);
typedef void (APIENTRY *QglVertex2fFn)(float x, float y);
extern "C" QglPixelStoreiFn qglPixelStorei;
extern "C" QglGetIntegervFn qglGetIntegerv;
extern "C" QglIsEnabledFn qglIsEnabled;
extern "C" QglActiveTextureFn qglActiveTextureARB;
extern "C" QglBindTextureFn qglBindTexture;
extern "C" QglGenTexturesFn qglGenTextures;
extern "C" QglDeleteTexturesFn qglDeleteTextures;
extern "C" QglTexParameteriFn qglTexParameteri;
extern "C" QglTexImage2DFn qglTexImage2D;
extern "C" QglEnableDisableFn qglEnable;
extern "C" QglEnableDisableFn qglDisable;
extern "C" QglBeginFn qglBegin;
extern "C" QglEndFn qglEnd;
extern "C" QglTexCoord2fFn qglTexCoord2f;
extern "C" QglVertex2fFn qglVertex2f;

static void logInit();
static void logClose();
extern "C" void RendererLogPrintf(const char* fmt, ...);
int hook_unprotect(void* ptr, int size, unsigned long* restore);
int hook_protect(void* ptr, int size, unsigned long restore);
static void QDECL a1_flashlight_toggle(void);

/* Alice cvar_t layout, recovered from R_Register and the renderer ABI. */
typedef struct cvar_s {
    const char* name;
    const char* string;
    const char* resetString;
    const char* latchedString;
    int flags;
    qboolean modified;
    int modificationCount;
    float value;
    int integer;
    struct cvar_s* next;
} cvar_t;

static const int CVAR_ARCHIVE = 1;
static cvar_t* r_rmx_coronas = nullptr;
static cvar_t* r_rmx_dynamiclight = nullptr;
static uint32_t r_rmxdlights = 0;
static uint32_t r_rmxcoronas = 0;

static HMODULE s_rendererModule = nullptr;
static HMODULE s_opengl32 = nullptr;

/* shaderCommands_t field offsets, recovered from the tessellation writers. */
static const size_t TESS_VERTEXES_OFFSET = 0xAFC80;
static const size_t TESS_NORMALS_OFFSET = 0x124F80;

static void configure_tess_array_addresses()
{
    void* ptrs[] = { tess + TESS_VERTEXES_OFFSET, tess + TESS_NORMALS_OFFSET };

    RendererLogPrintf("Remix tess arrays: tess.vertexes=%p, tess.normal=%p (normal delta +0x%X)\n",
                      ptrs[0], ptrs[1],
                      (unsigned int)(TESS_NORMALS_OFFSET - TESS_VERTEXES_OFFSET));

    qind_global_options_set(OPT_NORMALPTR, ptrs);
}

/*
 * Remix switches permanently to its UI path after its first orthographic,
 * no-depth-write draw of a frame.  Alice prepares 2D state, then begins each
 * HUD element through RE_RenderScene.  Emit one marker just before the first
 * HUD RE_RenderScene, while that 2D state is still active.
 */
static const unsigned int GL_TEXTURE_2D_VALUE = 0x0de1;
static const unsigned int GL_TEXTURE0_ARB_VALUE = 0x84c0;
static const unsigned int GL_ACTIVE_TEXTURE_ARB_VALUE = 0x84e0;
static const unsigned int GL_TEXTURE_BINDING_2D_VALUE = 0x8069;
static const unsigned int GL_TEXTURE_MIN_FILTER_VALUE = 0x2801;
static const unsigned int GL_TEXTURE_MAG_FILTER_VALUE = 0x2800;
static const unsigned int GL_NEAREST_VALUE = 0x2600;
static const unsigned int GL_RGBA_VALUE = 0x1908;
static const unsigned int GL_UNSIGNED_BYTE_VALUE = 0x1401;
static const unsigned int GL_QUADS_VALUE = 0x0007;

static unsigned int s_uiMarkerTexture = 0;
static bool s_uiMarkerEmittedThisFrame = false;

static bool ui_marker_qgl_ready()
{
    return qglGetIntegerv && qglIsEnabled && qglBindTexture &&
           qglGenTextures && qglTexParameteri &&
           qglTexImage2D && qglEnable && qglDisable && qglBegin && qglEnd &&
           qglTexCoord2f && qglVertex2f;
}

static bool create_ui_marker_texture()
{
    static const byte markerPixels[2 * 2 * 4] = {
        0xff, 0x00, 0xff, 0xff,
        0x00, 0xff, 0xff, 0xff,
        0x00, 0xff, 0xff, 0xff,
        0xff, 0x00, 0xff, 0xff
    };
    int savedActiveTexture;
    int savedTexture2D;
    unsigned int markerTexture = 0;

    if (s_uiMarkerTexture)
        return true;
    if (!ui_marker_qgl_ready())
        return false;

    savedActiveTexture = GL_TEXTURE0_ARB_VALUE;
    if (qglActiveTextureARB)
    {
        qglGetIntegerv(GL_ACTIVE_TEXTURE_ARB_VALUE, &savedActiveTexture);
        qglActiveTextureARB(GL_TEXTURE0_ARB_VALUE);
    }
    qglGetIntegerv(GL_TEXTURE_BINDING_2D_VALUE, &savedTexture2D);

    qglGenTextures(1, &markerTexture);
    if (markerTexture)
    {
        qglBindTexture(GL_TEXTURE_2D_VALUE, markerTexture);
        qglTexParameteri(GL_TEXTURE_2D_VALUE, GL_TEXTURE_MIN_FILTER_VALUE,
                          GL_NEAREST_VALUE);
        qglTexParameteri(GL_TEXTURE_2D_VALUE, GL_TEXTURE_MAG_FILTER_VALUE,
                          GL_NEAREST_VALUE);
        qglTexImage2D(GL_TEXTURE_2D_VALUE, 0, GL_RGBA_VALUE, 2, 2, 0,
                      GL_RGBA_VALUE, GL_UNSIGNED_BYTE_VALUE, markerPixels);
        s_uiMarkerTexture = markerTexture;
    }

    qglBindTexture(GL_TEXTURE_2D_VALUE, (unsigned int)savedTexture2D);
    if (qglActiveTextureARB)
        qglActiveTextureARB((unsigned int)savedActiveTexture);

    if (!s_uiMarkerTexture)
        return false;

    RendererLogPrintf("Remix UI marker texture created: %u\n", s_uiMarkerTexture);
    return true;
}

static bool emit_ui_marker_draw()
{
    int savedActiveTexture;
    int savedTexture2D;
    unsigned char texture2DWasEnabled;

    if (!create_ui_marker_texture())
        return false;

    savedActiveTexture = GL_TEXTURE0_ARB_VALUE;
    if (qglActiveTextureARB)
    {
        qglGetIntegerv(GL_ACTIVE_TEXTURE_ARB_VALUE, &savedActiveTexture);
        qglActiveTextureARB(GL_TEXTURE0_ARB_VALUE);
    }
    qglGetIntegerv(GL_TEXTURE_BINDING_2D_VALUE, &savedTexture2D);
    texture2DWasEnabled = qglIsEnabled(GL_TEXTURE_2D_VALUE);

    qglEnable(GL_TEXTURE_2D_VALUE);
    qglBindTexture(GL_TEXTURE_2D_VALUE, s_uiMarkerTexture);
    qglBegin(GL_QUADS_VALUE);
    qglTexCoord2f(0.0f, 0.0f); qglVertex2f(0.0f, 0.0f);
    qglTexCoord2f(1.0f, 0.0f); qglVertex2f(64.0f, 0.0f);
    qglTexCoord2f(1.0f, 1.0f); qglVertex2f(64.0f, 64.0f);
    qglTexCoord2f(0.0f, 1.0f); qglVertex2f(0.0f, 64.0f);
    qglEnd();

    qglBindTexture(GL_TEXTURE_2D_VALUE, (unsigned int)savedTexture2D);
    if (!texture2DWasEnabled)
        qglDisable(GL_TEXTURE_2D_VALUE);
    if (qglActiveTextureARB)
        qglActiveTextureARB((unsigned int)savedActiveTexture);
    return true;
}

static void destroy_ui_marker_texture()
{
    int savedActiveTexture;
    int savedTexture2D;
    unsigned int markerTexture = s_uiMarkerTexture;

    s_uiMarkerTexture = 0;
    s_uiMarkerEmittedThisFrame = false;
    if (!markerTexture || !qglGetIntegerv || !qglBindTexture ||
        !qglDeleteTextures)
        return;

    savedActiveTexture = GL_TEXTURE0_ARB_VALUE;
    if (qglActiveTextureARB)
    {
        qglGetIntegerv(GL_ACTIVE_TEXTURE_ARB_VALUE, &savedActiveTexture);
        qglActiveTextureARB(GL_TEXTURE0_ARB_VALUE);
    }
    qglGetIntegerv(GL_TEXTURE_BINDING_2D_VALUE, &savedTexture2D);
    qglDeleteTextures(1, &markerTexture);
    if ((unsigned int)savedTexture2D != markerTexture)
        qglBindTexture(GL_TEXTURE_2D_VALUE, (unsigned int)savedTexture2D);
    if (qglActiveTextureARB)
        qglActiveTextureARB((unsigned int)savedActiveTexture);
}

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
    RendererInitRemixShaderOptions();
    return exports;
}

/*
 * Notify the Remix wrapper before the renderer starts replacing its world
 * state, then continue through Detours' trampoline into the original
 * implementation.
 */
typedef void (__cdecl *RELoadWorldMapFn)(const char* mapName);
static RELoadWorldMapFn s_originalRELoadWorldMap = RE_LoadWorldMap;
static bool s_loadWorldMapHooked = false;

static void __cdecl RE_LoadWorldMap_RmxHook(const char* mapName)
{
    rmx_begin_loading_map(mapName);
    s_originalRELoadWorldMap(mapName);
}

static void install_load_world_map_hook()
{
    LONG status;

    if (s_loadWorldMapHooked)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRELoadWorldMap,
                              RE_LoadWorldMap_RmxHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_loadWorldMapHooked = true;
        RendererLogPrintf("RE_LoadWorldMap Remix hook installed at %p\n",
                          (void*)RE_LoadWorldMap);
    }
    else
    {
        s_originalRELoadWorldMap = RE_LoadWorldMap;
        RendererLogPrintf("WARN: failed to install RE_LoadWorldMap Remix hook: %ld\n",
                          status);
    }
}

static void uninstall_load_world_map_hook()
{
    LONG status;

    if (!s_loadWorldMapHooked)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRELoadWorldMap,
                              RE_LoadWorldMap_RmxHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove RE_LoadWorldMap Remix hook: %ld\n",
                          status);

    s_originalRELoadWorldMap = RE_LoadWorldMap;
    s_loadWorldMapHooked = false;
}

/*
 * R_Register runs after the renderer has received ri, so it is the earliest
 * safe point to add a game-console command.  RE_Shutdown removes the command
 * while the import table is still valid; this also supports renderer restarts
 * without leaving a callback into an unloaded module.
 */
typedef void (__cdecl *RRegisterFn)(void);
typedef void (__cdecl *REShutdownFn)(int destroyWindow);
static RRegisterFn s_originalRRegister = R_Register;
static REShutdownFn s_originalREShutdown = RE_Shutdown;
static bool s_flashlightCommandHooksInstalled = false;
static bool s_flashlightCommandRegistered = false;
static const char s_flashlightToggleCommand[] = "rmx_flashlight_toggle";

static void __cdecl R_Register_FlashlightCommandHook(void)
{
    s_originalRRegister();

    if (ri.Cvar_Get)
    {
        r_rmx_coronas = (cvar_t*)ri.Cvar_Get(
            "rmx_coronas", "0", CVAR_ARCHIVE);
        r_rmx_dynamiclight = (cvar_t*)ri.Cvar_Get(
            "rmx_dynamiclight", "1", CVAR_ARCHIVE);
    }

    if (!s_flashlightCommandRegistered && ri.Cmd_AddCommand)
    {
        ri.Cmd_AddCommand(s_flashlightToggleCommand, a1_flashlight_toggle);
        s_flashlightCommandRegistered = true;
    }
}

static void __cdecl RE_Shutdown_FlashlightCommandHook(int destroyWindow)
{
    destroy_ui_marker_texture();

    if (s_flashlightCommandRegistered && ri.Cmd_RemoveCommand)
    {
        ri.Cmd_RemoveCommand(s_flashlightToggleCommand);
        s_flashlightCommandRegistered = false;
    }

    s_originalREShutdown(destroyWindow);
}

static void install_flashlight_command_hooks()
{
    LONG status;

    if (s_flashlightCommandHooksInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRRegister,
                              R_Register_FlashlightCommandHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalREShutdown,
                              RE_Shutdown_FlashlightCommandHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_flashlightCommandHooksInstalled = true;
        RendererLogPrintf("Flashlight command lifecycle hooks installed\n");
    }
    else
    {
        s_originalRRegister = R_Register;
        s_originalREShutdown = RE_Shutdown;
        RendererLogPrintf("WARN: failed to install flashlight command lifecycle hooks: %ld\n",
                          status);
    }
}

static void uninstall_flashlight_command_hooks()
{
    LONG status;

    if (!s_flashlightCommandHooksInstalled)
        return;

    if (s_flashlightCommandRegistered && ri.Cmd_RemoveCommand)
    {
        ri.Cmd_RemoveCommand(s_flashlightToggleCommand);
        s_flashlightCommandRegistered = false;
    }

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalREShutdown,
                              RE_Shutdown_FlashlightCommandHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRRegister,
                              R_Register_FlashlightCommandHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove flashlight command lifecycle hooks: %ld\n",
                          status);

    s_originalRRegister = R_Register;
    s_originalREShutdown = RE_Shutdown;
    s_flashlightCommandHooksInstalled = false;
}

/*
 * Alice exposes dynamic-light submission as RE_AddLightToScene.  Its final
 * integer parameter is renderer-specific, but it is preserved verbatim when
 * continuing into the original function.
 */
typedef void (__cdecl *REAddLightToSceneFn)(const vec3_t org, float intensity,
                                            float r, float g, float b, int type);
typedef void (__cdecl *REAddRefEntityToSceneFn)(const refEntity_t* ent);
typedef void (__cdecl *REBeginFrameFn)(int stereoFrame);
static REAddLightToSceneFn s_originalREAddLightToScene = RE_AddLightToScene;
static REAddRefEntityToSceneFn s_originalREAddRefEntityToScene = RE_AddRefEntityToScene;
static REBeginFrameFn s_originalREBeginFrame = RE_BeginFrame;
static bool s_rmxDynamicLightHooksInstalled = false;

static void __cdecl RE_AddLightToScene_RmxHook(const vec3_t org, float intensity,
                                                float r, float g, float b, int type)
{
    if (r_rmx_dynamiclight && r_rmx_dynamiclight->value)
    {
        vec3_t color = { r, g, b };
        rmx_light_add(LIGHT_DYNAMIC, (int)r_rmxdlights, org, org, color, intensity);
        ++r_rmxdlights;
    }

    s_originalREAddLightToScene(org, intensity, r, g, b, type);
}

/* R_DrawLensFlares identifies static torch/lamp candidates by renderfx bit 3. */
static void __cdecl RE_AddRefEntityToScene_RmxCoronaHook(const refEntity_t* ent)
{
    if (ent && r_rmx_coronas && r_rmx_coronas->value && (ent->renderfx & 0x8))
    {
        const byte* rgba = (const byte*)ent + 0xbc;
        vec3_t color = {
            rgba[0] / 255.0f,
            rgba[1] / 255.0f,
            rgba[2] / 255.0f
        };

        rmx_light_add(LIGHT_CORONA, (int)r_rmxcoronas,
                      ent->origin, ent->origin, color, 0.0f);
        ++r_rmxcoronas;
    }

    s_originalREAddRefEntityToScene(ent);
}

static void __cdecl RE_BeginFrame_RmxHook(int stereoFrame)
{
    r_rmxdlights = 0;
    r_rmxcoronas = 0;
    s_uiMarkerEmittedThisFrame = false;

    if (r_rmx_dynamiclight && r_rmx_dynamiclight->modified)
    {
        r_rmx_dynamiclight->modified = qfalse;
        rmx_lights_clear(LIGHT_DYNAMIC);
    }

    if (r_rmx_coronas && r_rmx_coronas->modified)
    {
        r_rmx_coronas->modified = qfalse;
        rmx_lights_clear(LIGHT_CORONA);
    }

    s_originalREBeginFrame(stereoFrame);
}

static void install_rmx_dynamic_light_hooks()
{
    LONG status;

    if (s_rmxDynamicLightHooksInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalREAddLightToScene,
                              RE_AddLightToScene_RmxHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalREAddRefEntityToScene,
                              RE_AddRefEntityToScene_RmxCoronaHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalREBeginFrame,
                              RE_BeginFrame_RmxHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_rmxDynamicLightHooksInstalled = true;
        RendererLogPrintf("Remix dynamic-light/corona hooks installed\n");
    }
    else
    {
        s_originalREAddLightToScene = RE_AddLightToScene;
        s_originalREAddRefEntityToScene = RE_AddRefEntityToScene;
        s_originalREBeginFrame = RE_BeginFrame;
        RendererLogPrintf("WARN: failed to install Remix dynamic-light/corona hooks: %ld\n",
                          status);
    }
}

static void uninstall_rmx_dynamic_light_hooks()
{
    LONG status;

    if (!s_rmxDynamicLightHooksInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalREBeginFrame,
                              RE_BeginFrame_RmxHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalREAddRefEntityToScene,
                              RE_AddRefEntityToScene_RmxCoronaHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalREAddLightToScene,
                              RE_AddLightToScene_RmxHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove Remix dynamic-light/corona hooks: %ld\n",
                          status);

    s_originalREAddLightToScene = RE_AddLightToScene;
    s_originalREAddRefEntityToScene = RE_AddRefEntityToScene;
    s_originalREBeginFrame = RE_BeginFrame;
    r_rmx_coronas = nullptr;
    r_rmx_dynamiclight = nullptr;
    r_rmxdlights = 0;
    r_rmxcoronas = 0;
    s_rmxDynamicLightHooksInstalled = false;
}

/* Feed Remix the renderer's active 3D camera before Alice consumes the view. */
typedef void (__cdecl *RERenderSceneFn)(const refdef_t* fd);
static RERenderSceneFn s_originalRERenderScene = RE_RenderScene;
static bool s_rmxCameraHookInstalled = false;

static void __cdecl RE_RenderScene_RmxCameraHook(const refdef_t* fd)
{
    static const float identity[9] = { 1.0f, 0.0f, 0.0f,
                                        0.0f, 1.0f, 0.0f,
                                        0.0f, 0.0f, 1.0f };

    if (fd && memcmp(identity, fd->viewaxis, sizeof(identity)) != 0)
        rmx_setplayerpos(fd->vieworg, fd->viewaxis[0]);

    if (fd)
        RendererSetRemixShaderTime(fd->time);

    /* HUD refdefs use a backend Clear Flag which matches rdflags != 0 */
    if (!s_uiMarkerEmittedThisFrame && fd && fd->rdflags != 0 && emit_ui_marker_draw())
    {
        s_uiMarkerEmittedThisFrame = true;
        //RendererLogPrintf("Remix UI marker emitted before HUD RE_RenderScene\n");
    }

    s_originalRERenderScene(fd);
}

static void install_rmx_camera_hook()
{
    LONG status;

    if (s_rmxCameraHookInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRERenderScene,
                              RE_RenderScene_RmxCameraHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_rmxCameraHookInstalled = true;
        RendererLogPrintf("Remix camera hook installed\n");
    }
    else
    {
        s_originalRERenderScene = RE_RenderScene;
        RendererLogPrintf("WARN: failed to install Remix camera hook: %ld\n", status);
    }
}

static void uninstall_rmx_camera_hook()
{
    LONG status;

    if (!s_rmxCameraHookInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRERenderScene,
                              RE_RenderScene_RmxCameraHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove Remix camera hook: %ld\n", status);

    s_originalRERenderScene = RE_RenderScene;
    s_rmxCameraHookInstalled = false;
}

/*
 * RB_SurfaceFace, RB_SurfaceGrid, and RB_SurfaceTriangles all populate
 * tess.normal when shader->needsNormal is set.  Face expands its plane normal
 * per vertex; grid and triangles copy their source vertex normals.  Cache the
 * active shader at RB_BeginSurface, then force only this tessellation gate
 * while those static-surface handlers execute.
 */
typedef void (__cdecl *RBBeginSurfaceFn)(void* shader, void* fog);
typedef void (__cdecl *RBSurfaceFn)(void* surface);
static RBBeginSurfaceFn s_originalRBBeginSurface = RB_BeginSurface;
static RBSurfaceFn s_originalRBSurfaceFace = RB_SurfaceFace;
static RBSurfaceFn s_originalRBSurfaceGrid = RB_SurfaceGrid;
static RBSurfaceFn s_originalRBSurfaceTriangles = RB_SurfaceTriangles;
static void* s_activeTessShader = nullptr;
static bool s_staticSurfaceNormalHooksInstalled = false;
static const size_t SHADER_NEEDS_NORMAL_OFFSET = 0xbc;

static void __cdecl RB_BeginSurface_NormalCaptureHook(void* shader, void* fog)
{
    s_activeTessShader = shader;
    s_originalRBBeginSurface(shader, fog);
}

static void force_static_surface_normals(RBSurfaceFn original, void* surface)
{
    int* needsNormal = s_activeTessShader
        ? (int*)((byte*)s_activeTessShader + SHADER_NEEDS_NORMAL_OFFSET)
        : nullptr;
    int previousNeedsNormal = needsNormal ? *needsNormal : 0;

    if (needsNormal)
        *needsNormal = qtrue;

    original(surface);

    if (needsNormal)
        *needsNormal = previousNeedsNormal;
}

static void __cdecl RB_SurfaceFace_NormalHook(void* surface)
{
    force_static_surface_normals(s_originalRBSurfaceFace, surface);
}

static void __cdecl RB_SurfaceGrid_NormalHook(void* surface)
{
    force_static_surface_normals(s_originalRBSurfaceGrid, surface);
}

static void __cdecl RB_SurfaceTriangles_NormalHook(void* surface)
{
    force_static_surface_normals(s_originalRBSurfaceTriangles, surface);
}

static void install_static_surface_normal_hooks()
{
    LONG status;

    if (s_staticSurfaceNormalHooksInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRBBeginSurface,
                              RB_BeginSurface_NormalCaptureHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRBSurfaceFace,
                              RB_SurfaceFace_NormalHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRBSurfaceGrid,
                              RB_SurfaceGrid_NormalHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRBSurfaceTriangles,
                              RB_SurfaceTriangles_NormalHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_staticSurfaceNormalHooksInstalled = true;
        RendererLogPrintf("Static surface normal hooks installed\n");
    }
    else
    {
        s_originalRBBeginSurface = RB_BeginSurface;
        s_originalRBSurfaceFace = RB_SurfaceFace;
        s_originalRBSurfaceGrid = RB_SurfaceGrid;
        s_originalRBSurfaceTriangles = RB_SurfaceTriangles;
        s_activeTessShader = nullptr;
        RendererLogPrintf("WARN: failed to install static surface normal hooks: %ld\n",
                          status);
    }
}

static void uninstall_static_surface_normal_hooks()
{
    LONG status;

    if (!s_staticSurfaceNormalHooksInstalled)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRBSurfaceTriangles,
                              RB_SurfaceTriangles_NormalHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRBSurfaceGrid,
                              RB_SurfaceGrid_NormalHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRBSurfaceFace,
                              RB_SurfaceFace_NormalHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRBBeginSurface,
                              RB_BeginSurface_NormalCaptureHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove static surface normal hooks: %ld\n",
                          status);

    s_originalRBBeginSurface = RB_BeginSurface;
    s_originalRBSurfaceFace = RB_SurfaceFace;
    s_originalRBSurfaceGrid = RB_SurfaceGrid;
    s_originalRBSurfaceTriangles = RB_SurfaceTriangles;
    s_activeTessShader = nullptr;
    s_staticSurfaceNormalHooksInstalled = false;
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
static const uintptr_t EXE_RUNNING_FROM_ALICE2_CHECK = 0x4655F4;

typedef int (__cdecl *KeySetBindingFn)(int keyId, char* command);
typedef int (__cdecl *KeyStringToKeynumFn)(const char* keyName);

static KeySetBindingFn s_originalKeySetBinding =
    (KeySetBindingFn)EXE_KEY_SET_BINDING;
static bool s_consoleBindHooked = false;
static bool s_consoleKeyCheckPatched = false;
static byte s_originalConsoleKeyCheck[12];
static bool s_runningFromAlice2Patched = false;
static byte s_originalrunningFromAlice2[30];

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

static bool patch_running_from_alice2()
{
    // Disable the '-RunningFromAlice2' launch argument check
    byte* code = (byte*)EXE_RUNNING_FROM_ALICE2_CHECK;
    unsigned long restore;

    if (!s_runningFromAlice2Patched)
        memcpy(s_originalrunningFromAlice2, code, sizeof(s_originalrunningFromAlice2));

    if (!hook_unprotect(code, (int)sizeof(s_originalrunningFromAlice2), &restore))
        return false;
    
    memset(code, 0x90, sizeof(s_originalrunningFromAlice2));
    FlushInstructionCache(GetCurrentProcess(), code, sizeof(s_originalrunningFromAlice2));
    hook_protect(code, (int)sizeof(s_originalrunningFromAlice2), restore);

    s_runningFromAlice2Patched = true;
    RendererLogPrintf("RunningFromAlice2 was patched\n");
    return true;
}

static void uninstall_runningfromalice2()
{
    byte* code = (byte*)EXE_RUNNING_FROM_ALICE2_CHECK;
    unsigned long restore;

    if (s_runningFromAlice2Patched &&
        hook_unprotect(code, (int)sizeof(s_originalrunningFromAlice2), &restore))
    {
        memcpy(code, s_originalrunningFromAlice2, sizeof(s_originalrunningFromAlice2));
        FlushInstructionCache(GetCurrentProcess(), code, sizeof(s_originalrunningFromAlice2));
        hook_protect(code, (int)sizeof(s_originalrunningFromAlice2), restore);
        s_runningFromAlice2Patched = false;
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
typedef void (__cdecl *RMarkLeavesFn)();
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
static RMarkLeavesFn s_originalRMarkLeaves = nullptr;
static SurfIsOffscreenFn s_originalSurfIsOffscreen =
    (SurfIsOffscreenFn)SurfIsOffscreen;
static const uintptr_t s_rSkyRenderAddress = (uintptr_t)R_Sky_Render;
static bool s_skyPortalTraceHooked = false;
static bool s_skyPortalNovisHooked = false;
static renderer_cvar_t* s_forceSkyPortal = nullptr;
static unsigned int s_forcedSkyPortalTraceCount = 0;
static renderer_cvar_t** s_rNovisSlot = nullptr;
static bool s_skyPortalMarkLeavesArmed = false;
static unsigned int s_skyPortalNovisTraceCount = 0;

static bool address_in_renderer_image(const void* address);

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

/*
 * R_AddWorldSurfaces calls its private R_MarkLeaves at +0x30.  The latter
 * loads the renderer's r_novis cvar slot at +0x6f.  Both instruction shapes
 * are checked before using the relocated addresses, so this remains tied to
 * the linked renderer build rather than a fixed DLL base address.
 */
static bool recover_sky_portal_novis_targets()
{
    byte* addWorldSurfaces = (byte*)R_AddWorldSurfaces;
    byte* markLeaves;
    int32_t callDisplacement;
    uint32_t rNovisSlotAddress;

    if (s_originalRMarkLeaves && s_rNovisSlot)
        return true;

    if (!addWorldSurfaces ||
        addWorldSurfaces[0] != 0xa1 ||
        addWorldSurfaces[5] != 0x83 || addWorldSurfaces[6] != 0x78 ||
        addWorldSurfaces[7] != 0x20 || addWorldSurfaces[8] != 0x00 ||
        addWorldSurfaces[9] != 0x0f || addWorldSurfaces[10] != 0x84 ||
        addWorldSurfaces[0x30] != 0xe8)
    {
        RendererLogPrintf("WARN: R_AddWorldSurfaces signature mismatch; sky r_novis scope disabled\n");
        return false;
    }

    memcpy(&callDisplacement, addWorldSurfaces + 0x31, sizeof(callDisplacement));
    markLeaves = addWorldSurfaces + 0x35 + callDisplacement;
    if (!address_in_renderer_image(markLeaves) ||
        markLeaves[0] != 0x51 || markLeaves[1] != 0xa1 ||
        markLeaves[6] != 0x55 || markLeaves[7] != 0x33 ||
        markLeaves[8] != 0xed || markLeaves[9] != 0x57 ||
        markLeaves[10] != 0x39 || markLeaves[11] != 0x68 ||
        markLeaves[12] != 0x20 || markLeaves[0x6f] != 0xa1)
    {
        RendererLogPrintf("WARN: R_MarkLeaves signature mismatch at %p; sky r_novis scope disabled\n",
                          markLeaves);
        return false;
    }

    memcpy(&rNovisSlotAddress, markLeaves + 0x70, sizeof(rNovisSlotAddress));
    if (!address_in_renderer_image((const void*)(uintptr_t)rNovisSlotAddress))
    {
        RendererLogPrintf("WARN: recovered r_novis slot lies outside renderer image\n");
        return false;
    }

    s_originalRMarkLeaves = (RMarkLeavesFn)markLeaves;
    s_rNovisSlot = (renderer_cvar_t**)(uintptr_t)rNovisSlotAddress;
    RendererLogPrintf("Sky r_novis scope targets: R_MarkLeaves=%p, r_novis slot=%p\n",
                      markLeaves, s_rNovisSlot);
    return true;
}

static void __cdecl RMarkLeaves_SkyPortalNovisHook()
{
    renderer_cvar_t* rNovis;
    int savedNoVis;

    if (!s_skyPortalMarkLeavesArmed || !s_rNovisSlot)
    {
        s_originalRMarkLeaves();
        return;
    }

    /* Consume the arm before calling original: only the sky view's first
       PVS build is changed, never a recursively spawned portal/mirror view. */
    s_skyPortalMarkLeavesArmed = false;
    rNovis = *s_rNovisSlot;
    if (!rNovis || rNovis->integer == 0)
    {
        s_originalRMarkLeaves();
        return;
    }

    savedNoVis = rNovis->integer;
    rNovis->integer = 0;
    //if (s_skyPortalNovisTraceCount++ < 16)
    //    RendererLogPrintf("Sky portal PVS: temporarily r_novis %d -> 0\n", savedNoVis);

    s_originalRMarkLeaves();
    rNovis->integer = savedNoVis;
}

static void __cdecl RSkyRender_NovisHook()
{
    renderer_cvar_t* rNovis = s_rNovisSlot ? *s_rNovisSlot : nullptr;
    const bool previousArm = s_skyPortalMarkLeavesArmed;

    /* R_Sky_Render may early-out.  In that case the saved arm is simply
       restored and no main-view visibility state has been changed. */
    if (rNovis && rNovis->integer != 0)
        s_skyPortalMarkLeavesArmed = true;

    s_originalRSkyRender();
    s_skyPortalMarkLeavesArmed = previousArm;
}

static void install_sky_portal_novis_fix()
{
    LONG status;

    if (s_skyPortalNovisHooked || !recover_sky_portal_novis_targets())
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRSkyRender,
                              RSkyRender_NovisHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalRMarkLeaves,
                              RMarkLeaves_SkyPortalNovisHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status == NO_ERROR)
    {
        s_skyPortalNovisHooked = true;
        RendererLogPrintf("Sky portal r_novis PVS scope installed\n");
    }
    else
    {
        RendererLogPrintf("WARN: failed to install sky portal r_novis scope: %ld\n",
                          status);
        s_originalRSkyRender = R_Sky_Render;
        s_originalRMarkLeaves = nullptr;
        s_rNovisSlot = nullptr;
    }
}

static void uninstall_sky_portal_novis_fix()
{
    LONG status;

    if (!s_skyPortalNovisHooked)
        return;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRSkyRender,
                              RSkyRender_NovisHook);
    if (status == NO_ERROR)
        status = DetourDetach((PVOID*)&s_originalRMarkLeaves,
                              RMarkLeaves_SkyPortalNovisHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
        RendererLogPrintf("WARN: failed to remove sky portal r_novis scope: %ld\n",
                          status);

    s_originalRSkyRender = R_Sky_Render;
    s_originalRMarkLeaves = nullptr;
    s_rNovisSlot = nullptr;
    s_skyPortalMarkLeavesArmed = false;
    s_skyPortalNovisHooked = false;
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

/*
 * qsortFast is private to tr_main.  R_SortDrawSurfs invokes it for the front
 * and back draw-surface arrays with 8-byte drawSurf_t entries.  Resolve its
 * address through those calls: this survives the different final DLL layout
 * of Debug and Release builds without importing a private library symbol.
 */
typedef void (__cdecl *QsortFastFn)(void* base, uint32_t count,
                                    uint32_t elementSize);
static QsortFastFn s_originalQsortFast = nullptr;
static bool s_stableDrawSurfSortHooked = false;

static byte* recover_qsort_fast()
{
    byte* sortDrawSurfs = resolve_local_jump((byte*)R_SortDrawSurfs,
                                              "R_SortDrawSurfs");
    int32_t firstDisplacement;
    int32_t secondDisplacement;
    byte* firstTarget;
    byte* secondTarget;

    if (!sortDrawSurfs || !address_in_renderer_image(sortDrawSurfs))
        return nullptr;

    /* Alice tr_main.obj: push ebx/ebp/esi/edi; call qsortFast at +0x25/+0x36. */
    if (sortDrawSurfs[0] != 0x53 || sortDrawSurfs[1] != 0x55 ||
        sortDrawSurfs[2] != 0x56 || sortDrawSurfs[3] != 0x57 ||
        sortDrawSurfs[4] != 0x8b || sortDrawSurfs[5] != 0x7c ||
        sortDrawSurfs[6] != 0x24 || sortDrawSurfs[7] != 0x18 ||
        sortDrawSurfs[8] != 0xb8 || sortDrawSurfs[9] != 0x00 ||
        sortDrawSurfs[10] != 0x00 || sortDrawSurfs[11] != 0x01 ||
        sortDrawSurfs[12] != 0x00 || sortDrawSurfs[0x25] != 0xe8 ||
        sortDrawSurfs[0x36] != 0xe8)
    {
        RendererLogPrintf("WARN: R_SortDrawSurfs signature/call layout did not match\n");
        return nullptr;
    }

    memcpy(&firstDisplacement, sortDrawSurfs + 0x26, sizeof(firstDisplacement));
    memcpy(&secondDisplacement, sortDrawSurfs + 0x37, sizeof(secondDisplacement));
    firstTarget = sortDrawSurfs + 0x2a + firstDisplacement;
    secondTarget = sortDrawSurfs + 0x3b + secondDisplacement;

    if (firstTarget != secondTarget || !address_in_renderer_image(firstTarget))
    {
        RendererLogPrintf("WARN: R_SortDrawSurfs qsortFast targets do not match (%p, %p)\n",
                          firstTarget, secondTarget);
        return nullptr;
    }

    /* qsortFast: sub esp,0xf4; push edi; mov edi,[esp+0x100]; cmp edi,2. */
    if (firstTarget[0] != 0x81 || firstTarget[1] != 0xec ||
        firstTarget[2] != 0xf4 || firstTarget[3] != 0x00 ||
        firstTarget[4] != 0x00 || firstTarget[5] != 0x00 ||
        firstTarget[6] != 0x57 || firstTarget[7] != 0x8b ||
        firstTarget[8] != 0xbc || firstTarget[9] != 0x24 ||
        firstTarget[10] != 0x00 || firstTarget[11] != 0x01 ||
        firstTarget[12] != 0x00 || firstTarget[13] != 0x00 ||
        firstTarget[14] != 0x83 || firstTarget[15] != 0xff ||
        firstTarget[16] != 0x02)
    {
        RendererLogPrintf("WARN: recovered qsortFast signature did not match at %p\n",
                          firstTarget);
        return nullptr;
    }

    return firstTarget;
}

static void install_stable_draw_surf_sort()
{
    byte* qsortFast = recover_qsort_fast();
    LONG status;

    if (!qsortFast)
        return;

    s_originalQsortFast = (QsortFastFn)qsortFast;
    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalQsortFast,
                              StableDrawSurfQsortFastHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
    {
        RendererLogPrintf("WARN: failed to install stable drawSurf sort hook: %ld\n",
                          status);
        s_originalQsortFast = nullptr;
        return;
    }

    RendererInitStableDrawSurfSort((void*)s_originalQsortFast);
    s_stableDrawSurfSortHooked = true;
    RendererLogPrintf("Stable drawSurf sort installed: R_SortDrawSurfs=%p qsortFast=%p\n",
                      (void*)R_SortDrawSurfs, qsortFast);
}

static void uninstall_stable_draw_surf_sort()
{
    LONG status;

    if (s_stableDrawSurfSortHooked)
    {
        status = DetourTransactionBegin();
        if (status == NO_ERROR)
            status = DetourUpdateThread(GetCurrentThread());
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalQsortFast,
                                  StableDrawSurfQsortFastHook);
        if (status == NO_ERROR)
            status = DetourTransactionCommit();
        else
            DetourTransactionAbort();

        if (status != NO_ERROR)
            RendererLogPrintf("WARN: failed to remove stable drawSurf sort hook: %ld\n",
                              status);
    }

    RendererShutdownStableDrawSurfSort();
    s_originalQsortFast = nullptr;
    s_stableDrawSurfSortHooked = false;
}

/*
 * These are private static tr_shade functions from renderer.lib.  Resolve
 * them from their code, not linker names, so the hook keeps working in Debug
 * and Release builds where their final addresses differ.
 */
static byte* find_compute_colors()
{
    const byte* image = (const byte*)s_rendererModule;
    const IMAGE_DOS_HEADER* dos;
    const IMAGE_NT_HEADERS* nt;
    size_t imageSize;
    size_t offset;
    byte* found = nullptr;

    if (!image)
        return nullptr;

    dos = (const IMAGE_DOS_HEADER*)image;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE)
        return nullptr;

    nt = (const IMAGE_NT_HEADERS*)(image + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE)
        return nullptr;

    imageSize = nt->OptionalHeader.SizeOfImage;
    for (offset = 0; offset + 29 <= imageSize; ++offset)
    {
        byte* code = (byte*)image + offset;

        /* fld1; stack frame; pStage->rgbGen; jump table dispatch */
        if (code[0] != 0xd9 || code[1] != 0xe8 ||
            code[2] != 0x83 || code[3] != 0xec || code[4] != 0x10 ||
            code[5] != 0x55 || code[6] != 0x8b || code[7] != 0x6c ||
            code[8] != 0x24 || code[9] != 0x18 ||
            code[10] != 0x8b || code[11] != 0x85 ||
            code[12] != 0x98 || code[13] != 0x02 ||
            code[14] != 0x00 || code[15] != 0x00 ||
            code[16] != 0x48 || code[17] != 0x83 ||
            code[18] != 0xf8 || code[19] != 0x0f ||
            code[20] != 0x0f || code[21] != 0x87 ||
            code[26] != 0xff || code[27] != 0x24 || code[28] != 0x85)
        {
            continue;
        }

        if (found)
            return nullptr;
        found = code;
    }

    return found;
}

static byte* find_compute_texcoords()
{
    const byte* image = (const byte*)s_rendererModule;
    const IMAGE_DOS_HEADER* dos;
    const IMAGE_NT_HEADERS* nt;
    size_t imageSize;
    size_t offset;
    byte* found = nullptr;

    if (!image)
        return nullptr;

    dos = (const IMAGE_DOS_HEADER*)image;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE)
        return nullptr;

    nt = (const IMAGE_NT_HEADERS*)(image + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE)
        return nullptr;

    imageSize = nt->OptionalHeader.SizeOfImage;
    for (offset = 0; offset + 0x170 <= imageSize; ++offset)
    {
        byte* code = (byte*)image + offset;

        /* tr_shade's two-bundle tcGen loop and jump-table dispatch. */
        if (code[0] != 0x53 || code[1] != 0x55 || code[2] != 0x56 ||
            code[3] != 0x8b || code[4] != 0x74 || code[5] != 0x24 ||
            code[6] != 0x10 || code[7] != 0x57 ||
            code[8] != 0x33 || code[9] != 0xed || code[10] != 0xbf ||
            code[15] != 0x81 || code[16] != 0xc6 ||
            code[17] != 0x10 || code[18] != 0x01 ||
            code[19] != 0x00 || code[20] != 0x00 ||
            code[21] != 0xeb || code[22] != 0x09 ||
            code[23] != 0x8d || code[24] != 0xa4 || code[25] != 0x24 ||
            code[26] != 0x00 || code[27] != 0x00 ||
            code[28] != 0x00 || code[29] != 0x00 ||
            code[30] != 0x8b || code[31] != 0xff ||
            code[32] != 0x83 || code[33] != 0xbe ||
            code[34] != 0xf8 || code[35] != 0xfe ||
            code[36] != 0xff || code[37] != 0xff || code[38] != 0x00 ||
            code[39] != 0x0f || code[40] != 0x84 ||
            code[45] != 0x8b || code[46] != 0x06 || code[47] != 0x48 ||
            code[48] != 0x83 || code[49] != 0xf8 || code[50] != 0x05 ||
            code[51] != 0x0f || code[52] != 0x87 ||
            code[57] != 0xff || code[58] != 0x24 || code[59] != 0x85)
        {
            continue;
        }

        if (found)
            return nullptr;
        found = code;
    }

    return found;
}

typedef void (__cdecl *ComputeShaderStageFn)(void* stage);
typedef void (__cdecl *TurbulentTexCoordsFn)(const void* waveform,
                                              float* destination);
typedef void (__cdecl *TexcoordsModifierFn)(const void* modifier,
                                             float* destination);
typedef void (__cdecl *StageIteratorGenericFn)(void);

static ComputeShaderStageFn s_originalComputeColors = nullptr;
static ComputeShaderStageFn s_originalComputeTexCoords = nullptr;
static TurbulentTexCoordsFn s_originalTurbulentTexCoords =
    RB_CalcTurbulentTexCoords;
static TexcoordsModifierFn s_originalScaleTexCoords = RB_CalcScaleTexCoords;
static TexcoordsModifierFn s_originalScrollTexCoords = RB_CalcScrollTexCoords;
static TexcoordsModifierFn s_originalOffsetTexCoords = RB_CalcOffsetTexCoords;
static TexcoordsModifierFn s_originalTransformTexCoords = RB_CalcTransformTexCoords;
static StageIteratorGenericFn s_originalStageIteratorGeneric = RB_StageIteratorGeneric;
static bool s_remixShaderHooksInstalled = false;

static void install_remix_shader_hooks()
{
    byte* computeColors = find_compute_colors();
    byte* computeTexCoords = find_compute_texcoords();
    uint32_t currentEntityAddress;
    uint32_t backEndAddress;
    uint32_t projection2DAddress;
    uint32_t cameraMatrix;
    LONG status;

    if (!computeColors || !computeTexCoords)
    {
        RendererLogPrintf("WARN: Remix shader hook targets not found (colors=%p, texcoords=%p)\n",
                          computeColors, computeTexCoords);
        return;
    }

    /* mov ecx, [_backEnd + 0x518] in ComputeTexCoords at +0x168. */
    if (computeTexCoords[0x168] != 0x8b ||
        computeTexCoords[0x169] != 0x0d ||
        computeTexCoords[0x16e] != 0x81 ||
        computeTexCoords[0x16f] != 0xc1)
    {
        RendererLogPrintf("WARN: ComputeTexCoords backEnd signature mismatch at %p\n",
                          computeTexCoords);
        return;
    }

    memcpy(&currentEntityAddress, &computeTexCoords[0x16a],
           sizeof(currentEntityAddress));
    backEndAddress = currentEntityAddress - 0x518;
    /* Verified in Alice tr_backend.obj: backEnd.projection2D is +0x7ac. */
    projection2DAddress = backEndAddress + 0x7ac;
    if (!address_in_renderer_image((void*)(uintptr_t)projection2DAddress))
    {
        RendererLogPrintf("WARN: recovered backEnd.projection2D lies outside renderer image\n");
        return;
    }
    cameraMatrix = backEndAddress + 0x2a0;
    qind_mat_preferred_address((const void*)cameraMatrix);

    s_originalComputeColors = (ComputeShaderStageFn)computeColors;
    s_originalComputeTexCoords = (ComputeShaderStageFn)computeTexCoords;
    s_originalTurbulentTexCoords = RB_CalcTurbulentTexCoords;
    s_originalScaleTexCoords = RB_CalcScaleTexCoords;
    s_originalScrollTexCoords = RB_CalcScrollTexCoords;
    s_originalOffsetTexCoords = RB_CalcOffsetTexCoords;
    s_originalTransformTexCoords = RB_CalcTransformTexCoords;
    s_originalStageIteratorGeneric = RB_StageIteratorGeneric;

    status = DetourTransactionBegin();
    if (status == NO_ERROR)
        status = DetourUpdateThread(GetCurrentThread());
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalComputeColors,
                              RemixComputeColorsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalComputeTexCoords,
                              RemixComputeTexCoordsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalTurbulentTexCoords,
                              RemixTurbulentTexCoordsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalScaleTexCoords,
                              RemixScaleTexCoordsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalScrollTexCoords,
                              RemixScrollTexCoordsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalOffsetTexCoords,
                              RemixOffsetTexCoordsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalTransformTexCoords,
                              RemixTransformTexCoordsHook);
    if (status == NO_ERROR)
        status = DetourAttach((PVOID*)&s_originalStageIteratorGeneric,
                              RemixStageIteratorGenericHook);
    if (status == NO_ERROR)
        status = DetourTransactionCommit();
    else
        DetourTransactionAbort();

    if (status != NO_ERROR)
    {
        RendererLogPrintf("WARN: failed to install Remix shader hooks: %ld\n", status);
        s_originalComputeColors = nullptr;
        s_originalComputeTexCoords = nullptr;
        s_originalTurbulentTexCoords = RB_CalcTurbulentTexCoords;
        s_originalScaleTexCoords = RB_CalcScaleTexCoords;
        s_originalScrollTexCoords = RB_CalcScrollTexCoords;
        s_originalOffsetTexCoords = RB_CalcOffsetTexCoords;
        s_originalTransformTexCoords = RB_CalcTransformTexCoords;
        s_originalStageIteratorGeneric = RB_StageIteratorGeneric;
        return;
    }

    RendererInitRemixShaderHooks((void*)s_originalComputeColors,
                                 (void*)s_originalComputeTexCoords,
                                 (void*)s_originalTurbulentTexCoords,
                                 (void*)(uintptr_t)projection2DAddress);
    RendererInitRemixGpuUvTransformHooks((void*)s_originalScaleTexCoords,
                                         (void*)s_originalScrollTexCoords,
                                         (void*)s_originalOffsetTexCoords,
                                         (void*)s_originalTransformTexCoords,
                                         (void*)s_originalStageIteratorGeneric);
    s_remixShaderHooksInstalled = true;
    RendererLogPrintf("Remix shader hooks installed: colors %p, texcoords %p, projection2D %p, gpu UV modifiers enabled\n",
                      computeColors, computeTexCoords,
                      (void*)(uintptr_t)projection2DAddress);
}

static void uninstall_remix_shader_hooks()
{
    LONG status;

    if (s_remixShaderHooksInstalled)
    {
        status = DetourTransactionBegin();
        if (status == NO_ERROR)
            status = DetourUpdateThread(GetCurrentThread());
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalStageIteratorGeneric,
                                  RemixStageIteratorGenericHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalTransformTexCoords,
                                  RemixTransformTexCoordsHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalOffsetTexCoords,
                                  RemixOffsetTexCoordsHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalScrollTexCoords,
                                  RemixScrollTexCoordsHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalScaleTexCoords,
                                  RemixScaleTexCoordsHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalTurbulentTexCoords,
                                  RemixTurbulentTexCoordsHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalComputeTexCoords,
                                  RemixComputeTexCoordsHook);
        if (status == NO_ERROR)
            status = DetourDetach((PVOID*)&s_originalComputeColors,
                                  RemixComputeColorsHook);
        if (status == NO_ERROR)
            status = DetourTransactionCommit();
        else
            DetourTransactionAbort();

        if (status != NO_ERROR)
            RendererLogPrintf("WARN: failed to remove Remix shader hooks: %ld\n", status);
    }

    RendererShutdownRemixShaderHooks();
    s_originalComputeColors = nullptr;
    s_originalComputeTexCoords = nullptr;
    s_originalTurbulentTexCoords = RB_CalcTurbulentTexCoords;
    s_originalScaleTexCoords = RB_CalcScaleTexCoords;
    s_originalScrollTexCoords = RB_CalcScrollTexCoords;
    s_originalOffsetTexCoords = RB_CalcOffsetTexCoords;
    s_originalTransformTexCoords = RB_CalcTransformTexCoords;
    s_originalStageIteratorGeneric = RB_StageIteratorGeneric;
    s_remixShaderHooksInstalled = false;
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
        s_opengl32 = LoadLibrary("opengl32");
        logInit();
        rmx_interface_init(s_opengl32);
        configure_tess_array_addresses();
        install_load_world_map_hook();
        install_flashlight_command_hooks();
        install_rmx_dynamic_light_hooks();
        install_rmx_camera_hook();
        install_static_surface_normal_hooks();
        install_sepia_screenshot_fix();
        install_console_fix();
        patch_running_from_alice2();
        install_sky_portal_trace();
        install_sky_portal_novis_fix();
        install_glw_getvalidmodes();
        install_stable_draw_surf_sort();
        install_vertex_lighting_mode_hook();
        install_remix_shader_hooks();
        install_getrefapi();
        break;
    case DLL_PROCESS_DETACH:
        uninstall_static_surface_normal_hooks();
        uninstall_rmx_camera_hook();
        uninstall_rmx_dynamic_light_hooks();
        uninstall_flashlight_command_hooks();
        uninstall_load_world_map_hook();
        uninstall_remix_shader_hooks();
        uninstall_vertex_lighting_mode_hook();
        uninstall_stable_draw_surf_sort();
        uninstall_glw_getvalidmodes();
        uninstall_getrefapi();
        uninstall_sky_portal_novis_fix();
        uninstall_sky_portal_trace();
        uninstall_runningfromalice2();
        uninstall_console_fix();
        uninstall_sepia_screenshot_fix();
        logClose();
        if(s_opengl32) FreeLibrary(s_opengl32);
        s_opengl32 = nullptr;
        s_rendererModule = nullptr;
        break;
    default:
        break;
    }
    return TRUE;
}

static void QDECL a1_flashlight_toggle(void)
{
	rmx_flashlight_enable(-1);
	//play a switch sound
	ri.Cmd_ExecuteText(EXEC_APPEND, "play sound/ambience/special/padlock1.wav");
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
