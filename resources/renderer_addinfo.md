# Renderer implementation notes

## `r_ignoreFastPath` and vertex colours

`r_ignoreFastPath 1` forces Alice to use the generic shader-stage iterator
instead of its specialised one-pass vertex-lit and lightmapped multitexture
iterators.  This is useful with `r_novertex_colors 1`: animated character
materials commonly choose `RB_StageIteratorVertexLitTexture`, which calls
`RB_CalcDiffuseColor` directly and therefore bypasses `ComputeColors`.  The
generic iterator calls `ComputeColors`, so the Remix colour override affects
those characters as well.  The generic route is an intended renderer fallback,
but is slower; use it only when the reduced fast-path performance is
acceptable.  Sky selection happens before this decision and is unaffected.

Changing `r_ignoreFastPath` requires a map reload or `vid_restart`, because a
shader's iterator is selected when that shader is finalised.

## Remix shader-stage wrappers

`src/tr_shade.c` detours Alice's private `ComputeColors` and
`ComputeTexCoords` routines rather than maintaining copies of them.  With
`r_novertex_colors 1`, it temporarily changes a 3D stage to identity RGB and
disables fog colour adjustment while Alice computes the output, then restores
the stage; the original alpha generator remains active for intentional
transparency and 2D UI rendering is excluded.  With
`r_environmentMapping 0`, environment-mapped stages temporarily use
`TCGEN_TEXTURE`, preserving the source mesh's diffuse UVs instead of emitting
view-dependent reflection UVs.  With `r_turbulentTextures 0`, the turbulent UV
calculator is skipped, retaining base UVs and allowing subsequent texture
modifiers to run.  The defaults preserve the original renderer behaviour.

## Skies and portals

The important distinction is that Alice has two separate “portal” concepts:

1.  Renderer portals: mirrors, remote-camera views, etc.
2.  Ritual’s sky portal: the separate authored surreal sky-world view.
3.  Gameplay teleporters: game triggers plus their visible effect; these are not necessarily renderer portals.

`r_noportals 1` only controls the first category, so it is unsurprising that it does not remove Alice’s teleportation portals.

The normal render order is broadly:

RE_RenderScene
  └─ R_RenderView (main camera)
       ├─ collect world/entity surfaces and sort drawSurfs
       ├─ for portal/mirror surfaces:
       │    R_MirrorViewBySurface
       │      └─ recursively render portal view first
       └─ queue the main view draw-surface command

Backend executes each queued view
  ├─ RB_BeginDrawingView
  └─ RB_RenderDrawSurfList
       └─ each shader's stage iterator draws its surfaces
            └─ sky shaders use RB_StageIteratorSky

The ordinary Quake 3-style sky is not a final fullscreen clear. When the sorted sky surfaces are processed, `RB_StageIteratorSky` clips their triangles and draws the skybox/clouds at the far depth range. If no sky is drawn, the normal view generally only clears depth, not color—hence the old frame-history / hall-of-mirrors smear.

Relevant built-in cvars:

-   `r_fastsky 1`: skips `RB_StageIteratorSky`; it also disables normal renderer portal views.
-   `r_noportals 1`: makes `R_MirrorViewBySurface` refuse mirror/remote portal subviews.
-   `r_portalOnly 1`: debug mode—renders only a detected renderer portal view.
-   `r_novis` / `r_nocull`: affect what surfaces survive world visibility/frustum culling, but do not inherently guarantee the separate sky portal launches.
-   `r_showsky`: sky debug behavior.

The fix we made was for a second, Alice/Ritual-specific path:

visible world sky surface
  → R_Sky_AddSurf collects it
  → R_Sky_Render tests whether a collected sky surface is on-screen
  → if yes, render the authored sky-portal view

With `r_novis`/`r_nocull`, that final `SurfIsOffscreen` test could disagree with the surface collection. The portal view was then skipped depending on view direction. Our `r_forceSkyPortal 1` hook changes only that sky-portal gate—specifically the `ENTITYNUM_WORLD` test made from `R_Sky_Render`. It preserves the authored sky camera/origin and leaves ordinary mirrors/portals alone.

For Remix teleportation portals: because `r_noportals 1` changes nothing, they are probably a normal entity/shader/particle effect plus game-side teleport logic, rather than a `R_MirrorViewBySurface` portal view.

### Portal-sky Remix investigation

`r_noportals 1` disables standard renderer mirror/remote-camera views.  Alice
also has Ritual `isPortalSky` surfaces: the normal world collector diverts them
to `R_Sky_AddSurf`, and `R_Sky_Render` then issues a separate `R_RenderView`
from the authored sky camera.  This is outside the normal `r_noportals` path.

The portal-sky surface itself has no ordinary visible material: Alice diverts
it to `R_Sky_AddSurf` and obtains its appearance solely from the recursive
sky-camera render.  Consequently it cannot be globally converted to a normal
draw surface without removing the level's sky.

## Stable TIKI draw-surface records

Alice submits TIKI-model geometry through `R_AddTikiSurfaces`.  For each
visible TIKI mesh it builds a small, 12-byte surface record in the renderer's
`tess_surfaces` scratch ring:

```c
struct tiki_surface_record {
    uint32_t type;       // 11 (`SF_TIKI`)
    void* tikiMesh;
    void* oldFrame;
};
```

The original code advances that ring with a 2,048-entry mask:

```c
tess_surface_index = (tess_surface_index + 1) & 0x7ff;
```

It then gives `R_AddDrawSurf` a pointer to the scratch record.  The actual
surface is consumed later by the back end.  Under some scene workloads a ring
entry can be reused before its queued draw has been consumed.  The queued draw
then observes the later record's `tikiMesh` and frame pointers instead of the
ones it was submitted with.

This appeared as brief, recurring changes to the vertex and UV data of static
lantern meshes.  It was not a Remix or OpenGL-wrapper buffer issue: the
renderer had already selected a different TIKI mesh before issuing OpenGL.
The model handle, animation, and animation-frame state remained unchanged;
only the queued scratch record changed.

### Fix

`R_AddDrawSurf` is detoured in `_dllmain.cpp`.  When the submitted surface has
type `11`, the hook copies its 12-byte record into a private 16,384-record
per-frame pool and passes the stable copy to the original `R_AddDrawSurf`.
All other surface types are passed through unchanged.

The pool is reset at `RE_BeginFrame`, after the previous frame's back-end work
has completed.  This preserves the surface data for the lifetime of every
queued draw while avoiding a change to the original renderer's fixed scratch
array or its sort path.  A one-time warning is logged if the private pool is
ever exhausted in a frame.

### Preferred source-level fix

With access to the renderer source, the cleaner solution is to give each
queued TIKI draw ownership of its transient surface record.  At TIKI
submission time, copy the record into a frame/command-buffer arena instead of
passing a pointer into a modulo-wrapped global scratch array:

```c
void R_AddTikiDrawSurf(const srfTiki_t* source, shader_t* shader,
                       int fogNum, int dlightMap)
{
    srfTiki_t* stable = R_FrameAlloc(sizeof(*stable));
    *stable = *source;

    R_AddDrawSurf(stable, shader, fogNum, dlightMap);
}
```

The allocation arena must be owned by the render-command buffer and kept alive
until its back end has completed.  In an SMP renderer, use one arena per
in-flight command buffer/frame slot and recycle it only after the corresponding
completion fence.  Resetting at an arbitrary frame boundary is only safe when
the preceding back-end work is known to have finished.

An even more explicit design is for `drawSurf_t` to contain a copy of the
transient `srfTiki_t` payload (or a typed sidecar index) rather than a pointer
to mutable scratch memory.  Either approach removes the ownership ambiguity.

The essential constraints are:

- Never overwrite a surface record while a queued draw can still reference it.
- Do not rely on a modulo-wrapped fixed array for queued transient data.
- If a bounded arena is retained, detect overflow and grow or fail safely;
  never silently reuse a live record.
