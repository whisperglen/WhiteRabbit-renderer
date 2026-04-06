// ===========================================
// Function: _R_GammaCorrect @ 0000dc00
// ===========================================

void _R_GammaCorrect(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      *(undefined1 *)(iVar1 + param_1) = *(undefined1 *)(*(byte *)(iVar1 + param_1) + 0x2000);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return;
}



// ===========================================
// Function: generateHashValue @ 0000dc24
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
// Function: _GL_TextureMode @ 0000dc68
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _GL_TextureMode(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int *piVar3;
  int iVar4;
  
  ppuVar2 = &_modes;
  iVar4 = 0;
  do {
    iVar1 = _Q_stricmp(*ppuVar2,param_1);
    if (iVar1 == 0) break;
    ppuVar2 = ppuVar2 + 3;
    iVar4 = iVar4 + 1;
  } while ((int)ppuVar2 < 0x3650);
  if (iVar4 == 5) {
    if (_DAT_00012790 == 1) {
      (*__ri)(0,s_Refusing_to_set_trilinear_on_a_v);
      iVar4 = 3;
    }
  }
  else if (iVar4 == 6) {
    iVar4 = (*__ri)(0,s_bad_filter_name_);
    return iVar4;
  }
  __gl_filter_min = *(int *)(iVar4 * 0xc + 0x360c);
  __gl_filter_max = *(int *)(iVar4 * 0xc + 0x3610);
  iVar4 = iVar4 * 0xc;
  iVar1 = 0;
  if (0 < _DAT_000252f4) {
    piVar3 = (int *)&DAT_00025348;
    do {
      if ((piVar3[4] != 0) && (*piVar3 != 0)) {
        _GL_Bind(piVar3 + -0x14);
        (*__qglTexParameterf)(0xde1,&DAT_00002801,(float)__gl_filter_min);
        iVar4 = (*__qglTexParameterf)(0xde1,&DAT_00002800,(float)__gl_filter_max);
      }
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 0x20;
    } while (iVar1 < _DAT_000252f4);
  }
  return iVar4;
}



// ===========================================
// Function: _R_SumOfUsedImages @ 0000dd5f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _R_SumOfUsedImages(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < _DAT_000252f4) {
    piVar2 = (int *)&DAT_00025344;
    iVar3 = _DAT_000252f4;
    do {
      if (piVar2[2] == __ri) {
        iVar1 = iVar1 + piVar2[-1] * *piVar2;
      }
      piVar2 = piVar2 + 0x20;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}



// ===========================================
// Function: _R_ImageList_f @ 0000dd97
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ImageList_f(void)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *local_8 [2];
  
  local_8[0] = s_no_;
  local_8[1] = s_yes;
  (*__ri)(0,s_________w____h____mm___TMU___if_);
  iVar2 = 0;
  iVar4 = 0;
  if (0 < _DAT_000252f4) {
    piVar3 = (int *)&DAT_00025344;
    do {
      iVar2 = iVar2 + piVar3[-1] * *piVar3;
      (*__ri)(0,s__4i___4i__4i___s____d___,iVar4,piVar3[-1],*piVar3,local_8[piVar3[5]],piVar3[4]);
      pcVar5 = (char *)piVar3[3];
      if ((int)pcVar5 < 0x8051) {
        if (pcVar5 == s_c__program_files_microsoft_sdks__0000804f + 1) {
          pcVar5 = s_RGB5__;
        }
        else {
          switch(pcVar5) {
          case (char *)0x1:
            pcVar5 = s_I_____;
            break;
          case (char *)0x2:
            pcVar5 = s_IA____;
            break;
          case (char *)0x3:
            pcVar5 = s_RGB___;
            break;
          case (char *)0x4:
            pcVar5 = s_RGBA__;
            break;
          default:
switchD_0000de14_caseD_4:
            pcVar5 = s_______;
          }
        }
      }
      else if ((int)pcVar5 < 0x8059) {
        if (pcVar5 == s_c__program_files_microsoft_sdks__0000804f + 9) {
          pcVar5 = s_RGBA8_;
        }
        else if (pcVar5 == s_c__program_files_microsoft_sdks__0000804f + 2) {
          pcVar5 = s_RGB8__;
        }
        else {
          if (pcVar5 != s_c__program_files_microsoft_sdks__0000804f + 7)
          goto switchD_0000de14_caseD_4;
          pcVar5 = s_RGBA4_;
        }
      }
      else {
        if (pcVar5 != s_c__program_files_microsoft_sdks__00008371 + 0x30)
        goto switchD_0000de14_caseD_4;
        pcVar5 = s_S3TC__;
      }
      (*__ri)(0,pcVar5);
      puVar1 = (undefined *)piVar3[9];
      if (puVar1 == &DAT_00002900) {
        pcVar5 = s_clmp_;
LAB_0000deb6:
        (*__ri)(0,pcVar5);
      }
      else {
        if (puVar1 == &DAT_00002901) {
          pcVar5 = s_rept_;
          goto LAB_0000deb6;
        }
        (*__ri)(0,s__4i_,puVar1);
      }
      (*__ri)(0,s___s_,piVar3 + -0x13);
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x20;
    } while (iVar4 < _DAT_000252f4);
  }
  (*__ri)(0,s____________);
  (*__ri)(0,s___i_total_texels__not_including_,iVar2);
  (*__ri)(0,s___i_total_images__,_DAT_000252f4);
  return;
}



// ===========================================
// Function: _ResampleTexture @ 0000df2f
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void _ResampleTexture(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6
                     )

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  int local_2008;
  int iStack_2004;
  int aiStack_2000 [1024];
  int aiStack_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0xdf39;
  uVar3 = (param_2 << 0x10) / param_5;
  iVar5 = 0;
  uVar7 = uVar3 >> 2;
  if (0 < param_5) {
    do {
      aiStack_2000[iVar5] = (uVar7 >> 0x10) * 4;
      iVar5 = iVar5 + 1;
      uVar7 = uVar7 + uVar3;
    } while (iVar5 < param_5);
  }
  iVar5 = 0;
  uVar7 = (uVar3 >> 2) * 3;
  if (0 < param_5) {
    do {
      aiStack_1000[iVar5] = (uVar7 >> 0x10) * 4;
      iVar5 = iVar5 + 1;
      uVar7 = uVar7 + uVar3;
    } while (iVar5 < param_5);
  }
  local_2008 = 0;
  if (0 < param_6) {
    do {
      iVar5 = __ftol2_sse();
      iVar5 = param_1 + iVar5 * param_2 * 4;
      iVar4 = __ftol2_sse();
      iVar4 = param_1 + iVar4 * param_2 * 4;
      iStack_2004 = 0;
      if (0 < param_5) {
        puVar6 = (undefined1 *)(param_4 + 2);
        do {
          iVar1 = aiStack_2000[iStack_2004];
          iVar2 = aiStack_1000[iStack_2004];
          puVar6[-2] = (char)((int)((uint)*(byte *)(iVar1 + iVar5) + (uint)*(byte *)(iVar2 + iVar4)
                                    + (uint)*(byte *)(iVar1 + iVar4) +
                                   (uint)*(byte *)(iVar2 + iVar5)) >> 2);
          puVar6[-1] = (char)((int)((uint)*(byte *)(iVar2 + 1 + iVar4) +
                                    (uint)*(byte *)(iVar1 + 1 + iVar4) +
                                    (uint)*(byte *)(iVar2 + 1 + iVar5) +
                                   (uint)*(byte *)(iVar1 + 1 + iVar5)) >> 2);
          *puVar6 = (char)((int)((uint)*(byte *)(iVar2 + 2 + iVar4) +
                                 (uint)*(byte *)(iVar1 + 2 + iVar4) +
                                 (uint)*(byte *)(iVar2 + 2 + iVar5) +
                                (uint)*(byte *)(iVar1 + 2 + iVar5)) >> 2);
          iStack_2004 = iStack_2004 + 1;
          puVar6[1] = (char)((int)((uint)*(byte *)(iVar2 + 3 + iVar4) +
                                   (uint)*(byte *)(iVar1 + 3 + iVar4) +
                                   (uint)*(byte *)(iVar2 + 3 + iVar5) +
                                  (uint)*(byte *)(iVar1 + 3 + iVar5)) >> 2);
          puVar6 = puVar6 + 4;
        } while (iStack_2004 < param_5);
      }
      local_2008 = local_2008 + 1;
      param_4 = param_4 + param_5 * 4;
    } while (local_2008 < param_6);
  }
  return;
}



// ===========================================
// Function: _R_LightScaleTexture @ 0000e0ed
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LightScaleTexture(int param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  
  if (_DAT_00011d30 != 0) {
    if (param_4 == 0) {
      param_2 = param_2 * param_3;
      if (_DAT_00012794 == 0) {
        if (0 < param_2) {
          pbVar1 = (byte *)(param_1 + 2);
          do {
            pbVar1[-2] = *(byte *)((byte)(&_s_intensitytable)[pbVar1[-2]] + 0x2000);
            pbVar1[-1] = *(byte *)((byte)(&_s_intensitytable)[pbVar1[-1]] + 0x2000);
            *pbVar1 = *(byte *)((byte)(&_s_intensitytable)[*pbVar1] + 0x2000);
            pbVar1 = pbVar1 + 4;
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (0 < param_2) {
        pbVar1 = (byte *)(param_1 + 2);
        do {
          pbVar1[-2] = (&_s_intensitytable)[pbVar1[-2]];
          pbVar1[-1] = (&_s_intensitytable)[pbVar1[-1]];
          *pbVar1 = (&_s_intensitytable)[*pbVar1];
          pbVar1 = pbVar1 + 4;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
        return;
      }
    }
    else if ((_DAT_00012794 == 0) && (param_2 = param_2 * param_3, 0 < param_2)) {
      pbVar1 = (byte *)(param_1 + 2);
      do {
        pbVar1[-2] = *(byte *)(pbVar1[-2] + 0x2000);
        pbVar1[-1] = *(byte *)(pbVar1[-1] + 0x2000);
        *pbVar1 = *(byte *)(*pbVar1 + 0x2000);
        pbVar1 = pbVar1 + 4;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
  }
  return;
}



// ===========================================
// Function: _R_MipMap2 @ 0000e203
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_MipMap2(int param_1,int param_2)

{
  size_t __n;
  void *__src;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  void *unaff_ESI;
  int iVar10;
  uint uVar11;
  uint uStack_6c;
  void *pvStack_64;
  void *pvStack_5c;
  int iStack_58;
  uint uStack_54;
  int iStack_50;
  void *pvStack_40;
  
  iStack_50 = param_2 >> 1;
  iVar10 = param_1 >> 1;
  __n = iStack_50 * iVar10 * 4;
  __src = (void *)(*_DAT_00011384)(__n);
  uVar6 = param_2 - 1;
  if (0 < iStack_50) {
    uStack_54 = 2;
    pvStack_64 = __src;
    do {
      if (0 < iVar10) {
        iVar1 = (uStack_54 - 2 & uVar6) * param_1;
        iVar2 = (uStack_54 & uVar6) * param_1;
        iVar8 = (uStack_54 - 1 & uVar6) * param_1;
        iVar3 = (uStack_54 - 3 & uVar6) * param_1;
        uStack_6c = 2;
        pvStack_5c = pvStack_64;
        iStack_58 = iVar10;
        do {
          uVar9 = param_1 - 1;
          uVar4 = uStack_6c - 1 & uVar9;
          uVar7 = uStack_6c - 2 & uVar9;
          pvStack_40 = (void *)((int)unaff_ESI + (uVar7 + iVar8) * 4);
          uVar11 = uStack_6c & uVar9;
          uVar9 = uStack_6c - 3 & uVar9;
          iVar5 = 0;
          do {
            *(char *)((int)pvStack_5c + iVar5) =
                 (char)(((uint)*(byte *)((int)unaff_ESI + iVar5 + (uVar9 + iVar3) * 4) +
                         ((uint)*(byte *)((int)unaff_ESI + iVar5 + (uVar7 + iVar3) * 4) +
                          ((uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar1 + uVar7) * 4) +
                           (uint)*(byte *)((int)pvStack_40 + iVar5) +
                           (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar1 + uVar4) * 4) +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (uVar4 + iVar8) * 4)) * 2 +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar2 + uVar7) * 4) +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar1 + uVar9) * 4) +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar1 + uVar11) * 4) +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (uVar4 + iVar3) * 4) +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar2 + uVar4) * 4) +
                          (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar8 + uVar9) * 4) +
                         (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar8 + uVar11) * 4)) * 2 +
                         (uint)*(byte *)((int)unaff_ESI + iVar5 + (iVar2 + uVar9) * 4) +
                         (uint)*(byte *)((int)unaff_ESI + iVar5 + (uVar11 + iVar3) * 4) +
                        (uint)*(byte *)((int)unaff_ESI + iVar5 + (uVar11 + iVar2) * 4)) / 0x24);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 4);
          pvStack_5c = (void *)((int)pvStack_5c + 4);
          uStack_6c = uStack_6c + 2;
          iStack_58 = iStack_58 + -1;
        } while (iStack_58 != 0);
      }
      pvStack_64 = (void *)((int)pvStack_64 + iVar10 * 4);
      uStack_54 = uStack_54 + 2;
      iStack_50 = iStack_50 + -1;
    } while (iStack_50 != 0);
  }
  _memcpy(unaff_ESI,__src,__n);
  (*___fltused)(pvStack_40);
  return;
}



// ===========================================
// Function: _R_MipMap @ 0000e4b8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _R_MipMap(byte *param_1,int param_2)

{
  int in_EAX;
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  int local_20;
  int local_1c;
  
  if ((__r_simpleMipMaps != 0) && (*(int *)(__r_simpleMipMaps + 0x20) == 0)) {
    _R_MipMap2(param_2);
    return;
  }
  if ((param_2 != 1) || (in_EAX != 1)) {
    iVar2 = param_2 >> 1;
    local_1c = in_EAX >> 1;
    if ((iVar2 == 0) || (local_1c == 0)) {
      iVar2 = iVar2 + local_1c;
      if (0 < iVar2) {
        pbVar3 = param_1 + 2;
        do {
          pbVar3[-2] = (byte)((int)((uint)param_1[4] + (uint)*param_1) >> 1);
          pbVar3[-1] = (byte)((int)((uint)param_1[5] + (uint)param_1[1]) >> 1);
          *pbVar3 = (byte)((int)((uint)param_1[6] + (uint)param_1[2]) >> 1);
          pbVar3[1] = (byte)((int)((uint)param_1[7] + (uint)param_1[3]) >> 1);
          pbVar3 = pbVar3 + 4;
          param_1 = param_1 + 8;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    else {
      pbVar3 = param_1;
      if (0 < local_1c) {
        do {
          if (0 < iVar2) {
            pbVar1 = param_1 + param_2 * 4;
            local_20 = iVar2;
            do {
              *pbVar3 = (byte)((int)((uint)pbVar1[param_2 * -4 + 4] + (uint)pbVar1[4] +
                                     (uint)*param_1 + (uint)*pbVar1) >> 2);
              pbVar3[1] = (byte)((int)((uint)pbVar1[param_2 * -4 + 1] +
                                       (uint)pbVar1[param_2 * -4 + 5] + (uint)pbVar1[5] +
                                      (uint)pbVar1[1]) >> 2);
              pbVar3[2] = (byte)((int)((uint)pbVar1[param_2 * -4 + 2] +
                                       (uint)pbVar1[param_2 * -4 + 6] + (uint)pbVar1[6] +
                                      (uint)pbVar1[2]) >> 2);
              pbVar3[3] = (byte)((int)((uint)pbVar1[param_2 * -4 + 3] +
                                       (uint)pbVar1[param_2 * -4 + 7] + (uint)pbVar1[7] +
                                      (uint)pbVar1[3]) >> 2);
              pbVar3 = pbVar3 + 4;
              param_1 = param_1 + 8;
              pbVar1 = pbVar1 + 8;
              local_20 = local_20 + -1;
            } while (local_20 != 0);
          }
          param_1 = param_1 + param_2 * 4;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
        return;
      }
    }
  }
  return;
}



// ===========================================
// Function: _R_BlendOverTexture @ 0000e683
// ===========================================

void __thiscall _R_BlendOverTexture(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *in_EAX;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)param_2[3];
  bVar1 = *param_2;
  bVar2 = param_2[1];
  bVar3 = param_2[2];
  iVar4 = 0xff - uVar5;
  if (0 < param_1) {
    do {
      *in_EAX = (byte)((int)((uint)*in_EAX * iVar4 + bVar1 * uVar5) >> 9);
      in_EAX[1] = (byte)((int)((uint)in_EAX[1] * iVar4 + bVar2 * uVar5) >> 9);
      in_EAX[2] = (byte)((int)((uint)in_EAX[2] * iVar4 + bVar3 * uVar5) >> 9);
      in_EAX = in_EAX + 4;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



// ===========================================
// Function: _Upload32 @ 0000e6eb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Upload32(int *param_1,undefined4 *param_2,int param_3,int param_4,int param_5,int param_6,
              int param_7,byte param_8,int *param_9,int *param_10,undefined4 *param_11)

{
  float fVar1;
  int in_EAX;
  int *piVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  bool bVar9;
  int *unaff_retaddr;
  undefined *puVar10;
  undefined4 uVar11;
  
  _GLimp_Resume();
  iVar7 = 1;
  if (1 < in_EAX) {
    do {
      iVar7 = iVar7 * 2;
    } while (iVar7 < in_EAX);
  }
  puVar8 = (undefined4 *)&_feat_00;
  if (1 < (int)param_2) {
    do {
      puVar8 = (undefined4 *)((int)puVar8 * 2);
    } while ((int)puVar8 < (int)param_2);
  }
  if ((__r_roundImagesDown != 0) && (*(int *)(__r_roundImagesDown + 0x20) != 0)) {
    if (in_EAX < iVar7) {
      iVar7 = iVar7 >> 1;
    }
    if ((*(int *)(__r_roundImagesDown + 0x20) != 0) && ((int)param_2 < (int)puVar8)) {
      puVar8 = (undefined4 *)((int)puVar8 >> 1);
    }
  }
  if ((iVar7 != in_EAX) || (puVar8 != param_2)) {
    piVar2 = (int *)(*_DAT_00011384)((int)puVar8 * iVar7 * 4);
    _ResampleTexture(param_1);
    in_EAX = iVar7;
    param_1 = piVar2;
    param_2 = puVar8;
  }
  if (param_4 != 0) {
    if (__r_picmip == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = (byte)*(undefined4 *)(__r_picmip + 0x20);
    }
    iVar5 = iVar7 >> (bVar4 & 0x1f);
    if (__r_picmip == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = (byte)*(undefined4 *)(__r_picmip + 0x20);
    }
    puVar3 = (undefined4 *)((int)puVar8 >> (bVar4 & 0x1f));
    if ((1 < iVar5) && (1 < (int)puVar3)) {
      iVar7 = iVar5;
      puVar8 = puVar3;
    }
  }
  if (iVar7 < 1) {
    iVar7 = 1;
  }
  if ((int)puVar8 < 1) {
    puVar8 = (undefined4 *)&_feat_00;
  }
  if ((param_3 != 0) && ((iVar7 == 1 || (puVar8 == (undefined4 *)&_feat_00)))) {
    (*_DAT_00011374)(1,s_Upload32__Image_with_width_or_he);
  }
  for (; (_DAT_00012778 < iVar7 || (_DAT_00012778 < (int)puVar8));
      puVar8 = (undefined4 *)((int)puVar8 >> 1)) {
    iVar7 = iVar7 >> 1;
  }
  if (param_7 == 0) {
    if (((_DAT_00012798 == 1) && (param_5 == 0)) && ((param_8 & 1) == 0)) {
      pcVar6 = s_c__program_files_microsoft_sdks__00008371 + 0x30;
    }
    else if (__r_texturebits == 0) {
LAB_0000e87d:
      pcVar6 = s_c__program_files_microsoft_sdks__0000804f + 2;
    }
    else {
      if (*(int *)(__r_texturebits + 0x20) != 0x10) {
        if (*(int *)(__r_texturebits + 0x20) == 0x20) goto LAB_0000e87d;
        if (*(int *)(__r_colorbits + 0x20) != 0x10) {
          pcVar6 = s_c__program_files_microsoft_sdks__0000804f +
                   (-(uint)(*(int *)(__r_colorbits + 0x20) != 0x20) & 0xffff7fb2) + 2;
          goto LAB_0000e8e6;
        }
      }
      pcVar6 = s_c__program_files_microsoft_sdks__0000804f +
               (-(uint)(param_6 != 0) & 0xffff7fb3) + 1;
    }
  }
  else if (*(int *)(__r_texturebits + 0x20) == 0x10) {
    pcVar6 = s_c__program_files_microsoft_sdks__0000804f + (uint)(param_6 != 0) * 2 + 7;
  }
  else if (*(int *)(__r_texturebits + 0x20) == 0x20) {
    pcVar6 = s_c__program_files_microsoft_sdks__0000804f + 9;
  }
  else if (*(int *)(__r_colorbits + 0x20) == 0x10) {
    pcVar6 = s_c__program_files_microsoft_sdks__0000804f + (uint)(param_6 != 0) * 2 + 7;
  }
  else {
    pcVar6 = s_c__program_files_microsoft_sdks__0000804f +
             (-(uint)(*(int *)(__r_colorbits + 0x20) != 0x20) & 0xffff7fac) + 9;
  }
LAB_0000e8e6:
  iVar5 = in_EAX - iVar7;
  bVar9 = in_EAX == iVar7;
  if (!bVar9) goto LAB_0000e98e;
  if (puVar8 == param_2) {
    if (param_3 != 0) goto LAB_0000e9cc;
    (*__qglTexImage2D)(0xde1,0,pcVar6,iVar7,puVar8,0,0x1908,0x1401,param_1);
    *param_1 = iVar7;
    *param_2 = puVar8;
    *unaff_retaddr = (int)pcVar6;
  }
  else {
    while( true ) {
      iVar5 = in_EAX - iVar7;
      bVar9 = in_EAX == iVar7;
LAB_0000e98e:
      if ((bVar9 || SBORROW4(in_EAX,iVar7) != iVar5 < 0) && ((int)param_2 <= (int)puVar8)) break;
      _R_MipMap(in_EAX);
      param_2 = (undefined4 *)((int)param_2 >> 1);
      in_EAX = in_EAX >> 1;
      if (in_EAX < 1) {
        in_EAX = 1;
      }
      if ((int)param_2 < 1) {
        param_2 = (undefined4 *)&_feat_00;
      }
    }
LAB_0000e9cc:
    _R_LightScaleTexture(param_1,iVar7,puVar8,param_3 == 0);
    *param_10 = iVar7;
    uVar11 = 0x1908;
    *param_11 = puVar8;
    *param_9 = (int)pcVar6;
    (*__qglTexImage2D)(0xde1,0,pcVar6,iVar7,puVar8,0,0x1908,0x1401,param_1);
    if (param_3 != 0) {
      iVar5 = 0;
      puVar10 = &_mipBlendColors;
      while ((1 < iVar7 || (1 < (int)puVar8))) {
        _R_MipMap(iVar7);
        iVar7 = iVar7 >> 1;
        puVar8 = (undefined4 *)((int)puVar8 >> 1);
        if (iVar7 < 1) {
          iVar7 = 1;
        }
        if ((int)puVar8 < 1) {
          puVar8 = (undefined4 *)0x1;
        }
        puVar10 = puVar10 + 4;
        iVar5 = iVar5 + 1;
        if (*(int *)(__r_colorMipLevels + 0x20) != 0) {
          _R_BlendOverTexture(puVar10);
        }
        (*__qglTexImage2D)(0xde1,iVar5,pcVar6,iVar7,puVar8,0,0x1908,0x1401,uVar11);
      }
      puVar10 = &DAT_00002801;
      (*__qglTexParameterf)(0xde1,&DAT_00002801,(float)__gl_filter_min);
      fVar1 = (float)__gl_filter_max;
      goto LAB_0000e955;
    }
  }
  puVar10 = &DAT_00002801;
  (*__qglTexParameterf)(0xde1,&DAT_00002801,___real_46180400);
  fVar1 = ___real_46180400;
LAB_0000e955:
  (*__qglTexParameterf)(0xde1,&DAT_00002800,fVar1);
  _GL_CheckErrors();
  if (puVar10 != (undefined *)0x0) {
    (*___fltused)(puVar10);
  }
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _R_CreateImage @ 0000eaca
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 *
_R_CreateImage(char *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
              undefined4 param_6,char *param_7,undefined4 param_8,undefined4 param_9,
              undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
              undefined4 param_14,int param_15)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  bool bVar10;
  
  iVar9 = 0;
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0x3f < (uint)((int)pcVar5 - (int)(param_1 + 1))) {
    (*_DAT_00011374)(1,s_R_CreateImage____s__is_too_long_,param_1);
  }
  _strncmp(param_1,s__lightmap,9);
  iVar6 = _strncmp(param_1,s__lightmapD,10);
  if (_DAT_000252f4 == 0x600) {
    (*_DAT_00011374)(1,s_R_CreateImage__MAX_DRAWIMAGES_hi);
  }
  if ((param_4 != 0) && (*(int *)(__r_ext_compressed_lightmaps + 0x20) == 0)) {
    param_5 = 1;
  }
  bVar10 = _DAT_000252f4 == 0;
  if (0 < _DAT_000252f4) {
    pcVar5 = &DAT_000252f8;
    do {
      if (*pcVar5 == '\0') break;
      iVar9 = iVar9 + 1;
      pcVar5 = pcVar5 + 0x80;
    } while (iVar9 < _DAT_000252f4);
    bVar10 = iVar9 == _DAT_000252f4;
  }
  if (bVar10) {
    if (_DAT_000252f4 == 0x600) {
      (*_DAT_00011374)(1,s_MAX_DRAWIMAGES);
    }
    else {
      _DAT_000252f4 = _DAT_000252f4 + 1;
    }
  }
  iVar7 = iVar9 * 0x80;
  puVar8 = &DAT_000252f8 + iVar7;
  *(undefined4 *)(&DAT_00025358 + iVar7) = param_11;
  *(uint *)(iVar7 + 0x2535c) = (uint)(iVar6 == 0);
  *(int *)(&DAT_00025368 + iVar7) = param_15;
  *(undefined4 *)(iVar7 + 0x25360) = param_12;
  *(undefined4 *)(iVar7 + 0x25364) = param_13;
  iVar6 = (int)puVar8 - (int)param_7;
  do {
    cVar1 = *param_7;
    param_7[iVar6] = cVar1;
    iVar4 = __qglActiveTextureARB;
    param_7 = param_7 + 1;
  } while (cVar1 != '\0');
  *(int *)(&DAT_00025348 + iVar7) = iVar9 + 0x400;
  *(undefined4 *)(iVar7 + 0x25338) = param_9;
  *(undefined4 *)(iVar7 + 0x2533c) = param_10;
  *(undefined4 *)(iVar7 + 0x25370) = 0;
  if ((iVar4 == 0) || (param_4 == 0)) {
    *(undefined4 *)(&DAT_00025354 + iVar7) = 0;
  }
  else {
    *(undefined4 *)(&DAT_00025354 + iVar7) = 1;
  }
  if (iVar4 != 0) {
    _GL_SelectTexture(*(undefined4 *)(&DAT_00025354 + iVar7));
  }
  _GL_Bind(puVar8);
  _Upload32(param_8,*(undefined4 *)(iVar7 + 0x2533c),*(undefined4 *)(&DAT_00025358 + iVar7),param_12
            ,*(undefined4 *)(iVar7 + 0x2535c),param_13,param_14,param_5,&DAT_00025350 + iVar7,
            &DAT_00025340 + iVar7,&DAT_00025344 + iVar7);
  (*__qglTexParameterf)(0xde1,&DAT_00002802,(float)param_15);
  (*__qglTexParameterf)(0xde1,&DAT_00002803,param_12);
  (*__qglBindTexture)(0xde1,0);
  iVar9 = *(int *)(&DAT_00025354 + iVar7);
  *(undefined4 *)(&_glState + iVar9 * 4) = 0xffffffff;
  if (iVar9 == 1) {
    _GL_SelectTexture(0);
  }
  iVar9 = generateHashValue();
  uVar3 = __r_sequencenumber;
  uVar2 = *(undefined4 *)(&_hashTable + iVar9 * 4);
  *(undefined1 **)(&_hashTable + iVar9 * 4) = puVar8;
  *(undefined4 *)(iVar7 + 0x25374) = uVar2;
  *(undefined4 *)(&DAT_0002536c + iVar7) = uVar3;
  return puVar8;
}



// ===========================================
// Function: _LoadFTX @ 0000ecf8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall _LoadFTX(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_EDI;
  undefined4 local_10;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  *unaff_EDI = 0;
  iVar1 = (*_DAT_000113b4)(param_1,&local_10,1,1);
  if (0 < iVar1) {
    (*__GLimp_Suspend)(&iStack_c,0xc,local_10);
    if (__bigendian != 0) {
      uStack_4 = _LittleLong(uStack_4);
      iStack_8 = _LittleLong(iStack_8);
      iStack_c = _LittleLong(iStack_c);
    }
    *param_3 = iStack_8;
    *param_2 = iStack_c;
    iVar1 = iStack_c * iStack_8 * 4;
    *param_4 = uStack_4;
    uVar2 = (*_DAT_0001138c)(iVar1);
    *unaff_EDI = uVar2;
    (*__GLimp_Suspend)(uVar2,iVar1,local_10);
    (*_DAT_000113bc)(local_10);
  }
  return;
}



// ===========================================
// Function: _LoadTGA @ 0000edb9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _LoadTGA(undefined4 param_1,int *param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte bVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte bStack_30;
  byte bStack_2f;
  byte bStack_2e;
  uint uStack_2c;
  uint uStack_24;
  byte *pbStack_1c;
  byte *local_18;
  byte bStack_14;
  byte bStack_13;
  byte bStack_2;
  
  *param_2 = 0;
  (*__qglTexImage2D)(param_1,&local_18);
  pbVar9 = local_18;
  if (local_18 != (byte *)0x0) {
    bStack_14 = *local_18;
    bStack_13 = local_18[1];
    bVar8 = local_18[2];
    _LittleShort(*(undefined2 *)(local_18 + 3));
    _LittleShort(*(undefined2 *)(pbVar9 + 5));
    _LittleShort(*(undefined2 *)(pbVar9 + 8));
    _LittleShort(*(undefined2 *)(pbVar9 + 10));
    uVar3 = _LittleShort(*(undefined2 *)(pbVar9 + 0xc));
    uVar11 = (uint)uVar3;
    uVar3 = _LittleShort(*(undefined2 *)(pbVar9 + 0xe));
    bStack_2 = pbVar9[0x10];
    pbVar9 = pbVar9 + 0x12;
    uStack_2c = (uint)uVar3;
    if (((bVar8 != 2) && (bVar8 != 10)) && (bVar8 != 3)) {
      (*_DAT_00011374)(1,s_LoadTGA__Only_type_2__RGB___3__g);
    }
    if (bStack_13 != 0) {
      (*_DAT_00011374)(1,s_LoadTGA__colormaps_not_supported);
    }
    if (bStack_2 == 0x20) {
      *param_5 = 1;
    }
    else if ((bStack_2 != 0x18) && (bVar8 != 3)) {
      (*_DAT_00011374)(1,s_LoadTGA__Only_32_or_24_bit_image);
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = uVar11;
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = uStack_2c;
    }
    iVar4 = (*_DAT_0001138c)(uStack_2c * uVar11 * 4);
    *param_2 = iVar4;
    if (bStack_14 != 0) {
      pbVar9 = pbVar9 + bStack_14;
    }
    if ((bVar8 == 2) || (bVar8 == 3)) {
      iVar5 = uStack_2c - 1;
      if (-1 < iVar5) {
        pbVar12 = (byte *)(iVar4 + iVar5 * uVar11 * 4);
        uVar1 = uVar11;
        pbVar10 = pbVar12;
        do {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            if (bStack_2 == 8) {
              bVar8 = *pbVar9;
              *pbVar12 = bVar8;
              pbVar12[1] = bVar8;
LAB_0000f1fb:
              pbVar12[2] = bVar8;
              pbVar12[3] = 0xff;
LAB_0000f202:
              pbVar9 = pbVar9 + 1;
              pbVar12 = pbVar12 + 4;
            }
            else {
              if (bStack_2 == 0x18) {
                bVar8 = *pbVar9;
                bVar2 = pbVar9[1];
                pbVar7 = pbVar9 + 2;
                pbVar9 = pbVar9 + 2;
                *pbVar12 = *pbVar7;
                pbVar12[1] = bVar2;
                goto LAB_0000f1fb;
              }
              if (bStack_2 == 0x20) {
                bVar8 = *pbVar9;
                bVar2 = pbVar9[1];
                bVar6 = pbVar9[3];
                *pbVar12 = pbVar9[2];
                pbVar9 = pbVar9 + 3;
                pbVar12[1] = bVar2;
                pbVar12[2] = bVar8;
                pbVar12[3] = bVar6;
                goto LAB_0000f202;
              }
              (*_DAT_00011374)(1,s_LoadTGA__illegal_pixel_size___d_,bStack_2,param_1);
            }
          }
          iVar5 = iVar5 + -1;
          pbVar12 = pbVar10 + uVar11 * -4;
          uVar1 = uVar11;
          pbVar10 = pbVar12;
        } while (-1 < iVar5);
      }
    }
    else if (bVar8 == 10) {
      bVar8 = 0;
      bStack_30 = 0;
      bVar2 = 0;
      bStack_2e = 0xff;
joined_r0x0000ef40:
      uStack_2c = uStack_2c - 1;
      if (-1 < (int)uStack_2c) {
        pbVar12 = (byte *)(iVar4 + uStack_2c * uVar11 * 4);
        uStack_24 = 0;
        if (uVar11 != 0) {
          do {
            bVar6 = *pbVar9 & 0x7f;
            pbVar10 = pbVar9 + 1;
            if ((char)*pbVar9 < '\0') {
              if (bStack_2 == 0x18) {
                bVar8 = *pbVar10;
                bVar2 = pbVar9[2];
                pbVar9 = pbVar9 + 3;
                bStack_30 = *pbVar9;
                bStack_2e = 0xff;
LAB_0000efe3:
                pbVar10 = pbVar9 + 1;
              }
              else {
                if (bStack_2 == 0x20) {
                  bVar8 = *pbVar10;
                  bVar2 = pbVar9[2];
                  bStack_30 = pbVar9[3];
                  pbVar9 = pbVar9 + 4;
                  bStack_2e = *pbVar9;
                  goto LAB_0000efe3;
                }
                (*_DAT_00011374)(1,s_LoadTGA__illegal_pixel_size___d_,bStack_2,param_1);
              }
              bStack_2f = 0;
              if (bVar6 != 0xff) {
                pbVar7 = (byte *)(iVar4 + uStack_2c * uVar11 * 4);
                do {
                  *pbVar12 = bStack_30;
                  pbVar12[1] = bVar2;
                  pbVar12[2] = bVar8;
                  pbVar12[3] = bStack_2e;
                  uStack_24 = uStack_24 + 1;
                  pbVar12 = pbVar12 + 4;
                  if (uStack_24 == uVar11) {
                    uStack_24 = 0;
                    pbVar9 = pbVar10;
                    if ((int)uStack_2c < 1) goto joined_r0x0000ef40;
                    uStack_2c = uStack_2c - 1;
                    pbVar7 = pbVar7 + uVar11 * -4;
                    pbVar12 = pbVar7;
                  }
                  bStack_2f = bStack_2f + 1;
                } while (bStack_2f < (byte)(bVar6 + 1));
              }
            }
            else {
              bStack_2f = 0;
              if (bVar6 != 0xff) {
                pbStack_1c = (byte *)(iVar4 + uStack_2c * uVar11 * 4);
                do {
                  if (bStack_2 == 0x18) {
                    bVar8 = *pbVar10;
                    bVar2 = pbVar10[1];
                    bStack_30 = pbVar10[2];
                    pbVar10 = pbVar10 + 2;
                    *pbVar12 = bStack_30;
                    pbVar12[1] = bVar2;
                    pbVar12[2] = bVar8;
                    pbVar12[3] = 0xff;
LAB_0000f0f1:
                    pbVar10 = pbVar10 + 1;
                    pbVar12 = pbVar12 + 4;
                  }
                  else {
                    if (bStack_2 == 0x20) {
                      bVar8 = *pbVar10;
                      bVar2 = pbVar10[1];
                      bStack_30 = pbVar10[2];
                      bStack_2e = pbVar10[3];
                      *pbVar12 = bStack_30;
                      pbVar10 = pbVar10 + 3;
                      pbVar12[1] = bVar2;
                      pbVar12[2] = bVar8;
                      pbVar12[3] = bStack_2e;
                      goto LAB_0000f0f1;
                    }
                    (*_DAT_00011374)(1,s_LoadTGA__illegal_pixel_size___d_,bStack_2,param_1);
                  }
                  uStack_24 = uStack_24 + 1;
                  if (uStack_24 == uVar11) {
                    uStack_24 = 0;
                    pbVar9 = pbVar10;
                    if ((int)uStack_2c < 1) goto joined_r0x0000ef40;
                    uStack_2c = uStack_2c - 1;
                    pbVar12 = pbStack_1c + uVar11 * -4;
                    pbStack_1c = pbVar12;
                  }
                  bStack_2f = bStack_2f + 1;
                } while (bStack_2f < (byte)(bVar6 + 1));
              }
            }
            pbVar9 = pbVar10;
          } while ((int)uStack_24 < (int)uVar11);
        }
        goto joined_r0x0000ef40;
      }
    }
    (*_DAT_000113cc)(local_18);
  }
  return;
}



// ===========================================
// Function: _R_LoadImage @ 0000f23c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_LoadImage(char *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStackY_68;
  char acStack_40 [4];
  int iStack_3c;
  int iStack_38;
  char acStack_34 [52];
  
  *param_5 = 0;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  if (*(int *)(__r_verbose + 0x20) != 0) {
    (*__glConfig)();
  }
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (4 < (int)pcVar2 - (int)(param_1 + 1)) {
    iVar3 = _Q_stricmp();
    if (iVar3 == 0) {
      uStackY_68 = 0xf2d5;
      _strncpy(acStack_40,param_1,0x40);
      pcVar2 = acStack_34;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = pcVar2 + (-5 - (int)&stack0xffffff9c);
      (&stack0xffffff9d)[(int)pcVar2] = 0x66;
      (&stack0xffffff9e)[(int)pcVar2] = 0x74;
      (&stack0xffffff9f)[(int)pcVar2] = 0x78;
      _LoadFTX();
      if (*param_2 == 0) {
        iStack_38 = 0;
        _LoadTGA();
      }
    }
    else {
      iVar3 = _Q_stricmp();
      if (iVar3 == 0) {
        _LoadGHOST();
      }
    }
    if (*(int *)(__r_verbose + 0x20) != 0) {
      iVar3 = (*__glConfig)();
      __pc_imageTime = __pc_imageTime + (iVar3 - iStack_3c);
      if (iStack_38 != 0) {
        (*__ri)();
        return;
      }
      (*__ri)();
    }
  }
  return;
}



// ===========================================
// Function: _R_FindImageFile @ 0000f3aa
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * _R_FindImageFile(byte *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  bool bVar8;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pbVar2 = param_1;
  if (param_1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  iVar3 = generateHashValue();
  for (pbVar5 = *(byte **)(&_hashTable + iVar3 * 4); pbVar4 = pbVar2, pbVar7 = pbVar5,
      pbVar5 != (byte *)0x0; pbVar5 = *(byte **)(pbVar5 + 0x7c)) {
    do {
      bVar1 = *pbVar4;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0000f3fa:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0000f3ff;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0000f3fa;
      pbVar4 = pbVar4 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0000f3ff:
    if (iVar3 == 0) {
      pcVar6 = s__white;
      pbVar4 = pbVar2;
      goto LAB_0000f440;
    }
  }
  _R_LoadImage(pbVar2,&param_1,&local_4,&local_8,&local_c);
  if (param_1 == (byte *)0x0) {
    return param_1;
  }
  pbVar4 = (byte *)_R_CreateImage(pbVar2,param_1,local_4,local_8,param_2,param_3,param_4,local_c,
                                  param_5);
  pbVar5 = pbVar2;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != 0);
  if (4 < (int)pbVar5 - (int)(pbVar2 + 1)) {
    pbVar7 = &s__gst;
    pbVar5 = pbVar2 + ((int)pbVar5 - (int)(pbVar2 + 1)) + -4;
    do {
      bVar1 = *pbVar5;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0000f54a:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0000f54f;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0000f54a;
      pbVar5 = pbVar5 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0000f54f:
    if (iVar3 == 0) {
      _R_SetGhostImage(pbVar2,pbVar4);
    }
  }
  (*___chkstk)(param_1);
  return pbVar4;
  while( true ) {
    bVar1 = pbVar4[1];
    bVar8 = bVar1 < ((byte *)pcVar6)[1];
    if (bVar1 != ((byte *)pcVar6)[1]) goto LAB_0000f460;
    pbVar4 = pbVar4 + 2;
    pcVar6 = (char *)((byte *)pcVar6 + 2);
    if (bVar1 == 0) break;
LAB_0000f440:
    bVar1 = *pbVar4;
    bVar8 = bVar1 < (byte)*pcVar6;
    if (bVar1 != *pcVar6) {
LAB_0000f460:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0000f465;
    }
    if (bVar1 == 0) break;
  }
  iVar3 = 0;
LAB_0000f465:
  if (iVar3 != 0) {
    if (*(int *)(pbVar5 + 0x60) != param_2) {
      (*__ri)(1,s_WARNING__reused_image__s_with_mi,pbVar2);
    }
    if (*(int *)(pbVar5 + 0x68) != param_3) {
      (*__ri)(1,s_WARNING__reused_image__s_with_mi,pbVar2);
    }
    if (*(int *)(pbVar5 + 0x70) != param_5) {
      (*__ri)(0,s_WARNING__reused_image__s_with_mi,pbVar2);
    }
  }
  if (__r_registration_active == 0) {
    return pbVar5;
  }
  if (*(int *)(pbVar5 + 0x74) == -1) {
    return pbVar5;
  }
  *(undefined4 *)(pbVar5 + 0x74) = __r_sequencenumber;
  return pbVar5;
}



// ===========================================
// Function: _R_InitFogTable @ 0000f5ad
// ===========================================

void _R_InitFogTable(void)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = 0;
  do {
    fVar2 = (float10)__CIpow();
    *(float *)(&DAT_0005d300 + iVar1 * 4) = (float)fVar2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return;
}



// ===========================================
// Function: _R_FogFactor @ 0000f5e9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _R_FogFactor(float param_1,float param_2)

{
  float10 fVar1;
  int iVar2;
  
  fVar1 = (float10)0;
  if (((float10)(param_1 - (float)___real_3f60000000000000) < fVar1 ==
       (NAN((float10)(param_1 - (float)___real_3f60000000000000)) || NAN(fVar1))) &&
     (param_2 < ___real_3d000000 == (NAN(param_2) || NAN(___real_3d000000)))) {
    iVar2 = __ftol2_sse();
    return (float10)*(float *)(&DAT_0005d300 + iVar2 * -4);
  }
  return fVar1;
}



// ===========================================
// Function: _R_CreateFogImage @ 0000f687
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_CreateFogImage(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int iStack_24;
  int iStack_20;
  undefined1 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar4 = (*_DAT_00011384)(0x8000);
  iStack_20 = 0;
  do {
    iStack_24 = 0;
    fVar2 = (float)___real_3fe0000000000000;
    fVar1 = (float)___real_3f70000000000000;
    do {
      fVar6 = (float10)_R_FogFactor(((float)iStack_20 + fVar2) * fVar1,
                                    ((float)iStack_24 + (float)___real_3fe0000000000000) *
                                    (float)___real_3fa0000000000000);
      iVar5 = __ftol2_sse();
      fVar3 = (float)___real_406fe00000000000;
      iStack_24 = iStack_24 + 1;
      *(undefined1 *)(iVar4 + 2 + iVar5) = 0xff;
      *(undefined1 *)(iVar4 + 1 + iVar5) = 0xff;
      *(undefined1 *)(iVar5 + iVar4) = 0xff;
      uStack_18 = (undefined1)(int)ROUND((float)fVar6 * fVar3);
      *(undefined1 *)(iVar4 + 3 + iVar5) = uStack_18;
    } while ((float)iStack_24 < ___real_42000000);
    iStack_20 = iStack_20 + 1;
  } while ((float)iStack_20 < ___real_43800000);
  ___ftol2_sse = _R_CreateImage(s__fog,iVar4,0x100,0x20,0,0,0,1,&DAT_00002900);
  *(undefined4 *)(___ftol2_sse + 0x74) = 0xffffffff;
  (*___fltused)(iVar4);
  uStack_10 = 0x3f800000;
  uStack_c = 0x3f800000;
  uStack_8 = 0x3f800000;
  uStack_4 = 0x3f800000;
  (*__qglTexParameterfv)(0xde1,0x1004,&uStack_10);
  return;
}



// ===========================================
// Function: _R_CreateDefaultImage @ 0000f805
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_CreateDefaultImage(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 local_400;
  undefined4 uStack_3fc;
  undefined *puStack_3f8;
  undefined1 local_3f4 [960];
  undefined1 auStack_34 [52];
  
  _memset(&local_400,0x20,0x400);
  iVar1 = 0;
  puVar2 = local_3f4 + 2;
  do {
    local_3f4[iVar1 * 4 + 3] = 0xff;
    local_3f4[iVar1 * 4 + 2] = 0xff;
    local_3f4[iVar1 * 4 + 1] = 0xff;
    local_3f4[iVar1 * 4] = 0xff;
    puVar2[1] = 0xff;
    *puVar2 = 0xff;
    puVar2[-1] = 0xff;
    puVar2[-2] = 0xff;
    auStack_34[iVar1 * 4 + 3] = 0xff;
    auStack_34[iVar1 * 4 + 2] = 0xff;
    auStack_34[iVar1 * 4 + 1] = 0xff;
    auStack_34[iVar1 * 4] = 0xff;
    puVar2[0x3d] = 0xff;
    puVar2[0x3c] = 0xff;
    puVar2[0x3b] = 0xff;
    puVar2[0x3a] = 0xff;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x40;
  } while (iVar1 < 0x10);
  puStack_3f8 = &DAT_00002901;
  uStack_3fc = 0;
  local_400 = 0;
  ___chkstk = _R_CreateImage(s__default,local_3f4,0x10,0x10,1,0);
  *(undefined4 *)(___chkstk + 0x74) = 0xffffffff;
  return;
}



// ===========================================
// Function: _R_CreateBuiltinImages @ 0000f8a5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_CreateBuiltinImages(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 local_400 [12];
  undefined1 local_3f4;
  undefined1 local_3f3 [1011];
  
  _R_CreateDefaultImage();
  _memset(local_400,0xff,0x400);
  _DAT_000113a4 = _R_CreateImage(s__white,&local_3f4,8,8,0,0,0,0,&DAT_00002901);
  *(undefined4 *)(_DAT_000113a4 + 0x74) = 0xffffffff;
  puVar3 = local_3f3;
  iVar4 = 0x10;
  do {
    iVar2 = 0x10;
    puVar1 = puVar3;
    do {
      puVar1[1] = DAT_00011d28;
      *puVar1 = DAT_00011d28;
      puVar1[-1] = DAT_00011d28;
      puVar1[2] = 0xff;
      puVar1 = puVar1 + 0x40;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar3 = puVar3 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  __r_simpleMipMaps = _R_CreateImage(s__identityLight,&local_3f4,8,8,0,0,0,0,&DAT_00002901);
  *(undefined4 *)(__r_simpleMipMaps + 0x74) = 0xffffffff;
  _DAT_00011394 = _R_CreateImage(s__scratch,&local_3f4,0x10,0x10,0,1,0,0,&DAT_00002900);
  *(undefined4 *)(_DAT_00011394 + 0x74) = 0xffffffff;
  _DAT_0001139c = _R_FindImageFile(s_gfx_2d_proj_lobe_tga,0,0,1,&DAT_00002900);
  if (_DAT_0001139c != 0) {
    *(undefined4 *)(_DAT_0001139c + 0x74) = 0xffffffff;
    _R_CreateFogImage();
    return;
  }
  (*_DAT_00011374)(1,s_R_CreateDlightImage__couldnt_loa);
  _R_CreateFogImage();
  return;
}



// ===========================================
// Function: _R_SetColorMappings @ 0000f9c5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetColorMappings(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  float10 fVar6;
  float10 extraout_ST0;
  char *pcVar7;
  float fVar8;
  float fVar9;
  
  iVar5 = 0;
  if (__r_overBrightBits == 0) {
    _DAT_00011d2c = 0;
  }
  else {
    _DAT_00011d2c = *(int *)(__r_overBrightBits + 0x20);
  }
  if (_DAT_00012794 == 0) {
    _DAT_00011d2c = 0;
  }
  if (_DAT_000127b4 == 0) {
    _DAT_00011d2c = 0;
  }
  if (_DAT_00012780 < 0x11) {
    if (_DAT_00011d2c < 2) goto LAB_0000fa25;
    _DAT_00011d2c = 1;
  }
  else if (_DAT_00011d2c < 3) {
LAB_0000fa25:
    if (_DAT_00011d2c < 0) {
      _DAT_00011d2c = 0;
    }
  }
  else {
    _DAT_00011d2c = 2;
  }
  bVar4 = (byte)_DAT_00011d2c;
  _DAT_00011d24 = 1.0 / (float)(1 << (bVar4 & 0x1f));
  _DAT_00011d28 = __ftol2_sse();
  if ((__r_intensity != 0) && (*(float *)(__r_intensity + 0x1c) <= 1.0)) {
    (*___ftol2_sse)(s_r_intensity,s_1);
    bVar4 = (byte)_DAT_00011d2c;
  }
  if (__r_gamma != 0) {
    if (___real_3f000000 <= *(float *)(__r_gamma + 0x1c)) {
      if (___real_40400000 < *(float *)(__r_gamma + 0x1c) !=
          (NAN(___real_40400000) || NAN(*(float *)(__r_gamma + 0x1c)))) {
        pcVar7 = s_3_0;
        goto LAB_0000fad1;
      }
    }
    else {
      pcVar7 = s_0_5;
LAB_0000fad1:
      (*___ftol2_sse)(s_r_gamma,pcVar7);
      bVar4 = (byte)_DAT_00011d2c;
    }
    if (__r_gamma != 0) {
      fVar9 = *(float *)(__r_gamma + 0x1c);
      goto LAB_0000fb04;
    }
  }
  fVar9 = (float)___real_3ff3333333333333;
LAB_0000fb04:
  iVar2 = _DAT_00012794;
  iVar1 = __r_intensity;
  fVar8 = fVar9;
  if (((_DAT_00012794 == 0) && (NAN(fVar9) == (fVar9 == 1.0))) ||
     ((__r_intensity != 0 &&
      (NAN(*(float *)(__r_intensity + 0x1c)) == (*(float *)(__r_intensity + 0x1c) == 1.0))))) {
    _DAT_00011d30 = 1;
  }
  else {
    _DAT_00011d30 = 0;
  }
  do {
    iVar3 = iVar5;
    if (NAN(fVar9) == (fVar9 == 1.0)) {
      __CIpow();
      fVar9 = fVar8;
      iVar3 = __ftol2_sse();
      fVar8 = fVar9;
    }
    fVar6 = (float10)1;
    iVar3 = iVar3 << (bVar4 & 0x1f);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0xff < iVar3) {
      iVar3 = 0xff;
    }
    *(char *)(iVar5 + 0x2000) = (char)iVar3;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x100);
  iVar5 = 0;
  do {
    if (iVar1 == 0) {
      fVar9 = (float)fVar6;
    }
    else {
      fVar9 = *(float *)(iVar1 + 0x1c);
    }
    iVar3 = __ftol2_sse();
    if (0xff < iVar3) {
      iVar3 = 0xff;
    }
    (&_s_intensitytable)[iVar5] = (char)iVar3;
    iVar5 = iVar5 + 1;
    fVar6 = extraout_ST0;
  } while (iVar5 < 0x100);
  if (iVar2 != 0) {
    _GLimp_SetGamma(0x2000,0x2000,0x2000,iVar5,fVar9);
  }
  return;
}



// ===========================================
// Function: _R_InitImages @ 0000fc21
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_InitImages(void)

{
  _memset(&_hashTable,0,0x1000);
  _memset(&DAT_000252f8,0,0x30000);
  _DAT_000252f4 = 0;
  _R_SetColorMappings();
  _R_CreateBuiltinImages();
  return;
}



// ===========================================
// Function: _R_DeleteImageFromHash @ 0000fc5a
// ===========================================

void _R_DeleteImageFromHash(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = generateHashValue();
  iVar4 = 0;
  iVar1 = *(int *)(&_hashTable + iVar2 * 4);
  if (*(int *)(&_hashTable + iVar2 * 4) != 0) {
    while (iVar3 = iVar1, param_1 != iVar3) {
      iVar1 = *(int *)(iVar3 + 0x7c);
      iVar4 = iVar3;
      if (*(int *)(iVar3 + 0x7c) == 0) {
        return;
      }
    }
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x7c) = *(undefined4 *)(iVar3 + 0x7c);
      return;
    }
    *(undefined4 *)(&_hashTable + iVar2 * 4) = *(undefined4 *)(iVar3 + 0x7c);
  }
  return;
}



// ===========================================
// Function: _R_FreeImage @ 0000fca1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_FreeImage(void *param_1)

{
  if (*(int *)((int)param_1 + 0x50) != 0) {
    (*__qglDeleteTextures)(1,(int)param_1 + 0x50);
  }
  _R_DeleteImageFromHash(param_1);
  _memset(param_1,0,0x80);
  return;
}



// ===========================================
// Function: _R_DeleteTextures @ 0000fcd0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DeleteTextures(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *__s;
  int iVar5;
  
  iVar5 = 0;
  if (0 < _DAT_000252f4) {
    __s = &DAT_000252f8;
    do {
      if (*(int *)(__s + 0x50) != 0) {
        (*__qglDeleteTextures)(1,__s + 0x50);
      }
      iVar4 = generateHashValue();
      puVar3 = *(undefined1 **)(&_hashTable + iVar4 * 4);
      puVar2 = (undefined1 *)0x0;
      while (puVar1 = puVar3, puVar1 != (undefined1 *)0x0) {
        if (__s == puVar1) {
          if (puVar2 == (undefined1 *)0x0) {
            *(undefined4 *)(&_hashTable + iVar4 * 4) = *(undefined4 *)(puVar1 + 0x7c);
          }
          else {
            *(undefined4 *)(puVar2 + 0x7c) = *(undefined4 *)(puVar1 + 0x7c);
          }
          break;
        }
        puVar2 = puVar1;
        puVar3 = *(undefined1 **)(puVar1 + 0x7c);
      }
      _memset(__s,0,0x80);
      iVar5 = iVar5 + 1;
      __s = __s + 0x80;
    } while (iVar5 < _DAT_000252f4);
  }
  _memset(&DAT_000252f8,0,0x30000);
  __glState = 0;
  _DAT_00011404 = 0;
  _DAT_000252f4 = 0;
  if (__qglBindTexture != (code *)0x0) {
    if (__qglActiveTextureARB != 0) {
      _GL_SelectTexture();
      (*__qglBindTexture)();
      _GL_SelectTexture();
      (*__qglBindTexture)();
      return;
    }
    (*__qglBindTexture)();
  }
  return;
}



// ===========================================
// Function: _R_FreeUnusedImages @ 0000fdbf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_FreeUnusedImages(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < _DAT_000252f4) {
    piVar2 = (int *)&DAT_0002536c;
    do {
      if ((((char)piVar2[-0x1d] != '\0') && (*piVar2 != __r_sequencenumber)) && (*piVar2 != -1)) {
        if (piVar2[-9] != 0) {
          (*__qglDeleteTextures)(1,piVar2 + -9);
        }
        _R_DeleteImageFromHash(piVar2 + -0x1d);
        _memset(piVar2 + -0x1d,0,0x80);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x20;
    } while (iVar1 < _DAT_000252f4);
  }
  return;
}



// ===========================================
// Function: _CommaParse @ 0000fe21
// ===========================================

char * _CommaParse(void)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 *unaff_EDI;
  
  pcVar2 = (char *)*unaff_EDI;
  iVar4 = 0;
  `CommaParse'::__l2::com_token = 0;
  if (pcVar2 == (char *)0x0) {
    *unaff_EDI = 0;
    return &`CommaParse'::__l2::com_token;
  }
LAB_0000fe41:
  do {
    cVar3 = *pcVar2;
    while ((cVar3 < '!' && (cVar3 != '\0'))) {
      pcVar1 = pcVar2 + 1;
      pcVar2 = pcVar2 + 1;
      cVar3 = *pcVar1;
    }
    cVar3 = *pcVar2;
    if (cVar3 != '/') {
      if (cVar3 == '\0') {
        return s_;
      }
      if (cVar3 != '\"') goto LAB_0000fef1;
      cVar3 = pcVar2[1];
      pcVar2 = pcVar2 + 2;
      if (cVar3 != '\"') {
        while (cVar3 != '\0') {
          if (iVar4 < 0x400) {
            (&`CommaParse'::__l2::com_token)[iVar4] = cVar3;
            iVar4 = iVar4 + 1;
          }
          cVar3 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          if (cVar3 == '\"') {
            (&`CommaParse'::__l2::com_token)[iVar4] = 0;
            *unaff_EDI = pcVar2;
            return &`CommaParse'::__l2::com_token;
          }
        }
      }
LAB_0000ff19:
      (&`CommaParse'::__l2::com_token)[iVar4] = 0;
      *unaff_EDI = pcVar2;
      return &`CommaParse'::__l2::com_token;
    }
    if (pcVar2[1] != '/') {
      if (pcVar2[1] != '*') {
        do {
          (&`CommaParse'::__l2::com_token)[iVar4] = cVar3;
          iVar4 = iVar4 + 1;
          do {
            cVar3 = pcVar2[1];
            pcVar2 = pcVar2 + 1;
            if ((cVar3 < '!') || (cVar3 == ',')) {
              if (iVar4 == 0x400) {
                iVar4 = 0;
              }
              goto LAB_0000ff19;
            }
LAB_0000fef1:
          } while (0x3ff < iVar4);
        } while( true );
      }
      cVar3 = '/';
      do {
        if ((cVar3 == '*') && (pcVar2[1] == '/')) {
          if (*pcVar2 != '\0') {
            pcVar2 = pcVar2 + 2;
          }
          break;
        }
        cVar3 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      } while (cVar3 != '\0');
      goto LAB_0000fe41;
    }
    cVar3 = '/';
    do {
      if (cVar3 == '\n') break;
      cVar3 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while (cVar3 != '\0');
  } while( true );
}



// ===========================================
// Function: _RE_RegisterSkin @ 0000ff2a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _RE_RegisterSkin(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  byte *pbVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  bool bVar12;
  char *pcStack_44;
  undefined1 auStack_40 [60];
  char *pcStack_4;
  
  if ((param_1 == (byte *)0x0) || (*param_1 == 0)) {
    _Com_Printf(s_Empty_name_passed_to_RE_Register);
    return 0;
  }
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (bVar1 != 0);
  if (0x3f < (uint)((int)pbVar2 - (int)(param_1 + 1))) {
    _Com_Printf(s_Skin_name_exceeds_MAX_QPATH_);
    return 0;
  }
  uVar11 = 1;
  if (1 < _DAT_000572fc) {
    do {
      pbVar2 = *(byte **)(&DAT_00057300 + uVar11 * 4);
      pbVar8 = param_1;
      do {
        bVar1 = *pbVar2;
        bVar12 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0000ffaa:
          iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_0000ffaf;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar12 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0000ffaa;
        pbVar2 = pbVar2 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0000ffaf:
      if (iVar3 == 0) {
        return -(uint)(*(int *)(*(byte **)(&DAT_00057300 + uVar11 * 4) + 0x40) != 0) & uVar11;
      }
      uVar11 = uVar11 + 1;
    } while ((int)uVar11 < _DAT_000572fc);
  }
  if (_DAT_000572fc == 0x400) {
    (*__ri)(3,s_WARNING__RE_RegisterSkin____s___,param_1);
    return 0;
  }
  _DAT_000572fc = _DAT_000572fc + 1;
  iVar3 = (*__Q_stricmp)(0xc4);
  *(int *)(&DAT_00057300 + uVar11 * 4) = iVar3;
  _Q_strncpyz(iVar3,param_1,0x40);
  *(undefined4 *)(iVar3 + 0x40) = 0;
  _R_SyncRenderThread();
  pbVar2 = param_1;
  do {
    pbVar8 = pbVar2;
    pbVar2 = pbVar8 + 1;
  } while (*pbVar8 != 0);
  pcVar9 = s__skin;
  pbVar8 = pbVar8 + -5;
  do {
    bVar1 = *pbVar8;
    bVar12 = bVar1 < (byte)*pcVar9;
    if (bVar1 != *pcVar9) {
LAB_0001005c:
      iVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_00010061;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar8[1];
    bVar12 = bVar1 < ((byte *)pcVar9)[1];
    if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0001005c;
    pbVar8 = pbVar8 + 2;
    pcVar9 = (char *)((byte *)pcVar9 + 2);
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00010061:
  if (iVar4 == 0) {
    (*__qglTexImage2D)(param_1,&pcStack_44);
    pcVar9 = pcStack_44;
    pcVar10 = pcStack_44;
    if (pcStack_44 != (char *)0x0) {
      do {
        if (*pcVar10 == '\0') break;
        pcVar6 = (char *)_CommaParse();
        _Q_strncpyz(auStack_40,pcVar6,0x40);
        if (*pcVar6 == '\0') break;
        _Q_strlwr(auStack_40);
        if (*pcStack_4 == ',') {
          pcStack_4 = pcStack_4 + 1;
        }
        pcVar10 = pcStack_4;
        pcVar6 = _strstr(pcVar6,s_tag_);
        if (pcVar6 == (char *)0x0) {
          uVar5 = _CommaParse();
          uVar7 = (*__Q_stricmp)(0x44);
          *(undefined4 *)(iVar3 + 0x44 + *(int *)(iVar3 + 0x40) * 4) = uVar7;
          iVar4 = *(int *)(iVar3 + 0x44 + *(int *)(iVar3 + 0x40) * 4);
          _Q_strncpyz(iVar4,auStack_40,0x40);
          uVar5 = _R_FindShader(uVar5,0xffffffff,1,1,1);
          *(undefined4 *)(iVar4 + 0x40) = uVar5;
          *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + 1;
          pcVar10 = pcVar9;
        }
      } while (pcVar10 != (char *)0x0);
      (*_DAT_000113cc)(pcStack_44);
      if (*(int *)(iVar3 + 0x40) != 0) goto LAB_0001008e;
    }
    _GLimp_Suspend();
    return 0;
  }
  *(undefined4 *)(iVar3 + 0x40) = 1;
  uVar5 = (*__Q_stricmp)(4);
  *(undefined4 *)(iVar3 + 0x44) = uVar5;
  uVar5 = _R_FindShader(param_1,0xffffffff,1,1,1);
  *(undefined4 *)(*(int *)(iVar3 + 0x44) + 0x40) = uVar5;
LAB_0001008e:
  _GLimp_Suspend();
  return uVar11;
}



// ===========================================
// Function: _R_InitSkins @ 000101a2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_InitSkins(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_000572fc = 1;
  iVar1 = (*__Q_stricmp)(0xc4);
  _DAT_00057300 = iVar1;
  _Q_strncpyz(iVar1,s_<default_skin>,0x40);
  *(undefined4 *)(iVar1 + 0x40) = 1;
  iVar2 = (*__Q_stricmp)(0x44);
  *(int *)(iVar1 + 0x44) = iVar2;
  *(undefined4 *)(iVar2 + 0x40) = _DAT_000113ac;
  return;
}



// ===========================================
// Function: _R_GetSkinByHandle @ 000101ec
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_GetSkinByHandle(int param_1)

{
  if ((0 < param_1) && (param_1 < _DAT_000572fc)) {
    return *(undefined4 *)(&DAT_00057300 + param_1 * 4);
  }
  return _DAT_00057300;
}



// ===========================================
// Function: _R_SkinList_f @ 0001020b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SkinList_f(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  (*__ri)(0,s____________________);
  iVar2 = 0;
  if (0 < _DAT_000572fc) {
    do {
      iVar1 = *(int *)(&DAT_00057300 + iVar2 * 4);
      (*__ri)(0,s__3i__s_,iVar2,iVar1);
      iVar3 = 0;
      if (0 < *(int *)(iVar1 + 0x40)) {
        piVar4 = (int *)(iVar1 + 0x44);
        do {
          (*__ri)(0,s_________s____s_,*piVar4,*(undefined4 *)(*piVar4 + 0x40));
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar3 < *(int *)(iVar1 + 0x40));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < _DAT_000572fc);
  }
  (*__ri)(0,s____________________);
  return;
}



// ===========================================
// Function: _R_RefreshImageFile @ 0001028c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_RefreshImageFile(byte *param_1)

{
  byte bVar1;
  byte *__s;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  byte *pbVar5;
  bool bVar6;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  byte *in_stack_00000020;
  byte *local_40 [3];
  undefined1 local_34 [52];
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  _strncpy((char *)local_40,(char *)param_1,0x40);
  local_40[0] = (byte *)0x102b7;
  iVar2 = generateHashValue();
  __s = *(byte **)(&_hashTable + iVar2 * 4);
  do {
    pbVar3 = param_1;
    pbVar5 = __s;
    if (__s == (byte *)0x0) {
LAB_00010326:
      local_40[0] = in_stack_00000020;
      uVar4 = _R_FindImageFile(local_34,in_stack_00000014,in_stack_00000018,in_stack_0000001c);
      return uVar4;
    }
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_000102ec:
        iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_000102f1;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_000102ec;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_000102f1:
    if (iVar2 == 0) {
      local_40[0] = __s + 0x50;
      if (*(int *)(__s + 0x50) != 0) {
        (*__qglDeleteTextures)(1);
      }
      local_40[0] = __s;
      _R_DeleteImageFromHash();
      _memset(__s,0,0x80);
      goto LAB_00010326;
    }
    __s = *(byte **)(__s + 0x7c);
  } while( true );
}



