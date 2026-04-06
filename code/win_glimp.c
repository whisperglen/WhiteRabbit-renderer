// ===========================================
// Function: _GLW_GetValidModes @ 0000c900
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLW_GetValidModes(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iStack_a8;
  undefined *puStack_a4;
  
  pcVar5 = ___imp__EnumDisplaySettingsA_12;
  puStack_a4 = &_g_DeviceModes + _g_NumDeviceModes * 0x9c;
  iStack_a8 = _g_NumDeviceModes;
  iVar3 = (*___imp__EnumDisplaySettingsA_12)(0);
  while ((iVar3 != 0 && (_g_NumDeviceModes = _g_NumDeviceModes + 1, _g_NumDeviceModes < 0x400))) {
    iVar3 = (*pcVar5)(0,_g_NumDeviceModes,&_g_DeviceModes + _g_NumDeviceModes * 0x9c);
  }
  (*pcVar5)(0,0xffffffff,&iStack_a8);
  if (0 < _g_NumDeviceModes) {
    pcVar5 = __chkstk;
    iVar3 = _g_NumDeviceModes;
    do {
      iVar1 = *(int *)(pcVar5 + -4);
      iVar2 = *(int *)pcVar5;
      if ((0x27f < iVar1) && (0x1df < iVar2)) {
        iVar4 = 0;
        if (0 < _g_NumValidRes) {
          do {
            if ((iVar1 == *(int *)(&_g_ValidResolutions + iVar4 * 8)) &&
               (iVar2 == *(int *)(&DAT_0000fbe4 + iVar4 * 8))) break;
            iVar4 = iVar4 + 1;
          } while (iVar4 < _g_NumValidRes);
        }
        if (iVar4 == _g_NumValidRes) {
          *(int *)(&_g_ValidResolutions + iVar4 * 8) = iVar1;
          *(int *)(&DAT_0000fbe4 + iVar4 * 8) = iVar2;
          _g_NumValidRes = _g_NumValidRes + 1;
        }
      }
      pcVar5 = pcVar5 + 0x9c;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}



// ===========================================
// Function: _GLW_GetModeInfo @ 0000c9e5
// ===========================================

undefined4 _GLW_GetModeInfo(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if ((-2 < param_4) && (param_4 < _g_NumDeviceModes)) {
    if (param_4 == -1) {
      param_4 = 0;
    }
    *param_1 = *(undefined4 *)(&_g_ValidResolutions + param_4 * 8);
    *param_2 = *(undefined4 *)(&DAT_0000fbe4 + param_4 * 8);
    *param_3 = 0x3f800000;
    return 1;
  }
  return 0;
}



// ===========================================
// Function: _GLW_ChoosePFD @ 0000ca28
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall _GLW_ChoosePFD(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  byte *pbVar9;
  int unaff_EDI;
  uint *puVar10;
  char *pcVar11;
  undefined4 local_2830;
  undefined1 auStack_2828 [7];
  byte abStack_2821 [17];
  undefined1 auStack_2810 [4];
  uint auStack_280c [2560];
  undefined4 *puStack_c;
  undefined4 uStack_4;
  
  uStack_4 = 0xca32;
  local_2830 = 0;
  (*__ri)(0,s____GLW_ChoosePFD___d___d___d___,*(undefined1 *)(param_2 + 9),
          *(undefined1 *)(param_2 + 0x17),*(undefined1 *)(param_2 + 0x18));
  pcVar5 = ___imp__DescribePixelFormat_16;
  if (_DAT_0001103c < 1) {
    iVar6 = (*___imp__DescribePixelFormat_16)(param_1,1,0x28,auStack_2828);
  }
  else {
    iVar6 = (*__qwglDescribePixelFormat)(param_1,1,0x28,auStack_2828);
  }
  if (0x100 < iVar6) {
    (*__ri)(3,s____numPFDs_>_MAX_PFDS___d_>__d__,iVar6,0x100);
    iVar6 = 0x100;
  }
  (*__ri)(0,s_____d_PFDs_found_,iVar6 + -1);
  iVar8 = 1;
  if (0 < iVar6) {
    puVar7 = auStack_2810;
    do {
      if (_DAT_0001103c < 1) {
        (*pcVar5)(param_1,iVar8,0x28,puVar7);
      }
      else {
        (*__qwglDescribePixelFormat)();
      }
      iVar8 = iVar8 + 1;
      puVar7 = puVar7 + 0x28;
    } while (iVar8 <= iVar6);
  }
  iVar8 = 1;
  if (0 < iVar6) {
    puVar10 = auStack_280c;
    do {
      uVar2 = *puVar10;
      if (((uVar2 & 0x40) == 0) || (*(int *)(__r_allowSoftwareGL + 0x20) != 0)) {
        if ((char)puVar10[1] == '\0') {
          uVar3 = puStack_c[1];
          if ((uVar2 & uVar3) == uVar3) {
            if ((0xe < *(byte *)((int)puVar10 + 0x13)) &&
               ((3 < (byte)puVar10[5] || (*(char *)(puStack_c + 6) == '\0')))) {
              if (((unaff_EDI != 0) &&
                  ((((uVar2 & 2) == 0 || ((abStack_2821[unaff_EDI * 0x28 + -0x13] & 2) != 0)) ||
                   ((uVar3 & 2) == 0)))) &&
                 ((((uVar2 & 2) != 0 || ((abStack_2821[unaff_EDI * 0x28 + -0x13] & 2) == 0)) ||
                  ((uVar3 & 2) == 0)))) {
                iVar4 = unaff_EDI * 0x28;
                bVar1 = *(byte *)((int)&local_2830 + iVar4 + 1);
                if ((bVar1 == *(byte *)((int)puStack_c + 9)) ||
                   ((*(byte *)((int)puVar10 + 5) != *(byte *)((int)puStack_c + 9) &&
                    (*(byte *)((int)puVar10 + 5) <= bVar1)))) {
                  if ((abStack_2821[iVar4] == *(byte *)((int)puStack_c + 0x17)) ||
                     ((*(byte *)((int)puVar10 + 0x13) != *(byte *)((int)puStack_c + 0x17) &&
                      (*(byte *)((int)puVar10 + 0x13) <= abStack_2821[iVar4])))) {
                    bVar1 = *(byte *)(puStack_c + 6);
                    if ((abStack_2821[iVar4 + 1] == bVar1) ||
                       (((byte)puVar10[5] != bVar1 &&
                        (((byte)puVar10[5] <= abStack_2821[iVar4 + 1] || (bVar1 == 0))))))
                    goto LAB_0000cc68;
                  }
                }
              }
              unaff_EDI = iVar8;
            }
          }
          else if (*(int *)(__r_verbose + 0x20) != 0) {
            (*__ri)(0,s____PFD__d_rejected__improper_fla,iVar8,uVar2,uVar3);
          }
        }
        else if (*(int *)(__r_verbose + 0x20) != 0) {
          (*__ri)(0,s____PFD__d_rejected__not_RGBA_,iVar8);
        }
      }
      else if (*(int *)(__r_verbose + 0x20) != 0) {
        (*__ri)(0,s____PFD__d_rejected__software_acc,iVar8);
      }
LAB_0000cc68:
      iVar8 = iVar8 + 1;
      puVar10 = puVar10 + 10;
    } while (iVar8 <= iVar6);
    if (unaff_EDI != 0) {
      if ((*(uint *)(abStack_2821 + unaff_EDI * 0x28 + -0x13) & 0x40) == 0) {
        if ((*(uint *)(abStack_2821 + unaff_EDI * 0x28 + -0x13) & 0x1000) == 0) {
          pcVar11 = s____hardware_acceleration_found_;
        }
        else {
          pcVar11 = s____MCD_acceleration_found_;
        }
      }
      else {
        if (*(int *)(__r_allowSoftwareGL + 0x20) == 0) {
          (*__ri)(0,s____no_hardware_acceleration_foun);
          return 0;
        }
        pcVar11 = s____using_software_emulation_;
      }
      (*__ri)(0,pcVar11);
      pbVar9 = abStack_2821 + unaff_EDI * 0x28 + -0x17;
      for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puStack_c = *(undefined4 *)pbVar9;
        pbVar9 = pbVar9 + 4;
        puStack_c = puStack_c + 1;
      }
      return unaff_EDI;
    }
  }
  return 0;
}



// ===========================================
// Function: _GLW_CreatePFD @ 0000ccfb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLW_CreatePFD(undefined4 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                   int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_28._0_2_ = 0x28;
  local_28._2_2_ = 1;
  local_1f = param_2;
  local_24 = 0x25;
  local_20 = 0;
  local_1e = 0;
  local_1d = 0;
  local_1c = 0;
  local_1b = 0;
  local_1a = 0;
  local_19 = 0;
  local_18 = 0;
  local_17 = 0;
  local_16 = 0;
  local_15 = 0;
  local_14 = 0;
  local_13 = 0;
  local_12 = 0;
  local_f = 0;
  local_e = 0;
  local_d = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_11 = param_3;
  local_10 = param_4;
  if (param_5 != 0) {
    (*__ri)(0,s____attempting_to_use_stereo_);
    local_24 = 0x27;
  }
  _DAT_00011068 = (uint)(param_5 != 0);
  puVar2 = &local_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



// ===========================================
// Function: _GLW_MakeContext @ 0000cdc8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLW_MakeContext(void)

{
  int iVar1;
  
  if (_DAT_0000fbd4 == 0) {
    iVar1 = _GLW_ChoosePFD();
    if (iVar1 == 0) {
      (*__ri)(0,s____GLW_ChoosePFD_failed_);
      return 1;
    }
    (*__ri)(0,s____PIXELFORMAT__d_selected_,iVar1);
    if (_DAT_0001103c < 1) {
      (*___imp__DescribePixelFormat_16)(_DAT_0000fbc4,iVar1,0x28);
      iVar1 = (*___imp__SetPixelFormat_12)(_DAT_0000fbc4,iVar1);
      if (iVar1 == 0) {
        (*__ri)(0,s____SetPixelFormat_failed_,_DAT_0000fbc4);
        return 1;
      }
    }
    else {
      (*__qwglDescribePixelFormat)(_DAT_0000fbc4);
      iVar1 = (*__qwglSetPixelFormat)(_DAT_0000fbc4,iVar1);
      if (iVar1 == 0) {
        (*__ri)(0,s____qwglSetPixelFormat_failed_);
        return 1;
      }
    }
    _DAT_0000fbd4 = 1;
  }
  if (__r_allowSoftwareGL != 0) {
    return 0;
  }
  (*__ri)(0,s____creating_GL_context__);
  __r_allowSoftwareGL = (*__qwglCreateContext)(_DAT_0000fbc4);
  if (__r_allowSoftwareGL != 0) {
    (*__ri)(0,s_succeeded_);
    (*__ri)(0,s____making_context_current__);
    iVar1 = (*__qwglMakeCurrent)(_DAT_0000fbc4,__r_allowSoftwareGL);
    if (iVar1 != 0) {
      (*__ri)(0,s_succeeded_);
      return 0;
    }
    (*__qwglDeleteContext)(__r_allowSoftwareGL);
    __r_allowSoftwareGL = 0;
  }
  (*__ri)(0,s_failed_);
  return 2;
}



// ===========================================
// Function: _GLW_InitDriver @ 0000cf41
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLW_InitDriver(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  (*__ri)(0,s_Initializing_OpenGL_driver_);
  if (_DAT_0000fbc4 == 0) {
    (*__ri)(0,s____getting_DC__);
    _DAT_0000fbc4 = (*___imp__GetDC_4)(___imp__SetFocus_4);
    if (_DAT_0000fbc4 == 0) {
      (*__ri)(0,s_failed_);
      return 0;
    }
    (*__ri)(0,s_succeeded_);
  }
  if (in_EAX == 0) {
    in_EAX = __renderCommandsEvent;
  }
  iVar2 = *(int *)(__r_depthbits + 0x20);
  if (iVar2 == 0) {
    iVar2 = (uint)(0x10 < in_EAX) * 8 + 0x10;
  }
  iVar3 = *(int *)(__r_stencilbits + 0x20);
  if (iVar2 < 0x18) {
    iVar3 = 0;
  }
  if (_DAT_0000fbd4 != 0) goto LAB_0000d0e6;
  _GLW_CreatePFD(&`GLW_InitDriver'::__l2::pfd,in_EAX,iVar2,iVar3,*(undefined4 *)(__r_stereo + 0x20))
  ;
  iVar1 = _GLW_MakeContext();
  if (iVar1 == 0) {
LAB_0000d0b7:
    if (((DAT_0000200c & 2) == 0) && (*(int *)(__r_stereo + 0x20) != 0)) {
      (*__ri)(0,s____failed_to_select_stereo_pixel);
      _DAT_00011068 = 0;
    }
LAB_0000d0e6:
    _DAT_00011034 = (uint)DAT_0000201f;
    _DAT_00011030 = (uint)DAT_00002011;
    _DAT_00011038 = (uint)DAT_00002020;
    return 1;
  }
  if (iVar1 == 2) {
    (*__ri)(3,s____failed_hard_);
    return 0;
  }
  if ((*(int *)(__r_colorbits + 0x20) != __renderCommandsEvent) || (iVar3 != 0)) {
    if (__renderCommandsEvent < in_EAX) {
      in_EAX = __renderCommandsEvent;
    }
    _GLW_CreatePFD(&`GLW_InitDriver'::__l2::pfd,in_EAX,iVar2,0,*(undefined4 *)(__r_stereo + 0x20));
    iVar2 = _GLW_MakeContext();
    if (iVar2 == 0) goto LAB_0000d0b7;
    if (_DAT_0000fbc4 == 0) goto LAB_0000d0a0;
  }
  (*___imp__ReleaseDC_8)(___imp__SetFocus_4,_DAT_0000fbc4);
  _DAT_0000fbc4 = 0;
LAB_0000d0a0:
  (*__ri)(0,s____failed_to_find_an_appropriate);
  return 0;
}



// ===========================================
// Function: _GLW_CreateWindow @ 0000d116
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLW_CreateWindow(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  char *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar6 = 0;
  if (_s_classRegistered == 0) {
    local_14 = (char *)0x0;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    local_24 = __glw_state;
    local_28 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = _DAT_0000fcac;
    local_1c = (*___imp__LoadIconA_8)(_DAT_0000fcac,1);
    local_20 = (*___imp__LoadCursorA_8)(0,0x7f00);
    local_1c = 0x11;
    local_18 = 0;
    local_14 = s_American_McGee_s_AliceWin;
    sVar1 = (*___imp__RegisterClassA_4)(&iStack_38);
    if (sVar1 == 0) {
      (*_DAT_0000fc3c)(0,s_GLW_CreateWindow__could_not_regi);
    }
    _s_classRegistered = 1;
    (*__ri)(0,s____registered_window_class_);
  }
  if (___imp__SetFocus_4 == (code *)0x0) {
    iStack_38 = 0;
    iStack_34 = 0;
    iStack_30 = param_2;
    iStack_2c = param_3;
    if ((in_EAX == 0) && (iVar2 = _Q_stricmp(s_3dfxvgl,param_1), iVar2 != 0)) {
      uStack_3c = 0;
      uStack_40 = 0x10c80000;
      (*___imp__AdjustWindowRect_12)(&iStack_38,0x10c80000,0);
    }
    else {
      uStack_3c = 8;
      uStack_40 = 0x90080000;
    }
    iVar5 = iStack_30 - iStack_38;
    iVar2 = iStack_2c - iStack_34;
    if ((in_EAX == 0) && (iVar3 = _Q_stricmp(s_3dfxvgl,param_1), iVar3 != 0)) {
      iVar6 = (*_DAT_0000fc5c)(s_vid_xpos,s_,0);
      iVar4 = (*_DAT_0000fc5c)(s_vid_ypos,s_,0);
      iVar3 = *(int *)(iVar6 + 0x20);
      iVar6 = *(int *)(iVar4 + 0x20);
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      if ((iVar5 < _DAT_0000fbdc) && (iVar2 < __g_ValidResolutions)) {
        if (_DAT_0000fbdc < iVar3 + iVar5) {
          iVar3 = _DAT_0000fbdc - iVar5;
        }
        if (__g_ValidResolutions < iVar6 + iVar2) {
          iVar6 = __g_ValidResolutions - iVar2;
        }
      }
    }
    else {
      iVar3 = 0;
    }
    ___imp__SetFocus_4 =
         (code *)(*___imp__CreateWindowExA_48)
                           (uStack_3c,s_American_McGee_s_AliceWin,s_American_McGee_s_Alice,uStack_40
                            ,iVar3,iVar6,iVar5,iVar2,0,0,_DAT_0000fcac,0);
    if (___imp__SetFocus_4 == (code *)0x0) {
      (*_DAT_0000fc3c)(0,s_GLW_CreateWindow_____Couldn_t_cr);
    }
    (*___imp__ShowWindow_8)(___imp__SetFocus_4,5);
    (*___imp__UpdateWindow_4)(___imp__SetFocus_4);
    (*__ri)(0,s____created_window__d__d___dx_d__,iVar3,iVar6,iVar5,iVar2);
  }
  else {
    (*__ri)(0,s____window_already_present__Creat);
  }
  iVar6 = _GLW_InitDriver();
  if (iVar6 != 0) {
    (*___imp__SetForegroundWindow_4)(___imp__SetFocus_4);
    (*___imp__SetFocus_4)(___imp__SetFocus_4);
    return 1;
  }
  (*___imp__ShowWindow_8)(___imp__SetFocus_4,0);
  (*___imp__DestroyWindow_4)(___imp__SetFocus_4);
  ___imp__SetFocus_4 = (code *)0x0;
  return 0;
}



// ===========================================
// Function: _PrintCDSError @ 0000d3c8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall _PrintCDSError(undefined4 param_1)

{
  switch(param_1) {
  default:
    (*__ri)(0,s_unknown_error__d_,param_1);
    return;
  case 1:
    (*__ri)(0,s_restart_required_);
    return;
  case 0xfffffffb:
    (*__ri)(0,s_bad_param_);
    return;
  case 0xfffffffc:
    (*__ri)(0,s_bad_flags_);
    return;
  case 0xfffffffd:
    (*__ri)(0,s_not_updated_);
    return;
  case 0xfffffffe:
    (*__ri)(0,s_bad_mode_);
    return;
  case 0xffffffff:
    (*__ri)(0,s_DISP_CHANGE_FAILED_);
    return;
  }
}



// ===========================================
// Function: _GLW_SetMode @ 0000d46c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _GLW_SetMode(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  code *pcVar2;
  int in_EAX;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint uStack_15c;
  uint uStack_158;
  char *pcStack_154;
  char *local_140 [5];
  undefined2 uStack_12c;
  uint uStack_128;
  int iStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  int iStack_d8;
  undefined1 auStack_c8 [12];
  undefined1 auStack_bc [92];
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_30;
  undefined4 uStack_20;
  int iStack_18;
  
  pcStack_154 = (char *)0x0;
  local_140[0] = s_W;
  local_140[1] = s_FS;
  uStack_158 = 0xd49b;
  (*__ri)();
  if ((in_EAX < -1) || (_g_NumDeviceModes <= in_EAX)) {
    pcStack_154 = (char *)0xd654;
    (*__ri)();
    return 2;
  }
  if (in_EAX == -1) {
    in_EAX = 0;
  }
  _DAT_00011054 = *(uint *)(&_g_ValidResolutions + in_EAX * 8);
  _DAT_0001105c = 0x3f800000;
  pcStack_154 = local_140[param_3];
  _DAT_00011058 = *(uint *)(&DAT_0000fbe4 + in_EAX * 8);
  uStack_15c = _DAT_00011054;
  uStack_158 = _DAT_00011058;
  (*__ri)(0,s___d__d__s_);
  pcVar2 = ___imp__GetDesktopWindow_0;
  pcStack_154 = (char *)0xd505;
  pcStack_154 = (char *)(*___imp__GetDesktopWindow_0)();
  uStack_158 = 0xd50c;
  uVar3 = (*___imp__GetDC_4)();
  pcVar1 = ___imp__GetDeviceCaps_8;
  uStack_158 = 0xc;
  uStack_15c = uVar3;
  __renderCommandsEvent = (*___imp__GetDeviceCaps_8)();
  _DAT_0000fbdc = (*pcVar1)(uVar3,8);
  __g_ValidResolutions = (*pcVar1)(uVar3,10);
  uVar4 = (*pcVar2)(uVar3);
  (*___imp__ReleaseDC_8)(uVar4);
  if (_DAT_0001103c == 2) {
    (*___imp__SetPixelFormat_12)(s_r_stipplelines,s_0);
    *(undefined4 *)(__r_stipplelines + 0x14) = 0;
    if (_DAT_0001103c != 2) goto LAB_0000d570;
LAB_0000d5ba:
    if (iStack_18 == 0) {
LAB_0000d8c5:
      if (_DAT_0000fbe4 != 0) {
        (*___imp__ChangeDisplaySettingsA_8)(0,0);
      }
      _DAT_0000fbe4 = 0;
      iVar5 = _GLW_CreateWindow(uStack_20,_DAT_00011054,_DAT_00011058,param_2);
      if (iVar5 == 0) {
        return 2;
      }
      goto LAB_0000d90a;
    }
  }
  else {
LAB_0000d570:
    if ((0xe < __renderCommandsEvent) && (__renderCommandsEvent != 0x18)) goto LAB_0000d5ba;
    if (param_2 == 0) {
LAB_0000d597:
      iVar5 = (*___imp__MessageBoxA_16)
                        (0,s_It_is_highly_unlikely_that_a_cor,s_Low_Desktop_Color_Depth,0x31);
      if (iVar5 != 1) {
        return 2;
      }
      goto LAB_0000d5ba;
    }
    if (iStack_18 == 0) {
      if (0xe < param_2) goto LAB_0000d597;
      goto LAB_0000d8c5;
    }
  }
  iVar5 = __renderCommandsEvent;
  _memset(&uStack_15c,0,0x9c);
  uStack_12c = 0x9c;
  uStack_e4 = _DAT_00011054;
  uStack_e0 = _DAT_00011058;
  uStack_128 = 0x180000;
  if (*(int *)(__r_displayRefresh + 0x20) != 0) {
    uStack_128 = 0x580000;
    iStack_d8 = *(int *)(__r_displayRefresh + 0x20);
  }
  if (param_2 == 0) {
    pcVar7 = s____using_desktop_display_depth_o;
LAB_0000d67d:
    (*__ri)(0,pcVar7,iVar5);
  }
  else {
    if (__g_DeviceModes != 0) {
      uStack_128 = uStack_128 | 0x40000;
      iStack_e8 = param_2;
      pcVar7 = s____using_colorsbits_of__d_;
      iVar5 = param_2;
      goto LAB_0000d67d;
    }
    (*__ri)(0,s_WARNING____changing_depth_not_su);
  }
  if (_DAT_0000fbe4 == 0) {
    (*__ri)(0,s____calling_CDS__);
    pcVar1 = ___imp__ChangeDisplaySettingsA_8;
    iVar5 = (*___imp__ChangeDisplaySettingsA_8)(&stack0xfffffeb0,4);
    if (iVar5 != 0) {
      (*__ri)(0,s_failed__);
      _PrintCDSError();
      (*__ri)(0,s____trying_next_higher_resolution);
      iVar5 = 0;
      iVar6 = (*___imp__EnumDisplaySettingsA_12)(0,0,auStack_bc);
      do {
        if (iVar6 == 0) {
LAB_0000d7ea:
          (*__ri)(0,s__failed__);
          _PrintCDSError();
          (*__ri)(0,s____restoring_display_settings_);
          (*pcVar1)(0,0);
          _DAT_0000fbe4 = 0;
          _DAT_00011064 = 0;
          iVar5 = _GLW_CreateWindow(uStack_30,_DAT_00011054,_DAT_00011058,param_2);
          return 2 - (uint)(iVar5 != 0);
        }
        if (((_DAT_00011054 <= uStack_5c) && (_DAT_00011058 <= uStack_58)) && (0xe < uStack_60)) {
          if ((iVar5 != -1) && (iVar5 = (*pcVar1)(auStack_c8,4), iVar5 == 0)) {
            (*__ri)(0,s__ok_);
            iVar5 = _GLW_CreateWindow(uStack_20,_DAT_00011054,_DAT_00011058,param_2);
            if (iVar5 == 0) {
              (*__ri)(0,s____restoring_display_settings_);
              (*pcVar1)(0,0);
              return 2;
            }
            goto LAB_0000d8b9;
          }
          goto LAB_0000d7ea;
        }
        iVar5 = iVar5 + 1;
        iVar6 = (*___imp__EnumDisplaySettingsA_12)(0,iVar5,auStack_c8);
      } while( true );
    }
    (*__ri)(0,s_ok_);
    iVar5 = _GLW_CreateWindow(uStack_20,_DAT_00011054,_DAT_00011058,param_2);
    if (iVar5 == 0) {
      (*__ri)(0,s____restoring_display_settings_);
      (*pcVar1)(0,0);
      return 2;
    }
LAB_0000d8b9:
    _DAT_0000fbe4 = 1;
  }
  else {
    (*__ri)(0,s____already_fullscreen__avoiding_);
    iVar5 = _GLW_CreateWindow(uStack_20,_DAT_00011054,_DAT_00011058,param_2);
    if (iVar5 == 0) {
      (*__ri)(0,s____restoring_display_settings_);
      (*___imp__ChangeDisplaySettingsA_8)(0,0);
      return 2;
    }
  }
LAB_0000d90a:
  _memset(&uStack_15c,0,0x9c);
  uStack_12c = 0x9c;
  iVar5 = (*___imp__EnumDisplaySettingsA_12)(0,0xffffffff,&stack0xfffffeb0);
  if (iVar5 != 0) {
    _DAT_00011060 = uStack_e4;
  }
  _DAT_00011064 = iStack_18;
  return 0;
}



// ===========================================
// Function: _GLW_InitExtensions @ 0000d961
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLW_InitExtensions(void)

{
  char *pcVar1;
  
  if (*(int *)(__r_allowExtensions + 0x20) == 0) {
    (*__ri)(0,s_____IGNORING_OPENGL_EXTENSIONS__);
    return;
  }
  (*__ri)(0,s_Initializing_OpenGL_extensions_);
  _DAT_00011048 = 0;
  pcVar1 = _strstr((char *)0x10828,s_GL_S3_s3tc);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = s____GL_S3_s3tc_not_found_;
  }
  else if (*(int *)(__r_ext_compressed_textures + 0x20) == 0) {
    _DAT_00011048 = 0;
    pcVar1 = s____ignoring_GL_S3_s3tc_;
  }
  else {
    _DAT_00011048 = 1;
    pcVar1 = s____using_GL_S3_s3tc_;
  }
  (*__ri)(0,pcVar1);
  _DAT_0001104c = 0;
  pcVar1 = _strstr((char *)0x10828,s_EXT_texture_env_add);
  if (pcVar1 != (char *)0x0) {
    if (*(int *)(__r_ext_texture_env_add + 0x20) == 0) {
      _DAT_0001104c = 0;
    }
    else {
      _DAT_0001104c = 1;
    }
  }
  (*__ri)();
  __qwglSwapIntervalEXT = (*__qwglGetProcAddress)();
  if (__qwglSwapIntervalEXT == 0) {
    (*__ri)(0);
  }
  else {
    (*__ri)(0);
    *(undefined4 *)(__r_swapInterval + 0x14) = 1;
  }
  __qglMultiTexCoord2fARB = 0;
  __qglActiveTextureARB = 0;
  __qglClientActiveTextureARB = 0;
  pcVar1 = _strstr((char *)0x10828,s_GL_ARB_multitexture);
  if ((pcVar1 != (char *)0x0) && (*(int *)(__r_ext_multitexture + 0x20) != 0)) {
    __qglMultiTexCoord2fARB = (*__qwglGetProcAddress)();
    __qglActiveTextureARB = (*__qwglGetProcAddress)();
    __qglClientActiveTextureARB = (*__qwglGetProcAddress)();
    if (__qglActiveTextureARB == 0) goto LAB_0000db27;
    (*__qglGetIntegerv)(&DAT_000084e2,&DAT_0001102c);
    if (_DAT_0001102c < 2) {
      __qglMultiTexCoord2fARB = 0;
      __qglActiveTextureARB = 0;
      __qglClientActiveTextureARB = 0;
    }
  }
  (*__ri)();
LAB_0000db27:
  __qglTextureEnvCombineExists = 0;
  pcVar1 = _strstr((char *)0x10828,s_GL_EXT_texture_env_combine);
  if ((((pcVar1 != (char *)0x0) &&
       (pcVar1 = _strstr((char *)0x10828,s_GL_NV_texture_env_combine4), pcVar1 != (char *)0x0)) &&
      (NAN(*(float *)(__r_ext_texture_env_combine + 0x1c)) ==
       (*(float *)(__r_ext_texture_env_combine + 0x1c) == 0.0))) && (__qglActiveTextureARB != 0)) {
    __qglTextureEnvCombineExists = 1;
  }
  (*__ri)();
  __qglLockArraysEXT = 0;
  __qglUnlockArraysEXT = 0;
  pcVar1 = _strstr((char *)0x10828,s_GL_EXT_compiled_vertex_array);
  if (((pcVar1 == (char *)0x0) || (_DAT_00011040 == 2)) ||
     (*(int *)(__r_ext_compiled_vertex_array + 0x20) == 0)) {
    (*__ri)();
  }
  else {
    (*__ri)();
    __qglLockArraysEXT = (*__qwglGetProcAddress)();
    __qglUnlockArraysEXT = (*__qwglGetProcAddress)();
    if ((__qglLockArraysEXT == 0) || (__qglUnlockArraysEXT == 0)) {
      (*_DAT_0000fc3c)();
    }
  }
  __qwglGetDeviceGammaRamp3DFX = 0;
  __qwglSetDeviceGammaRamp3DFX = 0;
  pcVar1 = _strstr((char *)0x10828,s_WGL_3DFX_gamma_control);
  if (pcVar1 == (char *)0x0) {
    (*__ri)();
    return;
  }
  if ((*(int *)(__r_ignorehwgamma + 0x20) != 0) || (*(int *)(__r_ext_gamma_control + 0x20) == 0)) {
    (*__ri)();
    return;
  }
  __qwglGetDeviceGammaRamp3DFX = (*__qwglGetProcAddress)();
  __qwglSetDeviceGammaRamp3DFX = (*__qwglGetProcAddress)();
  if ((__qwglGetDeviceGammaRamp3DFX != 0) && (__qwglSetDeviceGammaRamp3DFX != 0)) {
    (*__ri)();
    return;
  }
  __qwglGetDeviceGammaRamp3DFX = 0;
  __qwglSetDeviceGammaRamp3DFX = 0;
  return;
}



// ===========================================
// Function: _GLW_CheckOSVersion @ 0000dcd0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLW_CheckOSVersion(void)

{
  int iVar1;
  undefined4 uVar2;
  uint local_94 [2];
  ushort uStack_8c;
  int iStack_88;
  
  local_94[0] = 0x94;
  __g_DeviceModes = 0;
  iVar1 = (*___imp__GetVersionExA_4)(local_94);
  if (iVar1 == 0) {
    (*__ri)(0,s_GLW_CheckOSVersion_____GetVersio);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if ((4 < local_94[0]) ||
       ((local_94[0] == 4 && ((iStack_88 == 2 || ((iStack_88 == 1 && (0x456 < uStack_8c)))))))) {
      __g_DeviceModes = 1;
      return uVar2;
    }
  }
  return uVar2;
}



// ===========================================
// Function: _GLimp_EndFrame @ 0000dd44
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_EndFrame(void)

{
  int iVar1;
  
  if (((*(int *)(__r_swapInterval + 0x14) != 0) &&
      (*(undefined4 *)(__r_swapInterval + 0x14) = 0, _DAT_00011068 == 0)) &&
     (__qwglSwapIntervalEXT != (code *)0x0)) {
    (*__qwglSwapIntervalEXT)(*(undefined4 *)(__r_swapInterval + 0x20));
  }
  iVar1 = _Q_stricmp(*(undefined4 *)(__r_drawBuffer + 4),s_GL_FRONT);
  if (iVar1 != 0) {
    if (_DAT_0001103c < 1) {
      (*___imp__SwapBuffers_4)(_DAT_0000fbc4);
    }
    else {
      iVar1 = (*__qwglSwapBuffers)(_DAT_0000fbc4);
      if (iVar1 == 0) {
        (*_DAT_0000fc3c)(0,s_GLimp_EndFrame_____SwapBuffers__);
        _QGL_EnableLogging(*(undefined4 *)(__r_logFile + 0x20));
        return;
      }
    }
  }
  _QGL_EnableLogging(*(undefined4 *)(__r_logFile + 0x20));
  return;
}



// ===========================================
// Function: _GLimp_Shutdown @ 0000dde5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_Shutdown(void)

{
  int iVar1;
  
  if (__qwglMakeCurrent != (code *)0x0) {
    (*__ri)(0,s_Shutting_down_OpenGL_subsystem_);
    _WG_RestoreGamma();
    if (__qwglMakeCurrent != (code *)0x0) {
      iVar1 = (*__qwglMakeCurrent)(0,0);
      (*__ri)(0,s____wglMakeCurrent__NULL__NULL___,(&_success)[iVar1 != 0]);
    }
    if (__r_allowSoftwareGL != 0) {
      iVar1 = (*__qwglDeleteContext)(__r_allowSoftwareGL);
      (*__ri)(0,s____deleting_GL_context___s_,(&_success)[iVar1 != 0]);
      __r_allowSoftwareGL = 0;
    }
    if (_DAT_0000fbc4 != 0) {
      iVar1 = (*___imp__ReleaseDC_8)(___imp__SetFocus_4,_DAT_0000fbc4);
      (*__ri)(0,s____releasing_DC___s_,(&_success)[iVar1 != 0]);
      _DAT_0000fbc4 = 0;
    }
    if (___imp__SetFocus_4 != 0) {
      (*__ri)(0,s____destroying_window_);
      (*___imp__ShowWindow_8)(___imp__SetFocus_4,0);
      (*___imp__DestroyWindow_4)(___imp__SetFocus_4);
      ___imp__SetFocus_4 = 0;
      _DAT_0000fbd4 = 0;
    }
    if (__r_maskMinidriver != (FILE *)0x0) {
      _fclose(__r_maskMinidriver);
      __r_maskMinidriver = (FILE *)0x0;
    }
    if (_DAT_0000fbe4 != 0) {
      (*__ri)(0,s____resetting_display_);
      (*___imp__ChangeDisplaySettingsA_8)(0,0);
      _DAT_0000fbe4 = 0;
    }
    _QGL_Shutdown();
    _memset(&_glConfig,0,0x1448);
    _memset(&_glState,0,0x2c);
  }
  return;
}



// ===========================================
// Function: _GLimp_LogComment @ 0000df41
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_LogComment(void)

{
  if (__r_maskMinidriver != (FILE *)0x0) {
    _fprintf(__r_maskMinidriver,s__s);
  }
  return;
}



// ===========================================
// Function: _GLimp_RenderThreadWrapper @ 0000df5e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_RenderThreadWrapper(void)

{
  (*__glimpRenderThread)();
  (*__qwglMakeCurrent)(_DAT_0000fbc4,0);
  return;
}



// ===========================================
// Function: _GLimp_SpawnRenderThread @ 0000df73
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool _GLimp_SpawnRenderThread(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = ___imp__CreateEventA_16;
  __renderCommandsEvent = (*___imp__CreateEventA_16)(0,1,0,0);
  __renderCompletedEvent = (*pcVar1)(0,1,0,0);
  uVar2 = 0;
  __renderActiveEvent = (*pcVar1)(0,1,0,0);
  __glimpRenderThread = uVar2;
  __renderThreadHandle =
       (*___imp__CreateThread_24)(0,0,_GLimp_RenderThreadWrapper,0,0,&_renderThreadId);
  return __renderThreadHandle != 0;
}



// ===========================================
// Function: _GLimp_RendererSleep @ 0000dfd8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLimp_RendererSleep(void)

{
  undefined4 uVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = (*__qwglMakeCurrent)(_DAT_0000fbc4,0);
  pcVar3 = ___imp__ResetEvent_4;
  if (iVar4 == 0) {
    __wglErrors = __wglErrors + 1;
  }
  (*___imp__ResetEvent_4)(__renderActiveEvent);
  pcVar2 = ___imp__SetEvent_4;
  (*___imp__SetEvent_4)(__renderCompletedEvent);
  (*___imp__WaitForSingleObject_8)(__renderCommandsEvent,0xffffffff);
  iVar4 = (*__qwglMakeCurrent)(_DAT_0000fbc4,__r_allowSoftwareGL);
  if (iVar4 == 0) {
    __wglErrors = __wglErrors + 1;
  }
  (*pcVar3)(__renderCompletedEvent);
  (*pcVar3)(__renderCommandsEvent);
  uVar1 = _smpData;
  (*pcVar2)(__renderActiveEvent);
  return uVar1;
}



// ===========================================
// Function: _GLimp_FrontEndSleep @ 0000e061
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_FrontEndSleep(void)

{
  int iVar1;
  
  (*___imp__WaitForSingleObject_8)(__renderCompletedEvent,0xffffffff);
  iVar1 = (*__qwglMakeCurrent)(_DAT_0000fbc4,__r_allowSoftwareGL);
  if (iVar1 == 0) {
    __wglErrors = __wglErrors + 1;
  }
  return;
}



// ===========================================
// Function: _GLimp_WakeRenderer @ 0000e08e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_WakeRenderer(undefined4 param_1)

{
  int iVar1;
  
  _smpData = param_1;
  iVar1 = (*__qwglMakeCurrent)(_DAT_0000fbc4,0);
  if (iVar1 == 0) {
    __wglErrors = __wglErrors + 1;
  }
  (*___imp__SetEvent_4)(__renderCommandsEvent);
  (*___imp__WaitForSingleObject_8)(__renderActiveEvent,0xffffffff);
  return;
}



// ===========================================
// Function: _GLimp_ChangeMode @ 0000e0cc
// ===========================================

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLimp_ChangeMode(void)

{
  code *pcVar1;
  int iVar2;
  int in_stack_00000010;
  int *piStack_14f4;
  undefined4 uStack_14f0;
  int local_14e8;
  int local_14e4;
  int local_14e0;
  int local_14dc;
  undefined2 uStack_14c4;
  undefined4 uStack_14c0;
  int iStack_147c;
  int iStack_1478;
  int iStack_1470;
  undefined1 auStack_1454 [12];
  undefined1 local_1448 [5188];
  undefined4 uStack_4;
  
  uStack_4 = 0xe0d6;
  _memcpy(local_1448,&_glConfig,0x1448);
  if ((-2 < in_stack_00000010) && (in_stack_00000010 < _g_NumDeviceModes)) {
    if (in_stack_00000010 == -1) {
      in_stack_00000010 = 0;
    }
    _DAT_00011054 = *(int *)(&_g_ValidResolutions + in_stack_00000010 * 8);
    _DAT_00011058 = *(int *)(&DAT_0000fbe4 + in_stack_00000010 * 8);
    _DAT_0001105c = 0x3f800000;
  }
  local_14e8 = 0;
  local_14e4 = 0;
  local_14e0 = _DAT_00011054;
  local_14dc = _DAT_00011058;
  if (_DAT_0000fbe4 == 0) {
    uStack_14f0 = 0x90c80000;
    piStack_14f4 = &local_14e8;
    (*___imp__AdjustWindowRect_12)();
  }
  pcVar1 = ___imp__SetWindowPos_28;
  piStack_14f4 = (int *)(local_14dc - local_14e4);
  uStack_14f0 = 4;
  (*___imp__SetWindowPos_28)(___imp__SetFocus_4,0,0,0,local_14e0 - local_14e8);
  if (_DAT_0000fbe4 != 0) {
    _memset(&piStack_14f4,0,0x9c);
    uStack_14c4 = 0x9c;
    iStack_147c = _DAT_00011054;
    iStack_1478 = _DAT_00011058;
    uStack_14c0 = 0x180000;
    if (*(int *)(__r_displayRefresh + 0x20) != 0) {
      uStack_14c0 = 0x580000;
      iStack_1470 = *(int *)(__r_displayRefresh + 0x20);
    }
    iVar2 = (*___imp__ChangeDisplaySettingsA_8)(&local_14e8,4);
    if (iVar2 != 0) {
      _memcpy(&_glConfig,auStack_1454,0x1448);
      (*pcVar1)(___imp__SetFocus_4,0,0,0,_DAT_00011054,_DAT_00011058,4);
      return 0;
    }
    _memset(&uStack_14f0,0,0x9c);
    uStack_14c0 = CONCAT22(uStack_14c0._2_2_,0x9c);
    iVar2 = (*___imp__EnumDisplaySettingsA_12)(0,0xffffffff,&local_14e4);
    if (iVar2 != 0) {
      _DAT_00011060 = iStack_147c;
    }
  }
  _IN_ChangeResolution();
  return 1;
}



// ===========================================
// Function: _GLimp_ChangeFullscreen @ 0000e29d
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLimp_ChangeFullscreen(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  undefined1 local_9c [48];
  undefined2 local_6c;
  undefined4 local_68;
  int local_24;
  int local_20;
  int local_18;
  
  pcVar1 = ___imp__SetWindowLongA_12;
  if (param_1 == 0) {
    if (_DAT_0000fbe4 != 0) {
      iStack_c4 = 0xffffffec;
      iStack_c8 = ___imp__SetFocus_4;
      _DAT_0000fbe4 = 0;
      _DAT_00011064 = 0;
      iStack_cc = 0xe3d6;
      (*___imp__SetWindowLongA_12)();
      iStack_cc = 0x10c80000;
      iVar4 = -0x10;
      iVar2 = ___imp__SetFocus_4;
      (*pcVar1)(___imp__SetFocus_4,0xfffffff0);
      iVar3 = 0;
      (*___imp__ChangeDisplaySettingsA_8)(0,0);
      iStack_cc = 0;
      iStack_c8 = 0;
      iStack_c4 = _DAT_00011054;
      (*___imp__AdjustWindowRect_12)(&iStack_cc,0x90c80000,0);
      pcVar1 = ___imp__SetWindowPos_28;
      iVar2 = iStack_cc - iVar2;
      (*___imp__SetWindowPos_28)(___imp__SetFocus_4,0,0,0,(iVar4 - iVar3) + -1,iVar2 + -1,4);
      (*pcVar1)(___imp__SetFocus_4,0,0,0,iVar4 - iVar3,iVar2,4);
    }
  }
  else if (_DAT_0000fbe4 == 0) {
    iStack_c4 = 0xe2d0;
    _memset(local_9c,0,0x9c);
    local_6c = 0x9c;
    local_24 = _DAT_00011054;
    local_20 = _DAT_00011058;
    local_68 = 0x180000;
    if (*(int *)(__r_displayRefresh + 0x20) != 0) {
      local_68 = 0x580000;
      local_18 = *(int *)(__r_displayRefresh + 0x20);
    }
    iVar2 = (*___imp__ChangeDisplaySettingsA_8)();
    pcVar1 = ___imp__SetWindowLongA_12;
    if (iVar2 != 0) {
      return 0;
    }
    (*___imp__SetWindowLongA_12)();
    iStack_c4 = 0xfffffff0;
    iStack_c8 = ___imp__SetFocus_4;
    iStack_cc = 0xe358;
    (*pcVar1)();
    pcVar1 = ___imp__SetWindowPos_28;
    iStack_cc = 4;
    (*___imp__SetWindowPos_28)(___imp__SetFocus_4,0,0,0,_DAT_00011054 + -1,_DAT_00011058 + -1);
    (*pcVar1)(___imp__SetFocus_4,0,0,0,_DAT_00011054,_DAT_00011058,4);
    _DAT_0000fbe4 = 1;
    _DAT_00011064 = 1;
  }
  iStack_c4 = 0xe467;
  _memset(local_9c,0,0x9c);
  local_6c = 0x9c;
  iVar2 = (*___imp__EnumDisplaySettingsA_12)();
  if (iVar2 != 0) {
    _DAT_00011060 = local_24;
  }
  _IN_ChangeResolution();
  return 1;
}



// ===========================================
// Function: _GLW_StartDriverAndSetMode @ 0000e4a6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall _GLW_StartDriverAndSetMode(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _GLW_SetMode(param_2,param_1);
  if (iVar1 == 1) {
    (*__ri)(0,s____WARNING__fullscreen_unavailab);
    return 0;
  }
  if (iVar1 != 2) {
    return 1;
  }
  (*__ri)(0,s____WARNING__could_not_set_the_gi);
  return 0;
}



// ===========================================
// Function: _GLW_LoadOpenGL @ 0000e4ea
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _GLW_LoadOpenGL(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *unaff_EBX;
  undefined1 auStack_3f8 [1016];
  
  iVar4 = -8 - (int)unaff_EBX;
  do {
    cVar1 = *unaff_EBX;
    unaff_EBX[(int)(auStack_3f8 + iVar4)] = cVar1;
    unaff_EBX = unaff_EBX + 1;
  } while (cVar1 != '\0');
  _Q_strlwr(&stack0xfffffc00);
  _GLW_GetValidModes();
  pcVar3 = _strstr(&stack0xfffffc00,s_opengl32);
  if ((pcVar3 == (char *)0x0) && (*(int *)(__r_maskMinidriver + 0x20) == 0)) {
    _DAT_0001103c = 1;
    (*__ri)(0);
    pcVar3 = _strstr(&stack0xfffffc00,s_3dfxvgl);
    if (pcVar3 != (char *)0x0) {
      _DAT_0001103c = 2;
    }
  }
  else {
    _DAT_0001103c = 0;
  }
  __putenv(s_FX_GLIDE_NO_SPLASH_0);
  iVar4 = _QGL_Init(auStack_3f8);
  if (iVar4 != 0) {
    iVar4 = *(int *)(__r_fullscreen + 0x20);
    uVar2 = *(undefined4 *)(__r_mode + 0x20);
    iVar5 = _GLW_SetMode();
    if (iVar5 == 1) {
      (*__ri)(0,s____WARNING__fullscreen_unavailab);
    }
    else {
      if (iVar5 != 2) goto LAB_0000e621;
      (*__ri)(0,s____WARNING__could_not_set_the_gi,uVar2);
    }
    if ((_DAT_0001103c == 0) &&
       (((*(int *)(__r_colorbits + 0x20) != 0x20 || (iVar4 != 0)) ||
        (*(int *)(__r_mode + 0x20) != 0)))) {
      iVar4 = _GLW_StartDriverAndSetMode();
      if (iVar4 != 0) {
LAB_0000e621:
        if (_DAT_0001103c == 2) {
          _DAT_00011064 = 1;
        }
        return 1;
      }
    }
  }
  _QGL_Shutdown();
  return 0;
}



// ===========================================
// Function: _GLW_StartOpenGL @ 0000e652
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLW_StartOpenGL(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  iVar2 = _GLW_LoadOpenGL();
  if (iVar2 != 0) {
    return;
  }
  iVar2 = _Q_stricmp(*(undefined4 *)(__r_glDriver + 4),s_opengl32);
  if (iVar2 == 0) {
    bVar1 = true;
  }
  else {
    iVar2 = _Q_stricmp(*(undefined4 *)(__r_glDriver + 4),s_3dfxvgl);
    if (iVar2 == 0) {
      iVar2 = _GLW_LoadOpenGL();
      if (iVar2 != 0) {
        (*___imp__SetPixelFormat_12)(s_r_glDriver,s_opengl32);
        *(undefined4 *)(__r_glDriver + 0x14) = 0;
        return;
      }
      goto LAB_0000e73e;
    }
  }
  iVar2 = _GLW_LoadOpenGL();
  if (iVar2 != 0) {
    (*___imp__SetPixelFormat_12)(s_r_glDriver,s_3dfxvgl);
    *(undefined4 *)(__r_glDriver + 0x14) = 0;
    return;
  }
  if (!bVar1) {
    iVar2 = _GLW_LoadOpenGL();
    if (iVar2 == 0) {
      (*_DAT_0000fc3c)(0,s_GLW_StartOpenGL_____could_not_lo);
    }
    (*___imp__SetPixelFormat_12)(s_r_glDriver,s_opengl32);
    *(undefined4 *)(__r_glDriver + 0x14) = 0;
    return;
  }
LAB_0000e73e:
  (*_DAT_0000fc3c)(0,s_GLW_StartOpenGL_____could_not_lo);
  return;
}



// ===========================================
// Function: _GLimp_Init @ 0000e751
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLimp_Init(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  char *pcStack_3b8;
  undefined *puStack_3b4;
  
  (*_DAT_0000fc5c)();
  (*__ri)();
  iVar2 = _GLW_CheckOSVersion();
  if (iVar2 == 0) {
    (*_DAT_0000fc3c)();
  }
  iVar2 = (*_DAT_0000fc5c)();
  _sscanf(*(char **)(iVar2 + 4),s__i);
  iVar2 = (*_DAT_0000fc5c)(s_win_wndproc);
  puVar4 = &_glw_state;
  _sscanf(*(char **)(iVar2 + 4),s__i);
  __r_allowSoftwareGL = (*_DAT_0000fc5c)(s_r_allowSoftwareGL,s_0,0x20,puVar4);
  __r_maskMinidriver = (*_DAT_0000fc5c)(s_r_maskMinidriver,s_0,0x20);
  _GLW_StartOpenGL();
  iVar2 = (*__qglGetString)();
  if (iVar2 == 0) {
    (*_DAT_0000fc3c)();
  }
  _Q_strncpyz();
  iVar2 = (*__qglGetString)();
  if (iVar2 == 0) {
    (*_DAT_0000fc3c)();
  }
  _Q_strncpyz();
  iVar2 = (*__qglGetString)();
  if (iVar2 == 0) {
    (*_DAT_0000fc3c)();
  }
  _Q_strncpyz();
  iVar2 = (*__qglGetString)();
  if (iVar2 == 0) {
    (*_DAT_0000fc3c)();
  }
  _Q_strncpyz();
  iVar2 = 0;
  do {
    cVar1 = (&_glConfig)[iVar2];
    (&stack0xfffffc00)[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  _Q_strlwr();
  iVar2 = _Q_stricmp();
  if (iVar2 != 0) {
    _DAT_00011040 = 0;
    (*___imp__SetPixelFormat_12)();
    pcVar3 = _strstr(&stack0xfffffbe0,s_voodoo_graphics_1_tmu_2_mb);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = _strstr(&stack0xfffffbe8,s_voodoo5);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = _strstr(&stack0xfffffbf0,s_geforce);
        if (pcVar3 == (char *)0x0) {
          (*___imp__SetPixelFormat_12)();
          pcVar3 = _strstr(&stack0xfffffbe8,s_rage_128);
          if (pcVar3 == (char *)0x0) {
            pcVar3 = _strstr(&stack0xfffffbf0,s_rage128);
            if (pcVar3 == (char *)0x0) {
              pcVar3 = _strstr(&stack0xfffffbf8,s_savage);
              if (pcVar3 != (char *)0x0) {
                (*___imp__SetPixelFormat_12)();
                (*___imp__SetPixelFormat_12)();
              }
              goto LAB_0000ea57;
            }
          }
        }
        (*___imp__SetPixelFormat_12)();
      }
      else {
        (*___imp__SetPixelFormat_12)();
        (*___imp__SetPixelFormat_12)();
      }
    }
    else {
      (*___imp__SetPixelFormat_12)();
      (*_DAT_0000fc5c)(s_r_picmip,s_1,0x21);
    }
  }
LAB_0000ea57:
  pcVar3 = _strstr(&stack0xfffffc00,s_banshee);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = _strstr(&stack0xfffffc08,s_voodoo3);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = _strstr(&stack0xfffffc10,s_voodoo_graphics_1_tmu_2_mb);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = _strstr(&stack0xfffffc18,s_glzicd);
        if (pcVar3 == (char *)0x0) {
          pcVar3 = _strstr(&stack0xfffffc20,s_rage_pro);
          if (pcVar3 == (char *)0x0) {
            pcVar3 = _strstr(&stack0xfffffc28,s_Rage_Pro);
            if (pcVar3 == (char *)0x0) {
              pcVar3 = _strstr(&stack0xfffffc30,s_rage_128);
              if (pcVar3 == (char *)0x0) {
                pcVar3 = _strstr(&stack0xfffffc38,s_permedia2);
                if (pcVar3 == (char *)0x0) {
                  pcVar3 = _strstr(&stack0xfffffc40,s_riva_128);
                  if (pcVar3 == (char *)0x0) {
                    _strstr((char *)&pcStack_3b8,s_riva_tnt_);
                  }
                  else {
                    _DAT_00011040 = 2;
                  }
                }
                else {
                  _DAT_00011040 = 4;
                }
              }
              goto LAB_0000eb8a;
            }
          }
          _DAT_00011040 = 3;
        }
      }
      goto LAB_0000eb8a;
    }
  }
  (*___imp__SetPixelFormat_12)();
  *(undefined4 *)(__r_stipplelines + 0x14) = 0;
  _DAT_00011040 = 1;
LAB_0000eb8a:
  puStack_3b4 = &_glConfig;
  pcStack_3b8 = s_r_lastValidRenderer;
  (*___imp__SetPixelFormat_12)();
  _GLW_InitExtensions();
  _WG_CheckHardwareGamma();
  return;
}



