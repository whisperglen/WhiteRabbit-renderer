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
