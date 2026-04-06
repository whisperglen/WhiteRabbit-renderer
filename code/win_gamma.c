// ===========================================
// Function: _WG_CheckHardwareGamma @ 00007c00
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _WG_CheckHardwareGamma(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  
  pcVar1 = ___imp__GetDesktopWindow_0;
  _DAT_0000a3b4 = 0;
  if (__qwglSetDeviceGammaRamp3DFX != 0) {
    _DAT_0000a3b4 = 1;
    uVar2 = (*___imp__GetDesktopWindow_0)();
    uVar2 = (*___imp__GetDC_4)(uVar2);
    _DAT_0000a3b4 = (*__qwglGetDeviceGammaRamp3DFX)(uVar2,0x2000);
    uVar2 = (*pcVar1)(uVar2);
    (*___imp__ReleaseDC_8)(uVar2);
    return;
  }
  if ((_DAT_0000a3ac != 1) && (*(int *)(__r_ignorehwgamma + 0x20) == 0)) {
    uVar2 = (*___imp__GetDesktopWindow_0)();
    uVar2 = (*___imp__GetDC_4)(uVar2);
    _DAT_0000a3b4 = (*___imp__GetDeviceGammaRamp_8)(uVar2,0x2000);
    uVar2 = (*pcVar1)(uVar2);
    (*___imp__ReleaseDC_8)(uVar2);
    if (_DAT_0000a3b4 != 0) {
      if (((DAT_000021ff <= _s_oldHardwareGamma._1_1_) || (DAT_000023ff <= DAT_00002200._1_1_)) ||
         (DAT_000025ff <= DAT_00002400._1_1_)) {
        _DAT_0000a3b4 = 0;
        (*__ri)(3,s_WARNING__device_has_broken_gamma);
      }
      if (DAT_0000216b == -1) {
        (*__ri)(3,s_WARNING__suspicious_gamma_tables);
        iVar3 = 0;
        do {
          uVar4 = (undefined2)(iVar3 << 8);
          *(undefined2 *)(iVar3 * 2 + 0x2000) = uVar4;
          (&DAT_00002200)[iVar3] = uVar4;
          (&DAT_00002400)[iVar3] = uVar4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0xff);
      }
      if ((_DAT_0000a3b4 != 0) && (*(int *)(__r_overBrightBits + 0x20) != 0)) {
        __qglTextureEnvCombineExists = 0;
      }
    }
  }
  return;
}



// ===========================================
// Function: _GLimp_SetGamma @ 00007d48
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_SetGamma(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int local_60c;
  undefined2 local_600 [256];
  undefined2 local_400 [256];
  undefined2 local_200 [256];
  
  if (((_DAT_0000a3b4 != 0) && (*(int *)(__r_ignorehwgamma + 0x20) == 0)) && (_DAT_00008fb4 != 0)) {
    local_60c = 0x40;
    puVar3 = local_400;
    puVar4 = param_2;
    puVar5 = (undefined1 *)(param_3 + 1);
    puVar6 = (undefined1 *)(param_1 + 3);
    do {
      uVar1 = *puVar4;
      puVar3[-0x100] = CONCAT11(puVar4[param_1 - (int)param_2],puVar4[param_1 - (int)param_2]);
      uVar2 = puVar4[param_3 - (int)param_2];
      *puVar3 = CONCAT11(uVar1,uVar1);
      uVar1 = puVar5[param_1 - param_3];
      puVar3[0x100] = CONCAT11(uVar2,uVar2);
      uVar2 = puVar4[1];
      puVar3[-0xff] = CONCAT11(uVar1,uVar1);
      uVar1 = *puVar5;
      puVar3[1] = CONCAT11(uVar2,uVar2);
      uVar2 = puVar6[-1];
      puVar3[0x101] = CONCAT11(uVar1,uVar1);
      uVar1 = puVar4[2];
      puVar3[-0xfe] = CONCAT11(uVar2,uVar2);
      uVar2 = puVar5[1];
      puVar3[2] = CONCAT11(uVar1,uVar1);
      uVar1 = *puVar6;
      puVar3[0x102] = CONCAT11(uVar2,uVar2);
      uVar2 = puVar4[3];
      puVar3[-0xfd] = CONCAT11(uVar1,uVar1);
      uVar1 = puVar5[2];
      puVar3[3] = CONCAT11(uVar2,uVar2);
      local_60c = local_60c + -1;
      puVar3[0x103] = CONCAT11(uVar1,uVar1);
      puVar3 = puVar3 + 4;
      puVar4 = puVar4 + 4;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
    } while (local_60c != 0);
    if (__qwglSetDeviceGammaRamp3DFX != (code *)0x0) {
      (*__qwglSetDeviceGammaRamp3DFX)(_DAT_00008fb4,local_600);
      return;
    }
    (*___imp__SetDeviceGammaRamp_8)(_DAT_00008fb4,local_600);
  }
  return;
}



// ===========================================
// Function: _GLimp_BigSuspend @ 00007efc
// ===========================================

void _GLimp_BigSuspend(void)

{
  return;
}



// ===========================================
// Function: _GLimp_BigResume @ 00007efd
// ===========================================

void _GLimp_BigResume(void)

{
  return;
}



// ===========================================
// Function: _GLimp_Suspend @ 00007efe
// ===========================================

void _GLimp_Suspend(void)

{
  return;
}



// ===========================================
// Function: _GLimp_Resume @ 00007eff
// ===========================================

void _GLimp_Resume(void)

{
  return;
}



// ===========================================
// Function: _WG_RestoreGamma @ 00007f00
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _WG_RestoreGamma(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = ___imp__GetDesktopWindow_0;
  if (_DAT_0000a3b4 != 0) {
    if (__qwglSetDeviceGammaRamp3DFX != (code *)0x0) {
      (*__qwglSetDeviceGammaRamp3DFX)(_DAT_00008fb4,0x2000);
      return;
    }
    uVar2 = (*___imp__GetDesktopWindow_0)();
    uVar2 = (*___imp__GetDC_4)(uVar2);
    (*___imp__SetDeviceGammaRamp_8)(uVar2,0x2000);
    uVar2 = (*pcVar1)(uVar2);
    (*___imp__ReleaseDC_8)(uVar2);
  }
  return;
}



