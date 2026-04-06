// ===========================================
// Function: _AddSkyPolygon @ 0000a700
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _AddSkyPolygon(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float *in_EAX;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float local_18;
  float local_14;
  float local_10;
  
  local_18 = __vec3_origin;
  iVar9 = 0;
  local_14 = _DAT_0000d144;
  local_10 = ___fltused;
  pfVar7 = in_EAX;
  if (3 < param_1) {
    iVar8 = (param_1 - 4U >> 2) + 1;
    iVar9 = iVar8 * 4;
    pfVar6 = in_EAX;
    do {
      pfVar7 = pfVar6 + 0xc;
      iVar8 = iVar8 + -1;
      local_18 = pfVar6[9] + pfVar6[6] + pfVar6[3] + local_18 + *pfVar6;
      local_14 = pfVar6[10] + pfVar6[7] + pfVar6[4] + pfVar6[1] + local_14;
      local_10 = pfVar6[0xb] + pfVar6[8] + pfVar6[5] + pfVar6[2] + local_10;
      pfVar6 = pfVar7;
    } while (iVar8 != 0);
  }
  if (iVar9 < param_1) {
    iVar9 = param_1 - iVar9;
    do {
      iVar9 = iVar9 + -1;
      local_18 = local_18 + *pfVar7;
      local_14 = pfVar7[1] + local_14;
      local_10 = pfVar7[2] + local_10;
      pfVar7 = pfVar7 + 3;
    } while (iVar9 != 0);
  }
  fVar5 = ABS(local_18);
  fVar1 = ABS(local_14);
  fVar2 = ABS(local_10);
  if ((fVar1 < fVar5 == (NAN(fVar1) || NAN(fVar5))) || (fVar2 < fVar5 == (NAN(fVar2) || NAN(fVar5)))
     ) {
    if ((fVar1 <= fVar2) || (fVar5 < fVar1 == (NAN(fVar5) || NAN(fVar1)))) {
      iVar9 = 5;
      if (0.0 <= local_10) {
        iVar9 = 4;
      }
    }
    else if (0.0 <= local_14) {
      iVar9 = 2;
    }
    else {
      iVar9 = 3;
    }
  }
  else if (0.0 <= local_18) {
    iVar9 = 0;
  }
  else {
    iVar9 = 1;
  }
  if (0 < param_1) {
    fVar5 = (float)___real_3f50624dd2f1a9fc;
    iVar8 = *(int *)(iVar9 * 0xc + 0x3650);
    do {
      if (iVar8 < 1) {
        fVar1 = -*(float *)((int)in_EAX - (iVar8 * 4 + 4));
      }
      else {
        fVar1 = in_EAX[iVar8 + -1];
      }
      if (fVar1 < fVar5 == (NAN(fVar1) || NAN(fVar5))) {
        iVar4 = *(int *)(&`AddSkyPolygon'::__l2::vec_to_st + iVar9 * 0xc);
        if (iVar4 < 0) {
          fVar2 = -*(float *)((int)in_EAX - (iVar4 * 4 + 4));
        }
        else {
          fVar2 = in_EAX[iVar4 + -1];
        }
        fVar2 = fVar2 / fVar1;
        iVar4 = *(int *)(iVar9 * 0xc + 0x364c);
        if (iVar4 < 0) {
          fVar3 = -*(float *)((int)in_EAX - (iVar4 * 4 + 4));
        }
        else {
          fVar3 = in_EAX[iVar4 + -1];
        }
        fVar3 = fVar3 / fVar1;
        if (fVar2 < (float)(&_sky_mins)[iVar9]) {
          (&_sky_mins)[iVar9] = fVar2;
        }
        if (fVar3 < (float)(&DAT_000023e8)[iVar9]) {
          (&DAT_000023e8)[iVar9] = fVar3;
        }
        if ((float)(&_sky_maxs)[iVar9] < fVar2 != (NAN((float)(&_sky_maxs)[iVar9]) || NAN(fVar2))) {
          (&_sky_maxs)[iVar9] = fVar2;
        }
        if ((float)(&DAT_00002418)[iVar9] < fVar3 !=
            (NAN((float)(&DAT_00002418)[iVar9]) || NAN(fVar3))) {
          (&DAT_00002418)[iVar9] = fVar3;
        }
      }
      in_EAX = in_EAX + 3;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



// ===========================================
// Function: _ClipSkyPolygon @ 0000a9d6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ClipSkyPolygon(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  bool bVar6;
  bool bVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  int iStack_830;
  float *pfStack_82c;
  float *pfStack_828;
  float *pfStack_824;
  float *pfStack_820;
  float *pfStack_81c;
  int iStack_818;
  int iStack_814;
  float *pfStack_810;
  float *pfStack_80c;
  float *pfStack_808;
  int aiStack_800 [64];
  float afStack_700 [64];
  float fStack_600;
  float fStack_5fc;
  float afStack_5f8 [190];
  float fStack_300;
  float fStack_2fc;
  float afStack_2f8 [190];
  
  if (0x3e < param_1) {
    (*_DAT_0000d154)(1,s_ClipSkyPolygon__MAX_CLIP_VERTS);
  }
  if (param_3 == 6) {
    _AddSkyPolygon();
    return;
  }
  iVar9 = 0;
  bVar6 = false;
  iVar2 = param_3 * 0xc;
  bVar7 = false;
  if (0 < param_1) {
    pfVar8 = (float *)(param_2 + 2);
    do {
      fVar3 = *(float *)(&DAT_00003608 + iVar2) * *pfVar8 +
              pfVar8[-1] * *(float *)(&DAT_00003604 + iVar2) +
              pfVar8[-2] * *(float *)(&_sky_clip + iVar2);
      dVar5 = (double)fVar3;
      if (dVar5 <= ___real_3fb999999999999a) {
        if (dVar5 < ___real_bfb999999999999a == (NAN(dVar5) || NAN(___real_bfb999999999999a))) {
          aiStack_800[iVar9] = 2;
        }
        else {
          bVar7 = true;
          aiStack_800[iVar9] = 1;
        }
      }
      else {
        bVar6 = true;
        aiStack_800[iVar9] = 0;
      }
      afStack_700[iVar9] = fVar3;
      iVar9 = iVar9 + 1;
      pfVar8 = pfVar8 + 3;
    } while (iVar9 < param_1);
    if ((bVar6) && (bVar7)) {
      afStack_700[iVar9] = afStack_700[0];
      aiStack_800[iVar9] = aiStack_800[0];
      puVar1 = param_2 + iVar9 * 3;
      *puVar1 = *param_2;
      pfVar8 = (float *)(param_2 + 1);
      pfStack_82c = afStack_2f8;
      puVar1[1] = *pfVar8;
      iStack_814 = 0;
      iStack_818 = 0;
      puVar1[2] = param_2[2];
      iStack_830 = 0;
      pfVar12 = afStack_5f8;
      pfStack_828 = &fStack_2fc;
      pfStack_824 = afStack_2f8;
      pfVar11 = &fStack_5fc;
      pfVar13 = &fStack_300;
      pfVar10 = &fStack_600;
      pfStack_820 = pfVar10;
      pfStack_81c = pfVar11;
      pfStack_810 = pfVar13;
      pfStack_80c = pfVar12;
      pfStack_808 = pfStack_828;
      do {
        iVar2 = aiStack_800[iStack_830];
        if (iVar2 == 0) {
          iStack_818 = iStack_818 + 1;
          *pfVar10 = pfVar8[-1];
          pfStack_820 = pfStack_820 + 3;
          pfStack_81c = pfStack_81c + 3;
          *pfVar11 = *pfVar8;
          pfVar10 = pfVar10 + 3;
          *pfVar12 = pfVar8[1];
          pfVar11 = pfVar11 + 3;
          pfVar12 = pfVar12 + 3;
          pfStack_80c = pfStack_80c + 3;
        }
        else {
          if (iVar2 != 1) {
            if (iVar2 != 2) goto LAB_0000ac1e;
            iStack_818 = iStack_818 + 1;
            pfStack_820 = pfStack_820 + 3;
            *pfVar10 = pfVar8[-1];
            pfStack_81c = pfStack_81c + 3;
            *pfVar11 = *pfVar8;
            pfVar10 = pfVar10 + 3;
            pfVar11 = pfVar11 + 3;
            *pfVar12 = pfVar8[1];
            pfVar12 = pfVar12 + 3;
            pfStack_80c = pfStack_80c + 3;
          }
          iStack_814 = iStack_814 + 1;
          *pfVar13 = pfVar8[-1];
          *pfStack_828 = *pfVar8;
          *pfStack_824 = pfVar8[1];
          pfStack_824 = pfStack_824 + 3;
          pfStack_810 = pfStack_810 + 3;
          pfStack_808 = pfStack_808 + 3;
          pfStack_828 = pfStack_828 + 3;
          pfVar13 = pfVar13 + 3;
          pfStack_82c = pfStack_82c + 3;
        }
LAB_0000ac1e:
        if (((aiStack_800[iStack_830] != 2) && (aiStack_800[iStack_830 + 1] != 2)) &&
           (aiStack_800[iStack_830 + 1] != aiStack_800[iStack_830])) {
          iStack_818 = iStack_818 + 1;
          iStack_814 = iStack_814 + 1;
          pfStack_828 = pfStack_828 + 3;
          fVar3 = afStack_700[iStack_830] / (afStack_700[iStack_830] - afStack_700[iStack_830 + 1]);
          pfStack_824 = pfStack_824 + 3;
          pfVar10 = pfVar10 + 3;
          pfVar11 = pfVar11 + 3;
          pfVar12 = pfVar12 + 3;
          pfVar13 = pfVar13 + 3;
          fVar4 = pfVar8[-1] + fVar3 * (pfVar8[2] - pfVar8[-1]);
          *pfStack_820 = fVar4;
          *pfStack_810 = fVar4;
          pfStack_810 = pfStack_810 + 3;
          fVar4 = (pfVar8[3] - *pfVar8) * fVar3 + *pfVar8;
          *pfStack_81c = fVar4;
          *pfStack_808 = fVar4;
          fVar3 = (pfVar8[4] - pfVar8[1]) * fVar3 + pfVar8[1];
          *pfStack_80c = fVar3;
          *pfStack_82c = fVar3;
          pfStack_82c = pfStack_82c + 3;
          pfStack_820 = pfStack_820 + 3;
          pfStack_81c = pfStack_81c + 3;
          pfStack_80c = pfStack_80c + 3;
          pfStack_808 = pfStack_808 + 3;
        }
        iStack_830 = iStack_830 + 1;
        pfVar8 = pfVar8 + 3;
        if (param_1 <= iStack_830) {
          _ClipSkyPolygon(iStack_818,&fStack_600,param_3 + 1);
          _ClipSkyPolygon(iStack_814,&fStack_300,param_3 + 1);
          return;
        }
      } while( true );
    }
  }
  _ClipSkyPolygon(param_1,param_2,param_3 + 1);
  return;
}



// ===========================================
// Function: _ClearSkyBox @ 0000ad76
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ClearSkyBox(void)

{
  DAT_000023e8 = ___real_461c3c00;
  _sky_mins = ___real_461c3c00;
  DAT_00002418 = ___real_c61c3c00;
  _sky_maxs = ___real_c61c3c00;
  DAT_0000241c = ___real_c61c3c00;
  DAT_00002404 = ___real_c61c3c00;
  _DAT_00002420 = ___real_c61c3c00;
  _DAT_00002408 = ___real_c61c3c00;
  _DAT_00002424 = ___real_c61c3c00;
  _DAT_0000240c = ___real_c61c3c00;
  _DAT_00002428 = ___real_c61c3c00;
  _DAT_00002410 = ___real_c61c3c00;
  _DAT_0000242c = ___real_c61c3c00;
  _DAT_00002414 = ___real_c61c3c00;
  DAT_000023ec = ___real_461c3c00;
  DAT_000023d4 = ___real_461c3c00;
  _DAT_000023f0 = ___real_461c3c00;
  _DAT_000023d8 = ___real_461c3c00;
  _DAT_000023f4 = ___real_461c3c00;
  _DAT_000023dc = ___real_461c3c00;
  _DAT_000023f8 = ___real_461c3c00;
  _DAT_000023e0 = ___real_461c3c00;
  _DAT_000023fc = ___real_461c3c00;
  _DAT_000023e4 = ___real_461c3c00;
  return;
}



// ===========================================
// Function: _RB_ClipSkyPolygons @ 0000ae13
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_ClipSkyPolygons(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  _ClearSkyBox();
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x317050)) {
    piVar3 = (int *)(param_1 + 8);
    do {
      iVar1 = piVar3[-2] * 0x10 + param_1;
      local_3c = *(float *)((piVar3[-2] + 45000) * 0x10 + param_1) - _DAT_0000d340;
      local_38 = *(float *)(iVar1 + 0xafc84) - _DAT_0000d344;
      local_34 = *(float *)(iVar1 + 0xafc88) - _DAT_0000d348;
      iVar1 = piVar3[-1] * 0x10 + param_1;
      local_30 = *(float *)((piVar3[-1] + 45000) * 0x10 + param_1) - _DAT_0000d340;
      local_2c = *(float *)(iVar1 + 0xafc84) - _DAT_0000d344;
      local_28 = *(float *)(iVar1 + 0xafc88) - _DAT_0000d348;
      iVar1 = *piVar3 * 0x10 + param_1;
      local_24 = *(float *)((*piVar3 + 45000) * 0x10 + param_1) - _DAT_0000d340;
      local_20 = *(float *)(iVar1 + 0xafc84) - _DAT_0000d344;
      local_1c = *(float *)(iVar1 + 0xafc88) - _DAT_0000d348;
      _ClipSkyPolygon(3,&local_3c,0);
      iVar2 = iVar2 + 3;
      piVar3 = piVar3 + 3;
    } while (iVar2 < *(int *)(param_1 + 0x317050));
  }
  return;
}



// ===========================================
// Function: _MakeSkyVec @ 0000af0e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _MakeSkyVec(undefined4 param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  int iVar2;
  int in_EAX;
  float *unaff_ESI;
  float local_10 [4];
  
  local_10[0] = _DAT_0000d53c / (float)___real_3ffc000000000000;
  iVar2 = *(int *)(&`MakeSkyVec'::__l2::st_to_vec + in_EAX * 0xc);
  local_10[1] = param_3 * local_10[0];
  local_10[2] = param_4 * local_10[0];
  local_10[3] = local_10[0];
  if (iVar2 < 0) {
    fVar1 = -*(float *)((int)local_10 + (4 - (iVar2 * 4 + 4)));
  }
  else {
    fVar1 = local_10[iVar2];
  }
  *param_2 = fVar1;
  iVar2 = *(int *)(&DAT_00003694 + in_EAX * 0xc);
  if (iVar2 < 0) {
    fVar1 = -*(float *)((int)local_10 + (4 - (iVar2 * 4 + 4)));
  }
  else {
    fVar1 = local_10[iVar2];
  }
  param_2[1] = fVar1;
  iVar2 = *(int *)(&DAT_00003698 + in_EAX * 0xc);
  if (iVar2 < 0) {
    fVar1 = -*(float *)((int)local_10 + (4 - (iVar2 * 4 + 4)));
  }
  else {
    fVar1 = local_10[iVar2];
  }
  param_2[2] = fVar1;
  param_3 = (param_3 + 1.0) * (float)___real_3fe0000000000000;
  param_4 = (param_4 + 1.0) * (float)___real_3fe0000000000000;
  if (__sky_min <= param_3) {
    if (__sky_max < param_3 != (NAN(__sky_max) || NAN(param_3))) {
      param_3 = __sky_max;
    }
  }
  else {
    param_3 = __sky_min;
  }
  if (param_4 < __sky_min == (NAN(param_4) || NAN(__sky_min))) {
    if (__sky_max < param_4) {
      param_4 = __sky_max;
    }
  }
  else {
    param_4 = __sky_min;
  }
  if (unaff_ESI == (float *)0x0) {
    return;
  }
  *unaff_ESI = param_3;
  unaff_ESI[1] = 1.0 - param_4;
  return;
}



// ===========================================
// Function: _DrawSkySide @ 0000b054
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawSkySide(int param_1,int *param_2)

{
  undefined *puVar1;
  int unaff_EBP;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *unaff_retaddr;
  
  _GL_Bind();
  iVar3 = *(int *)(param_1 + 4) + 4;
  if (iVar3 < param_2[1] + 4) {
    do {
      (*__qglBegin)(5);
      iVar2 = *unaff_retaddr + 4;
      if (iVar2 <= *param_2 + 4) {
        puVar1 = &DAT_0000206c + (param_1 + iVar2) * 0xc;
        puVar4 = &DAT_000033a8 + (param_1 + iVar2) * 8;
        do {
          (*__qglTexCoord2fv)(puVar4 + -0x48);
          (*__qglVertex3fv)(puVar1 + -0x6c);
          (*__qglTexCoord2fv)(puVar4);
          (*__qglVertex3fv)(puVar1);
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 8;
          puVar1 = puVar1 + 0xc;
          iVar3 = unaff_EBP;
        } while (iVar2 <= *param_2 + 4);
      }
      (*__qglEnd)();
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2[1] + 4);
  }
  return;
}



// ===========================================
// Function: _DrawSkyBox @ 0000b11f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawSkyBox(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  int in_stack_0000001c;
  int in_stack_00000024;
  int in_stack_00000028;
  int local_18;
  int iStack_14;
  int iStack_4;
  
  _memset(&_s_skyTexCoords,0,0x288);
  local_18 = 0;
  do {
    dVar8 = _floor((double)((float)(&_sky_mins)[local_18] * (float)___real_4010000000000000));
    (&_sky_mins)[local_18] = (float)((float10)dVar8 * (float10)___real_3fd0000000000000);
    dVar8 = _floor((double)((float)(&DAT_000023e8)[local_18] * (float)___real_4010000000000000));
    (&DAT_000023e8)[local_18] = (float)((float10)dVar8 * (float10)___real_3fd0000000000000);
    dVar8 = _ceil((double)((float)(&_sky_maxs)[local_18] * (float)___real_4010000000000000));
    (&_sky_maxs)[local_18] = (float)((float10)dVar8 * (float10)___real_3fd0000000000000);
    dVar8 = _ceil((double)((float)(&DAT_00002418)[local_18] * (float)___real_4010000000000000));
    param_3 = (float)((float10)dVar8 * (float10)___real_3fd0000000000000);
    (&DAT_00002418)[local_18] = param_3;
    if (((float)(&_sky_maxs)[local_18] < (float)(&_sky_mins)[local_18] ==
         ((float)(&_sky_maxs)[local_18] == (float)(&_sky_mins)[local_18])) &&
       ((float)(&DAT_000023e8)[local_18] < param_3)) {
      iVar3 = __ftol2_sse();
      in_stack_00000024 = iVar3;
      iVar4 = __ftol2_sse();
      in_stack_00000028 = iVar4;
      iVar5 = __ftol2_sse();
      in_stack_0000001c = iVar5;
      iVar6 = __ftol2_sse();
      if (iVar3 < -4) {
        iVar3 = -4;
        param_1 = iVar3;
      }
      else if (4 < iVar3) {
        iVar3 = 4;
        param_1 = iVar3;
      }
      if (iVar4 < -4) {
        iVar4 = -4;
        param_2 = iVar4;
      }
      else if (4 < iVar4) {
        iVar4 = 4;
        param_2 = iVar4;
      }
      if (iVar5 < -4) {
        iVar5 = -4;
        iStack_4 = iVar5;
      }
      else if (4 < iVar5) {
        iVar5 = 4;
        iStack_4 = iVar5;
      }
      if (iVar6 < -4) {
        iVar6 = -4;
      }
      else if (4 < iVar6) {
        iVar6 = 4;
      }
      if (iVar4 + 4 <= iVar6 + 4) {
        iStack_14 = ((iVar6 + 4) - (iVar4 + 4)) + 1;
        do {
          if (iVar3 + 4 <= iVar5 + 4) {
            fVar2 = (float)iVar4;
            fVar1 = (float)___real_3fd0000000000000;
            iVar7 = ((iVar5 + 4) - (iVar3 + 4)) + 1;
            iVar6 = iVar3;
            do {
              _MakeSkyVec((float)iVar6 * (float)___real_3fd0000000000000,fVar2 * fVar1);
              iVar6 = iVar6 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          iVar4 = iVar4 + 1;
          iStack_14 = iStack_14 + -1;
        } while (iStack_14 != 0);
      }
      _DrawSkySide(&param_1,&iStack_4);
    }
    local_18 = local_18 + 1;
  } while (local_18 < 6);
  return;
}



// ===========================================
// Function: _FillCloudySkySide @ 0000b3c4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _FillCloudySkySide(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int local_14;
  
  iVar8 = _DAT_003241fc;
  iVar1 = *param_2;
  iVar4 = iVar1 - *param_1;
  iVar5 = param_2[1] - param_1[1];
  iVar2 = param_1[1] + 4;
  if (iVar2 <= param_2[1] + 4) {
    local_14 = iVar2 * 9;
    do {
      iVar7 = *param_1 + 4;
      if (iVar7 <= iVar1 + 4) {
        puVar3 = (undefined4 *)(&DAT_00003364 + (local_14 + iVar7) * 8);
        pfVar6 = (float *)(&DAT_00002004 + (local_14 + iVar7) * 0xc);
        do {
          *(float *)(_DAT_003241fc * 0x10 + 0xbce28) = pfVar6[-1] + _DAT_0000d340;
          *(float *)(_DAT_003241fc * 0x10 + 0xbce2c) = *pfVar6 + _DAT_0000d344;
          *(float *)(_DAT_003241fc * 0x10 + 0xbce30) = pfVar6[1] + _DAT_0000d348;
          *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a7428) = puVar3[-1];
          *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a742c) = *puVar3;
          _DAT_003241fc = _DAT_003241fc + 1;
          if (29999 < _DAT_003241fc) {
            (*_DAT_0000d154)(1,s_SHADER_MAX_VERTEXES_hit_in_FillC);
          }
          iVar1 = *param_2;
          iVar7 = iVar7 + 1;
          pfVar6 = pfVar6 + 3;
          puVar3 = puVar3 + 2;
        } while (iVar7 <= iVar1 + 4);
      }
      local_14 = local_14 + 9;
      iVar2 = iVar2 + 1;
    } while (iVar2 <= param_2[1] + 4);
  }
  if ((param_3 != 0) && (0 < iVar5)) {
    iVar8 = iVar8 + 1;
    param_1 = (int *)iVar5;
    do {
      iVar1 = iVar8;
      iVar2 = iVar4;
      if (0 < iVar4) {
        do {
          *(int *)(&_tess + _DAT_003241f8 * 4) = iVar1 + -1;
          _DAT_003241f8 = _DAT_003241f8 + 1;
          iVar5 = iVar1 + -1 + iVar4 + 1;
          *(int *)(&_tess + _DAT_003241f8 * 4) = iVar5;
          _DAT_003241f8 = _DAT_003241f8 + 1;
          *(int *)(&_tess + _DAT_003241f8 * 4) = iVar1;
          _DAT_003241f8 = _DAT_003241f8 + 1;
          *(int *)(&_tess + _DAT_003241f8 * 4) = iVar5;
          _DAT_003241f8 = _DAT_003241f8 + 1;
          *(int *)(&_tess + _DAT_003241f8 * 4) = iVar5 + 1;
          _DAT_003241f8 = _DAT_003241f8 + 1;
          *(int *)(&_tess + _DAT_003241f8 * 4) = iVar1;
          _DAT_003241f8 = _DAT_003241f8 + 1;
          iVar2 = iVar2 + -1;
          iVar1 = iVar1 + 1;
        } while (iVar2 != 0);
      }
      iVar8 = iVar8 + iVar4 + 1;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  return;
}



// ===========================================
// Function: _FillCloudBox @ 0000b5f2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _FillCloudBox(void)

{
  int iVar1;
  float10 fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  double dVar10;
  int iStack00000010;
  int iStack00000018;
  int iStack0000001c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar7 = 0;
  do {
    if (iVar7 != 5) {
      dVar10 = _floor((double)((float)(&_sky_mins)[iVar7] * (float)___real_4010000000000000));
      (&_sky_mins)[iVar7] = (float)((float10)dVar10 * (float10)___real_3fd0000000000000);
      dVar10 = _floor((double)((float)(&DAT_000023e8)[iVar7] * (float)___real_4010000000000000));
      (&DAT_000023e8)[iVar7] = (float)((float10)dVar10 * (float10)___real_3fd0000000000000);
      dVar10 = _ceil((double)((float)(&_sky_maxs)[iVar7] * (float)___real_4010000000000000));
      (&_sky_maxs)[iVar7] = (float)((float10)dVar10 * (float10)___real_3fd0000000000000);
      dVar10 = _ceil((double)((float)(&DAT_00002418)[iVar7] * (float)___real_4010000000000000));
      fVar2 = (float10)___real_3fd0000000000000;
      (&DAT_00002418)[iVar7] = (float)((float10)dVar10 * fVar2);
      if (((float)(&_sky_maxs)[iVar7] < (float)(&_sky_mins)[iVar7] ==
           ((float)(&_sky_maxs)[iVar7] == (float)(&_sky_mins)[iVar7])) &&
         ((float)(&DAT_000023e8)[iVar7] < (float)((float10)dVar10 * fVar2))) {
        iStack00000018 = myftol((float)(&_sky_mins)[iVar7] * (float)___real_4010000000000000);
        iStack0000001c = myftol((float)(&DAT_000023e8)[iVar7] * (float)___real_4010000000000000);
        iStack00000010 = myftol((float)(&_sky_maxs)[iVar7] * (float)___real_4010000000000000);
        iVar4 = myftol((float)(&DAT_00002418)[iVar7] * (float)___real_4010000000000000);
        if (iStack00000018 < -4) {
          iStack00000018 = -4;
        }
        else if (4 < iStack00000018) {
          iStack00000018 = 4;
        }
        if (___real_c0800000 <= (float)iStack0000001c) {
          if (4 < iStack0000001c) {
            iStack0000001c = 4;
          }
        }
        else {
          iStack0000001c = -4;
        }
        if (iStack00000010 < -4) {
          iStack00000010 = -4;
        }
        else if (4 < iStack00000010) {
          iStack00000010 = 4;
        }
        if ((float)iVar4 < ___real_c0800000 == (NAN((float)iVar4) || NAN(___real_c0800000))) {
          if (4 < iVar4) {
            iVar4 = 4;
          }
        }
        else {
          iVar4 = -4;
        }
        iVar5 = iStack0000001c + 4;
        if (iVar5 <= iVar4 + 4) {
          iVar1 = iStack00000018 + 4;
          local_14 = iVar5 * 9;
          local_18 = iStack0000001c;
          do {
            if (iVar1 <= iStack00000010 + 4) {
              fVar3 = (float)___real_3fd0000000000000;
              puVar8 = (undefined4 *)(&DAT_00003364 + (local_14 + iVar1) * 8);
              puVar6 = &DAT_00002434 + (iVar1 + (iVar5 + local_c) * 9) * 2;
              iVar9 = ((iStack00000010 + 4) - iVar1) + 1;
              local_1c = iStack00000018;
              do {
                _MakeSkyVec((float)local_1c * (float)___real_3fd0000000000000,
                            (float)local_18 * fVar3);
                local_1c = local_1c + 1;
                puVar8[-1] = puVar6[-1];
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 2;
                puVar8 = puVar8 + 2;
                iVar9 = iVar9 + -1;
                iVar7 = local_10;
              } while (iVar9 != 0);
            }
            local_18 = local_18 + 1;
            local_14 = local_14 + 9;
            iVar5 = iVar5 + 1;
          } while (iVar5 <= iVar4 + 4);
        }
        _FillCloudySkySide();
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  return;
}



// ===========================================
// Function: _R_BuildCloudData @ 0000b912
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_BuildCloudData(int param_1)

{
  float fVar1;
  int iVar2;
  
  __sky_min = ___real_3b800000;
  _DAT_003241f8 = 0;
  _DAT_003241fc = 0;
  __sky_max = ___real_3f7f0000;
  fVar1 = *(float *)(*(int *)(param_1 + 0x317040) + 0x68);
  if (NAN(fVar1) == (fVar1 == 0.0)) {
    iVar2 = 0;
    do {
      if (*(int *)(_DAT_00324208 + iVar2 * 4) == 0) {
        return;
      }
      _FillCloudBox(iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
  }
  return;
}



// ===========================================
// Function: _R_InitSkyTexCoords @ 0000b97f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_InitSkyTexCoords(void)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float10 fVar4;
  float10 fVar5;
  int local_4c;
  float local_20;
  float local_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  
  _DAT_0000d53c = ___real_44800000;
  pfVar3 = (float *)&DAT_00002434;
  do {
    local_4c = 0;
    do {
      iVar2 = 0;
      fVar1 = (float)___real_3fd0000000000000;
      do {
        _MakeSkyVec((float)(iVar2 + -4) * (float)___real_3fd0000000000000,
                    (float)(local_4c + -4) * fVar1);
        fVar4 = (float10)__CIsqrt();
        fVar5 = (float10)___real_4000000000000000;
        fVar4 = (float10)(float)((fVar4 * fVar5 -
                                 (float10)local_18 * fVar5 * (float10)___real_40b0000000000000) *
                                ((float10)1 /
                                (((float10)(local_1c * local_1c) + (float10)(local_20 * local_20) +
                                 (float10)(local_18 * local_18)) * fVar5)));
        fStack_14 = (float)(fVar4 * (float10)local_20);
        fStack_10 = (float)((float10)local_1c * fVar4);
        fStack_c = (float)((float10)___real_40b0000000000000 +
                          (float10)(float)(fVar4 * (float10)local_18));
        _VectorNormalize(&fStack_14);
        fVar4 = (float10)__CIacos();
        pfVar3[-1] = (float)fVar4;
        fVar4 = (float10)__CIacos();
        *pfVar3 = (float)fVar4;
        iVar2 = iVar2 + 1;
        pfVar3 = pfVar3 + 2;
      } while (iVar2 < 9);
      local_4c = local_4c + 1;
    } while (local_4c < 9);
  } while ((int)pfVar3 < 0x3364);
  return;
}



// ===========================================
// Function: _RB_DrawSun @ 0000bb39
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_DrawSun(void)

{
  float fVar1;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  if ((_DAT_0000d674 != 0) && (*(int *)(__r_drawSun + 0x20) != 0)) {
    (*__qglLoadMatrixf)(0xd3f8);
    (*__qglTranslatef)(_DAT_0000d340,_DAT_0000d344,_DAT_0000d348);
    fStack_14 = _DAT_0000d53c / (float)___real_3ffc000000000000;
    fVar1 = (float)___real_3fd999999999999a * fStack_14;
    fStack_1c = _DAT_0000deec * fStack_14;
    fStack_18 = _DAT_0000def0 * fStack_14;
    fStack_14 = fStack_14 * _DAT_0000def4;
    _PerpendicularVector(&fStack_34,&DAT_0000deec);
    _CrossProduct();
    fStack_34 = fVar1 * fStack_34;
    fStack_30 = fStack_30 * fVar1;
    fStack_2c = fStack_2c * fVar1;
    fStack_28 = fStack_28 * fVar1;
    fStack_24 = fStack_24 * fVar1;
    fStack_20 = fVar1 * fStack_20;
    (*__qglDepthRange)();
    _RB_BeginSurface(_DAT_0000d24c,_DAT_003241ec);
    *(float *)(_DAT_003241fc * 0x10 + 0xbce28) = (fStack_2c - fVar1) - fStack_38;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce2c) = (fStack_28 - fStack_40) - fStack_34;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce30) = (fStack_24 - fStack_3c) - fStack_30;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a7428) = 0;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a742c) = 0;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c728) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c729) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c72a) = 0xff;
    _DAT_003241fc = _DAT_003241fc + 1;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce28) = (fVar1 + fStack_2c) - fStack_38;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce2c) = (fStack_40 + fStack_28) - fStack_34;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce30) = (fStack_3c + fStack_24) - fStack_30;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a7428) = 0;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a742c) = 0x3f800000;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c728) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c729) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c72a) = 0xff;
    _DAT_003241fc = _DAT_003241fc + 1;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce28) = fVar1 + fStack_2c + fStack_38;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce2c) = fStack_40 + fStack_28 + fStack_34;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce30) = fStack_3c + fStack_24 + fStack_30;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a7428) = 0x3f800000;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a742c) = 0x3f800000;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c728) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c729) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c72a) = 0xff;
    _DAT_003241fc = _DAT_003241fc + 1;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce28) = (fStack_2c - fVar1) + fStack_38;
    *(float *)(_DAT_003241fc * 0x10 + 0xbce2c) = fStack_34 + (fStack_28 - fStack_40);
    *(float *)(_DAT_003241fc * 0x10 + 0xbce30) = (fStack_24 - fStack_3c) + fStack_30;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a7428) = 0x3f800000;
    *(undefined4 *)(_DAT_003241fc * 0x10 + 0x1a742c) = 0;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c728) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c729) = 0xff;
    *(undefined1 *)(_DAT_003241fc * 4 + 0x21c72a) = 0xff;
    _DAT_003241fc = _DAT_003241fc + 1;
    *(undefined4 *)(&_tess + _DAT_003241f8 * 4) = 0;
    _DAT_003241f8 = _DAT_003241f8 + 1;
    *(undefined4 *)(&_tess + _DAT_003241f8 * 4) = 1;
    _DAT_003241f8 = _DAT_003241f8 + 1;
    *(undefined4 *)(&_tess + _DAT_003241f8 * 4) = 2;
    _DAT_003241f8 = _DAT_003241f8 + 1;
    *(undefined4 *)(&_tess + _DAT_003241f8 * 4) = 0;
    _DAT_003241f8 = _DAT_003241f8 + 1;
    *(undefined4 *)(&_tess + _DAT_003241f8 * 4) = 2;
    _DAT_003241f8 = _DAT_003241f8 + 1;
    *(undefined4 *)(&_tess + _DAT_003241f8 * 4) = 3;
    _DAT_003241f8 = _DAT_003241f8 + 1;
    _DAT_00324214 = 1;
    _RB_EndSurface();
    (*__qglDepthRange)(0,0x3ff0000000000000);
  }
  return;
}



// ===========================================
// Function: _RB_StageIteratorSky @ 0000c05a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StageIteratorSky(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(__r_fastsky + 0x20) == 0) {
    _RB_ClipSkyPolygons();
    uVar2 = 0;
    if (*(int *)(__r_showsky + 0x20) == 0) {
      uVar2 = 0x3ff0000000000000;
    }
    (*__qglDepthRange)(uVar2,uVar2);
    if ((*(code **)(_DAT_003241e8 + 0x6c) != (code *)0x0) &&
       (*(code **)(_DAT_003241e8 + 0x6c) != __qglPopMatrix)) {
      uVar2 = CONCAT44(_DAT_0000dbb4,_DAT_0000dbb4);
      uVar1 = _DAT_0000dbb4;
      (*__qglColor3f)();
      (*__qglPushMatrix)();
      _GL_State(0,uVar1,uVar2);
      (*__qglTranslatef)(_DAT_0000d340,_DAT_0000d344,_DAT_0000d348);
      _DrawSkyBox(_DAT_003241e8);
      (*__qglPopMatrix)();
    }
    _R_BuildCloudData();
    _RB_StageIteratorGeneric();
    (*__qglDepthRange)(0,0x3ff0000000000000);
    _DAT_0000d674 = 1;
  }
  return;
}



