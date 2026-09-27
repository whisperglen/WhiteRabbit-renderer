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
#define STAGE_BUNDLE_SIZE                     0x13c
#define BUNDLE_NUM_TEXMODS_OFFSET             0x1c
#define BUNDLE_TEXMODS_OFFSET                 0x20

#define GL_MATRIX_MODE                        0x0ba0
#define GL_TEXTURE                            0x1702
#define GL_TEXTURE0_ARB                       0x84c0
#define GL_ACTIVE_TEXTURE_ARB                 0x84e0

#define NUM_TEXTURE_BUNDLES                   2
#define MAX_GPU_TEXMOD_EVENTS                 32

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

#define TMOD_TRANSFORM                        1
#define TMOD_SCROLL                           3
#define TMOD_SCALE                            4
#define TMOD_STRETCH                          5
#define TMOD_ROTATE                           6
#define TMOD_OFFSET                           9

/* cvar_t::integer is at +0x20 in Alice's 32-bit ABI. */
typedef struct renderer_cvar_s {
    uint8_t reserved[0x20];
    int integer;
} renderer_cvar_t;

typedef void (__cdecl *shader_stage_fn)(void* stage);
typedef void (__cdecl *turbulent_texcoords_fn)(const void* waveform,
                                                float* destination);
typedef void (__cdecl *texcoords_modifier_fn)(const void* modifier,
                                               float* destination);
typedef void (__cdecl *stage_iterator_fn)(void);
typedef void (__stdcall *qgl_get_integerv_fn)(unsigned int pname, int* values);
typedef void (__stdcall *qgl_matrix_mode_fn)(unsigned int mode);
typedef void (__stdcall *qgl_load_identity_fn)(void);
typedef void (__stdcall *qgl_load_matrixf_fn)(const float* matrix);
typedef void (__stdcall *qgl_active_texture_fn)(unsigned int texture);

/*
 * Recovered from ComputeTexCoords and RB_CalcTransformTexCoords.  This is a
 * view of Alice's 0x4c-byte texModInfo_t record, not an address-dependent
 * copy of renderer memory.  The union at 0x40 is passed directly to scroll
 * and offset calculators by the original code.
 */
typedef struct alice_texmod_vec2_s {
    float s;
    float t;
} alice_texmod_vec2_t;

typedef struct alice_texmod_s {
    int type;                              /* 0x00 */
    uint8_t opaque04_to_17[0x14];          /* 0x04 */
    float matrix[2][2];                    /* 0x18 */
    alice_texmod_vec2_t translate;         /* 0x28 */
    alice_texmod_vec2_t scale;             /* 0x30 */
    uint8_t opaque38_to_3f[8];             /* 0x38 */
    union {
        alice_texmod_vec2_t scroll;
        alice_texmod_vec2_t offset;
    } movement;                            /* 0x40 */
    uint32_t rotate;                       /* 0x48 */
} alice_texmod_t;

typedef char alice_texmod_size_must_be_0x4c[
    (sizeof(alice_texmod_t) == 0x4c) ? 1 : -1];

static shader_stage_fn s_originalComputeColors;
static shader_stage_fn s_originalComputeTexCoords;
static turbulent_texcoords_fn s_originalTurbulentTexCoords;
static texcoords_modifier_fn s_originalScaleTexCoords;
static texcoords_modifier_fn s_originalScrollTexCoords;
static texcoords_modifier_fn s_originalOffsetTexCoords;
static texcoords_modifier_fn s_originalTransformTexCoords;
static stage_iterator_fn s_originalStageIteratorGeneric;
static int* s_backEndProjection2D;

static renderer_cvar_t* s_noVertexColors;
static renderer_cvar_t* s_turbulentTextures;
static renderer_cvar_t* s_environmentMapping;
static renderer_cvar_t* s_traceComputeColors;
static renderer_cvar_t* s_gpuUvTransform;
static renderer_cvar_t* s_gpuUvTransformSlot0;

/* The qgl variables belong to Alice's renderer library. */
extern qgl_get_integerv_fn qglGetIntegerv;
extern qgl_matrix_mode_fn qglMatrixMode;
extern qgl_load_identity_fn qglLoadIdentity;
extern qgl_load_matrixf_fn qglLoadMatrixf;
extern qgl_active_texture_fn qglActiveTextureARB;

typedef struct gpu_texmod_event_s {
    int type;
    int bundle;
} gpu_texmod_event_t;

static float s_textureMatrices[NUM_TEXTURE_BUNDLES][16];
static gpu_texmod_event_t s_gpuTexmodEvents[MAX_GPU_TEXMOD_EVENTS];
static int s_gpuTexmodEventCount;
static int s_gpuTexmodEventIndex;
static int s_gpuTexcoordsActive;
static int s_textureMatricesApplied;
static float s_refdefTimeSeconds;

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

static void matrix_identity(float* matrix)
{
    memset(matrix, 0, sizeof(float) * 16);
    matrix[0] = 1.0f;
    matrix[5] = 1.0f;
    matrix[10] = 1.0f;
    matrix[15] = 1.0f;
}

static int matrix_is_identity(const float* matrix)
{
    static float identity[16] = {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    return memcmp(matrix, identity, sizeof(identity)) == 0;
}

/*
 * Matches OpenGL's column-major texture-matrix composition.  This is kept
 * equivalent to the JediKnight implementation so modifiers remain ordered
 * exactly as Alice's CPU texcoord loop applies them.
 */
static void multiply_texture_matrix(int bundle, const float* matrix)
{
    float previous[16];
    float* destination;
    int row;
    int column;

    if (bundle < 0 || bundle >= NUM_TEXTURE_BUNDLES)
        return;

    destination = s_textureMatrices[bundle];
    memcpy(previous, destination, sizeof(previous));
    for (row = 0; row < 4; ++row)
    {
        for (column = 0; column < 4; ++column)
        {
            destination[row * 4 + column] =
                matrix[0 * 4 + column] * previous[row * 4 + 0] +
                matrix[1 * 4 + column] * previous[row * 4 + 1] +
                matrix[2 * 4 + column] * previous[row * 4 + 2] +
                matrix[3 * 4 + column] * previous[row * 4 + 3];
        }
    }
}

static int next_gpu_texmod_bundle(int type)
{
    gpu_texmod_event_t* event;

    if (!s_gpuTexcoordsActive || s_gpuTexmodEventIndex >= s_gpuTexmodEventCount)
        return -1;

    event = &s_gpuTexmodEvents[s_gpuTexmodEventIndex];
    if (event->type != type)
        return -1;

    ++s_gpuTexmodEventIndex;
    return event->bundle;
}

static void queue_gpu_texmod(int type, int bundle)
{
    if (s_gpuTexmodEventCount >= MAX_GPU_TEXMOD_EVENTS)
        return;

    s_gpuTexmodEvents[s_gpuTexmodEventCount].type = type;
    s_gpuTexmodEvents[s_gpuTexmodEventCount].bundle = bundle;
    ++s_gpuTexmodEventCount;
}

/*
 * ComputeTexCoords visits the two bundles in order.  Record the affine
 * modifier calls that Alice will make, so calculator hooks know which of the
 * two GL texture units receives each matrix without relying on tess addresses.
 */
static void queue_stage_gpu_texmods(const void* stage)
{
    int bundle;

    s_gpuTexmodEventCount = 0;
    s_gpuTexmodEventIndex = 0;

    if (!stage)
        return;

    for (bundle = 0; bundle < NUM_TEXTURE_BUNDLES; ++bundle)
    {
        const uint8_t* bundleData = (const uint8_t*)stage +
            STAGE_BUNDLE0_TCGEN_OFFSET + bundle * STAGE_BUNDLE_SIZE;
        int texmodCount = read_int(bundleData + BUNDLE_NUM_TEXMODS_OFFSET);
        const alice_texmod_t* texmods;
        int texmodIndex;

        memcpy(&texmods, bundleData + BUNDLE_TEXMODS_OFFSET, sizeof(texmods));
        if (!texmods || texmodCount <= 0)
            continue;

        for (texmodIndex = 0;
             texmodIndex < texmodCount && s_gpuTexmodEventCount < MAX_GPU_TEXMOD_EVENTS;
             ++texmodIndex)
        {
            int type = texmods[texmodIndex].type;

            switch (type)
            {
            case TMOD_SCALE:
            case TMOD_SCROLL:
            case TMOD_OFFSET:
                queue_gpu_texmod(type, bundle);
                break;
            case TMOD_TRANSFORM:
            case TMOD_STRETCH:
            case TMOD_ROTATE:
                /* Stretch and rotate calculate a transform then call this. */
                queue_gpu_texmod(TMOD_TRANSFORM, bundle);
                break;
            default:
                break;
            }
        }
    }
}

static int qgl_texture_matrix_api_available(void)
{
    return qglGetIntegerv && qglMatrixMode && qglLoadIdentity &&
           qglLoadMatrixf && qglActiveTextureARB;
}

static void clear_gl_texture_matrices(void)
{
    int savedMatrixMode;
    int savedActiveTexture;
    int bundle;

    if (!qgl_texture_matrix_api_available())
        return;

    qglGetIntegerv(GL_MATRIX_MODE, &savedMatrixMode);
    qglGetIntegerv(GL_ACTIVE_TEXTURE_ARB, &savedActiveTexture);
    qglMatrixMode(GL_TEXTURE);
    for (bundle = 0; bundle < NUM_TEXTURE_BUNDLES; ++bundle)
    {
        qglActiveTextureARB(GL_TEXTURE0_ARB + bundle);
        qglLoadIdentity();
    }
    qglMatrixMode((unsigned int)savedMatrixMode);
    qglActiveTextureARB((unsigned int)savedActiveTexture);
    s_textureMatricesApplied = 0;
}

static void load_gl_texture_matrices(void)
{
    int savedMatrixMode;
    int savedActiveTexture;
    int bundle;
    int sourceBundle = 0;
    int promoteToSlot0 = cvar_enabled(s_gpuUvTransformSlot0);

    if (!qgl_texture_matrix_api_available())
        return;

    qglGetIntegerv(GL_MATRIX_MODE, &savedMatrixMode);
    qglGetIntegerv(GL_ACTIVE_TEXTURE_ARB, &savedActiveTexture);
    if (promoteToSlot0)
    {
        for (bundle = 0; bundle < NUM_TEXTURE_BUNDLES; ++bundle)
        {
            if (!matrix_is_identity(s_textureMatrices[bundle]))
            {
                sourceBundle = bundle;
                break;
            }
        }
    }
    qglMatrixMode(GL_TEXTURE);
    for (bundle = 0; bundle < NUM_TEXTURE_BUNDLES; ++bundle)
    {
        qglActiveTextureARB(GL_TEXTURE0_ARB + bundle);
        if (promoteToSlot0 && bundle != 0)
            qglLoadIdentity();
        else
            qglLoadMatrixf(s_textureMatrices[promoteToSlot0 ? sourceBundle : bundle]);
    }
    qglMatrixMode((unsigned int)savedMatrixMode);
    qglActiveTextureARB((unsigned int)savedActiveTexture);
    s_textureMatricesApplied = 1;
}

static float texture_scroll_fraction(float value)
{
    int whole = (int)value;
    float fraction = value - (float)whole;

    return fraction < 0.0f ? fraction + 1.0f : fraction;
}

/* Alice uses 0x4996b438 as an entity-relative offset sentinel. */
static int is_static_texture_offset(const alice_texmod_vec2_t* values)
{
    uint32_t first;
    uint32_t second;

    memcpy(&first, &values->s, sizeof(first));
    memcpy(&second, &values->t, sizeof(second));
    return first != 0x4996b438U && second != 0x4996b438U;
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
    if (!s_gpuUvTransform)
        s_gpuUvTransform = (renderer_cvar_t*)ri.Cvar_Get(
            "rmx_gpu_uv_transform", "0", CVAR_ARCHIVE);
    if (!s_gpuUvTransformSlot0)
        s_gpuUvTransformSlot0 = (renderer_cvar_t*)ri.Cvar_Get(
            "rmx_gpu_uv_transform_slot0", "0", CVAR_ARCHIVE);

    RendererLogPrintf("Remix shader options: r_novertex_colors=%d, "
                      "r_turbulentTextures=%d, r_environmentMapping=%d, "
                      "rmx_gpu_uv_transform=%d, rmx_gpu_uv_transform_slot0=%d\n",
                      s_noVertexColors ? s_noVertexColors->integer : -1,
                      s_turbulentTextures ? s_turbulentTextures->integer : -1,
                      s_environmentMapping ? s_environmentMapping->integer : -1,
                      s_gpuUvTransform ? s_gpuUvTransform->integer : -1,
                      s_gpuUvTransformSlot0 ?
                          s_gpuUvTransformSlot0->integer : -1);
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
    int useGpuUvTransforms;

    if (!s_originalComputeTexCoords)
        return;

    useGpuUvTransforms = stage && cvar_enabled(s_gpuUvTransform) &&
                         qgl_texture_matrix_api_available();

    if (stage && s_environmentMapping && !cvar_enabled(s_environmentMapping))
    {
        originalBundle0TcGen = read_int((uint8_t*)stage + STAGE_BUNDLE0_TCGEN_OFFSET);
        originalBundle1TcGen = read_int((uint8_t*)stage + STAGE_BUNDLE1_TCGEN_OFFSET);
        replaceBundle0 = originalBundle0TcGen == TCGEN_ENVIRONMENT_MAPPED;
        replaceBundle1 = originalBundle1TcGen == TCGEN_ENVIRONMENT_MAPPED;

        if (replaceBundle0)
            write_int((uint8_t*)stage + STAGE_BUNDLE0_TCGEN_OFFSET, TCGEN_TEXTURE);
        if (replaceBundle1)
            write_int((uint8_t*)stage + STAGE_BUNDLE1_TCGEN_OFFSET, TCGEN_TEXTURE);
    }

    if (useGpuUvTransforms)
    {
        int bundle;

        for (bundle = 0; bundle < NUM_TEXTURE_BUNDLES; ++bundle)
            matrix_identity(s_textureMatrices[bundle]);
        queue_stage_gpu_texmods(stage);
        s_gpuTexcoordsActive = 1;
    }

    s_originalComputeTexCoords(stage);

    s_gpuTexcoordsActive = 0;
    s_gpuTexmodEventCount = 0;
    s_gpuTexmodEventIndex = 0;

    if (useGpuUvTransforms)
        load_gl_texture_matrices();

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

void __cdecl RemixScaleTexCoordsHook(const void* scale, float* destination)
{
    int bundle = next_gpu_texmod_bundle(TMOD_SCALE);

    if (bundle >= 0 && scale)
    {
        const alice_texmod_vec2_t* values = (const alice_texmod_vec2_t*)scale;
        const float matrix[16] = {
            values->s, 0.0f,      0.0f, 0.0f,
            0.0f,      values->t, 0.0f, 0.0f,
            0.0f,      0.0f,      1.0f, 0.0f,
            0.0f,      0.0f,      0.0f, 1.0f
        };
        multiply_texture_matrix(bundle, matrix);
        return;
    }

    if (s_originalScaleTexCoords)
        s_originalScaleTexCoords(scale, destination);
}

void __cdecl RemixScrollTexCoordsHook(const void* scrollSpeed, float* destination)
{
    int bundle = next_gpu_texmod_bundle(TMOD_SCROLL);

    if (bundle >= 0 && scrollSpeed)
    {
        const alice_texmod_vec2_t* values =
            (const alice_texmod_vec2_t*)scrollSpeed;
        const float matrix[16] = {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            texture_scroll_fraction(values->s * s_refdefTimeSeconds),
            texture_scroll_fraction(values->t * s_refdefTimeSeconds),
            0.0f, 1.0f
        };
        multiply_texture_matrix(bundle, matrix);
        return;
    }

    if (s_originalScrollTexCoords)
        s_originalScrollTexCoords(scrollSpeed, destination);
}

void __cdecl RemixOffsetTexCoordsHook(const void* offset, float* destination)
{
    int bundle = next_gpu_texmod_bundle(TMOD_OFFSET);

    if (bundle >= 0 && offset &&
        is_static_texture_offset((const alice_texmod_vec2_t*)offset))
    {
        const alice_texmod_vec2_t* values = (const alice_texmod_vec2_t*)offset;
        const float matrix[16] = {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            values->s, values->t, 0.0f, 1.0f
        };
        multiply_texture_matrix(bundle, matrix);
        return;
    }

    if (s_originalOffsetTexCoords)
        s_originalOffsetTexCoords(offset, destination);
}

void __cdecl RemixTransformTexCoordsHook(const void* modifier, float* destination)
{
    int bundle = next_gpu_texmod_bundle(TMOD_TRANSFORM);

    if (bundle >= 0 && modifier)
    {
        const alice_texmod_t* values = (const alice_texmod_t*)modifier;
        float matrix[16];

        matrix_identity(matrix);
        matrix[0] = values->matrix[0][0];
        matrix[1] = values->matrix[0][1];
        matrix[4] = values->matrix[1][0];
        matrix[5] = values->matrix[1][1];
        matrix[12] = values->translate.s;
        matrix[13] = values->translate.t;
        multiply_texture_matrix(bundle, matrix);
        return;
    }

    if (s_originalTransformTexCoords)
        s_originalTransformTexCoords(modifier, destination);
}

void __cdecl RemixStageIteratorGenericHook(void)
{
    if (s_originalStageIteratorGeneric)
        s_originalStageIteratorGeneric();

    if (s_textureMatricesApplied)
        clear_gl_texture_matrices();
}

void RendererSetRemixShaderTime(int milliseconds)
{
    s_refdefTimeSeconds = (float)milliseconds * 0.001f;
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

void RendererInitRemixGpuUvTransformHooks(void* originalScaleTexCoords,
                                          void* originalScrollTexCoords,
                                          void* originalOffsetTexCoords,
                                          void* originalTransformTexCoords,
                                          void* originalStageIteratorGeneric)
{
    s_originalScaleTexCoords = (texcoords_modifier_fn)originalScaleTexCoords;
    s_originalScrollTexCoords = (texcoords_modifier_fn)originalScrollTexCoords;
    s_originalOffsetTexCoords = (texcoords_modifier_fn)originalOffsetTexCoords;
    s_originalTransformTexCoords =
        (texcoords_modifier_fn)originalTransformTexCoords;
    s_originalStageIteratorGeneric =
        (stage_iterator_fn)originalStageIteratorGeneric;
}

void RendererShutdownRemixShaderHooks(void)
{
    if (s_textureMatricesApplied)
        clear_gl_texture_matrices();

    s_originalComputeColors = NULL;
    s_originalComputeTexCoords = NULL;
    s_originalTurbulentTexCoords = NULL;
    s_originalScaleTexCoords = NULL;
    s_originalScrollTexCoords = NULL;
    s_originalOffsetTexCoords = NULL;
    s_originalTransformTexCoords = NULL;
    s_originalStageIteratorGeneric = NULL;
    s_backEndProjection2D = NULL;
    s_noVertexColors = NULL;
    s_turbulentTextures = NULL;
    s_environmentMapping = NULL;
    s_gpuUvTransform = NULL;
    s_gpuUvTransformSlot0 = NULL;
    s_gpuTexmodEventCount = 0;
    s_gpuTexmodEventIndex = 0;
    s_gpuTexcoordsActive = 0;
    s_textureMatricesApplied = 0;
    s_refdefTimeSeconds = 0.0f;
}
