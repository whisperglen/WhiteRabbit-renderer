#include <stdint.h>
#include <string.h>

#include "alice_renderer_api.h"

/*
 * Alice's ComputeColors and ComputeTexCoords are private static functions in
 * renderer.lib.  The detour setup discovers their entries in _dllmain.cpp;
 * this file changes only the active shaderStage_t long enough for Alice's
 * original implementation to produce Remix-stable attributes.
 */
#define CVAR_ARCHIVE                         1

#define STAGE_RGBGEN_OFFSET                  0x298
#define STAGE_ALPHAGEN_OFFSET                 0x2b0
#define STAGE_STATEBITS_OFFSET                0x2b4
#define STAGE_ADJUST_COLORS_FOR_FOG_OFFSET    0x2b8
#define STAGE_BUNDLE0_TCGEN_OFFSET           0x110
#define STAGE_BUNDLE1_TCGEN_OFFSET           0x24c

#define CGEN_IDENTITY                        1
#define CGEN_EXACT_VERTEX                    5
#define CGEN_VERTEX                          6
#define CGEN_FOG                            11
#define CGEN_ALPHA_FOG                      16
#define AGEN_SKIP                            1
#define AGEN_VERTEX                          4
#define AGEN_ALPHA_FOG                      18
#define ACFF_NONE                            0
#define TCGEN_TEXTURE                        3
#define TCGEN_ENVIRONMENT_MAPPED             4

/* cvar_t::integer is at +0x20 in Alice's 32-bit ABI. */
typedef struct renderer_cvar_s {
    uint8_t reserved[0x20];
    int integer;
} renderer_cvar_t;

typedef void (__cdecl *shader_stage_fn)(void* stage);
typedef void (__cdecl *turbulent_texcoords_fn)(const void* waveform,
                                                float* destination);

static shader_stage_fn s_originalComputeColors;
static shader_stage_fn s_originalComputeTexCoords;
static turbulent_texcoords_fn s_originalTurbulentTexCoords;
static int* s_backEndProjection2D;

static renderer_cvar_t* s_noVertexColors;
static renderer_cvar_t* s_turbulentTextures;
static renderer_cvar_t* s_environmentMapping;
static renderer_cvar_t* s_traceComputeColors;

static int read_int(const void* address)
{
    int value;
    memcpy(&value, address, sizeof(value));
    return value;
}

static void write_int(void* address, int value)
{
    memcpy(address, &value, sizeof(value));
}

static int cvar_enabled(const renderer_cvar_t* cvar)
{
    return cvar && cvar->integer != 0;
}

/* FinishShader creates these fog-only passes after the material stage. */
static int should_neutralize_stage_rgb(int rgbGen, int alphaGen)
{
    return rgbGen != CGEN_FOG &&
           rgbGen != CGEN_ALPHA_FOG &&
           alphaGen != AGEN_ALPHA_FOG;
}

extern refimport_t ri;
extern void RendererLogPrintf(const char* fmt, ...);

void RendererInitRemixShaderOptions(void)
{
    if (!ri.Cvar_Get)
        return;

    if (!s_noVertexColors)
        s_noVertexColors = (renderer_cvar_t*)ri.Cvar_Get(
            "r_novertex_colors", "0", CVAR_ARCHIVE);
    if (!s_turbulentTextures)
        s_turbulentTextures = (renderer_cvar_t*)ri.Cvar_Get(
            "r_turbulentTextures", "1", CVAR_ARCHIVE);
    if (!s_environmentMapping)
        s_environmentMapping = (renderer_cvar_t*)ri.Cvar_Get(
            "r_environmentMapping", "1", CVAR_ARCHIVE);

    RendererLogPrintf("Remix shader options: r_novertex_colors=%d, "
                      "r_turbulentTextures=%d, r_environmentMapping=%d, ",
                      s_noVertexColors ? s_noVertexColors->integer : -1,
                      s_turbulentTextures ? s_turbulentTextures->integer : -1,
                      s_environmentMapping ? s_environmentMapping->integer : -1);
}

/*
 * Preserve 2D UI/font colours.  In a 3D view, forcing identity RGB makes
 * Alice's existing ComputeColors writes white RGB.  Some generated stages
 * pair a vertex-backed rgbGen with AGEN_SKIP: in that case the rgb generator
 * is also the only producer of alpha.  Temporarily making alphaGen vertex
 * preserves that alpha after identity RGB fills the colour buffer with FF.
 * Fog colour adjustment is disabled only during this calculation.
 */
void __cdecl RemixComputeColorsHook(void* stage)
{
    int originalRgbGen;
    int originalAlphaGen;
    int originalAdjustColorsForFog;
    int originalStateBits;
    int overrideApplied;

    if (!s_originalComputeColors)
        return;

    if (!stage)
    {
        s_originalComputeColors(stage);
        return;
    }

    originalRgbGen = read_int((uint8_t*)stage + STAGE_RGBGEN_OFFSET);
    originalAlphaGen = read_int((uint8_t*)stage + STAGE_ALPHAGEN_OFFSET);
    originalAdjustColorsForFog = read_int(
        (uint8_t*)stage + STAGE_ADJUST_COLORS_FOR_FOG_OFFSET);
    originalStateBits = read_int((uint8_t*)stage + STAGE_STATEBITS_OFFSET);
    overrideApplied = cvar_enabled(s_noVertexColors) &&
                      !(s_backEndProjection2D && *s_backEndProjection2D) &&
                      should_neutralize_stage_rgb(originalRgbGen,
                                                  originalAlphaGen);

    if (!overrideApplied)
    {
        s_originalComputeColors(stage);
        return;
    }

    write_int((uint8_t*)stage + STAGE_RGBGEN_OFFSET, CGEN_IDENTITY);
    if (originalAlphaGen == AGEN_SKIP &&
        (originalRgbGen == CGEN_EXACT_VERTEX || originalRgbGen == CGEN_VERTEX))
    {
        write_int((uint8_t*)stage + STAGE_ALPHAGEN_OFFSET, AGEN_VERTEX);
    }
    write_int((uint8_t*)stage + STAGE_ADJUST_COLORS_FOR_FOG_OFFSET, ACFF_NONE);
    s_originalComputeColors(stage);
    write_int((uint8_t*)stage + STAGE_RGBGEN_OFFSET, originalRgbGen);
    write_int((uint8_t*)stage + STAGE_ALPHAGEN_OFFSET, originalAlphaGen);
    write_int((uint8_t*)stage + STAGE_ADJUST_COLORS_FOR_FOG_OFFSET,
              originalAdjustColorsForFog);
}

/*
 * Environment mapping is view-dependent.  When disabled, use the surface's
 * first (diffuse) UV set instead of writing zeroes, so Remix sees stable,
 * original mesh UVs.  Restore the shader stage immediately after Alice has
 * filled tess.svars.texcoords.
 */
void __cdecl RemixComputeTexCoordsHook(void* stage)
{
    int originalBundle0TcGen;
    int originalBundle1TcGen;
    int replaceBundle0 = 0;
    int replaceBundle1 = 0;

    if (!s_originalComputeTexCoords)
        return;

    if (!stage || !s_environmentMapping || cvar_enabled(s_environmentMapping))
    {
        s_originalComputeTexCoords(stage);
        return;
    }

    originalBundle0TcGen = read_int((uint8_t*)stage + STAGE_BUNDLE0_TCGEN_OFFSET);
    originalBundle1TcGen = read_int((uint8_t*)stage + STAGE_BUNDLE1_TCGEN_OFFSET);
    replaceBundle0 = originalBundle0TcGen == TCGEN_ENVIRONMENT_MAPPED;
    replaceBundle1 = originalBundle1TcGen == TCGEN_ENVIRONMENT_MAPPED;

    if (replaceBundle0)
        write_int((uint8_t*)stage + STAGE_BUNDLE0_TCGEN_OFFSET, TCGEN_TEXTURE);
    if (replaceBundle1)
        write_int((uint8_t*)stage + STAGE_BUNDLE1_TCGEN_OFFSET, TCGEN_TEXTURE);

    s_originalComputeTexCoords(stage);

    if (replaceBundle0)
        write_int((uint8_t*)stage + STAGE_BUNDLE0_TCGEN_OFFSET, originalBundle0TcGen);
    if (replaceBundle1)
        write_int((uint8_t*)stage + STAGE_BUNDLE1_TCGEN_OFFSET, originalBundle1TcGen);
}

/* Keep the original UVs accumulated before TMOD_TURBULENT and run later mods. */
void __cdecl RemixTurbulentTexCoordsHook(const void* waveform, float* destination)
{
    if ((!s_turbulentTextures || cvar_enabled(s_turbulentTextures)) &&
        s_originalTurbulentTexCoords)
        s_originalTurbulentTexCoords(waveform, destination);
}

void RendererInitRemixShaderHooks(void* originalComputeColors,
                                  void* originalComputeTexCoords,
                                  void* originalTurbulentTexCoords,
                                  void* backEndProjection2D)
{
    s_originalComputeColors = (shader_stage_fn)originalComputeColors;
    s_originalComputeTexCoords = (shader_stage_fn)originalComputeTexCoords;
    s_originalTurbulentTexCoords =
        (turbulent_texcoords_fn)originalTurbulentTexCoords;
    s_backEndProjection2D = (int*)backEndProjection2D;
}

void RendererShutdownRemixShaderHooks(void)
{
    s_originalComputeColors = NULL;
    s_originalComputeTexCoords = NULL;
    s_originalTurbulentTexCoords = NULL;
    s_backEndProjection2D = NULL;
    s_noVertexColors = NULL;
    s_turbulentTextures = NULL;
    s_environmentMapping = NULL;
}
