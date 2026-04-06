// ===========================================
// Function: ~strdata @ 00009900
// ===========================================

/* public: __thiscall strdata::~strdata(void) */

void __thiscall strdata::~strdata(strdata *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  return;
}



// ===========================================
// Function: `scalar_deleting_destructor' @ 0000990e
// ===========================================

/* public: void * __thiscall strdata::`scalar deleting destructor'(unsigned int) */

void * __thiscall strdata::_scalar_deleting_destructor_(strdata *this,uint param_1)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===========================================
// Function: length @ 00009936
// ===========================================

/* public: int __thiscall str::length(void)const  */

int __thiscall str::length(str *this)

{
  if (*(int *)this != 0) {
    return *(int *)(*(int *)this + 0xc);
  }
  return 0;
}



// ===========================================
// Function: str @ 00009943
// ===========================================

/* public: __thiscall str::str(void) */

str * __thiscall str::str(str *this)

{
  *(undefined4 *)this = 0;
  ::str::EnsureAlloced(this,1,true);
  *(undefined1 *)**(undefined4 **)this = 0;
  return this;
}



// ===========================================
// Function: operator[] @ 00009960
// ===========================================

/* public: char & __thiscall str::operator[](int) */

char * __thiscall str::operator[](str *this,int param_1)

{
  int *piVar1;
  
  ::str::EnsureDataWritable(this);
  piVar1 = *(int **)this;
  if (((piVar1 != (int *)0x0) && (-1 < param_1)) && (param_1 < piVar1[3])) {
    return (char *)(*piVar1 + param_1);
  }
  return &`public:_char&___thiscall_str::operator[](int)'::__l2::dummy;
}



// ===========================================
// Function: operator= @ 0000998c
// ===========================================

/* public: void __thiscall str::operator=(char const *) */

void __thiscall str::operator=(str *this,char *param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
  if (param_1 == (char *)0x0) {
    ::str::EnsureAlloced(this,1,false);
    *(undefined1 *)**(undefined4 **)this = 0;
    *(undefined4 *)(*(int *)this + 0xc) = 0;
    return;
  }
  if (*(int **)this == (int *)0x0) {
    pcVar1 = param_1 + 1;
    pcVar4 = param_1;
    do {
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    ::str::EnsureAlloced(this,((int)pcVar4 - (int)pcVar1) + 1,false);
    pcVar6 = (char *)**(undefined4 **)this;
    do {
      cVar3 = *param_1;
      *pcVar6 = cVar3;
      param_1 = param_1 + 1;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    *(int *)(*(int *)this + 0xc) = (int)pcVar4 - (int)pcVar1;
    return;
  }
  if (param_1 != (char *)**(int **)this) {
    ::str::EnsureDataWritable(this);
    pcVar1 = (char *)**(uint **)this;
    if ((pcVar1 <= param_1) && (param_1 <= pcVar1 + (*(uint **)this)[3])) {
      iVar5 = 0;
      cVar3 = *param_1;
      while (cVar3 != '\0') {
        *(char *)(iVar5 + **(int **)this) = cVar3;
        iVar2 = iVar5 + 1;
        iVar5 = iVar5 + 1;
        cVar3 = param_1[iVar2];
      }
      *(undefined1 *)(iVar5 + **(int **)this) = 0;
      *(int *)(*(int *)this + 0xc) = *(int *)(*(int *)this + 0xc) - ((int)param_1 - (int)pcVar1);
      return;
    }
    pcVar1 = param_1 + 1;
    pcVar4 = param_1;
    do {
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    ::str::EnsureAlloced(this,((int)pcVar4 - (int)pcVar1) + 1,false);
    pcVar6 = (char *)**(undefined4 **)this;
    do {
      cVar3 = *param_1;
      *pcVar6 = cVar3;
      param_1 = param_1 + 1;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    *(int *)(*(int *)this + 0xc) = (int)pcVar4 - (int)pcVar1;
  }
  return;
}



// ===========================================
// Function: _RB_StreamEnd @ 00009a7a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StreamEnd(void)

{
  uint uVar1;
  int *piVar2;
  
  if (2 < _DAT_0032232c) {
    uVar1 = 0;
    __tess = 0;
    _DAT_0000b2dc = 1;
    __backEnd = 2;
    if (_DAT_0032232c != 2 && -1 < _DAT_0032232c + -2) {
      piVar2 = (int *)&DAT_0000b2dc;
      do {
        piVar2[-1] = (uVar1 & 1) + uVar1;
        piVar2[1] = uVar1 + 2;
        *piVar2 = (uVar1 - (uVar1 & 1)) + 1;
        _DAT_00322328 = _DAT_00322328 + 3;
        uVar1 = uVar1 + 1;
        piVar2 = piVar2 + 3;
      } while ((int)uVar1 < _DAT_0032232c + -2);
    }
    _RB_EndSurface();
    return;
  }
  _RB_EndSurface();
  return;
}



// ===========================================
// Function: _RB_StreamBeginDrawSurf @ 00009ae8
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StreamBeginDrawSurf(void)

{
  _DAT_0000ba88 = _DAT_0032232c;
  return;
}



// ===========================================
// Function: _RB_StreamEndDrawSurf @ 00009af3
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_StreamEndDrawSurf(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = _DAT_0000ba88;
  if (2 < _DAT_0032232c - _DAT_0000ba88) {
    iVar1 = (_DAT_0032232c - _DAT_0000ba88) + -2;
    uVar3 = 0;
    if (0 < iVar1) {
      piVar4 = (int *)(&DAT_0000b2dc + _DAT_00322328 * 4);
      do {
        piVar4[-1] = (uVar3 & 1) + iVar2 + uVar3;
        *piVar4 = uVar3 + 1 + (iVar2 - (uVar3 & 1));
        piVar4[1] = iVar2 + 2 + uVar3;
        _DAT_00322328 = _DAT_00322328 + 3;
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 3;
      } while ((int)uVar3 < iVar1);
    }
    return;
  }
  _DAT_0032232c = _DAT_0000ba88;
  return;
}



// ===========================================
// Function: addTriangle @ 00009b58
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl addTriangle(void) */

void __cdecl addTriangle(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0x1a5558) = __cntSt;
  uVar1 = _cntColor;
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0x1a555c) = _DAT_00002005;
  *(char *)(_DAT_0032232c * 4 + 0x21a858) = (char)uVar1;
  uVar2 = _cntColor._2_1_;
  *(char *)(_DAT_0032232c * 4 + 0x21a859) = (char)((uint)uVar1 >> 8);
  *(undefined1 *)(_DAT_0032232c * 4 + 0x21a85a) = uVar2;
  *(undefined1 *)(_DAT_0032232c * 4 + 0x21a85b) = _cntColor._3_1_;
  _DAT_0032232c = _DAT_0032232c + 1;
  _DAT_00322344 = 1;
  return;
}



// ===========================================
// Function: _RB_Vertex3fv @ 00009bd6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Vertex3fv(undefined4 *param_1)

{
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf58) = *param_1;
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf5c) = param_1[1];
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf60) = param_1[2];
  addTriangle();
  return;
}



// ===========================================
// Function: _RB_Vertex3f @ 00009c14
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Vertex3f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf58) = param_1;
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf5c) = param_2;
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf60) = param_3;
  addTriangle();
  return;
}



// ===========================================
// Function: _RB_Vertex2f @ 00009c51
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Vertex2f(undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf58) = param_1;
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf5c) = param_2;
  *(undefined4 *)(_DAT_0032232c * 0x10 + 0xbaf60) = 0;
  addTriangle();
  return;
}



// ===========================================
// Function: _RB_Color4f @ 00009c8c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Color4f(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  undefined1 local_4;
  
  fVar1 = (float)_DAT_0000bcb0;
  local_4 = (undefined1)(int)ROUND(fVar1 * param_1);
  _cntColor._0_1_ = local_4;
  param_2._0_1_ = (undefined1)(int)ROUND(fVar1 * param_2);
  _cntColor._1_1_ = param_2._0_1_;
  param_2._0_1_ = (undefined1)(int)ROUND(fVar1 * param_3);
  _cntColor._2_1_ = param_2._0_1_;
  param_2._0_1_ = (undefined1)(int)ROUND(param_4 * (float)___real_406fe00000000000);
  _cntColor._3_1_ = param_2._0_1_;
  return;
}



// ===========================================
// Function: _RB_Color3f @ 00009d51
// ===========================================

void _RB_Color3f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _RB_Color4f(param_1,param_2,param_3,0x3f800000);
  return;
}



// ===========================================
// Function: _RB_Color3fv @ 00009d7a
// ===========================================

void _RB_Color3fv(undefined4 *param_1)

{
  _RB_Color4f(*param_1,param_1[1],param_1[2],0x3f800000);
  return;
}



// ===========================================
// Function: _RB_Color4bv @ 00009da3
// ===========================================

void _RB_Color4bv(undefined1 *param_1)

{
  _cntColor._0_1_ = *param_1;
  _cntColor._1_1_ = param_1[1];
  _cntColor._2_1_ = param_1[2];
  _cntColor._3_1_ = param_1[3];
  return;
}



// ===========================================
// Function: _RB_Texcoord2f @ 00009dcf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Texcoord2f(undefined4 param_1,undefined4 param_2)

{
  __cntSt = param_1;
  _DAT_00002005 = param_2;
  return;
}



// ===========================================
// Function: _RB_Texcoord2fv @ 00009de4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _RB_Texcoord2fv(undefined4 *param_1)

{
  __cntSt = *param_1;
  _DAT_00002005 = param_1[1];
  return;
}



// ===========================================
// Function: _RE_GetShaderWidth @ 00009dfa
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _RE_GetShaderWidth(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return *(undefined4 *)(*(int *)(*(int *)(_DAT_0000b334 + 0x194) + 8) + 0x48);
  }
  iVar1 = _R_GetShaderByHandle(param_1);
  return *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x194) + 8) + 0x48);
}



// ===========================================
// Function: _RE_GetShaderHeight @ 00009e2a
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _RE_GetShaderHeight(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return *(undefined4 *)(*(int *)(*(int *)(_DAT_0000b334 + 0x194) + 8) + 0x4c);
  }
  iVar1 = _R_GetShaderByHandle(param_1);
  return *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x194) + 8) + 0x4c);
}



// ===========================================
// Function: DelRef @ 00009e5a
// ===========================================

/* public: bool __thiscall strdata::DelRef(void) */

bool __thiscall strdata::DelRef(strdata *this)

{
  strdata *psVar1;
  
  psVar1 = this + 4;
  *(int *)psVar1 = *(int *)psVar1 + -1;
  if (*(int *)psVar1 < 0) {
    if (*(void **)this != (void *)0x0) {
      operator_delete(*(void **)this);
    }
    operator_delete(this);
    return true;
  }
  return false;
}



// ===========================================
// Function: ~str @ 00009e83
// ===========================================

/* public: __thiscall str::~str(void) */

void __thiscall str::~str(str *this)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)this;
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      if ((void *)*puVar2 != (void *)0x0) {
        operator_delete((void *)*puVar2);
      }
      operator_delete(puVar2);
    }
    *(undefined4 *)this = 0;
  }
  return;
}



// ===========================================
// Function: _R_DrawDebugNumber @ 00009eb4
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_DrawDebugNumber(undefined4 param_1,undefined4 param_2,float *param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8)

{
  float fVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
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
  undefined1 auStack_c [12];
  
  puVar7 = (undefined4 *)0x0;
  str::EnsureAlloced((str *)&stack0xffffffac,1,true);
  *(undefined1 *)*puVar7 = 0;
  local_44 = _DAT_0000ba50;
  local_40 = _DAT_0000ba54;
  local_3c = _DAT_0000ba58;
  local_4c = (int *)(_DAT_0000ba48 * (float)___real_bff0000000000000);
  local_48 = (float)___real_bff0000000000000 * _DAT_0000ba4c;
  _VectorNormalize(&local_44);
  _VectorNormalize(&stack0xffffffb0);
  local_44 = (float)param_3 * local_44;
  local_40 = local_40 * (float)param_3;
  local_3c = local_3c * (float)param_3;
  local_4c = (int *)((float)local_4c * (float)param_3);
  local_48 = (float)param_3 * local_48;
  if (param_7 < 1) {
    __ftol2_sse();
    pcVar2 = (char *)va();
  }
  else {
    _sprintf((char *)&fStack_14,s_____df);
    pcVar2 = (char *)va(auStack_c);
  }
  str::operator=((str *)&local_4c,pcVar2);
  if (local_4c == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = local_4c[3];
  }
  fStack_30 = (float)(iVar3 * -5 + 5) * local_48 + *param_3;
  if (local_4c == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = local_4c[3];
  }
  fStack_2c = (float)(iVar3 * -5 + 5) * local_44 + param_3[1];
  if (local_4c == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = local_4c[3];
  }
  iVar5 = 0;
  fStack_28 = (float)(iVar3 * -5 + 5) * local_40 + param_3[2];
  do {
    piVar4 = local_4c;
    if (local_4c == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = local_4c[3];
    }
    if (iVar3 <= iVar5) {
      if ((local_4c != (int *)0x0) && (local_4c[1] = local_4c[1] + -1, local_4c[1] < 0)) {
        if ((void *)*local_4c != (void *)0x0) {
          operator_delete((void *)*local_4c);
        }
        operator_delete(piVar4);
      }
      return;
    }
    str::EnsureDataWritable((str *)&local_4c);
    if (((local_4c == (int *)0x0) || (iVar5 < 0)) || (local_4c[3] <= iVar5)) {
      pcVar2 = &`public:_char&___thiscall_str::operator[](int)'::__l2::dummy;
    }
    else {
      pcVar2 = (char *)(*local_4c + iVar5);
    }
    if (*pcVar2 == '.') {
      iVar3 = 10;
    }
    else {
      str::EnsureDataWritable((str *)&local_4c);
      if (((local_4c == (int *)0x0) || (iVar5 < 0)) || (local_4c[3] <= iVar5)) {
        pcVar2 = &`public:_char&___thiscall_str::operator[](int)'::__l2::dummy;
      }
      else {
        pcVar2 = (char *)(*local_4c + iVar5);
      }
      if (*pcVar2 == '-') {
        iVar3 = 0xb;
      }
      else {
        str::EnsureDataWritable((str *)&local_4c);
        if (((local_4c == (int *)0x0) || (iVar5 < 0)) || (local_4c[3] <= iVar5)) {
          pcVar2 = &`public:_char&___thiscall_str::operator[](int)'::__l2::dummy;
        }
        else {
          pcVar2 = (char *)(*local_4c + iVar5);
        }
        iVar3 = *pcVar2 + -0x30;
      }
    }
    iVar6 = 0;
    piVar4 = (int *)(&_Numbers + iVar3 * 0x20);
    do {
      if (*piVar4 == 0) break;
      iVar3 = *piVar4 * 0x10;
      fStack_18 = *(float *)(iVar3 + 0x2284) * local_3c +
                  fStack_30 + local_48 * *(float *)(&_Lines + iVar3);
      fStack_14 = *(float *)(iVar3 + 0x2284) * fStack_38 +
                  fStack_2c + local_44 * *(float *)(&_Lines + iVar3);
      fStack_10 = *(float *)(iVar3 + 0x2284) * fStack_34 +
                  fStack_28 + local_40 * *(float *)(&_Lines + iVar3);
      fStack_24 = *(float *)(iVar3 + 0x228c) * local_3c +
                  *(float *)(iVar3 + 0x2288) * local_48 + fStack_30;
      fStack_20 = *(float *)(iVar3 + 0x228c) * fStack_38 +
                  *(float *)(iVar3 + 0x2288) * local_44 + fStack_2c;
      fStack_1c = *(float *)(iVar3 + 0x228c) * fStack_34 +
                  local_40 * *(float *)(iVar3 + 0x2288) + fStack_28;
      _R_DebugLine(&fStack_18,&fStack_24,param_6,param_7,param_8,0x3f800000);
      iVar6 = iVar6 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar6 < 8);
    fVar1 = (float)___real_4024000000000000;
    iVar5 = iVar5 + 1;
    fStack_30 = local_48 * fVar1 + fStack_30;
    fStack_2c = local_44 * fVar1 + fStack_2c;
    fStack_28 = fVar1 * local_40 + fStack_28;
  } while( true );
}



