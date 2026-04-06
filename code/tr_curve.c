// ===========================================
// Function: _LerpDrawVert @ 00007a00
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _LerpDrawVert(float *param_1)

{
  float fVar1;
  float *in_EAX;
  float *unaff_ESI;
  
  fVar1 = (float)___real_3fe0000000000000;
  *in_EAX = (*unaff_ESI + *param_1) * fVar1;
  in_EAX[1] = (unaff_ESI[1] + param_1[1]) * fVar1;
  in_EAX[2] = (unaff_ESI[2] + param_1[2]) * fVar1;
  in_EAX[3] = (unaff_ESI[3] + param_1[3]) * fVar1;
  in_EAX[4] = (unaff_ESI[4] + param_1[4]) * fVar1;
  in_EAX[5] = (unaff_ESI[5] + param_1[5]) * fVar1;
  in_EAX[6] = (unaff_ESI[6] + param_1[6]) * fVar1;
  *(char *)(in_EAX + 10) =
       (char)((int)((uint)*(byte *)(unaff_ESI + 10) + (uint)*(byte *)(param_1 + 10)) >> 1);
  *(char *)((int)in_EAX + 0x29) =
       (char)((int)((uint)*(byte *)((int)unaff_ESI + 0x29) + (uint)*(byte *)((int)param_1 + 0x29))
             >> 1);
  *(char *)((int)in_EAX + 0x2a) =
       (char)((int)((uint)*(byte *)((int)unaff_ESI + 0x2a) + (uint)*(byte *)((int)param_1 + 0x2a))
             >> 1);
  *(char *)((int)in_EAX + 0x2b) =
       (char)((int)((uint)*(byte *)((int)unaff_ESI + 0x2b) + (uint)*(byte *)((int)param_1 + 0x2b))
             >> 1);
  return;
}



// ===========================================
// Function: _Transpose @ 00007a91
// ===========================================

void _Transpose(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_30;
  undefined4 local_2c [11];
  
  if (param_2 < param_1) {
    if (0 < param_2) {
      local_30 = 0;
      iVar6 = 1;
      do {
        if (iVar6 < param_1) {
          puVar2 = (undefined4 *)((local_30 + iVar6) * 0x2c + param_3);
          puVar4 = (undefined4 *)((local_30 + 0x40 + iVar6) * 0x2c + param_3);
          iVar5 = iVar6;
          do {
            iVar3 = 0xb;
            puVar7 = puVar2;
            puVar8 = puVar4;
            if (iVar5 < param_2) {
              puVar7 = puVar4;
              puVar8 = local_2c;
              for (; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar8 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar8 = puVar8 + 1;
              }
              puVar7 = puVar2;
              puVar8 = puVar4;
              for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar8 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar8 = puVar8 + 1;
              }
              puVar7 = local_2c;
              puVar8 = puVar2;
            }
            iVar5 = iVar5 + 1;
            puVar2 = puVar2 + 0xb;
            puVar4 = puVar4 + 0x2cb;
            for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
          } while (iVar5 < param_1);
        }
        local_30 = local_30 + 0x41;
        bVar1 = iVar6 < param_2;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      return;
    }
  }
  else if (0 < param_1) {
    local_30 = 0;
    iVar6 = 1;
    do {
      if (iVar6 < param_2) {
        puVar2 = (undefined4 *)((local_30 + iVar6) * 0x2c + param_3);
        puVar4 = (undefined4 *)((local_30 + 0x40 + iVar6) * 0x2c + param_3);
        iVar5 = iVar6;
        do {
          iVar3 = 0xb;
          puVar7 = puVar4;
          puVar8 = puVar2;
          if (iVar5 < param_1) {
            puVar7 = puVar2;
            puVar8 = local_2c;
            for (; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
            puVar7 = puVar4;
            puVar8 = puVar2;
            for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
            puVar7 = local_2c;
            puVar8 = puVar4;
          }
          iVar5 = iVar5 + 1;
          puVar2 = puVar2 + 0xb;
          puVar4 = puVar4 + 0x2cb;
          for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        } while (iVar5 < param_2);
      }
      local_30 = local_30 + 0x41;
      bVar1 = iVar6 < param_1;
      iVar6 = iVar6 + 1;
    } while (bVar1);
  }
  return;
}



// ===========================================
// Function: _MakeMeshNormals @ 00007bd5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _MakeMeshNormals(int param_1,int param_2,float *param_3)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  float10 fVar10;
  int *piStack_d8;
  float *pfStack_d4;
  int iStack_d0;
  float *pfStack_cc;
  int iStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  int iStack_b8;
  int local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  int aiStack_80 [8];
  undefined1 auStack_60 [4];
  float afStack_5c [23];
  
  iVar6 = 0;
  bVar9 = param_2 == 0;
  local_b4 = 0;
  if (0 < param_2) {
    pfVar4 = param_3 + 2;
    pfVar3 = param_3 + param_1 * 0xb + -10;
    do {
      local_b0 = pfVar4[-2] - pfVar3[-1];
      local_ac = pfVar4[-1] - *pfVar3;
      local_a8 = *pfVar4 - pfVar3[1];
      fVar10 = (float10)_VectorLength(&local_b0);
      if ((float10)___real_3f800000 < fVar10) break;
      iVar6 = iVar6 + 1;
      pfVar4 = pfVar4 + 0x2cb;
      pfVar3 = pfVar3 + 0x2cb;
    } while (iVar6 < param_2);
    bVar9 = iVar6 == param_2;
  }
  if (bVar9) {
    local_b4 = 1;
  }
  iVar6 = 0;
  bVar9 = param_1 == 0;
  iStack_b8 = 0;
  if (0 < param_1) {
    pfVar4 = param_3 + 2;
    pfVar3 = param_3 + param_2 * 0x2cb + -0x2c9;
    do {
      local_b0 = pfVar4[-2] - pfVar3[-2];
      local_ac = pfVar4[-1] - pfVar3[-1];
      local_a8 = *pfVar4 - *pfVar3;
      fVar10 = (float10)_VectorLength(&local_b0);
      if ((float10)___real_3f800000 < fVar10) break;
      iVar6 = iVar6 + 1;
      pfVar4 = pfVar4 + 0xb;
      pfVar3 = pfVar3 + 0xb;
    } while (iVar6 < param_1);
    bVar9 = iVar6 == param_1;
  }
  if (bVar9) {
    iStack_b8 = 1;
  }
  iStack_c8 = 0;
  if (0 < param_1) {
    pfStack_cc = param_3;
    do {
      iStack_d0 = 0;
      if (0 < param_2) {
        pfStack_d4 = pfStack_cc;
        do {
          fStack_98 = *pfStack_d4;
          pfVar4 = afStack_5c;
          piVar8 = &DAT_00002004;
          fStack_94 = pfStack_d4[1];
          fStack_90 = pfStack_d4[2];
          piStack_d8 = aiStack_80;
          do {
            pfVar4[1] = 0.0;
            *pfVar4 = 0.0;
            *piStack_d8 = 0;
            pfVar4[-1] = 0.0;
            iVar6 = 1;
            do {
              iVar2 = piVar8[-1] * iVar6 + iStack_c8;
              iVar1 = *piVar8 * iVar6 + iStack_d0;
              if (local_b4 != 0) {
                if (iVar2 < 0) {
                  iVar2 = iVar2 + -1 + param_1;
                }
                else if (param_1 <= iVar2) {
                  iVar2 = iVar2 + (1 - param_1);
                }
              }
              if (iStack_b8 != 0) {
                if (iVar1 < 0) {
                  iVar1 = iVar1 + -1 + param_2;
                }
                else if (param_2 <= iVar1) {
                  iVar1 = iVar1 + (1 - param_2);
                }
              }
              if ((((iVar2 < 0) || (param_1 <= iVar2)) || (iVar1 < 0)) || (param_2 <= iVar1)) break;
              iVar2 = iVar1 * 0x41 + iVar2;
              fStack_a4 = param_3[iVar2 * 0xb] - fStack_98;
              fStack_a0 = param_3[iVar2 * 0xb + 1] - fStack_94;
              fStack_9c = param_3[iVar2 * 0xb + 2] - fStack_90;
              fVar10 = (float10)_VectorNormalize2(&fStack_a4,&fStack_a4);
              if ((NAN((float10)0) || NAN(fVar10)) == ((float10)0 == fVar10)) {
                pfVar4[-1] = fStack_a4;
                *piStack_d8 = 1;
                *pfVar4 = fStack_a0;
                pfVar4[1] = fStack_9c;
                break;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < 4);
            piStack_d8 = piStack_d8 + 1;
            piVar8 = piVar8 + 2;
            pfVar4 = pfVar4 + 3;
          } while ((int)piVar8 < 0x2044);
          fStack_bc = 0.0;
          uVar7 = 1;
          fStack_c0 = 0.0;
          puVar5 = auStack_60;
          fStack_c4 = 0.0;
          piVar8 = aiStack_80;
          iVar6 = 8;
          do {
            if ((*piVar8 != 0) && (aiStack_80[uVar7 & 7] != 0)) {
              _CrossProduct(auStack_60 + (uVar7 & 7) * 0xc,puVar5,&fStack_8c);
              fVar10 = (float10)_VectorNormalize2(&fStack_8c,&fStack_8c);
              if ((NAN(fVar10) || NAN((float10)___real_00000000)) ==
                  (fVar10 == (float10)___real_00000000)) {
                fStack_c4 = fStack_8c + fStack_c4;
                fStack_c0 = fStack_88 + fStack_c0;
                fStack_bc = fStack_84 + fStack_bc;
              }
            }
            piVar8 = piVar8 + 1;
            puVar5 = puVar5 + 0xc;
            uVar7 = uVar7 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          _VectorNormalize2(&fStack_c4,pfStack_d4 + 7);
          pfStack_d4 = pfStack_d4 + 0x2cb;
          iStack_d0 = iStack_d0 + 1;
        } while (iStack_d0 < param_2);
      }
      pfStack_cc = pfStack_cc + 0xb;
      iStack_c8 = iStack_c8 + 1;
    } while (iStack_c8 < param_1);
  }
  return;
}



// ===========================================
// Function: _InvertCtrl @ 00007f6c
// ===========================================

void __fastcall _InvertCtrl(int param_1,int param_2)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_38;
  int local_30;
  undefined4 local_2c [11];
  
  if (0 < param_2) {
    puVar3 = in_EAX + param_1 * 0xb + -0xb;
    local_38 = in_EAX;
    local_30 = param_2;
    do {
      puVar2 = local_38;
      puVar4 = puVar3;
      iVar5 = param_1 / 2;
      if (0 < param_1 / 2) {
        do {
          puVar6 = puVar2;
          puVar7 = local_2c;
          for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar6 = puVar4;
          puVar7 = puVar2;
          for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          iVar5 = iVar5 + -1;
          puVar6 = local_2c;
          puVar7 = puVar4;
          for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar2 = puVar2 + 0xb;
          puVar4 = puVar4 + -0xb;
        } while (iVar5 != 0);
      }
      local_38 = local_38 + 0x2cb;
      puVar3 = puVar3 + 0x2cb;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
  }
  return;
}



// ===========================================
// Function: _InvertErrorTable @ 00008007
// ===========================================

void __fastcall _InvertErrorTable(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  undefined4 uStack_21c;
  undefined4 auStack_114 [68];
  
  iVar1 = 0;
  puVar2 = param_3;
  puVar4 = (undefined4 *)&stack0xfffffdf0;
  for (iVar3 = 0x82; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if (3 < param_2) {
    puVar2 = param_3 + 0x42;
    do {
      iVar3 = iVar1 * 4;
      iVar1 = iVar1 + 4;
      puVar2[-1] = *(undefined4 *)(&stack0xfffffdf0 + iVar3);
      *puVar2 = (&uStack_21c)[iVar1];
      puVar2[1] = *(undefined4 *)(&stack0xfffffde8 + iVar1 * 4);
      puVar2[2] = *(undefined4 *)(&stack0xfffffdec + iVar1 * 4);
      puVar2 = puVar2 + 4;
    } while (iVar1 < param_2 + -3);
  }
  if (iVar1 < param_2) {
    puVar2 = (undefined4 *)(&stack0xfffffdf0 + iVar1 * 4);
    puVar4 = param_3 + iVar1 + 0x41;
    for (param_2 = param_2 - iVar1; param_2 != 0; param_2 = param_2 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  iVar1 = 0;
  if (3 < unaff_EBX) {
    iVar3 = (unaff_EBX - 4U >> 2) + 1;
    iVar1 = iVar3 * 4;
    puVar2 = param_3 + 2;
    puVar4 = auStack_114 + unaff_EBX;
    do {
      puVar2[-2] = puVar4[1];
      iVar3 = iVar3 + -1;
      puVar2[-1] = *puVar4;
      *puVar2 = puVar4[-1];
      puVar2[1] = puVar4[-2];
      puVar2 = puVar2 + 4;
      puVar4 = puVar4 + -4;
    } while (iVar3 != 0);
  }
  if (iVar1 < unaff_EBX) {
    puVar2 = auStack_114 + (unaff_EBX - iVar1) + 1;
    do {
      iVar3 = iVar1 + 1;
      param_3[iVar1] = *puVar2;
      puVar2 = puVar2 + -1;
      iVar1 = iVar3;
    } while (iVar3 < unaff_EBX);
  }
  return;
}



// ===========================================
// Function: _PutPointsOnCurve @ 000080dd
// ===========================================

void _PutPointsOnCurve(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int local_5c;
  
  if (0 < param_2) {
    local_5c = param_2;
    do {
      if (1 < param_3) {
        iVar1 = (param_3 - 2U >> 1) + 1;
        do {
          _LerpDrawVert();
          _LerpDrawVert();
          _LerpDrawVert();
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      local_5c = local_5c + -1;
    } while (local_5c != 0);
  }
  local_5c = param_3;
  if (0 < param_3) {
    do {
      if (1 < param_2) {
        iVar1 = (param_2 - 2U >> 1) + 1;
        do {
          _LerpDrawVert();
          _LerpDrawVert();
          _LerpDrawVert();
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      local_5c = local_5c + -1;
    } while (local_5c != 0);
  }
  return;
}



// ===========================================
// Function: _R_SubdividePatchToGrid @ 000081e1
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
_R_SubdividePatchToGrid
          (int param_1,int param_2,float param_3,undefined4 *param_4,undefined4 param_5,
          undefined4 param_6,int param_7,int param_8)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  float *pfVar18;
  float *pfVar19;
  undefined4 *puVar20;
  float *pfVar21;
  undefined4 *puVar22;
  float10 fVar23;
  float10 fVar24;
  float10 fVar25;
  float10 fVar26;
  float10 extraout_ST1;
  undefined4 *puStack_2d90c;
  int iStack_2d908;
  int iStack_2d900;
  float fStack_2d8fc;
  undefined4 *puStack_2d8f8;
  float *pfStack_2d8f4;
  float *pfStack_2d8f0;
  int iStack_2d8ec;
  float fStack_2d8e8;
  undefined4 *puStack_2d8e4;
  float fStack_2d8e0;
  float fStack_2d8dc;
  float fStack_2d8d8;
  float fStack_2d8d4;
  float fStack_2d8d0;
  float fStack_2d8cc;
  float fStack_2d8c8;
  float afStack_2d8b8 [4];
  float fStack_2d8a8;
  float fStack_2d8a4;
  float afStack_2d88c [11];
  float afStack_2d860 [11];
  undefined1 auStack_2d834 [8];
  float afStack_2d82c [65];
  undefined4 uStack_2d728;
  undefined1 auStack_2d724 [248];
  float afStack_2d62c [6];
  undefined4 auStack_2d614 [5];
  float afStack_2d600 [11];
  undefined4 auStack_2d5d4 [1408];
  undefined4 auStack_2bfd4 [45045];
  
  if (0 < param_1) {
    puStack_2d90c = param_4;
    iVar8 = param_1;
    do {
      if (0 < param_2) {
        iVar11 = param_2;
        puVar5 = puStack_2d90c;
        puVar4 = (undefined4 *)(((int)afStack_2d62c - (int)param_4) + (int)puStack_2d90c);
        do {
          iVar11 = iVar11 + -1;
          puVar20 = puVar5;
          puVar22 = puVar4;
          for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar22 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar22 = puVar22 + 1;
          }
          puVar5 = puVar5 + param_1 * 0xb;
          puVar4 = puVar4 + 0x2cb;
        } while (iVar11 != 0);
      }
      puStack_2d90c = puStack_2d90c + 0xb;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  fVar23 = (float10)___real_4000000000000000;
  pfVar17 = afStack_2d82c;
  fVar24 = (float10)___real_3fd0000000000000;
  fVar25 = (float10)1;
  iStack_2d908 = 2;
  iVar8 = param_2;
  do {
    param_2 = iVar8;
    pfVar15 = pfVar17 + -2;
    for (iVar8 = 0x41; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pfVar15 = 0.0;
      pfVar15 = pfVar15 + 1;
    }
    iVar8 = param_1;
    if (2 < param_1) {
      pfStack_2d8f4 = afStack_2d600;
      pfVar15 = afStack_2d62c;
      pfVar18 = pfVar17 + -1;
      iVar11 = 2;
      iStack_2d8ec = 3;
      iVar7 = param_1;
      pfStack_2d8f0 = pfVar17;
      do {
        fStack_2d8fc = 0.0;
        if (param_2 < 1) {
          fVar26 = (float10)0.0;
        }
        else {
          puStack_2d8f8 = (undefined4 *)param_2;
          pfVar14 = pfVar15;
          pfVar3 = pfVar15;
          while( true ) {
            fStack_2d8e8 = (float)(((float10)pfVar14[0xb] * fVar23 + (float10)*pfVar14 +
                                   (float10)pfVar14[0x16]) * fVar24) - *pfVar3;
            puStack_2d8e4 =
                 (undefined4 *)
                 ((float)(((float10)pfVar14[0xc] * fVar23 + (float10)pfVar14[1] +
                          (float10)pfVar14[0x17]) * fVar24) - pfVar3[1]);
            fStack_2d8e0 = (float)(fVar24 * ((float10)pfVar14[0x18] +
                                            (float10)pfVar14[2] + (float10)pfVar14[0xd] * fVar23)) -
                           pfVar3[2];
            fStack_2d8dc = pfVar3[0x16] - *pfVar3;
            fStack_2d8d8 = pfVar3[0x17] - pfVar3[1];
            fStack_2d8d4 = pfVar3[0x18] - pfVar3[2];
            _VectorNormalize(&fStack_2d8dc);
            fStack_2d8c8 = fStack_2d8d4 * fStack_2d8e0 +
                           (float)puStack_2d8e4 * fStack_2d8d8 + fStack_2d8e8 * fStack_2d8dc;
            fStack_2d8d0 = fStack_2d8c8 * fStack_2d8dc;
            fStack_2d8cc = fStack_2d8c8 * fStack_2d8d8;
            fStack_2d8c8 = fStack_2d8c8 * fStack_2d8d4;
            fStack_2d8e8 = fStack_2d8e8 - fStack_2d8d0;
            puStack_2d8e4 = (undefined4 *)((float)puStack_2d8e4 - fStack_2d8cc);
            fStack_2d8e0 = fStack_2d8e0 - fStack_2d8c8;
            fVar25 = (float10)_VectorLength(&fStack_2d8e8);
            fVar1 = (float)fVar25;
            fVar26 = (float10)fStack_2d8fc;
            if (fVar26 < (float10)fVar1 != (NAN(fVar26) || NAN((float10)fVar1))) {
              fVar26 = (float10)fVar1;
              fStack_2d8fc = fVar1;
            }
            pfVar14 = pfVar14 + 0x2cb;
            pfVar3 = pfVar3 + 0x2cb;
            puStack_2d8f8 = (undefined4 *)((int)puStack_2d8f8 + -1);
            if (puStack_2d8f8 == (undefined4 *)0x0) break;
            fVar23 = (float10)___real_4000000000000000;
            fVar24 = (float10)___real_3fd0000000000000;
          }
          fVar24 = (float10)___real_3fd0000000000000;
          fVar23 = (float10)___real_4000000000000000;
          fVar25 = (float10)1;
          iVar7 = param_1;
        }
        if (fVar26 < (float10)___real_3fb999999999999a ==
            (NAN(fVar26) || NAN((float10)___real_3fb999999999999a))) {
          iVar8 = iVar7 + 2;
          if (iVar8 < 0x42) {
            if ((float10)param_3 < fVar26) {
              *pfStack_2d8f0 = (float)(fVar25 / fVar26);
              if (0 < param_2) {
                iVar16 = 0;
                puStack_2d8f8 = (undefined4 *)param_2;
                pfVar14 = pfStack_2d8f4;
                iVar7 = iVar7 + 1;
                do {
                  iVar9 = iVar7;
                  _LerpDrawVert();
                  _LerpDrawVert();
                  _LerpDrawVert();
                  if (iStack_2d8ec < iVar7) {
                    iVar12 = iVar7 - iStack_2d8ec;
                    pfVar3 = afStack_2d62c + (iVar7 + iVar16) * 0xb;
                    do {
                      iVar12 = iVar12 + -1;
                      pfVar19 = pfVar3 + -0x16;
                      pfVar21 = pfVar3;
                      for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                        *pfVar21 = *pfVar19;
                        pfVar19 = pfVar19 + 1;
                        pfVar21 = pfVar21 + 1;
                      }
                      pfVar3 = pfVar3 + -0xb;
                    } while (iVar12 != 0);
                  }
                  pfVar3 = afStack_2d8b8;
                  pfVar19 = pfVar14;
                  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *pfVar19 = *pfVar3;
                    pfVar3 = pfVar3 + 1;
                    pfVar19 = pfVar19 + 1;
                  }
                  pfVar3 = afStack_2d860;
                  pfVar19 = pfVar14 + 0xb;
                  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *pfVar19 = *pfVar3;
                    pfVar3 = pfVar3 + 1;
                    pfVar19 = pfVar19 + 1;
                  }
                  pfVar3 = pfVar14 + 0x16;
                  iVar16 = iVar16 + 0x41;
                  pfVar14 = pfVar14 + 0x2cb;
                  puStack_2d8f8 = (undefined4 *)((int)puStack_2d8f8 + -1);
                  pfVar19 = afStack_2d88c;
                  for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *pfVar3 = *pfVar19;
                    pfVar19 = pfVar19 + 1;
                    pfVar3 = pfVar3 + 1;
                  }
                  iVar7 = iVar9;
                } while (puStack_2d8f8 != (undefined4 *)0x0);
                fVar24 = (float10)___real_3fd0000000000000;
                fVar23 = (float10)___real_4000000000000000;
                fVar25 = (float10)1;
              }
              pfStack_2d8f0 = pfStack_2d8f0 + -2;
              iStack_2d8ec = iStack_2d8ec + -2;
              pfStack_2d8f4 = pfStack_2d8f4 + -0x16;
              pfVar18 = pfVar18 + -2;
              pfVar15 = pfVar15 + -0x16;
              iVar11 = iVar11 + -2;
              param_1 = iVar8;
            }
            else {
              *pfVar18 = (float)(fVar25 / fVar26);
              iVar8 = iVar7;
            }
          }
          else {
            *pfVar18 = (float)(fVar25 / fVar26);
            iVar8 = iVar7;
          }
        }
        else {
          *pfVar18 = ___real_4479c000;
          iVar8 = iVar7;
        }
        pfStack_2d8f0 = pfStack_2d8f0 + 2;
        iStack_2d8ec = iStack_2d8ec + 2;
        pfStack_2d8f4 = pfStack_2d8f4 + 0x16;
        iVar11 = iVar11 + 2;
        pfVar18 = pfVar18 + 2;
        pfVar15 = pfVar15 + 0x16;
        iVar7 = iVar8;
      } while (iVar11 < iVar8);
    }
    fVar25 = (float10)_Transpose(iVar8,param_2,afStack_2d62c);
    param_1 = param_2;
    pfVar17 = pfVar17 + 0x41;
    iStack_2d908 = iStack_2d908 + -1;
    fVar24 = extraout_ST1;
  } while (iStack_2d908 != 0);
  _PutPointsOnCurve(afStack_2d62c,param_2,iVar8);
  iVar11 = param_2 + -1;
  iVar7 = param_2;
  if (1 < iVar11) {
    pfVar17 = afStack_2d82c;
    puStack_2d90c = auStack_2d5d4;
    puStack_2d8f8 = (undefined4 *)0x2;
    do {
      if ((NAN((double)pfVar17[-1]) || NAN(___real_408f380000000000)) !=
          ((double)pfVar17[-1] == ___real_408f380000000000)) {
        if ((int)puStack_2d8f8 < param_2) {
          iVar16 = param_2 - (int)puStack_2d8f8;
          pfVar15 = pfVar17;
          pfVar18 = pfVar17 + -1;
          for (iVar7 = iVar16; puVar5 = puStack_2d90c, iVar7 != 0; iVar7 = iVar7 + -1) {
            *pfVar18 = *pfVar15;
            pfVar15 = pfVar15 + 1;
            pfVar18 = pfVar18 + 1;
          }
          do {
            puVar4 = puVar5;
            iVar7 = iVar8;
            if (0 < iVar8) {
              do {
                iVar7 = iVar7 + -1;
                puVar20 = puVar4;
                puVar22 = puVar4 + -0xb;
                for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *puVar22 = *puVar20;
                  puVar20 = puVar20 + 1;
                  puVar22 = puVar22 + 1;
                }
                puVar4 = puVar4 + 0x2cb;
              } while (iVar7 != 0);
            }
            puVar5 = puVar5 + 0xb;
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
        }
        param_2 = param_2 + -1;
        iVar11 = iVar11 + -1;
      }
      puStack_2d90c = puStack_2d90c + 0xb;
      pfVar17 = pfVar17 + 1;
      bVar2 = (int)puStack_2d8f8 < iVar11;
      iVar7 = param_2;
      puStack_2d8f8 = (undefined4 *)((int)puStack_2d8f8 + 1);
    } while (bVar2);
  }
  iStack_2d900 = iVar8 + -1;
  param_2 = iVar8;
  if (1 < iStack_2d900) {
    puVar5 = auStack_2bfd4;
    puVar4 = &uStack_2d728;
    iVar8 = 2;
    do {
      if ((NAN((double)(float)puVar4[-1]) || NAN(___real_408f380000000000)) !=
          ((double)(float)puVar4[-1] == ___real_408f380000000000)) {
        if (iVar8 < param_2) {
          param_2 = param_2 - iVar8;
          puVar20 = puVar4;
          puVar22 = puVar4 + -1;
          for (iVar11 = param_2; puVar13 = puVar5, iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar22 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar22 = puVar22 + 1;
          }
          do {
            if (0 < iVar7) {
              puVar20 = puVar13;
              puVar22 = puVar13 + -0x2cb;
              for (uVar10 = (uint)(iVar7 * 0x2c) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar22 = *puVar20;
                puVar20 = puVar20 + 1;
                puVar22 = puVar22 + 1;
              }
            }
            puVar13 = puVar13 + 0x2cb;
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
        param_2 = iStack_2d900;
      }
      iStack_2d900 = param_2 + -1;
      puVar5 = puVar5 + 0x2cb;
      puVar4 = puVar4 + 1;
      bVar2 = iVar8 < iStack_2d900;
      iVar8 = iVar8 + 1;
    } while (bVar2);
  }
  iStack_2d8ec = iVar7;
  if (iVar7 < param_2) {
    _Transpose(iVar7,param_2,afStack_2d62c);
    _InvertErrorTable(auStack_2d834);
    _InvertCtrl();
    iStack_2d8ec = param_2;
    param_2 = iVar7;
  }
  _MakeMeshNormals(iStack_2d8ec,param_2,afStack_2d62c);
  puVar5 = (undefined4 *)(*___chkstk)((iStack_2d8ec * param_2 + 2) * 0x2c);
  pvVar6 = (void *)(*___chkstk)(iStack_2d8ec * 4);
  puVar5[0x14] = pvVar6;
  _memcpy(pvVar6,auStack_2d834,iStack_2d8ec * 4);
  pvVar6 = (void *)(*___chkstk)(param_2 * 4);
  puVar5[0x15] = pvVar6;
  _memcpy(pvVar6,auStack_2d724,param_2 * 4);
  puVar5[0x12] = iStack_2d8ec;
  puVar5[0x13] = param_2;
  *puVar5 = 3;
  _ClearBounds(puVar5 + 3,puVar5 + 6);
  if (0 < iStack_2d8ec) {
    puStack_2d8f8 = auStack_2d614;
    puStack_2d8e4 = puVar5 + 0x16;
    iVar8 = iStack_2d8ec;
    do {
      iVar11 = iVar8;
      if (0 < param_2) {
        pfStack_2d8f4 = (float *)puStack_2d8f8;
        puVar4 = puStack_2d8e4;
        pfStack_2d8f0 = (float *)param_2;
        do {
          pfVar17 = pfStack_2d8f4;
          puVar20 = puVar4;
          for (iVar11 = 0xb; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar20 = *pfVar17;
            pfVar17 = pfVar17 + 1;
            puVar20 = puVar20 + 1;
          }
          _AddPointToBounds(puVar4,puVar5 + 3,puVar5 + 6);
          puVar4 = puVar4 + iVar8 * 0xb;
          pfStack_2d8f4 = pfStack_2d8f4 + 0x2cb;
          pfStack_2d8f0 = (float *)((int)pfStack_2d8f0 + -1);
          iVar11 = param_7;
          param_2 = param_8;
        } while (pfStack_2d8f0 != (float *)0x0);
      }
      puStack_2d8f8 = puStack_2d8f8 + 0xb;
      puStack_2d8e4 = puStack_2d8e4 + 0xb;
      iStack_2d8ec = iStack_2d8ec + -1;
      iVar8 = iVar11;
    } while (iStack_2d8ec != 0);
  }
  fVar1 = (float)___real_3fe0000000000000;
  afStack_2d8b8[3] = ((float)puVar5[6] + (float)puVar5[3]) * fVar1;
  puVar5[9] = afStack_2d8b8[3];
  puVar5[10] = ((float)puVar5[7] + (float)puVar5[4]) * fVar1;
  puVar5[0xb] = ((float)puVar5[8] + (float)puVar5[5]) * fVar1;
  afStack_2d8b8[3] = (float)puVar5[3] - afStack_2d8b8[3];
  fStack_2d8a8 = (float)puVar5[4] - (float)puVar5[10];
  fStack_2d8a4 = (float)puVar5[5] - (float)puVar5[0xb];
  fVar25 = (float10)_VectorLength(afStack_2d8b8 + 3);
  puVar5[0xc] = (float)fVar25;
  puVar5[0xd] = puVar5[9];
  puVar5[0xe] = puVar5[10];
  puVar5[0xf] = puVar5[0xb];
  puVar5[0x10] = (float)fVar25;
  return puVar5;
}



