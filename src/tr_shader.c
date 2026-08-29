#include <stdint.h>
#include <string.h>

/*
 * This is a deliberately narrow view of Alice's temporary tr_shader state.
 * The renderer keeps these objects private in renderer.lib, so _dllmain.cpp
 * discovers their addresses from the verified FinishShader call site and
 * supplies them here.  All offsets are cross-checked against the linked
 * tr_shader.obj and realice's recovered Alice headers.
 */
#define MAX_SHADER_STAGES                 8
#define SHADER_STAGE_SIZE                 0x2ec

#define SHADER_LIGHTMAP_INDEX_OFFSET      0x040
#define SHADER_SORT_OFFSET                0x04c
#define SS_OPAQUE                         4

#define STAGE_ACTIVE_OFFSET               0x000
#define STAGE_BUNDLE0_TCGEN_OFFSET        0x110
#define STAGE_BUNDLE0_IS_LIGHTMAP_OFFSET  0x134
#define STAGE_RGBGEN_OFFSET               0x298
#define STAGE_ALPHAGEN_OFFSET             0x2b0
#define STAGE_STATEBITS_OFFSET            0x2b4

#define TCGEN_LIGHTMAP                    2
#define CGEN_IDENTITY                     1
#define CGEN_IDENTITY_LIGHTING            2
#define CGEN_EXACT_VERTEX                 5
#define CGEN_LIGHTING_DIFFUSE             10
#define AGEN_SKIP                         1
#define LIGHTMAP_NONE                     (-1)

#define GLS_SRCBLEND_BITS                 0x0000000fU
#define GLS_DSTBLEND_BITS                 0x000000f0U
#define GLS_DEPTHMASK_TRUE                0x00000100U

typedef void (__cdecl *vertex_lighting_collapse_fn)(void);

static uint8_t* s_unfoggedStages;
static uint8_t* s_shader;
static void* s_rVertexLightSlot;
static vertex_lighting_collapse_fn s_originalVertexLightingCollapse;

static int read_int(const void* address)
{
    int value;
    memcpy(&value, address, sizeof(value));
    return value;
}

static float read_float(const void* address)
{
    float value;
    memcpy(&value, address, sizeof(value));
    return value;
}

static unsigned int read_uint(const void* address)
{
    unsigned int value;
    memcpy(&value, address, sizeof(value));
    return value;
}

static void write_int(void* address, int value)
{
    memcpy(address, &value, sizeof(value));
}

static void write_uint(void* address, unsigned int value)
{
    memcpy(address, &value, sizeof(value));
}

static uint8_t* stage_at(int stage)
{
    return s_unfoggedStages + stage * SHADER_STAGE_SIZE;
}

/* shader_t::sort is a float, even though shaderSort_t supplies its values. */
static int shader_is_opaque(void)
{
    return read_float(s_shader + SHADER_SORT_OFFSET) == (float)SS_OPAQUE;
}

static int vertex_light_mode(void)
{
    int* cvar;

    if (!s_rVertexLightSlot)
        return 0;

    cvar = *(int**)s_rVertexLightSlot;
    return cvar ? cvar[8] : 0; /* cvar_t::integer at +0x20 */
}

/*
 * Port of the r_vertexLight == 2 part of the RTCW patch, expressed through
 * the recovered Alice ABI rather than a second incompatible renderer header.
 */
static int VertexLightingRemoveLightmaps(void)
{
    int stage;
    int nextOpenStage;
    int finalStageCount;

    for (stage = 0, nextOpenStage = 0, finalStageCount = 0;
         stage < MAX_SHADER_STAGES;
         ++stage)
    {
        uint8_t* source = stage_at(stage);
        uint8_t* destination;
        int rgbGen;

        if (!read_int(source + STAGE_ACTIVE_OFFSET))
            break;

        /* Preserve all non-lightmap stages, including terrain blend passes. */
        if (read_int(source + STAGE_BUNDLE0_IS_LIGHTMAP_OFFSET) ||
            read_int(source + STAGE_BUNDLE0_TCGEN_OFFSET) == TCGEN_LIGHTMAP)
        {
            continue;
        }

        destination = stage_at(nextOpenStage);
        if (destination != source)
            memmove(destination, source, SHADER_STAGE_SIZE);

        if (shader_is_opaque() && nextOpenStage == 0)
        {
            unsigned int stateBits = read_uint(destination + STAGE_STATEBITS_OFFSET);
            stateBits &= ~(GLS_SRCBLEND_BITS | GLS_DSTBLEND_BITS);
            stateBits |= GLS_DEPTHMASK_TRUE;
            write_uint(destination + STAGE_STATEBITS_OFFSET, stateBits);
            write_int(destination + STAGE_ALPHAGEN_OFFSET, AGEN_SKIP);
        }

        if (shader_is_opaque())
        {
            rgbGen = read_int(destination + STAGE_RGBGEN_OFFSET);
            if (rgbGen == CGEN_IDENTITY ||
                rgbGen == CGEN_IDENTITY_LIGHTING ||
                rgbGen == CGEN_LIGHTING_DIFFUSE)
            {
                write_int(destination + STAGE_RGBGEN_OFFSET,
                          read_int(s_shader + SHADER_LIGHTMAP_INDEX_OFFSET) == LIGHTMAP_NONE
                              ? CGEN_LIGHTING_DIFFUSE
                              : CGEN_EXACT_VERTEX);
            }
        }

        ++nextOpenStage;
        ++finalStageCount;
    }

    for (stage = finalStageCount; stage < MAX_SHADER_STAGES; ++stage)
        memset(stage_at(stage), 0, SHADER_STAGE_SIZE);

    return finalStageCount;
}

/* Called from the patched FinishShader call instruction. */
int __cdecl VertexLightingModeHook(void)
{
    if (vertex_light_mode() == 2 && s_unfoggedStages && s_shader)
        return VertexLightingRemoveLightmaps();

    if (s_originalVertexLightingCollapse)
        s_originalVertexLightingCollapse();

    return 1;
}

void __cdecl RendererInitVertexLightingModeHook(void* unfoggedStages,
                                                void* shader,
                                                void* rVertexLightSlot,
                                                void* originalVertexLightingCollapse)
{
    s_unfoggedStages = (uint8_t*)unfoggedStages;
    s_shader = (uint8_t*)shader;
    s_rVertexLightSlot = rVertexLightSlot;
    s_originalVertexLightingCollapse =
        (vertex_lighting_collapse_fn)originalVertexLightingCollapse;
}

void __cdecl RendererShutdownVertexLightingModeHook(void)
{
    s_unfoggedStages = NULL;
    s_shader = NULL;
    s_rVertexLightSlot = NULL;
    s_originalVertexLightingCollapse = NULL;
}
