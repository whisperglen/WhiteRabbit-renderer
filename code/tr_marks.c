// ===========================================
// Function: _R_ChopPolyBehindPlane @ 00007b00
// ===========================================

void _R_ChopPolyBehindPlane(int param_1,void *param_2,void *param_3,float param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float *in_EAX;
  int iVar4;
  float *pfVar5;
  int *unaff_EBX;
  float *pfVar6;
  float local_230;
  int local_22c [71];
  float local_110 [68];
  
  if (0x3d < param_1) {
    *unaff_EBX = 0;
    return;
  }
  iVar4 = 0;
  local_22c[2] = 0;
  local_22c[1] = 0;
  local_22c[0] = 0;
  if (0 < param_1) {
    pfVar5 = (float *)((int)param_2 + 8);
    do {
      fVar2 = (in_EAX[2] * *pfVar5 + pfVar5[-1] * in_EAX[1] + pfVar5[-2] * *in_EAX) - param_4;
      local_110[iVar4] = fVar2;
      if (fVar2 <= param_5) {
        if (-param_5 <= fVar2) {
          local_22c[iVar4 + 3] = 2;
        }
        else {
          local_22c[iVar4 + 3] = 1;
        }
      }
      else {
        local_22c[iVar4 + 3] = 0;
      }
      local_22c[local_22c[iVar4 + 3]] = local_22c[local_22c[iVar4 + 3]] + 1;
      iVar4 = iVar4 + 1;
      pfVar5 = pfVar5 + 3;
    } while (iVar4 < param_1);
  }
  local_110[iVar4] = local_110[0];
  local_22c[iVar4 + 3] = local_22c[3];
  *unaff_EBX = 0;
  if (local_22c[0] != 0) {
    if (local_22c[1] == 0) {
      *unaff_EBX = param_1;
      _memcpy(param_3,param_2,param_1 * 0xc);
      return;
    }
    iVar4 = 0;
    if (0 < param_1) {
      pfVar5 = (float *)((int)param_2 + 8);
      do {
        pfVar6 = (float *)((int)param_3 + *unaff_EBX * 0xc);
        iVar3 = local_22c[iVar4 + 3];
        if (iVar3 == 2) {
          *pfVar6 = pfVar5[-2];
          pfVar6[1] = pfVar5[-1];
          fVar2 = *pfVar5;
LAB_00007d1c:
          pfVar6[2] = fVar2;
          *unaff_EBX = *unaff_EBX + 1;
        }
        else {
          if (iVar3 == 0) {
            *pfVar6 = pfVar5[-2];
            pfVar6[1] = pfVar5[-1];
            pfVar6[2] = *pfVar5;
            *unaff_EBX = *unaff_EBX + 1;
            pfVar6 = (float *)((int)param_3 + *unaff_EBX * 0xc);
          }
          if ((local_22c[iVar4 + 4] != 2) && (local_22c[iVar4 + 4] != iVar3)) {
            local_230 = local_110[iVar4] - local_110[iVar4 + 1];
            pfVar1 = (float *)((int)param_2 + ((iVar4 + 1) % param_1) * 0xc);
            if (NAN(local_230) == (local_230 == 0.0)) {
              local_230 = local_110[iVar4] / local_230;
            }
            else {
              local_230 = 0.0;
            }
            *pfVar6 = pfVar5[-2] + local_230 * (*pfVar1 - pfVar5[-2]);
            pfVar6[1] = (pfVar1[1] - pfVar5[-1]) * local_230 + pfVar5[-1];
            fVar2 = (pfVar1[2] - *pfVar5) * local_230 + *pfVar5;
            goto LAB_00007d1c;
          }
        }
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 3;
      } while (iVar4 < param_1);
    }
  }
  return;
}



// ===========================================
// Function: _R_BoxSurfaces_r @ 00007d39
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_BoxSurfaces_r(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                     int *param_6,float *param_7)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = *param_1;
  while (iVar3 == -1) {
    iVar3 = _BoxOnPlaneSide(param_2,param_3,param_1[9]);
    if (iVar3 == 1) {
      param_1 = (int *)param_1[10];
    }
    else {
      if (iVar3 != 2) {
        _R_BoxSurfaces_r(param_1[10],param_2,param_3,param_4,param_5,param_6,param_7);
      }
      param_1 = (int *)param_1[0xb];
    }
    iVar3 = *param_1;
  }
  piVar1 = (int *)param_1[0x10];
  iVar3 = param_1[0x11];
  do {
    if ((iVar3 == 0) || (iVar3 = iVar3 + -1, param_5 <= *param_6)) {
      return;
    }
    piVar2 = (int *)*piVar1;
    if (((*(byte *)(piVar2[1] + 0x58) & 0x30) == 0) &&
       ((*(uint *)(piVar2[1] + 0x5c) & 0xfffffffe) == 0)) {
      piVar5 = (int *)piVar2[3];
      if (*piVar5 == 2) {
        iVar4 = _BoxOnPlaneSide(param_2,param_3,piVar5 + 1);
        if ((iVar4 != 1) && (iVar4 != 2)) {
          piVar5 = (int *)piVar2[3];
          if ((float)piVar5[3] * param_7[2] +
              (float)piVar5[1] * *param_7 + (float)piVar5[2] * param_7[1] <=
              (float)___real_bfe0000000000000) goto LAB_00007e40;
          goto LAB_00007e1e;
        }
        *piVar2 = __VectorInverse;
      }
      else if (*piVar5 == 3) {
LAB_00007e40:
        if (*piVar2 != __VectorInverse) {
          *piVar2 = __VectorInverse;
          *(int **)(param_4 + *param_6 * 4) = piVar5;
          *param_6 = *param_6 + 1;
        }
      }
      else {
        *piVar2 = __VectorInverse;
      }
    }
    else {
LAB_00007e1e:
      *piVar2 = __VectorInverse;
    }
    piVar1 = piVar1 + 1;
  } while( true );
}



// ===========================================
// Function: _R_AddMarkFragments @ 00007e6a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddMarkFragments(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                        int param_6,int param_7,undefined4 param_8,int param_9,int *param_10,
                        int *param_11,undefined4 param_12,undefined4 param_13,float *param_14)

{
  float *__src;
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = 0;
  if (0 < param_3) {
    do {
      _R_ChopPolyBehindPlane
                (param_1,uVar2 * 0x300 + param_2,(uint)(uVar2 == 0) * 0x300 + param_2,
                 *(undefined4 *)(param_5 + iVar1 * 4),___real_3f000000);
      uVar2 = uVar2 ^ 1;
      if (param_1 == 0) {
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  if ((param_1 != 0) && (*param_10 + param_1 <= param_6)) {
    iVar1 = *param_11;
    *(int *)(param_9 + iVar1 * 0x18) = *param_10;
    param_9 = param_9 + iVar1 * 0x18;
    *(int *)(param_9 + 4) = param_1;
    __src = (float *)(param_2 + uVar2 * 0x300);
    *(float *)(param_9 + 0x14) =
         __src[2] * param_14[2] +
         *__src * *param_14 + *(float *)(param_2 + 4 + uVar2 * 0x300) * param_14[1];
    *(float *)(param_9 + 8) = *param_14;
    *(float *)(param_9 + 0xc) = param_14[1];
    *(float *)(param_9 + 0x10) = param_14[2];
    _memcpy((void *)(param_7 + *param_10 * 0xc),__src,param_1 * 0xc);
    *param_10 = *param_10 + param_1;
    *param_11 = *param_11 + 1;
  }
  return;
}



// ===========================================
// Function: _R_MarkFragments @ 00007f7a
// ===========================================

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_MarkFragments(float *param_1,float *param_2,float *param_3,undefined4 param_4,
                    undefined4 param_5,int param_6,undefined4 param_7)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int *piVar10;
  int iStack_b8c;
  float *pfStack_b88;
  float *pfStack_b84;
  float *pfStack_b80;
  int iStack_b7c;
  float fStack_b78;
  float fStack_b74;
  float fStack_b70;
  float local_b6c;
  float fStack_b68;
  float fStack_b64;
  float fStack_b60;
  float fStack_b5c;
  float fStack_b58;
  int iStack_b54;
  float fStack_b50;
  float fStack_b4c;
  float fStack_b48;
  undefined1 auStack_b44 [12];
  undefined1 auStack_b38 [12];
  float fStack_b2c;
  float fStack_b28;
  float fStack_b24;
  float fStack_b20;
  float fStack_b1c;
  float fStack_b18;
  float fStack_b14;
  float fStack_b10;
  float fStack_b0c;
  float fStack_b08;
  float fStack_b04;
  float fStack_b00;
  float fStack_524;
  float afStack_520 [66];
  float afStack_418 [198];
  int aiStack_100 [64];
  
  __VectorInverse = __VectorInverse + 1;
  _VectorNormalize2(param_3,&local_b6c);
  _ClearBounds(auStack_b44,auStack_b38);
  if (0 < (int)param_1) {
    pfVar8 = param_2 + 2;
    pfStack_b88 = param_1;
    do {
      _AddPointToBounds(pfVar8 + -2,auStack_b44,auStack_b38);
      fStack_b2c = *param_3 + pfVar8[-2];
      fStack_b28 = pfVar8[-1] + param_3[1];
      fStack_b24 = *pfVar8 + param_3[2];
      _AddPointToBounds(&fStack_b2c,auStack_b44,auStack_b38);
      fVar3 = (float)___real_4034000000000000;
      fStack_b2c = pfVar8[-2] - local_b6c * fVar3;
      fStack_b28 = pfVar8[-1] - fStack_b68 * fVar3;
      fStack_b24 = *pfVar8 - fStack_b64 * fVar3;
      _AddPointToBounds(&fStack_b2c,auStack_b44,auStack_b38);
      pfVar8 = pfVar8 + 3;
      pfStack_b88 = (float *)((int)pfStack_b88 + -1);
    } while (pfStack_b88 != (float *)0x0);
  }
  if (0x40 < (int)param_1) {
    param_1 = (float *)0x40;
  }
  if (0 < (int)param_1) {
    pfVar8 = afStack_418;
    pfStack_b84 = (float *)((int)pfVar8 - (int)param_2);
    iStack_b8c = 1;
    pfStack_b80 = param_1;
    pfVar9 = param_2 + 2;
    pfStack_b88 = afStack_520;
    do {
      iVar7 = iStack_b8c % (int)param_1;
      fStack_b60 = param_2[iVar7 * 3] - pfVar9[-2];
      fStack_b5c = param_2[iVar7 * 3 + 1] - pfVar9[-1];
      fStack_b58 = param_2[iVar7 * 3 + 2] - *pfVar9;
      fStack_b78 = pfVar9[-2] - (*param_3 + pfVar9[-2]);
      fStack_b74 = pfVar9[-1] - (pfVar9[-1] + param_3[1]);
      fStack_b70 = *pfVar9 - (param_3[2] + *pfVar9);
      _CrossProduct(&fStack_b60,&fStack_b78,pfVar8);
      _VectorNormalize(pfVar8);
      pfVar1 = pfVar8 + 1;
      fVar3 = *pfVar8;
      iStack_b8c = iStack_b8c + 1;
      pfVar6 = pfStack_b88 + 1;
      pfVar8 = pfVar8 + 3;
      pfStack_b80 = (float *)((int)pfStack_b80 + -1);
      *pfStack_b88 = *(float *)((int)pfStack_b84 + (int)pfVar9) * *pfVar9 +
                     fVar3 * pfVar9[-2] + *pfVar1 * pfVar9[-1];
      pfVar9 = pfVar9 + 3;
      pfStack_b88 = pfVar6;
    } while (pfStack_b80 != (float *)0x0);
    pfStack_b80 = (float *)0x0;
  }
  afStack_418[(int)param_1 * 3] = local_b6c;
  afStack_418[(int)param_1 * 3 + 1] = fStack_b68;
  afStack_418[(int)param_1 * 3 + 2] = fStack_b64;
  pfStack_b84 = afStack_418 + (int)param_1 * 3 + 5;
  afStack_520[(int)param_1] =
       (param_2[2] * fStack_b64 + fStack_b68 * param_2[1] + *param_2 * local_b6c) -
       (float)___real_4040000000000000;
  afStack_418[(int)param_1 * 3 + 3] = local_b6c;
  afStack_418[(int)param_1 * 3 + 4] = fStack_b68;
  *pfStack_b84 = fStack_b64;
  _VectorInverse();
  iStack_b54 = 0;
  uVar4 = *(undefined4 *)(__CrossProduct + 0xa0);
  pfStack_b88 = (float *)((int)param_1 + 2);
  (&fStack_524)[(int)pfStack_b88] =
       (*pfStack_b84 * param_2[2] +
       afStack_418[(int)param_1 * 3 + 4] * param_2[1] + *param_2 * afStack_418[(int)param_1 * 3 + 3]
       ) - (float)___real_4034000000000000;
  _R_BoxSurfaces_r(uVar4,auStack_b44,auStack_b38,aiStack_100,0x40,&iStack_b54,&local_b6c);
  pfStack_b80 = (float *)0x0;
  iStack_b8c = 0;
  pfStack_b84 = (float *)0x0;
  if (0 < iStack_b54) {
    fStack_b00 = (float)___real_4000000000000000;
    do {
      piVar5 = (int *)aiStack_100[(int)pfStack_b84];
      if (*piVar5 == 3) {
        iStack_b7c = 0;
        if (piVar5[0x13] != 1 && -1 < piVar5[0x13] + -1) {
          do {
            iVar7 = 0;
            if (piVar5[0x12] != 1 && -1 < piVar5[0x12] + -1) {
              do {
                iVar2 = piVar5[0x12] * iStack_b7c + 2 + iVar7;
                pfVar8 = (float *)(piVar5 + iVar2 * 0xb + piVar5[0x12] * 0xb);
                fStack_b20 = (float)piVar5[iVar2 * 0xb + 7] * fStack_b00 +
                             (float)piVar5[iVar2 * 0xb];
                fStack_b1c = (float)piVar5[iVar2 * 0xb + 8] * fStack_b00 +
                             (float)piVar5[iVar2 * 0xb + 1];
                fStack_b18 = (float)piVar5[iVar2 * 0xb + 9] * fStack_b00 +
                             (float)piVar5[iVar2 * 0xb + 2];
                fStack_b14 = pfVar8[7] * fStack_b00 + *pfVar8;
                fStack_b10 = pfVar8[8] * fStack_b00 + pfVar8[1];
                fStack_b0c = pfVar8[9] * fStack_b00 + pfVar8[2];
                fStack_b08 = (float)piVar5[iVar2 * 0xb + 0x12] * fStack_b00 +
                             (float)piVar5[iVar2 * 0xb + 0xb];
                fStack_b04 = (float)piVar5[iVar2 * 0xb + 0x13] * fStack_b00 +
                             (float)piVar5[iVar2 * 0xb + 0xc];
                fStack_b00 = fStack_b00 * (float)piVar5[iVar2 * 0xb + 0x14] +
                             (float)piVar5[iVar2 * 0xb + 0xd];
                fStack_b60 = fStack_b20 - fStack_b14;
                fStack_b5c = fStack_b1c - fStack_b10;
                fStack_b58 = fStack_b18 - fStack_b0c;
                fStack_b78 = fStack_b08 - fStack_b14;
                fStack_b74 = fStack_b04 - fStack_b10;
                fStack_b70 = fStack_b00 - fStack_b0c;
                _CrossProduct(&fStack_b60,&fStack_b78,&fStack_b50);
                _VectorNormalize(&fStack_b50);
                fVar3 = fStack_b48 * fStack_b64 + fStack_b50 * local_b6c + fStack_b4c * fStack_b68;
                if ((fVar3 < (float)___real_bfb999999999999a !=
                     (NAN(fVar3) || NAN((float)___real_bfb999999999999a))) &&
                   (_R_AddMarkFragments(3,&fStack_b20,pfStack_b88,afStack_418,afStack_520,param_4,
                                        param_5,param_6,param_7,&pfStack_b80,&iStack_b8c,auStack_b44
                                        ,auStack_b38,&fStack_b50), iStack_b8c == param_6)) {
                  return iStack_b8c;
                }
                fVar3 = (float)___real_4000000000000000;
                pfVar8 = (float *)(piVar5 + iVar2 * 0xb + piVar5[0x12] * 0xb);
                fStack_b20 = (float)piVar5[iVar2 * 0xb + 0xb] +
                             (float)piVar5[iVar2 * 0xb + 0x12] * fVar3;
                fStack_b1c = (float)piVar5[iVar2 * 0xb + 0x13] * fVar3 +
                             (float)piVar5[iVar2 * 0xb + 0xc];
                fStack_b18 = (float)piVar5[iVar2 * 0xb + 0x14] * fVar3 +
                             (float)piVar5[iVar2 * 0xb + 0xd];
                fStack_b14 = pfVar8[7] * fVar3 + *pfVar8;
                fStack_b10 = pfVar8[8] * fVar3 + pfVar8[1];
                fStack_b0c = pfVar8[9] * fVar3 + pfVar8[2];
                fStack_b08 = pfVar8[0x12] * fVar3 + pfVar8[0xb];
                fStack_b04 = pfVar8[0x13] * fVar3 + pfVar8[0xc];
                fStack_b00 = fVar3 * pfVar8[0x14] + pfVar8[0xd];
                fStack_b60 = fStack_b20 - fStack_b14;
                fStack_b5c = fStack_b1c - fStack_b10;
                fStack_b58 = fStack_b18 - fStack_b0c;
                fStack_b78 = fStack_b08 - fStack_b14;
                fStack_b74 = fStack_b04 - fStack_b10;
                fStack_b70 = fStack_b00 - fStack_b0c;
                _CrossProduct(&fStack_b60,&fStack_b78,&fStack_b50);
                _VectorNormalize(&fStack_b50);
                fVar3 = fStack_b48 * fStack_b64 + fStack_b50 * local_b6c + fStack_b4c * fStack_b68;
                if ((fVar3 < (float)___real_bfa999999999999a !=
                     (NAN(fVar3) || NAN((float)___real_bfa999999999999a))) &&
                   (_R_AddMarkFragments(3,&fStack_b20,pfStack_b88,afStack_418,afStack_520,param_4,
                                        param_5,param_6,param_7,&pfStack_b80,&iStack_b8c,auStack_b44
                                        ,auStack_b38,&fStack_b50), iStack_b8c == param_6)) {
                  return iStack_b8c;
                }
                fStack_b00 = (float)___real_4000000000000000;
                iVar7 = iVar7 + 1;
              } while (iVar7 < piVar5[0x12] + -1);
            }
            iStack_b7c = iStack_b7c + 1;
          } while (iStack_b7c < piVar5[0x13] + -1);
        }
      }
      else if ((*piVar5 == 2) &&
              (fStack_b64 * (float)piVar5[3] +
               (float)piVar5[2] * fStack_b68 + (float)piVar5[1] * local_b6c <=
               (float)___real_bfe0000000000000)) {
        iStack_b7c = 0;
        if (0 < piVar5[9]) {
          piVar10 = (int *)((int)piVar5 + piVar5[10] + 8);
          do {
            iVar7 = piVar10[-2];
            fStack_b08 = (float)piVar5[1] * fStack_b00;
            fStack_b20 = (float)piVar5[iVar7 * 8 + 0xb] + fStack_b08;
            fStack_b04 = (float)piVar5[2] * fStack_b00;
            fStack_b1c = (float)piVar5[iVar7 * 8 + 0xc] + fStack_b04;
            fStack_b00 = (float)piVar5[3] * fStack_b00;
            fStack_b18 = (float)piVar5[iVar7 * 8 + 0xd] + fStack_b00;
            pfVar8 = (float *)(piVar5 + piVar10[-1] * 8 + 0xb);
            fStack_b14 = *pfVar8 + fStack_b08;
            fStack_b10 = pfVar8[1] + fStack_b04;
            pfVar9 = (float *)(piVar5 + *piVar10 * 8 + 0xb);
            fStack_b0c = pfVar8[2] + fStack_b00;
            fStack_b08 = *pfVar9 + fStack_b08;
            fStack_b04 = fStack_b04 + pfVar9[1];
            fStack_b00 = fStack_b00 + pfVar9[2];
            _R_AddMarkFragments(3,&fStack_b20,pfStack_b88,afStack_418,afStack_520,param_4,param_5,
                                param_6,param_7,&pfStack_b80,&iStack_b8c,auStack_b44,auStack_b38,
                                piVar5 + 1);
            if (iStack_b8c == param_6) {
              return iStack_b8c;
            }
            fStack_b00 = (float)___real_4000000000000000;
            iStack_b7c = iStack_b7c + 3;
            piVar10 = piVar10 + 3;
          } while (iStack_b7c < piVar5[9]);
        }
      }
      pfStack_b84 = (float *)((int)pfStack_b84 + 1);
    } while ((int)pfStack_b84 < iStack_b54);
  }
  return iStack_b8c;
}



