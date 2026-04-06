// ===========================================
// Function: _R_GetModelByHandle @ 00009c00
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * _R_GetModelByHandle(int param_1)

{
  if ((0 < param_1) && (param_1 < _DAT_000201f0)) {
    return &DAT_0000cfb0 + param_1 * 0x70;
  }
  return &DAT_0000cfb0;
}



// ===========================================
// Function: _R_FreeModel @ 00009c20
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_FreeModel(void *param_1)

{
  if (*(int *)((int)param_1 + 0x40) == 5) {
    (*_DAT_0000c2e4)(*(undefined4 *)((int)param_1 + 0x60));
  }
  _memset(param_1,0,0x70);
  return;
}



// ===========================================
// Function: _R_AllocModel @ 00009c47
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * _R_AllocModel(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = 0;
  if (0 < _DAT_000201f0) {
    pcVar3 = &DAT_0000cfb0;
    do {
      if (*pcVar3 == '\0') break;
      iVar1 = iVar1 + 1;
      pcVar3 = pcVar3 + 0x70;
    } while (iVar1 < _DAT_000201f0);
  }
  if (iVar1 == _DAT_000201f0) {
    if (_DAT_000201f0 == 700) {
      return (undefined1 *)0x0;
    }
    _DAT_000201f0 = _DAT_000201f0 + 1;
  }
  iVar2 = iVar1 * 0x70;
  *(int *)(iVar2 + 0xcff4) = iVar1;
  *(undefined4 *)(iVar2 + 0xd01c) = _r_sequencenumber;
  return &DAT_0000cfb0 + iVar2;
}



// ===========================================
// Function: _R_FreeModels @ 00009c98
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_FreeModels(void)

{
  char *__s;
  int iVar1;
  
  iVar1 = 0;
  if (0 < _DAT_000201f0) {
    __s = &DAT_0000cfb0;
    do {
      if ((*__s != '\0') && (*(int *)(__s + 0x40) != 5)) {
        _memset(__s,0,0x70);
      }
      iVar1 = iVar1 + 1;
      __s = __s + 0x70;
    } while (iVar1 < _DAT_000201f0);
  }
  return;
}



// ===========================================
// Function: _R_CacheModel @ 00009cd0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_CacheModel(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iStack_8;
  
  if (*(int *)(param_1 + 0x6c) != -1) {
    *(undefined4 *)(param_1 + 0x6c) = _r_sequencenumber;
  }
  if ((((*(int *)(param_1 + 0x40) == 5) && (-1 < *(int *)(param_1 + 0x60))) &&
      (iVar1 = (*__glConfig)(*(int *)(param_1 + 0x60)), iVar1 != 0)) &&
     (iStack_8 = 0, 0 < *(int *)(iVar1 + 0x80))) {
    param_1 = 0;
    do {
      iVar4 = 0;
      pcVar5 = (char *)(*(int *)(iVar1 + 0xa0) + param_1 + iVar1);
      if (0 < *(int *)(pcVar5 + 0x150)) {
        pcVar3 = pcVar5 + 0x140;
        pcVar6 = pcVar5;
        do {
          pcVar6 = pcVar6 + 0x40;
          if (*pcVar6 != '\0') {
            iVar2 = _R_FindShader(pcVar6,0xffffffff,(*(uint *)(pcVar5 + 0x154) & 0x100) == 0,
                                  (*(uint *)(pcVar5 + 0x154) & 0x200) == 0,1);
            *(undefined4 *)pcVar3 = *(undefined4 *)(iVar2 + 0x44);
          }
          iVar4 = iVar4 + 1;
          pcVar3 = pcVar3 + 4;
        } while (iVar4 < *(int *)(pcVar5 + 0x150));
      }
      param_1 = param_1 + 0x15c;
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < *(int *)(iVar1 + 0x80));
  }
  return;
}



// ===========================================
// Function: _R_LoadMD3 @ 00009dc2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_R_LoadMD3(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
          undefined4 param_6)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  void *in_EAX;
  int iVar4;
  undefined4 uVar5;
  size_t __n;
  char *pcVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined2 *puVar14;
  float10 fVar15;
  
  iVar9 = param_2;
  iVar2 = param_1;
  iVar4 = _LittleLong(*(undefined4 *)((int)in_EAX + 4));
  if (iVar4 != 0xf) {
    (*__ri)(3,s_R_LoadMD3___s_has_wrong_version_,param_3,iVar4,0xf);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 2;
  iVar4 = _LittleLong(*(undefined4 *)((int)in_EAX + 0x68));
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + iVar4;
  uVar5 = (*__R_FindShader)(iVar4);
  *(undefined4 *)(param_1 + 0x50 + param_2 * 4) = uVar5;
  __n = _LittleLong(*(undefined4 *)((int)in_EAX + 0x68));
  _memcpy(*(void **)(param_1 + 0x50 + param_2 * 4),in_EAX,__n);
  uVar5 = _LittleLong(**(undefined4 **)(param_1 + 0x50 + param_2 * 4));
  **(undefined4 **)(param_1 + 0x50 + param_2 * 4) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 4));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 4) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x4c));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x4c) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x50));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x50) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x54));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x54) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x5c));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x5c) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x60));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x60) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 100));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 100) = uVar5;
  uVar5 = _LittleLong(*(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x68));
  *(undefined4 *)(*(int *)(param_1 + 0x50 + param_2 * 4) + 0x68) = uVar5;
  iVar4 = *(int *)(param_1 + 0x50 + param_2 * 4);
  if (0 < *(int *)(iVar4 + 0x4c)) {
    param_1 = 0;
    if (0 < *(int *)(iVar4 + 0x4c)) {
      pfVar8 = (float *)(*(int *)(iVar4 + 0x5c) + iVar4 + 0x24);
      do {
        fVar15 = (float10)_LittleFloat(pfVar8);
        *pfVar8 = (float)fVar15;
        pfVar10 = pfVar8 + -3;
        param_2 = 3;
        do {
          fVar15 = (float10)_LittleFloat(pfVar10 + -6);
          pfVar10[-6] = (float)fVar15;
          fVar15 = (float10)_LittleFloat(pfVar10 + -3);
          pfVar10[-3] = (float)fVar15;
          fVar15 = (float10)_LittleFloat(pfVar10);
          *pfVar10 = (float)fVar15;
          pfVar10 = pfVar10 + 1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
        pfVar8 = pfVar8 + 0xe;
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)(*(int *)(iVar2 + 0x50 + iVar9 * 4) + 0x4c));
    }
    iVar4 = *(int *)(iVar2 + 0x50 + iVar9 * 4);
    param_1 = 0;
    if (0 < *(int *)(iVar4 + 0x50) * *(int *)(iVar4 + 0x4c)) {
      pfVar8 = (float *)(*(int *)(iVar4 + 0x60) + iVar4 + 0x4c);
      do {
        param_2 = 3;
        pfVar10 = pfVar8;
        do {
          fVar15 = (float10)_LittleFloat(pfVar10 + -3);
          pfVar10[-3] = (float)fVar15;
          fVar15 = (float10)_LittleFloat(pfVar10);
          *pfVar10 = (float)fVar15;
          fVar15 = (float10)_LittleFloat(pfVar10 + 3);
          pfVar10[3] = (float)fVar15;
          fVar15 = (float10)_LittleFloat(pfVar10 + 6);
          pfVar10[6] = (float)fVar15;
          pfVar10 = pfVar10 + 1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
        iVar4 = *(int *)(iVar2 + 0x50 + iVar9 * 4);
        pfVar8 = pfVar8 + 0x1c;
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)(iVar4 + 0x50) * *(int *)(iVar4 + 0x4c));
    }
    iVar4 = *(int *)(iVar2 + 0x50 + iVar9 * 4);
    puVar11 = (undefined4 *)(*(int *)(iVar4 + 100) + iVar4);
    param_1 = 0;
    if (0 < *(int *)(iVar4 + 0x54)) {
      do {
        uVar5 = _LittleLong(*puVar11);
        *puVar11 = uVar5;
        uVar5 = _LittleLong(puVar11[0x11]);
        puVar11[0x11] = uVar5;
        uVar5 = _LittleLong(puVar11[0x12]);
        puVar11[0x12] = uVar5;
        uVar5 = _LittleLong(puVar11[0x13]);
        puVar11[0x13] = uVar5;
        uVar5 = _LittleLong(puVar11[0x15]);
        puVar11[0x15] = uVar5;
        uVar5 = _LittleLong(puVar11[0x16]);
        puVar11[0x16] = uVar5;
        uVar5 = _LittleLong(puVar11[0x14]);
        puVar11[0x14] = uVar5;
        uVar5 = _LittleLong(puVar11[0x17]);
        puVar11[0x17] = uVar5;
        uVar5 = _LittleLong(puVar11[0x18]);
        puVar11[0x18] = uVar5;
        uVar5 = _LittleLong(puVar11[0x19]);
        puVar11[0x19] = uVar5;
        uVar5 = _LittleLong(puVar11[0x1a]);
        puVar11[0x1a] = uVar5;
        if (30000 < (int)puVar11[0x14]) {
          (*_DAT_0000c274)(1,s_R_LoadMD3___s_has_more_than__i_v,param_6,&DAT_00007530,puVar11[0x14])
          ;
        }
        if (180000 < puVar11[0x15] * 3) {
          (*_DAT_0000c274)(1,s_R_LoadMD3___s_has_more_than__i_t,param_6,60000,puVar11[0x15]);
        }
        pcVar6 = (char *)(puVar11 + 1);
        *puVar11 = 6;
        _Q_strlwr(pcVar6);
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        iVar4 = (int)pcVar6 - ((int)puVar11 + 5);
        if ((2 < iVar4) && (*(char *)((int)puVar11 + iVar4 + 2) == '_')) {
          *(undefined1 *)((int)puVar11 + iVar4 + 2) = 0;
        }
        iVar12 = puVar11[0x17] + (int)puVar11;
        iVar4 = 0;
        if (0 < (int)puVar11[0x13]) {
          do {
            iVar7 = _R_FindShader(iVar12,0xffffffff,1,1,1);
            if (*(int *)(iVar7 + 0x50) == 0) {
              *(undefined4 *)(iVar12 + 0x40) = *(undefined4 *)(iVar7 + 0x44);
            }
            else {
              *(undefined4 *)(iVar12 + 0x40) = 0;
            }
            iVar4 = iVar4 + 1;
            iVar12 = iVar12 + 0x44;
          } while (iVar4 < (int)puVar11[0x13]);
        }
        puVar13 = (undefined4 *)(puVar11[0x16] + (int)puVar11);
        iVar4 = 0;
        if (0 < (int)puVar11[0x15]) {
          do {
            uVar5 = _LittleLong(*puVar13);
            *puVar13 = uVar5;
            uVar5 = _LittleLong(puVar13[1]);
            puVar13[1] = uVar5;
            uVar5 = _LittleLong(puVar13[2]);
            puVar13[2] = uVar5;
            iVar4 = iVar4 + 1;
            puVar13 = puVar13 + 3;
          } while (iVar4 < (int)puVar11[0x15]);
        }
        pfVar8 = (float *)(puVar11[0x18] + (int)puVar11);
        iVar4 = 0;
        if (0 < (int)puVar11[0x14]) {
          do {
            fVar15 = (float10)_LittleFloat(pfVar8);
            *pfVar8 = (float)fVar15;
            fVar15 = (float10)_LittleFloat(pfVar8 + 1);
            pfVar8[1] = (float)fVar15;
            iVar4 = iVar4 + 1;
            pfVar8 = pfVar8 + 2;
            iVar9 = param_5;
          } while (iVar4 < (int)puVar11[0x14]);
        }
        puVar14 = (undefined2 *)(puVar11[0x19] + (int)puVar11);
        iVar4 = 0;
        if (0 < (int)(puVar11[0x14] * puVar11[0x12])) {
          do {
            uVar3 = _LittleShort(*puVar14);
            *puVar14 = uVar3;
            uVar3 = _LittleShort(puVar14[1]);
            puVar14[1] = uVar3;
            uVar3 = _LittleShort(puVar14[2]);
            puVar14[2] = uVar3;
            uVar3 = _LittleShort(puVar14[3]);
            puVar14[3] = uVar3;
            iVar4 = iVar4 + 1;
            puVar14 = puVar14 + 4;
          } while (iVar4 < (int)(puVar11[0x14] * puVar11[0x12]));
        }
        puVar11 = (undefined4 *)((int)puVar11 + puVar11[0x1a]);
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)(*(int *)(iVar2 + 0x50 + iVar9 * 4) + 0x54));
    }
    return 1;
  }
  (*__ri)(3,s_R_LoadMD3___s_has_no_frames_,param_6);
  return 0;
}



// ===========================================
// Function: _R_LoadMD4 @ 0000a2bb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
_R_LoadMD4(int param_1,int param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5)

{
  void *in_EAX;
  int iVar1;
  undefined4 *__dest;
  size_t __n;
  undefined4 uVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float *pfVar8;
  uint uVar9;
  float10 fVar10;
  int iVar11;
  int iStack_8;
  int iStack_4;
  
  iVar1 = _LittleLong(*(undefined4 *)((int)in_EAX + 4));
  if (iVar1 != 1) {
    (*__ri)(3,s_R_LoadMD4___s_has_wrong_version_,param_2,iVar1,1);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 3;
  iVar1 = _LittleLong(*(undefined4 *)((int)in_EAX + 0x5c));
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + iVar1;
  __dest = (undefined4 *)(*__R_FindShader)(iVar1);
  *(undefined4 **)(param_1 + 0x5c) = __dest;
  __n = _LittleLong(*(undefined4 *)((int)in_EAX + 0x5c));
  _memcpy(__dest,in_EAX,__n);
  uVar2 = _LittleLong(*__dest);
  *__dest = uVar2;
  uVar2 = _LittleLong(__dest[1]);
  __dest[1] = uVar2;
  uVar2 = _LittleLong(__dest[0x12]);
  __dest[0x12] = uVar2;
  uVar2 = _LittleLong(__dest[0x13]);
  __dest[0x13] = uVar2;
  uVar2 = _LittleLong(__dest[0x15]);
  __dest[0x15] = uVar2;
  uVar2 = _LittleLong(__dest[0x14]);
  __dest[0x14] = uVar2;
  uVar2 = _LittleLong(__dest[0x16]);
  __dest[0x16] = uVar2;
  uVar2 = _LittleLong(__dest[0x17]);
  __dest[0x17] = uVar2;
  if (0 < (int)__dest[0x12]) {
    iVar1 = __dest[0x13];
    iStack_8 = 0;
    if (0 < (int)__dest[0x12]) {
      iStack_4 = 0;
      do {
        iVar5 = __dest[0x14] + iStack_4;
        pfVar8 = (float *)((int)__dest + iVar5 + 0x24);
        fVar10 = (float10)_LittleFloat(pfVar8);
        *pfVar8 = (float)fVar10;
        pfVar8 = (float *)((int)__dest + iVar5 + 0x18);
        iVar11 = 3;
        do {
          fVar10 = (float10)_LittleFloat(pfVar8 + -6);
          pfVar8[-6] = (float)fVar10;
          fVar10 = (float10)_LittleFloat(pfVar8 + -3);
          pfVar8[-3] = (float)fVar10;
          fVar10 = (float10)_LittleFloat(pfVar8);
          *pfVar8 = (float)fVar10;
          pfVar8 = pfVar8 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        uVar9 = 0;
        if ((__dest[0x13] * 3 & 0xfffffffU) != 0) {
          pfVar8 = (float *)((int)__dest + iVar5 + 0x38);
          do {
            fVar10 = (float10)_LittleFloat(pfVar8);
            *pfVar8 = (float)fVar10;
            uVar9 = uVar9 + 1;
            pfVar8 = pfVar8 + 1;
          } while (uVar9 < (uint)(__dest[0x13] * 0x30) >> 2);
        }
        iStack_4 = iStack_4 + iVar1 * 0x30 + 0x38;
        iStack_8 = iStack_8 + 1;
      } while (iStack_8 < (int)__dest[0x12]);
    }
    piVar3 = (int *)(__dest[0x16] + (int)__dest);
    if (0 < (int)__dest[0x15]) {
      do {
        puVar6 = (undefined4 *)(piVar3[1] + (int)piVar3);
        iStack_8 = 0;
        if (0 < *piVar3) {
          do {
            uVar2 = _LittleLong(*puVar6);
            *puVar6 = uVar2;
            uVar2 = _LittleLong(puVar6[0x25]);
            puVar6[0x25] = uVar2;
            uVar2 = _LittleLong(puVar6[0x26]);
            puVar6[0x26] = uVar2;
            uVar2 = _LittleLong(puVar6[0x23]);
            puVar6[0x23] = uVar2;
            uVar2 = _LittleLong(puVar6[0x24]);
            puVar6[0x24] = uVar2;
            uVar2 = _LittleLong(puVar6[0x29]);
            puVar6[0x29] = uVar2;
            if (30000 < (int)puVar6[0x23]) {
              (*_DAT_0000c274)(1,s_R_LoadMD3___s_has_more_than__i_v,param_5,&DAT_00007530,
                               puVar6[0x23]);
            }
            if (180000 < puVar6[0x25] * 3) {
              (*_DAT_0000c274)(1,s_R_LoadMD3___s_has_more_than__i_t,param_5,60000,puVar6[0x25]);
            }
            iVar1 = _R_FindShader(puVar6 + 0x11,0xffffffff,1,1,1);
            iVar11 = 0;
            if (*(int *)(iVar1 + 0x50) == 0) {
              puVar6[0x21] = *(undefined4 *)(iVar1 + 0x44);
            }
            else {
              puVar6[0x21] = 0;
            }
            puVar7 = (undefined4 *)(puVar6[0x26] + (int)puVar6);
            if (0 < (int)puVar6[0x25]) {
              do {
                uVar2 = _LittleLong(*puVar7);
                *puVar7 = uVar2;
                uVar2 = _LittleLong(puVar7[1]);
                puVar7[1] = uVar2;
                uVar2 = _LittleLong(puVar7[2]);
                puVar7[2] = uVar2;
                iVar11 = iVar11 + 1;
                puVar7 = puVar7 + 3;
              } while (iVar11 < (int)puVar6[0x25]);
            }
            iVar1 = puVar6[0x24] + (int)puVar6;
            param_2 = 0;
            if (0 < (int)puVar6[0x23]) {
              do {
                fVar10 = (float10)_LittleFloat((float *)(iVar1 + 0xc));
                *(float *)(iVar1 + 0xc) = (float)fVar10;
                fVar10 = (float10)_LittleFloat((float *)(iVar1 + 0x10));
                *(float *)(iVar1 + 0x10) = (float)fVar10;
                fVar10 = (float10)_LittleFloat((float *)(iVar1 + 0x14));
                *(float *)(iVar1 + 0x14) = (float)fVar10;
                fVar10 = (float10)_LittleFloat((float *)(iVar1 + 0x18));
                *(float *)(iVar1 + 0x18) = (float)fVar10;
                fVar10 = (float10)_LittleFloat((float *)(iVar1 + 0x1c));
                *(float *)(iVar1 + 0x1c) = (float)fVar10;
                iVar11 = _LittleLong(*(undefined4 *)(iVar1 + 0x20));
                *(int *)(iVar1 + 0x20) = iVar11;
                iVar5 = 0;
                if (0 < iVar11) {
                  pfVar8 = (float *)(iVar1 + 0x28);
                  do {
                    fVar4 = (float)_LittleLong(pfVar8[-1]);
                    pfVar8[-1] = fVar4;
                    fVar10 = (float10)_LittleFloat(pfVar8);
                    *pfVar8 = (float)fVar10;
                    fVar10 = (float10)_LittleFloat(pfVar8 + 1);
                    pfVar8[1] = (float)fVar10;
                    fVar10 = (float10)_LittleFloat(pfVar8 + 2);
                    pfVar8[2] = (float)fVar10;
                    fVar10 = (float10)_LittleFloat(pfVar8 + 3);
                    pfVar8[3] = (float)fVar10;
                    iVar5 = iVar5 + 1;
                    pfVar8 = pfVar8 + 5;
                    __dest = param_3;
                  } while (iVar5 < *(int *)(iVar1 + 0x20));
                }
                param_2 = param_2 + 1;
                iVar1 = iVar1 + 0x24 + *(int *)(iVar1 + 0x20) * 0x14;
              } while (param_2 < (int)puVar6[0x23]);
            }
            puVar6 = (undefined4 *)((int)puVar6 + puVar6[0x29]);
            iStack_8 = iStack_8 + 1;
          } while (iStack_8 < *piVar3);
        }
        piVar3 = (int *)((int)piVar3 + piVar3[2]);
      } while (iStack_8 + 1 < (int)__dest[0x15]);
    }
    return 1;
  }
  (*__ri)(3,s_R_LoadMD4___s_has_no_frames_,param_5);
  return 0;
}



// ===========================================
// Function: _RE_BeginRegistration @ 0000a6eb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_BeginRegistration(void *param_1)

{
  int *piVar1;
  int iVar2;
  
  _R_SyncRenderThread();
  iVar2 = 1;
  if (1 < _DAT_000201f0) {
    piVar1 = (int *)&DAT_0000d060;
    do {
      if (((char)piVar1[-0x10] != '\0') && (*piVar1 != 5)) {
        _memset(piVar1 + -0x10,0,0x70);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x1c;
    } while (iVar2 < _DAT_000201f0);
  }
  (*_DAT_0000c27c)();
  _memcpy(param_1,&_glConfig,0x1448);
  _r_sequencenumber = _r_sequencenumber + 1;
  _r_registration_active = 1;
  _DAT_0000cf4c = 0xffffffff;
  _R_ClearFlares();
  _RE_ClearScene();
  _R_SetupShaders();
  _R_InitLensFlare();
  __tr = 1;
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _RE_EndRegistration @ 0000a788
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_EndRegistration(void)

{
  int iVar1;
  int *piVar2;
  
  _r_registration_active = 0;
  _R_SyncRenderThread();
  iVar1 = 1;
  _RB_ShowImages(1);
  if (1 < _DAT_000201f0) {
    piVar2 = (int *)&DAT_0000d08c;
    do {
      if ((((char)piVar2[-0x1b] != '\0') && (*piVar2 != _r_sequencenumber)) && (*piVar2 != -1)) {
        if (piVar2[-0xb] == 5) {
          (*_DAT_0000c2e4)(piVar2[-3]);
        }
        _memset(piVar2 + -0x1b,0,0x70);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x1c;
    } while (iVar1 < _DAT_000201f0);
  }
  _R_FreeUnusedImages();
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _R_ModelInit @ 0000a809
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ModelInit(void)

{
  char *pcVar1;
  
  _DAT_000201f0 = 0;
  pcVar1 = (char *)_R_AllocModel();
  *(undefined4 *)pcVar1 = s____BAD_MODEL___._0_4_;
  *(undefined4 *)(pcVar1 + 4) = s____BAD_MODEL___._4_4_;
  *(undefined4 *)(pcVar1 + 8) = s____BAD_MODEL___._8_4_;
  *(undefined4 *)(pcVar1 + 0xc) = s____BAD_MODEL___._12_4_;
  pcVar1[0x40] = '\0';
  pcVar1[0x41] = '\0';
  pcVar1[0x42] = '\0';
  pcVar1[0x43] = '\0';
  return;
}



// ===========================================
// Function: _R_Modellist_f @ 0000a843
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Modellist_f(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar3 = 1;
  iVar5 = 0;
  if (1 < _DAT_000201f0) {
    piVar4 = (int *)&DAT_0000d074;
    do {
      iVar1 = *piVar4;
      iVar2 = 1;
      if ((iVar1 != 0) && (iVar1 != piVar4[-1])) {
        iVar2 = 2;
      }
      if ((piVar4[1] != 0) && (piVar4[1] != iVar1)) {
        iVar2 = iVar2 + 1;
      }
      (*__ri)(0,s__8i_____i___s_,piVar4[-3],iVar2,piVar4 + -0x15);
      iVar5 = iVar5 + piVar4[-3];
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x1c;
    } while (iVar3 < _DAT_000201f0);
  }
  (*__ri)(0,s__8i___Total_models_,iVar5);
  return;
}



// ===========================================
// Function: _R_GetTag @ 0000a8b8
// ===========================================

byte * __thiscall _R_GetTag(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  
  if (*(int *)(in_EAX + 0x4c) <= param_1) {
    param_1 = *(int *)(in_EAX + 0x4c) + -1;
  }
  iVar2 = *(int *)(in_EAX + 0x50);
  iVar5 = 0;
  pbVar6 = (byte *)(iVar2 * param_1 * 0x70 + *(int *)(in_EAX + 0x60) + in_EAX);
  pbVar4 = param_2;
  pbVar7 = pbVar6;
  if (0 < iVar2) {
LAB_0000a8e8:
    do {
      bVar1 = *pbVar6;
      bVar8 = bVar1 < *pbVar4;
      if (bVar1 == *pbVar4) {
        if (bVar1 != 0) {
          bVar1 = pbVar6[1];
          bVar8 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_0000a908;
          pbVar6 = pbVar6 + 2;
          pbVar4 = pbVar4 + 2;
          if (bVar1 != 0) goto LAB_0000a8e8;
        }
        iVar3 = 0;
      }
      else {
LAB_0000a908:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (iVar3 == 0) {
        return pbVar7;
      }
      iVar5 = iVar5 + 1;
      pbVar6 = pbVar7 + 0x70;
      pbVar4 = param_2;
      pbVar7 = pbVar6;
    } while (iVar5 < iVar2);
  }
  return (byte *)0x0;
}



// ===========================================
// Function: _R_LerpTag @ 0000a927
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LerpTag(float *param_1,int param_2,undefined4 param_3,undefined4 param_4,float param_5,
               undefined4 param_6)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 < 1) || (_DAT_000201f0 <= param_2)) {
    puVar2 = &DAT_0000cfb0;
  }
  else {
    puVar2 = &DAT_0000cfb0 + param_2 * 0x70;
  }
  if (*(int *)(puVar2 + 0x50) == 0) {
    _AxisClear(param_1 + 3);
    param_1[2] = 0.0;
    param_1[1] = 0.0;
    *param_1 = 0.0;
    return;
  }
  iVar3 = _R_GetTag(param_6);
  iVar4 = _R_GetTag(param_6);
  if ((iVar3 != 0) && (iVar4 != 0)) {
    fVar1 = 1.0 - param_5;
    *param_1 = *(float *)(iVar4 + 0x40) * param_5 + fVar1 * *(float *)(iVar3 + 0x40);
    param_1[3] = *(float *)(iVar4 + 0x4c) * param_5 + *(float *)(iVar3 + 0x4c) * fVar1;
    param_1[6] = *(float *)(iVar4 + 0x58) * param_5 + *(float *)(iVar3 + 0x58) * fVar1;
    param_1[9] = *(float *)(iVar4 + 100) * param_5 + *(float *)(iVar3 + 100) * fVar1;
    param_1[1] = *(float *)(iVar4 + 0x44) * param_5 + *(float *)(iVar3 + 0x44) * fVar1;
    param_1[4] = *(float *)(iVar4 + 0x50) * param_5 + *(float *)(iVar3 + 0x50) * fVar1;
    param_1[7] = *(float *)(iVar4 + 0x5c) * param_5 + *(float *)(iVar3 + 0x5c) * fVar1;
    param_1[10] = *(float *)(iVar4 + 0x68) * param_5 + *(float *)(iVar3 + 0x68) * fVar1;
    param_1[2] = *(float *)(iVar4 + 0x48) * param_5 + *(float *)(iVar3 + 0x48) * fVar1;
    param_1[5] = *(float *)(iVar4 + 0x54) * param_5 + *(float *)(iVar3 + 0x54) * fVar1;
    param_1[8] = *(float *)(iVar4 + 0x60) * param_5 + *(float *)(iVar3 + 0x60) * fVar1;
    param_1[0xb] = fVar1 * *(float *)(iVar3 + 0x6c) + *(float *)(iVar4 + 0x6c) * param_5;
    _VectorNormalize(param_1 + 3);
    _VectorNormalize(param_1 + 6);
    _VectorNormalize(param_1 + 9);
    return;
  }
  _AxisClear(param_1 + 3);
  param_1[2] = 0.0;
  param_1[1] = 0.0;
  *param_1 = 0.0;
  return;
}



// ===========================================
// Function: _R_ModelBounds @ 0000aaad
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _R_ModelBounds(undefined4 param_1,int param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined1 *puVar5;
  int iVar6;
  
  if ((param_2 < 1) || (_DAT_000201f0 <= param_2)) {
    puVar5 = &DAT_0000cfb0;
  }
  else {
    puVar5 = &DAT_0000cfb0 + param_2 * 0x70;
  }
  if (*(float **)(puVar5 + 0x4c) != (float *)0x0) {
    *param_3 = **(float **)(puVar5 + 0x4c);
    param_3[1] = *(float *)(*(int *)(puVar5 + 0x4c) + 4);
    param_3[2] = *(float *)(*(int *)(puVar5 + 0x4c) + 8);
    *param_4 = *(float *)(*(int *)(puVar5 + 0x4c) + 0xc);
    param_4[1] = *(float *)(*(int *)(puVar5 + 0x4c) + 0x10);
    param_4[2] = *(float *)(*(int *)(puVar5 + 0x4c) + 0x14);
    return;
  }
  if (*(int *)(puVar5 + 0x40) == 5) {
    (*_DAT_0000c2ec)(*(undefined4 *)(puVar5 + 0x60),0x3f800000,param_3,param_4,param_1);
    return;
  }
  if (*(int *)(puVar5 + 0x40) == 6) {
    pfVar1 = *(float **)(puVar5 + 100);
    fVar3 = pfVar1[4] * *pfVar1 * (float)___real_3fe0000000000000;
    fVar4 = pfVar1[1] * pfVar1[4] * (float)___real_3fe0000000000000;
    *param_3 = -fVar3;
    param_3[1] = -fVar4;
    param_3[2] = 0.0;
    *param_4 = fVar3;
    param_4[1] = fVar4;
    param_4[2] = 0.0;
    return;
  }
  iVar2 = *(int *)(puVar5 + 0x50);
  if (iVar2 == 0) {
    param_3[2] = 0.0;
    param_3[1] = 0.0;
    *param_3 = 0.0;
    param_4[2] = 0.0;
    param_4[1] = 0.0;
    *param_4 = 0.0;
    return;
  }
  iVar6 = *(int *)(iVar2 + 0x5c) + iVar2;
  *param_3 = *(float *)(*(int *)(iVar2 + 0x5c) + iVar2);
  param_3[1] = *(float *)(iVar6 + 4);
  param_3[2] = *(float *)(iVar6 + 8);
  *param_4 = *(float *)(iVar6 + 0xc);
  param_4[1] = *(float *)(iVar6 + 0x10);
  param_4[2] = *(float *)(iVar6 + 0x14);
  return;
}



// ===========================================
// Function: _R_ModelRadius @ 0000abdd
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _R_ModelRadius(float param_1)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 local_4;
  
  if (((int)param_1 < 1) || (_DAT_000201f0 <= (int)param_1)) {
    puVar5 = &DAT_0000cfb0;
  }
  else {
    puVar5 = &DAT_0000cfb0 + (int)param_1 * 0x70;
  }
  puVar2 = *(undefined4 **)(puVar5 + 0x4c);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(puVar5 + 0x40) == 5) {
                    /* WARNING: Could not recover jumptable at 0x0000ac43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      fVar9 = (float10)(*__R_FreeUnusedImages)();
      return fVar9;
    }
    if (*(int *)(puVar5 + 0x40) == 6) {
      pfVar3 = *(float **)(puVar5 + 100);
      fVar9 = (float10)(*pfVar3 * pfVar3[4] * (float)___real_3fe0000000000000);
      fVar8 = (float10)(pfVar3[1] * pfVar3[4] * (float)___real_3fe0000000000000);
      if (fVar8 < fVar9 == (NAN(fVar8) || NAN(fVar9))) {
        return fVar8;
      }
      return fVar9;
    }
    iVar4 = *(int *)(puVar5 + 0x50);
    if (iVar4 == 0) {
      return (float10)0;
    }
    iVar6 = *(int *)(iVar4 + 0x5c) + iVar4;
    local_18[0] = *(undefined4 *)(*(int *)(iVar4 + 0x5c) + iVar4);
    local_18[1] = *(undefined4 *)(iVar6 + 4);
    local_18[2] = *(undefined4 *)(iVar6 + 8);
    local_18[3] = *(undefined4 *)(iVar6 + 0xc);
    local_8 = *(undefined4 *)(iVar6 + 0x10);
    local_4 = *(undefined4 *)(iVar6 + 0x14);
  }
  else {
    local_18[0] = *puVar2;
    local_18[1] = puVar2[1];
    local_18[2] = puVar2[2];
    local_18[3] = puVar2[3];
    local_8 = puVar2[4];
    local_4 = puVar2[5];
  }
  uVar7 = 0;
  param_1 = 0.0;
  do {
    local_24 = local_18[(uVar7 & 1) * 3];
    local_20 = local_18[(uVar7 >> 1 & 1) * 3 + 1];
    local_1c = local_18[(uVar7 >> 2 & 1) * 3 + 2];
    fVar9 = (float10)_VectorLength(&local_24);
    fVar1 = (float)fVar9;
    if (param_1 < fVar1 != (NAN(param_1) || NAN(fVar1))) {
      param_1 = fVar1;
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 8);
  return (float10)param_1;
}



// ===========================================
// Function: _TIKI_GetHandle @ 0000ad42
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _TIKI_GetHandle(int param_1)

{
  undefined1 *puVar1;
  
  if ((param_1 < 1) || (_DAT_000201f0 <= param_1)) {
    puVar1 = &DAT_0000cfb0;
  }
  else {
    puVar1 = &DAT_0000cfb0 + param_1 * 0x70;
    if (puVar1 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
  }
  if (*(int *)(puVar1 + 0x40) != 5) {
    return 0xffffffff;
  }
  return *(undefined4 *)(puVar1 + 0x60);
}



// ===========================================
// Function: _RE_RegisterModel @ 0000ad74
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * _RE_RegisterModel(byte *param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  char *pcVar11;
  byte *pbVar12;
  byte *pbVar13;
  char *pcVar14;
  uint uVar15;
  bool bVar16;
  int iStack_460;
  undefined4 *puStack_45c;
  char *pcStack_458;
  int local_454;
  int iStack_450;
  int iStack_44c;
  char acStack_448 [79];
  char cStack_3f9;
  char acStack_3f8 [8];
  char acStack_3f0 [1008];
  
  if ((param_1 == (byte *)0x0) || (*param_1 == 0)) {
    (*__ri)(0,s_RE_RegisterModel__NULL_name_);
    return (char *)0x0;
  }
  pbVar3 = param_1;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (bVar1 != 0);
  if (0x3f < (uint)((int)pbVar3 - (int)(param_1 + 1))) {
    _Com_Printf(s_Model_name_exceeds_MAX_QPATH_);
    return (char *)0x0;
  }
  uVar15 = 1;
  if (1 < _DAT_000201f0) {
    pbVar12 = &DAT_0000d020;
    pbVar3 = param_1;
    pbVar13 = pbVar12;
LAB_0000add8:
    do {
      bVar1 = *pbVar12;
      bVar16 = bVar1 < *pbVar3;
      if (bVar1 == *pbVar3) {
        if (bVar1 != 0) {
          bVar1 = pbVar12[1];
          bVar16 = bVar1 < pbVar3[1];
          if (bVar1 != pbVar3[1]) goto LAB_0000adf8;
          pbVar12 = pbVar12 + 2;
          pbVar3 = pbVar3 + 2;
          if (bVar1 != 0) goto LAB_0000add8;
        }
        iVar4 = 0;
      }
      else {
LAB_0000adf8:
        iVar4 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
      }
      if (iVar4 == 0) {
        if ((_r_registration_active != 0) && (*(int *)(pbVar13 + 0x6c) != _r_sequencenumber)) {
          _R_CacheModel(pbVar13);
        }
        return (char *)(-(uint)(*(int *)(pbVar13 + 0x40) != 0) & uVar15);
      }
      uVar15 = uVar15 + 1;
      pbVar12 = pbVar13 + 0x70;
      pbVar3 = param_1;
      pbVar13 = pbVar12;
    } while ((int)uVar15 < _DAT_000201f0);
  }
  iVar4 = _R_AllocModel();
  local_454 = iVar4;
  if (iVar4 == 0) {
    (*__ri)(3,s_RE_RegisterModel__R_AllocModel__,param_1);
    return (char *)0x0;
  }
  _Q_strncpyz(iVar4,param_1,0x40);
  _R_SyncRenderThread();
  pcVar14 = *(char **)(iVar4 + 0x44);
  *(int *)(iVar4 + 0x6c) = _r_sequencenumber;
  pcVar5 = _strrchr((char *)param_1,0x2e);
  if ((pcVar5 != (char *)0x0) && (pcVar5 = pcVar5 + 1, pcVar5 != (char *)0x0)) {
    iVar6 = _Q_stricmp(pcVar5,s_spr);
    if (iVar6 == 0) {
      uVar7 = _SPR_RegisterSprite(param_1);
      *(undefined4 *)(iVar4 + 100) = uVar7;
      iVar6 = iVar4 - (int)param_1;
      do {
        bVar1 = *param_1;
        param_1[iVar6] = bVar1;
        param_1 = param_1 + 1;
      } while (bVar1 != 0);
      if (*(int *)(iVar4 + 100) != 0) {
        *(undefined4 *)(iVar4 + 0x48) = 0;
        *(undefined4 *)(iVar4 + 0x40) = 6;
        _GLimp_Suspend();
        return pcVar14;
      }
      goto _fail_88218;
    }
    iVar6 = _Q_stricmp(pcVar5,s_tik);
    if (iVar6 == 0) {
      uVar7 = (*__R_SyncRenderThread)(param_1);
      *(undefined4 *)(iVar4 + 0x60) = uVar7;
      iVar6 = iVar4 - (int)param_1;
      do {
        bVar1 = *param_1;
        param_1[iVar6] = bVar1;
        param_1 = param_1 + 1;
      } while (bVar1 != 0);
      if (-1 < *(int *)(iVar4 + 0x60)) {
        local_454 = (*__glConfig)(*(int *)(iVar4 + 0x60));
        if ((local_454 != 0) && (iStack_450 = 0, 0 < *(int *)(local_454 + 0x80))) {
          iStack_460 = 0;
          do {
            iVar4 = 0;
            pcVar14 = (char *)(*(int *)(local_454 + 0xa0) + iStack_460 + local_454);
            if (0 < *(int *)(pcVar14 + 0x150)) {
              pcVar5 = pcVar14 + 0x140;
              pcVar11 = pcVar14;
              do {
                pcVar11 = pcVar11 + 0x40;
                if (*pcVar11 == '\0') {
                  pcVar5[0] = '\0';
                  pcVar5[1] = '\0';
                  pcVar5[2] = '\0';
                  pcVar5[3] = '\0';
                }
                else {
                  iVar6 = _R_FindShader(pcVar11,0xffffffff,(*(uint *)(pcVar14 + 0x154) & 0x100) == 0
                                        ,(*(uint *)(pcVar14 + 0x154) & 0x200) == 0,1);
                  *(undefined4 *)pcVar5 = *(undefined4 *)(iVar6 + 0x44);
                }
                iVar4 = iVar4 + 1;
                pcVar5 = pcVar5 + 4;
              } while (iVar4 < *(int *)(pcVar14 + 0x150));
            }
            iStack_460 = iStack_460 + 0x15c;
            iStack_450 = iStack_450 + 1;
            pcVar14 = pcStack_458;
            iVar4 = iStack_44c;
          } while (iStack_450 < *(int *)(local_454 + 0x80));
        }
        *(undefined4 *)(iVar4 + 0x40) = 5;
        *(undefined4 *)(iVar4 + 0x48) = 0;
        _GLimp_Suspend();
        return pcVar14;
      }
      goto _fail_88218;
    }
  }
  *(undefined4 *)(iVar4 + 0x68) = 0;
  iStack_460 = 0;
  iVar6 = 2;
  pcStack_458 = acStack_3f8 + -(int)param_1;
  pbVar3 = param_1;
  do {
    do {
      bVar1 = *pbVar3;
      pbVar3[(int)pcStack_458] = bVar1;
      pbVar3 = pbVar3 + 1;
    } while (bVar1 != 0);
    if (iVar6 != 0) {
      pcVar14 = _strrchr(acStack_3f8,0x2e);
      if (pcVar14 != (char *)0x0) {
        pcVar14 = _strrchr(acStack_3f0,0x2e);
        *pcVar14 = '\0';
      }
      _sprintf((char *)&iStack_450,s___d_md3);
      pcVar14 = acStack_448;
      do {
        cVar2 = *pcVar14;
        pcVar14 = pcVar14 + 1;
      } while (cVar2 != '\0');
      uVar15 = (int)pcVar14 - (int)acStack_448;
      pcVar14 = &cStack_3f9;
      do {
        pcVar5 = pcVar14 + 1;
        pcVar14 = pcVar14 + 1;
      } while (*pcVar5 != '\0');
      pcVar5 = acStack_448;
      for (uVar10 = uVar15 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      for (uVar15 = uVar15 & 3; iVar4 = iStack_44c, uVar15 != 0; uVar15 = uVar15 - 1) {
        *pcVar14 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar14 = pcVar14 + 1;
      }
    }
    (*__R_SetupShaders)(acStack_3f8,&puStack_45c);
    if (puStack_45c != (undefined4 *)0x0) {
      __loadmodel = iVar4;
      iVar8 = _LittleLong(*puStack_45c);
      if (iVar8 == 0x34504449) {
        iVar8 = _R_LoadMD4();
        iVar6 = 3;
      }
      else {
        if (iVar8 != 0x33504449) {
          (*__ri)(3,s_RE_RegisterModel__unknown_fileid,param_1);
          goto _fail_88218;
        }
        iVar8 = _R_LoadMD3(iVar4,iVar6);
      }
      (*_DAT_0000c2cc)(puStack_45c);
      if (iVar8 == 0) {
        if (iVar6 == 0) goto _fail_88218;
        break;
      }
      *(int *)(iVar4 + 0x68) = *(int *)(iVar4 + 0x68) + 1;
      iStack_460 = iStack_460 + 1;
      if (iVar6 <= *(int *)(__r_lodbias + 0x20)) break;
    }
    iVar6 = iVar6 + -1;
    pbVar3 = param_1;
  } while (-1 < iVar6);
  if (iStack_460 != 0) {
    iVar6 = iVar6 + -1;
    if (-1 < iVar6) {
      puVar9 = (undefined4 *)(iVar4 + 0x50 + iVar6 * 4);
      do {
        *(int *)(iVar4 + 0x68) = *(int *)(iVar4 + 0x68) + 1;
        *puVar9 = puVar9[1];
        iVar6 = iVar6 + -1;
        puVar9 = puVar9 + -1;
      } while (-1 < iVar6);
    }
    _GLimp_Suspend();
    return *(char **)(iVar4 + 0x44);
  }
_fail_88218:
  *(undefined4 *)(iVar4 + 0x40) = 0;
  _GLimp_Suspend();
  return (char *)0x0;
}



// ===========================================
// Function: _TIKI_FlushAll @ 0000b1e2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _TIKI_FlushAll(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  char *__s;
  undefined1 auStackY_d0a0 [53236];
  undefined4 uStackY_ac;
  
  iVar3 = 1;
  if (1 < _DAT_000201f0) {
    __s = &DAT_0000d020;
    puVar4 = auStackY_d0a0;
    do {
      if ((*__s != '\0') && (pcVar2 = __s, *(int *)(__s + 0x40) == 5)) {
        do {
          cVar1 = *pcVar2;
          puVar4[(int)pcVar2] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        (*_DAT_0000c2e4)();
        uStackY_ac = 0xb235;
        _memset(__s,0,0x70);
        _RE_RegisterModel();
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + -0x70;
      __s = __s + 0x70;
    } while (iVar3 < _DAT_000201f0);
  }
  return;
}



