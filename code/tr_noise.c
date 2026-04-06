// ===========================================
// Function: _R_NoiseInit @ 00007046
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_NoiseInit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  _srand(0x3e9);
  iVar2 = 0;
  do {
    iVar1 = _rand();
    *(float *)((int)&_s_noise_table + iVar2) =
         ((float)iVar1 / (float)___real_40dfffc000000000 +
         (float)iVar1 / (float)___real_40dfffc000000000) - (float)___real_3ff0000000000000;
    iVar1 = _rand();
    iVar3 = iVar2 + 4;
    *(uint *)(iVar2 + 0x2000) =
         (int)ROUND(((double)iVar1 / ___real_40dfffc000000000) * ___real_406fe00000000000) & 0xff;
    iVar2 = iVar3;
  } while (iVar3 < 0x400);
  return;
}



// ===========================================
// Function: _R_NoiseGet4f @ 000070ce
// ===========================================

float10 _R_NoiseGet4f(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  uint uVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  uint uStack_68;
  int iStack_60;
  float afStack_5c [22];
  
  uVar14 = (ulonglong)unaff_EBX;
  uVar13 = CONCAT44(unaff_ESI,unaff_EDI);
  _floor((double)param_1);
  iVar5 = __ftol2_sse(uVar13,uVar14);
  _floor((double)param_2);
  iVar6 = __ftol2_sse();
  _floor((double)param_3);
  iVar7 = __ftol2_sse();
  _floor((double)param_4);
  uStack_68 = __ftol2_sse();
  fVar4 = afStack_5c[1];
  fVar1 = (float)(int)uStack_68;
  iVar9 = 0;
  fVar2 = 1.0 - afStack_5c[1];
  fVar3 = 1.0 - afStack_5c[3];
  do {
    uVar8 = (int)(param_3 - (float)iVar7) + *(int *)((uStack_68 & 0xff) * 4 + 0x2000);
    uVar10 = *(int *)((uVar8 & 0xff) * 4 + 0x2000) + iVar6;
    uVar12 = *(int *)((uVar10 & 0xff) * 4 + 0x2000) + iVar5;
    uVar10 = *(int *)((uVar10 + 1 & 0xff) * 4 + 0x2000) + iVar5;
    uVar8 = *(int *)((uVar8 + 1 & 0xff) * 4 + 0x2000) + iStack_60;
    uVar11 = *(int *)((uVar8 & 0xff) * 4 + 0x2000) + iVar5;
    uVar8 = *(int *)((uVar8 + 1 & 0xff) * 4 + 0x2000) + iVar5;
    uStack_68 = uStack_68 + 1;
    iVar9 = iVar9 + 1;
    afStack_5c[iVar9] =
         (((float)(&_s_noise_table)[*(int *)((uVar12 & 0xff) * 4 + 0x2000)] * fVar3 +
          (float)(&_s_noise_table)[*(int *)((uVar12 + 1 & 0xff) * 4 + 0x2000)] * afStack_5c[3]) *
          fVar2 + ((float)(&_s_noise_table)[*(int *)((uVar10 & 0xff) * 4 + 0x2000)] * fVar3 +
                  (float)(&_s_noise_table)[*(int *)((uVar10 + 1 & 0xff) * 4 + 0x2000)] *
                  afStack_5c[3]) * fVar4) * (1.0 - afStack_5c[0]) +
         (((float)(&_s_noise_table)[*(int *)((uVar11 & 0xff) * 4 + 0x2000)] * fVar3 +
          (float)(&_s_noise_table)[*(int *)((uVar11 + 1 & 0xff) * 4 + 0x2000)] * afStack_5c[3]) *
          fVar2 + ((float)(&_s_noise_table)[*(int *)((uVar8 & 0xff) * 4 + 0x2000)] * fVar3 +
                  (float)(&_s_noise_table)[*(int *)((uVar8 + 1 & 0xff) * 4 + 0x2000)] *
                  afStack_5c[3]) * fVar4) * afStack_5c[0];
    iVar6 = iStack_60;
  } while (iVar9 < 2);
  return (float10)((1.0 - (param_4 - fVar1)) * afStack_5c[1] + afStack_5c[2] * (param_4 - fVar1));
}



