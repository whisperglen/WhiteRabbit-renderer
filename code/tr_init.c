// ===========================================
// Function: _AssertCvarRange @ 0000dd00
// ===========================================

void _AssertCvarRange(float param_1,float param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  char *pcVar3;
  double dVar4;
  
  if (param_3 != 0) {
    iVar1 = __ftol2_sse();
    if (iVar1 != unaff_ESI[8]) {
      (*_ri.Printf)(3,s_WARNING__cvar___s__must_be_integ,*unaff_ESI,(double)(float)unaff_ESI[7]);
      uVar2 = va(s__d,unaff_ESI[8]);
      (*_ri.field10_0x28)(*unaff_ESI,uVar2);
    }
  }
  if ((float)unaff_ESI[7] < param_1) {
    (*_ri.Printf)(3,s_WARNING__cvar___s__out_of_range_,*unaff_ESI,(double)(float)unaff_ESI[7],
                  (double)param_1);
    dVar4 = (double)param_1;
    pcVar3 = s__f;
    uVar2 = va();
    (*_ri.field10_0x28)(*unaff_ESI,uVar2,pcVar3,dVar4);
    return;
  }
  if (param_2 < (float)unaff_ESI[7] != (NAN(param_2) || NAN((float)unaff_ESI[7]))) {
    (*_ri.Printf)(3,s_WARNING__cvar___s__out_of_range_,*unaff_ESI,(double)(float)unaff_ESI[7],
                  (double)param_2);
    dVar4 = (double)param_2;
    pcVar3 = s__f;
    uVar2 = va();
    (*_ri.field10_0x28)(*unaff_ESI,uVar2,pcVar3,dVar4);
    return;
  }
  return;
}



// ===========================================
// Function: _GL_CheckErrors @ 0000ddef
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_CheckErrors(void)

{
  undefined2 uVar1;
  void *pvVar2;
  char acStack_40 [4];
  char acStack_3c [4];
  char acStack_38 [4];
  char acStack_34 [4];
  char acStack_30 [2];
  char cStack_2e;
  char cStack_2d;
  char cStack_2c;
  
  pvVar2 = (*_ri.field8_0x20)();
  if ((pvVar2 != (void *)0x0) && (*(int *)(__r_ignoreGLErrors + 0x20) == 0)) {
    uVar1 = _cStack_2e;
    switch(pvVar2) {
    case (void *)0x500:
      acStack_40[0] = s_GL_INVALID_ENUM[0];
      acStack_40[1] = s_GL_INVALID_ENUM[1];
      acStack_40[2] = s_GL_INVALID_ENUM[2];
      acStack_40[3] = s_GL_INVALID_ENUM[3];
      acStack_3c[0] = s_GL_INVALID_ENUM[4];
      acStack_3c[1] = s_GL_INVALID_ENUM[5];
      acStack_3c[2] = s_GL_INVALID_ENUM[6];
      acStack_3c[3] = s_GL_INVALID_ENUM[7];
      acStack_38[0] = s_GL_INVALID_ENUM[8];
      acStack_38[1] = s_GL_INVALID_ENUM[9];
      acStack_38[2] = s_GL_INVALID_ENUM[10];
      acStack_38[3] = s_GL_INVALID_ENUM[0xb];
      acStack_34[0] = s_GL_INVALID_ENUM[0xc];
      acStack_34[1] = s_GL_INVALID_ENUM[0xd];
      acStack_34[2] = s_GL_INVALID_ENUM[0xe];
      acStack_34[3] = s_GL_INVALID_ENUM[0xf];
      break;
    case (void *)0x501:
      acStack_40[0] = s_GL_INVALID_VALUE[0];
      acStack_40[1] = s_GL_INVALID_VALUE[1];
      acStack_40[2] = s_GL_INVALID_VALUE[2];
      acStack_40[3] = s_GL_INVALID_VALUE[3];
      acStack_3c[0] = s_GL_INVALID_VALUE[4];
      acStack_3c[1] = s_GL_INVALID_VALUE[5];
      acStack_3c[2] = s_GL_INVALID_VALUE[6];
      acStack_3c[3] = s_GL_INVALID_VALUE[7];
      acStack_38[0] = s_GL_INVALID_VALUE[8];
      acStack_38[1] = s_GL_INVALID_VALUE[9];
      acStack_38[2] = s_GL_INVALID_VALUE[10];
      acStack_38[3] = s_GL_INVALID_VALUE[0xb];
      acStack_34[0] = s_GL_INVALID_VALUE[0xc];
      acStack_34[1] = s_GL_INVALID_VALUE[0xd];
      acStack_34[2] = s_GL_INVALID_VALUE[0xe];
      acStack_34[3] = s_GL_INVALID_VALUE[0xf];
      acStack_30[0] = s_GL_INVALID_VALUE[0x10];
      break;
    case (void *)0x502:
      acStack_40[0] = s_GL_INVALID_OPERATION[0];
      acStack_40[1] = s_GL_INVALID_OPERATION[1];
      acStack_40[2] = s_GL_INVALID_OPERATION[2];
      acStack_40[3] = s_GL_INVALID_OPERATION[3];
      acStack_3c[0] = s_GL_INVALID_OPERATION[4];
      acStack_3c[1] = s_GL_INVALID_OPERATION[5];
      acStack_3c[2] = s_GL_INVALID_OPERATION[6];
      acStack_3c[3] = s_GL_INVALID_OPERATION[7];
      acStack_38[0] = s_GL_INVALID_OPERATION[8];
      acStack_38[1] = s_GL_INVALID_OPERATION[9];
      acStack_38[2] = s_GL_INVALID_OPERATION[10];
      acStack_38[3] = s_GL_INVALID_OPERATION[0xb];
      acStack_34[0] = s_GL_INVALID_OPERATION[0xc];
      acStack_34[1] = s_GL_INVALID_OPERATION[0xd];
      acStack_34[2] = s_GL_INVALID_OPERATION[0xe];
      acStack_34[3] = s_GL_INVALID_OPERATION[0xf];
      acStack_30[0] = s_GL_INVALID_OPERATION[0x10];
      acStack_30[1] = s_GL_INVALID_OPERATION[0x11];
      cStack_2e = s_GL_INVALID_OPERATION[0x12];
      cStack_2d = s_GL_INVALID_OPERATION[0x13];
      cStack_2c = s_GL_INVALID_OPERATION[0x14];
      break;
    case (void *)0x503:
      acStack_40[0] = s_GL_STACK_OVERFLOW[0];
      acStack_40[1] = s_GL_STACK_OVERFLOW[1];
      acStack_40[2] = s_GL_STACK_OVERFLOW[2];
      acStack_40[3] = s_GL_STACK_OVERFLOW[3];
      acStack_3c[0] = s_GL_STACK_OVERFLOW[4];
      acStack_3c[1] = s_GL_STACK_OVERFLOW[5];
      acStack_3c[2] = s_GL_STACK_OVERFLOW[6];
      acStack_3c[3] = s_GL_STACK_OVERFLOW[7];
      acStack_38[0] = s_GL_STACK_OVERFLOW[8];
      acStack_38[1] = s_GL_STACK_OVERFLOW[9];
      acStack_38[2] = s_GL_STACK_OVERFLOW[10];
      acStack_38[3] = s_GL_STACK_OVERFLOW[0xb];
      acStack_34[0] = s_GL_STACK_OVERFLOW[0xc];
      acStack_34[1] = s_GL_STACK_OVERFLOW[0xd];
      acStack_34[2] = s_GL_STACK_OVERFLOW[0xe];
      acStack_34[3] = s_GL_STACK_OVERFLOW[0xf];
      acStack_30[0] = s_GL_STACK_OVERFLOW[0x10];
      acStack_30[1] = s_GL_STACK_OVERFLOW[0x11];
      _acStack_30 = CONCAT22(uVar1,acStack_30);
      break;
    case (void *)0x504:
      acStack_40[0] = s_GL_STACK_UNDERFLOW[0];
      acStack_40[1] = s_GL_STACK_UNDERFLOW[1];
      acStack_40[2] = s_GL_STACK_UNDERFLOW[2];
      acStack_40[3] = s_GL_STACK_UNDERFLOW[3];
      acStack_3c[0] = s_GL_STACK_UNDERFLOW[4];
      acStack_3c[1] = s_GL_STACK_UNDERFLOW[5];
      acStack_3c[2] = s_GL_STACK_UNDERFLOW[6];
      acStack_3c[3] = s_GL_STACK_UNDERFLOW[7];
      acStack_38[0] = s_GL_STACK_UNDERFLOW[8];
      acStack_38[1] = s_GL_STACK_UNDERFLOW[9];
      acStack_38[2] = s_GL_STACK_UNDERFLOW[10];
      acStack_38[3] = s_GL_STACK_UNDERFLOW[0xb];
      acStack_34[0] = s_GL_STACK_UNDERFLOW[0xc];
      acStack_34[1] = s_GL_STACK_UNDERFLOW[0xd];
      acStack_34[2] = s_GL_STACK_UNDERFLOW[0xe];
      acStack_34[3] = s_GL_STACK_UNDERFLOW[0xf];
      cStack_2e = s_GL_STACK_UNDERFLOW[0x12];
      acStack_30[0] = s_GL_STACK_UNDERFLOW[0x10];
      acStack_30[1] = s_GL_STACK_UNDERFLOW[0x11];
      break;
    case (void *)0x505:
      acStack_40[0] = s_GL_OUT_OF_MEMORY[0];
      acStack_40[1] = s_GL_OUT_OF_MEMORY[1];
      acStack_40[2] = s_GL_OUT_OF_MEMORY[2];
      acStack_40[3] = s_GL_OUT_OF_MEMORY[3];
      acStack_3c[0] = s_GL_OUT_OF_MEMORY[4];
      acStack_3c[1] = s_GL_OUT_OF_MEMORY[5];
      acStack_3c[2] = s_GL_OUT_OF_MEMORY[6];
      acStack_3c[3] = s_GL_OUT_OF_MEMORY[7];
      acStack_38[0] = s_GL_OUT_OF_MEMORY[8];
      acStack_38[1] = s_GL_OUT_OF_MEMORY[9];
      acStack_38[2] = s_GL_OUT_OF_MEMORY[10];
      acStack_38[3] = s_GL_OUT_OF_MEMORY[0xb];
      acStack_34[0] = s_GL_OUT_OF_MEMORY[0xc];
      acStack_34[1] = s_GL_OUT_OF_MEMORY[0xd];
      acStack_34[2] = s_GL_OUT_OF_MEMORY[0xe];
      acStack_34[3] = s_GL_OUT_OF_MEMORY[0xf];
      acStack_30[0] = s_GL_OUT_OF_MEMORY[0x10];
      break;
    default:
      func_0x000117a0(acStack_40,0x40,s__i,pvVar2);
    }
    (*_ri.Error)(0,s_GL_CheckErrors___s,acStack_40);
  }
  return;
}



// ===========================================
// Function: _R_GetModeInfo @ 0000dfaf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _R_GetModeInfo(undefined4 *param_1,undefined4 *param_2,float *param_3,int param_4)

{
  if ((-2 < param_4) && (param_4 < _s_numVidModes)) {
    if (param_4 == -1) {
      *param_1 = *(undefined4 *)(__r_customwidth + 0x20);
      *param_2 = *(undefined4 *)(__r_customheight + 0x20);
      *param_3 = *(float *)(__r_customaspect + 0x1c);
      return 1;
    }
    param_4 = param_4 * 0x10;
    *param_1 = *(undefined4 *)(&DAT_00003104 + param_4);
    *param_2 = *(undefined4 *)(&DAT_00003108 + param_4);
    *param_3 = (float)*(int *)(&DAT_00003104 + param_4) /
               (*(float *)(&DAT_0000310c + param_4) * (float)*(int *)(&DAT_00003108 + param_4));
    return 1;
  }
  return 0;
}



// ===========================================
// Function: _R_TakeScreenshot @ 0000e080
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_TakeScreenshot(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_EBP;
  int unaff_ESI;
  
  puVar3 = (undefined4 *)(*_ri.field5_0x14)((_DAT_00012830 * _DAT_0001282c + 6) * 3);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  *(undefined2 *)(puVar3 + 4) = 0;
  *(char *)((int)puVar3 + 0xe) = (char)param_4;
  *(char *)((int)puVar3 + 0xd) = (char)((uint)param_3 >> 8);
  *(undefined1 *)((int)puVar3 + 2) = 2;
  *(char *)(puVar3 + 3) = (char)param_3;
  *(char *)((int)puVar3 + 0xf) = (char)((uint)param_4 >> 8);
  *(undefined1 *)(puVar3 + 4) = 0x18;
  (*_ri.field14_0x38)(param_1,param_2,param_3,param_4,0x1907,0x1401,(int)puVar3 + 0x12);
  iVar2 = (param_3 * unaff_ESI + 6) * 3;
  if (0x12 < iVar2) {
    puVar4 = puVar3 + 5;
    iVar5 = (iVar2 - 0x13U) / 3 + 1;
    do {
      uVar1 = *(undefined1 *)((int)puVar4 + -2);
      *(undefined1 *)((int)puVar4 + -2) = *(undefined1 *)puVar4;
      *(undefined1 *)puVar4 = uVar1;
      puVar4 = (undefined4 *)((int)puVar4 + 3);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if ((0 < _DAT_0001217c) && (_DAT_0001281c != 0)) {
    func_0x000117b0((int)puVar3 + 0x12,_DAT_00012830 * _DAT_0001282c * 3);
  }
  (*_ri.field26_0x68)(unaff_EBP,puVar3,iVar2);
  (*_ri.field6_0x18)(puVar3);
  return;
}



// ===========================================
// Function: _R_ScreenshotFilename @ 0000e17a
// ===========================================

void _R_ScreenshotFilename(undefined *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 < &DAT_00002710) {
    iVar1 = ((int)param_1 % 1000) % 100;
    _Com_sprintf(param_2,0x104,s_screenshots_shot_i_i_i_i_tga,(int)param_1 / 1000,
                 ((int)param_1 % 1000) / 100,iVar1 / 10,iVar1 % 10);
    return;
  }
  _Com_sprintf(param_2,0x104,s_screenshots_shot9999_tga);
  return;
}



// ===========================================
// Function: _R_SepiaScreenShot @ 0000e209
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SepiaScreenShot(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined1 uVar16;
  int iVar17;
  undefined4 *puStack_34;
  int iStack_2c;
  int iStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 uStack_18;
  int iStack_14;
  int iStack_10;
  
  pvVar5 = (*_ri.field5_0x14)(_DAT_00012830 * _DAT_0001282c * 3);
  puVar6 = (undefined4 *)(*_ri.field5_0x14)((param_2 * param_3 + 6) * 3);
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  puVar6[3] = 0;
  *(undefined2 *)(puVar6 + 4) = 0;
  *(char *)(puVar6 + 3) = (char)param_2;
  *(undefined1 *)((int)puVar6 + 2) = 2;
  *(char *)((int)puVar6 + 0xd) = (char)((uint)param_2 >> 8);
  *(char *)((int)puVar6 + 0xe) = (char)param_3;
  *(char *)((int)puVar6 + 0xf) = (char)((uint)param_3 >> 8);
  *(undefined1 *)(puVar6 + 4) = 0x18;
  (*_ri.field14_0x38)(0,0,_DAT_0001282c,_DAT_00012830,0x1907,0x1401,pvVar5);
  if (0 < param_3) {
    puVar10 = puVar6 + 5;
    iStack_2c = param_3;
    do {
      iVar15 = 0;
      puStack_34 = puVar10;
      if (0 < iStack_14) {
        do {
          iVar12 = 0;
          iVar11 = 0;
          iVar14 = 0;
          iVar17 = 3;
          do {
            iVar7 = func_0x00011798();
            iVar7 = iVar7 * _DAT_0001282c;
            iVar13 = 4;
            do {
              iVar8 = func_0x00011798();
              iVar8 = iVar8 + iVar7;
              iVar1 = iStack_28 + iVar8 * 2;
              iVar9 = iVar1 + iVar8;
              iVar14 = iVar14 + (uint)*(byte *)(iVar9 + 1);
              iVar12 = iVar12 + (uint)*(byte *)(iVar1 + iVar8);
              iVar11 = iVar11 + (uint)*(byte *)(iVar9 + 2);
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          if ((iVar11 < iVar12) && (iVar14 < iVar12)) {
            fVar2 = (float)(iVar12 / 0xc);
          }
          else if ((iVar12 < iVar11) && (iVar14 < iVar11)) {
            fVar2 = (float)(iVar11 / 0xc);
          }
          else {
            fVar2 = (float)(iVar14 / 0xc);
          }
          uVar16 = (undefined1)(int)ROUND(fVar2);
          *(undefined1 *)((int)puStack_34 + -2) = uVar16;
          *(undefined1 *)((int)puStack_34 + -1) = uVar16;
          *(undefined1 *)puStack_34 = uVar16;
          iVar15 = iVar15 + 1;
          param_3 = iStack_10;
          puVar6 = puStack_24;
          puStack_34 = (undefined4 *)((int)puStack_34 + 3);
        } while (iVar15 < iStack_14);
      }
      dVar4 = ___real_4004666660000000;
      dVar3 = ___real_406fe00000000000;
      fVar2 = ___real_40233333;
      puVar10 = (undefined4 *)((int)puVar10 + iStack_14 * 3);
      iStack_2c = iStack_2c + -1;
    } while (iStack_2c != 0);
    if (0 < param_3) {
      iVar15 = (int)puVar6 + 0x12;
      do {
        iVar14 = iVar15;
        iVar17 = iStack_14;
        if (0 < iStack_14) {
          do {
            iVar11 = 0;
            do {
              if ((double)*(byte *)(iVar14 + iVar11) * dVar4 <= dVar3) {
                puStack_24._0_1_ = (undefined1)(int)ROUND((float)*(byte *)(iVar14 + iVar11) * fVar2)
                ;
                *(undefined1 *)(iVar14 + iVar11) = puStack_24._0_1_;
              }
              else {
                *(undefined1 *)(iVar14 + iVar11) = 0xff;
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < 3);
            iVar17 = iVar17 + -1;
            iVar14 = iVar14 + 3;
          } while (iVar17 != 0);
        }
        iVar15 = iVar15 + iStack_14 * 3;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  (*_ri.field26_0x68)(uStack_18,puVar6,uStack_20);
  (*_ri.field6_0x18)(puVar6);
  (*_ri.field6_0x18)(iStack_28);
  return;
}



// ===========================================
// Function: _R_ResampledScreenShot @ 0000e535
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ResampledScreenShot(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  int iStack_34;
  void *pvStack_30;
  int iStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_20;
  undefined4 uStack_18;
  
  pvVar2 = (*_ri.field5_0x14)(_DAT_00012830 * _DAT_0001282c * 3);
  iVar10 = param_2 * param_3;
  puVar3 = (undefined4 *)(*_ri.field5_0x14)(iVar10 * 3 + 0x12);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  *(undefined2 *)(puVar3 + 4) = 0;
  *(char *)(puVar3 + 3) = (char)param_2;
  *(undefined1 *)((int)puVar3 + 2) = 2;
  *(char *)((int)puVar3 + 0xd) = (char)((uint)param_2 >> 8);
  *(char *)((int)puVar3 + 0xe) = (char)param_3;
  *(char *)((int)puVar3 + 0xf) = (char)((uint)param_3 >> 8);
  *(undefined1 *)(puVar3 + 4) = 0x18;
  (*_ri.field14_0x38)(0,0,_DAT_0001282c,_DAT_00012830,0x1907,0x1401,pvVar2);
  pvVar9 = pvVar2;
  if (0 < param_3) {
    pcVar6 = (char *)(puVar3 + 5);
    iStack_34 = param_3;
    do {
      iVar12 = 0;
      pcVar14 = pcVar6;
      if (0 < (int)pvVar2) {
        do {
          iVar7 = 0;
          iVar8 = 0;
          iVar11 = 0;
          iVar10 = 3;
          do {
            iVar4 = func_0x00011798();
            iVar4 = iVar4 * _DAT_0001282c;
            iVar13 = 4;
            do {
              iVar5 = func_0x00011798();
              iVar5 = iVar5 + iVar4;
              iVar1 = iVar5 * 3;
              iVar8 = iVar8 + (uint)*(byte *)((int)pvStack_30 + iVar1 + 1);
              iVar11 = iVar11 + (uint)*(byte *)((int)pvStack_30 + iVar5 * 3);
              iVar7 = iVar7 + (uint)*(byte *)((int)pvStack_30 + iVar1 + 2);
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          pcVar14[-2] = ((char)(iVar7 / 0xc) + (char)(iVar7 >> 0x1f)) -
                        (char)((longlong)iVar7 * 0x2aaaaaab >> 0x3f);
          pcVar14[-1] = ((char)(iVar8 / 0xc) + (char)(iVar8 >> 0x1f)) -
                        (char)((longlong)iVar8 * 0x2aaaaaab >> 0x3f);
          *pcVar14 = ((char)(iVar11 / 0xc) + (char)(iVar11 >> 0x1f)) -
                     (char)((longlong)iVar11 * 0x2aaaaaab >> 0x3f);
          iVar12 = iVar12 + 1;
          puVar3 = puStack_28;
          iVar10 = iStack_2c;
          pcVar14 = pcVar14 + 3;
        } while (iVar12 < (int)pvVar2);
      }
      pcVar6 = pcVar6 + (int)pvVar2 * 3;
      iStack_34 = iStack_34 + -1;
      pvVar9 = pvStack_30;
    } while (iStack_34 != 0);
  }
  if ((0 < _DAT_0001217c) && (_DAT_0001281c != 0)) {
    func_0x000117b0((int)puVar3 + 0x12,iVar10 * 3);
  }
  (*_ri.field26_0x68)(uStack_18,puVar3,uStack_20);
  (*_ri.field6_0x18)(puVar3);
  (*_ri.field6_0x18)(pvVar9);
  return;
}



// ===========================================
// Function: _R_LevelShot @ 0000e793
// ===========================================

void _R_LevelShot(void)

{
  code *pcVar1;
  char local_104 [8];
  undefined1 local_fc [252];
  
  pcVar1 = _ri.field20_0x50 + 0x40;
  _sprintf(local_104,s_levelshots__s_tga);
  _R_ResampledScreenShot(local_fc,0x80,0x80,pcVar1);
  (*_ri.Printf)(0,s_Wrote__s_,local_fc);
  return;
}



// ===========================================
// Function: _R_ScreenShot_f @ 0000e7de
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_ScreenShot_f(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  bool bVar8;
  undefined1 auStack_144 [64];
  undefined1 auStack_104 [260];
  
  pcVar7 = s_levelshot;
  pbVar2 = (byte *)(*_ri.field14_0x38)(1);
  do {
    bVar1 = *pbVar2;
    bVar8 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_0000e815:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0000e81a;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar8 = bVar1 < ((byte *)pcVar7)[1];
    if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0000e815;
    pbVar2 = pbVar2 + 2;
    pcVar7 = (char *)((byte *)pcVar7 + 2);
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0000e81a:
  if (iVar3 == 0) {
    _R_LevelShot();
    return;
  }
  pcVar7 = s_silent;
  pbVar2 = (byte *)(*_ri.field14_0x38)(1);
  do {
    bVar1 = *pbVar2;
    bVar8 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_0000e85e:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_0000e863;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar8 = bVar1 < ((byte *)pcVar7)[1];
    if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0000e85e;
    pbVar2 = pbVar2 + 2;
    pcVar7 = (char *)((byte *)pcVar7 + 2);
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0000e863:
  pvVar4 = (*_ri.field13_0x34)();
  if (((int)pvVar4 < 2) || (iVar3 == 0)) {
    if (`R_ScreenShot_f'::__l2::lastNumber == (undefined *)0xffffffff) {
      `R_ScreenShot_f'::__l2::lastNumber = (undefined *)0x0;
      do {
        _R_ScreenshotFilename(`R_ScreenShot_f'::__l2::lastNumber,auStack_104);
        pvVar4 = (*_ri.field22_0x58)(auStack_104,0);
        if ((int)pvVar4 < 1) break;
        `R_ScreenShot_f'::__l2::lastNumber = `R_ScreenShot_f'::__l2::lastNumber + 1;
      } while ((int)`R_ScreenShot_f'::__l2::lastNumber < 10000);
    }
    else {
      _R_ScreenshotFilename(`R_ScreenShot_f'::__l2::lastNumber,auStack_104);
    }
    if (`R_ScreenShot_f'::__l2::lastNumber == &DAT_00002710) {
      (*_ri.Printf)(0,s_ScreenShot__Couldn_t_create_a_fi);
      return;
    }
    `R_ScreenShot_f'::__l2::lastNumber = `R_ScreenShot_f'::__l2::lastNumber + 1;
  }
  else {
    pvVar4 = (*_ri.field14_0x38)(1);
    iVar5 = func_0x000117e0(pvVar4,0x2f);
    if (iVar5 == 0) {
      func_0x000117a0(auStack_104,0x104,s_screenshots__s_tga,pvVar4);
    }
    else {
      func_0x000117d8(auStack_104,pvVar4,0x104);
    }
    pvVar4 = (*_ri.field13_0x34)();
    if (2 < (int)pvVar4) {
      pvVar4 = (*_ri.field14_0x38)(2);
      iVar5 = func_0x000117d0(pvVar4);
      pvVar4 = (*_ri.field14_0x38)(3);
      iVar6 = func_0x000117d0(pvVar4);
      if ((iVar5 != 0) && (iVar6 != 0)) {
        _R_SepiaScreenShot(auStack_104,iVar5,iVar6);
        return;
      }
    }
  }
  _R_TakeScreenshot(0,0,_DAT_0001282c,_DAT_00012830,auStack_104);
  if (iVar3 != 0) {
    func_0x000117a0(auStack_144,0x40,s_centerprint__Wrote__s__,auStack_104);
    (*_ri.field15_0x3c)(0,auStack_144);
  }
  return;
}



// ===========================================
// Function: _GL_SetDefaultState @ 0000e9f0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GL_SetDefaultState(void)

{
  char *pcVar1;
  
  (*__qglClearDepth)(0x3ff0000000000000);
  (*__qglCullFace)(0x404);
  (*__qglColor4f)(0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  if (__qglActiveTextureARB != 0) {
    _GL_SelectTexture(1);
    if (_r_textureMode == 0) {
      pcVar1 = s_GL_LINEAR_MIPMAP_NEAREST;
    }
    else {
      pcVar1 = *(char **)(_r_textureMode + 4);
    }
    _GL_TextureMode(pcVar1);
    _GL_TexEnv(&DAT_00002100);
    (*_ri.field38_0x98)(0xde1);
    _GL_SelectTexture(0);
  }
  (*_ri.field36_0x90)(0xde1);
  if (_r_textureMode == 0) {
    pcVar1 = s_GL_LINEAR_MIPMAP_NEAREST;
  }
  else {
    pcVar1 = *(char **)(_r_textureMode + 4);
  }
  _GL_TextureMode(pcVar1);
  _GL_TexEnv(&DAT_00002100);
  (*_ri.field34_0x88)(0x1d01);
  (*_ri.field32_0x80)(0x203);
  (*_ri.field30_0x78)(s_c__program_files_microsoft_sdks__00008073 + 1);
  _DAT_000114ec = 0x500;
  (*_ri.field28_0x70)(0x408,0x1b02);
  (*_ri.field26_0x68)(1);
  (*_ri.field38_0x98)(0xb71);
  (*_ri.field36_0x90)(0xc11);
  (*_ri.field38_0x98)(0xb44);
  (*_ri.field38_0x98)(0xbe2);
  (*_ri.field24_0x60)(0xb65,ram0x0000d0af);
  return;
}



// ===========================================
// Function: _AppendString @ 0000eb27
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void _AppendString(undefined4 param_1,undefined4 param_2,char *param_3,char *param_4,int param_5)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char local_1000 [12];
  char local_ff4 [4080];
  undefined4 uStack_4;
  
  uStack_4 = 0xeb31;
  _vsprintf(local_1000,param_3,&param_4);
  pcVar2 = param_4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar3 = local_ff4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (pcVar2 + (int)(pcVar3 + (-(int)(local_ff4 + 1) - (int)(param_4 + 1))) < (char *)(param_5 + -1)
     ) {
    pcVar2 = local_ff4;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar2 - (int)local_ff4;
    param_4 = param_4 + -1;
    do {
      pcVar2 = param_4 + 1;
      param_4 = param_4 + 1;
    } while (*pcVar2 != '\0');
    pcVar2 = local_ff4;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)param_4 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      param_4 = param_4 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_4 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      param_4 = param_4 + 1;
    }
  }
  return;
}



// ===========================================
// Function: _RE_GetGraphicsInfo @ 0000ebb8
// ===========================================

undefined4 _RE_GetGraphicsInfo(void)

{
  return 0x2000;
}



// ===========================================
// Function: _BuildGfxInfo @ 0000ebbe
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _BuildGfxInfo(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char *pcVar6;
  char *apcStack_10 [4];
  
  pvVar3 = (*_ri.field9_0x24)(s_sys_cpustring,s_,0);
  apcStack_10[0] = s_disabled;
  apcStack_10[1] = s_enabled;
  apcStack_10[2] = s_windowed;
  apcStack_10[3] = s_fullscreen;
  *param_1 = 0;
  _AppendString(param_1,0x1000,s__GL_VENDOR___s_,0x11800);
  _AppendString(param_1,0x1000,s_GL_RENDERER___s_,&_glConfig);
  _AppendString(param_1,0x1000,s_GL_VERSION___s_,0x11c00);
  pcVar6 = &DAT_00012000;
  do {
    puVar4 = (undefined1 *)func_0x000117e0(pcVar6,0x20);
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 0;
    }
    pcVar5 = pcVar6;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (1 < (uint)((int)pcVar5 - (int)(pcVar6 + 1))) {
      _AppendString(param_1,0x1000,s_GL_EXTENSIONS___s_,pcVar6);
    }
    if (puVar4 == (undefined1 *)0x0) break;
    pcVar6 = puVar4 + 1;
    *puVar4 = 0x20;
  } while (pcVar6 != (char *)0x0);
  _AppendString(param_1,0x1000,s_GL_MAX_TEXTURE_SIZE___d_,_DAT_00012800);
  _AppendString(param_1,0x1000,s_GL_MAX_ACTIVE_TEXTURES_ARB___d_,_DAT_00012804);
  _AppendString(param_1,0x1000,s__PIXELFORMAT__color__d_bits__Z__,_DAT_00012808,_DAT_0001280c,
                _DAT_00012810);
  _AppendString(param_1,0x1000,s_MODE___d___d_x__d__s_hz_,*(undefined4 *)(__r_mode + 0x20),
                _DAT_0001282c,_DAT_00012830,apcStack_10[(*(int *)(__r_fullscreen + 0x20) == 1) + 2])
  ;
  if (_DAT_00012838 == 0) {
    _AppendString(param_1,0x1000,s_N_A_);
  }
  else {
    _AppendString(param_1,0x1000,s__d_,_DAT_00012838);
  }
  if (_DAT_0001281c == 0) {
    pcVar6 = s_GAMMA__software_w___d_overbright;
  }
  else {
    pcVar6 = s_GAMMA__hardware_w___d_overbright;
  }
  _AppendString(param_1,0x1000,pcVar6,_DAT_0001217c);
  _AppendString(param_1,0x1000,s_CPU___s_,*(undefined4 *)((int)pvVar3 + 4));
  _AppendString(param_1,0x1000,s_rendering_primitives__);
  iVar2 = *(int *)(__r_primitives + 0x20);
  if (iVar2 == 0) {
    if (__qglLockArraysEXT == 0) {
      pcVar6 = s_multiple_glArrayElement_;
    }
    else {
LAB_0000ede2:
      pcVar6 = s_single_glDrawElements_;
    }
  }
  else if (iVar2 == -1) {
    pcVar6 = s_none_;
  }
  else {
    if (iVar2 == 2) goto LAB_0000ede2;
    if (iVar2 == 1) {
      pcVar6 = s_multiple_glArrayElement_;
    }
    else {
      if (iVar2 != 3) goto LAB_0000ee0d;
      pcVar6 = s_multiple_glColor4ubv___glTexCoor;
    }
  }
  _AppendString(param_1,0x1000,pcVar6);
LAB_0000ee0d:
  _AppendString(param_1,0x1000,s_texturemode___s_,*(undefined4 *)(_r_textureMode + 4));
  _AppendString(param_1,0x1000,s_picmip___d_,*(undefined4 *)(_r_picmip + 0x20));
  _AppendString(param_1,0x1000,s_texture_bits___d_,*(undefined4 *)(_r_texturebits + 0x20));
  _AppendString(param_1,0x1000,s_multitexture___s_,apcStack_10[__qglActiveTextureARB != 0]);
  _AppendString(param_1,0x1000,s_compiled_vertex_arrays___s_,apcStack_10[__qglLockArraysEXT != 0]);
  _AppendString(param_1,0x1000,s_texenv_add___s_,apcStack_10[_DAT_00012824 != 0]);
  _AppendString(param_1,0x1000,s_compressed_textures___s_,apcStack_10[_DAT_00012820 != 0]);
  if ((*(int *)(__r_vertexLight + 0x20) != 0) || (_DAT_00012818 == 4)) {
    _AppendString(param_1,0x1000,s_HACK__using_vertex_lightmap_appr);
  }
  if (_DAT_00012818 == 3) {
    _AppendString(param_1,0x1000,s_HACK__ragePro_approximations_);
  }
  if (_DAT_00012818 == 2) {
    _AppendString(param_1,0x1000,s_HACK__riva128_approximations_);
  }
  if (_DAT_00012844 != 0) {
    _AppendString(param_1,0x1000,s_Using_dual_processor_acceleratio);
  }
  if (*(int *)(__r_finish + 0x20) != 0) {
    _AppendString(param_1,0x1000,s_Forcing_glFinish_);
  }
  return;
}



// ===========================================
// Function: _R_SetMode @ 0000efac
// ===========================================

undefined4 _R_SetMode(undefined4 param_1,void *param_2)

{
  undefined4 uVar1;
  
  uVar1 = _GLimp_ChangeMode(param_1);
  _memcpy(param_2,&_glConfig,0x1448);
  return uVar1;
}



// ===========================================
// Function: _R_SetFullscreen @ 0000efd4
// ===========================================

void _R_SetFullscreen(undefined4 param_1,void *param_2)

{
  _GLimp_ChangeFullscreen(param_1);
  _memcpy(param_2,&_glConfig,0x1448);
  return;
}



// ===========================================
// Function: _R_Register @ 0000eff6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Register(void)

{
  undefined4 uVar1;
  
  __r_glDriver = (*_ri.field9_0x24)(s_r_glDriver,s_opengl32,0x21);
  __r_allowExtensions = (*_ri.field9_0x24)(s_r_allowExtensions,s_1,0x21);
  __r_ext_compressed_textures = (*_ri.field9_0x24)(s_r_ext_compress_textures,s_0,0x21);
  __r_ext_compressed_lightmaps = (*_ri.field9_0x24)(s_r_ext_compress_lightmaps,s_0,0x21);
  __r_ext_gamma_control = (*_ri.field9_0x24)(s_r_ext_gamma_control,s_1,0x21);
  __r_ext_multitexture = (*_ri.field9_0x24)(s_r_ext_multitexture,s_1,0x21);
  __r_ext_compiled_vertex_array = (*_ri.field9_0x24)(s_r_ext_compiled_vertex_array,s_1,0x21);
  __r_ext_texture_env_add = (*_ri.field9_0x24)(s_r_ext_texture_env_add,s_1,0x21);
  __r_ext_texture_env_combine = (*_ri.field9_0x24)(s_r_ext_texture_env_combine,s_0,1);
  _r_picmip = (*_ri.field9_0x24)(s_r_picmip,s_0,0x21);
  __r_roundImagesDown = (*_ri.field9_0x24)(s_r_roundImagesDown,s_1,0x21);
  __r_colorMipLevels = (*_ri.field9_0x24)(s_r_colorMipLevels,s_0,0x20);
  _AssertCvarRange(0,___real_41800000,1);
  __r_detailTextures = (*_ri.field9_0x24)(s_r_detailtextures,s_1,1);
  _r_texturebits = (*_ri.field9_0x24)(s_r_texturebits,s_32,0x21);
  __r_colorbits = (*_ri.field9_0x24)(s_r_colorbits,s_32,0x21);
  __r_stereo = (*_ri.field9_0x24)(s_r_stereo,s_0,0x21);
  __r_stencilbits = (*_ri.field9_0x24)(s_r_stencilbits,s_8,0x21);
  __r_depthbits = (*_ri.field9_0x24)(s_r_depthbits,s_0,0x21);
  __r_overBrightBits = (*_ri.field9_0x24)(s_r_overBrightBits,s_0,0x21);
  __r_ignorehwgamma = (*_ri.field9_0x24)(s_r_ignorehwgamma,s_0,0x21);
  __r_mode = (*_ri.field9_0x24)(s_r_mode,s_0,0x21);
  __r_fullscreen = (*_ri.field9_0x24)(s_r_fullscreen,s_1,0x21);
  __r_customwidth = (*_ri.field9_0x24)(s_r_customwidth,s_1280,0x21);
  __r_customheight = (*_ri.field9_0x24)(s_r_customheight,s_720,0x21);
  __r_customaspect = (*_ri.field9_0x24)(s_r_customaspect,s_1,0x21);
  __r_simpleMipMaps = (*_ri.field9_0x24)(s_r_simpleMipMaps,s_1,0x21);
  __r_vertexLight = (*_ri.field9_0x24)(s_r_vertexLight,s_0,0x21);
  __r_smp = (*_ri.field9_0x24)(s_r_smp,s_0,0x21);
  __r_ignoreFastPath = (*_ri.field9_0x24)(s_r_ignoreFastPath,s_0,0x21);
  uVar1 = va(s__d,4,0x21);
  __r_subdivisions = (*_ri.field9_0x24)(s_r_subdivisions,uVar1);
  __r_displayRefresh = (*_ri.field9_0x24)(s_r_displayRefresh,s_0,0x20);
  _AssertCvarRange(0,___real_43480000,1);
  __r_fullbright = (*_ri.field9_0x24)(s_r_fullbright,s_0,0x220);
  __r_mapOverBrightBits = (*_ri.field9_0x24)(s_r_mapOverBrightBits,s_0,0x20);
  __r_intensity = (*_ri.field9_0x24)(s_r_intensity,s_1,0x20);
  __r_numdebuglines = (*_ri.field9_0x24)(s_g_numdebuglines,s_4096,0x20);
  __r_singleShader = (*_ri.field9_0x24)(s_r_singleShader,s_0,0x220);
  __r_lerpmodels = (*_ri.field9_0x24)(s_r_lerpmodels,s_1,0);
  __r_lodCurveError = (*_ri.field9_0x24)(s_r_lodCurveError,s_250,1);
  __r_lodbias = (*_ri.field9_0x24)(s_r_lodbias,s_0,1);
  __r_flares = (*_ri.field9_0x24)(s_r_flares,s_0,1);
  __r_znear = (*_ri.field9_0x24)(s_r_znear,s_4,0x200);
  _AssertCvarRange(___real_3a83126f,___real_43480000,1);
  __r_ignoreGLErrors = (*_ri.field9_0x24)(s_r_ignoreGLErrors,s_1,1);
  __r_fastsky = (*_ri.field9_0x24)(s_r_fastsky,s_0,1);
  __r_fastdlights = (*_ri.field9_0x24)(s_r_fastdlights,s_0,1);
  __r_drawSun = (*_ri.field9_0x24)(s_r_drawSun,s_0,1);
  __r_dynamiclight = (*_ri.field9_0x24)(s_r_dynamiclight,s_1,1);
  __r_dlightBacks = (*_ri.field9_0x24)(s_r_dlightBacks,s_1,1);
  __r_finish = (*_ri.field9_0x24)(s_r_finish,s_0,1);
  _r_textureMode = (*_ri.field9_0x24)(s_r_textureMode,s_GL_LINEAR_MIPMAP_NEAREST,1);
  __r_swapInterval = (*_ri.field9_0x24)(s_r_swapInterval,s_0,1);
  __r_gamma = (*_ri.field9_0x24)(s_r_gamma,s_1_016006,1);
  __r_facePlaneCull = (*_ri.field9_0x24)(s_r_facePlaneCull,s_1,1);
  __r_railWidth = (*_ri.field9_0x24)(s_r_railWidth,s_16,1);
  __r_railCoreWidth = (*_ri.field9_0x24)(s_r_railCoreWidth,s_6,1);
  __r_railSegmentLength = (*_ri.field9_0x24)(s_r_railSegmentLength,s_32,1);
  __r_primitives = (*_ri.field9_0x24)(s_r_primitives,s_0,1);
  __r_ambientScale = (*_ri.field9_0x24)(s_r_ambientScale,s_0_5,0x200);
  __r_directedScale = (*_ri.field9_0x24)(s_r_directedScale,s_1,0x200);
  __r_showImages = (*_ri.field9_0x24)(s_r_showImages,s_0,0x100);
  __r_showlod = (*_ri.field9_0x24)(s_r_showlod,s_0,0x100);
  __r_debugLight = (*_ri.field9_0x24)(s_r_debuglight,s_0,0x100);
  __r_debugSort = (*_ri.field9_0x24)(s_r_debugSort,s_0,0x200);
  __r_printShaders = (*_ri.field9_0x24)(s_r_printShaders,s_0,0);
  __r_nocurves = (*_ri.field9_0x24)(s_r_nocurves,s_0,0x200);
  __r_drawworld = (*_ri.field9_0x24)(s_r_drawworld,s_1,0x200);
  __r_lightmap = (*_ri.field9_0x24)(s_r_lightmap,s_0,0);
  __r_portalOnly = (*_ri.field9_0x24)(s_r_portalOnly,s_0,0x200);
  __r_flareSize = (*_ri.field9_0x24)(s_r_flareSize,s_40,0x200);
  __r_flareFade = (*_ri.field9_0x24)(s_r_flareFade,s_7,0x200);
  __r_showSmp = (*_ri.field9_0x24)(s_r_showSmp,s_0,0x200);
  __r_skipBackEnd = (*_ri.field9_0x24)(s_r_skipBackEnd,s_0,0x200);
  __r_measureOverdraw = (*_ri.field9_0x24)(s_r_measureOverdraw,s_0,0x200);
  __r_lodscale = (*_ri.field9_0x24)(s_r_lodscale,s_5,0);
  __r_norefresh = (*_ri.field9_0x24)(s_r_norefresh,s_0,0x200);
  __r_drawentities = (*_ri.field9_0x24)(s_r_drawentities,s_1,0x200);
  __r_drawsprites = (*_ri.field9_0x24)(s_r_drawsprites,s_1,0x200);
  __r_ignore = (*_ri.field9_0x24)(s_r_ignore,s_1,0x200);
  __r_nocull = (*_ri.field9_0x24)(s_r_nocull,s_0,0x200);
  __r_novis = (*_ri.field9_0x24)(s_r_novis,s_0,0x200);
  __r_showcluster = (*_ri.field9_0x24)(s_r_showcluster,s_0,0x200);
  __r_speeds = (*_ri.field9_0x24)(s_r_speeds,s_0,0x200);
  __r_verbose = (*_ri.field9_0x24)(s_r_verbose,s_0,0x200);
  __r_logFile = (*_ri.field9_0x24)(s_r_logFile,s_0,0x200);
  __r_debugSurface = (*_ri.field9_0x24)(s_r_debugSurface,s_0,0x200);
  __r_nobind = (*_ri.field9_0x24)(s_r_nobind,s_0,0x200);
  __r_showtris = (*_ri.field9_0x24)(s_r_showtris,s_0,0x200);
  __r_showsky = (*_ri.field9_0x24)(s_r_showsky,s_0,0x200);
  __r_shownormals = (*_ri.field9_0x24)(s_r_shownormals,s_0,0x200);
  __r_showskel = (*_ri.field9_0x24)(s_r_showskel,s_0,0x200);
  __r_clear = (*_ri.field9_0x24)(s_r_clear,s_0,0x200);
  __r_offsetFactor = (*_ri.field9_0x24)(s_r_offsetfactor,s__1,0x200);
  __r_offsetUnits = (*_ri.field9_0x24)(s_r_offsetunits,s__2,0x200);
  __r_drawBuffer = (*_ri.field9_0x24)(s_r_drawBuffer,s_GL_BACK,0);
  __r_lockpvs = (*_ri.field9_0x24)(s_r_lockpvs,s_0,0x200);
  __r_noportals = (*_ri.field9_0x24)(s_r_noportals,s_0,0x200);
  __r_shadows = (*_ri.field9_0x24)(s_cg_shadows,s_1,0);
  __r_stipplelines = (*_ri.field9_0x24)(s_r_stipplelines,s_1,1);
  __r_light_lines = (*_ri.field9_0x24)(s_r_light_lines,s_0,1);
  __r_light_sun_line = (*_ri.field9_0x24)(s_r_light_sun_line,s_0,1);
  __r_light_int_scale = (*_ri.field9_0x24)(s_r_light_int_scale,s_0_05,1);
  __r_light_emphasize = (*_ri.field9_0x24)(s_r_light_emphasize,s_0,0);
  __r_light_emphasizePercent = (*_ri.field9_0x24)(s_r_light_emphasizePercent,s_0,0);
  __r_light_nolight = (*_ri.field9_0x24)(s_r_light_nolight,s_0,1);
  __r_skyportal = (*_ri.field9_0x24)(s_r_skyportal,s_0,0);
  __r_skyportal_origin = (*_ri.field9_0x24)(s_r_skyportal_origin,s_0_0_0,0);
  __r_farplane = (*_ri.field9_0x24)(s_r_farplane,s_0,0);
  __r_farplane_color = (*_ri.field9_0x24)(s_r_farplane_color,s__5__5__5,0);
  __r_farplane_nocull = (*_ri.field9_0x24)(s_r_farplane_nocull,s_0,0);
  __r_farplane_nofog = (*_ri.field9_0x24)(s_r_farplane_nofog,s_0,0);
  __r_farplane_pulse = (*_ri.field9_0x24)(s_r_farplane_pulse,s_0,0);
  __r_farplane_pulseFrequency = (*_ri.field9_0x24)(s_r_farplane_pulseFrequency,s_0,0);
  __r_shaderlod = (*_ri.field9_0x24)(s_r_shaderlod,s_0_5,1);
  __r_skyportal = (*_ri.field9_0x24)(s_r_skyportal,s_0,0);
  __r_skyportal_origin = (*_ri.field9_0x24)(s_r_skyportal_origin,s_0_0_0,0);
  __r_sunflare = (*_ri.field9_0x24)(s_r_sunflare,s_0,0);
  __r_place_sunflare = (*_ri.field9_0x24)(s_r_place_sunflare,s_0,0);
  __r_sunflare_inportalsky = (*_ri.field9_0x24)(s_r_sunflare_inportalsky,s_0,0);
  __r_lightcoronasize = (*_ri.field9_0x24)(s_r_lightcoronasize,s__1,1);
  __r_useglfog = (*_ri.field9_0x24)(s_r_useglfog,s_1,1);
  __r_debuglines_depthmask = (*_ri.field9_0x24)(s_r_debuglines_depthmask,s_0,1);
  __r_skelsubdivision = (*_ri.field9_0x24)(s_r_skelsubdivision,s_0,0);
  __fps = (*_ri.field9_0x24)(s_fps,s_0,0);
  __r_toggle = (*_ri.field9_0x24)(s_r_toggle,s_0,0);
  (*_ri.field11_0x2c)(s_imagelist,&_R_ImageList_f);
  (*_ri.field11_0x2c)(s_shaderlist,&_R_ShaderList_f);
  (*_ri.field11_0x2c)(s_skinlist,&_R_SkinList_f);
  (*_ri.field11_0x2c)(s_modellist,&_R_Modellist_f);
  (*_ri.field11_0x2c)(s_modelist,&_R_ModeList_f);
  (*_ri.field11_0x2c)(s_screenshot,_R_ScreenShot_f);
  (*_ri.field11_0x2c)(s_gfxinfo,&_GfxInfo_f);
  __pc_imageTime = 0;
  return;
}



// ===========================================
// Function: _R_InitExtensions @ 0000fc9b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_InitExtensions(void)

{
  if (_qglTextureEnvCombineExists != 0) {
    _DAT_000114e4 = 0;
    __r_fastsky = 0;
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000853e + 0x33,
                    ___real_47057500);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000853e + 0x34,
                    ___real_46040000);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000857f + 1,___real_47057700);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000857f + 0x11,
                    ___real_44400000);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000857f + 2,___real_45b81000);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000857f + 0x12,
                    ___real_44400000);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000857f + 3,___real_47057700);
    (*__qglTexEnvf)(&DAT_00002300,s_c__program_files_microsoft_sdks__0000857f + 0x13,
                    ___real_44408000);
  }
  return;
}



// ===========================================
// Function: _RE_Shutdown @ 0000fd84
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_Shutdown(int param_1)

{
  (*_ri.Printf)(0,s_RE_Shutdown___i___,param_1);
  (*_ri.field12_0x30)(s_modellist);
  (*_ri.field12_0x30)(s_screenshot);
  (*_ri.field12_0x30)(s_imagelist);
  (*_ri.field12_0x30)(s_shaderlist);
  (*_ri.field12_0x30)(s_skinlist);
  (*_ri.field12_0x30)(s_gfxinfo);
  (*_ri.field12_0x30)(s_modelist);
  if (_ri.field12_0x30 != (ri_func *)0x0) {
    _R_SyncRenderThread();
    _R_ShutdownCommandBuffers();
    _R_DeleteTextures();
    _GLimp_Suspend();
  }
  _ri.field12_0x30 = (ri_func *)0x0;
  _R_ShutdownShaders();
  if (__backEndData != 0) {
    (*_ri.field8_0x20)(__backEndData);
    __backEndData = 0;
  }
  if (_DAT_000118bc != 0) {
    (*_ri.field8_0x20)(_DAT_000118bc);
    _DAT_000118bc = 0;
  }
  _R_FreeModels();
  if (param_1 != 0) {
    _GLimp_Shutdown();
  }
                    /* WARNING: Could not recover jumptable at 0x0000fe5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_ri.field3_0xc)();
  return;
}



// ===========================================
// Function: _RE_SetRenderTime @ 0000fe62
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_SetRenderTime(int param_1)

{
  _DAT_0001193c = param_1;
  __tess = (float)param_1 / (float)___real_408f400000000000;
  _R_UpdateGhostTextures();
  return;
}



// ===========================================
// Function: _RE_GetRenderTime @ 0000fe80
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_GetRenderTime(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_1 = _DAT_0001193c;
  uVar1 = __ftol2_sse();
  *param_2 = uVar1;
  return;
}



// ===========================================
// Function: _InitOpenGL @ 0000fe9e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _InitOpenGL(void)

{
  int local_4;
  
  if (_DAT_0001282c == 0) {
    _GLimp_Init();
  }
  if (_DAT_00012800 < 1) {
    (*__qglGetIntegerv)(0xd33,&local_4);
    _DAT_00012800 = local_4;
    if (local_4 < 1) {
      _DAT_00012800 = 0;
    }
  }
  _R_InitCommandBuffers();
  _BuildGfxInfo(0x2000);
  (*_ri.Printf)(0,0x2000);
  (*_ri.field10_0x28)(s_r_gfxinfo,0x2000);
  _GL_SetDefaultState();
  return;
}



// ===========================================
// Function: _R_Init @ 0000ff0f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_Init(void)

{
  undefined4 uVar1;
  float fVar2;
  void *pvVar3;
  float10 fVar4;
  int iStack0000002c;
  
  (*_ri.Printf)(0,s_______R_Init_______);
  _memset(&_ri.field12_0x30,0,0x642a4);
  _memset(&_backEnd,0,0xa88);
  _memset(&_tess,0,0x317070);
  _Swap_Init();
  _Com_Printf();
  _memset((void *)0x2ee028,0xff,120000);
  DAT_00011cd4 = 0xff;
  DAT_00011cd5 = 0;
  DAT_00011cd6 = 0xff;
  DAT_00011cd7 = 0xff;
  iStack0000002c = 0;
  do {
    fVar4 = (float10)__CIsin();
    *(float *)(&DAT_00058750 + iStack0000002c * 4) = (float)fVar4;
    uVar1 = ___real_bf800000;
    if (iStack0000002c < 0x200) {
      uVar1 = 0x3f800000;
    }
    *(undefined4 *)(&DAT_00059750 + iStack0000002c * 4) = uVar1;
    fVar2 = (float)___real_3f50000000000000 * (float)iStack0000002c;
    *(float *)(&DAT_0005b750 + iStack0000002c * 4) = fVar2;
    *(float *)(&DAT_0005c750 + iStack0000002c * 4) = 1.0 - fVar2;
    if (iStack0000002c < 0x200) {
      if (iStack0000002c < 0x100) {
        fVar2 = (float)iStack0000002c * (float)___real_3f70000000000000;
      }
      else {
        fVar2 = 1.0 - *(float *)(&DAT_0005a350 + iStack0000002c * 4);
      }
    }
    else {
      fVar2 = -*(float *)(&DAT_00059f50 + iStack0000002c * 4);
    }
    *(float *)(&DAT_0005a750 + iStack0000002c * 4) = fVar2;
    iStack0000002c = iStack0000002c + 1;
  } while (iStack0000002c < 0x400);
  _DAT_00075a54 = (*_ri.field2_0x8)();
  if (_DAT_00075a54 == (void *)0x0) {
    _DAT_00075a54 = (void *)0xffffffff;
  }
  _R_InitFogTable();
  _R_NoiseInit();
  _R_Sky_Init();
  _R_Register();
  __backEndData = (*_ri.field7_0x1c)();
  if (*(int *)(__r_smp + 0x20) == 0) {
    _DAT_000118bc = (void *)0x0;
  }
  else {
    _DAT_000118bc = (*_ri.field7_0x1c)();
  }
  _R_ToggleSmpFrame();
  _GLimp_Resume();
  _InitOpenGL();
  _R_InitExtensions();
  _R_InitImages();
  _R_StartupShaders();
  _R_InitSkins();
  _R_ModelInit();
  _GLimp_Suspend();
  pvVar3 = (*_ri.field8_0x20)();
  if (pvVar3 != (void *)0x0) {
    (*_ri.Printf)();
  }
  (*_ri.Printf)();
  return;
}



// ===========================================
// Function: _GetRefAPI @ 00010139
// ===========================================

undefined4 _GetRefAPI(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *prVar2;
  
  prVar2 = &_ri;
  for (iVar1 = 0x27; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)prVar2 = *param_2;
    param_2 = param_2 + 1;
    prVar2 = (void *)((int)prVar2 + 4);
  }
  _memset(&`GetRefAPI'::__l2::re,0,0xd8);
  if (param_4 != 8) {
    (*_ri.Printf)(0);
    return 0;
  }
  _R_Init();
  `GetRefAPI'::__l2::re.field0_0x0 = _RE_Shutdown;
  `GetRefAPI'::__l2::re.field1_0x4 = (re_func *)&_RE_BeginRegistration;
  `GetRefAPI'::__l2::re.field8_0x20 = (re_func *)&_RE_EndRegistration;
  `GetRefAPI'::__l2::re.field2_0x8 = (re_func *)&_RE_RegisterModel;
  `GetRefAPI'::__l2::re.field3_0xc = (re_func *)&_RE_RegisterSkin;
  `GetRefAPI'::__l2::re.field4_0x10 = (re_func *)&_RE_RegisterShader;
  `GetRefAPI'::__l2::re.field5_0x14 = (re_func *)&_RE_RegisterShaderNoMip;
  `GetRefAPI'::__l2::re.field6_0x18 = (re_func *)&_RE_RefreshShaderNoMip;
  `GetRefAPI'::__l2::re.field7_0x1c = (re_func *)&_RE_RefreshStaticShaderNoMip;
  `GetRefAPI'::__l2::re.field10_0x28 = (re_func *)&_RE_LoadWorldMap;
  `GetRefAPI'::__l2::re.field42_0xa8 = (re_func *)&_R_LoadFont;
  `GetRefAPI'::__l2::re.field9_0x24 = (re_func *)&_RE_SetWorldVisData;
  `GetRefAPI'::__l2::re.field29_0x74 = (re_func *)&_RE_BeginFrame;
  `GetRefAPI'::__l2::re.field32_0x80 = (re_func *)&_RE_EndFrame;
  `GetRefAPI'::__l2::re.field33_0x84 = (re_func *)&_R_MarkFragments;
  `GetRefAPI'::__l2::re.field34_0x88 = (re_func *)&_R_LerpTag;
  `GetRefAPI'::__l2::re.field35_0x8c = (re_func *)&_R_ModelBounds;
  `GetRefAPI'::__l2::re.field36_0x90 = (re_func *)&_R_ModelRadius;
  `GetRefAPI'::__l2::re.field11_0x2c = (re_func *)&_RE_ClearScene;
  `GetRefAPI'::__l2::re.field12_0x30 = (re_func *)&_RE_AddRefEntityToScene;
  `GetRefAPI'::__l2::re.field13_0x34 = (re_func *)&_RE_AddRefSpriteToScene;
  `GetRefAPI'::__l2::re.field14_0x38 = (re_func *)&_RE_AddPolyToScene;
  `GetRefAPI'::__l2::re.field15_0x3c = (re_func *)&_RE_AddLightToScene;
  `GetRefAPI'::__l2::re.field16_0x40 = (re_func *)&_RE_RenderScene;
  `GetRefAPI'::__l2::re.field17_0x44 = (re_func *)&_RE_GetRenderEntity;
  `GetRefAPI'::__l2::re.field18_0x48 = (re_func *)&_R_SavePerformanceCounters;
  `GetRefAPI'::__l2::re.field37_0x94 = (re_func *)&_TIKI_GetHandle;
  `GetRefAPI'::__l2::re.field38_0x98 = (re_func *)&_TIKI_FlushAll;
  `GetRefAPI'::__l2::re.field19_0x4c = (re_func *)&_Draw_SetColor;
  `GetRefAPI'::__l2::re.field22_0x58 = (re_func *)&_Draw_StretchPic;
  `GetRefAPI'::__l2::re.field25_0x64 = (re_func *)&_RE_StretchRaw;
  `GetRefAPI'::__l2::re.field26_0x68 = (re_func *)&_R_DebugLine;
  `GetRefAPI'::__l2::re.field23_0x5c = (re_func *)&_Draw_TilePic;
  `GetRefAPI'::__l2::re.field24_0x60 = (re_func *)&_Draw_TilePicOffset;
  `GetRefAPI'::__l2::re.field27_0x6c = (re_func *)&_DrawBox;
  `GetRefAPI'::__l2::re.field28_0x70 = (re_func *)&_AddBox;
  `GetRefAPI'::__l2::re.field21_0x54 = (re_func *)&_Set2DWindow;
  `GetRefAPI'::__l2::re.field20_0x50 = (re_func *)&_SetFull2DWindow;
  `GetRefAPI'::__l2::re.field30_0x78 = (re_func *)&_RE_Scissor;
  `GetRefAPI'::__l2::re.field31_0x7c = (re_func *)&_DrawLineLoop;
  `GetRefAPI'::__l2::re.field39_0x9c = (re_func *)&_R_DrawString;
  `GetRefAPI'::__l2::re.field40_0xa0 = (re_func *)&_R_GetFontHeight;
  `GetRefAPI'::__l2::re.field41_0xa4 = (re_func *)&_R_GetFontStringWidth;
  `GetRefAPI'::__l2::re.field43_0xac = (re_func *)&_RE_SwipeBegin;
  `GetRefAPI'::__l2::re.field44_0xb0 = (re_func *)&_RE_SwipePoint;
  `GetRefAPI'::__l2::re.field45_0xb4 = (re_func *)&_RE_SwipeEnd;
  `GetRefAPI'::__l2::re.field46_0xb8 = _RE_SetRenderTime;
  `GetRefAPI'::__l2::re.field47_0xbc = _RE_GetRenderTime;
  `GetRefAPI'::__l2::re.field48_0xc0 = (re_func *)&_R_NoiseGet4f;
  `GetRefAPI'::__l2::re.field49_0xc4 = _R_SetMode;
  `GetRefAPI'::__l2::re.field50_0xc8 = _R_SetFullscreen;
  `GetRefAPI'::__l2::re.field52_0xd0 = (re_func *)&_RE_GetShaderHeight;
  `GetRefAPI'::__l2::re.field51_0xcc = (re_func *)&_RE_GetShaderWidth;
  `GetRefAPI'::__l2::re.field53_0xd4 = _RE_GetGraphicsInfo;
  return 0x3000;
}



