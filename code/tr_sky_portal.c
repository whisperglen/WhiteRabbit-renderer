// ===========================================
// Function: _atan2f @ 00008400
// ===========================================

float __cdecl _atan2f(float __y,float __x)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIatan2();
  return (float)fVar1;
}



// ===========================================
// Function: atan2 @ 00008416
// ===========================================

/* float __cdecl atan2(float,float) */

float __cdecl atan2(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIatan2();
  return (float)fVar1;
}



// ===========================================
// Function: _VectorFromString @ 0000842c
// ===========================================

bool _VectorFromString(char *param_1)

{
  int iVar1;
  
  iVar1 = _sscanf(param_1,s__f__f__f);
  return iVar1 == 3;
}



// ===========================================
// Function: _R_Sky_Init @ 00008456
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Sky_Init(void)

{
  _DAT_0000a504 = 0;
  _DAT_0000a588 = 0;
  return;
}



// ===========================================
// Function: _R_Sky_Reset @ 00008463
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Sky_Reset(void)

{
  if (_DAT_0000a504 == 0) {
    _DAT_0000a500 = 0;
    _DAT_0000a598 = ___real_46000000;
    _DAT_0000a588 = 0;
    _DAT_0000a59c = ___real_46000000;
    _DAT_0000a5a0 = ___real_46000000;
    _DAT_0000a5a4 = ___real_c6000000;
    _DAT_0000a5a8 = ___real_c6000000;
    _DAT_0000a5ac = ___real_c6000000;
  }
  return;
}



// ===========================================
// Function: _R_Sky_AddSurf @ 000084a8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _R_Sky_AddSurf(undefined4 param_1,undefined4 param_2)

{
  if (_DAT_0000a504 == 0) {
    if (_DAT_0000a588 < 0x20) {
      *(undefined4 *)(&DAT_0000a508 + _DAT_0000a588 * 4) = param_2;
      _DAT_0000a588 = _DAT_0000a588 + 1;
    }
    if (_DAT_0000a500 != 0) {
      if (*(float *)(_DAT_0000a500 + 8) <= _DAT_0000a598) {
        _DAT_0000a598 = *(float *)(_DAT_0000a500 + 8);
      }
      if (*(float *)(_DAT_0000a500 + 0x14) < _DAT_0000a5a4 ==
          (NAN(*(float *)(_DAT_0000a500 + 0x14)) || NAN(_DAT_0000a5a4))) {
        _DAT_0000a5a4 = *(float *)(_DAT_0000a500 + 0x14);
      }
      if (*(float *)(_DAT_0000a500 + 0xc) <= _DAT_0000a59c) {
        _DAT_0000a59c = *(float *)(_DAT_0000a500 + 0xc);
      }
      if (*(float *)(_DAT_0000a500 + 0x18) < _DAT_0000a5a8 ==
          (NAN(*(float *)(_DAT_0000a500 + 0x18)) || NAN(_DAT_0000a5a8))) {
        _DAT_0000a5a8 = *(float *)(_DAT_0000a500 + 0x18);
      }
      if (*(float *)(_DAT_0000a500 + 0x10) <= _DAT_0000a5a0) {
        _DAT_0000a5a0 = *(float *)(_DAT_0000a500 + 0x10);
      }
      if (*(float *)(_DAT_0000a500 + 0x1c) < _DAT_0000a5ac ==
          (NAN(*(float *)(_DAT_0000a500 + 0x1c)) || NAN(_DAT_0000a5ac))) {
        _DAT_0000a5ac = *(float *)(_DAT_0000a500 + 0x1c);
      }
    }
  }
  else if (`R_Sky_AddSurf'::__l2::last_sky_warning < _DAT_0000a600 + -1000) {
    (*__ri)(3,s_WARNING__sky_being_drawn_in_a_sk,param_1);
    `R_Sky_AddSurf'::__l2::last_sky_warning = _DAT_0000a600;
    return;
  }
  return;
}



// ===========================================
// Function: R_Sky_ChangeFrustum @ 000085e3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_Sky_ChangeFrustum(void) */

void __cdecl R_Sky_ChangeFrustum(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  uint uVar8;
  float10 fVar9;
  float local_98;
  float local_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float local_68 [4];
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_3c;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  float local_14;
  float local_10;
  float local_c;
  
  fVar4 = _DAT_0000a1fc;
  fVar3 = _DAT_0000a1f8;
  fVar2 = _DAT_0000a1f4;
  local_68[0] = _DAT_0000a598;
  local_68[1] = (float)_DAT_0000a59c;
  pfVar7 = (float *)&DAT_0000a374;
  local_68[2] = (float)_DAT_0000a5a0;
  pfVar6 = &local_50;
  iVar5 = 4;
  local_68[3] = (float)_DAT_0000a5a4;
  local_58 = _DAT_0000a5a8;
  local_54 = _DAT_0000a5ac;
  local_50 = _DAT_0000a218;
  local_4c = _DAT_0000a21c;
  local_48 = _DAT_0000a220;
  fVar1 = (float)___real_bff0000000000000;
  local_3c = _DAT_0000a218 * fVar1;
  local_38 = _DAT_0000a21c * fVar1;
  local_34 = _DAT_0000a220 * fVar1;
  local_28 = _DAT_0000a20c;
  local_24 = _DAT_0000a210;
  local_20 = _DAT_0000a214;
  local_14 = _DAT_0000a20c * fVar1;
  local_10 = _DAT_0000a210 * fVar1;
  local_c = _DAT_0000a214 * fVar1;
  do {
    local_98 = ___real_47c34f80;
    pfVar6[3] = pfVar6[2] * _DAT_0000a1fc + *pfVar6 * _DAT_0000a1f4 + pfVar6[1] * _DAT_0000a1f8;
    _CrossProduct(pfVar7,pfVar6,&local_7c);
    uVar8 = 0;
    fStack_70 = fStack_74 * _DAT_0000a1fc + _DAT_0000a1f4 * local_7c + _DAT_0000a1f8 * fStack_78;
    do {
      fVar1 = (local_68[((int)uVar8 >> 2 & 1U) * 3 + 2] - fVar4) * pfVar7[2] +
              (local_68[((int)uVar8 >> 1 & 1U) * 3 + 1] - fVar3) * pfVar7[1] +
              (local_68[(uVar8 & 1) * 3] - fVar2) * *pfVar7;
      if (fVar1 < 0.0 != (fVar1 == 0.0)) break;
      fVar9 = (float10)__CIatan2();
      fVar1 = (float)fVar9;
      if ((fVar1 < 0.0 == NAN(fVar1)) &&
         (fVar1 = (fVar1 * (float)___real_4066800000000000) / (float)___real_400921fb54442d18,
         fVar1 < local_98)) {
        local_98 = fVar1;
      }
      uVar8 = uVar8 + 1;
    } while ((int)uVar8 < 8);
    if ((0.0 < local_98) && (local_98 < ___real_43340000)) {
      _RotatePointAroundVector(pfVar7,pfVar6,pfVar7,local_98);
      _VectorNormalize(pfVar7);
      *(undefined1 *)(pfVar7 + 4) = 3;
      pfVar7[3] = fVar4 * pfVar7[2] + *pfVar7 * fVar2 + pfVar7[1] * fVar3;
      _SetPlaneSignbits(pfVar7);
    }
    pfVar6 = pfVar6 + 5;
    pfVar7 = pfVar7 + 5;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}



// ===========================================
// Function: _R_Sky_Render @ 000088bf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Sky_Render(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 auStack_52c [8];
  undefined4 auStack_524 [7];
  undefined4 auStack_508 [4];
  undefined4 uStack_4f8;
  undefined4 auStack_4f4 [59];
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined4 auStack_288 [161];
  
  if (((_DAT_0000a588 != 0) && (_DAT_0000a760 != 0)) && (_DAT_0000a5b0 == 0)) {
    if (_DAT_0000a504 != 0) {
      (*__ri)(3,s_WARNING__Recursive_skies_found__);
      return;
    }
    iVar2 = 0;
    if (0 < _DAT_0000a588) {
      do {
        iVar1 = _SurfIsOffscreen(*(undefined4 *)(*(int *)(&DAT_0000a508 + iVar2 * 4) + 0xc),
                                 *(undefined4 *)(*(int *)(&DAT_0000a508 + iVar2 * 4) + 4),0x3fe);
        if (iVar1 == 0) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < _DAT_0000a588);
    }
    if (iVar2 != _DAT_0000a588) {
      _DAT_0000a5b0 = 1;
      puVar3 = (undefined4 *)&DAT_0000a1f4;
      puVar4 = auStack_288;
      for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)&DAT_0000a1f4;
      puVar4 = auStack_508;
      for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      if (*(int *)(__r_skyportal + 0x20) == 0) {
        auStack_508[0] = _DAT_0000a768;
        auStack_508[1] = _DAT_0000a76c;
        auStack_508[2] = _DAT_0000a770;
        _MatrixMultiply(auStack_508 + 3,0xa774,auStack_52c);
        puVar3 = auStack_524;
        puVar4 = auStack_4f4;
        for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
      }
      else {
        iVar2 = _sscanf(*(char **)(__r_skyportal_origin + 4),s__f__f__f);
        if (iVar2 != 3) {
          (*__ri)(3,s_WARNING__Invalid_sky_portal_orig,*(undefined4 *)(__r_skyportal_origin + 4));
          return;
        }
      }
      uStack_408 = auStack_508[2];
      _DAT_0000a504 = 1;
      uStack_404 = auStack_508[3];
      uStack_400 = uStack_4f8;
      iVar2 = _R_PointInLeaf(&uStack_408);
      if (iVar2 != 0) {
        _R_RenderView(auStack_508 + 2);
      }
      puVar3 = auStack_288 + 2;
      puVar4 = (undefined4 *)&DAT_0000a1f4;
      for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      _DAT_0000a504 = 0;
      _DAT_0000a588 = 0;
      _R_RotateForViewer();
      _R_SetupFrustum();
    }
  }
  return;
}



