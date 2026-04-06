// ===========================================
// Function: _R_DebugCircle @ 0000c200
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DebugCircle(float *param_1,float param_2,float param_3,float param_4,float param_5,
                   float param_6,int param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  if ((_DAT_00010144 != (int *)0x0) && (__r_debuglines_depthmask != (int *)0x0)) {
    if (param_7 == 0) {
      local_18 = _DAT_00010be8;
      local_14 = _DAT_00010bec;
      local_10 = _DAT_00010bf0;
      local_24 = _DAT_00010bf4;
      local_20 = _DAT_00010bf8;
      local_1c = _DAT_00010bfc;
    }
    else {
      local_24 = 1.0;
      local_14 = 1.0;
      local_20 = 0.0;
      local_1c = 0.0;
      local_18 = 0.0;
      local_10 = 0.0;
    }
    iVar8 = 0;
    iVar10 = 0;
    piVar9 = __r_debuglines_depthmask;
    fVar4 = 0.0;
    fVar5 = 0.0;
    fVar6 = 0.0;
    do {
      fVar1 = *param_1;
      fVar2 = param_1[1];
      fVar3 = param_1[2];
      fVar11 = (float10)__CIsin();
      fVar11 = fVar11 * (float10)param_2;
      fVar12 = (float10)__CIcos();
      fVar12 = fVar12 * (float10)param_2;
      fVar1 = (float)((float10)local_18 * fVar12 +
                     (float10)(float)((float10)local_24 * fVar11 + (float10)fVar1));
      fVar2 = (float)((float10)local_14 * fVar12 +
                     (float10)(float)((float10)local_20 * fVar11 + (float10)fVar2));
      fVar3 = (float)(fVar12 * (float10)local_10 +
                     (float10)(float)(fVar11 * (float10)local_1c + (float10)fVar3));
      if (0 < iVar8) {
        pfVar7 = (float *)(*piVar9 * 0x30 + *_DAT_00010144);
        *piVar9 = *piVar9 + 1;
        if (*(int *)(__r_numdebuglines + 0x20) <= *__r_debuglines_depthmask) {
          (*__ri)(0,0xc000);
          return;
        }
        *pfVar7 = fVar6;
        *(undefined2 *)(pfVar7 + 0xb) = 1;
        pfVar7[1] = fVar5;
        *(undefined2 *)((int)pfVar7 + 0x2e) = 0xffff;
        pfVar7[2] = fVar4;
        pfVar7[3] = fVar1;
        pfVar7[4] = fVar2;
        pfVar7[5] = fVar3;
        pfVar7[6] = param_3;
        pfVar7[7] = param_4;
        pfVar7[8] = param_5;
        pfVar7[9] = param_6;
        pfVar7[10] = 1.0;
        piVar9 = __r_debuglines_depthmask;
      }
      iVar10 = iVar10 + 0x168;
      iVar8 = iVar8 + 1;
      fVar4 = fVar3;
      fVar5 = fVar2;
      fVar6 = fVar1;
    } while (iVar10 < 0x21c1);
    return;
  }
  return;
}



// ===========================================
// Function: _R_DebugLine @ 0000c433
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DebugLine(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((_DAT_00010144 != (int *)0x0) && (__r_debuglines_depthmask != (int *)0x0)) {
    iVar1 = *__r_debuglines_depthmask;
    if (*(int *)(__r_numdebuglines + 0x20) <= iVar1) {
      (*__ri)(0,0xc000);
      return;
    }
    puVar2 = (undefined4 *)(iVar1 * 0x30 + *_DAT_00010144);
    *__r_debuglines_depthmask = iVar1 + 1;
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = param_1[2];
    puVar2[3] = *param_2;
    puVar2[4] = param_2[1];
    puVar2[5] = param_2[2];
    *(undefined2 *)(puVar2 + 0xb) = 1;
    *(undefined2 *)((int)puVar2 + 0x2e) = 0xffff;
    puVar2[6] = param_3;
    puVar2[7] = param_4;
    puVar2[8] = param_5;
    puVar2[9] = param_6;
    puVar2[10] = 0x3f800000;
  }
  return;
}



// ===========================================
// Function: _R_DrawDebugLines @ 0000c4d7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _R_DrawDebugLines(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  float unaff_ESI;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  if ((((_DAT_00010144 != (int *)0x0) && (__r_debuglines_depthmask != (int *)0x0)) &&
      (*__r_debuglines_depthmask != 0)) && (((DAT_00010c04 & 1) == 0 && (_DAT_00010b04 == 0)))) {
    _R_SyncRenderThread(param_1);
    _GL_Bind();
    if (__r_debuglines_depthmask[8] == 0) {
      _GL_State();
    }
    else {
      _GL_State();
      (*__qglDepthRange)(0,0);
    }
    (*__qglDisableClientState)(&DAT_00008076);
    (*__qglDisableClientState)();
    sVar1 = 4;
    sVar2 = -1;
    if (*(int *)(__r_stipplelines + 0x20) != 0) {
      (*__qglEnable)(0xb24);
      (*__qglLineStipple)(4,0xffff);
      (*__qglLineWidth)(0x3f800000);
    }
    (*__qglBegin)(1);
    iVar3 = *_DAT_00010144;
    for (iVar4 = *__r_debuglines_depthmask; 0 < iVar4; iVar4 = iVar4 + -1) {
      if ((*(int *)(__r_stipplelines + 0x20) != 0) &&
         ((((NAN(*(float *)(iVar3 + 0x28)) || NAN(unaff_ESI)) ==
            (*(float *)(iVar3 + 0x28) == unaff_ESI) || (sVar1 != *(short *)(iVar3 + 0x2c))) ||
          (sVar2 != *(short *)(iVar3 + 0x2e))))) {
        (*__qglEnd)();
        (*__qglLineStipple)(*(undefined2 *)(iVar3 + 0x2c),*(undefined2 *)(iVar3 + 0x2e));
        (*__qglLineWidth)(*(undefined4 *)(iVar3 + 0x28));
        (*__qglBegin)(1);
        unaff_ESI = *(float *)(iVar3 + 0x28);
        sVar1 = *(short *)(iVar3 + 0x2c);
        sVar2 = *(short *)(iVar3 + 0x2e);
      }
      (*__qglColor4f)(*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                      *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24));
      (*__qglVertex3fv)(iVar3);
      (*__qglVertex3fv)(iVar3 + 0xc);
      iVar3 = iVar3 + 0x30;
    }
    (*__qglEnd)();
    if (*(int *)(__r_stipplelines + 0x20) != 0) {
      uVar5 = 0xb24;
      (*__qglDisable)();
      uVar6 = CONCAT44(uVar5,0xffff);
      uVar5 = 1;
      (*__qglLineStipple)();
      (*__qglLineWidth)(0x3f800000,uVar5,uVar6);
    }
    (*__qglDepthRange)(0,0x3ff0000000000000);
    _GLimp_Suspend();
    return;
  }
  return;
}



// ===========================================
// Function: _R_CullLocalBoxOffset @ 0000c6d4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_CullLocalBoxOffset(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  float afStack_80 [8];
  float local_60;
  float local_5c [23];
  
  iVar13 = 0;
  if (*(int *)(__r_nocull + 0x20) != 0) {
    return 1;
  }
  fVar1 = *param_1;
  uVar10 = 0;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  pfVar11 = local_5c;
  do {
    fVar4 = *(float *)(param_2 + (uVar10 & 1) * 0xc);
    fVar5 = *(float *)(param_2 + 4 + ((int)uVar10 >> 1 & 1U) * 0xc);
    fVar6 = *(float *)(param_2 + 8 + ((int)uVar10 >> 2 & 1U) * 0xc);
    uVar10 = uVar10 + 1;
    pfVar11[-1] = fVar6 * _DAT_00010aa8 +
                  fVar5 * _DAT_00010a9c + fVar1 + _DAT_00010a84 + fVar4 * _DAT_00010a90;
    *pfVar11 = _DAT_00010aac * fVar6 +
               _DAT_00010aa0 * fVar5 + _DAT_00010a94 * fVar4 + fVar2 + _DAT_00010a88;
    pfVar11[1] = _DAT_00010ab0 * fVar6 +
                 _DAT_00010aa4 * fVar5 + fVar3 + _DAT_00010a8c + _DAT_00010a98 * fVar4;
    pfVar11 = pfVar11 + 3;
  } while ((int)uVar10 < 8);
  bVar9 = false;
  if (0 < _DAT_00010a5c + 4) {
    pfVar11 = (float *)&DAT_0001097c;
    do {
      bVar8 = false;
      iVar14 = 0;
      pfVar12 = &local_60;
      bVar7 = false;
      do {
        fVar1 = pfVar12[2] * *pfVar11 + *pfVar12 * pfVar11[-2] + pfVar12[1] * pfVar11[-1];
        afStack_80[iVar14] = fVar1;
        if (pfVar11[1] < fVar1 == (NAN(pfVar11[1]) || NAN(fVar1))) {
          bVar8 = true;
        }
        else {
          bVar7 = true;
          if (bVar8) goto LAB_0000c962;
        }
        fVar1 = pfVar12[5] * *pfVar11 + pfVar12[4] * pfVar11[-1] + pfVar12[3] * pfVar11[-2];
        afStack_80[iVar14 + 1] = fVar1;
        if (pfVar11[1] < fVar1 == (NAN(pfVar11[1]) || NAN(fVar1))) {
          bVar8 = true;
        }
        else {
          bVar7 = true;
          if (bVar8) goto LAB_0000c962;
        }
        fVar1 = pfVar12[8] * *pfVar11 + pfVar12[7] * pfVar11[-1] + pfVar12[6] * pfVar11[-2];
        afStack_80[iVar14 + 2] = fVar1;
        if (pfVar11[1] < fVar1 == (NAN(pfVar11[1]) || NAN(fVar1))) {
          bVar8 = true;
        }
        else {
          bVar7 = true;
          if (bVar8) goto LAB_0000c962;
        }
        fVar1 = pfVar12[0xb] * *pfVar11 + pfVar12[10] * pfVar11[-1] + pfVar12[9] * pfVar11[-2];
        afStack_80[iVar14 + 3] = fVar1;
        if (pfVar11[1] < fVar1 == (NAN(pfVar11[1]) || NAN(fVar1))) {
          bVar8 = true;
        }
        else {
          bVar7 = true;
          if (bVar8) goto LAB_0000c962;
        }
        iVar14 = iVar14 + 4;
        pfVar12 = pfVar12 + 0xc;
      } while (iVar14 < 8);
      if (!bVar7) {
        return 2;
      }
LAB_0000c962:
      bVar9 = (bool)(bVar9 | bVar8);
      iVar13 = iVar13 + 1;
      pfVar11 = pfVar11 + 5;
    } while (iVar13 < _DAT_00010a5c + 4);
    if (bVar9) {
      return 1;
    }
  }
  return 0;
}



// ===========================================
// Function: _R_CullLocalBox @ 0000c9a8
// ===========================================

void _R_CullLocalBox(undefined4 param_1)

{
  _R_CullLocalBoxOffset(&_vec3_origin,param_1);
  return;
}



// ===========================================
// Function: _R_CullPointAndRadius @ 0000c9bb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_CullPointAndRadius(float *param_1,float param_2)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  
  bVar2 = false;
  if (*(int *)(__r_nocull + 0x20) != 0) {
    return 1;
  }
  iVar4 = 0;
  if (0 < _DAT_00010a5c + 4) {
    pfVar3 = (float *)&DAT_0001097c;
    do {
      fVar1 = (*pfVar3 * param_1[2] + pfVar3[-1] * param_1[1] + pfVar3[-2] * *param_1) - pfVar3[1];
      if (fVar1 < -param_2 != (NAN(fVar1) || NAN(-param_2))) {
        return 2;
      }
      if (fVar1 < param_2 != (fVar1 == param_2)) {
        bVar2 = true;
      }
      iVar4 = iVar4 + 1;
      pfVar3 = pfVar3 + 5;
    } while (iVar4 < _DAT_00010a5c + 4);
    if (bVar2) {
      return 1;
    }
  }
  return 0;
}



// ===========================================
// Function: _R_LocalNormalToWorld @ 0000ca60
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LocalNormalToWorld(float *param_1,float *param_2)

{
  *param_2 = _DAT_00010aa8 * param_1[2] + _DAT_00010a9c * param_1[1] + *param_1 * _DAT_00010a90;
  param_2[1] = _DAT_00010aac * param_1[2] + _DAT_00010aa0 * param_1[1] + *param_1 * _DAT_00010a94;
  param_2[2] = _DAT_00010ab0 * param_1[2] + _DAT_00010aa4 * param_1[1] + *param_1 * _DAT_00010a98;
  return;
}



// ===========================================
// Function: _R_LocalPointToWorld @ 0000cacb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LocalPointToWorld(float *param_1,float *param_2)

{
  *param_2 = _DAT_00010aa8 * param_1[2] + _DAT_00010a9c * param_1[1] + *param_1 * _DAT_00010a90 +
             _DAT_00010a84;
  param_2[1] = _DAT_00010aac * param_1[2] + _DAT_00010aa0 * param_1[1] + *param_1 * _DAT_00010a94 +
               _DAT_00010a88;
  param_2[2] = _DAT_00010ab0 * param_1[2] + _DAT_00010aa4 * param_1[1] + *param_1 * _DAT_00010a98 +
               _DAT_00010a8c;
  return;
}



// ===========================================
// Function: _R_WorldToLocal @ 0000cb48
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_WorldToLocal(float *param_1,float *param_2)

{
  *param_2 = _DAT_00010a98 * param_1[2] + _DAT_00010a94 * param_1[1] + *param_1 * _DAT_00010a90;
  param_2[1] = _DAT_00010aa4 * param_1[2] + _DAT_00010aa0 * param_1[1] + *param_1 * _DAT_00010a9c;
  param_2[2] = _DAT_00010ab0 * param_1[2] + _DAT_00010aac * param_1[1] + *param_1 * _DAT_00010aa8;
  return;
}



// ===========================================
// Function: _R_TransformModelToClip @ 0000cbb3
// ===========================================

void _R_TransformModelToClip
               (float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  *param_4 = param_2[8] * param_1[2] + *param_1 * *param_2 + param_2[4] * param_1[1] + param_2[0xc];
  param_4[1] = param_2[9] * param_1[2] + param_2[1] * *param_1 + param_2[5] * param_1[1] +
               param_2[0xd];
  param_4[2] = param_2[10] * param_1[2] + param_2[2] * *param_1 + param_2[6] * param_1[1] +
               param_2[0xe];
  param_4[3] = param_2[0xb] * param_1[2] + param_2[3] * *param_1 + param_2[7] * param_1[1] +
               param_2[0xf];
  *param_5 = param_3[0xc] * param_4[3] +
             param_3[8] * param_4[2] + *param_3 * *param_4 + param_3[4] * param_4[1];
  param_5[1] = param_3[0xd] * param_4[3] +
               param_3[9] * param_4[2] + param_3[1] * *param_4 + param_3[5] * param_4[1];
  param_5[2] = param_3[0xe] * param_4[3] +
               param_3[10] * param_4[2] + param_3[2] * *param_4 + param_3[6] * param_4[1];
  param_5[3] = param_3[0xf] * param_4[3] +
               param_3[0xb] * param_4[2] + param_3[3] * *param_4 + param_3[7] * param_4[1];
  return;
}



// ===========================================
// Function: _R_TransformClipToWindow @ 0000ccb0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_TransformClipToWindow(float *param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  
  *param_3 = *param_1 / param_1[3];
  param_3[1] = param_1[1] / param_1[3];
  param_3[2] = (param_1[2] + param_1[3]) / (param_1[3] + param_1[3]);
  fVar1 = (float)___real_3fe0000000000000;
  *param_4 = (float)*(int *)(param_2 + 0x130) * (*param_3 + 1.0) * fVar1;
  param_4[1] = (param_3[1] + 1.0) * fVar1 * (float)*(int *)(param_2 + 0x134);
  param_4[2] = param_3[2];
  iVar2 = __ftol2_sse();
  *param_4 = (float)iVar2;
  iVar2 = __ftol2_sse();
  param_4[1] = (float)iVar2;
  return;
}



// ===========================================
// Function: myGlMultMatrix @ 0000cd37
// ===========================================

/* myGlMultMatrix */

void __cdecl myGlMultMatrix(int param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  
  iVar3 = 4;
  pfVar1 = (float *)(param_1 + 8);
  pfVar2 = (float *)(param_3 + 8);
  do {
    iVar3 = iVar3 + -1;
    pfVar2[-2] = param_2[0xc] * pfVar1[1] +
                 param_2[8] * *pfVar1 + param_2[4] * pfVar1[-1] + pfVar1[-2] * *param_2;
    pfVar2[-1] = param_2[0xd] * pfVar1[1] +
                 param_2[9] * *pfVar1 + pfVar1[-1] * param_2[5] + pfVar1[-2] * param_2[1];
    *pfVar2 = param_2[0xe] * pfVar1[1] +
              param_2[10] * *pfVar1 + param_2[6] * pfVar1[-1] + param_2[2] * pfVar1[-2];
    pfVar2[1] = param_2[0xf] * pfVar1[1] +
                param_2[0xb] * *pfVar1 + param_2[7] * pfVar1[-1] + param_2[3] * pfVar1[-2];
    pfVar1 = pfVar1 + 4;
    pfVar2 = pfVar2 + 4;
  } while (iVar3 != 0);
  return;
}



// ===========================================
// Function: _R_RotateForEntity @ 0000cde3
// ===========================================

void _R_RotateForEntity(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (*param_1 == 0) {
    *param_3 = (float)param_1[0x12];
    param_3[1] = (float)param_1[0x13];
    param_3[2] = (float)param_1[0x14];
    param_3[3] = (float)param_1[8];
    param_3[4] = (float)param_1[9];
    param_3[5] = (float)param_1[10];
    param_3[6] = (float)param_1[0xb];
    param_3[7] = (float)param_1[0xc];
    param_3[8] = (float)param_1[0xd];
    param_3[9] = (float)param_1[0xe];
    param_3[10] = (float)param_1[0xf];
    local_18 = (float)param_1[0x10];
    param_3[0xb] = local_18;
    local_40 = param_3[3];
    local_30 = param_3[6];
    local_20 = param_3[9];
    local_10 = *param_3;
    local_3c = param_3[4];
    local_2c = param_3[7];
    local_1c = param_3[10];
    local_c = param_3[1];
    local_38 = param_3[5];
    local_28 = param_3[8];
    local_8 = param_3[2];
    local_34 = 0;
    local_24 = 0;
    local_14 = 0;
    local_4 = 0x3f800000;
    myGlMultMatrix(&local_40,param_2 + 0x2e,param_3 + 0xf);
    fVar2 = *param_2 - *param_3;
    fVar3 = param_2[1] - param_3[1];
    fVar4 = param_2[2] - param_3[2];
    if (param_1[0x11] == 0) {
      fVar5 = 1.0;
    }
    else {
      fVar8 = (float10)_VectorLength(param_1 + 8);
      fVar1 = (float)fVar8;
      fVar5 = 0.0;
      if (NAN(fVar1) == (fVar1 == 0.0)) {
        fVar5 = 1.0 / fVar1;
      }
    }
    param_3[0xc] = fVar5 * (fVar3 * param_3[4] + fVar2 * param_3[3] + fVar4 * param_3[5]);
    param_3[0xd] = (param_3[8] * fVar4 + fVar2 * param_3[6] + param_3[7] * fVar3) * fVar5;
    param_3[0xe] = (fVar4 * param_3[0xb] + param_3[9] * fVar2 + param_3[10] * fVar3) * fVar5;
    return;
  }
  pfVar7 = param_2 + 0x1f;
  for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *param_3 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



// ===========================================
// Function: _R_RotateForViewer @ 0000cfa3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_RotateForViewer(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  _memset(&DAT_00010a84,0,0x7c);
  _DAT_00010a90 = 0x3f800000;
  _DAT_00010aa0 = 0x3f800000;
  _DAT_00010ab0 = 0x3f800000;
  _DAT_00010ab4 = _DAT_000107f4;
  _DAT_00010ab8 = _DAT_000107f8;
  _DAT_00010abc = _DAT_000107fc;
  local_34 = _DAT_00010800;
  local_24 = _DAT_00010804;
  local_14 = _DAT_00010808;
  local_4 = -_DAT_000107fc * _DAT_00010808 -
            (_DAT_000107f8 * _DAT_00010804 + _DAT_000107f4 * _DAT_00010800);
  local_30 = _DAT_0001080c;
  local_20 = _DAT_00010810;
  local_10 = _DAT_00010814;
  local_2c = _DAT_00010818;
  local_1c = _DAT_0001081c;
  local_c = _DAT_00010820;
  local_28 = 0;
  local_18 = 0;
  local_8 = 0;
  myGlMultMatrix(&local_34,0x2000,0x10ac0);
  puVar2 = (undefined4 *)&DAT_00010a84;
  puVar3 = (undefined4 *)&DAT_00010870;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}



// ===========================================
// Function: _SetFarClip @ 0000d100
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SetFarClip(void)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  float local_20;
  float local_10;
  
  if ((DAT_00010c04 & 1) == 0) {
    local_20 = 0.0;
    uVar5 = 1;
    do {
      uVar1 = uVar5 - 1;
      fVar3 = _DAT_000109e4;
      if ((uVar1 & 1) != 0) {
        fVar3 = _DAT_000109d8;
      }
      fVar4 = _DAT_000109e8;
      if ((uVar1 & 2) != 0) {
        fVar4 = _DAT_000109dc;
      }
      if ((uVar1 & 4) == 0) {
        local_10 = _DAT_000109ec;
      }
      else {
        local_10 = _DAT_000109e0;
      }
      fVar3 = (local_10 - _DAT_000107fc) * (local_10 - _DAT_000107fc) +
              (fVar3 - _DAT_000107f4) * (fVar3 - _DAT_000107f4) +
              (fVar4 - _DAT_000107f8) * (fVar4 - _DAT_000107f8);
      if (local_20 < fVar3 != (NAN(local_20) || NAN(fVar3))) {
        local_20 = fVar3;
      }
      uVar6 = uVar5 - 2 & 1;
      fVar3 = _DAT_000109e4;
      if (uVar6 != 0) {
        fVar3 = _DAT_000109d8;
      }
      fVar4 = _DAT_000109e8;
      if ((uVar5 & 2) != 0) {
        fVar4 = _DAT_000109dc;
      }
      if ((uVar5 & 4) == 0) {
        local_10 = _DAT_000109ec;
      }
      else {
        local_10 = _DAT_000109e0;
      }
      fVar3 = (local_10 - _DAT_000107fc) * (local_10 - _DAT_000107fc) +
              (fVar3 - _DAT_000107f4) * (fVar3 - _DAT_000107f4) +
              (fVar4 - _DAT_000107f8) * (fVar4 - _DAT_000107f8);
      if (local_20 < fVar3 != (NAN(local_20) || NAN(fVar3))) {
        local_20 = fVar3;
      }
      fVar3 = _DAT_000109e4;
      if ((uVar1 & 1) != 0) {
        fVar3 = _DAT_000109d8;
      }
      fVar4 = _DAT_000109e8;
      if ((uVar5 + 1 & 2) != 0) {
        fVar4 = _DAT_000109dc;
      }
      if ((uVar5 + 1 & 4) == 0) {
        local_10 = _DAT_000109ec;
      }
      else {
        local_10 = _DAT_000109e0;
      }
      fVar3 = (local_10 - _DAT_000107fc) * (local_10 - _DAT_000107fc) +
              (fVar3 - _DAT_000107f4) * (fVar3 - _DAT_000107f4) +
              (fVar4 - _DAT_000107f8) * (fVar4 - _DAT_000107f8);
      if (local_20 < fVar3 != (NAN(local_20) || NAN(fVar3))) {
        local_20 = fVar3;
      }
      fVar3 = _DAT_000109e4;
      if (uVar6 != 0) {
        fVar3 = _DAT_000109d8;
      }
      fVar4 = _DAT_000109e8;
      if ((uVar5 - 2 & 2) != 0) {
        fVar4 = _DAT_000109dc;
      }
      if ((uVar5 + 2 & 4) == 0) {
        local_10 = _DAT_000109ec;
      }
      else {
        local_10 = _DAT_000109e0;
      }
      fVar3 = (local_10 - _DAT_000107fc) * (local_10 - _DAT_000107fc) +
              (fVar3 - _DAT_000107f4) * (fVar3 - _DAT_000107f4) +
              (fVar4 - _DAT_000107f8) * (fVar4 - _DAT_000107f8);
      if (local_20 < fVar3 != (NAN(local_20) || NAN(fVar3))) {
        local_20 = fVar3;
      }
      iVar2 = uVar5 + 3;
      uVar5 = uVar5 + 4;
    } while (iVar2 < 8);
    fVar7 = (float10)__CIsqrt();
    _DAT_000109f0 = (float)fVar7;
    return;
  }
  _DAT_000109f0 = (float)___real_45000000;
  return;
}



// ===========================================
// Function: _R_SetupProjection @ 0000d3f2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetupProjection(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  _SetFarClip();
  fVar5 = _DAT_000109f0;
  fVar1 = *(float *)(__r_znear + 0x1c);
  fVar6 = (float10)__CItan();
  fVar2 = (float)(fVar6 * (float10)fVar1);
  fVar3 = -fVar2;
  fVar6 = (float10)__CItan();
  fVar7 = (float10)fVar1;
  fVar1 = (float)(fVar7 * fVar6);
  fVar4 = fVar1 - -fVar1;
  fVar6 = (float10)fVar2;
  fVar8 = (float10)fVar5;
  _DAT_00010934 = (float)((fVar7 + fVar7) / (float10)fVar4);
  _DAT_00010944 = 0;
  _DAT_00010954 = (-fVar1 + fVar1) / fVar4;
  _DAT_00010964 = 0;
  _DAT_00010938 = 0;
  fVar9 = (float10)(float)(fVar6 - (float10)fVar3);
  _DAT_00010948 = (float)((fVar7 + fVar7) / fVar9);
  _DAT_00010958 = (float)(((float10)fVar3 + fVar6) / fVar9);
  _DAT_00010968 = 0;
  _DAT_0001093c = 0;
  _DAT_0001094c = 0;
  _DAT_0001095c = (float)-((fVar8 + fVar7) / (float10)(float)(fVar8 - fVar7));
  _DAT_0001096c =
       (float)((fVar8 * (float10)___real_c000000000000000 * fVar7) / (float10)(float)(fVar8 - fVar7)
              );
  _DAT_00010940 = 0;
  _DAT_00010950 = 0;
  _DAT_00010960 = ___real_bf800000;
  _DAT_00010970 = 0;
  return;
}



// ===========================================
// Function: _R_SetupFrustum @ 0000d544
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetupFrustum(void)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  float10 fVar5;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  
  fVar5 = (float10)__CIsin();
  fVar1 = (float)fVar5;
  fVar5 = (float10)__CIcos();
  fVar2 = (float)fVar5;
  _DAT_00010974 = fVar1 * _DAT_00010800 + fVar2 * _DAT_0001080c;
  _DAT_00010978 = _DAT_00010810 * fVar2 + _DAT_00010804 * fVar1;
  _DAT_0001097c = _DAT_00010814 * fVar2 + _DAT_00010808 * fVar1;
  fVar2 = -fVar2;
  _DAT_00010988 = fVar1 * _DAT_00010800 + fVar2 * _DAT_0001080c;
  _DAT_0001098c = _DAT_00010810 * fVar2 + _DAT_00010804 * fVar1;
  _DAT_00010990 = fVar2 * _DAT_00010814 + _DAT_00010808 * fVar1;
  fVar5 = (float10)__CIsin();
  fVar1 = (float)fVar5;
  fVar5 = (float10)__CIcos();
  fVar2 = (float)fVar5;
  pfVar4 = (float *)&DAT_00010978;
  _DAT_0001099c = fVar1 * _DAT_00010800 + fVar2 * _DAT_00010818;
  _DAT_000109a0 = _DAT_0001081c * fVar2 + _DAT_00010804 * fVar1;
  _DAT_000109a4 = _DAT_00010820 * fVar2 + _DAT_00010808 * fVar1;
  fVar2 = -fVar2;
  _DAT_000109b0 = fVar1 * _DAT_00010800 + fVar2 * _DAT_00010818;
  _DAT_000109b4 = _DAT_0001081c * fVar2 + _DAT_00010804 * fVar1;
  _DAT_000109b8 = fVar2 * _DAT_00010820 + _DAT_00010808 * fVar1;
  do {
    *(undefined1 *)(pfVar4 + 3) = 3;
    pfVar4[2] = pfVar4[1] * _DAT_000107fc + pfVar4[-1] * _DAT_000107f4 + *pfVar4 * _DAT_000107f8;
    _SetPlaneSignbits(pfVar4 + -1);
    pfVar4 = pfVar4 + 5;
  } while ((int)pfVar4 < 0x109c8);
  if (_DAT_00010b04 != 0) {
    _DAT_00010a58 = 0;
    _DAT_00010a5c = 0;
    _DAT_00010a60 = 0.0;
    return;
  }
  if (*(int *)(__r_farplane + 0x20) != 0) {
    _DAT_00010a60 = *(float *)(__r_farplane + 0x1c);
    if (NAN(*(float *)(__r_farplane_pulse + 0x1c)) == (*(float *)(__r_farplane_pulse + 0x1c) == 0.0)
       ) {
      uVar3 = myftol((1.0 / *(float *)(__r_farplane_pulseFrequency + 0x1c)) * __R_GetShaderByHandle
                     * (float)___real_4090000000000000);
      _DAT_00010a60 =
           _DAT_00010a60 -
           ((float)___real_3fe0000000000000 +
           *(float *)((uVar3 & 0x3ff) * 4 + 0x57050) * (float)___real_3fe0000000000000) *
           *(float *)(__r_farplane_pulse + 0x1c);
    }
    _sscanf(*(char **)(__r_farplane_color + 4),s__f__f__f);
    _DAT_00010a70 = (uint)(*(int *)(__r_farplane_nocull + 0x20) == 0);
  }
  if (NAN(_DAT_00010a60) == (_DAT_00010a60 == 0.0)) {
    _DAT_000109f4 = _DAT_00010a60;
    _DAT_000109f8 = 1.0 / _DAT_00010a60;
    _DAT_00010a20 = _DAT_00010a64;
    _DAT_00010a24 = _DAT_00010a68;
    _DAT_00010a28 = _DAT_00010a6c;
    _DAT_00010a18 = _ColorBytes3(_DAT_00010a64,_DAT_00010a68,_DAT_00010a6c);
    _DAT_00010a1c = 0x3f800000;
    DAT_000109d4 = 3;
    fStack_18 = _DAT_000107f8 + _DAT_00010804 * _DAT_00010a60;
    fStack_14 = _DAT_000107fc + _DAT_00010808 * _DAT_00010a60;
    _DAT_000109cc = (float)___real_bff0000000000000;
    _DAT_000109c4 = _DAT_00010800 * _DAT_000109cc;
    _DAT_000109c8 = _DAT_00010804 * _DAT_000109cc;
    _DAT_000109cc = _DAT_000109cc * _DAT_00010808;
    _DAT_000109d0 =
         _DAT_000109cc * fStack_14 +
         _DAT_000109c4 * (_DAT_000107f4 + _DAT_00010800 * _DAT_00010a60) + _DAT_000109c8 * fStack_18
    ;
    _SetPlaneSignbits(&DAT_000109c4);
    _DAT_00010a5c = _DAT_00010a70;
    _DAT_00010a58 = (uint)(*(int *)(__r_farplane_nofog + 0x20) == 0);
    if (*(int *)(__r_farplane_nofog + 0x20) == 0) {
      (*__qglFogf)(0xb64,_DAT_00010a60);
      fStack_18 = _DAT_00010a74 * _DAT_00010a64;
      fStack_14 = _DAT_00010a74 * _DAT_00010a68;
      fStack_10 = _DAT_00010a74 * _DAT_00010a6c;
      uStack_c = 0x3f800000;
      (*__qglFogfv)(0xb66,&fStack_18);
      return;
    }
  }
  else {
    _DAT_00010a58 = 0;
    _DAT_00010a5c = 0;
  }
  return;
}



// ===========================================
// Function: _R_MirrorPoint @ 0000da6d
// ===========================================

void _R_MirrorPoint(float *param_1,float *param_2,float *param_3,float *param_4)

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
  
  fVar5 = *param_1 - *param_2;
  fVar6 = param_1[1] - param_2[1];
  fVar7 = param_1[2] - param_2[2];
  fVar8 = fVar6 * param_2[4] + fVar5 * param_2[3] + fVar7 * param_2[5];
  fVar1 = param_3[4];
  fVar2 = param_3[5];
  fVar9 = param_2[8] * fVar7 + param_2[6] * fVar5 + param_2[7] * fVar6;
  fVar3 = param_3[7];
  fVar4 = param_3[8];
  fVar7 = fVar7 * param_2[0xb] + param_2[10] * fVar6 + param_2[9] * fVar5;
  fVar5 = param_3[10];
  fVar6 = param_3[0xb];
  *param_4 = *param_3 + fVar8 * param_3[3] + 0.0 + fVar9 * param_3[6] + fVar7 * param_3[9];
  param_4[1] = param_3[1] + fVar5 * fVar7 + fVar3 * fVar9 + fVar1 * fVar8 + 0.0;
  param_4[2] = param_3[2] + fVar7 * fVar6 + fVar9 * fVar4 + fVar8 * fVar2 + 0.0;
  return;
}



// ===========================================
// Function: _R_MirrorVector @ 0000db96
// ===========================================

void _R_MirrorVector(float *param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  
  param_4[2] = 0.0;
  param_4[1] = 0.0;
  *param_4 = 0.0;
  fVar1 = *(float *)(param_2 + 0x14) * param_1[2] +
          *(float *)(param_2 + 0xc) * *param_1 + *(float *)(param_2 + 0x10) * param_1[1];
  *param_4 = *param_4 + fVar1 * *(float *)(param_3 + 0xc);
  param_4[1] = *(float *)(param_3 + 0x10) * fVar1 + param_4[1];
  param_4[2] = fVar1 * *(float *)(param_3 + 0x14) + param_4[2];
  fVar1 = *(float *)(param_2 + 0x20) * param_1[2] +
          *(float *)(param_2 + 0x18) * *param_1 + *(float *)(param_2 + 0x1c) * param_1[1];
  *param_4 = *param_4 + fVar1 * *(float *)(param_3 + 0x18);
  param_4[1] = *(float *)(param_3 + 0x1c) * fVar1 + param_4[1];
  param_4[2] = fVar1 * *(float *)(param_3 + 0x20) + param_4[2];
  fVar1 = *(float *)(param_2 + 0x2c) * param_1[2] +
          *(float *)(param_2 + 0x24) * *param_1 + *(float *)(param_2 + 0x28) * param_1[1];
  *param_4 = *param_4 + fVar1 * *(float *)(param_3 + 0x24);
  param_4[1] = *(float *)(param_3 + 0x28) * fVar1 + param_4[1];
  param_4[2] = fVar1 * *(float *)(param_3 + 0x2c) + param_4[2];
  return;
}



// ===========================================
// Function: _R_PlaneForSurface @ 0000dc73
// ===========================================

void _R_PlaneForSurface(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int local_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 == 2) {
      *param_2 = param_1[1];
      param_2[1] = param_1[2];
      param_2[2] = param_1[3];
      param_2[3] = param_1[4];
      param_2[4] = param_1[5];
      return;
    }
    if (*param_1 == 4) {
      piVar1 = (int *)param_1[0xe];
      iVar2 = param_1[0x10];
      _PlaneFromPoints(&local_10,*piVar1 * 0x2c + iVar2,piVar1[1] * 0x2c + iVar2,
                       piVar1[2] * 0x2c + iVar2);
      *param_2 = local_10;
      param_2[1] = iStack_c;
      param_2[2] = iStack_8;
      param_2[3] = iStack_4;
      return;
    }
  }
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  *param_2 = 0x3f800000;
  return;
}



// ===========================================
// Function: _R_GetPortalOrientations @ 0000dd19
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_R_GetPortalOrientations
          (float param_1,int param_2,float *param_3,float *param_4,float *param_5,
          undefined4 *param_6)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  undefined4 extraout_EDX;
  float *pfVar5;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  _R_PlaneForSurface(*(undefined4 *)((int)param_1 + 4),&local_28);
  param_3[3] = local_28;
  pfVar1 = param_3 + 3;
  pfVar2 = param_3 + 6;
  param_3[4] = local_24;
  param_3[5] = local_20;
  _PerpendicularVector(pfVar2,pfVar1);
  pfVar5 = param_3 + 9;
  _CrossProduct(pfVar1,pfVar2,pfVar5);
  if (param_2 == 0x3fe) {
    fStack_14 = local_28;
    fStack_10 = local_24;
    fStack_c = local_20;
    fStack_8 = fStack_1c;
    uStack_4 = uStack_18;
  }
  else {
    _DAT_000107e4 = param_2;
    _DAT_00010514 = param_2 * 0x2cc + _DAT_00010d34;
    _R_RotateForEntity(_DAT_00010514,&DAT_000107f4,&DAT_00010a84);
    _R_LocalNormalToWorld(&local_28,&fStack_14);
    fStack_8 = fStack_1c +
               fStack_10 * _DAT_00010a88 + fStack_14 * _DAT_00010a84 + fStack_c * _DAT_00010a8c;
    fStack_1c = _DAT_00010a8c * local_20 + local_24 * _DAT_00010a88 + local_28 * _DAT_00010a84 +
                fStack_1c;
    *pfVar1 = fStack_14;
    param_3[4] = fStack_10;
    param_3[5] = fStack_c;
    fStack_40 = *pfVar2;
    fStack_3c = param_3[7];
    fStack_38 = param_3[8];
    _R_LocalNormalToWorld(&fStack_40,pfVar2);
    fStack_40 = *pfVar5;
    fStack_3c = param_3[10];
    fStack_38 = param_3[0xb];
    _R_LocalNormalToWorld(extraout_EDX,pfVar5);
  }
  iVar4 = 0;
  if (0 < _DAT_00010d30) {
    pfVar5 = (float *)(_DAT_00010d34 + 0x48);
    do {
      if (((pfVar5[-0x12] == 9.80909e-45) &&
          (fVar3 = (pfVar5[2] * local_20 + *pfVar5 * local_28 + pfVar5[1] * local_24) - fStack_1c,
          fVar3 <= ___real_42800000)) &&
         (fVar3 < ___real_c2800000 == (NAN(fVar3) || NAN(___real_c2800000)))) {
        *param_5 = pfVar5[0x15];
        param_5[1] = pfVar5[0x16];
        param_5[2] = pfVar5[0x17];
        if ((((NAN(*pfVar5) || NAN(pfVar5[0x15])) != (*pfVar5 == pfVar5[0x15])) &&
            ((NAN(pfVar5[1]) || NAN(pfVar5[0x16])) != (pfVar5[1] == pfVar5[0x16]))) &&
           ((NAN(pfVar5[2]) || NAN(pfVar5[0x17])) != (pfVar5[2] == pfVar5[0x17]))) {
          *param_3 = fStack_8 * fStack_14;
          param_3[1] = fStack_8 * fStack_10;
          param_3[2] = fStack_c * fStack_8;
          *param_4 = fStack_8 * fStack_14;
          param_4[1] = param_3[1];
          param_4[2] = param_3[2];
          param_4[3] = __vec3_origin - *pfVar1;
          param_4[4] = _DAT_0001016c - param_3[4];
          param_4[5] = ___ftol2_sse - param_3[5];
          param_4[6] = *pfVar2;
          param_4[7] = param_3[7];
          param_4[8] = param_3[8];
          param_4[9] = param_3[9];
          param_4[10] = param_3[10];
          param_4[0xb] = param_3[0xb];
          *param_6 = 1;
          return 1;
        }
        param_1 = (pfVar5[2] * fStack_c + pfVar5[1] * fStack_10 + *pfVar5 * fStack_14) - fStack_8;
        fVar3 = -param_1;
        *param_3 = fVar3 * *pfVar1 + *pfVar5;
        param_3[1] = fVar3 * param_3[4] + pfVar5[1];
        param_3[2] = fVar3 * param_3[5] + pfVar5[2];
        pfVar1 = param_4 + 3;
        *param_4 = pfVar5[0x15];
        param_4[1] = pfVar5[0x16];
        param_4[2] = pfVar5[0x17];
        _AxisCopy(pfVar5 + -10,pfVar1);
        pfVar2 = param_4 + 6;
        *pfVar1 = __vec3_origin - *pfVar1;
        param_4[4] = _DAT_0001016c - param_4[4];
        param_4[5] = ___ftol2_sse - param_4[5];
        *pfVar2 = __vec3_origin - *pfVar2;
        param_4[7] = _DAT_0001016c - param_4[7];
        fStack_2c = ___ftol2_sse - param_4[8];
        param_4[8] = fStack_2c;
        fVar3 = pfVar5[0x1a];
        if ((int)fVar3 < 1) {
          if (-1 < (int)fVar3) {
            *param_6 = 0;
            return 1;
          }
          if (fVar3 == -NAN) {
            param_1 = (float)(_DAT_00010c00 % 0xe10) / (float)___real_4024000000000000;
          }
          else if (fVar3 == -NAN) {
            param_1 = (float)(_DAT_00010c00 % 0xe10) / (float)___real_c024000000000000;
          }
          fStack_34 = *pfVar2;
          fStack_30 = param_4[7];
        }
        else {
          fStack_34 = *pfVar2;
          fStack_30 = param_4[7];
          param_1 = (float)(int)pfVar5[0x1a];
        }
        _RotatePointAroundVector(pfVar2,pfVar1,&fStack_34,param_1);
        _CrossProduct(pfVar1,pfVar2,param_4 + 9);
        *param_6 = 0;
        return 1;
      }
      iVar4 = iVar4 + 1;
      pfVar5 = pfVar5 + 0xb3;
    } while (iVar4 < _DAT_00010d30);
  }
  return 0;
}



// ===========================================
// Function: _SurfIsOffscreen @ 0000e1d5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _SurfIsOffscreen(int *param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  float10 fVar10;
  uint local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float fStack_90;
  undefined1 local_8c [16];
  undefined4 local_7c [12];
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [64];
  
  local_a4 = ___real_47c35000;
  local_a8 = 0xffffffff;
  if (*param_1 != 2) {
    (*__ri)(3,s_WARNING__SurfIsOffscreen_called_);
    return 0;
  }
  if (param_3 == 0x3fe) {
    puVar5 = (undefined4 *)&DAT_00010870;
    puVar8 = local_7c;
    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  else {
    _R_RotateForEntity(param_3 * 0x2cc + _DAT_00010d34,&DAT_000107f4,local_7c);
  }
  iVar3 = param_1[8];
  if (0 < iVar3) {
    piVar9 = param_1 + 0xb;
    do {
      uVar6 = 0;
      _R_TransformModelToClip(piVar9,local_40,&DAT_00010934,local_8c,&local_a0);
      if (local_94 < local_a0 == (local_94 == local_a0)) {
        if (local_a0 <= -local_94) {
          uVar6 = 2;
        }
      }
      else {
        uVar6 = 1;
      }
      if (local_9c < local_94) {
        if (local_9c <= -local_94) {
          uVar6 = uVar6 | 8;
        }
      }
      else {
        uVar6 = uVar6 | 4;
      }
      if (local_98 < local_94) {
        if (local_98 <= -local_94) {
          uVar6 = uVar6 | 0x20;
        }
      }
      else {
        uVar6 = uVar6 | 0x10;
      }
      local_a8 = local_a8 & uVar6;
      piVar9 = piVar9 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (local_a8 == 0) {
      bVar2 = 0.0 < *(float *)(param_2 + 0xac);
      iVar3 = param_1[10];
      iVar4 = param_1[9] / 3;
      iVar7 = 0;
      if (0 < param_1[9]) {
        do {
          iVar1 = *(int *)((int)param_1 + iVar7 * 4 + iVar3);
          local_a0 = (float)param_1[iVar1 * 8 + 0xb] - local_4c;
          local_9c = (float)param_1[iVar1 * 8 + 0xc] - local_48;
          local_98 = (float)param_1[iVar1 * 8 + 0xd] - local_44;
          if (bVar2) {
            fVar10 = (float10)_VectorLength(&local_a0);
            fStack_90 = (float)fVar10;
            if (fStack_90 < local_a4) {
              local_a4 = fStack_90;
            }
          }
          if ((float)___real_0000000000000000 <=
              (float)param_1[3] * local_98 +
              (float)param_1[2] * local_9c + (float)param_1[1] * local_a0) {
            iVar4 = iVar4 + -1;
          }
          iVar7 = iVar7 + 3;
        } while (iVar7 < param_1[9]);
      }
      if ((iVar4 != 0) &&
         ((!bVar2 ||
          (*(float *)(param_2 + 0xac) < local_a4 ==
           (NAN(*(float *)(param_2 + 0xac)) || NAN(local_a4)))))) {
        return 0;
      }
    }
  }
  return 1;
}



// ===========================================
// Function: _R_SpriteFogNum @ 0000e435
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_SpriteFogNum(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  
  if (((DAT_00010c04 & 1) != 0) || (_DAT_00010b04 != 0)) {
    return 0;
  }
  iVar4 = 1;
  if (1 < *(int *)(___CIsin + 0xb4)) {
    pfVar5 = (float *)(*(int *)(___CIsin + 0xb8) + 0x60);
    do {
      iVar2 = 0;
      pfVar3 = pfVar5;
      do {
        fVar1 = *(float *)(param_1 + iVar2 * 4) - param_2;
        if ((pfVar3[3] < fVar1 != (pfVar3[3] == fVar1)) ||
           (*(float *)(param_1 + iVar2 * 4) + param_2 <= *pfVar3)) break;
        iVar2 = iVar2 + 1;
        pfVar3 = pfVar3 + 1;
      } while (iVar2 < 3);
      if (iVar2 == 3) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      pfVar5 = pfVar5 + 0x17;
    } while (iVar4 < *(int *)(___CIsin + 0xb4));
  }
  return 0;
}



// ===========================================
// Function: shortsort @ 0000e4c0
// ===========================================

/* shortsort */

void __cdecl shortsort(void)

{
  uint uVar1;
  uint *puVar2;
  uint *in_EAX;
  uint *puVar3;
  uint *unaff_ESI;
  
  if (unaff_ESI < in_EAX) {
    puVar2 = unaff_ESI + 2;
    puVar3 = unaff_ESI;
    do {
      for (; puVar2 <= in_EAX; puVar2 = puVar2 + 2) {
        if (*puVar3 < *puVar2) {
          puVar3 = puVar2;
        }
      }
      uVar1 = *puVar3;
      *puVar3 = *in_EAX;
      *in_EAX = uVar1;
      uVar1 = puVar3[1];
      puVar3[1] = in_EAX[1];
      in_EAX[1] = uVar1;
      in_EAX = in_EAX + -2;
      puVar2 = unaff_ESI + 2;
      puVar3 = unaff_ESI;
    } while (unaff_ESI < in_EAX);
  }
  return;
}



// ===========================================
// Function: qsortFast @ 0000e505
// ===========================================

/* qsortFast */

void __cdecl qsortFast(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int local_f4;
  undefined4 auStack_f0 [30];
  int aiStack_78 [30];
  
  if ((param_2 < 2) || (param_3 == 0)) {
    return;
  }
  local_f4 = 0;
  puVar5 = (uint *)((param_2 - 1) * param_3 + (int)param_1);
_recurse_88607:
  uVar1 = (uint)((int)puVar5 - (int)param_1) / param_3 + 1;
  if (8 < uVar1) {
    iVar2 = (uVar1 >> 1) * param_3;
    uVar1 = *(uint *)(iVar2 + (int)param_1);
    puVar3 = (uint *)(iVar2 + (int)param_1);
    *puVar3 = *param_1;
    *param_1 = uVar1;
    uVar1 = puVar3[1];
    puVar3[1] = param_1[1];
    param_1[1] = uVar1;
    puVar3 = (uint *)((int)puVar5 + param_3);
    puVar4 = param_1;
LAB_0000e595:
    puVar4 = (uint *)((int)puVar4 + param_3);
    if (puVar4 <= puVar5) goto code_r0x0000e59b;
    goto LAB_0000e5a5;
  }
  shortsort();
  goto LAB_0000e55a;
code_r0x0000e59b:
  if (*puVar4 <= *param_1) goto LAB_0000e595;
LAB_0000e5a5:
  do {
    puVar3 = (uint *)((int)puVar3 - param_3);
    if (puVar3 <= param_1) break;
  } while (*param_1 <= *puVar3);
  if (puVar4 <= puVar3) {
    uVar1 = *puVar4;
    *puVar4 = *puVar3;
    *puVar3 = uVar1;
    uVar1 = puVar4[1];
    puVar4[1] = puVar3[1];
    puVar3[1] = uVar1;
    goto LAB_0000e595;
  }
  uVar1 = *param_1;
  *param_1 = *puVar3;
  *puVar3 = uVar1;
  uVar1 = param_1[1];
  param_1[1] = puVar3[1];
  puVar3[1] = uVar1;
  if ((int)puVar3 + (-1 - (int)param_1) < (int)puVar5 - (int)puVar4) {
    if (puVar4 < puVar5) {
      auStack_f0[local_f4] = puVar4;
      aiStack_78[local_f4] = (int)puVar5;
      local_f4 = local_f4 + 1;
    }
    if ((uint *)((int)param_1 + param_3) < puVar3) {
      puVar5 = (uint *)((int)puVar3 - param_3);
      goto _recurse_88607;
    }
  }
  else {
    if ((uint *)((int)param_1 + param_3) < puVar3) {
      auStack_f0[local_f4] = param_1;
      aiStack_78[local_f4] = (int)puVar3 - param_3;
      local_f4 = local_f4 + 1;
    }
    param_1 = puVar4;
    if (puVar4 < puVar5) goto _recurse_88607;
  }
LAB_0000e55a:
  local_f4 = local_f4 + -1;
  if (local_f4 < 0) {
    return;
  }
  puVar5 = (uint *)aiStack_78[local_f4];
  param_1 = (uint *)auStack_f0[local_f4];
  goto _recurse_88607;
}



// ===========================================
// Function: _R_AddDrawSurf @ 0000e649
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddDrawSurf(undefined4 param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = _DAT_00010d50 & 0xffff;
  *(uint *)(_DAT_00010d54 + uVar1 * 8) =
       (*(int *)(param_2 + 0x48) << 0x13 | param_3) * 8 | param_4 & 3 | _DAT_000107ec;
  *(undefined4 *)(_DAT_00010d54 + 4 + uVar1 * 8) = param_1;
  _DAT_00010d50 = _DAT_00010d50 + 1;
  return;
}



// ===========================================
// Function: _R_AddSpriteSurf @ 0000e694
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddSpriteSurf(undefined4 param_1,int param_2,float param_3)

{
  uint uVar1;
  uint local_8;
  
  uVar1 = _DAT_00010d58 & 0xffff;
  if (___real_4d800000 < param_3 != (NAN(___real_4d800000) || NAN(param_3))) {
    param_3 = ___real_4d800000;
  }
  local_8 = (uint)(longlong)ROUND((float)___real_41b0000000000000 - param_3);
  *(uint *)(_DAT_00010d5c + uVar1 * 8) = local_8 | *(int *)(param_2 + 0x48) << 0x16;
  *(undefined4 *)(_DAT_00010d5c + 4 + uVar1 * 8) = param_1;
  _DAT_00010d58 = _DAT_00010d58 + 1;
  return;
}



// ===========================================
// Function: _R_DecomposeSort @ 0000e711
// ===========================================

void _R_DecomposeSort(uint param_1,uint *param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  *param_4 = param_1 >> 3 & 0x1f;
  *param_3 = *(undefined4 *)((param_1 >> 0x16) * 4 + 0x5504c);
  *param_2 = param_1 >> 0xc & 0x3ff;
  *param_5 = param_1 & 3;
  return;
}



// ===========================================
// Function: _R_AddEntitySurfaces @ 0000e750
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddEntitySurfaces(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  if ((*(int *)(__r_drawentities + 0x20) != 0) && (_DAT_000107e4 = 0, 0 < _DAT_00010d30)) {
    do {
      puVar5 = (undefined4 *)(_DAT_000107e4 * 0x2cc + _DAT_00010d34);
      _DAT_00010514 = puVar5;
      puVar5[0x74] = 0;
      _DAT_000107ec = _DAT_000107e4 << 0xc;
      uVar1 = puVar5[1];
      if (((uVar1 & 2) == 0) || (_DAT_000108f8 == 0)) {
        if (_DAT_00010b04 == 0) {
          if ((uVar1 & 0x4000) == 0) goto LAB_0000e7e1;
        }
        else if ((uVar1 & 0x4000) != 0) {
LAB_0000e7e1:
          if (_DAT_000108f8 == 0) {
            if ((uVar1 & 0x400000) == 0) goto LAB_0000e7fd;
          }
          else if ((uVar1 & 0xc00000) != 0) {
LAB_0000e7fd:
            switch(*puVar5) {
            case 0:
              _R_RotateForEntity(puVar5,&DAT_000107f4,&DAT_00010a84);
              _DAT_000107f0 = _R_GetModelByHandle(puVar5[3]);
              if (_DAT_000107f0 == 0) {
                _R_AddDrawSurf(&_entitySurface,_DAT_000100fc,0,0);
              }
              else {
                switch(*(undefined4 *)(_DAT_000107f0 + 0x40)) {
                case 0:
                  if (((*(byte *)(puVar5 + 1) & 1) == 0) || (_DAT_000108f8 != 0)) {
                    _R_GetShaderByHandle(puVar5[0x2e]);
                    _R_AddDrawSurf(&_entitySurface,_DAT_000100fc,0,0);
                  }
                  break;
                case 1:
                  _R_AddBrushModelSurfaces(puVar5);
                  break;
                case 2:
                  _R_AddMD3Surfaces(puVar5);
                  break;
                case 3:
                  _R_AddAnimSurfaces(puVar5);
                  break;
                default:
                  pcVar6 = s_R_AddEntitySurfaces__Bad_modelty;
                  goto LAB_0000e9a8;
                case 5:
                  _R_AddTikiSurfaces(puVar5);
                  break;
                case 6:
                  break;
                }
              }
              break;
            default:
              pcVar6 = s_R_AddEntitySurfaces__Bad_reType;
LAB_0000e9a8:
              (*_DAT_000100b4)(1,pcVar6);
              break;
            case 2:
              (*_DAT_000100b4)(1,s_R_AddEntitySurfaces__Sprite_bein);
              _DAT_000107f0 = _R_GetModelByHandle(puVar5[3]);
              if (_DAT_000107f0 == 0) {
                uVar3 = _R_GetShaderByHandle(puVar5[0x2e]);
                uVar4 = _R_SpriteFogNum(puVar5 + 0x12,puVar5[0x6e],0);
                _R_AddDrawSurf(&_entitySurface,uVar3,uVar4);
              }
              iVar2 = _DAT_000107f0;
              uVar3 = _R_SpriteFogNum(puVar5 + 0x12,puVar5[0x6e],0);
              _R_AddDrawSurf(&_entitySurface,*(undefined4 *)(*(int *)(iVar2 + 100) + 0x14),uVar3);
              break;
            case 3:
            case 4:
            case 5:
            case 6:
              if (((uVar1 & 1) == 0) || (_DAT_000108f8 != 0)) {
                uVar3 = _R_GetShaderByHandle(puVar5[0x2e]);
                uVar4 = _R_SpriteFogNum(puVar5 + 0x12,puVar5[0x6e],0);
                _R_AddDrawSurf(&_entitySurface,uVar3,uVar4);
              }
              break;
            case 7:
              break;
            }
          }
        }
      }
      _DAT_000107e4 = _DAT_000107e4 + 1;
    } while (_DAT_000107e4 < _DAT_00010d30);
  }
  return;
}



// ===========================================
// Function: _R_AddSpriteSurfaces @ 0000ea0c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddSpriteSurfaces(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((*(int *)(__r_drawsprites + 0x20) != 0) && (_DAT_000107e8 = 0, 0 < _DAT_00010d38)) {
    do {
      iVar6 = _DAT_000107e8 * 0x54 + _DAT_00010d3c;
      uVar1 = *(uint *)(iVar6 + 0x48);
      if (((uVar1 & 1) == 0) || (_DAT_000108f8 != 0)) {
        if (_DAT_00010b04 == 0) {
          if ((uVar1 & 0x4000) == 0) goto LAB_0000ea7a;
        }
        else if ((uVar1 & 0x4000) != 0) {
LAB_0000ea7a:
          if (_DAT_000108f8 == 0) {
            if ((uVar1 & 0x400000) == 0) goto LAB_0000ea9b;
          }
          else if ((uVar1 & 0xc00000) != 0) {
LAB_0000ea9b:
            _DAT_000107e4 = 0x3fe;
            _DAT_000107ec = 0x3fe000;
            _DAT_000107f0 = _R_GetModelByHandle(*(undefined4 *)(iVar6 + 4));
            if ((_DAT_000107f0 != 0) && (*(int *)(_DAT_000107f0 + 100) != 0)) {
              uVar5 = _R_SpriteFogNum((float *)(iVar6 + 0xc),
                                      (*(float **)(_DAT_000107f0 + 100))[4] *
                                      **(float **)(_DAT_000107f0 + 100) * *(float *)(iVar6 + 0x18));
              *(undefined4 *)(iVar6 + 0x50) = uVar5;
              *(undefined4 *)(iVar6 + 8) =
                   *(undefined4 *)(*(int *)(*(int *)(_DAT_000107f0 + 100) + 0x14) + 0x48);
              fVar2 = *(float *)(iVar6 + 0xc) - _DAT_00010bd0;
              fVar3 = *(float *)(iVar6 + 0x10) - _DAT_00010bd4;
              fVar4 = *(float *)(iVar6 + 0x14) - _DAT_00010bd8;
              _R_AddSpriteSurf(iVar6,*(undefined4 *)(*(int *)(_DAT_000107f0 + 100) + 0x14),
                               fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3);
            }
          }
        }
      }
      _DAT_000107e8 = _DAT_000107e8 + 1;
    } while (_DAT_000107e8 < _DAT_00010d38);
  }
  return;
}



// ===========================================
// Function: _R_GenerateDrawSurfs @ 0000eb8b
// ===========================================

void _R_GenerateDrawSurfs(void)

{
  _R_AddWorldSurfaces();
  if ((DAT_00010c04 & 1) == 0) {
    _R_AddSwipeSurfaces();
  }
  _R_AddPolygonSurfaces();
  _R_SetupProjection();
  _R_AddEntitySurfaces();
  _R_AddSpriteSurfaces();
  return;
}



// ===========================================
// Function: _R_DebugPolygon @ 0000ebb2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DebugPolygon(uint param_1)

{
  int iVar1;
  int unaff_ESI;
  
  _GL_State(0x122);
  (*__qglColor3f)((float)(param_1 & 1),(float)((int)param_1 >> 1 & 1),(float)((int)param_1 >> 2 & 1)
                 );
  (*__qglBegin)(9);
  iVar1 = unaff_ESI;
  if (0 < unaff_ESI) {
    do {
      (*__qglVertex3fv)();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  (*__qglEnd)();
  _GL_State();
  (*__qglDepthRange)(0,0);
  (*__qglColor3f)(0x3f800000,0x3f800000,0x3f800000);
  (*__qglBegin)(9);
  if (0 < unaff_ESI) {
    do {
      (*__qglVertex3fv)();
      unaff_ESI = unaff_ESI + -1;
    } while (unaff_ESI != 0);
  }
  (*__qglEnd)();
  (*__qglDepthRange)(0,0x3ff0000000000000);
  return;
}



// ===========================================
// Function: _R_DebugGraphics @ 0000ec9e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DebugGraphics(void)

{
  if (*(int *)(__r_debugSurface + 0x20) != 0) {
    _R_SyncRenderThread();
    _GL_Bind(_DAT_000100f4);
    _GL_Cull(0);
    (*__qglVertex3fv)(_R_DebugPolygon);
    _GLimp_Suspend();
    return;
  }
  return;
}



// ===========================================
// Function: _R_CullLocalPointAndRadius @ 0000ecd5
// ===========================================

void _R_CullLocalPointAndRadius(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_c [12];
  
  _R_LocalPointToWorld(param_1,local_c);
  _R_CullPointAndRadius(local_c,param_2);
  return;
}



// ===========================================
// Function: _R_MirrorViewBySurface @ 0000ed23
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_MirrorViewBySurface(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_568;
  float local_564;
  float local_560;
  float local_55c;
  float local_558;
  float local_554;
  undefined1 local_538 [48];
  undefined4 local_508 [3];
  undefined1 local_4fc [12];
  undefined1 local_4f0 [12];
  undefined1 local_4e4 [212];
  undefined1 local_410 [12];
  undefined4 local_404;
  undefined1 local_400 [12];
  float local_3f4;
  float local_3f0;
  float local_3ec;
  float local_3e8;
  undefined4 local_288 [3];
  undefined1 local_27c [12];
  undefined1 local_270 [12];
  undefined1 local_264 [608];
  
  if (_DAT_000108f8 == 0) {
    if ((*(int *)(__r_noportals + 0x20) == 0) && (*(int *)(__r_fastsky + 0x20) == 0)) {
      iVar1 = _SurfIsOffscreen(param_1[1],*(undefined4 *)((*param_1 >> 0x16) * 4 + 0x5504c),
                               *param_1 >> 0xc & 0x3ff);
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)&DAT_000107f4;
        puVar3 = local_288;
        for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        puVar2 = (undefined4 *)&DAT_000107f4;
        puVar3 = local_508;
        for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        local_404 = 1;
        iVar1 = _R_GetPortalOrientations(param_1,param_2,local_538,&local_568,local_410,local_400);
        if (iVar1 != 0) {
          _DAT_00010bb4 = 1;
          _R_MirrorPoint(local_288,local_538,&local_568,local_508);
          local_3f4 = __vec3_origin - local_55c;
          local_3f0 = _DAT_0001016c - local_558;
          local_3ec = ___ftol2_sse - local_554;
          local_3e8 = local_560 * local_3ec + local_568 * local_3f4 + local_564 * local_3f0;
          _R_MirrorVector(local_27c,local_538,&local_568,local_4fc);
          _R_MirrorVector(local_270,local_538,&local_568,local_4f0);
          _R_MirrorVector(local_264,local_538,&local_568,local_4e4);
          _R_RenderView(local_508);
          puVar2 = local_288;
          puVar3 = (undefined4 *)&DAT_000107f4;
          for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar3 = puVar3 + 1;
          }
          return 1;
        }
      }
    }
  }
  else {
    (*__ri)(1,s_WARNING__recursive_mirror_portal);
  }
  return 0;
}



// ===========================================
// Function: _R_SortDrawSurfs @ 0000ef04
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SortDrawSurfs(uint *param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  if (0x10000 < param_2) {
    param_2 = 0x10000;
  }
  if (0x10000 < param_4) {
    param_4 = 0x10000;
  }
  qsortFast(param_1,param_2,8);
  qsortFast(param_3,param_4,8);
  _R_Sky_Render();
  if ((_DAT_000108f8 == 0) && (iVar3 = 0, puVar4 = param_1, 0 < param_2)) {
    do {
      uVar1 = *puVar4;
      iVar2 = *(int *)((uVar1 >> 0x16) * 4 + 0x5504c);
      if (1.0 < *(float *)(iVar2 + 0x4c) != NAN(*(float *)(iVar2 + 0x4c))) break;
      if (NAN(*(float *)(iVar2 + 0x4c)) != (*(float *)(iVar2 + 0x4c) == 0.0)) {
        (*_DAT_000100b4)(1,s_Shader___s_with_sort____SS_BAD,iVar2);
      }
      iVar2 = _R_MirrorViewBySurface(puVar4,uVar1 >> 0xc & 0x3ff);
      if (iVar2 != 0) {
        if (*(int *)(__r_portalOnly + 0x20) != 0) {
          return;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 2;
    } while (iVar3 < param_2);
  }
  _R_AddDrawSurfCmd(param_1,param_2);
  _R_AddSpriteSurfCmd(param_3,param_4);
  return;
}



// ===========================================
// Function: _R_RenderView @ 0000efdc
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_RenderView(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((0 < (int)param_1[0x4c]) && (0 < (int)param_1[0x4d])) {
    ___fltused = ___fltused + 1;
    puVar4 = (undefined4 *)&DAT_000107f4;
    for (iVar3 = 0xa0; iVar2 = _DAT_00010d58, iVar1 = _DAT_00010d50, iVar3 != 0; iVar3 = iVar3 + -1)
    {
      *puVar4 = *param_1;
      param_1 = param_1 + 1;
      puVar4 = puVar4 + 1;
    }
    ___fltused = ___fltused + 1;
    _DAT_00010900 = ___CIcos;
    _DAT_00010904 = __r_numdebuglines;
    _R_RotateForViewer();
    _R_SetupFrustum();
    _R_Sky_Reset();
    _R_AddWorldSurfaces();
    if ((DAT_00010c04 & 1) == 0) {
      _R_AddSwipeSurfaces();
    }
    _R_AddPolygonSurfaces();
    _R_SetupProjection();
    _R_AddEntitySurfaces();
    _R_AddSpriteSurfaces();
    _R_SortDrawSurfs(_DAT_00010d54 + iVar1 * 8,_DAT_00010d50 - iVar1,_DAT_00010d5c + iVar2 * 8,
                     _DAT_00010d58 - iVar2);
    _R_DrawDebugLines();
    _R_DebugGraphics();
    (*__qglDisable)(0xc11);
  }
  return;
}



