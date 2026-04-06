// ===========================================
// Function: _VectorFromString @ 0000a600
// ===========================================

bool _VectorFromString(char *param_1)

{
  int iVar1;
  
  iVar1 = _sscanf(param_1,s__f__f__f);
  return iVar1 == 3;
}



// ===========================================
// Function: R_Sphere_Light_Sun @ 0000a62a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_Light_Sun(void) */

void __cdecl R_Sphere_Light_Sun(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  undefined1 *puStack_8c;
  undefined1 *puStack_88;
  undefined1 *puStack_84;
  undefined1 *puStack_80;
  undefined1 *puStack_7c;
  undefined1 *puStack_78;
  float *pfStack_74;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [44];
  uint uStack_10;
  
  if (DAT_00002018 != '\0') {
    fVar1 = (float)___real_40d0000000000000;
    uStack_60 = 0;
    uStack_68 = 0x100000000;
    local_48 = _DAT_0000e1cc + _DAT_0000200c * fVar1;
    uStack_70 = 0;
    pfStack_74 = &local_48;
    puStack_7c = local_3c;
    puStack_78 = &DAT_0000e1cc;
    local_44 = _DAT_00002010 * fVar1 + _DAT_0000e1d0;
    local_40 = fVar1 * _DAT_00002014 + _DAT_0000e1d4;
    puStack_80 = (undefined1 *)0xa698;
    (*_DAT_0000dcd4)();
    uVar7 = uStack_10 >> 2 & 1;
    if (*(int *)(__r_light_sun_line + 0x20) != 0) {
      uStack_60 = 0x300;
      uStack_68 = CONCAT44(0xa740,(undefined4)uStack_68);
      _GL_State();
      uStack_60 = 0xa749;
      (*__qglPushMatrix)();
      uStack_60 = 0xe0fc;
      uStack_68 = CONCAT44(0xa754,(undefined4)uStack_68);
      (*__qglLoadMatrixf)();
      uStack_68 = 0;
      uStack_70 = 0;
      pfStack_74 = (float *)0xa766;
      (*__qglDepthRange)();
      pfStack_74 = (float *)0xde1;
      puStack_78 = (undefined1 *)0xa771;
      (*__qglDisable)();
      puStack_78 = (undefined1 *)0x1;
      puStack_7c = (undefined1 *)0xa779;
      (*__qglBegin)();
      puStack_84 = DAT_0000a504;
      if (uVar7 != 0) {
        puStack_84 = _spheredef;
      }
      puStack_7c = DAT_0000a504;
      puStack_88 = (undefined1 *)0xa7a3;
      puStack_80 = puStack_84;
      (*__qglColor3f)();
      puStack_88 = &DAT_0000e1c0;
      puStack_8c = (undefined1 *)0xa7ae;
      (*__qglVertex3fv)();
      puStack_8c = _spheredef;
      (*__qglColor3f)(_spheredef,_spheredef);
      (*__qglVertex3fv)(&puStack_8c);
      (*__qglEnd)();
      (*__qglEnable)(0xde1);
      (*__qglDepthRange)(0,0x3ff0000000000000);
      (*__qglPopMatrix)();
    }
    if (uVar7 != 0) {
      fVar1 = _DAT_00002010 * *(float *)(_DAT_0000e170 + 0x24) +
              _DAT_0000200c * *(float *)(_DAT_0000e170 + 0x20) +
              _DAT_00002014 * *(float *)(_DAT_0000e170 + 0x28);
      fVar3 = *(float *)(_DAT_0000e170 + 0x34) * _DAT_00002014 +
              *(float *)(_DAT_0000e170 + 0x2c) * _DAT_0000200c +
              *(float *)(_DAT_0000e170 + 0x30) * _DAT_00002010;
      fVar2 = _DAT_00002014 * *(float *)(_DAT_0000e170 + 0x40) +
              *(float *)(_DAT_0000e170 + 0x3c) * _DAT_00002010 +
              *(float *)(_DAT_0000e170 + 0x38) * _DAT_0000200c;
      uStack_60 = 0xa877;
      _VectorNormalizeFast();
      fVar4 = fVar3 * 0.0;
      fVar5 = fVar2 * 0.0;
      fVar6 = fVar1 + fVar4 + fVar5;
      if ((float)DAT_0000a504 < fVar6) {
        _DAT_0000e178 = __s_sun * fVar6 + _DAT_0000e178;
        _DAT_0000e17c = _DAT_00002004 * fVar6 + _DAT_0000e17c;
        _DAT_0000e180 = _DAT_0000e180 + _DAT_00002008 * fVar6;
      }
      fVar6 = (fVar4 - fVar1 * (float)___real_3ff0000000000000) + fVar5;
      if ((float)DAT_0000a504 < fVar6) {
        _DAT_0000e184 = fVar6 * __s_sun + _DAT_0000e184;
        _DAT_0000e188 = _DAT_00002004 * fVar6 + _DAT_0000e188;
        _DAT_0000e18c = _DAT_00002008 * fVar6 + _DAT_0000e18c;
      }
      fVar1 = fVar1 * 0.0;
      fVar6 = fVar3 + fVar1 + fVar5;
      if ((float)DAT_0000a504 < fVar6) {
        _DAT_0000e190 = __s_sun * fVar6 + _DAT_0000e190;
        _DAT_0000e194 = _DAT_00002004 * fVar6 + _DAT_0000e194;
        _DAT_0000e198 = _DAT_0000e198 + _DAT_00002008 * fVar6;
      }
      fVar5 = (fVar1 - fVar3 * 1.0) + fVar5;
      if ((float)DAT_0000a504 < fVar5) {
        _DAT_0000e19c = __s_sun * fVar5 + _DAT_0000e19c;
        _DAT_0000e1a0 = _DAT_00002004 * fVar5 + _DAT_0000e1a0;
        _DAT_0000e1a4 = fVar5 * _DAT_00002008 + _DAT_0000e1a4;
      }
      fVar3 = fVar2 + fVar1 + fVar4;
      if ((float)DAT_0000a504 < fVar3) {
        _DAT_0000e1a8 = __s_sun * fVar3 + _DAT_0000e1a8;
        _DAT_0000e1ac = _DAT_00002004 * fVar3 + _DAT_0000e1ac;
        _DAT_0000e1b0 = fVar3 * _DAT_00002008 + _DAT_0000e1b0;
      }
      fVar1 = (fVar1 + fVar4) - fVar2 * 1.0;
      if ((float)DAT_0000a504 < fVar1) {
        _DAT_0000e1b4 = __s_sun * fVar1 + _DAT_0000e1b4;
        _DAT_0000e1b8 = _DAT_00002004 * fVar1 + _DAT_0000e1b8;
        _DAT_0000e1bc = _DAT_00002008 * fVar1 + _DAT_0000e1bc;
        return;
      }
    }
  }
  return;
}



// ===========================================
// Function: R_Sphere_CalculateSphereOrigin @ 0000aac0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* bool __cdecl R_Sphere_CalculateSphereOrigin(void) */

bool __cdecl R_Sphere_CalculateSphereOrigin(void)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float local_c;
  float local_8;
  
  iVar2 = *(int *)(_DAT_0000e170 + 0x1b0);
  if ((iVar2 != 0) && (*(int *)(_DAT_0000e170 + 0x1ac) != 0)) {
    pfVar3 = *(float **)(_DAT_0000e170 + 0x1ac);
    if (*(int *)(iVar2 + 0xe4) < 0) {
      fVar1 = pfVar3[0xf] * *(float *)(_DAT_0000e170 + 0x60) * *(float *)(iVar2 + 0xa4);
    }
    else {
      fVar1 = pfVar3[6] * *(float *)(_DAT_0000e170 + 0x60) * *(float *)(iVar2 + 0xa4);
    }
    fVar4 = (float)___real_3fe0000000000000;
    _DAT_0000e1d8 = fVar1 * fVar4;
    if ((*(uint *)(_DAT_0000e170 + 4) & 0x80000) == 0) {
      local_c = *(float *)(_DAT_0000e170 + 0x48);
      local_8 = *(float *)(_DAT_0000e170 + 0x4c);
      fVar1 = *(float *)(_DAT_0000e170 + 0x50);
    }
    else {
      local_c = *(float *)(_DAT_0000e170 + 0x10);
      local_8 = *(float *)(_DAT_0000e170 + 0x14);
      fVar1 = *(float *)(_DAT_0000e170 + 0x18);
    }
    _DAT_0000e1c8 = *(float *)(_DAT_0000e170 + 0x60) * *(float *)(iVar2 + 0xa4);
    _DAT_0000e1c0 =
         (*(float *)(iVar2 + 0xb0) + (pfVar3[3] + *pfVar3) * fVar4 + *(float *)(iVar2 + 0xbc)) *
         _DAT_0000e1c8;
    _DAT_0000e1c4 =
         (*(float *)(iVar2 + 0xb4) + (pfVar3[4] + pfVar3[1]) * fVar4 + *(float *)(iVar2 + 0xc0)) *
         _DAT_0000e1c8;
    _DAT_0000e1c8 =
         _DAT_0000e1c8 *
         (*(float *)(iVar2 + 0xb8) + (pfVar3[5] + pfVar3[2]) * fVar4 + *(float *)(iVar2 + 0xc4));
    _DAT_0000e1cc =
         _DAT_0000e1c0 * *(float *)(_DAT_0000e170 + 0x20) +
         _DAT_0000e1c4 * *(float *)(_DAT_0000e170 + 0x2c) +
         _DAT_0000e1c8 * *(float *)(_DAT_0000e170 + 0x38) + local_c;
    _DAT_0000e1d0 =
         *(float *)(_DAT_0000e170 + 0x3c) * _DAT_0000e1c8 +
         *(float *)(_DAT_0000e170 + 0x30) * _DAT_0000e1c4 +
         *(float *)(_DAT_0000e170 + 0x24) * _DAT_0000e1c0 + local_8;
    _DAT_0000e1d4 =
         *(float *)(_DAT_0000e170 + 0x40) * _DAT_0000e1c8 +
         *(float *)(_DAT_0000e170 + 0x34) * _DAT_0000e1c4 +
         *(float *)(_DAT_0000e170 + 0x28) * _DAT_0000e1c0 + fVar1;
    return true;
  }
  return false;
}



// ===========================================
// Function: R_Sphere_ResetPointColors @ 0000ace0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* bool __cdecl R_Sphere_ResetPointColors(void) */

bool __cdecl R_Sphere_ResetPointColors(void)

{
  bool bVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar1 = false;
  if (_DAT_0000e170 != 0) {
    if ((*(uint *)(_DAT_0000e170 + 4) & 0x8000) == 0) {
      if ((*(uint *)(_DAT_0000e170 + 4) & 0x20000) == 0) goto LAB_0000ad53;
      local_4 = _DAT_0000e62c * (float)___real_4040000000000000;
      local_c = local_4;
      local_8 = local_4;
    }
    else {
      local_4 = (float)*(byte *)(_DAT_0000e170 + 0xbe);
      local_c = (float)*(byte *)(_DAT_0000e170 + 0xbc);
      local_8 = (float)*(byte *)(_DAT_0000e170 + 0xbd);
    }
    bVar1 = true;
  }
LAB_0000ad53:
  if (((_DAT_00071f08 != 0) && (*(int *)(__r_fullbright + 0x20) == 0)) && (_DAT_0000e1dc != 0)) {
    if (bVar1) {
      _DAT_0000e178 = __ambientlight + local_c;
      _DAT_0000e17c = _DAT_00002020 + local_8;
      _DAT_0000e180 = _DAT_00002024 + local_4;
    }
    else {
      _DAT_0000e178 = __ambientlight;
      _DAT_0000e17c = _DAT_00002020;
      _DAT_0000e180 = _DAT_00002024;
    }
    _DAT_0000e18c = _DAT_0000e180;
    _DAT_0000e198 = _DAT_0000e180;
    _DAT_0000e1a4 = _DAT_0000e180;
    _DAT_0000e1b0 = _DAT_0000e180;
    _DAT_0000e1bc = _DAT_0000e180;
    _DAT_0000e184 = _DAT_0000e178;
    _DAT_0000e190 = _DAT_0000e178;
    _DAT_0000e19c = _DAT_0000e178;
    _DAT_0000e1a8 = _DAT_0000e178;
    _DAT_0000e1b4 = _DAT_0000e178;
    _DAT_0000e188 = _DAT_0000e17c;
    _DAT_0000e194 = _DAT_0000e17c;
    _DAT_0000e1a0 = _DAT_0000e17c;
    _DAT_0000e1ac = _DAT_0000e17c;
    _DAT_0000e1b8 = _DAT_0000e17c;
    return true;
  }
  _DAT_0000e1bc = (float)_DAT_0000e630;
  _DAT_0000e1a8 = _DAT_0000e1bc;
  _DAT_0000e1ac = _DAT_0000e1bc;
  _DAT_0000e1b0 = _DAT_0000e1bc;
  if (bVar1) {
    _DAT_0000e1a8 = _DAT_0000e1bc + local_c;
    _DAT_0000e1ac = _DAT_0000e1bc + local_8;
    _DAT_0000e1b0 = _DAT_0000e1bc + local_4;
  }
  _DAT_0000e1b4 = _DAT_0000e1bc;
  _DAT_0000e1b8 = _DAT_0000e1bc;
  if (!bVar1) {
    _DAT_0000e178 = _DAT_0000e1a8;
    _DAT_0000e17c = _DAT_0000e1ac;
    _DAT_0000e180 = _DAT_0000e1b0;
    _DAT_0000e184 = _DAT_0000e1a8;
    _DAT_0000e188 = _DAT_0000e1ac;
    _DAT_0000e18c = _DAT_0000e1b0;
    _DAT_0000e190 = _DAT_0000e1a8;
    _DAT_0000e194 = _DAT_0000e1ac;
    _DAT_0000e198 = _DAT_0000e1b0;
    _DAT_0000e19c = _DAT_0000e1a8;
    _DAT_0000e1a0 = _DAT_0000e1ac;
    _DAT_0000e1a4 = _DAT_0000e1b0;
    return false;
  }
  _DAT_0000e1b4 = _DAT_0000e1bc + local_c;
  _DAT_0000e1b8 = _DAT_0000e1bc + local_8;
  _DAT_0000e1bc = local_4 + _DAT_0000e1bc;
  _DAT_0000e178 = _DAT_0000e1a8;
  _DAT_0000e17c = _DAT_0000e1ac;
  _DAT_0000e180 = _DAT_0000e1b0;
  _DAT_0000e184 = _DAT_0000e1a8;
  _DAT_0000e188 = _DAT_0000e1ac;
  _DAT_0000e18c = _DAT_0000e1b0;
  _DAT_0000e190 = _DAT_0000e1a8;
  _DAT_0000e194 = _DAT_0000e1ac;
  _DAT_0000e198 = _DAT_0000e1b0;
  _DAT_0000e19c = _DAT_0000e1a8;
  _DAT_0000e1a0 = _DAT_0000e1ac;
  _DAT_0000e1a4 = _DAT_0000e1b0;
  return false;
}



// ===========================================
// Function: R_Sphere_BuildStaticLights @ 0000aff3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_BuildStaticLights(struct spherel_t * *) */

void __cdecl R_Sphere_BuildStaticLights(spherel_t **param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  spherel_t *psVar5;
  int iVar6;
  int *local_4;
  
  iVar4 = _light_reference_count;
  if (*(int *)(__VectorLength + 0xf8) == 0) {
    iVar4 = 0;
    if (0 < _DAT_00071f08) {
      psVar5 = (spherel_t *)0x5a008;
      do {
        param_1[_DAT_0000e1f0] = psVar5;
        _DAT_0000e1f0 = _DAT_0000e1f0 + 1;
        iVar4 = iVar4 + 1;
        psVar5 = psVar5 + 0x40;
      } while (iVar4 < _DAT_00071f08);
    }
  }
  else {
    local_4 = (int *)&DAT_0000e1dc;
    while (iVar1 = *local_4, iVar1 != 0) {
      iVar6 = 0;
      if (0 < *(int *)(iVar1 + 0x3c)) {
        do {
          iVar2 = *(int *)(*(int *)(iVar1 + 0x38) + iVar6 * 4);
          iVar3 = *(int *)(*(int *)(iVar2 + 0x1c) + 0x34);
          if ((((&DAT_0000dcac)[iVar3 >> 3] & (byte)(1 << ((byte)iVar3 & 7))) == 0) &&
             (*(int *)(iVar2 + 0x3c) != iVar4)) {
            param_1[_DAT_0000e1f0] = *(spherel_t **)(*(int *)(iVar1 + 0x38) + iVar6 * 4);
            _DAT_0000e1f0 = _DAT_0000e1f0 + 1;
            *(int *)(*(int *)(*(int *)(iVar1 + 0x38) + iVar6 * 4) + 0x3c) = iVar4;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(iVar1 + 0x3c));
      }
      local_4 = local_4 + 1;
      if (0xe1eb < (int)local_4) {
        return;
      }
    }
  }
  return;
}



// ===========================================
// Function: R_Sphere_DrawDebugLine @ 0000b0d5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_DrawDebugLine(struct spherel_t *,float,float * const) */

void __cdecl R_Sphere_DrawDebugLine(spherel_t *param_1,float param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  float fStack_30;
  undefined8 uStack_2c;
  undefined8 uStack_24;
  undefined4 uStack_1c;
  int iStack_14;
  float fStack_10;
  
  if ((*(int *)(__r_light_lines + 0x20) != 0) &&
     (*(float *)(__r_light_lines + 0x1c) < param_2 !=
      (*(float *)(__r_light_lines + 0x1c) == param_2))) {
    uStack_1c = 0xb101;
    (*__qglPushMatrix)();
    uStack_1c = 0xe0fc;
    uStack_24 = CONCAT44(0xb10c,(undefined4)uStack_24);
    (*__qglLoadMatrixf)();
    uStack_24 = 0x3000000b116;
    _GL_State();
    uStack_24 = 0;
    uStack_2c = 0;
    fStack_30 = 6.35517e-41;
    (*__qglDepthRange)();
    fStack_30 = 4.97881e-42;
    (*__qglDisable)();
    fStack_10 = fStack_10 / (float)___real_406fe00000000000;
    fStack_30 = *(float *)(iStack_14 + 0xc) * fStack_10;
    fVar1 = *(float *)(iStack_14 + 0x10) * fStack_10;
    fStack_10 = fStack_10 * *(float *)(iStack_14 + 0x14);
    uStack_2c = CONCAT44(fStack_10,fVar1);
    if ((_spheredef < fStack_30 != (NAN(_spheredef) || NAN(fStack_30))) ||
       ((_spheredef < fVar1 != (NAN(_spheredef) || NAN(fVar1)) ||
        (_spheredef < fStack_10 != (NAN(_spheredef) || NAN(fStack_10)))))) {
      _NormalizeColor();
    }
    (*__qglColor3fv)(&fStack_30);
    (*__qglBegin)(1);
    (*__qglVertex3fv)(iStack_14);
    (*__qglVertex3fv)(&DAT_0000e1c0);
    pfVar2 = (float *)&DAT_0000a504;
    do {
      fStack_30 = *pfVar2 * _DAT_0000e1d8 + *(float *)(iStack_14 + 4);
      uStack_2c = CONCAT44(uStack_2c._4_4_,_DAT_0000e1d8 * pfVar2[1] + *(float *)(iStack_14 + 8));
      (*__qglVertex3fv)(iStack_14);
      (*__qglVertex3fv)();
      pfVar2 = pfVar2 + 3;
    } while ((int)pfVar2 < 0xa54c);
    (*__qglEnd)();
    (*__qglEnable)(0xde1);
    (*__qglDepthRange)(0,0x3ff0000000000000);
    (*__qglPopMatrix)();
  }
  return;
}



// ===========================================
// Function: R_Sphere_AddSpotLight @ 0000b23f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_AddSpotLight(struct spherel_t *) */

void __cdecl R_Sphere_AddSpotLight(spherel_t *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int iVar14;
  float10 fVar15;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (DAT_0000a504 <= *(float *)(param_1 + 0x28)) {
    local_24 = *(float *)param_1 - *(float *)(_DAT_0000e170 + 0x48);
    local_20 = *(float *)(param_1 + 4) - *(float *)(_DAT_0000e170 + 0x4c);
    local_1c = *(float *)(param_1 + 8) - *(float *)(_DAT_0000e170 + 0x50);
    fVar1 = *(float *)(param_1 + 0x28);
  }
  else {
    fVar1 = -((_DAT_0000e1d0 * *(float *)(param_1 + 0x30) +
               _DAT_0000e1cc * *(float *)(param_1 + 0x2c) +
              _DAT_0000e1d4 * *(float *)(param_1 + 0x34)) -
             (*(float *)(param_1 + 8) * *(float *)(param_1 + 0x34) +
             *(float *)(param_1 + 4) * *(float *)(param_1 + 0x30) +
             *(float *)(param_1 + 0x2c) * *(float *)param_1));
    local_18 = fVar1 * *(float *)(param_1 + 0x2c) + _DAT_0000e1cc;
    local_14 = fVar1 * *(float *)(param_1 + 0x30) + _DAT_0000e1d0;
    local_10 = fVar1 * *(float *)(param_1 + 0x34) + _DAT_0000e1d4;
    local_30 = local_18 - *(float *)param_1;
    local_2c = local_14 - *(float *)(param_1 + 4);
    local_28 = local_10 - *(float *)(param_1 + 8);
    fVar1 = local_28 * local_28 + local_30 * local_30 + local_2c * local_2c;
    if (*(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x28) < fVar1) {
      fVar15 = (float10)_Q_rsqrt(fVar1);
      fVar1 = (float)(-(float10)*(float *)(param_1 + 0x28) * fVar15);
      local_30 = fVar1 * local_30;
      local_2c = fVar1 * local_2c;
      local_28 = fVar1 * local_28;
    }
    local_24 = (*(float *)param_1 - *(float *)(_DAT_0000e170 + 0x48)) + local_30;
    local_20 = (*(float *)(param_1 + 4) - *(float *)(_DAT_0000e170 + 0x4c)) + local_2c;
    local_1c = (*(float *)(param_1 + 8) - *(float *)(_DAT_0000e170 + 0x50)) + local_28;
    fVar1 = ___real_3fa00000;
  }
  local_18 = local_20 * *(float *)(_DAT_0000e170 + 0x24) +
             local_24 * *(float *)(_DAT_0000e170 + 0x20) +
             local_1c * *(float *)(_DAT_0000e170 + 0x28);
  local_14 = *(float *)(_DAT_0000e170 + 0x34) * local_1c +
             *(float *)(_DAT_0000e170 + 0x2c) * local_24 +
             *(float *)(_DAT_0000e170 + 0x30) * local_20;
  local_10 = local_1c * *(float *)(_DAT_0000e170 + 0x40) +
             *(float *)(_DAT_0000e170 + 0x3c) * local_20 +
             *(float *)(_DAT_0000e170 + 0x38) * local_24;
  fVar7 = local_18 - _DAT_0000e1c0;
  fVar8 = local_14 - _DAT_0000e1c4;
  fVar9 = local_10 - _DAT_0000e1c8;
  fVar15 = (float10)_Q_rsqrt(fVar9 * fVar9 + fVar7 * fVar7 + fVar8 * fVar8);
  fVar10 = *(float *)(param_1 + 0x18) * (float)___real_40dd4c0000000000 *
           (float)fVar15 * (float)fVar15;
  if (_spheredef <= fVar10) {
    fVar3 = *(float *)(_DAT_0000e170 + 0x28) * *(float *)(param_1 + 0x34) +
            *(float *)(_DAT_0000e170 + 0x20) * *(float *)(param_1 + 0x2c) +
            *(float *)(_DAT_0000e170 + 0x24) * *(float *)(param_1 + 0x30);
    fVar4 = *(float *)(_DAT_0000e170 + 0x34) * *(float *)(param_1 + 0x34) +
            *(float *)(_DAT_0000e170 + 0x2c) * *(float *)(param_1 + 0x2c) +
            *(float *)(_DAT_0000e170 + 0x30) * *(float *)(param_1 + 0x30);
    fVar5 = *(float *)(_DAT_0000e170 + 0x40) * *(float *)(param_1 + 0x34) +
            *(float *)(_DAT_0000e170 + 0x38) * *(float *)(param_1 + 0x2c) +
            *(float *)(_DAT_0000e170 + 0x3c) * *(float *)(param_1 + 0x30);
    fVar12 = -(fVar5 * fVar9 + fVar3 * fVar7 + fVar4 * fVar8);
    if (-_DAT_0000e1d8 <= fVar12) {
      iVar14 = 0;
      fVar13 = DAT_0000a504;
      do {
        fVar2 = -(*(float *)((int)&DAT_0000a508 + iVar14) * fVar5 +
                 fVar3 * *(float *)((int)&_spheredef + iVar14) +
                 *(float *)((int)&DAT_0000a504 + iVar14) * fVar4);
        if ((fVar2 < fVar13 == (NAN(fVar2) || NAN(fVar13))) &&
           (fVar12 < fVar13 == (NAN(fVar12) || NAN(fVar13)))) {
          fStack_c = fVar7 + fVar12 * fVar3;
          fStack_8 = fVar8 + fVar12 * fVar4;
          fStack_4 = fVar5 * fVar12 + fVar9;
          fVar11 = fVar12 * fVar1;
          fVar15 = (float10)_VectorLength(&fStack_c);
          fVar13 = DAT_0000a504;
          fVar2 = (float)fVar15;
          if (fVar11 < fVar2 == (fVar11 == fVar2)) {
            fVar6 = _spheredef;
            if (fVar11 - (float)___real_4040000000000000 < fVar2) {
              fVar6 = (fVar11 - fVar2) * (float)___real_3fa0000000000000;
            }
            fVar6 = -(fVar3 * *(float *)((int)&_spheredef + iVar14) +
                      fVar4 * *(float *)((int)&DAT_0000a504 + iVar14) +
                     fVar5 * *(float *)((int)&DAT_0000a508 + iVar14)) * fVar10 * fVar6;
            if (fVar6 < DAT_0000a504 == (fVar6 == DAT_0000a504)) {
              *(float *)(&DAT_0000e178 + iVar14) =
                   *(float *)(param_1 + 0xc) * fVar6 + *(float *)(&DAT_0000e178 + iVar14);
              *(float *)(&DAT_0000e17c + iVar14) =
                   *(float *)(param_1 + 0x10) * fVar6 + *(float *)(&DAT_0000e17c + iVar14);
              *(float *)(&DAT_0000e180 + iVar14) =
                   fVar6 * *(float *)(param_1 + 0x14) + *(float *)(&DAT_0000e180 + iVar14);
            }
          }
        }
        iVar14 = iVar14 + 0xc;
      } while (iVar14 < 0x48);
      R_Sphere_DrawDebugLine(param_1,fVar10,&local_18);
      return;
    }
  }
  return;
}



// ===========================================
// Function: R_Sphere_AddLight @ 0000b728
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_AddLight(struct spherel_t *) */

void __cdecl R_Sphere_AddLight(spherel_t *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  spherel_t *psVar5;
  spherel_t *psVar6;
  int iVar7;
  float10 fVar8;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 local_3c [8];
  float fStack_34;
  
  psVar5 = param_1;
  if ((((DAT_0000a504 < *(float *)(param_1 + 0x18) ==
         (NAN(DAT_0000a504) || NAN(*(float *)(param_1 + 0x18)))) ||
       ((*(uint *)(_DAT_0000e170 + 4) & 0x8000000) == 0)) &&
      ((DAT_0000a504 <= *(float *)(param_1 + 0x18) ||
       ((*(uint *)(_DAT_0000e170 + 4) & 0x8000000) != 0)))) &&
     ((*(int *)(param_1 + 0x20) == 0 ||
      ((*_DAT_0000dcd4)(local_3c,&DAT_0000e1cc,param_1,0,0,0,1,0), _spheredef <= fStack_34)))) {
    if (*(int *)(param_1 + 0x24) != 0) {
      R_Sphere_AddSpotLight(param_1);
      return;
    }
    fStack_48 = *(float *)param_1 - *(float *)(_DAT_0000e170 + 0x48);
    fStack_44 = *(float *)(param_1 + 4) - *(float *)(_DAT_0000e170 + 0x4c);
    fStack_40 = *(float *)(param_1 + 8) - *(float *)(_DAT_0000e170 + 0x50);
    fStack_54 = fStack_44 * *(float *)(_DAT_0000e170 + 0x24) +
                fStack_48 * *(float *)(_DAT_0000e170 + 0x20) +
                fStack_40 * *(float *)(_DAT_0000e170 + 0x28);
    fStack_50 = *(float *)(_DAT_0000e170 + 0x34) * fStack_40 +
                *(float *)(_DAT_0000e170 + 0x2c) * fStack_48 +
                *(float *)(_DAT_0000e170 + 0x30) * fStack_44;
    fStack_4c = fStack_40 * *(float *)(_DAT_0000e170 + 0x40) +
                *(float *)(_DAT_0000e170 + 0x3c) * fStack_44 +
                *(float *)(_DAT_0000e170 + 0x38) * fStack_48;
    fVar2 = fStack_54 - _DAT_0000e1c0;
    fVar3 = fStack_50 - _DAT_0000e1c4;
    fVar4 = fStack_4c - _DAT_0000e1c8;
    fVar8 = (float10)_Q_rsqrt(fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3);
    fVar1 = *(float *)(param_1 + 0x18);
    if (fVar1 < DAT_0000a504 != (NAN(fVar1) || NAN(DAT_0000a504))) {
      fVar1 = fVar1 * (float)___real_bff0000000000000;
    }
    psVar6 = (spherel_t *)(fVar1 * (float)___real_40dd4c0000000000 * (float)fVar8 * (float)fVar8);
    if ((float)psVar6 < _spheredef == (NAN((float)psVar6) || NAN(_spheredef))) {
      if (((NAN(DAT_0000a504) || NAN(*(float *)(param_1 + 0x38))) ==
           (DAT_0000a504 == *(float *)(param_1 + 0x38))) &&
         (*(float *)(param_1 + 0x38) < (float)psVar6 !=
          (NAN(*(float *)(param_1 + 0x38)) || NAN((float)psVar6)))) {
        psVar6 = *(spherel_t **)(param_1 + 0x38);
      }
      param_1 = psVar6;
      R_Sphere_DrawDebugLine(psVar5,(float)param_1,&fStack_54);
      iVar7 = 0;
      do {
        fStack_48 = _DAT_0000e1d8 * *(float *)((int)&_spheredef + iVar7) + fVar2;
        fStack_44 = *(float *)((int)&DAT_0000a504 + iVar7) * _DAT_0000e1d8 + fVar3;
        fStack_40 = _DAT_0000e1d8 * *(float *)((int)&DAT_0000a508 + iVar7) + fVar4;
        _VectorNormalizeFast(&fStack_48);
        fVar1 = fStack_40 * *(float *)((int)&DAT_0000a508 + iVar7) +
                fStack_48 * *(float *)((int)&_spheredef + iVar7) +
                *(float *)((int)&DAT_0000a504 + iVar7) * fStack_44;
        if (fVar1 < DAT_0000a504 == (NAN(fVar1) || NAN(DAT_0000a504))) {
          fVar1 = fVar1 * (float)param_1;
          *(float *)(&DAT_0000e178 + iVar7) =
               *(float *)(&DAT_0000e178 + iVar7) + fVar1 * *(float *)(psVar5 + 0xc);
          *(float *)(&DAT_0000e17c + iVar7) =
               *(float *)(psVar5 + 0x10) * fVar1 + *(float *)(&DAT_0000e17c + iVar7);
          *(float *)(&DAT_0000e180 + iVar7) =
               fVar1 * *(float *)(psVar5 + 0x14) + *(float *)(&DAT_0000e180 + iVar7);
        }
        iVar7 = iVar7 + 0xc;
      } while (iVar7 < 0x48);
      return;
    }
  }
  return;
}



// ===========================================
// Function: R_Sphere_SetupLightDir @ 0000ba06
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_SetupLightDir(void) */

void __cdecl R_Sphere_SetupLightDir(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_c;
  float local_8;
  float local_4;
  
  local_4 = DAT_0000a504;
  local_8 = DAT_0000a504;
  local_c = DAT_0000a504;
  iVar2 = 0;
  do {
    fVar4 = (float10)_VectorLength(&DAT_0000e178 + iVar2);
    fVar1 = (float)fVar4;
    iVar3 = iVar2 + 0xc;
    local_c = local_c + fVar1 * *(float *)((int)&_spheredef + iVar2);
    local_8 = *(float *)((int)&DAT_0000a504 + iVar2) * fVar1 + local_8;
    local_4 = fVar1 * *(float *)((int)&DAT_0000a508 + iVar2) + local_4;
    iVar2 = iVar3;
  } while (iVar3 < 0x48);
  _VectorNormalize(&local_c);
  *(float *)(_DAT_0000e170 + 0x1d8) = local_c;
  *(float *)(_DAT_0000e170 + 0x1dc) = local_8;
  *(float *)(_DAT_0000e170 + 0x1e0) = local_4;
  return;
}



// ===========================================
// Function: R_Sphere_NormalizeColors @ 0000babc
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_NormalizeColors(void) */

void __cdecl R_Sphere_NormalizeColors(void)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  
  if (_DAT_0000e3f8 == 0) {
    pfVar3 = (float *)&DAT_0000e178;
    fVar1 = (float)(1 << ((byte)_DAT_0000e634 & 0x1f));
    fVar2 = (float)___real_406fe00000000000;
    do {
      if ((NAN(DAT_0000a504) || NAN(fVar1)) == (DAT_0000a504 == fVar1)) {
        *pfVar3 = *pfVar3 * fVar1;
        pfVar3[1] = pfVar3[1] * fVar1;
        pfVar3[2] = pfVar3[2] * fVar1;
      }
      if (((fVar2 < *pfVar3) || (fVar2 < pfVar3[1])) || (fVar2 < pfVar3[2])) {
        _NormalizeColor(pfVar3,pfVar3);
        fVar2 = (float)___real_406fe00000000000;
        *pfVar3 = *pfVar3 * fVar2;
        pfVar3[1] = pfVar3[1] * fVar2;
        pfVar3[2] = pfVar3[2] * fVar2;
      }
      pfVar3 = pfVar3 + 3;
    } while ((int)pfVar3 < 0xe1c0);
  }
  return;
}



// ===========================================
// Function: EmphasizeSphereColors @ 0000bb85
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl EmphasizeSphereColors(void) */

void __cdecl EmphasizeSphereColors(void)

{
  float fVar1;
  
  if (*(int *)(__r_light_emphasizePercent + 0x20) != 0) {
    fVar1 = *(float *)(__r_light_emphasizePercent + 0x1c) * (float)___real_3f847ae140000000 +
            (float)___real_3ff0000000000000;
    _DAT_0000e178 = fVar1 * _DAT_0000e178;
    _DAT_0000e17c = _DAT_0000e17c * fVar1;
    _DAT_0000e180 = _DAT_0000e180 * fVar1;
    _DAT_0000e184 = _DAT_0000e184 * fVar1;
    _DAT_0000e188 = _DAT_0000e188 * fVar1;
    _DAT_0000e18c = _DAT_0000e18c * fVar1;
    _DAT_0000e190 = _DAT_0000e190 * fVar1;
    _DAT_0000e194 = _DAT_0000e194 * fVar1;
    _DAT_0000e198 = _DAT_0000e198 * fVar1;
    _DAT_0000e19c = _DAT_0000e19c * fVar1;
    _DAT_0000e1a0 = _DAT_0000e1a0 * fVar1;
    _DAT_0000e1a4 = _DAT_0000e1a4 * fVar1;
    _DAT_0000e1a8 = _DAT_0000e1a8 * fVar1;
    _DAT_0000e1ac = _DAT_0000e1ac * fVar1;
    _DAT_0000e1b0 = _DAT_0000e1b0 * fVar1;
    _DAT_0000e1b4 = _DAT_0000e1b4 * fVar1;
    _DAT_0000e1b8 = _DAT_0000e1b8 * fVar1;
    _DAT_0000e1bc = fVar1 * _DAT_0000e1bc;
  }
  if (1 < *(int *)(__r_light_emphasize + 0x20)) {
    _DAT_0000e178 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e178;
    _DAT_0000e17c = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e17c;
    _DAT_0000e180 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e180;
    _DAT_0000e184 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e184;
    _DAT_0000e188 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e188;
    _DAT_0000e18c = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e18c;
    _DAT_0000e190 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e190;
    _DAT_0000e194 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e194;
    _DAT_0000e198 = *(float *)(__r_light_emphasize + 0x1c) + _DAT_0000e198;
    _DAT_0000e19c = _DAT_0000e19c + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1a0 = _DAT_0000e1a0 + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1a4 = _DAT_0000e1a4 + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1a8 = _DAT_0000e1a8 + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1ac = _DAT_0000e1ac + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1b0 = _DAT_0000e1b0 + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1b4 = _DAT_0000e1b4 + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1b8 = _DAT_0000e1b8 + *(float *)(__r_light_emphasize + 0x1c);
    _DAT_0000e1bc = _DAT_0000e1bc + *(float *)(__r_light_emphasize + 0x1c);
  }
  return;
}



// ===========================================
// Function: q_fabs @ 0000bdc7
// ===========================================

/* float __cdecl q_fabs(float) */

float __cdecl q_fabs(float param_1)

{
  return ABS(param_1);
}



// ===========================================
// Function: RB_Light_Sphere_ExactDLights @ 0000bddc
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl RB_Light_Sphere_ExactDLights(unsigned char *) */

void __cdecl RB_Light_Sphere_ExactDLights(uchar *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  uchar *puVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 fVar12;
  int iStack_34;
  int local_2c;
  uint local_20 [2];
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  local_20[0] = 0xffffffff;
  local_20[1] = 0;
  local_2c = 0;
  if (0 < _DAT_00324d0c) {
    fVar10 = (float10)___real_406fe00000000000;
    puVar9 = param_1 + 1;
    pfVar8 = (float *)&DAT_00132c3c;
    do {
      puVar9[2] = 0xff;
      iVar2 = ((int)pfVar8[-1] >> 0x1f) * -0xc;
      iVar3 = ((int)*pfVar8 >> 0x1f) * -0xc;
      iVar4 = ((int)pfVar8[1] >> 0x1f) * -0xc;
      fVar11 = (float10)(*(float *)(&DAT_0000e1a8 + iVar4) * ABS(pfVar8[1]) +
                        *(float *)(&DAT_0000e190 + iVar3) * ABS(*pfVar8) +
                        *(float *)(&DAT_0000e178 + ((int)pfVar8[-1] >> 0x1f) * -0xc) *
                        ABS(pfVar8[-1]));
      fVar1 = (float)(fVar11 - fVar10);
      local_18 = (float)(fVar11 - (float10)(float)((uint)fVar1 & local_20[-((int)fVar1 >> 0x1f)]));
      fVar11 = (float10)(*(float *)(&DAT_0000e1ac + iVar4) * ABS(pfVar8[1]) +
                        *(float *)(&DAT_0000e194 + iVar3) * ABS(*pfVar8) +
                        *(float *)(&DAT_0000e17c + iVar2) * ABS(pfVar8[-1]));
      fVar1 = (float)(fVar11 - fVar10);
      local_14 = (float)(fVar11 - (float10)(float)((uint)fVar1 & local_20[-((int)fVar1 >> 0x1f)]));
      fVar11 = (float10)(*(float *)(&DAT_0000e1b0 + iVar4) * ABS(pfVar8[1]) +
                        *(float *)(&DAT_0000e198 + iVar3) * ABS(*pfVar8) +
                        *(float *)(&DAT_0000e180 + iVar2) * ABS(pfVar8[-1]));
      fVar1 = (float)(fVar11 - fVar10);
      local_10 = (float)(fVar11 - (float10)(float)((uint)fVar1 & local_20[-((int)fVar1 >> 0x1f)]));
      param_1 = (uchar *)__ftol2_sse();
      uVar5 = __ftol2_sse();
      fVar12 = extraout_ST1;
      uVar6 = __ftol2_sse();
      fVar11 = extraout_ST0;
      fVar10 = extraout_ST1_00;
      if ((NAN(extraout_ST0) || NAN(fVar12)) == (extraout_ST0 == fVar12)) {
        param_1 = (uchar *)__ftol2_sse();
        uVar5 = __ftol2_sse();
        uVar6 = __ftol2_sse();
        fVar11 = extraout_ST0_00;
        fVar10 = extraout_ST1_01;
      }
      iStack_34 = 0;
      if (0 < _DAT_0000e3f4) {
        pfVar7 = (float *)&DAT_0000e1f4;
        do {
          fStack_c = *pfVar7 - pfVar8[-0x1d4c1];
          fStack_8 = pfVar7[1] - pfVar8[-120000];
          fStack_4 = pfVar7[2] - pfVar8[-119999];
          if (fVar11 <= (float10)(fStack_4 * pfVar8[1] + fStack_c * pfVar8[-1] + fStack_8 * *pfVar8)
             ) {
            _Q_rsqrt(fStack_c * fStack_c + fStack_8 * fStack_8 + fStack_4 * fStack_4);
            param_1 = (uchar *)__ftol2_sse();
            uVar5 = __ftol2_sse();
            uVar6 = __ftol2_sse();
            fVar11 = (float10)DAT_0000a504;
            fVar10 = (float10)___real_406fe00000000000;
          }
          iStack_34 = iStack_34 + 1;
          pfVar7 = pfVar7 + 4;
        } while (iStack_34 < _DAT_0000e3f4);
      }
      if (((uVar6 | uVar5 | (uint)param_1) & 0xffffff00) != 0) {
        param_1 = (uchar *)__ftol2_sse();
        uVar5 = __ftol2_sse();
        uVar6 = __ftol2_sse();
        fVar10 = extraout_ST1_02;
      }
      puVar9[-1] = (uchar)param_1;
      *puVar9 = (uchar)uVar5;
      puVar9[1] = (uchar)uVar6;
      local_2c = local_2c + 1;
      puVar9 = puVar9 + 4;
      pfVar8 = pfVar8 + 4;
    } while (local_2c < _DAT_00324d0c);
  }
  return;
}



// ===========================================
// Function: RB_Light_Sphere @ 0000c227
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl RB_Light_Sphere(unsigned char *) */

void __cdecl RB_Light_Sphere(uchar *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  uchar uVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  float *pfVar11;
  uchar *puVar12;
  uint local_14 [2];
  float local_c;
  float local_8;
  float local_4;
  
  iVar10 = 0;
  local_14[0] = 0xffffffff;
  local_14[1] = 0;
  if (0 < _DAT_00324d0c) {
    puVar12 = param_1 + 2;
    pfVar11 = (float *)&DAT_00132c40;
    do {
      fVar4 = (float)___real_406fe00000000000;
      fVar7 = ABS(pfVar11[-2]);
      iVar6 = 2 - ((int)pfVar11[-1] >> 0x1f);
      iVar1 = ((int)pfVar11[-2] >> 0x1f) * -0xc;
      fVar8 = ABS(pfVar11[-1]);
      iVar2 = iVar6 * 0xc;
      iVar3 = (4 - ((int)*pfVar11 >> 0x1f)) * 0xc;
      fVar9 = ABS(*pfVar11);
      local_c = fVar7 * *(float *)(&DAT_0000e178 + ((int)pfVar11[-2] >> 0x1f) * -0xc) +
                fVar8 * *(float *)(&DAT_0000e178 + iVar6 * 0xc) +
                fVar9 * *(float *)(&DAT_0000e178 + iVar3);
      local_8 = *(float *)(&DAT_0000e17c + iVar3) * fVar9 +
                *(float *)(&DAT_0000e17c + iVar2) * fVar8 +
                *(float *)(&DAT_0000e17c + iVar1) * fVar7;
      local_4 = fVar9 * *(float *)(&DAT_0000e180 + iVar3) +
                *(float *)(&DAT_0000e180 + iVar1) * fVar7 +
                *(float *)(&DAT_0000e180 + iVar2) * fVar8;
      fVar7 = local_c - fVar4;
      local_c = local_c - (float)((uint)fVar7 & local_14[-((int)fVar7 >> 0x1f)]);
      fVar7 = local_8 - fVar4;
      local_8 = local_8 - (float)((uint)fVar7 & local_14[-((int)fVar7 >> 0x1f)]);
      fVar4 = local_4 - fVar4;
      local_4 = local_4 - (float)((uint)fVar4 & local_14[-((int)fVar4 >> 0x1f)]);
      uVar5 = myftol(local_c);
      puVar12[-2] = uVar5;
      uVar5 = myftol(local_8);
      puVar12[-1] = uVar5;
      uVar5 = myftol(local_4);
      *puVar12 = uVar5;
      puVar12[1] = 0xff;
      iVar10 = iVar10 + 1;
      pfVar11 = pfVar11 + 4;
      puVar12 = puVar12 + 4;
    } while (iVar10 < _DAT_00324d0c);
  }
  return;
}



// ===========================================
// Function: RB_Light_FullbrightSphere @ 0000c3ff
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl RB_Light_FullbrightSphere(unsigned char *) */

void __cdecl RB_Light_FullbrightSphere(uchar *param_1)

{
  uchar *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < _DAT_00324d0c) {
    puVar1 = param_1 + 2;
    do {
      puVar1[-2] = 0xff;
      puVar1[-1] = 0xff;
      *puVar1 = 0xff;
      puVar1[1] = 0xff;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 4;
    } while (iVar2 < _DAT_00324d0c);
  }
  return;
}



// ===========================================
// Function: _R_Sphere_InitLights @ 0000c42a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Sphere_InitLights(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int *piVar10;
  undefined1 *puVar11;
  int iStack_20;
  float fStack_1c;
  undefined1 auStack_18 [4];
  int iStack_14;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  iStack_20 = (*__atof)();
  DAT_00002018 = 0;
  _DAT_0000e3f8 = 0;
  _DAT_0000e3fc = RB_Light_Sphere;
  _DAT_00002024 = DAT_0000a504;
  _DAT_00002020 = DAT_0000a504;
  __ambientlight = DAT_0000a504;
joined_r0x0000c46b:
  do {
    if (iStack_20 == 0) {
      return;
    }
    pbVar2 = (byte *)_COM_Parse(&iStack_20);
    pcVar5 = s_suncolor;
    pbVar4 = pbVar2;
    do {
      bVar1 = *pbVar4;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_0000c4b0:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0000c4b5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar6 = bVar1 < ((byte *)pcVar5)[1];
      if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_0000c4b0;
      pbVar4 = pbVar4 + 2;
      pcVar5 = (char *)((byte *)pcVar5 + 2);
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0000c4b5:
    if (iVar3 == 0) {
      pcVar5 = (char *)_COM_Parse(&iStack_20);
      _sscanf(pcVar5,s__f__f__f);
      iStack_14 = 1 << ((byte)_DAT_0000e634 & 0x1f);
      iStack_20 = 0xc4fe;
      iVar3 = __ftol2_sse();
      fStack_1c = (float)iVar3;
      DAT_00002018 = 1;
      __s_sun = fStack_1c * __s_sun;
      _DAT_00002004 = fStack_1c * _DAT_00002004;
      _DAT_00002008 = fStack_1c * _DAT_00002008;
      goto joined_r0x0000c46b;
    }
    pcVar5 = s_sundirection;
    pbVar4 = pbVar2;
    do {
      bVar1 = *pbVar4;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_0000c56a:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0000c56f;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar6 = bVar1 < ((byte *)pcVar5)[1];
      if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_0000c56a;
      pbVar4 = pbVar4 + 2;
      pcVar5 = (char *)((byte *)pcVar5 + 2);
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0000c56f:
    if (iVar3 == 0) {
      pcVar5 = (char *)_COM_Parse(&iStack_20);
      puVar11 = auStack_10;
      piVar10 = &iStack_14;
      puVar8 = auStack_18;
      _sscanf(pcVar5,s__f__f__f);
      _AngleVectors(auStack_10,&DAT_0000200c,0,0,puVar8,piVar10,puVar11);
      DAT_00002018 = 1;
    }
    else {
      pcVar5 = s_sunflare;
      pbVar4 = pbVar2;
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < (byte)*pcVar5;
        if (bVar1 != *pcVar5) {
LAB_0000c5e0:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_0000c5e5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < ((byte *)pcVar5)[1];
        if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_0000c5e0;
        pbVar4 = pbVar4 + 2;
        pcVar5 = (char *)((byte *)pcVar5 + 2);
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0000c5e5:
      if (iVar3 == 0) {
        pcVar5 = (char *)_COM_Parse(&iStack_20);
        puVar11 = auStack_4;
        puVar8 = auStack_8;
        puVar9 = auStack_c;
        _sscanf(pcVar5,s__f__f__f);
        _R_SetSunFlare(auStack_4,puVar9,puVar8,puVar11);
      }
      else {
        pcVar5 = s_sunflare_inportalsky;
        pbVar4 = pbVar2;
        do {
          bVar1 = *pbVar4;
          bVar6 = bVar1 < (byte)*pcVar5;
          if (bVar1 != *pcVar5) {
LAB_0000c64a:
            iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_0000c64f;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar6 = bVar1 < ((byte *)pcVar5)[1];
          if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_0000c64a;
          pbVar4 = pbVar4 + 2;
          pcVar5 = (char *)((byte *)pcVar5 + 2);
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_0000c64f:
        if (iVar3 == 0) {
          pcVar5 = (char *)_COM_Parse(&iStack_20);
          dVar7 = _atof(pcVar5);
          if ((NAN(dVar7) || NAN(___real_0000000000000000)) == (dVar7 == ___real_0000000000000000))
          {
            _R_SunFlareInPortalSky();
          }
        }
        else {
          pbVar4 = &s_ambientlight;
          do {
            bVar1 = *pbVar2;
            bVar6 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
LAB_0000c6a1:
              iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_0000c6a6;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar2[1];
            bVar6 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) goto LAB_0000c6a1;
            pbVar2 = pbVar2 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_0000c6a6:
          if (iVar3 == 0) {
            pcVar5 = (char *)_COM_Parse(&iStack_20);
            _sscanf(pcVar5,s__f__f__f);
          }
        }
      }
    }
  } while( true );
}



// ===========================================
// Function: R_Sphere_SetupGlobals @ 0000c6e1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* bool __cdecl R_Sphere_SetupGlobals(void) */

bool __cdecl R_Sphere_SetupGlobals(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  local_6c = DAT_0000a504;
  local_68 = DAT_0000a504;
  local_64 = DAT_0000a504;
  local_60 = DAT_0000a504;
  local_5c = DAT_0000a504;
  local_58 = _spheredef;
  local_54 = _spheredef;
  local_44 = _spheredef;
  local_50 = DAT_0000a504;
  local_4c = DAT_0000a504;
  local_48 = DAT_0000a504;
  local_40 = DAT_0000a504;
  local_3c = DAT_0000a50c;
  local_2c = DAT_0000a50c;
  local_18 = DAT_0000a50c;
  local_14 = DAT_0000a50c;
  local_4 = DAT_0000a50c;
  local_38 = DAT_0000a504;
  local_34 = DAT_0000a504;
  local_30 = DAT_0000a504;
  local_28 = DAT_0000a504;
  local_1c = DAT_0000a504;
  local_10 = DAT_0000a504;
  local_c = DAT_0000a504;
  local_8 = DAT_0000a504;
  local_24 = _spheredef;
  local_20 = _spheredef;
  if (((_r_light_emphasize & 1) == 0) &&
     ((_DAT_0000e170 == 0 || ((*(uint *)(_DAT_0000e170 + 4) & 0x40000) == 0)))) {
    bVar1 = R_Sphere_CalculateSphereOrigin();
    if (bVar1) {
      _light_reference_count = _light_reference_count + 1;
      iVar6 = 0;
      _DAT_0000e1dc = 0;
      _DAT_0000e1e0 = 0;
      _DAT_0000e1e4 = 0;
      _DAT_0000e1e8 = 0;
      pfVar5 = &local_68;
      iVar4 = 9;
      do {
        local_78 = _DAT_0000e1cc + _DAT_0000e1d8 * pfVar5[-1];
        local_74 = *pfVar5 * _DAT_0000e1d8 + _DAT_0000e1d0;
        local_70 = _DAT_0000e1d8 * pfVar5[1] + _DAT_0000e1d4;
        iVar2 = _R_PointInLeaf(&local_78);
        if (*(int *)(iVar2 + 0x34) != -1) {
          iVar3 = 0;
          do {
            if (*(int *)(&DAT_0000e1dc + iVar3 * 4) == iVar2) break;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 4);
          if ((iVar3 == 4) && (iVar6 < 4)) {
            *(int *)(&DAT_0000e1dc + iVar6 * 4) = iVar2;
            iVar6 = iVar6 + 1;
          }
        }
        pfVar5 = pfVar5 + 3;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          _DAT_0000e1f0 = iVar4;
          _DAT_0000e3fc = RB_Light_Sphere;
          return true;
        }
      } while( true );
    }
  }
  else {
    _DAT_0000e178 = (float)_DAT_0000e630;
    _DAT_0000e17c = _DAT_0000e178;
    _DAT_0000e180 = _DAT_0000e178;
    _DAT_0000e184 = _DAT_0000e178;
    _DAT_0000e188 = _DAT_0000e178;
    _DAT_0000e18c = _DAT_0000e178;
    _DAT_0000e190 = _DAT_0000e178;
    _DAT_0000e194 = _DAT_0000e178;
    _DAT_0000e198 = _DAT_0000e178;
    _DAT_0000e19c = _DAT_0000e178;
    _DAT_0000e1a0 = _DAT_0000e178;
    _DAT_0000e1a4 = _DAT_0000e178;
    _DAT_0000e1a8 = _DAT_0000e178;
    _DAT_0000e1ac = _DAT_0000e178;
    _DAT_0000e1b0 = _DAT_0000e178;
    _DAT_0000e1b4 = _DAT_0000e178;
    _DAT_0000e1b8 = _DAT_0000e178;
    _DAT_0000e1bc = _DAT_0000e178;
  }
  return false;
}



// ===========================================
// Function: R_Sphere_BuildDLights @ 0000c8d0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sphere_BuildDLights(struct spherel_t * *) */

void __cdecl R_Sphere_BuildDLights(spherel_t **param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar7 = 0;
  _DAT_0000e3f8 = (uint)(0 < _DAT_0000dde4);
  iVar9 = 0;
  _DAT_0000e3f4 = 0;
  if (_DAT_0000e3f8 == 0) {
    _DAT_0000e3fc = RB_Light_Sphere;
    if (0 < _DAT_0000dde4) {
      _DAT_0000e3f8 = 0;
      do {
        iVar5 = _DAT_0000dde8 + iVar7;
        iVar8 = (_DAT_00071f08 + iVar9) * 0x40;
        *(undefined4 *)(iVar8 + 0x5a008) = *(undefined4 *)(_DAT_0000dde8 + iVar7);
        *(undefined4 *)(iVar8 + 0x5a00c) = *(undefined4 *)(iVar5 + 4);
        *(undefined4 *)(iVar8 + 0x5a010) = *(undefined4 *)(iVar5 + 8);
        *(undefined4 *)(iVar8 + 0x5a014) = *(undefined4 *)(iVar5 + 0xc);
        *(undefined4 *)(iVar8 + 0x5a018) = *(undefined4 *)(iVar5 + 0x10);
        *(undefined4 *)(iVar8 + 0x5a01c) = *(undefined4 *)(iVar5 + 0x14);
        *(undefined4 *)(iVar8 + 0x5a020) = *(undefined4 *)(iVar5 + 0x18);
        uVar6 = _R_PointInLeaf(iVar5);
        iVar5 = _DAT_0000e1f0;
        *(undefined4 *)(iVar8 + 0x5a024) = uVar6;
        *(undefined4 *)(iVar8 + 0x5a028) = 0;
        *(undefined4 *)(iVar8 + 0x5a02c) = 0;
        param_1[iVar5] = (spherel_t *)(iVar8 + 0x5a008);
        _DAT_0000e1f0 = _DAT_0000e1f0 + 1;
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 0x2c;
      } while (iVar9 < _DAT_0000dde4);
      return;
    }
  }
  else {
    _DAT_0000e3fc = RB_Light_Sphere_ExactDLights;
    if (0 < _DAT_0000dde4) {
      do {
        if (_DAT_0000e3f4 == 0x20) {
          return;
        }
        pfVar1 = (float *)(iVar7 + _DAT_0000dde8);
        local_c = *(float *)(iVar7 + _DAT_0000dde8) - _DAT_0000e1cc;
        local_8 = *(float *)(iVar7 + 4 + _DAT_0000dde8) - _DAT_0000e1d0;
        local_4 = *(float *)(iVar7 + 8 + _DAT_0000dde8) - _DAT_0000e1d4;
        fVar10 = (float10)_VectorLength(&local_c);
        if ((float10)pfVar1[6] + (float10)_DAT_0000e1d8 < fVar10 ==
            (NAN((float10)pfVar1[6] + (float10)_DAT_0000e1d8) || NAN(fVar10))) {
          fVar2 = *pfVar1 - *(float *)(_DAT_0000e170 + 0x48);
          fVar3 = pfVar1[1] - *(float *)(_DAT_0000e170 + 0x4c);
          fVar4 = pfVar1[2] - *(float *)(_DAT_0000e170 + 0x50);
          *(float *)(&DAT_0000e1f4 + _DAT_0000e3f4 * 0x10) =
               fVar3 * *(float *)(_DAT_0000e170 + 0x24) + fVar2 * *(float *)(_DAT_0000e170 + 0x20) +
               fVar4 * *(float *)(_DAT_0000e170 + 0x28);
          *(float *)(&DAT_0000e1f8 + _DAT_0000e3f4 * 0x10) =
               *(float *)(_DAT_0000e170 + 0x34) * fVar4 +
               *(float *)(_DAT_0000e170 + 0x2c) * fVar2 + *(float *)(_DAT_0000e170 + 0x30) * fVar3;
          *(float *)(&DAT_0000e1fc + _DAT_0000e3f4 * 0x10) =
               fVar4 * *(float *)(_DAT_0000e170 + 0x40) +
               *(float *)(_DAT_0000e170 + 0x3c) * fVar3 + *(float *)(_DAT_0000e170 + 0x38) * fVar2;
          *(int *)(&DAT_0000e200 + _DAT_0000e3f4 * 0x10) = iVar9;
          _DAT_0000e3f4 = _DAT_0000e3f4 + 1;
        }
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 0x2c;
      } while (iVar9 < _DAT_0000dde4);
    }
  }
  return;
}



// ===========================================
// Function: _R_Sphere_SetupEntity @ 0000caec
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Sphere_SetupEntity(void)

{
  bool bVar1;
  int iVar2;
  spherel_t *local_17f0 [1531];
  undefined4 uStack_4;
  
  uStack_4 = 0xcaf6;
  if ((*(uint *)(_DAT_0000e170 + 4) & 0x8000200) == 0) {
    _DAT_0000e3fc = (code *)&_RB_CalcDiffuseColor;
    R_Sphere_CalculateSphereOrigin();
    _R_SetupEntityLighting(0xe770,_DAT_0000e170,&DAT_0000e1cc);
    return;
  }
  if (((*(uint *)(_DAT_0000e170 + 4) & 0x40000) == 0) && (*(int *)(__r_light_nolight + 0x20) == 0))
  {
    bVar1 = R_Sphere_SetupGlobals();
    if ((bVar1) && (bVar1 = R_Sphere_ResetPointColors(), bVar1)) {
      if (DAT_00002018 != '\0') {
        R_Sphere_Light_Sun();
      }
      R_Sphere_BuildStaticLights(local_17f0);
      R_Sphere_BuildDLights(local_17f0);
      _DAT_0000e150 = _DAT_0000e150 + _DAT_0000e1f0;
      iVar2 = 0;
      if (0 < _DAT_0000e1f0) {
        do {
          R_Sphere_AddLight(local_17f0[iVar2]);
          iVar2 = iVar2 + 1;
        } while (iVar2 < _DAT_0000e1f0);
      }
      R_Sphere_SetupLightDir();
      EmphasizeSphereColors();
      R_Sphere_NormalizeColors();
      return;
    }
  }
  else {
    _DAT_0000e3fc = RB_Light_FullbrightSphere;
  }
  return;
}



