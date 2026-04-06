// ===========================================
// Function: _Draw_SetColor @ 00016c00
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Draw_SetColor(float *param_1)

{
  float fVar1;
  undefined1 local_4;
  
  if (param_1 == (float *)0x0) {
    param_1 = (float *)&_r_colorWhite;
  }
  fVar1 = (float)_DAT_00019970;
  local_4 = (undefined1)(int)ROUND(fVar1 * *param_1);
  DAT_00019758 = local_4;
  local_4 = (undefined1)(int)ROUND(param_1[1] * fVar1);
  DAT_00019759 = local_4;
  local_4 = (undefined1)(int)ROUND(fVar1 * param_1[2]);
  DAT_0001975a = local_4;
  local_4 = (undefined1)(int)ROUND(param_1[3] * (float)___real_406fe00000000000);
  DAT_0001975b = local_4;
  (*__qglColor4ubv)(&DAT_00019758);
  return;
}



// ===========================================
// Function: _Draw_StretchPic @ 00016cde
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Draw_StretchPic(float param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                     undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  int iVar2;
  
  _R_SyncRenderThread();
  iVar2 = _DAT_00018ff4;
  if (param_9 != 0) {
    iVar2 = _R_GetShaderByHandle(param_9);
  }
  if (param_3 <= 0.0) {
    iVar1 = *(int *)(*(int *)(iVar2 + 0x194) + 8);
    param_3 = (float)*(int *)(iVar1 + 0x40);
    param_4 = (float)*(int *)(iVar1 + 0x44);
  }
  _RB_Color4f((float)DAT_00019758,(float)DAT_00019759,(float)DAT_0001975a,(float)DAT_0001975b);
  _RB_BeginSurface(iVar2,0);
  _RB_Texcoord2f(param_5,param_6);
  _RB_Vertex3f(param_1,param_2,0);
  _RB_Texcoord2f(param_7,param_6);
  _RB_Vertex3f(param_1 + param_3,param_2,0);
  _RB_Texcoord2f(param_5,param_8);
  _RB_Vertex3f(param_1,param_2 + param_4,0);
  _RB_Texcoord2f(param_7,param_8);
  _RB_Vertex3f(param_1 + param_3,param_2 + param_4,0);
  _RB_StreamEnd();
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _Draw_TilePic @ 00016e68
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Draw_TilePic(float param_1,float param_2,float param_3,float param_4,int param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  _R_SyncRenderThread();
  iVar6 = _DAT_00018ff4;
  if (param_5 != 0) {
    iVar6 = _R_GetShaderByHandle(param_5);
  }
  if (param_3 <= 0.0) {
    iVar1 = *(int *)(*(int *)(iVar6 + 0x194) + 8);
    param_3 = (float)*(int *)(iVar1 + 0x40);
    param_4 = (float)*(int *)(iVar1 + 0x44);
  }
  iVar1 = *(int *)(*(int *)(iVar6 + 0x194) + 8);
  fVar2 = (float)*(int *)(iVar1 + 0x48);
  fVar3 = (float)*(int *)(iVar1 + 0x4c);
  _RB_Color4f((float)DAT_00019758,(float)DAT_00019759,(float)DAT_0001975a,(float)DAT_0001975b);
  _RB_StreamBegin(iVar6,0);
  fVar4 = param_2 / fVar3;
  fVar5 = param_1 / fVar2;
  _RB_Texcoord2f(fVar5,fVar4);
  _RB_Vertex2f(param_1,param_2);
  param_3 = param_1 + param_3;
  fVar2 = param_3 / fVar2;
  _RB_Texcoord2f(fVar2,fVar4);
  _RB_Vertex2f(param_3,param_2);
  param_2 = param_2 + param_4;
  fVar3 = param_2 / fVar3;
  _RB_Texcoord2f(fVar5,fVar3);
  _RB_Vertex2f(param_1,param_2);
  _RB_Texcoord2f(fVar2,fVar3);
  _RB_Vertex2f(param_3,param_2);
  _RB_StreamEnd();
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _Draw_TilePicOffset @ 00017026
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Draw_TilePicOffset(float param_1,float param_2,float param_3,float param_4,int param_5,
                        int param_6,int param_7)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  
  _R_SyncRenderThread();
  iVar8 = _DAT_00018ff4;
  if (param_5 != 0) {
    iVar8 = _R_GetShaderByHandle(param_5);
  }
  if (param_3 <= 0.0) {
    iVar1 = *(int *)(*(int *)(iVar8 + 0x194) + 8);
    param_3 = (float)*(int *)(iVar1 + 0x40);
    param_4 = (float)*(int *)(iVar1 + 0x44);
  }
  iVar1 = *(int *)(*(int *)(iVar8 + 0x194) + 8);
  fVar2 = (float)*(int *)(iVar1 + 0x48);
  fVar3 = (float)*(int *)(iVar1 + 0x4c);
  _RB_Color4f((float)DAT_00019758,(float)DAT_00019759,(float)DAT_0001975a,(float)DAT_0001975b);
  _RB_StreamBegin(iVar8,0);
  fVar4 = param_2 / fVar3;
  fVar5 = param_1 / fVar2;
  _RB_Texcoord2f(fVar5,fVar4);
  fVar6 = (float)param_7 + param_2;
  fVar7 = (float)param_6 + param_1;
  _RB_Vertex2f(fVar7,fVar6);
  fVar2 = (param_1 + param_3) / fVar2;
  _RB_Texcoord2f(fVar2,fVar4);
  _RB_Vertex2f(param_3 + fVar7,fVar6);
  fVar3 = (param_2 + param_4) / fVar3;
  _RB_Texcoord2f(fVar5,fVar3);
  _RB_Vertex2f(fVar7,param_4 + fVar6);
  _RB_Texcoord2f(fVar2,fVar3);
  _RB_Vertex2f(param_3 + fVar7,param_4 + fVar6);
  _RB_StreamEnd();
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _RE_StretchRaw @ 00017204
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_StretchRaw(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  float fVar13;
  char *pcVar14;
  double dVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  
  _R_SyncRenderThread();
  bVar2 = 0;
  uVar1 = 1;
  bVar3 = 0;
  if (1 < in_stack_00000014) {
    do {
      bVar2 = bVar3 + 1;
      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      bVar3 = bVar2;
    } while ((int)uVar1 < in_stack_00000014);
  }
  bVar3 = 0;
  bVar4 = 0;
  uVar1 = 1;
  if (1 < in_stack_00000018) {
    do {
      bVar4 = bVar3 + 1;
      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      bVar3 = bVar4;
    } while ((int)uVar1 < in_stack_00000018);
  }
  if ((1 << (bVar2 & 0x1f) != in_stack_00000014) || (1 << (bVar4 & 0x1f) != in_stack_00000018)) {
    (*_DAT_0001904c)(1,s_Draw_StretchRaw__size_not_a_powe,in_stack_00000014,in_stack_00000018);
  }
  _GL_Bind(_DAT_00018fdc);
  *(int *)(_DAT_00018fdc + 0x48) = in_stack_00000014;
  *(int *)(_DAT_00018fdc + 0x40) = in_stack_00000014;
  iVar20 = 0x1401;
  iVar19 = 0x1908;
  uVar18 = 0;
  uVar17 = 3;
  *(int *)(_DAT_00018fdc + 0x4c) = in_stack_00000018;
  iVar16 = 0;
  *(int *)(_DAT_00018fdc + 0x44) = in_stack_00000018;
  uVar11 = 0xde1;
  (*__qglTexImage2D)();
  pcVar14 = s_PARSE_SECURITY_URL_000027fb + 6;
  (*__qglTexParameterf)
            (0xde1,s_PARSE_SECURITY_URL_000027fb + 6,___real_46180400,uVar11,iVar16,uVar17,
             in_stack_00000014,in_stack_00000018,uVar18,iVar19,iVar20,in_stack_0000001c);
  uVar11 = 0xde1;
  (*__qglTexParameterf)(0xde1,s_PARSE_SECURITY_URL_000027fb + 5,___real_46180400);
  iVar10 = 7;
  (*__qglBegin)(7);
  dVar15 = (double)iVar20;
  fVar9 = (float)___real_3fe0000000000000 / (float)iVar20;
  dVar12 = (double)iVar19;
  fVar7 = (float)___real_3fe0000000000000 / (float)iVar19;
  fVar13 = fVar7;
  (*__qglTexCoord2f)(fVar7,fVar9,iVar10,uVar11,dVar12,fVar7,pcVar14,dVar15);
  iVar20 = (int)((ulonglong)dVar15 >> 0x20);
  fVar5 = (float)iVar20;
  iVar19 = SUB84(dVar12,0);
  (*__qglVertex2f)(fVar5,(float)iVar16);
  fVar7 = (float)(((float10)(double)CONCAT44(fVar9,fVar7) - (float10)___real_3fe0000000000000) /
                 (float10)(double)CONCAT44(fVar9,fVar7));
  fVar8 = fVar7;
  (*__qglTexCoord2f)(fVar7,in_stack_00000014);
  fVar6 = (float)(int)(pcVar14 + (int)fVar5);
  (*__qglVertex2f)(fVar6,iVar20);
  fVar5 = (float)(((float10)(double)CONCAT44(fVar9,fVar8) - (float10)___real_3fe0000000000000) /
                 (float10)(double)CONCAT44(fVar9,fVar8));
  (*__qglTexCoord2f)(fVar7,fVar5);
  (*__qglVertex2f)(fVar13,(float)(iVar10 + iVar19));
  (*__qglTexCoord2f)(fVar6,uVar11);
  (*__qglVertex2f)(fVar5,in_stack_00000014);
  (*__qglEnd)();
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _RE_StretchRawBlend @ 0001744b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_StretchRawBlend(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_00000020;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  float fVar13;
  char *pcVar14;
  double dVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  
  _R_SyncRenderThread();
  bVar2 = 0;
  uVar1 = 1;
  bVar3 = 0;
  if (1 < in_stack_00000014) {
    do {
      bVar2 = bVar3 + 1;
      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      bVar3 = bVar2;
    } while ((int)uVar1 < in_stack_00000014);
  }
  bVar3 = 0;
  bVar4 = 0;
  uVar1 = 1;
  if (1 < in_stack_00000018) {
    do {
      bVar4 = bVar3 + 1;
      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      bVar3 = bVar4;
    } while ((int)uVar1 < in_stack_00000018);
  }
  if ((1 << (bVar2 & 0x1f) != in_stack_00000014) || (1 << (bVar4 & 0x1f) != in_stack_00000018)) {
    (*_DAT_0001904c)(1,s_Draw_StretchRaw__size_not_a_powe,in_stack_00000014,in_stack_00000018);
  }
  _GL_Bind(_DAT_00018fdc);
  *(int *)(_DAT_00018fdc + 0x48) = in_stack_00000014;
  *(int *)(_DAT_00018fdc + 0x40) = in_stack_00000014;
  iVar20 = 0x1401;
  iVar19 = 0x1908;
  uVar18 = 0;
  uVar17 = 3;
  *(int *)(_DAT_00018fdc + 0x4c) = in_stack_00000018;
  iVar16 = 0;
  *(int *)(_DAT_00018fdc + 0x44) = in_stack_00000018;
  uVar11 = 0xde1;
  (*__qglTexImage2D)();
  pcVar14 = s_PARSE_SECURITY_URL_000027fb + 6;
  (*__qglTexParameterf)
            (0xde1,s_PARSE_SECURITY_URL_000027fb + 6,___real_46180400,uVar11,iVar16,uVar17,
             in_stack_00000014,in_stack_00000018,uVar18,iVar19,iVar20,in_stack_00000020);
  uVar11 = 0xde1;
  (*__qglTexParameterf)(0xde1,s_PARSE_SECURITY_URL_000027fb + 5,___real_46180400);
  iVar10 = 7;
  (*__qglBegin)(7);
  dVar15 = (double)iVar20;
  fVar9 = (float)___real_3fe0000000000000 / (float)iVar20;
  dVar12 = (double)iVar19;
  fVar7 = (float)___real_3fe0000000000000 / (float)iVar19;
  fVar13 = fVar7;
  (*__qglTexCoord2f)(fVar7,fVar9,iVar10,uVar11,dVar12,fVar7,pcVar14,dVar15);
  iVar20 = (int)((ulonglong)dVar15 >> 0x20);
  fVar5 = (float)iVar20;
  iVar19 = SUB84(dVar12,0);
  (*__qglVertex2f)(fVar5,(float)iVar16);
  fVar7 = (float)(((float10)(double)CONCAT44(fVar9,fVar7) - (float10)___real_3fe0000000000000) /
                 (float10)(double)CONCAT44(fVar9,fVar7));
  fVar8 = fVar7;
  (*__qglTexCoord2f)(fVar7,in_stack_00000014);
  fVar6 = (float)(int)(pcVar14 + (int)fVar5);
  (*__qglVertex2f)(fVar6,iVar20);
  fVar5 = (float)(((float10)(double)CONCAT44(fVar9,fVar8) - (float10)___real_3fe0000000000000) /
                 (float10)(double)CONCAT44(fVar9,fVar8));
  (*__qglTexCoord2f)(fVar7,fVar5);
  (*__qglVertex2f)(fVar13,(float)(iVar10 + iVar19));
  (*__qglTexCoord2f)(fVar6,uVar11);
  (*__qglVertex2f)(fVar5,in_stack_00000014);
  (*__qglEnd)();
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _AddBox @ 00017692
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _AddBox(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 *puVar4;
  
  _R_SyncRenderThread();
  puVar4 = &DAT_00019758;
  (*__qglColor4ubv)(&DAT_00019758);
  fVar3 = 4.97881e-42;
  (*__qglDisable)(0xde1);
  _GL_State(0x422);
  fVar2 = 9.80909e-45;
  (*__qglBegin)(7);
  fVar1 = fVar3;
  (*__qglVertex2f)(fVar3,puVar4);
  fVar1 = (float)puVar4 + fVar1;
  (*__qglVertex2f)(fVar1,fVar2);
  fVar3 = fVar3 + fVar2;
  (*__qglVertex2f)(puVar4,fVar3);
  (*__qglVertex2f)(fVar3,fVar1);
  (*__qglEnd)();
  (*__qglEnable)(0xde1);
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _DrawBox @ 00017750
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawBox(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 *puVar4;
  
  _R_SyncRenderThread();
  puVar4 = &DAT_00019758;
  (*__qglColor4ubv)(&DAT_00019758);
  fVar3 = 4.97881e-42;
  (*__qglDisable)(0xde1);
  _GL_State(0x465);
  fVar2 = 9.80909e-45;
  (*__qglBegin)(7);
  fVar1 = fVar3;
  (*__qglVertex2f)(fVar3,puVar4);
  fVar1 = (float)puVar4 + fVar1;
  (*__qglVertex2f)(fVar1,fVar2);
  fVar3 = fVar3 + fVar2;
  (*__qglVertex2f)(puVar4,fVar3);
  (*__qglVertex2f)(fVar3,fVar1);
  (*__qglEnd)();
  (*__qglEnable)(0xde1);
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _DrawLineLoop @ 0001780e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawLineLoop(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_retaddr;
  
  _R_SyncRenderThread();
  (*__qglDisable)(0xde1);
  if (param_2 != 0) {
    (*__qglEnable)(0xb24);
    (*__qglLineStipple)(param_2,param_2);
  }
  (*__qglBegin)(2);
  iVar2 = 0;
  if (0 < unaff_retaddr) {
    do {
      uVar1 = __ftol2_sse();
      uVar1 = __ftol2_sse(uVar1);
      (*__qglVertex2i)(uVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < unaff_retaddr);
  }
  (*__qglEnd)();
  (*__qglEnable)(0xde1);
  if (param_2 != 0) {
    (*__qglDisable)(0xb24);
  }
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _Set2DWindow @ 000178a5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Set2DWindow(float param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float unaff_EBX;
  float unaff_ESI;
  float unaff_EDI;
  float unaff_retaddr;
  float fVar1;
  
  _R_SyncRenderThread();
  fVar1 = param_4;
  (*__qglViewport)(param_1,param_2,param_3,param_4);
  (*__qglScissor)(unaff_EDI,param_2,param_3,param_4);
  (*__qglMatrixMode)(0x1701);
  (*__qglLoadIdentity)();
  (*__qglOrtho)((double)fVar1,(double)unaff_EDI,(double)unaff_ESI,(double)unaff_EBX,
                (double)unaff_retaddr,(double)param_1);
  (*__qglMatrixMode)(0x1700);
  (*__qglLoadIdentity)();
  _GL_State(0x465);
  (*__qglEnable)(0xbe2);
  (*__qglDisable)(0xb44);
  (*__qglDisable)(0x3000);
  if (_DAT_00019754 == 0) {
    _DAT_00019754 = 1;
  }
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _RE_Scissor @ 00017978
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_Scissor(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_retaddr;
  
  _R_SyncRenderThread();
  (*__qglEnable)(0xc11);
  (*__qglScissor)(unaff_retaddr,param_1,param_2,param_3);
  _GLimp_Suspend();
  return;
}



// ===========================================
// Function: _SetFull2DWindow @ 000179a7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SetFull2DWindow(void)

{
  _Set2DWindow(0,0,_DAT_0001a4d4,_DAT_0001a4d8,0,(float)_DAT_0001a4d4,(float)_DAT_0001a4d8,0,
               ___real_bf800000,0x3f800000);
  return;
}



// ===========================================
// Function: _DrawInitialLoadingScreen @ 000179f1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawInitialLoadingScreen(undefined4 param_1,float param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  byte *pbVar12;
  byte *pbVar13;
  float10 extraout_ST0;
  
  iVar2 = (int)param_2;
  if (`DrawInitialLoadingScreen'::__l2::imageBuffer == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)_malloc(0x10000);
    puVar1 = puVar5 + 0x4000;
    pbVar12 = &_GIMP_IMAGE_rle_pixel_data;
    `DrawInitialLoadingScreen'::__l2::imageBuffer = puVar5;
    while (puVar5 < puVar1) {
      uVar6 = (uint)*pbVar12;
      pbVar13 = pbVar12 + 1;
      if ((char)*pbVar12 < '\0') {
        iVar7 = uVar6 - 0x80;
        do {
          *puVar5 = *(undefined4 *)pbVar13;
          puVar5 = puVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        pbVar12 = pbVar12 + 5;
      }
      else {
        _memcpy(puVar5,pbVar13,uVar6 * 4);
        puVar5 = puVar5 + uVar6;
        pbVar12 = pbVar13 + uVar6 * 4;
      }
    }
  }
  if (`DrawInitialLoadingScreen'::__l2::loadingImageBuffer == (undefined4 *)0x0) {
    `DrawInitialLoadingScreen'::__l2::loadingW = ___real_43800000;
    `DrawInitialLoadingScreen'::__l2::loadingH = ___real_42000000;
    if (__g_eLanguage == 1) {
      puVar5 = (undefined4 *)_malloc(0x8000);
      puVar1 = puVar5 + 0x2000;
      pbVar12 = &_DE_LOADING_rle_pixel_data;
      `DrawInitialLoadingScreen'::__l2::loadingImageBuffer = puVar5;
      while (puVar5 < puVar1) {
        uVar6 = (uint)*pbVar12;
        pbVar13 = pbVar12 + 1;
        if ((char)*pbVar12 < '\0') {
          iVar7 = uVar6 - 0x80;
          do {
            *puVar5 = *(undefined4 *)pbVar13;
            puVar5 = puVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          pbVar12 = pbVar12 + 5;
        }
        else {
          _memcpy(puVar5,pbVar13,uVar6 * 4);
          puVar5 = puVar5 + uVar6;
          pbVar12 = pbVar13 + uVar6 * 4;
        }
      }
    }
    else if (__g_eLanguage == 2) {
      puVar5 = (undefined4 *)_malloc(0x8000);
      puVar1 = puVar5 + 0x2000;
      pbVar12 = &_FR_LOADING_rle_pixel_data;
      `DrawInitialLoadingScreen'::__l2::loadingImageBuffer = puVar5;
      while (puVar5 < puVar1) {
        uVar6 = (uint)*pbVar12;
        pbVar13 = pbVar12 + 1;
        if ((char)*pbVar12 < '\0') {
          iVar7 = uVar6 - 0x80;
          do {
            *puVar5 = *(undefined4 *)pbVar13;
            puVar5 = puVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          pbVar12 = pbVar12 + 5;
        }
        else {
          _memcpy(puVar5,pbVar13,uVar6 * 4);
          puVar5 = puVar5 + uVar6;
          pbVar12 = pbVar13 + uVar6 * 4;
        }
      }
    }
    else if (__g_eLanguage == 3) {
      puVar5 = (undefined4 *)_malloc(0x8000);
      puVar1 = puVar5 + 0x2000;
      pbVar12 = &_ES_LOADING_rle_pixel_data;
      `DrawInitialLoadingScreen'::__l2::loadingImageBuffer = puVar5;
      while (puVar5 < puVar1) {
        uVar6 = (uint)*pbVar12;
        pbVar13 = pbVar12 + 1;
        if ((char)*pbVar12 < '\0') {
          iVar7 = uVar6 - 0x80;
          do {
            *puVar5 = *(undefined4 *)pbVar13;
            puVar5 = puVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          pbVar12 = pbVar12 + 5;
        }
        else {
          _memcpy(puVar5,pbVar13,uVar6 * 4);
          puVar5 = puVar5 + uVar6;
          pbVar12 = pbVar13 + uVar6 * 4;
        }
      }
    }
    else {
      puVar5 = (undefined4 *)_malloc(0x8000);
      puVar1 = puVar5 + 0x2000;
      pbVar12 = &_EN_LOADING_rle_pixel_data;
      `DrawInitialLoadingScreen'::__l2::loadingImageBuffer = puVar5;
      while (puVar5 < puVar1) {
        uVar6 = (uint)*pbVar12;
        pbVar13 = pbVar12 + 1;
        if ((char)*pbVar12 < '\0') {
          iVar7 = uVar6 - 0x80;
          do {
            *puVar5 = *(undefined4 *)pbVar13;
            puVar5 = puVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          pbVar12 = pbVar12 + 5;
        }
        else {
          _memcpy(puVar5,pbVar13,uVar6 * 4);
          puVar5 = puVar5 + uVar6;
          pbVar12 = pbVar13 + uVar6 * 4;
        }
      }
    }
  }
  if ((_DAT_00019970 != 0x7f) && (_DAT_00019970 != 0x3f)) {
    _DAT_00019970 = 0xff;
  }
  iVar7 = 0;
  if ((int)param_2 < 1) {
LAB_00017f66:
    if (param_3 != 0) {
      _free(`DrawInitialLoadingScreen'::__l2::imageBuffer);
      `DrawInitialLoadingScreen'::__l2::imageBuffer = (undefined4 *)0x0;
      _free(`DrawInitialLoadingScreen'::__l2::loadingImageBuffer);
      `DrawInitialLoadingScreen'::__l2::loadingImageBuffer = (undefined4 *)0x0;
    }
    return;
  }
  do {
    _Set2DWindow(0,0,_DAT_0001a4d4,_DAT_0001a4d8,0,(float)_DAT_0001a4d4,(float)_DAT_0001a4d8,0,
                 ___real_bf800000,0x3f800000);
    _Draw_SetColor(&_g_color_table);
    _DrawBox(0,0,___real_44a00000,___real_44700000);
    _Draw_SetColor(0);
    _Set2DWindow(0,0,_DAT_0001a4d4,_DAT_0001a4d8,0,(float)_DAT_0001a4d4,(float)_DAT_0001a4d8,0,
                 ___real_bf800000,0x3f800000);
    iVar8 = _Sys_Milliseconds();
    if (`DrawInitialLoadingScreen'::__l60::prevTime < 0) {
      `DrawInitialLoadingScreen'::__l60::prevTime = _Sys_Milliseconds();
      _fadeValue = (float)param_4;
    }
    param_2 = (float)(iVar8 - `DrawInitialLoadingScreen'::__l60::prevTime);
    if (___real_42040000 < (float)(int)param_2) {
      param_2 = 4.62428e-44;
    }
    param_2 = (float)(int)param_2 * (float)___real_3fc5c28f60000000;
    fVar3 = _fadeValue;
    if (0.0 < param_2) {
      do {
        if (`DrawInitialLoadingScreen'::__l60::isIncreasing == 0) {
          fVar3 = _fadeValue - param_2;
        }
        else {
          fVar3 = _fadeValue + param_2;
        }
        if (fVar3 <= (float)___real_406fe00000000000) {
          if (fVar3 < 0.0 == NAN(fVar3)) break;
          `DrawInitialLoadingScreen'::__l60::isIncreasing = 1;
          fVar4 = 0.0;
          fVar3 = _fadeValue;
        }
        else {
          `DrawInitialLoadingScreen'::__l60::isIncreasing = 0;
          fVar3 = (float)___real_406fe00000000000 - _fadeValue;
          _fadeValue = ___real_437f0000;
          fVar4 = _fadeValue;
        }
        _fadeValue = fVar4;
        param_2 = param_2 - fVar3;
        fVar3 = _fadeValue;
      } while (0.0 < param_2);
    }
    _fadeValue = fVar3;
    `DrawInitialLoadingScreen'::__l60::prevTime = iVar8;
    uVar9 = __ftol2_sse();
    if (param_3 != 0) {
      _fadeValue = (float)extraout_ST0;
      `DrawInitialLoadingScreen'::__l60::prevTime = -1;
      `DrawInitialLoadingScreen'::__l60::isIncreasing = 1;
    }
    uVar10 = __ftol2_sse(0x80,0x80,0x80,0x80,uVar9,`DrawInitialLoadingScreen'::__l2::imageBuffer);
    uVar10 = __ftol2_sse(uVar10);
    _RE_StretchRawBlend(uVar10);
    uVar10 = __ftol2_sse();
    uVar11 = __ftol2_sse();
    uVar9 = __ftol2_sse(uVar11,uVar10,uVar11,uVar10,uVar9,
                        `DrawInitialLoadingScreen'::__l2::loadingImageBuffer);
    uVar9 = __ftol2_sse(uVar9);
    _RE_StretchRawBlend(uVar9);
    (*__qglFinish)();
    _GLimp_EndFrame();
    iVar7 = iVar7 + 1;
    if (iVar2 <= iVar7) goto LAB_00017f66;
    (*___imp__Sleep_4)(0x10);
  } while( true );
}



