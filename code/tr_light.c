// ===========================================
// Function: _R_TransformDlights @ 00007b00
// ===========================================

void _R_TransformDlights(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  if (3 < param_1) {
    iVar5 = (param_1 - 4U >> 2) + 1;
    iVar6 = iVar5 * 4;
    pfVar4 = param_2;
    do {
      fVar1 = *pfVar4 - *param_3;
      fVar2 = pfVar4[1] - param_3[1];
      fVar3 = pfVar4[2] - param_3[2];
      pfVar4[8] = fVar1 * param_3[3] + fVar2 * param_3[4] + fVar3 * param_3[5];
      pfVar4[9] = fVar3 * param_3[8] + param_3[7] * fVar2 + param_3[6] * fVar1;
      pfVar4[10] = fVar3 * param_3[0xb] + param_3[9] * fVar1 + param_3[10] * fVar2;
      fVar1 = pfVar4[0xb] - *param_3;
      fVar2 = pfVar4[0xc] - param_3[1];
      fVar3 = pfVar4[0xd] - param_3[2];
      pfVar4[0x13] = fVar1 * param_3[3] + fVar2 * param_3[4] + fVar3 * param_3[5];
      pfVar4[0x14] = fVar3 * param_3[8] + param_3[7] * fVar2 + param_3[6] * fVar1;
      pfVar4[0x15] = fVar3 * param_3[0xb] + param_3[9] * fVar1 + param_3[10] * fVar2;
      fVar1 = pfVar4[0x16] - *param_3;
      fVar2 = pfVar4[0x17] - param_3[1];
      fVar3 = pfVar4[0x18] - param_3[2];
      pfVar4[0x1e] = fVar1 * param_3[3] + fVar2 * param_3[4] + fVar3 * param_3[5];
      pfVar4[0x1f] = fVar3 * param_3[8] + param_3[7] * fVar2 + param_3[6] * fVar1;
      pfVar4[0x20] = fVar3 * param_3[0xb] + param_3[9] * fVar1 + param_3[10] * fVar2;
      fVar1 = pfVar4[0x21] - *param_3;
      fVar2 = pfVar4[0x22] - param_3[1];
      fVar3 = pfVar4[0x23] - param_3[2];
      pfVar4[0x29] = fVar1 * param_3[3] + fVar2 * param_3[4] + fVar3 * param_3[5];
      param_2 = pfVar4 + 0x2c;
      iVar5 = iVar5 + -1;
      pfVar4[0x2a] = fVar3 * param_3[8] + param_3[7] * fVar2 + param_3[6] * fVar1;
      pfVar4[0x2b] = fVar3 * param_3[0xb] + param_3[9] * fVar1 + param_3[10] * fVar2;
      pfVar4 = param_2;
    } while (iVar5 != 0);
  }
  if (iVar6 < param_1) {
    param_1 = param_1 - iVar6;
    do {
      param_1 = param_1 + -1;
      fVar1 = *param_2 - *param_3;
      fVar2 = param_2[1] - param_3[1];
      fVar3 = param_2[2] - param_3[2];
      param_2[8] = fVar1 * param_3[3] + fVar2 * param_3[4] + fVar3 * param_3[5];
      param_2[9] = fVar3 * param_3[8] + param_3[7] * fVar2 + param_3[6] * fVar1;
      param_2[10] = fVar3 * param_3[0xb] + param_3[9] * fVar1 + param_3[10] * fVar2;
      param_2 = param_2 + 0xb;
    } while (param_1 != 0);
  }
  return;
}



// ===========================================
// Function: _R_DlightBmodel @ 00007db2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DlightBmodel(int param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  uint local_4;
  
  _R_TransformDlights(_DAT_0000a518,_DAT_0000a51c,0xa25c);
  iVar4 = 0;
  local_4 = 0;
  if (0 < _DAT_0000a518) {
    pfVar7 = (float *)(_DAT_0000a51c + 0x20);
    do {
      iVar5 = 0;
      pfVar6 = pfVar7;
      do {
        fVar3 = *pfVar6 - *(float *)(param_1 + 0xc + iVar5 * 4);
        if ((pfVar7[-2] < fVar3 != (NAN(pfVar7[-2]) || NAN(fVar3))) ||
           (fVar3 = *(float *)(param_1 + iVar5 * 4) - *pfVar6,
           pfVar7[-2] < fVar3 != (NAN(pfVar7[-2]) || NAN(fVar3)))) {
          if (iVar5 < 3) goto LAB_00007e34;
          break;
        }
        iVar5 = iVar5 + 1;
        pfVar6 = pfVar6 + 1;
      } while (iVar5 < 3);
      local_4 = local_4 | 1 << ((byte)iVar4 & 0x1f);
LAB_00007e34:
      iVar4 = iVar4 + 1;
      pfVar7 = pfVar7 + 0xb;
    } while (iVar4 < _DAT_0000a518);
  }
  iVar4 = 0;
  *(uint *)(_DAT_00009cec + 0x1d0) = (uint)(local_4 != 0);
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar5 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x18) + iVar5 + 0xc);
      iVar2 = *piVar1;
      if (iVar2 == 2) {
        piVar1[_DAT_000098a4 + 6] = local_4;
      }
      else if ((iVar2 == 3) || (iVar2 == 4)) {
        piVar1[_DAT_000098a4 + 1] = local_4;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar4 < *(int *)(param_1 + 0x1c));
  }
  return;
}



// ===========================================
// Function: _R_SetupEntityLightingGrid @ 00007ea0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _R_SetupEntityLightingGrid(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  float local_84;
  int *local_80;
  uint local_7c;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float afStack_64 [7];
  int iStack_48;
  
  *in_EAX = *in_EAX - *(float *)(___ftol2_sse + 0xbc);
  in_EAX[1] = in_EAX[1] - *(float *)(___ftol2_sse + 0xc0);
  in_EAX[2] = in_EAX[2] - *(float *)(___ftol2_sse + 0xc4);
  local_80 = (int *)(___ftol2_sse + 0xe0);
  iVar8 = 0;
  do {
    pfVar7 = (float *)((int)afStack_64 + iVar8 + 0xc);
    fVar2 = *(float *)(((int)in_EAX - (int)(afStack_64 + 3)) + (int)pfVar7) * (float)local_80[-3];
    _floor((double)fVar2);
    iVar4 = __ftol2_sse();
    *(int *)((int)afStack_64 + iVar8) = iVar4;
    *pfVar7 = fVar2 - (float)iVar4;
    if (iVar4 < 0) {
      *(undefined4 *)((int)afStack_64 + iVar8) = 0;
    }
    else if (*local_80 + -1 <= iVar4) {
      *(int *)((int)afStack_64 + iVar8) = *local_80 + -1;
    }
    local_80 = local_80 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0xc);
  local_80 = (int *)0x0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  iStack_48 = *(int *)(___ftol2_sse + 0xe0) * 8;
  iVar8 = *(int *)(___ftol2_sse + 0xe4) * *(int *)(___ftol2_sse + 0xe0) * 8;
  pbVar1 = (byte *)((int)afStack_64[2] * iVar8 + (int)afStack_64[1] * iStack_48 +
                    *(int *)(___ftol2_sse + 0xec) + (int)afStack_64[0] * 8);
  local_7c = 0;
  fStack_70 = (float)local_80;
  fStack_6c = (float)local_80;
  fStack_68 = (float)local_80;
  do {
    if ((local_7c & 1) == 0) {
      local_84 = 1.0 - afStack_64[3];
      pbVar5 = pbVar1;
    }
    else {
      local_84 = afStack_64[3];
      pbVar5 = pbVar1 + 8;
    }
    if ((local_7c & 2) == 0) {
      fVar2 = 1.0 - afStack_64[4];
    }
    else {
      pbVar5 = pbVar5 + iStack_48;
      fVar2 = afStack_64[4];
    }
    if ((local_7c & 4) == 0) {
      fVar3 = 1.0 - afStack_64[5];
    }
    else {
      pbVar5 = pbVar5 + iVar8;
      fVar3 = afStack_64[5];
    }
    fVar3 = fVar3 * fVar2 * local_84;
    if ((uint)pbVar5[1] + (uint)pbVar5[2] + (uint)*pbVar5 != 0) {
      local_80 = (int *)(fVar3 + (float)local_80);
      *(float *)(param_1 + 0x1e4) = (float)*pbVar5 * fVar3 + *(float *)(param_1 + 0x1e4);
      *(float *)(param_1 + 0x1e8) = (float)pbVar5[1] * fVar3 + *(float *)(param_1 + 0x1e8);
      *(float *)(param_1 + 0x1ec) = (float)pbVar5[2] * fVar3 + *(float *)(param_1 + 0x1ec);
      *(float *)(param_1 + 500) = (float)pbVar5[3] * fVar3 + *(float *)(param_1 + 500);
      *(float *)(param_1 + 0x1f8) = (float)pbVar5[4] * fVar3 + *(float *)(param_1 + 0x1f8);
      *(float *)(param_1 + 0x1fc) = (float)pbVar5[5] * fVar3 + *(float *)(param_1 + 0x1fc);
      uVar6 = (uint)pbVar5[6] * 4 + 0x100;
      afStack_64[0] =
           *(float *)(((uint)pbVar5[7] * 4 + 0x100 & 0x3ff) * 4 + 0x50828) *
           *(float *)(uVar6 * 4 + 0x50428);
      afStack_64[1] = *(float *)((uint)pbVar5[7] * 0x10 + 0x50828) * *(float *)(uVar6 * 4 + 0x50428)
      ;
      afStack_64[2] = *(float *)((uVar6 & 0x3ff) * 4 + 0x50828);
      fStack_70 = afStack_64[0] * fVar3 + fStack_70;
      fStack_6c = afStack_64[1] * fVar3 + fStack_6c;
      fStack_68 = fVar3 * afStack_64[2] + fStack_68;
    }
    local_7c = local_7c + 1;
  } while ((int)local_7c < 8);
  if ((0.0 < (float)local_80) &&
     ((float)local_80 < (float)___real_3fefae147ae147ae !=
      (NAN((float)local_80) || NAN((float)___real_3fefae147ae147ae)))) {
    fVar2 = 1.0 / (float)local_80;
    *(float *)(param_1 + 0x1e4) = fVar2 * *(float *)(param_1 + 0x1e4);
    *(float *)(param_1 + 0x1e8) = *(float *)(param_1 + 0x1e8) * fVar2;
    *(float *)(param_1 + 0x1ec) = *(float *)(param_1 + 0x1ec) * fVar2;
    *(float *)(param_1 + 500) = *(float *)(param_1 + 500) * fVar2;
    *(float *)(param_1 + 0x1f8) = *(float *)(param_1 + 0x1f8) * fVar2;
    *(float *)(param_1 + 0x1fc) = fVar2 * *(float *)(param_1 + 0x1fc);
  }
  pfVar7 = (float *)(__r_ambientScale + 0x1c);
  *(float *)(param_1 + 0x1e4) = *(float *)(__r_ambientScale + 0x1c) * *(float *)(param_1 + 0x1e4);
  *(float *)(param_1 + 0x1e8) = *(float *)(param_1 + 0x1e8) * *pfVar7;
  *(float *)(param_1 + 0x1ec) = *pfVar7 * *(float *)(param_1 + 0x1ec);
  pfVar7 = (float *)(__r_directedScale + 0x1c);
  *(float *)(param_1 + 500) = *(float *)(__r_directedScale + 0x1c) * *(float *)(param_1 + 500);
  *(float *)(param_1 + 0x1f8) = *pfVar7 * *(float *)(param_1 + 0x1f8);
  *(float *)(param_1 + 0x1fc) = *pfVar7 * *(float *)(param_1 + 0x1fc);
  _VectorNormalize2(&fStack_70,param_1 + 0x1d8);
  return;
}



// ===========================================
// Function: _LogLight @ 00008283
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _LogLight(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  if ((*(byte *)(unaff_ESI + 4) & 2) != 0) {
    iVar2 = __ftol2_sse();
    fVar1 = (float)iVar2;
    if ((fVar1 < *(float *)(unaff_ESI + 0x1e8) != (NAN(fVar1) || NAN(*(float *)(unaff_ESI + 0x1e8)))
        ) || (fVar1 < *(float *)(unaff_ESI + 0x1ec))) {
      iVar2 = __ftol2_sse();
    }
    iVar3 = __ftol2_sse();
    fVar1 = (float)iVar3;
    if ((fVar1 < *(float *)(unaff_ESI + 0x1f8) != (NAN(fVar1) || NAN(*(float *)(unaff_ESI + 0x1f8)))
        ) || (fVar1 < *(float *)(unaff_ESI + 0x1fc))) {
      iVar3 = __ftol2_sse();
    }
    (*__ri)(0,s_amb__i__dir__i_,iVar2,iVar3);
  }
  return;
}



// ===========================================
// Function: _R_SetupEntityLighting @ 0000834a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetupEntityLighting(int param_1,float param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  float10 fVar9;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar4 = (int)param_2;
  iVar7 = 0;
  if (*(int *)((int)param_2 + 0x1d4) == 0) {
    *(undefined4 *)((int)param_2 + 0x1d4) = 1;
    uVar6 = *(uint *)(param_1 + 0x4c) & 1;
    if (((uVar6 == 0) && (*(int *)(___ftol2_sse + 0xec) != 0)) &&
       ((*(uint *)((int)param_2 + 4) & 0x40000) == 0)) {
      _R_SetupEntityLightingGrid();
    }
    else {
      if (uVar6 == 0) {
        fVar2 = (float)___real_4062c00000000000;
        fVar3 = _DAT_0000a24c * fVar2;
        *(float *)((int)param_2 + 0x1ec) = fVar3;
        *(float *)((int)param_2 + 0x1e8) = fVar3;
        *(float *)((int)param_2 + 0x1e4) = fVar3;
        fVar2 = fVar2 * _DAT_0000a24c;
      }
      else {
        fVar2 = 0.0;
        *(undefined4 *)((int)param_2 + 0x1ec) = 0;
        *(undefined4 *)((int)param_2 + 0x1e8) = 0;
        *(undefined4 *)((int)param_2 + 0x1e4) = 0;
      }
      *(float *)((int)param_2 + 0x1fc) = fVar2;
      *(float *)((int)param_2 + 0x1f8) = fVar2;
      *(float *)((int)param_2 + 500) = fVar2;
    }
    if ((*(uint *)((int)param_2 + 4) & 0x20000) != 0) {
      fVar2 = (float)___real_4040000000000000;
      *(float *)((int)param_2 + 0x1e4) = *(float *)((int)param_2 + 0x1e4) + _DAT_0000a24c * fVar2;
      *(float *)((int)param_2 + 0x1e8) = _DAT_0000a24c * fVar2 + *(float *)((int)param_2 + 0x1e8);
      *(float *)((int)param_2 + 0x1ec) = fVar2 * _DAT_0000a24c + *(float *)((int)param_2 + 0x1ec);
    }
    fVar9 = (float10)_VectorLength((int)param_2 + 500);
    fStack_4 = (float)fVar9;
    *(undefined4 *)((int)param_2 + 0x2c8) = 0;
    fStack_c = fStack_4 * *(float *)((int)param_2 + 0x1d8);
    fStack_8 = *(float *)((int)param_2 + 0x1dc) * fStack_4;
    fStack_4 = fStack_4 * *(float *)((int)param_2 + 0x1e0);
    if (0 < *(int *)(param_1 + 0x188)) {
      do {
        pfVar8 = (float *)(iVar7 * 0x2c + *(int *)(param_1 + 0x18c));
        fStack_18 = *pfVar8 - *param_3;
        fStack_14 = pfVar8[1] - param_3[1];
        fStack_10 = pfVar8[2] - param_3[2];
        fVar9 = (float10)_VectorLength(&fStack_18);
        fVar2 = (float)fVar9;
        if (pfVar8[6] < fVar2 == (NAN(pfVar8[6]) || NAN(fVar2))) {
          fVar2 = (pfVar8[6] * (float)___real_40dd4c0000000000) / (fVar2 * fVar2);
          *(float *)((int)param_2 + 500) = *(float *)((int)param_2 + 500) + fVar2 * pfVar8[3];
          *(float *)((int)param_2 + 0x1f8) = pfVar8[4] * fVar2 + *(float *)((int)param_2 + 0x1f8);
          *(float *)((int)param_2 + 0x1fc) = fVar2 * pfVar8[5] + *(float *)((int)param_2 + 0x1fc);
          if ((*(byte *)(param_1 + 0x4c) & 1) != 0) {
            if (iVar7 == 0) {
              *(float *)((int)param_2 + 0x1d8) = fStack_18;
              *(float *)((int)param_2 + 0x1dc) = fStack_14;
              *(float *)((int)param_2 + 0x1e0) = fStack_10;
              fStack_4 = fStack_10;
              fStack_c = fStack_18;
              fStack_8 = fStack_14;
            }
            if (*(int *)((int)param_2 + 0x2c8) < 8) {
              _VectorNormalize(&fStack_18);
              *(float *)((int)param_2 + 0x208 + iVar7 * 0xc) = fStack_18;
              iVar1 = (int)param_2 + iVar7 * 0xc;
              *(float *)(iVar1 + 0x20c) = fStack_14;
              *(float *)((int)param_2 + (iVar7 * 3 + 0x84) * 4) = fStack_10;
              *(float *)(iVar1 + 0x268) = fVar2 * pfVar8[3];
              *(float *)(iVar1 + 0x26c) = pfVar8[4] * fVar2;
              *(float *)((int)param_2 + (iVar7 * 3 + 0x9c) * 4) = fVar2 * pfVar8[5];
              *(int *)((int)param_2 + 0x2c8) = *(int *)((int)param_2 + 0x2c8) + 1;
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x188));
    }
    fVar2 = (float)___real_406fe00000000000;
    if (((fVar2 < *(float *)((int)param_2 + 500) !=
          (NAN(fVar2) || NAN(*(float *)((int)param_2 + 500)))) ||
        (fVar2 < *(float *)((int)param_2 + 0x1f8))) || (fVar2 < *(float *)((int)param_2 + 0x1fc))) {
      fVar3 = *(float *)((int)param_2 + 500);
      if (fVar3 < *(float *)((int)param_2 + 0x1f8) !=
          (NAN(fVar3) || NAN(*(float *)((int)param_2 + 0x1f8)))) {
        fVar3 = *(float *)((int)param_2 + 0x1f8);
      }
      param_2 = fVar3;
      if (param_2 < *(float *)(iVar4 + 0x1fc) != (NAN(param_2) || NAN(*(float *)(iVar4 + 0x1fc)))) {
        param_2 = *(float *)(iVar4 + 0x1fc);
      }
      fVar2 = fVar2 / param_2;
      *(float *)(iVar4 + 500) = fVar2 * *(float *)(iVar4 + 500);
      *(float *)(iVar4 + 0x1f8) = *(float *)(iVar4 + 0x1f8) * fVar2;
      *(float *)(iVar4 + 0x1fc) = *(float *)(iVar4 + 0x1fc) * fVar2;
      *(float *)(iVar4 + 0x1e4) = *(float *)(iVar4 + 0x1e4) * fVar2;
      *(float *)(iVar4 + 0x1e8) = *(float *)(iVar4 + 0x1e8) * fVar2;
      *(float *)(iVar4 + 0x1ec) = fVar2 * *(float *)(iVar4 + 0x1ec);
    }
    if ((*(uint *)(iVar4 + 4) & 0x8000) != 0) {
      *(float *)(iVar4 + 0x1e4) = (float)*(byte *)(iVar4 + 0xbc) + *(float *)(iVar4 + 0x1e4);
      *(float *)(iVar4 + 0x1e8) = (float)*(byte *)(iVar4 + 0xbd) + *(float *)(iVar4 + 0x1e8);
      *(float *)(iVar4 + 0x1ec) = (float)*(byte *)(iVar4 + 0xbe) + *(float *)(iVar4 + 0x1ec);
    }
    fVar2 = (float)_DAT_0000a250;
    if (fVar2 < *(float *)(iVar4 + 0x1e4) != (NAN(fVar2) || NAN(*(float *)(iVar4 + 0x1e4)))) {
      *(float *)(iVar4 + 0x1e4) = fVar2;
    }
    fVar2 = (float)_DAT_0000a250;
    if (fVar2 < *(float *)(iVar4 + 0x1e8) != (NAN(fVar2) || NAN(*(float *)(iVar4 + 0x1e8)))) {
      *(float *)(iVar4 + 0x1e8) = fVar2;
    }
    fVar2 = (float)_DAT_0000a250;
    if (fVar2 < *(float *)(iVar4 + 0x1ec) != (NAN(fVar2) || NAN(*(float *)(iVar4 + 0x1ec)))) {
      *(float *)(iVar4 + 0x1ec) = fVar2;
    }
    if (*(int *)(__r_debugLight + 0x20) != 0) {
      _LogLight();
    }
    uVar5 = myftol(*(undefined4 *)(iVar4 + 0x1e4));
    *(undefined1 *)(iVar4 + 0x1f0) = uVar5;
    uVar5 = myftol(*(undefined4 *)(iVar4 + 0x1e8));
    *(undefined1 *)(iVar4 + 0x1f1) = uVar5;
    uVar5 = myftol(*(undefined4 *)(iVar4 + 0x1ec));
    *(undefined1 *)(iVar4 + 0x1f2) = uVar5;
    *(undefined1 *)(iVar4 + 499) = 0xff;
    _VectorNormalize(&fStack_c);
    *(float *)(iVar4 + 0x1d8) =
         fStack_8 * *(float *)(iVar4 + 0x24) + fStack_c * *(float *)(iVar4 + 0x20) +
         fStack_4 * *(float *)(iVar4 + 0x28);
    *(float *)(iVar4 + 0x1dc) =
         *(float *)(iVar4 + 0x34) * fStack_4 +
         *(float *)(iVar4 + 0x2c) * fStack_c + *(float *)(iVar4 + 0x30) * fStack_8;
    *(float *)(iVar4 + 0x1e0) =
         fStack_4 * *(float *)(iVar4 + 0x40) +
         *(float *)(iVar4 + 0x3c) * fStack_8 + *(float *)(iVar4 + 0x38) * fStack_c;
  }
  return;
}



