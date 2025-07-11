
#ifndef _QTYPES_H
#define _QTYPES_H
#endif

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#undef QDECL
#define QDECL __cdecl

#undef QCALL
#define QCALL __stdcall

#define ID_INLINE __inline
#define PATH_SEP '\\'

#define Q3_LITTLE_ENDIAN

#ifndef M_PI
#define M_PI		3.14159265358979323846	// matches value in gcc v2 math.h
#endif

	// angle indexes
#define	PITCH				0		// up / down
#define	YAW					1		// left / right
#define	ROLL				2		// fall over

typedef unsigned char 		byte;
typedef unsigned char		uchar;

enum { qfalse, qtrue };

typedef union {
	float f;
	int i;
	unsigned int ui;
} floatint_t;

typedef int	qboolean;

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t quat_t[4]; // | x y z w |
typedef vec_t vec5_t[5];
typedef vec_t matrix3x3_t[9];
typedef vec_t matrix_t[16];
typedef vec3_t axis_t[3];

typedef	int	fixed4_t;
typedef	int	fixed8_t;
typedef	int	fixed16_t;

// plane_t structure
// !!! if this is changed, it must be changed in asm code too !!!
typedef struct cplane_s {
	vec3_t	normal;
	float	dist;
	byte	type;			// for fast side tests: 0,1,2 = axial, 3 = nonaxial
	byte	signbits;		// signx + (signy<<1) + (signz<<2), used as lookup during collision
	byte	pad[2];
} cplane_t;

#define DEG2RAD( a ) ( ( (a) * M_PI ) / 180.0F )
#define RAD2DEG( a ) ( ( (a) * 180.0f ) / M_PI )


// print levels from renderer (FIXME: set up for game / cgame?)
typedef enum {
	PRINT_ALL,
	PRINT_DEVELOPER,		// only print when "developer 1"
	PRINT_DEVELOPER_2,		// print when "developer 2"
	PRINT_WARNING,
	PRINT_ERROR
} printParm_t;


#ifdef ERR_FATAL
#undef ERR_FATAL			// this is be defined in malloc.h
#endif

// parameters to the main Error routine
typedef enum {
	ERR_FATAL,					// exit the entire game with a popup window
	ERR_DROP,					// print to console and disconnect from game
	ERR_SERVERDISCONNECT,		// don't kill server
	ERR_DISCONNECT,				// client disconnected from the server
	ERR_NEED_CD					// pop up the need-cd dialog
} errorParm_t;

extern void QDECL Com_Printf( const char* msg, ... );
extern void QDECL Com_DPrintf( const char* msg, ... );
extern void QDECL Com_Error( int level, const char* error, ... );

extern char* COM_ParseExt( char** data_p, qboolean allowLineBreaks );


#define VectorClear(a)			((a)[0]=(a)[1]=(a)[2]=0)

#define DotProduct(x,y)			((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define DotProduct2D(x,y)		((x)[0]*(y)[0]+(x)[1]*(y)[1])
#define CrossProduct2D(a,b)		((a)[0]*(b)[1]-(b)[0]*(a)[1])
#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorAdd2D(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1])
#define VectorSub2D(a,b,c)		((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1])
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define VectorCopy2D(a,b)		((b)[0]=(a)[0],(b)[1]=(a)[1])
#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	VectorScale2D(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s))
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define	VectorMA2D(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s))

size_t Q_vsnprintf( char* str, size_t size, const char* format, va_list ap );
void Q_strncpyz( char* dest, const char* src, size_t destsize );
size_t QDECL Com_sprintf( char* dest, size_t size, const char* fmt, ... );

#ifdef __cplusplus
}
#endif