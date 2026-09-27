# WhiteRabbit-renderer
Compile the renderer lib of AMG-A1 HD into a dll

## Improvements for Remix:
- UI auto detection: does not need Textures marked as UI
- Sky auto detection: this needs to be enabled in Alt-X menu, and the black starry-sky texture must be Ignored
- dynamic lights are passed on to remix (intensity and radius can be configured via Alt-C menu)
- on load map, remix options can be changed (they are loaded from ini; see [rtxconf.default] -> put ALL defaults here, then add customizations to [rtxconf.mapname]; use same format as rtx.conf)
- added a flashlight (bind f rmx_flashlight_toggle)
- added some surface normals (some geometry still shows hard edges)
- gpu texture transforms (some animated textures are visible in remix, mark them as decals)
- environment (shininess) maps can be disabled and Ignored (r_environmentMaps 0)
- turbulent textures animation can be disabled (not sure how helpful; r_turbulentTextures 0)

### TODOs
- some animated textures still do not render
- r_novis 1 shows all level geometry, I need to implement the AABB fixes from RTCW
- may need better normals for some surfaces