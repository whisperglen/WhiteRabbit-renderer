// ===========================================
// Function: _R_SetFontHeightScale @ 00158300
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetFontHeightScale(undefined4 param_1)

{
  __s_fontHeightScale = param_1;
  return;
}



// ===========================================
// Function: _R_SetFontScale @ 0015830b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetFontScale(undefined4 param_1)

{
  __s_fontGeneralScale = param_1;
  return;
}



// ===========================================
// Function: _R_SetFontZ @ 00158316
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetFontZ(undefined4 param_1)

{
  __s_fontZ = param_1;
  return;
}



// ===========================================
// Function: R_LoadFontShader @ 00158321
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl R_LoadFontShader(struct fontheader_t *) */

void __cdecl R_LoadFontShader(fontheader_t *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined1 local_40 [64];
  
  uVar3 = __r_sequencenumber;
  __r_sequencenumber = 0xffffffff;
  _Com_sprintf(local_40,0x40,s_gfx_fonts__s,param_1 + 0x1400);
  uVar4 = _R_FindShader(local_40,0xffffffff,0,0,0);
  *(undefined4 *)(param_1 + 0x1508) = uVar4;
  __r_sequencenumber = uVar3;
  if (*(int *)(param_1 + 0x1508) == 0) {
    (*_DAT_00159d1c)(1,s_Could_not_load_font_shader_for__,local_40);
  }
  iVar1 = *(int *)(param_1 + 0x1508);
  iVar6 = 0;
  if (0 < *(int *)(iVar1 + 400)) {
    piVar5 = (int *)(iVar1 + 0x194);
    do {
      piVar2 = (int *)*piVar5;
      if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
        piVar2[0xa6] = 0xf;
        *(undefined4 *)(*piVar5 + 0x2b0) = 0x10;
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar6 < *(int *)(iVar1 + 400));
    *(undefined4 *)(param_1 + 0x150c) = __r_sequencenumber;
    return;
  }
  *(undefined4 *)(param_1 + 0x150c) = __r_sequencenumber;
  return;
}



// ===========================================
// Function: _R_DrawString @ 001583f7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DrawString(fontheader_t *param_1,char *param_2,float param_3,float param_4,float param_5,
                  float param_6,float param_7,float param_8,float param_9,int param_10)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  fontheader_t *pfVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float local_30;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar8 = param_4;
  fVar7 = param_3;
  iVar13 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = ___real_bf800000;
  if (param_1 != (fontheader_t *)0x0) {
    _R_SyncRenderThread();
    if (*(int *)(param_1 + 0x150c) != __r_sequencenumber) {
      *(undefined4 *)(param_1 + 0x1508) = 0;
    }
    if (*(int *)(param_1 + 0x1508) == 0) {
      R_LoadFontShader(param_1);
    }
    param_9 = __s_fontHeightScale * __s_fontGeneralScale * *(float *)(param_1 + 0x1500) * param_9;
    _RB_BeginSurface(*(undefined4 *)(param_1 + 0x1508),0);
    cVar1 = *param_2;
    local_30 = param_4;
    fVar5 = param_3;
    while ((cVar1 != '\0' && ((param_10 == -1 || (iVar13 < param_10))))) {
      uVar12 = (uint)(byte)param_2[iVar13];
      if (uVar12 == 9) {
        param_3 = fVar5;
        if (*(int *)(param_1 + 0x80) != -1) {
          param_3 = *(float *)(param_1 + *(int *)(param_1 + 0x80) * 0x10 + 0x408) *
                    (float)___real_4070000000000000 * __s_fontGeneralScale *
                    (float)___real_4008000000000000 + fVar5;
        }
      }
      else {
        param_3 = fVar7;
        if (uVar12 == 10) {
          param_4 = param_9 + param_7 + local_30;
          local_30 = param_4;
        }
        else if ((uVar12 != 0xd) &&
                (iVar9 = *(int *)(param_1 + uVar12 * 4), param_3 = fVar5, iVar9 != -1)) {
          _RB_CheckOverflow(4,6);
          iVar9 = (iVar9 + 0x40) * 0x10;
          pfVar10 = param_1 + iVar9;
          fVar2 = *(float *)(param_1 + iVar9 + 8) * (float)___real_4070000000000000 *
                  __s_fontGeneralScale * param_8;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f3fd0) = *(float *)pfVar10;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f3fd4) = *(float *)(pfVar10 + 4);
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f3fe0) = *(float *)(pfVar10 + 8) + *(float *)pfVar10;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f3fe4) = *(float *)(pfVar10 + 4);
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f3ff0) = *(float *)pfVar10;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f3ff4) =
               *(float *)(pfVar10 + 4) + *(float *)(pfVar10 + 0xc);
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f4000) = *(float *)(pfVar10 + 8) + *(float *)pfVar10;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2f4004) =
               *(float *)(pfVar10 + 4) + *(float *)(pfVar10 + 0xc);
          *(float *)(_DAT_00470da4 * 0x10 + 0x2099d0) = fVar5;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2099d4) = param_4;
          uVar6 = __s_fontZ;
          *(undefined4 *)(_DAT_00470da4 * 0x10 + 0x2099d8) = __s_fontZ;
          fVar3 = fVar2 + fVar5;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2099e0) = fVar3;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2099e4) = param_4;
          *(undefined4 *)(_DAT_00470da4 * 0x10 + 0x2099e8) = uVar6;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2099f0) = fVar5;
          fVar4 = param_9 + param_4;
          *(float *)(_DAT_00470da4 * 0x10 + 0x2099f4) = fVar4;
          *(undefined4 *)(_DAT_00470da4 * 0x10 + 0x2099f8) = uVar6;
          *(float *)(_DAT_00470da4 * 0x10 + 0x209a00) = fVar3;
          *(float *)(_DAT_00470da4 * 0x10 + 0x209a04) = fVar4;
          *(undefined4 *)(_DAT_00470da4 * 0x10 + 0x209a08) = uVar6;
          if (NAN(param_5) == (param_5 == 0.0)) {
            iVar9 = 0;
            do {
              iVar11 = (_DAT_00470da4 + iVar9) * 0x10;
              uStack_10 = *(undefined4 *)(iVar11 + 0x2099d8);
              fStack_18 = *(float *)(iVar11 + 0x2099d0) - fVar7;
              fStack_14 = *(float *)(iVar11 + 0x2099d4) - fVar8;
              _RotatePointAroundVector(iVar11 + 0x2099d0,&local_c,&fStack_18,param_5);
              iVar11 = (_DAT_00470da4 + iVar9) * 0x10;
              *(float *)(iVar11 + 0x2099d0) = fVar7 + *(float *)(iVar11 + 0x2099d0);
              iVar11 = (_DAT_00470da4 + iVar9) * 0x10;
              iVar9 = iVar9 + 1;
              *(float *)(iVar11 + 0x2099d4) = fVar8 + *(float *)(iVar11 + 0x2099d4);
            } while (iVar9 < 4);
          }
          *(int *)(&_tess + _DAT_00470da0 * 4) = _DAT_00470da4;
          *(int *)(&DAT_00159d54 + _DAT_00470da0 * 4) = _DAT_00470da4 + 1;
          *(int *)(_RB_CheckOverflow + _DAT_00470da0 * 4) = _DAT_00470da4 + 2;
          *(int *)(&DAT_00159d5c + _DAT_00470da0 * 4) = _DAT_00470da4 + 1;
          *(int *)(_RB_BeginSurface + _DAT_00470da0 * 4) = _DAT_00470da4 + 3;
          *(int *)(&DAT_00159d64 + _DAT_00470da0 * 4) = _DAT_00470da4 + 2;
          _DAT_00470da4 = _DAT_00470da4 + 4;
          _DAT_00470da0 = _DAT_00470da0 + 6;
          param_3 = fVar2 + param_6 + fVar5;
        }
      }
      iVar13 = iVar13 + 1;
      cVar1 = param_2[iVar13];
      fVar5 = param_3;
    }
    _RB_EndSurface();
    _GLimp_Suspend();
  }
  return;
}



// ===========================================
// Function: _R_GetFontHeight @ 0015889d
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _R_GetFontHeight(int param_1)

{
  if (param_1 == 0) {
    return (float10)0;
  }
  return (float10)(__s_fontHeightScale * __s_fontGeneralScale * *(float *)(param_1 + 0x1500));
}



// ===========================================
// Function: _R_GetFontStringWidth @ 001588c3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _R_GetFontStringWidth(int param_1,byte *param_2)

{
  float fVar1;
  int iVar2;
  byte bVar3;
  float10 fVar4;
  float local_4;
  
  fVar4 = (float10)0;
  local_4 = (float)fVar4;
  if (param_1 != 0) {
    bVar3 = *param_2;
    if (bVar3 != 0) {
      do {
        if (bVar3 == 9) {
          if (*(int *)(param_1 + 0x80) != -1) {
            fVar1 = *(float *)(*(int *)(param_1 + 0x80) * 0x10 + 0x408 + param_1) *
                    (float)___real_4008000000000000;
LAB_00158915:
            local_4 = fVar1 + local_4;
          }
        }
        else {
          iVar2 = *(int *)(param_1 + (uint)bVar3 * 4);
          if (iVar2 != -1) {
            fVar1 = *(float *)(iVar2 * 0x10 + 0x408 + param_1);
            goto LAB_00158915;
          }
        }
        bVar3 = param_2[1];
        param_2 = param_2 + 1;
      } while (bVar3 != 0);
    }
    fVar4 = (float10)(__s_fontGeneralScale * (float)___real_4070000000000000 * local_4);
  }
  return fVar4;
}



// ===========================================
// Function: _R_LoadFont @ 0015893e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

fontheader_t * _R_LoadFont(char *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  undefined *puVar11;
  fontheader_t *pfVar12;
  double dVar13;
  int iStack_8;
  int iStack_4;
  
  bVar2 = false;
  iVar9 = 0;
  if (0 < _s_numLoadedFonts) {
    puVar11 = &DAT_00003400;
    do {
      iVar3 = _Q_stricmp(param_1,puVar11);
      if (iVar3 == 0) {
        return (fontheader_t *)(iVar9 * 0x1510 + 0x2000);
      }
      iVar9 = iVar9 + 1;
      puVar11 = puVar11 + 0x1510;
    } while (iVar9 < _s_numLoadedFonts);
  }
  pcVar7 = param_1;
  if (0xfe < _s_numLoadedFonts) {
    (*__ri)(3,s_LoadFont__Too_many_fonts_loaded_,param_1);
    return (fontheader_t *)0x0;
  }
  uVar4 = va(s_fonts__s_RitualFont,param_1,&iStack_4);
  iVar9 = (*__atof)(uVar4);
  if (iVar9 == -1) {
    (*__ri)(3,s_LoadFont__Couldn_t_load_font__s_,pcVar7);
    return (fontheader_t *)0x0;
  }
  iVar9 = _s_numLoadedFonts * 0x1510;
  pfVar12 = (fontheader_t *)(iVar9 + 0x2000);
  *(undefined4 *)(&DAT_00003500 + iVar9) = 0;
  *(undefined4 *)(&DAT_00003504 + iVar9) = 0;
  pcVar5 = pcVar7;
  do {
    cVar1 = *pcVar5;
    pcVar5[(int)(pfVar12 + (0x1400 - (int)pcVar7))] = cVar1;
    pcVar5 = pcVar5 + 1;
    iStack_8 = iStack_4;
  } while (cVar1 != '\0');
joined_r0x00158a33:
  do {
    do {
      pcVar5 = pcVar7;
      if (iStack_8 == 0) goto LAB_00158ca0;
      pcVar6 = (char *)_COM_Parse(&iStack_8);
      iVar3 = _Q_stricmp(pcVar6,s_RitFont);
      pcVar7 = param_1;
    } while (iVar3 == 0);
    iVar3 = _Q_stricmp(pcVar6,s_indirections);
    if (iVar3 == 0) {
      uVar4 = _COM_Parse(&iStack_8);
      iVar3 = _Q_stricmp(uVar4,s__);
      if (iVar3 != 0) goto LAB_00158c9b;
      iVar3 = 0;
      do {
        pcVar7 = (char *)_COM_Parse(&iStack_8);
        if (*pcVar7 == '\0') goto LAB_00158c9b;
        iVar8 = _atoi(pcVar7);
        *(int *)(pfVar12 + iVar3 * 4) = iVar8;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x100);
    }
    else {
      iVar3 = _Q_stricmp(pcVar6,s_locations);
      if (iVar3 != 0) {
        iVar3 = _Q_stricmp(pcVar6,s_height);
        if (iVar3 == 0) {
          pcVar7 = (char *)_COM_Parse(&iStack_8);
          dVar13 = _atof(pcVar7);
          *(float *)(&DAT_00003500 + iVar9) = (float)dVar13;
          pcVar7 = param_1;
        }
        else {
          iVar3 = _Q_stricmp(pcVar6,s_aspect);
          if (iVar3 != 0) {
            if (*pcVar6 == '\0') goto LAB_00158ca0;
            (*__ri)(3,s_WARNING__Unknown_token___s__pars,pcVar6,pcVar5);
            goto LAB_00158c9b;
          }
          pcVar7 = (char *)_COM_Parse(&iStack_8);
          dVar13 = _atof(pcVar7);
          *(float *)(&DAT_00003504 + iVar9) = (float)dVar13;
          pcVar7 = param_1;
        }
        goto joined_r0x00158a33;
      }
      uVar4 = _COM_Parse(&iStack_8,s__);
      iVar3 = _Q_stricmp(uVar4);
      if (iVar3 != 0) goto LAB_00158c9b;
      iVar3 = 0;
      pfVar10 = (float *)(&DAT_00002404 + iVar9);
      do {
        uVar4 = _COM_Parse(&iStack_8,s__);
        iVar8 = _Q_stricmp(uVar4);
        if (iVar8 != 0) goto LAB_00158c9b;
        if (NAN(*(float *)(&DAT_00003504 + iVar9)) != (*(float *)(&DAT_00003504 + iVar9) == 0.0)) {
          (*__ri)(3,s_WARNING__aspect_decl_must_be_bef,param_1);
          goto LAB_00158c9b;
        }
        pcVar7 = (char *)_COM_Parse(&iStack_8);
        dVar13 = _atof(pcVar7);
        pfVar10[-1] = (float)((float10)dVar13 * (float10)___real_3f70000000000000);
        pcVar7 = (char *)_COM_Parse(&iStack_4);
        dVar13 = _atof(pcVar7);
        *pfVar10 = (float)dVar13 * *(float *)(&DAT_00003504 + iVar9) *
                   (float)___real_3f70000000000000;
        pcVar7 = (char *)_COM_Parse(&stack0x00000000);
        dVar13 = _atof(pcVar7);
        pfVar10[1] = (float)((float10)dVar13 * (float10)___real_3f70000000000000);
        pcVar7 = (char *)_COM_Parse(&param_1);
        dVar13 = _atof(pcVar7);
        pfVar10[2] = (float)dVar13 * *(float *)(&DAT_00003504 + iVar9) *
                     (float)___real_3f70000000000000;
        uVar4 = _COM_Parse(&stack0x00000008);
        iVar8 = _Q_stricmp(uVar4,s__);
        if (iVar8 != 0) goto LAB_00158c9b;
        iVar3 = iVar3 + 1;
        pfVar10 = pfVar10 + 4;
      } while (iVar3 < 0x100);
    }
    uVar4 = _COM_Parse(&iStack_8,s__);
    iVar3 = _Q_stricmp(uVar4);
    pcVar7 = param_1;
    if (iVar3 != 0) {
LAB_00158c9b:
      bVar2 = true;
LAB_00158ca0:
      R_LoadFontShader(pfVar12);
      if ((NAN(*(float *)(&DAT_00003500 + iVar9)) != (*(float *)(&DAT_00003500 + iVar9) == 0.0)) ||
         (NAN(*(float *)(&DAT_00003504 + iVar9)) != (*(float *)(&DAT_00003504 + iVar9) == 0.0))) {
        bVar2 = true;
      }
      (*_DAT_00159d74)(iStack_4);
      if (!bVar2) {
        _s_numLoadedFonts = _s_numLoadedFonts + 1;
        return pfVar12;
      }
      (*__ri)(3,s_WARNING__Error_parsing_font__s__,param_1);
      return (fontheader_t *)0x0;
    }
  } while( true );
}



