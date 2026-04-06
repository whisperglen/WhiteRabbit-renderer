// ===========================================
// Function: _R_CullGrid @ 00008617
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_CullGrid(void)

{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(__r_nocurves + 0x20) != 0) {
    return 1;
  }
  if (_DAT_0000a98c == 0x3fe) {
    iVar1 = _R_CullPointAndRadius(in_EAX + 0x24,*(undefined4 *)(in_EAX + 0x30));
  }
  else {
    iVar1 = _R_CullLocalPointAndRadius(in_EAX + 0x24);
  }
  if (iVar1 == 2) {
    _DAT_0000af68 = _DAT_0000af68 + 1;
    return 1;
  }
  if (iVar1 != 1) {
    _DAT_0000af60 = _DAT_0000af60 + 1;
    return 0;
  }
  _DAT_0000af64 = _DAT_0000af64 + 1;
  iVar1 = _R_CullLocalBox(in_EAX + 0xc);
  if (iVar1 == 2) {
    _DAT_0000af74 = _DAT_0000af74 + 1;
    return 1;
  }
  if (iVar1 == 0) {
    _DAT_0000af6c = _DAT_0000af6c + 1;
    return 0;
  }
  _DAT_0000af70 = _DAT_0000af70 + 1;
  return 0;
}



// ===========================================
// Function: _R_CullSurface @ 000086b5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall _R_CullSurface(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int *in_EAX;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(__r_nocull + 0x20) == 0) {
    iVar4 = *in_EAX;
    if (iVar4 == 3) {
      uVar3 = _R_CullGrid();
      return uVar3;
    }
    if (iVar4 == 4) {
      iVar4 = _R_CullLocalBox(in_EAX + 3,param_1);
      return (uint)(iVar4 == 2);
    }
    if (((iVar4 == 2) && (*(int *)(param_2 + 0xb4) != 2)) &&
       (*(int *)(__r_facePlaneCull + 0x20) != 0)) {
      fVar1 = (float)in_EAX[3] * _DAT_0000ac64 +
              (float)in_EAX[1] * _DAT_0000ac5c + (float)in_EAX[2] * _DAT_0000ac60;
      if (*(int *)(param_2 + 0xb4) == 0) {
        if ((float)in_EAX[4] - (float)___real_4020000000000000 <= fVar1) {
          return 0;
        }
      }
      else {
        fVar2 = (float)in_EAX[4] + (float)___real_4020000000000000;
        if (fVar2 < fVar1 == (NAN(fVar2) || NAN(fVar1))) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}



// ===========================================
// Function: _R_DlightFace @ 00008767
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _R_DlightFace(void)

{
  float fVar1;
  uint in_EAX;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  int unaff_ESI;
  
  iVar2 = 0;
  uVar4 = 1;
  if (3 < _DAT_0000aee8) {
    pfVar3 = (float *)(_DAT_0000aeec + 0x4c);
    iVar5 = (_DAT_0000aee8 - 4U >> 2) + 1;
    iVar2 = iVar5 * 4;
    do {
      if (((in_EAX & uVar4) != 0) &&
         ((fVar1 = (pfVar3[-9] * *(float *)(unaff_ESI + 0xc) +
                   pfVar3[-0xb] * *(float *)(unaff_ESI + 4) +
                   pfVar3[-10] * *(float *)(unaff_ESI + 8)) - *(float *)(unaff_ESI + 0x10),
          fVar1 < -pfVar3[-0xd] || (pfVar3[-0xd] < fVar1 != (NAN(pfVar3[-0xd]) || NAN(fVar1)))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      if (((in_EAX & uVar4) != 0) &&
         ((fVar1 = (pfVar3[2] * *(float *)(unaff_ESI + 0xc) +
                   *(float *)(unaff_ESI + 4) * *pfVar3 + pfVar3[1] * *(float *)(unaff_ESI + 8)) -
                   *(float *)(unaff_ESI + 0x10), fVar1 < -pfVar3[-2] ||
          (pfVar3[-2] < fVar1 != (NAN(pfVar3[-2]) || NAN(fVar1)))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      if (((in_EAX & uVar4) != 0) &&
         ((fVar1 = (pfVar3[0xd] * *(float *)(unaff_ESI + 0xc) +
                   pfVar3[0xb] * *(float *)(unaff_ESI + 4) + pfVar3[0xc] * *(float *)(unaff_ESI + 8)
                   ) - *(float *)(unaff_ESI + 0x10), fVar1 < -pfVar3[9] ||
          (pfVar3[9] < fVar1 != (NAN(pfVar3[9]) || NAN(fVar1)))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      if (((in_EAX & uVar4) != 0) &&
         ((fVar1 = (pfVar3[0x18] * *(float *)(unaff_ESI + 0xc) +
                   pfVar3[0x16] * *(float *)(unaff_ESI + 4) +
                   pfVar3[0x17] * *(float *)(unaff_ESI + 8)) - *(float *)(unaff_ESI + 0x10),
          fVar1 < -pfVar3[0x14] || (pfVar3[0x14] < fVar1 != (NAN(pfVar3[0x14]) || NAN(fVar1)))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      pfVar3 = pfVar3 + 0x2c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (iVar2 < _DAT_0000aee8) {
    iVar5 = _DAT_0000aee8 - iVar2;
    pfVar3 = (float *)(iVar2 * 0x2c + 0x20 + _DAT_0000aeec);
    do {
      if (((in_EAX & uVar4) != 0) &&
         ((fVar1 = (pfVar3[2] * *(float *)(unaff_ESI + 0xc) +
                   *(float *)(unaff_ESI + 4) * *pfVar3 + pfVar3[1] * *(float *)(unaff_ESI + 8)) -
                   *(float *)(unaff_ESI + 0x10), fVar1 < -pfVar3[-2] ||
          (pfVar3[-2] < fVar1 != (NAN(pfVar3[-2]) || NAN(fVar1)))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      pfVar3 = pfVar3 + 0xb;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (in_EAX != 0) {
    *(uint *)(unaff_ESI + 0x18 + _DAT_0000a274 * 4) = in_EAX;
    return in_EAX;
  }
  _DAT_0000af98 = _DAT_0000af98 + 1;
  *(undefined4 *)(unaff_ESI + 0x18 + _DAT_0000a274 * 4) = 0;
  return in_EAX;
}



// ===========================================
// Function: _R_DlightGrid @ 00008977
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall _R_DlightGrid(undefined4 param_1,int param_2)

{
  uint in_EAX;
  int iVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = 0;
  uVar4 = 1;
  if (3 < _DAT_0000aee8) {
    pfVar2 = (float *)(_DAT_0000aeec + 0x44);
    iVar3 = (_DAT_0000aee8 - 4U >> 2) + 1;
    iVar1 = iVar3 * 4;
    do {
      if (((in_EAX & uVar4) != 0) &&
         ((((*(float *)(param_2 + 0x18) < pfVar2[-9] - pfVar2[-0xb] !=
             (NAN(*(float *)(param_2 + 0x18)) || NAN(pfVar2[-9] - pfVar2[-0xb])) ||
            (pfVar2[-9] + pfVar2[-0xb] < *(float *)(param_2 + 0xc))) ||
           (*(float *)(param_2 + 0x1c) < pfVar2[-8] - pfVar2[-0xb] !=
            (NAN(*(float *)(param_2 + 0x1c)) || NAN(pfVar2[-8] - pfVar2[-0xb])))) ||
          (((pfVar2[-8] + pfVar2[-0xb] < *(float *)(param_2 + 0x10) ||
            (*(float *)(param_2 + 0x20) < pfVar2[-7] - pfVar2[-0xb] !=
             (NAN(*(float *)(param_2 + 0x20)) || NAN(pfVar2[-7] - pfVar2[-0xb])))) ||
           (pfVar2[-7] + pfVar2[-0xb] < *(float *)(param_2 + 0x14))))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      if (((in_EAX & uVar4) != 0) &&
         (((*(float *)(param_2 + 0x18) < pfVar2[2] - *pfVar2 !=
            (NAN(*(float *)(param_2 + 0x18)) || NAN(pfVar2[2] - *pfVar2)) ||
           (pfVar2[2] + *pfVar2 < *(float *)(param_2 + 0xc))) ||
          ((*(float *)(param_2 + 0x1c) < pfVar2[3] - *pfVar2 !=
            (NAN(*(float *)(param_2 + 0x1c)) || NAN(pfVar2[3] - *pfVar2)) ||
           (((pfVar2[3] + *pfVar2 < *(float *)(param_2 + 0x10) ||
             (*(float *)(param_2 + 0x20) < pfVar2[4] - *pfVar2 !=
              (NAN(*(float *)(param_2 + 0x20)) || NAN(pfVar2[4] - *pfVar2)))) ||
            (pfVar2[4] + *pfVar2 < *(float *)(param_2 + 0x14))))))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      if (((in_EAX & uVar4) != 0) &&
         ((((*(float *)(param_2 + 0x18) < pfVar2[0xd] - pfVar2[0xb] !=
             (NAN(*(float *)(param_2 + 0x18)) || NAN(pfVar2[0xd] - pfVar2[0xb])) ||
            (pfVar2[0xd] + pfVar2[0xb] < *(float *)(param_2 + 0xc))) ||
           ((*(float *)(param_2 + 0x1c) < pfVar2[0xe] - pfVar2[0xb] !=
             (NAN(*(float *)(param_2 + 0x1c)) || NAN(pfVar2[0xe] - pfVar2[0xb])) ||
            ((pfVar2[0xe] + pfVar2[0xb] < *(float *)(param_2 + 0x10) ||
             (*(float *)(param_2 + 0x20) < pfVar2[0xf] - pfVar2[0xb] !=
              (NAN(*(float *)(param_2 + 0x20)) || NAN(pfVar2[0xf] - pfVar2[0xb])))))))) ||
          (pfVar2[0xf] + pfVar2[0xb] < *(float *)(param_2 + 0x14))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      if (((in_EAX & uVar4) != 0) &&
         (((((*(float *)(param_2 + 0x18) < pfVar2[0x18] - pfVar2[0x16] !=
              (NAN(*(float *)(param_2 + 0x18)) || NAN(pfVar2[0x18] - pfVar2[0x16])) ||
             (pfVar2[0x18] + pfVar2[0x16] < *(float *)(param_2 + 0xc))) ||
            (*(float *)(param_2 + 0x1c) < pfVar2[0x19] - pfVar2[0x16] !=
             (NAN(*(float *)(param_2 + 0x1c)) || NAN(pfVar2[0x19] - pfVar2[0x16])))) ||
           ((pfVar2[0x19] + pfVar2[0x16] < *(float *)(param_2 + 0x10) ||
            (*(float *)(param_2 + 0x20) < pfVar2[0x1a] - pfVar2[0x16] !=
             (NAN(*(float *)(param_2 + 0x20)) || NAN(pfVar2[0x1a] - pfVar2[0x16])))))) ||
          (pfVar2[0x1a] + pfVar2[0x16] < *(float *)(param_2 + 0x14))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      pfVar2 = pfVar2 + 0x2c;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar1 < _DAT_0000aee8) {
    pfVar2 = (float *)(iVar1 * 0x2c + 0x18 + _DAT_0000aeec);
    iVar1 = _DAT_0000aee8 - iVar1;
    do {
      if (((in_EAX & uVar4) != 0) &&
         (((*(float *)(param_2 + 0x18) < pfVar2[2] - *pfVar2 !=
            (NAN(*(float *)(param_2 + 0x18)) || NAN(pfVar2[2] - *pfVar2)) ||
           (pfVar2[2] + *pfVar2 < *(float *)(param_2 + 0xc))) ||
          ((*(float *)(param_2 + 0x1c) < pfVar2[3] - *pfVar2 !=
            (NAN(*(float *)(param_2 + 0x1c)) || NAN(pfVar2[3] - *pfVar2)) ||
           (((pfVar2[3] + *pfVar2 < *(float *)(param_2 + 0x10) ||
             (*(float *)(param_2 + 0x20) < pfVar2[4] - *pfVar2 !=
              (NAN(*(float *)(param_2 + 0x20)) || NAN(pfVar2[4] - *pfVar2)))) ||
            (*pfVar2 + pfVar2[4] < *(float *)(param_2 + 0x14))))))))) {
        in_EAX = in_EAX & ~uVar4;
      }
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      pfVar2 = pfVar2 + 0xb;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (in_EAX != 0) {
    *(uint *)(param_2 + 4 + _DAT_0000a274 * 4) = in_EAX;
    return in_EAX;
  }
  _DAT_0000af98 = _DAT_0000af98 + 1;
  *(undefined4 *)(param_2 + 4 + _DAT_0000a274 * 4) = 0;
  return 0;
}



// ===========================================
// Function: _R_DlightSurface @ 00008c69
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall _R_DlightSurface(int param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = **(int **)(param_1 + 0xc);
  if (iVar1 == 2) {
    in_EAX = _R_DlightFace();
  }
  else if (iVar1 == 3) {
    in_EAX = _R_DlightGrid();
  }
  else {
    if (iVar1 != 4) {
      return 0;
    }
    (*(int **)(param_1 + 0xc))[_DAT_0000a274 + 1] = in_EAX;
  }
  if (in_EAX != 0) {
    _DAT_0000af94 = _DAT_0000af94 + 1;
  }
  return in_EAX;
}



// ===========================================
// Function: _R_AddWorldSurface @ 00008ca7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddWorldSurface(void)

{
  uint in_EAX;
  int iVar1;
  int *unaff_ESI;
  
  if (*unaff_ESI != ___fltused) {
    *unaff_ESI = ___fltused;
    iVar1 = _R_CullSurface(unaff_ESI[1]);
    if (iVar1 == 0) {
      if (in_EAX != 0) {
        iVar1 = _R_DlightSurface();
        in_EAX = (uint)(iVar1 != 0);
      }
      iVar1 = unaff_ESI[1];
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0xa4) != 0)) {
        _R_Sky_AddSurf();
        return;
      }
      _R_AddDrawSurf(unaff_ESI[3],iVar1,unaff_ESI[2],in_EAX);
    }
  }
  return;
}



// ===========================================
// Function: _R_AddBrushModelSurfaces @ 00008d0c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddBrushModelSurfaces(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((*(byte *)(param_1 + 4) & 1) == 0) || (_DAT_0000aaa0 != 0)) {
    iVar1 = _R_GetModelByHandle(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(iVar1 + 0x4c);
    iVar2 = _R_CullLocalBox(iVar1);
    if (iVar2 != 2) {
      _R_DlightBmodel(iVar1);
      iVar2 = 0;
      if (0 < *(int *)(iVar1 + 0x1c)) {
        do {
          _R_AddWorldSurface();
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar1 + 0x1c));
      }
    }
  }
  return;
}



// ===========================================
// Function: _R_RecursiveWorldNode @ 00008d80
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_RecursiveWorldNode(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1[1] != _DAT_0000a264) {
    return;
  }
  while( true ) {
    if (*(int *)(__r_nocull + 0x20) == 0) {
      if ((param_2 & 1) != 0) {
        iVar1 = _BoxOnPlaneSide(param_1 + 2,param_1 + 5,0xab1c);
        if (iVar1 == 2) {
          return;
        }
        if (iVar1 == 1) {
          param_2 = param_2 & 0xfffffffe;
        }
      }
      if ((param_2 & 2) != 0) {
        iVar1 = _BoxOnPlaneSide(param_1 + 2,param_1 + 5,0xab30);
        if (iVar1 == 2) {
          return;
        }
        if (iVar1 == 1) {
          param_2 = param_2 & 0xfffffffd;
        }
      }
      if ((param_2 & 4) != 0) {
        iVar1 = _BoxOnPlaneSide(param_1 + 2,param_1 + 5,0xab44);
        if (iVar1 == 2) {
          return;
        }
        if (iVar1 == 1) {
          param_2 = param_2 & 0xfffffffb;
        }
      }
      if ((param_2 & 8) != 0) {
        iVar1 = _BoxOnPlaneSide(param_1 + 2,param_1 + 5,0xab58);
        if (iVar1 == 2) {
          return;
        }
        if (iVar1 == 1) {
          param_2 = param_2 & 0xfffffff7;
        }
      }
      if ((_DAT_0000ac04 != 0) && ((param_2 & 0x10) != 0)) {
        iVar1 = _BoxOnPlaneSide(param_1 + 2,param_1 + 5,0xab6c);
        if (iVar1 == 2) {
          return;
        }
        if (iVar1 == 1) {
          param_2 = param_2 & 0xffffffef;
        }
      }
    }
    if (*param_1 != -1) break;
    _R_RecursiveWorldNode(param_1[10],param_2,param_3);
    param_1 = (int *)param_1[0xb];
    if (param_1[1] != _DAT_0000a264) {
      return;
    }
  }
  _DAT_0000af90 = _DAT_0000af90 + 1;
  if ((float)param_1[2] < _DAT_0000ab80) {
    _DAT_0000ab80 = (float)param_1[2];
  }
  if ((float)param_1[3] < _DAT_0000ab84) {
    _DAT_0000ab84 = (float)param_1[3];
  }
  if ((float)param_1[4] < _DAT_0000ab88) {
    _DAT_0000ab88 = (float)param_1[4];
  }
  if (_DAT_0000ab8c < (float)param_1[5] != (NAN(_DAT_0000ab8c) || NAN((float)param_1[5]))) {
    _DAT_0000ab8c = (float)param_1[5];
  }
  if (_DAT_0000ab90 < (float)param_1[6] != (NAN(_DAT_0000ab90) || NAN((float)param_1[6]))) {
    _DAT_0000ab90 = (float)param_1[6];
  }
  if (_DAT_0000ab94 < (float)param_1[7] != (NAN(_DAT_0000ab94) || NAN((float)param_1[7]))) {
    _DAT_0000ab94 = (float)param_1[7];
  }
  _DAT_0000aca8 = param_1;
  for (iVar1 = param_1[0x11]; iVar1 != 0; iVar1 = iVar1 + -1) {
    _R_AddWorldSurface();
  }
  return;
}



// ===========================================
// Function: _R_PointInLeaf @ 00008f88
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall _R_PointInLeaf(undefined4 param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  int *piVar3;
  
  if (__r_nocull == 0) {
    (*_DAT_0000a2b4)(1,s_R_PointInLeaf__bad_model,param_1);
  }
  piVar3 = *(int **)(__r_nocull + 0xa0);
  iVar2 = *piVar3;
  while (iVar2 == -1) {
    pfVar1 = (float *)piVar3[9];
    if ((pfVar1[2] * param_2[2] + *pfVar1 * *param_2 + pfVar1[1] * param_2[1]) - pfVar1[3] <= 0.0) {
      piVar3 = (int *)piVar3[0xb];
    }
    else {
      piVar3 = (int *)piVar3[10];
    }
    iVar2 = *piVar3;
  }
  return piVar3;
}



// ===========================================
// Function: _R_ClusterPVS @ 00008ff4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall _R_ClusterPVS(undefined4 param_1,int param_2)

{
  if ((((__r_nocull != 0) && (*(int *)(__r_nocull + 0xf8) != 0)) && (-1 < param_2)) &&
     (param_2 < *(int *)(__r_nocull + 0xf0))) {
    return *(int *)(__r_nocull + 0xf4) * param_2 + *(int *)(__r_nocull + 0xf8);
  }
  return *(int *)(__r_nocull + 0xfc);
}



// ===========================================
// Function: _R_MarkLeaves @ 00009026
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_MarkLeaves(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  if (*(int *)(__r_lockpvs + 0x20) == 0) {
    iVar1 = _R_PointInLeaf(0xaa94);
    iVar7 = *(int *)(iVar1 + 0x30);
    if (((_DAT_0000af44 != iVar7) || (_DAT_0000add0 != 0)) ||
       (*(int *)(__r_showcluster + 0x14) != 0)) {
      if (((*(int *)(__r_showcluster + 0x14) != 0) || (*(int *)(__r_showcluster + 0x20) != 0)) &&
         (*(undefined4 *)(__r_showcluster + 0x14) = 0, *(int *)(__r_showcluster + 0x20) != 0)) {
        (*__ri)(0,s_cluster__i__area__i_,iVar7,*(undefined4 *)(iVar1 + 0x34));
      }
      iVar1 = _DAT_0000a264 + 1;
      _DAT_0000a264 = iVar1;
      _DAT_0000af44 = iVar7;
      if ((*(int *)(__r_novis + 0x20) == 0) && (iVar7 != -1)) {
        iVar2 = _R_ClusterPVS();
        iVar7 = *(int *)(__r_nocull + 0xa0);
        iVar5 = __r_nocull;
        if (0 < *(int *)(__r_nocull + 0x98)) {
          do {
            iVar4 = *(int *)(iVar7 + 0x30);
            if ((((-1 < iVar4) && (iVar4 < *(int *)(iVar5 + 0xf0))) &&
                ((*(byte *)((iVar4 >> 3) + iVar2) & (byte)(1 << ((byte)iVar4 & 7))) != 0)) &&
               (iVar4 = iVar7,
               (*(byte *)((*(int *)(iVar7 + 0x34) >> 3) + 0xadb0) &
               (byte)(1 << ((byte)*(int *)(iVar7 + 0x34) & 7))) == 0)) {
              do {
                iVar5 = __r_nocull;
                if (*(int *)(iVar4 + 4) == iVar1) break;
                *(int *)(iVar4 + 4) = iVar1;
                piVar3 = (int *)(iVar4 + 0x20);
                iVar4 = *piVar3;
                iVar1 = _DAT_0000a264;
                iVar5 = __r_nocull;
              } while (*piVar3 != 0);
            }
            iVar6 = iVar6 + 1;
            iVar7 = iVar7 + 0x48;
            if (*(int *)(iVar5 + 0x98) <= iVar6) {
              return;
            }
          } while( true );
        }
      }
      else {
        iVar6 = 0;
        if (0 < *(int *)(__r_nocull + 0x98)) {
          iVar5 = 0;
          iVar7 = __r_nocull;
          do {
            piVar3 = (int *)(*(int *)(iVar7 + 0xa0) + iVar5);
            if (*piVar3 != 1) {
              piVar3[1] = iVar1;
              iVar7 = __r_nocull;
              iVar1 = _DAT_0000a264;
            }
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + 0x48;
          } while (iVar6 < *(int *)(iVar7 + 0x98));
        }
      }
    }
  }
  return;
}



// ===========================================
// Function: _R_AddWorldSurfaces @ 000091a4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddWorldSurfaces(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(int *)(__r_drawworld + 0x20) != 0) && ((DAT_0000adac & 1) == 0)) {
    _DAT_0000a98c = 0x3fe;
    _DAT_0000a994 = 0x3fe000;
    _R_MarkLeaves();
    _ClearBounds(&DAT_0000ab80,&DAT_0000ab8c);
    if (0x20 < _DAT_0000aee8) {
      _DAT_0000aee8 = 0x20;
    }
    uVar3 = 0;
    iVar2 = 0;
    if (0 < _DAT_0000aee8) {
      pbVar1 = (byte *)(_DAT_0000aeec + 0x1c);
      do {
        if ((*pbVar1 & 8) == 0) {
          uVar3 = uVar3 | 1 << ((byte)iVar2 & 0x1f);
        }
        iVar2 = iVar2 + 1;
        pbVar1 = pbVar1 + 0x2c;
      } while (iVar2 < _DAT_0000aee8);
    }
    _R_RecursiveWorldNode(*(undefined4 *)(__r_nocull + 0xa0),0x1f,uVar3);
  }
  return;
}



