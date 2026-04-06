// ===========================================
// Function: _RB_CheckOverflow @ 0000a400
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_CheckOverflow(int param_1,int param_2)

{
  if ((_DAT_00324eec + param_1 < 30000) && (_DAT_00324ee8 + param_2 < 180000)) {
    return;
  }
  _RB_EndSurface();
  if (29999 < param_1) {
    (*_DAT_0000de8c)(1,s_RB_CheckOverflow__verts_>_MAX___,param_1,&DAT_00007530);
  }
  if (179999 < param_2) {
    (*_DAT_0000de8c)(1,s_RB_CheckOverflow__indices_>_MAX_,param_2,180000);
  }
  _RB_BeginSurface();
  return;
}



// ===========================================
// Function: _RB_AddQuadStampExt @ 0000a486
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_AddQuadStampExt(float *param_1,float *param_2,float *param_3,undefined4 *param_4,
                        undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  if ((29999 < _DAT_00324eec + 4) ||
     ((179999 < _DAT_00324ee8 + 6 && ((29999 < _DAT_00324eec + 4 || (179999 < _DAT_00324ee8 + 6)))))
     ) {
    _RB_EndSurface();
    _RB_BeginSurface(_DAT_00324ed8,_DAT_00324edc);
  }
  iVar5 = _DAT_00324eec;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec;
  *(int *)(&DAT_0000de9c + _DAT_00324ee8 * 4) = iVar5 + 1;
  *(int *)(&_backEnd + _DAT_00324ee8 * 4) = iVar5 + 3;
  *(int *)(&DAT_0000dea4 + _DAT_00324ee8 * 4) = iVar5 + 3;
  *(int *)(&_vec3_origin + _DAT_00324ee8 * 4) = iVar5 + 1;
  *(int *)(&DAT_0000deac + _DAT_00324ee8 * 4) = iVar5 + 2;
  iVar6 = iVar5 * 0x10;
  *(float *)(iVar6 + 0xbdb18) = *param_2 + *param_1 + *param_3;
  *(float *)(iVar6 + 0xbdb1c) = param_1[1] + param_2[1] + param_3[1];
  *(float *)(iVar6 + 0xbdb20) = param_1[2] + param_2[2] + param_3[2];
  *(float *)(iVar6 + 0xbdb28) = (*param_1 - *param_2) + *param_3;
  *(float *)(iVar6 + 0xbdb2c) = (param_1[1] - param_2[1]) + param_3[1];
  *(float *)(iVar6 + 0xbdb30) = (param_1[2] - param_2[2]) + param_3[2];
  *(float *)(iVar6 + 0xbdb38) = (*param_1 - *param_2) - *param_3;
  *(float *)(iVar6 + 0xbdb3c) = (param_1[1] - param_2[1]) - param_3[1];
  *(float *)(iVar6 + 0xbdb40) = (param_1[2] - param_2[2]) - param_3[2];
  *(float *)(iVar6 + 0xbdb48) = (*param_2 + *param_1) - *param_3;
  *(float *)(iVar6 + 0xbdb4c) = (param_1[1] + param_2[1]) - param_3[1];
  *(float *)(iVar6 + 0xbdb50) = (param_1[2] + param_2[2]) - param_3[2];
  fVar2 = __vec3_origin - _DAT_0000e094;
  fVar3 = _DAT_0000deac - _DAT_0000e098;
  fVar4 = ___fltused - _DAT_0000e09c;
  *(float *)(iVar6 + 0x132e48) = fVar2;
  *(float *)(iVar6 + 0x132e38) = fVar2;
  *(float *)(iVar6 + 0x132e28) = fVar2;
  *(float *)(iVar6 + 0x132e18) = fVar2;
  *(float *)(iVar6 + 0x132e4c) = fVar3;
  *(float *)(iVar6 + 0x132e3c) = fVar3;
  *(float *)(iVar6 + 0x132e2c) = fVar3;
  *(float *)(iVar6 + 0x132e1c) = fVar3;
  *(float *)(iVar6 + 0x132e50) = fVar4;
  *(float *)(iVar6 + 0x132e40) = fVar4;
  *(float *)(iVar6 + 0x132e30) = fVar4;
  *(float *)(iVar6 + 0x132e20) = fVar4;
  *(undefined4 *)(iVar6 + 0x1a8120) = param_5;
  *(undefined4 *)(iVar6 + 0x1a8118) = param_5;
  *(undefined4 *)(iVar6 + 0x1a8124) = param_6;
  *(undefined4 *)(iVar6 + 0x1a811c) = param_6;
  *(undefined4 *)(iVar6 + 0x1a8130) = param_7;
  *(undefined4 *)(iVar6 + 0x1a8128) = param_7;
  *(undefined4 *)(iVar6 + 0x1a8140) = param_7;
  *(undefined4 *)(iVar6 + 0x1a8138) = param_7;
  *(undefined4 *)(iVar6 + 0x1a8134) = param_6;
  *(undefined4 *)(iVar6 + 0x1a812c) = param_6;
  *(undefined4 *)(iVar6 + 0x1a8144) = param_8;
  *(undefined4 *)(iVar6 + 0x1a813c) = param_8;
  *(undefined4 *)(iVar6 + 0x1a8154) = param_8;
  *(undefined4 *)(iVar6 + 0x1a814c) = param_8;
  *(undefined4 *)(iVar6 + 0x1a8150) = param_5;
  *(undefined4 *)(iVar6 + 0x1a8148) = param_5;
  uVar1 = *param_4;
  *(undefined4 *)(iVar5 * 4 + 0x21d424) = uVar1;
  *(undefined4 *)(iVar5 * 4 + 0x21d420) = uVar1;
  *(undefined4 *)(iVar5 * 4 + 0x21d41c) = uVar1;
  *(undefined4 *)(iVar5 * 4 + 0x21d418) = uVar1;
  _DAT_00324eec = _DAT_00324eec + 4;
  _DAT_00324ee8 = _DAT_00324ee8 + 6;
  _DAT_00324f04 = 1;
  return;
}



// ===========================================
// Function: _RB_AddQuadStamp @ 0000a721
// ===========================================

void _RB_AddQuadStamp(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _RB_AddQuadStampExt(param_1,param_2,param_3,param_4,0,0,0x3f800000,0x3f800000);
  return;
}



// ===========================================
// Function: _RB_SurfaceSprite @ 0000a754
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceSprite(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = _DAT_0000e3b8;
  fVar1 = *(float *)(_DAT_0000e3b8 + 0x1b8);
  if (NAN(*(float *)(_DAT_0000e3b8 + 0x1bc)) == (*(float *)(_DAT_0000e3b8 + 0x1bc) == 0.0)) {
    fVar5 = (float10)__CIsin();
    fVar6 = (float10)__CIcos();
    fVar2 = fVar1 * (float)fVar6;
    fVar3 = -(float)fVar5 * fVar1;
    local_18 = _DAT_0000e0ac * fVar3 + _DAT_0000e0a0 * fVar2;
    local_14 = _DAT_0000e0b0 * fVar3 + _DAT_0000e0a4 * fVar2;
    local_10 = _DAT_0000e0a8 * fVar2 + _DAT_0000e0b4 * fVar3;
    fVar1 = (float)fVar5 * fVar1;
    local_c = _DAT_0000e0a0 * fVar1 + _DAT_0000e0ac * fVar2;
    local_8 = _DAT_0000e0a4 * fVar1 + _DAT_0000e0b0 * fVar2;
    local_4 = fVar1 * _DAT_0000e0a8 + _DAT_0000e0b4 * fVar2;
  }
  else {
    local_18 = fVar1 * _DAT_0000e0a0;
    local_14 = _DAT_0000e0a4 * fVar1;
    local_10 = _DAT_0000e0a8 * fVar1;
    local_c = _DAT_0000e0ac * fVar1;
    local_8 = _DAT_0000e0b0 * fVar1;
    local_4 = fVar1 * _DAT_0000e0b4;
  }
  if (_DAT_0000e190 != 0) {
    local_18 = __vec3_origin - local_18;
    local_14 = _DAT_0000deac - local_14;
    local_10 = ___fltused - local_10;
  }
  _RB_AddQuadStampExt(iVar4 + 0x48,&local_18,&local_c,iVar4 + 0xbc,0,0,0x3f800000,0x3f800000);
  return;
}



// ===========================================
// Function: _RB_SurfacePolychain @ 0000a921
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfacePolychain(int param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((29999 < *(int *)(param_1 + 0xc) + _DAT_00324eec) ||
     (179999 < _DAT_00324ee8 + (*(int *)(param_1 + 0xc) + -2) * 3)) {
    _RB_CheckOverflow(*(int *)(param_1 + 0xc),*(int *)(param_1 + 0xc) * 3 + -6);
  }
  if ((*(int *)(_DAT_00324ed8 + 0xbc) == 0) || (*(int *)(param_1 + 0xc) < 3)) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0x3f800000;
  }
  else {
    pfVar1 = *(float **)(param_1 + 0x10);
    local_c = *pfVar1 - pfVar1[0xc];
    local_8 = pfVar1[1] - pfVar1[0xd];
    local_4 = pfVar1[2] - pfVar1[0xe];
    local_18 = *pfVar1 - pfVar1[6];
    local_14 = pfVar1[1] - pfVar1[7];
    local_10 = pfVar1[2] - pfVar1[8];
    _CrossProduct(&local_c,&local_18,&local_24);
    _VectorNormalize(&local_24);
  }
  iVar4 = 0;
  iVar5 = _DAT_00324eec;
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar2 = (undefined4 *)(_DAT_00324eec * 0x10 + 0xbdb1c);
    iVar3 = 0;
    do {
      iVar4 = iVar4 + 1;
      puVar2[-1] = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x10));
      iVar5 = iVar5 + 1;
      *puVar2 = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x10));
      puVar2[1] = *(undefined4 *)(iVar3 + 8 + *(int *)(param_1 + 0x10));
      puVar2[119999] = local_24;
      puVar2[120000] = local_20;
      puVar2[0x1d4c1] = local_1c;
      puVar2[239999] = *(undefined4 *)(iVar3 + 0xc + *(int *)(param_1 + 0x10));
      puVar2[240000] = *(undefined4 *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10));
      *(undefined4 *)(iVar5 * 4 + 0x21d414) =
           *(undefined4 *)(iVar3 + 0x14 + *(int *)(param_1 + 0x10));
      puVar2 = puVar2 + 4;
      iVar3 = iVar3 + 0x18;
    } while (iVar4 < *(int *)(param_1 + 0xc));
  }
  iVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 2 && -1 < *(int *)(param_1 + 0xc) + -2) {
    do {
      *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec;
      *(int *)(&DAT_0000de9c + _DAT_00324ee8 * 4) = _DAT_00324eec + 1 + iVar4;
      *(int *)(&_backEnd + _DAT_00324ee8 * 4) = _DAT_00324eec + 2 + iVar4;
      _DAT_00324ee8 = _DAT_00324ee8 + 3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0xc) + -2);
  }
  _DAT_00324eec = iVar5;
  _DAT_00324f04 = 1;
  return;
}



// ===========================================
// Function: _RB_SurfaceTriangles @ 0000ab0a
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceTriangles(int param_1)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int local_4b10;
  int iStack_4b0c;
  int local_4b08;
  int aiStack_4b00 [4799];
  undefined4 uStack_4;
  
  uStack_4 = 0xab14;
  uVar3 = *(uint *)(param_1 + 4 + __backEnd * 4);
  _DAT_00324ee0 = _DAT_00324ee0 | uVar3;
  if ((*(uint *)(_DAT_00324ed8 + 0x58) & 0x800004) != 0) {
    _DAT_00324ee0 = 0;
  }
  iVar11 = *(int *)(param_1 + 0x40);
  fVar2 = *(float *)(iVar11 + 0x18);
  _R_CalcLod(param_1 + 0x24,*(float *)(param_1 + 0x30) * (float)___real_3ff8000000000000,
             *(undefined4 *)(iVar11 + 0x44),*(undefined4 *)(iVar11 + 0x70));
  iVar11 = *(int *)(param_1 + 0x3c);
  iStack_4b0c = __ftol2_sse();
  if ((fVar2 <= (float)iStack_4b0c) || (iStack_4b0c = __ftol2_sse(), 0 < iStack_4b0c)) {
    if (iVar11 < iStack_4b0c) {
      iStack_4b0c = iVar11;
    }
    if ((29999 < _DAT_00324eec + iStack_4b0c) || (179999 < *(int *)(param_1 + 0x34) + _DAT_00324ee8)
       ) {
      _RB_CheckOverflow(iStack_4b0c,*(undefined4 *)(param_1 + 0x34));
    }
    iVar11 = *(int *)(param_1 + 0x3c);
    iVar6 = 0;
    if (iStack_4b0c == iVar11) {
      iVar11 = _DAT_00324ee8 * 4;
      if (0 < *(int *)(param_1 + 0x34)) {
        do {
          iVar1 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          *(int *)(iVar11 + 0xde94 + iVar6 * 4) =
               *(int *)(*(int *)(param_1 + 0x38) + iVar1) + _DAT_00324eec;
        } while (iVar6 < *(int *)(param_1 + 0x34));
      }
      _DAT_00324ee8 = _DAT_00324ee8 + *(int *)(param_1 + 0x34);
    }
    else {
      if (0 < iStack_4b0c) {
        do {
          aiStack_4b00[iVar6] = iVar6;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iStack_4b0c);
      }
      if (iStack_4b0c < iVar11) {
        piVar9 = (int *)(iStack_4b0c * 0x2c + 0x14 + *(int *)(param_1 + 0x40));
        iVar6 = iStack_4b0c;
        do {
          aiStack_4b00[iVar6] = aiStack_4b00[*piVar9];
          iVar6 = iVar6 + 1;
          piVar9 = piVar9 + 0xb;
        } while (iVar6 < iVar11);
      }
      iVar11 = 0;
      if (0 < *(int *)(param_1 + 0x34)) {
        do {
          iVar6 = *(int *)(param_1 + 0x38);
          iVar1 = aiStack_4b00[*(int *)(iVar6 + iVar11 * 4)];
          iVar4 = aiStack_4b00[*(int *)(iVar6 + 4 + iVar11 * 4)];
          iVar6 = aiStack_4b00[*(int *)(iVar6 + 8 + iVar11 * 4)];
          if (((iVar1 != iVar4) && (iVar4 != iVar6)) && (iVar6 != iVar1)) {
            *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec + iVar1;
            *(int *)(&DAT_0000de9c + _DAT_00324ee8 * 4) = _DAT_00324eec + iVar4;
            *(int *)(&_backEnd + _DAT_00324ee8 * 4) = _DAT_00324eec + iVar6;
            _DAT_00324ee8 = _DAT_00324ee8 + 3;
          }
          iVar11 = iVar11 + 3;
        } while (iVar11 < *(int *)(param_1 + 0x34));
      }
    }
    puVar8 = *(undefined4 **)(param_1 + 0x40);
    iVar11 = _DAT_00324eec * 0x10;
    puVar10 = (undefined4 *)(iVar11 + 0xbdb18);
    puVar14 = (undefined4 *)(iVar11 + 0x132e18);
    puVar12 = (undefined4 *)(iVar11 + 0x1a8118);
    puVar13 = (undefined4 *)(_DAT_00324eec * 4 + 0x21d418);
    if (((*(int *)(_DAT_00324ed8 + 0xbc) == 0) && (*(int *)(_DAT_00324ed8 + 0x1fc) == 0)) &&
       (_DAT_0000eb60 == 0)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    _DAT_00324f04 = 1;
    local_4b10 = 0;
    if (3 < iStack_4b0c) {
      local_4b08 = (iStack_4b0c - 4U >> 2) + 1;
      local_4b10 = local_4b08 * 4;
      puVar7 = puVar8;
      do {
        *puVar10 = *puVar7;
        puVar10[1] = puVar7[1];
        puVar10[2] = puVar7[2];
        if (bVar5) {
          *puVar14 = puVar7[7];
          puVar14[1] = puVar7[8];
          puVar14[2] = puVar7[9];
        }
        *puVar12 = puVar7[3];
        puVar12[1] = puVar7[4];
        *puVar13 = puVar7[10];
        puVar10[4] = puVar7[0xb];
        puVar10[5] = puVar7[0xc];
        puVar10[6] = puVar7[0xd];
        if (bVar5) {
          puVar14[4] = puVar7[0x12];
          puVar14[5] = puVar7[0x13];
          puVar14[6] = puVar7[0x14];
        }
        puVar12[4] = puVar7[0xe];
        puVar12[5] = puVar7[0xf];
        puVar13[1] = puVar7[0x15];
        puVar10[8] = puVar7[0x16];
        puVar10[9] = puVar7[0x17];
        puVar10[10] = puVar7[0x18];
        if (bVar5) {
          puVar14[8] = puVar7[0x1d];
          puVar14[9] = puVar7[0x1e];
          puVar14[10] = puVar7[0x1f];
        }
        puVar12[8] = puVar7[0x19];
        puVar12[9] = puVar7[0x1a];
        puVar13[2] = puVar7[0x20];
        puVar10[0xc] = puVar7[0x21];
        puVar10[0xd] = puVar7[0x22];
        puVar10[0xe] = puVar7[0x23];
        if (bVar5) {
          puVar14[0xc] = puVar7[0x28];
          puVar14[0xd] = puVar7[0x29];
          puVar14[0xe] = puVar7[0x2a];
        }
        puVar8 = puVar7 + 0x2c;
        puVar12[0xc] = puVar7[0x24];
        puVar10 = puVar10 + 0x10;
        puVar14 = puVar14 + 0x10;
        puVar12[0xd] = puVar7[0x25];
        puVar13[3] = puVar7[0x2b];
        puVar12 = puVar12 + 0x10;
        puVar13 = puVar13 + 4;
        local_4b08 = local_4b08 + -1;
        puVar7 = puVar8;
      } while (local_4b08 != 0);
    }
    if (local_4b10 < iStack_4b0c) {
      local_4b10 = iStack_4b0c - local_4b10;
      do {
        *puVar10 = *puVar8;
        puVar10[1] = puVar8[1];
        puVar10[2] = puVar8[2];
        if (bVar5) {
          *puVar14 = puVar8[7];
          puVar14[1] = puVar8[8];
          puVar14[2] = puVar8[9];
        }
        *puVar12 = puVar8[3];
        puVar10 = puVar10 + 4;
        puVar14 = puVar14 + 4;
        puVar12[1] = puVar8[4];
        *puVar13 = puVar8[10];
        puVar12 = puVar12 + 4;
        puVar13 = puVar13 + 1;
        local_4b10 = local_4b10 + -1;
        puVar8 = puVar8 + 0xb;
      } while (local_4b10 != 0);
    }
    iVar11 = 0;
    if (0 < *(int *)(param_1 + 0x3c)) {
      do {
        iVar6 = _DAT_00324eec + iVar11;
        iVar11 = iVar11 + 1;
        *(uint *)(iVar6 * 4 + 0x23a8d8) = uVar3;
      } while (iVar11 < *(int *)(param_1 + 0x3c));
    }
    _DAT_00324eec = _DAT_00324eec + iStack_4b0c;
  }
  return;
}



// ===========================================
// Function: _RB_SurfaceBeam @ 0000af4f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceBeam(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  float local_c8;
  float local_c4;
  float local_c0;
  int iStack_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0 [4];
  float afStack_90 [13];
  undefined1 auStack_5c [20];
  float afStack_48 [18];
  
  local_c8 = *(float *)(_DAT_0000e3b8 + 0x9c);
  local_c4 = *(float *)(_DAT_0000e3b8 + 0xa0);
  local_c0 = *(float *)(_DAT_0000e3b8 + 0xa4);
  local_ac = *(float *)(_DAT_0000e3b8 + 0x48);
  local_a8 = *(float *)(_DAT_0000e3b8 + 0x4c);
  local_a4 = *(float *)(_DAT_0000e3b8 + 0x50);
  local_b8 = local_c8 - local_ac;
  local_b4 = local_c4 - local_a8;
  local_b0 = local_c0 - local_a4;
  local_a0[0] = local_b8;
  local_a0[1] = local_b4;
  local_a0[2] = local_b0;
  fVar5 = (float10)_VectorNormalize(local_a0);
  if ((NAN(fVar5) || NAN((float10)___real_00000000)) == (fVar5 == (float10)___real_00000000)) {
    _PerpendicularVector(&local_c8,local_a0);
    fVar1 = (float)___real_4010000000000000;
    local_c8 = local_c8 * fVar1;
    iStack_bc = 0;
    local_c4 = local_c4 * fVar1;
    local_c0 = fVar1 * local_c0;
    iVar2 = 0;
    do {
      local_a0[3] = (float)iStack_bc * (float)___real_404e000000000000;
      _RotatePointAroundVector((float *)((int)afStack_90 + iVar2),local_a0,&local_c8,local_a0[3]);
      iStack_bc = iStack_bc + 1;
      iVar3 = iVar2 + 0xc;
      *(float *)((int)afStack_48 + iVar2) = *(float *)((int)afStack_90 + iVar2) + local_b8;
      *(float *)((int)afStack_48 + iVar2 + 4) = *(float *)((int)afStack_90 + iVar2 + 4) + local_b4;
      *(float *)((int)afStack_48 + iVar2 + 8) = *(float *)((int)afStack_90 + iVar2 + 8) + local_b0;
      iVar2 = iVar3;
    } while (iVar3 < 0x48);
    _GL_Bind(_DAT_0000df14);
    _GL_State(0x22);
    (*__qglColor3f)(0x3f800000,0,0);
    (*__qglBegin)(5);
    uVar4 = 0;
    do {
      (*__qglVertex3fv)(local_a0 + (uVar4 % 6) * 3);
      (*__qglVertex3fv)(auStack_5c + (uVar4 % 6) * 0xc);
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 7);
    (*__qglEnd)();
  }
  return;
}



// ===========================================
// Function: _DoRailCore @ 0000b10c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _DoRailCore(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float *in_EAX;
  float *unaff_ESI;
  
  fVar6 = param_3;
  iVar5 = _DAT_00324eec;
  fVar2 = (float)___real_3f70000000000000;
  fVar1 = -param_3;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = *param_1 * param_3 + *in_EAX;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = param_1[1] * param_3 + in_EAX[1];
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = param_1[2] * param_3 + in_EAX[2];
  *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a8118) = 0;
  *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0;
  iVar4 = _DAT_0000e3b8;
  dVar3 = ___real_3fd0000000000000;
  param_3._0_1_ =
       (undefined1)(int)ROUND((double)*(byte *)(_DAT_0000e3b8 + 0xbc) * ___real_3fd0000000000000);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = param_3._0_1_;
  param_3._0_1_ = (undefined1)(int)ROUND((double)*(byte *)(iVar4 + 0xbd) * dVar3);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = param_3._0_1_;
  param_3._0_1_ = (undefined1)(int)ROUND((double)*(byte *)(iVar4 + 0xbe) * dVar3);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = param_3._0_1_;
  _DAT_00324eec = _DAT_00324eec + 1;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = *in_EAX + fVar1 * *param_1;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = param_1[1] * fVar1 + in_EAX[1];
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = param_1[2] * fVar1 + in_EAX[2];
  *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a8118) = 0;
  *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0x3f800000;
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar4 + 0xbc);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar4 + 0xbd);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar4 + 0xbe);
  _DAT_00324eec = _DAT_00324eec + 1;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = *param_1 * fVar6 + *unaff_ESI;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = param_1[1] * fVar6 + unaff_ESI[1];
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = unaff_ESI[2] + param_1[2] * fVar6;
  *(float *)(_DAT_00324eec * 0x10 + 0x1a8118) = param_2 * fVar2;
  *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0;
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar4 + 0xbc);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar4 + 0xbd);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar4 + 0xbe);
  _DAT_00324eec = _DAT_00324eec + 1;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = *param_1 * fVar1 + *unaff_ESI;
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = param_1[1] * fVar1 + unaff_ESI[1];
  *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = unaff_ESI[2] + param_1[2] * fVar1;
  *(float *)(_DAT_00324eec * 0x10 + 0x1a8118) = param_2 * fVar2;
  *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0x3f800000;
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar4 + 0xbc);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar4 + 0xbd);
  *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar4 + 0xbe);
  _DAT_00324eec = _DAT_00324eec + 1;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar5;
  _DAT_00324ee8 = _DAT_00324ee8 + 1;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar5 + 1;
  _DAT_00324ee8 = _DAT_00324ee8 + 1;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar5 + 2;
  _DAT_00324ee8 = _DAT_00324ee8 + 1;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar5 + 2;
  _DAT_00324ee8 = _DAT_00324ee8 + 1;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar5 + 1;
  _DAT_00324ee8 = _DAT_00324ee8 + 1;
  *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar5 + 3;
  _DAT_00324ee8 = _DAT_00324ee8 + 1;
  _DAT_00324f04 = 1;
  return;
}



// ===========================================
// Function: _DoRailDiscs @ 0000b555
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DoRailDiscs(int param_1,float *param_2,float *param_3,float *param_4)

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
  int iVar10;
  int iVar11;
  float *unaff_ESI;
  float *pfVar12;
  float10 fVar13;
  int local_50;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (1 < param_1) {
    param_1 = param_1 + -1;
  }
  if (param_1 != 0) {
    fVar7 = (float)*(int *)(__r_railWidth + 0x20);
    pfVar12 = &local_2c;
    local_50 = 0x2d;
    do {
      fVar13 = (float10)__CIcos();
      fVar1 = (float)fVar13;
      fVar13 = (float10)__CIsin();
      fVar2 = (float)fVar13;
      fVar9 = (float)___real_3fd0000000000000;
      fVar3 = param_4[1];
      fVar4 = param_3[1];
      fVar5 = param_3[2];
      fVar6 = param_4[2];
      fVar8 = *param_2 + fVar7 * (fVar1 * *param_3 + fVar2 * *param_4) * fVar9;
      pfVar12[-1] = fVar8;
      fVar3 = param_2[1] + (fVar1 * fVar4 + fVar3 * fVar2) * fVar9 * fVar7;
      *pfVar12 = fVar3;
      fVar1 = param_2[2] + (fVar5 * fVar1 + fVar6 * fVar2) * fVar9 * fVar7;
      pfVar12[1] = fVar1;
      if (1 < param_1) {
        pfVar12[-1] = *unaff_ESI + fVar8;
        *pfVar12 = fVar3 + unaff_ESI[1];
        pfVar12[1] = fVar1 + unaff_ESI[2];
      }
      local_50 = local_50 + 0x5a;
      pfVar12 = pfVar12 + 3;
    } while (local_50 < 0x195);
    iVar10 = _DAT_0000e3b8;
    if (0 < param_1) {
      do {
        if (((29999 < _DAT_00324eec + 4) || (179999 < _DAT_00324ee8 + 6)) &&
           ((29999 < _DAT_00324eec + 4 || (179999 < _DAT_00324ee8 + 6)))) {
          _RB_EndSurface();
          _RB_BeginSurface(_DAT_00324ed8,_DAT_00324edc);
          iVar10 = _DAT_0000e3b8;
        }
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = local_30;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = local_2c;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = local_28;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a8118) = 0x3f800000;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0;
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar10 + 0xbc);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar10 + 0xbd);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar10 + 0xbe);
        _DAT_00324eec = _DAT_00324eec + 1;
        local_30 = *unaff_ESI + local_30;
        local_2c = local_2c + unaff_ESI[1];
        local_28 = unaff_ESI[2] + local_28;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = fStack_24;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = fStack_20;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = fStack_1c;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a8118) = 0x3f800000;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0x3f800000;
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar10 + 0xbc);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar10 + 0xbd);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar10 + 0xbe);
        _DAT_00324eec = _DAT_00324eec + 1;
        fStack_24 = *unaff_ESI + fStack_24;
        fStack_20 = fStack_20 + unaff_ESI[1];
        fStack_1c = unaff_ESI[2] + fStack_1c;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = fStack_18;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = fStack_14;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = fStack_10;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a8118) = 0;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0x3f800000;
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar10 + 0xbc);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar10 + 0xbd);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar10 + 0xbe);
        _DAT_00324eec = _DAT_00324eec + 1;
        fStack_18 = *unaff_ESI + fStack_18;
        fStack_14 = fStack_14 + unaff_ESI[1];
        fStack_10 = unaff_ESI[2] + fStack_10;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb18) = fStack_c;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb1c) = fStack_8;
        *(float *)(_DAT_00324eec * 0x10 + 0xbdb20) = fStack_4;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a8118) = 0;
        *(undefined4 *)(_DAT_00324eec * 0x10 + 0x1a811c) = 0;
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d418) = *(undefined1 *)(iVar10 + 0xbc);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d419) = *(undefined1 *)(iVar10 + 0xbd);
        *(undefined1 *)(_DAT_00324eec * 4 + 0x21d41a) = *(undefined1 *)(iVar10 + 0xbe);
        _DAT_00324f04 = 1;
        fStack_c = *unaff_ESI + fStack_c;
        fStack_8 = fStack_8 + unaff_ESI[1];
        iVar11 = _DAT_00324eec + -3;
        fStack_4 = unaff_ESI[2] + fStack_4;
        _DAT_00324eec = _DAT_00324eec + 1;
        *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar11;
        _DAT_00324ee8 = _DAT_00324ee8 + 1;
        *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec + -3;
        _DAT_00324ee8 = _DAT_00324ee8 + 1;
        *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec + -1;
        _DAT_00324ee8 = _DAT_00324ee8 + 1;
        *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec + -1;
        _DAT_00324ee8 = _DAT_00324ee8 + 1;
        *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec + -3;
        _DAT_00324ee8 = _DAT_00324ee8 + 1;
        *(int *)(&_tess + _DAT_00324ee8 * 4) = _DAT_00324eec + -2;
        _DAT_00324ee8 = _DAT_00324ee8 + 1;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}



// ===========================================
// Function: _RB_SurfaceRailRings @ 0000bade
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceRailRings(void)

{
  int iVar1;
  int iVar2;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 auStack_c [12];
  
  local_24 = *(float *)(_DAT_0000e3b8 + 0x9c);
  local_20 = *(float *)(_DAT_0000e3b8 + 0xa0);
  local_1c = *(float *)(_DAT_0000e3b8 + 0xa4);
  local_18 = *(float *)(_DAT_0000e3b8 + 0x48);
  local_14 = *(float *)(_DAT_0000e3b8 + 0x4c);
  local_10 = *(float *)(_DAT_0000e3b8 + 0x50);
  local_30 = local_18 - local_24;
  local_2c = local_14 - local_20;
  local_28 = local_10 - local_1c;
  _VectorNormalize(&local_30);
  __ftol2_sse();
  _MakeNormalVectors(&local_30,auStack_c,&local_18);
  iVar1 = __r_railSegmentLength;
  iVar2 = __ftol2_sse();
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  local_30 = *(float *)(iVar1 + 0x1c) * local_30;
  local_2c = *(float *)(iVar1 + 0x1c) * local_2c;
  local_28 = *(float *)(iVar1 + 0x1c) * local_28;
  _DoRailDiscs(iVar2,&local_24,auStack_c,&local_18);
  return;
}



// ===========================================
// Function: _RB_SurfaceRailCore @ 0000bbc5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceRailCore(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 auStack_c [12];
  
  fVar1 = *(float *)(_DAT_0000e3b8 + 0x9c);
  fVar2 = *(float *)(_DAT_0000e3b8 + 0xa0);
  fVar3 = *(float *)(_DAT_0000e3b8 + 0xa4);
  fVar4 = *(float *)(_DAT_0000e3b8 + 0x48);
  fVar5 = *(float *)(_DAT_0000e3b8 + 0x4c);
  fVar6 = *(float *)(_DAT_0000e3b8 + 0x50);
  local_18 = fVar4 - fVar1;
  local_14 = fVar5 - fVar2;
  local_10 = fVar6 - fVar3;
  _VectorNormalize(&local_18);
  iVar7 = __ftol2_sse();
  fStack_24 = fVar1 - _DAT_0000e088;
  fStack_20 = fVar2 - _DAT_0000e08c;
  fStack_1c = fVar3 - _DAT_0000e090;
  _VectorNormalize(&fStack_24);
  fStack_30 = fVar4 - _DAT_0000e088;
  fStack_2c = fVar5 - _DAT_0000e08c;
  fStack_28 = fVar6 - _DAT_0000e090;
  _VectorNormalize(&fStack_30);
  _CrossProduct(&fStack_24,&fStack_30,auStack_c);
  _VectorNormalize(auStack_c);
  _DoRailCore((float)iVar7,(float)*(int *)(__r_railCoreWidth + 0x20));
  return;
}



// ===========================================
// Function: _RB_SurfaceLightningBolt @ 0000bcf4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceLightningBolt(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_3c [12];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 auStack_c [12];
  
  fVar1 = *(float *)(_DAT_0000e3b8 + 0x9c);
  fVar2 = *(float *)(_DAT_0000e3b8 + 0xa0);
  fVar3 = *(float *)(_DAT_0000e3b8 + 0xa4);
  fVar4 = *(float *)(_DAT_0000e3b8 + 0x48);
  fVar5 = *(float *)(_DAT_0000e3b8 + 0x4c);
  fVar6 = *(float *)(_DAT_0000e3b8 + 0x50);
  local_18 = fVar1 - fVar4;
  local_14 = fVar2 - fVar5;
  local_10 = fVar3 - fVar6;
  _VectorNormalize(&local_18);
  iVar7 = __ftol2_sse();
  fStack_24 = fVar4 - _DAT_0000e088;
  fStack_20 = fVar5 - _DAT_0000e08c;
  fStack_1c = fVar6 - _DAT_0000e090;
  _VectorNormalize(&fStack_24);
  fStack_30 = fVar1 - _DAT_0000e088;
  fStack_2c = fVar2 - _DAT_0000e08c;
  fStack_28 = fVar3 - _DAT_0000e090;
  _VectorNormalize(&fStack_30);
  _CrossProduct(&fStack_24,&fStack_30,auStack_3c);
  _VectorNormalize(auStack_3c);
  iVar8 = 4;
  do {
    _DoRailCore((float)iVar7,___real_41000000);
    _RotatePointAroundVector(auStack_c,&local_18,auStack_3c,___real_42340000);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return;
}



// ===========================================
// Function: _LerpMeshVertexes @ 0000be6f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _LerpMeshVertexes(int param_1,float param_2)

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
  int iVar10;
  uint uVar11;
  short *psVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float *pfVar16;
  float *pfVar17;
  short *psVar18;
  float *pfVar19;
  float *pfVar20;
  short *psVar21;
  short *psVar22;
  short *local_2c;
  int local_20;
  
  local_20 = *(int *)(param_1 + 0x50);
  fVar7 = 1.0 - param_2;
  fVar9 = fVar7 * (float)___real_3f90000000000000;
  psVar21 = (short *)(*(int *)(param_1 + 100) + *(short *)(_DAT_0000e3b8 + 0x5e) * local_20 * 8 +
                     param_1);
  pfVar17 = (float *)(_DAT_00324eec * 0x10 + 0xbdb18);
  pfVar20 = (float *)(_DAT_00324eec * 0x10 + 0x132e18);
  psVar18 = psVar21 + 3;
  if (NAN(param_2) == (param_2 == 0.0)) {
    fVar8 = (float)___real_3f90000000000000 * param_2;
    psVar12 = (short *)(*(int *)(param_1 + 100) + *(short *)(_DAT_0000e3b8 + 0x5c) * local_20 * 8 +
                       param_1);
    local_2c = psVar12 + 3;
    if (0 < local_20) {
      do {
        *pfVar17 = (float)(int)*psVar21 * fVar9 + (float)(int)*psVar12 * fVar8;
        pfVar17[1] = (float)(int)psVar21[1] * fVar9 + (float)(int)psVar12[1] * fVar8;
        pfVar17[2] = (float)(int)psVar12[2] * fVar8 + (float)(int)psVar21[2] * fVar9;
        uVar11 = (int)*psVar18 >> 8 & 0xff;
        uVar14 = ((int)*psVar18 & 0xffU) * 4 + 0x100;
        fVar1 = *(float *)(uVar11 * 0x10 + 0x54e70);
        fVar2 = *(float *)(uVar14 * 4 + 0x54a70);
        fVar3 = *(float *)((uVar14 & 0x3ff) * 4 + 0x54e70);
        uVar13 = (int)*local_2c >> 8 & 0xff;
        uVar15 = ((int)*local_2c & 0xffU) * 4 + 0x100;
        fVar4 = *(float *)(uVar13 * 0x10 + 0x54e70);
        fVar5 = *(float *)(uVar15 * 4 + 0x54a70);
        fVar6 = *(float *)((uVar15 & 0x3ff) * 4 + 0x54e70);
        *pfVar20 = *(float *)((uVar13 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                   *(float *)(uVar15 * 4 + 0x54a70) * param_2 +
                   *(float *)((uVar11 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                   *(float *)(uVar14 * 4 + 0x54a70) * fVar7;
        pfVar20[1] = fVar4 * fVar5 * param_2 + fVar1 * fVar2 * fVar7;
        pfVar20[2] = fVar7 * fVar3 + fVar6 * param_2;
        _VectorNormalize(pfVar20);
        psVar12 = psVar12 + 4;
        local_2c = local_2c + 4;
        psVar21 = psVar21 + 4;
        psVar18 = psVar18 + 4;
        pfVar17 = pfVar17 + 4;
        pfVar20 = pfVar20 + 4;
        local_20 = local_20 + -1;
      } while (local_20 != 0);
      return;
    }
  }
  else {
    iVar10 = 0;
    if (3 < local_20) {
      param_1 = (local_20 - 4U >> 2) + 1;
      iVar10 = param_1 * 4;
      pfVar16 = pfVar17;
      psVar12 = psVar18;
      pfVar19 = pfVar20;
      psVar22 = psVar21;
      do {
        *pfVar16 = (float)(int)*psVar22 * fVar9;
        pfVar16[1] = (float)(int)psVar22[1] * fVar9;
        pfVar16[2] = (float)(int)psVar22[2] * fVar9;
        uVar11 = (int)*psVar12 >> 8 & 0xff;
        uVar13 = ((int)*psVar12 & 0xffU) * 4 + 0x100;
        *pfVar19 = *(float *)((uVar11 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                   *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[1] = *(float *)(uVar11 * 0x10 + 0x54e70) * *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[2] = *(float *)((uVar13 & 0x3ff) * 4 + 0x54e70);
        pfVar16[4] = (float)(int)psVar22[4] * fVar9;
        pfVar16[5] = (float)(int)psVar22[5] * fVar9;
        pfVar16[6] = (float)(int)psVar22[6] * fVar9;
        uVar11 = (int)psVar12[4] >> 8 & 0xff;
        uVar13 = ((int)psVar12[4] & 0xffU) * 4 + 0x100;
        pfVar19[4] = *(float *)((uVar11 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                     *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[5] = *(float *)(uVar11 * 0x10 + 0x54e70) * *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[6] = *(float *)((uVar13 & 0x3ff) * 4 + 0x54e70);
        pfVar16[8] = (float)(int)psVar22[8] * fVar9;
        pfVar16[9] = (float)(int)psVar22[9] * fVar9;
        pfVar17 = pfVar16 + 0x10;
        pfVar20 = pfVar19 + 0x10;
        psVar21 = psVar22 + 0x10;
        psVar18 = psVar12 + 0x10;
        pfVar16[10] = (float)(int)psVar22[10] * fVar9;
        uVar11 = (int)psVar12[8] >> 8 & 0xff;
        uVar13 = ((int)psVar12[8] & 0xffU) * 4 + 0x100;
        pfVar19[8] = *(float *)((uVar11 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                     *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[9] = *(float *)(uVar11 * 0x10 + 0x54e70) * *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[10] = *(float *)((uVar13 & 0x3ff) * 4 + 0x54e70);
        pfVar16[0xc] = (float)(int)psVar22[0xc] * fVar9;
        pfVar16[0xd] = (float)(int)psVar22[0xd] * fVar9;
        pfVar16[0xe] = (float)(int)psVar22[0xe] * fVar9;
        uVar11 = (int)psVar12[0xc] >> 8 & 0xff;
        uVar13 = ((int)psVar12[0xc] & 0xffU) * 4 + 0x100;
        pfVar19[0xc] = *(float *)((uVar11 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                       *(float *)(uVar13 * 4 + 0x54a70);
        param_1 = param_1 + -1;
        pfVar19[0xd] = *(float *)(uVar11 * 0x10 + 0x54e70) * *(float *)(uVar13 * 4 + 0x54a70);
        pfVar19[0xe] = *(float *)((uVar13 & 0x3ff) * 4 + 0x54e70);
        pfVar16 = pfVar17;
        psVar12 = psVar18;
        pfVar19 = pfVar20;
        psVar22 = psVar21;
      } while (param_1 != 0);
    }
    if (iVar10 < local_20) {
      param_1 = local_20 - iVar10;
      do {
        *pfVar17 = (float)(int)*psVar21 * fVar9;
        pfVar17[1] = (float)(int)psVar21[1] * fVar9;
        pfVar17[2] = (float)(int)psVar21[2] * fVar9;
        uVar11 = (int)*psVar18 >> 8 & 0xff;
        uVar13 = ((int)*psVar18 & 0xffU) * 4 + 0x100;
        *pfVar20 = *(float *)((uVar11 * 4 + 0x100 & 0x3ff) * 4 + 0x54e70) *
                   *(float *)(uVar13 * 4 + 0x54a70);
        param_1 = param_1 + -1;
        pfVar20[1] = *(float *)(uVar11 * 0x10 + 0x54e70) * *(float *)(uVar13 * 4 + 0x54a70);
        pfVar20[2] = *(float *)((uVar13 & 0x3ff) * 4 + 0x54e70);
        pfVar17 = pfVar17 + 4;
        psVar18 = psVar18 + 4;
        pfVar20 = pfVar20 + 4;
        psVar21 = psVar21 + 4;
      } while (param_1 != 0);
    }
  }
  return;
}



// ===========================================
// Function: _RB_SurfaceMesh @ 0000c405
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceMesh(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  
  if (*(short *)(_DAT_0000e3b8 + 0x5c) == *(short *)(_DAT_0000e3b8 + 0x5e)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(_DAT_0000e3b8 + 0xa8);
  }
  if ((29999 < *(int *)(param_1 + 0x50) + _DAT_00324eec) ||
     (179999 < _DAT_00324ee8 + *(int *)(param_1 + 0x54) * 3)) {
    _RB_CheckOverflow(*(int *)(param_1 + 0x50),*(int *)(param_1 + 0x54) * 3);
  }
  _LerpMeshVertexes(param_1,uVar2);
  iVar1 = _DAT_00324eec;
  iVar7 = *(int *)(param_1 + 0x58);
  iVar3 = *(int *)(param_1 + 0x54) * 3;
  iVar4 = 0;
  if (0 < iVar3) {
    piVar8 = (int *)(&_tess + _DAT_00324ee8 * 4);
    do {
      *piVar8 = *(int *)(iVar7 + param_1 + iVar4 * 4) + iVar1;
      iVar4 = iVar4 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar4 < iVar3);
  }
  _DAT_00324ee8 = _DAT_00324ee8 + iVar3;
  iVar3 = *(int *)(param_1 + 0x50);
  iVar4 = *(int *)(param_1 + 0x60) + param_1;
  iVar7 = 0;
  if (3 < iVar3) {
    iVar9 = (iVar3 - 4U >> 2) + 1;
    iVar7 = iVar9 * 4;
    puVar5 = (undefined4 *)(iVar1 * 0x10 + 0x1a811c);
    puVar6 = (undefined4 *)(iVar4 + 8);
    do {
      puVar5[-1] = puVar6[-2];
      iVar9 = iVar9 + -1;
      *puVar5 = puVar6[-1];
      puVar5[3] = *puVar6;
      puVar5[4] = puVar6[1];
      puVar5[7] = puVar6[2];
      puVar5[8] = puVar6[3];
      puVar5[0xb] = puVar6[4];
      puVar5[0xc] = puVar6[5];
      puVar5 = puVar5 + 0x10;
      puVar6 = puVar6 + 8;
    } while (iVar9 != 0);
  }
  if (iVar3 <= iVar7) {
    _DAT_00324eec = _DAT_00324eec + *(int *)(param_1 + 0x50);
    return;
  }
  puVar5 = (undefined4 *)((iVar7 + iVar1) * 0x10 + 0x1a811c);
  do {
    iVar1 = iVar7 * 8;
    iVar7 = iVar7 + 1;
    puVar5[-1] = *(undefined4 *)(iVar4 + iVar1);
    *puVar5 = *(undefined4 *)(iVar4 + -4 + iVar7 * 8);
    puVar5 = puVar5 + 4;
  } while (iVar7 < iVar3);
  _DAT_00324eec = _DAT_00324eec + *(int *)(param_1 + 0x50);
  return;
}



// ===========================================
// Function: _RB_SurfaceFace @ 0000c55c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceFace(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  
  if ((29999 < *(int *)(param_1 + 0x20) + _DAT_00324eec) ||
     (179999 < *(int *)(param_1 + 0x24) + _DAT_00324ee8)) {
    _RB_CheckOverflow(*(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24));
  }
  iVar9 = _DAT_00324eec;
  uVar1 = *(uint *)(param_1 + 0x18 + __backEnd * 4);
  _DAT_00324ee0 = _DAT_00324ee0 | uVar1;
  if ((*(uint *)(_DAT_00324ed8 + 0x58) & 0x800004) != 0) {
    _DAT_00324ee0 = 0;
  }
  iVar6 = *(int *)(param_1 + 0x28);
  iVar2 = *(int *)(param_1 + 0x24) + -1;
  iVar8 = _DAT_00324ee8 * 4;
  if (-1 < iVar2) {
    piVar4 = (int *)(&_tess + iVar8 + iVar2 * 4);
    do {
      *piVar4 = *(int *)(((iVar6 + param_1) - (int)(&_tess + iVar8)) + (int)piVar4) + iVar9;
      iVar2 = iVar2 + -1;
      piVar4 = piVar4 + -1;
    } while (-1 < iVar2);
  }
  _DAT_00324ee8 = _DAT_00324ee8 + *(int *)(param_1 + 0x24);
  iVar9 = *(int *)(param_1 + 0x20);
  if (((*(int *)(_DAT_00324ed8 + 0xbc) != 0) || (*(int *)(_DAT_00324ed8 + 0x1fc) != 0)) ||
     (_DAT_0000eb60 != 0)) {
    iVar8 = 0;
    iVar6 = _DAT_00324eec;
    if (3 < iVar9) {
      iVar2 = (iVar9 - 4U >> 2) + 1;
      iVar8 = iVar2 * 4;
      iVar6 = _DAT_00324eec + iVar8;
      puVar3 = (undefined4 *)(_DAT_00324eec * 0x10 + 0x132e1c);
      do {
        iVar2 = iVar2 + -1;
        puVar3[-1] = *(undefined4 *)(param_1 + 4);
        *puVar3 = *(undefined4 *)(param_1 + 8);
        puVar3[1] = *(undefined4 *)(param_1 + 0xc);
        puVar3[3] = *(undefined4 *)(param_1 + 4);
        puVar3[4] = *(undefined4 *)(param_1 + 8);
        puVar3[5] = *(undefined4 *)(param_1 + 0xc);
        puVar3[7] = *(undefined4 *)(param_1 + 4);
        puVar3[8] = *(undefined4 *)(param_1 + 8);
        puVar3[9] = *(undefined4 *)(param_1 + 0xc);
        puVar3[0xb] = *(undefined4 *)(param_1 + 4);
        puVar3[0xc] = *(undefined4 *)(param_1 + 8);
        puVar3[0xd] = *(undefined4 *)(param_1 + 0xc);
        puVar3 = puVar3 + 0x10;
      } while (iVar2 != 0);
    }
    if (iVar8 < iVar9) {
      iVar8 = iVar9 - iVar8;
      puVar3 = (undefined4 *)(iVar6 * 0x10 + 0x132e1c);
      do {
        iVar8 = iVar8 + -1;
        puVar3[-1] = *(undefined4 *)(param_1 + 4);
        *puVar3 = *(undefined4 *)(param_1 + 8);
        puVar3[1] = *(undefined4 *)(param_1 + 0xc);
        puVar3 = puVar3 + 4;
      } while (iVar8 != 0);
    }
  }
  if (iVar9 < 1) {
    _DAT_00324eec = _DAT_00324eec + *(int *)(param_1 + 0x20);
    return;
  }
  puVar3 = (undefined4 *)(param_1 + 0x2c);
  puVar5 = (undefined4 *)(_DAT_00324eec * 0x10 + 0xbdb1c);
  puVar7 = (uint *)(_DAT_00324eec * 4 + 0x23a8d8);
  do {
    puVar5[-1] = *puVar3;
    iVar9 = iVar9 + -1;
    *puVar5 = puVar3[1];
    puVar5[1] = puVar3[2];
    puVar5[239999] = puVar3[3];
    puVar5[240000] = puVar3[4];
    puVar5[0x3a981] = puVar3[5];
    puVar5[0x3a982] = puVar3[6];
    puVar7[-30000] = puVar3[7];
    *puVar7 = uVar1;
    puVar3 = puVar3 + 8;
    puVar5 = puVar5 + 4;
    puVar7 = puVar7 + 1;
  } while (iVar9 != 0);
  _DAT_00324eec = _DAT_00324eec + *(int *)(param_1 + 0x20);
  return;
}



// ===========================================
// Function: _LodErrorForVolume @ 0000c772
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _LodErrorForVolume(float param_1)

{
  float *in_EAX;
  float local_10;
  
  local_10 = _DAT_0000e09c *
             ((_DAT_0000e334 * in_EAX[2] + _DAT_0000e328 * in_EAX[1] + *in_EAX * _DAT_0000e31c +
              _DAT_0000e310) - _DAT_0000e090) +
             _DAT_0000e094 *
             ((_DAT_0000e32c * in_EAX[2] + _DAT_0000e320 * in_EAX[1] + *in_EAX * _DAT_0000e314 +
              _DAT_0000e308) - _DAT_0000e088) +
             _DAT_0000e098 *
             ((_DAT_0000e330 * in_EAX[2] + _DAT_0000e324 * in_EAX[1] + *in_EAX * _DAT_0000e318 +
              _DAT_0000e30c) - _DAT_0000e08c);
  if (local_10 < 0.0 != NAN(local_10)) {
    local_10 = -local_10;
  }
  local_10 = local_10 - param_1;
  if (local_10 < 1.0) {
    local_10 = 1.0;
  }
  return (float10)(*(float *)(__r_lodCurveError + 0x1c) / local_10);
}



// ===========================================
// Function: _RB_SurfaceGrid @ 0000c885
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceGrid(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  float *pfVar15;
  int iVar16;
  uint *puVar17;
  float10 fVar18;
  int local_238;
  int local_234;
  int local_22c;
  undefined4 *local_224;
  int *local_220;
  int local_20c [66];
  int local_104 [65];
  
  uVar2 = *(uint *)(param_1 + 4 + __backEnd * 4);
  _DAT_00324ee0 = _DAT_00324ee0 | uVar2;
  if ((*(uint *)(_DAT_00324ed8 + 0x58) & 0x800004) != 0) {
    _DAT_00324ee0 = 0;
  }
  fVar18 = (float10)_LodErrorForVolume(*(undefined4 *)(param_1 + 0x40));
  fVar1 = (float)fVar18;
  iVar3 = *(int *)(param_1 + 0x48);
  iVar14 = 1;
  iVar10 = iVar3 + -1;
  local_104[0] = 0;
  iVar7 = 1;
  if (1 < iVar10) {
    if (3 < iVar3 + -2) {
      pfVar15 = (float *)(*(int *)(param_1 + 0x50) + 0xc);
      do {
        if (pfVar15[-2] < fVar1 != (pfVar15[-2] == fVar1)) {
          local_104[iVar14] = iVar7;
          iVar14 = iVar14 + 1;
        }
        if (pfVar15[-1] < fVar1 != (pfVar15[-1] == fVar1)) {
          local_104[iVar14] = iVar7 + 1;
          iVar14 = iVar14 + 1;
        }
        if (*pfVar15 < fVar1 != (*pfVar15 == fVar1)) {
          local_104[iVar14] = iVar7 + 2;
          iVar14 = iVar14 + 1;
        }
        if (pfVar15[1] < fVar1 != (pfVar15[1] == fVar1)) {
          local_104[iVar14] = iVar7 + 3;
          iVar14 = iVar14 + 1;
        }
        iVar7 = iVar7 + 4;
        pfVar15 = pfVar15 + 4;
      } while (iVar7 < iVar3 + -4);
    }
    if (iVar7 < iVar10) {
      pfVar15 = (float *)(*(int *)(param_1 + 0x50) + iVar7 * 4);
      do {
        if (*pfVar15 < fVar1 != (*pfVar15 == fVar1)) {
          local_104[iVar14] = iVar7;
          iVar14 = iVar14 + 1;
        }
        iVar7 = iVar7 + 1;
        pfVar15 = pfVar15 + 1;
      } while (iVar7 < iVar10);
    }
  }
  iVar7 = *(int *)(param_1 + 0x4c);
  iVar16 = 1;
  local_104[iVar14] = iVar10;
  iVar14 = iVar14 + 1;
  iVar3 = iVar7 + -1;
  local_20c[1] = 0;
  iVar10 = 1;
  if (1 < iVar3) {
    if (3 < iVar7 + -2) {
      pfVar15 = (float *)(*(int *)(param_1 + 0x54) + 0xc);
      do {
        if (pfVar15[-2] < fVar1 != (pfVar15[-2] == fVar1)) {
          local_20c[iVar16 + 1] = iVar10;
          iVar16 = iVar16 + 1;
        }
        if (pfVar15[-1] < fVar1 != (pfVar15[-1] == fVar1)) {
          local_20c[iVar16 + 1] = iVar10 + 1;
          iVar16 = iVar16 + 1;
        }
        if (*pfVar15 < fVar1 != (*pfVar15 == fVar1)) {
          local_20c[iVar16 + 1] = iVar10 + 2;
          iVar16 = iVar16 + 1;
        }
        if (pfVar15[1] < fVar1 != (pfVar15[1] == fVar1)) {
          local_20c[iVar16 + 1] = iVar10 + 3;
          iVar16 = iVar16 + 1;
        }
        iVar10 = iVar10 + 4;
        pfVar15 = pfVar15 + 4;
      } while (iVar10 < iVar7 + -4);
    }
    if (iVar10 < iVar3) {
      pfVar15 = (float *)(*(int *)(param_1 + 0x54) + iVar10 * 4);
      do {
        if (*pfVar15 < fVar1 != (*pfVar15 == fVar1)) {
          local_20c[iVar16 + 1] = iVar10;
          iVar16 = iVar16 + 1;
        }
        iVar10 = iVar10 + 1;
        pfVar15 = pfVar15 + 1;
      } while (iVar10 < iVar3);
    }
  }
  iVar7 = iVar16 + 1;
  local_20c[0] = iVar14;
  local_20c[iVar7] = iVar3;
  local_22c = 0;
  if (0 < iVar16) {
    iVar3 = iVar14 * 6;
    do {
      while( true ) {
        iVar10 = _DAT_00324eec;
        iVar5 = ((int)&DAT_00007530 - _DAT_00324eec) / iVar14;
        local_238 = (180000 - _DAT_00324ee8) / iVar3;
        if ((1 < iVar5) && (0 < local_238)) break;
        _RB_EndSurface();
        _RB_BeginSurface(_DAT_00324ed8,_DAT_00324edc);
      }
      if (iVar5 < local_238 + 1) {
        local_238 = iVar5 + -1;
      }
      if (iVar7 < local_238 + local_22c) {
        local_238 = iVar7 - local_22c;
      }
      iVar5 = _DAT_00324eec * 0x10;
      local_224 = (undefined4 *)(iVar5 + 0x132e18);
      puVar11 = (undefined4 *)(iVar5 + 0xbdb18);
      puVar8 = (undefined4 *)(iVar5 + 0x1a8118);
      puVar13 = (undefined4 *)(_DAT_00324eec * 4 + 0x21d418);
      puVar17 = (uint *)(_DAT_00324eec * 4 + 0x23a8d8);
      if (((*(int *)(_DAT_00324ed8 + 0xbc) != 0) || (*(int *)(_DAT_00324ed8 + 0x1fc) != 0)) ||
         (bVar4 = false, _DAT_0000eb60 != 0)) {
        bVar4 = true;
      }
      if (0 < local_238) {
        local_220 = local_20c + local_22c + 1;
        local_234 = local_238;
        do {
          iVar5 = 0;
          if (0 < iVar14) {
            iVar12 = *local_220;
            do {
              puVar6 = (undefined4 *)
                       ((*(int *)(param_1 + 0x48) * iVar12 + 2 + local_104[iVar5]) * 0x2c + param_1)
              ;
              *puVar11 = *puVar6;
              puVar11[1] = puVar6[1];
              puVar11[2] = puVar6[2];
              *puVar8 = puVar6[3];
              puVar8[1] = puVar6[4];
              puVar8[2] = puVar6[5];
              puVar8[3] = puVar6[6];
              if (bVar4) {
                *local_224 = puVar6[7];
                local_224[1] = puVar6[8];
                local_224[2] = puVar6[9];
              }
              *puVar13 = puVar6[10];
              local_224 = local_224 + 4;
              *puVar17 = uVar2;
              iVar5 = iVar5 + 1;
              puVar17 = puVar17 + 1;
              puVar11 = puVar11 + 4;
              puVar8 = puVar8 + 4;
              puVar13 = puVar13 + 1;
              iVar14 = local_20c[0];
            } while (iVar5 < local_20c[0]);
          }
          local_220 = local_220 + 1;
          local_234 = local_234 + -1;
        } while (local_234 != 0);
      }
      local_234 = local_238 + -1;
      if (0 < local_234) {
        do {
          iVar10 = iVar10 + iVar14;
          iVar5 = iVar14 + -1;
          if (0 < iVar5) {
            iVar9 = (1 - iVar14) + iVar10;
            iVar12 = iVar10;
            do {
              *(int *)(&_tess + _DAT_00324ee8 * 4) = iVar9 + -1;
              *(int *)(&DAT_0000de9c + _DAT_00324ee8 * 4) = iVar12;
              *(int *)(&_backEnd + _DAT_00324ee8 * 4) = iVar9;
              *(int *)(&DAT_0000dea4 + _DAT_00324ee8 * 4) = iVar9;
              *(int *)(&_vec3_origin + _DAT_00324ee8 * 4) = iVar12;
              *(int *)(&DAT_0000deac + _DAT_00324ee8 * 4) = iVar12 + 1;
              _DAT_00324ee8 = _DAT_00324ee8 + 6;
              iVar9 = iVar9 + 1;
              iVar12 = iVar12 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          local_234 = local_234 + -1;
        } while (local_234 != 0);
      }
      _DAT_00324eec = _DAT_00324eec + local_238 * iVar14;
      local_22c = local_22c + -1 + local_238;
    } while (local_22c < iVar16);
  }
  return;
}



// ===========================================
// Function: _RB_SurfaceAxis @ 0000ccd7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceAxis(void)

{
  _GL_Bind(_DAT_0000df14);
  (*__qglLineWidth)(___real_40400000);
  (*__qglBegin)(1);
  (*__qglColor3f)(0x3f800000,0,0);
  (*__qglVertex3f)(0,0,0);
  (*__qglVertex3f)(___real_41800000,0,0);
  (*__qglColor3f)(0,0x3f800000,0);
  (*__qglVertex3f)(0,0,0);
  (*__qglVertex3f)(0,___real_41800000,0);
  (*__qglColor3f)(0,0,0x3f800000);
  (*__qglVertex3f)(0,0,0);
  (*__qglVertex3f)(0,0,___real_41800000);
  (*__qglEnd)();
  (*__qglLineWidth)(0x3f800000);
  return;
}



// ===========================================
// Function: _RB_SurfaceEntity @ 0000cdea
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceEntity(void)

{
  switch(*_DAT_0000e3b8) {
  case 2:
    _RB_SurfaceSprite();
    return;
  case 3:
    _RB_SurfaceBeam();
    return;
  case 4:
    _RB_SurfaceRailCore();
    return;
  case 5:
    _RB_SurfaceRailRings();
    return;
  case 6:
    _RB_SurfaceLightningBolt();
    return;
  default:
    _RB_SurfaceAxis();
    return;
  }
}



// ===========================================
// Function: _RB_SurfaceBad @ 0000ce32
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceBad(void)

{
  (*__ri)(0,s_Bad_surface_tesselated__);
  return;
}



// ===========================================
// Function: _RB_SurfaceFlare @ 0000ce43
// ===========================================

void _RB_SurfaceFlare(void)

{
  return;
}



// ===========================================
// Function: _RB_SurfaceDisplayList @ 0000ce44
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceDisplayList(int param_1)

{
  (*__qglCallList)(*(undefined4 *)(param_1 + 4));
  return;
}



// ===========================================
// Function: _RB_SurfaceSkip @ 0000ce53
// ===========================================

void _RB_SurfaceSkip(void)

{
  return;
}



