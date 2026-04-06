// ===========================================
// Function: _R_SavePerformanceCounters @ 00008600
// ===========================================

void _R_SavePerformanceCounters(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&DAT_0000a35c;
  puVar3 = &_pc_save;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}



// ===========================================
// Function: _R_PerformanceCounters @ 00008616
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _R_PerformanceCounters(undefined4 param_1)

{
  int iVar1;
  
  if (*(int *)(__fps + 0x20) != 0) {
    _R_SumOfUsedImages(DAT_00002010 / 3,DAT_00002008,_DAT_0000a370,param_1);
    (*_DAT_00009f24)(_DAT_0000a36c / 3,_DAT_0000a364);
  }
  iVar1 = *(int *)(__r_speeds + 0x20);
  if (iVar1 == 0) {
    _memset(&DAT_0000ab88,0,0x44);
    _memset(&DAT_0000a35c,0,0x30);
    return;
  }
  if (iVar1 == 1) {
    iVar1 = _R_SumOfUsedImages((double)(_DAT_0000a374 / (float)(_DAT_0000b2b0 * _DAT_0000b2ac)));
    (*__ri)(0,s__i__i_shaders_surfs__i_leafs__i_,_DAT_0000a360,_DAT_0000a35c,_DAT_0000abb8,
            _DAT_0000a364,_DAT_0000a368 / 3,_DAT_0000a36c / 3,
            (double)iVar1 / ___real_412e848000000000);
  }
  else if (iVar1 == 2) {
    (*__ri)(0,s___patch___i_sin__i_sclip___i_sou,_DAT_0000ab88,_DAT_0000ab8c,_DAT_0000ab90,
            _DAT_0000ab94,_DAT_0000ab98);
    (*__ri)(0,s___md3___i_sin__i_sclip___i_sout_,_DAT_0000aba0,_DAT_0000aba4,_DAT_0000aba8,
            _DAT_0000abac,_DAT_0000abb0,_DAT_0000abb4);
  }
  else if (iVar1 == 3) {
    (*__ri)();
  }
  else if (iVar1 == 4) {
    if (_DAT_0000a378 != 0) {
      (*__ri)(0,s__dlight_srf__i__culled__i__verts,_DAT_0000abbc,_DAT_0000abc0,_DAT_0000a378);
      (*__ri)(0,s__realdlights_maps__i__texels__i_,_DAT_0000abc4,_DAT_0000abc8);
    }
  }
  else if (iVar1 == 5) {
    (*__ri)(0,s__zFar____0f_,(double)_DAT_0000a7c0);
  }
  else if (iVar1 == 6) {
    (*__ri)(0,s__flare_adds__i_tests__i_renders_,_DAT_0000a380,_DAT_0000a384);
  }
  _memset(&DAT_0000ab88,0,0x44);
  _memset(&DAT_0000a35c,0,0x30);
  return;
}



// ===========================================
// Function: _R_InitCommandBuffers @ 000088a3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_InitCommandBuffers(void)

{
  int iVar1;
  
  _DAT_0000b2c4 = 0;
  if (*(int *)(__r_smp + 0x20) != 0) {
    (*__ri)(0,s_Trying_SMP_acceleration____);
    iVar1 = _GLimp_SpawnRenderThread(&_RB_RenderThread);
    if (iVar1 != 0) {
      (*__ri)(0,s____succeeded__);
      _DAT_0000b2c4 = 1;
      return;
    }
    (*__ri)(0,s____failed__);
  }
  return;
}



// ===========================================
// Function: _R_ShutdownCommandBuffers @ 00008902
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ShutdownCommandBuffers(void)

{
  if (_DAT_0000b2c4 != 0) {
    _GLimp_WakeRenderer(0);
    _DAT_0000b2c4 = 0;
  }
  return;
}



// ===========================================
// Function: _R_IssueRenderCommands @ 00008920
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_IssueRenderCommands(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = *(int *)(&_backEndData + _DAT_00009e9c * 4);
  *(undefined4 *)(iVar1 + 0x1deab4 + *(int *)(iVar1 + 0x21eab4)) = 0;
  *(undefined4 *)(iVar1 + 0x21eab4) = 0;
  if (_DAT_0000b2c4 == 0) goto LAB_0000899c;
  if (__renderThreadActive == 0) {
    __c_blockedOnMain = __c_blockedOnMain + 1;
    if (*(int *)(__r_showSmp + 0x20) != 0) {
      pcVar2 = s__;
      goto LAB_0000898c;
    }
  }
  else {
    __c_blockedOnRender = __c_blockedOnRender + 1;
    if (*(int *)(__r_showSmp + 0x20) != 0) {
      pcVar2 = s_R;
LAB_0000898c:
      (*__ri)(0,pcVar2);
    }
  }
  _GLimp_FrontEndSleep();
LAB_0000899c:
  if (param_1 != 0) {
    _R_PerformanceCounters();
  }
  if (*(int *)(__r_skipBackEnd + 0x20) == 0) {
    if (_DAT_0000b2c4 == 0) {
      _RB_ExecuteRenderCommands();
      return;
    }
    _GLimp_WakeRenderer(iVar1 + 0x1deab4);
  }
  return;
}



// ===========================================
// Function: _R_SyncRenderThread @ 000089d2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SyncRenderThread(void)

{
  _GLimp_Resume();
  if (__tr != 0) {
    _R_IssueRenderCommands(0);
    if (_DAT_0000b2c4 != 0) {
      _GLimp_FrontEndSleep();
      return;
    }
  }
  return;
}



// ===========================================
// Function: _R_GetCommandBuffer @ 000089f9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_GetCommandBuffer(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(&_backEndData + (int)_DAT_00009e9c * 4);
  iVar2 = *(int *)(iVar1 + 0x21eab4) + param_1;
  if (0x40000 < iVar2 + 4) {
    if (0x3fffc < param_1) {
      (*_DAT_00009e9c)(0,s_R_GetCommandBuffer__bad_size__i,param_1);
    }
    return 0;
  }
  *(int *)(iVar1 + 0x21eab4) = iVar2;
  return (iVar2 - param_1) + iVar1 + 0x1deab4;
}



// ===========================================
// Function: _R_AddDrawSurfCmd @ 00008a4b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddDrawSurfCmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(&_backEndData + _DAT_00009e9c * 4);
  iVar1 = *(int *)(iVar2 + 0x21eab4);
  if (iVar1 + 0x474 < 0x40001) {
    *(int *)(iVar2 + 0x21eab4) = iVar1 + 0x470;
    puVar5 = (undefined4 *)(iVar1 + iVar2 + 0x1deab4);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[0x11a] = param_1;
      *puVar5 = 1;
      puVar5[0x11b] = param_2;
      puVar3 = (undefined4 *)&DAT_0000a988;
      puVar4 = puVar5;
      for (iVar2 = 0x79; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
      }
      puVar4 = (undefined4 *)&DAT_0000a5c4;
      puVar5 = puVar5 + 0x7a;
      for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
  }
  return;
}



// ===========================================
// Function: _R_AddSpriteSurfCmd @ 00008ac7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddSpriteSurfCmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(&_backEndData + _DAT_00009e9c * 4);
  iVar1 = *(int *)(iVar2 + 0x21eab4);
  if (iVar1 + 0x474 < 0x40001) {
    *(int *)(iVar2 + 0x21eab4) = iVar1 + 0x470;
    puVar5 = (undefined4 *)(iVar1 + iVar2 + 0x1deab4);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[0x11a] = param_1;
      *puVar5 = 2;
      puVar5[0x11b] = param_2;
      puVar3 = (undefined4 *)&DAT_0000a988;
      puVar4 = puVar5;
      for (iVar2 = 0x79; puVar4 = puVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
      }
      puVar4 = (undefined4 *)&DAT_0000a5c4;
      puVar5 = puVar5 + 0x7a;
      for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
  }
  return;
}



// ===========================================
// Function: _RE_BeginFrame @ 00008b43
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_BeginFrame(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (__tr == 0) {
    return;
  }
  __r_speeds = __r_speeds + 1;
  _DAT_00009f9c = 0;
  __R_SumOfUsedImages = 0;
  if (*(int *)(__r_measureOverdraw + 0x20) == 0) {
    if (*(int *)(__r_measureOverdraw + 0x14) == 0) goto LAB_00008c42;
    _R_SyncRenderThread();
    (*__qglDisable)(0xb90);
  }
  else {
    if (_DAT_0000b290 < 4) {
      (*__ri)(0,s_Warning__not_enough_stencil_bits,_DAT_0000b290);
      (*__GLimp_SpawnRenderThread)(s_r_measureOverdraw,s_0);
      *(undefined4 *)(__r_measureOverdraw + 0x14) = 0;
      goto LAB_00008c42;
    }
    if (*(int *)(__r_shadows + 0x20) == 2) {
      (*__ri)(0,s_Warning__stencil_shadows_and_ove);
      (*__GLimp_SpawnRenderThread)(s_r_measureOverdraw,s_0);
      *(undefined4 *)(__r_measureOverdraw + 0x14) = 0;
      goto LAB_00008c42;
    }
    _R_SyncRenderThread();
    (*__qglEnable)(0xb90);
    (*__qglStencilMask)(0xffffffff);
    (*__qglClearStencil)(0);
    (*__qglStencilFunc)(0x207,0,0xffffffff);
    (*__qglStencilOp)(0x1e00,0x1e02,0x1e02);
  }
  _GLimp_Suspend();
LAB_00008c42:
  *(undefined4 *)(__r_measureOverdraw + 0x14) = 0;
  if (*(int *)(__r_textureMode + 0x14) != 0) {
    _GLimp_Resume();
    if ((__tr != 0) && (_R_IssueRenderCommands(0), _DAT_0000b2c4 != 0)) {
      _GLimp_FrontEndSleep();
    }
    _GL_TextureMode(*(undefined4 *)(__r_textureMode + 4));
    *(undefined4 *)(__r_textureMode + 0x14) = 0;
    _GLimp_Suspend();
  }
  if (*(int *)(__r_gamma + 0x14) != 0) {
    *(undefined4 *)(__r_gamma + 0x14) = 0;
    _GLimp_Resume();
    if ((__tr != 0) && (_R_IssueRenderCommands(0), _DAT_0000b2c4 != 0)) {
      _GLimp_FrontEndSleep();
    }
    _R_SetColorMappings();
    _GLimp_Suspend();
  }
  if (*(int *)(__r_ignoreGLErrors + 0x20) == 0) {
    _GLimp_Resume();
    if ((__tr != 0) && (_R_IssueRenderCommands(0), _DAT_0000b2c4 != 0)) {
      _GLimp_FrontEndSleep();
    }
    iVar3 = (*__qglGetError)();
    if (iVar3 != 0) {
      (*_DAT_00009e9c)(0,s_RE_BeginFrame_____glGetError___f,iVar3);
    }
    _GLimp_Suspend();
  }
  iVar3 = *(int *)(&_backEndData + (int)_DAT_00009e9c * 4);
  iVar2 = *(int *)(iVar3 + 0x21eab4);
  if (iVar2 + 0xc < 0x40001) {
    puVar1 = (undefined4 *)(iVar2 + iVar3 + 0x1deab4);
    *(int *)(iVar3 + 0x21eab4) = iVar2 + 8;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 3;
      if (_DAT_0000b2c0 != 0) {
        if (param_1 == 1) {
          puVar1[1] = 0x402;
          return;
        }
        if (param_1 == 2) {
          puVar1[1] = 0x403;
          return;
        }
        (*_DAT_00009e9c)(0,s_RE_BeginFrame__Stereo_is_enabled,param_1);
        return;
      }
      if (param_1 != 0) {
        (*_DAT_00009e9c)(0,s_RE_BeginFrame__Stereo_is_disable,param_1);
      }
      iVar3 = _Q_stricmp(*(undefined4 *)(__r_drawBuffer + 4),s_GL_FRONT);
      puVar1[1] = (iVar3 != 0) + 0x404;
    }
  }
  return;
}



// ===========================================
// Function: _RE_EndFrame @ 00008dd0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_EndFrame(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (__tr != 0) {
    iVar2 = *(int *)(&_backEndData + _DAT_00009e9c * 4);
    iVar3 = *(int *)(iVar2 + 0x21eab4);
    if (iVar3 + 8 < 0x40001) {
      *(int *)(iVar2 + 0x21eab4) = iVar3 + 4;
      puVar1 = (undefined4 *)(iVar3 + iVar2 + 0x1deab4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = 4;
        _R_IssueRenderCommands(1);
        _R_ToggleSmpFrame();
        if (param_1 != (undefined4 *)0x0) {
          *param_1 = _DAT_0000abcc;
        }
        _DAT_0000abcc = 0;
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = _DAT_0000a8fc;
        }
        _DAT_0000a8fc = 0;
      }
    }
  }
  return;
}



