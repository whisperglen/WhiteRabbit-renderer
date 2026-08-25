#pragma once

/*
 * Alice renderer ABI recovered from renderer.lib and cross-checked against
 * realice's FAKK2/Alice renderer headers. This is intentionally an ABI
 * header: entries whose complete prototype has not yet been verified are
 * represented by renderer_entry_t, but their slot and binary layout are
 * fixed and checked below.
 */

#include <stddef.h>

#include "qtypes.h"

typedef int qhandle_t;
typedef int fileHandle_t;

/* Opaque game-side TIKI records.  The renderer only exchanges pointers. */
typedef struct dtiki_s dtiki_t;

/*
 * The public render-entity block is copied verbatim by
 * RE_AddRefEntityToScene (0x73 dwords).  Keep this layout separate from the
 * renderer's 0x2cc-byte trRefEntity_t, whose final 0x100 bytes are derived
 * renderer state.
 */
typedef enum refEntityType_e
{
    RT_MODEL = 0,
    RT_POLY = 1,
    RT_SPRITE = 2,
    RT_BEAM = 3,
    RT_RAIL_CORE = 4,
    RT_RAIL_RINGS = 5,
    RT_LIGHTNING = 6,
    RT_PORTALSURFACE = 7
} refEntityType_t;

typedef struct refEntity_s
{
    refEntityType_t reType;             /* 0x000 */
    int renderfx;                       /* 0x004 */
    int unknown08;                      /* 0x008: Alice extension */
    qhandle_t hModel;                   /* 0x00c */
    vec3_t lightingOrigin;              /* 0x010 */
    float shadowPlane;                  /* 0x01c */
    axis_t axis;                        /* 0x020 */
    qboolean nonNormalizedAxes;         /* 0x044 */
    vec3_t origin;                      /* 0x048 */
    int animation;                      /* 0x054: current skeletal animation */
    int oldAnimation;                   /* 0x058 */
    unsigned short oldFrame;            /* 0x05c */
    unsigned short frame;               /* 0x05e */
    float scale;                        /* 0x060 */
    byte opaque64_to_e3[0x80];          /* controller/skin/TIKI state */
    int tikiHandle;                     /* 0x0e4: passed to TIKI_GetSkel */
    byte opaquee8_to_1cb[0xe4];
} refEntity_t;

#define MAX_MAP_AREA_BYTES 32
#define MAX_RENDER_STRINGS 8
#define MAX_RENDER_STRING_LENGTH 32

/*
 * RE_RenderScene retains the standard Q3 refdef prefix.  It copies the
 * 0x100-byte text block at 0x70 and consumes Alice-specific fields through
 * 0x1bc.  Their semantics still need recovery, so they remain opaque.
 */
typedef struct refdef_s
{
    int x, y, width, height;             /* 0x000 */
    float fov_x, fov_y;                  /* 0x010 */
    vec3_t vieworg;                      /* 0x018 */
    axis_t viewaxis;                     /* 0x024 */
    int time;                            /* 0x048 */
    int rdflags;                         /* 0x04c */
    byte areamask[MAX_MAP_AREA_BYTES];   /* 0x050 */
    char text[MAX_RENDER_STRINGS][MAX_RENDER_STRING_LENGTH]; /* 0x070 */
    byte aliceExtension[0x50];           /* 0x170 .. 0x1bf */
} refdef_t;

typedef struct refimport_s
{
    void (QDECL *Printf)(int printLevel, const char* format, ...);                 /* 00 */
    void (QDECL *Error)(int errorLevel, const char* format, ...);                  /* 01 */
    int  (QDECL *Milliseconds)(void);                                               /* 02 */
    void (QDECL *Hunk_Clear)(void);                                                 /* 03 */
    void* (QDECL *Hunk_Alloc)(int size);                                            /* 04 */
    void* (QDECL *Hunk_AllocateTempMemory)(int size);                               /* 05 */
    void (QDECL *Hunk_FreeTempMemory)(void* block);                                 /* 06 */
    void* (QDECL *Malloc)(int bytes);                                               /* 07 */
    void (QDECL *Free)(void* buffer);                                               /* 08 */
    void* (QDECL *Cvar_Get)(const char* name, const char* value, int flags);        /* 09 */
    void (QDECL *Cvar_Set)(const char* name, const char* value);                    /* 10 */
    void (QDECL *Cmd_AddCommand)(const char* name, void (QDECL *command)(void));    /* 11 */
    void (QDECL *Cmd_RemoveCommand)(const char* name);                              /* 12 */
    int  (QDECL *Cmd_Argc)(void);                                                   /* 13 */
    char* (QDECL *Cmd_Argv)(int index);                                             /* 14 */
    void (QDECL *Cmd_ExecuteText)(int when, const char* text);                      /* 15 */
    void (QDECL *CM_DrawDebugSurface)(void (QDECL *drawPoly)(int, int, float*));    /* 16 */
    int  (QDECL *FS_FOpenFileRead)(const char* name, fileHandle_t* file,
                                   qboolean unique, int flags);                     /* 17 */
    int  (QDECL *FS_Read)(void* buffer, int length, fileHandle_t file);             /* 18 */
    void (QDECL *FS_FCloseFile)(fileHandle_t file);                                 /* 19 */
    int  (QDECL *FS_Seek)(fileHandle_t file, long offset, int origin);              /* 20 */
    int  (QDECL *FS_FileIsInPAK)(const char* name, int* checksum);                  /* 21 */
    int  (QDECL *FS_ReadFile)(const char* name, void** buffer);                     /* 22 */
    void (QDECL *FS_FreeFile)(void* buffer);                                        /* 23 */
    char** (QDECL *FS_ListFiles)(const char* path, const char* extension, int* count); /* 24 */
    void (QDECL *FS_FreeFileList)(char** files);                                    /* 25 */
    void (QDECL *FS_WriteFile)(const char* path, const void* buffer, int size);     /* 26 */
    void* (QDECL *TIKI_GetAnim)(int tikiHandle);                                    /* 27 */
    void* (QDECL *TIKI_GetTiki)(int tikiHandle);                                    /* 28 */
    void (QDECL *TIKI_FreeTiki)(int tikiHandle);                                    /* 29 */
    int  (QDECL *TIKI_RegisterTiki)(const char* path);                              /* 30 */
    void (QDECL *TIKI_CalculateBounds)(dtiki_t* tiki, float scale, vec3_t mins,
                                       vec3_t maxs);                                 /* 31 */
    float (QDECL *TIKI_GlobalRadius)(int tikiHandle);                               /* 32 */
    void (QDECL *CM_BoxTrace)(void);                                                /* 33: prototype pending */
    const char* (QDECL *CM_EntityString)(void);                                     /* 34 */
    void (QDECL *CL_RefSetPerformanceCounters)(int, int, int, int, int, int);       /* 35 */
    void* DebugLines;                                                               /* 36 */
    int* numDebugLines;                                                             /* 37 */
    void* reserved38;                                                               /* 38 */
} refimport_t;

typedef void (QDECL *renderer_entry_t)(void);

/*
 * Alice's refexport_t has 54 entries. Slots 7 and 20 are Alice extensions
 * relative to the FAKK2/realice table: RefreshStaticShaderNoMip and
 * SetFull2DWindow.
 */
typedef struct refexport_s
{
    renderer_entry_t Shutdown;                        /* 00 */
    renderer_entry_t BeginRegistration;               /* 01 */
    renderer_entry_t RegisterModel;                   /* 02 */
    renderer_entry_t RegisterSkin;                    /* 03 */
    renderer_entry_t RegisterShader;                  /* 04 */
    renderer_entry_t RegisterShaderNoMip;             /* 05 */
    renderer_entry_t RefreshShaderNoMip;              /* 06 */
    renderer_entry_t RefreshStaticShaderNoMip;        /* 07 */
    renderer_entry_t EndRegistration;                 /* 08 */
    renderer_entry_t SetWorldVisData;                 /* 09 */
    renderer_entry_t LoadWorldMap;                    /* 10 */
    renderer_entry_t ClearScene;                      /* 11 */
    renderer_entry_t AddRefEntityToScene;             /* 12 */
    renderer_entry_t AddRefSpriteToScene;             /* 13 */
    renderer_entry_t AddPolyToScene;                  /* 14 */
    renderer_entry_t AddLightToScene;                 /* 15 */
    renderer_entry_t RenderScene;                     /* 16 */
    renderer_entry_t GetRenderEntity;                 /* 17 */
    renderer_entry_t SavePerformanceCounters;         /* 18 */
    renderer_entry_t SetColor;                        /* 19 */
    renderer_entry_t SetFull2DWindow;                 /* 20 */
    renderer_entry_t Set2DWindow;                     /* 21 */
    renderer_entry_t DrawStretchPic;                  /* 22 */
    renderer_entry_t DrawTilePic;                     /* 23 */
    renderer_entry_t DrawTilePicOffset;               /* 24 */
    renderer_entry_t StretchRaw;                      /* 25 */
    renderer_entry_t DebugLine;                       /* 26 */
    renderer_entry_t DrawBox;                         /* 27 */
    renderer_entry_t AddBox;                          /* 28 */
    renderer_entry_t BeginFrame;                      /* 29 */
    renderer_entry_t Scissor;                         /* 30 */
    renderer_entry_t DrawLineLoop;                    /* 31 */
    renderer_entry_t EndFrame;                        /* 32 */
    renderer_entry_t MarkFragments;                   /* 33 */
    renderer_entry_t LerpTag;                         /* 34 */
    renderer_entry_t ModelBounds;                     /* 35 */
    renderer_entry_t ModelRadius;                     /* 36 */
    renderer_entry_t TIKI_GetHandle;                  /* 37 */
    renderer_entry_t TIKI_FlushAll;                   /* 38 */
    renderer_entry_t DrawString;                      /* 39 */
    renderer_entry_t GetFontHeight;                   /* 40 */
    renderer_entry_t GetFontStringWidth;              /* 41 */
    renderer_entry_t LoadFont;                        /* 42 */
    renderer_entry_t SwipeBegin;                      /* 43 */
    renderer_entry_t SwipePoint;                      /* 44 */
    renderer_entry_t SwipeEnd;                        /* 45 */
    renderer_entry_t SetRenderTime;                   /* 46 */
    renderer_entry_t GetRenderTime;                   /* 47 */
    renderer_entry_t NoiseGet4f;                      /* 48 */
    renderer_entry_t SetMode;                         /* 49 */
    renderer_entry_t SetFullscreen;                   /* 50 */
    renderer_entry_t GetShaderWidth;                  /* 51 */
    renderer_entry_t GetShaderHeight;                 /* 52 */
    renderer_entry_t GetGraphicsInfo;                 /* 53 */
} refexport_t;

/* The renderer copies 0x1448 bytes for glConfig. Field recovery is pending. */
typedef struct glconfig_s
{
    byte opaque[0x1448];
} glconfig_t;

#if UINTPTR_MAX == 0xffffffffu
typedef char alice_refimport_size_must_be_0x9c[(sizeof(refimport_t) == 0x9c) ? 1 : -1];
typedef char alice_refexport_size_must_be_0xd8[(sizeof(refexport_t) == 0xd8) ? 1 : -1];
typedef char alice_tiki_get_anim_offset_must_be_0x6c[(offsetof(refimport_t, TIKI_GetAnim) == 0x6c) ? 1 : -1];
typedef char alice_glconfig_size_must_be_0x1448[(sizeof(glconfig_t) == 0x1448) ? 1 : -1];
typedef char alice_refentity_size_must_be_0x1cc[(sizeof(refEntity_t) == 0x1cc) ? 1 : -1];
typedef char alice_refentity_hmodel_offset_must_be_0x0c[(offsetof(refEntity_t, hModel) == 0x0c) ? 1 : -1];
typedef char alice_refentity_origin_offset_must_be_0x48[(offsetof(refEntity_t, origin) == 0x48) ? 1 : -1];
typedef char alice_refentity_tiki_offset_must_be_0xe4[(offsetof(refEntity_t, tikiHandle) == 0xe4) ? 1 : -1];
typedef char alice_refdef_text_offset_must_be_0x70[(offsetof(refdef_t, text) == 0x70) ? 1 : -1];
typedef char alice_refdef_observed_prefix_must_be_0x1c0[(sizeof(refdef_t) == 0x1c0) ? 1 : -1];
#endif
