// ===========================================
// Function: _CullSprite @ 00007600
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _CullSprite(int param_1)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float afStack_20 [8];
  
  iVar7 = 0;
  bVar4 = false;
  if (0 < _DAT_00009280 + 4) {
    pfVar8 = (float *)&DAT_000091a0;
    do {
      bVar3 = false;
      bVar2 = false;
      iVar6 = 0;
      pfVar5 = (float *)(param_1 + 8);
      do {
        fVar1 = *pfVar8 * *pfVar5 + pfVar5[-1] * pfVar8[-1] + pfVar5[-2] * pfVar8[-2];
        afStack_20[iVar6] = fVar1;
        if (pfVar8[1] < fVar1 == (NAN(pfVar8[1]) || NAN(fVar1))) {
          bVar3 = true;
        }
        else {
          bVar2 = true;
          if (bVar3) goto LAB_00007689;
        }
        iVar6 = iVar6 + 1;
        pfVar5 = pfVar5 + 3;
      } while (iVar6 < 4);
      if (!bVar2) {
        return 2;
      }
LAB_00007689:
      bVar4 = (bool)(bVar4 | bVar3);
      iVar7 = iVar7 + 1;
      pfVar8 = pfVar8 + 5;
    } while (iVar7 < _DAT_00009280 + 4);
    if (bVar4) {
      return 1;
    }
  }
  return 0;
}



// ===========================================
// Function: _RB_DrawSprite @ 000076c2
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_DrawSprite(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
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
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(int *)(param_1 + 4) == 0) {
    (*__ri)(3,s_No_model_found_for_Sprite_);
    return;
  }
  iVar6 = _R_GetModelByHandle(*(int *)(param_1 + 4));
  iVar7 = *(int *)(iVar6 + 100);
  fVar1 = *(float *)(iVar7 + 8);
  fVar2 = *(float *)(iVar7 + 0xc);
  fVar5 = *(float *)(iVar7 + 0x10) * *(float *)(param_1 + 0x18);
  if (*(int *)(*(int *)(iVar7 + 0x14) + 0x9c) == 0) {
    fStack_48 = _DAT_0000903c;
    fStack_44 = _DAT_00009040;
    fStack_40 = _DAT_00009044;
    if (_DAT_00009120 == 0) {
      fStack_4c = (float)___real_bff0000000000000;
      fStack_54 = _DAT_00009030 * fStack_4c;
      fStack_50 = _DAT_00009034 * fStack_4c;
      fStack_4c = fStack_4c * _DAT_00009038;
    }
    else {
      fStack_54 = _DAT_00009030;
      fStack_50 = _DAT_00009034;
      fStack_4c = _DAT_00009038;
    }
  }
  else {
    iVar7 = *(int *)(*(int *)(*(int *)(iVar6 + 100) + 0x14) + 0x9c);
    if (iVar7 == 2) {
      fStack_54 = *(float *)(param_1 + 0x28);
      fStack_50 = *(float *)(param_1 + 0x2c);
      fStack_4c = *(float *)(param_1 + 0x30);
      fStack_48 = *(float *)(param_1 + 0x34);
      fStack_44 = *(float *)(param_1 + 0x38);
      fStack_40 = *(float *)(param_1 + 0x3c);
    }
    else if (iVar7 == 3) {
      fStack_3c = _DAT_00009024;
      fStack_38 = _DAT_00009028;
      fStack_34 = _DAT_0000902c;
      if ((float)___real_3feffec13b9f127f < _DAT_0000902c) {
        return;
      }
      if (_DAT_0000902c < (float)___real_bfeffec13b9f127f !=
          (NAN(_DAT_0000902c) || NAN((float)___real_bfeffec13b9f127f))) {
        return;
      }
      fStack_48 = 0.0;
      fStack_44 = 0.0;
      fStack_40 = 1.0;
      fStack_54 = _DAT_00009028;
      fStack_50 = -_DAT_00009024;
      fStack_4c = 0.0;
      _VectorNormalize(&fStack_54);
    }
    else if (iVar7 == 1) {
      __CIatan2();
      fVar8 = (float10)__CIsin();
      fVar3 = (float)fVar8;
      fVar8 = (float10)__CIcos();
      fVar4 = (float)fVar8;
      fStack_54 = fVar4 * _DAT_00009030 + fVar3 * _DAT_0000903c;
      fStack_48 = _DAT_0000903c * fVar4 - fVar3 * _DAT_00009030;
      fStack_50 = _DAT_00009040 * fVar3 + _DAT_00009034 * fVar4;
      fStack_44 = _DAT_00009040 * fVar4 - fVar3 * _DAT_00009034;
      fStack_4c = _DAT_00009044 * fVar3 + _DAT_00009038 * fVar4;
      fStack_40 = _DAT_00009044 * fVar4 - _DAT_00009038 * fVar3;
    }
  }
  fStack_48 = fVar5 * fStack_48;
  fStack_44 = fStack_44 * fVar5;
  fStack_40 = fStack_40 * fVar5;
  fStack_54 = fStack_54 * fVar5;
  fStack_50 = fStack_50 * fVar5;
  fStack_4c = fVar5 * fStack_4c;
  fStack_24 = *(float *)(param_1 + 0xc) + fVar2 * fStack_48;
  fStack_20 = fStack_44 * fVar2 + *(float *)(param_1 + 0x10);
  fStack_1c = fStack_40 * fVar2 + *(float *)(param_1 + 0x14);
  fVar5 = -fVar1;
  fStack_30 = fStack_24 + fVar5 * fStack_54;
  fStack_2c = fStack_20 + fVar5 * fStack_50;
  fStack_28 = fStack_1c + fStack_4c * fVar5;
  fStack_24 = fStack_24 + fStack_54 * fVar1;
  fStack_20 = fStack_20 + fStack_50 * fVar1;
  fStack_1c = fStack_1c + fStack_4c * fVar1;
  fVar2 = -fVar2;
  fStack_c = fVar2 * fStack_48 + *(float *)(param_1 + 0xc);
  fStack_8 = fVar2 * fStack_44 + *(float *)(param_1 + 0x10);
  fStack_4 = fVar2 * fStack_40 + *(float *)(param_1 + 0x14);
  fStack_18 = fStack_c + fVar5 * fStack_54;
  fStack_14 = fStack_8 + fVar5 * fStack_50;
  fStack_10 = fStack_4c * fVar5 + fStack_4;
  fStack_c = fStack_c + fStack_54 * fVar1;
  fStack_8 = fStack_8 + fStack_50 * fVar1;
  fStack_4 = fStack_4c * fVar1 + fStack_4;
  iVar7 = _CullSprite(&fStack_30);
  if (iVar7 == 2) {
    return;
  }
  _RB_CheckOverflow(4,6);
  *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183cc) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183c8) = *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183cc);
  *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183c4) = *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183c8);
  *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183c0) = *(undefined4 *)(_DAT_0031fe94 * 4 + 0x2183c4);
  _DAT_0031feac = 1;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30c0) = 0;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30c4) = 0;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30d0) = 0x3f800000;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30d4) = 0;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30e0) = 0;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30e4) = 0x3f800000;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30f0) = 0x3f800000;
  *(undefined4 *)(_DAT_0031fe94 * 0x10 + 0x1a30f4) = 0x3f800000;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ac0) = fStack_30;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ac4) = fStack_2c;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ac8) = fStack_28;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ad0) = fStack_24;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ad4) = fStack_20;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ad8) = fStack_1c;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ae0) = fStack_18;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ae4) = fStack_14;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8ae8) = fStack_10;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8af0) = fStack_c;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8af4) = fStack_8;
  *(float *)(_DAT_0031fe94 * 0x10 + 0xb8af8) = fStack_4;
  *(int *)(&_tess + _DAT_0031fe90 * 4) = _DAT_0031fe94 + 2;
  *(int *)(&DAT_00008e44 + _DAT_0031fe90 * 4) = _DAT_0031fe94 + 1;
  *(int *)(_RB_CheckOverflow + _DAT_0031fe90 * 4) = _DAT_0031fe94;
  *(int *)(&DAT_00008e4c + _DAT_0031fe90 * 4) = _DAT_0031fe94 + 2;
  *(int *)(_VectorNormalize + _DAT_0031fe90 * 4) = _DAT_0031fe94 + 3;
  *(int *)(&DAT_00008e54 + _DAT_0031fe90 * 4) = _DAT_0031fe94 + 1;
  _DAT_0031fe94 = _DAT_0031fe94 + 4;
  _DAT_0031fe90 = _DAT_0031fe90 + 6;
  DAT_0031fea4 = *(undefined1 *)(param_1 + 0x44);
  return;
}



// ===========================================
// Function: _SPR_RegisterSprite @ 00007d4c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * _SPR_RegisterSprite(undefined4 param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  undefined1 local_104 [260];
  
  iVar3 = 0;
  _COM_StripExtension(param_1,local_104);
  fVar1 = (float)_R_FindShader(local_104,0xffffffff,0,0,0);
  if (fVar1 == 0.0) {
    return (float *)0x0;
  }
  pfVar2 = (float *)(*___CIsin)(0x18);
  if (pfVar2 == (float *)0x0) {
    (*_DAT_00008e64)(1,s_Could_not_allocate_memory_for_sp,param_1);
  }
  pfVar2[5] = fVar1;
  if ((*(int *)((int)fVar1 + 0x194) == 0) || (*(int *)(*(int *)((int)fVar1 + 0x194) + 8) == 0)) {
    if ((*(int *)((int)fVar1 + 0x1b8) != 0) && (*(int *)(*(int *)((int)fVar1 + 0x1b8) + 8) != 0)) {
      iVar3 = *(int *)(*(int *)((int)fVar1 + 0x1b8) + 8);
      goto LAB_00007ddf;
    }
  }
  else {
    iVar3 = *(int *)(*(int *)((int)fVar1 + 0x194) + 8);
LAB_00007ddf:
    if (iVar3 != 0) goto LAB_00007df4;
  }
  (*_DAT_00008e64)(1,s_Could_not_find_image_for_sprite_,param_1);
LAB_00007df4:
  *pfVar2 = (float)*(int *)(iVar3 + 0x40);
  pfVar2[1] = (float)*(int *)(iVar3 + 0x44);
  fVar1 = (float)___real_3fe0000000000000;
  pfVar2[2] = *pfVar2 * fVar1;
  pfVar2[3] = fVar1 * pfVar2[1];
  pfVar2[4] = *(float *)((int)pfVar2[5] + 0xa0);
  return pfVar2;
}



