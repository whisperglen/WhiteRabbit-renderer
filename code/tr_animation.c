// ===========================================
// Function: _R_AddAnimSurfaces @ 00007200
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddAnimSurfaces(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(_DAT_00008d38 + 0x5c);
  piVar4 = (int *)(*(int *)(iVar3 + 0x58) + iVar3);
  iVar2 = 0;
  iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 4 + iVar3) + (int)piVar4;
  if (0 < *piVar4) {
    do {
      uVar1 = _R_GetShaderByHandle(*(undefined4 *)(iVar3 + 0x84));
      _R_AddDrawSurf(iVar3,uVar1,0,0);
      iVar3 = iVar3 + *(int *)(iVar3 + 0xa4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *piVar4);
  }
  return;
}



// ===========================================
// Function: _RB_SurfaceAnim @ 00007249
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_SurfaceAnim(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int *piStack_1834;
  int local_1830;
  float *pfStack_182c;
  float fStack_1820;
  float fStack_181c;
  float fStack_1818;
  float local_1814;
  float fStack_1810;
  float fStack_180c;
  float fStack_1808;
  float afStack_1804 [3];
  float afStack_17f8 [1533];
  undefined4 uStack_4;
  
  uStack_4 = 0x7253;
  if (*(short *)(_DAT_00008b30 + 0x5c) == *(short *)(_DAT_00008b30 + 0x5e)) {
    local_1814 = 0.0;
    fVar1 = 1.0;
  }
  else {
    local_1814 = *(float *)(_DAT_00008b30 + 0xa8);
    fVar1 = 1.0 - local_1814;
  }
  iVar3 = *(int *)(param_1 + 0x88);
  iVar8 = *(int *)(iVar3 + 0x50 + param_1);
  iVar9 = iVar3 + param_1;
  iVar3 = *(int *)(iVar3 + 0x4c + param_1) * 0x30 + 0x38;
  iVar7 = *(short *)(_DAT_00008b30 + 0x5e) * iVar3 + iVar8 + iVar9;
  iVar11 = *(short *)(_DAT_00008b30 + 0x5c) * iVar3 + iVar8 + iVar9;
  _RB_CheckOverflow(*(undefined4 *)(param_1 + 0x8c),*(int *)(param_1 + 0x94) * 3);
  iVar2 = _DAT_0031f65c;
  iVar12 = _DAT_0031f658;
  iVar3 = *(int *)(param_1 + 0x98);
  iVar8 = *(int *)(param_1 + 0x94) * 3;
  pfStack_182c = (float *)0x0;
  if (0 < iVar8) {
    piStack_1834 = (int *)(&_tess + _DAT_0031f658 * 4);
    do {
      *piStack_1834 = *(int *)(iVar3 + param_1 + (int)pfStack_182c * 4) + iVar12;
      piStack_1834 = piStack_1834 + 1;
      pfStack_182c = (float *)((int)pfStack_182c + 1);
    } while ((int)pfStack_182c < iVar8);
  }
  _DAT_0031f658 = _DAT_0031f658 + iVar8;
  if (NAN(local_1814) == (local_1814 == 0.0)) {
    iVar3 = *(int *)(iVar9 + 0x4c) * 0xc;
    pfStack_182c = afStack_1804 + 1;
    iVar8 = 0;
    if (3 < iVar3) {
      local_1830 = (iVar3 - 4U >> 2) + 1;
      iVar8 = local_1830 * 4;
      pfVar4 = (float *)(iVar11 + 0x38);
      pfVar6 = afStack_1804 + 3;
      pfVar10 = (float *)(iVar7 + 0x40);
      do {
        local_1830 = local_1830 + -1;
        pfVar6[-2] = *pfVar4 * local_1814 + *(float *)((iVar7 - iVar11) + (int)pfVar4) * fVar1;
        pfVar6[-1] = pfVar10[-1] * fVar1 + pfVar4[1] * local_1814;
        *pfVar6 = *pfVar10 * fVar1 + pfVar4[2] * local_1814;
        pfVar6[1] = pfVar10[1] * fVar1 + pfVar4[3] * local_1814;
        pfVar4 = pfVar4 + 4;
        pfVar6 = pfVar6 + 4;
        pfVar10 = pfVar10 + 4;
      } while (local_1830 != 0);
    }
    if (iVar8 < iVar3) {
      pfVar4 = (float *)(iVar11 + 0x38 + iVar8 * 4);
      do {
        iVar8 = iVar8 + 1;
        afStack_1804[iVar8] =
             local_1814 * *pfVar4 + *(float *)((int)pfVar4 + (iVar7 - iVar11)) * fVar1;
        pfVar4 = pfVar4 + 1;
      } while (iVar8 < iVar3);
    }
  }
  else {
    pfStack_182c = (float *)(iVar7 + 0x38);
  }
  iVar8 = *(int *)(param_1 + 0x8c);
  iVar3 = *(int *)(param_1 + 0x90) + param_1;
  if (iVar8 < 1) {
    _DAT_0031f65c = _DAT_0031f65c + iVar8;
    return;
  }
  pfVar4 = (float *)(iVar2 * 0x10 + 0xb828c);
  do {
    iVar12 = *(int *)(iVar3 + 0x20);
    fStack_1818 = 0.0;
    fStack_181c = 0.0;
    fStack_1820 = 0.0;
    fStack_1808 = 0.0;
    fStack_180c = 0.0;
    fStack_1810 = 0.0;
    piVar5 = (int *)(iVar3 + 0x24);
    if (0 < iVar12) {
      do {
        pfVar6 = pfStack_182c + *piVar5 * 0xc;
        iVar12 = iVar12 + -1;
        fStack_1820 = (pfVar6[2] * (float)piVar5[4] +
                       *pfVar6 * (float)piVar5[2] + pfVar6[1] * (float)piVar5[3] + pfVar6[3]) *
                      (float)piVar5[1] + fStack_1820;
        fStack_181c = (pfVar6[6] * (float)piVar5[4] +
                       (float)piVar5[2] * pfVar6[4] + pfVar6[5] * (float)piVar5[3] + pfVar6[7]) *
                      (float)piVar5[1] + fStack_181c;
        fStack_1818 = (pfVar6[10] * (float)piVar5[4] +
                       (float)piVar5[2] * pfVar6[8] + pfVar6[9] * (float)piVar5[3] + pfVar6[0xb]) *
                      (float)piVar5[1] + fStack_1818;
        fStack_1810 = (pfVar6[2] * *(float *)(iVar3 + 0x14) +
                      *pfVar6 * *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x10) * pfVar6[1]) *
                      (float)piVar5[1] + fStack_1810;
        fStack_180c = (pfVar6[6] * *(float *)(iVar3 + 0x14) +
                      pfVar6[4] * *(float *)(iVar3 + 0xc) + pfVar6[5] * *(float *)(iVar3 + 0x10)) *
                      (float)piVar5[1] + fStack_180c;
        fStack_1808 = (pfVar6[10] * *(float *)(iVar3 + 0x14) +
                      pfVar6[8] * *(float *)(iVar3 + 0xc) + pfVar6[9] * *(float *)(iVar3 + 0x10)) *
                      (float)piVar5[1] + fStack_1808;
        piVar5 = piVar5 + 5;
      } while (iVar12 != 0);
    }
    iVar8 = iVar8 + -1;
    pfVar4[-1] = fStack_1820;
    *pfVar4 = fStack_181c;
    pfVar4[1] = fStack_1818;
    pfVar4[119999] = fStack_1810;
    pfVar4[120000] = fStack_180c;
    pfVar4[0x1d4c1] = fStack_1808;
    pfVar4[239999] = *(float *)(iVar3 + 0x18);
    pfVar4[240000] = *(float *)(iVar3 + 0x1c);
    iVar3 = iVar3 + 0x24 + *(int *)(iVar3 + 0x20) * 0x14;
    pfVar4 = pfVar4 + 4;
  } while (iVar8 != 0);
  _DAT_0031f65c = _DAT_0031f65c + *(int *)(param_1 + 0x8c);
  return;
}



