
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <math.h>
#include <intrin.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#include "qtypes.h"
#include "alice_renderer_api.h"

extern refimport_t ri;
extern void QDECL RendererLogPrintf(const char* fmt, ...);

// can't just use function pointers, or dll linkage can
// mess up when qcommon is included in multiple places
static short ( *_BigShort )( short l );
static short ( *_LittleShort )( short l );
static int ( *_BigLong )( int l );
static int ( *_LittleLong )( int l );
/*
 * Alice's renderer.lib uses the older id Tech float-endian ABI: the
 * float is passed by address.  This is significant on x86 because the
 * C linker decorates both the old and a by-value prototype as _LittleFloat,
 * so a mismatched shim links successfully but turns each input pointer into
 * a tiny floating point position.
 */
static float ( *_BigFloat )( const float *l );
static float ( *_LittleFloat )( const float *l );

short   BigShort( short l ) {return _BigShort( l );}
short   LittleShort( short l ) {return _LittleShort( l );}
int     BigLong( int l ) {return _BigLong( l );}
int     LittleLong( int l ) {return _LittleLong( l );}
float   BigFloat( const float *l ) {return _BigFloat( l );}
float   LittleFloat(const float *l) {return _LittleFloat( l );}

short   ShortSwap( short l ) {
    byte b1,b2;

    b1 = l & 255;
    b2 = ( l >> 8 ) & 255;

    return ( b1 << 8 ) + b2;
}

short   ShortNoSwap( short l ) {
    return l;
}

int    LongSwap( int l ) {
    byte b1,b2,b3,b4;

    b1 = l & 255;
    b2 = ( l >> 8 ) & 255;
    b3 = ( l >> 16 ) & 255;
    b4 = ( l >> 24 ) & 255;

    return ( (int)b1 << 24 ) + ( (int)b2 << 16 ) + ( (int)b3 << 8 ) + b4;
}

int LongNoSwap( int l ) {
    return l;
}

float FloatSwap( const float *f ) {
    union
    {
        float f;
        byte b[4];
    } dat1, dat2;


    dat1.f = *f;
    dat2.b[0] = dat1.b[3];
    dat2.b[1] = dat1.b[2];
    dat2.b[2] = dat1.b[1];
    dat2.b[3] = dat1.b[0];
    return dat2.f;
}

float FloatNoSwap( const float *f ) {
    return *f;
}

uint32_t bigendian = 0;

/*
================
Swap_Init
================
*/
void Swap_Init( void ) {
    byte swaptest[2] = {1,0};

    // set the byte swapping variables in a portable manner
    if ( *(short *)swaptest == 1 ) {
        _BigShort = ShortSwap;
        _LittleShort = ShortNoSwap;
        _BigLong = LongSwap;
        _LittleLong = LongNoSwap;
        _BigFloat = FloatSwap;
        _LittleFloat = FloatNoSwap;
    } else
    {
        bigendian = 1;

        _BigShort = ShortNoSwap;
        _LittleShort = ShortSwap;
        _BigLong = LongNoSwap;
        _LittleLong = LongSwap;
        _BigFloat = FloatNoSwap;
        _LittleFloat = FloatSwap;
    }

}

extern size_t Q_vsnprintf( char* str, size_t size, const char* format, va_list ap );

void QDECL Com_Printf( const char *msg, ... )
{
    va_list         argptr;
    char            text[1024];

    va_start(argptr, msg);
    Q_vsnprintf(text, sizeof(text), msg, argptr);
    va_end(argptr);

    //ri.Printf(PRINT_ALL, "%s", text);
    ri.Printf(PRINT_ALL, "%s", text);
}

void QDECL Com_DPrintf( const char *msg, ... )
{
    va_list         argptr;
    char            text[1024];

    va_start(argptr, msg);
    Q_vsnprintf(text, sizeof(text), msg, argptr);
    va_end(argptr);

    //ri.Printf(PRINT_DEVELOPER, "%s", text);
    ri.Printf(PRINT_DEVELOPER, "%s", text);
}

void QDECL Com_Error( int level, const char *error, ... )
{
    va_list         argptr;
    char            text[1024];

    va_start(argptr, error);
    Q_vsnprintf(text, sizeof(text), error, argptr);
    va_end(argptr);

    //ri.Error(level, "%s", text);
    ri.Error(level, "%s", text);
}

//int sys_timeBase;
//int Sys_Milliseconds (void)
//{
//	int             sys_curtime;
//	static qboolean initialized = qfalse;
//
//	if (!initialized) {
//		sys_timeBase = timeGetTime();
//		initialized = qtrue;
//	}
//	sys_curtime = timeGetTime() - sys_timeBase;
//
//	return sys_curtime;
//	//return ri.Milliseconds();
//}

int Sys_Milliseconds (void)
{
    return ri.Milliseconds();
}

#define	MAX_QPATH			256		// max length of a quake game pathname

void COM_DefaultExtension (char *path, int maxSize, const char *extension ) {
	char	oldPath[MAX_QPATH];
    char    *src;

    //
    // if path doesn't have a .EXT, append extension
    // (extension should include the .)
    //
    src = path + strlen(path) - 1;

    while (*src != '/' && src != path) {
        if ( *src == '.' ) {
            return;                 // it has an extension
        }
        src--;
    }

    Q_strncpyz( oldPath, path, sizeof( oldPath ) );
    Com_sprintf( path, maxSize, "%s%s", oldPath, extension );
}

const char* COM_Parse(char** data_p)
{
    const void* fp = (void*)0x00425070;//COM_GetToken
    return ((const char* (*)(char**, qboolean))fp)(data_p, 1);
}

char* COM_ParseExt(char** data_p, qboolean allowLineBreaks)
{
    const void* fp = (void*)0x00425390;
    return ((char* (*)(char**, qboolean))fp)(data_p, allowLineBreaks);
}

qboolean SkipBracedSection(char** program)
{
    const void* fp = (void*)0x00426410;
    return ((qboolean(*)(char**))fp)(program);
}

void SkipRestOfLine(char** data)
{
    const void* fp = (void*)0x004252f0;
    ((void (*)(char**))fp)(data);
}

typedef struct
{
	int		numpoints;
	vec3_t	p[4];		// variable sized
} winding_t;

winding_t* AllocWinding( int points )
{
    const void* fp = (void*)0x412090;
    return ((winding_t* (*)(int))fp)(points);
}

void FreeWinding( winding_t* w )
{
    const void* fp = (void*)0x4120e0;
    ((void (*)(winding_t*))fp)(w);
}

void ChopWindingInPlace( winding_t** inout, vec3_t normal, vec_t dist, vec_t epsilon )
{
    const void* fp = (void*)0x412b90;
    ((void (*)(winding_t**, vec3_t, vec_t, vec_t))fp)(inout, normal, dist, epsilon);
}

void *TIKI_GetSkel(int index)
{
    const void *fp = (void*)0x431ea0;
    void *result = ((void* (*)(int))fp)(index);

    return result;
}

void *TIKI_GetAnim(int index)
{
    void *result = ri.TIKI_GetAnim(index);
    return result;
}

void IN_ChangeResolution()
{
  const void *fp = (void*)0x464000;
  ((void (*)())fp)();
}

void CL_UpdateLoadingScreen( void )
{
  const void *fp = (void*)0x40aed0;
  ((void (*)())fp)();
}

void UI_SetLoadingStage( int num )
{
  const void *fp = (void*)0x4488e0;
  ((void (*)(int))fp)(num);
}

typedef struct {
    int firstPoint;
    int numPoints;
} markFragment_t;

int R_MarkFragments( int orientation, const vec3_t* points, const vec3_t projection,
    int maxPoints, vec3_t pointBuffer, int maxFragments, markFragment_t* fragmentBuffer );

int CM_MarkFragments( int orientation, const vec3_t* points, const vec3_t projection,
    int maxPoints, vec3_t pointBuffer, int maxFragments, markFragment_t* fragmentBuffer )
{
    return R_MarkFragments(orientation, points, projection, maxPoints, pointBuffer, maxFragments, fragmentBuffer);
}

//int g_eLanguage = 0; //english //0x7cf868 //FUN_004d60e0 gets called right after this is set
//vec4_t g_color_table = { 1.0f, 1.0f, 1.0f, 1.0f };
//int g_wv[2] = { 0, 0 };
