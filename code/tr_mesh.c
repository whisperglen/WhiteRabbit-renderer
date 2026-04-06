// ===========================================
// Function: _ProjectRadius @ 00012600
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _ProjectRadius(float param_1)

{
  float10 fVar1;
  float fVar2;
  float *in_EAX;
  float10 fVar3;
  
  fVar1 = (float10)0;
  fVar3 = (float10)((_DAT_000183bc * in_EAX[1] + _DAT_000183b8 * *in_EAX + _DAT_000183c0 * in_EAX[2]
                    ) - (_DAT_000183c0 * _DAT_000183b4 +
                        _DAT_000183b0 * _DAT_000183bc + _DAT_000183ac * _DAT_000183b8));
  if (fVar3 < fVar1 != (fVar3 == fVar1)) {
    return fVar1;
  }
  fVar2 = (ABS(param_1) * _DAT_00018500 + _DAT_000184f0 * 0.0 + (float)-fVar3 * _DAT_00018510 +
          _DAT_00018520) /
          ((float)-fVar3 * _DAT_00018518 + _DAT_00018508 * ABS(param_1) + _DAT_000184f8 * 0.0 +
          _DAT_00018528);
  if (1.0 < fVar2 != NAN(fVar2)) {
    return (float10)1.0;
  }
  return (float10)fVar2;
}



// ===========================================
// Function: _R_CullModel @ 00012706
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall _R_CullModel(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar3 = (float *)(*(int *)(param_1 + 0x5c) + *(short *)(in_EAX + 0x5e) * 0x38 + param_1);
  pfVar4 = (float *)(*(int *)(param_1 + 0x5c) + *(short *)(in_EAX + 0x5c) * 0x38 + param_1);
  if (*(int *)(in_EAX + 0x44) == 0) {
    if (*(short *)(in_EAX + 0x5e) == *(short *)(in_EAX + 0x5c)) {
      iVar1 = _R_CullLocalPointAndRadius(pfVar3 + 6,pfVar3[9]);
      if (iVar1 == 0) {
LAB_00012785:
        _DAT_00018988 = _DAT_00018988 + 1;
        return 0;
      }
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          _DAT_00018990 = _DAT_00018990 + 1;
          return 2;
        }
        goto LAB_000127dd;
      }
    }
    else {
      iVar1 = _R_CullLocalPointAndRadius(pfVar3 + 6,pfVar3[9]);
      if (pfVar3 != pfVar4) {
        iVar2 = _R_CullLocalPointAndRadius(pfVar4 + 6,pfVar4[9]);
        if (iVar1 != iVar2) goto LAB_000127dd;
      }
      if (iVar1 == 2) {
        _DAT_00018990 = _DAT_00018990 + 1;
        return 2;
      }
      if (iVar1 == 0) goto LAB_00012785;
    }
    _DAT_0001898c = _DAT_0001898c + 1;
  }
LAB_000127dd:
  if (*pfVar3 <= *pfVar4) {
    fStack_18 = *pfVar3;
  }
  else {
    fStack_18 = *pfVar4;
  }
  if (pfVar3[3] < pfVar4[3] == (NAN(pfVar3[3]) || NAN(pfVar4[3]))) {
    fStack_c = pfVar3[3];
  }
  else {
    fStack_c = pfVar4[3];
  }
  if (pfVar3[1] <= pfVar4[1]) {
    fStack_14 = pfVar3[1];
  }
  else {
    fStack_14 = pfVar4[1];
  }
  if (pfVar3[4] < pfVar4[4] == (NAN(pfVar3[4]) || NAN(pfVar4[4]))) {
    fStack_8 = pfVar3[4];
  }
  else {
    fStack_8 = pfVar4[4];
  }
  if (pfVar3[2] <= pfVar4[2]) {
    fStack_10 = pfVar3[2];
  }
  else {
    fStack_10 = pfVar4[2];
  }
  if (pfVar3[5] < pfVar4[5] == (NAN(pfVar3[5]) || NAN(pfVar4[5]))) {
    fStack_4 = pfVar3[5];
  }
  else {
    fStack_4 = pfVar4[5];
  }
  iVar1 = _R_CullLocalBox(&fStack_18);
  if (iVar1 != 0) {
    if (iVar1 != 1) {
      _DAT_0001899c = _DAT_0001899c + 1;
      return 2;
    }
    _DAT_00018998 = _DAT_00018998 + 1;
    return 1;
  }
  _DAT_00018994 = _DAT_00018994 + 1;
  return 0;
}



// ===========================================
// Function: _R_ComputeLOD @ 000128f4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_ComputeLOD(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  
  if (*(int *)(_DAT_000183a8 + 0x68) < 2) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(_DAT_000183a8 + 0x50) + 0x5c) + *(short *)(param_1 + 0x5e) * 0x38 +
            *(int *)(_DAT_000183a8 + 0x50);
    fVar4 = (float10)_RadiusFromBounds(iVar3,iVar3 + 0xc);
    fVar4 = (float10)_ProjectRadius((float)fVar4);
    fVar1 = (float)fVar4;
    if (NAN(fVar1) == (fVar1 == 0.0)) {
      fVar2 = *(float *)(__r_lodscale + 0x1c);
      if (___real_41a00000 < fVar2 == (NAN(___real_41a00000) || NAN(fVar2))) {
        fVar1 = 1.0 - fVar1 * fVar2;
      }
      else {
        fVar1 = 1.0 - fVar1 * ___real_41a00000;
      }
    }
    else {
      fVar1 = 0.0;
    }
    iVar3 = myftol((float)*(int *)(_DAT_000183a8 + 0x68) * fVar1);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (*(int *)(_DAT_000183a8 + 0x68) <= iVar3) {
      iVar3 = *(int *)(_DAT_000183a8 + 0x68) + -1;
    }
  }
  iVar3 = iVar3 + *(int *)(__r_lodbias + 0x20);
  if (*(int *)(_DAT_000183a8 + 0x68) <= iVar3) {
    iVar3 = *(int *)(_DAT_000183a8 + 0x68) + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  return iVar3;
}



// ===========================================
// Function: _R_ComputeFogNum @ 000129ec
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_ComputeFogNum(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  float local_c [3];
  
  if (((DAT_000187bc & 1) != 0) || (_DAT_000186bc != 0)) {
    return 0;
  }
  param_1 = *(int *)(param_1 + 0x5c) + *(short *)(param_2 + 0x5e) * 0x38 + param_1;
  iVar5 = 1;
  local_c[0] = *(float *)(param_2 + 0x48) + *(float *)(param_1 + 0x18);
  local_c[1] = *(float *)(param_2 + 0x4c) + *(float *)(param_1 + 0x1c);
  local_c[2] = *(float *)(param_2 + 0x50) + *(float *)(param_1 + 0x20);
  if (1 < *(int *)(__r_lodbias + 0xb4)) {
    pfVar4 = (float *)(*(int *)(__r_lodbias + 0xb8) + 0x60);
    do {
      iVar2 = 0;
      pfVar3 = pfVar4;
      do {
        fVar1 = local_c[iVar2] - *(float *)(param_1 + 0x24);
        if (pfVar3[3] < fVar1 != (pfVar3[3] == fVar1)) break;
        if (local_c[iVar2] + *(float *)(param_1 + 0x24) <= *pfVar3) break;
        iVar2 = iVar2 + 1;
        pfVar3 = pfVar3 + 1;
      } while (iVar2 < 3);
      if (iVar2 == 3) {
        return iVar5;
      }
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 0x17;
    } while (iVar5 < *(int *)(__r_lodbias + 0xb4));
  }
  return 0;
}



// ===========================================
// Function: _R_AddMD3Surfaces @ 00012abb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddMD3Surfaces(int param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  bool bVar13;
  int iStack_24;
  int iStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((*(uint *)(param_1 + 4) & 1) == 0) || (bVar3 = true, _DAT_000184b0 != 0)) {
    bVar3 = false;
  }
  if ((*(uint *)(param_1 + 4) & 0x200000) != 0) {
    *(short *)(param_1 + 0x5e) =
         (short)((int)*(short *)(param_1 + 0x5e) % *(int *)(*(int *)(_DAT_000183a8 + 0x50) + 0x4c));
    *(short *)(param_1 + 0x5c) =
         (short)((int)*(short *)(param_1 + 0x5c) % *(int *)(*(int *)(_DAT_000183a8 + 0x50) + 0x4c));
  }
  iVar4 = *(int *)(*(int *)(_DAT_000183a8 + 0x50) + 0x4c);
  if ((iVar4 <= *(short *)(param_1 + 0x5e)) || (iVar4 <= *(short *)(param_1 + 0x5c))) {
    (*__ri)(1,s_R_AddMD3Surfaces__no_such_frame_,(int)*(short *)(param_1 + 0x5c),
            (int)*(short *)(param_1 + 0x5e),_DAT_000183a8);
    *(undefined2 *)(param_1 + 0x5e) = 0;
    *(undefined2 *)(param_1 + 0x5c) = 0;
  }
  iVar4 = _R_ComputeLOD(param_1);
  iVar4 = *(int *)(_DAT_000183a8 + 0x50 + iVar4 * 4);
  iVar5 = _R_CullModel();
  if (iVar5 != 2) {
    if (1 < *(int *)(__r_shadows + 0x20)) {
      if ((*(uint *)(param_1 + 4) & 0x80000) == 0) {
        uStack_c = *(undefined4 *)(param_1 + 0x48);
        uStack_8 = *(undefined4 *)(param_1 + 0x4c);
        uStack_4 = *(undefined4 *)(param_1 + 0x50);
      }
      else {
        uStack_c = *(undefined4 *)(param_1 + 0x10);
        uStack_8 = *(undefined4 *)(param_1 + 0x14);
        uStack_4 = *(undefined4 *)(param_1 + 0x18);
      }
      _R_SetupEntityLighting(0x18770,param_1,&uStack_c);
    }
    iVar5 = _R_ComputeFogNum(iVar4,param_1);
    iVar10 = *(int *)(iVar4 + 100) + iVar4;
    iStack_14 = 0;
    if (0 < *(int *)(iVar4 + 0x54)) {
      do {
        if (*(int *)(param_1 + 0xb8) == 0) {
          iVar6 = *(int *)(param_1 + 0xb4);
          if ((iVar6 < 1) || (_DAT_0005dc04 <= iVar6)) {
            if (*(int *)(iVar10 + 0x4c) < 1) {
              iStack_24 = _DAT_00017cb4;
            }
            else {
              iStack_24 = *(int *)(*(int *)(*(int *)(iVar10 + 0x5c) +
                                            (*(int *)(param_1 + 0xb0) % *(int *)(iVar10 + 0x4c)) *
                                            0x44 + 0x40 + iVar10) * 4 + 0x5bc04);
            }
          }
          else {
            iVar6 = _R_GetSkinByHandle(iVar6);
            iVar11 = 0;
            iStack_24 = _DAT_00017cb4;
            if (0 < *(int *)(iVar6 + 0x40)) {
              puVar12 = (undefined4 *)(iVar6 + 0x44);
              do {
                pbVar7 = (byte *)*puVar12;
                pbVar9 = (byte *)(iVar10 + 4);
                do {
                  bVar1 = *pbVar7;
                  bVar13 = bVar1 < *pbVar9;
                  if (bVar1 != *pbVar9) {
LAB_00012c80:
                    iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
                    goto LAB_00012c85;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar7[1];
                  bVar13 = bVar1 < pbVar9[1];
                  if (bVar1 != pbVar9[1]) goto LAB_00012c80;
                  pbVar7 = pbVar7 + 2;
                  pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                iVar8 = 0;
LAB_00012c85:
                if (iVar8 == 0) {
                  iStack_24 = *(int *)(*(int *)(iVar6 + 0x44 + iVar11 * 4) + 0x40);
                  break;
                }
                iVar11 = iVar11 + 1;
                puVar12 = puVar12 + 1;
              } while (iVar11 < *(int *)(iVar6 + 0x40));
            }
          }
        }
        else {
          iStack_24 = _R_GetShaderByHandle(*(int *)(param_1 + 0xb8));
        }
        if (((((!bVar3) && (*(int *)(__r_shadows + 0x20) == 2)) && (iVar5 == 0)) &&
            ((uVar2 = *(uint *)(param_1 + 4), (uVar2 & 4) == 0 && ((uVar2 & 0x800) != 0)))) &&
           (((uVar2 & 0x4000000) != 0 &&
            ((NAN(___real_40800000) || NAN(*(float *)(iStack_24 + 0x4c))) !=
             (___real_40800000 == *(float *)(iStack_24 + 0x4c)))))) {
          _R_AddDrawSurf(iVar10,__R_GetSkinByHandle,0,0);
        }
        if (((*(int *)(__r_shadows + 0x20) == 3) && (iVar5 == 0)) &&
           (((*(uint *)(param_1 + 4) & 0x100000) != 0 &&
            (((*(uint *)(param_1 + 4) & 0x4000000) != 0 &&
             ((NAN(___real_40800000) || NAN(*(float *)(iStack_24 + 0x4c))) !=
              (___real_40800000 == *(float *)(iStack_24 + 0x4c)))))))) {
          _R_AddDrawSurf(iVar10,_DAT_00017cbc,0,0);
        }
        if (!bVar3) {
          _R_AddDrawSurf(iVar10,iStack_24,iVar5,0);
        }
        iVar10 = iVar10 + *(int *)(iVar10 + 0x68);
        iStack_14 = iStack_14 + 1;
      } while (iStack_14 < *(int *)(iVar4 + 0x54));
    }
  }
  return;
}



// ===========================================
// Function: _R_CullTikiModel @ 00012dd6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_CullTikiModel(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float afStack_24 [9];
  
  if (*(int *)(in_EAX + 0x44) == 0) {
    fVar1 = *(float *)(_newFrame + 0x3c) * __tiki_scale;
    if (_oldFrame == _newFrame) {
      iVar3 = _R_CullLocalPointAndRadius(&_tiki_localorigin,fVar1);
      if (iVar3 == 0) {
LAB_00012e43:
        _DAT_00018988 = _DAT_00018988 + 1;
        return 0;
      }
      if (iVar3 == 1) {
        _DAT_0001898c = _DAT_0001898c + 1;
      }
      else if (iVar3 == 2) {
        _DAT_00018990 = _DAT_00018990 + 1;
        return 2;
      }
    }
    else {
      iVar3 = _R_CullLocalPointAndRadius(&_tiki_localorigin,fVar1);
      iVar4 = _R_CullLocalPointAndRadius
                        (&_tiki_localorigin,*(float *)(_oldFrame + 0x3c) * __tiki_scale);
      if (iVar3 == iVar4) {
        if (iVar3 == 2) {
          _DAT_00018990 = _DAT_00018990 + 1;
          return 2;
        }
        if (iVar3 == 0) goto LAB_00012e43;
        _DAT_0001898c = _DAT_0001898c + 1;
      }
    }
  }
  if ((*(byte *)(_DAT_000180cc + 4) & 0x10) == 0) {
    afStack_24[2] = 0.0;
    afStack_24[1] = 0.0;
    afStack_24[0] = 0.0;
  }
  else {
    afStack_24[0] = *(float *)(in_EAX + 0x48) - *(float *)(in_EAX + 0x9c);
    afStack_24[1] = *(float *)(in_EAX + 0x4c) - *(float *)(in_EAX + 0xa0);
    afStack_24[2] = *(float *)(in_EAX + 0x50) - *(float *)(in_EAX + 0xa4);
  }
  iVar4 = (int)afStack_24 + (0xc - _newFrame);
  pfVar5 = (float *)(_newFrame + 0xc);
  iVar3 = 0;
  do {
    if (_oldFrame == _newFrame) {
      *(float *)((int)afStack_24 + iVar3 + 0xc) =
           pfVar5[-3] * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = *pfVar5 * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
    }
    else {
      fVar2 = *(float *)(iVar3 + _oldFrame) * __tiki_scale +
              *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = pfVar5[-3] * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
      *(float *)((int)afStack_24 + iVar3 + 0xc) = fVar1;
      fVar2 = *(float *)((_oldFrame - _newFrame) + (int)pfVar5) * __tiki_scale +
              *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = *pfVar5 * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
    }
    *(float *)(iVar4 + (int)pfVar5) = fVar1;
    if (0.0 < *(float *)((int)afStack_24 + iVar3) == NAN(*(float *)((int)afStack_24 + iVar3))) {
      *(float *)((int)afStack_24 + iVar3 + 0xc) =
           *(float *)((int)afStack_24 + iVar3) + *(float *)((int)afStack_24 + iVar3 + 0xc);
    }
    else {
      *(float *)(iVar4 + (int)pfVar5) =
           *(float *)(iVar4 + (int)pfVar5) + *(float *)((int)afStack_24 + iVar3);
    }
    iVar3 = iVar3 + 4;
    pfVar5 = pfVar5 + 1;
  } while (iVar3 < 0xc);
  iVar3 = _R_CullLocalBox(afStack_24 + 3);
  if (iVar3 == 0) {
    _DAT_00018994 = _DAT_00018994 + 1;
    return 0;
  }
  if (iVar3 == 1) {
    _DAT_00018998 = _DAT_00018998 + 1;
    return 1;
  }
  _DAT_0001899c = _DAT_0001899c + 1;
  return 2;
}



// ===========================================
// Function: _R_CullSkelModel @ 0001304e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_CullSkelModel(int param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int unaff_EDI;
  float afStack_24 [9];
  
  if (*(int *)(in_EAX + 0x44) == 0) {
    fVar1 = *(float *)(unaff_EDI + 0x18) * __tiki_scale;
    if (param_1 == unaff_EDI) {
      iVar3 = _R_CullLocalPointAndRadius(&_tiki_localorigin,fVar1);
      if (iVar3 == 0) {
LAB_000130b8:
        _DAT_00018988 = _DAT_00018988 + 1;
        return 0;
      }
      if (iVar3 == 1) {
        _DAT_0001898c = _DAT_0001898c + 1;
      }
      else if (iVar3 == 2) {
        _DAT_00018990 = _DAT_00018990 + 1;
        return 2;
      }
    }
    else {
      iVar3 = _R_CullLocalPointAndRadius(&_tiki_localorigin,fVar1);
      iVar4 = _R_CullLocalPointAndRadius
                        (&_tiki_localorigin,*(float *)(param_1 + 0x18) * __tiki_scale);
      if (iVar3 == iVar4) {
        if (iVar3 == 2) {
          _DAT_00018990 = _DAT_00018990 + 1;
          return 2;
        }
        if (iVar3 == 0) goto LAB_000130b8;
        _DAT_0001898c = _DAT_0001898c + 1;
      }
    }
  }
  if ((*(byte *)(_DAT_000180cc + 4) & 0x10) == 0) {
    afStack_24[2] = 0.0;
    afStack_24[1] = 0.0;
    afStack_24[0] = 0.0;
  }
  else {
    afStack_24[0] = *(float *)(in_EAX + 0x48) - *(float *)(in_EAX + 0x9c);
    afStack_24[1] = *(float *)(in_EAX + 0x4c) - *(float *)(in_EAX + 0xa0);
    afStack_24[2] = *(float *)(in_EAX + 0x50) - *(float *)(in_EAX + 0xa4);
  }
  iVar4 = (int)afStack_24 + (0xc - unaff_EDI);
  pfVar5 = (float *)(unaff_EDI + 0xc);
  iVar3 = 0;
  do {
    if (param_1 == unaff_EDI) {
      *(float *)((int)afStack_24 + iVar3 + 0xc) =
           pfVar5[-3] * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = *pfVar5 * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
    }
    else {
      fVar2 = *(float *)(iVar3 + param_1) * __tiki_scale +
              *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = pfVar5[-3] * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
      *(float *)((int)afStack_24 + iVar3 + 0xc) = fVar1;
      fVar2 = *(float *)((param_1 - unaff_EDI) + (int)pfVar5) * __tiki_scale +
              *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = *pfVar5 * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
    }
    *(float *)(iVar4 + (int)pfVar5) = fVar1;
    if (0.0 < *(float *)((int)afStack_24 + iVar3) == NAN(*(float *)((int)afStack_24 + iVar3))) {
      *(float *)((int)afStack_24 + iVar3 + 0xc) =
           *(float *)((int)afStack_24 + iVar3) + *(float *)((int)afStack_24 + iVar3 + 0xc);
    }
    else {
      *(float *)(iVar4 + (int)pfVar5) =
           *(float *)(iVar4 + (int)pfVar5) + *(float *)((int)afStack_24 + iVar3);
    }
    iVar3 = iVar3 + 4;
    pfVar5 = pfVar5 + 1;
  } while (iVar3 < 0xc);
  iVar3 = _R_CullLocalBox(afStack_24 + 3);
  if (iVar3 == 0) {
    _DAT_00018994 = _DAT_00018994 + 1;
    return 0;
  }
  if (iVar3 == 1) {
    _DAT_00018998 = _DAT_00018998 + 1;
    return 1;
  }
  _DAT_0001899c = _DAT_0001899c + 1;
  return 2;
}



// ===========================================
// Function: _R_CalcLod @ 000132ae
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
_R_CalcLod(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float fVar4;
  
  fVar2 = (float10)_ProjectRadius(param_3,param_1);
  fVar1 = (float10)0;
  fVar3 = (float10)(float)fVar2;
  fVar2 = (float10)1;
  if ((NAN(fVar3) || NAN(fVar1)) == (fVar3 == fVar1)) {
    fVar4 = *(float *)(__r_lodscale + 0x1c);
    if (___real_41a00000 < fVar4 == (NAN(___real_41a00000) || NAN(fVar4))) {
      fVar4 = (float)((float10)param_4 * (float10)fVar4 * fVar3);
    }
    else {
      fVar4 = (float)((float10)param_4 * (float10)___real_41a00000 * fVar3);
    }
  }
  else {
    fVar4 = (float)fVar2;
  }
  fVar3 = (float10)(fVar4 - (*(float *)(__r_lodbias + 0x1c) + param_5));
  if (fVar3 < fVar1 != (NAN(fVar3) || NAN(fVar1))) {
    return (float10)(float)fVar1;
  }
  if (fVar2 < fVar3 != (NAN(fVar2) || NAN(fVar3))) {
    return (float10)(float)fVar2;
  }
  return fVar3;
}



// ===========================================
// Function: _R_TikiCalcLod @ 0001336a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
_R_TikiCalcLod(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  float10 fVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  iVar2 = (int)param_3;
  fVar3 = (float10)_ProjectRadius(param_4,param_1);
  fVar1 = (float10)0;
  fVar4 = (float10)(float)fVar3;
  fVar3 = (float10)1;
  fVar5 = fVar3;
  if ((NAN(fVar4) || NAN(fVar1)) == (fVar4 == fVar1)) {
    param_3 = *(float *)(__r_lodscale + 0x1c);
    if (___real_41a00000 < param_3 != (NAN(___real_41a00000) || NAN(param_3))) {
      param_3 = ___real_41a00000;
    }
    fVar5 = (float10)*(float *)(iVar2 + 0xa8) * (float10)param_3 * fVar4;
  }
  param_3 = (float)fVar5;
  fVar5 = (float10)(param_3 - (*(float *)(__r_lodbias + 0x1c) + *(float *)(iVar2 + 0xac)));
  if (fVar5 < fVar1 == (NAN(fVar5) || NAN(fVar1))) {
    if (fVar3 < fVar5 == (NAN(fVar3) || NAN(fVar5))) {
      return fVar5;
    }
    return (float10)(float)fVar3;
  }
  return (float10)(float)fVar1;
}



// ===========================================
// Function: _R_CalcFogNum @ 0001342b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_CalcFogNum(float *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  float local_c [3];
  
  if ((DAT_000187bc & 1) != 0) {
    return 0;
  }
  iVar1 = *(int *)(__r_lodbias + 0xb4);
  if ((iVar1 < 2) || (_DAT_000186bc != 0)) {
    return 0;
  }
  local_c[0] = *param_1;
  local_c[1] = param_1[1];
  iVar5 = 1;
  param_2 = param_2 * (float)___real_3fe0000000000000;
  local_c[2] = param_2 + param_1[2];
  if (iVar1 < 2) {
    return 0;
  }
  pfVar4 = (float *)(*(int *)(__r_lodbias + 0xb8) + 0x60);
  do {
    iVar2 = 0;
    pfVar3 = pfVar4;
    do {
      if ((pfVar3[3] < local_c[iVar2] - param_2 != (pfVar3[3] == local_c[iVar2] - param_2)) ||
         (local_c[iVar2] + param_2 <= *pfVar3)) break;
      iVar2 = iVar2 + 1;
      pfVar3 = pfVar3 + 1;
    } while (iVar2 < 3);
    if (iVar2 == 3) {
      return iVar5;
    }
    iVar5 = iVar5 + 1;
    pfVar4 = pfVar4 + 0x17;
    if (iVar1 <= iVar5) {
      return 0;
    }
  } while( true );
}



// ===========================================
// Function: _R_ValidateSkelFrame @ 000134fb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_ValidateSkelFrame(undefined4 param_1,int param_2,int *param_3,short *param_4)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *param_3;
  if ((*(int *)(param_2 + 0x88) <= iVar2) || (iVar2 < 0)) {
    (*__ri)(1,s_R_AddSkelSurfaces__no_such_anim_,iVar2,param_1);
    *param_3 = 0;
    *param_4 = 0;
  }
  iVar2 = _TIKI_GetAnim(*(undefined4 *)(*(int *)(param_2 + 0x168 + *param_3 * 4) + 0xb8 + param_2));
  if (iVar2 == 0) {
    (*__ri)(1,s_R_AddSkelSurfaces__couldn_t_get_,*param_3,param_1);
    return 0;
  }
  sVar1 = *param_4;
  if ((*(int *)(iVar2 + 0x4c) <= (int)sVar1) || (sVar1 < 0)) {
    (*__ri)(1,s_R_AddSkelSurfaces__no_such_frame,(int)sVar1,*param_3,param_1);
    *param_4 = 0;
  }
  return (*(int *)(iVar2 + 0x50) * 0x10 + 0x28) * (int)*param_4 + *(int *)(iVar2 + 0x68) + iVar2;
}



// ===========================================
// Function: _QuatMult @ 000135b9
// ===========================================

void _QuatMult(float *param_1,float *param_2,float *param_3)

{
  *param_3 = (param_1[1] * param_2[2] + *param_2 * param_1[3] + *param_1 * param_2[3]) -
             param_1[2] * param_2[1];
  param_3[1] = (param_1[2] * *param_2 + param_1[1] * param_2[3] + param_2[1] * param_1[3]) -
               *param_1 * param_2[2];
  param_3[2] = (param_2[1] * *param_1 + param_2[2] * param_1[3] + param_1[2] * param_2[3]) -
               param_1[1] * *param_2;
  param_3[3] = ((param_1[3] * param_2[3] - *param_1 * *param_2) - param_2[1] * param_1[1]) -
               param_1[2] * param_2[2];
  return;
}



// ===========================================
// Function: _R_GetBone @ 00013641
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_GetBone(int param_1,int param_2,undefined4 param_3,float *param_4)

{
  short *psVar1;
  float fVar2;
  
  psVar1 = (short *)(param_1 * 0x10 + 0x28 + param_2);
  fVar2 = (float)___real_3f90410420000000;
  param_4[4] = (float)(int)*(short *)(param_1 * 0x10 + 0x30 + param_2) * fVar2;
  param_4[5] = (float)(int)psVar1[5] * fVar2;
  param_4[6] = (float)(int)psVar1[6] * fVar2;
  fVar2 = (float)___real_3f00002000000000;
  *param_4 = (float)(int)*psVar1 * fVar2;
  param_4[1] = (float)(int)psVar1[1] * fVar2;
  param_4[2] = (float)(int)psVar1[2] * fVar2;
  param_4[3] = (float)(int)psVar1[3] * fVar2;
  return;
}



// ===========================================
// Function: _ScaleQuatToMat @ 000136db
// ===========================================

void _ScaleQuatToMat(float *param_1,float *param_2,float param_3)

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
  
  fVar6 = param_3 + param_3;
  fVar8 = param_1[1] * fVar6;
  fVar9 = fVar6 * param_1[2];
  fVar10 = fVar6 * *param_1 * *param_1;
  fVar1 = *param_1;
  fVar2 = *param_1;
  fVar3 = param_1[1];
  fVar4 = param_1[1];
  fVar5 = param_1[2];
  fVar11 = param_1[3] * fVar6 * *param_1;
  fVar6 = param_1[3];
  fVar7 = param_1[3];
  *param_2 = param_3 - (fVar3 * fVar8 + fVar5 * fVar9);
  param_2[1] = fVar8 * fVar1 - fVar9 * fVar7;
  param_2[2] = fVar8 * fVar6 + fVar9 * fVar2;
  param_2[3] = fVar9 * fVar7 + fVar8 * fVar1;
  param_2[4] = param_3 - (fVar10 + fVar5 * fVar9);
  param_2[5] = fVar4 * fVar9 - fVar11;
  param_2[6] = fVar9 * fVar2 - fVar8 * fVar6;
  param_2[7] = fVar4 * fVar9 + fVar11;
  param_2[8] = param_3 - (fVar10 + fVar3 * fVar8);
  return;
}



// ===========================================
// Function: _R_ValidateSkelFrame_V2 @ 000137f6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_ValidateSkelFrame_V2(undefined4 param_1,int param_2,int *param_3,short *param_4)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *param_3;
  if ((*(int *)(param_2 + 0x88) <= iVar2) || (iVar2 < 0)) {
    (*__ri)(1,s_R_AddSkelSurfaces__no_such_anim_,iVar2,param_1);
    *param_3 = 0;
    *param_4 = 0;
  }
  iVar2 = _TIKI_GetAnim(*(undefined4 *)(*(int *)(param_2 + 0x168 + *param_3 * 4) + 0xb8 + param_2));
  if (iVar2 == 0) {
    (*__ri)(1,s_R_AddSkelSurfaces__couldn_t_get_,*param_3,param_1);
    return 0;
  }
  sVar1 = *param_4;
  if ((*(int *)(iVar2 + 0x48) <= (int)sVar1) || (sVar1 < 0)) {
    (*__ri)(1,s_R_AddSkelSurfaces__no_such_frame,(int)sVar1,*param_3,param_1);
    *param_4 = 0;
  }
  return (*(int *)(iVar2 + 0x4c) * 0x1c + 0x28) * (int)*param_4 + *(int *)(iVar2 + 0x68) + iVar2;
}



// ===========================================
// Function: _R_CullSkelModel_V2 @ 000138be
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_CullSkelModel_V2(undefined4 param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float afStack_24 [9];
  
  if (*(int *)(param_2 + 0x44) == 0) {
    fVar1 = *(float *)(param_3 + 0x18) * __tiki_scale;
    if (param_4 == param_3) {
      iVar3 = _R_CullLocalPointAndRadius(&_tiki_localorigin,fVar1);
      if (iVar3 == 0) {
LAB_00013930:
        _DAT_00018988 = _DAT_00018988 + 1;
        return 0;
      }
      if (iVar3 == 1) {
        _DAT_0001898c = _DAT_0001898c + 1;
      }
      else if (iVar3 == 2) {
        _DAT_00018990 = _DAT_00018990 + 1;
        return 2;
      }
    }
    else {
      iVar3 = _R_CullLocalPointAndRadius(&_tiki_localorigin,fVar1);
      iVar4 = _R_CullLocalPointAndRadius
                        (&_tiki_localorigin,*(float *)(param_4 + 0x18) * __tiki_scale);
      if (iVar3 == iVar4) {
        if (iVar3 == 2) {
          _DAT_00018990 = _DAT_00018990 + 1;
          return 2;
        }
        if (iVar3 == 0) goto LAB_00013930;
        _DAT_0001898c = _DAT_0001898c + 1;
      }
    }
  }
  if ((*(byte *)(_DAT_000180cc + 4) & 0x10) == 0) {
    afStack_24[2] = 0.0;
    afStack_24[1] = 0.0;
    afStack_24[0] = 0.0;
  }
  else {
    afStack_24[0] = *(float *)(param_2 + 0x48) - *(float *)(param_2 + 0x9c);
    afStack_24[1] = *(float *)(param_2 + 0x4c) - *(float *)(param_2 + 0xa0);
    afStack_24[2] = *(float *)(param_2 + 0x50) - *(float *)(param_2 + 0xa4);
  }
  iVar4 = (int)afStack_24 + (0xc - param_3);
  pfVar5 = (float *)(param_3 + 0xc);
  iVar3 = 0;
  do {
    if (param_4 == param_3) {
      *(float *)((int)afStack_24 + iVar3 + 0xc) =
           pfVar5[-3] * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = *pfVar5 * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
    }
    else {
      fVar2 = *(float *)(iVar3 + param_4) * __tiki_scale +
              *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = pfVar5[-3] * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
      *(float *)((int)afStack_24 + iVar3 + 0xc) = fVar1;
      fVar2 = *(float *)((param_4 - param_3) + (int)pfVar5) * __tiki_scale +
              *(float *)((int)&_tiki_localorigin + iVar3);
      fVar1 = *pfVar5 * __tiki_scale + *(float *)((int)&_tiki_localorigin + iVar3);
      if (fVar2 < fVar1) {
        fVar1 = fVar2;
      }
    }
    *(float *)(iVar4 + (int)pfVar5) = fVar1;
    if (0.0 < *(float *)((int)afStack_24 + iVar3) == NAN(*(float *)((int)afStack_24 + iVar3))) {
      *(float *)((int)afStack_24 + iVar3 + 0xc) =
           *(float *)((int)afStack_24 + iVar3) + *(float *)((int)afStack_24 + iVar3 + 0xc);
    }
    else {
      *(float *)(iVar4 + (int)pfVar5) =
           *(float *)(iVar4 + (int)pfVar5) + *(float *)((int)afStack_24 + iVar3);
    }
    iVar3 = iVar3 + 4;
    pfVar5 = pfVar5 + 1;
  } while (iVar3 < 0xc);
  iVar3 = _R_CullLocalBox(afStack_24 + 3);
  if (iVar3 == 0) {
    _DAT_00018994 = _DAT_00018994 + 1;
    return 0;
  }
  if (iVar3 == 1) {
    _DAT_00018998 = _DAT_00018998 + 1;
    return 1;
  }
  _DAT_0001899c = _DAT_0001899c + 1;
  return 2;
}



// ===========================================
// Function: _R_CountTikiLodTris @ 00013b2b
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_CountTikiLodTris(int param_1,undefined4 param_2,int *param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_4b0c;
  int local_4b08;
  int iStack_4b04;
  int aiStack_4b00 [4799];
  undefined4 uStack_4;
  
  uStack_4 = 0x13b35;
  *param_3 = 0;
  *param_4 = 0;
  iVar8 = *(int *)(_DAT_000180cc + 0x1b0);
  __tiki_scale = *(float *)(_DAT_000180cc + 0x60) * *(float *)(iVar8 + 0xa4);
  local_4b0c = 0;
  local_4b08 = 0;
  _tiki_localorigin = __tiki_scale * *(float *)(iVar8 + 0xbc);
  _DAT_00008324 = *(float *)(iVar8 + 0xc0) * __tiki_scale;
  _DAT_00008328 = __tiki_scale * *(float *)(iVar8 + 0xc4);
  if (param_5 == 0) {
    iVar4 = _TIKI_GetAnim(*(undefined4 *)
                           (*(int *)(iVar8 + 0x168 + *(int *)(param_1 + 0x54) * 4) + iVar8 + 0xb8));
    iStack_4b04 = *(int *)(iVar8 + 0x80);
    iVar4 = *(int *)(iVar4 + 0x68) + iVar4;
    if (iStack_4b04 < 1) {
      *param_3 = 0;
      *param_4 = 0;
      return;
    }
    do {
      iVar8 = *(int *)(iVar4 + 0x48);
      iVar5 = __ftol2_sse();
      iVar1 = *(int *)(iVar4 + 0x4c);
      if ((iVar5 < iVar1) && (iVar5 = iVar1, iVar1 < 1)) {
        iVar5 = 0;
      }
      if (iVar8 < iVar5) {
        iVar5 = iVar8;
      }
      iVar1 = *(int *)(iVar4 + 0x54);
      iVar2 = *(int *)(iVar4 + 0x58);
      local_4b08 = local_4b08 + *(int *)(iVar4 + 0x50);
      iVar3 = *(int *)(iVar4 + 0x50) * 3;
      iVar6 = 0;
      if (0 < iVar5) {
        do {
          aiStack_4b00[iVar6] = iVar6;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar5);
      }
      for (; iVar5 < iVar8; iVar5 = iVar5 + 1) {
        aiStack_4b00[iVar5] = aiStack_4b00[*(int *)(iVar2 + iVar4 + iVar5 * 4)];
      }
      if (0 < iVar3) {
        piVar7 = (int *)(iVar1 + iVar4 + 8);
        iVar8 = (iVar3 - 1U) / 3 + 1;
        do {
          if (((aiStack_4b00[piVar7[-2]] != aiStack_4b00[piVar7[-1]]) &&
              (aiStack_4b00[piVar7[-1]] != aiStack_4b00[*piVar7])) &&
             (aiStack_4b00[*piVar7] != aiStack_4b00[piVar7[-2]])) {
            local_4b0c = local_4b0c + 1;
          }
          piVar7 = piVar7 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar4 = iVar4 + *(int *)(iVar4 + 100);
      iStack_4b04 = iStack_4b04 + -1;
    } while (iStack_4b04 != 0);
    *param_3 = local_4b0c;
    *param_4 = local_4b08;
    return;
  }
  iVar4 = _TIKI_GetSkel(*(undefined4 *)(iVar8 + 0xe4));
  iStack_4b04 = *(int *)(iVar8 + 0x80);
  iVar4 = *(int *)(iVar4 + 0x54) + iVar4;
  if (iStack_4b04 < 1) {
    *param_3 = 0;
    *param_4 = 0;
    return;
  }
  do {
    iVar8 = *(int *)(iVar4 + 0x48);
    iVar5 = __ftol2_sse();
    iVar1 = *(int *)(iVar4 + 0x4c);
    if ((iVar5 < iVar1) && (iVar5 = iVar1, iVar1 < 1)) {
      iVar5 = 0;
    }
    if (iVar8 < iVar5) {
      iVar5 = iVar8;
    }
    iVar1 = *(int *)(iVar4 + 0x50);
    iVar2 = *(int *)(iVar4 + 0x58);
    local_4b08 = local_4b08 + *(int *)(iVar4 + 0x44);
    iVar3 = *(int *)(iVar4 + 0x44) * 3;
    iVar6 = 0;
    if (0 < iVar5) {
      do {
        aiStack_4b00[iVar6] = iVar6;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar5);
    }
    for (; iVar5 < iVar8; iVar5 = iVar5 + 1) {
      aiStack_4b00[iVar5] = aiStack_4b00[*(int *)(iVar2 + iVar4 + iVar5 * 4)];
    }
    if (0 < iVar3) {
      piVar7 = (int *)(iVar1 + iVar4 + 8);
      iVar8 = (iVar3 - 1U) / 3 + 1;
      do {
        if (((aiStack_4b00[piVar7[-2]] != aiStack_4b00[piVar7[-1]]) &&
            (aiStack_4b00[piVar7[-1]] != aiStack_4b00[*piVar7])) &&
           (aiStack_4b00[*piVar7] != aiStack_4b00[piVar7[-2]])) {
          local_4b0c = local_4b0c + 1;
        }
        piVar7 = piVar7 + 3;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    iVar4 = iVar4 + *(int *)(iVar4 + 0x5c);
    iStack_4b04 = iStack_4b04 + -1;
  } while (iStack_4b04 != 0);
  *param_3 = local_4b0c;
  *param_4 = local_4b08;
  return;
}



// ===========================================
// Function: _R_AddSkelSurfaces_V2 @ 00013e2b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddSkelSurfaces_V2(int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  float *pfVar10;
  float *pfVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  float *pfVar15;
  byte *pbVar16;
  float10 fVar17;
  byte *pbStack_388;
  float fStack_384;
  byte *local_380;
  byte *pbStack_37c;
  float fStack_378;
  int iStack_374;
  int iStack_370;
  undefined *puStack_36c;
  byte *local_368;
  float fStack_364;
  int local_360;
  int local_35c;
  int local_358;
  int iStack_354;
  byte *pbStack_350;
  int *piStack_34c;
  float fStack_348;
  float fStack_344;
  float fStack_340;
  float fStack_33c;
  float fStack_338;
  float fStack_334;
  float fStack_330;
  float fStack_32c;
  float fStack_328;
  float fStack_324;
  float afStack_320 [200];
  
  pbVar12 = (byte *)0x0;
  local_380 = (byte *)0x0;
  local_368 = (byte *)0x0;
  local_35c = 0;
  local_360 = 0;
  local_358 = 0;
  if ((*(int *)(param_1 + 0x84) == 0) && (*(int *)(param_1 + 0x98) == 0)) {
    (*__ri)(1,s_R_AddSkelSurfaces__model___s__wi,param_2);
    return;
  }
  iVar3 = _TIKI_GetSkel(*(undefined4 *)(param_3 + 0xe4));
  iStack_370 = iVar3;
  if (iVar3 == 0) {
    (*__ri)(1,s_R_AddSkelSurfaces__couldn_t_get_,param_2);
    return;
  }
  if (*(int *)(iVar3 + 0x4c) + _TIKI_Skel_boneindex < 0xfa1) {
    __tiki_scale = *(float *)(param_3 + 0xa4) * *(float *)(param_1 + 0x60);
    fStack_378 = 0.0;
    _tiki_localorigin = __tiki_scale * *(float *)(param_3 + 0xbc);
    _DAT_00008324 = *(float *)(param_3 + 0xc0) * __tiki_scale;
    _DAT_00008328 = __tiki_scale * *(float *)(param_3 + 0xc4);
    if (*(int *)(param_1 + 0x84) != 0) {
      pbVar12 = (byte *)_R_ValidateSkelFrame_V2(param_2,param_3,param_1 + 0x54,param_1 + 0x5e);
      if (pbVar12 == (byte *)0x0) {
        return;
      }
      local_380 = pbVar12;
      local_368 = (byte *)_R_ValidateSkelFrame_V2(param_2,param_3,param_1 + 0x58,param_1 + 0x5c);
      iVar4 = _R_CullSkelModel_V2(param_3,param_1,pbVar12,local_368);
      if (iVar4 == 2) {
        return;
      }
      fStack_378 = *(float *)(pbVar12 + 0x18) * __tiki_scale;
      *(byte **)(param_1 + 0x1a8) = local_368;
      *(byte **)(param_1 + 0x1ac) = pbVar12;
    }
    if (*(int *)(param_1 + 0x98) != 0) {
      iVar4 = _R_ValidateSkelFrame_V2(param_2,param_3,param_1 + 0x68,param_1 + 0x70);
      if (iVar4 == 0) {
        return;
      }
      local_35c = iVar4;
      local_360 = _R_ValidateSkelFrame_V2(param_2,param_3,param_1 + 0x6c,param_1 + 0x72);
      local_358 = _R_ValidateSkelFrame_V2(param_2,param_3,param_1 + 0x90,param_1 + 0x94);
      pbVar12 = local_380;
      if (*(int *)(param_1 + 0x84) == 0) {
        iVar5 = _R_CullSkelModel_V2(param_3,param_1,iVar4,local_360);
        if (iVar5 == 2) {
          return;
        }
        fStack_378 = *(float *)(iVar4 + 0x18) * __tiki_scale;
        *(int *)(param_1 + 0x1a8) = local_360;
        *(int *)(param_1 + 0x1ac) = iVar4;
        pbVar12 = local_380;
      }
    }
    fStack_338 = _tiki_localorigin + *(float *)(param_1 + 0x48);
    fStack_334 = _DAT_00008324 + *(float *)(param_1 + 0x4c);
    fStack_330 = _DAT_00008328 + *(float *)(param_1 + 0x50);
    if (_DAT_000184b0 == 0) {
      fVar17 = (float10)_R_TikiCalcLod(&fStack_338,param_3,fStack_378);
      *(float *)(param_1 + 0x200) = (float)fVar17;
    }
    else {
      fVar17 = (float10)_R_TikiCalcLod(&fStack_338,param_3,fStack_378);
      *(float *)(param_1 + 0x204) = (float)fVar17;
    }
    fStack_378 = (float)_R_CalcFogNum(&fStack_338,fStack_378);
    if (*(int *)(param_1 + 100) != 0) {
      if (-1 < *(int *)(param_1 + 0xf4)) {
        *(undefined4 *)(*(int *)(param_1 + 0xf4) * 4 + 0x2000) = 1;
      }
      if (-1 < *(int *)(param_1 + 0x118)) {
        *(undefined4 *)(*(int *)(param_1 + 0x118) * 4 + 0x2000) = 2;
      }
      if (-1 < *(int *)(param_1 + 0x13c)) {
        *(undefined4 *)(*(int *)(param_1 + 0x13c) * 4 + 0x2000) = 3;
      }
      if (-1 < *(int *)(param_1 + 0x160)) {
        *(undefined4 *)(*(int *)(param_1 + 0x160) * 4 + 0x2000) = 4;
      }
      if (-1 < *(int *)(param_1 + 0x184)) {
        *(undefined4 *)(*(int *)(param_1 + 0x184) * 4 + 0x2000) = 5;
      }
    }
    puStack_36c = &_TIKI_Skel_Bones + _TIKI_Skel_boneindex * 0x40;
    piStack_34c = (int *)(*(int *)(iVar3 + 0x50) + iVar3);
    if (*(int *)(param_1 + 0x84) != 0) {
      if (((*(int *)(__r_lerpmodels + 0x20) == 0) || (local_368 == pbVar12)) ||
         (local_368 == (byte *)0x0)) {
        pbStack_350 = (byte *)0x0;
        fStack_384 = 1.0;
      }
      else {
        pbStack_350 = *(byte **)(param_1 + 0xa8);
        fStack_384 = 1.0 - (float)pbStack_350;
      }
      if (0.0 < *(float *)(param_1 + 0x74) == (*(float *)(param_1 + 0x74) == 0.0)) {
        fStack_364 = 0.0;
        pbVar12 = (byte *)0x0;
        pbStack_388 = (byte *)0x0;
        iVar4 = 2;
        if (NAN((float)pbStack_350) != ((float)pbStack_350 == 0.0)) {
          iVar4 = 1;
        }
      }
      else {
        pbVar12 = (byte *)_R_ValidateSkelFrame_V2(param_2,param_3,param_1 + 0x7c,param_1 + 0x80);
        fStack_364 = *(float *)(param_1 + 0x74);
        pbStack_388 = (byte *)(1.0 - fStack_364);
        if (NAN((float)pbStack_350) == ((float)pbStack_350 == 0.0)) {
          iVar4 = 3;
        }
        else {
          iVar4 = 2;
          fStack_384 = fStack_364;
          local_368 = pbVar12;
          pbStack_350 = pbStack_388;
        }
        if (pbVar12 == (byte *)0x0) {
          iVar4 = iVar4 + -1;
        }
      }
      pbVar13 = local_380 + 0x28;
      pbVar16 = pbVar12 + 0x28;
      if (*(int *)(param_1 + 0x98) == 0) {
        if (iVar4 == 3) {
          iStack_374 = 0;
          if (0 < *(int *)(iVar3 + 0x4c)) {
            pfVar15 = (float *)(local_368 + (int)(pbVar16 + (0x18 - (int)pbVar12)));
            iStack_354 = (int)local_368 - (int)local_380;
            pbStack_37c = pbVar12 + -(int)local_380;
            local_368 = pbVar12 + -(int)local_368;
            pfVar11 = (float *)(puStack_36c + 0x14);
            pfVar10 = (float *)(local_380 + (int)(pbVar16 + (0x10 - (int)pbVar12)));
            do {
              _SlerpQuaternion(pfVar15 + -6,pfVar10 + -4,fStack_384,&fStack_348);
              _SlerpQuaternion(pbVar16,&fStack_348,fStack_364,pfVar11 + -5);
              pfVar11[-1] = fStack_364 *
                            ((float)pbStack_350 * *(float *)(iStack_354 + (int)pfVar10) +
                            fStack_384 * *pfVar10) +
                            (float)pbStack_388 *
                            *(float *)(pbStack_37c + -0x1c + (int)(pfVar10 + 7));
              *pfVar11 = *(float *)(pbVar16 + 0x14) * (float)pbStack_388 +
                         (pfVar15[-1] * (float)pbStack_350 + pfVar10[1] * fStack_384) * fStack_364;
              iStack_374 = iStack_374 + 1;
              pfVar11[1] = (float)pbStack_388 * *(float *)(local_368 + -0x1c + (int)(pfVar15 + 7)) +
                           fStack_364 * (pfVar10[2] * fStack_384 + *pfVar15 * (float)pbStack_350);
              iVar3 = iStack_370;
              pfVar11 = pfVar11 + 0x10;
              pfVar15 = pfVar15 + 7;
              pfVar10 = pfVar10 + 7;
              pbVar16 = pbVar16 + 0x1c;
            } while (iStack_374 < *(int *)(iStack_370 + 0x4c));
          }
        }
        else if (iVar4 == 2) {
          iStack_374 = 0;
          if (0 < *(int *)(iVar3 + 0x4c)) {
            pbStack_37c = local_380 + -(int)local_368;
            pfVar15 = (float *)(puStack_36c + 0x14);
            pfVar11 = (float *)(local_368 + (int)(pbVar13 + (0x14 - (int)local_380)));
            do {
              _SlerpQuaternion(pfVar11 + -5,pbVar13,fStack_384,pfVar15 + -5);
              iStack_374 = iStack_374 + 1;
              pfVar15[-1] = (float)pbStack_350 * pfVar11[-1] +
                            fStack_384 * *(float *)(pbVar13 + 0x10);
              *pfVar15 = *pfVar11 * (float)pbStack_350 +
                         *(float *)(pbStack_37c + -0x1c + (int)(pfVar11 + 7)) * fStack_384;
              pfVar15[1] = *(float *)(pbVar13 + 0x18) * fStack_384 + (float)pbStack_350 * pfVar11[1]
              ;
              iVar3 = iStack_370;
              pfVar15 = pfVar15 + 0x10;
              pbVar13 = pbVar13 + 0x1c;
              pfVar11 = pfVar11 + 7;
            } while (iStack_374 < *(int *)(iStack_370 + 0x4c));
          }
        }
        else if ((iVar4 == 1) && (iVar4 = 0, 0 < *(int *)(iVar3 + 0x4c))) {
          puVar14 = (undefined4 *)(puStack_36c + 0x14);
          do {
            iVar4 = iVar4 + 1;
            puVar14[-1] = *(undefined4 *)(pbVar13 + 0x10);
            *puVar14 = *(undefined4 *)(pbVar13 + 0x14);
            puVar14[1] = *(undefined4 *)(pbVar13 + 0x18);
            puVar14[-5] = *(undefined4 *)pbVar13;
            puVar14[-4] = *(undefined4 *)(pbVar13 + 4);
            puVar14[-3] = *(undefined4 *)(pbVar13 + 8);
            puVar14[-2] = *(undefined4 *)(pbVar13 + 0xc);
            puVar14 = puVar14 + 0x10;
            pbVar13 = pbVar13 + 0x1c;
          } while (iVar4 < *(int *)(iVar3 + 0x4c));
        }
      }
      else if (iVar4 == 3) {
        iStack_374 = 0;
        if (0 < *(int *)(iVar3 + 0x4c)) {
          pfVar15 = (float *)(local_368 + (int)(pbVar16 + (0x18 - (int)pbVar12)));
          iStack_354 = (int)local_368 - (int)local_380;
          pbStack_37c = pbVar12 + -(int)local_380;
          pfVar10 = (float *)(puStack_36c + 0x14);
          local_368 = pbVar12 + -(int)local_368;
          pfVar11 = (float *)(local_380 + (int)(pbVar16 + (0x10 - (int)pbVar12)));
          fVar2 = fStack_384;
          local_380 = (byte *)(piStack_34c + 1);
          do {
            if (*(int *)local_380 == 1) {
              _SlerpQuaternion(pfVar15 + -6,pfVar11 + -4,fVar2,&fStack_348);
              _SlerpQuaternion(pbVar16,&fStack_348,fStack_364,pfVar10 + -5);
              pfVar10[-1] = fStack_364 *
                            ((float)pbStack_350 * *(float *)(iStack_354 + (int)pfVar11) +
                            fStack_384 * *pfVar11) +
                            (float)pbStack_388 * *(float *)(pbStack_37c + (int)pfVar11);
              *pfVar10 = *(float *)(pbVar16 + 0x14) * (float)pbStack_388 +
                         (pfVar15[-1] * (float)pbStack_350 + pfVar11[1] * fStack_384) * fStack_364;
              pfVar10[1] = (float)pbStack_388 * *(float *)(local_368 + (int)pfVar15) +
                           fStack_364 * (pfVar11[2] * fStack_384 + *pfVar15 * (float)pbStack_350);
              fVar2 = fStack_384;
            }
            local_380 = local_380 + 0x48;
            iStack_374 = iStack_374 + 1;
            pfVar10 = pfVar10 + 0x10;
            pbVar16 = pbVar16 + 0x1c;
            pfVar15 = pfVar15 + 7;
            pfVar11 = pfVar11 + 7;
            iVar3 = iStack_370;
          } while (iStack_374 < *(int *)(iStack_370 + 0x4c));
        }
      }
      else if (iVar4 == 2) {
        iStack_374 = 0;
        if (0 < *(int *)(iVar3 + 0x4c)) {
          pfVar15 = (float *)(local_368 + (int)(pbVar13 + (0x14 - (int)local_380)));
          pbStack_388 = (byte *)(piStack_34c + 1);
          pfVar11 = (float *)(puStack_36c + 0x14);
          pbStack_37c = local_380 + -(int)local_368;
          fVar2 = fStack_384;
          do {
            if (*(int *)pbStack_388 == 1) {
              _SlerpQuaternion(pfVar15 + -5,pbVar13,fVar2,pfVar11 + -5);
              pfVar11[-1] = (float)pbStack_350 * pfVar15[-1] +
                            fStack_384 * *(float *)(pbVar13 + 0x10);
              *pfVar11 = *pfVar15 * (float)pbStack_350 +
                         *(float *)(pbStack_37c + (int)pfVar15) * fStack_384;
              pfVar11[1] = *(float *)(pbVar13 + 0x18) * fStack_384 + (float)pbStack_350 * pfVar15[1]
              ;
              fVar2 = fStack_384;
            }
            pbStack_388 = pbStack_388 + 0x48;
            iStack_374 = iStack_374 + 1;
            pfVar11 = pfVar11 + 0x10;
            pbVar13 = pbVar13 + 0x1c;
            pfVar15 = pfVar15 + 7;
            iVar3 = iStack_370;
          } while (iStack_374 < *(int *)(iStack_370 + 0x4c));
        }
      }
      else if ((iVar4 == 1) && (iVar4 = 0, 0 < *(int *)(iVar3 + 0x4c))) {
        puVar14 = (undefined4 *)(puStack_36c + 0x14);
        piVar9 = piStack_34c + 1;
        do {
          if (*piVar9 == 1) {
            puVar14[-1] = *(undefined4 *)(pbVar13 + 0x10);
            *puVar14 = *(undefined4 *)(pbVar13 + 0x14);
            puVar14[1] = *(undefined4 *)(pbVar13 + 0x18);
            puVar14[-5] = *(undefined4 *)pbVar13;
            puVar14[-4] = *(undefined4 *)(pbVar13 + 4);
            puVar14[-3] = *(undefined4 *)(pbVar13 + 8);
            puVar14[-2] = *(undefined4 *)(pbVar13 + 0xc);
          }
          iVar4 = iVar4 + 1;
          piVar9 = piVar9 + 0x12;
          puVar14 = puVar14 + 0x10;
          pbVar13 = pbVar13 + 0x1c;
        } while (iVar4 < *(int *)(iVar3 + 0x4c));
      }
    }
    if (*(int *)(param_1 + 0x98) != 0) {
      if (((*(int *)(__r_lerpmodels + 0x20) == 0) || (local_360 == local_35c)) || (local_360 == 0))
      {
        local_380 = (byte *)0x0;
        fStack_384 = 1.0;
      }
      else {
        local_380 = *(byte **)(param_1 + 0xac);
        fStack_384 = 1.0 - (float)local_380;
      }
      if (0.0 < *(float *)(param_1 + 0x88) == (*(float *)(param_1 + 0x88) == 0.0)) {
        fStack_364 = 0.0;
        local_358 = 0;
        pbStack_388 = (byte *)0x0;
        iVar4 = 2;
        if (NAN((float)local_380) != ((float)local_380 == 0.0)) {
          iVar4 = 1;
        }
      }
      else {
        fStack_364 = *(float *)(param_1 + 0x88);
        pbStack_388 = (byte *)(1.0 - fStack_364);
        if (NAN((float)local_380) == ((float)local_380 == 0.0)) {
          iVar4 = 3;
        }
        else {
          iVar4 = 2;
          local_360 = local_358;
          fStack_384 = fStack_364;
          local_380 = pbStack_388;
        }
        if (local_358 == 0) {
          iVar4 = iVar4 + -1;
        }
      }
      iVar8 = 0;
      puVar14 = (undefined4 *)(local_35c + 0x28);
      iVar5 = local_358 + 0x28;
      if (*(int *)(param_1 + 0x84) == 0) {
        if (iVar4 == 3) {
          iStack_374 = 0;
          if (0 < *(int *)(iVar3 + 0x4c)) {
            iVar4 = iVar5 - local_358;
            iStack_354 = local_360 - local_35c;
            iVar3 = local_358 - local_35c;
            local_358 = local_358 - local_360;
            pfVar15 = (float *)(puStack_36c + 0x14);
            pfVar11 = (float *)(iVar4 + 0x18 + local_360);
            pfVar10 = (float *)(iVar4 + 0x10 + local_35c);
            local_35c = iVar3;
            do {
              _SlerpQuaternion(pfVar11 + -6,pfVar10 + -4,fStack_384,&fStack_348);
              _SlerpQuaternion(iVar5,&fStack_348,fStack_364,pfVar15 + -5);
              pfVar15[-1] = fStack_364 *
                            ((float)local_380 * *(float *)(iStack_354 + (int)pfVar10) +
                            fStack_384 * *pfVar10) +
                            (float)pbStack_388 * *(float *)(local_35c + -0x1c + (int)(pfVar10 + 7));
              *pfVar15 = *(float *)(iVar5 + 0x14) * (float)pbStack_388 +
                         (pfVar11[-1] * (float)local_380 + pfVar10[1] * fStack_384) * fStack_364;
              iStack_374 = iStack_374 + 1;
              pfVar15[1] = (float)pbStack_388 * *(float *)(local_358 + -0x1c + (int)(pfVar11 + 7)) +
                           fStack_364 * (pfVar10[2] * fStack_384 + *pfVar11 * (float)local_380);
              pfVar15 = pfVar15 + 0x10;
              pfVar11 = pfVar11 + 7;
              pfVar10 = pfVar10 + 7;
              iVar5 = iVar5 + 0x1c;
            } while (iStack_374 < *(int *)(iStack_370 + 0x4c));
          }
        }
        else if (iVar4 == 2) {
          iVar4 = 0;
          if (0 < *(int *)(iVar3 + 0x4c)) {
            iStack_354 = local_35c - local_360;
            pfVar15 = (float *)(puStack_36c + 0x14);
            pfVar11 = (float *)((int)puVar14 + local_360 + (0x14 - local_35c));
            do {
              _SlerpQuaternion(pfVar11 + -5,puVar14,fStack_384,pfVar15 + -5);
              iVar4 = iVar4 + 1;
              pfVar15[-1] = (float)local_380 * pfVar11[-1] + fStack_384 * (float)puVar14[4];
              *pfVar15 = *pfVar11 * (float)local_380 +
                         *(float *)(iStack_354 + -0x1c + (int)(pfVar11 + 7)) * fStack_384;
              pfVar15[1] = (float)puVar14[6] * fStack_384 + (float)local_380 * pfVar11[1];
              pfVar15 = pfVar15 + 0x10;
              puVar14 = puVar14 + 7;
              pfVar11 = pfVar11 + 7;
            } while (iVar4 < *(int *)(iStack_370 + 0x4c));
          }
        }
        else if ((iVar4 == 1) && (0 < *(int *)(iVar3 + 0x4c))) {
          puVar6 = (undefined4 *)(puStack_36c + 0x14);
          do {
            iVar8 = iVar8 + 1;
            puVar6[-1] = puVar14[4];
            *puVar6 = puVar14[5];
            puVar6[1] = puVar14[6];
            puVar6[-5] = *puVar14;
            puVar6[-4] = puVar14[1];
            puVar6[-3] = puVar14[2];
            puVar6[-2] = puVar14[3];
            puVar6 = puVar6 + 0x10;
            puVar14 = puVar14 + 7;
          } while (iVar8 < *(int *)(iVar3 + 0x4c));
        }
      }
      else if (iVar4 == 3) {
        iStack_374 = 0;
        if (0 < *(int *)(iVar3 + 0x4c)) {
          iVar4 = iVar5 - local_358;
          pfVar15 = (float *)(iVar4 + 0x18 + local_360);
          pbStack_37c = (byte *)(piStack_34c + 1);
          iStack_354 = local_360 - local_35c;
          iVar3 = local_358 - local_35c;
          pfVar10 = (float *)(puStack_36c + 0x14);
          local_358 = local_358 - local_360;
          pfVar11 = (float *)(iVar4 + 0x10 + local_35c);
          fVar2 = fStack_384;
          local_35c = iVar3;
          do {
            if (*(int *)pbStack_37c != 1) {
              _SlerpQuaternion(pfVar15 + -6,pfVar11 + -4,fVar2,&fStack_348);
              _SlerpQuaternion(iVar5,&fStack_348,fStack_364,pfVar10 + -5);
              pfVar10[-1] = fStack_364 *
                            ((float)local_380 * *(float *)(iStack_354 + (int)pfVar11) +
                            fStack_384 * *pfVar11) +
                            (float)pbStack_388 * *(float *)(local_35c + (int)pfVar11);
              *pfVar10 = *(float *)(iVar5 + 0x14) * (float)pbStack_388 +
                         (pfVar15[-1] * (float)local_380 + pfVar11[1] * fStack_384) * fStack_364;
              pfVar10[1] = (float)pbStack_388 * *(float *)(local_358 + (int)pfVar15) +
                           fStack_364 * (pfVar11[2] * fStack_384 + *pfVar15 * (float)local_380);
              fVar2 = fStack_384;
            }
            pbStack_37c = pbStack_37c + 0x48;
            iStack_374 = iStack_374 + 1;
            pfVar10 = pfVar10 + 0x10;
            iVar5 = iVar5 + 0x1c;
            pfVar15 = pfVar15 + 7;
            pfVar11 = pfVar11 + 7;
          } while (iStack_374 < *(int *)(iStack_370 + 0x4c));
        }
      }
      else if (iVar4 == 2) {
        iVar3 = 0;
        if (0 < *(int *)(iStack_370 + 0x4c)) {
          pfVar15 = (float *)((int)puVar14 + local_360 + (0x14 - local_35c));
          pbStack_37c = (byte *)(piStack_34c + 1);
          pfVar11 = (float *)(puStack_36c + 0x14);
          iStack_354 = local_35c - local_360;
          fVar2 = fStack_384;
          do {
            if (*(int *)pbStack_37c != 1) {
              _SlerpQuaternion(pfVar15 + -5,puVar14,fVar2,pfVar11 + -5);
              pfVar11[-1] = (float)local_380 * pfVar15[-1] + fStack_384 * (float)puVar14[4];
              *pfVar11 = *pfVar15 * (float)local_380 +
                         *(float *)(iStack_354 + (int)pfVar15) * fStack_384;
              pfVar11[1] = (float)puVar14[6] * fStack_384 + (float)local_380 * pfVar15[1];
              fVar2 = fStack_384;
            }
            pbStack_37c = pbStack_37c + 0x48;
            iVar3 = iVar3 + 1;
            pfVar11 = pfVar11 + 0x10;
            puVar14 = puVar14 + 7;
            pfVar15 = pfVar15 + 7;
          } while (iVar3 < *(int *)(iStack_370 + 0x4c));
        }
      }
      else if ((iVar4 == 1) && (0 < *(int *)(iVar3 + 0x4c))) {
        puVar6 = (undefined4 *)(puStack_36c + 0x14);
        piVar9 = piStack_34c + 1;
        do {
          if (*piVar9 != 1) {
            puVar6[-1] = puVar14[4];
            *puVar6 = puVar14[5];
            puVar6[1] = puVar14[6];
            puVar6[-5] = *puVar14;
            puVar6[-4] = puVar14[1];
            puVar6[-3] = puVar14[2];
            puVar6[-2] = puVar14[3];
          }
          iVar8 = iVar8 + 1;
          piVar9 = piVar9 + 0x12;
          puVar6 = puVar6 + 0x10;
          puVar14 = puVar14 + 7;
        } while (iVar8 < *(int *)(iVar3 + 0x4c));
      }
    }
    iVar3 = 0;
    if (0 < *(int *)(iStack_370 + 0x4c)) {
      pfVar15 = (float *)(puStack_36c + 0x10);
      piVar9 = piStack_34c;
      do {
        iVar4 = *piVar9;
        if (iVar4 < 0) {
          iVar4 = *(int *)(iVar3 * 4 + 0x2000);
          if (iVar4 == 0) {
            afStack_320[iVar3] = 1.0;
          }
          else {
            afStack_320[iVar3] = *(float *)(param_1 + 0xf0 + iVar4 * 0x24);
            _QuatMult(pfVar15 + -4,param_1 + iVar4 * 0x24 + 0xe0,&fStack_348);
            pfVar15[-4] = fStack_348;
            *(undefined4 *)(iVar3 * 4 + 0x2000) = 0;
            pfVar15[-3] = fStack_344;
            pfVar15[-2] = fStack_340;
            pfVar15[-1] = fStack_33c;
          }
          _QuatToMat(pfVar15 + -4,pfVar15 + 3);
        }
        else {
          afStack_320[iVar3] = afStack_320[iVar4];
          pfVar11 = pfVar15 + -4;
          _QuatMult(pfVar11,puStack_36c + iVar4 * 0x40,&fStack_348);
          _MatrixTransformVector(pfVar15,puStack_36c + *piVar9 * 0x40 + 0x1c,&fStack_32c);
          *pfVar15 = *(float *)(puStack_36c + *piVar9 * 0x40 + 0x10) + fStack_32c;
          pfVar15[1] = *(float *)(puStack_36c + *piVar9 * 0x40 + 0x14) + fStack_328;
          iVar4 = *(int *)(iVar3 * 4 + 0x2000);
          pfVar15[2] = *(float *)(puStack_36c + *piVar9 * 0x40 + 0x18) + fStack_324;
          if (iVar4 == 0) {
            _ScaleQuatToMat(&fStack_348,pfVar15 + 3,afStack_320[iVar3]);
            *pfVar11 = fStack_348;
            pfVar15[-3] = fStack_344;
            pfVar15[-2] = fStack_340;
            pfVar15[-1] = fStack_33c;
          }
          else {
            afStack_320[iVar3] = *(float *)(param_1 + 0xf0 + iVar4 * 0x24) * afStack_320[iVar3];
            _QuatMult(&fStack_348,param_1 + iVar4 * 0x24 + 0xe0,pfVar11);
            _ScaleQuatToMat(pfVar11,pfVar15 + 3,afStack_320[iVar3]);
            *(undefined4 *)(iVar3 * 4 + 0x2000) = 0;
          }
        }
        iVar3 = iVar3 + 1;
        pfVar15 = pfVar15 + 0x10;
        piVar9 = piVar9 + 0x12;
      } while (iVar3 < *(int *)(iStack_370 + 0x4c));
    }
    puVar14 = (undefined4 *)(*(int *)(iStack_370 + 0x54) + iStack_370);
    iVar3 = *(int *)(param_3 + 0xa0) + param_3;
    if (0 < *(int *)(param_3 + 0x80)) {
      pbStack_388 = (byte *)(param_1 + 0xd0);
      pbVar12 = (byte *)(-0xd0 - param_1);
      pbStack_37c = pbVar12;
      do {
        if ((*pbStack_388 & 4) == 0) {
          iVar4 = (*pbStack_388 & 3) + *(int *)(param_1 + 0xb0);
          if ((*(int *)(param_1 + 0xb8) == 0) || ((*(uint *)(param_1 + 4) & 0x10000) != 0)) {
            iVar5 = *(int *)(param_1 + 0xb4);
            if ((iVar5 < 1) || (_DAT_0005dc04 <= iVar5)) {
              if (iVar4 < *(int *)(iVar3 + 0x150)) {
                iVar4 = *(int *)(*(int *)(iVar3 + 0x140 + iVar4 * 4) * 4 + 0x5bc04);
              }
              else {
                iVar4 = *(int *)(*(int *)(iVar3 + 0x140) * 4 + 0x5bc04);
              }
            }
            else {
              iVar4 = *(int *)(iVar5 * 4 + 0x5dc08);
              iVar4 = *(int *)(*(int *)(iVar4 + 0x44 +
                                       ((int)(pbStack_388 + (int)pbStack_37c) %
                                       *(int *)(iVar4 + 0x40)) * 4) + 0x40);
            }
          }
          else {
            iVar4 = _R_GetShaderByHandle(*(int *)(param_1 + 0xb8));
          }
          *puVar14 = 0xc;
          if (((((param_4 == 0) && (*(int *)(__r_shadows + 0x20) == 2)) && (fStack_378 == 0.0)) &&
              ((uVar1 = *(uint *)(param_1 + 4), (uVar1 & 4) == 0 && ((uVar1 & 0x800) != 0)))) &&
             (((uVar1 & 0x4000000) != 0 &&
              ((NAN(___real_40800000) || NAN(*(float *)(iVar4 + 0x4c))) !=
               (___real_40800000 == *(float *)(iVar4 + 0x4c)))))) {
            _R_AddDrawSurf(puVar14,__R_GetSkinByHandle,0,0);
          }
          if (((*(int *)(__r_shadows + 0x20) == 3) && (fStack_378 == 0.0)) &&
             (((*(uint *)(param_1 + 4) & 0x100000) != 0 &&
              (((*(uint *)(param_1 + 4) & 0x4000000) != 0 &&
               ((NAN(___real_40800000) || NAN(*(float *)(iVar4 + 0x4c))) !=
                (___real_40800000 == *(float *)(iVar4 + 0x4c)))))))) {
            _R_AddDrawSurf(puVar14,_DAT_00017cbc,0,0);
          }
          if (param_4 == 0) {
            if (((*pbStack_388 & 0x40) == 0) || (*(int *)(iVar3 + 0x150) < 2)) {
              _R_AddDrawSurf(puVar14,iVar4,fStack_378,0);
            }
            else {
              iVar4 = (*pbStack_388 & 2) + *(int *)(param_1 + 0xb0);
              _R_AddDrawSurf(puVar14,*(undefined4 *)
                                      (*(int *)(iVar3 + 0x140 + iVar4 * 4) * 4 + 0x5bc04),fStack_378
                             ,0);
              _R_AddDrawSurf(puVar14,*(undefined4 *)
                                      (*(int *)(iVar3 + 0x144 + iVar4 * 4) * 4 + 0x5bc04),fStack_378
                             ,0);
            }
          }
          pbVar12 = pbStack_37c;
          if ((*(int *)(param_1 + 0xb8) != 0) && ((*(uint *)(param_1 + 4) & 0x10000) != 0)) {
            uVar7 = _R_GetShaderByHandle(*(int *)(param_1 + 0xb8));
            _R_AddDrawSurf(puVar14,uVar7,fStack_378,0);
            pbVar12 = pbStack_37c;
          }
        }
        puVar14 = (undefined4 *)((int)puVar14 + puVar14[0x17]);
        pbStack_388 = pbStack_388 + 1;
        iVar3 = iVar3 + 0x15c;
      } while ((int)(pbVar12 + (int)pbStack_388) < *(int *)(param_3 + 0x80));
    }
    *(int *)(param_1 + 0x1b0) = param_3;
    *(int *)(param_1 + 0x1b4) = _TIKI_Skel_boneindex;
    _TIKI_Skel_boneindex = _TIKI_Skel_boneindex + *(int *)(iStack_370 + 0x4c);
    if (*(int *)(__r_showlod + 0x20) != 0) {
      fStack_338 = *(float *)(param_1 + 0x48);
      fStack_334 = *(float *)(param_1 + 0x4c);
      fStack_330 = *(float *)(param_1 + 0x50) + (float)___real_4059000000000000;
      _R_CountTikiLodTris(param_1,*(undefined4 *)(param_1 + 0x200),&pbStack_388,&fStack_378,1);
      fVar2 = (float)(int)fStack_378;
      if ((int)fStack_378 < 10) {
        fVar2 = fVar2 / (float)___real_4024000000000000;
        uVar7 = 1;
      }
      else if ((int)fStack_378 < 100) {
        fVar2 = fVar2 / (float)___real_4059000000000000;
        uVar7 = 2;
      }
      else if ((int)fStack_378 < 1000) {
        fVar2 = fVar2 / (float)___real_408f400000000000;
        uVar7 = 3;
      }
      else {
        fVar2 = fVar2 / (float)___real_40c3880000000000;
        uVar7 = 4;
      }
      pbStack_388 = (byte *)(fVar2 + (float)(int)pbStack_388);
      pbStack_37c = (byte *)(1.0 / *(float *)(param_1 + 0x200));
      _R_DrawDebugNumber(&fStack_338,pbStack_388,pbStack_37c,0x3f800000,0x3f800000,0,uVar7);
    }
    return;
  }
  (*__ri)(1,s_R_AddSkelSurfaces__too_many_skel,param_2);
  return;
}



// ===========================================
// Function: _R_AddSkelSurfaces @ 0001514a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddSkelSurfaces(int param_1,undefined4 param_2,int param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  byte *pbVar12;
  int *piVar13;
  float *pfVar14;
  byte *pbVar15;
  undefined4 *puVar16;
  float10 fVar17;
  byte *pbStack_438;
  float fStack_434;
  float fStack_430;
  byte *local_42c;
  undefined *puStack_428;
  float fStack_424;
  int *piStack_420;
  int local_41c;
  byte *local_418;
  byte *pbStack_414;
  int local_410;
  int local_40c;
  float fStack_408;
  float fStack_404;
  float fStack_400;
  float fStack_3fc;
  float fStack_3f8;
  float fStack_3f4;
  float fStack_3f0;
  float fStack_3ec;
  float fStack_3e8;
  float fStack_3e4;
  float fStack_3e0;
  float fStack_3b8;
  float fStack_3b4;
  float fStack_3b0;
  undefined1 auStack_3ac [16];
  float fStack_39c;
  float fStack_398;
  float fStack_394;
  float fStack_36c;
  float fStack_368;
  float fStack_364;
  undefined1 auStack_360 [16];
  float fStack_350;
  float fStack_34c;
  float fStack_348;
  float afStack_320 [200];
  
  pbVar15 = (byte *)0x0;
  pbVar12 = (byte *)0x0;
  local_418 = (byte *)0x0;
  local_42c = (byte *)0x0;
  local_410 = 0;
  local_40c = 0;
  local_41c = 0;
  if ((*(int *)(param_1 + 0x84) == 0) && (*(int *)(param_1 + 0x98) == 0)) {
    (*__ri)(1,s_R_AddSkelSurfaces__model___s__wi,param_2);
    return;
  }
  iVar7 = _TIKI_GetSkel(*(undefined4 *)(param_3 + 0xe4));
  if (iVar7 == 0) {
    (*__ri)(1,s_R_AddSkelSurfaces__couldn_t_get_,param_2);
    return;
  }
  if (*(int *)(iVar7 + 4) != 2) {
    if (4000 < *(int *)(iVar7 + 0x4c) + _TIKI_Skel_boneindex) {
      (*__ri)(1,s_R_AddSkelSurfaces__too_many_skel,param_2);
      return;
    }
    __tiki_scale = *(float *)(param_3 + 0xa4) * *(float *)(param_1 + 0x60);
    fStack_430 = 0.0;
    _tiki_localorigin = __tiki_scale * *(float *)(param_3 + 0xbc);
    _DAT_00008324 = *(float *)(param_3 + 0xc0) * __tiki_scale;
    _DAT_00008328 = __tiki_scale * *(float *)(param_3 + 0xc4);
    if (*(int *)(param_1 + 0x84) != 0) {
      pbVar15 = (byte *)_R_ValidateSkelFrame(param_2,param_3,param_1 + 0x54,param_1 + 0x5e);
      if (pbVar15 == (byte *)0x0) {
        return;
      }
      local_418 = pbVar15;
      pbVar12 = (byte *)_R_ValidateSkelFrame(param_2,param_3,param_1 + 0x58,param_1 + 0x5c);
      local_42c = pbVar12;
      iVar8 = _R_CullSkelModel(pbVar12);
      if (iVar8 == 2) {
        return;
      }
      fStack_430 = *(float *)(pbVar15 + 0x18);
      *(byte **)(param_1 + 0x1a8) = pbVar12;
      fStack_430 = fStack_430 * __tiki_scale;
      *(byte **)(param_1 + 0x1ac) = pbVar15;
    }
    if (*(int *)(param_1 + 0x98) != 0) {
      iVar8 = _R_ValidateSkelFrame(param_2,param_3,param_1 + 0x68,param_1 + 0x70);
      if (iVar8 == 0) {
        return;
      }
      local_410 = iVar8;
      iVar9 = _R_ValidateSkelFrame(param_2,param_3,param_1 + 0x6c,param_1 + 0x72);
      local_40c = iVar9;
      local_41c = _R_ValidateSkelFrame(param_2,param_3,param_1 + 0x90,param_1 + 0x94);
      pbVar12 = local_42c;
      pbVar15 = local_418;
      if (*(int *)(param_1 + 0x84) == 0) {
        iVar10 = _R_CullSkelModel(iVar9);
        if (iVar10 == 2) {
          return;
        }
        fStack_430 = *(float *)(iVar8 + 0x18);
        *(int *)(param_1 + 0x1a8) = iVar9;
        fStack_430 = fStack_430 * __tiki_scale;
        *(int *)(param_1 + 0x1ac) = iVar8;
        pbVar12 = local_42c;
        pbVar15 = local_418;
      }
    }
    fStack_3b8 = *(float *)(param_1 + 0x48) + _tiki_localorigin;
    fStack_3b4 = *(float *)(param_1 + 0x4c) + _DAT_00008324;
    fStack_3b0 = *(float *)(param_1 + 0x50) + _DAT_00008328;
    if (_DAT_000184b0 == 0) {
      fVar17 = (float10)_R_TikiCalcLod(&fStack_3b8,param_3,fStack_430);
      *(float *)(param_1 + 0x200) = (float)fVar17;
    }
    else {
      fVar17 = (float10)_R_TikiCalcLod(&fStack_3b8,param_3,fStack_430);
      *(float *)(param_1 + 0x204) = (float)fVar17;
    }
    fStack_430 = (float)_R_CalcFogNum(&fStack_3b8,fStack_430);
    if (*(int *)(param_1 + 100) != 0) {
      if (-1 < *(int *)(param_1 + 0xf4)) {
        (&`R_AddSkelSurfaces'::__l2::modifier)[*(int *)(param_1 + 0xf4)] = 1;
      }
      if (-1 < *(int *)(param_1 + 0x118)) {
        (&`R_AddSkelSurfaces'::__l2::modifier)[*(int *)(param_1 + 0x118)] = 2;
      }
      if (-1 < *(int *)(param_1 + 0x13c)) {
        (&`R_AddSkelSurfaces'::__l2::modifier)[*(int *)(param_1 + 0x13c)] = 3;
      }
      if (-1 < *(int *)(param_1 + 0x160)) {
        (&`R_AddSkelSurfaces'::__l2::modifier)[*(int *)(param_1 + 0x160)] = 4;
      }
      if (-1 < *(int *)(param_1 + 0x184)) {
        (&`R_AddSkelSurfaces'::__l2::modifier)[*(int *)(param_1 + 0x184)] = 5;
      }
    }
    puStack_428 = &_TIKI_Skel_Bones + _TIKI_Skel_boneindex * 0x40;
    piStack_420 = (int *)(*(int *)(iVar7 + 0x50) + iVar7);
    if (*(int *)(param_1 + 0x84) != 0) {
      if (((*(int *)(__r_lerpmodels + 0x20) == 0) || (pbVar12 == pbVar15)) ||
         (pbVar12 == (byte *)0x0)) {
        pbStack_414 = (byte *)0x0;
        fStack_434 = 1.0;
      }
      else {
        pbStack_414 = *(byte **)(param_1 + 0xa8);
        fStack_434 = 1.0 - (float)pbStack_414;
      }
      fVar2 = *(float *)(param_1 + 0x74);
      if (NAN(fVar2) || 0.0 < fVar2 == (fVar2 == 0.0)) {
        fStack_424 = 0.0;
        pbVar12 = (byte *)0x0;
        pbStack_438 = (byte *)0x0;
        iVar8 = 2;
        if (NAN((float)pbStack_414) != ((float)pbStack_414 == 0.0)) {
          iVar8 = 1;
        }
      }
      else {
        pbVar12 = (byte *)_R_ValidateSkelFrame(param_2,param_3,param_1 + 0x7c,param_1 + 0x80);
        fStack_424 = *(float *)(param_1 + 0x74);
        pbStack_438 = (byte *)(1.0 - fStack_424);
        if (NAN((float)pbStack_414) == ((float)pbStack_414 == 0.0)) {
          iVar8 = 3;
        }
        else {
          iVar8 = 2;
          fStack_434 = fStack_424;
          local_42c = pbVar12;
          pbStack_414 = pbStack_438;
        }
        if (pbVar12 == (byte *)0x0) {
          iVar8 = iVar8 + -1;
        }
      }
      pbVar5 = local_418;
      pbVar15 = local_42c;
      if (*(int *)(param_1 + 0x98) == 0) {
        if (iVar8 == 3) {
          if (0 < *(int *)(iVar7 + 0x4c)) {
            iVar8 = 0;
            piVar13 = piStack_420;
            pfVar14 = (float *)(puStack_428 + 0x14);
            do {
              _R_GetBone(iVar8,local_42c,piVar13,auStack_3ac);
              _R_GetBone(iVar8,local_418,piVar13,&fStack_3f8);
              _R_GetBone(iVar8,pbVar12,piVar13,auStack_360);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,&fStack_408);
              _SlerpQuaternion(auStack_360,&fStack_408,fStack_424,pfVar14 + -5);
              pfVar14[-1] = fStack_424 * (fStack_434 * fStack_3e8 + (float)pbStack_414 * fStack_39c)
                            + (float)pbStack_438 * fStack_350;
              *pfVar14 = fStack_34c * (float)pbStack_438 +
                         (fStack_398 * (float)pbStack_414 + fStack_3e4 * fStack_434) * fStack_424;
              iVar8 = iVar8 + 1;
              piVar13 = piVar13 + 0x12;
              pfVar14[1] = (fStack_3e0 * fStack_434 + fStack_394 * (float)pbStack_414) * fStack_424
                           + fStack_348 * (float)pbStack_438;
              pfVar14 = pfVar14 + 0x10;
            } while (iVar8 < *(int *)(iVar7 + 0x4c));
          }
        }
        else if (iVar8 == 2) {
          iVar8 = 0;
          if (0 < *(int *)(iVar7 + 0x4c)) {
            piVar13 = piStack_420;
            pfVar14 = (float *)(puStack_428 + 0x14);
            do {
              _R_GetBone(iVar8,pbVar15,piVar13,auStack_3ac);
              _R_GetBone(iVar8,local_418,piVar13,&fStack_3f8);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,pfVar14 + -5);
              iVar8 = iVar8 + 1;
              piVar13 = piVar13 + 0x12;
              pfVar14[-1] = fStack_434 * fStack_3e8 + (float)pbStack_414 * fStack_39c;
              *pfVar14 = fStack_398 * (float)pbStack_414 + fStack_3e4 * fStack_434;
              pfVar14[1] = fStack_434 * fStack_3e0 + fStack_394 * (float)pbStack_414;
              pfVar14 = pfVar14 + 0x10;
            } while (iVar8 < *(int *)(iVar7 + 0x4c));
          }
        }
        else if ((iVar8 == 1) && (iVar8 = 0, 0 < *(int *)(iVar7 + 0x4c))) {
          piVar13 = piStack_420;
          pfVar14 = (float *)(puStack_428 + 0x14);
          do {
            _R_GetBone(iVar8,pbVar5,piVar13,&fStack_3f8);
            pfVar14[-1] = fStack_3e8;
            iVar8 = iVar8 + 1;
            *pfVar14 = fStack_3e4;
            piVar13 = piVar13 + 0x12;
            pfVar14[1] = fStack_3e0;
            pfVar14[-5] = fStack_3f8;
            pfVar14[-4] = fStack_3f4;
            pfVar14[-3] = fStack_3f0;
            pfVar14[-2] = fStack_3ec;
            pfVar14 = pfVar14 + 0x10;
          } while (iVar8 < *(int *)(iVar7 + 0x4c));
        }
      }
      else if (iVar8 == 3) {
        iVar8 = 0;
        if (0 < *(int *)(iVar7 + 0x4c)) {
          pfVar14 = (float *)(puStack_428 + 0x14);
          piVar13 = piStack_420;
          do {
            if (piVar13[1] == 1) {
              _R_GetBone(iVar8,local_42c,piVar13,auStack_3ac);
              _R_GetBone(iVar8,local_418,piVar13,&fStack_3f8);
              _R_GetBone(iVar8,pbVar12,piVar13,auStack_360);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,&fStack_408);
              _SlerpQuaternion(auStack_360,&fStack_408,fStack_424,pfVar14 + -5);
              pfVar14[-1] = fStack_424 * (fStack_434 * fStack_3e8 + (float)pbStack_414 * fStack_39c)
                            + (float)pbStack_438 * fStack_350;
              *pfVar14 = fStack_34c * (float)pbStack_438 +
                         (fStack_398 * (float)pbStack_414 + fStack_3e4 * fStack_434) * fStack_424;
              pfVar14[1] = (fStack_3e0 * fStack_434 + fStack_394 * (float)pbStack_414) * fStack_424
                           + fStack_348 * (float)pbStack_438;
            }
            iVar8 = iVar8 + 1;
            piVar13 = piVar13 + 0x12;
            pfVar14 = pfVar14 + 0x10;
          } while (iVar8 < *(int *)(iVar7 + 0x4c));
        }
      }
      else if (iVar8 == 2) {
        iVar8 = 0;
        if (0 < *(int *)(iVar7 + 0x4c)) {
          pfVar14 = (float *)(puStack_428 + 0x14);
          piVar13 = piStack_420;
          do {
            if (piVar13[1] == 1) {
              _R_GetBone(iVar8,local_42c,piVar13,auStack_3ac);
              _R_GetBone(iVar8,local_418,piVar13,&fStack_3f8);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,pfVar14 + -5);
              pfVar14[-1] = fStack_434 * fStack_3e8 + (float)pbStack_414 * fStack_39c;
              *pfVar14 = fStack_398 * (float)pbStack_414 + fStack_3e4 * fStack_434;
              pfVar14[1] = fStack_434 * fStack_3e0 + fStack_394 * (float)pbStack_414;
            }
            iVar8 = iVar8 + 1;
            piVar13 = piVar13 + 0x12;
            pfVar14 = pfVar14 + 0x10;
          } while (iVar8 < *(int *)(iVar7 + 0x4c));
        }
      }
      else if ((iVar8 == 1) && (iVar8 = 0, 0 < *(int *)(iVar7 + 0x4c))) {
        pfVar14 = (float *)(puStack_428 + 0x14);
        piVar13 = piStack_420;
        do {
          if (piVar13[1] == 1) {
            _R_GetBone(iVar8,local_418,piVar13,&fStack_3f8);
            pfVar14[-1] = fStack_3e8;
            *pfVar14 = fStack_3e4;
            pfVar14[1] = fStack_3e0;
            pfVar14[-5] = fStack_3f8;
            pfVar14[-4] = fStack_3f4;
            pfVar14[-3] = fStack_3f0;
            pfVar14[-2] = fStack_3ec;
          }
          iVar8 = iVar8 + 1;
          piVar13 = piVar13 + 0x12;
          pfVar14 = pfVar14 + 0x10;
        } while (iVar8 < *(int *)(iVar7 + 0x4c));
      }
    }
    iVar8 = local_410;
    if (*(int *)(param_1 + 0x98) != 0) {
      iVar9 = 0;
      if (((*(int *)(__r_lerpmodels + 0x20) == 0) || (local_40c == local_410)) || (local_40c == 0))
      {
        local_42c = (byte *)0x0;
        fStack_434 = 1.0;
      }
      else {
        local_42c = *(byte **)(param_1 + 0xac);
        fStack_434 = 1.0 - (float)local_42c;
      }
      if (0.0 < *(float *)(param_1 + 0x88) == (*(float *)(param_1 + 0x88) == 0.0)) {
        fStack_424 = 0.0;
        local_41c = 0;
        pbStack_438 = (byte *)0x0;
        iVar10 = 2;
        if (NAN((float)local_42c) != ((float)local_42c == 0.0)) {
          iVar10 = 1;
        }
      }
      else {
        fStack_424 = *(float *)(param_1 + 0x88);
        pbStack_438 = (byte *)(1.0 - fStack_424);
        if (NAN((float)local_42c) == ((float)local_42c == 0.0)) {
          iVar10 = 3;
        }
        else {
          iVar10 = 2;
          local_40c = local_41c;
          fStack_434 = fStack_424;
          local_42c = pbStack_438;
        }
        if (local_41c == 0) {
          iVar10 = iVar10 + -1;
        }
      }
      iVar6 = local_40c;
      iVar4 = local_41c;
      if (*(int *)(param_1 + 0x84) == 0) {
        if (iVar10 == 3) {
          if (0 < *(int *)(iVar7 + 0x4c)) {
            pfVar14 = (float *)(puStack_428 + 0x14);
            piVar13 = piStack_420;
            do {
              _R_GetBone(iVar9,local_40c,piVar13,auStack_3ac);
              _R_GetBone(iVar9,local_410,piVar13,&fStack_3f8);
              _R_GetBone(iVar9,iVar4,piVar13,auStack_360);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,&fStack_408);
              _SlerpQuaternion(auStack_360,&fStack_408,fStack_424,pfVar14 + -5);
              iVar9 = iVar9 + 1;
              piVar13 = piVar13 + 0x12;
              pfVar14[-1] = (float)pbStack_438 * fStack_350 +
                            fStack_424 * ((float)local_42c * fStack_39c + fStack_434 * fStack_3e8);
              *pfVar14 = (float)pbStack_438 * fStack_34c +
                         ((float)local_42c * fStack_398 + fStack_434 * fStack_3e4) * fStack_424;
              pfVar14[1] = (float)pbStack_438 * fStack_348 +
                           (fStack_3e0 * fStack_434 + fStack_394 * (float)local_42c) * fStack_424;
              pfVar14 = pfVar14 + 0x10;
            } while (iVar9 < *(int *)(iVar7 + 0x4c));
          }
        }
        else if (iVar10 == 2) {
          if (0 < *(int *)(iVar7 + 0x4c)) {
            piVar13 = piStack_420;
            pfVar14 = (float *)(puStack_428 + 0x14);
            do {
              _R_GetBone(iVar9,iVar6,piVar13,auStack_3ac);
              _R_GetBone(iVar9,local_410,piVar13,&fStack_3f8);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,pfVar14 + -5);
              iVar9 = iVar9 + 1;
              piVar13 = piVar13 + 0x12;
              pfVar14[-1] = (float)local_42c * fStack_39c + fStack_434 * fStack_3e8;
              *pfVar14 = (float)local_42c * fStack_398 + fStack_434 * fStack_3e4;
              pfVar14[1] = (float)local_42c * fStack_394 + fStack_3e0 * fStack_434;
              pfVar14 = pfVar14 + 0x10;
            } while (iVar9 < *(int *)(iVar7 + 0x4c));
          }
        }
        else if ((iVar10 == 1) && (iVar9 = 0, 0 < *(int *)(iVar7 + 0x4c))) {
          piVar13 = piStack_420;
          pfVar14 = (float *)(puStack_428 + 0x14);
          do {
            _R_GetBone(iVar9,iVar8,piVar13,&fStack_3f8);
            pfVar14[-1] = fStack_3e8;
            iVar9 = iVar9 + 1;
            *pfVar14 = fStack_3e4;
            piVar13 = piVar13 + 0x12;
            pfVar14[1] = fStack_3e0;
            pfVar14[-5] = fStack_3f8;
            pfVar14[-4] = fStack_3f4;
            pfVar14[-3] = fStack_3f0;
            pfVar14[-2] = fStack_3ec;
            pfVar14 = pfVar14 + 0x10;
          } while (iVar9 < *(int *)(iVar7 + 0x4c));
        }
      }
      else if (iVar10 == 3) {
        if (0 < *(int *)(iVar7 + 0x4c)) {
          pfVar14 = (float *)(puStack_428 + 0x14);
          piVar13 = piStack_420;
          do {
            if (piVar13[1] != 1) {
              _R_GetBone(iVar9,local_40c,piVar13,auStack_3ac);
              _R_GetBone(iVar9,local_410,piVar13,&fStack_3f8);
              _R_GetBone(iVar9,iVar4,piVar13,auStack_360);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,&fStack_408);
              _SlerpQuaternion(auStack_360,&fStack_408,fStack_424,pfVar14 + -5);
              pfVar14[-1] = (float)pbStack_438 * fStack_350 +
                            fStack_424 * ((float)local_42c * fStack_39c + fStack_434 * fStack_3e8);
              *pfVar14 = (float)pbStack_438 * fStack_34c +
                         ((float)local_42c * fStack_398 + fStack_434 * fStack_3e4) * fStack_424;
              pfVar14[1] = (float)pbStack_438 * fStack_348 +
                           (fStack_3e0 * fStack_434 + fStack_394 * (float)local_42c) * fStack_424;
            }
            iVar9 = iVar9 + 1;
            piVar13 = piVar13 + 0x12;
            pfVar14 = pfVar14 + 0x10;
          } while (iVar9 < *(int *)(iVar7 + 0x4c));
        }
      }
      else if (iVar10 == 2) {
        if (0 < *(int *)(iVar7 + 0x4c)) {
          pfVar14 = (float *)(puStack_428 + 0x14);
          piVar13 = piStack_420;
          do {
            if (piVar13[1] != 1) {
              _R_GetBone(iVar9,local_40c,piVar13,auStack_3ac);
              _R_GetBone(iVar9,local_410,piVar13,&fStack_3f8);
              _SlerpQuaternion(auStack_3ac,&fStack_3f8,fStack_434,pfVar14 + -5);
              pfVar14[-1] = (float)local_42c * fStack_39c + fStack_434 * fStack_3e8;
              *pfVar14 = (float)local_42c * fStack_398 + fStack_434 * fStack_3e4;
              pfVar14[1] = (float)local_42c * fStack_394 + fStack_3e0 * fStack_434;
            }
            iVar9 = iVar9 + 1;
            piVar13 = piVar13 + 0x12;
            pfVar14 = pfVar14 + 0x10;
          } while (iVar9 < *(int *)(iVar7 + 0x4c));
        }
      }
      else if ((iVar10 == 1) && (iVar8 = 0, 0 < *(int *)(iVar7 + 0x4c))) {
        pfVar14 = (float *)(puStack_428 + 0x14);
        piVar13 = piStack_420;
        do {
          if (piVar13[1] != 1) {
            _R_GetBone(iVar8,local_410,piVar13,&fStack_3f8);
            pfVar14[-1] = fStack_3e8;
            *pfVar14 = fStack_3e4;
            pfVar14[1] = fStack_3e0;
            pfVar14[-5] = fStack_3f8;
            pfVar14[-4] = fStack_3f4;
            pfVar14[-3] = fStack_3f0;
            pfVar14[-2] = fStack_3ec;
          }
          iVar8 = iVar8 + 1;
          piVar13 = piVar13 + 0x12;
          pfVar14 = pfVar14 + 0x10;
        } while (iVar8 < *(int *)(iVar7 + 0x4c));
      }
    }
    iVar8 = 0;
    if (0 < *(int *)(iVar7 + 0x4c)) {
      pfVar14 = (float *)(puStack_428 + 0x10);
      piVar13 = piStack_420;
      do {
        iVar9 = *piVar13;
        if (iVar9 < 0) {
          iVar9 = (&`R_AddSkelSurfaces'::__l2::modifier)[iVar8];
          if (iVar9 == 0) {
            afStack_320[iVar8] = 1.0;
          }
          else {
            afStack_320[iVar8] = *(float *)(param_1 + 0xf0 + iVar9 * 0x24);
            _QuatMult(pfVar14 + -4,param_1 + iVar9 * 0x24 + 0xe0,&fStack_408);
            pfVar14[-4] = fStack_408;
            (&`R_AddSkelSurfaces'::__l2::modifier)[iVar8] = 0;
            pfVar14[-3] = fStack_404;
            pfVar14[-2] = fStack_400;
            pfVar14[-1] = fStack_3fc;
          }
          _QuatToMat(pfVar14 + -4,pfVar14 + 3);
        }
        else {
          afStack_320[iVar8] = afStack_320[iVar9];
          pfVar1 = pfVar14 + -4;
          _QuatMult(pfVar1,puStack_428 + iVar9 * 0x40,&fStack_408);
          _MatrixTransformVector(pfVar14,puStack_428 + *piVar13 * 0x40 + 0x1c,&fStack_36c);
          *pfVar14 = *(float *)(puStack_428 + *piVar13 * 0x40 + 0x10) + fStack_36c;
          pfVar14[1] = *(float *)(puStack_428 + *piVar13 * 0x40 + 0x14) + fStack_368;
          iVar9 = (&`R_AddSkelSurfaces'::__l2::modifier)[iVar8];
          pfVar14[2] = *(float *)(puStack_428 + *piVar13 * 0x40 + 0x18) + fStack_364;
          if (iVar9 == 0) {
            _ScaleQuatToMat(&fStack_408,pfVar14 + 3,afStack_320[iVar8]);
            *pfVar1 = fStack_408;
            pfVar14[-3] = fStack_404;
            pfVar14[-2] = fStack_400;
            pfVar14[-1] = fStack_3fc;
          }
          else {
            afStack_320[iVar8] = *(float *)(param_1 + 0xf0 + iVar9 * 0x24) * afStack_320[iVar8];
            _QuatMult(&fStack_408,param_1 + iVar9 * 0x24 + 0xe0,pfVar1);
            _ScaleQuatToMat(pfVar1,pfVar14 + 3,afStack_320[iVar8]);
            (&`R_AddSkelSurfaces'::__l2::modifier)[iVar8] = 0;
          }
        }
        iVar8 = iVar8 + 1;
        pfVar14 = pfVar14 + 0x10;
        piVar13 = piVar13 + 0x12;
      } while (iVar8 < *(int *)(iVar7 + 0x4c));
    }
    puVar16 = (undefined4 *)(*(int *)(iVar7 + 0x54) + iVar7);
    iVar8 = *(int *)(param_3 + 0xa0) + param_3;
    if (0 < *(int *)(param_3 + 0x80)) {
      pbStack_438 = (byte *)(param_1 + 0xd0);
      iVar9 = -0xd0 - param_1;
      local_41c = iVar9;
      do {
        if ((*pbStack_438 & 4) == 0) {
          iVar9 = (*pbStack_438 & 3) + *(int *)(param_1 + 0xb0);
          if ((*(int *)(param_1 + 0xb8) == 0) || ((*(uint *)(param_1 + 4) & 0x10000) != 0)) {
            iVar10 = *(int *)(param_1 + 0xb4);
            if ((iVar10 < 1) || (_DAT_0005dc04 <= iVar10)) {
              if (iVar9 < *(int *)(iVar8 + 0x150)) {
                iVar9 = *(int *)(*(int *)(iVar8 + 0x140 + iVar9 * 4) * 4 + 0x5bc04);
              }
              else {
                iVar9 = *(int *)(*(int *)(iVar8 + 0x140) * 4 + 0x5bc04);
              }
            }
            else {
              iVar9 = *(int *)(iVar10 * 4 + 0x5dc08);
              iVar9 = *(int *)(*(int *)(iVar9 + 0x44 +
                                       ((int)(pbStack_438 + local_41c) % *(int *)(iVar9 + 0x40)) * 4
                                       ) + 0x40);
            }
          }
          else {
            iVar9 = _R_GetShaderByHandle(*(int *)(param_1 + 0xb8));
          }
          *puVar16 = 0xc;
          if (((((param_4 == 0) && (*(int *)(__r_shadows + 0x20) == 2)) && (fStack_430 == 0.0)) &&
              ((uVar3 = *(uint *)(param_1 + 4), (uVar3 & 4) == 0 && ((uVar3 & 0x800) != 0)))) &&
             (((uVar3 & 0x4000000) != 0 &&
              ((NAN(___real_40800000) || NAN(*(float *)(iVar9 + 0x4c))) !=
               (___real_40800000 == *(float *)(iVar9 + 0x4c)))))) {
            _R_AddDrawSurf(puVar16,__R_GetSkinByHandle,0,0);
          }
          if (((*(int *)(__r_shadows + 0x20) == 3) && (fStack_430 == 0.0)) &&
             (((*(uint *)(param_1 + 4) & 0x100000) != 0 &&
              (((*(uint *)(param_1 + 4) & 0x4000000) != 0 &&
               ((NAN(___real_40800000) || NAN(*(float *)(iVar9 + 0x4c))) !=
                (___real_40800000 == *(float *)(iVar9 + 0x4c)))))))) {
            _R_AddDrawSurf(puVar16,_DAT_00017cbc,0,0);
          }
          if (param_4 == 0) {
            if (((*pbStack_438 & 0x40) == 0) || (*(int *)(iVar8 + 0x150) < 2)) {
              _R_AddDrawSurf(puVar16,iVar9,fStack_430,0);
            }
            else {
              iVar9 = (*pbStack_438 & 2) + *(int *)(param_1 + 0xb0);
              _R_AddDrawSurf(puVar16,*(undefined4 *)
                                      (*(int *)(iVar8 + 0x140 + iVar9 * 4) * 4 + 0x5bc04),fStack_430
                             ,0);
              _R_AddDrawSurf(puVar16,*(undefined4 *)
                                      (*(int *)(iVar8 + 0x144 + iVar9 * 4) * 4 + 0x5bc04),fStack_430
                             ,0);
            }
          }
          iVar9 = local_41c;
          if ((*(int *)(param_1 + 0xb8) != 0) && ((*(uint *)(param_1 + 4) & 0x10000) != 0)) {
            uVar11 = _R_GetShaderByHandle(*(int *)(param_1 + 0xb8));
            _R_AddDrawSurf(puVar16,uVar11,fStack_430,0);
            iVar9 = local_41c;
          }
        }
        puVar16 = (undefined4 *)((int)puVar16 + puVar16[0x17]);
        pbStack_438 = pbStack_438 + 1;
        iVar8 = iVar8 + 0x15c;
      } while ((int)(pbStack_438 + iVar9) < *(int *)(param_3 + 0x80));
    }
    *(int *)(param_1 + 0x1b0) = param_3;
    *(int *)(param_1 + 0x1b4) = _TIKI_Skel_boneindex;
    _TIKI_Skel_boneindex = _TIKI_Skel_boneindex + *(int *)(iVar7 + 0x4c);
    if (*(int *)(__r_showlod + 0x20) != 0) {
      fStack_3b8 = *(float *)(param_1 + 0x48);
      fStack_3b4 = *(float *)(param_1 + 0x4c);
      fStack_3b0 = *(float *)(param_1 + 0x50) + (float)___real_4059000000000000;
      _R_CountTikiLodTris(param_1,*(undefined4 *)(param_1 + 0x200),&pbStack_438,&fStack_430,1);
      fVar2 = (float)(int)fStack_430;
      if ((int)fStack_430 < 10) {
        fVar2 = fVar2 / (float)___real_4024000000000000;
        uVar11 = 1;
      }
      else if ((int)fStack_430 < 100) {
        fVar2 = fVar2 / (float)___real_4059000000000000;
        uVar11 = 2;
      }
      else if ((int)fStack_430 < 1000) {
        fVar2 = fVar2 / (float)___real_408f400000000000;
        uVar11 = 3;
      }
      else {
        fVar2 = fVar2 / (float)___real_40c3880000000000;
        uVar11 = 4;
      }
      pbStack_438 = (byte *)(fVar2 + (float)(int)pbStack_438);
      fStack_430 = 1.0 / *(float *)(param_1 + 0x200);
      _R_DrawDebugNumber(&fStack_3b8,pbStack_438,fStack_430,0x3f800000,0x3f800000,0,uVar11);
    }
    return;
  }
  _R_AddSkelSurfaces_V2(param_1,param_2,param_3,param_4);
  return;
}



// ===========================================
// Function: _R_AddTikiSurfaces @ 000165de
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddTikiSurfaces(float param_1)

{
  short sVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  float10 fVar12;
  byte *pbStack_24;
  int local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar4 = (int)param_1;
  if (((*(byte *)((int)param_1 + 4) & 1) == 0) || (local_20 = 1, _DAT_000184b0 != 0)) {
    local_20 = 0;
  }
  iVar6 = _R_GetModelByHandle(*(undefined4 *)((int)param_1 + 0xc));
  iVar7 = (*_DAT_00017d48)(*(undefined4 *)(iVar6 + 0x60));
  iStack_14 = iVar7;
  if (iVar7 == 0) {
    (*__ri)(1,s_R_AddTikiSurfaces__couldn_t_get_,iVar6);
    return;
  }
  if (-1 < *(int *)(iVar7 + 0xe4)) {
    _R_AddSkelSurfaces(iVar4,iVar6,iVar7,local_20);
    return;
  }
  iVar8 = *(int *)(iVar4 + 0x54);
  if ((*(int *)(iVar7 + 0x88) <= iVar8) || (iVar8 < 0)) {
    (*__ri)(1,s_R_AddTikiSurfaces__no_such_anim_,iVar8,iVar6);
    *(undefined4 *)(iVar4 + 0x54) = 0;
    *(undefined2 *)(iVar4 + 0x5e) = 0;
  }
  iVar8 = _TIKI_GetAnim(*(undefined4 *)
                         (*(int *)(iVar7 + 0x168 + *(int *)(iVar4 + 0x54) * 4) + 0xb8 + iVar7));
  if (iVar8 == 0) {
    uVar10 = *(undefined4 *)(iVar4 + 0x54);
  }
  else {
    sVar1 = *(short *)(iVar4 + 0x5e);
    if ((*(int *)(iVar8 + 0x48) <= (int)sVar1) || (sVar1 < 0)) {
      (*__ri)(1,s_R_AddTikiSurfaces__no_such_frame,(int)sVar1,*(undefined4 *)(iVar4 + 0x54),iVar6);
      *(undefined2 *)(iVar4 + 0x5e) = 0;
    }
    _newFrame = *(int *)(iVar8 + 100) + *(short *)(iVar4 + 0x5e) * 0x44 + iVar8;
    if ((*(int *)(iVar7 + 0x88) <= *(int *)(iVar4 + 0x58)) || (*(int *)(iVar4 + 0x58) < 0)) {
      (*__ri)(1,s_R_AddTikiSurfaces__no_such_oldan,*(undefined4 *)(iVar4 + 0x54),iVar6);
      *(undefined4 *)(iVar4 + 0x58) = 0;
      *(undefined2 *)(iVar4 + 0x5c) = 0;
    }
    iVar7 = _TIKI_GetAnim(*(undefined4 *)
                           (*(int *)(iVar7 + 0x168 + *(int *)(iVar4 + 0x58) * 4) + 0xb8 + iVar7));
    if (iVar7 != 0) {
      sVar1 = *(short *)(iVar4 + 0x5c);
      if ((*(int *)(iVar7 + 0x48) <= (int)sVar1) || (sVar1 < 0)) {
        (*__ri)(1,s_R_AddTikiSurfaces__no_such_oldfr,(int)sVar1,*(undefined4 *)(iVar4 + 0x58),iVar6)
        ;
        *(undefined2 *)(iVar4 + 0x5c) = 0;
      }
      iVar6 = iStack_14;
      __tiki_scale = *(float *)(iStack_14 + 0xa4) * *(float *)(iVar4 + 0x60);
      _oldFrame = *(int *)(iVar7 + 100) + *(short *)(iVar4 + 0x5c) * 0x44 + iVar7;
      _tiki_localorigin = __tiki_scale * *(float *)(iStack_14 + 0xbc);
      _DAT_00008324 = *(float *)(iStack_14 + 0xc0) * __tiki_scale;
      _DAT_00008328 = __tiki_scale * *(float *)(iStack_14 + 0xc4);
      iVar9 = _R_CullTikiModel();
      if (iVar9 != 2) {
        param_1 = *(float *)(_newFrame + 0x3c) * __tiki_scale;
        fStack_c = _tiki_localorigin + *(float *)(iVar4 + 0x48);
        fStack_8 = _DAT_00008324 + *(float *)(iVar4 + 0x4c);
        fStack_4 = _DAT_00008328 + *(float *)(iVar4 + 0x50);
        if (_DAT_000184b0 == 0) {
          fVar12 = (float10)_R_TikiCalcLod(&fStack_c,iVar6,param_1);
          *(float *)(iVar4 + 0x200) = (float)fVar12;
        }
        else {
          fVar12 = (float10)_R_TikiCalcLod(&fStack_c,iVar6,param_1);
          *(float *)(iVar4 + 0x204) = (float)fVar12;
        }
        iStack_1c = _R_CalcFogNum(&fStack_c,param_1);
        iVar8 = *(int *)(iVar8 + 0x68) + iVar8;
        param_1 = (float)(*(int *)(iVar7 + 0x68) + iVar7);
        iVar6 = *(int *)(iStack_14 + 0xa0) + iStack_14;
        iStack_18 = iVar8;
        if (0 < *(int *)(iStack_14 + 0x80)) {
          pbStack_24 = (byte *)(iVar4 + 0xd0);
          fStack_10 = (float)(-0xd0 - iVar4);
          uVar11 = _tess_surface_index;
          do {
            iStack_18 = iVar8;
            if ((*pbStack_24 & 4) == 0) {
              iVar7 = (*pbStack_24 & 3) + *(int *)(iVar4 + 0xb0);
              if ((*(int *)(iVar4 + 0xb8) == 0) || ((*(uint *)(iVar4 + 4) & 0x10000) != 0)) {
                iVar9 = *(int *)(iVar4 + 0xb4);
                if ((iVar9 < 1) || (_DAT_0005dc04 <= iVar9)) {
                  if (iVar7 < *(int *)(iVar6 + 0x150)) {
                    iVar7 = *(int *)(*(int *)(iVar6 + 0x140 + iVar7 * 4) * 4 + 0x5bc04);
                  }
                  else {
                    iVar7 = *(int *)(*(int *)(iVar6 + 0x140) * 4 + 0x5bc04);
                  }
                }
                else {
                  iVar7 = *(int *)(iVar9 * 4 + 0x5dc08);
                  iVar7 = *(int *)(*(int *)(iVar7 + 0x44 +
                                           ((int)(pbStack_24 + (int)fStack_10) %
                                           *(int *)(iVar7 + 0x40)) * 4) + 0x40);
                }
              }
              else {
                iVar7 = _R_GetShaderByHandle(*(int *)(iVar4 + 0xb8));
                uVar11 = _tess_surface_index;
              }
              iVar5 = iStack_1c;
              iVar9 = uVar11 * 0xc;
              *(undefined4 *)(&_tess_surfaces + iVar9) = 0xb;
              *(int *)(&DAT_00002324 + iVar9) = iVar8;
              *(float *)(&DAT_00002328 + iVar9) = param_1;
              if (((((local_20 == 0) && (*(int *)(__r_shadows + 0x20) == 2)) && (iStack_1c == 0)) &&
                  ((uVar2 = *(uint *)(iVar4 + 4), (uVar2 & 4) == 0 && ((uVar2 & 0x800) != 0)))) &&
                 (((uVar2 & 0x4000000) != 0 &&
                  ((NAN(___real_40800000) || NAN(*(float *)(iVar7 + 0x4c))) !=
                   (___real_40800000 == *(float *)(iVar7 + 0x4c)))))) {
                _R_AddDrawSurf(&_tess_surfaces + iVar9,__R_GetSkinByHandle,0,0);
                uVar11 = _tess_surface_index;
              }
              if (((*(int *)(__r_shadows + 0x20) == 3) && (iVar5 == 0)) &&
                 (((*(uint *)(iVar4 + 4) & 0x100000) != 0 &&
                  (((*(uint *)(iVar4 + 4) & 0x4000000) != 0 &&
                   ((NAN(___real_40800000) || NAN(*(float *)(iVar7 + 0x4c))) !=
                    (___real_40800000 == *(float *)(iVar7 + 0x4c)))))))) {
                _R_AddDrawSurf(&_tess_surfaces + uVar11 * 0xc,_DAT_00017cbc,0,0);
                uVar11 = _tess_surface_index;
              }
              if (local_20 == 0) {
                if (((*pbStack_24 & 0x40) == 0) || (*(int *)(iVar6 + 0x150) < 2)) {
                  _R_AddDrawSurf(&_tess_surfaces + uVar11 * 0xc,iVar7,iVar5,0);
                  uVar11 = _tess_surface_index;
                }
                else {
                  iVar7 = (*pbStack_24 & 2) + *(int *)(iVar4 + 0xb0);
                  _R_AddDrawSurf(&_tess_surfaces + uVar11 * 0xc,
                                 *(undefined4 *)(*(int *)(iVar6 + 0x140 + iVar7 * 4) * 4 + 0x5bc04),
                                 iVar5,0);
                  _R_AddDrawSurf(&_tess_surfaces + _tess_surface_index * 0xc,
                                 *(undefined4 *)(*(int *)(iVar6 + 0x144 + iVar7 * 4) * 4 + 0x5bc04),
                                 iVar5,0);
                  uVar11 = _tess_surface_index;
                }
              }
              if ((*(int *)(iVar4 + 0xb8) != 0) && ((*(uint *)(iVar4 + 4) & 0x10000) != 0)) {
                uVar10 = _R_GetShaderByHandle(*(int *)(iVar4 + 0xb8));
                _R_AddDrawSurf(&_tess_surfaces + _tess_surface_index * 0xc,uVar10,iVar5,0);
                uVar11 = _tess_surface_index;
              }
              uVar11 = uVar11 + 1 & 0x7ff;
              param_1 = (float)((int)param_1 + *(int *)((int)param_1 + 100));
              _tess_surface_index = uVar11;
            }
            else {
              param_1 = (float)((int)param_1 + *(int *)((int)param_1 + 100));
            }
            iVar8 = iStack_18 + *(int *)(iStack_18 + 100);
            pbStack_24 = pbStack_24 + 1;
            iVar6 = iVar6 + 0x15c;
            iStack_18 = iVar8;
          } while ((int)(pbStack_24 + (int)fStack_10) < *(int *)(iStack_14 + 0x80));
        }
        iVar6 = _newFrame;
        *(int *)(iVar4 + 0x1a8) = _oldFrame;
        *(int *)(iVar4 + 0x1ac) = iVar6;
        *(int *)(iVar4 + 0x1b0) = iStack_14;
        if (*(int *)(__r_showlod + 0x20) != 0) {
          fStack_c = *(float *)(iVar4 + 0x48);
          fStack_8 = *(float *)(iVar4 + 0x4c);
          fStack_4 = *(float *)(iVar4 + 0x50) + (float)___real_4059000000000000;
          _R_CountTikiLodTris(iVar4,*(undefined4 *)(iVar4 + 0x200),&local_20,&param_1,0);
          fVar3 = (float)(int)param_1;
          if ((int)param_1 < 10) {
            param_1 = fVar3 / (float)___real_4024000000000000;
            uVar10 = 1;
          }
          else if ((int)param_1 < 100) {
            param_1 = fVar3 / (float)___real_4059000000000000;
            uVar10 = 2;
          }
          else if ((int)param_1 < 1000) {
            param_1 = fVar3 / (float)___real_408f400000000000;
            uVar10 = 3;
          }
          else {
            param_1 = fVar3 / (float)___real_40c3880000000000;
            uVar10 = 4;
          }
          param_1 = param_1 + (float)local_20;
          fStack_10 = 1.0 / *(float *)(iVar4 + 0x200);
          _R_DrawDebugNumber(&fStack_c,param_1,fStack_10,0x3f800000,0x3f800000,0,uVar10);
        }
      }
      return;
    }
    uVar10 = *(undefined4 *)(iVar4 + 0x58);
  }
  (*__ri)(1,s_R_AddTikiSurfaces__couldn_t_get_,uVar10,iVar6);
  return;
}



