// ===========================================
// Function: _R_DrawStripElements @ 0000b092
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DrawStripElements(int param_1)

{
  bool bVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *unaff_EDI;
  int iVar5;
  int iVar6;
  
  (*__qglBegin)(5);
  __c_begins = __c_begins + 1;
  if (param_1 < 1) {
    return;
  }
  (*unaff_EDI)(*in_EAX);
  (*unaff_EDI)(in_EAX[1]);
  (*unaff_EDI)(in_EAX[2]);
  iVar5 = in_EAX[1];
  __c_vertexes = __c_vertexes + 3;
  iVar6 = *in_EAX;
  iVar2 = in_EAX[2];
  bVar1 = false;
  if (3 < param_1) {
    piVar4 = in_EAX + 5;
    iVar3 = (param_1 - 4U) / 3 + 1;
    do {
      if (bVar1) {
        if ((iVar2 != piVar4[-1]) || (iVar6 != piVar4[-2])) {
          (*__qglEnd)();
          (*__qglBegin)(5);
          __c_begins = __c_begins + 1;
          (*unaff_EDI)(piVar4[-2]);
          (*unaff_EDI)(piVar4[-1]);
          iVar5 = *piVar4;
          goto LAB_0000b180;
        }
        (*unaff_EDI)(*piVar4);
        __c_vertexes = __c_vertexes + 1;
LAB_0000b189:
        bVar1 = false;
      }
      else {
        if ((piVar4[-2] != iVar2) || (piVar4[-1] != iVar5)) {
          (*__qglEnd)();
          (*__qglBegin)(5);
          __c_begins = __c_begins + 1;
          (*unaff_EDI)(piVar4[-2]);
          (*unaff_EDI)(piVar4[-1]);
          iVar5 = *piVar4;
LAB_0000b180:
          (*unaff_EDI)(iVar5);
          __c_vertexes = __c_vertexes + 3;
          goto LAB_0000b189;
        }
        (*unaff_EDI)(*piVar4);
        bVar1 = true;
        __c_vertexes = __c_vertexes + 1;
      }
      iVar6 = piVar4[-2];
      iVar5 = piVar4[-1];
      iVar2 = *piVar4;
      piVar4 = piVar4 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
                    /* WARNING: Could not recover jumptable at 0x0000b1ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*__qglEnd)();
  return;
}



// ===========================================
// Function: _R_DrawElements @ 0000b1b9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _R_DrawElements(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(__r_primitives + 0x20);
  if (iVar1 == 0) {
    if (__qglLockArraysEXT == 0) {
      _R_DrawStripElements(param_2);
      return;
    }
  }
  else if (iVar1 != 2) {
    if (iVar1 == 1) {
      _R_DrawStripElements(param_2);
      return;
    }
    if (iVar1 == 3) {
      _R_DrawStripElements(param_2);
    }
    return;
  }
  (*__qglDrawElements)(4,param_2,0x1405);
  return;
}



// ===========================================
// Function: _R_BindAnimatedImage @ 0000b221
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _R_BindAnimatedImage(float param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  if ((int)unaff_ESI[0x40] < 2) {
    _GL_Bind(*unaff_ESI,param_1);
    return;
  }
  if (unaff_ESI[0x4d] == 0) {
    param_1 = (float)unaff_ESI[0x41] * __qglEnableClientState * (float)___real_4090000000000000;
    iVar1 = _myftol(param_1);
    iVar1 = iVar1 >> 10;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = (int)*(short *)(_DAT_0000e680 + 0x5e);
  }
  if ((*(byte *)(unaff_ESI + 0x4e) & 1) == 0) {
    iVar1 = iVar1 % (int)unaff_ESI[0x40];
  }
  else if ((int)unaff_ESI[0x40] <= iVar1) {
    _GL_Bind(unaff_ESI[unaff_ESI[0x40] + -1],param_1);
    return;
  }
  _GL_Bind(unaff_ESI[iVar1],param_1);
  return;
}



// ===========================================
// Function: _DrawTris @ 0000b2b8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawTris(void)

{
  int unaff_ESI;
  int unaff_EDI;
  float *pfStack_bc;
  float *pfStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  float fStack_a8;
  undefined4 uStack_a4;
  float fStack_a0;
  undefined8 uStack_9c;
  undefined8 uStack_94;
  float afStack_8c [5];
  float fStack_78;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  
  afStack_8c[2] = (float)_DAT_0000e204;
  afStack_8c[1] = 6.41402e-41;
  _GL_Bind();
  afStack_8c[2] = 1.0;
  afStack_8c[1] = 1.0;
  afStack_8c[0] = 1.0;
  uStack_94 = CONCAT44(0xb2e1,(float)uStack_94);
  (*__qglColor3f)();
  if (unaff_EDI == 1) {
    uStack_94 = 0x2000000b2f0;
    _GL_State();
  }
  else {
    uStack_94 = 0x3000000b2ff;
    _GL_State();
    uStack_94 = 0;
    uStack_9c = 0;
    fStack_a0 = 6.42369e-41;
    (*__qglDepthRange)();
    if (2 < unaff_EDI) goto LAB_0000b388;
  }
  uStack_94._4_4_ = &DAT_00008076;
  uStack_94._0_4_ = 6.42593e-41;
  (*__qglDisableClientState)();
  uStack_94 = CONCAT44(uStack_94._4_4_,&DAT_00008078);
  uStack_9c = CONCAT44(0xb32c,(float)uStack_9c);
  (*__qglDisableClientState)();
  uStack_9c = CONCAT44(unaff_ESI + 720000,0x10);
  fStack_a0 = 7.18306e-42;
  uStack_a4 = 3;
  fStack_a8 = 6.43056e-41;
  (*__qglVertexPointer)();
  if (__qglLockArraysEXT != (code *)0x0) {
    uStack_94 = (ulonglong)*(uint *)(unaff_ESI + 0x317054) << 0x20;
    uStack_9c = CONCAT44(0xb356,(float)uStack_9c);
    (*__qglLockArraysEXT)();
    uStack_9c = 0xad2f0000b360;
    _GLimp_LogComment();
  }
  uStack_94 = CONCAT44(0xb370,(float)uStack_94);
  _R_DrawElements();
  if (__qglUnlockArraysEXT != (code *)0x0) {
    uStack_94 = CONCAT44(0xb37b,(float)uStack_94);
    (*__qglUnlockArraysEXT)();
    uStack_94 = 0xad1c0000b385;
    _GLimp_LogComment();
  }
LAB_0000b388:
  if (1 < unaff_EDI) {
    uStack_5c = 0;
    uStack_60 = 0;
    uStack_64 = 0;
    uStack_50 = 0;
    uStack_54 = 0;
    uStack_58 = 0;
    uStack_94 = 0x3000000b3b5;
    _GL_State();
    uStack_94 = 0;
    uStack_9c = 0;
    fStack_a0 = 6.4492e-41;
    (*__qglDepthRange)();
    fStack_a0 = 4.97881e-42;
    uStack_a4 = 0xb3d2;
    (*__qglDisable)();
    uStack_a4 = 1;
    fStack_a8 = 6.45186e-41;
    (*__qglBegin)();
    fStack_a8 = 1.0;
    uStack_ac = 0;
    fStack_b0 = 0.0;
    uStack_b4 = 0x3f800000;
    pfStack_b8 = (float *)0xb3f6;
    (*__qglColor4f)();
    pfStack_b8 = afStack_8c;
    afStack_8c[2] = afStack_8c[2] - (float)___real_4014000000000000;
    fStack_78 = (float)___real_4014000000000000 + fStack_78;
    pfStack_bc = (float *)0xb41b;
    (*__qglVertex3fv)();
    pfStack_bc = afStack_8c + 2;
    (*__qglVertex3fv)();
    afStack_8c[0] = afStack_8c[0] + (float)___real_4014000000000000;
    afStack_8c[3] = afStack_8c[3] - (float)___real_4014000000000000;
    (*__qglColor4f)(0,0x3f800000,0,0x3f800000);
    fStack_a0 = fStack_a0 - (float)___real_4014000000000000;
    uStack_94 = CONCAT44(uStack_94._4_4_,(float)___real_4014000000000000 + (float)uStack_94);
    (*__qglVertex3fv)(&uStack_a4);
    (*__qglVertex3fv)(&uStack_9c);
    fStack_a8 = fStack_a8 + (float)___real_4014000000000000;
    uStack_9c = CONCAT44(uStack_9c._4_4_,(float)uStack_9c - (float)___real_4014000000000000);
    (*__qglColor4f)(0,0,0x3f800000,0x3f800000);
    pfStack_bc = (float *)((float)pfStack_bc - (float)___real_4014000000000000);
    fStack_b0 = (float)___real_4014000000000000 + fStack_b0;
    (*__qglVertex3fv)(&pfStack_bc);
    (*__qglVertex3fv)(&uStack_b4);
    pfStack_b8 = (float *)((float)pfStack_b8 - (float)___real_4014000000000000);
    (*__qglEnd)();
    (*__qglEnable)(0xde1);
    (*__qglDepthRange)(0,0x3ff0000000000000);
  }
  return;
}



// ===========================================
// Function: _DrawNormals @ 0000b537
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _DrawNormals(void)

{
  undefined4 unaff_ESI;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar5;
  undefined8 uVar4;
  int iStack_c;
  int iStack_4;
  
  _GL_Bind();
  (*__qglColor3f)(0x3f800000);
  if (iStack_4 == 0) {
    _GL_State();
    (*__qglDepthRange)(0,0);
  }
  else {
    _GL_State();
  }
  uVar5 = 1;
  (*__qglBegin)();
  iVar2 = 0;
  if (0 < *(int *)(iStack_c + 0x317054)) {
    uVar4 = CONCAT44(uVar5,unaff_ESI);
    iVar1 = iStack_c + 720000;
    do {
      iVar3 = iVar1;
      (*__qglVertex3fv)();
      (*__qglVertex3fv)(&stack0xffffffe0,iVar3,uVar4);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar2 < *(int *)(iStack_c + 0x317054));
  }
  (*__qglEnd)();
  if (iStack_4 == 0) {
    (*__qglDepthRange)(0,0x3ff0000000000000);
  }
  return;
}



// ===========================================
// Function: _RB_GLFogStageIteratorFunc @ 0000b625
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_GLFogStageIteratorFunc(void)

{
  __qglDrawElements = __qglDrawElements | 0x8000;
  (**(code **)(_DAT_00325128 + 0x20c))();
  __qglDrawElements = __qglDrawElements & 0xffff7fff;
  return;
}



// ===========================================
// Function: _DrawMultitextured @ 0000b647
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _DrawMultitextured(int param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_EBX;
  undefined4 uVar3;
  undefined *puVar4;
  
  iVar1 = *(int *)(*(int *)(unaff_EBX + 0x317060) + param_1 * 4);
  _GL_State(*(undefined4 *)(iVar1 + 0x2b4));
  (*__qglTexCoordPointer)(2,0x1406,0,unaff_EBX + 0x2673c0);
  _R_BindAnimatedImage();
  if ((*(uint *)(iVar1 + 0x2b4) & 0x4000) != 0) {
    __qglBegin = *(uint *)(iVar1 + 0x280) & 3;
    _DAT_0000e134 = 0x4000;
    uVar2 = *(uint *)(iVar1 + 0x280) & 3;
    if (uVar2 == 1) {
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008571,
                      ___real_46040000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008580,
                      ___real_4704c000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008590,
                      ___real_44400000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008581,
                      ___real_4704c100);
      puVar4 = &DAT_00008591;
      uVar3 = ___real_44400000;
    }
    else {
      if (uVar2 != 2) {
        (*__ri)(3,s_Unknown_MT_mode_for___s_,*(undefined4 *)(unaff_EBX + 0x317040));
        goto LAB_0000b833;
      }
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008571,
                      ___real_43820000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008580,
                      ___real_4704c000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008590,
                      ___real_44400000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008581,0);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008591,
                      ___real_44404000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008582,
                      ___real_4704c100);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008592,
                      ___real_44400000);
      (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008583,0);
      puVar4 = &DAT_00008593;
      uVar3 = ___real_44404000;
    }
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,puVar4,uVar3);
  }
LAB_0000b833:
  _GL_SelectTexture(1);
  (*__qglEnableClientState)(&DAT_00008078);
  if ((*(uint *)(iVar1 + 0x2b4) & 0x4000) == 0) {
    if ((*(int *)(__r_lightmap + 0x20) == 0) || (*(int *)(iVar1 + 0x270) == 0)) {
      uVar2 = *(uint *)(iVar1 + 0x280) & 3;
      if (uVar2 == 1) {
        puVar4 = &DAT_00002100;
      }
      else {
        if (uVar2 != 2) {
          (*__ri)(3,s_Unknown_MT_mode_for___s_,*(undefined4 *)(unaff_EBX + 0x317040));
          goto LAB_0000b976;
        }
        puVar4 = (undefined *)0x104;
      }
    }
    else {
      puVar4 = (undefined *)0x1e01;
    }
    _GL_TexEnv(puVar4);
  }
  else {
    _DAT_0000e134 = 0x4000;
    _GL_TexEnv(&DAT_00008570);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008571,
                    ___real_47057500);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008580,
                    ___real_47057700);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008590,
                    ___real_44400000);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008581,
                    ___real_47057800);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008591,
                    ___real_44400000);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008582,
                    ___real_47057700);
    (*__qglTexEnvf)(s__O2__Ob2__Ic__Alice1_src_common___000021ea + 0x116,&DAT_00008592,
                    ___real_44408000);
  }
LAB_0000b976:
  (*__qglTexCoordPointer)(2,0x1406,0,unaff_EBX + 0x2a1d40);
  _R_BindAnimatedImage();
  _R_DrawElements();
  (*__qglDisable)(0xde1);
  (*__qglDisableClientState)(&DAT_00008078);
  _GL_SelectTexture(0);
  return;
}



// ===========================================
// Function: _ProjectDlightTexture @ 0000b9c7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ProjectDlightTexture(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined1 uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined1 *puVar22;
  float *pfVar23;
  undefined4 uVar24;
  float *local_40;
  int local_3c;
  int local_38;
  
  if ((_DAT_0000e2f4 == 0) || (local_3c = 0, _DAT_0000e2f4 < 1)) {
    return;
  }
  fVar17 = (float)___real_406fe00000000000;
  fVar15 = (float)___real_3fe0000000000000;
  local_38 = 0;
  iVar19 = _DAT_00325138;
  do {
    if ((_DAT_00325130 & 1 << ((byte)local_3c & 0x1f)) != 0) {
      fVar1 = *(float *)(local_38 + 0x20 + __RB_CalcTurbulentTexCoords);
      iVar21 = local_38 + __RB_CalcTurbulentTexCoords;
      iVar20 = 0;
      fVar2 = *(float *)(iVar21 + 0x24);
      fVar3 = *(float *)(iVar21 + 0x28);
      local_40 = (float *)&_texCoordsArray;
      fVar4 = *(float *)(iVar21 + 0x18);
      fVar14 = (float)___real_3fe8000000000000 / fVar4;
      fVar5 = *(float *)(iVar21 + 0xc);
      fVar6 = *(float *)(iVar21 + 0x10);
      fVar7 = *(float *)(iVar21 + 0x14);
      if (0 < _DAT_0032513c) {
        puVar22 = &DAT_0000e0f2;
        pfVar23 = (float *)&DAT_0013306c;
        do {
          fVar8 = pfVar23[-1];
          _DAT_0000e668 = _DAT_0000e668 + 1;
          fVar9 = *pfVar23;
          fVar10 = pfVar23[1];
          fVar11 = ABS(fVar8);
          fVar12 = ABS(fVar9);
          if (fVar12 < fVar11 == (NAN(fVar12) || NAN(fVar11))) {
            iVar19 = 1;
            if (ABS(fVar10) < fVar12 == (NAN(ABS(fVar10)) || NAN(fVar12))) goto LAB_0000baee;
          }
          else if (ABS(fVar10) < fVar11 == (NAN(ABS(fVar10)) || NAN(fVar11))) {
LAB_0000baee:
            iVar19 = 2;
          }
          else {
            iVar19 = 0;
          }
          fVar11 = fVar1 - pfVar23[-0x1d4c1];
          fVar12 = fVar2 - pfVar23[-120000];
          fVar13 = fVar3 - pfVar23[-119999];
          fVar16 = fVar13;
          if (iVar19 == 0) {
            *local_40 = fVar12 * fVar14 + fVar15;
          }
          else {
            *local_40 = fVar11 * fVar14 + fVar15;
            if (iVar19 != 1) {
              fVar16 = fVar12;
            }
          }
          local_40[1] = fVar16 * fVar14 + fVar15;
          fVar8 = fVar13 * fVar10 + fVar11 * fVar8 + fVar9 * fVar12;
          if (fVar8 <= fVar4) {
            if (-fVar4 <= fVar8) {
              if (fVar8 < 0.0) {
                fVar8 = -fVar8;
              }
              fVar15 = (fVar4 - fVar8) * (float)___real_3ff5555560000000 * fVar14;
              uVar18 = _myftol(fVar15 * fVar5 * fVar17);
              puVar22[-2] = uVar18;
              uVar18 = _myftol(fVar15 * fVar6 * fVar17);
              puVar22[-1] = uVar18;
              uVar18 = _myftol(fVar15 * fVar7 * fVar17);
              fVar15 = (float)___real_3fe0000000000000;
              *puVar22 = uVar18;
            }
            else {
              puVar22[-2] = 0;
              puVar22[-1] = 0;
              *puVar22 = 0;
            }
          }
          else {
            puVar22[-2] = 0;
            puVar22[-1] = 0;
            *puVar22 = 0;
          }
          puVar22[1] = 0xff;
          iVar20 = iVar20 + 1;
          local_40 = local_40 + 2;
          pfVar23 = pfVar23 + 4;
          puVar22 = puVar22 + 4;
          iVar19 = _DAT_00325138;
        } while (iVar20 < _DAT_0032513c);
      }
      iVar20 = 0;
      if (0 < iVar19) {
        do {
          *(undefined4 *)(&_hitIndexes + iVar20 * 4) = *(undefined4 *)(&_tess + iVar20 * 4);
          *(undefined4 *)(&DAT_0000e0e4 + iVar20 * 4) = *(undefined4 *)(&DAT_0000e0ec + iVar20 * 4);
          *(undefined4 *)(&_tess + iVar20 * 4) = *(undefined4 *)(&_colorArray + iVar20 * 4);
          iVar20 = iVar20 + 3;
        } while (iVar20 < iVar19);
        if (iVar20 != 0) {
          (*__qglEnableClientState)(&DAT_00008078);
          (*__qglTexCoordPointer)(2,0x1406,0,&_texCoordsArray);
          (*__qglEnableClientState)(&DAT_00008076);
          (*__qglColorPointer)(4,0x1401,0,&_colorArray);
          _GL_Bind(_DAT_0000e1fc);
          if ((*(byte *)(iVar21 + 0x1c) & 4) == 0) {
            uVar24 = 0x823;
          }
          else {
            uVar24 = 0x824;
          }
          _GL_State(uVar24);
          iVar19 = *(int *)(__r_primitives + 0x20);
          if (iVar19 == 0) {
            if (__qglLockArraysEXT == 0) {
LAB_0000bd57:
              _R_DrawStripElements(iVar20);
            }
            else {
LAB_0000bd2b:
              (*__qglDrawElements)(4,iVar20,0x1405,&_hitIndexes);
            }
          }
          else {
            if (iVar19 == 2) goto LAB_0000bd2b;
            if ((iVar19 == 1) || (iVar19 == 3)) goto LAB_0000bd57;
          }
          _DAT_0000e65c = _DAT_0000e65c + iVar20;
          fVar15 = (float)___real_3fe0000000000000;
          _DAT_0000e66c = _DAT_0000e66c + iVar20;
          iVar19 = _DAT_00325138;
        }
      }
    }
    local_3c = local_3c + 1;
    local_38 = local_38 + 0x2c;
    if (_DAT_0000e2f4 <= local_3c) {
      return;
    }
    fVar17 = (float)___real_406fe00000000000;
  } while( true );
}



// ===========================================
// Function: _ComputeColors @ 0000bdaa
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ComputeColors(int param_1)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  undefined1 uStack_4;
  
  fVar2 = _DAT_0000eb84;
  switch(*(undefined4 *)(param_1 + 0x298)) {
  case 1:
    _memset(&DAT_00257fe8,0xff,_DAT_0032513c * 4);
    break;
  case 2:
    _memset(&DAT_00257fe8,_DAT_0000eb88,_DAT_0032513c * 4);
    break;
  case 3:
    _RB_CalcColorFromEntity(&DAT_00257fe8);
    break;
  case 4:
    _RB_CalcColorFromOneMinusEntity(&DAT_00257fe8);
    break;
  case 5:
_LN117:
    _memcpy(&DAT_00257fe8,&DAT_0021d668,_DAT_0032513c * 4);
    break;
  case 6:
    if (_DAT_00325154 != 0) {
      if (NAN(_DAT_0000eb84) == (_DAT_0000eb84 == 1.0)) {
        iVar3 = 0;
        if (0 < _DAT_0032513c) {
          do {
            iVar4 = iVar3 * 4;
            bVar1 = (&DAT_0021d669)[iVar3 * 4];
            iVar3 = iVar3 + 1;
            *(char *)(iVar3 * 4 + 0x257fe4) =
                 (char)(int)ROUND((float)(byte)(&DAT_0021d668)[iVar4] * fVar2);
            *(char *)(iVar3 * 4 + 0x257fe5) = (char)(int)ROUND((float)bVar1 * fVar2);
            *(char *)(iVar3 * 4 + 0x257fe6) =
                 (char)(int)ROUND((float)*(byte *)(iVar3 * 4 + 0x21d666) * fVar2);
          } while (iVar3 < _DAT_0032513c);
        }
        goto _LN136;
      }
      goto _LN117;
    }
    (*__ri)(3,s_Vertex_color_specified_for_shade,_DAT_00325128);
    break;
  case 7:
    if (NAN(_DAT_0000eb84) == (_DAT_0000eb84 == 1.0)) {
      iVar3 = 0;
      if (0 < _DAT_0032513c) {
        do {
          iVar4 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *(char *)(iVar3 * 4 + 0x257fe4) =
               (char)(int)ROUND((float)(int)(0xff - (uint)(byte)(&DAT_0021d668)[iVar4]) * fVar2);
          *(char *)(iVar3 * 4 + 0x257fe5) =
               (char)(int)ROUND((float)(int)(0xff - (uint)*(byte *)(iVar3 * 4 + 0x21d665)) * fVar2);
          *(char *)(iVar3 * 4 + 0x257fe6) =
               (char)(int)ROUND((float)(int)(0xff - (uint)*(byte *)(iVar3 * 4 + 0x21d666)) * fVar2);
        } while (iVar3 < _DAT_0032513c);
      }
      goto _LN136;
    }
    iVar3 = 0;
    if (0 < _DAT_0032513c) {
      do {
        (&DAT_00257fe8)[iVar3 * 4] = -1 - (&DAT_0021d668)[iVar3 * 4];
        (&DAT_00257fe9)[iVar3 * 4] = -1 - (&DAT_0021d669)[iVar3 * 4];
        (&DAT_00257fea)[iVar3 * 4] = -1 - (&DAT_0021d66a)[iVar3 * 4];
        iVar3 = iVar3 + 1;
      } while (iVar3 < _DAT_0032513c);
    }
    break;
  case 8:
    _RB_CalcWaveColor(param_1 + 0x284,&DAT_00257fe8,0);
    break;
  case 9:
    _RB_CalcWaveColor(param_1 + 0x284,&DAT_00257fe8,param_1 + 0x2e4);
    break;
  case 10:
    if (_DAT_0000e90c != (code *)0x0) {
      (*_DAT_0000e90c)(&DAT_00257fe8);
    }
    break;
  case 0xb:
    iVar6 = _DAT_0032512c * 0x5c;
    iVar3 = *(int *)(__GL_SelectTexture + 0xb8);
    iVar4 = 0;
    if (0 < _DAT_0032513c) {
      do {
        *(undefined4 *)(&DAT_00257fe8 + iVar4 * 4) = *(undefined4 *)(iVar6 + iVar3 + 0x1c);
        iVar4 = iVar4 + 1;
      } while (iVar4 < _DAT_0032513c);
    }
    break;
  case 0xc:
    _RB_CalcColorFromConstant(&DAT_00257fe8,param_1 + 0x2e4);
    break;
  default:
_LN136:
    break;
  case 0xe:
  case 0x10:
    _RB_CalcAlphaFogBlend(&DAT_00257fe8);
    break;
  case 0xf:
    _RB_CalcColorFromConstant(&DAT_00257fe8,0xe918);
  }
  switch(*(undefined4 *)(param_1 + 0x2b0)) {
  case 0:
    iVar3 = *(int *)(param_1 + 0x298);
    if ((((iVar3 != 1) && (iVar3 != 10)) &&
        ((iVar3 != 6 || (NAN(_DAT_0000eb84) == (_DAT_0000eb84 == 1.0))))) &&
       (iVar3 = 0, 0 < _DAT_0032513c)) {
      do {
        (&DAT_00257feb)[iVar3 * 4] = 0xff;
        iVar3 = iVar3 + 1;
      } while (iVar3 < _DAT_0032513c);
    }
    break;
  case 2:
    _RB_CalcAlphaFromEntity(&DAT_00257fe8);
    break;
  case 3:
    _RB_CalcAlphaFromOneMinusEntity(&DAT_00257fe8);
    break;
  case 4:
    iVar3 = 0;
    if (0 < _DAT_0032513c) {
      do {
        (&DAT_00257feb)[iVar3 * 4] = (&DAT_0021d66b)[iVar3 * 4];
        iVar3 = iVar3 + 1;
      } while (iVar3 < _DAT_0032513c);
    }
    break;
  case 6:
    _RB_CalcSpecularAlpha(&DAT_00257fe8,*(undefined4 *)(param_1 + 0x2d4),param_1 + 0x2d8);
    break;
  case 7:
    _RB_CalcWaveAlpha(param_1 + 0x29c,&DAT_00257fe8);
    break;
  case 8:
    iVar3 = 0;
    if (0 < _DAT_0032513c) {
      do {
        fVar7 = (float10)_VectorLength(&stack0x00000000);
        fVar2 = (float)fVar7 / *(float *)(_DAT_00325128 + 0xac);
        if (fVar2 < 0.0 == NAN(fVar2)) {
          if (1.0 < fVar2 == NAN(fVar2)) {
            uStack_4 = (undefined1)(int)ROUND(fVar2 * (float)___real_406fe00000000000);
          }
          else {
            uStack_4 = 0xff;
          }
        }
        else {
          uStack_4 = 0;
        }
        (&DAT_00257feb)[iVar3 * 4] = uStack_4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < _DAT_0032513c);
    }
    break;
  case 0xd:
    _RB_CalcAlphaFromDot
              (&DAT_00257fe8,*(undefined4 *)(param_1 + 0x2d0),*(undefined4 *)(param_1 + 0x2d4));
    break;
  case 0xe:
    _RB_CalcAlphaFromOneMinusDot
              (&DAT_00257fe8,*(undefined4 *)(param_1 + 0x2d0),*(undefined4 *)(param_1 + 0x2d4));
    break;
  case 0xf:
    uVar5 = (uint)*(byte *)(param_1 + 0x2e7);
    goto LAB_0000c439;
  case 0x10:
    uVar5 = (uint)DAT_0000e91b;
    goto LAB_0000c439;
  case 0x13:
    uVar5 = (int)ROUND(_DAT_0000ee74 * (float)___real_406fe00000000000) & 0xff;
    goto LAB_0000c439;
  case 0x14:
    uVar5 = (int)ROUND((1.0 - _DAT_0000ee74) * (float)___real_406fe00000000000) & 0xff;
LAB_0000c439:
    _RB_CalcAlphaFromConstant(&DAT_00257fe8,uVar5);
  }
  iVar3 = *(int *)(param_1 + 0x2b8);
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 4) == 0) {
      if (iVar3 == 1) {
        _RB_CalcModulateColorsByFog();
        return;
      }
      if (iVar3 == 2) {
        _RB_CalcModulateRGBAsByFog();
        return;
      }
      if (iVar3 == 3) {
        _RB_CalcModulateAlphasByFog();
        return;
      }
    }
    else {
      if (iVar3 == 1) {
        _RB_CalcModulateColorsByFog_Alpha();
        return;
      }
      if (iVar3 == 2) {
        _RB_CalcModulateRGBAsByFog_Alpha();
        return;
      }
      if (iVar3 == 3) {
        _RB_CalcModulateAlphasByFog_Alpha();
        return;
      }
    }
    (*_DAT_0000e1fc)(1,s_ComputeColors___invalid_adjustCo,iVar3);
  }
  return;
}



// ===========================================
// Function: _ComputeTexCoords @ 0000c58a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ComputeTexCoords(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 *__s;
  
  iVar8 = 0;
  __s = &DAT_002754a8;
  puVar9 = (undefined4 *)(param_1 + 0x110);
  do {
    if (puVar9[-0x42] == 0) {
      return;
    }
    switch(*puVar9) {
    case 1:
      _memset(__s,0,_DAT_0032513c * 8);
      break;
    case 2:
      iVar7 = 0;
      if (0 < _DAT_0032513c) {
        puVar5 = (undefined4 *)&DAT_001a8374;
        puVar2 = (undefined4 *)(__s + 4);
        do {
          iVar7 = iVar7 + 1;
          puVar2[-1] = puVar5[-1];
          uVar1 = *puVar5;
          puVar5 = puVar5 + 4;
          *puVar2 = uVar1;
          puVar2 = puVar2 + 2;
        } while (iVar7 < _DAT_0032513c);
      }
      break;
    case 3:
      iVar7 = 0;
      if (0 < _DAT_0032513c) {
        puVar5 = (undefined4 *)&DAT_001a836c;
        puVar2 = (undefined4 *)(__s + 4);
        do {
          iVar7 = iVar7 + 1;
          puVar2[-1] = puVar5[-1];
          uVar1 = *puVar5;
          puVar5 = puVar5 + 4;
          *puVar2 = uVar1;
          puVar2 = puVar2 + 2;
        } while (iVar7 < _DAT_0032513c);
      }
      break;
    case 4:
      _RB_CalcEnvironmentTexCoords(__s);
      break;
    case 5:
      _RB_CalcFogTexCoords(__s);
      break;
    case 6:
      iVar7 = 0;
      if (0 < _DAT_0032513c) {
        pfVar3 = (float *)&DAT_000bdd68;
        pfVar6 = (float *)(__s + 4);
        do {
          iVar7 = iVar7 + 1;
          pfVar6[-1] = pfVar3[2] * (float)puVar9[3] +
                       (float)puVar9[1] * *pfVar3 + pfVar3[1] * (float)puVar9[2];
          *pfVar6 = (float)puVar9[6] * pfVar3[2] +
                    *pfVar3 * (float)puVar9[4] + (float)puVar9[5] * pfVar3[1];
          pfVar3 = pfVar3 + 4;
          pfVar6 = pfVar6 + 2;
        } while (iVar7 < _DAT_0032513c);
      }
      break;
    default:
      (*__ri)(1,s_WARNING__invalid_tcGen___d__spec,*(undefined4 *)(param_1 + 0x110 + iVar8 * 0x13c),
              _DAT_00325128);
      return;
    }
    iVar7 = 0;
    if (0 < (int)puVar9[7]) {
      do {
        iVar4 = puVar9[8] + iVar7 * 0x4c;
        switch(*(undefined4 *)(puVar9[8] + iVar7 * 0x4c)) {
        case 0:
          iVar7 = 4;
          break;
        case 1:
          _RB_CalcTransformTexCoords(iVar4,__s);
          break;
        case 2:
          _RB_CalcTurbulentTexCoords(iVar4 + 4,__s);
          break;
        case 3:
          _RB_CalcScrollTexCoords(iVar4 + 0x40,__s);
          break;
        case 4:
          _RB_CalcScaleTexCoords(iVar4 + 0x30,__s);
          break;
        case 5:
          _RB_CalcStretchTexCoords(iVar4 + 4,__s);
          break;
        case 6:
          _RB_CalcRotateTexCoords(*(undefined4 *)(iVar4 + 0x48),__s);
          break;
        case 7:
          _RB_CalcScrollTexCoords(_DAT_0000e680 + 0xc0,__s);
          break;
        case 9:
          _RB_CalcOffsetTexCoords(iVar4 + 0x40,__s);
          break;
        case 10:
          _RB_CalcParallaxTexCoords(iVar4 + 0x38,__s);
          break;
        case 0xb:
          _RB_CalcMacroTexCoords(iVar4 + 0x30,__s);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)puVar9[7]);
    }
    __s = __s + 240000;
    iVar8 = iVar8 + 1;
    puVar9 = puVar9 + 0x4f;
  } while ((int)__s < 0x2ea7a8);
  return;
}



// ===========================================
// Function: _RB_IterateStagesGeneric @ 0000c83e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_IterateStagesGeneric(void)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  
  iVar3 = 0;
  fVar2 = _DAT_0000ee74;
  do {
    iVar1 = *(int *)(_DAT_00325148 + iVar3 * 4);
    if (iVar1 == 0) {
      return;
    }
    if ((((*(int *)(iVar1 + 0x2c0) == 0) || (*(int *)(__r_detailTextures + 0x20) != 0)) &&
        ((*(int *)(iVar1 + 0x2b0) != 0x13 || (___real_3c23d70a <= fVar2)))) &&
       ((*(int *)(iVar1 + 0x2b0) != 0x14 || (fVar2 <= (float)___real_3fefae1480000000)))) {
      _ComputeColors(iVar1);
      _ComputeTexCoords(iVar1);
      if (_setArraysOnce == 0) {
        (*__qglEnableClientState)(&DAT_00008076);
        (*__qglColorPointer)(4,0x1401,0,in_EAX + 2400000);
      }
      if (*(int *)(iVar1 + 0x144) == 0) {
        if (_setArraysOnce == 0) {
          (*__qglTexCoordPointer)(2,0x1406,0,in_EAX + 0x2673c0);
        }
        if ((*(int *)(iVar1 + 0x138) == 0) ||
           (((*(int *)(__r_vertexLight + 0x20) == 0 && (_DAT_0000f730 != 4)) ||
            (*(int *)(__r_lightmap + 0x20) == 0)))) {
          _R_BindAnimatedImage();
        }
        else {
          _GL_Bind(_DAT_0000e204);
        }
        _GL_State(-(uint)(_DAT_0000e914 != 0) & 0x400 | *(uint *)(iVar1 + 0x2b4));
        _R_DrawElements();
      }
      else {
        _DrawMultitextured();
      }
      fVar2 = _DAT_0000ee74;
      if (*(int *)(__r_lightmap + 0x20) != 0) {
        if (*(int *)(iVar1 + 0x134) != 0) {
          return;
        }
        if (*(int *)(iVar1 + 0x270) != 0) {
          return;
        }
        if (*(int *)(iVar1 + 0x138) != 0) {
          return;
        }
      }
    }
    iVar3 = iVar3 + 1;
    if (7 < iVar3) {
      return;
    }
  } while( true );
}



// ===========================================
// Function: _RB_StageIteratorGeneric @ 0000c9c4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StageIteratorGeneric(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  _RB_DeformTessGeometry();
  if (_DAT_0032512c != (undefined *)0x0) {
    if (_DAT_0032512c == &DAT_0000270f) {
      bVar1 = *(byte *)(_DAT_00325128 + 0x204) & 4;
    }
    else {
      bVar1 = *(byte *)(_DAT_00325128 + 0x204) & 2;
    }
    if (bVar1 != 0) {
      _RB_CalcAlphaFogDensities();
    }
  }
  if (*(int *)(__r_logFile + 0x20) != 0) {
    uVar2 = _va(s_____RB_StageIteratorGeneric___s_,_DAT_00325128);
    _GLimp_LogComment(uVar2);
  }
  _GL_Cull(*(undefined4 *)(_DAT_00325128 + 0xb4));
  if (*(int *)(_DAT_00325128 + 0xb8) != 0) {
    (*__qglEnable)(&DAT_00008037);
    (*__qglPolygonOffset)
              (*(undefined4 *)(__r_offsetFactor + 0x1c),*(undefined4 *)(__r_offsetUnits + 0x1c));
  }
  if ((_DAT_00325140 < 2) && ((*_DAT_00325148 == 0 || (*(int *)(*_DAT_00325148 + 0x280) == 0)))) {
    _setArraysOnce = 1;
    (*__qglEnableClientState)(&DAT_00008076);
    (*__qglColorPointer)(4,0x1401,0,&DAT_00257fe8);
    (*__qglEnableClientState)(&DAT_00008078);
    (*__qglTexCoordPointer)(2,0x1406,0,&DAT_002754a8);
  }
  else {
    _setArraysOnce = 0;
    (*__qglDisableClientState)(&DAT_00008076);
    (*__qglDisableClientState)(&DAT_00008078);
  }
  (*__qglVertexPointer)(3,0x1406,0x10,&DAT_000bdd68);
  if (__qglLockArraysEXT != (code *)0x0) {
    (*__qglLockArraysEXT)(0,_DAT_0032513c);
    _GLimp_LogComment(s_glLockArraysEXT_);
  }
  if (_setArraysOnce == 0) {
    (*__qglEnableClientState)(&DAT_00008078);
    (*__qglEnableClientState)(&DAT_00008076);
  }
  _RB_IterateStagesGeneric();
  if (((_DAT_00325130 != 0) && (_DAT_00325134 == 0)) &&
     (*(float *)(_DAT_00325128 + 0x4c) <= ___real_40800000)) {
    _ProjectDlightTexture();
  }
  if (__qglUnlockArraysEXT != (code *)0x0) {
    (*__qglUnlockArraysEXT)();
    _GLimp_LogComment(s_glUnlockArraysEXT_);
  }
  if (*(int *)(_DAT_00325128 + 0xb8) != 0) {
    (*__qglDisable)(&DAT_00008037);
  }
  return;
}



// ===========================================
// Function: _RB_StageIteratorVertexLitTextureUnfogged @ 0000cbb5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StageIteratorVertexLitTextureUnfogged(void)

{
  undefined4 uVar1;
  
  if (_DAT_0000e90c == (code *)0x0) {
    _RB_CalcDiffuseColor(&DAT_00257fe8);
  }
  else {
    (*_DAT_0000e90c)();
  }
  if (*(int *)(__r_logFile + 0x20) != 0) {
    uVar1 = _va(s_____RB_StageIteratorVertexLitTex,_DAT_00325128);
    _GLimp_LogComment(uVar1);
  }
  _GL_Cull(*(undefined4 *)(_DAT_00325128 + 0xb4));
  (*__qglEnableClientState)(&DAT_00008076);
  (*__qglEnableClientState)(&DAT_00008078);
  (*__qglColorPointer)(4,0x1401,0,&DAT_00257fe8);
  (*__qglTexCoordPointer)(2,0x1406,0x10,&DAT_001a8368);
  (*__qglVertexPointer)(3,0x1406,0x10,&DAT_000bdd68);
  if (__qglLockArraysEXT != (code *)0x0) {
    (*__qglLockArraysEXT)(0,_DAT_0032513c);
    _GLimp_LogComment(s_glLockArraysEXT_);
  }
  _R_BindAnimatedImage();
  _GL_State(*(undefined4 *)(*_DAT_00325148 + 0x2b4));
  _R_DrawElements();
  if (((_DAT_00325130 != 0) && (_DAT_00325134 == 0)) &&
     (*(float *)(_DAT_00325128 + 0x4c) <= ___real_40800000)) {
    _ProjectDlightTexture();
  }
  if (__qglUnlockArraysEXT != (code *)0x0) {
    (*__qglUnlockArraysEXT)();
    _GLimp_LogComment(s_glUnlockArraysEXT_);
  }
  return;
}



// ===========================================
// Function: _RB_StageIteratorLightmappedMultitextureUnfogged @ 0000ccf7
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StageIteratorLightmappedMultitextureUnfogged(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (*(int *)(__r_logFile + 0x20) != 0) {
    uVar1 = _va(s_____RB_StageIteratorLightmappedM,_DAT_00325128);
    _GLimp_LogComment(uVar1);
  }
  _GL_Cull(*(undefined4 *)(_DAT_00325128 + 0xb4));
  _GL_State(0x100);
  (*__qglVertexPointer)(3,0x1406,0x10,&DAT_000bdd68);
  (*__qglEnableClientState)(&DAT_00008076);
  (*__qglColorPointer)(4,0x1401,0,0x2ea7a8);
  _GL_SelectTexture(0);
  (*__qglEnableClientState)(&DAT_00008078);
  _R_BindAnimatedImage();
  (*__qglTexCoordPointer)(2,0x1406,0x10,&DAT_001a8368);
  _GL_SelectTexture(1);
  (*__qglEnable)(0xde1);
  if (*(int *)(__r_lightmap + 0x20) == 0) {
    puVar2 = &DAT_00002100;
  }
  else {
    puVar2 = (undefined *)0x1e01;
  }
  _GL_TexEnv(puVar2);
  _R_BindAnimatedImage();
  (*__qglEnableClientState)(&DAT_00008078);
  (*__qglTexCoordPointer)(2,0x1406,0x10,&DAT_001a8370);
  if (__qglLockArraysEXT != (code *)0x0) {
    (*__qglLockArraysEXT)(0,_DAT_0032513c);
    _GLimp_LogComment(s_glLockArraysEXT_);
  }
  _R_DrawElements();
  (*__qglDisable)(0xde1);
  (*__qglDisableClientState)(&DAT_00008078);
  _GL_SelectTexture(0);
  if (((_DAT_00325130 != 0) && (_DAT_00325134 == 0)) &&
     (*(float *)(_DAT_00325128 + 0x4c) <= ___real_40800000)) {
    _ProjectDlightTexture();
  }
  if (__qglUnlockArraysEXT != (code *)0x0) {
    (*__qglUnlockArraysEXT)();
    _GLimp_LogComment(s_glUnlockArraysEXT_);
  }
  return;
}



// ===========================================
// Function: _RB_EndSurface @ 0000cea4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _RB_EndSurface(undefined4 param_1)

{
  if (_DAT_00325138 != 0) {
    if (_DAT_000bdd64 != 0) {
      (*_DAT_0000e1fc)(1,s_RB_EndSurface_____SHADER_MAX_IND,param_1);
    }
    if (NAN(_DAT_00133058) == (_DAT_00133058 == 0.0)) {
      (*_DAT_0000e1fc)(1,s_RB_EndSurface_____SHADER_MAX_VER);
    }
    if (_DAT_00325128 == __RB_CalcModulateColorsByFog) {
      _RB_ShadowTessEnd();
      return;
    }
    if ((*(int *)(__r_debugSort + 0x20) == 0) ||
       (*(float *)(_DAT_00325128 + 0x4c) <= (float)*(int *)(__r_debugSort + 0x20))) {
      _DAT_0000e650 = _DAT_0000e650 + 1;
      _DAT_0000e654 = _DAT_0000e654 + _DAT_0032513c;
      _DAT_0000e658 = _DAT_0000e658 + _DAT_00325138;
      _DAT_0000e65c = _DAT_0000e65c + _DAT_00325140 * _DAT_00325138;
      (*_DAT_00325144)();
      if (((DAT_0000ed14 & 1) == 0) && (_DAT_0000e914 == 0)) {
        if (*(int *)(__r_showtris + 0x20) != 0) {
          _DrawTris();
        }
        if (*(int *)(__r_shownormals + 0x20) != 0) {
          _DrawNormals(&_tess,1 < *(int *)(__r_shownormals + 0x20));
        }
      }
      _DAT_00325138 = 0;
      _GLimp_LogComment(s____________);
    }
  }
  return;
}



// ===========================================
// Function: _RB_BeginSurface @ 0000cfbc
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_BeginSurface(int param_1,undefined *param_2)

{
  _DAT_00325138 = 0;
  _DAT_0032513c = 0;
  _DAT_00325128 = param_1;
  _DAT_00325130 = 0;
  if ((*(int *)(__r_vertexLight + 0x20) != 0) || (_DAT_00325154 = 0, _DAT_0000f730 == 4)) {
    _DAT_00325154 = 1;
  }
  if ((((_DAT_0000e5b4 == 0) || (_DAT_00325150 != 0)) ||
      ((*(int *)(param_1 + 100) != 0 && (_DAT_0000e5b8 == 0)))) ||
     (_DAT_0032512c = &DAT_0000270f, _DAT_0000e914 != 0)) {
    _DAT_0032512c = param_2;
  }
  if (_DAT_0032512c == &DAT_0000270f) {
    if ((*(int *)(param_1 + 0x200) != 0) && (*(int *)(__r_useglfog + 0x20) != 0)) {
      _DAT_00325148 = param_1 + 0x194;
      _DAT_00325140 = *(undefined4 *)(param_1 + 400);
      _DAT_00325144 = _RB_GLFogStageIteratorFunc;
      return;
    }
    _DAT_00325148 = param_1 + 0x1dc;
    _DAT_00325140 = *(undefined4 *)(param_1 + 0x1d8);
  }
  else {
    if (_DAT_0032512c == (undefined *)0x0) {
      _DAT_00325148 = param_1 + 0x194;
      _DAT_00325140 = *(undefined4 *)(param_1 + 400);
      _DAT_00325144 = (code *)*(undefined4 *)(param_1 + 0x20c);
      return;
    }
    _DAT_00325148 = param_1 + 0x1b8;
    _DAT_00325140 = *(undefined4 *)(param_1 + 0x1b4);
  }
  if (*(int *)(param_1 + 100) == 0) {
    _DAT_00325144 = _RB_StageIteratorGeneric;
    return;
  }
  _DAT_00325144 = (code *)*(undefined4 *)(param_1 + 0x20c);
  return;
}



