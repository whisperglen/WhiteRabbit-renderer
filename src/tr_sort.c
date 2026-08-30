#include <stdint.h>
#include <stdlib.h>

/* Alice drawSurf_t is a packed sort key followed by the surface pointer. */
typedef struct renderer_draw_surf_s {
    uint32_t sort;
    const void* surface;
} renderer_draw_surf_t;

typedef void (__cdecl *qsort_fast_fn)(void* base, uint32_t count,
                                      uint32_t elementSize);

static qsort_fast_fn s_originalQsortFast;

/*
 * qsortFast compares only sort.  Ties therefore emerge in an implementation-
 * dependent order.  Surface addresses are stable for a loaded map and make
 * every distinct draw surface a deterministic secondary key.
 */
static int __cdecl compare_draw_surfs(const void* left, const void* right)
{
    const renderer_draw_surf_t* s1 = (const renderer_draw_surf_t*)left;
    const renderer_draw_surf_t* s2 = (const renderer_draw_surf_t*)right;
    const uintptr_t surface1 = (uintptr_t)s1->surface;
    const uintptr_t surface2 = (uintptr_t)s2->surface;

    if (s1->sort < s2->sort)
        return -1;
    if (s1->sort > s2->sort)
        return 1;
    if (surface1 < surface2)
        return -1;
    if (surface1 > surface2)
        return 1;
    return 0;
}

void __cdecl StableDrawSurfQsortFastHook(void* base, uint32_t count,
                                         uint32_t elementSize)
{
    if (base && count > 1 && elementSize == sizeof(renderer_draw_surf_t))
    {
        qsort(base, count, elementSize, compare_draw_surfs);
        return;
    }

    /* Keep the private utility usable if a non-draw-surface caller exists. */
    if (s_originalQsortFast)
        s_originalQsortFast(base, count, elementSize);
}

void __cdecl RendererInitStableDrawSurfSort(void* originalQsortFast)
{
    s_originalQsortFast = (qsort_fast_fn)originalQsortFast;
}

void __cdecl RendererShutdownStableDrawSurfSort(void)
{
    s_originalQsortFast = NULL;
}
