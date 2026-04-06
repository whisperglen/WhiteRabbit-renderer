// ===========================================
// Function: _cosf @ 00010200
// ===========================================

float __cdecl _cosf(float __x)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIcos();
  return (float)fVar1;
}



// ===========================================
// Function: _sinf @ 00010212
// ===========================================

float __cdecl _sinf(float __x)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsin();
  return (float)fVar1;
}



// ===========================================
// Function: _sqrtf @ 00010224
// ===========================================

float __cdecl _sqrtf(float __x)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsqrt();
  return (float)fVar1;
}



// ===========================================
// Function: cos @ 00010236
// ===========================================

/* float __cdecl cos(float) */

float __cdecl cos(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIcos();
  return (float)fVar1;
}



// ===========================================
// Function: sin @ 00010248
// ===========================================

/* float __cdecl sin(float) */

float __cdecl sin(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsin();
  return (float)fVar1;
}



// ===========================================
// Function: sqrt @ 0001025a
// ===========================================

/* float __cdecl sqrt(float) */

float __cdecl sqrt(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsqrt();
  return (float)fVar1;
}



// ===========================================
// Function: Vector @ 0001026c
// ===========================================

/* public: __thiscall Vector::Vector(void) */

void __thiscall Vector::Vector(Vector *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: Vector @ 00010279
// ===========================================

/* public: __thiscall Vector::Vector(float,float,float) */

void __thiscall Vector::Vector(Vector *this,float param_1,float param_2,float param_3)

{
  *(float *)this = param_1;
  *(float *)(this + 4) = param_2;
  *(float *)(this + 8) = param_3;
  return;
}



// ===========================================
// Function: Vector @ 00010292
// ===========================================

/* public: __thiscall Vector::Vector(char const *) */

Vector * __thiscall Vector::Vector(Vector *this,char *param_1)

{
  if (param_1 != (char *)0x0) {
    _sscanf(param_1,s__f__f__f);
    return this;
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}



// ===========================================
// Function: operator= @ 000102ca
// ===========================================

/* public: void __thiscall Vector::operator=(class Vector) */

void __thiscall
Vector::operator=(Vector *this,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)this = param_2;
  *(undefined4 *)(this + 4) = param_3;
  *(undefined4 *)(this + 8) = param_4;
  return;
}



// ===========================================
// Function: operator+ @ 000102e1
// ===========================================

/* class Vector __cdecl operator+(class Vector,class Vector) */

void __cdecl
operator+(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
         float param_7)

{
  *param_1 = param_5 + param_2;
  param_1[1] = param_6 + param_3;
  param_1[2] = param_7 + param_4;
  return;
}



// ===========================================
// Function: operator+= @ 00010306
// ===========================================

/* public: class Vector & __thiscall Vector::operator+=(class Vector) */

Vector * __thiscall Vector::operator+=(Vector *this,float param_2,float param_3,float param_4)

{
  *(float *)this = *(float *)this + param_2;
  *(float *)(this + 4) = *(float *)(this + 4) + param_3;
  *(float *)(this + 8) = *(float *)(this + 8) + param_4;
  return this;
}



// ===========================================
// Function: operator- @ 00010327
// ===========================================

/* class Vector __cdecl operator-(class Vector,class Vector) */

void __cdecl
operator-(float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
         float param_7)

{
  *param_1 = param_2 - param_5;
  param_1[1] = param_3 - param_6;
  param_1[2] = param_4 - param_7;
  return;
}



// ===========================================
// Function: operator* @ 0001034c
// ===========================================

/* class Vector __cdecl operator*(class Vector,float) */

void __cdecl operator*(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  *param_1 = param_5 * param_2;
  param_1[1] = param_3 * param_5;
  param_1[2] = param_5 * param_4;
  return;
}



// ===========================================
// Function: operator* @ 00010371
// ===========================================

/* class Vector __cdecl operator*(float,class Vector) */

void __cdecl operator*(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  *param_1 = param_2 * param_3;
  param_1[1] = param_4 * param_2;
  param_1[2] = param_2 * param_5;
  return;
}



// ===========================================
// Function: operator*= @ 00010396
// ===========================================

/* public: class Vector & __thiscall Vector::operator*=(float) */

Vector * __thiscall Vector::operator*=(Vector *this,float param_1)

{
  *(float *)this = param_1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(this + 4) * param_1;
  *(float *)(this + 8) = param_1 * *(float *)(this + 8);
  return this;
}



// ===========================================
// Function: length @ 000103b7
// ===========================================

/* public: float __thiscall Vector::length(void) */

float __thiscall Vector::length(Vector *this)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsqrt(*(float *)(this + 8) * *(float *)(this + 8) +
                            *(float *)this * *(float *)this +
                            *(float *)(this + 4) * *(float *)(this + 4));
  return (float)fVar1;
}



// ===========================================
// Function: normalize @ 000103e3
// ===========================================

/* public: float __thiscall Vector::normalize(void) */

float __thiscall Vector::normalize(Vector *this)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  
  fVar3 = (float10)__CIsqrt();
  fVar1 = (float)fVar3;
  if (NAN(fVar1) == (fVar1 == 0.0)) {
    fVar2 = 1.0 / fVar1;
    *(float *)this = fVar2 * *(float *)this;
    *(float *)(this + 4) = fVar2 * *(float *)(this + 4);
    *(float *)(this + 8) = fVar2 * *(float *)(this + 8);
  }
  return fVar1;
}



// ===========================================
// Function: ~strdata @ 00010452
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
// Function: `scalar_deleting_destructor' @ 00010460
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
// Function: str @ 00010488
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
// Function: c_str @ 000104a5
// ===========================================

/* public: char const * __thiscall str::c_str(void)const  */

char * __thiscall str::c_str(str *this)

{
  return (char *)**(undefined4 **)this;
}



// ===========================================
// Function: operator= @ 000104aa
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
// Function: operator== @ 00010593
// ===========================================

/* bool __cdecl operator==(class str const &,char const *) */

bool __cdecl operator==(str *param_1,char *param_2)

{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  if (param_2 == (char *)0x0) {
    return false;
  }
  pbVar2 = (byte *)**(undefined4 **)param_1;
  while( true ) {
    bVar1 = *pbVar2;
    bVar3 = bVar1 < (byte)*param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = pbVar2[1];
    bVar3 = bVar1 < ((byte *)param_2)[1];
    if (bVar1 != ((byte *)param_2)[1]) break;
    pbVar2 = pbVar2 + 2;
    param_2 = (char *)((byte *)param_2 + 2);
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar3 == (uint)(bVar3 != 0);
}



// ===========================================
// Function: GetDieTime @ 000105dd
// ===========================================

/* public: float __thiscall Particle::GetDieTime(void) */

float __thiscall Particle::GetDieTime(Particle *this)

{
  return *(float *)(this + 4);
}



// ===========================================
// Function: GetPosition @ 000105e1
// ===========================================

/* public: class Vector __thiscall ParticleEmitter::GetPosition(void) */

void __thiscall ParticleEmitter::GetPosition(ParticleEmitter *this)

{
  undefined4 uVar1;
  undefined4 *in_stack_00000004;
  
  *in_stack_00000004 = *(undefined4 *)(this + 8);
  uVar1 = *(undefined4 *)(this + 0x10);
  in_stack_00000004[1] = *(undefined4 *)(this + 0xc);
  in_stack_00000004[2] = uVar1;
  return;
}



// ===========================================
// Function: GetSrcColor @ 000105f9
// ===========================================

/* public: int __thiscall ParticleEmitter::GetSrcColor(void) */

int __thiscall ParticleEmitter::GetSrcColor(ParticleEmitter *this)

{
  return *(int *)(this + 0x14);
}



// ===========================================
// Function: GetLightningVar @ 000105fd
// ===========================================

/* public: float __thiscall ParticleEmitter::GetLightningVar(void) */

float __thiscall ParticleEmitter::GetLightningVar(ParticleEmitter *this)

{
  return *(float *)(this + 0x84);
}



// ===========================================
// Function: GetLightningSubdivisions @ 00010604
// ===========================================

/* public: int __thiscall ParticleEmitter::GetLightningSubdivisions(void) */

int __thiscall ParticleEmitter::GetLightningSubdivisions(ParticleEmitter *this)

{
  return *(int *)(this + 0x88);
}



// ===========================================
// Function: RandomizeRange @ 0001060b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall ParticleEmitter::RandomizeRange(float,float) */

float __thiscall ParticleEmitter::RandomizeRange(ParticleEmitter *this,float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _rand();
  return ((float)iVar1 / (float)___real_40dfffc000000000) * (param_2 - param_1) + param_1;
}



// ===========================================
// Function: RandomizeAngle @ 0001063b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall ParticleEmitter::RandomizeAngle(float,float) */

float __thiscall ParticleEmitter::RandomizeAngle(ParticleEmitter *this,float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _rand();
  return ((float)(iVar1 + -0x3fff) / (float)___real_40dfffc000000000) * param_2 + param_1;
}



// ===========================================
// Function: CalculateDirection @ 0001066c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class Vector __thiscall ParticleEmitter::CalculateDirection(float) */

float __thiscall ParticleEmitter::CalculateDirection(ParticleEmitter *this,float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIcos();
  *(float *)param_1 = (float)fVar1;
  fVar1 = (float10)__CIsin();
  *(float *)((int)param_1 + 4) = (float)-fVar1;
  *(undefined4 *)((int)param_1 + 8) = 0;
  return param_1;
}



// ===========================================
// Function: GetVelocity @ 000106a5
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class Vector __thiscall ParticleEmitter::GetVelocity(void) */

float * __thiscall ParticleEmitter::GetVelocity(ParticleEmitter *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float *in_stack_00000004;
  
  *in_stack_00000004 = 0.0;
  in_stack_00000004[1] = 0.0;
  in_stack_00000004[2] = 0.0;
  _rand();
  fVar4 = (float10)__CIcos();
  fVar5 = (float10)__CIsin();
  *in_stack_00000004 = (float)fVar4;
  in_stack_00000004[1] = (float)-fVar5;
  in_stack_00000004[2] = 0.0;
  fVar1 = *(float *)(this + 0x3c);
  fVar2 = *(float *)(this + 0x40);
  iVar3 = _rand();
  fVar1 = ((float)iVar3 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1;
  *in_stack_00000004 = fVar1 * *in_stack_00000004;
  in_stack_00000004[1] = in_stack_00000004[1] * fVar1;
  in_stack_00000004[2] = fVar1 * in_stack_00000004[2];
  return in_stack_00000004;
}



// ===========================================
// Function: GetAcceleration @ 00010789
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class Vector __thiscall ParticleEmitter::GetAcceleration(void) */

float * __thiscall ParticleEmitter::GetAcceleration(ParticleEmitter *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float *in_stack_00000004;
  
  *in_stack_00000004 = 0.0;
  in_stack_00000004[1] = 0.0;
  in_stack_00000004[2] = 0.0;
  _rand();
  fVar6 = (float10)__CIcos();
  fVar7 = (float10)__CIsin();
  *in_stack_00000004 = (float)fVar6;
  in_stack_00000004[1] = (float)-fVar7;
  in_stack_00000004[2] = 0.0;
  fVar1 = *(float *)(this + 0x4c);
  fVar2 = *(float *)(this + 0x50);
  iVar5 = _rand();
  fVar3 = *(float *)(this + 0x70);
  fVar4 = *(float *)(this + 0x74);
  fVar1 = ((float)iVar5 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1;
  *in_stack_00000004 = fVar1 * *in_stack_00000004 + *(float *)(this + 0x6c);
  in_stack_00000004[1] = in_stack_00000004[1] * fVar1 + fVar3;
  in_stack_00000004[2] = fVar1 * in_stack_00000004[2] + fVar4;
  return in_stack_00000004;
}



// ===========================================
// Function: GetRate @ 000108a6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall ParticleEmitter::GetRate(void) */

float __thiscall ParticleEmitter::GetRate(ParticleEmitter *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *(float *)(this + 0x24);
  fVar2 = *(float *)(this + 0x28);
  iVar3 = _rand();
  return ((float)iVar3 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1;
}



// ===========================================
// Function: GetColorRate @ 000108e6
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall ParticleEmitter::GetColorRate(void) */

float __thiscall ParticleEmitter::GetColorRate(ParticleEmitter *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *(float *)(this + 0x1c);
  fVar2 = *(float *)(this + 0x20);
  iVar3 = _rand();
  return ((float)iVar3 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1;
}



// ===========================================
// Function: IsParticles @ 00010926
// ===========================================

/* public: int __thiscall ParticleEmitter::IsParticles(void) */

int __thiscall ParticleEmitter::IsParticles(ParticleEmitter *this)

{
  return *(int *)(this + 0x68);
}



// ===========================================
// Function: IsGravityWell @ 0001092a
// ===========================================

/* public: int __thiscall ParticleEmitter::IsGravityWell(void) */

int __thiscall ParticleEmitter::IsGravityWell(ParticleEmitter *this)

{
  return *(int *)(this + 0x60);
}



// ===========================================
// Function: IsBallLightning @ 0001092e
// ===========================================

/* public: int __thiscall ParticleEmitter::IsBallLightning(void) */

int __thiscall ParticleEmitter::IsBallLightning(ParticleEmitter *this)

{
  return *(int *)(this + 0x78);
}



// ===========================================
// Function: IsSwarm @ 00010932
// ===========================================

/* public: int __thiscall ParticleEmitter::IsSwarm(void) */

int __thiscall ParticleEmitter::IsSwarm(ParticleEmitter *this)

{
  return *(int *)(this + 0x8c);
}



// ===========================================
// Function: GetWavyDistance @ 00010939
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall ParticleEmitter::GetWavyDistance(void) */

float __thiscall ParticleEmitter::GetWavyDistance(ParticleEmitter *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *(float *)(this + 0x54);
  fVar2 = *(float *)(this + 0x58);
  iVar3 = _rand();
  return ((float)iVar3 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1;
}



// ===========================================
// Function: GetBallLightningRadius @ 00010979
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall ParticleEmitter::GetBallLightningRadius(void) */

int __thiscall ParticleEmitter::GetBallLightningRadius(ParticleEmitter *this)

{
  int iVar1;
  
  _rand();
  iVar1 = __ftol2_sse();
  return iVar1;
}



// ===========================================
// Function: GetDieTime @ 000109c0
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: float __thiscall ParticleEmitter::GetDieTime(float) */

float __thiscall ParticleEmitter::GetDieTime(ParticleEmitter *this,float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *(float *)(this + 0x2c);
  fVar2 = *(float *)(this + 0x30);
  iVar3 = _rand();
  return ((float)iVar3 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1 + param_1;
}



// ===========================================
// Function: RandomizeRange @ 00010a0e
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* float __cdecl RandomizeRange(float,float) */

float __cdecl RandomizeRange(float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _rand();
  return ((float)iVar1 / (float)___real_40dfffc000000000) * (param_2 - param_1) + param_1;
}



// ===========================================
// Function: Particle @ 00010a3c
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall Particle::Particle(class Vector,class Vector,class
   Vector,int,int,float,int,float,float,float,float,class Vector,int,int,int) */

Particle * __thiscall
Particle::Particle(Particle *this,undefined8 param_2,undefined4 param_3,float param_4,float param_5,
                  undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                  int param_10,float param_11,undefined4 param_12,undefined4 param_13,float param_14
                  ,float param_15,float param_16,undefined4 param_17,undefined4 param_18,
                  undefined4 param_19,undefined4 param_20,undefined4 param_21,undefined4 param_22,
                  undefined4 param_23)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  float10 fVar8;
  
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x94) = (undefined4)param_2;
  *(undefined4 *)(this + 0x98) = param_2._4_4_;
  *(undefined4 *)(this + 0x9c) = param_3;
  *(undefined4 *)(this + 0x70) = param_3;
  *(undefined4 *)(this + 0x68) = (undefined4)param_2;
  *(undefined4 *)(this + 0x6c) = param_2._4_4_;
  *(float *)(this + 8) = param_4;
  *(float *)(this + 0xc) = param_5;
  *(undefined4 *)(this + 0x10) = param_6;
  *(undefined4 *)(this + 0x14) = param_7;
  *(undefined4 *)(this + 0x18) = param_8;
  *(undefined4 *)(this + 0x1c) = param_9;
  *(int *)(this + 0xa0) = param_10;
  *(int *)(this + 0x38) = param_10;
  *(undefined4 *)(this + 100) = param_12;
  *(float *)(this + 0x3c) = param_11;
  *(float *)(this + 0x30) = param_14;
  *(undefined4 *)(this + 0x2c) = param_13;
  param_11 = -param_14;
  *(undefined4 *)(this + 0x7c) = param_21;
  *(undefined4 *)(this + 0x80) = param_22;
  *(undefined4 *)(this + 0x84) = param_23;
  param_10 = _rand();
  *(float *)(this + 0x34) =
       ((float)param_10 / (float)___real_40dfffc000000000) * (param_14 - param_11) + param_11;
  *(float *)this = param_15;
  *(float *)(this + 4) = param_16;
  *(float *)(this + 0x74) = param_16 - param_15;
  *(undefined4 *)(this + 0x78) = param_17;
  *(undefined4 *)(this + 0x88) = param_18;
  *(undefined4 *)(this + 0x8c) = param_19;
  *(undefined4 *)(this + 0x90) = param_20;
  param_4 = *(float *)(this + 8);
  param_5 = *(float *)(this + 0xc);
  param_6 = *(undefined4 *)(this + 0x10);
  Vector::normalize((Vector *)&param_4);
  fVar7 = (float10)__CIcos();
  fVar8 = (float10)__CIsin();
  uVar1 = *(uint *)(this + 0x38);
  uVar2 = *(uint *)(this + 0x3c);
  *(float *)(this + 0x20) =
       (float)((float10)param_4 * (float10)(double)fVar7 - (float10)param_5 * fVar8);
  uVar3 = (int)uVar2 >> 8 & 0xff;
  *(uint *)(this + 0x58) = uVar2 & 0xff;
  uVar4 = (int)uVar1 >> 8 & 0xff;
  uVar6 = (int)uVar1 >> 0x10 & 0xff;
  *(uint *)(this + 0x5c) = uVar3;
  uVar5 = (int)uVar2 >> 0x10 & 0xff;
  *(uint *)(this + 0x60) = uVar5;
  *(uint *)(this + 0x40) = (uVar2 & 0xff) - (uVar1 & 0xff);
  *(float *)(this + 0x24) =
       (float)((float10)param_5 * (float10)(double)fVar7 + (float10)param_4 * fVar8);
  *(uint *)(this + 0x44) = uVar3 - uVar4;
  *(uint *)(this + 0x4c) = uVar1 & 0xff;
  *(uint *)(this + 0x54) = uVar6;
  *(uint *)(this + 0x50) = uVar4;
  *(uint *)(this + 0x48) = uVar5 - uVar6;
  return this;
}



// ===========================================
// Function: Update @ 00010c69
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall Particle::Update(float) */

void __thiscall Particle::Update(Particle *this,float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  
  fVar3 = (float)frameTime / (float)___real_408f400000000000;
  fVar4 = fVar3 * fVar3 * (float)___real_3fe0000000000000;
  if (*(int *)(this + 0x7c) != 0) {
    iVar5 = _rand();
    if (iVar5 % *(int *)(this + 0x80) == 0) {
      uVar6 = _rand();
      fVar1 = (float)(uVar6 & 0x7fff) / (float)___real_40dfffc000000000 -
              (float)___real_3fe0000000000000;
      *(float *)(this + 8) = (fVar1 + fVar1) * *(float *)(this + 0x78);
      uVar6 = _rand();
      fVar1 = (float)(uVar6 & 0x7fff) / (float)___real_40dfffc000000000 -
              (float)___real_3fe0000000000000;
      *(float *)(this + 0xc) = (fVar1 + fVar1) * *(float *)(this + 0x78);
      uVar6 = _rand();
      fVar1 = (float)(uVar6 & 0x7fff) / (float)___real_40dfffc000000000 -
              (float)___real_3fe0000000000000;
      *(float *)(this + 0x10) = (fVar1 + fVar1) * *(float *)(this + 0x78);
    }
    fVar1 = (float)*(int *)(this + 0x84);
    if (*(float *)(this + 0x88) <= *(float *)(this + 0x94)) {
      fVar2 = *(float *)(this + 8) - fVar1;
    }
    else {
      fVar2 = fVar1 + *(float *)(this + 8);
    }
    *(float *)(this + 8) = fVar2;
    if (*(float *)(this + 0x8c) <= *(float *)(this + 0x98)) {
      fVar2 = *(float *)(this + 0xc) - fVar1;
    }
    else {
      fVar2 = fVar1 + *(float *)(this + 0xc);
    }
    *(float *)(this + 0xc) = fVar2;
    if (*(float *)(this + 0x90) <= *(float *)(this + 0x9c)) {
      fVar1 = *(float *)(this + 0x10) - fVar1;
    }
    else {
      fVar1 = fVar1 + *(float *)(this + 0x10);
    }
    *(float *)(this + 0x10) = fVar1;
  }
  *(undefined4 *)(this + 0x94) = *(undefined4 *)(this + 0x68);
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(this + 0x6c);
  *(undefined4 *)(this + 0x9c) = *(undefined4 *)(this + 0x70);
  *(float *)(this + 0x94) =
       *(float *)(this + 0x94) + *(float *)(this + 8) * fVar3 + fVar4 * *(float *)(this + 0x14);
  *(float *)(this + 0x98) =
       *(float *)(this + 0xc) * fVar3 + *(float *)(this + 0x98) + *(float *)(this + 0x18) * fVar4;
  *(float *)(this + 0x9c) =
       *(float *)(this + 0x10) * fVar3 + *(float *)(this + 0x9c) + fVar4 * *(float *)(this + 0x1c);
  *(float *)(this + 8) = *(float *)(this + 8) + *(float *)(this + 0x14) * fVar3;
  *(float *)(this + 0xc) = *(float *)(this + 0x18) * fVar3 + *(float *)(this + 0xc);
  *(float *)(this + 0x10) = fVar3 * *(float *)(this + 0x1c) + *(float *)(this + 0x10);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(this + 0x94);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 0x98);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x9c);
  if (*(int *)(this + 0x2c) != 0) {
    fVar9 = (float10)__CIsin();
    fVar3 = (*(float *)(this + 0x30) + *(float *)(this + 0x34)) * (float)fVar9;
    *(float *)(this + 0x94) = fVar3 * *(float *)(this + 0x20) + *(float *)(this + 0x94);
    *(float *)(this + 0x98) = *(float *)(this + 0x98) + *(float *)(this + 0x24) * fVar3;
    *(float *)(this + 0x9c) = fVar3 * *(float *)(this + 0x28) + *(float *)(this + 0x9c);
  }
  uVar6 = __ftol2_sse();
  uVar7 = __ftol2_sse();
  uVar8 = __ftol2_sse();
  *(uint *)(this + 0xa0) = ((uVar6 & 0xff) << 8 | uVar7 & 0xff) << 8 | uVar8 & 0xff;
  return;
}



// ===========================================
// Function: Load @ 00011085
// ===========================================

/* public: void __thiscall ParticleEmitter::Load(char * *) */

void __thiscall ParticleEmitter::Load(ParticleEmitter *this,char **param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  char **ppcStack00000020;
  char **ppcStack00000028;
  char **ppcStack00000030;
  char **ppcStack0000004c;
  char **ppcStack00000054;
  char **ppcStack0000005c;
  
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 8) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0xc) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x10) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(int *)(this + 0x14) = iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(int *)(this + 0x18) = iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x1c) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000020 = (char **)_atoi(pcVar1);
  *(float *)(this + 0x20) = (float)(int)ppcStack00000020;
  pcVar1 = (char *)_COM_ParseExt(param_1);
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x24) = (float)dVar4;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x28) = (float)dVar4;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x2c) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  ppcStack00000030 = (char **)_atoi(pcVar1);
  ppcStack00000020 = (char **)0x1;
  *(float *)(this + 0x30) = (float)(int)ppcStack00000030;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x34) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x38) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x44) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(float *)(this + 0x48) = (float)iVar2;
  pcVar1 = (char *)_COM_ParseExt(param_1);
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x3c) = (float)dVar4;
  pcVar1 = (char *)_COM_ParseExt(param_1,1);
  ppcStack00000030 = (char **)0x1120c;
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x40) = (float)dVar4;
  ppcStack00000030 = param_1;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000028 = (char **)0x1121d;
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x4c) = (float)dVar4;
  ppcStack00000028 = param_1;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000020 = (char **)0x1122e;
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x50) = (float)dVar4;
  ppcStack00000020 = param_1;
  pcVar1 = (char *)_COM_ParseExt();
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x54) = (float)dVar4;
  pcVar1 = (char *)_COM_ParseExt();
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x58) = (float)dVar4;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  ppcStack0000004c = (char **)0x1;
  *(uint *)(this + 0x5c) = (uint)(iVar2 != 0);
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(uint *)(this + 0x68) = (uint)(iVar2 != 0);
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(uint *)(this + 0x60) = (uint)(iVar2 != 0);
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000030 = (char **)0x112a9;
  dVar4 = _atof(pcVar1);
  *(float *)(this + 100) = (float)dVar4;
  ppcStack00000030 = param_1;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000028 = (char **)0x112ba;
  iVar2 = _atoi(pcVar1);
  ppcStack00000028 = param_1;
  *(uint *)(this + 0x78) = (uint)(iVar2 != 0);
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000020 = (char **)0x112d1;
  _atof(pcVar1);
  uVar3 = __ftol2_sse();
  ppcStack00000020 = param_1;
  *(undefined4 *)(this + 0x7c) = uVar3;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack0000005c = (char **)0x112ea;
  _atof(pcVar1);
  uVar3 = __ftol2_sse();
  ppcStack0000005c = param_1;
  *(undefined4 *)(this + 0x80) = uVar3;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack00000054 = (char **)0x11303;
  dVar4 = _atof(pcVar1);
  *(float *)(this + 0x84) = (float)dVar4;
  ppcStack00000054 = param_1;
  pcVar1 = (char *)_COM_ParseExt();
  ppcStack0000004c = (char **)0x11317;
  _atof(pcVar1);
  uVar3 = __ftol2_sse();
  ppcStack0000004c = param_1;
  *(undefined4 *)(this + 0x88) = uVar3;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(uint *)(this + 0x8c) = (uint)(iVar2 != 0);
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(int *)(this + 0x90) = iVar2;
  pcVar1 = (char *)_COM_ParseExt();
  iVar2 = _atoi(pcVar1);
  *(int *)(this + 0x94) = iVar2;
  return;
}



// ===========================================
// Function: SetTexel @ 0001136c
// ===========================================

/* public: void __thiscall GhostTexture::SetTexel(int,int,unsigned int) */

void __thiscall GhostTexture::SetTexel(GhostTexture *this,int param_1,int param_2,uint param_3)

{
  *(uint *)(*(int *)(this + 0x18) + (*(int *)(this + 0xc) * param_2 + param_1) * 4) = param_3;
  return;
}



// ===========================================
// Function: Burn @ 00011385
// ===========================================

/* public: void __thiscall GhostTexture::Burn(void) */

void __thiscall GhostTexture::Burn(GhostTexture *this)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_c;
  int local_8;
  
  if (*(int *)(this + 0x24) == 0) {
    if ((*(int *)(this + 0x20) != 0) && (local_c = 1, 1 < *(int *)(this + 0x10) + -1)) {
      do {
        iVar6 = *(int *)(this + 0x18) + *(int *)(this + 0xc) * local_c * 4;
        local_8 = 1;
        if (1 < *(int *)(this + 0xc) + -1) {
          puVar7 = (uint *)(iVar6 + 8);
          do {
            puVar1 = (uint *)(iVar6 + (*(int *)(this + 0xc) + local_8) * 4);
            uVar5 = ((int)((puVar7[-2] & 0xff) + (*puVar7 & 0xff) + (*puVar1 & 0xff) +
                          (puVar7[-1] & 0xff)) >> 2) - *(int *)(this + 0x2c);
            uVar10 = ((int)((uint)*(byte *)((int)puVar7 + -7) + (uint)*(byte *)((int)puVar7 + -3) +
                            (uint)*(byte *)((int)puVar7 + 1) + (uint)*(byte *)((int)puVar1 + 1)) >>
                     2) - *(int *)(this + 0x2c);
            uVar4 = ((int)((uint)*(byte *)((int)puVar7 + -6) + (uint)*(byte *)((int)puVar7 + -2) +
                           (uint)*(byte *)((int)puVar7 + 2) + (uint)*(byte *)((int)puVar1 + 2)) >> 2
                    ) - *(int *)(this + 0x2c);
            if ((int)uVar5 < 0) {
              uVar5 = 0;
            }
            if ((int)uVar10 < 0) {
              uVar10 = 0;
            }
            if ((int)uVar4 < 0) {
              uVar4 = 0;
            }
            uVar4 = ((uVar4 & 0xff) << 8 | uVar10 & 0xff) << 8 | uVar5 & 0xff;
            if (uVar4 != 0) {
              puVar7[-1] = uVar4;
            }
            local_8 = local_8 + 1;
            puVar7 = puVar7 + 1;
          } while (local_8 < *(int *)(this + 0xc) + -1);
        }
        local_c = local_c + 1;
      } while (local_c < *(int *)(this + 0x10) + -1);
    }
  }
  else {
    iVar6 = 1;
    if (1 < *(int *)(this + 0x10) + -1) {
      iVar8 = *(int *)(this + 0xc);
      iVar9 = iVar8 + -1;
      do {
        iVar3 = *(int *)(this + 0x18) + iVar8 * iVar6 * 4;
        iVar2 = 1;
        if (1 < iVar9) {
          do {
            uVar4 = (*(uint *)(iVar3 + iVar2 * 4) & 0xff) - *(int *)(this + 0x28);
            local_c = (uint)*(byte *)(iVar3 + 1 + iVar2 * 4) - *(int *)(this + 0x28);
            iVar9 = (uint)*(byte *)(iVar3 + 2 + iVar2 * 4) - *(int *)(this + 0x28);
            if ((int)uVar4 < 0) {
              uVar4 = 0;
            }
            if (local_c < 0) {
              local_c = 0;
            }
            if (iVar9 < 0) {
              local_8._0_1_ = 0;
            }
            else {
              local_8._0_1_ = (undefined1)iVar9;
            }
            *(uint *)(iVar3 + iVar2 * 4) =
                 (uint)CONCAT11((undefined1)local_8,(undefined1)local_c) << 8 | uVar4 & 0xff;
            iVar8 = *(int *)(this + 0xc);
            iVar2 = iVar2 + 1;
            iVar9 = iVar8 + -1;
          } while (iVar2 < iVar9);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(this + 0x10) + -1);
    }
  }
  iVar6 = *(int *)(this + 0x18);
  iVar9 = 0;
  if (0 < *(int *)(this + 0xc)) {
    do {
      *(undefined4 *)(iVar6 + iVar9 * 4) = 0;
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(this + 0xc));
  }
  iVar9 = 0;
  if (0 < *(int *)(this + 0x10)) {
    iVar8 = 4;
    do {
      *(undefined4 *)(iVar6 + *(int *)(this + 0xc) * iVar9 * 4) = 0;
      iVar9 = iVar9 + 1;
      *(undefined4 *)(*(int *)(this + 0xc) * iVar8 + -4 + iVar6) = 0;
      iVar8 = iVar8 + 4;
    } while (iVar9 < *(int *)(this + 0x10));
  }
  iVar6 = *(int *)(this + 0x10);
  iVar9 = *(int *)(this + 0xc);
  iVar8 = *(int *)(this + 0x18);
  iVar3 = 0;
  if (0 < iVar9) {
    do {
      *(undefined4 *)(iVar8 + (iVar6 + -1) * iVar9 * 4 + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0xc));
  }
  return;
}



// ===========================================
// Function: ComputeOutCode @ 000115cb
// ===========================================

/* public: unsigned int __thiscall GhostTexture::ComputeOutCode(int,int,int,int,int,int) */

uint __thiscall
GhostTexture::ComputeOutCode
          (GhostTexture *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          int param_6)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_6 < param_2) {
    uVar1 = 1;
  }
  else if (param_2 < param_5) {
    uVar1 = 2;
  }
  if (param_4 < param_1) {
    return uVar1 | 4;
  }
  if (param_1 < param_3) {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}



// ===========================================
// Function: ClipAndDrawLine @ 00011605
// ===========================================

/* public: void __thiscall GhostTexture::ClipAndDrawLine(class Vector,class Vector,int) */

void __thiscall GhostTexture::ClipAndDrawLine(GhostTexture *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uStack00000010;
  undefined4 in_stack_0000001c;
  int iStack_20;
  int iStack_18;
  uint uStack_14;
  uint uStack_10;
  
  iVar2 = __ftol2_sse();
  iVar3 = __ftol2_sse();
  iStack_20 = __ftol2_sse();
  iVar4 = __ftol2_sse();
  iVar1 = *(int *)(this + 0xc);
  iVar9 = *(int *)(this + 0x10) + -1;
  iVar5 = iVar1 + -1;
  uStack_10 = 0;
  if (iVar9 < iVar3) {
    uStack_10 = 1;
  }
  else if (iVar3 < 0) {
    uStack_10 = 2;
  }
  if (iVar5 < iVar2) {
    uStack_10 = uStack_10 | 4;
  }
  else if (iVar2 < 0) {
    uStack_10 = uStack_10 | 8;
  }
  uStack_14 = 0;
  if (iVar9 < iVar4) {
    uStack_14 = 1;
  }
  else if (iVar4 < 0) {
    uStack_14 = 2;
  }
  if (iVar5 < iStack_20) {
    uStack_14 = uStack_14 | 4;
  }
  else if (iStack_20 < 0) {
    uStack_14 = uStack_14 | 8;
  }
  while (uStack_14 != 0 || uStack_10 != 0) {
    if ((uStack_10 & uStack_14) != 0) {
      return;
    }
    uStack00000010 = uStack_10;
    if (uStack_10 == 0) {
      uStack00000010 = uStack_14;
    }
    if ((uStack00000010 & 1) == 0) {
      if ((uStack00000010 & 2) == 0) {
        if ((uStack00000010 & 4) == 0) {
          iVar7 = iVar3;
          iVar12 = iVar2;
          if (uStack00000010 != 0) {
            iVar7 = iVar3 - ((iVar4 - iVar3) * iVar2) / (iStack_20 - iVar2);
            iVar12 = 0;
          }
        }
        else {
          iVar7 = ((iVar5 - iVar2) * (iVar4 - iVar3)) / (iStack_20 - iVar2) + iVar3;
          iVar12 = iVar5;
        }
      }
      else {
        iVar7 = 0;
        iVar12 = iVar2 - ((iStack_20 - iVar2) * iVar3) / (iVar4 - iVar3);
      }
    }
    else {
      iVar7 = iVar9;
      iVar12 = ((iVar9 - iVar3) * (iStack_20 - iVar2)) / (iVar4 - iVar3) + iVar2;
    }
    if (uStack00000010 == uStack_10) {
      uStack_10 = 0;
      if (iVar9 < iVar7) {
        uStack_10 = 1;
      }
      else if (iVar7 < 0) {
        uStack_10 = 2;
      }
      iVar3 = iVar7;
      iVar2 = iVar12;
      if (iVar5 < iVar12) {
        uStack_10 = uStack_10 | 4;
      }
      else if (iVar12 < 0) {
        uStack_10 = uStack_10 | 8;
      }
    }
    else {
      uStack_14 = 0;
      if (iVar9 < iVar7) {
        uStack_14 = 1;
      }
      else if (iVar7 < 0) {
        uStack_14 = 2;
      }
      iVar4 = iVar7;
      iStack_20 = iVar12;
      if (iVar5 < iVar12) {
        uStack_14 = uStack_14 | 4;
      }
      else if (iVar12 < 0) {
        uStack_14 = uStack_14 | 8;
      }
    }
  }
  uVar10 = iStack_20 - iVar2;
  iVar8 = (uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f);
  iVar7 = iVar8 * 2;
  uVar11 = iVar4 - iVar3;
  iVar5 = (uint)(-1 < (int)uVar10) * 2 + -1;
  iVar6 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
  iVar12 = iVar6 * 2;
  iVar9 = (uint)(-1 < (int)uVar11) * 2 + -1;
  if (iVar12 < iVar7) {
    iStack_18 = -(iVar7 >> 1);
    *(undefined4 *)(*(int *)(this + 0x18) + (iVar1 * iVar3 + iVar2) * 4) = in_stack_0000001c;
    if (iVar2 != iStack_20) {
      do {
        iStack_18 = iVar12 + iStack_18;
        if (-1 < iStack_18) {
          iVar3 = iVar3 + iVar9;
          iStack_18 = iStack_18 + iVar8 * -2;
        }
        iVar2 = iVar2 + iVar5;
        *(undefined4 *)(*(int *)(this + 0x18) + (*(int *)(this + 0xc) * iVar3 + iVar2) * 4) =
             in_stack_0000001c;
      } while (iVar2 != iStack_20);
      return;
    }
  }
  else {
    iVar12 = -(iVar12 >> 1);
    *(undefined4 *)(*(int *)(this + 0x18) + (iVar1 * iVar3 + iVar2) * 4) = in_stack_0000001c;
    uStack_14 = iVar2;
    while (iVar3 != iVar4) {
      iVar12 = iVar7 + iVar12;
      if (-1 < iVar12) {
        uStack_14 = uStack_14 + iVar5;
        iVar12 = iVar12 + iVar6 * -2;
      }
      iVar3 = iVar3 + iVar9;
      *(undefined4 *)(*(int *)(this + 0x18) + (*(int *)(this + 0xc) * iVar3 + uStack_14) * 4) =
           in_stack_0000001c;
    }
  }
  return;
}



// ===========================================
// Function: RotateVector @ 00011904
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class Vector __thiscall GhostTexture::RotateVector(class Vector,float) */

float * __thiscall
GhostTexture::RotateVector(undefined4 param_1,float *param_2,float param_3,float param_4)

{
  float10 fVar1;
  float10 fVar2;
  
  param_2[2] = 0.0;
  fVar1 = (float10)__CIcos();
  fVar2 = (float10)__CIsin();
  *param_2 = param_3 * (float)fVar1 - param_4 * (float)fVar2;
  param_2[1] = (float)fVar1 * param_4 + (float)fVar2 * param_3;
  return param_2;
}



// ===========================================
// Function: GenerateLightning @ 00011969
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall GhostTexture::GenerateLightning(class Vector,class
   Vector,int,float,int,int) */

void __thiscall
GhostTexture::GenerateLightning
          (GhostTexture *this,float param_2,float param_3,float param_4,float param_5,float param_6,
          float param_7,undefined4 param_8,float param_9,int param_10,int param_11)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float10 fVar6;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 auStack_c [12];
  
  local_24 = 0.0;
  local_20 = 0.0;
  local_1c = 0.0;
  if (param_10 == param_11) {
    fVar1 = (float)___real_3fe0000000000000;
    ClipAndDrawLine(this,param_2 + fVar1,param_3 + fVar1,param_4,param_5 + fVar1,fVar1 + param_6,
                    param_7,param_8);
    return;
  }
  local_24 = param_5 - param_2;
  local_20 = param_6 - param_3;
  local_1c = param_7 - param_4;
  local_18 = local_24;
  local_14 = local_20;
  local_10 = local_1c;
  fVar6 = (float10)__CIsqrt();
  fVar1 = (float)fVar6 * (float)___real_3fe0000000000000;
  Vector::normalize((Vector *)&local_24);
  iVar4 = _rand();
  pfVar5 = (float *)RotateVector(this,auStack_c,local_24,local_20,local_1c,
                                 ((float)iVar4 / (float)___real_40dfffc000000000) *
                                 (param_9 - -param_9) + -param_9);
  local_24 = fVar1 * *pfVar5;
  local_20 = pfVar5[1] * fVar1;
  local_1c = fVar1 * pfVar5[2];
  fVar1 = local_24 + param_2;
  fVar2 = local_20 + param_3;
  fVar3 = param_4 + local_1c;
  local_18 = fVar1;
  local_14 = fVar2;
  local_10 = fVar3;
  GenerateLightning(this,param_2,param_3,param_4,fVar1,fVar2,fVar3,param_8,param_9,param_10 + 1,
                    param_11);
  GenerateLightning(this,fVar1,fVar2,fVar3,param_5,param_6,param_7,param_8,param_9,param_10 + 1,
                    param_11);
  return;
}



// ===========================================
// Function: FreeObjectList @ 00011bf1
// ===========================================

/* public: void __thiscall Container<class Particle *>::FreeObjectList(void) */

void __thiscall Container<class_Particle*>::FreeObjectList(Container<class_Particle*> *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: ClearObjectList @ 00011c19
// ===========================================

/* public: void __thiscall Container<class Particle *>::ClearObjectList(void) */

void __thiscall Container<class_Particle*>::ClearObjectList(Container<class_Particle*> *this)

{
  void *pvVar1;
  
  if ((*(void **)this != (void *)0x0) && (*(int *)(this + 4) != 0)) {
    operator_delete(*(void **)this);
    pvVar1 = operator_new(-(uint)((int)((ulonglong)*(uint *)(this + 8) * 4 >> 0x20) != 0) |
                          (uint)((ulonglong)*(uint *)(this + 8) * 4));
    *(void **)this = pvVar1;
    *(undefined4 *)(this + 4) = 0;
  }
  return;
}



// ===========================================
// Function: NumObjects @ 00011c55
// ===========================================

/* public: int __thiscall Container<class Particle *>::NumObjects(void) */

int __thiscall Container<class_Particle*>::NumObjects(Container<class_Particle*> *this)

{
  return *(int *)(this + 4);
}



// ===========================================
// Function: Resize @ 00011c59
// ===========================================

/* public: void __thiscall Container<class Particle *>::Resize(int) */

void __thiscall Container<class_Particle*>::Resize(Container<class_Particle*> *this,int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_1 < 1) {
    if (*(void **)this != (void *)0x0) {
      operator_delete(*(void **)this);
    }
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    return;
  }
  pvVar1 = *(void **)this;
  *(int *)(this + 8) = param_1;
  if (pvVar1 != (void *)0x0) {
    if (param_1 < *(int *)(this + 4)) {
      *(int *)(this + 8) = *(int *)(this + 4);
    }
    pvVar2 = operator_new(-(uint)((int)((ulonglong)*(uint *)(this + 8) * 4 >> 0x20) != 0) |
                          (uint)((ulonglong)*(uint *)(this + 8) * 4));
    *(void **)this = pvVar2;
    iVar3 = 0;
    if (0 < *(int *)(this + 4)) {
      do {
        *(undefined4 *)(*(int *)this + iVar3 * 4) = *(undefined4 *)((int)pvVar1 + iVar3 * 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(this + 4));
    }
    operator_delete(pvVar1);
    return;
  }
  pvVar1 = operator_new(-(uint)((int)((ulonglong)(uint)param_1 * 4 >> 0x20) != 0) |
                        (uint)((ulonglong)(uint)param_1 * 4));
  *(void **)this = pvVar1;
  return;
}



// ===========================================
// Function: SetObjectAt @ 00011d05
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall Container<class Particle *>::SetObjectAt(int,class Particle * &) */

void __thiscall
Container<class_Particle*>::SetObjectAt
          (Container<class_Particle*> *this,int param_1,Particle **param_2)

{
  if ((param_1 < 1) || (*(int *)(this + 4) < param_1)) {
    (*_DAT_000143cc)(1,s_Container__SetObjectAt___index_o);
  }
  *(Particle **)(*(int *)this + -4 + param_1 * 4) = *param_2;
  return;
}



// ===========================================
// Function: AddObject @ 00011d37
// ===========================================

/* public: int __thiscall Container<class Particle *>::AddObject(class Particle * &) */

int __thiscall
Container<class_Particle*>::AddObject(Container<class_Particle*> *this,Particle **param_1)

{
  if (*(int *)this == 0) {
    Resize(this,10);
  }
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    Resize(this,*(int *)(this + 8) * 2);
  }
  *(Particle **)(*(int *)this + *(int *)(this + 4) * 4) = *param_1;
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(int *)(this + 4);
}



// ===========================================
// Function: AddObjectAt @ 00011d70
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall Container<class Particle *>::AddObjectAt(int,class Particle * &) */

void __thiscall
Container<class_Particle*>::AddObjectAt
          (Container<class_Particle*> *this,int param_1,Particle **param_2)

{
  if (*(int *)(this + 8) < param_1) {
    Resize(this,param_1);
  }
  if (*(int *)(this + 4) < param_1) {
    *(int *)(this + 4) = param_1;
  }
  if ((param_1 < 1) || (*(int *)(this + 4) < param_1)) {
    (*_DAT_000143cc)(1,s_Container__SetObjectAt___index_o);
  }
  *(Particle **)(*(int *)this + -4 + param_1 * 4) = *param_2;
  return;
}



// ===========================================
// Function: IndexOfObject @ 00011db5
// ===========================================

/* public: int __thiscall Container<class Particle *>::IndexOfObject(class Particle * &) */

int __thiscall
Container<class_Particle*>::IndexOfObject(Container<class_Particle*> *this,Particle **param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(this + 4)) {
    piVar2 = *(int **)this;
    do {
      iVar1 = iVar1 + 1;
      if ((Particle *)*piVar2 == *param_1) {
        return iVar1;
      }
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(this + 4));
  }
  return 0;
}



// ===========================================
// Function: ObjectInList @ 00011dd9
// ===========================================

/* public: int __thiscall Container<class Particle *>::ObjectInList(class Particle * &) */

int __thiscall
Container<class_Particle*>::ObjectInList(Container<class_Particle*> *this,Particle **param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(this + 4)) {
    piVar2 = *(int **)this;
    while ((Particle *)*piVar2 != *param_1) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (*(int *)(this + 4) <= iVar1) {
        return 0;
      }
    }
    if (iVar1 != -1) {
      return 1;
    }
  }
  return 0;
}



// ===========================================
// Function: ObjectAt @ 00011e11
// ===========================================

/* public: class Particle * & __thiscall Container<class Particle *>::ObjectAt(int) */

Particle ** __thiscall
Container<class_Particle*>::ObjectAt(Container<class_Particle*> *this,int param_1)

{
  if ((param_1 < 1) || (*(int *)(this + 4) < param_1)) {
    _Com_Error(1,s_Container__ObjectAt___index_out_);
  }
  return (Particle **)(*(int *)this + -4 + param_1 * 4);
}



// ===========================================
// Function: AddressOfObjectAt @ 00011e3c
// ===========================================

/* public: class Particle * * __thiscall Container<class Particle *>::AddressOfObjectAt(int) */

Particle ** __thiscall
Container<class_Particle*>::AddressOfObjectAt(Container<class_Particle*> *this,int param_1)

{
  if (*(int *)(this + 8) < param_1) {
    _Com_Error(1,s_Container__AddressOfObjectAt___i);
  }
  if (*(int *)(this + 4) < param_1) {
    *(int *)(this + 4) = param_1;
  }
  return (Particle **)(*(int *)this + -4 + param_1 * 4);
}



// ===========================================
// Function: RemoveObjectAt @ 00011e6b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall Container<class Particle *>::RemoveObjectAt(int) */

void __thiscall
Container<class_Particle*>::RemoveObjectAt(Container<class_Particle*> *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)this == 0) {
    (*__ri)(3,s_Container__RemoveObjectAt___Empt);
    return;
  }
  if ((param_1 < 1) || (*(int *)(this + 4) < param_1)) {
    (*_DAT_000143cc)(1,s_Container__RemoveObjectAt___inde);
  }
  else {
    iVar1 = *(int *)(this + 4) + -1;
    iVar3 = param_1 + -1;
    *(int *)(this + 4) = iVar1;
    if (iVar3 < iVar1) {
      do {
        iVar2 = iVar3 * 4;
        iVar1 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(*(int *)this + iVar1) = *(undefined4 *)(*(int *)this + 4 + iVar2);
      } while (iVar3 < *(int *)(this + 4));
      return;
    }
  }
  return;
}



// ===========================================
// Function: RemoveObject @ 00011ec9
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall Container<class Particle *>::RemoveObject(class Particle * &) */

void __thiscall
Container<class_Particle*>::RemoveObject(Container<class_Particle*> *this,Particle **param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(this + 4)) {
    piVar2 = *(int **)this;
    do {
      if ((Particle *)*piVar2 == *param_1) {
        if (iVar1 + 1 != 0) {
          RemoveObjectAt(this,iVar1 + 1);
          return;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(this + 4));
  }
  (*__ri)(3,s_Container__RemoveObject___Object);
  return;
}



// ===========================================
// Function: Sort @ 00011f0f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall Container<class Particle *>::Sort(int (__cdecl*)(void const *,void const
   *)) */

void __thiscall
Container<class_Particle*>::Sort
          (Container<class_Particle*> *this,_func_int_void_ptr_void_ptr *param_1)

{
  if (*(void **)this == (void *)0x0) {
    (*__ri)(3,s_Container__RemoveObjectAt___Empt);
    return;
  }
  _qsort(*(void **)this,*(size_t *)(this + 4),4,(__compar_fn_t)param_1);
  return;
}



// ===========================================
// Function: NumObjects @ 00011f3f
// ===========================================

/* public: int __thiscall Container<class ParticleEmitter *>::NumObjects(void) */

int __thiscall
Container<class_ParticleEmitter*>::NumObjects(Container<class_ParticleEmitter*> *this)

{
  return *(int *)(this + 4);
}



// ===========================================
// Function: ObjectAt @ 00011f43
// ===========================================

/* public: class ParticleEmitter * & __thiscall Container<class ParticleEmitter *>::ObjectAt(int) */

ParticleEmitter ** __thiscall
Container<class_ParticleEmitter*>::ObjectAt(Container<class_ParticleEmitter*> *this,int param_1)

{
  if ((param_1 < 1) || (*(int *)(this + 4) < param_1)) {
    _Com_Error(1,s_Container__ObjectAt___index_out_);
  }
  return (ParticleEmitter **)(*(int *)this + -4 + param_1 * 4);
}



// ===========================================
// Function: NumObjects @ 00011f6e
// ===========================================

/* public: int __thiscall Container<class GhostTexture *>::NumObjects(void) */

int __thiscall Container<class_GhostTexture*>::NumObjects(Container<class_GhostTexture*> *this)

{
  return *(int *)(this + 4);
}



// ===========================================
// Function: ObjectAt @ 00011f72
// ===========================================

/* public: class GhostTexture * & __thiscall Container<class GhostTexture *>::ObjectAt(int) */

GhostTexture ** __thiscall
Container<class_GhostTexture*>::ObjectAt(Container<class_GhostTexture*> *this,int param_1)

{
  if ((param_1 < 1) || (*(int *)(this + 4) < param_1)) {
    _Com_Error(1,s_Container__ObjectAt___index_out_);
  }
  return (GhostTexture **)(*(int *)this + -4 + param_1 * 4);
}



// ===========================================
// Function: FreeObjectList @ 00011f9d
// ===========================================

/* public: void __thiscall Container<class ParticleEmitter *>::FreeObjectList(void) */

void __thiscall
Container<class_ParticleEmitter*>::FreeObjectList(Container<class_ParticleEmitter*> *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: Resize @ 00011fc5
// ===========================================

/* public: void __thiscall Container<class ParticleEmitter *>::Resize(int) */

void __thiscall
Container<class_ParticleEmitter*>::Resize(Container<class_ParticleEmitter*> *this,int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_1 < 1) {
    if (*(void **)this != (void *)0x0) {
      operator_delete(*(void **)this);
    }
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    return;
  }
  pvVar1 = *(void **)this;
  *(int *)(this + 8) = param_1;
  if (pvVar1 != (void *)0x0) {
    if (param_1 < *(int *)(this + 4)) {
      *(int *)(this + 8) = *(int *)(this + 4);
    }
    pvVar2 = operator_new(-(uint)((int)((ulonglong)*(uint *)(this + 8) * 4 >> 0x20) != 0) |
                          (uint)((ulonglong)*(uint *)(this + 8) * 4));
    *(void **)this = pvVar2;
    iVar3 = 0;
    if (0 < *(int *)(this + 4)) {
      do {
        *(undefined4 *)(*(int *)this + iVar3 * 4) = *(undefined4 *)((int)pvVar1 + iVar3 * 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(this + 4));
    }
    operator_delete(pvVar1);
    return;
  }
  pvVar1 = operator_new(-(uint)((int)((ulonglong)(uint)param_1 * 4 >> 0x20) != 0) |
                        (uint)((ulonglong)(uint)param_1 * 4));
  *(void **)this = pvVar1;
  return;
}



// ===========================================
// Function: FreeObjectList @ 00012071
// ===========================================

/* public: void __thiscall Container<class GhostTexture *>::FreeObjectList(void) */

void __thiscall Container<class_GhostTexture*>::FreeObjectList(Container<class_GhostTexture*> *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: Resize @ 00012099
// ===========================================

/* public: void __thiscall Container<class GhostTexture *>::Resize(int) */

void __thiscall
Container<class_GhostTexture*>::Resize(Container<class_GhostTexture*> *this,int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_1 < 1) {
    if (*(void **)this != (void *)0x0) {
      operator_delete(*(void **)this);
    }
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    return;
  }
  pvVar1 = *(void **)this;
  *(int *)(this + 8) = param_1;
  if (pvVar1 != (void *)0x0) {
    if (param_1 < *(int *)(this + 4)) {
      *(int *)(this + 8) = *(int *)(this + 4);
    }
    pvVar2 = operator_new(-(uint)((int)((ulonglong)*(uint *)(this + 8) * 4 >> 0x20) != 0) |
                          (uint)((ulonglong)*(uint *)(this + 8) * 4));
    *(void **)this = pvVar2;
    iVar3 = 0;
    if (0 < *(int *)(this + 4)) {
      do {
        *(undefined4 *)(*(int *)this + iVar3 * 4) = *(undefined4 *)((int)pvVar1 + iVar3 * 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(this + 4));
    }
    operator_delete(pvVar1);
    return;
  }
  pvVar1 = operator_new(-(uint)((int)((ulonglong)(uint)param_1 * 4 >> 0x20) != 0) |
                        (uint)((ulonglong)(uint)param_1 * 4));
  *(void **)this = pvVar1;
  return;
}



// ===========================================
// Function: DelRef @ 00012145
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
// Function: ~str @ 0001216e
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
// Function: Emit @ 0001219f
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall ParticleEmitter::Emit(float) */

void __thiscall ParticleEmitter::Emit(ParticleEmitter *this,float param_1)

{
  Container<class_Particle*> *this_00;
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
  int iVar11;
  Particle *pPVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  float local_40;
  
  fVar1 = *(float *)(this + 0x24);
  fVar2 = *(float *)(this + 0x28);
  iVar11 = _rand();
  fVar1 = ((float)iVar11 / (float)___real_40dfffc000000000) * (fVar2 - fVar1) + fVar1;
  local_40 = param_1 - *(float *)(this + 4);
  if (NAN(fVar1) == (fVar1 == 0.0)) {
    if (fVar1 < local_40) {
      this_00 = (Container<class_Particle*> *)(this + 0x9c);
      do {
        pPVar12 = (Particle *)operator_new(0xa4);
        if (pPVar12 == (Particle *)0x0) {
          uVar17 = 0;
        }
        else {
          fVar2 = *(float *)(this + 0x2c);
          uVar17 = *(undefined4 *)(this + 0x8c);
          fVar3 = *(float *)(this + 0x30);
          iVar11 = _rand();
          fVar8 = (float)___real_40dfffc000000000;
          fVar4 = *(float *)(this + 0x54);
          fVar5 = *(float *)(this + 0x58);
          iVar13 = _rand();
          fVar9 = (float)___real_40dfffc000000000;
          fVar6 = *(float *)(this + 0x1c);
          fVar7 = *(float *)(this + 0x20);
          iVar14 = _rand();
          fVar10 = (float)___real_40dfffc000000000;
          puVar15 = (undefined4 *)GetAcceleration(this);
          puVar16 = (undefined4 *)GetVelocity(this);
          uVar17 = Particle::Particle(pPVar12,*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc),
                                      *(undefined4 *)(this + 0x10),*puVar16,puVar16[1],puVar16[2],
                                      *puVar15,puVar15[1],puVar15[2],*(undefined4 *)(this + 0x14),
                                      *(undefined4 *)(this + 0x18),
                                      ((float)iVar14 / fVar10) * (fVar7 - fVar6) + fVar6,
                                      *(undefined4 *)(this + 0x5c),
                                      ((float)iVar13 / fVar9) * (fVar5 - fVar4) + fVar4,param_1,
                                      ((float)iVar11 / fVar8) * (fVar3 - fVar2) + fVar2 + param_1,
                                      *(undefined4 *)(this + 0x40),*(undefined4 *)(this + 8),
                                      *(undefined4 *)(this + 0xc),*(undefined4 *)(this + 0x10),
                                      uVar17,*(undefined4 *)(this + 0x90),
                                      *(undefined4 *)(this + 0x94));
        }
        if (*(int *)this_00 == 0) {
          Container<class_Particle*>::Resize(this_00,10);
        }
        if (*(int *)(this + 0xa0) == *(int *)(this + 0xa4)) {
          Container<class_Particle*>::Resize(this_00,*(int *)(this + 0xa4) * 2);
        }
        local_40 = local_40 - fVar1;
        *(undefined4 *)(*(int *)this_00 + *(int *)(this + 0xa0) * 4) = uVar17;
        *(int *)(this + 0xa0) = *(int *)(this + 0xa0) + 1;
        *(float *)(this + 4) = param_1;
      } while (fVar1 < local_40);
      return;
    }
  }
  else {
    *(float *)(this + 4) = param_1;
  }
  return;
}



// ===========================================
// Function: Update @ 00012422
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall GhostTexture::Update(void) */

void __thiscall GhostTexture::Update(GhostTexture *this)

{
  int iVar1;
  ParticleEmitter *this_00;
  Particle *this_01;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar9;
  int local_58;
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
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  fVar3 = (float)_DAT_00014f28 / (float)___real_408f400000000000;
  iVar1 = *(int *)(this + 4);
  local_58 = 1;
  if (0 < iVar1) {
    fVar9 = (float10)0;
    do {
      if ((local_58 < 1) || (*(int *)(this + 4) < local_58)) {
        _Com_Error(1,s_Container__ObjectAt___index_out_);
        fVar9 = (float10)0;
      }
      this_00 = *(ParticleEmitter **)(*(int *)this + -4 + local_58 * 4);
      if (*(int *)(this_00 + 0x60) != 0) {
        return;
      }
      if (*(int *)(this_00 + 0x78) == 0) {
        if (*(int *)(this_00 + 0x68) != 0) {
          ParticleEmitter::Emit(this_00,fVar3);
          goto LAB_00012641;
        }
        uStack_14 = *(undefined4 *)(this_00 + 0xc);
        uStack_18 = *(undefined4 *)(this_00 + 8);
        uStack_10 = *(undefined4 *)(this_00 + 0x10);
        iVar6 = __ftol2_sse();
        iVar4 = *(int *)(this + 0xc);
        iVar7 = __ftol2_sse();
        *(undefined4 *)(*(int *)(this + 0x18) + (iVar6 * iVar4 + iVar7) * 4) =
             *(undefined4 *)(this_00 + 0x14);
        fVar9 = extraout_ST0;
      }
      else {
        fStack_30 = (float)fVar9;
        fStack_2c = (float)fVar9;
        fStack_28 = (float)fVar9;
        fStack_48 = (float)fVar9;
        fStack_44 = (float)fVar9;
        fStack_40 = (float)fVar9;
        _rand();
        iVar4 = __ftol2_sse();
        if (iVar4 != 0) {
          fStack_3c = *(float *)(this_00 + 8);
          fStack_38 = *(float *)(this_00 + 0xc);
          fStack_34 = *(float *)(this_00 + 0x10);
          fStack_30 = fStack_3c;
          fStack_2c = fStack_38;
          fStack_28 = fStack_34;
          pfVar5 = (float *)ParticleEmitter::GetVelocity(this_00);
          fStack_48 = *pfVar5;
          fStack_44 = pfVar5[1];
          fStack_40 = pfVar5[2];
          fStack_24 = fStack_48;
          fStack_20 = fStack_44;
          fStack_1c = fStack_40;
          Vector::normalize((Vector *)&fStack_48);
          _rand();
          iVar4 = __ftol2_sse();
          fVar2 = (float)iVar4;
          fStack_48 = fStack_3c + fVar2 * fStack_48;
          fStack_44 = fStack_44 * fVar2 + fStack_38;
          fStack_40 = fVar2 * fStack_40 + fStack_34;
          GenerateLightning(this,fStack_30,fStack_2c,fStack_28,fStack_48,fStack_44,fStack_40,
                            *(undefined4 *)(this_00 + 0x14),*(undefined4 *)(this_00 + 0x84),0,
                            *(undefined4 *)(this_00 + 0x88));
        }
LAB_00012641:
        fVar9 = (float10)0;
      }
      iVar4 = *(int *)(this_00 + 0xa0);
      if (0 < iVar4) {
        do {
          if ((iVar4 < 1) || (*(int *)(this_00 + 0xa0) < iVar4)) {
            _Com_Error(1,s_Container__ObjectAt___index_out_);
          }
          this_01 = *(Particle **)(*(int *)(this_00 + 0x9c) + -4 + iVar4 * 4);
          Particle::Update(this_01,fVar3);
          iVar6 = *(int *)(this + 0xc);
          fVar2 = (float)iVar6;
          if ((((fVar2 < *(float *)(this_01 + 0x94) != (fVar2 == *(float *)(this_01 + 0x94))) ||
               (*(float *)(this_01 + 0x94) < 0.0)) ||
              ((float)*(int *)(this + 0x10) < *(float *)(this_01 + 0x98) !=
               ((float)*(int *)(this + 0x10) == *(float *)(this_01 + 0x98)))) ||
             ((*(float *)(this_01 + 0x98) < 0.0 ||
              (*(float *)(this_01 + 4) < fVar3 != (NAN(*(float *)(this_01 + 4)) || NAN(fVar3)))))) {
            operator_delete(this_01);
            Container<class_Particle*>::RemoveObjectAt
                      ((Container<class_Particle*> *)(this_00 + 0x9c),iVar4);
            fVar9 = (float10)0;
          }
          else {
            iVar7 = __ftol2_sse();
            iVar8 = __ftol2_sse();
            *(undefined4 *)(*(int *)(this + 0x18) + (iVar7 * iVar6 + iVar8) * 4) =
                 *(undefined4 *)(this_01 + 0xa0);
            fVar9 = extraout_ST0_00;
          }
          iVar4 = iVar4 + -1;
        } while (0 < iVar4);
      }
      local_58 = local_58 + 1;
    } while (local_58 <= iVar1);
  }
  return;
}



// ===========================================
// Function: _R_UpdateGhostTextures @ 000127ac
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_UpdateGhostTextures(void)

{
  GhostTexture *this;
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0000210c;
  frameTime = _DAT_00014f28 - lastTime;
  iVar2 = 1;
  lastTime = _DAT_00014f28;
  if (0 < DAT_0000210c) {
    do {
      if ((iVar2 < 1) || (DAT_0000210c < iVar2)) {
        _Com_Error(1,s_Container__ObjectAt___index_out_);
      }
      this = *(GhostTexture **)(_ghostManager + -4 + iVar2 * 4);
      GhostTexture::Update(this);
      GhostTexture::Burn(this);
      _GL_Bind(*(undefined4 *)(this + 0x14));
      (*__qglTexImage2D)(0xde1,0,3,*(undefined4 *)(this + 0xc),*(undefined4 *)(this + 0x10),0,0x1908
                         ,0x1401,*(undefined4 *)(this + 0x18));
      iVar2 = iVar2 + 1;
    } while (iVar2 <= iVar1);
  }
  return;
}



// ===========================================
// Function: _R_SetGhostImage @ 0001284b
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _R_SetGhostImage(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  
  iVar3 = DAT_0000210c;
  iVar7 = 1;
  if (0 < DAT_0000210c) {
    do {
      if ((iVar7 < 1) || (DAT_0000210c < iVar7)) {
        _Com_Error(1,s_Container__ObjectAt___index_out_);
      }
      iVar2 = *(int *)(_ghostManager + -4 + iVar7 * 4);
      if (param_1 != (byte *)0x0) {
        pbVar4 = (byte *)**(undefined4 **)(iVar2 + 0x1c);
        pbVar6 = param_1;
        do {
          bVar1 = *pbVar4;
          bVar8 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_000128b1:
            iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_000128b6;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar8 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_000128b1;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_000128b6:
        if (iVar5 == 0) {
          *(undefined4 *)(iVar2 + 0x14) = param_2;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= iVar3);
  }
  return;
}



// ===========================================
// Function: Container<class_Particle*> @ 000128d0
// ===========================================

/* public: __thiscall Container<class Particle *>::Container<class Particle *>(void) */

void __thiscall
Container<class_Particle*>::Container<class_Particle*>(Container<class_Particle*> *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: ~Container<class_Particle*> @ 000128dd
// ===========================================

/* public: __thiscall Container<class Particle *>::~Container<class Particle *>(void) */

void __thiscall
Container<class_Particle*>::~Container<class_Particle*>(Container<class_Particle*> *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: AddUniqueObject @ 00012905
// ===========================================

/* public: int __thiscall Container<class Particle *>::AddUniqueObject(class Particle * &) */

int __thiscall
Container<class_Particle*>::AddUniqueObject(Container<class_Particle*> *this,Particle **param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(this + 4)) {
    piVar2 = *(int **)this;
    do {
      if ((Particle *)*piVar2 == *param_1) {
        if (iVar1 + 1 != 0) {
          return iVar1 + 1;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(this + 4));
  }
  if (*(int *)this == 0) {
    Resize(this,10);
  }
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    Resize(this,*(int *)(this + 8) * 2);
  }
  *(Particle **)(*(int *)this + *(int *)(this + 4) * 4) = *param_1;
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(int *)(this + 4);
}



// ===========================================
// Function: Container<class_ParticleEmitter*> @ 00012961
// ===========================================

/* public: __thiscall Container<class ParticleEmitter *>::Container<class ParticleEmitter *>(void)
    */

void __thiscall
Container<class_ParticleEmitter*>::Container<class_ParticleEmitter*>
          (Container<class_ParticleEmitter*> *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: ~Container<class_ParticleEmitter*> @ 0001296e
// ===========================================

/* public: __thiscall Container<class ParticleEmitter *>::~Container<class ParticleEmitter *>(void)
    */

void __thiscall
Container<class_ParticleEmitter*>::~Container<class_ParticleEmitter*>
          (Container<class_ParticleEmitter*> *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: AddObject @ 00012996
// ===========================================

/* public: int __thiscall Container<class ParticleEmitter *>::AddObject(class ParticleEmitter * &)
    */

int __thiscall
Container<class_ParticleEmitter*>::AddObject
          (Container<class_ParticleEmitter*> *this,ParticleEmitter **param_1)

{
  if (*(int *)this == 0) {
    Resize(this,10);
  }
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    Resize(this,*(int *)(this + 8) * 2);
  }
  *(ParticleEmitter **)(*(int *)this + *(int *)(this + 4) * 4) = *param_1;
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(int *)(this + 4);
}



// ===========================================
// Function: Container<class_GhostTexture*> @ 000129cf
// ===========================================

/* public: __thiscall Container<class GhostTexture *>::Container<class GhostTexture *>(void) */

void __thiscall
Container<class_GhostTexture*>::Container<class_GhostTexture*>(Container<class_GhostTexture*> *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: ~Container<class_GhostTexture*> @ 000129dc
// ===========================================

/* public: __thiscall Container<class GhostTexture *>::~Container<class GhostTexture *>(void) */

void __thiscall
Container<class_GhostTexture*>::~Container<class_GhostTexture*>
          (Container<class_GhostTexture*> *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: AddObject @ 00012a04
// ===========================================

/* public: int __thiscall Container<class GhostTexture *>::AddObject(class GhostTexture * &) */

int __thiscall
Container<class_GhostTexture*>::AddObject
          (Container<class_GhostTexture*> *this,GhostTexture **param_1)

{
  if (*(int *)this == 0) {
    Resize(this,10);
  }
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    Resize(this,*(int *)(this + 8) * 2);
  }
  *(GhostTexture **)(*(int *)this + *(int *)(this + 4) * 4) = *param_1;
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return *(int *)(this + 4);
}



// ===========================================
// Function: GhostManager @ 00012a3d
// ===========================================

/* public: __thiscall GhostManager::GhostManager(void) */

void __thiscall GhostManager::GhostManager(GhostManager *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: ~GhostManager @ 00012a4a
// ===========================================

/* public: __thiscall GhostManager::~GhostManager(void) */

void __thiscall GhostManager::~GhostManager(GhostManager *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===========================================
// Function: GhostTexture @ 00012a72
// ===========================================

/* public: __thiscall GhostTexture::GhostTexture(void) */

GhostTexture * __thiscall GhostTexture::GhostTexture(GhostTexture *this)

{
  str *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &__ehhandler___0GhostTexture__QAE_XZ;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  this_00 = (str *)(this + 0x1c);
  local_4 = 0;
  *(undefined4 *)this_00 = 0;
  str::EnsureAlloced(this_00,1,true);
  *(undefined1 *)**(undefined4 **)this_00 = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}



// ===========================================
// Function: ParticleEmitter @ 00012acf
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall ParticleEmitter::ParticleEmitter(void) */

void __thiscall ParticleEmitter::ParticleEmitter(ParticleEmitter *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(float *)(this + 4) = (float)_DAT_00014f28 / (float)___real_408f400000000000;
  return;
}



// ===========================================
// Function: ParticleEmitter @ 00012b09
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __thiscall ParticleEmitter::ParticleEmitter(class
   Vector,float,float,float,float,float,float,float,float,float,float,int,int,float,float,int,float,float,float,float,int,int,float,int,int,int,float,int,int,int,int)
    */

ParticleEmitter * __thiscall
ParticleEmitter::ParticleEmitter
          (ParticleEmitter *this,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
          float param_13,float param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
          undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21,
          undefined4 param_22,undefined4 param_23,undefined4 param_24,undefined4 param_25,
          undefined4 param_26,undefined4 param_27,undefined4 param_28,undefined4 param_29,
          undefined4 param_30,undefined4 param_31,undefined4 param_32,undefined4 param_33,
          undefined4 param_34)

{
  float fVar1;
  float fVar2;
  undefined4 unaff_retaddr;
  undefined4 local_4;
  
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = param_3;
  *(undefined4 *)(this + 0x10) = param_4;
  *(undefined4 *)(this + 0x14) = param_15;
  *(undefined4 *)(this + 0x3c) = param_5;
  *(undefined4 *)(this + 0x18) = param_16;
  *(undefined4 *)(this + 0x40) = param_6;
  *(undefined4 *)(this + 0x5c) = param_19;
  *(undefined4 *)(this + 0x34) = param_7;
  *(undefined4 *)(this + 0x68) = param_24;
  *(undefined4 *)(this + 0x38) = param_8;
  *(undefined4 *)(this + 0x60) = param_25;
  *(undefined4 *)(this + 0x4c) = param_9;
  *(undefined4 *)(this + 0x78) = param_27;
  *(undefined4 *)(this + 0x50) = param_10;
  *(undefined4 *)(this + 0x7c) = param_28;
  *(undefined4 *)(this + 0x44) = param_11;
  *(undefined4 *)(this + 0x80) = param_29;
  *(undefined4 *)(this + 0x48) = param_12;
  *(undefined4 *)(this + 0x88) = param_31;
  *(undefined4 *)(this + 0x8c) = param_32;
  *(undefined4 *)(this + 0x90) = param_33;
  *(float *)(this + 0x24) = 1.0 / param_13;
  *(float *)(this + 0x28) = 1.0 / param_14;
  *(undefined4 *)(this + 0x1c) = param_17;
  *(undefined4 *)(this + 0x20) = param_18;
  *(undefined4 *)(this + 0x54) = param_20;
  *(undefined4 *)(this + 0x58) = param_21;
  *(undefined4 *)(this + 0x2c) = param_22;
  *(undefined4 *)(this + 0x30) = param_23;
  *(undefined4 *)(this + 100) = param_26;
  *(undefined4 *)(this + 0x84) = param_30;
  *(undefined4 *)(this + 0x94) = param_34;
  fVar2 = (float)_DAT_00014f28;
  fVar1 = (float)___real_408f400000000000;
  *(float *)this = fVar2 / fVar1;
  *(float *)(this + 4) = fVar2 / fVar1;
  _sscanf(s_0_0_0,s__f__f__f);
  *(undefined4 *)(this + 0x6c) = local_4;
  *(undefined4 *)(this + 0x70) = unaff_retaddr;
  *(undefined4 *)(this + 0x74) = param_2;
  return this;
}



// ===========================================
// Function: ~ParticleEmitter @ 00012ca2
// ===========================================

/* public: __thiscall ParticleEmitter::~ParticleEmitter(void) */

void __thiscall ParticleEmitter::~ParticleEmitter(ParticleEmitter *this)

{
  void *pvVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &__ehhandler___1ParticleEmitter__QAE_XZ;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = *(int *)(this + 0xa0);
  local_4 = 0;
  if (0 < iVar2) {
    do {
      if ((iVar2 < 1) || (*(int *)(this + 0xa0) < iVar2)) {
        _Com_Error(1,s_Container__ObjectAt___index_out_);
      }
      pvVar1 = *(void **)(*(int *)(this + 0x9c) + -4 + iVar2 * 4);
      Container<class_Particle*>::RemoveObjectAt((Container<class_Particle*> *)(this + 0x9c),iVar2);
      operator_delete(pvVar1);
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
  }
  local_4 = 0xffffffff;
  if (*(void **)(this + 0x9c) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x9c));
  }
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}



// ===========================================
// Function: _LoadGHOST @ 00012d59
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _LoadGHOST(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
               undefined4 param_5,int *param_6,undefined4 *param_7,undefined4 param_8,
               undefined4 param_9,int param_10)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  void *pvVar5;
  GhostTexture *this;
  Container<class_ParticleEmitter*> *this_00;
  undefined4 uVar6;
  ParticleEmitter *this_01;
  size_t __size;
  int local_8;
  undefined1 auStack_4 [4];
  
  (*_DAT_00014420)(param_1,&local_8);
  if (local_8 != 0) {
    _COM_ParseExt(&stack0xfffffff4,1);
    pcVar3 = (char *)_COM_ParseExt(&stack0xfffffff4,1);
    iVar4 = _atoi(pcVar3);
    piVar1 = param_4;
    *param_4 = iVar4;
    pcVar3 = (char *)_COM_ParseExt(&local_8,1);
    iVar4 = _atoi(pcVar3);
    piVar2 = param_6;
    *param_6 = iVar4;
    pcVar3 = (char *)_COM_ParseExt(auStack_4,1);
    _atoi(pcVar3);
    __size = *piVar1 * *piVar2;
    pvVar5 = _calloc(1,__size * 4);
    *param_7 = pvVar5;
    this = (GhostTexture *)operator_new(0x30);
    if (this == (GhostTexture *)0x0) {
      this_00 = (Container<class_ParticleEmitter*> *)0x0;
    }
    else {
      this_00 = (Container<class_ParticleEmitter*> *)GhostTexture::GhostTexture(this);
    }
    *(int *)(this_00 + 0xc) = *piVar1;
    *(int *)(this_00 + 0x10) = *piVar2;
    str::operator=((str *)(this_00 + 0x1c),(char *)param_6);
    pvVar5 = _calloc(4,__size);
    *(void **)(this_00 + 0x18) = pvVar5;
    pcVar3 = (char *)_COM_ParseExt(&param_4);
    iVar4 = _atoi(pcVar3);
    *(uint *)(this_00 + 0x20) = (uint)(iVar4 != 0);
    pcVar3 = (char *)_COM_ParseExt(&param_5,1);
    _atof(pcVar3);
    uVar6 = __ftol2_sse();
    *(undefined4 *)(this_00 + 0x2c) = uVar6;
    pcVar3 = (char *)_COM_ParseExt(&param_6,1);
    iVar4 = _atoi(pcVar3);
    *(uint *)(this_00 + 0x24) = (uint)(iVar4 != 0);
    pcVar3 = (char *)_COM_ParseExt(&param_7,1);
    iVar4 = _atoi(pcVar3);
    *(int *)(this_00 + 0x28) = iVar4;
    if (_ghostManager == 0) {
      Container<class_GhostTexture*>::Resize((Container<class_GhostTexture*> *)&ghostManager,10);
    }
    if (DAT_0000210c == DAT_00002110) {
      Container<class_GhostTexture*>::Resize
                ((Container<class_GhostTexture*> *)&ghostManager,DAT_00002110 * 2);
    }
    *(Container<class_ParticleEmitter*> **)(_ghostManager + DAT_0000210c * 4) = this_00;
    DAT_0000210c = DAT_0000210c + 1;
    iVar4 = param_10;
    if (0 < param_10) {
      do {
        this_01 = (ParticleEmitter *)operator_new(0xa8);
        if (this_01 == (ParticleEmitter *)0x0) {
          this_01 = (ParticleEmitter *)0x0;
        }
        else {
          *(undefined4 *)(this_01 + 8) = 0;
          *(undefined4 *)(this_01 + 0xc) = 0;
          *(undefined4 *)(this_01 + 0x10) = 0;
          *(undefined4 *)(this_01 + 0x6c) = 0;
          *(undefined4 *)(this_01 + 0x70) = 0;
          *(undefined4 *)(this_01 + 0x74) = 0;
          *(undefined4 *)(this_01 + 0x9c) = 0;
          *(undefined4 *)(this_01 + 0xa0) = 0;
          *(undefined4 *)(this_01 + 0xa4) = 0;
          *(float *)(this_01 + 4) = (float)_DAT_00014f28 / (float)___real_408f400000000000;
        }
        if (*(int *)this_00 == 0) {
          Container<class_ParticleEmitter*>::Resize(this_00,10);
        }
        if (*(int *)(this_00 + 4) == *(int *)(this_00 + 8)) {
          Container<class_ParticleEmitter*>::Resize(this_00,*(int *)(this_00 + 8) * 2);
        }
        *(ParticleEmitter **)(*(int *)this_00 + *(int *)(this_00 + 4) * 4) = this_01;
        *(int *)(this_00 + 4) = *(int *)(this_00 + 4) + 1;
        ParticleEmitter::Load(this_01,(char **)&param_8);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return;
}



// ===========================================
// Function: `dynamic_initializer_for_'ghostManager'' @ 00013100
// ===========================================

/* void __cdecl `dynamic initializer for 'ghostManager''(void) */

void __cdecl _dynamic_initializer_for__ghostManager__(void)

{
  _atexit(_dynamic_atexit_destructor_for__ghostManager__);
  return;
}



// ===========================================
// Function: `dynamic_atexit_destructor_for_'ghostManager'' @ 00013200
// ===========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl `dynamic atexit destructor for 'ghostManager''(void) */

void __cdecl _dynamic_atexit_destructor_for__ghostManager__(void)

{
  if (_ghostManager != (void *)0x0) {
    operator_delete(_ghostManager);
  }
  _ghostManager = (void *)0x0;
  DAT_0000210c = 0;
  DAT_00002110 = 0;
  return;
}



