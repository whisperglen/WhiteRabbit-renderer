// ===========================================
// Function: _TableForFunc @ 0000e800
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall _TableForFunc(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return 0x5c3c8;
  case 2:
    return 0x5d3c8;
  case 3:
    return 0x5e3c8;
  case 4:
    return 0x5f3c8;
  case 5:
    return 0x603c8;
  default:
    (*_DAT_00015424)(1,s_TableForFunc_called_with_invalid,param_1,_DAT_0032c468);
    return 0;
  }
}



// ===========================================
// Function: _RB_CalcDeformNormals @ 0000e85c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcDeformNormals(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  
  iVar3 = 0;
  if (0 < _DAT_0032c47c) {
    pfVar4 = (float *)&DAT_0013a3b0;
    do {
      fVar2 = (float)___real_3fef5c2900000000;
      fVar5 = (float10)_R_NoiseGet4f(fVar2 * pfVar4[-0x1d4c2],pfVar4[-0x1d4c1] * fVar2,
                                     pfVar4[-120000] * fVar2,*(float *)(param_1 + 0x20) * __memmove)
      ;
      pfVar1 = pfVar4 + -2;
      *pfVar1 = *(float *)(param_1 + 0x18) * (float)fVar5 + *pfVar1;
      fVar2 = (float)___real_3fef5c2900000000;
      fVar5 = (float10)_R_NoiseGet4f(fVar2 * pfVar4[-0x1d4c2] + (float)___real_4059000000000000,
                                     pfVar4[-0x1d4c1] * fVar2,pfVar4[-120000] * fVar2,
                                     *(float *)(param_1 + 0x20) * __memmove);
      pfVar4[-1] = *(float *)(param_1 + 0x18) * (float)fVar5 + pfVar4[-1];
      fVar2 = (float)___real_3fef5c2900000000;
      fVar5 = (float10)_R_NoiseGet4f(fVar2 * pfVar4[-0x1d4c2] + (float)___real_4069000000000000,
                                     pfVar4[-0x1d4c1] * fVar2,pfVar4[-120000] * fVar2,
                                     *(float *)(param_1 + 0x20) * __memmove);
      *pfVar4 = *(float *)(param_1 + 0x18) * (float)fVar5 + *pfVar4;
      _VectorNormalizeFast(pfVar1);
      iVar3 = iVar3 + 1;
      pfVar4 = pfVar4 + 4;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcBulgeVertexes @ 0000e9eb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcBulgeVertexes(int param_1)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < _DAT_0032c47c) {
    pfVar3 = (float *)&DAT_0013a3b0;
    do {
      uVar2 = __ftol2_sse();
      iVar4 = iVar4 + 1;
      fVar1 = *(float *)((uVar2 & 0x3ff) * 4 + 0x5c3c8) * *(float *)(param_1 + 0x2c);
      pfVar3[-0x1d4c2] = pfVar3[-0x1d4c2] + fVar1 * pfVar3[-2];
      pfVar3[-0x1d4c1] = pfVar3[-1] * fVar1 + pfVar3[-0x1d4c1];
      pfVar3[-120000] = fVar1 * *pfVar3 + pfVar3[-120000];
      pfVar3 = pfVar3 + 4;
    } while (iVar4 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _DeformText @ 0000ea96
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DeformText(char *param_1)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float fStack_40;
  float fStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = (float)___real_bf800000;
  _CrossProduct(&DAT_0013a3a8,&local_c,&local_18);
  fStack_3c = ___real_497423f0;
  fStack_40 = ___real_c97423f0;
  if (_DAT_000c50b0 < (float)___real_412e847e00000000 !=
      (NAN(_DAT_000c50b0) || NAN((float)___real_412e847e00000000))) {
    fStack_3c = _DAT_000c50b0;
  }
  if ((float)___real_c12e847e00000000 < _DAT_000c50b0) {
    fStack_40 = _DAT_000c50b0;
  }
  if (_DAT_000c50c0 < fStack_3c) {
    fStack_3c = _DAT_000c50c0;
  }
  if (fStack_40 < _DAT_000c50c0 != (NAN(fStack_40) || NAN(_DAT_000c50c0))) {
    fStack_40 = _DAT_000c50c0;
  }
  if (_DAT_000c50d0 < fStack_3c) {
    fStack_3c = _DAT_000c50d0;
  }
  if (fStack_40 < _DAT_000c50d0 != (NAN(fStack_40) || NAN(_DAT_000c50d0))) {
    fStack_40 = _DAT_000c50d0;
  }
  fStack_30 = _DAT_000c50d8 + _DAT_000c50c8 + _DAT_000c50b8 + _DAT_000c50a8 + 0.0;
  fStack_2c = _DAT_000c50dc + _DAT_000c50cc + _DAT_000c50bc + _DAT_000c50ac + 0.0;
  fStack_28 = _DAT_000c50e0 + _DAT_000c50d0 + _DAT_000c50c0 + _DAT_000c50b0 + 0.0;
  if (_DAT_000c50e0 < fStack_3c) {
    fStack_3c = _DAT_000c50e0;
  }
  if (fStack_40 < _DAT_000c50e0 != (NAN(fStack_40) || NAN(_DAT_000c50e0))) {
    fStack_40 = _DAT_000c50e0;
  }
  fVar3 = (float)___real_3fd0000000000000;
  local_c = 0;
  local_8 = 0;
  local_4 = (fStack_40 - fStack_3c) * (float)___real_3fe0000000000000;
  fVar2 = local_4 * (float)___real_bfe8000000000000;
  local_18 = local_18 * fVar2;
  fStack_14 = fStack_14 * fVar2;
  fStack_10 = fVar2 * fStack_10;
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar6 = (int)pcVar5 - (int)(param_1 + 1);
  fVar2 = (float)(iVar6 + -1);
  iVar8 = 0;
  _DAT_0032c478 = 0;
  _DAT_0032c47c = 0;
  uStack_35 = 0xff;
  uStack_36 = 0xff;
  uStack_37 = 0xff;
  uStack_38 = 0xff;
  fStack_24 = fVar2 * local_18 + fStack_30 * fVar3;
  fStack_20 = fVar2 * fStack_14 + fStack_2c * fVar3;
  fStack_1c = fVar2 * fStack_10 + fVar3 * fStack_28;
  if (0 < iVar6) {
    fVar3 = (float)___real_3fb0000000000000;
    fVar2 = (float)___real_4000000000000000;
    do {
      uVar7 = (uint)(byte)param_1[iVar8];
      if (uVar7 != 0x20) {
        fVar2 = (float)((int)uVar7 >> 4) * fVar3;
        fVar4 = (float)(uVar7 & 0xf) * fVar3;
        fStack_34 = fVar4 + fVar3;
        _RB_AddQuadStampExt(&fStack_24,&local_18,&local_c,&uStack_38,fVar4,fVar2,fStack_34,
                            fVar2 + fVar3);
        fVar3 = (float)___real_3fb0000000000000;
        fVar2 = (float)___real_4000000000000000;
      }
      iVar8 = iVar8 + 1;
      fStack_24 = fStack_24 - local_18 * fVar2;
      fStack_20 = fStack_20 - fStack_14 * fVar2;
      fStack_1c = fStack_1c - fStack_10 * fVar2;
    } while (iVar8 < iVar6);
  }
  return;
}



// ===========================================
// Function: _GlobalVectorToLocal @ 0000edd9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _GlobalVectorToLocal(float *param_1)

{
  float *in_EAX;
  
  *param_1 = _DAT_000158c4 * in_EAX[2] + _DAT_000158c0 * in_EAX[1] + *in_EAX * _DAT_000158bc;
  param_1[1] = _DAT_000158d0 * in_EAX[2] + _DAT_000158cc * in_EAX[1] + *in_EAX * _DAT_000158c8;
  param_1[2] = _DAT_000158dc * in_EAX[2] + _DAT_000158d8 * in_EAX[1] + *in_EAX * _DAT_000158d4;
  return;
}



// ===========================================
// Function: _AutospriteDeform @ 0000ee3c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _AutospriteDeform(void)

{
  uint extraout_EDX;
  uint uVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((_DAT_0032c47c & 3) != 0) {
    (*_DAT_00015424)(1,s_Autosprite_shader__s_had_odd_ver,_DAT_0032c468);
  }
  if (_DAT_0032c478 != ((int)_DAT_0032c47c >> 2) * 6) {
    (*_DAT_00015424)(1,s_Autosprite_shader__s_had_odd_ind,_DAT_0032c468);
  }
  uVar1 = _DAT_0032c47c;
  _DAT_0032c47c = 0;
  _DAT_0032c478 = 0;
  if (_DAT_00015960 == 0x15890) {
    fStack_3c = _DAT_00015648;
    fStack_38 = _DAT_0001564c;
    fStack_34 = _DAT_00015650;
    fStack_30 = _DAT_00015654;
    fStack_2c = _DAT_00015658;
    fStack_28 = _DAT_0001565c;
  }
  else {
    _GlobalVectorToLocal();
    _GlobalVectorToLocal();
    uVar1 = extraout_EDX;
  }
  if (0 < (int)uVar1) {
    pfVar3 = (float *)&DAT_000c50c8;
    iVar4 = (uVar1 - 1 >> 2) + 1;
    iVar2 = 0x2249a8;
    do {
      fStack_1c = (float)___real_3fd0000000000000;
      fStack_24 = (pfVar3[-4] + pfVar3[-8] + *pfVar3 + pfVar3[4]) * fStack_1c;
      fStack_20 = (pfVar3[-3] + pfVar3[-7] + pfVar3[1] + pfVar3[5]) * fStack_1c;
      fStack_1c = (pfVar3[-2] + pfVar3[-6] + pfVar3[2] + pfVar3[6]) * fStack_1c;
      fStack_18 = pfVar3[-8] - fStack_24;
      fStack_14 = pfVar3[-7] - fStack_20;
      fStack_10 = pfVar3[-6] - fStack_1c;
      fVar5 = (float10)_VectorLength(&fStack_18);
      fStack_4 = (float)(fVar5 * (float10)___real_3fe69fbe76c8b439);
      fStack_48 = fStack_4 * fStack_3c;
      fStack_44 = fStack_4 * fStack_38;
      fStack_40 = fStack_4 * fStack_34;
      fStack_c = fStack_4 * fStack_30;
      fStack_8 = fStack_4 * fStack_2c;
      fStack_4 = fStack_4 * fStack_28;
      if (_DAT_00015738 != 0) {
        fStack_48 = __vec3_origin - fStack_48;
        fStack_44 = _DAT_0001547c - fStack_44;
        fStack_40 = __VectorLength - fStack_40;
      }
      _RB_AddQuadStamp(&fStack_24,&fStack_48,&fStack_c,iVar2);
      pfVar3 = pfVar3 + 0x10;
      iVar2 = iVar2 + 0x10;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}



// ===========================================
// Function: _Autosprite2Deform @ 0000f03e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Autosprite2Deform(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  int iVar5;
  float *pfVar6;
  int *piVar7;
  int iVar8;
  float *pfVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float *pfStack_74;
  int iStack_6c;
  int iStack_68;
  int *piStack_64;
  float fStack_58;
  float fStack_54;
  int aiStack_50 [2];
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((_DAT_0032c47c & 3) != 0) {
    (*__ri)(3,s_Autosprite_shader__s_had_odd_ver,_DAT_0032c468);
  }
  if (_DAT_0032c478 != ((int)_DAT_0032c47c >> 2) * 6) {
    (*__ri)(3,s_Autosprite_shader__s_had_odd_ind,_DAT_0032c468);
  }
  if (_DAT_00015960 == 0x15890) {
    uStack_30 = _DAT_0001563c;
    uStack_2c = _DAT_00015640;
    uStack_28 = _DAT_00015644;
  }
  else {
    _GlobalVectorToLocal();
  }
  iStack_68 = 0;
  if (0 < (int)_DAT_0032c47c) {
    fVar13 = (float10)___real_3fe0000000000000;
    piStack_64 = (int *)&DAT_0001542c;
    puVar10 = &DAT_000c50a8;
    do {
      fStack_54 = ___real_497423f0;
      fStack_58 = ___real_497423f0;
      iVar5 = _edgeVerts * 0x10;
      iVar11 = DAT_00002104 * 0x10;
      iVar8 = 0;
      fVar1 = (*(float *)(puVar10 + iVar5 + 8) - *(float *)(puVar10 + iVar11 + 8)) *
              (*(float *)(puVar10 + iVar5 + 8) - *(float *)(puVar10 + iVar11 + 8)) +
              (*(float *)(puVar10 + iVar5) - *(float *)(puVar10 + iVar11)) *
              (*(float *)(puVar10 + iVar5) - *(float *)(puVar10 + iVar11)) +
              (*(float *)(puVar10 + iVar5 + 4) - *(float *)(puVar10 + iVar11 + 4)) *
              (*(float *)(puVar10 + iVar5 + 4) - *(float *)(puVar10 + iVar11 + 4));
      dVar4 = (double)fVar1;
      if (dVar4 < ___real_412e847e00000000 == (NAN(dVar4) || NAN(___real_412e847e00000000))) {
        if (dVar4 < ___real_412e847e00000000 != (NAN(dVar4) || NAN(___real_412e847e00000000))) {
          fStack_54 = fVar1;
        }
      }
      else {
        fStack_58 = fVar1;
      }
      aiStack_50[1] = 0;
      aiStack_50[0] = 0;
      iVar5 = 0;
      iVar11 = DAT_00002108 * 0x10;
      iVar12 = DAT_0000210c * 0x10;
      fVar1 = (*(float *)(puVar10 + iVar11 + 8) - *(float *)(puVar10 + iVar12 + 8)) *
              (*(float *)(puVar10 + iVar11 + 8) - *(float *)(puVar10 + iVar12 + 8)) +
              (*(float *)(puVar10 + iVar11) - *(float *)(puVar10 + iVar12)) *
              (*(float *)(puVar10 + iVar11) - *(float *)(puVar10 + iVar12)) +
              (*(float *)(puVar10 + iVar11 + 4) - *(float *)(puVar10 + iVar12 + 4)) *
              (*(float *)(puVar10 + iVar11 + 4) - *(float *)(puVar10 + iVar12 + 4));
      if (fStack_58 <= fVar1) {
        if (fVar1 < fStack_54) {
          iVar5 = 1;
          aiStack_50[1] = 1;
          fStack_54 = fVar1;
        }
      }
      else {
        fStack_54 = fStack_58;
        iVar5 = 0;
        iVar8 = 1;
        aiStack_50[1] = 0;
        aiStack_50[0] = 1;
        fStack_58 = fVar1;
      }
      iVar11 = DAT_00002110 * 0x10;
      iVar12 = DAT_00002114 * 0x10;
      fVar1 = (*(float *)(puVar10 + iVar11 + 8) - *(float *)(puVar10 + iVar12 + 8)) *
              (*(float *)(puVar10 + iVar11 + 8) - *(float *)(puVar10 + iVar12 + 8)) +
              (*(float *)(puVar10 + iVar11) - *(float *)(puVar10 + iVar12)) *
              (*(float *)(puVar10 + iVar11) - *(float *)(puVar10 + iVar12)) +
              (*(float *)(puVar10 + iVar11 + 4) - *(float *)(puVar10 + iVar12 + 4)) *
              (*(float *)(puVar10 + iVar11 + 4) - *(float *)(puVar10 + iVar12 + 4));
      if (fVar1 < fStack_58 == (NAN(fVar1) || NAN(fStack_58))) {
        iVar11 = iVar8;
        fVar2 = fStack_58;
        if (fVar1 < fStack_54) {
          iVar5 = 2;
          aiStack_50[1] = 2;
          fStack_54 = fVar1;
        }
      }
      else {
        aiStack_50[0] = 2;
        iVar11 = 2;
        iVar5 = iVar8;
        fVar2 = fVar1;
        fStack_54 = fStack_58;
        aiStack_50[1] = iVar8;
      }
      iVar8 = DAT_00002118 * 0x10;
      iVar12 = DAT_0000211c * 0x10;
      fVar1 = (*(float *)(puVar10 + iVar8 + 8) - *(float *)(puVar10 + iVar12 + 8)) *
              (*(float *)(puVar10 + iVar8 + 8) - *(float *)(puVar10 + iVar12 + 8)) +
              (*(float *)(puVar10 + iVar8) - *(float *)(puVar10 + iVar12)) *
              (*(float *)(puVar10 + iVar8) - *(float *)(puVar10 + iVar12)) +
              (*(float *)(puVar10 + iVar8 + 4) - *(float *)(puVar10 + iVar12 + 4)) *
              (*(float *)(puVar10 + iVar8 + 4) - *(float *)(puVar10 + iVar12 + 4));
      if (fVar1 < fVar2 == (NAN(fVar1) || NAN(fVar2))) {
        iVar8 = iVar11;
        fVar3 = fVar2;
        if (fVar1 < fStack_54) {
          iVar5 = 3;
          aiStack_50[1] = 3;
          fStack_54 = fVar1;
        }
      }
      else {
        aiStack_50[0] = 3;
        iVar8 = 3;
        iVar5 = iVar11;
        fVar3 = fVar1;
        fStack_54 = fVar2;
        aiStack_50[1] = iVar11;
      }
      iVar11 = DAT_00002120 * 0x10;
      iVar12 = DAT_00002124 * 0x10;
      fVar1 = (*(float *)(puVar10 + iVar11 + 8) - *(float *)(puVar10 + iVar12 + 8)) *
              (*(float *)(puVar10 + iVar11 + 8) - *(float *)(puVar10 + iVar12 + 8)) +
              (*(float *)(puVar10 + iVar11) - *(float *)(puVar10 + iVar12)) *
              (*(float *)(puVar10 + iVar11) - *(float *)(puVar10 + iVar12)) +
              (*(float *)(puVar10 + iVar11 + 4) - *(float *)(puVar10 + iVar12 + 4)) *
              (*(float *)(puVar10 + iVar11 + 4) - *(float *)(puVar10 + iVar12 + 4));
      if (fVar1 < fVar3 == (NAN(fVar1) || NAN(fVar3))) {
        iVar11 = iVar8;
        fVar2 = fVar3;
        if (fVar1 < fStack_54) {
          iVar5 = 4;
          aiStack_50[1] = 4;
          fStack_54 = fVar1;
        }
      }
      else {
        aiStack_50[0] = 4;
        iVar11 = 4;
        iVar5 = iVar8;
        fVar2 = fVar1;
        fStack_54 = fVar3;
        aiStack_50[1] = iVar8;
      }
      iVar8 = DAT_00002128 * 0x10;
      iVar12 = DAT_0000212c * 0x10;
      fStack_48 = *(float *)(puVar10 + iVar8) - *(float *)(puVar10 + iVar12);
      fStack_44 = *(float *)(puVar10 + iVar8 + 4) - *(float *)(puVar10 + iVar12 + 4);
      fStack_40 = *(float *)(puVar10 + iVar8 + 8) - *(float *)(puVar10 + iVar12 + 8);
      fVar1 = fStack_40 * fStack_40 + fStack_48 * fStack_48 + fStack_44 * fStack_44;
      if (fVar1 < fVar2 == (NAN(fVar1) || NAN(fVar2))) {
        iVar8 = iVar11;
        if (fVar1 < fStack_54) {
          iVar5 = 5;
          aiStack_50[1] = 5;
        }
      }
      else {
        aiStack_50[0] = 5;
        iVar8 = 5;
        iVar5 = iVar11;
        aiStack_50[1] = iVar11;
      }
      iVar11 = (&_edgeVerts)[iVar8 * 2] * 0x10;
      iVar8 = (&DAT_00002104)[iVar8 * 2] * 0x10;
      fStack_18 = (float)(((float10)*(float *)(puVar10 + iVar11) +
                          (float10)*(float *)(puVar10 + iVar8)) * fVar13);
      fStack_14 = (float)(((float10)*(float *)(puVar10 + iVar8 + 4) +
                          (float10)*(float *)(puVar10 + iVar11 + 4)) * fVar13);
      pfVar6 = (float *)(puVar10 + (&_edgeVerts)[iVar5 * 2] * 0x10);
      pfVar9 = (float *)(puVar10 + (&DAT_00002104)[iVar5 * 2] * 0x10);
      fStack_10 = (float)(((float10)*(float *)(puVar10 + iVar8 + 8) +
                          (float10)*(float *)(puVar10 + iVar11 + 8)) * fVar13);
      fStack_c = (float)(((float10)*pfVar6 + (float10)*pfVar9) * fVar13);
      fStack_8 = (float)(((float10)pfVar9[1] + (float10)pfVar6[1]) * fVar13);
      fStack_4 = (float)(((float10)pfVar9[2] + (float10)pfVar6[2]) * fVar13);
      fStack_24 = fStack_c - fStack_18;
      fStack_20 = fStack_8 - fStack_14;
      fStack_1c = fStack_4 - fStack_10;
      _CrossProduct(&fStack_24,&uStack_30,&fStack_3c);
      _VectorNormalize(&fStack_3c);
      pfStack_74 = &fStack_14;
      iStack_6c = 0;
      do {
        iVar5 = (&_edgeVerts)[*(int *)((int)aiStack_50 + iStack_6c) * 2];
        iVar8 = (&DAT_00002104)[*(int *)((int)aiStack_50 + iStack_6c) * 2];
        pfVar6 = (float *)(puVar10 + iVar5 * 0x10);
        pfVar9 = (float *)(puVar10 + iVar8 * 0x10);
        fVar14 = (float10)__CIsqrt();
        fVar13 = (float10)___real_3fe0000000000000;
        iVar11 = 0;
        fVar1 = (float)(fVar14 * fVar13);
        piVar7 = piStack_64;
        do {
          if ((piVar7[-1] == iVar5 + iStack_68) && (*piVar7 == iVar8 + iStack_68)) break;
          iVar11 = iVar11 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar11 < 5);
        if (iVar11 == 5) {
          *pfVar6 = pfStack_74[-1] + fVar1 * fStack_3c;
          pfVar6[1] = fStack_38 * fVar1 + *pfStack_74;
          pfVar6[2] = fStack_34 * fVar1 + pfStack_74[1];
          fVar1 = -fVar1;
          *pfVar9 = fVar1 * fStack_3c + pfStack_74[-1];
          pfVar9[1] = fVar1 * fStack_38 + *pfStack_74;
          fVar1 = fVar1 * fStack_34 + pfStack_74[1];
        }
        else {
          fVar2 = -fVar1;
          *pfVar6 = fVar2 * fStack_3c + pfStack_74[-1];
          pfVar6[1] = fVar2 * fStack_38 + *pfStack_74;
          pfVar6[2] = fVar2 * fStack_34 + pfStack_74[1];
          *pfVar9 = fStack_3c * fVar1 + pfStack_74[-1];
          pfVar9[1] = fStack_38 * fVar1 + *pfStack_74;
          fVar1 = fVar1 * fStack_34 + pfStack_74[1];
        }
        pfVar9[2] = fVar1;
        iStack_6c = iStack_6c + 4;
        pfStack_74 = pfStack_74 + 3;
      } while (iStack_6c < 8);
      piStack_64 = piStack_64 + 6;
      iStack_68 = iStack_68 + 4;
      puVar10 = puVar10 + 0x40;
    } while (iStack_68 < (int)_DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcColorFromEntity @ 0000f70b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcColorFromEntity(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (_DAT_00015960 != 0) {
    uVar1 = __ftol2_sse();
    iVar2 = 0;
    if (0 < _DAT_0032c47c) {
      do {
        *param_1 = uVar1;
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 1;
      } while (iVar2 < _DAT_0032c47c);
    }
  }
  return;
}



// ===========================================
// Function: _RB_CalcColorFromOneMinusEntity @ 0000f74b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcColorFromOneMinusEntity(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  if (_DAT_00015960 != 0) {
    iVar1 = 0;
    param_1 = (undefined4 *)
              CONCAT13(-1 - *(char *)(_DAT_00015960 + 0xbf),
                       CONCAT12(-1 - *(char *)(_DAT_00015960 + 0xbe),
                                CONCAT11(-1 - *(char *)(_DAT_00015960 + 0xbd),
                                         -1 - *(char *)(_DAT_00015960 + 0xbc))));
    if (0 < _DAT_0032c47c) {
      do {
        *puVar2 = param_1;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar1 < _DAT_0032c47c);
    }
  }
  return;
}



// ===========================================
// Function: _RB_CalcColorFromConstant @ 0000f7aa
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcColorFromConstant(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      *param_1 = *param_2;
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 1;
    } while (iVar1 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFromConstant @ 0000f7cf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFromConstant(int param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    puVar1 = (undefined1 *)(param_1 + 3);
    do {
      *puVar1 = param_2;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 4;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFromDot @ 0000f7f3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFromDot(int param_1,float param_2,float param_3)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  undefined1 *puVar4;
  undefined1 uStack_20;
  uint local_1c [2];
  double local_14;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = 0;
  local_1c[0] = 0xffffffff;
  local_1c[1] = 0;
  if (0 < _DAT_0032c47c) {
    local_14 = (double)(param_3 - param_2);
    pfVar3 = (float *)&DAT_000c50ac;
    puVar4 = (undefined1 *)(param_1 + 3);
    do {
      local_c = _DAT_000158e0 - pfVar3[-1];
      local_8 = _DAT_000158e4 - *pfVar3;
      local_4 = _DAT_000158e8 - pfVar3[1];
      _VectorNormalizeFast(&local_c);
      iVar2 = iVar2 + 1;
      fVar1 = pfVar3[0x1d4c1] * local_4 + pfVar3[119999] * local_c + pfVar3[120000] * local_8;
      uStack_20 = (undefined1)
                  (int)ROUND(((float)((uint)fVar1 & local_1c[-((int)fVar1 >> 0x1f)]) *
                              (float)local_14 + param_2) * (float)___real_406fe00000000000);
      *puVar4 = uStack_20;
      pfVar3 = pfVar3 + 4;
      puVar4 = puVar4 + 4;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFromOneMinusDot @ 0000f8ee
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFromOneMinusDot(int param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined1 *puVar5;
  undefined1 uStack_20;
  uint local_1c [2];
  double local_14;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = 0;
  local_1c[0] = 0xffffffff;
  local_1c[1] = 0;
  if (0 < _DAT_0032c47c) {
    local_14 = (double)(param_3 - param_2);
    pfVar4 = (float *)&DAT_000c50ac;
    puVar5 = (undefined1 *)(param_1 + 3);
    do {
      local_c = _DAT_000158e0 - pfVar4[-1];
      local_8 = _DAT_000158e4 - *pfVar4;
      local_4 = _DAT_000158e8 - pfVar4[1];
      _VectorNormalizeFast(&local_c);
      iVar3 = iVar3 + 1;
      fVar1 = 1.0 - (pfVar4[0x1d4c1] * local_4 + pfVar4[119999] * local_c + pfVar4[120000] * local_8
                    );
      fVar1 = fVar1 * fVar1;
      fVar2 = fVar1 - 1.0;
      uStack_20 = (undefined1)
                  (int)ROUND(((fVar1 - (float)((uint)fVar2 & local_1c[-((int)fVar2 >> 0x1f)])) *
                              (float)local_14 + param_2) * (float)___real_406fe00000000000);
      *puVar5 = uStack_20;
      pfVar4 = pfVar4 + 4;
      puVar5 = puVar5 + 4;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFromEntity @ 0000fa11
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFromEntity(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (_DAT_00015960 != 0) {
    iVar1 = 0;
    puVar2 = (undefined1 *)(param_1 + 3);
    if (0 < _DAT_0032c47c) {
      do {
        *puVar2 = *(undefined1 *)(_DAT_00015960 + 0xbf);
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 4;
      } while (iVar1 < _DAT_0032c47c);
    }
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFromOneMinusEntity @ 0000fa46
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFromOneMinusEntity(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (_DAT_00015960 != 0) {
    cVar1 = *(char *)(_DAT_00015960 + 0xbf);
    iVar2 = 0;
    pcVar3 = (char *)(param_1 + 3);
    if (0 < _DAT_0032c47c) {
      do {
        *pcVar3 = -1 - (-1 - cVar1);
        iVar2 = iVar2 + 1;
        pcVar3 = pcVar3 + 4;
      } while (iVar2 < _DAT_0032c47c);
    }
  }
  return;
}



// ===========================================
// Function: _RB_CalcModulateRGBAsByFog_Alpha @ 0000fa86
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcModulateRGBAsByFog_Alpha(byte *param_1)

{
  float fVar1;
  int iVar2;
  byte local_4;
  
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      fVar1 = 1.0 - *(float *)(&DAT_0030efa8 + iVar2 * 4);
      iVar2 = iVar2 + 1;
      local_4 = (byte)(int)ROUND((float)*param_1 * fVar1);
      *param_1 = local_4;
      local_4 = (byte)(int)ROUND((float)param_1[1] * fVar1);
      param_1[1] = local_4;
      local_4 = (byte)(int)ROUND((float)param_1[2] * fVar1);
      param_1[2] = local_4;
      local_4 = (byte)(int)ROUND(fVar1 * (float)param_1[3]);
      param_1[3] = local_4;
      param_1 = param_1 + 4;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcModulateColorsByFog_Alpha @ 0000fb85
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcModulateColorsByFog_Alpha(byte *param_1)

{
  float fVar1;
  int iVar2;
  byte local_4;
  
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      fVar1 = 1.0 - *(float *)(&DAT_0030efa8 + iVar2 * 4);
      iVar2 = iVar2 + 1;
      local_4 = (byte)(int)ROUND((float)*param_1 * fVar1);
      *param_1 = local_4;
      local_4 = (byte)(int)ROUND((float)param_1[1] * fVar1);
      param_1[1] = local_4;
      local_4 = (byte)(int)ROUND(fVar1 * (float)param_1[2]);
      param_1[2] = local_4;
      param_1 = param_1 + 4;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcModulateAlphasByFog_Alpha @ 0000fc53
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcModulateAlphasByFog_Alpha(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte local_4;
  
  iVar3 = 0;
  if (0 < _DAT_0032c47c) {
    pbVar2 = (byte *)(param_1 + 3);
    do {
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      local_4 = (byte)(int)ROUND((1.0 - *(float *)(&DAT_0030efa8 + iVar1)) * (float)*pbVar2);
      *pbVar2 = local_4;
      pbVar2 = pbVar2 + 4;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFogBlend @ 0000fcb5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFogBlend(undefined4 *param_1)

{
  int iVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined1 local_4;
  
  dVar2 = ___real_406fe00000000000;
  if (_DAT_0032c46c == &DAT_0000270f) {
    iVar4 = 0x15d74;
  }
  else {
    iVar4 = (int)_DAT_0032c46c * 0x5c + *(int *)(___fltused + 0xb8);
  }
  iVar3 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      *param_1 = *(undefined4 *)(iVar4 + 0x1c);
      iVar1 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      local_4 = (undefined1)(int)ROUND((double)*(float *)(&DAT_0030efa8 + iVar1) * dVar2);
      *(undefined1 *)((int)param_1 + 3) = local_4;
      param_1 = param_1 + 1;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFogFarPlaneDensities @ 0000fd36
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFogFarPlaneDensities(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float10 fVar6;
  uint local_14 [2];
  float local_c;
  float local_8;
  float local_4;
  
  fVar3 = _DAT_00015d70;
  local_14[0] = 0xffffffff;
  local_14[1] = 0;
  if (0 < _DAT_0032c47c) {
    pfVar4 = (float *)&DAT_000c50b0;
    iVar5 = 0;
    do {
      local_c = pfVar4[-2] - _DAT_000158e0;
      local_8 = pfVar4[-1] - _DAT_000158e4;
      local_4 = *pfVar4 - _DAT_000158e8;
      fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
      fVar6 = (float10)_Q_rsqrt(fVar1);
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 4;
      fVar1 = (float)(fVar6 * (float10)fVar1 * (float10)fVar3);
      fVar2 = fVar1 - (float)___real_3ff0000000000000;
      *(float *)(iVar5 * 4 + 0x30efa4) =
           fVar1 - (float)((uint)fVar2 & local_14[-((int)fVar2 >> 0x1f)]);
    } while (iVar5 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcEnvironmentTexCoords @ 0000fe0a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcEnvironmentTexCoords(float *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float local_18;
  float local_14;
  float local_10;
  float fStack_8;
  float fStack_4;
  
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    pfVar3 = (float *)&DAT_000c50b0;
    do {
      local_18 = _DAT_000158e0 - pfVar3[-2];
      local_14 = _DAT_000158e4 - pfVar3[-1];
      local_10 = _DAT_000158e8 - *pfVar3;
      _VectorNormalizeFast(&local_18);
      iVar2 = iVar2 + 1;
      fVar1 = local_10 * pfVar3[120000] + local_14 * pfVar3[119999] + pfVar3[0x1d4be] * local_18;
      fStack_8 = fVar1 * pfVar3[119999] * (float)___real_4000000000000000 - local_14;
      fStack_4 = fVar1 * pfVar3[120000] * (float)___real_4000000000000000 - local_10;
      fVar1 = (float)___real_3fe0000000000000;
      *param_1 = fStack_8 * fVar1 + fVar1;
      param_1[1] = fVar1 - fStack_4 * fVar1;
      pfVar3 = pfVar3 + 4;
      param_1 = param_1 + 2;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcTurbulentTexCoords @ 0000fef1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcTurbulentTexCoords(int param_1,float *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      uVar1 = __ftol2_sse();
      *param_2 = *(float *)((uVar1 & 0x3ff) * 4 + 0x5c3c8) * *(float *)(param_1 + 8) + *param_2;
      uVar1 = __ftol2_sse();
      iVar2 = iVar2 + 1;
      param_2[1] = *(float *)((uVar1 & 0x3ff) * 4 + 0x5c3c8) * *(float *)(param_1 + 8) + param_2[1];
      param_2 = param_2 + 2;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcScaleTexCoords @ 0000ff9c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcScaleTexCoords(float *param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      iVar1 = iVar1 + 1;
      *param_2 = *param_1 * *param_2;
      param_2[1] = param_1[1] * param_2[1];
      param_2 = param_2 + 2;
    } while (iVar1 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcOffsetTexCoords @ 0000ffcb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcOffsetTexCoords(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if ((NAN(___real_4996b438) || NAN(*param_1)) == (___real_4996b438 == *param_1)) {
    fVar1 = *param_1;
  }
  else {
    fVar1 = (float)(int)*(short *)(_DAT_00015960 + 0xf0) * (float)___real_3f10000000000000;
  }
  if ((NAN(___real_4996b438) || NAN(param_1[1])) == (___real_4996b438 == param_1[1])) {
    fVar2 = param_1[1];
  }
  else {
    fVar2 = (float)___real_3f10000000000000 * (float)(int)*(short *)(_DAT_00015960 + 0xf2);
  }
  iVar3 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      iVar3 = iVar3 + 1;
      *param_2 = *param_2 + fVar1;
      param_2[1] = param_2[1] + fVar2;
      param_2 = param_2 + 2;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcParallaxTexCoords @ 0001005f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcParallaxTexCoords(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  fVar1 = *param_1 * _DAT_00015f48;
  fVar2 = param_1[1] * _DAT_00015f4c;
  if (0 < _DAT_0032c47c) {
    do {
      iVar3 = iVar3 + 1;
      *param_2 = *param_2 + fVar1;
      param_2[1] = fVar2 + param_2[1];
      param_2 = param_2 + 2;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_TextureAxisFromPlane @ 000100b2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_TextureAxisFromPlane(float *param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  
  pfVar3 = param_1;
  if (NAN(*param_1) == (*param_1 == 1.0)) {
    if ((NAN(___real_bf800000) || NAN(*param_1)) == (___real_bf800000 == *param_1)) {
      if (NAN(param_1[1]) == (param_1[1] == 1.0)) {
        if ((NAN(___real_bf800000) || NAN(param_1[1])) == (___real_bf800000 == param_1[1])) {
          if (NAN(param_1[2]) != (param_1[2] == 1.0)) {
            uVar4 = 0;
            goto LAB_000102b0;
          }
          if ((NAN(___real_bf800000) || NAN(param_1[2])) != (___real_bf800000 == param_1[2])) {
            uVar4 = 1;
            goto LAB_000102b0;
          }
          param_1 = (float *)0x0;
          fVar2 = pfVar3[2] * _DAT_00002138 + _DAT_00002134 * pfVar3[1] + *pfVar3 * __rb_baseaxis;
          if (0.0 < fVar2) {
            param_1 = (float *)fVar2;
          }
          fVar2 = pfVar3[2] * _DAT_0000215c + _DAT_00002158 * pfVar3[1] + *pfVar3 * _DAT_00002154;
          bVar1 = (float)param_1 < fVar2 != (NAN((float)param_1) || NAN(fVar2));
          if (bVar1) {
            param_1 = (float *)fVar2;
          }
          uVar4 = (uint)bVar1;
          fVar2 = _DAT_00002180 * pfVar3[2] + *pfVar3 * _DAT_00002178 + _DAT_0000217c * pfVar3[1];
          if ((float)param_1 < fVar2 != (NAN((float)param_1) || NAN(fVar2))) {
            uVar4 = 2;
            param_1 = (float *)fVar2;
          }
          fVar2 = _DAT_000021a4 * pfVar3[2] + *pfVar3 * _DAT_0000219c + _DAT_000021a0 * pfVar3[1];
          if ((float)param_1 < fVar2 != (NAN((float)param_1) || NAN(fVar2))) {
            uVar4 = 3;
            param_1 = (float *)fVar2;
          }
          fVar2 = _DAT_000021c8 * pfVar3[2] + *pfVar3 * _DAT_000021c0 + _DAT_000021c4 * pfVar3[1];
          if ((float)param_1 < fVar2 != (NAN((float)param_1) || NAN(fVar2))) {
            uVar4 = 4;
            param_1 = (float *)fVar2;
          }
          fVar2 = _DAT_000021ec * pfVar3[2] + *pfVar3 * _DAT_000021e4 + _DAT_000021e8 * pfVar3[1];
          if ((float)param_1 < fVar2 == (NAN((float)param_1) || NAN(fVar2))) goto LAB_000102b0;
        }
        uVar4 = 5;
      }
      else {
        uVar4 = 4;
      }
    }
    else {
      uVar4 = 3;
    }
  }
  else {
    uVar4 = 2;
  }
LAB_000102b0:
  *param_2 = (&DAT_0000213c)[uVar4 * 9];
  param_2[1] = (&DAT_00002140)[uVar4 * 9];
  param_2[2] = (&DAT_00002144)[uVar4 * 9];
  *param_3 = (&DAT_00002148)[uVar4 * 9];
  param_3[1] = (&DAT_0000214c)[uVar4 * 9];
  param_3[2] = (&DAT_00002150)[uVar4 * 9];
  return;
}



// ===========================================
// Function: _RB_QuakeTextureVecs @ 000102f6
// ===========================================

void _RB_QuakeTextureVecs(undefined4 param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  
  pfVar1 = param_3 + 3;
  _RB_TextureAxisFromPlane(param_1,param_3,pfVar1);
  *param_3 = *param_2 * *param_3;
  param_3[1] = param_3[1] * *param_2;
  param_3[2] = param_3[2] * *param_2;
  *pfVar1 = param_2[1] * *pfVar1;
  param_3[4] = param_3[4] * param_2[1];
  param_3[5] = param_2[1] * param_3[5];
  return;
}



// ===========================================
// Function: _RB_CalcMacroTexCoords @ 00010344
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcMacroTexCoords(float *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = *(int *)(*(int *)(_DAT_0032c468 + 0x194) + 8);
  iVar1 = *(int *)(iVar2 + 0x48);
  iVar3 = 0;
  iVar2 = *(int *)(iVar2 + 0x4c);
  if (0 < _DAT_0032c47c) {
    pfVar4 = (float *)&DAT_000c50ac;
    do {
      _RB_TextureAxisFromPlane(pfVar4 + 119999,&local_18,&local_c);
      local_18 = *param_1 * local_18;
      iVar3 = iVar3 + 1;
      local_14 = *param_1 * local_14;
      local_10 = *param_1 * local_10;
      local_c = param_1[1] * local_c;
      local_8 = param_1[1] * local_8;
      local_4 = param_1[1] * local_4;
      *param_2 = (local_10 * pfVar4[1] + local_18 * pfVar4[-1] + *pfVar4 * local_14) / (float)iVar1;
      param_2[1] = (local_4 * pfVar4[1] + local_c * pfVar4[-1] + *pfVar4 * local_8) / (float)iVar2;
      param_2 = param_2 + 2;
      pfVar4 = pfVar4 + 4;
    } while (iVar3 < _DAT_0032c47c);
  }
  return;
}



// Failed to decompile _RB_CalcScrollTexCoords

// ===========================================
// Function: _RB_CalcTransformTexCoords @ 00010518
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcTransformTexCoords(int param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    do {
      fVar1 = *param_2;
      iVar2 = iVar2 + 1;
      *param_2 = *(float *)(param_1 + 0x28) +
                 fVar1 * *(float *)(param_1 + 0x18) + param_2[1] * *(float *)(param_1 + 0x20);
      param_2[1] = param_2[1] * *(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x1c) * fVar1 +
                   *(float *)(param_1 + 0x2c);
      param_2 = param_2 + 2;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcRotateTexCoords @ 00010578
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcRotateTexCoords(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  uint uVar2;
  undefined1 auStack_4c [24];
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
  uVar2 = __ftol2_sse(__memmove);
  fStack_30 = *(float *)((uVar2 & 0x3ff) * 4 + 0x5c3c8);
  fStack_34 = *(float *)((uVar2 + 0x100 & 0x3ff) * 4 + 0x5c3c8);
  fStack_2c = -fStack_30;
  fVar1 = (float)___real_3fe0000000000000;
  fStack_24 = (fVar1 - fStack_34 * fVar1) + fStack_30 * fVar1;
  fStack_20 = (fVar1 - fStack_30 * fVar1) - fStack_34 * fVar1;
  fStack_28 = fStack_34;
  _RB_CalcTransformTexCoords(auStack_4c,param_2);
  return;
}



// ===========================================
// Function: _RB_LerpTikiVertexes @ 00010650
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_LerpTikiVertexes
               (ushort *param_1,int param_2,ushort *param_3,int param_4,float param_5,float *param_6
               ,float param_7,int param_8)

{
  ushort *puVar1;
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
  float fVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  float *pfVar21;
  float *pfVar22;
  ushort *puVar23;
  float *pfVar24;
  float *pfVar25;
  ushort *puVar26;
  
  iVar15 = (int)param_3;
  fVar14 = 1.0 - param_5;
  puVar26 = (ushort *)
            (*(int *)((int)param_1 + 0x60) +
             (int)*(short *)(_DAT_00015960 + 0x5e) * *(int *)((int)param_1 + 0x48) * 8 +
            (int)param_1);
  param_1 = puVar26 + 3;
  pfVar22 = (float *)(&DAT_000c50a8 + _DAT_0032c47c * 0x10);
  pfVar25 = (float *)(&DAT_0013a3a8 + _DAT_0032c47c * 0x10);
  fVar13 = param_7 * fVar14 * *(float *)((int)param_3 + 0x18);
  fVar12 = *(float *)((int)param_3 + 0x1c) * fVar14 * param_7;
  fVar11 = *(float *)((int)param_3 + 0x20) * fVar14 * param_7;
  if (NAN(param_5) != (param_5 == 0.0)) {
    iVar18 = 0;
    if (3 < param_8) {
      param_3 = (ushort *)((param_8 - 4U >> 2) + 1);
      iVar18 = (int)param_3 * 4;
      pfVar21 = pfVar22;
      pfVar24 = pfVar25;
      puVar23 = puVar26;
      do {
        *pfVar21 = *(float *)(iVar15 + 0x24) * param_7 + (float)*puVar23 * fVar13 + *param_6;
        pfVar21[1] = *(float *)(iVar15 + 0x28) * param_7 + (float)puVar23[1] * fVar12 + param_6[1];
        pfVar21[2] = *(float *)(iVar15 + 0x2c) * param_7 + (float)puVar23[2] * fVar11 + param_6[2];
        uVar19 = (int)(short)*param_1 & 0xff;
        uVar16 = (int)(short)*param_1 >> 8 & 0xff;
        uVar20 = uVar19 * 4 + 0x100;
        *pfVar24 = *(float *)((uVar16 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
                   *(float *)(uVar19 * 0x10 + 0x5c3c8);
        pfVar24[1] = *(float *)(uVar16 * 0x10 + 0x5c3c8) * *(float *)(uVar20 * 4 + 0x5bfc8);
        pfVar24[2] = *(float *)((uVar20 & 0x3ff) * 4 + 0x5c3c8);
        pfVar21[4] = *(float *)(iVar15 + 0x24) * param_7 + (float)puVar23[4] * fVar13 + *param_6;
        pfVar21[5] = *(float *)(iVar15 + 0x28) * param_7 + (float)puVar23[5] * fVar12 + param_6[1];
        pfVar21[6] = *(float *)(iVar15 + 0x2c) * param_7 + (float)puVar23[6] * fVar11 + param_6[2];
        uVar19 = (int)(short)param_1[4] & 0xff;
        uVar16 = (int)(short)param_1[4] >> 8 & 0xff;
        uVar20 = uVar19 * 4 + 0x100;
        pfVar24[4] = *(float *)((uVar16 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
                     *(float *)(uVar19 * 0x10 + 0x5c3c8);
        pfVar24[5] = *(float *)(uVar16 * 0x10 + 0x5c3c8) * *(float *)(uVar20 * 4 + 0x5bfc8);
        pfVar24[6] = *(float *)((uVar20 & 0x3ff) * 4 + 0x5c3c8);
        pfVar21[8] = *(float *)(iVar15 + 0x24) * param_7 + (float)puVar23[8] * fVar13 + *param_6;
        pfVar21[9] = *(float *)(iVar15 + 0x28) * param_7 + (float)puVar23[9] * fVar12 + param_6[1];
        pfVar21[10] = *(float *)(iVar15 + 0x2c) * param_7 + (float)puVar23[10] * fVar11 + param_6[2]
        ;
        uVar19 = (int)(short)param_1[8] & 0xff;
        uVar16 = (int)(short)param_1[8] >> 8 & 0xff;
        uVar20 = uVar19 * 4 + 0x100;
        pfVar24[8] = *(float *)((uVar16 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
                     *(float *)(uVar19 * 0x10 + 0x5c3c8);
        pfVar24[9] = *(float *)(uVar16 * 0x10 + 0x5c3c8) * *(float *)(uVar20 * 4 + 0x5bfc8);
        pfVar24[10] = *(float *)((uVar20 & 0x3ff) * 4 + 0x5c3c8);
        pfVar21[0xc] = *(float *)(iVar15 + 0x24) * param_7 + (float)puVar23[0xc] * fVar13 + *param_6
        ;
        puVar1 = param_1 + 0x10;
        pfVar22 = pfVar21 + 0x10;
        pfVar25 = pfVar24 + 0x10;
        puVar26 = puVar23 + 0x10;
        pfVar21[0xd] = *(float *)(iVar15 + 0x28) * param_7 +
                       (float)puVar23[0xd] * fVar12 + param_6[1];
        pfVar21[0xe] = *(float *)(iVar15 + 0x2c) * param_7 +
                       (float)puVar23[0xe] * fVar11 + param_6[2];
        uVar19 = (int)(short)param_1[0xc] & 0xff;
        uVar16 = (int)(short)param_1[0xc] >> 8 & 0xff;
        uVar20 = uVar19 * 4 + 0x100;
        pfVar24[0xc] = *(float *)((uVar16 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
                       *(float *)(uVar19 * 0x10 + 0x5c3c8);
        param_3 = (ushort *)((int)param_3 + -1);
        pfVar24[0xd] = *(float *)(uVar16 * 0x10 + 0x5c3c8) * *(float *)(uVar20 * 4 + 0x5bfc8);
        pfVar24[0xe] = *(float *)((uVar20 & 0x3ff) * 4 + 0x5c3c8);
        pfVar21 = pfVar22;
        pfVar24 = pfVar25;
        puVar23 = puVar26;
        param_1 = puVar1;
      } while (param_3 != (ushort *)0x0);
    }
    if (iVar18 < param_8) {
      param_3 = (ushort *)(param_8 - iVar18);
      do {
        *pfVar22 = *(float *)(iVar15 + 0x24) * param_7 + (float)*puVar26 * fVar13 + *param_6;
        pfVar22[1] = *(float *)(iVar15 + 0x28) * param_7 + (float)puVar26[1] * fVar12 + param_6[1];
        pfVar22[2] = *(float *)(iVar15 + 0x2c) * param_7 + (float)puVar26[2] * fVar11 + param_6[2];
        uVar19 = (int)(short)*param_1 & 0xff;
        uVar16 = (int)(short)*param_1 >> 8 & 0xff;
        uVar20 = uVar19 * 4 + 0x100;
        *pfVar25 = *(float *)((uVar16 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
                   *(float *)(uVar19 * 0x10 + 0x5c3c8);
        param_3 = (ushort *)((int)param_3 + -1);
        pfVar25[1] = *(float *)(uVar16 * 0x10 + 0x5c3c8) * *(float *)(uVar20 * 4 + 0x5bfc8);
        pfVar25[2] = *(float *)((uVar20 & 0x3ff) * 4 + 0x5c3c8);
        pfVar22 = pfVar22 + 4;
        pfVar25 = pfVar25 + 4;
        puVar26 = puVar26 + 4;
        param_1 = param_1 + 4;
      } while (param_3 != (ushort *)0x0);
    }
    return;
  }
  puVar23 = (ushort *)
            (*(int *)(param_2 + 0x60) +
             (int)*(short *)(_DAT_00015960 + 0x5c) * *(int *)(param_2 + 0x48) * 8 + param_2);
  fVar10 = *(float *)(param_4 + 0x18) * param_5 * param_7;
  fVar2 = fVar14 * param_7;
  fVar3 = param_5 * param_7;
  *param_6 = *(float *)((int)param_3 + 0x24) * fVar2 + *(float *)(param_4 + 0x24) * fVar3 + *param_6
  ;
  fVar8 = *(float *)(param_4 + 0x1c) * param_5 * param_7;
  param_6[1] = *(float *)((int)param_3 + 0x28) * fVar2 + *(float *)(param_4 + 0x28) * fVar3 +
               param_6[1];
  fVar9 = *(float *)(param_4 + 0x20) * param_5 * param_7;
  param_6[2] = param_6[2] +
               fVar2 * *(float *)((int)param_3 + 0x2c) + *(float *)(param_4 + 0x2c) * fVar3;
  if (param_8 < 1) {
    return;
  }
  param_7 = (float)param_8;
  param_3 = puVar23 + 3;
  do {
    *pfVar22 = (float)*puVar26 * fVar13 + (float)*puVar23 * fVar10 + *param_6;
    pfVar22[1] = (float)puVar26[1] * fVar12 + (float)puVar23[1] * fVar8 + param_6[1];
    pfVar22[2] = (float)puVar26[2] * fVar11 + (float)puVar23[2] * fVar9 + param_6[2];
    uVar16 = (int)(short)*param_1 >> 8 & 0xff;
    uVar20 = ((int)(short)*param_1 & 0xffU) * 4 + 0x100;
    fVar2 = *(float *)(uVar16 * 0x10 + 0x5c3c8);
    fVar3 = *(float *)(uVar20 * 4 + 0x5bfc8);
    fVar4 = *(float *)((uVar20 & 0x3ff) * 4 + 0x5c3c8);
    uVar19 = (int)(short)*param_3 >> 8 & 0xff;
    uVar17 = ((int)(short)*param_3 & 0xffU) * 4 + 0x100;
    fVar5 = *(float *)(uVar19 * 0x10 + 0x5c3c8);
    fVar6 = *(float *)(uVar17 * 4 + 0x5bfc8);
    fVar7 = *(float *)((uVar17 & 0x3ff) * 4 + 0x5c3c8);
    *pfVar25 = *(float *)((uVar16 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
               *(float *)(uVar20 * 4 + 0x5bfc8) * fVar14 +
               *(float *)((uVar19 * 4 + 0x100 & 0x3ff) * 4 + 0x5c3c8) *
               *(float *)(uVar17 * 4 + 0x5bfc8) * param_5;
    pfVar25[1] = fVar5 * fVar6 * param_5 + fVar2 * fVar3 * fVar14;
    pfVar25[2] = fVar14 * fVar4 + fVar7 * param_5;
    _VectorNormalize(pfVar25);
    param_3 = param_3 + 4;
    param_1 = param_1 + 4;
    puVar23 = puVar23 + 4;
    puVar26 = puVar26 + 4;
    pfVar22 = pfVar22 + 4;
    pfVar25 = pfVar25 + 4;
    param_7 = (float)((int)param_7 + -1);
  } while (param_7 != 0.0);
  return;
}



// ===========================================
// Function: _RB_TikiMesh @ 00010d5a
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_TikiMesh(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int aiStack_4b00 [4799];
  undefined4 uStack_4;
  
  uStack_4 = 0x10d64;
  if (((*(int *)(_DAT_00015960 + 0x1b0) != 0) && (*(int *)(_DAT_00015960 + 0x1a8) != 0)) &&
     (*(int *)(_DAT_00015960 + 0x1ac) != 0)) {
    iVar10 = *(int *)(param_1 + 4);
    iVar6 = *(int *)(iVar10 + 0x48);
    iVar3 = __ftol2_sse();
    iVar9 = *(int *)(iVar10 + 0x4c);
    if ((iVar9 <= iVar3) || (iVar3 = iVar9, 0 < iVar9)) {
      if (iVar6 < iVar3) {
        iVar3 = iVar6;
      }
      _RB_CheckOverflow();
      _RB_LerpTikiVertexes();
      iVar6 = *(int *)(iVar10 + 0x58);
      iVar9 = *(int *)(iVar10 + 0x48);
      iVar7 = *(int *)(iVar10 + 0x54) + iVar10;
      iVar1 = *(int *)(iVar10 + 0x50) * 3;
      if (iVar3 == iVar9) {
        iVar6 = _DAT_0032c478 * 4;
        if (0 < iVar1) {
          piVar4 = (int *)(&_tess + iVar6);
          iVar9 = iVar1;
          do {
            iVar9 = iVar9 + -1;
            *piVar4 = *(int *)((iVar7 - (int)(&_tess + iVar6)) + (int)piVar4) + _DAT_0032c47c;
            piVar4 = piVar4 + 1;
          } while (iVar9 != 0);
        }
        _DAT_0032c478 = _DAT_0032c478 + iVar1;
      }
      else {
        iVar5 = 0;
        iVar2 = iVar3;
        if (0 < iVar3) {
          do {
            aiStack_4b00[iVar5] = iVar5;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar3);
        }
        for (; iVar2 < iVar9; iVar2 = iVar2 + 1) {
          aiStack_4b00[iVar2] = aiStack_4b00[*(int *)(iVar6 + iVar10 + iVar2 * 4)];
        }
        if (0 < iVar1) {
          piVar4 = (int *)(iVar7 + 8);
          iVar6 = (iVar1 - 1U) / 3 + 1;
          do {
            iVar9 = aiStack_4b00[piVar4[-2]];
            iVar1 = aiStack_4b00[piVar4[-1]];
            iVar7 = aiStack_4b00[*piVar4];
            if (((iVar9 != iVar1) && (iVar1 != iVar7)) && (iVar7 != iVar9)) {
              *(int *)(&_tess + _DAT_0032c478 * 4) = _DAT_0032c47c + iVar9;
              *(int *)(&DAT_0001542c + _DAT_0032c478 * 4) = _DAT_0032c47c + iVar1;
              *(int *)(&_tr + _DAT_0032c478 * 4) = _DAT_0032c47c + iVar7;
              _DAT_0032c478 = _DAT_0032c478 + 3;
            }
            piVar4 = piVar4 + 3;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      iVar10 = *(int *)(iVar10 + 0x5c) + iVar10;
      iVar6 = 0;
      if (3 < iVar3) {
        puVar8 = (undefined4 *)(iVar10 + 8);
        do {
          *(undefined4 *)(&DAT_001af6a8 + (_DAT_0032c47c + iVar6) * 0x10) = puVar8[-2];
          *(undefined4 *)((_DAT_0032c47c + iVar6) * 0x10 + 0x1af6ac) = puVar8[-1];
          *(undefined4 *)(&DAT_001af6b8 + (_DAT_0032c47c + iVar6) * 0x10) = *puVar8;
          *(undefined4 *)((_DAT_0032c47c + iVar6) * 0x10 + 0x1af6bc) = puVar8[1];
          *(undefined4 *)((_DAT_0032c47c + iVar6) * 0x10 + 0x1af6c8) = puVar8[2];
          *(undefined4 *)((_DAT_0032c47c + iVar6) * 0x10 + 0x1af6cc) = puVar8[3];
          *(undefined4 *)((_DAT_0032c47c + iVar6) * 0x10 + 0x1af6d8) = puVar8[4];
          iVar9 = _DAT_0032c47c + iVar6;
          iVar6 = iVar6 + 4;
          *(undefined4 *)(iVar9 * 0x10 + 0x1af6dc) = puVar8[5];
          puVar8 = puVar8 + 8;
        } while (iVar6 < iVar3 + -3);
      }
      for (; iVar6 < iVar3; iVar6 = iVar6 + 1) {
        *(undefined4 *)(&DAT_001af6a8 + (_DAT_0032c47c + iVar6) * 0x10) =
             *(undefined4 *)(iVar10 + iVar6 * 8);
        *(undefined4 *)((_DAT_0032c47c + iVar6) * 0x10 + 0x1af6ac) =
             *(undefined4 *)(iVar10 + 4 + iVar6 * 8);
      }
      _DAT_0032c47c = _DAT_0032c47c + iVar3;
    }
  }
  return;
}



// ===========================================
// Function: _LocalMatrixTransformVector @ 0001109b
// ===========================================

void _LocalMatrixTransformVector(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_2[6] * param_1[2] + *param_1 * *param_2 + param_2[3] * param_1[1];
  param_3[1] = param_2[7] * param_1[2] + param_2[4] * param_1[1] + param_2[1] * *param_1;
  param_3[2] = param_2[8] * param_1[2] + param_2[5] * param_1[1] + param_2[2] * *param_1;
  return;
}



// ===========================================
// Function: _B @ 000110ee
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _B(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  fVar5 = (1.0 - param_2) - param_3;
  in_EAX[2] = 0.0;
  in_EAX[1] = 0.0;
  *in_EAX = 0.0;
  fVar3 = fVar5 * fVar5 * fVar5;
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *in_EAX = *param_1 * fVar3 + 0.0;
  in_EAX[1] = fVar1 * fVar3 + 0.0;
  in_EAX[2] = fVar3 * fVar2 + 0.0;
  fVar3 = param_2 * param_2 * param_2;
  fVar1 = param_1[4];
  fVar2 = param_1[5];
  *in_EAX = *in_EAX + param_1[3] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  fVar3 = param_3 * param_3 * param_3;
  fVar1 = param_1[7];
  fVar2 = param_1[8];
  *in_EAX = *in_EAX + param_1[6] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  fVar4 = (float)___real_4008000000000000;
  fVar6 = fVar5 * fVar4;
  fVar3 = param_2 * fVar5 * fVar6;
  fVar1 = param_1[10];
  fVar2 = param_1[0xb];
  *in_EAX = *in_EAX + param_1[9] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  fVar3 = param_2 * fVar6 * param_2;
  fVar1 = param_1[0xd];
  fVar2 = param_1[0xe];
  *in_EAX = *in_EAX + param_1[0xc] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  fVar3 = fVar5 * fVar6 * param_3;
  fVar1 = param_1[0x10];
  fVar2 = param_1[0x11];
  *in_EAX = *in_EAX + param_1[0xf] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  fVar4 = fVar4 * param_2;
  fVar3 = param_2 * fVar4 * param_3;
  fVar1 = param_1[0x13];
  fVar2 = param_1[0x14];
  *in_EAX = *in_EAX + param_1[0x12] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  fVar3 = param_3 * param_3 * fVar6;
  fVar1 = param_1[0x16];
  fVar2 = param_1[0x17];
  *in_EAX = *in_EAX + param_1[0x15] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar2 * fVar3;
  fVar3 = fVar4 * param_3 * param_3;
  fVar1 = param_1[0x19];
  fVar2 = param_1[0x1a];
  *in_EAX = *in_EAX + param_1[0x18] * fVar3;
  in_EAX[1] = in_EAX[1] + fVar1 * fVar3;
  in_EAX[2] = in_EAX[2] + fVar3 * fVar2;
  param_3 = param_3 * fVar5 * (float)___real_4018000000000000 * param_2;
  fVar1 = param_1[0x1c];
  fVar2 = param_1[0x1d];
  *in_EAX = *in_EAX + param_1[0x1b] * param_3;
  in_EAX[1] = in_EAX[1] + fVar1 * param_3;
  in_EAX[2] = in_EAX[2] + param_3 * fVar2;
  return;
}



// ===========================================
// Function: _CurvedPNTriangle @ 00011413
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CurvedPNTriangle(int param_1,int param_2,int param_3)

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
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  int in_EAX;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iStack_160;
  int iStack_124;
  float fStack_10c;
  float fStack_100;
  int iStack_a4;
  
  iVar25 = _DAT_0032c478;
  iVar23 = in_EAX + 1;
  iVar21 = (param_2 / 3) * 3;
  iVar24 = iVar23 * iVar23 * iVar21;
  iVar21 = (iVar23 * iVar23 + 1) * iVar21;
  _RB_CheckOverflow(iVar21,iVar24);
  if (0 < param_2) {
    fVar16 = (float)___real_3fd5555560000000;
    piVar22 = (int *)(&DAT_0001542c + param_1 * 4);
    iStack_124 = (param_2 - 1U) / 3 + 1;
    do {
      iVar18 = piVar22[-1] * 0x10;
      iStack_a4 = *(int *)(&DAT_000c50a8 + iVar18);
      iVar19 = *piVar22 * 0x10;
      iVar20 = piVar22[1] * 0x10;
      fVar1 = *(float *)(&DAT_0013a3a8 + iVar18);
      fVar2 = *(float *)(&DAT_0013a3ac + iVar18);
      fVar3 = *(float *)(&DAT_0013a3b0 + iVar18);
      fVar4 = *(float *)(&DAT_0013a3a8 + iVar19);
      fVar5 = *(float *)(&DAT_0013a3ac + iVar19);
      fStack_10c = *(float *)(&DAT_0013a3b0 + iVar19);
      fVar6 = *(float *)(&DAT_0013a3a8 + iVar20);
      fVar7 = *(float *)(&DAT_0013a3ac + iVar20);
      fVar8 = *(float *)(&DAT_0013a3b0 + iVar20);
      fVar9 = *(float *)(&DAT_001af6a8 + piVar22[-1] * 0x10);
      fVar10 = *(float *)(piVar22[-1] * 0x10 + 0x1af6ac);
      fVar11 = *(float *)(&DAT_001af6a8 + *piVar22 * 0x10);
      fVar12 = *(float *)(*piVar22 * 0x10 + 0x1af6ac);
      fVar13 = *(float *)(&DAT_001af6a8 + piVar22[1] * 0x10);
      fVar14 = *(float *)(piVar22[1] * 0x10 + 0x1af6ac);
      fStack_100 = (*(float *)(&DAT_000c50b0 + iVar18) + *(float *)(&DAT_000c50b0 + iVar19) +
                   *(float *)(&DAT_000c50b0 + iVar20)) * fVar16;
      iStack_160 = 0;
      iVar18 = iVar23;
      if (-1 < iVar23) {
        do {
          iVar19 = iStack_160;
          fVar15 = (float)iStack_160;
          iStack_160 = 0;
          fVar15 = fVar15 * (1.0 / (float)iVar23);
          if (-1 < iVar18) {
            do {
              fVar16 = (float)iStack_160 * (1.0 / (float)iVar23);
              _B(fVar16,fVar15);
              iVar20 = _DAT_0032c47c * 0x10;
              fVar17 = (1.0 - fVar16) - fVar15;
              *(float *)(&DAT_0013a3a8 + iVar20) = fVar17 * fVar1 + fVar16 * fVar4 + fVar15 * fVar6;
              *(float *)(&DAT_0013a3ac + iVar20) = fVar17 * fVar2 + fVar16 * fVar5 + fVar15 * fVar7;
              *(float *)(&DAT_0013a3b0 + iVar20) =
                   fVar17 * fVar3 + fStack_10c * fVar16 + fVar15 * fVar8;
              _VectorNormalize(&DAT_0013a3a8 + iVar20);
              iVar20 = _DAT_0032c47c * 0x10;
              *(float *)(&DAT_001af6a8 + iVar20) =
                   fVar17 * fVar9 + fVar16 * fVar11 + fVar13 * fVar15;
              *(float *)(iVar20 + 0x1af6ac) = fVar17 * fVar10 + fVar12 * fVar16 + fVar14 * fVar15;
              if (iStack_160 < iVar18) {
                *(int *)(&_tess + _DAT_0032c478 * 4) = _DAT_0032c47c;
                _DAT_0032c478 = _DAT_0032c478 + 1;
                *(int *)(&_tess + _DAT_0032c478 * 4) = _DAT_0032c47c + 1;
                _DAT_0032c478 = _DAT_0032c478 + 1;
                *(int *)(&_tess + _DAT_0032c478 * 4) = (_DAT_0032c47c - iVar19) + 2 + in_EAX;
                _DAT_0032c478 = _DAT_0032c478 + 1;
              }
              if (iStack_160 < iVar18 + -1) {
                *(int *)(&_tess + _DAT_0032c478 * 4) = _DAT_0032c47c + 1;
                _DAT_0032c478 = _DAT_0032c478 + 1;
                *(int *)(&_tess + _DAT_0032c478 * 4) = (_DAT_0032c47c - iVar19) + 3 + in_EAX;
                _DAT_0032c478 = _DAT_0032c478 + 1;
                *(int *)(&_tess + _DAT_0032c478 * 4) = (_DAT_0032c47c - iVar19) + 2 + in_EAX;
                _DAT_0032c478 = _DAT_0032c478 + 1;
              }
              _DAT_0032c47c = _DAT_0032c47c + 1;
              iStack_160 = iStack_160 + 1;
            } while (iStack_160 <= iVar18);
            fVar16 = (float)___real_3fd5555560000000;
          }
          iStack_160 = iVar19 + 1;
          iVar18 = iVar18 + -1;
        } while (iStack_160 <= iVar23);
      }
      piVar22 = piVar22 + 3;
      iStack_124 = iStack_124 + -1;
    } while (iStack_124 != 0);
  }
  _memmove(&_tess + param_1 * 4,&_tess + iVar25 * 4,iVar24 * 4);
  _DAT_0032c478 = _DAT_0032c478 - param_2;
  iVar25 = iVar25 * 0x10;
  iVar23 = param_3 * 0x10;
  _memmove(&DAT_000c50a8 + iVar23,&DAT_000c50a8 + iVar25,iVar21 * 0x10);
  _memmove(&DAT_0013a3a8 + iVar23,&DAT_0013a3a8 + iVar25,(size_t)fStack_10c);
  _memmove(&DAT_001af6a8 + iVar23,&DAT_001af6a8 + iVar25,(size_t)fStack_100);
  _DAT_0032c47c = _DAT_0032c47c + (param_3 - iStack_a4);
  iVar23 = param_1;
  if (param_1 < _DAT_0032c478 + param_1) {
    do {
      *(int *)(&_tess + iVar23 * 4) = *(int *)(&_tess + iVar23 * 4) + (param_3 - iStack_a4);
      iVar23 = iVar23 + 1;
    } while (iVar23 < _DAT_0032c478 + param_1);
  }
  return;
}



// ===========================================
// Function: _RB_SkelMesh @ 00012206
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SkelMesh(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  int unaff_ESI;
  float *pfVar14;
  float *pfVar15;
  int unaff_EDI;
  float *pfVar16;
  int *piVar17;
  int iStack_4b30;
  int iStack_4b28;
  float fStack_4b20;
  float fStack_4b1c;
  float fStack_4b18;
  int aiStack_4b00 [4799];
  undefined4 uStack_4;
  
  uStack_4 = 0x12210;
  iVar12 = *(int *)(_DAT_00015960 + 0x1b0);
  iVar7 = _TIKI_GetSkel(*(undefined4 *)(iVar12 + 0xe4));
  iVar9 = *(int *)(param_1 + 0x48);
  iVar2 = *(int *)(_DAT_00015960 + 0x1b4);
  if (_DAT_00015734 == 0) {
    iStack_4b28 = __ftol2_sse();
  }
  else {
    iStack_4b28 = __ftol2_sse();
  }
  iVar3 = *(int *)(param_1 + 0x4c);
  if ((iVar3 <= iStack_4b28) || (iStack_4b28 = iVar3, 0 < iVar3)) {
    if (iVar9 < iStack_4b28) {
      iStack_4b28 = iVar9;
    }
    _RB_CheckOverflow(iStack_4b28,*(int *)(param_1 + 0x44) * 4);
    iVar6 = _DAT_0032c47c;
    iVar3 = _DAT_0032c478;
    fVar4 = *(float *)(_DAT_00015960 + 0x60) * *(float *)(iVar12 + 0xa4);
    iVar12 = *(int *)(param_1 + 0x58);
    iVar9 = *(int *)(param_1 + 0x44) * 3;
    iVar11 = *(int *)(param_1 + 0x50) + param_1;
    if (*(int *)(__r_showskel + 0x20) == 0) {
      _DAT_0032c47c = _DAT_0032c47c + iStack_4b28;
      iVar7 = *(int *)(param_1 + 0x48);
      iVar8 = 0;
      if (iStack_4b28 == iVar7) {
        if (0 < iVar9) {
          piVar17 = (int *)(&_tess + _DAT_0032c478 * 4);
          do {
            iVar12 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *piVar17 = *(int *)(iVar11 + iVar12) + iVar6;
            piVar17 = piVar17 + 1;
          } while (iVar8 < iVar9);
        }
        _DAT_0032c478 = _DAT_0032c478 + iVar9;
      }
      else {
        iVar5 = iStack_4b28;
        if (0 < iStack_4b28) {
          do {
            aiStack_4b00[iVar8] = iVar8;
            iVar8 = iVar8 + 1;
          } while (iVar8 < iStack_4b28);
        }
        for (; iVar5 < iVar7; iVar5 = iVar5 + 1) {
          aiStack_4b00[iVar5] = aiStack_4b00[*(int *)(iVar12 + param_1 + iVar5 * 4)];
        }
        if (0 < iVar9) {
          piVar17 = (int *)(iVar11 + 8);
          iVar12 = (iVar9 - 1U) / 3 + 1;
          do {
            iVar9 = aiStack_4b00[piVar17[-2]];
            iVar7 = aiStack_4b00[piVar17[-1]];
            iVar11 = aiStack_4b00[*piVar17];
            if (((iVar9 != iVar7) && (iVar7 != iVar11)) && (iVar11 != iVar9)) {
              *(int *)(&_tess + _DAT_0032c478 * 4) = iVar9 + iVar6;
              *(int *)(&DAT_0001542c + _DAT_0032c478 * 4) = iVar7 + iVar6;
              *(int *)(&_tr + _DAT_0032c478 * 4) = iVar11 + iVar6;
              _DAT_0032c478 = _DAT_0032c478 + 3;
            }
            piVar17 = piVar17 + 3;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
      }
      if (0 < iStack_4b28) {
        pfVar15 = (float *)(*(int *)(param_1 + 0x54) + param_1);
        pfVar14 = (float *)(&DAT_0013a3b0 + iVar6 * 0x10);
        iStack_4b30 = iStack_4b28;
        do {
          fVar13 = pfVar15[5];
          fStack_4b18 = 0.0;
          pfVar1 = pfVar15 + 6;
          fStack_4b1c = 0.0;
          fStack_4b20 = 0.0;
          pfVar16 = pfVar1;
          if (0 < (int)fVar13) {
            pfVar10 = pfVar15 + 10;
            do {
              iVar12 = (int)*pfVar16 * 0x40 + iVar2 * 0x40;
              pfVar16 = pfVar16 + 5;
              fVar13 = (float)((int)fVar13 + -1);
              fStack_4b20 = (*(float *)(&_TIKI_Skel_Bones + iVar12 + 0x10) +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x34) * *pfVar10 +
                            pfVar10[-2] * *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x1c) +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x28) * pfVar10[-1]) *
                            pfVar10[-3] + fStack_4b20;
              fStack_4b1c = (*(float *)(&_TIKI_Skel_Bones + iVar12 + 0x14) +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x38) * *pfVar10 +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x20) * pfVar10[-2] +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x2c) * pfVar10[-1]) *
                            pfVar10[-3] + fStack_4b1c;
              fStack_4b18 = (*(float *)(&_TIKI_Skel_Bones + iVar12 + 0x18) +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x3c) * *pfVar10 +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x24) * pfVar10[-2] +
                            *(float *)(&_TIKI_Skel_Bones + iVar12 + 0x30) * pfVar10[-1]) *
                            pfVar10[-3] + fStack_4b18;
              pfVar10 = pfVar10 + 5;
            } while (fVar13 != 0.0);
          }
          pfVar10 = (float *)(&_TIKI_Skel_Bones + (int)*pfVar1 * 0x40 + 0x1c + iVar2 * 0x40);
          iStack_4b30 = iStack_4b30 + -1;
          pfVar14[-2] = pfVar10[6] * pfVar15[2] +
                        *pfVar15 * *pfVar10 +
                        *(float *)(&_TIKI_Skel_Bones + (int)*pfVar1 * 0x40 + 0x28 + iVar2 * 0x40) *
                        pfVar15[1];
          pfVar14[-1] = pfVar10[7] * pfVar15[2] + pfVar10[1] * *pfVar15 + pfVar10[4] * pfVar15[1];
          *pfVar14 = pfVar10[8] * pfVar15[2] + pfVar10[2] * *pfVar15 + pfVar10[5] * pfVar15[1];
          pfVar14[-0x1d4c2] = fStack_4b20 * fVar4;
          pfVar14[-0x1d4c1] = fStack_4b1c * fVar4;
          pfVar14[-120000] = fStack_4b18 * fVar4;
          pfVar14[0x1d4be] = pfVar15[3];
          pfVar14[119999] = pfVar15[4];
          pfVar15 = pfVar16;
          pfVar14 = pfVar14 + 4;
        } while (iStack_4b30 != 0);
      }
      if (0 < *(int *)(__r_skelsubdivision + 0x20)) {
        _CurvedPNTriangle(iVar3,_DAT_0032c478 - iVar3,iVar6);
        return;
      }
    }
    else if ((NAN(___real_bf800000) || NAN(*(float *)(_DAT_00015960 + 0x200))) ==
             (___real_bf800000 == *(float *)(_DAT_00015960 + 0x200))) {
      *(float *)(_DAT_00015960 + 0x200) = ___real_bf800000;
      _GL_Bind(_DAT_0001546c);
      (*__qglColor3f)(0,0x3f800000,0x3f800000);
      (*__qglBegin)(1);
      iVar12 = 0;
      piVar17 = (int *)(*(int *)(unaff_EDI + 0x50) + unaff_EDI);
      if (0 < *(int *)(unaff_EDI + 0x4c)) {
        pfVar15 = (float *)(iVar7 + 0x20);
        do {
          (*__qglColor3f)(0x3f800000,0,0);
          (*__qglVertex3f)(pfVar15[-4],pfVar15[-3],pfVar15[-2]);
          fVar4 = (float)___real_4010000000000000;
          (*__qglVertex3f)(fVar4 * pfVar15[-1] + pfVar15[-4],*pfVar15 * fVar4 + pfVar15[-3],
                           pfVar15[-2] + pfVar15[1] * fVar4);
          (*__qglColor3f)(0,0x3f800000,0);
          (*__qglVertex3f)(pfVar15[-4],pfVar15[-3],pfVar15[-2]);
          fVar4 = (float)___real_4010000000000000;
          (*__qglVertex3f)(fVar4 * pfVar15[2] + pfVar15[-4],pfVar15[3] * fVar4 + pfVar15[-3],
                           pfVar15[-2] + pfVar15[4] * fVar4);
          (*__qglColor3f)(0,0,0x3f800000);
          (*__qglVertex3f)(pfVar15[-4],pfVar15[-3],pfVar15[-2]);
          fVar4 = (float)___real_4010000000000000;
          (*__qglVertex3f)(fVar4 * pfVar15[5] + pfVar15[-4],pfVar15[6] * fVar4 + pfVar15[-3],
                           pfVar15[-2] + pfVar15[7] * fVar4);
          if (*piVar17 != -1) {
            (*__qglColor3f)(0,0x3f800000,0x3f800000);
            iVar9 = *piVar17 * 0x40 + unaff_ESI;
            (*__qglVertex3f)(*(undefined4 *)(iVar9 + 0x10),*(undefined4 *)(iVar9 + 0x14),
                             *(undefined4 *)(iVar9 + 0x18));
            (*__qglVertex3f)(pfVar15[-4],pfVar15[-3],pfVar15[-2]);
          }
          iVar12 = iVar12 + 1;
          pfVar15 = pfVar15 + 0x10;
          piVar17 = piVar17 + 0x12;
        } while (iVar12 < *(int *)(unaff_EDI + 0x4c));
      }
                    /* WARNING: Could not recover jumptable at 0x00012812. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*__qglEnd)();
      return;
    }
  }
  return;
}



// ===========================================
// Function: myftol @ 00012825
// ===========================================

/* myftol */

int __cdecl myftol(float param_1)

{
  `myftol'::__l2::tmp = (int)ROUND(param_1);
  return `myftol'::__l2::tmp;
}



// ===========================================
// Function: _RB_CalcSpecularAlpha @ 00012835
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcSpecularAlpha(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  float *pfVar7;
  byte local_2c [8];
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar6 = 0;
  local_2c[0] = 0xff;
  local_2c[1] = 0xff;
  local_2c[2] = 0xff;
  local_2c[3] = 0xff;
  local_2c[4] = 0;
  local_2c[5] = 0;
  local_2c[6] = 0;
  local_2c[7] = 0;
  iVar3 = __ftol2_sse();
  pcVar5 = (char *)(param_1 + 3);
  if (0 < _DAT_0032c47c) {
    pfVar7 = (float *)&DAT_0013a3b0;
    do {
      fStack_18 = *param_3 - pfVar7[-0x1d4c2];
      fStack_14 = param_3[1] - pfVar7[-0x1d4c1];
      fStack_10 = param_3[2] - pfVar7[-120000];
      _VectorNormalizeFast(&fStack_18);
      fVar1 = fStack_18 * pfVar7[-2] + fStack_14 * pfVar7[-1] + fStack_10 * *pfVar7;
      fVar2 = (float)___real_4000000000000000;
      fStack_c = fVar1 * pfVar7[-2] * fVar2 - fStack_18;
      fStack_8 = pfVar7[-1] * fVar2 * fVar1 - fStack_14;
      fStack_4 = fVar2 * *pfVar7 * fVar1 - fStack_10;
      fStack_24 = _DAT_00015e2c - pfVar7[-0x1d4c2];
      fStack_20 = _DAT_00015e30 - pfVar7[-0x1d4c1];
      fStack_1c = _DAT_00015e34 - pfVar7[-120000];
      _Q_rsqrt(fStack_1c * fStack_1c + fStack_24 * fStack_24 + fStack_20 * fStack_20);
      iVar4 = __ftol2_sse();
      iVar6 = iVar6 + 1;
      *pcVar5 = (char)iVar4 - (local_2c[(iVar4 - iVar3 >> 0x1f) * -4] & (byte)(iVar4 - iVar3));
      pfVar7 = pfVar7 + 4;
      pcVar5 = pcVar5 + 4;
    } while (iVar6 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcDiffuseColor @ 000129ea
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcDiffuseColor(int param_1)

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
  undefined4 uVar10;
  float fVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined1 *puVar18;
  float local_40;
  int local_38;
  undefined1 local_34;
  float local_30;
  float local_2c;
  float local_28;
  
  iVar17 = _DAT_00015960;
  fVar1 = *(float *)(_DAT_00015960 + 0x1e4);
  fVar2 = *(float *)(_DAT_00015960 + 0x1e8);
  uVar10 = *(undefined4 *)(_DAT_00015960 + 0x1f0);
  fVar3 = *(float *)(_DAT_00015960 + 0x1ec);
  pfVar14 = (float *)&DAT_0013a3a8;
  fVar4 = *(float *)(_DAT_00015960 + 500);
  fVar5 = *(float *)(_DAT_00015960 + 0x1f8);
  fVar6 = *(float *)(_DAT_00015960 + 0x1fc);
  fVar7 = *(float *)(_DAT_00015960 + 0x1d8);
  fVar8 = *(float *)(_DAT_00015960 + 0x1dc);
  fVar9 = *(float *)(_DAT_00015960 + 0x1e0);
  if (*(int *)(_DAT_00015960 + 0x2c8) == 0) {
    if (0 < _DAT_0032c47c) {
      pfVar14 = (float *)&DAT_0013a3b0;
      puVar18 = (undefined1 *)(param_1 + 2);
      iVar17 = _DAT_0032c47c;
      do {
        fVar11 = *pfVar14 * fVar9 + pfVar14[-2] * fVar7 + pfVar14[-1] * fVar8;
        if (fVar11 < 0.0 == (fVar11 == 0.0)) {
          `myftol'::__l2::tmp = (int)ROUND(fVar11 * fVar4 + fVar1);
          local_40 = (float)`myftol'::__l2::tmp;
          if ((float)___real_406fe00000000000 < local_40) {
            local_40 = ___real_437f0000;
          }
          local_34 = (undefined1)(int)ROUND(local_40);
          puVar18[-2] = local_34;
          `myftol'::__l2::tmp = (int)ROUND(fVar11 * fVar5 + fVar2);
          local_40 = (float)`myftol'::__l2::tmp;
          if ((float)___real_406fe00000000000 < local_40) {
            local_40 = ___real_437f0000;
          }
          local_34 = (undefined1)(int)ROUND(local_40);
          puVar18[-1] = local_34;
          `myftol'::__l2::tmp = (int)ROUND(fVar11 * fVar6 + fVar3);
          local_40 = (float)`myftol'::__l2::tmp;
          if ((float)___real_406fe00000000000 < local_40) {
            local_40 = ___real_437f0000;
          }
          puVar18[1] = 0xff;
          local_34 = (undefined1)(int)ROUND(local_40);
          *puVar18 = local_34;
        }
        else {
          *(undefined4 *)(puVar18 + -2) = uVar10;
        }
        puVar18 = puVar18 + 4;
        pfVar14 = pfVar14 + 4;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
  }
  else if (0 < _DAT_0032c47c) {
    puVar18 = (undefined1 *)(param_1 + 2);
    local_38 = _DAT_0032c47c;
    do {
      iVar15 = *(int *)(iVar17 + 0x2c8);
      iVar12 = 0;
      local_28 = 0.0;
      local_2c = 0.0;
      local_30 = 0.0;
      if (3 < iVar15) {
        iVar16 = (iVar15 - 4U >> 2) + 1;
        iVar12 = iVar16 * 4;
        pfVar13 = (float *)(iVar17 + 0x20c);
        do {
          fVar4 = pfVar13[1] * pfVar14[2] + *pfVar14 * pfVar13[-1] + pfVar14[1] * *pfVar13;
          if (fVar4 < 0.0 == (fVar4 == 0.0)) {
            local_40 = fVar4 * pfVar13[0x17] + fVar1;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_30 = local_40 + local_30;
            local_40 = fVar4 * pfVar13[0x18] + fVar2;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_2c = local_40 + local_2c;
            local_40 = fVar4 * pfVar13[0x19] + fVar3;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_28 = local_40 + local_28;
          }
          fVar4 = pfVar13[4] * pfVar14[2] + *pfVar14 * pfVar13[2] + pfVar14[1] * pfVar13[3];
          if (fVar4 < 0.0 == (fVar4 == 0.0)) {
            local_40 = fVar4 * pfVar13[0x1a] + fVar1;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_30 = local_40 + local_30;
            local_40 = fVar4 * pfVar13[0x1b] + fVar2;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_2c = local_40 + local_2c;
            local_40 = fVar4 * pfVar13[0x1c] + fVar3;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_28 = local_40 + local_28;
          }
          fVar4 = pfVar13[7] * pfVar14[2] + *pfVar14 * pfVar13[5] + pfVar14[1] * pfVar13[6];
          if (fVar4 < 0.0 == (fVar4 == 0.0)) {
            local_40 = fVar4 * pfVar13[0x1d] + fVar1;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_30 = local_40 + local_30;
            local_40 = fVar4 * pfVar13[0x1e] + fVar2;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_2c = local_40 + local_2c;
            local_40 = fVar4 * pfVar13[0x1f] + fVar3;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_28 = local_40 + local_28;
          }
          fVar4 = pfVar13[10] * pfVar14[2] + *pfVar14 * pfVar13[8] + pfVar14[1] * pfVar13[9];
          if (fVar4 < 0.0 == (fVar4 == 0.0)) {
            local_40 = fVar4 * pfVar13[0x20] + fVar1;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_30 = local_40 + local_30;
            local_40 = fVar4 * pfVar13[0x21] + fVar2;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_2c = local_40 + local_2c;
            local_40 = fVar4 * pfVar13[0x22] + fVar3;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_28 = local_40 + local_28;
          }
          pfVar13 = pfVar13 + 0xc;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
      if (iVar12 < iVar15) {
        pfVar13 = (float *)(iVar17 + 0x20c + iVar12 * 0xc);
        iVar15 = iVar15 - iVar12;
        do {
          fVar4 = pfVar13[1] * pfVar14[2] + *pfVar14 * pfVar13[-1] + pfVar14[1] * *pfVar13;
          if (fVar4 < 0.0 == (fVar4 == 0.0)) {
            local_40 = fVar4 * pfVar13[0x17] + fVar1;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_30 = local_40 + local_30;
            local_40 = fVar4 * pfVar13[0x18] + fVar2;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_2c = local_40 + local_2c;
            local_40 = fVar4 * pfVar13[0x19] + fVar3;
            if (___real_406fe00000000000 < (double)local_40) {
              local_40 = ___real_437f0000;
            }
            local_28 = local_40 + local_28;
          }
          pfVar13 = pfVar13 + 3;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      if (___real_406fe00000000000 < (double)local_30) {
        local_30 = ___real_437f0000;
      }
      if (___real_406fe00000000000 < (double)local_2c) {
        local_2c = ___real_437f0000;
      }
      if (___real_406fe00000000000 < (double)local_28) {
        local_28 = ___real_437f0000;
      }
      `myftol'::__l2::tmp = (int)ROUND(local_30);
      puVar18[-2] = (char)`myftol'::__l2::tmp;
      `myftol'::__l2::tmp = (int)ROUND(local_2c);
      puVar18[-1] = (char)`myftol'::__l2::tmp;
      `myftol'::__l2::tmp = (int)ROUND(local_28);
      *puVar18 = (char)`myftol'::__l2::tmp;
      puVar18[1] = 0xff;
      puVar18 = puVar18 + 4;
      pfVar14 = pfVar14 + 4;
      local_38 = local_38 + -1;
    } while (local_38 != 0);
    return;
  }
  return;
}



// ===========================================
// Function: _EvalWaveForm @ 000131c6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _EvalWaveForm(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int unaff_ESI;
  
  iVar5 = _TableForFunc();
  fVar4 = (float)___real_3fb0000000000000;
  if ((NAN(___real_4996b438) || NAN(*(float *)(unaff_ESI + 4))) ==
      (___real_4996b438 == *(float *)(unaff_ESI + 4))) {
    fVar1 = *(float *)(unaff_ESI + 4);
  }
  else {
    fVar1 = (float)*(byte *)(_DAT_00015960 + 0xd0) * fVar4 - (float)___real_4020000000000000;
  }
  if ((NAN(___real_4996b438) || NAN(*(float *)(unaff_ESI + 8))) ==
      (___real_4996b438 == *(float *)(unaff_ESI + 8))) {
    fVar2 = *(float *)(unaff_ESI + 8);
  }
  else {
    fVar2 = (float)*(byte *)(_DAT_00015960 + 0xd1) * fVar4;
  }
  if ((NAN(___real_4996b438) || NAN(*(float *)(unaff_ESI + 0xc))) ==
      (___real_4996b438 == *(float *)(unaff_ESI + 0xc))) {
    fVar3 = *(float *)(unaff_ESI + 0xc);
  }
  else {
    fVar3 = (float)*(byte *)(_DAT_00015960 + 0xd2) * fVar4 - (float)___real_4020000000000000;
  }
  if ((NAN(___real_4996b438) || NAN(*(float *)(unaff_ESI + 0x10))) ==
      (___real_4996b438 == *(float *)(unaff_ESI + 0x10))) {
    fVar4 = *(float *)(unaff_ESI + 0x10);
  }
  else {
    fVar4 = fVar4 * (float)*(byte *)(_DAT_00015960 + 0xd3);
  }
  `myftol'::__l2::tmp = (uint)ROUND((__memmove * fVar4 + fVar3) * (float)___real_4090000000000000);
  return (float10)(*(float *)(iVar5 + (`myftol'::__l2::tmp & 0x3ff) * 4) * fVar2 + fVar1);
}



// ===========================================
// Function: _RB_CalcStretchTexCoords @ 000132f1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcStretchTexCoords(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  undefined1 local_4c [24];
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  fVar1 = (float10)_EvalWaveForm();
  local_34 = (float)((float10)1 / fVar1);
  local_2c = 0;
  local_24 = (float)___real_3fe0000000000000 - local_34 * (float)___real_3fe0000000000000;
  local_30 = 0;
  local_28 = local_34;
  local_20 = local_24;
  _RB_CalcTransformTexCoords(local_4c,param_2);
  return;
}



// ===========================================
// Function: _RB_CalcDeformVertexes @ 0001334f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcDeformVertexes(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  
  fVar4 = (float)___real_3fb0000000000000;
  if ((NAN(___real_4996b438) || NAN(*(float *)(param_1 + 0x14))) ==
      (___real_4996b438 == *(float *)(param_1 + 0x14))) {
    fVar1 = *(float *)(param_1 + 0x14);
  }
  else {
    fVar1 = (float)*(byte *)(_DAT_00015960 + 0xd0) * fVar4 - (float)___real_4020000000000000;
  }
  if ((NAN(___real_4996b438) || NAN(*(float *)(param_1 + 0x18))) ==
      (___real_4996b438 == *(float *)(param_1 + 0x18))) {
    fVar2 = *(float *)(param_1 + 0x18);
  }
  else {
    fVar2 = (float)*(byte *)(_DAT_00015960 + 0xd1) * fVar4;
  }
  if ((NAN(___real_4996b438) || NAN(*(float *)(param_1 + 0x1c))) ==
      (___real_4996b438 == *(float *)(param_1 + 0x1c))) {
    fVar3 = *(float *)(param_1 + 0x1c);
  }
  else {
    fVar3 = (float)*(byte *)(_DAT_00015960 + 0xd2) * fVar4 - (float)___real_4020000000000000;
  }
  if ((NAN(___real_4996b438) || NAN(*(float *)(param_1 + 0x20))) ==
      (___real_4996b438 == *(float *)(param_1 + 0x20))) {
    fVar4 = *(float *)(param_1 + 0x20);
  }
  else {
    fVar4 = fVar4 * (float)*(byte *)(_DAT_00015960 + 0xd3);
  }
  if (NAN(fVar4) == (fVar4 == 0.0)) {
    iVar7 = _TableForFunc();
    iVar8 = 0;
    if (0 < _DAT_0032c47c) {
      pfVar6 = (float *)&DAT_000c50ac;
      do {
        `myftol'::__l2::tmp =
             (uint)ROUND((__memmove * fVar4 +
                         (*pfVar6 + pfVar6[-1] + pfVar6[1]) * *(float *)(param_1 + 0x24) + fVar3) *
                         (float)___real_4090000000000000);
        iVar8 = iVar8 + 1;
        fVar5 = *(float *)(iVar7 + (`myftol'::__l2::tmp & 0x3ff) * 4) * fVar2 + fVar1;
        pfVar6[-1] = fVar5 * pfVar6[119999] + pfVar6[-1];
        *pfVar6 = *pfVar6 + pfVar6[120000] * fVar5;
        pfVar6[1] = pfVar6[1] + fVar5 * pfVar6[0x1d4c1];
        pfVar6 = pfVar6 + 4;
      } while (iVar8 < _DAT_0032c47c);
    }
  }
  else {
    fVar9 = (float10)_EvalWaveForm();
    fVar4 = (float)fVar9;
    iVar7 = 0;
    if (0 < _DAT_0032c47c) {
      pfVar6 = (float *)&DAT_0013a3b0;
      do {
        iVar7 = iVar7 + 1;
        pfVar6[-0x1d4c2] = pfVar6[-0x1d4c2] + pfVar6[-2] * fVar4;
        pfVar6[-0x1d4c1] = pfVar6[-1] * fVar4 + pfVar6[-0x1d4c1];
        pfVar6[-120000] = pfVar6[-120000] + fVar4 * *pfVar6;
        pfVar6 = pfVar6 + 4;
      } while (iVar7 < _DAT_0032c47c);
      return;
    }
  }
  return;
}



// ===========================================
// Function: _RB_CalcDeformWaveNormals @ 0001356d
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcDeformWaveNormals(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  int local_1c;
  
  iVar7 = _TableForFunc();
  fVar2 = *(float *)(param_1 + 0x14);
  fVar3 = *(float *)(param_1 + 0x18);
  local_1c = 0;
  fVar4 = *(float *)(param_1 + 0x1c);
  fVar5 = *(float *)(param_1 + 0x20);
  if (0 < _DAT_0032c47c) {
    pfVar8 = (float *)&DAT_000c50b0;
    do {
      fVar6 = (pfVar8[-2] + pfVar8[-1] + *pfVar8) * *(float *)(param_1 + 0x24) + fVar4;
      `myftol'::__l2::tmp =
           (uint)ROUND((__memmove * fVar5 + fVar6) * (float)___real_4090000000000000);
      pfVar1 = pfVar8 + 0x1d4be;
      *pfVar1 = (*(float *)(iVar7 + (`myftol'::__l2::tmp & 0x3ff) * 4) * fVar3 + fVar2) *
                *(float *)(param_1 + 4) + *pfVar1;
      `myftol'::__l2::tmp =
           (uint)ROUND((__memmove * fVar5 + fVar6) * (float)___real_4090000000000000);
      pfVar8[119999] =
           (*(float *)(iVar7 + (`myftol'::__l2::tmp & 0x3ff) * 4) * fVar3 + fVar2) *
           *(float *)(param_1 + 8) + pfVar8[119999];
      `myftol'::__l2::tmp =
           (uint)ROUND((__memmove * fVar5 + fVar6) * (float)___real_4090000000000000);
      pfVar8[120000] =
           (*(float *)(iVar7 + (`myftol'::__l2::tmp & 0x3ff) * 4) * fVar3 + fVar2) *
           *(float *)(param_1 + 0xc) + pfVar8[120000];
      _VectorNormalizeFast(pfVar1);
      local_1c = local_1c + 1;
      pfVar8 = pfVar8 + 4;
    } while (local_1c < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcMoveVertexes @ 000136e5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcMoveVertexes(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  
  fVar7 = (float10)_EvalWaveForm();
  fVar1 = (float)fVar7;
  fVar2 = *(float *)(param_1 + 4);
  iVar6 = 0;
  fVar3 = *(float *)(param_1 + 8);
  fVar4 = *(float *)(param_1 + 0xc);
  if (0 < _DAT_0032c47c) {
    pfVar5 = (float *)&DAT_000c50b0;
    do {
      iVar6 = iVar6 + 1;
      pfVar5[-2] = pfVar5[-2] + fVar1 * fVar2;
      pfVar5[-1] = fVar3 * fVar1 + pfVar5[-1];
      *pfVar5 = fVar1 * fVar4 + *pfVar5;
      pfVar5 = pfVar5 + 4;
    } while (iVar6 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_DeformTessGeometry @ 00013765
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_DeformTessGeometry(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(_DAT_0032c468 + 0xf0)) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(iVar3 + 0xf4 + _DAT_0032c468);
      iVar1 = iVar3 + 0xf4 + _DAT_0032c468;
      switch(iVar2) {
      case 1:
        _RB_CalcDeformVertexes(iVar1);
        break;
      case 2:
        _RB_CalcDeformNormals(iVar1);
        break;
      case 3:
        _RB_CalcBulgeVertexes(iVar1);
        break;
      case 4:
        _RB_CalcMoveVertexes(iVar1);
        break;
      case 5:
        _RB_ProjectionShadowDeform();
        break;
      case 6:
        _AutospriteDeform();
        break;
      case 7:
        _Autosprite2Deform();
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
        _DeformText(&DAT_000154c4 + (iVar2 + -8) * 0x20);
        break;
      case 0x10:
        _RB_CalcDeformWaveNormals(iVar1);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x34;
    } while (iVar4 < *(int *)(_DAT_0032c468 + 0xf0));
  }
  return;
}



// ===========================================
// Function: _RB_CalcWaveColor @ 00013849
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcWaveColor(int *param_1,undefined4 *param_2,byte *param_3)

{
  byte *pbVar1;
  float fVar2;
  byte bVar3;
  float fVar4;
  undefined2 uVar5;
  int iVar6;
  float10 fVar7;
  
  if (*param_1 == 8) {
    fVar7 = (float10)_R_NoiseGet4f(0,0,0,((float)param_1[3] + __memmove) * (float)param_1[4]);
    fVar7 = fVar7 * (float10)(float)param_1[2] + (float10)(float)param_1[1];
  }
  else {
    fVar7 = (float10)_EvalWaveForm();
    fVar7 = fVar7 * (float10)_DAT_00015dec;
  }
  fVar2 = (float)fVar7;
  fVar4 = 0.0;
  if ((fVar2 < 0.0 == NAN(fVar2)) && (fVar4 = fVar2, 1.0 < fVar2 != NAN(fVar2))) {
    fVar4 = 1.0;
  }
  if (param_3 == (byte *)0x0) {
    `myftol'::__l2::tmp = (int)ROUND(fVar4 * (float)___real_406fe00000000000);
    param_1 = (int *)(CONCAT31(CONCAT21((short)`myftol'::__l2::tmp,(char)`myftol'::__l2::tmp),
                               (char)`myftol'::__l2::tmp) & 0xffffff);
  }
  else {
    bVar3 = *param_3;
    pbVar1 = param_3 + 2;
    param_3._0_1_ = (undefined1)(int)ROUND((float)param_3[1] * fVar4);
    uVar5 = CONCAT11(param_3._0_1_,(char)(int)ROUND((float)bVar3 * fVar4));
    param_3._0_1_ = (undefined1)(int)ROUND((float)*pbVar1 * fVar4);
    param_1 = (int *)(uint)CONCAT12(param_3._0_1_,uVar5);
  }
  iVar6 = 0;
  param_1 = (int *)CONCAT13(0xff,param_1._0_3_);
  if (0 < _DAT_0032c47c) {
    do {
      *param_2 = param_1;
      iVar6 = iVar6 + 1;
      param_2 = param_2 + 1;
    } while (iVar6 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcWaveAlpha @ 000139cb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcWaveAlpha(int *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (*param_1 == 8) {
    _R_NoiseGet4f(0,0,0,((float)param_1[3] + __memmove) * (float)param_1[4]);
  }
  else {
    _EvalWaveForm();
  }
  uVar1 = __ftol2_sse();
  iVar2 = 0;
  if (0 < _DAT_0032c47c) {
    puVar3 = (undefined1 *)(param_2 + 3);
    do {
      *puVar3 = uVar1;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar2 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcAlphaFogDensities @ 00013aac
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcAlphaFogDensities(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float10 fVar6;
  uint local_24 [2];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_24[0] = 0xffffffff;
  local_24[1] = 0;
  if (_DAT_0032c46c == &DAT_0000270f) {
    _RB_CalcAlphaFogFarPlaneDensities();
    return;
  }
  iVar5 = (int)_DAT_0032c46c * 0x5c + *(int *)(___fltused + 0xb8);
  if (*(int *)(iVar5 + 0x34) != 0) {
    fVar6 = (float10)_EvalWaveForm();
    fVar1 = (float)(fVar6 - (float10)1);
    *(float *)(iVar5 + 0x20) =
         (float)___real_4020000000000000 /
         (float)((float10)1 + (float10)(float)((uint)fVar1 & local_24[-((int)fVar1 >> 0x1f)]));
  }
  local_10 = *(float *)(iVar5 + 0x20) *
             (*(float *)(iVar5 + 0x50) * _DAT_000158c4 +
             *(float *)(iVar5 + 0x4c) * _DAT_000158c0 + *(float *)(iVar5 + 0x48) * _DAT_000158bc);
  local_c = *(float *)(iVar5 + 0x20) *
            (*(float *)(iVar5 + 0x50) * _DAT_000158d0 +
            *(float *)(iVar5 + 0x4c) * _DAT_000158cc + *(float *)(iVar5 + 0x48) * _DAT_000158c8);
  local_8 = *(float *)(iVar5 + 0x20) *
            (*(float *)(iVar5 + 0x50) * _DAT_000158dc +
            *(float *)(iVar5 + 0x4c) * _DAT_000158d8 + *(float *)(iVar5 + 0x48) * _DAT_000158d4);
  local_4 = *(float *)(iVar5 + 0x20) *
            (*(float *)(iVar5 + 0x54) -
            (*(float *)(iVar5 + 0x50) * _DAT_000158b8 +
            *(float *)(iVar5 + 0x4c) * _DAT_000158b4 + *(float *)(iVar5 + 0x48) * _DAT_000158b0));
  fVar1 = (_DAT_000158e8 * local_8 + _DAT_000158e0 * local_10 + _DAT_000158e4 * local_c) - local_4;
  iVar5 = 0;
  if (0.0 <= fVar1) {
    if (0 < _DAT_0032c47c) {
      pfVar4 = (float *)&DAT_000c50b0;
      do {
        fVar2 = (*pfVar4 * local_8 + local_10 * pfVar4[-2] + local_c * pfVar4[-1]) - local_4;
        if (0.0 <= fVar2) {
          local_1c = _DAT_000158e0 - pfVar4[-2];
          local_18 = _DAT_000158e4 - pfVar4[-1];
          local_14 = _DAT_000158e8 - *pfVar4;
          fVar3 = local_14 * local_14 + local_1c * local_1c + local_18 * local_18;
          fVar6 = (float10)_Q_rsqrt(fVar3);
          fVar2 = (fVar2 + fVar1) *
                  (float)(fVar6 * (float10)fVar3) * (float)___real_3fe0000000000000;
          fVar3 = fVar2 - (float)___real_3ff0000000000000;
          *(float *)(&DAT_0030efa8 + iVar5 * 4) =
               fVar2 - (float)((uint)fVar3 & local_24[-((int)fVar3 >> 0x1f)]);
        }
        else {
          *(undefined4 *)(&DAT_0030efa8 + iVar5 * 4) = 0;
        }
        iVar5 = iVar5 + 1;
        pfVar4 = pfVar4 + 4;
      } while (iVar5 < _DAT_0032c47c);
    }
  }
  else if (0 < _DAT_0032c47c) {
    pfVar4 = (float *)&DAT_000c50b0;
    do {
      fVar2 = (*pfVar4 * local_8 + pfVar4[-2] * local_10 + pfVar4[-1] * local_c) - local_4;
      if (0.0 <= fVar2) {
        local_1c = _DAT_000158e0 - pfVar4[-2];
        local_18 = _DAT_000158e4 - pfVar4[-1];
        local_14 = _DAT_000158e8 - *pfVar4;
        fVar3 = local_14 * local_14 + local_1c * local_1c + local_18 * local_18;
        fVar6 = (float10)_Q_rsqrt(fVar3);
        fVar2 = (((float)___real_3fe0000000000000 * fVar2 + (float)___real_0000000000000000) *
                fVar2 * (float)(fVar6 * (float10)fVar3)) / (fVar2 - fVar1);
        fVar3 = fVar2 - (float)___real_3ff0000000000000;
        *(float *)(&DAT_0030efa8 + iVar5 * 4) =
             fVar2 - (float)((uint)fVar3 & local_24[-((int)fVar3 >> 0x1f)]);
      }
      else {
        *(undefined4 *)(&DAT_0030efa8 + iVar5 * 4) = 0;
      }
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 4;
    } while (iVar5 < _DAT_0032c47c);
    return;
  }
  return;
}



// ===========================================
// Function: _RB_CalcFogTexCoords @ 00013e45
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcFogTexCoords(float *param_1)

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
  float fVar14;
  float fVar15;
  bool bVar16;
  float fVar17;
  float *pfVar18;
  int iVar19;
  float10 fVar20;
  float local_2c;
  float local_28;
  float local_14;
  
  iVar19 = _DAT_0032c46c * 0x5c + *(int *)(___fltused + 0xb8);
  if (*(int *)(iVar19 + 0x34) != 0) {
    fVar20 = (float10)_EvalWaveForm();
    local_2c = (float)fVar20;
    if (local_2c < 1.0) {
      local_2c = 1.0;
    }
    *(float *)(iVar19 + 0x20) = (float)___real_4020000000000000 / local_2c;
  }
  fVar5 = _DAT_000158b0 - _DAT_00015630;
  fVar7 = _DAT_000158b4 - _DAT_00015634;
  fVar6 = _DAT_000158b8 - _DAT_00015638;
  fVar8 = -_DAT_000158f4;
  fVar9 = -_DAT_00015904;
  fVar10 = -_DAT_00015914;
  fVar11 = _DAT_00015640 * fVar7;
  fVar13 = _DAT_0001563c * fVar5;
  fVar12 = _DAT_00015644 * fVar6;
  fVar1 = *(float *)(iVar19 + 0x20);
  fVar2 = *(float *)(iVar19 + 0x20);
  fVar3 = *(float *)(iVar19 + 0x20);
  fVar4 = *(float *)(iVar19 + 0x20);
  if (*(int *)(iVar19 + 0x58) == 0) {
    local_28 = 1.0;
  }
  else {
    fVar5 = *(float *)(iVar19 + 0x50) * _DAT_000158c4 +
            *(float *)(iVar19 + 0x4c) * _DAT_000158c0 + *(float *)(iVar19 + 0x48) * _DAT_000158bc;
    fVar7 = *(float *)(iVar19 + 0x50) * _DAT_000158d0 +
            *(float *)(iVar19 + 0x4c) * _DAT_000158cc + *(float *)(iVar19 + 0x48) * _DAT_000158c8;
    fVar6 = *(float *)(iVar19 + 0x50) * _DAT_000158dc +
            *(float *)(iVar19 + 0x4c) * _DAT_000158d8 + *(float *)(iVar19 + 0x48) * _DAT_000158d4;
    local_14 = (_DAT_000158b4 * *(float *)(iVar19 + 0x4c) +
                *(float *)(iVar19 + 0x48) * _DAT_000158b0 +
               *(float *)(iVar19 + 0x50) * _DAT_000158b8) - *(float *)(iVar19 + 0x54);
    local_28 = local_14 + fVar7 * _DAT_000158e4 + fVar5 * _DAT_000158e0 + fVar6 * _DAT_000158e8;
    if (local_28 < 0.0) {
      bVar16 = true;
      goto LAB_00014043;
    }
  }
  bVar16 = false;
LAB_00014043:
  iVar19 = 0;
  fVar15 = (float)___real_3f60000000000000;
  if (_DAT_0032c47c < 1) {
    return;
  }
  pfVar18 = (float *)&DAT_000c50b0;
  do {
    fVar14 = *pfVar18 * fVar6 + pfVar18[-2] * fVar5 + pfVar18[-1] * fVar7 + local_14;
    if (bVar16) {
      fVar17 = ___real_3d000000;
      if (fVar14 < 1.0 == NAN(fVar14)) {
        fVar17 = ((float)___real_3fee000000000000 * fVar14) / (fVar14 - local_28) +
                 (float)___real_3fa0000000000000;
      }
    }
    else {
      fVar17 = ___real_3f780000;
      if (fVar14 < 0.0) {
        fVar17 = ___real_3d000000;
      }
    }
    iVar19 = iVar19 + 1;
    *param_1 = *pfVar18 * fVar3 * fVar10 + pfVar18[-2] * fVar1 * fVar8 + pfVar18[-1] * fVar2 * fVar9
               + fVar4 * (fVar12 + fVar13 + fVar11) + fVar15;
    pfVar18 = pfVar18 + 4;
    param_1[1] = fVar17;
    param_1 = param_1 + 2;
  } while (iVar19 < _DAT_0032c47c);
  return;
}



// ===========================================
// Function: _RB_CalcModulateColorsByFog @ 00014137
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcModulateColorsByFog(byte *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  byte local_4;
  
  _RB_CalcFogTexCoords(&_fogTexCoords);
  iVar4 = 0;
  if (0 < _DAT_0032c47c) {
    fVar3 = (float)___real_3fd0000000000000;
    fVar2 = (float)___real_4070000000000000;
    do {
      fVar1 = 1.0 - (*(float *)(&DAT_0001541c + iVar4 * 8) - fVar3) *
                    *(float *)(&_fogTexCoords + iVar4 * 8) * fVar2;
      if (fVar1 < 0.0 != NAN(fVar1)) {
        fVar1 = 0.0;
      }
      iVar4 = iVar4 + 1;
      local_4 = (byte)(int)ROUND((float)*param_1 * fVar1);
      *param_1 = local_4;
      local_4 = (byte)(int)ROUND((float)param_1[1] * fVar1);
      param_1[1] = local_4;
      local_4 = (byte)(int)ROUND(fVar1 * (float)param_1[2]);
      param_1[2] = local_4;
      param_1 = param_1 + 4;
    } while (iVar4 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcModulateAlphasByFog @ 0001423e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcModulateAlphasByFog(int param_1)

{
  float fVar1;
  float fVar2;
  byte *pbVar3;
  int iVar4;
  float local_8;
  byte local_4;
  
  _RB_CalcFogTexCoords(&_fogTexCoords);
  iVar4 = 0;
  if (0 < _DAT_0032c47c) {
    fVar2 = (float)___real_3fd0000000000000;
    fVar1 = (float)___real_4070000000000000;
    pbVar3 = (byte *)(param_1 + 3);
    do {
      local_8 = 1.0 - (*(float *)(&DAT_0001541c + iVar4 * 8) - fVar2) *
                      *(float *)(&_fogTexCoords + iVar4 * 8) * fVar1;
      if (local_8 < 0.0) {
        local_8 = 0.0;
      }
      iVar4 = iVar4 + 1;
      local_4 = (byte)(int)ROUND((float)*pbVar3 * local_8);
      *pbVar3 = local_4;
      pbVar3 = pbVar3 + 4;
    } while (iVar4 < _DAT_0032c47c);
  }
  return;
}



// ===========================================
// Function: _RB_CalcModulateRGBAsByFog @ 000142db
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CalcModulateRGBAsByFog(byte *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  byte local_4;
  
  _RB_CalcFogTexCoords(&_fogTexCoords);
  iVar4 = 0;
  if (0 < _DAT_0032c47c) {
    fVar3 = (float)___real_3fd0000000000000;
    fVar2 = (float)___real_4070000000000000;
    do {
      fVar1 = 1.0 - (*(float *)(&DAT_0001541c + iVar4 * 8) - fVar3) *
                    *(float *)(&_fogTexCoords + iVar4 * 8) * fVar2;
      if (fVar1 < 0.0 != NAN(fVar1)) {
        fVar1 = 0.0;
      }
      iVar4 = iVar4 + 1;
      local_4 = (byte)(int)ROUND((float)*param_1 * fVar1);
      *param_1 = local_4;
      local_4 = (byte)(int)ROUND((float)param_1[1] * fVar1);
      param_1[1] = local_4;
      local_4 = (byte)(int)ROUND((float)param_1[2] * fVar1);
      param_1[2] = local_4;
      local_4 = (byte)(int)ROUND(fVar1 * (float)param_1[3]);
      param_1[3] = local_4;
      param_1 = param_1 + 4;
    } while (iVar4 < _DAT_0032c47c);
  }
  return;
}



