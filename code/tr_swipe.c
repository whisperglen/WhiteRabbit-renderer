// ===========================================
// Function: _RE_SwipeBegin @ 000e8400
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RE_SwipeBegin(undefined4 param_1,float param_2,int param_3)

{
  int iVar1;
  
  if (___fltused == _lastswipeframe) {
    iVar1 = _numswipes;
    if (0x1f < _numswipes) {
      return;
    }
  }
  else {
    iVar1 = 0;
  }
  _numswipes = iVar1 + 1;
  (&DAT_00002004)[iVar1 * 0x1c06] = param_2;
  (&DAT_00002008)[iVar1 * 0x1c06] = param_1;
  *(undefined4 *)(iVar1 * 0x7018 + 0x2000) = 0xd;
  (&DAT_00002014)[iVar1 * 0x1c06] = 0;
  (&DAT_0000200c)[iVar1 * 0x1c06] = 0;
  (&DAT_00002010)[iVar1 * 0x1c06] = param_3;
  if ((param_3 < 0) && (NAN(param_2) == (param_2 == 0.0))) {
    (*__ri)(1,s_RE_SwipeBegin__Invalid_shader_ha);
    _lastswipeframe = ___fltused;
    return;
  }
  _lastswipeframe = ___fltused;
  return;
}



// ===========================================
// Function: _RE_SwipePoint @ 000e848e
// ===========================================

void _RE_SwipePoint(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _numswipes * 0x7018;
  if (*(int *)(iVar2 + -0x7004) < 0x400) {
    puVar1 = (undefined4 *)(iVar2 + -0x7000 + *(int *)(iVar2 + -0x7004) * 0x1c);
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    puVar1[3] = *param_2;
    puVar1[4] = param_2[1];
    puVar1[5] = param_2[2];
    puVar1[6] = param_3;
    *(int *)(iVar2 + -0x7004) = *(int *)(iVar2 + -0x7004) + 1;
  }
  return;
}



// ===========================================
// Function: _RE_SwipeEnd @ 000e84ee
// ===========================================

void _RE_SwipeEnd(void)

{
  return;
}



// ===========================================
// Function: _R_AddSwipeSurfaces @ 000e84ef
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_AddSwipeSurfaces(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_4;
  
  if (___fltused == _lastswipeframe) {
    if (_numswipes != 0) {
      iVar4 = 0;
      _DAT_000e9e1c = 0x3fe;
      _DAT_000e9e24 = 0x3fe000;
      if (0 < _numswipes) {
        piVar3 = &DAT_0000200c;
        iVar2 = _numswipes;
        do {
          local_4 = 0;
          if (piVar3[2] != 0) {
            if (*piVar3 != 0) {
              local_4 = _DAT_000ea238 - *piVar3;
            }
            *piVar3 = _DAT_000ea238;
            if (local_4 != 0) {
              piVar3[-1] = (int)((float)local_4 + (float)piVar3[-1]);
            }
            uVar1 = _R_GetShaderByHandle(piVar3[1]);
            _R_AddDrawSurf(piVar3 + -3,uVar1,0,0);
            iVar2 = _numswipes;
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 0x1c06;
        } while (iVar4 < iVar2);
      }
    }
    return;
  }
  _numswipes = 0;
  return;
}



// ===========================================
// Function: _RB_DrawSwipeSurface @ 000e8592
// ===========================================

void _RB_DrawSwipeSurface(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iStack_10;
  uint local_8 [2];
  
  if (param_1 == 0) {
    return;
  }
  fVar1 = *(float *)(param_1 + 4);
  local_8[0] = 0xffffffff;
  local_8[1] = 0;
  _RB_CheckOverflow(*(int *)(param_1 + 0x14) * 2,*(int *)(param_1 + 0x14) * 6);
  _RB_StreamBeginDrawSurf();
  iStack_10 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    pfVar3 = (float *)(param_1 + 0x30);
    do {
      fVar2 = 1.0 - (*(float *)(param_1 + 8) - *pfVar3) * (1.0 / fVar1);
      if ((fVar2 < 0.0 != (fVar2 == 0.0)) || (*(float *)(param_1 + 8) < *pfVar3)) {
        if (iStack_10 == *(int *)(param_1 + 0x14) + -1) {
          *(undefined4 *)(param_1 + 0x14) = 0;
        }
      }
      else {
        fVar2 = fVar2 - (float)((uint)(fVar2 - 1.0) & local_8[-((int)(fVar2 - 1.0) >> 0x1f)]);
        _RB_Color4f(fVar2,fVar2,fVar2,fVar2);
        fVar2 = (float)iStack_10 / (float)*(int *)(param_1 + 0x14);
        _RB_Texcoord2f(fVar2,0x3f800000);
        _RB_Vertex3fv(pfVar3 + -6);
        _RB_Texcoord2f(fVar2,0);
        _RB_Vertex3fv(pfVar3 + -3);
      }
      iStack_10 = iStack_10 + 1;
      pfVar3 = pfVar3 + 7;
    } while (iStack_10 < *(int *)(param_1 + 0x14));
  }
  _RB_StreamEndDrawSurf();
  return;
}



