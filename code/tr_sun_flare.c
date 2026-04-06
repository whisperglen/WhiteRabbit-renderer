// ===========================================
// Function: _VectorFromString @ 0000b500
// ===========================================

bool _VectorFromString(char *param_1)

{
  int iVar1;
  
  iVar1 = _sscanf(param_1,s__f__f__f);
  return iVar1 == 3;
}



// ===========================================
// Function: lens_flare @ 0000b52a
// ===========================================

/* public: __thiscall lens_flare::lens_flare(void) */

void __thiscall lens_flare::lens_flare(lens_flare *this)

{
  *(undefined4 *)(this + 0x174) = 0x3f800000;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x178) = 0x3f800000;
  *(undefined4 *)(this + 0x17c) = 0x3f800000;
  *(undefined4 *)(this + 0x180) = 0x3f800000;
  return;
}



// ===========================================
// Function: ~lens_flare @ 0000b54d
// ===========================================

/* public: virtual __thiscall lens_flare::~lens_flare(void) */

void __thiscall lens_flare::~lens_flare(lens_flare *this)

{
  *(undefined ***)this = &_vftable_;
  return;
}



// ===========================================
// Function: SetColor @ 0000b554
// ===========================================

/* public: void __thiscall lens_flare::SetColor(float const * const) */

void __thiscall lens_flare::SetColor(lens_flare *this,float *param_1)

{
  *(float *)(this + 0x174) = *param_1;
  *(float *)(this + 0x178) = param_1[1];
  *(float *)(this + 0x17c) = param_1[2];
  return;
}



// ===========================================
// Function: `scalar_deleting_destructor' @ 0000b575
// ===========================================

/* public: virtual void * __thiscall lens_flare::`scalar deleting destructor'(unsigned int) */

void * __thiscall lens_flare::_scalar_deleting_destructor_(lens_flare *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===========================================
// Function: dlight_lens_flare @ 0000b594
// ===========================================

/* public: __thiscall dlight_lens_flare::dlight_lens_flare(void) */

void __thiscall dlight_lens_flare::dlight_lens_flare(dlight_lens_flare *this)

{
  *(undefined4 *)(this + 0x174) = 0x3f800000;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x178) = 0x3f800000;
  *(undefined4 *)(this + 0x17c) = 0x3f800000;
  *(undefined4 *)(this + 0x180) = 0x3f800000;
  return;
}



// ===========================================
// Function: ~dlight_lens_flare @ 0000b5b7
// ===========================================

/* public: virtual __thiscall dlight_lens_flare::~dlight_lens_flare(void) */

void __thiscall dlight_lens_flare::~dlight_lens_flare(dlight_lens_flare *this)

{
  *(undefined ***)this = &lens_flare::_vftable_;
  return;
}



// ===========================================
// Function: `scalar_deleting_destructor' @ 0000b5be
// ===========================================

/* public: virtual void * __thiscall dlight_lens_flare::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
dlight_lens_flare::_scalar_deleting_destructor_(dlight_lens_flare *this,uint param_1)

{
  *(undefined ***)this = &lens_flare::_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===========================================
// Function: SetVect @ 0000b5dd
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall lens_flare::SetVect(float const * const) */

void __thiscall lens_flare::SetVect(lens_flare *this,float *param_1)

{
  float fVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  if (this[0x198] != (lens_flare)0x0) {
    local_18 = *param_1 - _DAT_0000e830;
    local_14 = param_1[1] - _DAT_0000e834;
    local_10 = param_1[2] - _DAT_0000e838;
    _VectorRotate(&local_18,0xe83c,&local_c);
    *(float *)(this + 0x168) = _DAT_0000e698 + local_c;
    *(float *)(this + 0x16c) = _DAT_0000e69c + fStack_8;
    *(float *)(this + 0x170) = _DAT_0000e6a0 + fStack_4;
    _VectorNormalize(&local_18);
    fVar1 = (float)___real_40d0000000000000;
    *(float *)(this + 0x15c) = _DAT_0000e698 + local_18 * fVar1;
    *(float *)(this + 0x160) = local_14 * fVar1 + _DAT_0000e69c;
    *(float *)(this + 0x164) = fVar1 * local_10 + _DAT_0000e6a0;
    return;
  }
  *(float *)(this + 0x168) = *param_1;
  *(float *)(this + 0x16c) = param_1[1];
  *(float *)(this + 0x170) = param_1[2];
  *(float *)(this + 0x15c) = *param_1;
  *(float *)(this + 0x160) = param_1[1];
  *(float *)(this + 0x164) = param_1[2];
  return;
}



// ===========================================
// Function: InPortalSky @ 0000b6ed
// ===========================================

/* public: void __thiscall lens_flare::InPortalSky(void) */

void __thiscall lens_flare::InPortalSky(lens_flare *this)

{
  this[0x198] = (lens_flare)0x1;
  return;
}



// ===========================================
// Function: NotInPortalSky @ 0000b6f5
// ===========================================

/* public: void __thiscall lens_flare::NotInPortalSky(void) */

void __thiscall lens_flare::NotInPortalSky(lens_flare *this)

{
  this[0x198] = (lens_flare)0x0;
  return;
}



// ===========================================
// Function: CheckRange @ 0000b6fd
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: bool __thiscall lens_flare::CheckRange(void) */

bool __thiscall lens_flare::CheckRange(lens_flare *this)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(this + 0x168) - _DAT_0000dd78;
  local_8 = *(float *)(this + 0x16c) - _DAT_0000dd7c;
  local_4 = *(float *)(this + 0x170) - _DAT_0000dd80;
  _VectorNormalizeFast(&local_c);
  fVar1 = _DAT_0000dd8c * local_4 + _DAT_0000dd84 * local_c + _DAT_0000dd88 * local_8;
  *(float *)(this + 0x18c) = fVar1;
  if (*(float *)(this + 4) < fVar1 != (NAN(*(float *)(this + 4)) || NAN(fVar1))) {
    return true;
  }
  return false;
}



// ===========================================
// Function: CheckRay @ 0000b78c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: bool __thiscall lens_flare::CheckRay(void) */

bool __thiscall lens_flare::CheckRay(lens_flare *this)

{
  int iVar1;
  undefined1 auStack_3c [8];
  float fStack_34;
  byte bStack_10;
  uint uStack_c;
  
  iVar1 = (*__R_RotateForViewer)();
  (**(code **)(iVar1 + 0x1c))
            (auStack_3c,&DAT_0000dd78,0,0,this + 0x15c,0xffffffff,0x2010001,0,1,
             s_lens_flare__CheckRay);
  if ((uStack_c & 0x2000000) != 0) {
    return false;
  }
  if (this[0x198] != (lens_flare)0x0) {
    return (bool)(bStack_10 >> 2 & 1);
  }
  if (NAN(fStack_34) != (fStack_34 == 1.0)) {
    return true;
  }
  return false;
}



// ===========================================
// Function: ScreenCalc @ 0000b80b
// ===========================================

/* public: bool __thiscall lens_flare::ScreenCalc(void) */

bool __thiscall lens_flare::ScreenCalc(lens_flare *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  float local_20 [8];
  
  local_20[4] = *(float *)(this + 0x168);
  bVar3 = true;
  local_20[5] = *(float *)(this + 0x16c);
  local_20[6] = *(float *)(this + 0x170);
  local_20[3] = 0.0;
  local_20[2] = 0.0;
  local_20[1] = 0.0;
  local_20[0] = 0.0;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 4;
    *(float *)((int)local_20 + iVar2) =
         *(float *)(iVar2 + 0xe5a8) * local_20[6] +
         *(float *)(iVar2 + 0xe598) * local_20[5] +
         *(float *)(iVar2 + 0xe588) * local_20[4] + *(float *)((int)local_20 + iVar2) +
         *(float *)(iVar2 + 0xe5b8);
    iVar2 = iVar1;
  } while (iVar1 < 0x10);
  local_20[7] = 0.0;
  local_20[6] = 0.0;
  local_20[5] = 0.0;
  local_20[4] = 0.0;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 4;
    *(float *)((int)local_20 + iVar2 + 0x10) =
         *(float *)(iVar2 + 0xe42c) * local_20[3] +
         *(float *)(iVar2 + 0xe41c) * local_20[2] +
         *(float *)(iVar2 + 0xe40c) * local_20[1] +
         *(float *)(iVar2 + 0xe3fc) * local_20[0] + *(float *)((int)local_20 + iVar2 + 0x10);
    iVar2 = iVar1;
  } while (iVar1 < 0x10);
  if ((local_20[7] < local_20[4] != (local_20[7] == local_20[4])) || (local_20[4] <= -local_20[7]))
  {
    bVar3 = false;
  }
  if ((local_20[7] <= local_20[5]) || (local_20[5] <= -local_20[7])) {
    bVar3 = false;
  }
  if ((local_20[7] <= local_20[6]) || (local_20[6] <= -local_20[7])) {
    bVar3 = false;
  }
  *(float *)(this + 0x184) = local_20[4] / local_20[7];
  *(float *)(this + 0x188) = local_20[5] / local_20[7];
  return bVar3;
}



// ===========================================
// Function: Try @ 0000b97e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall lens_flare::Try(void) */

void __thiscall lens_flare::Try(lens_flare *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  lens_flare *this_00;
  int iVar8;
  lens_flare *plVar9;
  
  bVar7 = ScreenCalc(this);
  if (((bVar7) && (bVar7 = CheckRange(this_00), bVar7)) && (bVar7 = CheckRay(this), bVar7)) {
    fVar1 = *(float *)(this + 0x184);
    fVar6 = (float)___real_c000000000000000;
    iVar8 = 0;
    fVar2 = *(float *)(this + 0x188);
    fVar3 = (*(float *)(this + 0x18c) - *(float *)(this + 4)) / (1.0 - *(float *)(this + 4));
    if (0 < *(int *)(this + 0xc)) {
      plVar9 = this + 0x10;
      do {
        fVar4 = fVar1 * fVar6 * *(float *)(plVar9 + 4) + *(float *)(this + 0x184);
        fVar5 = fVar6 * fVar2 * *(float *)(plVar9 + 4) + *(float *)(this + 0x188);
        _RB_Color4f(*(undefined4 *)(this + 0x174),*(undefined4 *)(this + 0x178),
                    *(undefined4 *)(this + 0x17c),
                    fVar3 * *(float *)(this + 0x180) * *(float *)(plVar9 + 0xc));
        _RB_StreamBegin(*(float *)(plVar9 + 8),0);
        _RB_Texcoord2f(0,0);
        _RB_Vertex2f(fVar4 - *(float *)plVar9,*(float *)plVar9 + fVar5);
        _RB_Texcoord2f(0x3f800000,0);
        _RB_Vertex2f(*(float *)plVar9 + fVar4,*(float *)plVar9 + fVar5);
        _RB_Texcoord2f(0,0x3f800000);
        _RB_Vertex2f(fVar4 - *(float *)plVar9,fVar5 - *(float *)plVar9);
        _RB_Texcoord2f(0x3f800000,0x3f800000);
        _RB_Vertex2f(*(float *)plVar9 + fVar4,fVar5 - *(float *)plVar9);
        _RB_StreamEnd();
        iVar8 = iVar8 + 1;
        plVar9 = plVar9 + 0x10;
      } while (iVar8 < *(int *)(this + 0xc));
    }
    *(undefined4 *)(this + 400) = _DAT_0000dbdc;
    *(undefined4 *)(this + 0x158) = 1;
    *(float *)(this + 0x194) = fVar3 * fVar3 * fVar3 * fVar3 * *(float *)(this + 8);
  }
  return;
}



// ===========================================
// Function: Try @ 0000bb8e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall dlight_lens_flare::Try(void) */

void __thiscall dlight_lens_flare::Try(dlight_lens_flare *this)

{
  float fVar1;
  bool bVar2;
  
  fVar1 = *(float *)(__r_lightcoronasize + 0x1c);
  lens_flare::Try((lens_flare *)this);
  bVar2 = lens_flare::CheckRay((lens_flare *)this);
  if (bVar2) {
    lens_flare::CheckRange((lens_flare *)this);
    if (0.0 < *(float *)(this + 0x18c)) {
      _RB_Color4f(*(undefined4 *)(this + 0x174),*(undefined4 *)(this + 0x178),
                  *(undefined4 *)(this + 0x17c),*(undefined4 *)(this + 0x180));
      _RB_StreamBegin(*(undefined4 *)(this + 0x1a0),0);
      _RB_Texcoord2f(0,0);
      _RB_Vertex2f(*(float *)(this + 0x184) - fVar1,fVar1 + *(float *)(this + 0x188));
      _RB_Texcoord2f(0x3f800000,0);
      _RB_Vertex2f(fVar1 + *(float *)(this + 0x184),fVar1 + *(float *)(this + 0x188));
      _RB_Texcoord2f(0,0x3f800000);
      _RB_Vertex2f(*(float *)(this + 0x184) - fVar1,*(float *)(this + 0x188) - fVar1);
      _RB_Texcoord2f(0x3f800000,0x3f800000);
      _RB_Vertex2f(fVar1 + *(float *)(this + 0x184),*(float *)(this + 0x188) - fVar1);
      _RB_StreamEnd();
      return;
    }
  }
  return;
}



// ===========================================
// Function: ScreenBlend @ 0000bd23
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall lens_flare::ScreenBlend(void) */

void __thiscall lens_flare::ScreenBlend(lens_flare *this)

{
  int iVar1;
  float fVar2;
  
  if ((*(int *)(this + 0x150) != 0) && (*(int *)(this + 0x158) != 0)) {
    iVar1 = *(int *)(this + 0x154);
    if ((_DAT_0000dbdc - *(int *)(this + 400) <= iVar1) &&
       (fVar2 = ((float)(iVar1 - (_DAT_0000dbdc - *(int *)(this + 400))) / (float)iVar1) *
                *(float *)(this + 0x194),
       fVar2 < (float)___real_3f1a36e2e0000000 == (fVar2 == (float)___real_3f1a36e2e0000000))) {
      _RB_Color4f(0x3f800000,0x3f800000,0x3f800000,fVar2);
      _RB_StreamBegin(*(undefined4 *)(this + 0x150),0);
      _RB_Vertex2f(___real_bf800000,___real_bf800000);
      _RB_Vertex2f(0x3f800000,___real_bf800000);
      _RB_Vertex2f(___real_bf800000,0x3f800000);
      _RB_Vertex2f(0x3f800000,0x3f800000);
      _RB_StreamEnd();
      return;
    }
    *(undefined4 *)(this + 0x158) = 0;
  }
  return;
}



// ===========================================
// Function: tmpRiFile @ 0000be14
// ===========================================

/* public: __thiscall tmpRiFile::tmpRiFile(void) */

void __thiscall tmpRiFile::tmpRiFile(tmpRiFile *this)

{
  *(undefined4 *)(this + 4) = 0;
  *this = (tmpRiFile)0x0;
  return;
}



// ===========================================
// Function: exists @ 0000be21
// ===========================================

/* public: bool __thiscall tmpRiFile::exists(void) */

bool __thiscall tmpRiFile::exists(tmpRiFile *this)

{
  return (bool)*this;
}



// ===========================================
// Function: close @ 0000be24
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall tmpRiFile::close(void) */

void __thiscall tmpRiFile::close(tmpRiFile *this)

{
  if (*this != (tmpRiFile)0x0) {
    (*_DAT_0000dbf4)(*(undefined4 *)(this + 4));
    *this = (tmpRiFile)0x0;
  }
  return;
}



// ===========================================
// Function: _R_DrawLensFlares @ 0000be3e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DrawLensFlares(void)

{
  uint uVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  
  if (DAT_00002245 == 0) {
    return;
  }
  if (_DAT_0000e5cc != 0) {
    return;
  }
  if (DAT_000023d5 == 0) {
    return;
  }
  _R_RotateForViewer();
  if (*(int *)(__r_place_sunflare + 0x20) != 0) {
    (*_DAT_0000dc1c)();
    fVar2 = (float)___real_3f847ae147ae147b;
    uVar3 = va(s__f__f__f,(double)(fStack_70 - _DAT_0000dd84 * fVar2),
               (double)(fStack_6c - _DAT_0000dd88 * fVar2),
               (double)(fStack_68 - _DAT_0000dd8c * fVar2));
    (*__RB_Color4f)(s_r_sunflare,uVar3);
  }
  (*__qglPushMatrix)();
  (*__qglLoadIdentity)();
  (*__qglMatrixMode)(0x1701);
  (*__qglPushMatrix)();
  (*__qglLoadIdentity)();
  (*__qglOrtho)(___real_bff0000000000000,0x3ff0000000000000,___real_bff0000000000000,0,0x3ff00000,
                (int)___real_c0f869f000000000,(int)((ulonglong)___real_c0f869f000000000 >> 0x20),
                (int)___real_40f869f000000000,(int)((ulonglong)___real_40f869f000000000 >> 0x20));
  iVar4 = _Q_stricmp(*(undefined4 *)(__r_sunflare + 4),s_0);
  if (iVar4 == 0) {
    if (_sunflare_active == '\0') goto LAB_0000c013;
    pfVar7 = (float *)&_sunflare_position;
  }
  else {
    DAT_000023d1 = *(int *)(__r_sunflare_inportalsky + 0x20) != 0;
    _VectorFromString(*(undefined4 *)(__r_sunflare + 4),&stack0xffffff44);
    pfVar7 = (float *)&stack0xffffff44;
  }
  lens_flare::SetVect((lens_flare *)&lens,pfVar7);
  lens_flare::Try((lens_flare *)&lens);
LAB_0000c013:
  iVar4 = 0;
  _DAT_00324c40 = 1;
  if (0 < _DAT_0000dd0c) {
    iVar5 = 0;
    iVar6 = _DAT_0000dd10;
    do {
      uVar1 = *(uint *)(iVar5 + 4 + iVar6);
      if (_DAT_0000e5cc == 0) {
        if ((uVar1 & 0x4000) == 0) goto LAB_0000c065;
      }
      else if ((uVar1 & 0x4000) != 0) {
LAB_0000c065:
        if ((uVar1 & 0x100) != 0) {
          DAT_00002711 = (uVar1 & 0x4000) != 0;
          lens_flare::SetVect((lens_flare *)&dlights,(float *)(iVar5 + 0x48 + iVar6));
          _DAT_000026f5 = (float)___real_406fe00000000000;
          _DAT_000026ed = (float)*(byte *)(iVar5 + 0xbc + _DAT_0000dd10) / _DAT_000026f5;
          _DAT_000026f1 = (float)*(byte *)(iVar5 + 0xbd + _DAT_0000dd10) / _DAT_000026f5;
          _DAT_000026f5 = (float)*(byte *)(iVar5 + 0xbe + _DAT_0000dd10) / _DAT_000026f5;
          dlight_lens_flare::Try((dlight_lens_flare *)&dlights);
          iVar6 = _DAT_0000dd10;
        }
        uVar1 = *(uint *)(iVar5 + 4 + iVar6);
        if ((uVar1 & 8) != 0) {
          DAT_00002571 = (byte)(uVar1 >> 0xe) & 1;
          lens_flare::SetVect((lens_flare *)&torches,(float *)(iVar5 + 0x48 + iVar6));
          _DAT_00002555 = (float)___real_406fe00000000000;
          _DAT_0000254d = (float)*(byte *)(iVar5 + 0xbc + _DAT_0000dd10) / _DAT_00002555;
          _DAT_00002551 = (float)*(byte *)(iVar5 + 0xbd + _DAT_0000dd10) / _DAT_00002555;
          _DAT_00002555 = (float)*(byte *)(iVar5 + 0xbe + _DAT_0000dd10) / _DAT_00002555;
          lens_flare::Try((lens_flare *)&torches);
          iVar6 = _DAT_0000dd10;
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x2cc;
    } while (iVar4 < _DAT_0000dd0c);
  }
  iVar4 = 0;
  if (0 < _DAT_0000dd1c) {
    iVar6 = 0;
    do {
      if (((uint)((float *)(_DAT_0000dd20 + iVar6))[7] & 3) != 0) {
        DAT_00002711 = 0;
        lens_flare::SetVect((lens_flare *)&dlights,(float *)(_DAT_0000dd20 + iVar6));
        _DAT_000026ed = *(float *)(iVar6 + 0xc + _DAT_0000dd20);
        _DAT_000026f1 = *(float *)(iVar6 + 0x10 + _DAT_0000dd20);
        _DAT_000026f5 = *(float *)(iVar6 + 0x14 + _DAT_0000dd20);
        dlight_lens_flare::Try((dlight_lens_flare *)&dlights);
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x2c;
    } while (iVar4 < _DAT_0000dd1c);
  }
  if (*(int *)(__r_place_sunflare + 0x20) == 0) {
    lens_flare::ScreenBlend((lens_flare *)&lens);
  }
  _DAT_00324c40 = 0;
  (*__qglPopMatrix)();
  (*__qglMatrixMode)(0x1700);
  (*__qglPopMatrix)();
  return;
}



// ===========================================
// Function: _R_SetSunFlare @ 0000c263
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetSunFlare(undefined4 *param_1)

{
  _sunflare_active = 1;
  __sunflare_position = *param_1;
  _DAT_00002104 = param_1[1];
  _DAT_00002108 = param_1[2];
  return;
}



// ===========================================
// Function: _R_SunFlareInPortalSky @ 0000c289
// ===========================================

void _R_SunFlareInPortalSky(void)

{
  DAT_000023d1 = 1;
  return;
}



// ===========================================
// Function: ~tmpRiFile @ 0000c291
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall tmpRiFile::~tmpRiFile(void) */

void __thiscall tmpRiFile::~tmpRiFile(tmpRiFile *this)

{
  if (*this != (tmpRiFile)0x0) {
    (*_DAT_0000dbf4)(*(undefined4 *)(this + 4));
    *this = (tmpRiFile)0x0;
  }
  return;
}



// ===========================================
// Function: open @ 0000c2ab
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall tmpRiFile::open(char const *,void * *) */

int __thiscall tmpRiFile::open(tmpRiFile *this,char *param_1,void **param_2)

{
  int iVar1;
  
  if (*this != (tmpRiFile)0x0) {
    (*_DAT_0000dbf4)(*(undefined4 *)(this + 4));
    *this = (tmpRiFile)0x0;
  }
  iVar1 = (*__r_sunflare)(param_1,param_2);
  if (iVar1 != -1) {
    *this = (tmpRiFile)0x1;
    *(void **)(this + 4) = *param_2;
  }
  return iVar1;
}



// ===========================================
// Function: Init @ 0000c2eb
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __thiscall lens_flare::Init(char const *) */

void __thiscall lens_flare::Init(lens_flare *this,char *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *unaff_FS_OFFSET;
  double dVar6;
  float local_1c;
  float fStack_18;
  float local_14;
  float local_10;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &__ehhandler__Init_lens_flare__UAEXPBD_Z;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_10 = 0.0;
  local_14 = (float)((uint)local_14 & 0xffffff00);
  local_4 = 0;
  *(undefined4 *)(this + 0x19c) = 0;
  iVar2 = (*__r_sunflare)(s_scripts_lensflare2_txt,&local_1c);
  fVar1 = local_1c;
  if (iVar2 == -1) {
    (*__ri)(3,s_WARNING__Could_not_open_lens_fla);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  local_14 = (float)CONCAT31(local_14._1_3_,1);
  local_10 = local_1c;
  iVar2 = _COM_ParseExt(&local_1c,1);
  while (iVar2 != 0) {
    if (local_1c == 0.0) {
      (*__ri)(3,s_WARNING__could_not_find_begin_fo,param_1);
      local_4 = 0xffffffff;
      (*_DAT_0000dbf4)(fVar1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    iVar2 = _Q_stricmp(iVar2,s_begin);
    if (iVar2 == 0) {
      uVar3 = _COM_ParseExt(&local_1c,0);
      iVar2 = _Q_stricmp(uVar3,param_1);
      if (iVar2 == 0) break;
    }
    iVar2 = _COM_ParseExt(&local_1c,1);
  }
  *(undefined4 *)(this + 4) = ___real_3f4ccccd;
  *(undefined4 *)(this + 8) = ___real_3f333333;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x19c) = 1;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0;
  iVar2 = _COM_ParseExt(&local_1c,1);
  do {
    if (iVar2 == 0) {
LAB_0000c6e0:
      if (*(int *)(this + 0xc) == 0) {
        (*__ri)(3,s_WARNING__no_lensflares_defined__);
      }
      if ((*(int *)(this + 0x150) == 0) && (iVar2 = _Q_stricmp(s_sun,param_1), iVar2 == 0)) {
        (*__ri)(3,s_WARNING__no_full_screen_blend_sh);
      }
      *(int *)(this + 400) = _DAT_0000dbdc - *(int *)(this + 0x154);
      local_4 = 0xffffffff;
      (*_DAT_0000dbf4)(local_10);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    if (local_1c == 0.0) {
      (*__ri)(3,s_WARNING__could_not_find_end_for_,param_1);
      goto LAB_0000c6e0;
    }
    iVar4 = _Q_stricmp(iVar2,s_dot_min);
    if (iVar4 == 0) {
      pcVar5 = (char *)_COM_ParseExt(&local_1c,0);
      if (*pcVar5 == '\0') {
        (*__ri)(3,s_WARNING__invalid_dot_min_in_lens);
      }
      else {
        dVar6 = _atof(pcVar5);
        *(float *)(this + 4) = (float)dVar6;
      }
    }
    else {
      iVar4 = _Q_stricmp(iVar2,s_flare);
      if (iVar4 == 0) {
        *(undefined4 *)(this + *(int *)(this + 0xc) * 0x10 + 0x1c) = 0x3f800000;
        pcVar5 = (char *)_COM_ParseExt(&local_1c,0);
        if (*pcVar5 == '\0') {
          (*__ri)(3,s_WARNING__no_flare_arg_1_for_flar,*(undefined4 *)(this + 0xc));
        }
        else {
          dVar6 = _atof(pcVar5);
          local_14 = (float)dVar6;
          *(float *)(this + (*(int *)(this + 0xc) + 1) * 0x10) = local_14;
          pcVar5 = (char *)_COM_ParseExt(&fStack_18,0);
          if (*pcVar5 == '\0') {
            (*__ri)(3,s_WARNING__no_flare_arg_2_for_flar,*(undefined4 *)(this + 0xc));
          }
          else {
            dVar6 = _atof(pcVar5);
            local_10 = (float)dVar6;
            *(float *)(this + *(int *)(this + 0xc) * 0x10 + 0x14) = local_10;
            pcVar5 = (char *)_COM_ParseExt(&local_14,0);
            if (*pcVar5 == '\0') {
              (*__ri)(3,s_WARNING__no_flare_arg_3_for_flar,*(undefined4 *)(this + 0xc));
            }
            else {
              uVar3 = _R_FindShader(pcVar5,0xffffffff,0,0,0);
              *(undefined4 *)(this + *(int *)(this + 0xc) * 0x10 + 0x18) = uVar3;
              pcVar5 = (char *)_COM_ParseExt(&local_14,0);
              if (*pcVar5 != '\0') {
                dVar6 = _atof(pcVar5);
                fStack_18 = (float)dVar6;
                *(float *)(this + *(int *)(this + 0xc) * 0x10 + 0x1c) = fStack_18;
              }
              *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
            }
          }
        }
      }
      else {
        iVar4 = _Q_stricmp(iVar2,s_fullscale);
        if (iVar4 == 0) {
          pcVar5 = (char *)_COM_ParseExt(&local_1c,0);
          if (*pcVar5 == '\0') {
            (*__ri)(3,s_WARNING__no_arg_for_fullscale__a);
          }
          else {
            dVar6 = _atof(pcVar5);
            *(float *)(this + 8) = (float)dVar6;
          }
        }
        else {
          iVar4 = _Q_stricmp(iVar2,s_fullscreen);
          if (iVar4 == 0) {
            pcVar5 = (char *)_COM_ParseExt(&local_1c,0);
            if (*pcVar5 == '\0') {
              (*__ri)(3,s_WARNING__no_arg_for_fullsreen_in);
            }
            else {
              uVar3 = _R_FindShader(pcVar5,0xffffffff,0,0,0);
              *(undefined4 *)(this + 0x150) = uVar3;
            }
          }
          else {
            iVar4 = _Q_stricmp(iVar2,s_fullfade);
            if (iVar4 == 0) {
              pcVar5 = (char *)_COM_ParseExt(&local_1c,0);
              if (*pcVar5 == '\0') {
                (*__ri)(3,s_WARNING__no_arg_for_fullfade_in_);
              }
              else {
                iVar2 = _atoi(pcVar5);
                *(int *)(this + 0x154) = iVar2;
              }
            }
            else {
              iVar2 = _Q_stricmp(iVar2,s_end);
              if (iVar2 == 0) goto LAB_0000c6e0;
            }
          }
        }
      }
    }
    iVar2 = _COM_ParseExt(&local_1c,1);
  } while( true );
}



// ===========================================
// Function: Init @ 0000c75f
// ===========================================

/* public: virtual void __thiscall dlight_lens_flare::Init(char const *) */

void __thiscall dlight_lens_flare::Init(dlight_lens_flare *this,char *param_1)

{
  undefined4 uVar1;
  
  lens_flare::Init((lens_flare *)this,param_1);
  uVar1 = _R_FindShader(s_textures_sprites_corona,0xffffffff,0,0,0);
  *(undefined4 *)(this + 0x1a0) = uVar1;
  return;
}



// ===========================================
// Function: _R_InitLensFlare @ 0000c78b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_InitLensFlare(void)

{
  _sunflare_active = 0;
  lens_flare::Init((lens_flare *)&lens,s_sun);
  lens_flare::Init((lens_flare *)&torches,s_entity);
  lens_flare::Init((lens_flare *)&dlights,s_dlight);
  _DAT_00002719 = _R_FindShader(s_textures_sprites_corona,0xffffffff,0,0,0);
  return;
}



// ===========================================
// Function: `dynamic_initializer_for_'lens'' @ 0000c900
// ===========================================

/* void __cdecl `dynamic initializer for 'lens''(void) */

void __cdecl _dynamic_initializer_for__lens__(void)

{
  _atexit(_dynamic_atexit_destructor_for__lens__);
  return;
}



// ===========================================
// Function: `dynamic_initializer_for_'torches'' @ 0000c90c
// ===========================================

/* void __cdecl `dynamic initializer for 'torches''(void) */

void __cdecl _dynamic_initializer_for__torches__(void)

{
  _atexit(_dynamic_atexit_destructor_for__torches__);
  return;
}



// ===========================================
// Function: `dynamic_initializer_for_'dlights'' @ 0000c918
// ===========================================

/* void __cdecl `dynamic initializer for 'dlights''(void) */

void __cdecl _dynamic_initializer_for__dlights__(void)

{
  _atexit(_dynamic_atexit_destructor_for__dlights__);
  return;
}



// ===========================================
// Function: `dynamic_atexit_destructor_for_'lens'' @ 0000ca00
// ===========================================

/* void __cdecl `dynamic atexit destructor for 'lens''(void) */

void __cdecl _dynamic_atexit_destructor_for__lens__(void)

{
  lens = (undefined *)&lens_flare::_vftable_;
  return;
}



// ===========================================
// Function: `dynamic_atexit_destructor_for_'torches'' @ 0000ca0b
// ===========================================

/* void __cdecl `dynamic atexit destructor for 'torches''(void) */

void __cdecl _dynamic_atexit_destructor_for__torches__(void)

{
  torches = (undefined *)&lens_flare::_vftable_;
  return;
}



// ===========================================
// Function: `dynamic_atexit_destructor_for_'dlights'' @ 0000ca16
// ===========================================

/* void __cdecl `dynamic atexit destructor for 'dlights''(void) */

void __cdecl _dynamic_atexit_destructor_for__dlights__(void)

{
  dlights = (undefined *)&lens_flare::_vftable_;
  return;
}



