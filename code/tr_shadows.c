// ===========================================
// Function: _R_AddEdgeDef @ 007b3900
// ===========================================

void _R_AddEdgeDef(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&_numEdgeDefs)[param_1];
  if (iVar1 != 0x20) {
    iVar2 = param_1 * 0x20 + iVar1;
    (&_edgeDefs)[iVar2 * 2] = param_2;
    (&DAT_0003c984)[iVar2 * 2] = param_3;
    (&_numEdgeDefs)[param_1] = iVar1 + 1;
  }
  return;
}



// ===========================================
// Function: _R_RenderShadowEdges @ 007b393c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_RenderShadowEdges(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined1 *local_14;
  int local_10;
  int *local_c;
  int local_8 [2];
  
  iVar4 = 0;
  if (0 < _DAT_00acd4b4) {
    local_14 = &DAT_008660e0;
    local_c = &_edgeDefs;
    do {
      local_10 = (&_numEdgeDefs)[iVar4];
      piVar5 = local_c;
      if (0 < local_10) {
        do {
          if (piVar5[1] != 0) {
            iVar1 = *piVar5;
            iVar3 = (&_numEdgeDefs)[iVar1];
            local_8[0] = 0;
            local_8[1] = 0;
            if (0 < iVar3) {
              piVar2 = &DAT_0003c984 + iVar1 * 0x40;
              do {
                if (piVar2[-1] == iVar4) {
                  local_8[*piVar2] = local_8[*piVar2] + 1;
                }
                piVar2 = piVar2 + 2;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
              if (local_8[1] != 0) goto LAB_007b3a35;
            }
            (*__qglVertex3fv)(local_14);
            (*__qglVertex3fv)(&DAT_008660e0 + (_DAT_00acd4b4 + iVar4) * 0x10);
            (*__qglVertex3fv)(&DAT_008660e0 + iVar1 * 0x10);
            (*__qglVertex3fv)(&DAT_008660e0 + (_DAT_00acd4b4 + iVar4) * 0x10);
            (*__qglVertex3fv)(&DAT_008660e0 + (_DAT_00acd4b4 + iVar1) * 0x10);
            (*__qglVertex3fv)(&DAT_008660e0 + iVar1 * 0x10);
          }
LAB_007b3a35:
          local_10 = local_10 + -1;
          piVar5 = piVar5 + 2;
        } while (local_10 != 0);
      }
      local_14 = local_14 + 0x10;
      iVar4 = iVar4 + 1;
      local_c = local_c + 0x40;
    } while (iVar4 < _DAT_00acd4b4);
  }
  return;
}



// ===========================================
// Function: _RB_ShadowTessEnd @ 007b3a6b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_ShadowTessEnd(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float unaff_retaddr;
  int *local_30;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((_DAT_00acd4b4 < 15000) && (3 < _DAT_007b78e0)) {
    fVar1 = *(float *)(_DAT_007b69e0 + 0x1d8);
    fVar2 = *(float *)(_DAT_007b69e0 + 0x1dc);
    fVar3 = *(float *)(_DAT_007b69e0 + 0x1e0);
    iVar9 = 0;
    if (0 < _DAT_00acd4b4) {
      fVar8 = (float)___real_4034000000000000;
      pfVar11 = (float *)&DAT_008660e4;
      do {
        *(float *)(&DAT_008660e0 + (_DAT_00acd4b4 + iVar9) * 0x10) = pfVar11[-1] - fVar1 * fVar8;
        *(float *)(&DAT_008660e4 + (_DAT_00acd4b4 + iVar9) * 0x10) = *pfVar11 - fVar2 * fVar8;
        iVar13 = _DAT_00acd4b4 + iVar9;
        iVar9 = iVar9 + 1;
        *(float *)(&DAT_008660e8 + iVar13 * 0x10) = pfVar11[1] - fVar3 * fVar8;
        pfVar11 = pfVar11 + 4;
      } while (iVar9 < _DAT_00acd4b4);
    }
    _memset(&_numEdgeDefs,0,_DAT_00acd4b4 * 4);
    iVar9 = _DAT_00acd4b0 / 3;
    iVar13 = 0;
    if (0 < iVar9) {
      local_30 = (int *)&DAT_007b6464;
      do {
        iVar4 = *local_30;
        iVar5 = local_30[-1];
        iVar6 = local_30[1];
        iVar12 = iVar4 * 0x10;
        iVar10 = iVar5 * 0x10;
        local_c = *(float *)(&DAT_008660e0 + iVar12) - *(float *)(&DAT_008660e0 + iVar10);
        iVar14 = iVar6 * 0x10;
        local_8 = *(float *)(&DAT_008660e4 + iVar12) - *(float *)(&DAT_008660e4 + iVar10);
        local_4 = *(float *)(&DAT_008660e8 + iVar12) - *(float *)(&DAT_008660e8 + iVar10);
        local_18 = *(float *)(&DAT_008660e0 + iVar14) - *(float *)(&DAT_008660e0 + iVar10);
        local_14 = *(float *)(&DAT_008660e4 + iVar14) - *(float *)(&DAT_008660e4 + iVar10);
        local_10 = *(float *)(&DAT_008660e8 + iVar14) - *(float *)(&DAT_008660e8 + iVar10);
        _CrossProduct(&local_c,&local_18,&stack0x00000000);
        if (param_2 * fStack_1c + unaff_retaddr * fStack_24 + param_1 * fStack_20 <=
            ___real_00000000) {
          *(undefined4 *)(iVar13 * 4 + 0x2000) = 0;
        }
        else {
          *(undefined4 *)(iVar13 * 4 + 0x2000) = 1;
        }
        iVar10 = (&_numEdgeDefs)[iVar5];
        if (iVar10 != 0x20) {
          uVar7 = *(undefined4 *)(iVar13 * 4 + 0x2000);
          iVar12 = iVar5 * 0x20 + iVar10;
          (&_edgeDefs)[iVar12 * 2] = iVar4;
          (&DAT_0003c984)[iVar12 * 2] = uVar7;
          (&_numEdgeDefs)[iVar5] = iVar10 + 1;
        }
        iVar10 = (&_numEdgeDefs)[iVar4];
        if (iVar10 != 0x20) {
          uVar7 = *(undefined4 *)(iVar13 * 4 + 0x2000);
          iVar12 = iVar4 * 0x20 + iVar10;
          (&_edgeDefs)[iVar12 * 2] = iVar6;
          (&DAT_0003c984)[iVar12 * 2] = uVar7;
          (&_numEdgeDefs)[iVar4] = iVar10 + 1;
        }
        iVar4 = (&_numEdgeDefs)[iVar6];
        if (iVar4 != 0x20) {
          uVar7 = *(undefined4 *)(iVar13 * 4 + 0x2000);
          iVar10 = iVar6 * 0x20 + iVar4;
          (&_edgeDefs)[iVar10 * 2] = iVar5;
          (&DAT_0003c984)[iVar10 * 2] = uVar7;
          (&_numEdgeDefs)[iVar6] = iVar4 + 1;
        }
        local_30 = local_30 + 3;
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar9);
    }
    _GL_Bind(_DAT_007b64f4);
    (*__qglEnable)(0xb44);
    _GL_State(0x12);
    (*__qglColor3f)(___real_3e4ccccd,___real_3e4ccccd,___real_3e4ccccd);
    (*__qglColorMask)(0,0,0,0);
    (*__qglEnable)(0xb90);
    (*__qglStencilFunc)(0x207,1,0xff);
    if (_DAT_007b67b8 != 0) {
      (*__qglCullFace)(0x404);
      (*__qglStencilOp)(0x1e00,0x1e00,0x1e02);
      _R_RenderShadowEdges();
      (*__qglCullFace)(0x405);
      (*__qglStencilOp)(0x1e00,0x1e00,0x1e03);
      _R_RenderShadowEdges();
      (*__qglColorMask)(1,1,1,1);
      return;
    }
    (*__qglCullFace)(0x405);
    (*__qglStencilOp)(0x1e00,0x1e00,0x1e02);
    (*__qglBegin)(4);
    _R_RenderShadowEdges();
    (*__qglEnd)();
    (*__qglCullFace)(0x404);
    (*__qglStencilOp)(0x1e00,0x1e00,0x1e03);
    (*__qglBegin)(4);
    _R_RenderShadowEdges();
    (*__qglEnd)();
    (*__qglColorMask)(1,1,1,1);
  }
  return;
}



// ===========================================
// Function: _RB_ShadowFinish @ 007b3e32
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_ShadowFinish(void)

{
  if ((*(int *)(__r_shadows + 0x20) == 2) && (3 < _DAT_007b78e0)) {
    (*__qglEnable)(0xb90);
    (*__qglStencilFunc)(0x205,0,0xff);
    (*__qglDisable)(0x3000);
    (*__qglDisable)(0xb44);
    _GL_Bind(_DAT_007b64f4);
    (*__qglLoadIdentity)();
    (*__qglColor3f)(___real_3f19999a,___real_3f19999a,___real_3f19999a);
    _GL_State(0x113);
    (*__qglBegin)(7);
    (*__qglVertex3f)(___real_c2c80000,___real_42c80000,___real_c1200000);
    (*__qglVertex3f)(___real_42c80000,___real_42c80000,___real_c1200000);
    (*__qglVertex3f)(___real_42c80000,___real_c2c80000,___real_c1200000);
    (*__qglVertex3f)(___real_c2c80000,___real_c2c80000,___real_c1200000);
    (*__qglEnd)();
    (*__qglColor4f)(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    (*__qglDisable)(0xb90);
  }
  return;
}



// ===========================================
// Function: _RB_CalcShadowImpactPolys @ 007b3f7d
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _RB_CalcShadowImpactPolys(float *param_1,float *param_2,float param_3,float param_4)

{
  int iVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iStack_1e80;
  float fStack_1e7c;
  float fStack_1e78;
  float fStack_1e74;
  undefined1 local_1e70 [12];
  float fStack_1e64;
  float fStack_1e60;
  float fStack_1e5c;
  float fStack_1e58;
  float fStack_1e54;
  float fStack_1e50;
  float fStack_1e48;
  float fStack_1e44;
  float fStack_1e40;
  float fStack_1e3c;
  float fStack_1e38;
  float fStack_1e34;
  float fStack_1e30;
  float fStack_1e2c;
  float fStack_1e28;
  float fStack_1e24;
  float fStack_1e20;
  float fStack_1e1c;
  float fStack_1e18;
  float fStack_1e14;
  float fStack_1e10;
  undefined1 auStack_1e0c [12];
  undefined1 auStack_1e00 [4];
  int aiStack_1dfc [767];
  undefined1 auStack_1200 [4];
  undefined4 auStack_11fc [1150];
  undefined4 uStack_4;
  
  uStack_4 = 0x7b3f87;
  if (NAN(param_3) == (param_3 == 0.0)) {
    _VectorNormalize2(param_1,local_1e70);
    _PerpendicularVector(&fStack_1e64,local_1e70);
    _RotatePointAroundVector(&fStack_1e58,local_1e70,&fStack_1e64,param_3);
    _CrossProduct(local_1e70,&fStack_1e58,&fStack_1e64);
  }
  else {
    _VectorNormalize2(param_1,local_1e70);
    fStack_1e74 = param_1[2];
    fStack_1e7c = -*param_1;
    fStack_1e78 = -param_1[1];
    vectoangles(&fStack_1e7c,auStack_1e0c);
    _AnglesToAxis(auStack_1e0c,local_1e70);
    fVar2 = (float)___real_bff0000000000000;
    fStack_1e58 = fStack_1e58 * fVar2;
    fStack_1e54 = fStack_1e54 * fVar2;
    fStack_1e50 = fVar2 * fStack_1e50;
  }
  fStack_1e18 = *param_2 - param_4 * fStack_1e64;
  fVar2 = fStack_1e58 * param_4;
  fStack_1e3c = fStack_1e18 - fVar2;
  fStack_1e24 = *param_2 + param_4 * fStack_1e64;
  fStack_1e30 = fStack_1e24 - fVar2;
  fStack_1e24 = fStack_1e24 + fVar2;
  fStack_1e18 = fStack_1e18 + fVar2;
  fStack_1e14 = param_2[1] - fStack_1e60 * param_4;
  fVar2 = fStack_1e54 * param_4;
  fStack_1e38 = fStack_1e14 - fVar2;
  fStack_1e20 = param_2[1] + fStack_1e60 * param_4;
  fStack_1e2c = fStack_1e20 - fVar2;
  fStack_1e20 = fStack_1e20 + fVar2;
  fStack_1e14 = fStack_1e14 + fVar2;
  fStack_1e10 = param_2[2] - fStack_1e5c * param_4;
  fVar2 = fStack_1e50 * param_4;
  fStack_1e34 = fStack_1e10 - fVar2;
  fStack_1e1c = param_2[2] + fStack_1e5c * param_4;
  fStack_1e28 = fStack_1e1c - fVar2;
  fStack_1e1c = fStack_1e1c + fVar2;
  fStack_1e10 = fStack_1e10 + fVar2;
  fStack_1e40 = (float)___real_c040000000000000;
  fStack_1e48 = *param_1 * fStack_1e40;
  fStack_1e44 = param_1[1] * fStack_1e40;
  fStack_1e40 = fStack_1e40 * param_1[2];
  _planeNum = _CM_MarkFragments(4,&fStack_1e3c,&fStack_1e48,0x180,auStack_1200,0x80,auStack_1e00);
  if (0 < _planeNum) {
    iVar5 = 0;
    piVar8 = aiStack_1dfc;
    iStack_1e80 = _planeNum;
    do {
      iVar1 = *piVar8;
      iVar6 = 0;
      if (3 < iVar1) {
        iVar7 = (iVar1 - 4U >> 2) + 1;
        iVar6 = iVar7 * 4;
        puVar3 = auStack_11fc + piVar8[-1] * 3;
        puVar4 = (undefined4 *)(&DAT_007b644c + iVar5);
        do {
          puVar4[-1] = puVar3[-1];
          iVar7 = iVar7 + -1;
          *puVar4 = *puVar3;
          puVar4[1] = puVar3[1];
          puVar4[2] = puVar3[2];
          puVar4[3] = puVar3[3];
          puVar4[4] = puVar3[4];
          puVar4[5] = puVar3[5];
          puVar4[6] = puVar3[6];
          puVar4[7] = puVar3[7];
          puVar4[8] = puVar3[8];
          puVar4[9] = puVar3[9];
          puVar4[10] = puVar3[10];
          puVar3 = puVar3 + 0xc;
          puVar4 = puVar4 + 0xc;
        } while (iVar7 != 0);
      }
      if (iVar6 < iVar1) {
        iVar7 = iVar1 - iVar6;
        puVar3 = auStack_11fc + (piVar8[-1] + iVar6) * 3;
        puVar4 = (undefined4 *)(&DAT_007b644c + iVar6 * 0xc + iVar5);
        do {
          puVar4[-1] = puVar3[-1];
          iVar7 = iVar7 + -1;
          *puVar4 = *puVar3;
          puVar4[1] = puVar3[1];
          puVar3 = puVar3 + 3;
          puVar4 = puVar4 + 3;
        } while (iVar7 != 0);
      }
      iVar6 = piVar8[4];
      *(int *)(&DAT_007b64fc + iVar5) = iVar1;
      *(int *)(&DAT_007b650c + iVar5) = iVar6;
      iStack_1e80 = iStack_1e80 + -1;
      *(int *)(&_qglDisable + iVar5) = piVar8[1];
      *(int *)(&DAT_007b6504 + iVar5) = piVar8[2];
      *(int *)(&_r_shadows + iVar5) = piVar8[3];
      iVar5 = iVar5 + 200;
      piVar8 = piVar8 + 6;
    } while (iStack_1e80 != 0);
    return;
  }
  return;
}



// ===========================================
// Function: _PointInPoly @ 007b42b0
// ===========================================

bool _PointInPoly(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_c;
  int local_8;
  
  iVar3 = (param_4 + 1) % 3;
  bVar1 = false;
  bVar9 = false;
  iVar7 = param_1 + -1;
  iVar4 = (param_4 + 2) % 3;
  iVar2 = 0;
  local_8 = 0;
  if (3 < param_1) {
    local_c = 0x24;
    pfVar6 = (float *)(param_2 + 0x18 + iVar4 * 4);
    pfVar5 = (float *)(param_2 + 0x18 + iVar3 * 4);
    iVar8 = iVar7 * 0xc;
    do {
      if ((((pfVar6[-6] <= *(float *)(param_3 + iVar4 * 4)) &&
           (*(float *)(param_3 + iVar4 * 4) < *(float *)(iVar8 + iVar4 * 4 + param_2))) ||
          ((*(float *)(iVar8 + iVar4 * 4 + param_2) <= *(float *)(param_3 + iVar4 * 4) &&
           (*(float *)(param_3 + iVar4 * 4) <= pfVar6[-6])))) &&
         (*(float *)(param_3 + iVar3 * 4) <=
          ((*(float *)(param_3 + iVar4 * 4) - pfVar6[-6]) *
          (*(float *)(iVar8 + iVar3 * 4 + param_2) - pfVar5[-6])) /
          (*(float *)(iVar8 + iVar4 * 4 + param_2) - pfVar6[-6]) + pfVar5[-6])) {
        bVar9 = !bVar1;
        bVar1 = bVar9;
      }
      if ((((pfVar6[-3] <= *(float *)(param_3 + iVar4 * 4)) &&
           (*(float *)(param_3 + iVar4 * 4) < pfVar6[-6])) ||
          ((pfVar6[-6] <= *(float *)(param_3 + iVar4 * 4) &&
           (*(float *)(param_3 + iVar4 * 4) < pfVar6[-3])))) &&
         (*(float *)(param_3 + iVar3 * 4) <
          ((*(float *)(param_3 + iVar4 * 4) - pfVar6[-3]) * (pfVar5[-6] - pfVar5[-3])) /
          (pfVar6[-6] - pfVar6[-3]) + pfVar5[-3])) {
        bVar9 = bVar9 == false;
        bVar1 = bVar9;
      }
      if ((((*pfVar6 <= *(float *)(param_3 + iVar4 * 4)) &&
           (*(float *)(param_3 + iVar4 * 4) < pfVar6[-3])) ||
          ((pfVar6[-3] <= *(float *)(param_3 + iVar4 * 4) &&
           (*(float *)(param_3 + iVar4 * 4) < *pfVar6)))) &&
         (*(float *)(param_3 + iVar3 * 4) <
          ((*(float *)(param_3 + iVar4 * 4) - *pfVar6) * (pfVar5[-3] - *pfVar5)) /
          (pfVar6[-3] - *pfVar6) + *pfVar5)) {
        bVar9 = bVar9 == false;
        bVar1 = bVar9;
      }
      if ((((pfVar6[3] <= *(float *)(param_3 + iVar4 * 4)) &&
           (*(float *)(param_3 + iVar4 * 4) <= *pfVar6)) ||
          ((*pfVar6 <= *(float *)(param_3 + iVar4 * 4) &&
           (*(float *)(param_3 + iVar4 * 4) <= pfVar6[3])))) &&
         (*(float *)(param_3 + iVar3 * 4) <
          ((*(float *)(param_3 + iVar4 * 4) - pfVar6[3]) * (*pfVar5 - pfVar5[3])) /
          (*pfVar6 - pfVar6[3]) + pfVar5[3])) {
        bVar9 = bVar9 == false;
        bVar1 = bVar9;
      }
      iVar7 = local_8 + 3;
      iVar2 = local_8 + 4;
      pfVar5 = pfVar5 + 0xc;
      pfVar6 = pfVar6 + 0xc;
      iVar8 = local_c;
      local_c = local_c + 0x30;
      local_8 = iVar2;
    } while (iVar2 < param_1 + -3);
  }
  if (iVar2 < param_1) {
    pfVar6 = (float *)(param_2 + (iVar2 * 3 + iVar3) * 4);
    param_1 = param_1 - iVar2;
    pfVar5 = (float *)(param_2 + (iVar2 * 3 + iVar4) * 4);
    iVar7 = iVar7 * 0xc;
    local_c = iVar2 * 0xc;
    do {
      if ((((*pfVar5 <= *(float *)(param_3 + iVar4 * 4)) &&
           (*(float *)(param_3 + iVar4 * 4) < *(float *)(iVar7 + iVar4 * 4 + param_2))) ||
          ((*(float *)(iVar7 + iVar4 * 4 + param_2) <= *(float *)(param_3 + iVar4 * 4) &&
           (*(float *)(param_3 + iVar4 * 4) < *pfVar5)))) &&
         (*(float *)(param_3 + iVar3 * 4) <
          ((*(float *)(param_3 + iVar4 * 4) - *pfVar5) *
          (*(float *)(iVar7 + iVar3 * 4 + param_2) - *pfVar6)) /
          (*(float *)(iVar7 + iVar4 * 4 + param_2) - *pfVar5) + *pfVar6)) {
        bVar9 = bVar9 == false;
      }
      pfVar6 = pfVar6 + 3;
      pfVar5 = pfVar5 + 3;
      param_1 = param_1 + -1;
      iVar7 = local_c;
      local_c = local_c + 0xc;
    } while (param_1 != 0);
  }
  return bVar9;
}



// ===========================================
// Function: _RB_ProjectionShadowDeform @ 007b460e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_ProjectionShadowDeform(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  float *pfVar17;
  int iVar18;
  int iStack_1a0;
  int *piStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float local_18c;
  float local_188;
  float local_184;
  int *piStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float local_160;
  float local_15c;
  float local_158;
  float fStack_154;
  int local_150;
  int local_14c;
  int local_148;
  int iStack_144;
  int iStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  undefined1 auStack_130 [24];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined1 auStack_f4 [36];
  float afStack_d0 [51];
  
  _shadowTriNum = 0;
  _shadowVertNum = 0;
  _planeNum = 0;
  local_160 = *(float *)(_DAT_007b69e0 + 0x48);
  local_15c = *(float *)(_DAT_007b69e0 + 0x4c);
  local_158 = *(float *)(_DAT_007b69e0 + 0x50);
  local_14c = 0;
  local_150 = 0;
  local_148 = 0;
  local_114 = 0;
  local_118 = 0;
  local_110 = ___real_bf800000;
  local_188 = (float)___real_4072c00000000000 * 0.0;
  local_18c = local_160 + local_188;
  local_188 = local_15c + local_188;
  local_184 = local_158 - (float)___real_4072c00000000000;
  iVar7 = (*_DAT_007b6608)();
  (**(code **)(iVar7 + 0x1c))
            (auStack_130,&local_160,0,0,&local_18c,0,&DAT_00010001,0,3,s_RB_ProjectionShadowDeform);
  _RB_CalcShadowImpactPolys(*(undefined4 *)(_DAT_007b69e0 + 0x1c4),___real_43160000);
  _TransposeMatrix(0x7b693c,auStack_f4);
  iVar7 = 0;
  if (0 < _planeNum) {
    pfVar14 = (float *)&DAT_007b6504;
    do {
      iVar13 = 0;
      if (0 < (int)pfVar14[-2]) {
        pfVar16 = pfVar14 + -0x2f;
        do {
          fStack_170 = *pfVar16 - local_160;
          fStack_16c = pfVar16[1] - local_15c;
          fStack_168 = pfVar16[2] - local_158;
          _MatrixTransformVector(&fStack_170,auStack_f4,pfVar16);
          iVar13 = iVar13 + 1;
          pfVar16 = pfVar16 + 3;
        } while (iVar13 < (int)pfVar14[-2]);
      }
      fStack_170 = pfVar14[-1];
      pfVar16 = pfVar14 + -1;
      fStack_16c = *pfVar14;
      fStack_168 = pfVar14[1];
      _MatrixTransformVector(&fStack_170,auStack_f4,pfVar16);
      _VectorNormalize(pfVar16);
      iVar13 = _planeNum;
      iVar7 = iVar7 + 1;
      pfVar14[2] = pfVar14[-0x2d] * pfVar14[1] +
                   pfVar14[-0x2f] * *pfVar16 + pfVar14[-0x2e] * *pfVar14;
      pfVar14 = pfVar14 + 0x32;
    } while (iVar7 < iVar13);
  }
  fVar1 = *(float *)(_DAT_007b69e0 + 0x1d8);
  fVar2 = *(float *)(_DAT_007b69e0 + 0x1dc);
  fVar3 = *(float *)(_DAT_007b69e0 + 0x1e0);
  fStack_190 = fVar3 + fVar1 * 0.0 + fVar2 * 0.0;
  if (fStack_190 < ___real_3f000000 != (NAN(fStack_190) || NAN(___real_3f000000))) {
    fVar6 = ((float)___real_3fe0000000000000 - fStack_190) * 0.0;
    fVar1 = fVar1 + fVar6;
    fVar2 = fVar2 + fVar6;
    fVar3 = fVar3 + ((float)___real_3fe0000000000000 - fStack_190);
    fStack_190 = fVar3 + fVar1 * 0.0 + fVar2 * 0.0;
  }
  fStack_190 = 1.0 / fStack_190;
  fStack_198 = fStack_190 * fVar1;
  fStack_194 = fStack_190 * fVar2;
  fStack_190 = fStack_190 * fVar3;
  if (0 < _DAT_00acd4b4) {
    iVar7 = 0;
    pfVar14 = (float *)&DAT_008660e0;
    iVar13 = _DAT_00acd4b4;
    do {
      iVar13 = iVar13 + -1;
      fStack_164 = *pfVar14 * 0.0 + pfVar14[1] * 0.0 + pfVar14[2] + 0.0;
      *(float *)(&_shadowVerts + iVar7) =
           *(float *)(&DAT_008660e0 + iVar7) - fStack_164 * fStack_198;
      *(float *)(&DAT_007b6454 + iVar7) =
           *(float *)(&DAT_008660e4 + iVar7) - fStack_194 * fStack_164;
      *(float *)(&_qglVertex3fv + iVar7) =
           *(float *)(&DAT_008660e8 + iVar7) - fStack_190 * fStack_164;
      iVar7 = iVar7 + 0x10;
      pfVar14 = pfVar14 + 4;
    } while (iVar13 != 0);
  }
  iVar7 = 0;
  _shadowVertNum = _DAT_00acd4b4;
  if (0 < _DAT_00acd4b0) {
    fVar6 = (float)___real_bfc999999999999a;
    piVar11 = (int *)(&DAT_007b6444 + _shadowTriNum * 0x1c);
    do {
      iVar13 = *(int *)(&DAT_007b6464 + iVar7 * 4);
      iVar8 = iVar13 * 0x10;
      fVar5 = *(float *)(iVar8 + 0x8db3e8) * fVar3 +
              *(float *)(iVar8 + 0x8db3e0) * fVar1 + *(float *)(iVar8 + 0x8db3e4) * fVar2;
      if (fVar5 < fVar6 == (NAN(fVar5) || NAN(fVar6))) {
        piVar11[-1] = *(int *)(&_tess + iVar7 * 4);
        iVar8 = *(int *)(&_qglEnd + iVar7 * 4);
        *piVar11 = iVar13;
        piVar11[1] = iVar8;
        piVar11[3] = 3;
        piVar11[4] = 0;
        _shadowTriNum = _shadowTriNum + 1;
        piVar11 = piVar11 + 7;
      }
      iVar7 = iVar7 + 3;
    } while (iVar7 < _DAT_00acd4b0);
  }
  iVar7 = _shadowTriNum;
  _DAT_00acd4b0 = 0;
  if (0 < _DAT_00acd4b4) {
    puVar9 = (undefined4 *)&_usedVerts;
    for (iVar13 = _DAT_00acd4b4; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar9 = 0xffffffff;
      puVar9 = puVar9 + 1;
    }
  }
  if (0 < iVar7) {
    puVar9 = (undefined4 *)&_qglVertex3fv;
    do {
      *puVar9 = 0;
      puVar9 = puVar9 + 7;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (_planeNum != 1 && -1 < _planeNum + -1) {
    piStack_180 = (int *)(_planeNum + -1);
    pfVar14 = (float *)&DAT_007b650c;
    iVar7 = 0;
    do {
      iVar8 = _planeNum;
      iVar13 = iVar7 + 1;
      local_18c = *pfVar14 * pfVar14[-3];
      local_188 = pfVar14[-2] * *pfVar14;
      local_184 = pfVar14[-1] * *pfVar14;
      if (iVar13 < _planeNum) {
        iVar12 = iVar13;
        if (3 < (int)piStack_180) {
          pfVar16 = pfVar14 + 0x31;
          do {
            fVar1 = pfVar16[1] * *pfVar16;
            if (local_184 < fVar1 != (NAN(local_184) || NAN(fVar1))) {
              iVar7 = iVar12;
              local_184 = fVar1;
            }
            fVar1 = pfVar16[0x33] * pfVar16[0x32];
            if (local_184 < fVar1 != (NAN(local_184) || NAN(fVar1))) {
              iVar7 = iVar12 + 1;
              local_184 = fVar1;
            }
            fVar1 = pfVar16[0x65] * pfVar16[100];
            if (local_184 < fVar1 != (NAN(local_184) || NAN(fVar1))) {
              iVar7 = iVar12 + 2;
              local_184 = fVar1;
            }
            fStack_174 = pfVar16[0x97] * pfVar16[0x96];
            if (local_184 < fStack_174 != (NAN(local_184) || NAN(fStack_174))) {
              iVar7 = iVar12 + 3;
              local_184 = fStack_174;
            }
            iVar12 = iVar12 + 4;
            pfVar16 = pfVar16 + 200;
          } while (iVar12 < _planeNum + -3);
        }
        if (iVar12 < _planeNum) {
          pfVar16 = (float *)(&_r_shadows + iVar12 * 200);
          do {
            fStack_174 = pfVar16[1] * *pfVar16;
            if (local_184 < fStack_174 != (NAN(local_184) || NAN(fStack_174))) {
              iVar7 = iVar12;
              local_184 = fStack_174;
            }
            iVar12 = iVar12 + 1;
            pfVar16 = pfVar16 + 0x32;
          } while (iVar12 < _planeNum);
        }
      }
      piStack_180 = (int *)((int)piStack_180 + -1);
      pfVar16 = pfVar14 + -0x31;
      pfVar17 = afStack_d0;
      for (iVar12 = 0x32; iVar12 != 0; iVar12 = iVar12 + -1) {
        *pfVar17 = *pfVar16;
        pfVar16 = pfVar16 + 1;
        pfVar17 = pfVar17 + 1;
      }
      pfVar16 = (float *)(&_psPlanes + iVar7 * 200);
      pfVar17 = pfVar14 + -0x31;
      for (iVar12 = 0x32; iVar12 != 0; iVar12 = iVar12 + -1) {
        *pfVar17 = *pfVar16;
        pfVar16 = pfVar16 + 1;
        pfVar17 = pfVar17 + 1;
      }
      pfVar14 = pfVar14 + 0x32;
      pfVar16 = afStack_d0;
      pfVar17 = (float *)(&_psPlanes + iVar7 * 200);
      for (iVar12 = 0x32; iVar12 != 0; iVar12 = iVar12 + -1) {
        *pfVar17 = *pfVar16;
        pfVar16 = pfVar16 + 1;
        pfVar17 = pfVar17 + 1;
      }
      iVar7 = iVar13;
    } while (iVar13 < iVar8 + -1);
  }
  iVar7 = 0;
  iStack_1a0 = 0;
  if (0 < _planeNum) {
    do {
      if (0 < _shadowVertNum) {
        puVar9 = (undefined4 *)&DAT_007b645c;
        iVar13 = _shadowVertNum;
        do {
          uVar10 = _PointInPoly(*(undefined4 *)(&DAT_007b64fc + iVar7),&_psPlanes + iVar7,
                                puVar9 + -3,2);
          *puVar9 = uVar10;
          puVar9 = puVar9 + 4;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
      }
      fStack_164 = 0.0;
      if (0 < _shadowTriNum) {
        piStack_180 = (int *)&DAT_007b6444;
        do {
          if (piStack_180[5] == 0) {
            iStack_140 = piStack_180[-1];
            iStack_144 = *piStack_180;
            fStack_154 = (float)piStack_180[1];
            iVar18 = iStack_140 * 0x10;
            iVar12 = iStack_144 * 0x10;
            iVar15 = (int)fStack_154 * 0x10;
            iVar8 = *(int *)(&DAT_007b645c + iVar18) + *(int *)(&DAT_007b645c + iVar12) +
                    *(int *)(&DAT_007b645c + iVar15);
            piStack_180[4] = iVar8;
            iVar13 = _DAT_00acd4b4;
            if (iVar8 == 0) {
              local_14c = local_14c + 1;
            }
            else if (iVar8 == 3) {
              local_148 = local_148 + 1;
              if (0x752c < _DAT_00acd4b4) {
                return;
              }
              if (0x2bf1c < _DAT_00acd4b0) {
                return;
              }
              fVar1 = *(float *)(&_shadowVerts + iVar18);
              piStack_180[5] = 1;
              fVar1 = -((*(float *)(&_qglVertex3fv + iVar18) * *(float *)(&_r_shadows + iVar7) +
                        *(float *)(&DAT_007b6454 + iVar18) * *(float *)(&DAT_007b6504 + iVar7) +
                        fVar1 * *(float *)(&_qglDisable + iVar7)) -
                       *(float *)(&DAT_007b650c + iVar7));
              local_18c = fVar1 * *(float *)(&_qglDisable + iVar7) +
                          *(float *)(&_shadowVerts + iVar18);
              local_188 = fVar1 * *(float *)(&DAT_007b6504 + iVar7) +
                          *(float *)(&DAT_007b6454 + iVar18);
              local_184 = fVar1 * *(float *)(&_r_shadows + iVar7) +
                          *(float *)(&_qglVertex3fv + iVar18);
              if ((*(int *)(&_usedVerts + iStack_140 * 4) == -1) ||
                 (*(int *)(&_usedVerts + iStack_140 * 4) == iStack_1a0)) {
                *(float *)(&DAT_008660e0 + iVar18) = local_18c;
                *(int *)(&_usedVerts + iStack_140 * 4) = iStack_1a0;
                *(float *)(&DAT_008660e4 + iVar18) = local_188;
                *(float *)(&DAT_008660e8 + iVar18) = local_184;
                *(int *)(&_tess + _DAT_00acd4b0 * 4) = iStack_140;
              }
              else {
                *(float *)(&DAT_008660e0 + iVar13 * 0x10) = local_18c;
                *(float *)(&DAT_008660e4 + _DAT_00acd4b4 * 0x10) = local_188;
                *(float *)(&DAT_008660e8 + _DAT_00acd4b4 * 0x10) = local_184;
                *(int *)(&_tess + _DAT_00acd4b0 * 4) = _DAT_00acd4b4;
                _DAT_00acd4b4 = _DAT_00acd4b4 + 1;
              }
              _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
              fVar1 = -((*(float *)(&_qglVertex3fv + iVar12) * *(float *)(&_r_shadows + iVar7) +
                        *(float *)(&DAT_007b6454 + iVar12) * *(float *)(&DAT_007b6504 + iVar7) +
                        *(float *)(&_shadowVerts + iVar12) * *(float *)(&_qglDisable + iVar7)) -
                       *(float *)(&DAT_007b650c + iVar7));
              fStack_17c = fVar1 * *(float *)(&_qglDisable + iVar7) +
                           *(float *)(&_shadowVerts + iVar12);
              fStack_178 = fVar1 * *(float *)(&DAT_007b6504 + iVar7) +
                           *(float *)(&DAT_007b6454 + iVar12);
              fStack_174 = fVar1 * *(float *)(&_r_shadows + iVar7) +
                           *(float *)(&_qglVertex3fv + iVar12);
              if ((*(int *)(&_usedVerts + iStack_144 * 4) == -1) ||
                 (*(int *)(&_usedVerts + iStack_144 * 4) == iStack_1a0)) {
                *(int *)(&_usedVerts + iStack_144 * 4) = iStack_1a0;
                *(float *)(&DAT_008660e0 + iVar12) = fStack_17c;
                *(float *)(&DAT_008660e4 + iVar12) = fStack_178;
                *(float *)(&DAT_008660e8 + iVar12) = fStack_174;
                *(int *)(&_tess + _DAT_00acd4b0 * 4) = iStack_144;
              }
              else {
                *(float *)(&DAT_008660e0 + _DAT_00acd4b4 * 0x10) = fStack_17c;
                *(float *)(&DAT_008660e4 + _DAT_00acd4b4 * 0x10) = fStack_178;
                *(float *)(&DAT_008660e8 + _DAT_00acd4b4 * 0x10) = fStack_174;
                *(int *)(&_tess + _DAT_00acd4b0 * 4) = _DAT_00acd4b4;
                _DAT_00acd4b4 = _DAT_00acd4b4 + 1;
              }
              _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
              fVar1 = -((*(float *)(&_qglVertex3fv + iVar15) * *(float *)(&_r_shadows + iVar7) +
                        *(float *)(&_qglDisable + iVar7) * *(float *)(&_shadowVerts + iVar15) +
                        *(float *)(&DAT_007b6504 + iVar7) * *(float *)(&DAT_007b6454 + iVar15)) -
                       *(float *)(&DAT_007b650c + iVar7));
              fStack_198 = fVar1 * *(float *)(&_qglDisable + iVar7) +
                           *(float *)(&_shadowVerts + iVar15);
              fStack_194 = fVar1 * *(float *)(&DAT_007b6504 + iVar7) +
                           *(float *)(&DAT_007b6454 + iVar15);
              fStack_190 = fVar1 * *(float *)(&_r_shadows + iVar7) +
                           *(float *)(&_qglVertex3fv + iVar15);
              if ((*(int *)(&_usedVerts + (int)fStack_154 * 4) == -1) ||
                 (*(int *)(&_usedVerts + (int)fStack_154 * 4) == iStack_1a0)) {
                *(int *)(&_usedVerts + (int)fStack_154 * 4) = iStack_1a0;
                *(float *)(&DAT_008660e0 + iVar15) = fStack_198;
                *(float *)(&DAT_008660e4 + iVar15) = fStack_194;
                *(float *)(&DAT_008660e8 + iVar15) = fStack_190;
                *(float *)(&_tess + _DAT_00acd4b0 * 4) = fStack_154;
                _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
              }
              else {
                *(float *)(&DAT_008660e0 + _DAT_00acd4b4 * 0x10) = fStack_198;
                *(float *)(&DAT_008660e4 + _DAT_00acd4b4 * 0x10) = fStack_194;
                *(float *)(&DAT_008660e8 + _DAT_00acd4b4 * 0x10) = fStack_190;
                *(int *)(&_tess + _DAT_00acd4b0 * 4) = _DAT_00acd4b4;
                _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
                _DAT_00acd4b4 = _DAT_00acd4b4 + 1;
              }
            }
            else {
              local_150 = local_150 + 1;
              piStack_19c = (int *)_AllocWinding(0x1e);
              *piStack_19c = 3;
              fVar1 = -((*(float *)(&_qglVertex3fv + iVar18) * *(float *)(&_r_shadows + iVar7) +
                        *(float *)(&DAT_007b6454 + iVar18) * *(float *)(&DAT_007b6504 + iVar7) +
                        *(float *)(&_shadowVerts + iVar18) * *(float *)(&_qglDisable + iVar7)) -
                       *(float *)(&DAT_007b650c + iVar7));
              local_18c = fVar1 * *(float *)(&_qglDisable + iVar7) +
                          *(float *)(&_shadowVerts + iVar18);
              local_188 = fVar1 * *(float *)(&DAT_007b6504 + iVar7) +
                          *(float *)(&DAT_007b6454 + iVar18);
              local_184 = fVar1 * *(float *)(&_r_shadows + iVar7) +
                          *(float *)(&_qglVertex3fv + iVar18);
              piStack_19c[1] = (int)local_18c;
              piStack_19c[2] = (int)local_188;
              piStack_19c[3] = (int)local_184;
              fVar1 = -((*(float *)(&_qglVertex3fv + iVar12) * *(float *)(&_r_shadows + iVar7) +
                        *(float *)(&DAT_007b6454 + iVar12) * *(float *)(&DAT_007b6504 + iVar7) +
                        *(float *)(&_shadowVerts + iVar12) * *(float *)(&_qglDisable + iVar7)) -
                       *(float *)(&DAT_007b650c + iVar7));
              fStack_17c = fVar1 * *(float *)(&_qglDisable + iVar7) +
                           *(float *)(&_shadowVerts + iVar12);
              fStack_178 = fVar1 * *(float *)(&DAT_007b6504 + iVar7) +
                           *(float *)(&DAT_007b6454 + iVar12);
              fStack_174 = fVar1 * *(float *)(&_r_shadows + iVar7) +
                           *(float *)(&_qglVertex3fv + iVar12);
              piStack_19c[4] = (int)fStack_17c;
              piStack_19c[5] = (int)fStack_178;
              piStack_19c[6] = (int)fStack_174;
              fVar1 = -((*(float *)(&_qglVertex3fv + iVar15) * *(float *)(&_r_shadows + iVar7) +
                        *(float *)(&_qglDisable + iVar7) * *(float *)(&_shadowVerts + iVar15) +
                        *(float *)(&DAT_007b6504 + iVar7) * *(float *)(&DAT_007b6454 + iVar15)) -
                       *(float *)(&DAT_007b650c + iVar7));
              fStack_198 = fVar1 * *(float *)(&_qglDisable + iVar7) +
                           *(float *)(&_shadowVerts + iVar15);
              fStack_194 = fVar1 * *(float *)(&DAT_007b6504 + iVar7) +
                           *(float *)(&DAT_007b6454 + iVar15);
              fStack_190 = fVar1 * *(float *)(&_r_shadows + iVar7) +
                           *(float *)(&_qglVertex3fv + iVar15);
              piStack_19c[7] = (int)fStack_198;
              piStack_19c[8] = (int)fStack_194;
              piStack_19c[9] = (int)fStack_190;
              if (0 < *(int *)(&DAT_007b64fc + iVar7)) {
                pfVar14 = (float *)(&_psPlanes + iVar7);
                iVar13 = 1;
                do {
                  if (piStack_19c == (int *)0x0) goto LAB_007b53f7;
                  iVar8 = iVar7 + (iVar13 % *(int *)(&DAT_007b64fc + iVar7)) * 0xc;
                  fStack_170 = *(float *)(&_psPlanes + iVar8) - *pfVar14;
                  fStack_16c = *(float *)(&DAT_007b644c + iVar8) - pfVar14[1];
                  fStack_168 = *(float *)(&_shadowVerts + iVar8) - pfVar14[2];
                  _VectorNormalize(&fStack_170);
                  _CrossProduct(&fStack_170,&_qglDisable + iVar7,&fStack_13c);
                  fStack_154 = pfVar14[2] * fStack_134 +
                               *pfVar14 * fStack_13c + pfVar14[1] * fStack_138;
                  _ChopWindingInPlace(&piStack_19c,&fStack_13c,fStack_154,___real_3d4ccccd);
                  pfVar14 = pfVar14 + 3;
                  bVar4 = iVar13 < *(int *)(&DAT_007b64fc + iVar7);
                  iVar13 = iVar13 + 1;
                } while (bVar4);
              }
              iVar13 = _DAT_00acd4b4;
              if (piStack_19c != (int *)0x0) {
                if ((int)&DAT_00007530 - *piStack_19c <= _DAT_00acd4b4) {
                  return;
                }
                iVar8 = 0;
                if (0 < *piStack_19c) {
                  piVar11 = piStack_19c + 2;
                  do {
                    *(int *)(&DAT_008660e0 + _DAT_00acd4b4 * 0x10) = piVar11[-1];
                    *(int *)(&DAT_008660e4 + _DAT_00acd4b4 * 0x10) = *piVar11;
                    *(int *)(&DAT_008660e8 + _DAT_00acd4b4 * 0x10) = piVar11[1];
                    _DAT_00acd4b4 = _DAT_00acd4b4 + 1;
                    iVar8 = iVar8 + 1;
                    piVar11 = piVar11 + 3;
                  } while (iVar8 < *piStack_19c);
                }
                if ((int)&DAT_0002bf20 - *piStack_19c <= _DAT_00acd4b0) {
                  return;
                }
                if (1 < *piStack_19c + -1) {
                  iVar8 = iVar13 + 2;
                  do {
                    *(int *)(&_tess + _DAT_00acd4b0 * 4) = iVar13;
                    _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
                    *(int *)(&_tess + _DAT_00acd4b0 * 4) = iVar8 + -1;
                    _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
                    *(int *)(&_tess + _DAT_00acd4b0 * 4) = iVar8;
                    _DAT_00acd4b0 = _DAT_00acd4b0 + 1;
                    iVar8 = iVar8 + 1;
                  } while ((-1 - iVar13) + iVar8 < *piStack_19c + -1);
                }
                _FreeWinding(piStack_19c);
              }
            }
          }
LAB_007b53f7:
          piStack_180 = piStack_180 + 7;
          fStack_164 = (float)((int)fStack_164 + 1);
        } while ((int)fStack_164 < _shadowTriNum);
      }
      iStack_1a0 = iStack_1a0 + 1;
      iVar7 = iVar7 + 200;
    } while (iStack_1a0 < _planeNum);
  }
  return;
}



