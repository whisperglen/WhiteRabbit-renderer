// ===========================================
// Function: generateHashValue @ 00016c00
// ===========================================

/* generateHashValue */

uint __cdecl generateHashValue(void)

{
  char *pcVar1;
  char cVar2;
  char *in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  if (*in_EAX != '\0') {
    iVar5 = 0x77 - (int)in_EAX;
    do {
      iVar3 = _tolower((int)*in_EAX);
      cVar2 = (char)iVar3;
      if (cVar2 == '.') break;
      if (cVar2 == '\\') {
        cVar2 = '/';
      }
      pcVar1 = in_EAX + iVar5;
      in_EAX = in_EAX + 1;
      uVar4 = uVar4 + (int)pcVar1 * (int)cVar2;
    } while (*in_EAX != '\0');
  }
  return uVar4 & 0x3ff;
}



// ===========================================
// Function: _FindShaderText @ 00016cbf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * _FindShaderText(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *unaff_EBX;
  
  iVar1 = generateHashValue();
  pcVar3 = (char *)(&_hashTable)[iVar1];
  while( true ) {
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)(*_DAT_0001ce34)(0x4c);
      _memset(pcVar3,0,0x4c);
      _strncpy(pcVar3,unaff_EBX,0x40);
      *(undefined4 *)(pcVar3 + 0x48) = (&_hashTable)[iVar1];
      (&_hashTable)[iVar1] = pcVar3;
      return pcVar3;
    }
    iVar2 = _Q_stricmp(pcVar3);
    if (iVar2 == 0) break;
    pcVar3 = *(char **)(pcVar3 + 0x48);
  }
  return pcVar3;
}



// ===========================================
// Function: _ParseVector @ 00016d20
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _ParseVector(undefined4 param_1)

{
  char *__nptr;
  int unaff_EBX;
  int iVar1;
  int unaff_EDI;
  double dVar2;
  
  iVar1 = 0;
  if (0 < unaff_EDI) {
    do {
      __nptr = (char *)_COM_ParseExt(param_1,0);
      if (*__nptr == '\0') {
        (*__ri)(3,s_WARNING__missing_vector_element_,&_shader);
        return 0;
      }
      dVar2 = _atof(__nptr);
      *(float *)(unaff_EBX + iVar1 * 4) = (float)dVar2;
      iVar1 = iVar1 + 1;
    } while (iVar1 < unaff_EDI);
  }
  return 1;
}



// ===========================================
// Function: _NameToAFunc @ 00016d73
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NameToAFunc(void)

{
  int iVar1;
  
  iVar1 = _Q_stricmp();
  if (iVar1 == 0) {
    return 0x10000000;
  }
  iVar1 = _Q_stricmp();
  if (iVar1 == 0) {
    return 0x20000000;
  }
  iVar1 = _Q_stricmp();
  if (iVar1 == 0) {
    return 0x40000000;
  }
  (*__ri)(3,s_WARNING__invalid_alphaFunc_name_);
  return 0;
}



// ===========================================
// Function: _NameToSrcBlendMode @ 00016dd4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NameToSrcBlendMode(void)

{
  int iVar1;
  
  iVar1 = _Q_stricmp();
  if (iVar1 != 0) {
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 3;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 4;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 5;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 6;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 7;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 8;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 9;
    }
    (*__ri)(3,s_WARNING__unknown_blend_mode___s_);
  }
  return 2;
}



// ===========================================
// Function: _NameToDstBlendMode @ 00016ec6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NameToDstBlendMode(void)

{
  int iVar1;
  
  iVar1 = _Q_stricmp();
  if (iVar1 != 0) {
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x10;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x50;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x60;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x70;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x80;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x30;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 0x40;
    }
    (*__ri)(3,s_WARNING__unknown_blend_mode___s_);
  }
  return 0x20;
}



// ===========================================
// Function: _NameToGenFunc @ 00016fa0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NameToGenFunc(void)

{
  int iVar1;
  
  iVar1 = _Q_stricmp();
  if (iVar1 != 0) {
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 2;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 3;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 4;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 5;
    }
    iVar1 = _Q_stricmp();
    if (iVar1 == 0) {
      return 8;
    }
    (*__ri)(3,s_WARNING__invalid_genfunc_name___);
  }
  return 1;
}



// ===========================================
// Function: _ParseWaveForm @ 0001704a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ParseWaveForm(void)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *unaff_EBX;
  double dVar5;
  undefined4 extraout_var;
  
  pcVar1 = (char *)_COM_ParseExt();
  if (*pcVar1 == '\0') {
    (*__ri)(3,s_WARNING__missing_waveform_parm_i,&_shader,extraout_var);
    return;
  }
  uVar2 = _NameToGenFunc();
  *unaff_EBX = uVar2;
  pcVar1 = (char *)_COM_ParseExt();
  if (*pcVar1 == '\0') {
    (*__ri)(3,s_WARNING__missing_BASE_waveform_p,&_shader);
    return;
  }
  iVar3 = _Q_stricmp(pcVar1,s_fromEntity);
  if (iVar3 == 0) {
    unaff_EBX[1] = ___real_4996b438;
  }
  else {
    dVar5 = _atof(pcVar1);
    unaff_EBX[1] = (float)dVar5;
  }
  pcVar1 = (char *)_COM_ParseExt();
  if (*pcVar1 == '\0') {
    (*__ri)(3,s_WARNING__missing_AMPLITUDE_wavef,&_shader);
    return;
  }
  iVar3 = _Q_stricmp(pcVar1,s_fromEntity);
  if (iVar3 == 0) {
    unaff_EBX[2] = ___real_4996b438;
  }
  else {
    dVar5 = _atof(pcVar1);
    unaff_EBX[2] = (float)dVar5;
  }
  pcVar1 = (char *)_COM_ParseExt();
  if (*pcVar1 == '\0') {
    (*__ri)(3,s_WARNING__missing_PHASE_waveform_,&_shader);
    return;
  }
  iVar3 = _Q_stricmp(pcVar1,s_fromEntity);
  if (iVar3 == 0) {
    unaff_EBX[3] = ___real_4996b438;
  }
  else {
    iVar3 = _Q_stricmp(pcVar1,s_random);
    if (iVar3 == 0) {
      uVar4 = _rand();
      unaff_EBX[2] = (float)(uVar4 & 0x7fff) / (float)___real_40dfffc000000000;
    }
    else {
      dVar5 = _atof(pcVar1);
      unaff_EBX[3] = (float)dVar5;
    }
  }
  pcVar1 = (char *)_COM_ParseExt();
  if (*pcVar1 == '\0') {
    (*__ri)(3,s_WARNING__missing_FREQUENCY_wavef,&_shader);
    return;
  }
  iVar3 = _Q_stricmp(pcVar1,s_fromEntity);
  if (iVar3 == 0) {
    unaff_EBX[4] = ___real_4996b438;
    return;
  }
  dVar5 = _atof(pcVar1);
  unaff_EBX[4] = (float)dVar5;
  return;
}



// ===========================================
// Function: _ParseTexMod @ 000171fb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _ParseTexMod(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  double dVar5;
  
  param_1 = in_EAX * 0x13c + param_1;
  iVar2 = *(int *)(param_1 + 300);
  if (iVar2 == 4) {
    (*_DAT_0001ce1c)(1,s_ERROR__too_many_tcMod_stages_in_,&_shader);
    return;
  }
  puVar4 = (undefined4 *)(iVar2 * 0x4c + *(int *)(param_1 + 0x130));
  *(int *)(param_1 + 300) = iVar2 + 1;
  uVar1 = _COM_ParseExt(&stack0x00000004,0);
  iVar2 = _Q_stricmp(uVar1,s_turb);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 == '\0') {
      (*__ri)(3,s_WARNING__missing_tcMod_turb_parm,&_shader);
      return;
    }
    dVar5 = _atof(pcVar3);
    puVar4[2] = (float)dVar5;
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
    if (*pcVar3 != '\0') {
      dVar5 = _atof(pcVar3);
      puVar4[3] = (float)dVar5;
      pcVar3 = (char *)_COM_ParseExt(&stack0x0000000c,0);
      if (*pcVar3 != '\0') {
        dVar5 = _atof(pcVar3);
        puVar4[4] = (float)dVar5;
        pcVar3 = (char *)_COM_ParseExt(&stack0x0000000c,0);
        if (*pcVar3 != '\0') {
          dVar5 = _atof(pcVar3);
          puVar4[5] = (float)dVar5;
          *puVar4 = 2;
          return;
        }
      }
    }
    (*__ri)(3,s_WARNING__missing_tcMod_turb_in_s,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_scale);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 != '\0') {
      dVar5 = _atof(pcVar3);
      puVar4[0xc] = (float)dVar5;
      pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
      if (*pcVar3 != '\0') {
        dVar5 = _atof(pcVar3);
        puVar4[0xd] = (float)dVar5;
        *puVar4 = 4;
        return;
      }
    }
    (*__ri)(3,s_WARNING__missing_scale_parms_in_,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_scroll);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 != '\0') {
      iVar2 = _Q_stricmp(pcVar3,s_fromEntity);
      if (iVar2 == 0) {
        puVar4[0x10] = ___real_4996b438;
      }
      else {
        dVar5 = _atof(pcVar3);
        puVar4[0x10] = (float)dVar5;
      }
      pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
      if (*pcVar3 != '\0') {
        iVar2 = _Q_stricmp(pcVar3,s_fromEntity);
        if (iVar2 == 0) {
          puVar4[0x11] = ___real_4996b438;
          *puVar4 = 3;
          return;
        }
        dVar5 = _atof(pcVar3);
        puVar4[0x11] = (float)dVar5;
        *puVar4 = 3;
        return;
      }
    }
    (*__ri)(3,s_WARNING__missing_scale_scroll_pa,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_stretch);
  if (iVar2 == 0) {
    _ParseWaveForm();
    *puVar4 = 5;
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_transform);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 != '\0') {
      dVar5 = _atof(pcVar3);
      puVar4[6] = (float)dVar5;
      pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
      if (*pcVar3 != '\0') {
        dVar5 = _atof(pcVar3);
        puVar4[7] = (float)dVar5;
        pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
        if (*pcVar3 != '\0') {
          dVar5 = _atof(pcVar3);
          puVar4[8] = (float)dVar5;
          pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
          if (*pcVar3 != '\0') {
            dVar5 = _atof(pcVar3);
            puVar4[9] = (float)dVar5;
            pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
            if (*pcVar3 != '\0') {
              dVar5 = _atof(pcVar3);
              puVar4[10] = (float)dVar5;
              pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
              if (*pcVar3 != '\0') {
                dVar5 = _atof(pcVar3);
                puVar4[0xb] = (float)dVar5;
                *puVar4 = 1;
                return;
              }
            }
          }
        }
      }
    }
    (*__ri)(3,s_WARNING__missing_transform_parms,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_rotate);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 == '\0') {
      (*__ri)(3,s_WARNING__missing_tcMod_rotate_pa,&_shader);
      return;
    }
    iVar2 = _Q_stricmp(pcVar3,s_fromEntity);
    if (iVar2 == 0) {
      puVar4[0x12] = ___real_4996b438;
      *puVar4 = 6;
      return;
    }
    dVar5 = _atof(pcVar3);
    puVar4[0x12] = (float)dVar5;
    *puVar4 = 6;
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_offset);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 != '\0') {
      iVar2 = _Q_stricmp(pcVar3,s_fromEntity);
      if (iVar2 == 0) {
        puVar4[0x10] = ___real_4996b438;
      }
      else {
        dVar5 = _atof(pcVar3);
        puVar4[0x10] = (float)dVar5;
      }
      pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
      if (*pcVar3 != '\0') {
        iVar2 = _Q_stricmp(pcVar3,s_fromEntity);
        if (iVar2 == 0) {
          puVar4[0x11] = ___real_4996b438;
          *puVar4 = 9;
          return;
        }
        dVar5 = _atof(pcVar3);
        puVar4[0x11] = (float)dVar5;
        *puVar4 = 9;
        return;
      }
    }
    (*__ri)(3,s_WARNING__missing_offset_parms_in,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_entityTranslate);
  if (iVar2 == 0) {
    *puVar4 = 7;
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_parallax);
  if (iVar2 == 0) {
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
    if (*pcVar3 != '\0') {
      dVar5 = _atof(pcVar3);
      puVar4[0xe] = (float)dVar5;
      pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
      if (*pcVar3 != '\0') {
        dVar5 = _atof(pcVar3);
        puVar4[0xf] = (float)dVar5;
        *puVar4 = 10;
        return;
      }
    }
    (*__ri)(3,s_WARNING__missing_rate_parms_in_s,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(uVar1,s_macro);
  if (iVar2 != 0) {
    (*__ri)(3,s_WARNING__unknown_tcMod___s__in_s,uVar1,&_shader);
    return;
  }
  pcVar3 = (char *)_COM_ParseExt(&stack0x00000004,0);
  if (*pcVar3 != '\0') {
    dVar5 = _atof(pcVar3);
    puVar4[0xc] = 1.0 / (float)dVar5;
    pcVar3 = (char *)_COM_ParseExt(&stack0x00000008,0);
    if (*pcVar3 != '\0') {
      dVar5 = _atof(pcVar3);
      *puVar4 = 0xb;
      puVar4[0xd] = 1.0 / (float)dVar5;
      _DAT_00006284 = 1;
      return;
    }
  }
  (*__ri)(3,s_WARNING__missing_scale_parms_in_,&_shader);
  return;
}



// ===========================================
// Function: _ParseStage @ 000177a0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _ParseStage(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  double dVar13;
  char *pcVar14;
  int local_440;
  int iStack_43c;
  uint local_434;
  uint local_430;
  uint local_42c;
  uint local_428;
  uint local_424;
  uint local_41c;
  float fStack_418;
  float fStack_414;
  float fStack_410;
  float fStack_40c;
  float fStack_408;
  undefined4 uStack_404;
  char acStack_400 [1024];
  
  uVar7 = _shader_noMipMaps;
  uVar6 = _shader_noPicMip;
  uVar5 = _shader_force32bit;
  local_428 = 0x100;
  local_42c = 0;
  local_430 = 0;
  local_434 = 0;
  local_424 = 0;
  bVar4 = false;
  local_440 = 0;
  local_41c = 0;
  *param_1 = 1;
  param_1[0xb1] = uVar7;
  param_1[0xb2] = uVar6;
  param_1[0xb3] = uVar5;
  pcVar8 = (char *)_COM_ParseExt(param_2,1);
  cVar2 = *pcVar8;
  do {
    if (cVar2 == '\0') {
      (*__ri)(3,s_WARNING__no_matching_____found_);
      return 0;
    }
    if (cVar2 == '}') {
      if (param_1[0xa6] == 0) {
        if (((local_440 < 1) && (param_1[0x4d] != 0)) ||
           ((local_42c != 0 && ((local_42c != 2 && (local_42c != 5)))))) {
          param_1[0xa6] = 1;
        }
        else {
          param_1[0xa6] = 2;
        }
      }
      if ((local_42c == 2) && (local_430 == 0x10)) {
        local_42c = 0;
        local_430 = 0;
        local_428 = 0x100;
      }
      if (local_41c == 0x400) {
        local_428 = 0;
      }
      if ((param_1[0xac] == 1) && ((param_1[0xa6] == 1 || (param_1[0xa6] == 10)))) {
        param_1[0xac] = 1;
      }
      param_1[0xad] = local_41c | local_424 | local_434 | local_430 | local_42c | local_428;
      return 1;
    }
    iVar9 = _Q_stricmp(pcVar8,s_nomipmaps);
    if (iVar9 == 0) {
      param_1[0xb1] = 1;
    }
    else {
      iVar9 = _Q_stricmp(pcVar8,s_nopicmip);
      if (iVar9 == 0) {
        param_1[0xb2] = 1;
      }
      else {
        iVar9 = _Q_stricmp(pcVar8,s_force32bit);
        if (iVar9 == 0) {
          param_1[0xb3] = 1;
        }
        else {
          iVar9 = _Q_stricmp(pcVar8,s_map);
          if (iVar9 == 0) {
            pcVar8 = (char *)_COM_ParseExt(param_2,0);
            if (*pcVar8 == '\0') {
              (*__ri)(3,s_WARNING__missing_parameter_for__,&_shader);
              return 0;
            }
            iVar9 = _Q_stricmp(pcVar8,s__whiteimage);
            if (iVar9 == 0) {
              param_1[local_440 * 0x4f + 2] = _DAT_0001ce9c;
            }
            else {
              iVar9 = _Q_stricmp(pcVar8,s__lightmap);
              if (iVar9 != 0) {
                iVar9 = _R_FindImageFile(pcVar8,param_1[0xb1] == 0,param_1[0xb2] == 0,param_1[0xb3],
                                         &DAT_00002901);
                param_1[local_440 * 0x4f + 2] = iVar9;
                goto joined_r0x00017a1a;
              }
              param_1[local_440 * 0x4f + 0x4d] = 1;
              if (DAT_00006208 < 0) {
                param_1[local_440 * 0x4f + 2] = _DAT_0001ce9c;
              }
              else {
                param_1[local_440 * 0x4f + 2] = *(undefined4 *)(&DAT_0001cebc + DAT_00006208 * 4);
              }
            }
          }
          else {
            iVar9 = _Q_stricmp(pcVar8,s_clampmap);
            if (iVar9 == 0) {
              pcVar8 = (char *)_COM_ParseExt(param_2,0);
              if (*pcVar8 == '\0') {
                (*__ri)(3,s_WARNING__missing_parameter_for__,&_shader);
                return 0;
              }
              iVar9 = _R_FindImageFile(pcVar8,param_1[0xb1] == 0,param_1[0xb2] == 0,param_1[0xb3],
                                       &DAT_0000812f);
              param_1[local_440 * 0x4f + 2] = iVar9;
joined_r0x00017a1a:
              if (iVar9 == 0) {
LAB_00017993:
                pcVar14 = s_WARNING__R_FindImageFile_could_n;
LAB_0001799e:
                (*__ri)(3,pcVar14,pcVar8,&_shader);
                return 0;
              }
            }
            else {
              iVar9 = _Q_stricmp(pcVar8,s_animMap);
              if ((iVar9 == 0) || (iVar9 = _Q_stricmp(pcVar8,s_animMapOnce), iVar9 == 0)) {
                _DAT_000063d0 = _DAT_000063d0 | 1;
                iVar9 = _Q_stricmp(pcVar8,s_animMapOnce);
                if (iVar9 == 0) {
                  *(byte *)(param_1 + local_440 * 0x4f + 0x50) =
                       *(byte *)(param_1 + local_440 * 0x4f + 0x50) | 1;
                }
                pcVar8 = (char *)_COM_ParseExt(param_2,0);
                if (*pcVar8 == '\0') {
                  (*__ri)(3,s_WARNING__missing_parameter_for__,&_shader);
                  return 0;
                }
                dVar13 = _atof(pcVar8);
                param_1[local_440 * 0x4f + 0x43] = (float)dVar13;
                pcVar8 = (char *)_COM_ParseExt(param_3,0);
                cVar2 = *pcVar8;
                while (cVar2 != '\0') {
                  iVar9 = param_1[local_440 * 0x4f + 0x42];
                  if (iVar9 < 0x40) {
                    iVar11 = _R_FindImageFile(pcVar8,param_1[0xb1] == 0,param_1[0xb2] == 0,
                                              param_1[0xb3],&DAT_00002901);
                    param_1[local_440 * 0x4f + iVar9 + 2] = iVar11;
                    if (iVar11 == 0) goto LAB_00017993;
                    param_1[local_440 * 0x4f + 0x42] = param_1[local_440 * 0x4f + 0x42] + 1;
                  }
                  else {
                    (*__ri)(3,s_WARNING__mapanim___too_many_anim,&_shader);
                  }
                  pcVar8 = (char *)_COM_ParseExt(param_2,0);
                  cVar2 = *pcVar8;
                }
              }
              else {
                iVar9 = _Q_stricmp(pcVar8,s_alphatest);
                if (iVar9 == 0) {
                  pcVar8 = (char *)_COM_ParseExt(param_2,0);
                  if (*pcVar8 == '\0') {
                    (*__ri)(3,s_WARNING__missing_parameter_for__,&_shader);
                  }
                  else {
                    iVar9 = _Q_stricmp(pcVar8,s_equal);
                    if (iVar9 == 0) {
                      uVar10 = 1;
                    }
                    else {
                      iVar9 = _Q_stricmp(pcVar8,s_notequal);
                      if (iVar9 == 0) {
                        uVar10 = 2;
                      }
                      else {
                        iVar9 = _Q_stricmp(pcVar8,s_greater);
                        if (iVar9 == 0) {
                          uVar10 = 3;
                        }
                        else {
                          iVar9 = _Q_stricmp(pcVar8,s_less);
                          if (iVar9 == 0) {
                            uVar10 = 4;
                          }
                          else {
                            iVar9 = _Q_stricmp(pcVar8,s_greaterequal);
                            if (iVar9 == 0) {
                              uVar10 = 5;
                            }
                            else {
                              iVar9 = _Q_stricmp(pcVar8,s_lessequal);
                              uVar10 = 6;
                              if (iVar9 != 0) {
                                uVar10 = local_434;
                              }
                            }
                          }
                        }
                      }
                    }
                    local_434 = uVar10 << 0x18;
                    pcVar8 = (char *)_COM_ParseExt(param_2,0);
                    if (*pcVar8 == '\0') {
                      (*__ri)(3,s_WARNING__missing_constant_for__a,&_shader);
                    }
                    else {
                      dVar13 = _atof(pcVar8);
                      iStack_43c = (int)(longlong)ROUND(dVar13 * ___real_406fe00000000000);
                      local_434 = local_434 | iStack_43c << 0x10;
                    }
                  }
                }
                else {
                  iVar9 = _Q_stricmp(pcVar8,s_alphaFunc);
                  if (iVar9 == 0) {
                    pcVar8 = (char *)_COM_ParseExt(param_2,0);
                    if (*pcVar8 == '\0') {
                      (*__ri)(3,s_WARNING__missing_parameter_for__,&_shader);
                      return 0;
                    }
                    local_434 = _NameToAFunc();
                  }
                  else {
                    iVar9 = _Q_stricmp(pcVar8,s_depthfunc);
                    if (iVar9 == 0) {
                      pcVar8 = (char *)_COM_ParseExt(param_2,0);
                      if (*pcVar8 == '\0') {
                        (*__ri)(3,s_WARNING__missing_parameter_for__,&_shader);
                        return 0;
                      }
                      iVar9 = _Q_stricmp(pcVar8,s_lequal);
                      if (iVar9 == 0) {
                        local_424 = 0;
                      }
                      else {
                        iVar9 = _Q_stricmp(pcVar8,s_equal);
                        if (iVar9 == 0) {
                          local_424 = 0x800;
                        }
                        else {
                          (*__ri)(3,s_WARNING__unknown_depthfunc___s__,pcVar8,&_shader);
                        }
                      }
                    }
                    else {
                      iVar9 = _Q_stricmp(pcVar8,s_detail);
                      if (iVar9 == 0) {
                        param_1[0xb0] = 1;
                      }
                      else {
                        iVar9 = _Q_stricmp(pcVar8,s_blendfunc);
                        if (iVar9 == 0) {
                          pcVar8 = (char *)_COM_ParseExt(param_2,0);
                          if (*pcVar8 == '\0') {
LAB_00017c8d:
                            (*__ri)(3,s_WARNING__missing_parm_for_blendF,&_shader);
                          }
                          else {
                            iVar9 = _Q_stricmp(pcVar8,s_add);
                            if (iVar9 == 0) {
                              local_42c = 2;
                              local_430 = 0x20;
                            }
                            else {
                              iVar9 = _Q_stricmp(pcVar8,s_filter);
                              if (iVar9 == 0) {
                                local_42c = 3;
                                local_430 = 0x10;
                              }
                              else {
                                iVar9 = _Q_stricmp(pcVar8,s_blend);
                                if (iVar9 == 0) {
                                  local_42c = 5;
                                  local_430 = 0x60;
                                }
                                else {
                                  local_42c = _NameToSrcBlendMode();
                                  pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                  if (*pcVar8 == '\0') goto LAB_00017c8d;
                                  local_430 = _NameToDstBlendMode();
                                }
                              }
                            }
                            if (!bVar4) {
                              local_428 = 0;
                            }
                          }
                        }
                        else {
                          iVar9 = _Q_stricmp(pcVar8,s_rgbGen);
                          if (iVar9 == 0) {
                            pcVar8 = (char *)_COM_ParseExt(param_2,0);
                            if (*pcVar8 == '\0') {
                              (*__ri)(3,s_WARNING__missing_parameters_for_,&_shader);
                            }
                            else {
                              iVar9 = _Q_stricmp(pcVar8,s_wave);
                              if (iVar9 == 0) {
                                _ParseWaveForm();
                                param_1[0xa6] = 8;
                              }
                              else {
                                iVar9 = _Q_stricmp(pcVar8,s_colorwave);
                                if (iVar9 == 0) {
                                  _ParseVector(param_2);
                                  fVar3 = (float)___real_406fe00000000000;
                                  iStack_43c._0_1_ = (undefined1)(int)ROUND(fStack_418 * fVar3);
                                  *(undefined1 *)(param_1 + 0xb9) = (undefined1)iStack_43c;
                                  iStack_43c._0_1_ = (undefined1)(int)ROUND(fStack_414 * fVar3);
                                  *(undefined1 *)((int)param_1 + 0x2e5) = (undefined1)iStack_43c;
                                  iStack_43c._0_1_ = (undefined1)(int)ROUND(fVar3 * fStack_410);
                                  *(undefined1 *)((int)param_1 + 0x2e6) = (undefined1)iStack_43c;
                                  _ParseWaveForm();
                                  param_1[0xa6] = 9;
                                }
                                else {
                                  iVar9 = _Q_stricmp(pcVar8,s_identity);
                                  if (iVar9 == 0) {
                                    param_1[0xa6] = 1;
                                  }
                                  else {
                                    iVar9 = _Q_stricmp(pcVar8,s_identityLighting);
                                    if (iVar9 == 0) {
                                      param_1[0xa6] = 2;
                                    }
                                    else {
                                      iVar9 = _Q_stricmp(pcVar8,s_global);
                                      if (iVar9 == 0) {
                                        param_1[0xa6] = 0xf;
                                      }
                                      else {
                                        iVar9 = _Q_stricmp(pcVar8,s_entity);
                                        if ((iVar9 == 0) ||
                                           (iVar9 = _Q_stricmp(pcVar8,s_fromentity), iVar9 == 0)) {
                                          param_1[0xa6] = 3;
                                        }
                                        else {
                                          iVar9 = _Q_stricmp(pcVar8,s_oneMinusEntity);
                                          if (iVar9 == 0) {
                                            param_1[0xa6] = 4;
                                          }
                                          else {
                                            iVar9 = _Q_stricmp(pcVar8,s_vertex);
                                            if ((iVar9 == 0) ||
                                               (iVar9 = _Q_stricmp(pcVar8,s_fromclient), iVar9 == 0)
                                               ) {
                                              param_1[0xa6] = 6;
                                              if (param_1[0xac] == 0) goto LAB_0001810e;
                                            }
                                            else {
                                              iVar9 = _Q_stricmp(pcVar8,s_exactVertex);
                                              if (iVar9 == 0) {
                                                param_1[0xa6] = 5;
                                              }
                                              else {
                                                iVar9 = _Q_stricmp(pcVar8,s_lightingDiffuse);
                                                if (iVar9 == 0) {
                                                  param_1[0xa6] = 10;
                                                }
                                                else {
                                                  iVar9 = _Q_stricmp(pcVar8,s_oneMinusVertex);
                                                  if (iVar9 == 0) {
                                                    param_1[0xa6] = 7;
                                                  }
                                                  else {
                                                    iVar9 = _Q_stricmp(pcVar8,s_globalColor);
                                                    if (iVar9 == 0) {
                                                      param_1[0xa6] = 0xf;
                                                    }
                                                    else {
                                                      iVar9 = _Q_stricmp(pcVar8,s_const);
                                                      if ((iVar9 == 0) ||
                                                         (iVar9 = _Q_stricmp(pcVar8,s_constant),
                                                         iVar9 == 0)) {
                                                        _ParseVector(param_2);
                                                        fVar3 = (float)___real_406fe00000000000;
                                                        param_1[0xa6] = 0xc;
                                                        iStack_43c._0_1_ =
                                                             (undefined1)
                                                             (int)ROUND(fStack_40c * fVar3);
                                                        *(undefined1 *)(param_1 + 0xb9) =
                                                             (undefined1)iStack_43c;
                                                        iStack_43c._0_1_ =
                                                             (undefined1)
                                                             (int)ROUND(fStack_408 * fVar3);
                                                        *(undefined1 *)((int)param_1 + 0x2e5) =
                                                             (undefined1)iStack_43c;
                                                        iStack_43c._0_1_ =
                                                             (undefined1)
                                                             (int)ROUND(fVar3 * uStack_404);
                                                        *(undefined1 *)((int)param_1 + 0x2e6) =
                                                             (undefined1)iStack_43c;
                                                      }
                                                      else {
                                                        (*__ri)(3,s_WARNING__unknown_rgbGen_paramete
                                                                ,pcVar8,&_shader);
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
                            iVar9 = _Q_stricmp(pcVar8,s_alphaGen);
                            if (iVar9 == 0) {
                              pcVar8 = (char *)_COM_ParseExt(param_2,0);
                              if (*pcVar8 == '\0') {
                                (*__ri)(3,s_WARNING__missing_parameters_for_,&_shader);
                              }
                              else {
                                iVar9 = _Q_stricmp(pcVar8,s_wave);
                                if (iVar9 == 0) {
                                  _ParseWaveForm();
                                  param_1[0xac] = 7;
                                }
                                else {
                                  iVar9 = _Q_stricmp(pcVar8,s_identity);
                                  if (iVar9 == 0) {
                                    param_1[0xac] = 0;
                                  }
                                  else {
                                    iVar9 = _Q_stricmp(pcVar8,s_global);
                                    if (iVar9 == 0) {
                                      param_1[0xac] = 0x10;
                                    }
                                    else {
                                      iVar9 = _Q_stricmp(pcVar8,s_entity);
                                      if ((iVar9 == 0) ||
                                         (iVar9 = _Q_stricmp(pcVar8,s_fromentity), iVar9 == 0)) {
                                        param_1[0xac] = 2;
                                      }
                                      else {
                                        iVar9 = _Q_stricmp(pcVar8,s_oneMinusEntity);
                                        if (iVar9 == 0) {
                                          param_1[0xac] = 3;
                                        }
                                        else {
                                          iVar9 = _Q_stricmp(pcVar8,s_vertex);
                                          if ((iVar9 == 0) ||
                                             (iVar9 = _Q_stricmp(pcVar8,s_fromclient), iVar9 == 0))
                                          {
LAB_0001810e:
                                            param_1[0xac] = 4;
                                          }
                                          else {
                                            iVar9 = _Q_stricmp(pcVar8,s_lightingSpecular);
                                            if (iVar9 == 0) {
                                              _DAT_00006284 = 1;
                                              param_1[0xb5] = ___real_437f0000;
                                              param_1[0xb6] = ___real_c4700000;
                                              uVar5 = ___real_44f78000;
                                              param_1[0xac] = 6;
                                              param_1[0xb7] = uVar5;
                                              param_1[0xb8] = ___real_42c00000;
                                              pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                              if (*pcVar8 != '\0') {
                                                dVar13 = _atof(pcVar8);
                                                param_1[0xb5] =
                                                     (float)((float10)dVar13 *
                                                            (float10)___real_406fe00000000000);
                                                _ParseVector(param_2);
                                              }
                                            }
                                            else {
                                              iVar9 = _Q_stricmp(pcVar8,s_oneMinusVertex);
                                              if (iVar9 == 0) {
                                                param_1[0xac] = 5;
                                              }
                                              else {
                                                iVar9 = _Q_stricmp(pcVar8,s_portal);
                                                if (iVar9 == 0) {
                                                  param_1[0xac] = 8;
                                                  pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                                  if (*pcVar8 == '\0') {
                                                    _DAT_00006274 = ___real_43800000;
                                                    (*__ri)(3,s_WARNING__missing_range_parameter,
                                                            &_shader);
                                                  }
                                                  else {
                                                    dVar13 = _atof(pcVar8);
                                                    _DAT_00006274 = (float)dVar13;
                                                  }
                                                }
                                                else {
                                                  iVar9 = _Q_stricmp(pcVar8,s_dot);
                                                  if (iVar9 == 0) {
                                                    _DAT_00006284 = 1;
                                                    param_1[0xb4] = 0;
                                                    param_1[0xb5] = 0x3f800000;
                                                    param_1[0xac] = 0xd;
                                                    pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                                    if (*pcVar8 != '\0') {
                                                      dVar13 = _atof(pcVar8);
LAB_0001842e:
                                                      param_1[0xb4] = (float)dVar13;
                                                      pcVar8 = (char *)_COM_ParseExt(param_3,0);
                                                      if (*pcVar8 != '\0') {
                                                        dVar13 = _atof(pcVar8);
                                                        param_1[0xb5] = (float)dVar13;
                                                      }
                                                    }
                                                  }
                                                  else {
                                                    iVar9 = _Q_stricmp(pcVar8,s_oneMinusDot);
                                                    if (iVar9 == 0) {
                                                      _DAT_00006284 = 1;
                                                      param_1[0xb4] = 0;
                                                      param_1[0xb5] = 0x3f800000;
                                                      param_1[0xac] = 0xe;
                                                      pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                                      if (*pcVar8 != '\0') {
                                                        dVar13 = _atof(pcVar8);
                                                        goto LAB_0001842e;
                                                      }
                                                    }
                                                    else {
                                                      iVar9 = _Q_stricmp(pcVar8,s_globalAlpha);
                                                      if (iVar9 == 0) {
                                                        param_1[0xac] = 0x10;
                                                      }
                                                      else {
                                                        iVar9 = _Q_stricmp(pcVar8,s_const);
                                                        if ((iVar9 == 0) ||
                                                           (iVar9 = _Q_stricmp(pcVar8,s_constant),
                                                           iVar9 == 0)) {
                                                          pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                                          if (*pcVar8 == '\0') {
                                                            (*__ri)(3,
                                                  s_WARNING__no_alphaGen_constant_sp,&_shader);
                                                  }
                                                  else {
                                                    _atof(pcVar8);
                                                    uVar10 = __ftol2_sse();
                                                    if (uVar10 < 0x100) {
                                                      param_1[0xac] = 0xf;
                                                      *(char *)((int)param_1 + 0x2e7) = (char)uVar10
                                                      ;
                                                    }
                                                    else {
                                                      (*__ri)(3,s_WARNING__alphaGen_constant__d_ou,
                                                              uVar10,&_shader);
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    iVar9 = _Q_stricmp(pcVar8,s_skyAlpha);
                                                    if (iVar9 == 0) {
                                                      param_1[0xac] = 0x13;
                                                    }
                                                    else {
                                                      iVar9 = _Q_stricmp(pcVar8,s_oneMinusSkyAlpha);
                                                      if (iVar9 == 0) {
                                                        param_1[0xac] = 0x14;
                                                      }
                                                      else {
                                                        (*__ri)(3,s_WARNING__unknown_alphaGen_parame
                                                                ,pcVar8,&_shader);
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            else {
                              iVar9 = _Q_stricmp(pcVar8,s_texgen);
                              if ((iVar9 == 0) || (iVar9 = _Q_stricmp(pcVar8,s_tcGen), iVar9 == 0))
                              {
                                pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                if (*pcVar8 == '\0') {
                                  (*__ri)(3,s_WARNING__missing_texgen_parm_in_,&_shader);
                                }
                                else {
                                  iVar9 = _Q_stricmp(pcVar8,s_environment);
                                  if (iVar9 == 0) {
                                    _DAT_00006284 = 1;
                                    param_1[local_440 * 0x4f + 0x44] = 4;
                                  }
                                  else {
                                    iVar9 = _Q_stricmp(pcVar8,s_lightmap);
                                    if (iVar9 == 0) {
                                      param_1[local_440 * 0x4f + 0x44] = 2;
                                    }
                                    else {
                                      iVar9 = _Q_stricmp(pcVar8,s_texture);
                                      if ((iVar9 == 0) ||
                                         (iVar9 = _Q_stricmp(pcVar8,s_base), iVar9 == 0)) {
                                        param_1[local_440 * 0x4f + 0x44] = 3;
                                      }
                                      else {
                                        iVar9 = _Q_stricmp(pcVar8,s_vector);
                                        if (iVar9 == 0) {
                                          _ParseVector(param_2);
                                          _ParseVector(param_2);
                                          param_1[local_440 * 0x4f + 0x44] = 6;
                                        }
                                        else {
                                          (*__ri)(3,s_WARNING__unknown_texgen_parm_in_,&_shader);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              else {
                                iVar9 = _Q_stricmp(pcVar8,s_tcMod);
                                if (iVar9 == 0) {
                                  acStack_400[0] = '\0';
                                  _memset(acStack_400 + 1,0,0x3ff);
                                  pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                  cVar2 = *pcVar8;
                                  while (pcVar14 = pcVar8, cVar2 != '\0') {
                                    do {
                                      cVar2 = *pcVar14;
                                      pcVar14 = pcVar14 + 1;
                                    } while (cVar2 != '\0');
                                    uVar10 = (int)pcVar14 - (int)pcVar8;
                                    pcVar14 = (char *)((int)&uStack_404 + 3);
                                    do {
                                      pcVar1 = pcVar14 + 1;
                                      pcVar14 = pcVar14 + 1;
                                    } while (*pcVar1 != '\0');
                                    for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                                      *(undefined4 *)pcVar14 = *(undefined4 *)pcVar8;
                                      pcVar8 = pcVar8 + 4;
                                      pcVar14 = pcVar14 + 4;
                                    }
                                    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                                      *pcVar14 = *pcVar8;
                                      pcVar8 = pcVar8 + 1;
                                      pcVar14 = pcVar14 + 1;
                                    }
                                    pcVar8 = (char *)((int)&uStack_404 + 3);
                                    do {
                                      pcVar14 = pcVar8 + 1;
                                      pcVar8 = pcVar8 + 1;
                                    } while (*pcVar14 != '\0');
                                    *(char (*) [2])pcVar8 = s__;
                                    pcVar8 = (char *)_COM_ParseExt(param_2,0);
                                    cVar2 = *pcVar8;
                                  }
                                  _ParseTexMod(acStack_400);
                                }
                                else {
                                  iVar9 = _Q_stricmp(pcVar8,s_depthwrite);
                                  if ((iVar9 == 0) ||
                                     (iVar9 = _Q_stricmp(pcVar8,s_depthmask), iVar9 == 0)) {
                                    local_428 = 0x100;
                                    bVar4 = true;
                                  }
                                  else {
                                    iVar9 = _Q_stricmp(pcVar8,s_noDepthTest);
                                    if (iVar9 == 0) {
                                      local_41c = 0x400;
                                    }
                                    else {
                                      iVar9 = _Q_stricmp(pcVar8,s_nextBundle);
                                      if (iVar9 == 0) {
                                        if (__qglActiveTextureARB == 0) {
                                          (*__ri)(3,s_WARNING__nextBundle_on_a_card_wi,&_shader);
                                          return 0;
                                        }
                                        iVar9 = local_440 + 2;
                                        param_1[0xa0] = param_1[0xa0] & 0xfffffffd | 1;
                                        local_440 = local_440 + 1;
                                        if (2 < iVar9) {
                                          (*__ri)(3,s_WARNING__too_many_nextBundle_com,&_shader);
                                          return 0;
                                        }
                                      }
                                      else {
                                        iVar9 = _Q_stricmp(pcVar8,s_frameFromEntity);
                                        if (iVar9 != 0) {
                                          pcVar14 = s_WARNING__unknown_parameter___s__;
                                          goto LAB_0001799e;
                                        }
                                        param_1[(local_440 + 1) * 0x4f] = 1;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    pcVar8 = (char *)_COM_ParseExt(param_2,1);
    cVar2 = *pcVar8;
  } while( true );
}



// ===========================================
// Function: _ParseDeform @ 00018b47
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ParseDeform(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  double dVar5;
  
  pcVar1 = (char *)_COM_ParseExt(param_1,0);
  if (*pcVar1 == '\0') {
    (*__ri)(3,s_WARNING__missing_deform_parm_in_,&_shader);
    return;
  }
  if (DAT_000062b8 == 3) {
    (*__ri)(3,s_WARNING__MAX_SHADER_DEFORMS_in__,&_shader);
    return;
  }
  iVar3 = DAT_000062b8 * 0x34;
  DAT_000062b8 = DAT_000062b8 + 1;
  piVar4 = (int *)(&DAT_000062bc + iVar3);
  iVar2 = _Q_stricmp(pcVar1,s_projectionShadow);
  if (iVar2 == 0) {
    *piVar4 = 5;
    return;
  }
  iVar2 = _Q_stricmp(pcVar1,s_autosprite);
  if (iVar2 == 0) {
    *piVar4 = 6;
    return;
  }
  iVar2 = _Q_stricmp(pcVar1,s_autosprite2);
  if (iVar2 == 0) {
    *piVar4 = 7;
    return;
  }
  iVar2 = _Q_stricmpn(pcVar1,s_text,4);
  if (iVar2 == 0) {
    iVar2 = pcVar1[4] + -0x30;
    if ((iVar2 < 0) || (7 < iVar2)) {
      iVar2 = 0;
    }
    *piVar4 = iVar2 + 8;
    _DAT_00006284 = 1;
    return;
  }
  iVar2 = _Q_stricmp(pcVar1,s_bulge);
  if (iVar2 == 0) {
    pcVar1 = (char *)_COM_ParseExt(param_1,0);
    if (*pcVar1 != '\0') {
      dVar5 = _atof(pcVar1);
      *(float *)(&DAT_000062e4 + iVar3) = (float)dVar5;
      pcVar1 = (char *)_COM_ParseExt(param_1,0);
      if (*pcVar1 != '\0') {
        dVar5 = _atof(pcVar1);
        *(float *)(&DAT_000062e8 + iVar3) = (float)dVar5;
        pcVar1 = (char *)_COM_ParseExt(param_1,0);
        if (*pcVar1 != '\0') {
          dVar5 = _atof(pcVar1);
          *(float *)(&DAT_000062ec + iVar3) = (float)dVar5;
          *piVar4 = 3;
          _DAT_00006284 = 1;
          return;
        }
      }
    }
    (*__ri)(3,s_WARNING__missing_deformVertexes_,&_shader);
    return;
  }
  iVar2 = _Q_stricmp(pcVar1,s_wave);
  if (iVar2 == 0) {
    pcVar1 = (char *)_COM_ParseExt(param_1,0);
    if (*pcVar1 != '\0') {
      dVar5 = _atof(pcVar1);
      if ((NAN(dVar5) || NAN(___real_0000000000000000)) == (dVar5 == ___real_0000000000000000)) {
        dVar5 = _atof(pcVar1);
        *(float *)(&DAT_000062e0 + iVar3) = 1.0 / (float)dVar5;
      }
      else {
        *(undefined4 *)(&DAT_000062e0 + iVar3) = ___real_42c80000;
        (*__ri)(3,s_WARNING__illegal_div_value_of_0_,&_shader);
      }
      _ParseWaveForm();
      *piVar4 = 1;
      _DAT_00006284 = 1;
      return;
    }
  }
  else {
    iVar2 = _Q_stricmp(pcVar1,s_normal);
    if (iVar2 == 0) {
      pcVar1 = (char *)_COM_ParseExt(param_1,0);
      if (*pcVar1 != '\0') {
        dVar5 = _atof(pcVar1);
        *(float *)(&DAT_000062d4 + iVar3) = (float)dVar5;
        pcVar1 = (char *)_COM_ParseExt(param_1,0);
        if (*pcVar1 != '\0') {
          dVar5 = _atof(pcVar1);
          *(float *)(&DAT_000062dc + iVar3) = (float)dVar5;
          *piVar4 = 2;
          _DAT_00006284 = 1;
          return;
        }
      }
    }
    else {
      iVar2 = _Q_stricmp(pcVar1,s_wavenormal);
      if (iVar2 != 0) {
        iVar2 = _Q_stricmp(pcVar1,s_move);
        if (iVar2 == 0) {
          _ParseVector(param_1);
          _ParseWaveForm();
          *piVar4 = 4;
          return;
        }
        (*__ri)(3,s_WARNING__unknown_deformVertexes_,pcVar1,&_shader);
        return;
      }
      pcVar1 = (char *)_COM_ParseExt(param_1,0);
      if (*pcVar1 != '\0') {
        dVar5 = _atof(pcVar1);
        if ((NAN(dVar5) || NAN(___real_0000000000000000)) == (dVar5 == ___real_0000000000000000)) {
          dVar5 = _atof(pcVar1);
          *(float *)(&DAT_000062e0 + iVar3) = 1.0 / (float)dVar5;
        }
        else {
          *(undefined4 *)(&DAT_000062e0 + iVar3) = ___real_42c80000;
          (*__ri)(3,s_WARNING__illegal_div_value_of_0_,&_shader);
        }
        _ParseVector(param_1);
        _ParseWaveForm();
        *piVar4 = 0x10;
        _DAT_00006284 = 1;
        return;
      }
    }
  }
  (*__ri)(3,s_WARNING__missing_deformVertexes_,&_shader);
  return;
}



// ===========================================
// Function: _ParseSkyParms @ 00018eb1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ParseSkyParms(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  char *__nptr;
  byte *pbVar6;
  bool bVar7;
  double dVar8;
  undefined1 auStack_40 [64];
  
  pbVar2 = (byte *)_COM_ParseExt();
  if (*pbVar2 == 0) {
    (*__ri)(3,s_WARNING___skyParms__missing_para,&_shader);
    return;
  }
  pbVar6 = &s__;
  pbVar3 = pbVar2;
  do {
    bVar1 = *pbVar3;
    bVar7 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_00018f06:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_00018f0b;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar7 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_00018f06;
    pbVar3 = pbVar3 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00018f0b:
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      _Com_sprintf(auStack_40,0x40,s__s__s_tga,pbVar2,
                   *(undefined4 *)((int)&`ParseSkyParms'::__l2::suf + iVar4));
      iVar5 = _R_FindImageFile(auStack_40,1,1,_shader_force32bit,&DAT_00002900);
      *(int *)((int)&DAT_00006234 + iVar4) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)((int)&DAT_00006234 + iVar4) = __ParseSurfaceParm;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x18);
  }
  __nptr = (char *)_COM_ParseExt();
  if (*__nptr != '\0') {
    dVar8 = _atof(__nptr);
    _DAT_00006230 = (float)dVar8;
    if (NAN(_DAT_00006230) != (_DAT_00006230 == 0.0)) {
      _DAT_00006230 = ___real_44000000;
    }
    _R_InitSkyTexCoords(_DAT_00006230);
    pbVar2 = (byte *)_COM_ParseExt();
    if (*pbVar2 != 0) {
      pbVar6 = &s__;
      pbVar3 = pbVar2;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_00019003:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_00019008;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_00019003;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00019008:
      if (iVar4 != 0) {
        iVar4 = 0;
        do {
          _Com_sprintf(auStack_40,0x40,s__s__s_tga,pbVar2,
                       *(undefined4 *)((int)&`ParseSkyParms'::__l2::suf + iVar4));
          iVar5 = _R_FindImageFile(auStack_40,1,1,_shader_force32bit,&DAT_00002900);
          *(int *)((int)&DAT_0000624c + iVar4) = iVar5;
          if (iVar5 == 0) {
            *(undefined4 *)((int)&DAT_0000624c + iVar4) = __ParseSurfaceParm;
          }
          iVar4 = iVar4 + 4;
        } while (iVar4 < 0x18);
      }
      DAT_0000622c = 1;
      return;
    }
  }
  (*__ri)(3,s_WARNING___skyParms__missing_para,&_shader);
  return;
}



// ===========================================
// Function: _ParseSort @ 00019074
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ParseSort(undefined4 param_1)

{
  char *__nptr;
  int iVar1;
  double dVar2;
  
  __nptr = (char *)_COM_ParseExt(param_1,0);
  if (*__nptr == '\0') {
    (*__ri)(3,s_WARNING__missing_sort_parameter_,&_shader);
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_portal);
  if (iVar1 == 0) {
    _DAT_00006214 = 1.0;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_sky);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_40400000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_opaque);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_40800000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_decal);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_40a00000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_seeThrough);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_40c00000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_banner);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_40e00000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_additive);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_41300000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_nearest);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_41880000;
    return;
  }
  iVar1 = _Q_stricmp(__nptr,s_underwater);
  if (iVar1 == 0) {
    _DAT_00006214 = (float)___real_41100000;
    return;
  }
  dVar2 = _atof(__nptr);
  _DAT_00006214 = (float)dVar2;
  return;
}



// ===========================================
// Function: _ParseShader @ 000191cf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _ParseShader(undefined4 param_1)

{
  char cVar1;
  float fVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  float10 fVar10;
  float10 fVar11;
  double dVar12;
  int local_18;
  int local_10;
  
  local_10 = 0;
  local_18 = 0;
  pcVar3 = (char *)_COM_ParseExt(param_1,1);
  if (*pcVar3 != '{') {
    (*__ri)(3,s_WARNING__expecting______found___,pcVar3,&_shader);
    return 0;
  }
  pcVar3 = (char *)_COM_ParseExt(param_1,1);
  cVar1 = *pcVar3;
  do {
    if (cVar1 == '\0') {
      (*__ri)(3,s_WARNING__no_concluding_____in_sh,&_shader);
      return 0;
    }
    iVar4 = 1;
    if (cVar1 == '}') {
      if ((((local_18 == 0) && (DAT_0000622c == 0)) && (_fogOnly == 0)) &&
         (((DAT_00006224 & 0x40) == 0 && ((DAT_00006220 & 0x80) == 0)))) {
        return 0;
      }
      _DAT_0000621c = 1;
      if ((local_18 != 0) && (_fogOnly != 0)) {
        (*__ri)(3,s_WARNING__shader___s__is_marked_a,&_shader);
      }
      return 1;
    }
    if (cVar1 == '{') {
      iVar4 = _ParseStage(&_unfoggedStages + local_18 * 0xbb,param_1);
      if (iVar4 == 0) {
        return 0;
      }
      (&_unfoggedStages)[local_18 * 0xbb] = 1;
      if (0 < local_18) {
        if ((&DAT_00007694)[local_18 * 0x2ec] == '\0') {
          (*__ri)(3,s_WARNING__shader___s__has_opaque_,&_shader);
        }
        if ((*(uint *)(&DAT_00007694 + local_18 * 0x2ec) & 0x100) != 0) {
          (*__ri)(3,s_WARNING__shader___s__has_depthma,&_shader);
        }
      }
      local_18 = local_18 + 1;
      goto LAB_00019aea;
    }
    iVar5 = _Q_stricmpn(pcVar3,s_qer,3);
    if (iVar5 == 0) {
LAB_00019ae1:
      _SkipRestOfLine(param_1);
    }
    else {
      iVar5 = _Q_stricmp(pcVar3,s_surfaceParm);
      if (((iVar5 == 0) || (iVar5 = _Q_stricmp(pcVar3,s_surfaceLight), iVar5 == 0)) ||
         ((iVar5 = _Q_stricmp(pcVar3,s_surfaceColor), iVar5 == 0 ||
          ((iVar5 = _Q_stricmp(pcVar3,s_surfaceAngle), iVar5 == 0 ||
           (iVar5 = _Q_stricmp(pcVar3,s_surfaceDensity), iVar5 == 0)))))) {
        iVar4 = _Q_stricmp(pcVar3,s_surfaceParm);
        if (iVar4 != 0) goto LAB_00019ae1;
        uVar6 = _COM_ParseExt(param_1,0);
        _ParseSurfaceParm(uVar6,&DAT_00006220,&DAT_00006224);
      }
      else {
        iVar5 = _Q_stricmp(pcVar3,s_q3map_sun);
        if (iVar5 == 0) {
          pcVar3 = (char *)_COM_ParseExt(param_1,0);
          dVar12 = _atof(pcVar3);
          _DAT_0001db48 = (float)dVar12;
          pcVar3 = (char *)_COM_ParseExt(param_1,0);
          dVar12 = _atof(pcVar3);
          _DAT_0001db4c = (float)dVar12;
          pcVar3 = (char *)_COM_ParseExt(param_1,0);
          dVar12 = _atof(pcVar3);
          _DAT_0001db50 = (float)dVar12;
          _VectorNormalize(&DAT_0001db48);
          pcVar3 = (char *)_COM_ParseExt(param_1,0);
          dVar12 = _atof(pcVar3);
          fVar2 = (float)dVar12;
          _DAT_0001db48 = fVar2 * _DAT_0001db48;
          _DAT_0001db4c = _DAT_0001db4c * fVar2;
          _DAT_0001db50 = fVar2 * _DAT_0001db50;
          pcVar3 = (char *)_COM_ParseExt(param_1,0);
          _atof(pcVar3);
          local_18 = 0;
          pcVar3 = (char *)_COM_ParseExt(param_1);
          _atof(pcVar3);
          fVar10 = (float10)__CIcos();
          fVar11 = (float10)__CIcos();
          _DAT_0001db54 = (float)(fVar11 * (float10)(double)fVar10);
          fVar11 = (float10)__CIsin();
          _DAT_0001db58 = (float)(fVar11 * (float10)(double)fVar10);
          fVar10 = (float10)__CIsin();
          _DAT_0001db5c = (float)fVar10;
        }
        else {
          iVar5 = _Q_stricmpn(pcVar3,s_q3map,5);
          if (iVar5 == 0) goto LAB_00019ae1;
          iVar5 = _Q_stricmp(pcVar3,s_deformVertexes);
          if (iVar5 == 0) {
            _ParseDeform(param_1);
            goto LAB_00019aea;
          }
          iVar5 = _Q_stricmp(pcVar3,s_tesssize);
          if (iVar5 == 0) goto LAB_00019ae1;
          iVar5 = _Q_stricmp(pcVar3,s_subdivisions);
          if (iVar5 == 0) {
            pcVar3 = (char *)_COM_ParseExt(param_1,0);
            if (*pcVar3 == '\0') {
              (*__ri)(3,s_WARNING__missing_subdivisions_pa,&_shader);
            }
            else {
              dVar12 = _atof(pcVar3);
              _DAT_00006270 = (float)dVar12;
            }
          }
          else {
            iVar5 = _Q_stricmp(pcVar3,s_nomipmaps);
            if (iVar5 == 0) {
              _shader_noMipMaps = 1;
            }
            else {
              iVar5 = _Q_stricmp(pcVar3,s_nopicmip);
              if (iVar5 == 0) {
                _shader_noPicMip = 1;
              }
              else {
                iVar5 = _Q_stricmp(pcVar3,s_force32bit);
                if (iVar5 == 0) {
                  _shader_force32bit = 1;
                }
                else {
                  iVar5 = _Q_stricmp(pcVar3,s_polygonOffset);
                  if (iVar5 == 0) {
                    DAT_00006280 = 1;
                  }
                  else {
                    iVar5 = _Q_stricmp(pcVar3,s_entityMergable);
                    if (iVar5 == 0) {
                      _DAT_00006228 = 1;
                    }
                    else {
                      iVar5 = _Q_stricmp(pcVar3,s_fogParms);
                      if (iVar5 == 0) {
                        iVar4 = _ParseVector(param_1);
                        if (iVar4 == 0) {
                          return 0;
                        }
                        pcVar3 = (char *)_COM_ParseExt(param_1,0);
                        if (*pcVar3 == '\0') {
                          (*__ri)(3,s_WARNING__missing_depth_for_opaqu,&_shader);
                        }
                        else {
                          dVar12 = _atof(pcVar3);
                          _DAT_000062a0 = (float)dVar12;
                          _SkipRestOfLine(param_1);
                        }
                      }
                      else {
                        iVar5 = _Q_stricmp(pcVar3,s_foggen);
                        if (iVar5 == 0) {
                          _ParseWaveForm();
                        }
                        else {
                          iVar5 = _Q_stricmp(pcVar3,s_portal);
                          if (iVar5 == 0) {
                            _DAT_00006214 = 0x3f800000;
                          }
                          else {
                            iVar5 = _Q_stricmp(pcVar3,s_skyparms);
                            if (iVar5 == 0) {
                              _ParseSkyParms();
                            }
                            else {
                              iVar5 = _Q_stricmp(pcVar3,s_portalsky);
                              if (iVar5 == 0) {
                                DAT_0000626c = 1;
                                _DAT_00006214 = ___real_40000000;
                              }
                              else {
                                iVar5 = _Q_stricmp(pcVar3,s_light);
                                if (iVar5 == 0) {
                                  _COM_ParseExt(param_1,0);
                                }
                                else {
                                  iVar5 = _Q_stricmp(pcVar3,s_spritegen);
                                  if (iVar5 == 0) {
                                    pcVar3 = (char *)_COM_ParseExt(param_1,0);
                                    if (*pcVar3 == '\0') {
                                      (*__ri)(3,s_WARNING__missing_spritegen_parm_,&_shader);
                                    }
                                    else {
                                      iVar4 = _Q_stricmp(pcVar3,s_parallel);
                                      if (iVar4 == 0) {
                                        _DAT_00006268 = 1.0;
                                        _DAT_00006264 = 0;
                                      }
                                      else {
                                        iVar4 = _Q_stricmp(pcVar3,s_parallel_oriented);
                                        if (iVar4 == 0) {
                                          _DAT_00006264 = 1;
                                          _DAT_00006268 = 1.0;
                                        }
                                        else {
                                          iVar4 = _Q_stricmp(pcVar3,s_parallel_upright);
                                          if (iVar4 == 0) {
                                            _DAT_00006264 = 3;
                                            _DAT_00006268 = 1.0;
                                          }
                                          else {
                                            iVar4 = _Q_stricmp(pcVar3,s_oriented);
                                            if (iVar4 == 0) {
                                              _DAT_00006264 = 2;
                                            }
                                            _DAT_00006268 = 1.0;
                                          }
                                        }
                                      }
                                    }
                                  }
                                  else {
                                    iVar5 = _Q_stricmp(pcVar3,s_spritescale);
                                    if (iVar5 == 0) {
                                      pcVar3 = (char *)_COM_ParseExt(param_1,0);
                                      if (*pcVar3 == '\0') {
                                        (*__ri)(3,s_WARNING__missing_spritescale_par,&_shader);
                                      }
                                      else {
                                        dVar12 = _atof(pcVar3);
                                        _DAT_00006268 = (float)dVar12;
                                      }
                                    }
                                    else {
                                      iVar5 = _Q_stricmp(pcVar3,s_cull);
                                      if (iVar5 == 0) {
                                        pcVar3 = (char *)_COM_ParseExt(param_1,0);
                                        if (*pcVar3 == '\0') {
                                          (*__ri)(3,s_WARNING__missing_cull_parms_in_s,&_shader);
                                        }
                                        else {
                                          iVar4 = _Q_stricmp(pcVar3,s_none);
                                          if (((iVar4 == 0) ||
                                              (iVar4 = _Q_stricmp(pcVar3,s_twosided), iVar4 == 0))
                                             || (iVar4 = _Q_stricmp(pcVar3,s_disable), iVar4 == 0))
                                          {
                                            _DAT_0000627c = 2;
                                          }
                                          else {
                                            iVar4 = _Q_stricmp(pcVar3,s_back);
                                            if (((iVar4 == 0) ||
                                                (iVar4 = _Q_stricmp(pcVar3,s_backside), iVar4 == 0))
                                               || (iVar4 = _Q_stricmp(pcVar3,s_backsided),
                                                  iVar4 == 0)) {
                                              _DAT_0000627c = 1;
                                            }
                                            else {
                                              (*__ri)(3,s_WARNING__invalid_cull_parm___s__,pcVar3,
                                                      &_shader);
                                            }
                                          }
                                        }
                                      }
                                      else {
                                        iVar5 = _Q_stricmp(pcVar3,s_fogonly);
                                        if (iVar5 == 0) {
                                          DAT_000073e8 = _DAT_0001ce9c;
                                          _unfoggedStages = 1;
                                          _DAT_00007694 = 0x65;
                                          puVar7 = &_unfoggedStages;
                                          puVar8 = &_foggedStages;
                                          for (iVar4 = 0xbb; iVar4 != 0; iVar4 = iVar4 + -1) {
                                            *puVar8 = *puVar7;
                                            puVar7 = puVar7 + 1;
                                            puVar8 = puVar8 + 1;
                                          }
                                          _fogOnly = 1;
                                        }
                                        else {
                                          iVar5 = _Q_stricmp(pcVar3,s_sort);
                                          if (iVar5 == 0) {
                                            _ParseSort(param_1);
                                          }
                                          else {
                                            iVar5 = _Q_stricmp(pcVar3,s_if);
                                            if (iVar5 == 0) {
                                              uVar6 = _COM_ParseExt(param_1,0);
                                              iVar5 = _Q_stricmp(uVar6,s_mtex);
                                              if (iVar5 == 0) {
                                                bVar9 = __qglActiveTextureARB != 0;
LAB_0001996c:
                                                if (!bVar9) {
LAB_000199ca:
                                                  _SkipRestOfLine(param_1);
                                                  do {
                                                    pcVar3 = (char *)_COM_ParseExt(param_1,1);
                                                    if (*pcVar3 == '\0') {
                                                      (*__ri)(3,s_WARNING__no_matching_endif_in_sh,
                                                              &_shader);
                                                      break;
                                                    }
                                                    iVar5 = _Q_stricmp(pcVar3,s_if);
                                                    if (iVar5 == 0) {
                                                      iVar4 = iVar4 + 1;
LAB_000199fe:
                                                      _SkipRestOfLine(param_1);
                                                    }
                                                    else {
                                                      iVar5 = _Q_stricmp(pcVar3,s_endif);
                                                      if (iVar5 != 0) goto LAB_000199fe;
                                                      iVar4 = iVar4 + -1;
                                                    }
                                                  } while (iVar4 != 0);
                                                  goto LAB_00019aea;
                                                }
                                              }
                                              else {
                                                iVar5 = _Q_stricmp(uVar6,s_no_mtex);
                                                if (iVar5 == 0) {
                                                  bVar9 = __qglActiveTextureARB == 0;
                                                  goto LAB_0001996c;
                                                }
                                                iVar5 = _Q_stricmp(uVar6,s_shaderlod);
                                                if (iVar5 != 0) {
                                                  iVar5 = _Q_stricmp(uVar6,s_0);
                                                  if (iVar5 != 0) {
                                                    iVar5 = _Q_stricmp(uVar6,s_1);
                                                    if (iVar5 == 0) goto LAB_00019970;
                                                    (*__ri)(3,s_WARNING__invalid_if_argument___s,
                                                            uVar6,&_shader);
                                                  }
                                                  goto LAB_000199ca;
                                                }
                                                pcVar3 = (char *)_COM_ParseExt(param_1,1);
                                                dVar12 = _atof(pcVar3);
                                                if ((double)*(float *)(__r_shaderlod + 0x1c) <=
                                                    dVar12) goto LAB_000199ca;
                                              }
LAB_00019970:
                                              local_10 = local_10 + 1;
                                            }
                                            else {
                                              iVar4 = _Q_stricmp(pcVar3,s_endif);
                                              if (iVar4 != 0) {
                                                (*__ri)(3,s_WARNING__unknown_general_shader_,pcVar3,
                                                        &_shader);
                                                return 0;
                                              }
                                              local_10 = local_10 + -1;
                                              if (local_10 < 0) {
                                                (*__ri)(3,s_WARNING__unmatched_endif_in_shad,
                                                        &_shader);
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_00019aea:
    pcVar3 = (char *)_COM_ParseExt(param_1,1);
    cVar1 = *pcVar3;
  } while( true );
}



// ===========================================
// Function: _ComputeStageIteratorFunc @ 00019b98
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ComputeStageIteratorFunc(void)

{
  _DAT_000063d4 = &_RB_StageIteratorGeneric;
  if (DAT_0000622c != 0) {
    _DAT_000063d4 = &_RB_StageIteratorSky;
    return;
  }
  if ((*(int *)(__r_ignoreFastPath + 0x20) == 0) && (DAT_00006358 == 1)) {
    if (DAT_00007678 == 10) {
      if (((DAT_00007690 == 0) && (DAT_000074f0 == 3)) &&
         ((DAT_00006280 == 0 && ((DAT_00007660 == 0 && (DAT_000062b8 == 0)))))) {
        _DAT_000063d4 = &_RB_StageIteratorVertexLitTextureUnfogged;
        return;
      }
    }
    else if (((((DAT_00007678 == 1) && (DAT_00007690 == 0)) && (DAT_000074f0 == 3)) &&
             ((DAT_0000762c == 2 && (DAT_00006280 == 0)))) &&
            ((DAT_000062b8 == 0 && (DAT_00007660 != 0)))) {
      _DAT_000063d4 = &_RB_StageIteratorLightmappedMultitextureUnfogged;
    }
  }
  return;
}



// ===========================================
// Function: _CollapseMultitexture @ 00019c5a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CollapseMultitexture(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  float *pfVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *local_2c;
  int local_28;
  undefined1 uStack_24;
  float local_20 [7];
  float local_4;
  
  local_28 = 0;
  if (*param_1 != 1 && -1 < *param_1 + -1) {
    fVar5 = (float)___real_3f70101020000000;
    local_2c = &DAT_00007660;
    do {
      fVar4 = 1.0;
      if (local_2c[-0xa0] == 0) {
        return;
      }
      if (local_2c[0x1b] == 0) {
        return;
      }
      if ((*local_2c == 0) &&
         ((_DAT_0001e2fc != 2 ||
          (*(int *)(local_2c[-0x9e] + 0x5c) != *(int *)(local_2c[0x1d] + 0x5c))))) {
        uVar7 = local_2c[0xd] & 0xff;
        uVar12 = local_2c[200] & 0xff;
        if (uVar7 == 0x12) {
          uVar7 = 0;
        }
        if ((((local_2c[200] ^ local_2c[0xd]) & 0xfffffe00) == 0) &&
           ((uVar7 == uVar12 || (uVar7 == 0)))) {
          iVar10 = 0;
          uVar7 = `CollapseMultitexture'::__l2::mtexBlends;
          while ((uVar7 != 0 && (uVar12 != uVar7))) {
            iVar6 = iVar10 * 2;
            iVar10 = iVar10 + 1;
            uVar7 = (&DAT_00008c20)[iVar6];
          }
          if ((((&`CollapseMultitexture'::__l2::mtexBlends)[iVar10 * 2] != 0) &&
              (((uVar7 = *(uint *)(iVar10 * 8 + 0x8c1c), uVar7 != 2 || (_DAT_0001e30c != 0)) &&
               (uVar12 = local_2c[6], uVar12 == local_2c[0xc1])))) &&
             (local_2c[0xc] == local_2c[199])) {
            if ((uVar12 == 8) || (uVar12 == 9)) {
              puVar8 = local_2c + 0xbc;
              uVar12 = 0x14;
              iVar10 = 4 - (int)puVar8;
              do {
                if (*(uint *)((int)local_2c + iVar10 + (int)puVar8) != *puVar8) goto LAB_00019ff3;
                uVar12 = uVar12 - 4;
                puVar8 = puVar8 + 1;
              } while (3 < uVar12);
            }
            if (local_2c[0xc] == 7) {
              puVar8 = local_2c + 0xc2;
              uVar12 = 0x14;
              iVar10 = 0x1c - (int)puVar8;
              do {
                if (*(uint *)((int)local_2c + iVar10 + (int)puVar8) != *puVar8) goto LAB_00019ff3;
                uVar12 = uVar12 - 4;
                puVar8 = puVar8 + 1;
              } while (3 < uVar12);
            }
            *local_2c = *local_2c & 0xfffffffc | uVar7;
            pbVar11 = (byte *)((int)local_2c + 0x65);
            iVar10 = 2;
            pfVar9 = local_20 + 1;
            do {
              bVar1 = *pbVar11;
              bVar2 = pbVar11[1];
              pfVar9[-1] = (float)pbVar11[-1];
              bVar3 = pbVar11[2];
              *pfVar9 = (float)bVar1;
              pbVar11 = pbVar11 + 0x2ec;
              pfVar9[1] = (float)bVar2;
              iVar10 = iVar10 + -1;
              pfVar9[2] = (float)bVar3;
              pfVar9[-1] = pfVar9[-1] * fVar5;
              *pfVar9 = *pfVar9 * fVar5;
              pfVar9[1] = pfVar9[1] * fVar5;
              pfVar9[2] = pfVar9[2] * fVar5;
              pfVar9 = pfVar9 + 4;
            } while (iVar10 != 0);
            if ((uVar7 & 3) == 1) {
              local_20[0] = local_20[0] * local_20[4];
              local_20[1] = local_20[1] * local_20[5];
              local_20[2] = local_20[2] * local_20[6];
              local_20[3] = local_20[3] * local_4;
            }
            else if ((uVar7 & 3) == 2) {
              local_20[0] = local_20[0] + local_20[4];
              if (local_20[0] < 1.0 != NAN(local_20[0])) {
                local_20[0] = fVar4;
              }
              local_20[1] = local_20[1] + local_20[5];
              if (local_20[1] < 1.0 != NAN(local_20[1])) {
                local_20[1] = fVar4;
              }
              local_20[2] = local_20[2] + local_20[6];
              if (local_20[2] < 1.0 != NAN(local_20[2])) {
                local_20[2] = fVar4;
              }
              local_20[3] = local_20[3] + local_4;
              if (local_20[3] < 1.0 == NAN(local_20[3])) {
              }
              else {
                local_20[3] = 1.0;
              }
            }
            else {
              (*__ri)(3,s_Unknown_MT_mode_collapsing_multi,&_shader);
            }
            iVar10 = 0;
            puVar8 = local_2c + 0x19;
            do {
              pfVar9 = local_20 + iVar10;
              iVar10 = iVar10 + 1;
              uStack_24 = (undefined1)(int)ROUND(*pfVar9 * (float)___real_406fe00000000000);
              *(undefined1 *)puVar8 = uStack_24;
              puVar8 = (uint *)((int)puVar8 + 0x2ed);
            } while (iVar10 < 4);
            iVar10 = 0x4f;
            puVar8 = local_2c + -0x4f;
            if (local_2c[-0x53] != 0) {
              puVar8 = local_2c + -0x9e;
              puVar13 = puVar8;
              puVar14 = local_2c + -0x4f;
              for (; iVar10 != 0; iVar10 = iVar10 + -1) {
                *puVar14 = *puVar13;
                puVar13 = puVar13 + 1;
                puVar14 = puVar14 + 1;
              }
            }
            puVar13 = local_2c + 0x1d;
            for (iVar10 = 0x4f; iVar10 != 0; iVar10 = iVar10 + -1) {
              *puVar8 = *puVar13;
              puVar13 = puVar13 + 1;
              puVar8 = puVar8 + 1;
            }
            if (local_28 + 2 < 8) {
              _memmove(local_2c + 0x1b,local_2c + 0xd6,(6 - local_28) * 0x2ec);
            }
            _memset(&DAT_00008854,0,0x2ec);
            fVar5 = (float)___real_3f70101020000000;
            *param_4 = *param_4 + -1;
          }
        }
      }
LAB_00019ff3:
      local_28 = local_28 + 1;
      local_2c = local_2c + 0xbb;
    } while (local_28 < *param_1 + -1);
  }
  return;
}



// ===========================================
// Function: _SortNewShader @ 0001a027
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SortNewShader(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(&DAT_00060df0 + _DAT_00060df0 * 4);
  fVar1 = *(float *)(iVar2 + 0x4c);
  iVar3 = _DAT_00060df0 + -2;
  if (-1 < iVar3) {
    if (3 < _DAT_00060df0 + -1) {
      do {
        iVar4 = *(int *)(&DAT_00061df4 + iVar3 * 4);
        if (*(float *)(iVar4 + 0x4c) < fVar1 != (*(float *)(iVar4 + 0x4c) == fVar1))
        goto LAB_0001a152;
        *(int *)(iVar3 * 4 + 0x61df8) = iVar4;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        iVar4 = *(int *)(iVar3 * 4 + 0x61df0);
        if (*(float *)(iVar4 + 0x4c) < fVar1 != (*(float *)(iVar4 + 0x4c) == fVar1)) {
          *(int *)(iVar2 + 0x48) = iVar3;
          *(int *)((iVar3 + -1) * 4 + 0x61df8) = iVar2;
          return;
        }
        *(int *)(&DAT_00061df4 + iVar3 * 4) = iVar4;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        iVar4 = *(int *)(iVar3 * 4 + 0x61dec);
        if (*(float *)(iVar4 + 0x4c) < fVar1 != (*(float *)(iVar4 + 0x4c) == fVar1)) {
          *(int *)(iVar2 + 0x48) = iVar3 + -1;
          *(int *)((iVar3 + -2) * 4 + 0x61df8) = iVar2;
          return;
        }
        *(int *)(iVar3 * 4 + 0x61df0) = iVar4;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        iVar4 = *(int *)(iVar3 * 4 + 0x61de8);
        if (*(float *)(iVar4 + 0x4c) < fVar1 != (*(float *)(iVar4 + 0x4c) == fVar1)) {
          iVar3 = iVar3 + -3;
          goto LAB_0001a152;
        }
        *(int *)(iVar3 * 4 + 0x61dec) = iVar4;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        iVar3 = iVar3 + -4;
      } while (2 < iVar3);
    }
    iVar4 = iVar3;
    if (-1 < iVar3) {
      while (iVar3 = iVar4, iVar4 = *(int *)(&DAT_00061df4 + iVar3 * 4),
            *(float *)(iVar4 + 0x4c) < fVar1 == (*(float *)(iVar4 + 0x4c) == fVar1)) {
        *(int *)(iVar3 * 4 + 0x61df8) = iVar4;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        iVar4 = iVar3 + -1;
        if (iVar4 < 0) {
          *(int *)(iVar2 + 0x48) = iVar3;
          *(int *)(iVar4 * 4 + 0x61df8) = iVar2;
          return;
        }
      }
    }
  }
LAB_0001a152:
  *(int *)(iVar2 + 0x48) = iVar3 + 1;
  *(int *)(iVar3 * 4 + 0x61df8) = iVar2;
  return;
}



// ===========================================
// Function: _VertexLightingCollapse @ 0001a4c7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _VertexLightingCollapse(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  iVar3 = DAT_00006208;
  if ((NAN(___real_40800000) || NAN(_DAT_00006214)) != (___real_40800000 == _DAT_00006214)) {
    piVar4 = &_unfoggedStages;
    iVar6 = -999999;
    piVar1 = &DAT_000074f0;
    do {
      if (piVar1[-0x44] == 0) break;
      iVar2 = 0;
      if (piVar1[9] != 0) {
        iVar2 = -100;
      }
      if (*piVar1 != 3) {
        iVar2 = iVar2 + -5;
      }
      if (piVar1[7] != 0) {
        iVar2 = iVar2 + -5;
      }
      if ((piVar1[0x62] != 1) && (piVar1[0x62] != 2)) {
        iVar2 = iVar2 + -3;
      }
      if (iVar6 < iVar2) {
        piVar4 = piVar1 + -0x44;
        iVar6 = iVar2;
      }
      if (piVar1[0x77] == 0) break;
      iVar2 = 0;
      if (piVar1[0xc4] != 0) {
        iVar2 = -100;
      }
      if (piVar1[0xbb] != 3) {
        iVar2 = iVar2 + -5;
      }
      if (piVar1[0xc2] != 0) {
        iVar2 = iVar2 + -5;
      }
      if ((piVar1[0x11d] != 1) && (piVar1[0x11d] != 2)) {
        iVar2 = iVar2 + -3;
      }
      if (iVar6 < iVar2) {
        piVar4 = piVar1 + 0x77;
        iVar6 = iVar2;
      }
      if (piVar1[0x132] == 0) break;
      iVar2 = 0;
      if (piVar1[0x17f] != 0) {
        iVar2 = -100;
      }
      if (piVar1[0x176] != 3) {
        iVar2 = iVar2 + -5;
      }
      if (piVar1[0x17d] != 0) {
        iVar2 = iVar2 + -5;
      }
      if ((piVar1[0x1d8] != 1) && (piVar1[0x1d8] != 2)) {
        iVar2 = iVar2 + -3;
      }
      if (iVar6 < iVar2) {
        piVar4 = piVar1 + 0x132;
        iVar6 = iVar2;
      }
      if (piVar1[0x1ed] == 0) break;
      iVar2 = 0;
      if (piVar1[0x23a] != 0) {
        iVar2 = -100;
      }
      if (piVar1[0x231] != 3) {
        iVar2 = iVar2 + -5;
      }
      if (piVar1[0x238] != 0) {
        iVar2 = iVar2 + -5;
      }
      if ((piVar1[0x293] != 1) && (piVar1[0x293] != 2)) {
        iVar2 = iVar2 + -3;
      }
      if (iVar6 < iVar2) {
        piVar4 = piVar1 + 0x1ed;
        iVar6 = iVar2;
      }
      piVar1 = piVar1 + 0x2ec;
    } while ((int)piVar1 < 0x8c50);
    piVar4 = piVar4 + 2;
    piVar1 = &DAT_000073e8;
    for (iVar6 = 0x4f; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar1 = piVar1 + 1;
    }
    _DAT_00007694 = _DAT_00007694 & 0xffffff00;
    _DAT_00007694 = _DAT_00007694 | 0x100;
    DAT_00007678 = (-(uint)(iVar3 != -1) & 0xfffffffb) + 10;
    DAT_00007690 = 1;
    goto LAB_0001a6f2;
  }
  if (DAT_00007514 != 0) {
    puVar5 = &DAT_000076cc;
    puVar7 = &_unfoggedStages;
    for (iVar3 = 0xbb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  if ((DAT_00007678 != 4) && (DAT_00007964 != 4)) {
    if (DAT_00007678 != 8) goto LAB_0001a6f2;
    if (DAT_00007664 == 4) {
      if (DAT_00007964 != 8) goto LAB_0001a6f2;
      bVar8 = DAT_00007950 == 5;
    }
    else {
      if ((DAT_00007664 != 5) || (DAT_00007964 != 8)) goto LAB_0001a6f2;
      bVar8 = DAT_00007950 == 4;
    }
    if (!bVar8) goto LAB_0001a6f2;
  }
  DAT_00007678 = 2;
LAB_0001a6f2:
  piVar4 = &DAT_000076cc;
  do {
    if (*piVar4 == 0) {
      return;
    }
    _memset(piVar4,0,0x2ec);
    piVar4 = piVar4 + 0xbb;
  } while ((int)piVar4 < 0x8b40);
  return;
}



// ===========================================
// Function: _FinishShader @ 0001a71d
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _FinishShader(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint extraout_EDX;
  undefined4 *unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar9;
  undefined4 unaff_ESI;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  size_t sVar13;
  undefined4 unaff_EDI;
  int *piVar14;
  uint uVar15;
  int *local_4;
  
  if (_currentShader == 0) {
    _currentShader = _FindShaderText();
  }
  iVar6 = _currentShader;
  bVar1 = false;
  if (DAT_00006218 != 0) {
    _currentShader = 0;
    *(undefined4 **)(iVar6 + 0x44) = _DAT_0001cea4;
    return _DAT_0001cea4;
  }
  if (DAT_0000626c != 0) {
    _DAT_00006214 = ___real_40000000;
  }
  if (DAT_0000622c != 0) {
    _DAT_00006214 = ___real_40400000;
  }
  if ((DAT_00006280 != 0) && (NAN(_DAT_00006214) != (_DAT_00006214 == 0.0))) {
    _DAT_00006214 = ___real_40a00000;
  }
  if (_fogOnly != 0) {
    _DAT_00006214 = ___real_41000000;
    puVar9 = &_unfoggedStages;
    puVar12 = &_foggedStages;
    for (iVar6 = 0xbb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar12 = puVar12 + 1;
    }
    _unfoggedStages = 0;
  }
  piVar14 = (int *)0x0;
  _DAT_000063c4 = 0;
  local_4 = (int *)0x0;
  piVar10 = &_unfoggedStages;
  do {
    if (*piVar10 == 0) break;
    if (piVar10[2] == 0) {
      (*__ri)(3,s_Shader__s_has_a_stage_with_no_im,&_shader);
      *piVar10 = 0;
    }
    else {
      if (piVar10[0xa6] == 10) {
        _DAT_000063c4 = 1;
      }
      piVar5 = piVar10 + 0x44;
      iVar6 = 2;
      do {
        if (piVar5[9] == 0) {
          if (*piVar5 == 0) {
            *piVar5 = 3;
          }
        }
        else {
          if (*piVar5 == 0) {
            *piVar5 = 2;
          }
          bVar1 = true;
        }
        piVar5 = piVar5 + 0x4f;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar8 = piVar10[0xad];
      if (((char)uVar8 != '\0') && (DAT_00007694 != '\0')) {
        uVar7 = uVar8 & 0xf;
        uVar15 = uVar8 & 0xf0;
        if (_fogOnly == 0) {
          if (uVar7 == 2) {
            if (uVar15 == 0x20) {
LAB_0001a8cc:
              piVar10[0xae] = 1;
            }
            else if (uVar15 == 0x60) {
              piVar10[0xae] = 2;
            }
          }
          else if (uVar7 == 1) {
            if (uVar15 == 0x40) goto LAB_0001a8cc;
          }
          else if ((uVar7 == 5) && ((uVar15 == 0x60 || (uVar15 == 0x20)))) {
            piVar10[0xae] = 3;
          }
        }
        if ((NAN(_DAT_00006214) != (_DAT_00006214 == 0.0)) &&
           (_DAT_00006214 = ___real_41200000, (uVar8 & 0x100) != 0)) {
          _DAT_00006214 = ___real_40c00000;
        }
      }
    }
    piVar10 = piVar10 + 0xbb;
    piVar14 = (int *)((int)piVar14 + 1);
  } while ((int)piVar10 < 0x8b40);
  if (NAN(_DAT_00006214) != (_DAT_00006214 == 0.0)) {
    _DAT_00006214 = ___real_40800000;
  }
  local_4 = piVar14;
  if (1 < (int)piVar14) {
    if ((*(int *)(__r_vertexLight + 0x20) == 0) && (_DAT_0001e300 != 4)) {
      if (__qglActiveTextureARB != 0) {
        _CollapseMultitexture(&local_4);
        piVar14 = local_4;
      }
    }
    else {
      _VertexLightingCollapse();
      bVar1 = false;
      piVar14 = (int *)&_feat_00;
    }
  }
  if ((-1 < DAT_00006208) && (!bVar1)) {
    (*__ri)(3,s_WARNING__shader___s__has_lightma,&_shader);
    DAT_00006208 = -1;
  }
  if ((((__qglTextureEnvCombineExists != 0) && (_unfoggedStages != 0)) && (DAT_000076cc == 0)) &&
     (((DAT_00007678 == 1 && (DAT_00007690 == 0)) &&
      (((_DAT_00007694 & 0xff) == 0 || (((byte)_DAT_00007694 & 0x12) == 0x12)))))) {
    DAT_00007678 = 0xe;
    DAT_00007690 = 0x11;
  }
  if ((-1 < DAT_00006208) && (!bVar1)) {
    (*__ri)(3,s_WARNING__shader___s__has_lightma,&_shader);
    DAT_00006208 = -1;
  }
  if (_fogOnly == 0) {
    _memcpy(&_foggedStages,&_unfoggedStages,0x1760);
    _memcpy(&_alphaFoggedStages,&_unfoggedStages,0x1760);
  }
  if ((int)piVar14 < 8) {
    uVar8 = 0;
    if (0 < (int)piVar14) {
      uVar8 = *(uint *)((int)piVar14 * 0x2ec + 0x73a8) & 0xd00;
    }
    iVar6 = (int)piVar14 * 0x2ec;
    if (*(int *)(iVar6 + 0x4d24) == 0) {
      (&_foggedStages)[(int)piVar14 * 0xbb] = 1;
      (&DAT_00004d00)[(int)piVar14 * 0xbb] = 0xb;
      *(undefined4 *)(iVar6 + 0x4d18) = 0;
      (&DAT_00004d1c)[(int)piVar14 * 0xbb] = uVar8 | 0x65;
      *(undefined4 *)(iVar6 + 0x4a70) = __r_shaderlod;
      *(undefined4 *)(iVar6 + 0x4d24) = 1;
      *(undefined4 *)(iVar6 + 0x4b78) = 5;
    }
    if (*(int *)(iVar6 + 0x22bc) == 0) {
      *(undefined4 *)(iVar6 + 0x2000) = 1;
      (&DAT_00002298)[(int)piVar14 * 0xbb] = 0x10;
      *(undefined4 *)(iVar6 + 0x22b0) = 0x12;
      (&DAT_000022b4)[(int)piVar14 * 0xbb] = uVar8 | 0x65;
      uVar4 = _DAT_0001ce9c;
      *(undefined4 *)(iVar6 + 0x22bc) = 1;
      *(undefined4 *)(iVar6 + 0x2008) = uVar4;
      *(undefined4 *)(iVar6 + 0x2110) = 1;
    }
  }
  else {
    (*_DAT_0001ce1c)(1,s_WARNING__overflowed_shader_stage,&_shader);
  }
  piVar14 = &DAT_00007678;
  do {
    piVar14[8] = 0;
    if (*piVar14 == 0xe) {
      *piVar14 = 1;
    }
    if (piVar14[6] == 0x11) {
      piVar14[6] = 0;
    }
    piVar14 = piVar14 + 0xbb;
  } while ((int)piVar14 < 0x8dd8);
  uVar15 = 0;
  uVar8 = 0;
  iVar11 = 0;
  iVar6 = 0;
  do {
    if (*(int *)((int)&_foggedStages + iVar6) != 0) {
      uVar15 = uVar15 + 1;
    }
    if (*(int *)((int)&_unfoggedStages + iVar6) != 0) {
      uVar8 = uVar8 + 1;
    }
    if (*(int *)(iVar6 + 0x2000) != 0) {
      iVar11 = iVar11 + 1;
    }
    if (*(int *)((int)&DAT_00004d54 + iVar6) != 0) {
      uVar15 = uVar15 + 1;
    }
    if (*(int *)((int)&DAT_000076cc + iVar6) != 0) {
      uVar8 = uVar8 + 1;
    }
    if (*(int *)((int)&DAT_000022ec + iVar6) != 0) {
      iVar11 = iVar11 + 1;
    }
    if (*(int *)((int)&DAT_00005040 + iVar6) != 0) {
      uVar15 = uVar15 + 1;
    }
    if (*(int *)((int)&DAT_000079b8 + iVar6) != 0) {
      uVar8 = uVar8 + 1;
    }
    if (*(int *)((int)&DAT_000025d8 + iVar6) != 0) {
      iVar11 = iVar11 + 1;
    }
    if (*(int *)((int)&DAT_0000532c + iVar6) != 0) {
      uVar15 = uVar15 + 1;
    }
    if (*(int *)((int)&DAT_00007ca4 + iVar6) != 0) {
      uVar8 = uVar8 + 1;
    }
    if (*(int *)((int)&DAT_000028c4 + iVar6) != 0) {
      iVar11 = iVar11 + 1;
    }
    iVar6 = iVar6 + 0xbb0;
  } while (iVar6 < 0x1760);
  iVar6 = 0;
  DAT_00006358 = uVar8;
  _DAT_0000637c = uVar15;
  _DAT_000063a0 = iVar11;
  do {
    if (*(int *)((int)&DAT_00004d00 + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_00004ce8 + iVar6) == 0) {
        *(uint *)((int)&DAT_00004d1c + iVar6) = *(uint *)((int)&DAT_00004d1c + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_00004d1c + iVar6) = *(uint *)((int)&DAT_00004d1c + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_00002298 + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_00002280 + iVar6) == 0) {
        *(uint *)((int)&DAT_000022b4 + iVar6) = *(uint *)((int)&DAT_000022b4 + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_000022b4 + iVar6) = *(uint *)((int)&DAT_000022b4 + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_00004fec + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_00004fd4 + iVar6) == 0) {
        *(uint *)((int)&DAT_00005008 + iVar6) = *(uint *)((int)&DAT_00005008 + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_00005008 + iVar6) = *(uint *)((int)&DAT_00005008 + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_00002584 + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_0000256c + iVar6) == 0) {
        *(uint *)((int)&DAT_000025a0 + iVar6) = *(uint *)((int)&DAT_000025a0 + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_000025a0 + iVar6) = *(uint *)((int)&DAT_000025a0 + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_000052d8 + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_000052c0 + iVar6) == 0) {
        *(uint *)((int)&DAT_000052f4 + iVar6) = *(uint *)((int)&DAT_000052f4 + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_000052f4 + iVar6) = *(uint *)((int)&DAT_000052f4 + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_00002870 + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_00002858 + iVar6) == 0) {
        *(uint *)((int)&DAT_0000288c + iVar6) = *(uint *)((int)&DAT_0000288c + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_0000288c + iVar6) = *(uint *)((int)&DAT_0000288c + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_000055c4 + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_000055ac + iVar6) == 0) {
        *(uint *)((int)&DAT_000055e0 + iVar6) = *(uint *)((int)&DAT_000055e0 + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_000055e0 + iVar6) = *(uint *)((int)&DAT_000055e0 + iVar6) | 0x4000;
      }
    }
    if (*(int *)((int)&DAT_00002b5c + iVar6) == 0xe) {
      if (*(int *)((int)&DAT_00002b44 + iVar6) == 0) {
        *(uint *)((int)&DAT_00002b78 + iVar6) = *(uint *)((int)&DAT_00002b78 + iVar6) | 0x2000;
      }
      else {
        *(uint *)((int)&DAT_00002b78 + iVar6) = *(uint *)((int)&DAT_00002b78 + iVar6) | 0x4000;
      }
    }
    iVar6 = iVar6 + 0xbb0;
  } while (iVar6 < 0x1760);
  if (_fogOnly == 0) {
    if (DAT_00004d00 == 0xe) {
      uVar15 = uVar15 - 1;
      _DAT_0000637c = uVar15;
    }
    else if (((char)DAT_00004d1c != '\0') && (DAT_00004d20 != 0)) {
      uVar15 = uVar15 - 1;
      _DAT_0000637c = uVar15;
    }
    if (DAT_00002298 == 0xe) {
      _DAT_000063a0 = iVar11 + -1;
    }
    else if (((char)DAT_000022b4 != '\0') && (DAT_000022b8 != 0)) {
      _DAT_000063a0 = iVar11 + -1;
    }
  }
  _DAT_000063cc = 0;
  iVar6 = 0;
  do {
    if (*(int *)(iVar6 + 0x2000) != 0) {
      *(undefined4 *)((int)&DAT_00002004 + iVar6) = 1;
      _DAT_000063cc = _DAT_000063cc | 4;
    }
    if ((uVar8 == uVar15) && (*(int *)((int)&_foggedStages + iVar6) != 0)) {
      *(undefined4 *)((int)&DAT_00004a6c + iVar6) = 1;
      _DAT_000063cc = _DAT_000063cc | 2;
    }
    iVar6 = iVar6 + 0x2ec;
  } while (iVar6 < 0x1760);
  _ComputeStageIteratorFunc();
  _DAT_000063c8 = (uint)(*(int *)(__r_toggle + 0x20) != 0);
  if (((DAT_00006358 == extraout_EDX) && (DAT_00007678 == 10)) && (DAT_00007690 == 0)) {
    _DAT_000063c8 = extraout_EDX;
  }
  if (_DAT_00060df0 == 0x400) {
    (*__ri)(3,s_WARNING__GeneratePermanentShader);
    *(undefined4 **)(_currentShader + 0x44) = _DAT_0001cea4;
    _currentShader = 0;
    return _DAT_0001cea4;
  }
  puVar2 = (undefined4 *)(*__Q_stricmp)(0x214,unaff_EDI,unaff_ESI,unaff_EBP);
  iVar6 = _currentShader;
  puVar9 = &_shader;
  puVar12 = puVar2;
  for (iVar11 = 0x85; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar12 = puVar12 + 1;
  }
  puVar2[0x84] = *(undefined4 *)(iVar6 + 0x44);
  *(undefined4 **)(iVar6 + 0x44) = puVar2;
  *(undefined4 **)(&DAT_00060df4 + _DAT_00060df0 * 4) = puVar2;
  puVar2[0x11] = _DAT_00060df0;
  *(undefined4 **)(&DAT_00061df4 + _DAT_00060df0 * 4) = puVar2;
  puVar2[0x12] = _DAT_00060df0;
  _DAT_00060df0 = _DAT_00060df0 + 1;
  iVar6 = 0;
  if (0 < (int)puVar2[100]) {
    piVar10 = &_unfoggedStages;
    piVar14 = puVar2 + 0x65;
    do {
      if (*piVar10 == 0) {
        puVar2[100] = iVar6;
        break;
      }
      piVar3 = (int *)(*__Q_stricmp)(0x2ec);
      *piVar14 = (int)piVar3;
      piVar5 = piVar10;
      for (iVar11 = 0xbb; iVar11 != 0; iVar11 = iVar11 + -1) {
        *piVar3 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar3 = piVar3 + 1;
      }
      iVar11 = 0;
      local_4 = piVar10 + 0x4c;
      do {
        sVar13 = *(int *)(iVar11 + 300 + *piVar14) * 0x4c;
        if (sVar13 != 0) {
          uVar4 = (*__Q_stricmp)(sVar13);
          *(undefined4 *)(iVar11 + 0x130 + *piVar14) = uVar4;
          _memcpy(*(void **)(iVar11 + 0x130 + *piVar14),(void *)*unaff_EBX,sVar13);
        }
        local_4 = local_4 + 0x4f;
        iVar11 = iVar11 + 0x13c;
      } while (iVar11 < 0x278);
      piVar10 = piVar10 + 0xbb;
      iVar6 = iVar6 + 1;
      piVar14 = piVar14 + 1;
    } while (iVar6 < (int)puVar2[100]);
  }
  iVar6 = 0;
  if (0 < (int)puVar2[0x6d]) {
    piVar10 = &_foggedStages;
    piVar14 = puVar2 + 0x6e;
    do {
      if (*piVar10 == 0) {
        puVar2[0x6d] = iVar6;
        break;
      }
      piVar3 = (int *)(*__Q_stricmp)(0x2ec);
      *piVar14 = (int)piVar3;
      piVar5 = piVar10;
      for (iVar11 = 0xbb; iVar11 != 0; iVar11 = iVar11 + -1) {
        *piVar3 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar3 = piVar3 + 1;
      }
      iVar11 = 0;
      local_4 = piVar10 + 0x4c;
      do {
        sVar13 = *(int *)(iVar11 + 300 + *piVar14) * 0x4c;
        if (sVar13 != 0) {
          uVar4 = (*__Q_stricmp)(sVar13);
          *(undefined4 *)(iVar11 + 0x130 + *piVar14) = uVar4;
          _memcpy(*(void **)(iVar11 + 0x130 + *piVar14),(void *)*unaff_EBX,sVar13);
        }
        local_4 = local_4 + 0x4f;
        iVar11 = iVar11 + 0x13c;
      } while (iVar11 < 0x278);
      piVar10 = piVar10 + 0xbb;
      iVar6 = iVar6 + 1;
      piVar14 = piVar14 + 1;
    } while (iVar6 < (int)puVar2[0x6d]);
  }
  iVar6 = 0;
  if (0 < (int)puVar2[0x76]) {
    piVar10 = &_alphaFoggedStages;
    piVar14 = puVar2 + 0x77;
    do {
      if (*piVar10 == 0) {
        puVar2[0x76] = iVar6;
        break;
      }
      piVar3 = (int *)(*__Q_stricmp)(0x2ec);
      *piVar14 = (int)piVar3;
      piVar5 = piVar10;
      for (iVar11 = 0xbb; iVar11 != 0; iVar11 = iVar11 + -1) {
        *piVar3 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar3 = piVar3 + 1;
      }
      iVar11 = 0;
      local_4 = piVar10 + 0x4c;
      do {
        sVar13 = *(int *)(iVar11 + 300 + *piVar14) * 0x4c;
        if (sVar13 != 0) {
          uVar4 = (*__Q_stricmp)(sVar13);
          *(undefined4 *)(iVar11 + 0x130 + *piVar14) = uVar4;
          _memcpy(*(void **)(iVar11 + 0x130 + *piVar14),(void *)*unaff_EBX,sVar13);
        }
        local_4 = local_4 + 0x4f;
        iVar11 = iVar11 + 0x13c;
      } while (iVar11 < 0x278);
      piVar10 = piVar10 + 0xbb;
      iVar6 = iVar6 + 1;
      piVar14 = piVar14 + 1;
    } while (iVar6 < (int)puVar2[0x76]);
  }
  _SortNewShader();
  _currentShader = 0;
  return puVar2;
}



// ===========================================
// Function: _R_CacheShaderStage @ 0001ae0b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_CacheShaderStage(int param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 0x138);
  iVar5 = 2;
  do {
    if ((piVar4[-1] == 0) && (*piVar4 == 0)) {
      iVar2 = piVar4[-0xc];
      if (iVar2 < 1) {
        iVar2 = 1;
      }
      else if (iVar2 < 1) goto LAB_0001ae6c;
      piVar3 = piVar4 + -0x4c;
      do {
        pcVar1 = (char *)*piVar3;
        if (((pcVar1 != (char *)0x0) && (*(int *)(pcVar1 + 0x74) != -1)) && (*pcVar1 != '*')) {
          *(undefined4 *)(pcVar1 + 0x74) = __r_sequencenumber;
        }
        piVar3 = piVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
LAB_0001ae6c:
    piVar4 = piVar4 + 0x4f;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}



// ===========================================
// Function: _R_CacheShader @ 0001ae7c
// ===========================================

void _R_CacheShader(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 400)) {
    puVar1 = (undefined4 *)(param_1 + 0x194);
    do {
      if (*(int *)*puVar1 != 0) {
        _R_CacheShaderStage((int *)*puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < *(int *)(param_1 + 400));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1b4)) {
    puVar1 = (undefined4 *)(param_1 + 0x1b8);
    do {
      if (*(int *)*puVar1 != 0) {
        _R_CacheShaderStage((int *)*puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x1b4));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1d8)) {
    puVar1 = (undefined4 *)(param_1 + 0x1dc);
    do {
      if (*(int *)*puVar1 != 0) {
        _R_CacheShaderStage((int *)*puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x1d8));
  }
  return;
}



// ===========================================
// Function: _R_FindShader @ 0001af0c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_FindShader(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__dest;
  undefined *puVar3;
  undefined4 *puVar4;
  char *in_stack_00000040;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  int in_stack_00000050;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined *puStack_74;
  undefined1 *puStack_70;
  undefined4 uStack_6c;
  char *pcStack_68;
  undefined1 *puStack_64;
  char *pcStack_60;
  int *piStack_5c;
  int iStack_48;
  undefined1 auStack_44 [64];
  undefined1 auStack_4 [4];
  
  if (*param_1 == '\0') {
    return _DAT_0001cea4;
  }
  if ((-1 < param_2) && (__RB_StageIteratorLightmappedMultitextureUnfogged <= param_2)) {
    param_2 = -3;
  }
  _COM_StripExtension(param_1,&local_80);
  iVar1 = generateHashValue();
  _currentShader = (char *)(&_hashTable)[iVar1];
joined_r0x0001af6c:
  if (_currentShader != (char *)0x0) {
    iVar2 = _Q_stricmp(_currentShader,&local_80);
    if (iVar2 != 0) goto code_r0x0001af89;
    if (_currentShader != (char *)0x0) {
      for (iVar1 = *(int *)(_currentShader + 0x44); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x210)) {
        if (*(int *)(iVar1 + 0x40) == param_2) {
          return iVar1;
        }
        if (iVar1 == _DAT_0001cea4) {
          return iVar1;
        }
      }
      goto LAB_0001afcf;
    }
  }
  __dest = (char *)(*_DAT_0001ce34)(0x4c);
  _memset(__dest,0,0x4c);
  _strncpy(__dest,&stack0xffffff74,0x40);
  *(undefined4 *)(__dest + 0x48) = (&_hashTable)[iVar1];
  (&_hashTable)[iVar1] = __dest;
  _currentShader = __dest;
LAB_0001afcf:
  _R_SyncRenderThread();
  _memset(&_shader,0,0x214);
  _memset(&_foggedStages,0,0x1760);
  _memset(&_unfoggedStages,0,0x1760);
  _memset(&_alphaFoggedStages,0,0x1760);
  _memset(&_texMods,0,0x1300);
  _DAT_00006268 = 0x3f800000;
  _shader_noPicMip = 0;
  _shader_noMipMaps = 0;
  _shader_force32bit = 0;
  _fogOnly = 0;
  _Q_strncpyz(&_shader,auStack_44,0x40);
  puVar4 = &DAT_0000764c;
  puVar3 = &DAT_000040e8;
  DAT_00006208 = param_2;
  do {
    *puVar4 = puVar3;
    puVar4[-0x4f] = puVar3 + -0x980;
    puVar3 = puVar3 + 0x130;
    puVar4 = puVar4 + 0xbb;
  } while ((int)puVar3 < 0x4a68);
  _DAT_00006284 = 0;
  _DAT_00006288 = 1;
  _DAT_0000628c = 1;
  _DAT_00006290 = 1;
  iVar1 = *(int *)(_currentShader + 0x40);
  if (iVar1 != 0) {
    iStack_48 = iVar1;
    if (*(int *)(__r_printShaders + 0x20) != 0) {
      piStack_5c = (int *)in_stack_00000040;
      pcStack_60 = s__SHADER___s_;
      puStack_64 = (undefined1 *)0x0;
      pcStack_68 = (char *)0x1b0dc;
      (*__ri)();
    }
    piStack_5c = &iStack_48;
    pcStack_60 = (char *)0x1b0e9;
    iVar1 = _ParseShader();
    if (iVar1 == 0) {
      DAT_00006218 = 1;
    }
    if ((DAT_00006208 == -3) && ((_DAT_00006220 & 0x400) == 0)) {
      DAT_00007678 = 5;
    }
    goto LAB_0001b2a1;
  }
  piStack_5c = (int *)0x40;
  puStack_64 = auStack_4;
  pcStack_60 = in_stack_00000040;
  pcStack_68 = (char *)0x1b170;
  _Q_strncpyz();
  pcStack_68 = s__tga;
  puStack_70 = auStack_4;
  uStack_6c = 0x40;
  puStack_74 = (undefined *)0x1b181;
  _COM_DefaultExtension();
  puStack_74 = &DAT_0000812f + (-(uint)(in_stack_00000050 != 0) & 0xffffa7d2);
  uStack_78 = 0;
  uStack_7c = in_stack_0000004c;
  local_80 = in_stack_00000048;
  iVar1 = _R_FindImageFile();
  if (iVar1 == 0) {
    piStack_5c = (int *)in_stack_00000040;
    pcStack_60 = s_Couldn_t_find_image_for_shader__;
    puStack_64 = (undefined1 *)0x3;
    pcStack_68 = (char *)0x1b1c7;
    (*__ri)();
    DAT_00006218 = 1;
    goto LAB_0001b2a1;
  }
  DAT_000073e8 = iVar1;
  if (DAT_00006208 == -1) {
    DAT_00007678 = 10;
LAB_0001b291:
    _DAT_00007694 = 0x100;
  }
  else {
    if (DAT_00006208 == -3) {
      DAT_00007678 = 5;
      DAT_00007690 = 1;
      goto LAB_0001b291;
    }
    if (DAT_00006208 != -4) {
      DAT_00007980 = DAT_00007980 | 0x13;
      DAT_000076cc = 1;
      DAT_00007964 = 1;
      DAT_000076d4 = iVar1;
      if (DAT_00006208 == -2) {
        DAT_000073e8 = _DAT_0001ce9c;
        DAT_00007678 = 2;
      }
      else {
        DAT_000073e8 = *(int *)(&DAT_0001cebc + DAT_00006208 * 4);
        DAT_00007678 = 1;
        DAT_00007514 = 1;
      }
      goto LAB_0001b291;
    }
    _DAT_000076ac = 1;
    DAT_00007678 = 0xf;
    DAT_00007690 = 0x10;
    _DAT_00007694 = 0x465;
  }
  _unfoggedStages = 1;
LAB_0001b2a1:
  piStack_5c = (int *)0x1b2a6;
  _GLimp_Suspend();
  piStack_5c = (int *)0x1b2ab;
  iVar1 = _FinishShader();
  return iVar1;
code_r0x0001af89:
  _currentShader = *(char **)(_currentShader + 0x48);
  goto joined_r0x0001af6c;
}



// ===========================================
// Function: _RE_RegisterShader @ 0001b2b6
// ===========================================

undefined4 _RE_RegisterShader(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((uint)((int)pcVar2 - (int)(param_1 + 1)) < 0x40) {
    iVar3 = _R_FindShader(param_1,0xfffffffc,1,1,1);
    if (*(int *)(iVar3 + 0x50) == 0) {
      return *(undefined4 *)(iVar3 + 0x44);
    }
  }
  else {
    _Com_Printf(s_Shader_name_exceeds_MAX_QPATH_);
  }
  return 0;
}



// ===========================================
// Function: _RE_RegisterShaderNoMip @ 0001b301
// ===========================================

undefined4 _RE_RegisterShaderNoMip(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((uint)((int)pcVar2 - (int)(param_1 + 1)) < 0x40) {
    iVar3 = _R_FindShader(param_1,0xfffffffc,0,0,0);
    if (*(int *)(iVar3 + 0x50) == 0) {
      return *(undefined4 *)(iVar3 + 0x44);
    }
  }
  else {
    _Com_Printf(s_Shader_name_exceeds_MAX_QPATH_);
  }
  return 0;
}



// ===========================================
// Function: _RE_RefreshShaderNoMip @ 0001b34c
// ===========================================

undefined4 _RE_RefreshShaderNoMip(char *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_40 [64];
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    _COM_StripExtension(param_1,local_40);
    iVar2 = generateHashValue();
    for (_currentShader = (&_hashTable)[iVar2]; _currentShader != 0;
        _currentShader = *(int *)(_currentShader + 0x48)) {
      iVar2 = _Q_stricmp(_currentShader,local_40);
      if (iVar2 == 0) {
        if (_currentShader != 0) {
          iVar2 = *(int *)(_currentShader + 0x44);
          iVar1 = *(int *)(*(int *)(iVar2 + 0x194) + 8);
          _currentShader = 0;
          if (iVar1 != 0) {
            uVar3 = _R_RefreshImageFile(iVar1,*(undefined4 *)(iVar1 + 0x60),
                                        *(undefined4 *)(iVar1 + 0x68),*(undefined4 *)(iVar1 + 0x6c),
                                        *(undefined4 *)(iVar1 + 0x70));
            *(undefined4 *)(*(int *)(iVar2 + 0x194) + 8) = uVar3;
          }
          return *(undefined4 *)(iVar2 + 0x44);
        }
        break;
      }
    }
    iVar2 = _R_FindShader(param_1,0xfffffffc,0,0,0);
    if (*(int *)(iVar2 + 0x50) == 0) {
      return *(undefined4 *)(iVar2 + 0x44);
    }
  }
  return 0;
}



// ===========================================
// Function: _RE_RefreshStaticShaderNoMip @ 0001b423
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _RE_RefreshStaticShaderNoMip(char *param_1,undefined4 param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  bool bVar7;
  undefined1 auStack_80 [64];
  undefined1 local_40 [64];
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    _COM_StripExtension(param_1,local_40);
    iVar3 = generateHashValue();
    for (_currentShader = (&_hashTable)[iVar3]; _currentShader != 0;
        _currentShader = *(int *)(_currentShader + 0x48)) {
      iVar3 = _Q_stricmp(_currentShader,local_40);
      if (iVar3 == 0) {
        if (_currentShader != 0) {
          iVar3 = *(int *)(_currentShader + 0x44);
          pbVar2 = *(byte **)(*(int *)(iVar3 + 0x194) + 8);
          _currentShader = 0;
          if (pbVar2 == (byte *)0x0) goto LAB_0001b562;
          _Q_strncpyz(auStack_80,param_2,0x40);
          _COM_DefaultExtension(auStack_80,0x40,s__tga);
          iVar4 = _Q_stricmp(pbVar2,auStack_80);
          if (iVar4 == 0) goto LAB_0001b5bb;
          if (pbVar2 == _DAT_0001ce9c) goto LAB_0001b562;
          *(int *)(pbVar2 + 0x78) = *(int *)(pbVar2 + 0x78) + -1;
          pcVar6 = s_title_bg_tga;
          pbVar5 = pbVar2;
          goto LAB_0001b525;
        }
        break;
      }
    }
    iVar3 = _R_FindShader(param_1,0xfffffffc,0,0,0);
    if (*(int *)(iVar3 + 0x50) == 0) {
      return *(undefined4 *)(iVar3 + 0x44);
    }
  }
  return 0;
  while( true ) {
    bVar1 = pbVar5[1];
    bVar7 = bVar1 < ((byte *)pcVar6)[1];
    if (bVar1 != ((byte *)pcVar6)[1]) goto LAB_0001b545;
    pbVar5 = pbVar5 + 2;
    pcVar6 = (char *)((byte *)pcVar6 + 2);
    if (bVar1 == 0) break;
LAB_0001b525:
    bVar1 = *pbVar5;
    bVar7 = bVar1 < (byte)*pcVar6;
    if (bVar1 != *pcVar6) {
LAB_0001b545:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_0001b54a;
    }
    if (bVar1 == 0) break;
  }
  iVar4 = 0;
LAB_0001b54a:
  if (iVar4 == 0) {
    *(int *)(pbVar2 + 0x78) = *(int *)(pbVar2 + 0x78) + 1;
  }
  if (*(int *)(pbVar2 + 0x78) < 1) {
    _R_FreeImage(pbVar2);
  }
LAB_0001b562:
  *(undefined4 *)(*(int *)(iVar3 + 0x194) + 8) = 0;
  iVar4 = _R_FindImageFile(auStack_80,0,0,0,&DAT_0000812f);
  if (iVar4 != 0) {
    *(int *)(iVar4 + 0x78) = *(int *)(iVar4 + 0x78) + 1;
  }
  *(int *)(*(int *)(iVar3 + 0x194) + 8) = iVar4;
  if (iVar4 != 0) {
    *(undefined4 *)(iVar3 + 0x50) = 0;
    return *(undefined4 *)(iVar3 + 0x44);
  }
  (*__ri)(3,s_Couldn_t_find_image_for_shader__,param_2);
  *(undefined4 *)(iVar3 + 0x50) = 1;
LAB_0001b5bb:
  return *(undefined4 *)(iVar3 + 0x44);
}



// ===========================================
// Function: _R_GetShaderByHandle @ 0001b5e5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_GetShaderByHandle(int param_1)

{
  if ((-1 < param_1) && (param_1 < _DAT_00060df0)) {
    return *(undefined4 *)(&DAT_00060df4 + param_1 * 4);
  }
  (*__ri)(3,s_R_GetShaderByHandle__out_of_rang,param_1);
  return _DAT_0001cea4;
}



// ===========================================
// Function: _R_ShaderList_f @ 0001b614
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ShaderList_f(void)

{
  undefined *puVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iStack_4;
  
  iVar8 = 0;
  (*__ri)(0,s_________________________);
  iStack_4 = 0;
  if (0 < _DAT_00060df0) {
    do {
      bVar3 = false;
      bVar2 = false;
      iVar4 = (*_DAT_0001ce4c)();
      if (iVar4 < 2) {
        iVar4 = *(int *)(&DAT_00060df4 + iVar8 * 4);
      }
      else {
        iVar4 = *(int *)(&DAT_00061df4 + iVar8 * 4);
      }
      (*__ri)(0,s__i_,*(undefined4 *)(iVar4 + 400));
      if (*(int *)(iVar4 + 0x40) < 0) {
        pcVar9 = s___;
      }
      else {
        pcVar9 = s_L_;
      }
      (*__ri)(0,pcVar9);
      piVar5 = *(int **)(iVar4 + 0x194);
      iVar7 = iVar4 + 0x194;
      if (piVar5 == (int *)0x0) {
LAB_0001b6d3:
        (*__ri)(0,s________);
      }
      else {
        do {
          if (*piVar5 == 0) break;
          if ((piVar5[0xa0] & 2U) != 0) {
            bVar2 = true;
          }
          if ((piVar5[0xa0] & 1U) != 0) {
            bVar3 = true;
          }
          piVar5 = *(int **)(iVar7 + 4);
          iVar7 = iVar7 + 4;
        } while (piVar5 != (int *)0x0);
        if (bVar2) {
          if (bVar3) goto LAB_0001b6e9;
          pcVar9 = s__;
        }
        else {
          if (!bVar3) goto LAB_0001b6d3;
LAB_0001b6e9:
          pcVar9 = s__;
        }
        pcVar6 = s__;
        if (!bVar2) {
          pcVar6 = s__;
        }
        (*__ri)(0,s_MT__s_s__,pcVar6,pcVar9);
      }
      if (*(int *)(iVar4 + 0x54) == 0) {
        pcVar9 = s___;
      }
      else {
        pcVar9 = s_E_;
      }
      (*__ri)(0,pcVar9);
      puVar1 = *(undefined **)(iVar4 + 0x20c);
      if (puVar1 == &_RB_StageIteratorGeneric) {
        pcVar9 = s_gen_;
      }
      else if (puVar1 == &_RB_StageIteratorSky) {
        pcVar9 = s_sky_;
      }
      else if (puVar1 == &_RB_StageIteratorLightmappedMultitextureUnfogged) {
        pcVar9 = s_lmmt;
      }
      else if (puVar1 == &_RB_StageIteratorVertexLitTextureUnfogged) {
        pcVar9 = s_vlt_;
      }
      else {
        pcVar9 = s_____;
      }
      (*__ri)(0,pcVar9);
      if (*(int *)(iVar4 + 0x50) == 0) {
        pcVar9 = s____s_;
      }
      else {
        pcVar9 = s____s__DEFAULTED__;
      }
      (*__ri)(0,pcVar9,iVar4);
      iStack_4 = iStack_4 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < _DAT_00060df0);
  }
  (*__ri)(0,s__i_total_shaders_,iStack_4);
  (*__ri)(0,s____________________);
  return;
}



// ===========================================
// Function: _ScanAndLoadShaderFiles @ 0001b7d7
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ScanAndLoadShaderFiles(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  undefined4 uVar13;
  int local_104c;
  char *pcStack_1048;
  int iStack_1044;
  undefined1 auStack_1040 [64];
  int aiStack_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x1b7e1;
  iVar8 = 0;
  iStack_1044 = (*__R_InitSkyTexCoords)(s_scripts,s__shader,&local_104c);
  if ((iStack_1044 == 0) || (local_104c == 0)) {
    (*__ri)(3,s_WARNING__no_shader_files_found_);
    return;
  }
  if (0x400 < local_104c) {
    local_104c = 0x400;
  }
  iVar7 = 0;
  if (0 < local_104c) {
    piVar9 = aiStack_1000;
    iVar11 = iStack_1044 - (int)piVar9;
    do {
      _Com_sprintf(auStack_1040,0x40,s_scripts__s,*(undefined4 *)(iVar11 + (int)piVar9));
      (*__ri)(2,s____loading___s__,auStack_1040);
      iVar2 = (*__Q_stricmpn)(auStack_1040,piVar9);
      iVar8 = iVar8 + iVar2;
      if (*piVar9 == 0) {
        (*_DAT_0001ce1c)(1,s_Couldn_t_load__s,auStack_1040);
      }
      iVar7 = iVar7 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar7 < local_104c);
  }
  iVar11 = 0;
  iVar7 = local_104c;
  if (0 < local_104c) {
    do {
      cVar1 = *(char *)aiStack_1000[iVar11];
      pcVar12 = (char *)aiStack_1000[iVar11];
      while (pcStack_1048 = pcVar12, cVar1 != '\0') {
        pcVar3 = (char *)_COM_ParseExt(&pcStack_1048,1);
        cVar1 = *pcVar3;
        iVar7 = local_104c;
        if (cVar1 == '\0') break;
        if (cVar1 == '}') {
          uVar13 = *(undefined4 *)(iStack_1044 + iVar11 * 4);
          pcVar12 = s_Extra___in__s_;
LAB_0001b907:
          (*_DAT_0001ce1c)(1,pcVar12,uVar13);
        }
        else if ((cVar1 == '{') &&
                (pcStack_1048 = pcVar12, iVar7 = _SkipBracedSection(&pcStack_1048), iVar7 == 0)) {
          uVar13 = *(undefined4 *)(iStack_1044 + iVar11 * 4);
          pcVar12 = s_Missing___in__s_;
          goto LAB_0001b907;
        }
        pcVar12 = pcStack_1048;
        iVar7 = local_104c;
        cVar1 = *pcStack_1048;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar7);
  }
  puVar4 = (undefined1 *)(*_DAT_0001ce34)(iVar8 + iVar7 * 2);
  *puVar4 = 0;
  iVar8 = local_104c;
  while (iVar8 = iVar8 + -1, _s_shaderText = puVar4, -1 < iVar8) {
    pcVar12 = puVar4 + -1;
    do {
      pcVar3 = pcVar12 + 1;
      pcVar12 = pcVar12 + 1;
    } while (*pcVar3 != '\0');
    *(char (*) [2])pcVar12 = s__;
    pcVar12 = (char *)aiStack_1000[iVar8];
    pcVar3 = pcVar12;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar5 = puVar4 + -1;
    do {
      pcVar10 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar10 != '\0');
    pcVar10 = pcVar12;
    for (uVar6 = (uint)((int)pcVar3 - (int)pcVar12) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = (int)pcVar3 - (int)pcVar12 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar5 = pcVar5 + 1;
    }
    (*_DAT_0001ce74)(aiStack_1000[iVar8]);
    puVar4 = _s_shaderText;
  }
  (*_DAT_0001ce7c)(iStack_1044);
  return;
}



// ===========================================
// Function: _FindShadersInShaderText @ 0001b9d1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _FindShadersInShaderText(void)

{
  char cVar1;
  char *__src;
  int iVar2;
  char *__dest;
  int local_4;
  
  iVar2 = _s_shaderText;
  local_4 = _s_shaderText;
  if (_s_shaderText != 0) {
    __src = (char *)_COM_ParseExt(&local_4,1);
    cVar1 = *__src;
    while (cVar1 != '\0') {
      if (cVar1 == '{') {
        local_4 = iVar2;
        _SkipBracedSection(&local_4);
      }
      else {
        iVar2 = generateHashValue();
        __dest = (char *)(*_DAT_0001ce34)(0x4c);
        _memset(__dest,0,0x4c);
        _strncpy(__dest,__src,0x40);
        *(undefined4 *)(__dest + 0x48) = (&_hashTable)[iVar2];
        (&_hashTable)[iVar2] = __dest;
        _currentShader = __dest;
        *(int *)(__dest + 0x40) = local_4;
      }
      iVar2 = local_4;
      __src = (char *)_COM_ParseExt(&local_4,1);
      cVar1 = *__src;
    }
  }
  return;
}



// ===========================================
// Function: _CreateInternalShaders @ 0001ba80
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CreateInternalShaders(void)

{
  int iVar1;
  
  iVar1 = 0;
  _DAT_00060df0 = 0;
  _memset(&_shader,0,0x214);
  _memset(&_foggedStages,0,0x1760);
  _memset(&_unfoggedStages,0,0x1760);
  _fogOnly = 0;
  _Q_strncpyz(&_shader,s_<default>,0x40);
  DAT_00006208 = 0xffffffff;
  DAT_000073e8 = __ParseSurfaceParm;
  _unfoggedStages = 1;
  _DAT_00007694 = 0x100;
  _currentShader = _FindShaderText();
  _DAT_0001cea4 = _FinishShader();
  do {
    _sprintf((char *)&_shader,s_<static_d>);
    DAT_00006208 = 0xfffffffc;
    DAT_000073e8 = _DAT_0001ce9c;
    _unfoggedStages = 1;
    DAT_00007678 = 0xc;
    _DAT_000076c4 = 0xffffffff;
    DAT_00007690 = 0xf;
    DAT_000076c8 = 0x7f;
    _DAT_00007694 = 0x165;
    _currentShader = _FindShaderText();
    _FinishShader();
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x14);
  _Q_strncpyz();
  DAT_00006208 = 0xffffffff;
  DAT_000073e8 = _DAT_0001ce9c;
  _unfoggedStages = 1;
  _DAT_00007694 = 0x100;
  _currentShader = _FindShaderText();
  _FinishShader();
  _Q_strncpyz();
  _DAT_00006214 = ___real_41700000;
  DAT_00006208 = 0xffffffff;
  _currentShader = _FindShaderText();
  ___CIsin = _FinishShader();
  return;
}



// ===========================================
// Function: _R_ShutdownShaders @ 0001bc40
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ShutdownShaders(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (_s_shaderText != 0) {
    (*__COM_ParseExt)(_s_shaderText);
  }
  _s_shaderText = 0;
  piVar3 = &_hashTable;
  do {
    iVar2 = *piVar3;
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x48);
      (*__COM_ParseExt)(iVar2);
      iVar2 = iVar1;
    }
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x73e0);
  return;
}



// ===========================================
// Function: _InitStaticShaders @ 0001bc97
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _InitStaticShaders(void)

{
  char cVar1;
  int iVar2;
  char *__src;
  char *pcStack_48;
  char *local_44;
  undefined1 *puStack_40;
  char acStack_3c [8];
  undefined1 auStack_34 [52];
  
  iVar2 = (*__Q_stricmpn)(s_scripts_static_shaders_txt,&local_44);
  if (iVar2 == -1) {
    (*__ri)(3,s_Couldn_t_find_static_shaders_fil);
    return;
  }
  pcStack_48 = local_44;
  __src = (char *)_COM_ParseExt(&pcStack_48,1);
  cVar1 = *__src;
  while (cVar1 != '\0') {
    _strncpy((char *)&puStack_40,__src,0x40);
    iVar2 = _R_FindShader(auStack_34,0xffffffff,1,1,1);
    if (iVar2 == 0) {
      puStack_40 = auStack_34;
      local_44 = s_InitStaticShaders__Couldn_t_find;
      pcStack_48 = (char *)0x3;
      (*__ri)();
    }
    local_44 = acStack_3c;
    puStack_40 = (undefined1 *)0x1;
    pcStack_48 = (char *)0x1bd2d;
    __src = (char *)_COM_ParseExt();
    cVar1 = *__src;
  }
  (*_DAT_0001ce74)(local_44);
  return;
}



// ===========================================
// Function: _R_SetupShaders @ 0001bd47
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetupShaders(void)

{
  int iVar1;
  int *piVar2;
  
  (*__ri)(0,s_Setting_up_Shaders_);
  _currentShader = 0;
  piVar2 = &_hashTable;
  do {
    for (iVar1 = *piVar2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x48)) {
      *(undefined4 *)(iVar1 + 0x44) = 0;
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x73e0);
  _CreateInternalShaders();
  _InitStaticShaders();
  _DAT_0001ceac = _R_FindShader(s_projectionShadow,0xffffffff,1,1,1);
  ___CIcos = _R_FindShader(s_flare,0xffffffff,1,1,1);
  return;
}



// ===========================================
// Function: _R_StartupShaders @ 0001bdbf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_StartupShaders(void)

{
  (*__ri)(0,s_Initializing_Shaders_);
  _currentShader = 0;
  _s_shaderText = 0;
  _memset(&_hashTable,0,0x1000);
  _ScanAndLoadShaderFiles();
  _FindShadersInShaderText();
  _R_SetupShaders();
  return;
}



