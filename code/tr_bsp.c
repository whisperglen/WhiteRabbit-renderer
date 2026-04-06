// ===========================================
// Function: _HSVtoRGB @ 0000c100
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _HSVtoRGB(float param_1,undefined4 param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *unaff_ESI;
  
  _floor((double)(param_1 * (float)___real_4014000000000000));
  iVar4 = __ftol2_sse();
  fVar3 = param_5 * (1.0 - param_4);
  fVar2 = (1.0 - (param_3 - (float)iVar4) * param_4) * param_5;
  fVar1 = param_5 * (1.0 - (1.0 - (param_3 - (float)iVar4)) * param_4);
  switch(iVar4) {
  case 0:
    *unaff_ESI = param_5;
    unaff_ESI[1] = fVar1;
    unaff_ESI[2] = fVar3;
    return;
  case 1:
    *unaff_ESI = fVar2;
    unaff_ESI[1] = param_5;
    unaff_ESI[2] = fVar3;
    return;
  case 2:
    *unaff_ESI = fVar3;
    unaff_ESI[1] = param_5;
    unaff_ESI[2] = fVar1;
    return;
  case 3:
    *unaff_ESI = fVar3;
    unaff_ESI[1] = fVar2;
    unaff_ESI[2] = param_5;
    return;
  case 4:
    *unaff_ESI = fVar1;
    unaff_ESI[1] = fVar3;
    unaff_ESI[2] = param_5;
    return;
  case 5:
    *unaff_ESI = param_5;
    unaff_ESI[1] = fVar3;
    unaff_ESI[2] = fVar2;
    return;
  default:
    return;
  }
}



// ===========================================
// Function: _R_ColorShiftLightingBytes @ 0000c200
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ColorShiftLightingBytes(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *unaff_ESI;
  undefined1 *unaff_EDI;
  
  bVar2 = (byte)_DAT_000107ac;
  uVar4 = (uint)unaff_ESI[2] << (bVar2 & 0x1f);
  uVar1 = (uint)unaff_ESI[1] << (bVar2 & 0x1f);
  uVar5 = (uint)*unaff_ESI << (bVar2 & 0x1f);
  if (0xff < (int)(uVar4 | uVar1 | uVar5)) {
    uVar3 = uVar5;
    if ((int)uVar5 <= (int)uVar1) {
      uVar3 = uVar1;
    }
    if ((int)uVar3 <= (int)uVar4) {
      uVar3 = uVar4;
    }
    uVar5 = (int)(uVar5 * 0xff) / (int)uVar3;
    uVar1 = (int)(uVar1 * 0xff) / (int)uVar3;
    uVar4 = (int)(uVar4 * 0xff) / (int)uVar3;
  }
  *unaff_EDI = (char)uVar5;
  unaff_EDI[1] = (char)uVar1;
  unaff_EDI[2] = (char)uVar4;
  unaff_EDI[3] = unaff_ESI[3];
  return;
}



// ===========================================
// Function: _R_LoadLightmaps @ 0000c289
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _R_LoadLightmaps(int *param_1)

{
  double dVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  float fStack_1005c;
  undefined1 uStack_10058;
  int iStack_10054;
  float fStack_10050;
  float fStack_1004c;
  float fStack_10048;
  float fStack_10044;
  undefined1 auStack_10040 [60];
  undefined1 auStack_10004 [65536];
  undefined4 uStack_4;
  
  uStack_4 = 0xc293;
  fStack_10050 = 0.0;
  iVar4 = 0;
  __memcpy = 0;
  if (param_1[1] != 0) {
    iStack_10054 = *param_1;
    _R_SyncRenderThread();
    __memcpy = param_1[1] / 0xc000;
    if ((*(int *)(__r_vertexLight + 0x20) == 0) && (_DAT_00011230 != 4)) {
      dVar1 = ___real_406fe00000000000;
      if (0 < __memcpy) {
        do {
          fVar2 = (float)dVar1;
          if (*(int *)(__r_lightmap + 0x20) == 2) {
            iVar7 = 0;
            pbVar5 = (byte *)(iStack_10054 + 2);
            do {
              fStack_1005c = (float)*pbVar5 * (float)___real_3fb020c4a0000000 +
                             (float)pbVar5[-2] * (float)___real_3fd51eb860000000 +
                             (float)pbVar5[-1] * (float)___real_3fe5eb851eb851ec;
              if (fStack_1005c <= fVar2) {
                fStack_1005c = fStack_1005c / fVar2;
              }
              else {
                fStack_1005c = 1.0;
              }
              if (fStack_10050 < fStack_1005c != (NAN(fStack_10050) || NAN(fStack_1005c))) {
                fStack_10050 = fStack_1005c;
              }
              _HSVtoRGB(fStack_1005c,0x3f800000,___real_3f000000);
              auStack_10004[iVar7 * 4 + 7] = 0xff;
              fVar2 = (float)___real_406fe00000000000;
              iVar7 = iVar7 + 1;
              pbVar5 = pbVar5 + 3;
              uStack_10058 = (undefined1)(int)ROUND(fStack_1004c * fVar2);
              auStack_10004[iVar7 * 4] = uStack_10058;
              uStack_10058 = (undefined1)(int)ROUND(fStack_10048 * fVar2);
              auStack_10004[iVar7 * 4 + 1] = uStack_10058;
              uStack_10058 = (undefined1)(int)ROUND(fStack_10044 * fVar2);
              auStack_10004[iVar7 * 4 + 2] = uStack_10058;
            } while (iVar7 < 0x4000);
          }
          else {
            do {
              iVar7 = 0;
              do {
                iVar6 = iVar7;
                _R_ColorShiftLightingBytes();
                auStack_10004[iVar6 * 4 + 7] = 0xff;
                iVar7 = iVar6 + 1;
              } while (iVar6 + 1 < 0x4000);
            } while (iVar6 + 2 < 0x4000);
          }
          _Com_sprintf(auStack_10040,0x40,s__lightmap_d,iVar4);
          uVar3 = _R_CreateImage(auStack_10040,auStack_10004 + 4,0x80,0x80,0,0,0,0,
                                 s_PARSE_ROOTDOCUMENT_000028f8 + 8);
          dVar1 = ___real_406fe00000000000;
          iStack_10054 = iStack_10054 + 0xc000;
          *(undefined4 *)(&DAT_0000fe44 + iVar4 * 4) = uVar3;
          iVar4 = iVar4 + 1;
        } while (iVar4 < __memcpy);
      }
      if (*(int *)(__r_lightmap + 0x20) == 2) {
        uVar3 = __ftol2_sse();
        (*__ri)(0,s_Brightest_lightmap_value___d_,uVar3);
        _GLimp_Suspend();
        return;
      }
    }
    _GLimp_Suspend();
  }
  return;
}



// ===========================================
// Function: _RE_SetWorldVisData @ 0000c534
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_SetWorldVisData(undefined4 param_1)

{
  _DAT_0000fe0c = param_1;
  return;
}



// ===========================================
// Function: _R_LoadVisibility @ 0000c53e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadVisibility(void)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  void *__dest;
  uint __n;
  
  __n = DAT_000020f0 + 0x3fU & 0xffffffc0;
  _DAT_000020fc = (void *)(*__Com_sprintf)(__n);
  _memset(_DAT_000020fc,0xff,__n);
  iVar1 = in_EAX[1];
  if (iVar1 != 0) {
    iVar2 = *in_EAX;
    DAT_000020f0 = _LittleLong();
    _DAT_000020f4 = _LittleLong(*(undefined4 *)(iVar2 + 4));
    if (_DAT_0000fe0c != 0) {
      _DAT_000020f8 = (void *)_DAT_0000fe0c;
      return;
    }
    __dest = (void *)(*__Com_sprintf)(iVar1 + -8);
    _memcpy(__dest,(void *)(iVar2 + 8),iVar1 - 8);
    _DAT_000020f8 = __dest;
  }
  return;
}



// ===========================================
// Function: _R_LoadSphereLights @ 0000c5c9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadSphereLights(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  float *pfVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float10 fVar7;
  uint local_8;
  
  uVar1 = (uint)param_1[1] / 0x3c;
  if ((uint)param_1[1] % 0x3c != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in_sphe,0x2000);
    return;
  }
  if (uVar1 < 0x5fd) {
    puVar6 = (undefined4 *)*param_1;
    if (uVar1 != 0) {
      puVar5 = (undefined4 *)&DAT_0005c188;
      local_8 = uVar1;
      do {
        pfVar4 = (float *)(puVar5 + 9);
        puVar5[-2] = *puVar6;
        param_1 = (undefined4 *)0x3;
        puVar5[-1] = puVar6[1];
        *puVar5 = puVar6[2];
        puVar5[1] = puVar6[3];
        puVar5[2] = puVar6[4];
        puVar5[3] = puVar6[5];
        *pfVar4 = (float)puVar6[10];
        puVar5[10] = puVar6[0xb];
        puVar5[0xb] = puVar6[0xc];
        do {
          fVar7 = (float10)_LittleFloat(pfVar4 + -0xb);
          pfVar4[-0xb] = (float)fVar7;
          fVar7 = (float10)_LittleFloat(pfVar4 + -8);
          pfVar4[-8] = (float)fVar7;
          fVar7 = (float10)_LittleFloat(pfVar4);
          *pfVar4 = (float)fVar7;
          pfVar4 = pfVar4 + 1;
          param_1 = (undefined4 *)((int)param_1 + -1);
        } while (param_1 != (undefined4 *)0x0);
        fVar7 = (float10)_LittleFloat(puVar6 + 0xd);
        puVar5[8] = (float)fVar7;
        fVar7 = (float10)_LittleFloat(puVar6 + 6);
        puVar5[4] = (float)fVar7;
        uVar2 = _LittleLong(puVar6[9]);
        puVar5[7] = uVar2;
        uVar2 = _LittleLong(puVar6[8]);
        puVar5[6] = uVar2;
        iVar3 = _LittleLong(puVar6[7]);
        puVar5[5] = DAT_000020a0 + (iVar3 + DAT_0000209c) * 0x48;
        fVar7 = (float10)_LittleFloat(puVar6 + 0xe);
        puVar5[0xc] = (float)fVar7;
        puVar5 = puVar5 + 0x10;
        puVar6 = puVar6 + 0xf;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
    _DAT_00074080 = uVar1;
    return;
  }
  (*_DAT_0000fdfc)(1,s_LoadMap__Too_many_spherelights_o,0x2000,0x5fc);
  return;
}



// ===========================================
// Function: _R_LoadSphereLightVis @ 0000c724
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadSphereLightVis(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((param_1[1] & 3U) != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in_sphe,0x2000);
    return;
  }
  uVar1 = (uint)param_1[1] >> 2;
  param_1 = (int *)*param_1;
  if ((uVar1 != 0) && (uVar1 != DAT_00002098 - DAT_0000209c)) {
    if ((__bigendian != 0) && (iVar5 = 0, uVar1 != 0)) {
      do {
        iVar2 = _LittleLong(param_1[iVar5]);
        param_1[iVar5] = iVar2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar1);
    }
    piVar4 = (int *)(DAT_000020a0 + DAT_0000209c * 0x48 + 0x38);
    do {
      iVar5 = 0;
      if (*param_1 == -1) {
LAB_0000c7bf:
        iVar5 = -1;
        param_1 = param_1 + 1;
      }
      else {
        do {
          iVar5 = iVar5 + 1;
        } while (param_1[iVar5] != -1);
        if (iVar5 == 0) goto LAB_0000c7bf;
        iVar2 = (*__Com_sprintf)(iVar5 * 0x40);
        *piVar4 = iVar2;
        piVar4[1] = iVar5;
        iVar5 = *param_1;
        iVar2 = 0;
        if (iVar5 != -1) {
          iVar3 = 0;
          do {
            iVar2 = iVar2 + 1;
            *(undefined1 **)(iVar3 + *piVar4) = &DAT_0005c180 + iVar5 * 0x40;
            iVar3 = iVar2 * 4;
            iVar5 = param_1[iVar2];
          } while (iVar5 != -1);
        }
        iVar5 = -1 - iVar2;
        param_1 = param_1 + iVar2 + 1;
      }
      uVar1 = uVar1 + iVar5;
      piVar4 = piVar4 + 0x12;
    } while (uVar1 != 0);
  }
  return;
}



// ===========================================
// Function: _ShaderForShaderNum @ 0000c819
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall _ShaderForShaderNum(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _LittleLong();
  if ((iVar1 < 0) || (DAT_00002084 <= iVar1)) {
    (*_DAT_0000fdfc)(1,s_ShaderForShaderNum__bad_num__i,iVar1);
  }
  if ((*(int *)(__r_vertexLight + 0x20) != 0) || (_DAT_00011230 == 4)) {
    param_1 = 0xfffffffd;
  }
  if ((*(int *)(__r_fullbright + 0x20) != 0) || (__memcpy == 0)) {
    param_1 = 0xfffffffe;
  }
  iVar1 = _R_FindShader(iVar1 * 0x4c + DAT_00002088,param_1,1,1,1);
  if (*(int *)(iVar1 + 0x50) != 0) {
    iVar1 = _DAT_0000fe2c;
  }
  return iVar1;
}



// ===========================================
// Function: _ParseFace @ 0000c8a0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ParseFace(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float10 fVar10;
  float *pfStack_10;
  int iStack_c;
  int iStack_8;
  
  _LittleLong(*(undefined4 *)(param_1 + 0x1c));
  iVar3 = _ShaderForShaderNum();
  *(int *)(param_3 + 4) = iVar3;
  if ((*(int *)(__r_singleShader + 0x20) != 0) && (*(int *)(iVar3 + 100) == 0)) {
    *(undefined4 *)(param_3 + 4) = _DAT_0000fe2c;
  }
  _CL_UpdateLoadingScreen();
  if ((*(byte *)(*(int *)(param_3 + 4) + 0x58) & 0x80) == 0) {
    iVar3 = _LittleLong(*(undefined4 *)(param_1 + 4));
    *(int *)(param_3 + 8) = iVar3 + 1;
    iStack_8 = _LittleLong(*(undefined4 *)(param_1 + 0x10));
    if (0x40 < iStack_8) {
      (*__ri)(3,s_WARNING__MAX_FACE_POINTS_exceede,iStack_8);
      iStack_8 = 0x40;
      *(undefined4 *)(param_3 + 4) = _DAT_0000fe2c;
    }
    iVar3 = _LittleLong(*(undefined4 *)(param_1 + 0x18));
    iVar7 = iStack_8 * 0x20 + 0x2c;
    puVar4 = (undefined4 *)(*__Com_sprintf)(iVar7 + iVar3 * 4);
    *puVar4 = 2;
    puVar4[8] = iStack_8;
    puVar4[9] = iVar3;
    puVar4[10] = iVar7;
    iVar7 = _LittleLong(*(undefined4 *)(param_1 + 0xc));
    if (0 < iStack_8) {
      pfStack_10 = (float *)(puVar4 + 0x10);
      iVar7 = param_2 + iVar7 * 0x2c + 0x28;
      do {
        pfVar6 = pfStack_10 + -5;
        iVar8 = iVar7 + -0x28;
        iStack_c = 3;
        do {
          fVar10 = (float10)_LittleFloat(iVar8);
          *pfVar6 = (float)fVar10;
          iVar8 = iVar8 + 4;
          pfVar6 = pfVar6 + 1;
          iStack_c = iStack_c + -1;
        } while (iStack_c != 0);
        iVar8 = iVar7 + -0x14;
        iStack_c = 2;
        pfVar6 = pfStack_10;
        do {
          fVar10 = (float10)_LittleFloat(iVar8 + -8);
          pfVar6[-2] = (float)fVar10;
          fVar10 = (float10)_LittleFloat(iVar8);
          *pfVar6 = (float)fVar10;
          iVar8 = iVar8 + 4;
          pfVar6 = pfVar6 + 1;
          iStack_c = iStack_c + -1;
        } while (iStack_c != 0);
        _R_ColorShiftLightingBytes();
        pfStack_10 = pfStack_10 + 8;
        iVar7 = iVar7 + 0x2c;
        iStack_8 = iStack_8 + -1;
      } while (iStack_8 != 0);
    }
    _CL_UpdateLoadingScreen();
    iVar7 = _LittleLong(*(undefined4 *)(param_1 + 0x14));
    iVar8 = 0;
    if (0 < iVar3) {
      do {
        iVar1 = iVar8 * 4;
        uVar5 = _LittleLong(*(undefined4 *)(iVar1 + param_4 + iVar7 * 4));
        iVar8 = iVar8 + 1;
        *(undefined4 *)(puVar4[10] + iVar1 + (int)puVar4) = uVar5;
      } while (iVar8 < iVar3);
    }
    pfVar6 = (float *)(puVar4 + 1);
    iVar3 = param_1 + 0x54;
    param_1 = 3;
    pfVar9 = pfVar6;
    do {
      fVar10 = (float10)_LittleFloat(iVar3);
      *pfVar9 = (float)fVar10;
      iVar3 = iVar3 + 4;
      pfVar9 = pfVar9 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    puVar4[4] = (float)puVar4[0xd] * (float)puVar4[3] +
                (float)puVar4[0xb] * *pfVar6 + (float)puVar4[0xc] * (float)puVar4[2];
    _SetPlaneSignbits(pfVar6);
    uVar2 = _PlaneTypeForNormal(pfVar6);
    *(undefined1 *)(puVar4 + 5) = uVar2;
    *(undefined4 **)(param_3 + 0xc) = puVar4;
    return;
  }
  *(undefined4 **)(param_3 + 0xc) = &`ParseFace'::`2'::skipData;
  return;
}



// ===========================================
// Function: _ParseMesh @ 0000cad9
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _ParseMesh(int param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float10 fVar6;
  float10 fVar7;
  float *pfStack_b03c;
  int iStack_b038;
  float afStack_b034 [6];
  undefined1 *puStack_b01c;
  int iStack_b018;
  int iStack_b014;
  int iStack_b010;
  float fStack_b00c;
  float fStack_b008;
  float fStack_b004;
  float afStack_b000 [5];
  undefined1 auStack_afec [45032];
  undefined4 uStack_4;
  
  uStack_4 = 0xcae3;
  _LittleLong(param_2[7]);
  iVar2 = _LittleLong(param_2[1]);
  *(int *)(param_3 + 8) = iVar2 + 1;
  iVar2 = _ShaderForShaderNum();
  *(int *)(param_3 + 4) = iVar2;
  if ((*(int *)(__r_singleShader + 0x20) != 0) && (*(int *)(iVar2 + 100) == 0)) {
    *(undefined4 *)(param_3 + 4) = _DAT_0000fe2c;
  }
  iVar2 = _LittleLong(*param_2);
  if ((*(byte *)(iVar2 * 0x4c + 0x40 + DAT_00002088) & 0x80) == 0) {
    iVar3 = _LittleLong(param_2[0x18]);
    iVar2 = _LittleLong(param_2[0x19]);
    iStack_b010 = iVar2;
    iVar4 = _LittleLong(param_2[3]);
    param_1 = param_1 + iVar4 * 0x2c;
    iStack_b038 = iVar2 * iVar3;
    if (0 < iStack_b038) {
      pfStack_b03c = afStack_b000;
      iStack_b014 = param_1 - (int)pfStack_b03c;
      iStack_b018 = (int)pfStack_b03c - param_1;
      puStack_b01c = auStack_afec + -param_1;
      param_1 = param_1 + 0x14;
      do {
        iVar2 = param_1 + 8;
        iVar4 = 3;
        pfVar5 = pfStack_b03c;
        do {
          fVar6 = (float10)_LittleFloat(iStack_b014 + (int)pfVar5);
          *pfVar5 = (float)fVar6;
          fVar6 = (float10)_LittleFloat(iVar2);
          pfVar5[7] = (float)fVar6;
          iVar2 = iVar2 + 4;
          pfVar5 = pfVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        pfVar5 = (float *)(iStack_b018 + param_1);
        iVar4 = 2;
        iVar2 = param_1;
        do {
          fVar6 = (float10)_LittleFloat(iVar2 + -8);
          pfVar5[-2] = (float)fVar6;
          fVar6 = (float10)_LittleFloat(iVar2);
          *pfVar5 = (float)fVar6;
          iVar2 = iVar2 + 4;
          pfVar5 = pfVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        _R_ColorShiftLightingBytes();
        pfStack_b03c = pfStack_b03c + 0xb;
        param_1 = param_1 + 0x2c;
        iStack_b038 = iStack_b038 + -1;
        iVar2 = iStack_b010;
      } while (iStack_b038 != 0);
    }
    _CL_UpdateLoadingScreen();
    fVar7 = (float10)_LittleFloat(param_2 + 0x1a);
    fVar6 = (float10)0;
    if ((NAN(fVar6) || NAN(fVar7)) == (fVar6 == fVar7)) {
      pfVar5 = afStack_b000;
      fVar6 = (float10)_LittleFloat(param_2 + 0x1a,pfVar5);
      fVar1 = (float)((float10)*(float *)(__r_subdivisions + 0x1c) *
                      (float10)___real_3fd0000000000000 * fVar6);
    }
    else {
      fVar7 = (float10)*(float *)(*(int *)(param_3 + 4) + 0xa8);
      if ((NAN(fVar6) || NAN(fVar7)) == (fVar6 == fVar7)) {
        fVar1 = *(float *)(__r_subdivisions + 0x1c) * (float)___real_3fd0000000000000 *
                *(float *)(*(int *)(param_3 + 4) + 0xa8);
      }
      else {
        fVar1 = *(float *)(__r_subdivisions + 0x1c);
      }
      pfVar5 = afStack_b000;
    }
    iVar2 = _R_SubdividePatchToGrid(iVar3,iVar2,fVar1,pfVar5);
    iVar3 = 0;
    *(int *)(param_3 + 0xc) = iVar2;
    param_2 = param_2 + 0x12;
    do {
      fVar6 = (float10)_LittleFloat(param_2 + -3);
      afStack_b034[iVar3] = (float)fVar6;
      fVar6 = (float10)_LittleFloat(param_2);
      afStack_b034[iVar3 + 3] = (float)fVar6;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar3 < 3);
    afStack_b034[3] = afStack_b034[0] + afStack_b034[3];
    afStack_b034[4] = afStack_b034[1] + afStack_b034[4];
    afStack_b034[5] = afStack_b034[2] + afStack_b034[5];
    fVar1 = (float)___real_3fe0000000000000;
    *(float *)(iVar2 + 0x34) = afStack_b034[3] * fVar1;
    *(float *)(iVar2 + 0x38) = afStack_b034[4] * fVar1;
    *(float *)(iVar2 + 0x3c) = afStack_b034[5] * fVar1;
    fStack_b00c = afStack_b034[0] - afStack_b034[3] * fVar1;
    fStack_b008 = afStack_b034[1] - *(float *)(iVar2 + 0x38);
    fStack_b004 = afStack_b034[2] - *(float *)(iVar2 + 0x3c);
    fVar6 = (float10)_VectorLength(&fStack_b00c);
    *(float *)(iVar2 + 0x40) = (float)fVar6;
    return;
  }
  *(undefined1 **)(param_3 + 0xc) = &`ParseMesh'::`2'::skipData;
  return;
}



// ===========================================
// Function: _ParseTriSurf @ 0000cdc0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ParseTriSurf(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  float10 fVar11;
  int iStack_28;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar3 = _LittleLong(*(undefined4 *)(param_1 + 4));
  *(int *)(param_3 + 8) = iVar3 + 1;
  iVar3 = _ShaderForShaderNum();
  *(int *)(param_3 + 4) = iVar3;
  if ((*(int *)(__r_singleShader + 0x20) != 0) && (*(int *)(iVar3 + 100) == 0)) {
    *(undefined4 *)(param_3 + 4) = _DAT_0000fe2c;
  }
  iVar3 = _LittleLong(*(undefined4 *)(param_1 + 0x10));
  iVar4 = _LittleLong(*(undefined4 *)(param_1 + 0x18));
  puVar5 = (undefined4 *)(*__Com_sprintf)((iVar3 * 0xb + iVar4) * 4 + 0x44);
  puVar5[0x10] = puVar5 + 0x11;
  puVar5[0xe] = puVar5 + 0x11 + iVar3 * 0xb;
  *puVar5 = 4;
  puVar5[0xf] = iVar3;
  puVar5[0xd] = iVar4;
  *(undefined4 **)(param_3 + 0xc) = puVar5;
  _ClearBounds(puVar5 + 3,puVar5 + 6);
  iVar6 = _LittleLong(*(undefined4 *)(param_1 + 0xc));
  param_2 = param_2 + iVar6 * 0x2c;
  if (0 < iVar3) {
    iVar6 = -param_2;
    puVar8 = (undefined4 *)(param_2 + 0x14);
    iStack_28 = iVar3;
    do {
      iVar10 = (8 - param_2) + (int)puVar8;
      puVar9 = puVar8 + 2;
      param_3 = 3;
      do {
        fVar11 = (float10)_LittleFloat(puVar9 + -7);
        *(float *)(puVar5[0x10] + (-0x1c - param_2) + (int)puVar9) = (float)fVar11;
        fVar11 = (float10)_LittleFloat(puVar9);
        *(float *)(iVar10 + puVar5[0x10]) = (float)fVar11;
        iVar10 = iVar10 + 4;
        puVar9 = puVar9 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      _AddPointToBounds((int)puVar8 + puVar5[0x10] + iVar6 + -0x14,puVar5 + 3,puVar5 + 6);
      iVar10 = (-8 - param_2) + (int)puVar8;
      param_3 = 2;
      do {
        fVar11 = (float10)_LittleFloat(iVar10 + param_2);
        *(float *)(iVar10 + puVar5[0x10]) = (float)fVar11;
        iVar10 = iVar10 + 4;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      uVar7 = _LittleLong(*puVar8);
      *(undefined4 *)((int)puVar8 + puVar5[0x10] + iVar6) = uVar7;
      fVar11 = (float10)_LittleFloat(puVar8 + 1);
      *(float *)((int)puVar8 + puVar5[0x10] + iVar6 + 4) = (float)fVar11;
      _R_ColorShiftLightingBytes();
      puVar8 = puVar8 + 0xb;
      iStack_28 = iStack_28 + -1;
    } while (iStack_28 != 0);
  }
  _CL_UpdateLoadingScreen();
  fStack_c = (float)puVar5[6] - (float)puVar5[3];
  fStack_8 = (float)puVar5[7] - (float)puVar5[4];
  fStack_4 = (float)puVar5[8] - (float)puVar5[5];
  fVar2 = (float)___real_3fe0000000000000;
  puVar5[9] = (float)puVar5[3] + fStack_c * fVar2;
  puVar5[10] = fStack_8 * fVar2 + (float)puVar5[4];
  puVar5[0xb] = fVar2 * fStack_4 + (float)puVar5[5];
  fVar11 = (float10)_VectorLength(&fStack_c);
  puVar5[0xc] = (float)fVar11;
  iVar6 = _LittleLong(*(undefined4 *)(param_1 + 0x14));
  iVar10 = 0;
  if (0 < iVar4) {
    do {
      uVar7 = _LittleLong(*(undefined4 *)(param_4 + iVar6 * 4 + iVar10 * 4));
      *(undefined4 *)(puVar5[0xe] + iVar10 * 4) = uVar7;
      iVar1 = *(int *)(puVar5[0xe] + iVar10 * 4);
      if ((iVar1 < 0) || (iVar3 <= iVar1)) {
        (*_DAT_0000fdfc)(1,s_Bad_index_in_triangle_surface);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar4);
  }
  return;
}



// ===========================================
// Function: _ParseFlare @ 0000d066
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _ParseFlare(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  float *pfVar3;
  float10 fVar4;
  
  iVar1 = _LittleLong(*(undefined4 *)(param_1 + 4));
  *(int *)(in_EAX + 8) = iVar1 + 1;
  iVar1 = _ShaderForShaderNum();
  *(int *)(in_EAX + 4) = iVar1;
  if ((*(int *)(__r_singleShader + 0x20) != 0) && (*(int *)(iVar1 + 100) == 0)) {
    *(undefined4 *)(in_EAX + 4) = _DAT_0000fe2c;
  }
  puVar2 = (undefined4 *)(*__Com_sprintf)(0x28);
  *puVar2 = 8;
  *(undefined4 **)(in_EAX + 0xc) = puVar2;
  param_1 = param_1 + 0x3c;
  pfVar3 = (float *)(puVar2 + 7);
  iVar1 = 3;
  do {
    fVar4 = (float10)_LittleFloat(param_1 + -0xc);
    pfVar3[-6] = (float)fVar4;
    fVar4 = (float10)_LittleFloat(param_1);
    *pfVar3 = (float)fVar4;
    fVar4 = (float10)_LittleFloat(param_1 + 0x18);
    pfVar3[-3] = (float)fVar4;
    param_1 = param_1 + 4;
    pfVar3 = pfVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



// ===========================================
// Function: _R_MergedWidthPoints @ 0000d0f8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_MergedWidthPoints(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  
  iVar2 = 1;
  iVar1 = *(int *)(param_1 + 0x48) + -1;
  if (1 < iVar1) {
    pfVar5 = (float *)((param_2 + 3) * 0x2c + param_1);
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 < iVar1) {
        pfVar3 = pfVar5 + 0xd;
        iVar4 = iVar2;
        do {
          if (((ABS((double)*pfVar5 - (double)pfVar3[-2]) <= ___real_3fb999999999999a) &&
              (ABS((double)pfVar5[1] - (double)pfVar3[-1]) <= ___real_3fb999999999999a)) &&
             (ABS((double)pfVar5[2] - (double)*pfVar3) <= ___real_3fb999999999999a)) {
            return 1;
          }
          iVar4 = iVar4 + 1;
          pfVar3 = pfVar3 + 0xb;
        } while (iVar4 < iVar1);
      }
      pfVar5 = pfVar5 + 0xb;
    } while (iVar2 < iVar1);
  }
  return 0;
}



// ===========================================
// Function: _R_MergedHeightPoints @ 0000d19e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_MergedHeightPoints(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_1 + 0x4c) + -1;
  iVar4 = 1;
  if (1 < iVar3) {
    do {
      iVar1 = iVar4 + 1;
      if (iVar1 < iVar3) {
        iVar2 = *(int *)(param_1 + 0x48);
        pfVar5 = (float *)((iVar2 * iVar1 + 2 + param_2) * 0x2c + param_1);
        iVar6 = iVar1;
        do {
          if (((ABS((double)*(float *)((iVar2 * iVar4 + 2 + param_2) * 0x2c + param_1) -
                    (double)*pfVar5) <= ___real_3fb999999999999a) &&
              (ABS((double)*(float *)(param_1 + 0x5c +
                                     (*(int *)(param_1 + 0x48) * iVar4 + param_2) * 0x2c) -
                   (double)*(float *)((*(int *)(param_1 + 0x48) * iVar6 + param_2) * 0x2c + 0x5c +
                                     param_1)) <= ___real_3fb999999999999a)) &&
             (ABS((double)*(float *)(param_1 + 0x60 +
                                    (*(int *)(param_1 + 0x48) * iVar4 + param_2) * 0x2c) -
                  (double)*(float *)((*(int *)(param_1 + 0x48) * iVar6 + param_2) * 0x2c + 0x60 +
                                    param_1)) <= ___real_3fb999999999999a)) {
            return 1;
          }
          iVar6 = iVar6 + 1;
          pfVar5 = pfVar5 + iVar2 * 0xb;
        } while (iVar6 < iVar3);
      }
      iVar4 = iVar1;
    } while (iVar1 < iVar3);
  }
  return 0;
}



// ===========================================
// Function: _R_FixSharedVertexLodError_r @ 0000d29e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_FixSharedVertexLodError_r(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  float *local_c;
  int local_4;
  
  local_4 = param_1;
  if (param_1 < DAT_000020a4) {
    iVar4 = param_1 << 4;
    do {
      piVar1 = *(int **)(iVar4 + 0xc + DAT_000020a8);
      if (((((*piVar1 == 3) && (piVar1[0x11] != 2)) &&
           ((NAN((float)piVar1[0x10]) || NAN(*(float *)(param_2 + 0x40))) !=
            ((float)piVar1[0x10] == *(float *)(param_2 + 0x40)))) &&
          (((NAN((float)piVar1[0xd]) || NAN(*(float *)(param_2 + 0x34))) !=
            ((float)piVar1[0xd] == *(float *)(param_2 + 0x34)) &&
           ((NAN((float)piVar1[0xe]) || NAN(*(float *)(param_2 + 0x38))) !=
            ((float)piVar1[0xe] == *(float *)(param_2 + 0x38)))))) &&
         ((NAN((float)piVar1[0xf]) || NAN(*(float *)(param_2 + 0x3c))) !=
          ((float)piVar1[0xf] == *(float *)(param_2 + 0x3c)))) {
        bVar2 = false;
        local_18 = 0;
        do {
          if (local_18 == 0) {
            local_10 = 0;
          }
          else {
            local_10 = (*(int *)(param_2 + 0x4c) + -1) * *(int *)(param_2 + 0x48);
          }
          iVar5 = _R_MergedWidthPoints(param_2,local_10);
          if ((iVar5 == 0) && (local_1c = 1, 1 < *(int *)(param_2 + 0x48) + -1)) {
            local_c = (float *)((local_10 + 3) * 0x2c + param_2);
            do {
              local_10 = local_10 + 1;
              local_20 = 0;
              do {
                if (local_20 == 0) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = (piVar1[0x13] + -1) * piVar1[0x12];
                }
                iVar6 = _R_MergedWidthPoints(piVar1,iVar5);
                dVar3 = ___real_3fb999999999999a;
                if ((iVar6 == 0) && (iVar6 = 1, 1 < piVar1[0x12] + -1)) {
                  pfVar9 = (float *)(piVar1 + iVar5 * 0xb + 0x23);
                  do {
                    if (((ABS((double)*local_c - (double)pfVar9[-2]) <= dVar3) &&
                        (ABS((double)*(float *)(local_10 * 0x2c + 0x5c + param_2) -
                             (double)pfVar9[-1]) <= dVar3)) &&
                       (ABS((double)*(float *)(local_10 * 0x2c + param_2 + 0x60) - (double)*pfVar9)
                        <= dVar3)) {
                      *(undefined4 *)(piVar1[0x14] + iVar6 * 4) =
                           *(undefined4 *)(*(int *)(param_2 + 0x50) + local_1c * 4);
                      bVar2 = true;
                    }
                    iVar6 = iVar6 + 1;
                    pfVar9 = pfVar9 + 0xb;
                  } while (iVar6 < piVar1[0x12] + -1);
                }
                local_20 = local_20 + 1;
              } while (local_20 < 2);
              local_20 = 0;
              do {
                if (local_20 == 0) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = piVar1[0x12] + -1;
                }
                iVar6 = _R_MergedHeightPoints(piVar1,iVar5);
                dVar3 = ___real_3fb999999999999a;
                if ((iVar6 == 0) && (iVar6 = 1, 1 < piVar1[0x13] + -1)) {
                  do {
                    iVar7 = piVar1[0x12] * iVar6 + iVar5;
                    if (ABS((double)*local_c - (double)(float)piVar1[(iVar7 + 2) * 0xb]) <= dVar3) {
                      if ((ABS((double)*(float *)(local_10 * 0x2c + 0x5c + param_2) -
                               (double)(float)piVar1[iVar7 * 0xb + 0x17]) <= dVar3) &&
                         (ABS((double)*(float *)(local_10 * 0x2c + param_2 + 0x60) -
                              (double)(float)piVar1[iVar7 * 0xb + 0x18]) <= dVar3)) {
                        *(undefined4 *)(piVar1[0x15] + iVar6 * 4) =
                             *(undefined4 *)(*(int *)(param_2 + 0x50) + local_1c * 4);
                        bVar2 = true;
                      }
                    }
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < piVar1[0x13] + -1);
                }
                local_20 = local_20 + 1;
              } while (local_20 < 2);
              local_c = local_c + 0xb;
              local_1c = local_1c + 1;
            } while (local_1c < *(int *)(param_2 + 0x48) + -1);
          }
          local_18 = local_18 + 1;
        } while (local_18 < 2);
        local_18 = 0;
        do {
          if (local_18 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(param_2 + 0x48) + -1;
          }
          iVar6 = _R_MergedHeightPoints(param_2,iVar5);
          if ((iVar6 == 0) && (local_1c = 1, 1 < *(int *)(param_2 + 0x4c) + -1)) {
            do {
              local_20 = 0;
              do {
                if (local_20 == 0) {
                  iVar6 = 0;
                }
                else {
                  iVar6 = (piVar1[0x13] + -1) * piVar1[0x12];
                }
                iVar7 = _R_MergedWidthPoints(piVar1,iVar6);
                dVar3 = ___real_3fb999999999999a;
                if ((iVar7 == 0) && (iVar7 = 1, 1 < piVar1[0x12] + -1)) {
                  pfVar9 = (float *)(piVar1 + iVar6 * 0xb + 0x22);
                  do {
                    iVar6 = iVar5 + *(int *)(param_2 + 0x48) * local_1c;
                    if (((ABS((double)*(float *)((iVar6 + 2) * 0x2c + param_2) - (double)pfVar9[-1])
                          <= dVar3) &&
                        (iVar6 = iVar6 * 0x2c,
                        ABS((double)*(float *)(iVar6 + 0x5c + param_2) - (double)*pfVar9) <= dVar3))
                       && (ABS((double)*(float *)(iVar6 + param_2 + 0x60) - (double)pfVar9[1]) <=
                           dVar3)) {
                      *(undefined4 *)(piVar1[0x14] + iVar7 * 4) =
                           *(undefined4 *)(*(int *)(param_2 + 0x54) + local_1c * 4);
                      bVar2 = true;
                    }
                    iVar7 = iVar7 + 1;
                    pfVar9 = pfVar9 + 0xb;
                  } while (iVar7 < piVar1[0x12] + -1);
                }
                local_20 = local_20 + 1;
              } while (local_20 < 2);
              local_20 = 0;
              do {
                if (local_20 == 0) {
                  iVar6 = 0;
                }
                else {
                  iVar6 = piVar1[0x12] + -1;
                }
                iVar7 = _R_MergedHeightPoints(piVar1,iVar6);
                dVar3 = ___real_3fb999999999999a;
                if ((iVar7 == 0) && (iVar7 = 1, 1 < piVar1[0x13] + -1)) {
                  do {
                    iVar8 = iVar5 + *(int *)(param_2 + 0x48) * local_1c;
                    iVar10 = piVar1[0x12] * iVar7 + iVar6;
                    if (ABS((double)*(float *)((iVar8 + 2) * 0x2c + param_2) -
                            (double)(float)piVar1[(iVar10 + 2) * 0xb]) <= dVar3) {
                      iVar8 = iVar8 * 0x2c;
                      if ((ABS((double)*(float *)(iVar8 + 0x5c + param_2) -
                               (double)(float)piVar1[iVar10 * 0xb + 0x17]) <= dVar3) &&
                         (ABS((double)*(float *)(iVar8 + param_2 + 0x60) -
                              (double)(float)piVar1[iVar10 * 0xb + 0x18]) <= dVar3)) {
                        *(undefined4 *)(piVar1[0x15] + iVar7 * 4) =
                             *(undefined4 *)(*(int *)(param_2 + 0x54) + local_1c * 4);
                        bVar2 = true;
                      }
                    }
                    iVar7 = iVar7 + 1;
                  } while (iVar7 < piVar1[0x13] + -1);
                }
                local_20 = local_20 + 1;
              } while (local_20 < 2);
              local_1c = local_1c + 1;
            } while (local_1c < *(int *)(param_2 + 0x4c) + -1);
          }
          local_18 = local_18 + 1;
        } while (local_18 < 2);
        if (bVar2) {
          piVar1[0x11] = 2;
          _R_FixSharedVertexLodError_r(param_1,piVar1);
        }
      }
      iVar4 = iVar4 + 0x10;
      local_4 = local_4 + 1;
    } while (local_4 < DAT_000020a4);
  }
  return;
}



// ===========================================
// Function: _R_FixSharedVertexLodError @ 0000d7a6
// ===========================================

void _R_FixSharedVertexLodError(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_000020a4) {
    iVar3 = 0;
    do {
      piVar1 = *(int **)(iVar3 + 0xc + DAT_000020a8);
      if ((*piVar1 == 3) && (piVar1[0x11] == 0)) {
        piVar1[0x11] = 2;
        _R_FixSharedVertexLodError_r(iVar2 + 1,piVar1);
        _CL_UpdateLoadingScreen();
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar2 < DAT_000020a4);
  }
  return;
}



// ===========================================
// Function: _R_LoadSurfaces @ 0000d7f2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadSurfaces(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *in_EAX;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_4 = 0;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  iVar6 = *in_EAX;
  if ((uint)in_EAX[1] % 0x6c != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar1 = *param_1;
  uVar5 = (uint)in_EAX[1] / 0x6c;
  if ((uint)param_1[1] % 0x2c != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar2 = *param_2;
  if ((*(byte *)(param_2 + 1) & 3) != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  iVar3 = (*__Com_sprintf)(uVar5 << 4);
  DAT_000020a4 = uVar5;
  DAT_000020a8 = iVar3;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    uVar4 = _LittleLong(*(undefined4 *)(iVar6 + 8));
    switch(uVar4) {
    case 1:
      _ParseFace(iVar6,uVar1,iVar3,uVar2);
      local_4 = local_4 + 1;
      break;
    case 2:
      _ParseMesh(iVar6,iVar3);
      local_8 = local_8 + 1;
      break;
    case 3:
      _ParseTriSurf(iVar6,uVar1,iVar3,uVar2);
      local_c = local_c + 1;
      break;
    case 4:
      _ParseFlare();
      local_10 = local_10 + 1;
      break;
    default:
      (*_DAT_0000fdfc)(1,s_Bad_surfaceType);
    }
    _CL_UpdateLoadingScreen();
    iVar6 = iVar6 + 0x6c;
    iVar3 = iVar3 + 0x10;
  }
  _R_FixSharedVertexLodError();
  (*__ri)(0,s____loaded__d_faces___i_meshes___,local_4,local_8,local_c,local_10);
  return;
}



// ===========================================
// Function: _R_LoadSubmodels @ 0000d98e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadSubmodels(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  float10 fVar7;
  int iStack_10;
  int iStack_c;
  
  iVar4 = *in_EAX;
  if ((uint)in_EAX[1] % 0x28 != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar5 = (uint)in_EAX[1] / 0x28;
  iVar1 = (*__Com_sprintf)(uVar5 << 5);
  iStack_10 = 0;
  DAT_0000208c = iVar1;
  if (uVar5 != 0) {
    do {
      iVar2 = _R_AllocModel();
      *(undefined4 *)(iVar2 + 0x40) = 1;
      *(int *)(iVar2 + 0x4c) = iVar1;
      _Com_sprintf(iVar2,0x40,s___d,iStack_10);
      pfVar6 = (float *)(iVar1 + 0xc);
      iStack_c = 3;
      iVar2 = iVar4;
      do {
        fVar7 = (float10)_LittleFloat(iVar2);
        pfVar6[-3] = (float)fVar7;
        fVar7 = (float10)_LittleFloat((iVar4 - iVar1) + (int)pfVar6);
        *pfVar6 = (float)fVar7;
        iVar2 = iVar2 + 4;
        pfVar6 = pfVar6 + 1;
        iStack_c = iStack_c + -1;
      } while (iStack_c != 0);
      iVar2 = _LittleLong(*(undefined4 *)(iVar4 + 0x18));
      *(int *)(iVar1 + 0x18) = iVar2 * 0x10 + DAT_000020a8;
      uVar3 = _LittleLong(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar1 + 0x1c) = uVar3;
      iStack_10 = iStack_10 + 1;
      iVar4 = iVar4 + 0x28;
      iVar1 = iVar1 + 0x20;
    } while (iStack_10 < (int)uVar5);
  }
  return;
}



// ===========================================
// Function: _R_SetParent @ 0000da9b
// ===========================================

void _R_SetParent(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  param_1[8] = param_2;
  while (iVar2 == -1) {
    _R_SetParent(param_1[10],param_1);
    piVar1 = (int *)param_1[0xb];
    piVar1[8] = (int)param_1;
    param_1 = piVar1;
    iVar2 = *piVar1;
  }
  return;
}



// ===========================================
// Function: _R_LoadNodesAndLeafs @ 0000dac8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadNodesAndLeafs(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *in_EAX;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int extraout_EDX;
  float *pfVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iStack_10;
  
  puVar6 = (undefined4 *)*in_EAX;
  if (((uint)in_EAX[1] % 0x24 != 0) || ((uint)param_1[1] % 0x30 != 0)) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar4 = (uint)param_1[1] / 0x30;
  uVar7 = (uint)in_EAX[1] / 0x24;
  piVar2 = (int *)(*__Com_sprintf)((uVar4 + uVar7) * 0x48);
  DAT_0000209c = uVar7;
  DAT_00002098 = uVar4 + uVar7;
  DAT_000020a0 = piVar2;
  for (uVar1 = uVar7; uVar1 != 0; uVar1 = uVar1 - 1) {
    puVar8 = puVar6 + 6;
    iStack_10 = 3;
    pfVar5 = (float *)(piVar2 + 5);
    do {
      iVar3 = _LittleLong(puVar8[-3]);
      pfVar5[-3] = (float)iVar3;
      iVar3 = _LittleLong(*puVar8);
      puVar8 = puVar8 + 1;
      iStack_10 = iStack_10 + -1;
      *pfVar5 = (float)iVar3;
      pfVar5 = pfVar5 + 1;
    } while (iStack_10 != 0);
    iVar3 = _LittleLong(*puVar6);
    piVar2[9] = DAT_00002094 + iVar3 * 0x14;
    *piVar2 = -1;
    piVar9 = piVar2 + 10;
    iStack_10 = 2;
    puVar8 = puVar6;
    do {
      puVar8 = puVar8 + 1;
      iVar3 = _LittleLong(*puVar8);
      if (iVar3 < 0) {
        iVar3 = (uVar7 - iVar3) + -1;
      }
      *piVar9 = (int)(DAT_000020a0 + iVar3 * 0x12);
      piVar9 = piVar9 + 1;
      iStack_10 = iStack_10 + -1;
    } while (iStack_10 != 0);
    puVar6 = puVar6 + 9;
    piVar2 = piVar2 + 0x12;
  }
  puVar6 = (undefined4 *)*param_1;
  piVar9 = DAT_000020a0;
  for (; DAT_000020a0 = piVar9, uVar4 != 0; uVar4 = uVar4 - 1) {
    puVar8 = puVar6 + 5;
    param_1 = (undefined4 *)0x3;
    pfVar5 = (float *)(piVar2 + 2);
    do {
      iVar3 = _LittleLong(*(undefined4 *)(((int)puVar6 - (int)piVar2) + (int)pfVar5));
      *pfVar5 = (float)iVar3;
      iVar3 = _LittleLong(*puVar8);
      puVar8 = puVar8 + 1;
      param_1 = (undefined4 *)((int)param_1 + -1);
      pfVar5[3] = (float)iVar3;
      pfVar5 = pfVar5 + 1;
    } while (param_1 != (undefined4 *)0x0);
    iVar3 = _LittleLong(*puVar6);
    piVar2[0xc] = iVar3;
    iVar3 = _LittleLong(puVar6[1]);
    piVar2[0xd] = iVar3;
    if (DAT_000020f0 <= piVar2[0xc]) {
      DAT_000020f0 = piVar2[0xc] + 1;
    }
    iVar3 = _LittleLong(puVar6[8]);
    piVar2[0x10] = DAT_000020b0 + iVar3 * 4;
    iVar3 = _LittleLong(puVar6[9]);
    piVar2[0x11] = iVar3;
    puVar6 = puVar6 + 0xc;
    piVar2 = piVar2 + 0x12;
    piVar9 = DAT_000020a0;
  }
  piVar9[8] = 0;
  if (*piVar9 == -1) {
    _R_SetParent(piVar9[10],piVar9);
    _R_SetParent(*(undefined4 *)(extraout_EDX + 0x2c),extraout_EDX);
  }
  return;
}



// ===========================================
// Function: _R_LoadShaders @ 0000dd2c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadShaders(void)

{
  void *__src;
  undefined4 *in_EAX;
  void *__dest;
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  __src = (void *)*in_EAX;
  if ((uint)in_EAX[1] % 0x4c != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar2 = (uint)in_EAX[1] / 0x4c;
  __dest = (void *)(*__Com_sprintf)(uVar2 * 0x4c);
  DAT_00002084 = uVar2;
  DAT_00002088 = __dest;
  _memcpy(__dest,__src,uVar2 * 0x4c);
  if ((__bigendian != 0) && (uVar2 != 0)) {
    puVar3 = (undefined4 *)((int)__dest + 0x44);
    do {
      uVar1 = _LittleLong(puVar3[-1]);
      puVar3[-1] = uVar1;
      uVar1 = _LittleLong(*puVar3);
      *puVar3 = uVar1;
      uVar1 = _LittleLong(puVar3[1]);
      puVar3[1] = uVar1;
      puVar3 = puVar3 + 0x13;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



// ===========================================
// Function: _R_LoadMarksurfaces @ 0000ddd5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadMarksurfaces(void)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *in_EAX;
  if ((*(byte *)(in_EAX + 1) & 3) != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar4 = (uint)in_EAX[1] >> 2;
  piVar1 = (int *)(*__Com_sprintf)(uVar4 * 4);
  _DAT_000020ac = uVar4;
  DAT_000020b0 = piVar1;
  if (uVar4 != 0) {
    iVar3 = iVar3 - (int)piVar1;
    do {
      iVar2 = _LittleLong(*(undefined4 *)(iVar3 + (int)piVar1));
      *piVar1 = iVar2 * 0x10 + DAT_000020a8;
      piVar1 = piVar1 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}



// ===========================================
// Function: _R_LoadPlanes @ 0000de48
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadPlanes(void)

{
  undefined1 uVar1;
  int *in_EAX;
  float *pfVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  uint uStack_14;
  int iStack_c;
  
  iVar6 = *in_EAX;
  if ((*(byte *)(in_EAX + 1) & 0xf) != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uVar4 = (uint)in_EAX[1] >> 4;
  pfVar2 = (float *)(*__Com_sprintf)(uVar4 * 0x28);
  _DAT_00002090 = uVar4;
  DAT_00002094 = pfVar2;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    uStack_14 = 0;
    uVar5 = 1;
    iStack_c = 3;
    pfVar3 = pfVar2;
    do {
      fVar7 = (float10)_LittleFloat((iVar6 - (int)pfVar2) + (int)pfVar3);
      *pfVar3 = (float)fVar7;
      if ((float)fVar7 < 0.0) {
        uStack_14 = uStack_14 | uVar5;
      }
      pfVar3 = pfVar3 + 1;
      uVar5 = uVar5 << 1 | (uint)((int)uVar5 < 0);
      iStack_c = iStack_c + -1;
    } while (iStack_c != 0);
    fVar7 = (float10)_LittleFloat(iVar6 + 0xc);
    pfVar2[3] = (float)fVar7;
    uVar1 = _PlaneTypeForNormal(pfVar2);
    *(undefined1 *)(pfVar2 + 4) = uVar1;
    *(undefined1 *)((int)pfVar2 + 0x11) = (undefined1)uStack_14;
    iVar6 = iVar6 + 0x10;
    pfVar2 = pfVar2 + 5;
  }
  return;
}



// ===========================================
// Function: _R_LoadFogs @ 0000df3a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadFogs(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *in_EAX;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  uint uStack_14;
  
  iVar13 = *in_EAX;
  if ((uint)in_EAX[1] % 0x48 != 0) {
    (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
  }
  uStack_14 = (uint)in_EAX[1] / 0x48;
  _DAT_000020b4 = uStack_14 + 1;
  puVar6 = (uint *)(*__Com_sprintf)(_DAT_000020b4 * 0x5c);
  _DAT_000020b8 = puVar6;
  if (uStack_14 != 0) {
    iVar2 = *param_1;
    if ((uint)param_1[1] % 0xc != 0) {
      (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
    }
    uVar3 = param_1[1];
    iVar4 = *param_2;
    if ((*(byte *)(param_2 + 1) & 7) != 0) {
      (*_DAT_0000fdfc)(1,s_LoadMap__funny_lump_size_in__s,0x2000);
    }
    uVar5 = param_2[1];
    if (uStack_14 != 0) {
      do {
        puVar11 = puVar6 + 0x17;
        uVar7 = _LittleLong(*(undefined4 *)(iVar13 + 0x40));
        *puVar11 = uVar7;
        if (uVar3 / 0xc <= uVar7) {
          (*_DAT_0000fdfc)(1,s_fog_brushNumber_out_of_range);
        }
        uVar7 = _LittleLong(*(undefined4 *)(iVar2 + *puVar11 * 0xc));
        if ((uVar5 >> 3) - 6 < uVar7) {
          (*_DAT_0000fdfc)(1,&s_fog_brush_sideNumber_out_of_rang);
        }
        iVar8 = _LittleLong(*(undefined4 *)(iVar4 + uVar7 * 8));
        puVar6[0x18] = (uint)-*(float *)(DAT_00002094 + 0xc + iVar8 * 0x14);
        iVar8 = _LittleLong(*(undefined4 *)(iVar4 + 8 + uVar7 * 8));
        puVar6[0x1b] = *(uint *)(DAT_00002094 + 0xc + iVar8 * 0x14);
        iVar8 = _LittleLong(*(undefined4 *)(iVar4 + 0x10 + uVar7 * 8));
        puVar6[0x19] = (uint)-*(float *)(DAT_00002094 + 0xc + iVar8 * 0x14);
        iVar8 = _LittleLong(*(undefined4 *)(iVar4 + 0x18 + uVar7 * 8));
        puVar6[0x1c] = *(uint *)(DAT_00002094 + 0xc + iVar8 * 0x14);
        iVar8 = _LittleLong(*(undefined4 *)(iVar4 + 0x20 + uVar7 * 8));
        puVar6[0x1a] = (uint)-*(float *)(DAT_00002094 + 0xc + iVar8 * 0x14);
        iVar8 = _LittleLong(*(undefined4 *)(iVar4 + 0x28 + uVar7 * 8));
        puVar6[0x1d] = *(uint *)(DAT_00002094 + 0xc + iVar8 * 0x14);
        iVar8 = _R_FindShader(iVar13,0xffffffff,1,1,1);
        pfVar12 = (float *)(iVar8 + 0xcc);
        pfVar14 = (float *)(puVar6 + 0x20);
        for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
          *pfVar14 = *pfVar12;
          pfVar12 = pfVar12 + 1;
          pfVar14 = pfVar14 + 1;
        }
        uVar9 = _ColorBytes4(_DAT_000107a4 * *(float *)(iVar8 + 0xcc),
                             *(float *)(iVar8 + 0xd0) * _DAT_000107a4,
                             _DAT_000107a4 * *(float *)(iVar8 + 0xd4),0x3f800000);
        fVar1 = 1.0;
        puVar6[0x1e] = uVar9;
        if (1.0 <= *(float *)(iVar8 + 0xd8)) {
          fVar1 = *(float *)(iVar8 + 0xd8);
        }
        puVar6[0x1f] = (uint)(1.0 / (fVar1 * (float)___real_4020000000000000));
        iVar8 = _LittleLong(*(undefined4 *)(iVar13 + 0x44));
        if (iVar8 == -1) {
          puVar6[0x2d] = 0;
        }
        else {
          puVar6[0x2d] = 1;
          iVar8 = _LittleLong(*(undefined4 *)(iVar4 + (iVar8 + uVar7) * 8));
          iVar8 = iVar8 * 0x14;
          puVar6[0x29] = (uint)(__vec3_origin - *(float *)(iVar8 + DAT_00002094));
          puVar6[0x2a] = (uint)(_DAT_0000fec4 - *(float *)(iVar8 + 4 + DAT_00002094));
          puVar6[0x2b] = (uint)(__ColorBytes4 - *(float *)(iVar8 + 8 + DAT_00002094));
          puVar6[0x2c] = (uint)-*(float *)(iVar8 + 0xc + DAT_00002094);
        }
        iVar13 = iVar13 + 0x48;
        uStack_14 = uStack_14 - 1;
        puVar6 = puVar11;
      } while (uStack_14 != 0);
    }
  }
  return;
}



// ===========================================
// Function: _R_LoadLightGrid @ 0000e26e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadLightGrid(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  int local_44;
  float afStack_3c [14];
  
  iVar3 = DAT_0000208c;
  DAT_000020c8 = ___real_43400000;
  DAT_000020cc = ___real_43400000;
  _DAT_000020d0 = ___real_43a00000;
  _DAT_000020d4 = ___real_3baaaaab;
  iVar4 = DAT_0000208c + 0xc;
  _DAT_000020d8 = ___real_3baaaaab;
  iVar2 = 0;
  _DAT_000020dc = ___real_3b4ccccd;
  do {
    dVar5 = _ceil((double)(*(float *)(iVar2 + iVar3) / *(float *)((int)&DAT_000020c8 + iVar2)));
    *(float *)((int)&DAT_000020bc + iVar2) = (float)dVar5 * *(float *)((int)&DAT_000020c8 + iVar2);
    dVar5 = _floor((double)(*(float *)(iVar2 + iVar4) / *(float *)((int)&DAT_000020c8 + iVar2)));
    *(float *)((int)afStack_3c + iVar2) = (float)dVar5 * *(float *)((int)&DAT_000020c8 + iVar2);
    uVar1 = __ftol2_sse();
    *(undefined4 *)((int)&DAT_000020e0 + iVar2) = uVar1;
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0xc);
  iVar3 = DAT_000020e0 * DAT_000020e4 * DAT_000020e8;
  if (param_1[1] != iVar3 * 8) {
    (*__ri)(2,s_WARNING__light_grid_mismatch_);
    DAT_000020ec = (void *)0x0;
    return;
  }
  DAT_000020ec = (void *)(*__Com_sprintf)();
  _memcpy(DAT_000020ec,(void *)*param_1,param_1[1]);
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      _R_ColorShiftLightingBytes();
      _R_ColorShiftLightingBytes();
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_44);
  }
  return;
}



// ===========================================
// Function: _R_LoadLump @ 0000e3dd
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadLump(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_3 = 0;
  iVar2 = param_2[1];
  param_3[1] = iVar2;
  if (iVar2 != 0) {
    uVar1 = (*_DAT_0000fe0c)(param_2[1]);
    *param_3 = uVar1;
    iVar2 = (*__memset)(param_1,*param_2,2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(*param_3,param_2[1],param_1);
  }
  return;
}



// ===========================================
// Function: _R_FreeLump @ 0000e43f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_FreeLump(int *param_1)

{
  if (*param_1 != 0) {
    (*__r_lightmap)(*param_1);
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}



// ===========================================
// Function: _RE_LoadWorldMap @ 0000e463
// ===========================================

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_LoadWorldMap(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int unaff_retaddr;
  undefined4 uStack_c0;
  int iStack_bc;
  int iStack_b8;
  undefined4 uStack_b4;
  int iStack_b0;
  int aiStack_ac [43];
  
  _UI_SetLoadingStage(7);
  _CL_UpdateLoadingScreen();
  _DAT_00010adc = ___real_3ee66666;
  _DAT_00010ae0 = ___real_3e99999a;
  _DAT_00010ae4 = ___real_3f666666;
  _VectorNormalize(&DAT_00010adc);
  _DAT_0000fe04 = 1;
  iVar1 = (*_DAT_0000fe3c)(param_1,&uStack_c0,1,1);
  if (iVar1 < 1) {
    (*_DAT_0000fdfc)(1,s_RE_LoadWorldMap___s_not_found,param_1);
  }
  (*__memcpy)(aiStack_ac,0xac,uStack_c0);
  iVar1 = 0;
  if (__bigendian != 0) {
    uVar6 = 0;
    do {
      iVar2 = _LittleLong(aiStack_ac[uVar6]);
      aiStack_ac[uVar6] = iVar2;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x2b);
  }
  __Com_sprintf = 0;
  _memset(&_s_worldData,0,0x104);
  _Q_strncpyz(0x2000,param_1,0x40);
  uVar3 = _COM_SkipPath(0x2000,0x40);
  _Q_strncpyz(&DAT_00002040,uVar3);
  _COM_StripExtension(&DAT_00002040,&DAT_00002040);
  __c_gridVerts = 0;
  _DAT_00010a80 = 0;
  __memcpy = (code *)0x0;
  if (aiStack_ac[4] != 0x2a) {
    (*_DAT_0000fdfc)(1,s_RE_LoadWorldMap___s_has_wrong_ve,param_1,aiStack_ac[4],0x2a);
  }
  uVar3 = uStack_b4;
  iVar2 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[7];
  if (aiStack_ac[7] != 0) {
    iVar2 = (*_DAT_0000fe0c)(aiStack_ac[7]);
    iStack_bc = iVar2;
    iVar4 = (*__memset)(uVar3,aiStack_ac[6],2);
    if (iVar4 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar2,aiStack_ac[7],uVar3);
  }
  _R_LoadShaders();
  if (iVar2 != 0) {
    (*__r_lightmap)(iVar2);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar2 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[9];
  if (aiStack_ac[9] != 0) {
    iVar2 = (*_DAT_0000fe0c)(aiStack_ac[9]);
    iStack_bc = iVar2;
    iVar4 = (*__memset)(uVar3,aiStack_ac[8],2);
    if (iVar4 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar2,aiStack_ac[9],uVar3);
  }
  _R_LoadPlanes();
  if (iVar2 != 0) {
    (*__r_lightmap)(iVar2);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar2 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0xb];
  if (aiStack_ac[0xb] != 0) {
    iVar2 = (*_DAT_0000fe0c)(aiStack_ac[0xb]);
    iStack_bc = iVar2;
    iVar4 = (*__memset)(uVar3,aiStack_ac[10],2);
    if (iVar4 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar2,aiStack_ac[0xb],uVar3);
  }
  _R_LoadLightmaps();
  if (iVar2 != 0) {
    (*__r_lightmap)(iVar2);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0xd];
  if (aiStack_ac[0xd] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0xd]);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0xc],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0xd],uVar3);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar2 = 0;
  iStack_b0 = 0;
  aiStack_ac[0] = aiStack_ac[0xf];
  if (aiStack_ac[0xf] != 0) {
    iVar2 = (*_DAT_0000fe0c)(aiStack_ac[0xf]);
    iStack_b0 = iVar2;
    iVar4 = (*__memset)(uVar3,aiStack_ac[0xe],2);
    if (iVar4 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar2,aiStack_ac[0xf],uVar3);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar4 = 0;
  aiStack_ac[1] = 0;
  aiStack_ac[2] = aiStack_ac[0x11];
  if (aiStack_ac[0x11] != 0) {
    iVar4 = (*_DAT_0000fe0c)(aiStack_ac[0x11]);
    aiStack_ac[1] = iVar4;
    iVar5 = (*__memset)(uVar3,aiStack_ac[0x10],2);
    if (iVar5 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar4,aiStack_ac[0x11],uVar3);
  }
  _CL_UpdateLoadingScreen();
  _R_LoadSurfaces(&iStack_b0,aiStack_ac + 1);
  if (iVar4 != 0) {
    (*__r_lightmap)(iVar4);
  }
  if (iVar2 != 0) {
    (*__r_lightmap)(iVar2);
  }
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x15];
  if (aiStack_ac[0x15] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x15]);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x14],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x15],uVar3);
  }
  _R_LoadMarksurfaces();
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_b0 = 0;
  aiStack_ac[0] = aiStack_ac[0x17];
  if (aiStack_ac[0x17] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x17]);
    iStack_b0 = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x16],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x17],uVar3);
  }
  uVar3 = uStack_b4;
  iVar2 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x19];
  if (aiStack_ac[0x19] != 0) {
    iVar2 = (*_DAT_0000fe0c)(aiStack_ac[0x19]);
    iStack_bc = iVar2;
    iVar4 = (*__memset)(uVar3,aiStack_ac[0x18],2);
    if (iVar4 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar2,aiStack_ac[0x19],uVar3);
  }
  _R_LoadNodesAndLeafs(&iStack_b0);
  if (iVar2 != 0) {
    (*__r_lightmap)(iVar2);
  }
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  aiStack_ac[1] = 0;
  aiStack_ac[2] = aiStack_ac[0x1b];
  if (aiStack_ac[0x1b] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x1b]);
    aiStack_ac[1] = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x1a],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x1b],uVar3);
  }
  uVar3 = uStack_b4;
  iVar2 = 0;
  iStack_b0 = 0;
  aiStack_ac[0] = aiStack_ac[0x1d];
  if (aiStack_ac[0x1d] != 0) {
    iVar2 = (*_DAT_0000fe0c)(aiStack_ac[0x1d]);
    iStack_b0 = iVar2;
    iVar4 = (*__memset)(uVar3,aiStack_ac[0x1c],2);
    if (iVar4 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar2,aiStack_ac[0x1d],uVar3);
  }
  uVar3 = uStack_b4;
  iVar4 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x1f];
  if (aiStack_ac[0x1f] != 0) {
    iVar4 = (*_DAT_0000fe0c)(aiStack_ac[0x1f]);
    iStack_bc = iVar4;
    iVar5 = (*__memset)(uVar3,aiStack_ac[0x1e],2);
    if (iVar5 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar4,aiStack_ac[0x1f],uVar3);
  }
  _R_LoadFogs(&iStack_b0,aiStack_ac + 1);
  if (iVar4 != 0) {
    (*__r_lightmap)(iVar4);
  }
  if (iVar2 != 0) {
    (*__r_lightmap)(iVar2);
  }
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x21];
  if (aiStack_ac[0x21] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x21]);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x20],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x21],uVar3);
  }
  _R_LoadSubmodels();
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x25];
  if (aiStack_ac[0x25] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x25]);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x24],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x25],uVar3);
  }
  _R_LoadVisibility();
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x27];
  if (aiStack_ac[0x27] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x27]);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x26],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x27],uVar3);
  }
  _R_LoadLightGrid(&iStack_bc);
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_bc = 0;
  iStack_b8 = aiStack_ac[0x29];
  if (aiStack_ac[0x29] != 0) {
    iVar1 = (*_DAT_0000fe0c)(aiStack_ac[0x29]);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x28],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,aiStack_ac[0x29],uVar3);
  }
  _R_LoadSphereLights(&iStack_bc);
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  uVar3 = uStack_b4;
  iVar1 = 0;
  iStack_bc = 0;
  if (unaff_retaddr != 0) {
    iVar1 = (*_DAT_0000fe0c)(unaff_retaddr);
    iStack_bc = iVar1;
    iVar2 = (*__memset)(uVar3,aiStack_ac[0x2a],2);
    if (iVar2 != 0) {
      _Com_Error(1,s_CM_LoadLump__Error_seeking_to_lu);
    }
    (*__memcpy)(iVar1,unaff_retaddr,uVar3);
  }
  _R_LoadSphereLightVis(&iStack_bc);
  if (iVar1 != 0) {
    (*__r_lightmap)(iVar1);
  }
  _CL_UpdateLoadingScreen();
  __Com_sprintf = 0x2000;
  _R_Sphere_InitLights();
  (*_DAT_0000fe44)(uStack_b4);
  _UI_SetLoadingStage(8);
  _CL_UpdateLoadingScreen();
  return;
}



