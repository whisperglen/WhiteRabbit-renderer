// ===========================================
// Function: _localtime @ 00029b00
// ===========================================

tm * _localtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)__localtime64();
  return ptVar1;
}



// ===========================================
// Function: _time @ 00029b0a
// ===========================================

time_t _time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = __time64();
  return tVar1;
}



// ===========================================
// Function: _FuncToString @ 00029b2d
// ===========================================

char * _FuncToString(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x200:
    return s_GL_NEVER;
  case 0x201:
    return s_GL_LESS;
  case 0x202:
    return s_GL_EQUAL;
  case 0x203:
    return s_GL_LEQUAL;
  case 0x204:
    return s_GL_GREATER;
  case 0x205:
    return s_GL_NOTEQUAL;
  case 0x206:
    return s_GL_GEQUAL;
  case 0x207:
    return s_GL_ALWAYS;
  default:
    return s_____UNKNOWN____;
  }
}



// ===========================================
// Function: _PrimToString @ 00029b95
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * _PrimToString(void)

{
  undefined3 uVar1;
  undefined3 uVar2;
  int in_EAX;
  
  uVar2 = DAT_000020cc_1;
  if (in_EAX == 4) {
    _prim = s_GL_TRIANGLES._0_4_;
    _DAT_000020cc = CONCAT31(DAT_000020cc_1,s_GL_TRIANGLES[0xc]);
    _DAT_000020c4 = s_GL_TRIANGLES._4_4_;
    _DAT_000020c8 = s_GL_TRIANGLES._8_4_;
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 5) {
    _prim = s_GL_TRIANGLE_STRIP._0_4_;
    _DAT_000020c4 = s_GL_TRIANGLE_STRIP._4_4_;
    _DAT_000020c8 = s_GL_TRIANGLE_STRIP._8_4_;
    _DAT_000020cc = s_GL_TRIANGLE_STRIP._12_4_;
    _DAT_000020d0 = s_GL_TRIANGLE_STRIP._16_2_;
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 6) {
    _prim = s_GL_TRIANGLE_FAN._0_4_;
    _DAT_000020cc = s_GL_TRIANGLE_FAN._12_4_;
    _DAT_000020c4 = s_GL_TRIANGLE_FAN._4_4_;
    _DAT_000020c8 = s_GL_TRIANGLE_FAN._8_4_;
    return &`PrimToString'::__l2::prim;
  }
  uVar1 = DAT_000020c8_1;
  if (in_EAX == 7) {
    _DAT_000020c8 = CONCAT31(DAT_000020c8_1,s_GL_QUADS[8]);
    _prim = s_GL_QUADS._0_4_;
    _DAT_000020c4 = s_GL_QUADS._4_4_;
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 8) {
    _prim = s_GL_QUAD_STRIP._0_4_;
    _DAT_000020c8 = s_GL_QUAD_STRIP._8_4_;
    _DAT_000020c4 = s_GL_QUAD_STRIP._4_4_;
    _DAT_000020cc = CONCAT22(DAT_000020cc_1._1_2_,s_GL_QUAD_STRIP._12_2_);
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 9) {
    _prim = s_GL_POLYGON._0_4_;
    _DAT_000020c4 = s_GL_POLYGON._4_4_;
    _DAT_000020c8 = CONCAT12(s_GL_POLYGON[10],s_GL_POLYGON._8_2_);
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 0) {
    _prim = s_GL_POINTS._0_4_;
    _DAT_000020c4 = s_GL_POINTS._4_4_;
    _DAT_000020c8 = CONCAT22(_DAT_000020ca,s_GL_POINTS._8_2_);
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 1) {
    _prim = s_GL_LINES._0_4_;
    _DAT_000020c4 = s_GL_LINES._4_4_;
    _DAT_000020c8 = CONCAT31(uVar1,s_GL_LINES[8]);
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 3) {
    _prim = s_GL_LINE_STRIP._0_4_;
    _DAT_000020cc = CONCAT22(DAT_000020cc_1._1_2_,s_GL_LINE_STRIP._12_2_);
    _DAT_000020c4 = s_GL_LINE_STRIP._4_4_;
    _DAT_000020c8 = s_GL_LINE_STRIP._8_4_;
    return &`PrimToString'::__l2::prim;
  }
  if (in_EAX == 2) {
    _prim = s_GL_LINE_LOOP._0_4_;
    _DAT_000020c8 = s_GL_LINE_LOOP._8_4_;
    _DAT_000020c4 = s_GL_LINE_LOOP._4_4_;
    _DAT_000020cc = CONCAT31(uVar2,s_GL_LINE_LOOP[0xc]);
    return &`PrimToString'::__l2::prim;
  }
  _sprintf(&`PrimToString'::__l2::prim,s_0x_x);
  return &`PrimToString'::__l2::prim;
}



// ===========================================
// Function: _CapToString @ 00029dd3
// ===========================================

char * _CapToString(void)

{
  undefined *in_EAX;
  
  if (in_EAX < (undefined *)0xde2) {
    if (in_EAX == (undefined *)0xde1) {
      return s_GL_TEXTURE_2D;
    }
    switch(in_EAX) {
    case (undefined *)0xb44:
      return s_GL_CULL_FACE;
    case (undefined *)0xb71:
      return s_GL_DEPTH_TEST;
    case (undefined *)0xb90:
      return s_GL_STENCIL_TEST;
    case (undefined *)0xbc0:
      return s_GL_ALPHA_TEST;
    case (undefined *)0xbe2:
      return s_GL_BLEND;
    }
  }
  else if (&DAT_00008076 < in_EAX) {
    if (in_EAX == &DAT_00008078) {
      return s_GL_TEXTURE_COORD_ARRAY;
    }
  }
  else {
    if (in_EAX == &DAT_00008076) {
      return s_GL_COLOR_ARRAY;
    }
    if (in_EAX == (undefined *)0x3000) {
      return s_GL_CLIP_PLANE0;
    }
    if (in_EAX == &DAT_00008074) {
      return s_GL_VERTEX_ARRAY;
    }
  }
  _sprintf(&`CapToString'::__l2::buffer,s_0x_x);
  return &`CapToString'::__l2::buffer;
}



// ===========================================
// Function: _TypeToString @ 00029f22
// ===========================================

char * _TypeToString(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x1400:
    return s_GL_BYTE;
  case 0x1401:
    return s_GL_UNSIGNED_BYTE;
  case 0x1402:
    return s_GL_SHORT;
  case 0x1403:
    return s_GL_UNSIGNED_SHORT;
  case 0x1404:
    return s_GL_INT;
  case 0x1405:
    return s_GL_UNSIGNED_INT;
  case 0x1406:
    return s_GL_FLOAT;
  default:
    return s_____UNKNOWN____;
  case 0x140a:
    return s_GL_DOUBLE;
  }
}



// ===========================================
// Function: _BlendToName @ 0002a0ca
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _BlendToName(char *param_1)

{
  uint in_EAX;
  int iVar1;
  char *pcVar2;
  
  if (in_EAX < 0x303) {
    if (in_EAX == 0x302) {
      *(undefined4 *)param_1 = s_GL_SRC_ALPHA._0_4_;
      *(undefined4 *)(param_1 + 4) = s_GL_SRC_ALPHA._4_4_;
      *(undefined4 *)(param_1 + 8) = s_GL_SRC_ALPHA._8_4_;
      param_1[0xc] = s_GL_SRC_ALPHA[0xc];
      return;
    }
    if (in_EAX == 0) {
      *(undefined4 *)param_1 = _s_GL_ZERO;
      *(undefined4 *)(param_1 + 4) = DAT_000273d6;
      return;
    }
    if (in_EAX == 1) {
      *(undefined4 *)param_1 = s_GL_ONE._0_4_;
      *(undefined2 *)(param_1 + 4) = s_GL_ONE._4_2_;
      param_1[6] = s_GL_ONE[6];
      return;
    }
  }
  else {
    switch(in_EAX) {
    case 0x303:
      pcVar2 = s_GL_ONE_MINUS_SRC_ALPHA;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)param_1 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        param_1 = param_1 + 4;
      }
      *(undefined2 *)param_1 = *(undefined2 *)pcVar2;
      param_1[2] = pcVar2[2];
      return;
    case 0x304:
      *(undefined4 *)param_1 = s_GL_DST_ALPHA._0_4_;
      *(undefined4 *)(param_1 + 4) = s_GL_DST_ALPHA._4_4_;
      *(undefined4 *)(param_1 + 8) = s_GL_DST_ALPHA._8_4_;
      param_1[0xc] = s_GL_DST_ALPHA[0xc];
      return;
    case 0x306:
      *(undefined4 *)param_1 = s_GL_DST_COLOR._0_4_;
      *(undefined4 *)(param_1 + 4) = s_GL_DST_COLOR._4_4_;
      *(undefined4 *)(param_1 + 8) = s_GL_DST_COLOR._8_4_;
      param_1[0xc] = s_GL_DST_COLOR[0xc];
      return;
    case 0x307:
      pcVar2 = s_GL_ONE_MINUS_DST_COLOR;
      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)param_1 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        param_1 = param_1 + 4;
      }
      *(undefined2 *)param_1 = *(undefined2 *)pcVar2;
      param_1[2] = pcVar2[2];
      return;
    }
  }
  _sprintf(param_1,s_0x_x);
  return;
}



// ===========================================
// Function: _QGL_Shutdown @ 0002cc24
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _QGL_Shutdown(void)

{
  (*__ri)(0,s____shutting_down_QGL_);
  if (_DAT_00032f94 != 0) {
    (*__ri)(0,s____unloading_OpenGL_DLL_);
    (*___imp__FreeLibrary_4)(_DAT_00032f94);
  }
  _DAT_00032f94 = 0;
  __qglAccum = 0;
  __qglAlphaFunc = 0;
  __qglAreTexturesResident = 0;
  __qglArrayElement = 0;
  __qglBegin = 0;
  __qglBindTexture = 0;
  __qglBitmap = 0;
  __qglBlendFunc = 0;
  __qglCallList = 0;
  __qglCallLists = 0;
  __qglClear = 0;
  __qglClearAccum = 0;
  __qglClearColor = 0;
  __qglClearDepth = 0;
  __qglClearIndex = 0;
  __qglClearStencil = 0;
  __qglClipPlane = 0;
  __qglColor3b = 0;
  __qglColor3bv = 0;
  __qglColor3d = 0;
  __qglColor3dv = 0;
  __qglColor3f = 0;
  __qglColor3fv = 0;
  __qglColor3i = 0;
  __qglColor3iv = 0;
  __qglColor3s = 0;
  __qglColor3sv = 0;
  __qglColor3ub = 0;
  __qglColor3ubv = 0;
  __qglColor3ui = 0;
  __qglColor3uiv = 0;
  __qglColor3us = 0;
  __qglColor3usv = 0;
  __qglColor4b = 0;
  __qglColor4bv = 0;
  __qglColor4d = 0;
  __qglColor4dv = 0;
  __qglColor4f = 0;
  __qglColor4fv = 0;
  __qglColor4i = 0;
  __qglColor4iv = 0;
  __qglColor4s = 0;
  __qglColor4sv = 0;
  __qglColor4ub = 0;
  __qglColor4ubv = 0;
  __qglColor4ui = 0;
  __qglColor4uiv = 0;
  __qglColor4us = 0;
  __qglColor4usv = 0;
  __qglColorMask = 0;
  __qglColorMaterial = 0;
  __qglColorPointer = 0;
  __qglCopyPixels = 0;
  __qglCopyTexImage1D = 0;
  __qglCopyTexImage2D = 0;
  __qglCopyTexSubImage1D = 0;
  __qglCopyTexSubImage2D = 0;
  __qglCullFace = 0;
  __qglDeleteLists = 0;
  __qglDeleteTextures = 0;
  __qglDepthFunc = 0;
  __qglDepthMask = 0;
  __qglDepthRange = 0;
  __qglDisable = 0;
  __qglDisableClientState = 0;
  __qglDrawArrays = 0;
  __qglDrawBuffer = 0;
  __qglDrawElements = 0;
  __qglDrawPixels = 0;
  __qglEdgeFlag = 0;
  __qglEdgeFlagPointer = 0;
  __qglEdgeFlagv = 0;
  __qglEnable = 0;
  __qglEnableClientState = 0;
  __qglEnd = 0;
  __qglEndList = 0;
  __qglEvalCoord1d = 0;
  __qglEvalCoord1dv = 0;
  __qglEvalCoord1f = 0;
  __qglEvalCoord1fv = 0;
  __qglEvalCoord2d = 0;
  __qglEvalCoord2dv = 0;
  __qglEvalCoord2f = 0;
  __qglEvalCoord2fv = 0;
  __qglEvalMesh1 = 0;
  __qglEvalMesh2 = 0;
  __qglEvalPoint1 = 0;
  __qglEvalPoint2 = 0;
  __qglFeedbackBuffer = 0;
  __qglFinish = 0;
  __qglFlush = 0;
  __qglFogf = 0;
  __qglFogfv = 0;
  __qglFogi = 0;
  __qglFogiv = 0;
  __qglFrontFace = 0;
  __qglFrustum = 0;
  __qglGenLists = 0;
  __qglGenTextures = 0;
  __qglGetBooleanv = 0;
  __qglGetClipPlane = 0;
  __qglGetDoublev = 0;
  __qglGetError = 0;
  __qglGetFloatv = 0;
  __qglGetIntegerv = 0;
  __qglGetLightfv = 0;
  __qglGetLightiv = 0;
  __qglGetMapdv = 0;
  __qglGetMapfv = 0;
  __qglGetMapiv = 0;
  __qglGetMaterialfv = 0;
  __qglGetMaterialiv = 0;
  __qglGetPixelMapfv = 0;
  __qglGetPixelMapuiv = 0;
  __qglGetPixelMapusv = 0;
  __qglGetPointerv = 0;
  __qglGetPolygonStipple = 0;
  __qglGetString = 0;
  __qglGetTexEnvfv = 0;
  __qglGetTexEnviv = 0;
  __qglGetTexGendv = 0;
  __qglGetTexGenfv = 0;
  __qglGetTexGeniv = 0;
  __qglGetTexImage = 0;
  __qglGetTexLevelParameterfv = 0;
  __qglGetTexLevelParameteriv = 0;
  __qglGetTexParameterfv = 0;
  __qglGetTexParameteriv = 0;
  __qglHint = 0;
  __qglIndexMask = 0;
  __qglIndexPointer = 0;
  __qglIndexd = 0;
  __qglIndexdv = 0;
  __qglIndexf = 0;
  __qglIndexfv = 0;
  __qglIndexi = 0;
  __qglIndexiv = 0;
  __qglIndexs = 0;
  __qglIndexsv = 0;
  __qglIndexub = 0;
  __qglIndexubv = 0;
  __qglInitNames = 0;
  __qglInterleavedArrays = 0;
  __qglIsEnabled = 0;
  __qglIsList = 0;
  __qglIsTexture = 0;
  __qglLightModelf = 0;
  __qglLightModelfv = 0;
  __qglLightModeli = 0;
  __qglLightModeliv = 0;
  __qglLightf = 0;
  __qglLightfv = 0;
  __qglLighti = 0;
  __qglLightiv = 0;
  __qglLineStipple = 0;
  __qglLineWidth = 0;
  __qglListBase = 0;
  __qglLoadIdentity = 0;
  __qglLoadMatrixd = 0;
  __qglLoadMatrixf = 0;
  __qglLoadName = 0;
  __qglLogicOp = 0;
  __qglMap1d = 0;
  __qglMap1f = 0;
  __qglMap2d = 0;
  __qglMap2f = 0;
  __qglMapGrid1d = 0;
  __qglMapGrid1f = 0;
  __qglMapGrid2d = 0;
  __qglMapGrid2f = 0;
  __qglMaterialf = 0;
  __qglMaterialfv = 0;
  __qglMateriali = 0;
  __qglMaterialiv = 0;
  __qglMatrixMode = 0;
  __qglMultMatrixd = 0;
  __qglMultMatrixf = 0;
  __qglNewList = 0;
  __qglNormal3b = 0;
  __qglNormal3bv = 0;
  __qglNormal3d = 0;
  __qglNormal3dv = 0;
  __qglNormal3f = 0;
  __qglNormal3fv = 0;
  __qglNormal3i = 0;
  __qglNormal3iv = 0;
  __qglNormal3s = 0;
  __qglNormal3sv = 0;
  __qglNormalPointer = 0;
  __qglOrtho = 0;
  __qglPassThrough = 0;
  __qglPixelMapfv = 0;
  __qglPixelMapuiv = 0;
  __qglPixelMapusv = 0;
  __qglPixelStoref = 0;
  __qglPixelStorei = 0;
  __qglPixelTransferf = 0;
  __qglPixelTransferi = 0;
  __qglPixelZoom = 0;
  __qglPointSize = 0;
  __qglPolygonMode = 0;
  __qglPolygonOffset = 0;
  __qglPolygonStipple = 0;
  __qglPopAttrib = 0;
  __qglPopClientAttrib = 0;
  __qglPopMatrix = 0;
  __qglPopName = 0;
  __qglPrioritizeTextures = 0;
  __qglPushAttrib = 0;
  __qglPushClientAttrib = 0;
  __qglPushMatrix = 0;
  __qglPushName = 0;
  __qglRasterPos2d = 0;
  __qglRasterPos2dv = 0;
  __qglRasterPos2f = 0;
  __qglRasterPos2fv = 0;
  __qglRasterPos2i = 0;
  __qglRasterPos2iv = 0;
  __qglRasterPos2s = 0;
  __qglRasterPos2sv = 0;
  __qglRasterPos3d = 0;
  __qglRasterPos3dv = 0;
  __qglRasterPos3f = 0;
  __qglRasterPos3fv = 0;
  __qglRasterPos3i = 0;
  __qglRasterPos3iv = 0;
  __qglRasterPos3s = 0;
  __qglRasterPos3sv = 0;
  __qglRasterPos4d = 0;
  __qglRasterPos4dv = 0;
  __qglRasterPos4f = 0;
  __qglRasterPos4fv = 0;
  __qglRasterPos4i = 0;
  __qglRasterPos4iv = 0;
  __qglRasterPos4s = 0;
  __qglRasterPos4sv = 0;
  __qglReadBuffer = 0;
  __qglReadPixels = 0;
  __qglRectd = 0;
  __qglRectdv = 0;
  __qglRectf = 0;
  __qglRectfv = 0;
  __qglRecti = 0;
  __qglRectiv = 0;
  __qglRects = 0;
  __qglRectsv = 0;
  __qglRenderMode = 0;
  __qglRotated = 0;
  __qglRotatef = 0;
  __qglScaled = 0;
  __qglScalef = 0;
  __qglScissor = 0;
  __qglSelectBuffer = 0;
  __qglShadeModel = 0;
  __qglStencilFunc = 0;
  __qglStencilMask = 0;
  __qglStencilOp = 0;
  __qglTexCoord1d = 0;
  __qglTexCoord1dv = 0;
  __qglTexCoord1f = 0;
  __qglTexCoord1fv = 0;
  __qglTexCoord1i = 0;
  __qglTexCoord1iv = 0;
  __qglTexCoord1s = 0;
  __qglTexCoord1sv = 0;
  __qglTexCoord2d = 0;
  __qglTexCoord2dv = 0;
  __qglTexCoord2f = 0;
  __qglTexCoord2fv = 0;
  __qglTexCoord2i = 0;
  __qglTexCoord2iv = 0;
  __qglTexCoord2s = 0;
  __qglTexCoord2sv = 0;
  __qglTexCoord3d = 0;
  __qglTexCoord3dv = 0;
  __qglTexCoord3f = 0;
  __qglTexCoord3fv = 0;
  __qglTexCoord3i = 0;
  __qglTexCoord3iv = 0;
  __qglTexCoord3s = 0;
  __qglTexCoord3sv = 0;
  __qglTexCoord4d = 0;
  __qglTexCoord4dv = 0;
  __qglTexCoord4f = 0;
  __qglTexCoord4fv = 0;
  __qglTexCoord4i = 0;
  __qglTexCoord4iv = 0;
  __qglTexCoord4s = 0;
  __qglTexCoord4sv = 0;
  __qglTexCoordPointer = 0;
  __qglTexEnvf = 0;
  __qglTexEnvfv = 0;
  __qglTexEnvi = 0;
  __qglTexEnviv = 0;
  __qglTexGend = 0;
  __qglTexGendv = 0;
  __qglTexGenf = 0;
  __qglTexGenfv = 0;
  __qglTexGeni = 0;
  __qglTexGeniv = 0;
  __qglTexImage1D = 0;
  __qglTexImage2D = 0;
  __qglTexParameterf = 0;
  __qglTexParameterfv = 0;
  __qglTexParameteri = 0;
  __qglTexParameteriv = 0;
  __qglTexSubImage1D = 0;
  __qglTexSubImage2D = 0;
  __qglTranslated = 0;
  __qglTranslatef = 0;
  __qglVertex2d = 0;
  __qglVertex2dv = 0;
  __qglVertex2f = 0;
  __qglVertex2fv = 0;
  __qglVertex2i = 0;
  __qglVertex2iv = 0;
  __qglVertex2s = 0;
  __qglVertex2sv = 0;
  __qglVertex3d = 0;
  __qglVertex3dv = 0;
  __qglVertex3f = 0;
  __qglVertex3fv = 0;
  __qglVertex3i = 0;
  __qglVertex3iv = 0;
  __qglVertex3s = 0;
  __qglVertex3sv = 0;
  __qglVertex4d = 0;
  __qglVertex4dv = 0;
  __qglVertex4f = 0;
  __qglVertex4fv = 0;
  __qglVertex4i = 0;
  __qglVertex4iv = 0;
  __qglVertex4s = 0;
  __qglVertex4sv = 0;
  __qglVertexPointer = 0;
  __qglViewport = 0;
  __qwglCopyContext = 0;
  __qwglCreateContext = 0;
  __qwglCreateLayerContext = 0;
  __qwglDeleteContext = 0;
  __qwglDescribeLayerPlane = 0;
  __qwglGetCurrentContext = 0;
  __qwglGetCurrentDC = 0;
  __qwglGetLayerPaletteEntries = 0;
  __qwglGetProcAddress = 0;
  __qwglMakeCurrent = 0;
  __qwglRealizeLayerPalette = 0;
  __qwglSetLayerPaletteEntries = 0;
  __qwglShareLists = 0;
  __qwglSwapLayerBuffers = 0;
  __qwglUseFontBitmaps = 0;
  __qwglUseFontOutlines = 0;
  __qwglChoosePixelFormat = 0;
  __qwglDescribePixelFormat = 0;
  __qwglGetPixelFormat = 0;
  __qwglSetPixelFormat = 0;
  __qwglSwapBuffers = 0;
  return;
}



// ===========================================
// Function: _QGL_EnableLogging @ 0002d4d1
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _QGL_EnableLogging(int param_1)

{
  undefined4 uVar1;
  tm *__tp;
  int iVar2;
  undefined1 auStack_408 [12];
  char acStack_3fc [1020];
  
  if (`QGL_EnableLogging'::__l2::isEnabled == 0) {
    if (param_1 == 0) {
      return;
    }
  }
  else {
    if (param_1 != 0) {
      uVar1 = va(s__d,*(int *)(__r_logFile + 0x20) + -1);
      (*__asctime)(s_r_logFile,uVar1);
      if (*(int *)(__r_logFile + 0x20) != 0) {
        return;
      }
      param_1 = 0;
    }
    if (`QGL_EnableLogging'::__l2::isEnabled == 0) {
      return;
    }
  }
  `QGL_EnableLogging'::__l2::isEnabled = param_1;
  if (param_1 == 0) {
    if (__fclose != (FILE *)0x0) {
      _fprintf(__fclose,s_____CLOSING_LOG_____);
      _fclose(__fclose);
      __fclose = (FILE *)0x0;
    }
    __qglLoadIdentity = (undefined1 *)_dllLoadIdentity;
    __qglEvalCoord2f = (undefined1 *)_dllEvalCoord2f;
    __qglGetPointerv = (undefined1 *)_dllGetPointerv;
    __qglGetError = (undefined1 *)__dllGetError;
    __qglTexCoord4d = (undefined1 *)_dllTexCoord4d;
    __qglDepthFunc = (undefined1 *)_dllDepthFunc;
    __qglLighti = (undefined1 *)_dllLighti;
    __qglCopyTexSubImage1D = (undefined1 *)_dllCopyTexSubImage1D;
    __qglVertex3s = (undefined1 *)_dllVertex3s;
    __qglLightModelf = (undefined1 *)_dllLightModelf;
    __qglInitNames = (undefined1 *)_dllInitNames;
    __qglShadeModel = (undefined1 *)_dllShadeModel;
    __qglGetMaterialiv = (undefined1 *)_dllGetMaterialiv;
    __qglTexCoord3iv = (undefined1 *)_dllTexCoord3iv;
    __qglMapGrid1d = (undefined1 *)_dllMapGrid1d;
    __qglListBase = (undefined1 *)_dllListBase;
    __qglNormal3d = (undefined1 *)_dllNormal3d;
    __qglRasterPos4dv = (undefined1 *)_dllRasterPos4dv;
    __qglGetMapiv = (undefined1 *)_dllGetMapiv;
    __qglVertex3i = (undefined1 *)_dllVertex3i;
    __qglTexCoord4iv = (undefined1 *)_dllTexCoord4iv;
    __qglEvalCoord1d = (undefined1 *)_dllEvalCoord1d;
    __qglMaterialfv = (undefined1 *)_dllMaterialfv;
    __qglEnableClientState = (undefined1 *)_dllEnableClientState;
    __qglEdgeFlagv = (undefined1 *)_dllEdgeFlagv;
    __qglMaterialiv = (undefined1 *)_dllMaterialiv;
    __qglNormal3bv = (undefined1 *)_dllNormal3bv;
    __qglDisableClientState = (undefined1 *)_dllDisableClientState;
    __qglRectd = (undefined1 *)_dllRectd;
    __qglColor4bv = (undefined1 *)_dllColor4bv;
    __qglGetTexEnviv = (undefined1 *)_dllGetTexEnviv;
    __qglTexCoord3d = (undefined1 *)_dllTexCoord3d;
    __qglVertex3f = (undefined1 *)_dllVertex3f;
    __qglEndList = (undefined1 *)_dllEndList;
    __qglTexCoordPointer = (undefined1 *)_dllTexCoordPointer;
    __qglTexCoord3i = (undefined1 *)_dllTexCoord3i;
    __qglTexEnvf = (undefined1 *)_dllTexEnvf;
    __qglFogiv = (undefined1 *)_dllFogiv;
    __qglRasterPos3f = (undefined1 *)_dllRasterPos3f;
    __qglMap2f = (undefined1 *)_dllMap2f;
    __qglTexCoord4dv = (undefined1 *)_dllTexCoord4dv;
    __qglDisable = (undefined1 *)_dllDisable;
    __qglColor4uiv = (undefined1 *)_dllColor4uiv;
    __qglRasterPos2d = (undefined1 *)_dllRasterPos2d;
    __qglFogfv = (undefined1 *)_dllFogfv;
    __qglTexEnvfv = (undefined1 *)_dllTexEnvfv;
    __qglPrioritizeTextures = (undefined1 *)_dllPrioritizeTextures;
    __qglLoadName = (undefined1 *)_dllLoadName;
    __qglColor3ub = (undefined1 *)_dllColor3ub;
    __qglTexSubImage1D = (undefined1 *)_dllTexSubImage1D;
    __qglColor4ub = (undefined1 *)_dllColor4ub;
    __qglRecti = (undefined1 *)_dllRecti;
    __qglTexParameteriv = (undefined1 *)_dllTexParameteriv;
    __qglTexCoord3dv = (undefined1 *)_dllTexCoord3dv;
    __qglColor3d = (undefined1 *)_dllColor3d;
    __qglLineStipple = (undefined1 *)_dllLineStipple;
    __qglGetTexParameterfv = (undefined1 *)_dllGetTexParameterfv;
    __qglGetPixelMapfv = (undefined1 *)_dllGetPixelMapfv;
    __qglNormal3iv = (undefined1 *)_dllNormal3iv;
    __qglTexCoord1iv = (undefined1 *)_dllTexCoord1iv;
    __qglTexCoord4f = (undefined1 *)_dllTexCoord4f;
    __qglTexCoord1f = (undefined1 *)_dllTexCoord1f;
    __qglOrtho = (undefined1 *)_dllOrtho;
    __qglVertex3fv = (undefined1 *)_dllVertex3fv;
    __qglRasterPos2f = (undefined1 *)_dllRasterPos2f;
    __qglColor4b = (undefined1 *)_dllColor4b;
    __qglPixelStoref = (undefined1 *)_dllPixelStoref;
    __qglBlendFunc = (undefined1 *)_dllBlendFunc;
    __qglRasterPos3sv = (undefined1 *)_dllRasterPos3sv;
    __qglIndexsv = (undefined1 *)_dllIndexsv;
    __qglSelectBuffer = (undefined1 *)_dllSelectBuffer;
    __qglPixelTransferf = (undefined1 *)_dllPixelTransferf;
    __qglVertex2s = (undefined1 *)_dllVertex2s;
    __qglTexGend = (undefined1 *)_dllTexGend;
    __qglNormal3dv = (undefined1 *)_dllNormal3dv;
    __qglVertex3dv = (undefined1 *)_dllVertex3dv;
    __qglGetBooleanv = (undefined1 *)_dllGetBooleanv;
    __qglRasterPos2dv = (undefined1 *)_dllRasterPos2dv;
    __qglVertex2dv = (undefined1 *)_dllVertex2dv;
    __qglClipPlane = (undefined1 *)_dllClipPlane;
    __qglPixelZoom = (undefined1 *)_dllPixelZoom;
    __qglTexCoord4fv = (undefined1 *)_dllTexCoord4fv;
    __qglGetString = (undefined1 *)__dllGetString;
    __qglRasterPos2fv = (undefined1 *)_dllRasterPos2fv;
    __qglRasterPos3d = (undefined1 *)_dllRasterPos3d;
    __qglColor4i = (undefined1 *)_dllColor4i;
    __qglIndexs = (undefined1 *)_dllIndexs;
    __qglLightModelfv = (undefined1 *)_dllLightModelfv;
    __qglColor3iv = (undefined1 *)_dllColor3iv;
    __qglPushClientAttrib = (undefined1 *)_dllPushClientAttrib;
    __qglTexCoord1sv = (undefined1 *)_dllTexCoord1sv;
    __qglRotated = (undefined1 *)_dllRotated;
    __qglScaled = (undefined1 *)_dllScaled;
    __qglColor3s = (undefined1 *)_dllColor3s;
    __qglRectsv = (undefined1 *)_dllRectsv;
    __qglPixelStorei = (undefined1 *)_dllPixelStorei;
    __qglRasterPos3iv = (undefined1 *)_dllRasterPos3iv;
    __qglFogi = (undefined1 *)_dllFogi;
    __qglCallLists = (undefined1 *)_dllCallLists;
    __qglTexCoord3s = (undefined1 *)_dllTexCoord3s;
    __qglGenLists = (undefined1 *)__dllGenLists;
    __qglMap1f = (undefined1 *)_dllMap1f;
    __qglVertex4sv = (undefined1 *)_dllVertex4sv;
    __qglTexImage2D = (undefined1 *)_dllTexImage2D;
    __qglGetMapfv = (undefined1 *)_dllGetMapfv;
    __qglEdgeFlagPointer = (undefined1 *)_dllEdgeFlagPointer;
    __qglGetDoublev = (undefined1 *)_dllGetDoublev;
    __qglClearIndex = (undefined1 *)_dllClearIndex;
    __qglColorMaterial = (undefined1 *)_dllColorMaterial;
    __qglLoadMatrixf = (undefined1 *)_dllLoadMatrixf;
    __qglPixelMapuiv = (undefined1 *)_dllPixelMapuiv;
    __qglLightModeliv = (undefined1 *)_dllLightModeliv;
    __qglGetTexGeniv = (undefined1 *)_dllGetTexGeniv;
    __qglRectf = (undefined1 *)_dllRectf;
    __qglTexCoord2f = (undefined1 *)_dllTexCoord2f;
    __qglGetIntegerv = (undefined1 *)_dllGetIntegerv;
    __qglVertex2d = (undefined1 *)_dllVertex2d;
    __qglGetMapdv = (undefined1 *)_dllGetMapdv;
    __qglIsTexture = (undefined1 *)__dllIsTexture;
    __qglGetPixelMapusv = (undefined1 *)_dllGetPixelMapusv;
    __qglDepthMask = (undefined1 *)_dllDepthMask;
    __qglMatrixMode = (undefined1 *)_dllMatrixMode;
    __qglPolygonMode = (undefined1 *)_dllPolygonMode;
    __qglTexCoord4s = (undefined1 *)_dllTexCoord4s;
    __qglPushMatrix = (undefined1 *)_dllPushMatrix;
    __qglVertex2i = (undefined1 *)_dllVertex2i;
    __qglRasterPos3s = (undefined1 *)_dllRasterPos3s;
    __qglNormal3f = (undefined1 *)_dllNormal3f;
    __qglIndexPointer = (undefined1 *)_dllIndexPointer;
    __qglAreTexturesResident = (undefined1 *)__dllAreTexturesResident;
    __qglIndexfv = (undefined1 *)_dllIndexfv;
    __qglColorMask = (undefined1 *)_dllColorMask;
    __qglIndexd = (undefined1 *)_dllIndexd;
    __qglGetLightfv = (undefined1 *)_dllGetLightfv;
    __qglColor4usv = (undefined1 *)_dllColor4usv;
    __qglRasterPos4s = (undefined1 *)_dllRasterPos4s;
    __qglLogicOp = (undefined1 *)_dllLogicOp;
    __qglPushName = (undefined1 *)_dllPushName;
    __qglTexSubImage2D = (undefined1 *)_dllTexSubImage2D;
    __qglEvalCoord2dv = (undefined1 *)_dllEvalCoord2dv;
    __qglRectiv = (undefined1 *)_dllRectiv;
    __qglStencilFunc = (undefined1 *)_dllStencilFunc;
    __qglPopAttrib = (undefined1 *)_dllPopAttrib;
    __qglTexCoord2fv = (undefined1 *)_dllTexCoord2fv;
    __qglRasterPos4i = (undefined1 *)_dllRasterPos4i;
    __qglColor3b = (undefined1 *)_dllColor3b;
    __qglPixelMapfv = (undefined1 *)_dllPixelMapfv;
    __qglColor4ubv = (undefined1 *)_dllColor4ubv;
    __qglFlush = (undefined1 *)_dllFlush;
    __qglColor3ui = (undefined1 *)_dllColor3ui;
    __qglEnd = (undefined1 *)_dllEnd;
    __qglColor3dv = (undefined1 *)_dllColor3dv;
    __qglTranslated = (undefined1 *)_dllTranslated;
    __qglNewList = (undefined1 *)_dllNewList;
    __qglGetTexLevelParameteriv = (undefined1 *)_dllGetTexLevelParameteriv;
    __qglTexGenfv = (undefined1 *)_dllTexGenfv;
    __qglReadPixels = (undefined1 *)_dllReadPixels;
    __qglGenTextures = (undefined1 *)_dllGenTextures;
    __qglRasterPos2sv = (undefined1 *)_dllRasterPos2sv;
    __qglTexCoord1d = (undefined1 *)_dllTexCoord1d;
    __qglAccum = (undefined1 *)_dllAccum;
    __qglColor4ui = (undefined1 *)_dllColor4ui;
    __qglScalef = (undefined1 *)_dllScalef;
    __qglRasterPos4iv = (undefined1 *)_dllRasterPos4iv;
    __qglIndexubv = (undefined1 *)_dllIndexubv;
    __qglEnable = (undefined1 *)_dllEnable;
    __qglVertex3sv = (undefined1 *)_dllVertex3sv;
    __qglRasterPos2i = (undefined1 *)_dllRasterPos2i;
    __qglTexGenf = (undefined1 *)_dllTexGenf;
    __qglNormal3b = (undefined1 *)_dllNormal3b;
    __qglIndexf = (undefined1 *)_dllIndexf;
    __qglPushAttrib = (undefined1 *)_dllPushAttrib;
    __qglTexCoord2d = (undefined1 *)_dllTexCoord2d;
    __qglLightiv = (undefined1 *)_dllLightiv;
    __qglPassThrough = (undefined1 *)_dllPassThrough;
    __qglCopyPixels = (undefined1 *)_dllCopyPixels;
    __qglMap2d = (undefined1 *)_dllMap2d;
    __qglIndexi = (undefined1 *)_dllIndexi;
    __qglColor3sv = (undefined1 *)_dllColor3sv;
    __qglVertex4i = (undefined1 *)_dllVertex4i;
    __qglDrawArrays = (undefined1 *)_dllDrawArrays;
    __qglEvalMesh1 = (undefined1 *)_dllEvalMesh1;
    __qglColor3usv = (undefined1 *)_dllColor3usv;
    __qglNormalPointer = (undefined1 *)_dllNormalPointer;
    __qglRasterPos3dv = (undefined1 *)_dllRasterPos3dv;
    __qglColor3f = (undefined1 *)_dllColor3f;
    __qglLoadMatrixd = (undefined1 *)_dllLoadMatrixd;
    __qglEvalPoint1 = (undefined1 *)_dllEvalPoint1;
    __qglReadBuffer = (undefined1 *)_dllReadBuffer;
    __qglBindTexture = (undefined1 *)_dllBindTexture;
    __qglEvalCoord1dv = (undefined1 *)_dllEvalCoord1dv;
    __qglTexCoord2iv = (undefined1 *)_dllTexCoord2iv;
    __qglPolygonOffset = (undefined1 *)_dllPolygonOffset;
    __qglRasterPos4fv = (undefined1 *)_dllRasterPos4fv;
    __qglTexCoord1dv = (undefined1 *)_dllTexCoord1dv;
    __qglIndexub = (undefined1 *)_dllIndexub;
    __qglArrayElement = (undefined1 *)_dllArrayElement;
    __qglVertex4dv = (undefined1 *)_dllVertex4dv;
    __qglColor3fv = (undefined1 *)_dllColor3fv;
    __qglNormal3i = (undefined1 *)_dllNormal3i;
    __qglMultMatrixd = (undefined1 *)_dllMultMatrixd;
    __qglDrawElements = (undefined1 *)_dllDrawElements;
    __qglTexEnvi = (undefined1 *)_dllTexEnvi;
    __qglVertex2f = (undefined1 *)_dllVertex2f;
    __qglColor4d = (undefined1 *)_dllColor4d;
    __qglEvalPoint2 = (undefined1 *)_dllEvalPoint2;
    __qglGetTexLevelParameterfv = (undefined1 *)_dllGetTexLevelParameterfv;
    __qglHint = (undefined1 *)_dllHint;
    __qglPopName = (undefined1 *)_dllPopName;
    __qglVertex2iv = (undefined1 *)_dllVertex2iv;
    __qglRectfv = (undefined1 *)_dllRectfv;
    __qglColor4dv = (undefined1 *)_dllColor4dv;
    __qglColor3bv = (undefined1 *)_dllColor3bv;
    __qglLightfv = (undefined1 *)_dllLightfv;
    __qglIndexiv = (undefined1 *)_dllIndexiv;
    __qglTexCoord4sv = (undefined1 *)_dllTexCoord4sv;
    __qglPixelTransferi = (undefined1 *)_dllPixelTransferi;
    __qglAlphaFunc = (undefined1 *)_dllAlphaFunc;
    __qglScissor = (undefined1 *)_dllScissor;
    __qglRotatef = (undefined1 *)_dllRotatef;
    __qglTranslatef = (undefined1 *)_dllTranslatef;
    __qglTexCoord2dv = (undefined1 *)_dllTexCoord2dv;
    __qglTexImage1D = (undefined1 *)_dllTexImage1D;
    __qglColor4iv = (undefined1 *)_dllColor4iv;
    __qglGetTexParameteriv = (undefined1 *)_dllGetTexParameteriv;
    __qglDrawBuffer = (undefined1 *)_dllDrawBuffer;
    __qglCullFace = (undefined1 *)_dllCullFace;
    __qglRasterPos4d = (undefined1 *)_dllRasterPos4d;
    __qglVertex4iv = (undefined1 *)_dllVertex4iv;
    __qglVertex2sv = (undefined1 *)_dllVertex2sv;
    __qglCopyTexImage1D = (undefined1 *)_dllCopyTexImage1D;
    __qglTexParameterfv = (undefined1 *)_dllTexParameterfv;
    __qglRenderMode = (undefined1 *)__dllRenderMode;
    __qglRasterPos4f = (undefined1 *)_dllRasterPos4f;
    __qglPopClientAttrib = (undefined1 *)_dllPopClientAttrib;
    __qglFinish = (undefined1 *)_dllFinish;
    __qglGetTexEnvfv = (undefined1 *)_dllGetTexEnvfv;
    __qglEvalCoord1f = (undefined1 *)_dllEvalCoord1f;
    __qglBegin = (undefined1 *)_dllBegin;
    __qglDeleteLists = (undefined1 *)_dllDeleteLists;
    __qglFeedbackBuffer = (undefined1 *)_dllFeedbackBuffer;
    __qglRasterPos3fv = (undefined1 *)_dllRasterPos3fv;
    __qglEvalCoord1fv = (undefined1 *)_dllEvalCoord1fv;
    __qglClear = (undefined1 *)_dllClear;
    __qglPointSize = (undefined1 *)_dllPointSize;
    __qglDepthRange = (undefined1 *)_dllDepthRange;
    __qglPopMatrix = (undefined1 *)_dllPopMatrix;
    __qglMapGrid2f = (undefined1 *)_dllMapGrid2f;
    __qglGetTexGendv = (undefined1 *)_dllGetTexGendv;
    __qglGetTexImage = (undefined1 *)_dllGetTexImage;
    __qglVertex2fv = (undefined1 *)_dllVertex2fv;
    __qglVertex3d = (undefined1 *)_dllVertex3d;
    __qglNormal3fv = (undefined1 *)_dllNormal3fv;
    __qglTexCoord3sv = (undefined1 *)_dllTexCoord3sv;
    __qglColor3ubv = (undefined1 *)_dllColor3ubv;
    __qglEvalCoord2fv = (undefined1 *)_dllEvalCoord2fv;
    __qglDrawPixels = (undefined1 *)_dllDrawPixels;
    __qglGetPixelMapuiv = (undefined1 *)_dllGetPixelMapuiv;
    __qglColor3uiv = (undefined1 *)_dllColor3uiv;
    __qglStencilOp = (undefined1 *)_dllStencilOp;
    __qglColorPointer = (undefined1 *)_dllColorPointer;
    __qglGetLightiv = (undefined1 *)_dllGetLightiv;
    __qglFrontFace = (undefined1 *)_dllFrontFace;
    __qglMaterialf = (undefined1 *)_dllMaterialf;
    __qglClearAccum = (undefined1 *)_dllClearAccum;
    __qglColor3us = (undefined1 *)_dllColor3us;
    __qglEvalMesh2 = (undefined1 *)_dllEvalMesh2;
    __qglColor3i = (undefined1 *)_dllColor3i;
    __qglViewport = (undefined1 *)_dllViewport;
    __qglVertex3iv = (undefined1 *)_dllVertex3iv;
    __qglGetTexGenfv = (undefined1 *)_dllGetTexGenfv;
    __qglIndexMask = (undefined1 *)_dllIndexMask;
    __qglVertex4d = (undefined1 *)_dllVertex4d;
    __qglEdgeFlag = (undefined1 *)_dllEdgeFlag;
    __qglRasterPos2iv = (undefined1 *)_dllRasterPos2iv;
    __qglTexEnviv = (undefined1 *)_dllTexEnviv;
    __qglVertexPointer = (undefined1 *)_dllVertexPointer;
    __qglDeleteTextures = (undefined1 *)_dllDeleteTextures;
    __qglCopyTexImage2D = (undefined1 *)_dllCopyTexImage2D;
    __qglClearColor = (undefined1 *)_dllClearColor;
    __qglFrustum = (undefined1 *)_dllFrustum;
    __qglColor4sv = (undefined1 *)_dllColor4sv;
    __qglLightf = (undefined1 *)_dllLightf;
    __qglBitmap = (undefined1 *)_dllBitmap;
    __qglColor4s = (undefined1 *)_dllColor4s;
    __qglIsEnabled = (undefined1 *)__dllIsEnabled;
    __qglGetMaterialfv = (undefined1 *)_dllGetMaterialfv;
    __qglColor4f = (undefined1 *)_dllColor4f;
    __qglTexCoord2sv = (undefined1 *)_dllTexCoord2sv;
    __qglMapGrid2d = (undefined1 *)_dllMapGrid2d;
    __qglRectdv = (undefined1 *)_dllRectdv;
    __qglFogf = (undefined1 *)_dllFogf;
    __qglGetClipPlane = (undefined1 *)_dllGetClipPlane;
    __qglTexGendv = (undefined1 *)_dllTexGendv;
    __qglRasterPos2s = (undefined1 *)_dllRasterPos2s;
    __qglInterleavedArrays = (undefined1 *)_dllInterleavedArrays;
    __qglTexCoord4i = (undefined1 *)_dllTexCoord4i;
    __qglTexCoord1i = (undefined1 *)_dllTexCoord1i;
    __qglStencilMask = (undefined1 *)_dllStencilMask;
    __qglTexGeniv = (undefined1 *)_dllTexGeniv;
    __qglTexGeni = (undefined1 *)_dllTexGeni;
    __qglVertex4f = (undefined1 *)_dllVertex4f;
    __qglTexCoord2s = (undefined1 *)_dllTexCoord2s;
    __qglTexCoord3f = (undefined1 *)_dllTexCoord3f;
    __qglEvalCoord2d = (undefined1 *)_dllEvalCoord2d;
    __qglMapGrid1f = (undefined1 *)_dllMapGrid1f;
    __qglTexCoord2i = (undefined1 *)_dllTexCoord2i;
    __qglPixelMapusv = (undefined1 *)_dllPixelMapusv;
    __qglTexCoord1fv = (undefined1 *)_dllTexCoord1fv;
    __qglPolygonStipple = (undefined1 *)_dllPolygonStipple;
    __qglCallList = (undefined1 *)_dllCallList;
    __qglClearDepth = (undefined1 *)_dllClearDepth;
    __qglColor4us = (undefined1 *)_dllColor4us;
    __qglTexParameteri = (undefined1 *)_dllTexParameteri;
    __qglGetFloatv = (undefined1 *)_dllGetFloatv;
    __qglIndexdv = (undefined1 *)_dllIndexdv;
    __qglVertex4fv = (undefined1 *)_dllVertex4fv;
    __qglTexParameterf = (undefined1 *)_dllTexParameterf;
    __qglRasterPos3i = (undefined1 *)_dllRasterPos3i;
    __qglLightModeli = (undefined1 *)_dllLightModeli;
    __qglRects = (undefined1 *)_dllRects;
    __qglMultMatrixf = (undefined1 *)_dllMultMatrixf;
    __qglMap1d = (undefined1 *)_dllMap1d;
    __qglLineWidth = (undefined1 *)_dllLineWidth;
    __qglMateriali = (undefined1 *)_dllMateriali;
    __qglClearStencil = (undefined1 *)_dllClearStencil;
    __qglNormal3s = (undefined1 *)_dllNormal3s;
    __qglTexCoord1s = (undefined1 *)_dllTexCoord1s;
    __qglRasterPos4sv = (undefined1 *)_dllRasterPos4sv;
    __qglTexCoord3fv = (undefined1 *)_dllTexCoord3fv;
    __qglIsList = (undefined1 *)__dllIsList;
    __qglColor4fv = (undefined1 *)_dllColor4fv;
    __qglVertex4s = (undefined1 *)_dllVertex4s;
    __qglNormal3sv = (undefined1 *)_dllNormal3sv;
    __qglGetPolygonStipple = (undefined1 *)_dllGetPolygonStipple;
    __qglCopyTexSubImage2D = (undefined1 *)_dllCopyTexSubImage2D;
    return;
  }
  if (__fclose == (FILE *)0x0) {
    __time64(auStack_408);
    __tp = (tm *)__localtime64(auStack_408);
    _asctime(__tp);
    iVar2 = (*_DAT_00032fc4)(s_fs_basepath,s_,0);
    _Com_sprintf(acStack_3fc,0x400,s__s_gl_log,*(undefined4 *)(iVar2 + 4));
    __fclose = _fopen(acStack_3fc,s_wt);
    _asctime(__tp);
    _fprintf(__fclose,s__s_);
  }
  __qglAccum = &_logAccum_8;
  __qglAlphaFunc = &_logAlphaFunc_8;
  __qglAreTexturesResident = &_logAreTexturesResident_12;
  __qglArrayElement = &_logArrayElement_4;
  __qglBegin = &_logBegin_4;
  __qglBindTexture = &_logBindTexture_8;
  __qglBitmap = &_logBitmap_28;
  __qglBlendFunc = &_logBlendFunc_8;
  __qglCallList = &_logCallList_4;
  __qglCallLists = &_logCallLists_12;
  __qglClear = &_logClear_4;
  __qglClearAccum = &_logClearAccum_16;
  __qglClearColor = &_logClearColor_16;
  __qglClearDepth = &_logClearDepth_8;
  __qglClearIndex = &_logClearIndex_4;
  __qglClearStencil = &_logClearStencil_4;
  __qglClipPlane = &_logClipPlane_8;
  __qglColor3b = &_logColor3b_12;
  __qglColor3bv = &_logColor3bv_4;
  __qglColor3d = &_logColor3d_24;
  __qglColor3dv = &_logColor3dv_4;
  __qglColor3f = &_logColor3f_12;
  __qglColor3fv = &_logColor3fv_4;
  __qglColor3i = &_logColor3i_12;
  __qglColor3iv = &_logColor3iv_4;
  __qglColor3s = &_logColor3s_12;
  __qglColor3sv = &_logColor3sv_4;
  __qglColor3ub = &_logColor3ub_12;
  __qglColor3ubv = &_logColor3ubv_4;
  __qglColor3ui = &_logColor3ui_12;
  __qglColor3uiv = &_logColor3uiv_4;
  __qglColor3us = &_logColor3us_12;
  __qglColor3usv = &_logColor3usv_4;
  __qglColor4b = &_logColor4b_16;
  __qglColor4bv = &_logColor4bv_4;
  __qglColor4d = &_logColor4d_32;
  __qglColor4dv = &_logColor4dv_4;
  __qglColor4f = &_logColor4f_16;
  __qglColor4fv = &_logColor4fv_4;
  __qglColor4i = &_logColor4i_16;
  __qglColor4iv = &_logColor4iv_4;
  __qglColor4s = &_logColor4s_16;
  __qglColor4sv = &_logColor4sv_4;
  __qglColor4ub = &_logColor4ub_16;
  __qglColor4ubv = &_logColor4ubv_4;
  __qglColor4ui = &_logColor4ui_16;
  __qglColor4uiv = &_logColor4uiv_4;
  __qglColor4us = &_logColor4us_16;
  __qglColor4usv = &_logColor4usv_4;
  __qglColorMask = &_logColorMask_16;
  __qglColorMaterial = &_logColorMaterial_8;
  __qglColorPointer = &_logColorPointer_16;
  __qglCopyPixels = &_logCopyPixels_20;
  __qglCopyTexImage1D = &_logCopyTexImage1D_28;
  __qglCopyTexImage2D = &_logCopyTexImage2D_32;
  __qglCopyTexSubImage1D = &_logCopyTexSubImage1D_24;
  __qglCopyTexSubImage2D = &_logCopyTexSubImage2D_32;
  __qglCullFace = &_logCullFace_4;
  __qglDeleteLists = &_logDeleteLists_8;
  __qglDeleteTextures = &_logDeleteTextures_8;
  __qglDepthFunc = &_logDepthFunc_4;
  __qglDepthMask = &_logDepthMask_4;
  __qglDepthRange = &_logDepthRange_16;
  __qglDisable = &_logDisable_4;
  __qglDisableClientState = &_logDisableClientState_4;
  __qglDrawArrays = &_logDrawArrays_12;
  __qglDrawBuffer = &_logDrawBuffer_4;
  __qglDrawElements = &_logDrawElements_16;
  __qglDrawPixels = &_logDrawPixels_20;
  __qglEdgeFlag = &_logEdgeFlag_4;
  __qglEdgeFlagPointer = &_logEdgeFlagPointer_8;
  __qglEdgeFlagv = &_logEdgeFlagv_4;
  __qglEnable = &_logEnable_4;
  __qglEnableClientState = &_logEnableClientState_4;
  __qglEnd = &_logEnd_0;
  __qglEndList = &_logEndList_0;
  __qglEvalCoord1d = &_logEvalCoord1d_8;
  __qglEvalCoord1dv = &_logEvalCoord1dv_4;
  __qglEvalCoord1f = &_logEvalCoord1f_4;
  __qglEvalCoord1fv = &_logEvalCoord1fv_4;
  __qglEvalCoord2d = &_logEvalCoord2d_16;
  __qglEvalCoord2dv = &_logEvalCoord2dv_4;
  __qglEvalCoord2f = &_logEvalCoord2f_8;
  __qglEvalCoord2fv = &_logEvalCoord2fv_4;
  __qglEvalMesh1 = &_logEvalMesh1_12;
  __qglEvalMesh2 = &_logEvalMesh2_20;
  __qglEvalPoint1 = &_logEvalPoint1_4;
  __qglEvalPoint2 = &_logEvalPoint2_8;
  __qglFeedbackBuffer = &_logFeedbackBuffer_12;
  __qglFinish = &_logFinish_0;
  __qglFlush = &_logFlush_0;
  __qglFogf = &_logFogf_8;
  __qglFogfv = &_logFogfv_8;
  __qglFogi = &_logFogi_8;
  __qglFogiv = &_logFogiv_8;
  __qglFrontFace = &_logFrontFace_4;
  __qglFrustum = &_logFrustum_48;
  __qglGenLists = &_logGenLists_4;
  __qglGenTextures = &_logGenTextures_8;
  __qglGetBooleanv = &_logGetBooleanv_8;
  __qglGetClipPlane = &_logGetClipPlane_8;
  __qglGetDoublev = &_logGetDoublev_8;
  __qglGetError = &_logGetError_0;
  __qglGetFloatv = &_logGetFloatv_8;
  __qglGetIntegerv = &_logGetIntegerv_8;
  __qglGetLightfv = &_logGetLightfv_12;
  __qglGetLightiv = &_logGetLightiv_12;
  __qglGetMapdv = &_logGetMapdv_12;
  __qglGetMapfv = &_logGetMapfv_12;
  __qglGetMapiv = &_logGetMapiv_12;
  __qglGetMaterialfv = &_logGetMaterialfv_12;
  __qglGetMaterialiv = &_logGetMaterialiv_12;
  __qglGetPixelMapfv = &_logGetPixelMapfv_8;
  __qglGetPixelMapuiv = &_logGetPixelMapuiv_8;
  __qglGetPixelMapusv = &_logGetPixelMapusv_8;
  __qglGetPointerv = &_logGetPointerv_8;
  __qglGetPolygonStipple = &_logGetPolygonStipple_4;
  __qglGetString = &_logGetString_4;
  __qglGetTexEnvfv = &_logGetTexEnvfv_12;
  __qglGetTexEnviv = &_logGetTexEnviv_12;
  __qglGetTexGendv = &_logGetTexGendv_12;
  __qglGetTexGenfv = &_logGetTexGenfv_12;
  __qglGetTexGeniv = &_logGetTexGeniv_12;
  __qglGetTexImage = &_logGetTexImage_20;
  __qglGetTexLevelParameterfv = &_logGetTexLevelParameterfv_16;
  __qglGetTexLevelParameteriv = &_logGetTexLevelParameteriv_16;
  __qglGetTexParameterfv = &_logGetTexParameterfv_12;
  __qglGetTexParameteriv = &_logGetTexParameteriv_12;
  __qglHint = &_logHint_8;
  __qglIndexMask = &_logIndexMask_4;
  __qglIndexPointer = &_logIndexPointer_12;
  __qglIndexd = &_logIndexd_8;
  __qglIndexdv = &_logIndexdv_4;
  __qglIndexf = &_logIndexf_4;
  __qglIndexfv = &_logIndexfv_4;
  __qglIndexi = &_logIndexi_4;
  __qglIndexiv = &_logIndexiv_4;
  __qglIndexs = &_logIndexs_4;
  __qglIndexsv = &_logIndexsv_4;
  __qglIndexub = &_logIndexub_4;
  __qglIndexubv = &_logIndexubv_4;
  __qglInitNames = &_logInitNames_0;
  __qglInterleavedArrays = &_logInterleavedArrays_12;
  __qglIsEnabled = &_logIsEnabled_4;
  __qglIsList = &_logIsList_4;
  __qglIsTexture = &_logIsTexture_4;
  __qglLightModelf = &_logLightModelf_8;
  __qglLightModelfv = &_logLightModelfv_8;
  __qglLightModeli = &_logLightModeli_8;
  __qglLightModeliv = &_logLightModeliv_8;
  __qglLightf = &_logLightf_12;
  __qglLightfv = &_logLightfv_12;
  __qglLighti = &_logLighti_12;
  __qglLightiv = &_logLightiv_12;
  __qglLineStipple = &_logLineStipple_8;
  __qglLineWidth = &_logLineWidth_4;
  __qglListBase = &_logListBase_4;
  __qglLoadIdentity = &_logLoadIdentity_0;
  __qglLoadMatrixd = &_logLoadMatrixd_4;
  __qglLoadMatrixf = &_logLoadMatrixf_4;
  __qglLoadName = &_logLoadName_4;
  __qglLogicOp = &_logLogicOp_4;
  __qglMap1d = &_logMap1d_32;
  __qglMap1f = &_logMap1f_24;
  __qglMap2d = &_logMap2d_56;
  __qglMap2f = &_logMap2f_40;
  __qglMapGrid1d = &_logMapGrid1d_20;
  __qglMapGrid1f = &_logMapGrid1f_12;
  __qglMapGrid2d = &_logMapGrid2d_40;
  __qglMapGrid2f = &_logMapGrid2f_24;
  __qglMaterialf = &_logMaterialf_12;
  __qglMaterialfv = &_logMaterialfv_12;
  __qglMateriali = &_logMateriali_12;
  __qglMaterialiv = &_logMaterialiv_12;
  __qglMatrixMode = &_logMatrixMode_4;
  __qglMultMatrixd = &_logMultMatrixd_4;
  __qglMultMatrixf = &_logMultMatrixf_4;
  __qglNewList = &_logNewList_8;
  __qglNormal3b = &_logNormal3b_12;
  __qglNormal3bv = &_logNormal3bv_4;
  __qglNormal3d = &_logNormal3d_24;
  __qglNormal3dv = &_logNormal3dv_4;
  __qglNormal3f = &_logNormal3f_12;
  __qglNormal3fv = &_logNormal3fv_4;
  __qglNormal3i = &_logNormal3i_12;
  __qglNormal3iv = &_logNormal3iv_4;
  __qglNormal3s = &_logNormal3s_12;
  __qglNormal3sv = &_logNormal3sv_4;
  __qglNormalPointer = &_logNormalPointer_12;
  __qglOrtho = &_logOrtho_48;
  __qglPassThrough = &_logPassThrough_4;
  __qglPixelMapfv = &_logPixelMapfv_12;
  __qglPixelMapuiv = &_logPixelMapuiv_12;
  __qglPixelMapusv = &_logPixelMapusv_12;
  __qglPixelStoref = &_logPixelStoref_8;
  __qglPixelStorei = &_logPixelStorei_8;
  __qglPixelTransferf = &_logPixelTransferf_8;
  __qglPixelTransferi = &_logPixelTransferi_8;
  __qglPixelZoom = &_logPixelZoom_8;
  __qglPointSize = &_logPointSize_4;
  __qglPolygonMode = &_logPolygonMode_8;
  __qglPolygonOffset = &_logPolygonOffset_8;
  __qglPolygonStipple = &_logPolygonStipple_4;
  __qglPopAttrib = &_logPopAttrib_0;
  __qglPopClientAttrib = &_logPopClientAttrib_0;
  __qglPopMatrix = &_logPopMatrix_0;
  __qglPopName = &_logPopName_0;
  __qglPrioritizeTextures = &_logPrioritizeTextures_12;
  __qglPushAttrib = &_logPushAttrib_4;
  __qglPushClientAttrib = &_logPushClientAttrib_4;
  __qglPushMatrix = &_logPushMatrix_0;
  __qglPushName = &_logPushName_4;
  __qglRasterPos2d = &_logRasterPos2d_16;
  __qglRasterPos2dv = &_logRasterPos2dv_4;
  __qglRasterPos2f = &_logRasterPos2f_8;
  __qglRasterPos2fv = &_logRasterPos2fv_4;
  __qglRasterPos2i = &_logRasterPos2i_8;
  __qglRasterPos2iv = &_logRasterPos2iv_4;
  __qglRasterPos2s = &_logRasterPos2s_8;
  __qglRasterPos2sv = &_logRasterPos2sv_4;
  __qglRasterPos3d = &_logRasterPos3d_24;
  __qglRasterPos3dv = &_logRasterPos3dv_4;
  __qglRasterPos3f = &_logRasterPos3f_12;
  __qglRasterPos3fv = &_logRasterPos3fv_4;
  __qglRasterPos3i = &_logRasterPos3i_12;
  __qglRasterPos3iv = &_logRasterPos3iv_4;
  __qglRasterPos3s = &_logRasterPos3s_12;
  __qglRasterPos3sv = &_logRasterPos3sv_4;
  __qglRasterPos4d = &_logRasterPos4d_32;
  __qglRasterPos4dv = &_logRasterPos4dv_4;
  __qglRasterPos4f = &_logRasterPos4f_16;
  __qglRasterPos4fv = &_logRasterPos4fv_4;
  __qglRasterPos4i = &_logRasterPos4i_16;
  __qglRasterPos4iv = &_logRasterPos4iv_4;
  __qglRasterPos4s = &_logRasterPos4s_16;
  __qglRasterPos4sv = &_logRasterPos4sv_4;
  __qglReadBuffer = &_logReadBuffer_4;
  __qglReadPixels = &_logReadPixels_28;
  __qglRectd = &_logRectd_32;
  __qglRectdv = &_logRectdv_8;
  __qglRectf = &_logRectf_16;
  __qglRectfv = &_logRectfv_8;
  __qglRecti = &_logRecti_16;
  __qglRectiv = &_logRectiv_8;
  __qglRects = &_logRects_16;
  __qglRectsv = &_logRectsv_8;
  __qglRenderMode = &_logRenderMode_4;
  __qglRotated = &_logRotated_32;
  __qglRotatef = &_logRotatef_16;
  __qglScaled = &_logScaled_24;
  __qglScalef = &_logScalef_12;
  __qglScissor = &_logScissor_16;
  __qglSelectBuffer = &_logSelectBuffer_8;
  __qglShadeModel = &_logShadeModel_4;
  __qglStencilFunc = &_logStencilFunc_12;
  __qglStencilMask = &_logStencilMask_4;
  __qglStencilOp = &_logStencilOp_12;
  __qglTexCoord1d = &_logTexCoord1d_8;
  __qglTexCoord1dv = &_logTexCoord1dv_4;
  __qglTexCoord1f = &_logTexCoord1f_4;
  __qglTexCoord1fv = &_logTexCoord1fv_4;
  __qglTexCoord1i = &_logTexCoord1i_4;
  __qglTexCoord1iv = &_logTexCoord1iv_4;
  __qglTexCoord1s = &_logTexCoord1s_4;
  __qglTexCoord1sv = &_logTexCoord1sv_4;
  __qglTexCoord2d = &_logTexCoord2d_16;
  __qglTexCoord2dv = &_logTexCoord2dv_4;
  __qglTexCoord2f = &_logTexCoord2f_8;
  __qglTexCoord2fv = &_logTexCoord2fv_4;
  __qglTexCoord2i = &_logTexCoord2i_8;
  __qglTexCoord2iv = &_logTexCoord2iv_4;
  __qglTexCoord2s = &_logTexCoord2s_8;
  __qglTexCoord2sv = &_logTexCoord2sv_4;
  __qglTexCoord3d = &_logTexCoord3d_24;
  __qglTexCoord3dv = &_logTexCoord3dv_4;
  __qglTexCoord3f = &_logTexCoord3f_12;
  __qglTexCoord3fv = &_logTexCoord3fv_4;
  __qglTexCoord3i = &_logTexCoord3i_12;
  __qglTexCoord3iv = &_logTexCoord3iv_4;
  __qglTexCoord3s = &_logTexCoord3s_12;
  __qglTexCoord3sv = &_logTexCoord3sv_4;
  __qglTexCoord4d = &_logTexCoord4d_32;
  __qglTexCoord4dv = &_logTexCoord4dv_4;
  __qglTexCoord4f = &_logTexCoord4f_16;
  __qglTexCoord4fv = &_logTexCoord4fv_4;
  __qglTexCoord4i = &_logTexCoord4i_16;
  __qglTexCoord4iv = &_logTexCoord4iv_4;
  __qglTexCoord4s = &_logTexCoord4s_16;
  __qglTexCoord4sv = &_logTexCoord4sv_4;
  __qglTexCoordPointer = &_logTexCoordPointer_16;
  __qglTexEnvf = &_logTexEnvf_12;
  __qglTexEnvfv = &_logTexEnvfv_12;
  __qglTexEnvi = &_logTexEnvi_12;
  __qglTexEnviv = &_logTexEnviv_12;
  __qglTexGend = &_logTexGend_16;
  __qglTexGendv = &_logTexGendv_12;
  __qglTexGenf = &_logTexGenf_12;
  __qglTexGenfv = &_logTexGenfv_12;
  __qglTexGeni = &_logTexGeni_12;
  __qglTexGeniv = &_logTexGeniv_12;
  __qglTexImage1D = &_logTexImage1D_32;
  __qglTexImage2D = &_logTexImage2D_36;
  __qglTexParameterf = &_logTexParameterf_12;
  __qglTexParameterfv = &_logTexParameterfv_12;
  __qglTexParameteri = &_logTexParameteri_12;
  __qglTexParameteriv = &_logTexParameteriv_12;
  __qglTexSubImage1D = &_logTexSubImage1D_28;
  __qglTexSubImage2D = &_logTexSubImage2D_36;
  __qglTranslated = &_logTranslated_24;
  __qglTranslatef = &_logTranslatef_12;
  __qglVertex2d = &_logVertex2d_16;
  __qglVertex2dv = &_logVertex2dv_4;
  __qglVertex2f = &_logVertex2f_8;
  __qglVertex2fv = &_logVertex2fv_4;
  __qglVertex2i = &_logVertex2i_8;
  __qglVertex2iv = &_logVertex2iv_4;
  __qglVertex2s = &_logVertex2s_8;
  __qglVertex2sv = &_logVertex2sv_4;
  __qglVertex3d = &_logVertex3d_24;
  __qglVertex3dv = &_logVertex3dv_4;
  __qglVertex3f = &_logVertex3f_12;
  __qglVertex3fv = &_logVertex3fv_4;
  __qglVertex3i = &_logVertex3i_12;
  __qglVertex3iv = &_logVertex3iv_4;
  __qglVertex3s = &_logVertex3s_12;
  __qglVertex3sv = &_logVertex3sv_4;
  __qglVertex4d = &_logVertex4d_32;
  __qglVertex4dv = &_logVertex4dv_4;
  __qglVertex4f = &_logVertex4f_16;
  __qglVertex4fv = &_logVertex4fv_4;
  __qglVertex4i = &_logVertex4i_16;
  __qglVertex4iv = &_logVertex4iv_4;
  __qglVertex4s = &_logVertex4s_16;
  __qglVertex4sv = &_logVertex4sv_4;
  __qglVertexPointer = &_logVertexPointer_16;
  __qglViewport = &_logViewport_16;
  return;
}



// ===========================================
// Function: _QGL_Init @ 0002f203
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _QGL_Init(void)

{
  code *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 auStack_800 [1024];
  undefined1 local_400 [1020];
  char *pcStack_4;
  
  (*___imp__GetSystemDirectoryA_8)(local_400,0x400);
  (*__ri)(0,s____initializing_QGL_);
  pcVar2 = _strstr(pcStack_4,s_3dfxvgl);
  pcVar1 = ___imp__LoadLibraryA_4;
  if (pcVar2 != (char *)0x0) {
    iVar3 = (*___imp__LoadLibraryA_4)(s_Glide3X);
    if (iVar3 == 0) {
      (*__ri)(0,s____WARNING__missing_Glide_instal);
      return 0;
    }
  }
  if (*pcStack_4 == '!') {
    _Q_strncpyz(auStack_800,pcStack_4,0x400);
  }
  else {
    _Com_sprintf(auStack_800,0x400,s__s__s,local_400,pcStack_4);
  }
  (*__ri)(0,s____calling_LoadLibrary____s_dll_,auStack_800);
  _DAT_00032f94 = (*pcVar1)(pcStack_4);
  if (_DAT_00032f94 == 0) {
    (*__ri)(0,s_failed_);
    return 0;
  }
  (*__ri)(0,s_succeeded_);
  pcVar1 = ___imp__GetProcAddress_8;
  _dllAccum = (*___imp__GetProcAddress_8)(_DAT_00032f94,s_glAccum);
  __qglAccum = _dllAccum;
  _dllAlphaFunc = (*pcVar1)(_DAT_00032f94,s_glAlphaFunc);
  __qglAlphaFunc = _dllAlphaFunc;
  __dllAreTexturesResident = (*pcVar1)(_DAT_00032f94,s_glAreTexturesResident);
  __qglAreTexturesResident = __dllAreTexturesResident;
  _dllArrayElement = (*pcVar1)(_DAT_00032f94,s_glArrayElement);
  __qglArrayElement = _dllArrayElement;
  _dllBegin = (*pcVar1)(_DAT_00032f94,s_glBegin);
  __qglBegin = _dllBegin;
  _dllBindTexture = (*pcVar1)(_DAT_00032f94,s_glBindTexture);
  __qglBindTexture = _dllBindTexture;
  _dllBitmap = (*pcVar1)(_DAT_00032f94,s_glBitmap);
  __qglBitmap = _dllBitmap;
  _dllBlendFunc = (*pcVar1)(_DAT_00032f94,s_glBlendFunc);
  __qglBlendFunc = _dllBlendFunc;
  _dllCallList = (*pcVar1)(_DAT_00032f94,s_glCallList);
  __qglCallList = _dllCallList;
  _dllCallLists = (*pcVar1)(_DAT_00032f94,s_glCallLists);
  __qglCallLists = _dllCallLists;
  _dllClear = (*pcVar1)(_DAT_00032f94,s_glClear);
  __qglClear = _dllClear;
  _dllClearAccum = (*pcVar1)(_DAT_00032f94,s_glClearAccum);
  __qglClearAccum = _dllClearAccum;
  _dllClearColor = (*pcVar1)(_DAT_00032f94,s_glClearColor);
  __qglClearColor = _dllClearColor;
  _dllClearDepth = (*pcVar1)(_DAT_00032f94,s_glClearDepth);
  __qglClearDepth = _dllClearDepth;
  _dllClearIndex = (*pcVar1)(_DAT_00032f94,s_glClearIndex);
  __qglClearIndex = _dllClearIndex;
  _dllClearStencil = (*pcVar1)(_DAT_00032f94,s_glClearStencil);
  __qglClearStencil = _dllClearStencil;
  _dllClipPlane = (*pcVar1)(_DAT_00032f94,s_glClipPlane);
  __qglClipPlane = _dllClipPlane;
  _dllColor3b = (*pcVar1)(_DAT_00032f94,s_glColor3b);
  __qglColor3b = _dllColor3b;
  _dllColor3bv = (*pcVar1)(_DAT_00032f94,s_glColor3bv);
  __qglColor3bv = _dllColor3bv;
  _dllColor3d = (*pcVar1)(_DAT_00032f94,s_glColor3d);
  __qglColor3d = _dllColor3d;
  _dllColor3dv = (*pcVar1)(_DAT_00032f94,s_glColor3dv);
  __qglColor3dv = _dllColor3dv;
  _dllColor3f = (*pcVar1)(_DAT_00032f94,s_glColor3f);
  __qglColor3f = _dllColor3f;
  _dllColor3fv = (*pcVar1)(_DAT_00032f94,s_glColor3fv);
  __qglColor3fv = _dllColor3fv;
  _dllColor3i = (*pcVar1)(_DAT_00032f94,s_glColor3i);
  __qglColor3i = _dllColor3i;
  _dllColor3iv = (*pcVar1)(_DAT_00032f94,s_glColor3iv);
  __qglColor3iv = _dllColor3iv;
  _dllColor3s = (*pcVar1)(_DAT_00032f94,s_glColor3s);
  __qglColor3s = _dllColor3s;
  _dllColor3sv = (*pcVar1)(_DAT_00032f94,s_glColor3sv);
  __qglColor3sv = _dllColor3sv;
  _dllColor3ub = (*pcVar1)(_DAT_00032f94,s_glColor3ub);
  __qglColor3ub = _dllColor3ub;
  _dllColor3ubv = (*pcVar1)(_DAT_00032f94,s_glColor3ubv);
  __qglColor3ubv = _dllColor3ubv;
  _dllColor3ui = (*pcVar1)(_DAT_00032f94,s_glColor3ui);
  __qglColor3ui = _dllColor3ui;
  _dllColor3uiv = (*pcVar1)(_DAT_00032f94,s_glColor3uiv);
  __qglColor3uiv = _dllColor3uiv;
  _dllColor3us = (*pcVar1)(_DAT_00032f94,s_glColor3us);
  __qglColor3us = _dllColor3us;
  _dllColor3usv = (*pcVar1)(_DAT_00032f94,s_glColor3usv);
  __qglColor3usv = _dllColor3usv;
  _dllColor4b = (*pcVar1)(_DAT_00032f94,s_glColor4b);
  __qglColor4b = _dllColor4b;
  _dllColor4bv = (*pcVar1)(_DAT_00032f94,s_glColor4bv);
  __qglColor4bv = _dllColor4bv;
  _dllColor4d = (*pcVar1)(_DAT_00032f94,s_glColor4d);
  __qglColor4d = _dllColor4d;
  _dllColor4dv = (*pcVar1)(_DAT_00032f94,s_glColor4dv);
  __qglColor4dv = _dllColor4dv;
  _dllColor4f = (*pcVar1)(_DAT_00032f94,s_glColor4f);
  __qglColor4f = _dllColor4f;
  _dllColor4fv = (*pcVar1)(_DAT_00032f94,s_glColor4fv);
  __qglColor4fv = _dllColor4fv;
  _dllColor4i = (*pcVar1)(_DAT_00032f94,s_glColor4i);
  __qglColor4i = _dllColor4i;
  _dllColor4iv = (*pcVar1)(_DAT_00032f94,s_glColor4iv);
  __qglColor4iv = _dllColor4iv;
  _dllColor4s = (*pcVar1)(_DAT_00032f94,s_glColor4s);
  __qglColor4s = _dllColor4s;
  _dllColor4sv = (*pcVar1)(_DAT_00032f94,s_glColor4sv);
  __qglColor4sv = _dllColor4sv;
  _dllColor4ub = (*pcVar1)(_DAT_00032f94,s_glColor4ub);
  __qglColor4ub = _dllColor4ub;
  _dllColor4ubv = (*pcVar1)(_DAT_00032f94,s_glColor4ubv);
  __qglColor4ubv = _dllColor4ubv;
  _dllColor4ui = (*pcVar1)(_DAT_00032f94,s_glColor4ui);
  __qglColor4ui = _dllColor4ui;
  _dllColor4uiv = (*pcVar1)(_DAT_00032f94,s_glColor4uiv);
  __qglColor4uiv = _dllColor4uiv;
  _dllColor4us = (*pcVar1)(_DAT_00032f94,s_glColor4us);
  __qglColor4us = _dllColor4us;
  _dllColor4usv = (*pcVar1)(_DAT_00032f94,s_glColor4usv);
  __qglColor4usv = _dllColor4usv;
  _dllColorMask = (*pcVar1)(_DAT_00032f94,s_glColorMask);
  __qglColorMask = _dllColorMask;
  _dllColorMaterial = (*pcVar1)(_DAT_00032f94,s_glColorMaterial);
  __qglColorMaterial = _dllColorMaterial;
  _dllColorPointer = (*pcVar1)(_DAT_00032f94,s_glColorPointer);
  __qglColorPointer = _dllColorPointer;
  _dllCopyPixels = (*pcVar1)(_DAT_00032f94,s_glCopyPixels);
  __qglCopyPixels = _dllCopyPixels;
  _dllCopyTexImage1D = (*pcVar1)(_DAT_00032f94,s_glCopyTexImage1D);
  __qglCopyTexImage1D = _dllCopyTexImage1D;
  _dllCopyTexImage2D = (*pcVar1)(_DAT_00032f94,s_glCopyTexImage2D);
  __qglCopyTexImage2D = _dllCopyTexImage2D;
  _dllCopyTexSubImage1D = (*pcVar1)(_DAT_00032f94,s_glCopyTexSubImage1D);
  __qglCopyTexSubImage1D = _dllCopyTexSubImage1D;
  _dllCopyTexSubImage2D = (*pcVar1)(_DAT_00032f94,s_glCopyTexSubImage2D);
  __qglCopyTexSubImage2D = _dllCopyTexSubImage2D;
  _dllCullFace = (*pcVar1)(_DAT_00032f94,s_glCullFace);
  __qglCullFace = _dllCullFace;
  _dllDeleteLists = (*pcVar1)(_DAT_00032f94,s_glDeleteLists);
  __qglDeleteLists = _dllDeleteLists;
  _dllDeleteTextures = (*pcVar1)(_DAT_00032f94,s_glDeleteTextures);
  __qglDeleteTextures = _dllDeleteTextures;
  _dllDepthFunc = (*pcVar1)(_DAT_00032f94,s_glDepthFunc);
  __qglDepthFunc = _dllDepthFunc;
  _dllDepthMask = (*pcVar1)(_DAT_00032f94,s_glDepthMask);
  __qglDepthMask = _dllDepthMask;
  _dllDepthRange = (*pcVar1)(_DAT_00032f94,s_glDepthRange);
  __qglDepthRange = _dllDepthRange;
  _dllDisable = (*pcVar1)(_DAT_00032f94,s_glDisable);
  __qglDisable = _dllDisable;
  _dllDisableClientState = (*pcVar1)(_DAT_00032f94,s_glDisableClientState);
  __qglDisableClientState = _dllDisableClientState;
  _dllDrawArrays = (*pcVar1)(_DAT_00032f94,s_glDrawArrays);
  __qglDrawArrays = _dllDrawArrays;
  _dllDrawBuffer = (*pcVar1)(_DAT_00032f94,s_glDrawBuffer);
  __qglDrawBuffer = _dllDrawBuffer;
  _dllDrawElements = (*pcVar1)(_DAT_00032f94,s_glDrawElements);
  __qglDrawElements = _dllDrawElements;
  _dllDrawPixels = (*pcVar1)(_DAT_00032f94,s_glDrawPixels);
  __qglDrawPixels = _dllDrawPixels;
  _dllEdgeFlag = (*pcVar1)(_DAT_00032f94,s_glEdgeFlag);
  __qglEdgeFlag = _dllEdgeFlag;
  _dllEdgeFlagPointer = (*pcVar1)(_DAT_00032f94,s_glEdgeFlagPointer);
  __qglEdgeFlagPointer = _dllEdgeFlagPointer;
  _dllEdgeFlagv = (*pcVar1)(_DAT_00032f94,s_glEdgeFlagv);
  __qglEdgeFlagv = _dllEdgeFlagv;
  _dllEnable = (*pcVar1)(_DAT_00032f94,s_glEnable);
  __qglEnable = _dllEnable;
  _dllEnableClientState = (*pcVar1)(_DAT_00032f94,s_glEnableClientState);
  __qglEnableClientState = _dllEnableClientState;
  _dllEnd = (*pcVar1)(_DAT_00032f94,s_glEnd);
  __qglEnd = _dllEnd;
  _dllEndList = (*pcVar1)(_DAT_00032f94,s_glEndList);
  __qglEndList = _dllEndList;
  _dllEvalCoord1d = (*pcVar1)(_DAT_00032f94,s_glEvalCoord1d);
  __qglEvalCoord1d = _dllEvalCoord1d;
  _dllEvalCoord1dv = (*pcVar1)(_DAT_00032f94,s_glEvalCoord1dv);
  __qglEvalCoord1dv = _dllEvalCoord1dv;
  _dllEvalCoord1f = (*pcVar1)(_DAT_00032f94,s_glEvalCoord1f);
  __qglEvalCoord1f = _dllEvalCoord1f;
  _dllEvalCoord1fv = (*pcVar1)(_DAT_00032f94,s_glEvalCoord1fv);
  __qglEvalCoord1fv = _dllEvalCoord1fv;
  _dllEvalCoord2d = (*pcVar1)(_DAT_00032f94,s_glEvalCoord2d);
  __qglEvalCoord2d = _dllEvalCoord2d;
  _dllEvalCoord2dv = (*pcVar1)(_DAT_00032f94,s_glEvalCoord2dv);
  __qglEvalCoord2dv = _dllEvalCoord2dv;
  _dllEvalCoord2f = (*pcVar1)(_DAT_00032f94,s_glEvalCoord2f);
  __qglEvalCoord2f = _dllEvalCoord2f;
  _dllEvalCoord2fv = (*pcVar1)(_DAT_00032f94,s_glEvalCoord2fv);
  __qglEvalCoord2fv = _dllEvalCoord2fv;
  _dllEvalMesh1 = (*pcVar1)(_DAT_00032f94,s_glEvalMesh1);
  __qglEvalMesh1 = _dllEvalMesh1;
  _dllEvalMesh2 = (*pcVar1)(_DAT_00032f94,s_glEvalMesh2);
  __qglEvalMesh2 = _dllEvalMesh2;
  _dllEvalPoint1 = (*pcVar1)(_DAT_00032f94,s_glEvalPoint1);
  __qglEvalPoint1 = _dllEvalPoint1;
  _dllEvalPoint2 = (*pcVar1)(_DAT_00032f94,s_glEvalPoint2);
  __qglEvalPoint2 = _dllEvalPoint2;
  _dllFeedbackBuffer = (*pcVar1)(_DAT_00032f94,s_glFeedbackBuffer);
  __qglFeedbackBuffer = _dllFeedbackBuffer;
  _dllFinish = (*pcVar1)(_DAT_00032f94,s_glFinish);
  __qglFinish = _dllFinish;
  _dllFlush = (*pcVar1)(_DAT_00032f94,s_glFlush);
  __qglFlush = _dllFlush;
  _dllFogf = (*pcVar1)(_DAT_00032f94,s_glFogf);
  __qglFogf = _dllFogf;
  _dllFogfv = (*pcVar1)(_DAT_00032f94,s_glFogfv);
  __qglFogfv = _dllFogfv;
  _dllFogi = (*pcVar1)(_DAT_00032f94,s_glFogi);
  __qglFogi = _dllFogi;
  _dllFogiv = (*pcVar1)(_DAT_00032f94,s_glFogiv);
  __qglFogiv = _dllFogiv;
  _dllFrontFace = (*pcVar1)(_DAT_00032f94,s_glFrontFace);
  __qglFrontFace = _dllFrontFace;
  _dllFrustum = (*pcVar1)(_DAT_00032f94,s_glFrustum);
  __qglFrustum = _dllFrustum;
  __dllGenLists = (*pcVar1)(_DAT_00032f94,s_glGenLists);
  __qglGenLists = __dllGenLists;
  _dllGenTextures = (*pcVar1)(_DAT_00032f94,s_glGenTextures);
  __qglGenTextures = _dllGenTextures;
  _dllGetBooleanv = (*pcVar1)(_DAT_00032f94,s_glGetBooleanv);
  __qglGetBooleanv = _dllGetBooleanv;
  _dllGetClipPlane = (*pcVar1)(_DAT_00032f94,s_glGetClipPlane);
  __qglGetClipPlane = _dllGetClipPlane;
  _dllGetDoublev = (*pcVar1)(_DAT_00032f94,s_glGetDoublev);
  __qglGetDoublev = _dllGetDoublev;
  __dllGetError = (*pcVar1)(_DAT_00032f94,s_glGetError);
  __qglGetError = __dllGetError;
  _dllGetFloatv = (*pcVar1)(_DAT_00032f94,s_glGetFloatv);
  __qglGetFloatv = _dllGetFloatv;
  _dllGetIntegerv = (*pcVar1)(_DAT_00032f94,s_glGetIntegerv);
  __qglGetIntegerv = _dllGetIntegerv;
  _dllGetLightfv = (*pcVar1)(_DAT_00032f94,s_glGetLightfv);
  __qglGetLightfv = _dllGetLightfv;
  _dllGetLightiv = (*pcVar1)(_DAT_00032f94,s_glGetLightiv);
  __qglGetLightiv = _dllGetLightiv;
  _dllGetMapdv = (*pcVar1)(_DAT_00032f94,s_glGetMapdv);
  __qglGetMapdv = _dllGetMapdv;
  _dllGetMapfv = (*pcVar1)(_DAT_00032f94,s_glGetMapfv);
  __qglGetMapfv = _dllGetMapfv;
  _dllGetMapiv = (*pcVar1)(_DAT_00032f94,s_glGetMapiv);
  __qglGetMapiv = _dllGetMapiv;
  _dllGetMaterialfv = (*pcVar1)(_DAT_00032f94,s_glGetMaterialfv);
  __qglGetMaterialfv = _dllGetMaterialfv;
  _dllGetMaterialiv = (*pcVar1)(_DAT_00032f94,s_glGetMaterialiv);
  __qglGetMaterialiv = _dllGetMaterialiv;
  _dllGetPixelMapfv = (*pcVar1)(_DAT_00032f94,s_glGetPixelMapfv);
  __qglGetPixelMapfv = _dllGetPixelMapfv;
  _dllGetPixelMapuiv = (*pcVar1)(_DAT_00032f94,s_glGetPixelMapuiv);
  __qglGetPixelMapuiv = _dllGetPixelMapuiv;
  _dllGetPixelMapusv = (*pcVar1)(_DAT_00032f94,s_glGetPixelMapusv);
  __qglGetPixelMapusv = _dllGetPixelMapusv;
  _dllGetPointerv = (*pcVar1)(_DAT_00032f94,s_glGetPointerv);
  __qglGetPointerv = _dllGetPointerv;
  _dllGetPolygonStipple = (*pcVar1)(_DAT_00032f94,s_glGetPolygonStipple);
  __qglGetPolygonStipple = _dllGetPolygonStipple;
  __qglGetString = (*pcVar1)(_DAT_00032f94,s_glGetString);
  __dllGetString = __qglGetString;
  _dllGetTexEnvfv = (*pcVar1)(_DAT_00032f94,s_glGetTexEnvfv);
  __qglGetTexEnvfv = _dllGetTexEnvfv;
  _dllGetTexEnviv = (*pcVar1)(_DAT_00032f94,s_glGetTexEnviv);
  __qglGetTexEnviv = _dllGetTexEnviv;
  _dllGetTexGendv = (*pcVar1)(_DAT_00032f94,s_glGetTexGendv);
  __qglGetTexGendv = _dllGetTexGendv;
  _dllGetTexGenfv = (*pcVar1)(_DAT_00032f94,s_glGetTexGenfv);
  __qglGetTexGenfv = _dllGetTexGenfv;
  _dllGetTexGeniv = (*pcVar1)(_DAT_00032f94,s_glGetTexGeniv);
  __qglGetTexGeniv = _dllGetTexGeniv;
  _dllGetTexImage = (*pcVar1)(_DAT_00032f94,s_glGetTexImage);
  __qglGetTexImage = _dllGetTexImage;
  _dllGetTexLevelParameterfv = (*pcVar1)(_DAT_00032f94,s_glGetLevelParameterfv);
  __qglGetTexLevelParameterfv = _dllGetTexLevelParameterfv;
  _dllGetTexLevelParameteriv = (*pcVar1)(_DAT_00032f94,s_glGetLevelParameteriv);
  __qglGetTexLevelParameteriv = _dllGetTexLevelParameteriv;
  _dllGetTexParameterfv = (*pcVar1)(_DAT_00032f94,s_glGetTexParameterfv);
  __qglGetTexParameterfv = _dllGetTexParameterfv;
  _dllGetTexParameteriv = (*pcVar1)(_DAT_00032f94,s_glGetTexParameteriv);
  __qglGetTexParameteriv = _dllGetTexParameteriv;
  _dllHint = (*pcVar1)(_DAT_00032f94,s_glHint);
  __qglHint = _dllHint;
  _dllIndexMask = (*pcVar1)(_DAT_00032f94,s_glIndexMask);
  __qglIndexMask = _dllIndexMask;
  _dllIndexPointer = (*pcVar1)(_DAT_00032f94,s_glIndexPointer);
  __qglIndexPointer = _dllIndexPointer;
  _dllIndexd = (*pcVar1)(_DAT_00032f94,s_glIndexd);
  __qglIndexd = _dllIndexd;
  _dllIndexdv = (*pcVar1)(_DAT_00032f94,s_glIndexdv);
  __qglIndexdv = _dllIndexdv;
  _dllIndexf = (*pcVar1)(_DAT_00032f94,s_glIndexf);
  __qglIndexf = _dllIndexf;
  _dllIndexfv = (*pcVar1)(_DAT_00032f94,s_glIndexfv);
  __qglIndexfv = _dllIndexfv;
  _dllIndexi = (*pcVar1)(_DAT_00032f94,s_glIndexi);
  __qglIndexi = _dllIndexi;
  _dllIndexiv = (*pcVar1)(_DAT_00032f94,s_glIndexiv);
  __qglIndexiv = _dllIndexiv;
  _dllIndexs = (*pcVar1)(_DAT_00032f94,s_glIndexs);
  __qglIndexs = _dllIndexs;
  _dllIndexsv = (*pcVar1)(_DAT_00032f94,s_glIndexsv);
  __qglIndexsv = _dllIndexsv;
  _dllIndexub = (*pcVar1)(_DAT_00032f94,s_glIndexub);
  __qglIndexub = _dllIndexub;
  _dllIndexubv = (*pcVar1)(_DAT_00032f94,s_glIndexubv);
  __qglIndexubv = _dllIndexubv;
  _dllInitNames = (*pcVar1)(_DAT_00032f94,s_glInitNames);
  __qglInitNames = _dllInitNames;
  _dllInterleavedArrays = (*pcVar1)(_DAT_00032f94,s_glInterleavedArrays);
  __qglInterleavedArrays = _dllInterleavedArrays;
  __dllIsEnabled = (*pcVar1)(_DAT_00032f94,s_glIsEnabled);
  __qglIsEnabled = __dllIsEnabled;
  __qglIsList = (*pcVar1)(_DAT_00032f94,s_glIsList);
  __dllIsList = __qglIsList;
  __dllIsTexture = (*pcVar1)(_DAT_00032f94,s_glIsTexture);
  __qglIsTexture = __dllIsTexture;
  _dllLightModelf = (*pcVar1)(_DAT_00032f94,s_glLightModelf);
  __qglLightModelf = _dllLightModelf;
  _dllLightModelfv = (*pcVar1)(_DAT_00032f94,s_glLightModelfv);
  __qglLightModelfv = _dllLightModelfv;
  _dllLightModeli = (*pcVar1)(_DAT_00032f94,s_glLightModeli);
  __qglLightModeli = _dllLightModeli;
  _dllLightModeliv = (*pcVar1)(_DAT_00032f94,s_glLightModeliv);
  __qglLightModeliv = _dllLightModeliv;
  _dllLightf = (*pcVar1)(_DAT_00032f94,s_glLightf);
  __qglLightf = _dllLightf;
  _dllLightfv = (*pcVar1)(_DAT_00032f94,s_glLightfv);
  __qglLightfv = _dllLightfv;
  _dllLighti = (*pcVar1)(_DAT_00032f94,s_glLighti);
  __qglLighti = _dllLighti;
  _dllLightiv = (*pcVar1)(_DAT_00032f94,s_glLightiv);
  __qglLightiv = _dllLightiv;
  _dllLineStipple = (*pcVar1)(_DAT_00032f94,s_glLineStipple);
  __qglLineStipple = _dllLineStipple;
  _dllLineWidth = (*pcVar1)(_DAT_00032f94,s_glLineWidth);
  __qglLineWidth = _dllLineWidth;
  _dllListBase = (*pcVar1)(_DAT_00032f94,s_glListBase);
  __qglListBase = _dllListBase;
  _dllLoadIdentity = (*pcVar1)(_DAT_00032f94,s_glLoadIdentity);
  __qglLoadIdentity = _dllLoadIdentity;
  _dllLoadMatrixd = (*pcVar1)(_DAT_00032f94,s_glLoadMatrixd);
  __qglLoadMatrixd = _dllLoadMatrixd;
  _dllLoadMatrixf = (*pcVar1)(_DAT_00032f94,s_glLoadMatrixf);
  __qglLoadMatrixf = _dllLoadMatrixf;
  _dllLoadName = (*pcVar1)(_DAT_00032f94,s_glLoadName);
  __qglLoadName = _dllLoadName;
  _dllLogicOp = (*pcVar1)(_DAT_00032f94,s_glLogicOp);
  __qglLogicOp = _dllLogicOp;
  _dllMap1d = (*pcVar1)(_DAT_00032f94,s_glMap1d);
  __qglMap1d = _dllMap1d;
  _dllMap1f = (*pcVar1)(_DAT_00032f94,s_glMap1f);
  __qglMap1f = _dllMap1f;
  _dllMap2d = (*pcVar1)(_DAT_00032f94,s_glMap2d);
  __qglMap2d = _dllMap2d;
  _dllMap2f = (*pcVar1)(_DAT_00032f94,s_glMap2f);
  __qglMap2f = _dllMap2f;
  _dllMapGrid1d = (*pcVar1)(_DAT_00032f94,s_glMapGrid1d);
  __qglMapGrid1d = _dllMapGrid1d;
  _dllMapGrid1f = (*pcVar1)(_DAT_00032f94,s_glMapGrid1f);
  __qglMapGrid1f = _dllMapGrid1f;
  _dllMapGrid2d = (*pcVar1)(_DAT_00032f94,s_glMapGrid2d);
  __qglMapGrid2d = _dllMapGrid2d;
  _dllMapGrid2f = (*pcVar1)(_DAT_00032f94,s_glMapGrid2f);
  __qglMapGrid2f = _dllMapGrid2f;
  _dllMaterialf = (*pcVar1)(_DAT_00032f94,s_glMaterialf);
  __qglMaterialf = _dllMaterialf;
  _dllMaterialfv = (*pcVar1)(_DAT_00032f94,s_glMaterialfv);
  __qglMaterialfv = _dllMaterialfv;
  _dllMateriali = (*pcVar1)(_DAT_00032f94,s_glMateriali);
  __qglMateriali = _dllMateriali;
  _dllMaterialiv = (*pcVar1)(_DAT_00032f94,s_glMaterialiv);
  __qglMaterialiv = _dllMaterialiv;
  _dllMatrixMode = (*pcVar1)(_DAT_00032f94,s_glMatrixMode);
  __qglMatrixMode = _dllMatrixMode;
  _dllMultMatrixd = (*pcVar1)(_DAT_00032f94,s_glMultMatrixd);
  __qglMultMatrixd = _dllMultMatrixd;
  _dllMultMatrixf = (*pcVar1)(_DAT_00032f94,s_glMultMatrixf);
  __qglMultMatrixf = _dllMultMatrixf;
  _dllNewList = (*pcVar1)(_DAT_00032f94,s_glNewList);
  __qglNewList = _dllNewList;
  _dllNormal3b = (*pcVar1)(_DAT_00032f94,s_glNormal3b);
  __qglNormal3b = _dllNormal3b;
  _dllNormal3bv = (*pcVar1)(_DAT_00032f94,s_glNormal3bv);
  __qglNormal3bv = _dllNormal3bv;
  _dllNormal3d = (*pcVar1)(_DAT_00032f94,s_glNormal3d);
  __qglNormal3d = _dllNormal3d;
  _dllNormal3dv = (*pcVar1)(_DAT_00032f94,s_glNormal3dv);
  __qglNormal3dv = _dllNormal3dv;
  _dllNormal3f = (*pcVar1)(_DAT_00032f94,s_glNormal3f);
  __qglNormal3f = _dllNormal3f;
  _dllNormal3fv = (*pcVar1)(_DAT_00032f94,s_glNormal3fv);
  __qglNormal3fv = _dllNormal3fv;
  _dllNormal3i = (*pcVar1)(_DAT_00032f94,s_glNormal3i);
  __qglNormal3i = _dllNormal3i;
  _dllNormal3iv = (*pcVar1)(_DAT_00032f94,s_glNormal3iv);
  __qglNormal3iv = _dllNormal3iv;
  _dllNormal3s = (*pcVar1)(_DAT_00032f94,s_glNormal3s);
  __qglNormal3s = _dllNormal3s;
  _dllNormal3sv = (*pcVar1)(_DAT_00032f94,s_glNormal3sv);
  __qglNormal3sv = _dllNormal3sv;
  _dllNormalPointer = (*pcVar1)(_DAT_00032f94,s_glNormalPointer);
  __qglNormalPointer = _dllNormalPointer;
  _dllOrtho = (*pcVar1)(_DAT_00032f94,s_glOrtho);
  __qglOrtho = _dllOrtho;
  _dllPassThrough = (*pcVar1)(_DAT_00032f94,s_glPassThrough);
  __qglPassThrough = _dllPassThrough;
  _dllPixelMapfv = (*pcVar1)(_DAT_00032f94,s_glPixelMapfv);
  __qglPixelMapfv = _dllPixelMapfv;
  _dllPixelMapuiv = (*pcVar1)(_DAT_00032f94,s_glPixelMapuiv);
  __qglPixelMapuiv = _dllPixelMapuiv;
  _dllPixelMapusv = (*pcVar1)(_DAT_00032f94,s_glPixelMapusv);
  __qglPixelMapusv = _dllPixelMapusv;
  _dllPixelStoref = (*pcVar1)(_DAT_00032f94,s_glPixelStoref);
  __qglPixelStoref = _dllPixelStoref;
  _dllPixelStorei = (*pcVar1)(_DAT_00032f94,s_glPixelStorei);
  __qglPixelStorei = _dllPixelStorei;
  _dllPixelTransferf = (*pcVar1)(_DAT_00032f94,s_glPixelTransferf);
  __qglPixelTransferf = _dllPixelTransferf;
  _dllPixelTransferi = (*pcVar1)(_DAT_00032f94,s_glPixelTransferi);
  __qglPixelTransferi = _dllPixelTransferi;
  _dllPixelZoom = (*pcVar1)(_DAT_00032f94,s_glPixelZoom);
  __qglPixelZoom = _dllPixelZoom;
  _dllPointSize = (*pcVar1)(_DAT_00032f94,s_glPointSize);
  __qglPointSize = _dllPointSize;
  _dllPolygonMode = (*pcVar1)(_DAT_00032f94,s_glPolygonMode);
  __qglPolygonMode = _dllPolygonMode;
  _dllPolygonOffset = (*pcVar1)(_DAT_00032f94,s_glPolygonOffset);
  __qglPolygonOffset = _dllPolygonOffset;
  _dllPolygonStipple = (*pcVar1)(_DAT_00032f94,s_glPolygonStipple);
  __qglPolygonStipple = _dllPolygonStipple;
  _dllPopAttrib = (*pcVar1)(_DAT_00032f94,s_glPopAttrib);
  __qglPopAttrib = _dllPopAttrib;
  _dllPopClientAttrib = (*pcVar1)(_DAT_00032f94,s_glPopClientAttrib);
  __qglPopClientAttrib = _dllPopClientAttrib;
  _dllPopMatrix = (*pcVar1)(_DAT_00032f94,s_glPopMatrix);
  __qglPopMatrix = _dllPopMatrix;
  _dllPopName = (*pcVar1)(_DAT_00032f94,s_glPopName);
  __qglPopName = _dllPopName;
  _dllPrioritizeTextures = (*pcVar1)(_DAT_00032f94,s_glPrioritizeTextures);
  __qglPrioritizeTextures = _dllPrioritizeTextures;
  _dllPushAttrib = (*pcVar1)(_DAT_00032f94,s_glPushAttrib);
  __qglPushAttrib = _dllPushAttrib;
  _dllPushClientAttrib = (*pcVar1)(_DAT_00032f94,s_glPushClientAttrib);
  __qglPushClientAttrib = _dllPushClientAttrib;
  _dllPushMatrix = (*pcVar1)(_DAT_00032f94,s_glPushMatrix);
  __qglPushMatrix = _dllPushMatrix;
  _dllPushName = (*pcVar1)(_DAT_00032f94,s_glPushName);
  __qglPushName = _dllPushName;
  _dllRasterPos2d = (*pcVar1)(_DAT_00032f94,s_glRasterPos2d);
  __qglRasterPos2d = _dllRasterPos2d;
  _dllRasterPos2dv = (*pcVar1)(_DAT_00032f94,s_glRasterPos2dv);
  __qglRasterPos2dv = _dllRasterPos2dv;
  _dllRasterPos2f = (*pcVar1)(_DAT_00032f94,s_glRasterPos2f);
  __qglRasterPos2f = _dllRasterPos2f;
  _dllRasterPos2fv = (*pcVar1)(_DAT_00032f94,s_glRasterPos2fv);
  __qglRasterPos2fv = _dllRasterPos2fv;
  _dllRasterPos2i = (*pcVar1)(_DAT_00032f94,s_glRasterPos2i);
  __qglRasterPos2i = _dllRasterPos2i;
  _dllRasterPos2iv = (*pcVar1)(_DAT_00032f94,s_glRasterPos2iv);
  __qglRasterPos2iv = _dllRasterPos2iv;
  _dllRasterPos2s = (*pcVar1)(_DAT_00032f94,s_glRasterPos2s);
  __qglRasterPos2s = _dllRasterPos2s;
  _dllRasterPos2sv = (*pcVar1)(_DAT_00032f94,s_glRasterPos2sv);
  __qglRasterPos2sv = _dllRasterPos2sv;
  _dllRasterPos3d = (*pcVar1)(_DAT_00032f94,s_glRasterPos3d);
  __qglRasterPos3d = _dllRasterPos3d;
  _dllRasterPos3dv = (*pcVar1)(_DAT_00032f94,s_glRasterPos3dv);
  __qglRasterPos3dv = _dllRasterPos3dv;
  _dllRasterPos3f = (*pcVar1)(_DAT_00032f94,s_glRasterPos3f);
  __qglRasterPos3f = _dllRasterPos3f;
  _dllRasterPos3fv = (*pcVar1)(_DAT_00032f94,s_glRasterPos3fv);
  __qglRasterPos3fv = _dllRasterPos3fv;
  _dllRasterPos3i = (*pcVar1)(_DAT_00032f94,s_glRasterPos3i);
  __qglRasterPos3i = _dllRasterPos3i;
  _dllRasterPos3iv = (*pcVar1)(_DAT_00032f94,s_glRasterPos3iv);
  __qglRasterPos3iv = _dllRasterPos3iv;
  _dllRasterPos3s = (*pcVar1)(_DAT_00032f94,s_glRasterPos3s);
  __qglRasterPos3s = _dllRasterPos3s;
  _dllRasterPos3sv = (*pcVar1)(_DAT_00032f94,s_glRasterPos3sv);
  __qglRasterPos3sv = _dllRasterPos3sv;
  _dllRasterPos4d = (*pcVar1)(_DAT_00032f94,s_glRasterPos4d);
  __qglRasterPos4d = _dllRasterPos4d;
  _dllRasterPos4dv = (*pcVar1)(_DAT_00032f94,s_glRasterPos4dv);
  __qglRasterPos4dv = _dllRasterPos4dv;
  _dllRasterPos4f = (*pcVar1)(_DAT_00032f94,s_glRasterPos4f);
  __qglRasterPos4f = _dllRasterPos4f;
  _dllRasterPos4fv = (*pcVar1)(_DAT_00032f94,s_glRasterPos4fv);
  __qglRasterPos4fv = _dllRasterPos4fv;
  _dllRasterPos4i = (*pcVar1)(_DAT_00032f94,s_glRasterPos4i);
  __qglRasterPos4i = _dllRasterPos4i;
  _dllRasterPos4iv = (*pcVar1)(_DAT_00032f94,s_glRasterPos4iv);
  __qglRasterPos4iv = _dllRasterPos4iv;
  _dllRasterPos4s = (*pcVar1)(_DAT_00032f94,s_glRasterPos4s);
  __qglRasterPos4s = _dllRasterPos4s;
  _dllRasterPos4sv = (*pcVar1)(_DAT_00032f94,s_glRasterPos4sv);
  __qglRasterPos4sv = _dllRasterPos4sv;
  _dllReadBuffer = (*pcVar1)(_DAT_00032f94,s_glReadBuffer);
  __qglReadBuffer = _dllReadBuffer;
  _dllReadPixels = (*pcVar1)(_DAT_00032f94,s_glReadPixels);
  __qglReadPixels = _dllReadPixels;
  _dllRectd = (*pcVar1)(_DAT_00032f94,s_glRectd);
  __qglRectd = _dllRectd;
  _dllRectdv = (*pcVar1)(_DAT_00032f94,s_glRectdv);
  __qglRectdv = _dllRectdv;
  _dllRectf = (*pcVar1)(_DAT_00032f94,s_glRectf);
  __qglRectf = _dllRectf;
  _dllRectfv = (*pcVar1)(_DAT_00032f94,s_glRectfv);
  __qglRectfv = _dllRectfv;
  _dllRecti = (*pcVar1)(_DAT_00032f94,s_glRecti);
  __qglRecti = _dllRecti;
  _dllRectiv = (*pcVar1)(_DAT_00032f94,s_glRectiv);
  __qglRectiv = _dllRectiv;
  _dllRects = (*pcVar1)(_DAT_00032f94,s_glRects);
  __qglRects = _dllRects;
  _dllRectsv = (*pcVar1)(_DAT_00032f94,s_glRectsv);
  __qglRectsv = _dllRectsv;
  __qglRenderMode = (*pcVar1)(_DAT_00032f94,s_glRenderMode);
  __dllRenderMode = __qglRenderMode;
  _dllRotated = (*pcVar1)(_DAT_00032f94,s_glRotated);
  __qglRotated = _dllRotated;
  _dllRotatef = (*pcVar1)(_DAT_00032f94,s_glRotatef);
  __qglRotatef = _dllRotatef;
  _dllScaled = (*pcVar1)(_DAT_00032f94,s_glScaled);
  __qglScaled = _dllScaled;
  _dllScalef = (*pcVar1)(_DAT_00032f94,s_glScalef);
  __qglScalef = _dllScalef;
  _dllScissor = (*pcVar1)(_DAT_00032f94,s_glScissor);
  __qglScissor = _dllScissor;
  _dllSelectBuffer = (*pcVar1)(_DAT_00032f94,s_glSelectBuffer);
  __qglSelectBuffer = _dllSelectBuffer;
  _dllShadeModel = (*pcVar1)(_DAT_00032f94,s_glShadeModel);
  __qglShadeModel = _dllShadeModel;
  _dllStencilFunc = (*pcVar1)(_DAT_00032f94,s_glStencilFunc);
  __qglStencilFunc = _dllStencilFunc;
  _dllStencilMask = (*pcVar1)(_DAT_00032f94,s_glStencilMask);
  __qglStencilMask = _dllStencilMask;
  _dllStencilOp = (*pcVar1)(_DAT_00032f94,s_glStencilOp);
  __qglStencilOp = _dllStencilOp;
  _dllTexCoord1d = (*pcVar1)(_DAT_00032f94,s_glTexCoord1d);
  __qglTexCoord1d = _dllTexCoord1d;
  _dllTexCoord1dv = (*pcVar1)(_DAT_00032f94,s_glTexCoord1dv);
  __qglTexCoord1dv = _dllTexCoord1dv;
  _dllTexCoord1f = (*pcVar1)(_DAT_00032f94,s_glTexCoord1f);
  __qglTexCoord1f = _dllTexCoord1f;
  _dllTexCoord1fv = (*pcVar1)(_DAT_00032f94,s_glTexCoord1fv);
  __qglTexCoord1fv = _dllTexCoord1fv;
  _dllTexCoord1i = (*pcVar1)(_DAT_00032f94,s_glTexCoord1i);
  __qglTexCoord1i = _dllTexCoord1i;
  _dllTexCoord1iv = (*pcVar1)(_DAT_00032f94,s_glTexCoord1iv);
  __qglTexCoord1iv = _dllTexCoord1iv;
  _dllTexCoord1s = (*pcVar1)(_DAT_00032f94,s_glTexCoord1s);
  __qglTexCoord1s = _dllTexCoord1s;
  _dllTexCoord1sv = (*pcVar1)(_DAT_00032f94,s_glTexCoord1sv);
  __qglTexCoord1sv = _dllTexCoord1sv;
  _dllTexCoord2d = (*pcVar1)(_DAT_00032f94,s_glTexCoord2d);
  __qglTexCoord2d = _dllTexCoord2d;
  _dllTexCoord2dv = (*pcVar1)(_DAT_00032f94,s_glTexCoord2dv);
  __qglTexCoord2dv = _dllTexCoord2dv;
  _dllTexCoord2f = (*pcVar1)(_DAT_00032f94,s_glTexCoord2f);
  __qglTexCoord2f = _dllTexCoord2f;
  _dllTexCoord2fv = (*pcVar1)(_DAT_00032f94,s_glTexCoord2fv);
  __qglTexCoord2fv = _dllTexCoord2fv;
  _dllTexCoord2i = (*pcVar1)(_DAT_00032f94,s_glTexCoord2i);
  __qglTexCoord2i = _dllTexCoord2i;
  _dllTexCoord2iv = (*pcVar1)(_DAT_00032f94,s_glTexCoord2iv);
  __qglTexCoord2iv = _dllTexCoord2iv;
  _dllTexCoord2s = (*pcVar1)(_DAT_00032f94,s_glTexCoord2s);
  __qglTexCoord2s = _dllTexCoord2s;
  _dllTexCoord2sv = (*pcVar1)(_DAT_00032f94,s_glTexCoord2sv);
  __qglTexCoord2sv = _dllTexCoord2sv;
  _dllTexCoord3d = (*pcVar1)(_DAT_00032f94,s_glTexCoord3d);
  __qglTexCoord3d = _dllTexCoord3d;
  _dllTexCoord3dv = (*pcVar1)(_DAT_00032f94,s_glTexCoord3dv);
  __qglTexCoord3dv = _dllTexCoord3dv;
  _dllTexCoord3f = (*pcVar1)(_DAT_00032f94,s_glTexCoord3f);
  __qglTexCoord3f = _dllTexCoord3f;
  _dllTexCoord3fv = (*pcVar1)(_DAT_00032f94,s_glTexCoord3fv);
  __qglTexCoord3fv = _dllTexCoord3fv;
  _dllTexCoord3i = (*pcVar1)(_DAT_00032f94,s_glTexCoord3i);
  __qglTexCoord3i = _dllTexCoord3i;
  _dllTexCoord3iv = (*pcVar1)(_DAT_00032f94,s_glTexCoord3iv);
  __qglTexCoord3iv = _dllTexCoord3iv;
  _dllTexCoord3s = (*pcVar1)(_DAT_00032f94,s_glTexCoord3s);
  __qglTexCoord3s = _dllTexCoord3s;
  _dllTexCoord3sv = (*pcVar1)(_DAT_00032f94,s_glTexCoord3sv);
  __qglTexCoord3sv = _dllTexCoord3sv;
  _dllTexCoord4d = (*pcVar1)(_DAT_00032f94,s_glTexCoord4d);
  __qglTexCoord4d = _dllTexCoord4d;
  _dllTexCoord4dv = (*pcVar1)(_DAT_00032f94,s_glTexCoord4dv);
  __qglTexCoord4dv = _dllTexCoord4dv;
  _dllTexCoord4f = (*pcVar1)(_DAT_00032f94,s_glTexCoord4f);
  __qglTexCoord4f = _dllTexCoord4f;
  _dllTexCoord4fv = (*pcVar1)(_DAT_00032f94,s_glTexCoord4fv);
  __qglTexCoord4fv = _dllTexCoord4fv;
  _dllTexCoord4i = (*pcVar1)(_DAT_00032f94,s_glTexCoord4i);
  __qglTexCoord4i = _dllTexCoord4i;
  _dllTexCoord4iv = (*pcVar1)(_DAT_00032f94,s_glTexCoord4iv);
  __qglTexCoord4iv = _dllTexCoord4iv;
  _dllTexCoord4s = (*pcVar1)(_DAT_00032f94,s_glTexCoord4s);
  __qglTexCoord4s = _dllTexCoord4s;
  _dllTexCoord4sv = (*pcVar1)(_DAT_00032f94,s_glTexCoord4sv);
  __qglTexCoord4sv = _dllTexCoord4sv;
  _dllTexCoordPointer = (*pcVar1)(_DAT_00032f94,s_glTexCoordPointer);
  __qglTexCoordPointer = _dllTexCoordPointer;
  _dllTexEnvf = (*pcVar1)(_DAT_00032f94,s_glTexEnvf);
  __qglTexEnvf = _dllTexEnvf;
  _dllTexEnvfv = (*pcVar1)(_DAT_00032f94,s_glTexEnvfv);
  __qglTexEnvfv = _dllTexEnvfv;
  _dllTexEnvi = (*pcVar1)(_DAT_00032f94,s_glTexEnvi);
  __qglTexEnvi = _dllTexEnvi;
  _dllTexEnviv = (*pcVar1)(_DAT_00032f94,s_glTexEnviv);
  __qglTexEnviv = _dllTexEnviv;
  _dllTexGend = (*pcVar1)(_DAT_00032f94,s_glTexGend);
  __qglTexGend = _dllTexGend;
  _dllTexGendv = (*pcVar1)(_DAT_00032f94,s_glTexGendv);
  __qglTexGendv = _dllTexGendv;
  _dllTexGenf = (*pcVar1)(_DAT_00032f94,s_glTexGenf);
  __qglTexGenf = _dllTexGenf;
  _dllTexGenfv = (*pcVar1)(_DAT_00032f94,s_glTexGenfv);
  __qglTexGenfv = _dllTexGenfv;
  _dllTexGeni = (*pcVar1)(_DAT_00032f94,s_glTexGeni);
  __qglTexGeni = _dllTexGeni;
  _dllTexGeniv = (*pcVar1)(_DAT_00032f94,s_glTexGeniv);
  __qglTexGeniv = _dllTexGeniv;
  _dllTexImage1D = (*pcVar1)(_DAT_00032f94,s_glTexImage1D);
  __qglTexImage1D = _dllTexImage1D;
  _dllTexImage2D = (*pcVar1)(_DAT_00032f94,s_glTexImage2D);
  __qglTexImage2D = _dllTexImage2D;
  _dllTexParameterf = (*pcVar1)(_DAT_00032f94,s_glTexParameterf);
  __qglTexParameterf = _dllTexParameterf;
  _dllTexParameterfv = (*pcVar1)(_DAT_00032f94,s_glTexParameterfv);
  __qglTexParameterfv = _dllTexParameterfv;
  _dllTexParameteri = (*pcVar1)(_DAT_00032f94,s_glTexParameteri);
  __qglTexParameteri = _dllTexParameteri;
  _dllTexParameteriv = (*pcVar1)(_DAT_00032f94,s_glTexParameteriv);
  __qglTexParameteriv = _dllTexParameteriv;
  _dllTexSubImage1D = (*pcVar1)(_DAT_00032f94,s_glTexSubImage1D);
  __qglTexSubImage1D = _dllTexSubImage1D;
  _dllTexSubImage2D = (*pcVar1)(_DAT_00032f94,s_glTexSubImage2D);
  __qglTexSubImage2D = _dllTexSubImage2D;
  _dllTranslated = (*pcVar1)(_DAT_00032f94,s_glTranslated);
  __qglTranslated = _dllTranslated;
  _dllTranslatef = (*pcVar1)(_DAT_00032f94,s_glTranslatef);
  __qglTranslatef = _dllTranslatef;
  _dllVertex2d = (*pcVar1)(_DAT_00032f94,s_glVertex2d);
  __qglVertex2d = _dllVertex2d;
  _dllVertex2dv = (*pcVar1)(_DAT_00032f94,s_glVertex2dv);
  __qglVertex2dv = _dllVertex2dv;
  _dllVertex2f = (*pcVar1)(_DAT_00032f94,s_glVertex2f);
  __qglVertex2f = _dllVertex2f;
  _dllVertex2fv = (*pcVar1)(_DAT_00032f94,s_glVertex2fv);
  __qglVertex2fv = _dllVertex2fv;
  _dllVertex2i = (*pcVar1)(_DAT_00032f94,s_glVertex2i);
  __qglVertex2i = _dllVertex2i;
  _dllVertex2iv = (*pcVar1)(_DAT_00032f94,s_glVertex2iv);
  __qglVertex2iv = _dllVertex2iv;
  _dllVertex2s = (*pcVar1)(_DAT_00032f94,s_glVertex2s);
  __qglVertex2s = _dllVertex2s;
  _dllVertex2sv = (*pcVar1)(_DAT_00032f94,s_glVertex2sv);
  __qglVertex2sv = _dllVertex2sv;
  _dllVertex3d = (*pcVar1)(_DAT_00032f94,s_glVertex3d);
  __qglVertex3d = _dllVertex3d;
  _dllVertex3dv = (*pcVar1)(_DAT_00032f94,s_glVertex3dv);
  __qglVertex3dv = _dllVertex3dv;
  _dllVertex3f = (*pcVar1)(_DAT_00032f94,s_glVertex3f);
  __qglVertex3f = _dllVertex3f;
  _dllVertex3fv = (*pcVar1)(_DAT_00032f94,s_glVertex3fv);
  __qglVertex3fv = _dllVertex3fv;
  _dllVertex3i = (*pcVar1)(_DAT_00032f94,s_glVertex3i);
  __qglVertex3i = _dllVertex3i;
  _dllVertex3iv = (*pcVar1)(_DAT_00032f94,s_glVertex3iv);
  __qglVertex3iv = _dllVertex3iv;
  _dllVertex3s = (*pcVar1)(_DAT_00032f94,s_glVertex3s);
  __qglVertex3s = _dllVertex3s;
  _dllVertex3sv = (*pcVar1)(_DAT_00032f94,s_glVertex3sv);
  __qglVertex3sv = _dllVertex3sv;
  _dllVertex4d = (*pcVar1)(_DAT_00032f94,s_glVertex4d);
  __qglVertex4d = _dllVertex4d;
  _dllVertex4dv = (*pcVar1)(_DAT_00032f94,s_glVertex4dv);
  __qglVertex4dv = _dllVertex4dv;
  _dllVertex4f = (*pcVar1)(_DAT_00032f94,s_glVertex4f);
  __qglVertex4f = _dllVertex4f;
  _dllVertex4fv = (*pcVar1)(_DAT_00032f94,s_glVertex4fv);
  __qglVertex4fv = _dllVertex4fv;
  _dllVertex4i = (*pcVar1)(_DAT_00032f94,s_glVertex4i);
  __qglVertex4i = _dllVertex4i;
  _dllVertex4iv = (*pcVar1)(_DAT_00032f94,s_glVertex4iv);
  __qglVertex4iv = _dllVertex4iv;
  _dllVertex4s = (*pcVar1)(_DAT_00032f94,s_glVertex4s);
  __qglVertex4s = _dllVertex4s;
  _dllVertex4sv = (*pcVar1)(_DAT_00032f94,s_glVertex4sv);
  __qglVertex4sv = _dllVertex4sv;
  _dllVertexPointer = (*pcVar1)(_DAT_00032f94,s_glVertexPointer);
  __qglVertexPointer = _dllVertexPointer;
  _dllViewport = (*pcVar1)(_DAT_00032f94,s_glViewport);
  __qglViewport = _dllViewport;
  __qwglCopyContext = (*pcVar1)(_DAT_00032f94,s_wglCopyContext);
  __qwglCreateContext = (*pcVar1)(_DAT_00032f94,s_wglCreateContext);
  __qwglCreateLayerContext = (*pcVar1)(_DAT_00032f94,s_wglCreateLayerContext);
  __qwglDeleteContext = (*pcVar1)(_DAT_00032f94,s_wglDeleteContext);
  __qwglDescribeLayerPlane = (*pcVar1)(_DAT_00032f94,s_wglDescribeLayerPlane);
  __qwglGetCurrentContext = (*pcVar1)(_DAT_00032f94,s_wglGetCurrentContext);
  __qwglGetCurrentDC = (*pcVar1)(_DAT_00032f94,s_wglGetCurrentDC);
  __qwglGetLayerPaletteEntries = (*pcVar1)(_DAT_00032f94,s_wglGetLayerPaletteEntries);
  __qwglGetProcAddress = (*pcVar1)(_DAT_00032f94,s_wglGetProcAddress);
  __qwglMakeCurrent = (*pcVar1)(_DAT_00032f94,s_wglMakeCurrent);
  __qwglRealizeLayerPalette = (*pcVar1)(_DAT_00032f94,s_wglRealizeLayerPalette);
  __qwglSetLayerPaletteEntries = (*pcVar1)(_DAT_00032f94,s_wglSetLayerPaletteEntries);
  __qwglShareLists = (*pcVar1)(_DAT_00032f94,s_wglShareLists);
  __qwglSwapLayerBuffers = (*pcVar1)(_DAT_00032f94,s_wglSwapLayerBuffers);
  __qwglUseFontBitmaps = (*pcVar1)(_DAT_00032f94,s_wglUseFontBitmapsA);
  __qwglUseFontOutlines = (*pcVar1)(_DAT_00032f94,s_wglUseFontOutlinesA);
  __qwglChoosePixelFormat = (*pcVar1)(_DAT_00032f94,s_wglChoosePixelFormat);
  __qwglDescribePixelFormat = (*pcVar1)(_DAT_00032f94,s_wglDescribePixelFormat);
  __qwglGetPixelFormat = (*pcVar1)(_DAT_00032f94,s_wglGetPixelFormat);
  __qwglSetPixelFormat = (*pcVar1)(_DAT_00032f94,s_wglSetPixelFormat);
  __qwglSwapBuffers = (*pcVar1)(_DAT_00032f94,s_wglSwapBuffers);
  __qwglSwapIntervalEXT = 0;
  __qglActiveTextureARB = 0;
  __qglClientActiveTextureARB = 0;
  __qglMultiTexCoord2fARB = 0;
  __qglLockArraysEXT = 0;
  __qglUnlockArraysEXT = 0;
  __qwglGetDeviceGammaRamp3DFX = 0;
  __qwglSetDeviceGammaRamp3DFX = 0;
  _QGL_EnableLogging(*(undefined4 *)(__r_logFile + 0x20));
  return 1;
}



