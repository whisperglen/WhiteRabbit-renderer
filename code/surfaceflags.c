// ===========================================
// Function: _ParseSurfaceParm @ 00003700
// ===========================================

void _ParseSurfaceParm(undefined4 param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  iVar2 = 0;
  ppuVar3 = &_infoParms;
  do {
    iVar1 = _Q_stricmp(param_1,*ppuVar3);
    if (iVar1 == 0) {
      *param_2 = *param_2 | (&DAT_00002008)[iVar2 * 4];
      *param_3 = *param_3 | (&DAT_0000200c)[iVar2 * 4];
      if ((&DAT_00002004)[iVar2 * 4] != 0) {
        *param_3 = *param_3 & 0xfffffffe;
      }
      return;
    }
    ppuVar3 = ppuVar3 + 4;
    iVar2 = iVar2 + 1;
  } while ((int)ppuVar3 < 0x2240);
  return;
}



