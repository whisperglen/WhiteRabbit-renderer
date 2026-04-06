// ===========================================
// Function: _R_ClearFlares @ 00007b00
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ClearFlares(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  _memset(&_r_flareStructs,0,0x1e00);
  __r_activeFlares = 0;
  puVar1 = (undefined4 *)&_r_flareStructs;
  puVar2 = (undefined4 *)0x0;
  do {
    __r_inactiveFlares = puVar1;
    *__r_inactiveFlares = puVar2;
    puVar1 = __r_inactiveFlares + 0xf;
    puVar2 = __r_inactiveFlares;
  } while ((int)(__r_inactiveFlares + 0xf) < 0xb1f0);
  return;
}



// ===========================================
// Function: _RB_AddFlare @ 00007b3a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_AddFlare(int param_1,undefined4 param_2,float *param_3,undefined4 *param_4,float *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40 [4];
  float fStack_30;
  float fStack_2c;
  undefined1 local_20 [8];
  undefined4 uStack_18;
  undefined1 auStack_10 [16];
  
  _DAT_00009928 = _DAT_00009928 + 1;
  local_50 = 0.0;
  if (param_5 != (float *)0x0) {
    local_4c = _DAT_00009608 - *param_3;
    local_48 = _DAT_0000960c - param_3[1];
    local_44 = _DAT_00009610 - param_3[2];
    _VectorNormalizeFast(&local_4c);
    local_50 = param_5[2] * local_44 + *param_5 * local_4c + param_5[1] * local_48;
    if (local_50 < ___real_3c23d70a) {
      return;
    }
  }
  _R_TransformModelToClip(param_3,0x98c4,0x9748,local_20,local_40);
  iVar3 = 0;
  do {
    if (local_40[3] <= local_40[iVar3]) {
      return;
    }
    if (local_40[iVar3] <= -local_40[3]) {
      return;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  _R_TransformClipToWindow(local_40,&DAT_00009608,auStack_10,&fStack_30);
  puVar1 = __r_inactiveFlares;
  if ((((fStack_30 < 0.0 != NAN(fStack_30)) ||
       ((float)_DAT_00009738 < fStack_30 != ((float)_DAT_00009738 == fStack_30))) ||
      (fStack_2c < 0.0 != NAN(fStack_2c))) ||
     (puVar4 = __r_activeFlares,
     (float)_DAT_0000973c < fStack_2c != ((float)_DAT_0000973c == fStack_2c))) {
    return;
  }
  for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    if (((puVar4[4] == param_1) && (puVar4[3] == _DAT_00009714)) && (puVar4[2] == _DAT_0000970c))
    goto LAB_00007cdf;
  }
  if (__r_inactiveFlares != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*__r_inactiveFlares;
    *__r_inactiveFlares = __r_activeFlares;
    __r_inactiveFlares = puVar4;
    __r_activeFlares = puVar1;
    puVar1[4] = param_1;
    puVar1[3] = _DAT_00009714;
    puVar1[2] = _DAT_0000970c;
    puVar1[1] = 0xffffffff;
    puVar4 = puVar1;
LAB_00007cdf:
    if (puVar4[1] != _DAT_00009718 + -1) {
      puVar4[7] = 0;
      puVar4[6] = _DAT_0000946c + -2000;
    }
    puVar4[1] = _DAT_00009718;
    puVar4[5] = param_2;
    puVar4[0xc] = *param_4;
    puVar4[0xd] = param_4[1];
    puVar4[0xe] = param_4[2];
    if (param_5 != (float *)0x0) {
      puVar4[0xc] = local_50 * (float)puVar4[0xc];
      puVar4[0xd] = local_50 * (float)puVar4[0xd];
      puVar4[0xe] = local_50 * (float)puVar4[0xe];
    }
    uVar2 = __ftol2_sse();
    puVar4[9] = uVar2;
    uVar2 = __ftol2_sse();
    puVar4[10] = uVar2;
    puVar4[0xb] = uStack_18;
  }
  return;
}



// ===========================================
// Function: _RB_TestFlare @ 00007d83
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_TestFlare(int param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = param_1;
  _DAT_0000992c = _DAT_0000992c + 1;
  fVar2 = 1.4013e-45;
  _DAT_00009454 = 0;
  (*__qglReadPixels)(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),1,1,0x1902,
                     0x1406,&param_1);
  fVar2 = -*(float *)(iVar1 + 0x2c) -
          -(_DAT_00009780 / (_DAT_00009774 * ((fVar2 + fVar2) - 1.0) - _DAT_00009770));
  if (fVar2 < (float)___real_4038000000000000 ==
      (NAN(fVar2) || NAN((float)___real_4038000000000000))) {
    if (*(int *)(iVar1 + 0x1c) != 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(int *)(iVar1 + 0x18) = _DAT_0000946c + -1;
    }
    fVar2 = 1.0 - ((float)(_DAT_0000946c - *(int *)(iVar1 + 0x18)) / (float)___real_408f400000000000
                  ) * *(float *)(__r_flareFade + 0x1c);
  }
  else {
    if (*(int *)(iVar1 + 0x1c) == 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 1;
      *(int *)(iVar1 + 0x18) = _DAT_0000946c + -1;
    }
    fVar2 = ((float)(_DAT_0000946c - *(int *)(iVar1 + 0x18)) / (float)___real_408f400000000000) *
            *(float *)(__r_flareFade + 0x1c);
  }
  if (fVar2 < 0.0 != NAN(fVar2)) {
    *(undefined4 *)(iVar1 + 0x20) = 0;
    return;
  }
  if (1.0 < fVar2 != NAN(fVar2)) {
    *(undefined4 *)(iVar1 + 0x20) = 0x3f800000;
    return;
  }
  *(float *)(iVar1 + 0x20) = fVar2;
  return;
}



// ===========================================
// Function: _RB_RenderFlare @ 00007eb6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_RenderFlare(int param_1)

{
  int *piVar1;
  float fVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int *piVar6;
  
  _DAT_00009930 = _DAT_00009930 + 1;
  uVar3 = __ftol2_sse();
  uVar4 = __ftol2_sse();
  uVar5 = __ftol2_sse();
  fVar2 = (*(float *)(__r_flareSize + 0x1c) / (float)___real_4084000000000000 -
          (float)___real_4020000000000000 / *(float *)(param_1 + 0x2c)) * (float)_DAT_00009738;
  _RB_BeginSurface(_DAT_000094c0,*(undefined4 *)(param_1 + 0x14));
  piVar1 = (int *)(param_1 + 0x24);
  piVar6 = (int *)(param_1 + 0x28);
  *(float *)(_DAT_003204ac * 0x10 + 0xb90d8) = (float)*(int *)(param_1 + 0x24) - fVar2;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90dc) = (float)*piVar6 - fVar2;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36d8) = 0;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36dc) = 0;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d8) = uVar3;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d9) = uVar4;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189da) = uVar5;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189db) = 0xff;
  _DAT_003204ac = _DAT_003204ac + 1;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90d8) = (float)*piVar1 - fVar2;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90dc) = (float)*piVar6 + fVar2;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36d8) = 0;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36dc) = 0x3f800000;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d8) = uVar3;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d9) = uVar4;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189da) = uVar5;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189db) = 0xff;
  _DAT_003204ac = _DAT_003204ac + 1;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90d8) = (float)*piVar1 + fVar2;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90dc) = (float)*piVar6 + fVar2;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36d8) = 0x3f800000;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36dc) = 0x3f800000;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d8) = uVar3;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d9) = uVar4;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189da) = uVar5;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189db) = 0xff;
  _DAT_003204ac = _DAT_003204ac + 1;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90d8) = (float)*piVar1 + fVar2;
  *(float *)(_DAT_003204ac * 0x10 + 0xb90dc) = (float)*piVar6 - fVar2;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36d8) = 0x3f800000;
  *(undefined4 *)(_DAT_003204ac * 0x10 + 0x1a36dc) = 0;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d8) = uVar3;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189d9) = uVar4;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189da) = uVar5;
  *(undefined1 *)(_DAT_003204ac * 4 + 0x2189db) = 0xff;
  _DAT_003204ac = _DAT_003204ac + 1;
  *(undefined4 *)(&_tess + _DAT_003204a8 * 4) = 0;
  _DAT_003204a8 = _DAT_003204a8 + 1;
  *(undefined4 *)(&_tess + _DAT_003204a8 * 4) = 1;
  _DAT_003204a8 = _DAT_003204a8 + 1;
  *(undefined4 *)(&_tess + _DAT_003204a8 * 4) = 2;
  _DAT_003204a8 = _DAT_003204a8 + 1;
  *(undefined4 *)(&_tess + _DAT_003204a8 * 4) = 0;
  _DAT_003204a8 = _DAT_003204a8 + 1;
  *(undefined4 *)(&_tess + _DAT_003204a8 * 4) = 2;
  _DAT_003204a8 = _DAT_003204a8 + 1;
  *(undefined4 *)(&_tess + _DAT_003204a8 * 4) = 3;
  _DAT_003204a8 = _DAT_003204a8 + 1;
  _DAT_003204c4 = 1;
  _RB_EndSurface();
  return;
}



// ===========================================
// Function: _RB_RenderFlares @ 0000823f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_RenderFlares(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(__r_flares + 0x20) != 0) {
    bVar1 = false;
    puVar3 = (undefined4 *)&_r_activeFlares;
    puVar2 = __r_activeFlares;
    if (__r_activeFlares != (undefined4 *)0x0) {
      do {
        if ((int)puVar2[1] < _DAT_00009718 + -1) {
          *puVar3 = *puVar2;
          *puVar2 = __r_inactiveFlares;
          puVar4 = puVar3;
          __r_inactiveFlares = puVar2;
        }
        else {
          puVar2[8] = 0;
          puVar4 = puVar2;
          if ((puVar2[3] == _DAT_00009714) && (puVar2[2] == _DAT_0000970c)) {
            _RB_TestFlare(puVar2);
            if (NAN((float)puVar2[8]) == ((float)puVar2[8] == 0.0)) {
              bVar1 = true;
            }
            else {
              *puVar3 = *puVar2;
              *puVar2 = __r_inactiveFlares;
              puVar4 = puVar3;
              __r_inactiveFlares = puVar2;
            }
          }
        }
        puVar2 = (undefined4 *)*puVar4;
        puVar3 = puVar4;
      } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
      if (bVar1) {
        if (_DAT_0000970c != 0) {
          (*__qglDisable)(0x3000);
        }
        (*__qglPushMatrix)();
        (*__qglLoadIdentity)();
        (*__qglMatrixMode)(0x1701);
        (*__qglPushMatrix)();
        (*__qglLoadIdentity)();
        (*__qglOrtho)((double)_DAT_00009730,(double)(_DAT_00009738 + _DAT_00009730),
                      (double)_DAT_00009734,(double)(_DAT_0000973c + _DAT_00009734),
                      ___real_c0f869f000000000,___real_40f869f000000000);
        for (puVar2 = __r_activeFlares; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2)
        {
          if (((puVar2[3] == _DAT_00009714) && (puVar2[2] == _DAT_0000970c)) &&
             (NAN((float)puVar2[8]) == ((float)puVar2[8] == 0.0))) {
            _RB_RenderFlare(puVar2);
          }
        }
        (*__qglPopMatrix)();
        (*__qglMatrixMode)(0x1700);
        (*__qglPopMatrix)();
      }
    }
  }
  return;
}



