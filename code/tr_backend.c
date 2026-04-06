// ===========================================
// Function: _GL_Bind @ 0000a600
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_Bind(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    (*__ri)(3,s_GL_Bind__NULL_image_);
    uVar1 = *(undefined4 *)(__qglDisable + 0x50);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x50);
  }
  if (((__r_nobind != 0) && (*(int *)(__r_nobind + 0x20) != 0)) && (_DAT_0000cd2c != 0)) {
    uVar1 = *(undefined4 *)(_DAT_0000cd2c + 0x50);
  }
  if (param_1 != 0) {
    *(code **)(param_1 + 0x54) = __ri;
  }
  *(undefined4 *)(&_glState + __r_nobind * 4) = uVar1;
  (*__qglEnable)(0xde1);
  (*__qglBindTexture)(0xde1,uVar1);
  return;
}



// ===========================================
// Function: _GL_SelectTexture @ 0000a676
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_SelectTexture(int param_1)

{
  if (__r_nobind != param_1) {
    if (param_1 == 0) {
      (*__qglActiveTextureARB)(&DAT_000084c0);
      (*__qglClientActiveTextureARB)(&DAT_000084c0);
      __r_nobind = param_1;
      return;
    }
    if (param_1 == 1) {
      (*__qglActiveTextureARB)(&DAT_000084c1);
      (*__qglClientActiveTextureARB)(&DAT_000084c1);
      __r_nobind = param_1;
      return;
    }
    (*_DAT_0000cd04)(1,s_GL_SelectTexture__unit____i,param_1);
    __r_nobind = param_1;
  }
  return;
}



// ===========================================
// Function: _GL_BindMultitexture @ 0000a6e1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_BindMultitexture(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_3 + 0x50);
  iVar2 = *(int *)(param_1 + 0x50);
  if ((*(int *)(__r_nobind + 0x20) != 0) && (_DAT_0000cd2c != 0)) {
    iVar1 = *(int *)(_DAT_0000cd2c + 0x50);
    iVar2 = iVar1;
  }
  if (_DAT_0000ccec != iVar1) {
    if (__r_nobind != 1) {
      (*__qglActiveTextureARB)(&DAT_000084c1);
      (*__qglClientActiveTextureARB)(&DAT_000084c1);
      __r_nobind = 1;
    }
    *(undefined4 *)(param_3 + 0x54) = __ri;
    _DAT_0000ccec = iVar1;
    (*__qglBindTexture)(0xde1,iVar1);
  }
  if (__glState != iVar2) {
    if (__r_nobind != 0) {
      (*__qglActiveTextureARB)(&DAT_000084c0);
      (*__qglClientActiveTextureARB)(&DAT_000084c0);
      __r_nobind = 0;
    }
    *(undefined4 *)(param_1 + 0x54) = __ri;
    __glState = iVar2;
    (*__qglBindTexture)(0xde1,iVar2);
  }
  return;
}



// ===========================================
// Function: _GL_Cull @ 0000a7ab
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_Cull(int param_1)

{
  if (__ri != param_1) {
    __ri = param_1;
    if (param_1 == 2) {
      (*__qglDisable)();
      return;
    }
    (*__qglEnable)(0xb44);
    if (param_1 == 1) {
      if (_DAT_0000cfb8 == 0) {
LAB_0000a7e4:
        (*__qglCullFace)(0x405);
        return;
      }
    }
    else if (_DAT_0000cfb8 != 0) goto LAB_0000a7e4;
    (*__qglCullFace)(0x404);
  }
  return;
}



// ===========================================
// Function: _GL_TexEnv @ 0000a807
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_TexEnv(undefined *param_1)

{
  bool bVar1;
  
  if (param_1 == *(undefined **)(&_tr + __r_nobind * 4)) {
    return;
  }
  *(undefined **)(&_tr + __r_nobind * 4) = param_1;
  if ((int)param_1 < 0x2102) {
    if ((0x20ff < (int)param_1) || (param_1 == (undefined *)0x104)) goto LAB_0000a85e;
    bVar1 = param_1 == (undefined *)0x1e01;
  }
  else {
    if (param_1 == &DAT_00008503) goto LAB_0000a85e;
    bVar1 = param_1 == &DAT_00008570;
  }
  if (!bVar1) {
    (*_DAT_0000cd04)(1,s_GL_TexEnv__invalid_env___d__pass,param_1);
    return;
  }
LAB_0000a85e:
  (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00002200,
                  (float)(int)param_1);
  return;
}



// ===========================================
// Function: _GL_State @ 0000a877
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_State(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 uVar6;
  float fVar7;
  undefined4 uVar8;
  
  uVar2 = param_1;
  uVar3 = ((uint)__qglActiveTextureARB | param_1) ^ _DAT_0000cd0c;
  if (uVar3 == 0) {
    return;
  }
  if ((uVar3 & 0x800) != 0) {
    if ((param_1 & 0x800) == 0) {
      uVar8 = 0x203;
    }
    else {
      uVar8 = 0x202;
    }
    (*__qglDepthFunc)(uVar8);
  }
  param_1._0_1_ = (char)uVar3;
  if ((char)param_1 != '\0') {
    if ((char)uVar2 == '\0') {
      (*__qglDisable)(0xbe2);
    }
    else {
      switch(uVar2 & 0xf) {
      case 1:
        uVar8 = 0;
        break;
      case 2:
        uVar8 = 1;
        break;
      case 3:
        uVar8 = 0x306;
        break;
      case 4:
        uVar8 = 0x307;
        break;
      case 5:
        uVar8 = 0x302;
        break;
      case 6:
        uVar8 = 0x303;
        break;
      case 7:
        uVar8 = 0x304;
        break;
      case 8:
        uVar8 = 0x305;
        break;
      case 9:
        uVar8 = 0x308;
        break;
      default:
        uVar8 = 1;
        (*_DAT_0000cd04)(1,s_GL_State__invalid_src_blend_stat);
      }
      switch(uVar2 & 0xf0) {
      case 0x10:
        uVar6 = 0;
        break;
      case 0x20:
        uVar6 = 1;
        break;
      case 0x30:
        uVar6 = 0x300;
        break;
      case 0x40:
        uVar6 = 0x301;
        break;
      case 0x50:
        uVar6 = 0x302;
        break;
      case 0x60:
        uVar6 = 0x303;
        break;
      case 0x70:
        uVar6 = 0x304;
        break;
      case 0x80:
        uVar6 = 0x305;
        break;
      default:
        uVar6 = 1;
        (*_DAT_0000cd04)(1,s_GL_State__invalid_dst_blend_stat);
      }
      (*__qglEnable)(0xbe2);
      (*__qglBlendFunc)(uVar8,uVar6);
    }
  }
  if ((uVar3 & 0x100) != 0) {
    (*__qglDepthMask)((uVar2 & 0x100) != 0);
  }
  if ((uVar3 & 0x200) != 0) {
    if ((uVar2 & 0x200) == 0) {
      uVar8 = 0x1b02;
    }
    else {
      uVar8 = 0x1b01;
    }
    (*__qglPolygonMode)(0x408,uVar8);
  }
  if ((uVar3 & 0x400) != 0) {
    if ((uVar2 & 0x400) == 0) {
      (*__qglEnable)(0xb71);
    }
    else {
      (*__qglDisable)();
    }
  }
  if ((uVar3 & 0x6000) != 0) {
    if ((uVar2 & 0x4000) == 0) {
      if ((uVar2 & 0x2000) == 0) {
        puVar4 = &_s_flipMatrix;
        uVar8 = ___real_46040000;
        if (*(undefined **)(&_tr + __r_nobind * 4) != &_s_flipMatrix) goto LAB_0000ab7b;
      }
      else {
        if (_DAT_0000cd04 != (code *)&`GL_State'::__l27::value) {
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008571,
                          ___real_47057500);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008572,
                          ___real_46040000);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008580,
                          ___real_47057700);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008590,
                          ___real_44400000);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008581,
                          ___real_45b81000);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008591,
                          ___real_44400000);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008582,
                          ___real_47057700);
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00008592,
                          ___real_44408000);
          _DAT_0000cd04 = (code *)&`GL_State'::__l27::value;
        }
        puVar4 = &DAT_00008570;
        uVar8 = ___real_47057000;
        if (*(undefined **)(&_tr + __r_nobind * 4) != &DAT_00008570) {
LAB_0000ab7b:
          *(undefined **)(&_tr + __r_nobind * 4) = puVar4;
          (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000022ec + 0x14,&DAT_00002200,uVar8);
        }
      }
    }
    else {
      puVar4 = &DAT_00008503;
      uVar8 = ___real_47050300;
      if (*(undefined **)(&_tr + __r_nobind * 4) != &DAT_00008503) goto LAB_0000ab7b;
    }
  }
  if ((uVar3 & 0xff0000) == 0) goto switchD_0000abc9_caseD_7;
  `GL_State'::__l27::value = uVar2 >> 0x10 & 0xff;
  _mode = uVar2 >> 0x18 & 0xf;
  switch(_mode) {
  case 0:
    (*__qglDisable)(0xbc0);
    goto switchD_0000abc9_caseD_7;
  case 1:
    (*__qglEnable)(0xbc0);
    fVar7 = (float)(int)`GL_State'::__l27::value;
    if ((int)`GL_State'::__l27::value < 0) {
      fVar7 = fVar7 + ___real_4f800000;
    }
    fVar7 = fVar7 * (float)___real_3f70000000000000;
    uVar8 = 0x202;
    break;
  case 2:
    (*__qglEnable)(0xbc0);
    fVar7 = (float)(int)`GL_State'::__l27::value;
    if ((int)`GL_State'::__l27::value < 0) {
      fVar7 = fVar7 + ___real_4f800000;
    }
    fVar7 = fVar7 * (float)___real_3f70000000000000;
    uVar8 = 0x205;
    break;
  case 3:
    (*__qglEnable)(0xbc0);
    fVar7 = (float)(int)`GL_State'::__l27::value;
    if ((int)`GL_State'::__l27::value < 0) {
      fVar7 = fVar7 + ___real_4f800000;
    }
    fVar7 = fVar7 * (float)___real_3f70000000000000;
    uVar8 = 0x204;
    break;
  case 4:
    (*__qglEnable)(0xbc0);
    fVar7 = (float)(int)`GL_State'::__l27::value;
    if ((int)`GL_State'::__l27::value < 0) {
      fVar7 = fVar7 + ___real_4f800000;
    }
    fVar7 = fVar7 * (float)___real_3f70000000000000;
    uVar8 = 0x201;
    break;
  case 5:
    (*__qglEnable)(0xbc0);
    fVar7 = (float)(int)`GL_State'::__l27::value;
    if ((int)`GL_State'::__l27::value < 0) {
      fVar7 = fVar7 + ___real_4f800000;
    }
    fVar7 = fVar7 * (float)___real_3f70000000000000;
    uVar8 = 0x206;
    break;
  case 6:
    (*__qglEnable)(0xbc0);
    fVar7 = (float)(int)`GL_State'::__l27::value;
    if ((int)`GL_State'::__l27::value < 0) {
      fVar7 = fVar7 + ___real_4f800000;
    }
    fVar7 = fVar7 * (float)___real_3f70000000000000;
    uVar8 = 0x203;
    break;
  default:
    goto switchD_0000abc9_caseD_7;
  }
  (*__qglAlphaFunc)(uVar8,fVar7);
switchD_0000abc9_caseD_7:
  if ((uVar3 & 0x70000000) == 0) goto LAB_0000add8;
  uVar5 = uVar2 & 0x70000000;
  if (uVar5 < 0x20000001) {
    if (uVar5 == 0x20000000) {
      (*__qglEnable)(0xbc0);
      uVar6 = 0x201;
      uVar8 = ___real_3f000000;
    }
    else {
      if (uVar5 == 0) {
        (*__qglDisable)(0xbc0);
        goto LAB_0000add8;
      }
      if (uVar5 != 0x10000000) goto LAB_0000add8;
      (*__qglEnable)(0xbc0);
      uVar6 = 0x204;
      uVar8 = 0;
    }
  }
  else {
    if (uVar5 != 0x40000000) goto LAB_0000add8;
    (*__qglEnable)(0xbc0);
    uVar6 = 0x206;
    uVar8 = ___real_3f000000;
  }
  (*__qglAlphaFunc)(uVar6,uVar8);
LAB_0000add8:
  iVar1 = __r_nobind;
  if ((uVar3 & 0x1000) != 0) {
    fVar7 = (float)(int)(&DAT_00002901 + (-(uint)((uVar2 & 0x1000) != 0) & 0x582e));
    if (__qglActiveTextureARB == (code *)0x0) {
      (*__qglTexParameterf)(0xde1,&DAT_00002802,fVar7);
      (*__qglTexParameterf)(0xde1,&DAT_00002803,fVar7);
    }
    else {
      if (__r_nobind != 0) {
        (*__qglActiveTextureARB)(&DAT_000084c0);
        (*__qglClientActiveTextureARB)(&DAT_000084c0);
        __r_nobind = 0;
      }
      (*__qglTexParameterf)(0xde1,&DAT_00002802,fVar7);
      (*__qglTexParameterf)(0xde1,&DAT_00002803,fVar7);
      if (__r_nobind != 1) {
        (*__qglActiveTextureARB)(&DAT_000084c1);
        (*__qglClientActiveTextureARB)(&DAT_000084c1);
        __r_nobind = 1;
      }
      (*__qglTexParameterf)(0xde1,&DAT_00002802,fVar7);
      (*__qglTexParameterf)(0xde1,&DAT_00002803,fVar7);
      _GL_SelectTexture(iVar1);
    }
  }
  if ((uVar3 & 0x8000) != 0) {
    if (((uint)__qglActiveTextureARB & 0x8000) != 0) {
      (*__qglEnable)();
      _DAT_0000cd0c = (uint)__qglActiveTextureARB | uVar2;
      return;
    }
    (*__qglDisable)(0xb60);
  }
  _DAT_0000cd0c = (uint)__qglActiveTextureARB | uVar2;
  return;
}



// ===========================================
// Function: _RB_Hyperspace @ 0000b01f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Hyperspace(void)

{
  float fVar1;
  
  fVar1 = (float)(_DAT_0000cd14 & 0xff) / (float)___real_406fe00000000000;
  (*__qglClearColor)(fVar1,fVar1,fVar1,0x3f800000);
  (*__qglClear)(0x4000);
  _DAT_0000d1dc = 1;
  return;
}



// ===========================================
// Function: _SetViewportAndScissor @ 0000b06f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SetViewportAndScissor(void)

{
  (*__qglMatrixMode)(0x1701);
  (*__qglLoadMatrixf)(0xcff0);
  (*__qglMatrixMode)(0x1700);
  (*__qglViewport)(_DAT_0000cfd8,_DAT_0000cfdc,_DAT_0000cfe0,_DAT_0000cfe4);
  (*__qglScissor)(_DAT_0000cfd8,_DAT_0000cfdc,_DAT_0000cfe0,_DAT_0000cfe4);
  return;
}



// ===========================================
// Function: _RB_BeginDrawingView @ 0000b0d2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_BeginDrawingView(void)

{
  uint uVar1;
  float fStack_28;
  double dStack_24;
  double dStack_1c;
  double dStack_14;
  double dStack_c;
  
  uVar1 = 0;
  if ((*(int *)(__r_finish + 0x20) == 1) && (_DAT_0000ccf4 == 0)) {
    (*__qglFinish)();
    _DAT_0000ccf4 = 1;
  }
  if (*(int *)(__r_finish + 0x20) == 0) {
    _DAT_0000ccf4 = 1;
  }
  _DAT_0000d474 = 0;
  _SetViewportAndScissor();
  _GL_State(0x100);
  if (_DAT_0000ceac == 0) {
    uVar1 = 0x100;
  }
  if ((*(int *)(__r_measureOverdraw + 0x20) != 0) || (*(int *)(__r_shadows + 0x20) == 2)) {
    uVar1 = uVar1 | 0x400;
  }
  if ((_qglCullFace & 1) == 0) {
    if (((NAN(_DAT_0000d11c) == (_DAT_0000d11c == 0.0)) && (_DAT_0000d7f0 == 0)) &&
       (_DAT_0000d7f4 == 0)) {
      (*__qglClearColor)(_DAT_0000d6b4 * _DAT_0000d0dc,_DAT_0000d0e0 * _DAT_0000d6b4,
                         _DAT_0000d6b4 * _DAT_0000d0e4,0);
      uVar1 = uVar1 | 0x4000;
    }
    else if (*(int *)(__r_fastsky + 0x20) != 0) {
      uVar1 = uVar1 | 0x4000;
      (*__qglClearColor)(___real_3f4ccccd,___real_3f333333,___real_3ecccccd,0x3f800000);
    }
  }
  (*__qglClear)(uVar1);
  if ((_qglCullFace & 4) != 0) {
    _RB_Hyperspace();
    return;
  }
  _DAT_0000d1dc = 0;
  __ri = 0xffffffff;
  _DAT_0000d1e4 = 0;
  if (_DAT_0000cfb4 != 0) {
    fStack_28 = _DAT_0000cfd0;
    dStack_24 = (double)(_DAT_0000cfc8 * _DAT_0000cec0 + _DAT_0000cfc4 * _DAT_0000cebc +
                        _DAT_0000cfcc * _DAT_0000cec4);
    dStack_1c = (double)(_DAT_0000ced0 * _DAT_0000cfcc +
                        _DAT_0000cec8 * _DAT_0000cfc4 + _DAT_0000cecc * _DAT_0000cfc8);
    dStack_14 = (double)(_DAT_0000cedc * _DAT_0000cfcc +
                        _DAT_0000ced4 * _DAT_0000cfc4 + _DAT_0000ced8 * _DAT_0000cfc8);
    dStack_c = (double)((_DAT_0000cfcc * _DAT_0000ceb8 +
                        _DAT_0000ceb4 * _DAT_0000cfc8 + _DAT_0000ceb0 * _DAT_0000cfc4) -
                       _DAT_0000cfd0);
    (*__qglLoadMatrixf)(&_s_flipMatrix);
    (*__qglClipPlane)(0x3000,&fStack_28);
    (*__qglEnable)(0x3000);
    return;
  }
  (*__qglDisable)(0x3000);
  return;
}



// ===========================================
// Function: _RB_RenderDrawSurfList @ 0000b350
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_RenderDrawSurfList(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  float local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  
  local_60 = __qglAlphaFunc;
  _RB_BeginDrawingView();
  _DAT_0000d1ac = _DAT_0000d1ac + param_2;
  iVar7 = -1;
  _DAT_0000d1e0 = 0xd158;
  local_58 = 0;
  local_54 = -1;
  local_4c = 0;
  local_50 = 0;
  iVar5 = -1;
  local_6c = 0;
  if (0 < param_2) {
    piVar4 = (int *)(param_1 + 4);
    local_48 = param_2;
    do {
      iVar1 = piVar4[-1];
      if ((iVar1 == iVar5) && (piVar2 = (int *)*piVar4, *piVar2 != 0xe)) {
        (**(code **)(&_rb_surfaceTable + *piVar2 * 4))(piVar2);
      }
      else {
        piVar2 = (int *)*piVar4;
        local_44 = iVar1;
        if (*piVar2 == 0xe) {
          local_70 = *(int *)(piVar2[2] * 4 + 0x51c8c);
          local_64 = 0x3fe;
          local_68 = piVar2[0x14];
          local_5c = 0;
        }
        else {
          _R_DecomposeSort(iVar1,&local_64,&local_70,&local_68,&local_5c);
        }
        if ((((local_70 == local_58) && (local_68 == local_54)) && (local_5c == local_50)) &&
           ((*(byte *)(local_70 + 0x208) & 1) == 0)) {
          if (local_64 != iVar7) {
            if (*(int *)(local_70 + 0x60) == 0) goto LAB_0000b459;
            goto LAB_0000b490;
          }
        }
        else {
LAB_0000b459:
          if (local_58 != 0) {
            _RB_EndSurface();
          }
          _RB_BeginSurface(local_70,local_68);
          local_50 = local_5c;
          local_58 = local_70;
          local_54 = local_68;
LAB_0000b490:
          if (local_64 != iVar7) {
            local_6c = 0;
            _DAT_0000d46c = 0;
            if (local_64 == 0x3fe) {
              _DAT_0000d1e0 = 0xd158;
              __qglAlphaFunc = local_60;
              puVar6 = (undefined4 *)&DAT_0000cf2c;
              puVar8 = (undefined4 *)&DAT_0000d130;
              for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
              }
              _R_TransformDlights(_DAT_0000ce54,__qglTexCoord2f,&DAT_0000d130);
              iVar5 = local_6c;
            }
            else {
              _DAT_0000d1e0 = local_64 * 0x2cc + __qglEnd;
              __qglAlphaFunc = local_60 - *(float *)(_DAT_0000d1e0 + 200);
              _R_RotateForEntity(_DAT_0000d1e0,&DAT_0000ceb0,&DAT_0000d130);
              if (*(int *)(_DAT_0000d1e0 + 0x1d0) != 0) {
                _R_TransformDlights(_DAT_0000ce54,__qglTexCoord2f,&DAT_0000d130);
              }
              iVar5 = 0;
              if ((*(byte *)(_DAT_0000d1e0 + 4) & 4) != 0) {
                local_6c = 1;
                iVar5 = local_6c;
              }
            }
            (*__qglLoadMatrixf)(0xd16c);
            iVar7 = local_64;
            if (local_4c != iVar5) {
              uVar3 = ___real_3fd3333333333333;
              if (iVar5 == 0) {
                uVar3 = 0x3ff0000000000000;
              }
              (*__qglDepthRange)(0,0,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
              iVar7 = local_64;
              local_4c = iVar5;
            }
          }
        }
        if ((*(int *)(_DAT_0000d1e0 + 0x1b0) != 0) && (*(int *)(local_70 + 0x1fc) != 0)) {
          _R_Sphere_SetupEntity();
        }
        if (*(int *)*piVar4 == 0xe) {
          __qglAlphaFunc = local_60 - (float)((int *)*piVar4)[0x13];
        }
        (**(code **)(&_rb_surfaceTable + *(int *)*piVar4 * 4))((int *)*piVar4);
        iVar5 = local_44;
      }
      piVar4 = piVar4 + 2;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
    if (local_58 != 0) {
      _RB_EndSurface();
    }
  }
  __qglAlphaFunc = local_60;
  (*__qglLoadMatrixf)(0xcf68);
  if (local_70 != 0) {
    (*__qglDepthRange)(0,0,0,0x3ff00000);
  }
  _RB_ShadowFinish();
  _RB_RenderFlares();
  _R_DrawLensFlares();
  return;
}



// ===========================================
// Function: _RB_RenderSpriteSurfList @ 0000b643
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_RenderSpriteSurfList(int param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  float unaff_EBP;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  fVar2 = __qglAlphaFunc;
  _DAT_0000d1ac = _DAT_0000d1ac + param_2;
  iVar4 = 0;
  _DAT_0000d1e0 = 0xd158;
  puVar5 = (undefined4 *)&DAT_0000cf2c;
  puVar7 = (undefined4 *)&DAT_0000d130;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  if (0 < param_2) {
    piVar6 = (int *)(param_1 + 4);
    do {
      iVar3 = *(int *)(*(int *)(*piVar6 + 8) * 4 + 0x51c8c);
      uVar1 = *(undefined4 *)(*piVar6 + 0x50);
      if (((iVar3 != iVar4) || ((*(byte *)(iVar3 + 0x208) & 1) != 0)) &&
         (*(int *)(iVar3 + 0x60) == 0)) {
        if (iVar4 != 0) {
          _RB_EndSurface();
        }
        _RB_BeginSurface(iVar3,uVar1);
        iVar4 = iVar3;
      }
      __qglAlphaFunc = fVar2;
      (*__qglLoadMatrixf)(0xd16c);
      __qglAlphaFunc = unaff_EBP - *(float *)(*piVar6 + 0x4c);
      (**(code **)(&_rb_surfaceTable + *(int *)*piVar6 * 4))((int *)*piVar6);
      piVar6 = piVar6 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (iVar4 != 0) {
      _RB_EndSurface();
    }
  }
  __qglAlphaFunc = fVar2;
  (*__qglLoadMatrixf)(0xcf68);
  return;
}



// ===========================================
// Function: _RB_DrawSurfs @ 0000b72d
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _RB_DrawSurfs(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (_DAT_00323e70 != 0) {
    _RB_EndSurface();
  }
  puVar3 = (undefined4 *)&DAT_0000cccc;
  puVar2 = param_1;
  for (iVar1 = 0x79; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0x7a;
  puVar3 = (undefined4 *)&DAT_0000ceb0;
  for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _RB_RenderDrawSurfList(param_1[0x11a],param_1[0x11b]);
  return param_1 + 0x11c;
}



// ===========================================
// Function: _RB_SpriteSurfs @ 0000b783
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _RB_SpriteSurfs(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (_DAT_00323e70 != 0) {
    _RB_EndSurface();
  }
  puVar3 = (undefined4 *)&DAT_0000cccc;
  puVar2 = param_1;
  for (iVar1 = 0x79; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0x7a;
  puVar3 = (undefined4 *)&DAT_0000ceb0;
  for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _RB_RenderSpriteSurfList(param_1[0x11a],param_1[0x11b]);
  return param_1 + 0x11c;
}



// ===========================================
// Function: _RB_DrawBuffer @ 0000b7d9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _RB_DrawBuffer(int param_1)

{
  (*__qglDrawBuffer)(*(undefined4 *)(param_1 + 4));
  if (*(int *)(__r_clear + 0x20) != 0) {
    (*__qglClearColor)(0x3f800000,0,___real_3f000000,0x3f800000);
    (*__qglClear)(&DAT_00004100);
  }
  return param_1 + 8;
}



// ===========================================
// Function: _RB_SetGL2D @ 0000b826
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SetGL2D(void)

{
  _Set2DWindow(0,0,_DAT_0000e26c,_DAT_0000e270,0,(float)_DAT_0000e26c,(float)_DAT_0000e270,0,0,
               0x3f800000);
  return;
}



// ===========================================
// Function: _RB_ShowImages @ 0000b86a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_ShowImages(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_retaddr;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  _Set2DWindow(0,0,_DAT_0000e26c,_DAT_0000e270,0,(float)_DAT_0000e26c,(float)_DAT_0000e270,0,0,
               0x3f800000);
  fVar9 = 2.29589e-41;
  (*__qglClear)(0x4000);
  (*__qglFinish)();
  iVar1 = (*__qglClientActiveTextureARB)();
  iVar2 = 0;
  if (0 < _DAT_00020c84) {
    puVar3 = &DAT_00020cd4;
    do {
      fVar5 = (float)(_DAT_0000e26c / 0x14);
      if (*(int *)(__r_showImages + 0x20) == 2) {
        fVar5 = (float)*(int *)(puVar3 + -4) * (float)___real_3f60000000000000 * fVar5;
      }
      _GL_Bind(puVar3 + -0x4c);
      fVar8 = 9.80909e-45;
      (*__qglBegin)(7);
      uVar7 = 0;
      (*__qglTexCoord2f)(0,0);
      fVar10 = fVar9;
      (*__qglVertex2f)(fVar5,fVar9);
      fVar6 = 0.0;
      fVar5 = 1.0;
      (*__qglTexCoord2f)(0x3f800000,0);
      fVar8 = fVar8 + fVar9;
      (*__qglVertex2f)(fVar8,uVar7);
      uVar4 = 0x3f800000;
      (*__qglTexCoord2f)(0x3f800000,0x3f800000);
      (*__qglVertex2f)(uVar7,fVar5 + fVar6);
      (*__qglTexCoord2f)(0,0x3f800000);
      (*__qglVertex2f)(fVar8,uVar4);
      (*__qglEnd)();
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 0x80;
      fVar9 = fVar10;
    } while (iVar2 < _DAT_00020c84);
  }
  (*__qglFinish)();
  iVar2 = (*__qglClientActiveTextureARB)();
  if (unaff_retaddr == 0) {
    (*__ri)(1,s__i_msec_to_draw_all_images_,iVar2 - iVar1);
  }
  return;
}



// ===========================================
// Function: _RB_SwapBuffers @ 0000bac6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall _RB_SwapBuffers(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  if (_DAT_00323e70 != 0) {
    _RB_EndSurface(param_1);
  }
  if (*(int *)(__r_showImages + 0x20) != 0) {
    _RB_ShowImages(0);
  }
  if (*(int *)(__r_measureOverdraw + 0x20) != 0) {
    iVar7 = 0;
    iVar5 = 0;
    param_1 = 0;
    iVar2 = (*_DAT_0000cd14)(_DAT_0000e270 * _DAT_0000e26c);
    uVar8 = 0x1901;
    (*__qglReadPixels)(0,0,_DAT_0000e26c,_DAT_0000e270,0x1901,0x1401,iVar2);
    iVar4 = _DAT_0000e270 * _DAT_0000e26c;
    iVar3 = 0;
    uVar6 = 0;
    if (1 < iVar4) {
      do {
        iVar7 = iVar7 + (uint)*(byte *)(iVar2 + iVar3);
        pbVar1 = (byte *)(iVar2 + 1 + iVar3);
        iVar3 = iVar3 + 2;
        iVar5 = iVar5 + (uint)*pbVar1;
        uVar6 = uVar8;
      } while (iVar3 < iVar4 + -1);
    }
    if (iVar3 < iVar4) {
      uVar6 = (uint)*(byte *)(iVar3 + iVar2);
    }
    _DAT_0000d1c4 = (float)(int)(iVar5 + iVar7 + uVar6) + _DAT_0000d1c4;
    (*__qglCullFace)(iVar2);
  }
  if (_DAT_0000ccf4 == 0) {
    (*__qglFinish)(param_1);
  }
  _GLimp_LogComment(s___________________RB_SwapBuffers);
  _GLimp_EndFrame();
  _DAT_0000d474 = 0;
  return param_2 + 4;
}



// ===========================================
// Function: _RB_ExecuteRenderCommands @ 0000bbd1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_ExecuteRenderCommands(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*__qglClientActiveTextureARB)();
  if ((*(int *)(__r_smp + 0x20) == 0) ||
     (__backEnd = 1, param_1 == (undefined4 *)(__backEndData + 0x1deab4))) {
    __backEnd = 0;
  }
  do {
    switch(*param_1) {
    case 0:
      iVar2 = (*__qglClientActiveTextureARB)();
      _DAT_0000d74c = _DAT_0000d74c + (iVar2 - iVar1);
      return;
    case 1:
      param_1 = (undefined4 *)_RB_DrawSurfs(param_1);
      break;
    case 2:
      param_1 = (undefined4 *)_RB_SpriteSurfs(param_1);
      break;
    case 3:
      param_1 = (undefined4 *)_RB_DrawBuffer(param_1);
      break;
    case 4:
      param_1 = (undefined4 *)_RB_SwapBuffers(param_1);
      break;
    default:
      (*__ri)(1,s_Unknown_render_command__i_,*param_1);
    }
  } while( true );
}



// ===========================================
// Function: _RB_RenderThread @ 0000bc8d
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_RenderThread(void)

{
  int iVar1;
  
  iVar1 = _GLimp_RendererSleep();
  while (iVar1 != 0) {
    __renderThreadActive = 1;
    _RB_ExecuteRenderCommands(iVar1);
    __renderThreadActive = 0;
    iVar1 = _GLimp_RendererSleep();
  }
  return;
}



