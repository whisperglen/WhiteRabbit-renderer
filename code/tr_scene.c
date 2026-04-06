// ===========================================
// Function: _R_ToggleSmpFrame @ 00008000
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ToggleSmpFrame(void)

{
  if (*(int *)(__r_smp + 0x20) == 0) {
    _DAT_00009c7c = 0;
  }
  else {
    _DAT_00009c7c = _DAT_00009c7c ^ 1;
  }
  *(undefined4 *)(*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x21eab4) = 0;
  __r_firstSceneDrawSurf = 0;
  __r_firstSceneSpriteSurf = 0;
  __r_numdlights = 0;
  __r_firstSceneDlight = 0;
  __r_numentities = 0;
  __r_firstSceneEntity = 0;
  __r_numsprites = 0;
  __r_firstSceneSprite = 0;
  __r_numpolys = 0;
  __r_firstScenePoly = 0;
  __r_numpolyverts = 0;
  return;
}



// ===========================================
// Function: _RE_ClearScene @ 00008066
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_ClearScene(void)

{
  __r_firstSceneDlight = __r_numdlights;
  __r_firstSceneEntity = __r_numentities;
  __r_firstSceneSprite = __r_numsprites;
  __r_firstScenePoly = __r_numpolys;
  return;
}



// ===========================================
// Function: _R_AddPolygonSurfaces @ 00008093
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddPolygonSurfaces(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  _DAT_0000a394 = 0x3fe;
  _DAT_0000a39c = 0x3fe000;
  iVar3 = _DAT_0000a4a8;
  iVar4 = _DAT_0000a8fc;
  if (0 < _DAT_0000a8f8) {
    do {
      uVar1 = *(uint *)(iVar4 + 0x14);
      if (((uVar1 & 1) == 0) || (iVar3 != 0)) {
        if (_DAT_0000a6b4 == 0) {
          if ((uVar1 & 0x4000) == 0) goto LAB_000080e7;
        }
        else if ((uVar1 & 0x4000) != 0) {
LAB_000080e7:
          if (iVar3 == 0) {
            if ((uVar1 & 0x400000) == 0) goto LAB_000080fb;
          }
          else if ((uVar1 & 0xc00000) != 0) {
LAB_000080fb:
            uVar2 = _R_GetShaderByHandle(*(undefined4 *)(iVar4 + 4));
            _R_AddDrawSurf(iVar4,uVar2,*(undefined4 *)(iVar4 + 8),0);
            iVar3 = _DAT_0000a4a8;
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar5 < _DAT_0000a8f8);
  }
  return;
}



// ===========================================
// Function: _RE_AddPolyToScene @ 00008129
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_AddPolyToScene(undefined4 param_1,int param_2,void *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  float local_c;
  float local_8;
  float local_4;
  
  if (__tr == 0) {
    return;
  }
  if ((0xc00 < __r_numpolyverts + param_2) || (0x2ff < __r_numpolys)) {
    (*__ri)(3,0x7f00);
    return;
  }
  puVar1 = (undefined4 *)
           (*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x1b32b4 + __r_numpolys * 0x18);
  puVar1[1] = param_1;
  *puVar1 = 5;
  puVar1[3] = param_2;
  puVar1[4] = *(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x1b7ab4 + __r_numpolyverts * 0x18;
  puVar1[5] = param_4;
  _memcpy((void *)puVar1[4],param_3,param_2 * 0x18);
  __r_numpolyverts = __r_numpolyverts + param_2;
  __r_numpolys = __r_numpolys + 1;
  if ((*(int *)(__ri + 0xb4) != 1) && (_DAT_0000a6b4 == 0)) {
    local_c = *(float *)puVar1[4];
    local_8 = *(float *)(puVar1[4] + 4);
    iVar8 = 1;
    local_4 = *(float *)(puVar1[4] + 8);
    fVar2 = *(float *)puVar1[4];
    fVar3 = *(float *)(puVar1[4] + 4);
    fVar4 = *(float *)(puVar1[4] + 8);
    if (1 < (int)puVar1[3]) {
      iVar7 = 0x18;
      do {
        _AddPointToBounds(puVar1[4] + iVar7,&local_c,&stack0x00000000);
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x18;
      } while (iVar8 < (int)puVar1[3]);
    }
    iVar7 = 1;
    iVar8 = *(int *)(__ri + 0xb4);
    bVar9 = iVar8 == 1;
    if (1 < iVar8) {
      if (3 < iVar8 + -1) {
        pfVar6 = (float *)(*(int *)(__ri + 0xb8) + 100);
        pfVar5 = (float *)(*(int *)(__ri + 0xb8) + 0xc0);
        do {
          if ((((pfVar6[-1] < fVar2 != (pfVar6[-1] == fVar2)) &&
               (*pfVar6 < fVar3 != (*pfVar6 == fVar3))) &&
              (pfVar6[1] < fVar4 != (pfVar6[1] == fVar4))) &&
             (((local_c <= pfVar6[2] && (local_8 <= pfVar6[3])) && (local_4 <= pfVar6[4]))))
          goto LAB_00008474;
          if (((pfVar5[-1] < fVar2 != (pfVar5[-1] == fVar2)) &&
              (*pfVar5 < fVar3 != (*pfVar5 == fVar3))) &&
             ((pfVar5[1] < fVar4 != (pfVar5[1] == fVar4) &&
              (((local_c <= pfVar5[2] && (local_8 <= pfVar5[3])) && (local_4 <= pfVar5[4])))))) {
            iVar7 = iVar7 + 1;
            goto LAB_00008474;
          }
          if ((((pfVar5[0x16] < fVar2 != (pfVar5[0x16] == fVar2)) &&
               (pfVar5[0x17] < fVar3 != (pfVar5[0x17] == fVar3))) &&
              ((pfVar5[0x18] < fVar4 != (pfVar5[0x18] == fVar4) &&
               ((local_c <= pfVar5[0x19] && (local_8 <= pfVar5[0x1a])))))) &&
             (local_4 <= pfVar5[0x1b])) {
            iVar7 = iVar7 + 2;
            goto LAB_00008474;
          }
          if (((((pfVar5[0x2d] < fVar2 != (pfVar5[0x2d] == fVar2)) &&
                (pfVar5[0x2e] < fVar3 != (pfVar5[0x2e] == fVar3))) &&
               (pfVar5[0x2f] < fVar4 != (pfVar5[0x2f] == fVar4))) &&
              ((local_c <= pfVar5[0x30] && (local_8 <= pfVar5[0x31])))) && (local_4 <= pfVar5[0x32])
             ) {
            iVar7 = iVar7 + 3;
            goto LAB_00008474;
          }
          iVar7 = iVar7 + 4;
          pfVar6 = pfVar6 + 0x5c;
          pfVar5 = pfVar5 + 0x5c;
        } while (iVar7 < iVar8 + -3);
      }
      if (iVar7 < iVar8) {
        pfVar6 = (float *)(*(int *)(__ri + 0xb8) + 8 + iVar7 * 0x5c);
        do {
          if (((pfVar6[-1] < fVar2 != (pfVar6[-1] == fVar2)) &&
              (*pfVar6 < fVar3 != (*pfVar6 == fVar3))) &&
             ((pfVar6[1] < fVar4 != (pfVar6[1] == fVar4) &&
              (((local_c <= pfVar6[2] && (local_8 <= pfVar6[3])) && (local_4 <= pfVar6[4]))))))
          break;
          iVar7 = iVar7 + 1;
          pfVar6 = pfVar6 + 0x17;
        } while (iVar7 < iVar8);
      }
LAB_00008474:
      bVar9 = iVar7 == iVar8;
    }
    if (!bVar9) goto LAB_00008487;
  }
  iVar7 = 0;
LAB_00008487:
  puVar1[2] = iVar7;
  return;
}



// ===========================================
// Function: _RE_GetRenderEntity @ 000084a6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _RE_GetRenderEntity(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < __r_numentities) {
    piVar2 = (int *)(*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x10064c);
    do {
      if (*piVar2 == param_1) {
        return iVar1 * 0x2cc + 0x100580 + *(int *)(&_backEndData + _DAT_00009c7c * 4);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xb3;
    } while (iVar1 < __r_numentities);
  }
  return 0;
}



// ===========================================
// Function: _RE_AddRefEntityToScene @ 000084ef
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_AddRefEntityToScene(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((__tr != 0) && (__r_numentities < 0x3fd)) {
    if (7 < *param_1) {
      (*_DAT_00009c8c)(1,s_RE_AddRefEntityToScene__bad_reTy,*param_1);
    }
    piVar2 = (int *)(*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x100580 +
                    __r_numentities * 0x2cc);
    for (iVar1 = 0x73; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *param_1;
      param_1 = param_1 + 1;
      piVar2 = piVar2 + 1;
    }
    *(undefined4 *)
     (*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x100754 + __r_numentities * 0x2cc) = 0;
    __r_numentities = __r_numentities + 1;
  }
  return;
}



// ===========================================
// Function: _RE_AddRefSpriteToScene @ 00008574
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_AddRefSpriteToScene(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((__tr != 0) && (__r_numsprites < 0x400)) {
    puVar1 = (undefined4 *)
             (*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x1c9ab4 + __r_numsprites * 0x54);
    puVar1[3] = *(undefined4 *)(param_1 + 0x48);
    puVar1[4] = *(undefined4 *)(param_1 + 0x4c);
    uVar2 = *(undefined4 *)(param_1 + 0x50);
    *puVar1 = 0xe;
    puVar1[5] = uVar2;
    puVar1[1] = *(undefined4 *)(param_1 + 0xc);
    puVar1[6] = *(undefined4 *)(param_1 + 0x60);
    *(undefined1 *)(puVar1 + 0x11) = *(undefined1 *)(param_1 + 0x5e);
    puVar1[0x12] = *(undefined4 *)(param_1 + 4);
    puVar1[0x13] = *(undefined4 *)(param_1 + 200);
    puVar1[7] = *(undefined4 *)(param_1 + 0x20);
    puVar1[8] = *(undefined4 *)(param_1 + 0x24);
    puVar1[9] = *(undefined4 *)(param_1 + 0x28);
    puVar1[10] = *(undefined4 *)(param_1 + 0x2c);
    puVar1[0xb] = *(undefined4 *)(param_1 + 0x30);
    puVar1[0xc] = *(undefined4 *)(param_1 + 0x34);
    puVar1[0xd] = *(undefined4 *)(param_1 + 0x38);
    puVar1[0xe] = *(undefined4 *)(param_1 + 0x3c);
    puVar1[0xf] = *(undefined4 *)(param_1 + 0x40);
    *(undefined1 *)(puVar1 + 0x10) = *(undefined1 *)(param_1 + 0xbc);
    *(undefined1 *)((int)puVar1 + 0x41) = *(undefined1 *)(param_1 + 0xbd);
    *(undefined1 *)((int)puVar1 + 0x42) = *(undefined1 *)(param_1 + 0xbe);
    *(undefined1 *)((int)puVar1 + 0x43) = *(undefined1 *)(param_1 + 0xbf);
    __r_numsprites = __r_numsprites + 1;
  }
  return;
}



// ===========================================
// Function: _RE_AddLightToScene @ 0000864a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_AddLightToScene(undefined4 *param_1,float param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  
  if ((((__tr != 0) && (__r_numdlights < 0x20)) && (param_2 < 0.0 == (param_2 == 0.0))) &&
     ((_DAT_0000b0c0 != 2 && (_DAT_0000b0c0 != 4)))) {
    puVar1 = (undefined4 *)
             (*(int *)(&_backEndData + _DAT_00009c7c * 4) + 0x100000 + __r_numdlights * 0x2c);
    __r_numdlights = __r_numdlights + 1;
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    puVar1[7] = param_6;
    puVar1[6] = param_2;
    puVar1[3] = param_3;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    return;
  }
  return;
}



// ===========================================
// Function: _RE_RenderScene @ 000086d9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_RenderScene(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  int iVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined1 auStack_280 [8];
  int iStack_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_14c;
  int iStack_148;
  undefined4 uStack_144;
  int iStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (__tr != 0) {
    _GLimp_LogComment(s________RE_RenderScene_______);
    if (*(int *)(__r_norefresh + 0x20) == 0) {
      (*__AddPointToBounds)();
      if ((__ri == 0) && ((*(byte *)(param_1 + 0x13) & 1) == 0)) {
        (*_DAT_00009c8c)(1,s_R_RenderScene__NULL_worldmodel);
      }
      puVar19 = param_1 + 0x1c;
      puVar20 = (undefined4 *)&DAT_0000a7e0;
      for (iVar18 = 0x40; iVar18 != 0; iVar18 = iVar18 + -1) {
        *puVar20 = *puVar19;
        puVar19 = puVar19 + 1;
        puVar20 = puVar20 + 1;
      }
      __TIKI_Skel_boneindex = 0;
      _DAT_0000a474 = 0;
      uVar1 = *param_1;
      _DAT_0000a76c = param_1[1];
      _DAT_0000a770 = param_1[2];
      iVar18 = param_1[3];
      _DAT_0000a778 = param_1[4];
      _DAT_0000a77c = param_1[5];
      _DAT_0000a780 = param_1[6];
      _DAT_0000a784 = param_1[7];
      _DAT_0000a788 = param_1[8];
      _DAT_0000a78c = param_1[9];
      _DAT_0000a790 = param_1[10];
      _DAT_0000a794 = param_1[0xb];
      _DAT_0000a798 = param_1[0xc];
      _DAT_0000a79c = param_1[0xd];
      _DAT_0000a7a0 = param_1[0xe];
      _DAT_0000a7a4 = param_1[0xf];
      _DAT_0000a7a8 = param_1[0x10];
      _DAT_0000a7ac = param_1[0x11];
      _DAT_0000a7b0 = param_1[0x12];
      _DAT_0000a7b4 = param_1[0x13];
      _DAT_0000a948 = param_1[0x6f];
      _DAT_0000a7d8 = 0;
      if ((_DAT_0000a7b4 & 1) == 0) {
        iVar2 = param_1[0x14];
        iVar3 = param_1[0x15];
        iVar4 = param_1[0x16];
        iVar5 = param_1[0x17];
        iVar6 = param_1[0x18];
        iVar7 = param_1[0x19];
        iVar8 = param_1[0x1a];
        iVar9 = param_1[0x1b];
        bVar16 = iVar2 != _DAT_0000a7b8;
        bVar17 = iVar3 != _DAT_0000a7bc;
        bVar15 = iVar4 != _DAT_0000a7c0;
        bVar14 = iVar5 != _DAT_0000a7c4;
        bVar13 = iVar6 != _DAT_0000a7c8;
        bVar12 = iVar7 != _DAT_0000a7cc;
        bVar11 = iVar8 != _DAT_0000a7d0;
        bVar10 = iVar9 != _DAT_0000a7d4;
        _DAT_0000a7b8 = iVar2;
        _DAT_0000a7bc = iVar3;
        _DAT_0000a7c0 = iVar4;
        _DAT_0000a7c4 = iVar5;
        _DAT_0000a7c8 = iVar6;
        _DAT_0000a7cc = iVar7;
        _DAT_0000a7d0 = iVar8;
        _DAT_0000a7d4 = iVar9;
        if (((((((bVar16 || bVar17) || bVar15) || bVar14) || bVar13) || bVar12) || bVar11) || bVar10
           ) {
          _DAT_0000a7d8 = 1;
        }
      }
      _DAT_0000a914 = param_1[0x62];
      _DAT_0000a910 = param_1[0x61];
      _DAT_0000a918 = param_1[99];
      _DAT_0000a904 = *(int *)(&_backEndData + _DAT_00009c7c * 4);
      _DAT_0000a91c = param_1[100];
      _DAT_0000a90c = _DAT_0000a904 + 0x80000;
      _DAT_0000a920 = param_1[0x65];
      _DAT_0000a924 = param_1[0x66];
      _DAT_0000a928 = param_1[0x67];
      _DAT_0000a92c = param_1[0x68];
      _DAT_0000a930 = param_1[0x69];
      _DAT_0000a934 = param_1[0x6a];
      _DAT_0000a938 = param_1[0x6b];
      _DAT_0000a93c = param_1[0x6c];
      _DAT_0000a940 = param_1[0x6d];
      _DAT_0000a944 = param_1[0x6e];
      _DAT_0000a900 = __r_firstSceneDrawSurf;
      _DAT_0000a908 = __r_firstSceneSpriteSurf;
      _DAT_0000a7dc = (float)_DAT_0000a7b0 * (float)___real_3f50624dd2f1a9fc;
      _DAT_0000a8e0 = __r_numentities - __r_firstSceneEntity;
      _DAT_0000a8e4 = __r_firstSceneEntity * 0x2cc + 0x100580 + _DAT_0000a904;
      _DAT_0000a8e8 = __r_numsprites - __r_firstSceneSprite;
      _DAT_0000a8ec = __r_firstSceneSprite * 0x54 + 0x1c9ab4 + _DAT_0000a904;
      _DAT_0000a8f0 = __r_numdlights - __r_firstSceneDlight;
      _DAT_0000a8f4 = __r_firstSceneDlight * 0x2c + 0x100000 + _DAT_0000a904;
      _DAT_0000a8f8 = __r_numpolys - __r_firstScenePoly;
      _DAT_0000a8fc = _DAT_0000a904 + 0x1b32b4 + __r_firstScenePoly * 0x18;
      if (((*(int *)(__r_dynamiclight + 0x20) == 0) || (*(int *)(__r_vertexLight + 0x20) == 1)) ||
         (_DAT_0000b0c0 == 4)) {
        _DAT_0000a8f0 = 0;
      }
      __R_GetShaderByHandle = __R_GetShaderByHandle + 1;
      _DAT_00009c74 = _DAT_00009c74 + 1;
      _DAT_0000a760 = 0;
      _DAT_0000a764 = 0;
      _DAT_0000a768 = uVar1;
      _DAT_0000a774 = iVar18;
      _memset(auStack_280,0,0x280);
      uStack_13c = _DAT_0000a778;
      uStack_138 = _DAT_0000a77c;
      uStack_274 = param_1[6];
      iStack_148 = (_DAT_0000b0d8 - iVar18) - _DAT_0000a76c;
      uStack_270 = param_1[7];
      uStack_26c = param_1[8];
      uStack_268 = param_1[9];
      uStack_144 = _DAT_0000a770;
      uStack_264 = param_1[10];
      uStack_170 = 0;
      uStack_260 = param_1[0xb];
      uStack_25c = param_1[0xc];
      uStack_258 = param_1[0xd];
      uStack_254 = param_1[0xe];
      uStack_250 = param_1[0xf];
      uStack_24c = param_1[0x10];
      uStack_248 = param_1[0x11];
      uStack_17c = param_1[6];
      uStack_178 = param_1[7];
      uStack_174 = param_1[8];
      uStack_8 = param_1[0x5c];
      uStack_4 = param_1[0x5d];
      uStack_14c = uVar1;
      iStack_140 = iVar18;
      _R_RenderView(&uStack_274);
      __r_firstSceneDrawSurf = _DAT_0000a900;
      __r_firstSceneSpriteSurf = _DAT_0000a908;
      __r_firstSceneEntity = __r_numentities;
      __r_firstSceneSprite = __r_numsprites;
      __r_firstSceneDlight = __r_numdlights;
      __r_firstScenePoly = __r_numpolys;
      iVar18 = (*__AddPointToBounds)();
      _DAT_0000a9ac = _DAT_0000a9ac + (iVar18 - iStack_278);
    }
  }
  return;
}



