
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

#define RI_PRINTF_OFF 0
#define RI_ERROR_OFF 1
#define RI_MILLIS_OFF 2
#define RI_TIKI_GETANIM_OFF 27
typedef void	(QDECL *ri_Printf)( int printLevel, const char *fmt, ...);
typedef void	(QDECL *ri_Error)( int errorLevel, const char *fmt, ...);
typedef int		(*ri_Milliseconds)( void );
typedef void* (*ri_TIKI_GetAnim)( int index );

extern intptr_t ri;
//sizeof(ri) = 0x27
static intptr_t *ri_dp = &ri;

// can't just use function pointers, or dll linkage can
// mess up when qcommon is included in multiple places
static short ( *_BigShort )( short l );
static short ( *_LittleShort )( short l );
static int ( *_BigLong )( int l );
static int ( *_LittleLong )( int l );
static float ( *_BigFloat )( float l );
static float ( *_LittleFloat )( float l );

short   BigShort( short l ) {return _BigShort( l );}
short   LittleShort( short l ) {return _LittleShort( l );}
int     BigLong( int l ) {return _BigLong( l );}
int     LittleLong( int l ) {return _LittleLong( l );}
float   BigFloat( float l ) {return _BigFloat( l );}
float   LittleFloat( float l ) {return _LittleFloat( l );}

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

float FloatSwap( float f ) {
	union
	{
		float f;
		byte b[4];
	} dat1, dat2;


	dat1.f = f;
	dat2.b[0] = dat1.b[3];
	dat2.b[1] = dat1.b[2];
	dat2.b[2] = dat1.b[1];
	dat2.b[3] = dat1.b[0];
	return dat2.f;
}

float FloatNoSwap( float f ) {
	return f;
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
	((ri_Printf)ri_dp[RI_PRINTF_OFF] )(PRINT_ALL, "%s", text);
}

void QDECL Com_DPrintf( const char *msg, ... )
{
	va_list         argptr;
	char            text[1024];

	va_start(argptr, msg);
	Q_vsnprintf(text, sizeof(text), msg, argptr);
	va_end(argptr);

	//ri.Printf(PRINT_DEVELOPER, "%s", text);
	((ri_Printf)ri_dp[RI_PRINTF_OFF])(PRINT_DEVELOPER, "%s", text);
}

void QDECL Com_Error( int level, const char *error, ... )
{
	va_list         argptr;
	char            text[1024];

	va_start(argptr, error);
	Q_vsnprintf(text, sizeof(text), error, argptr);
	va_end(argptr);

	//ri.Error(level, "%s", text);
	((ri_Error)ri_dp[RI_ERROR_OFF])(level, "%s", text);
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
	return ((ri_Milliseconds)ri_dp[RI_MILLIS_OFF])();
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


#define	MAX_STRING_CHARS	2048	// max length of a string passed to Cmd_TokenizeString
#define	MAX_STRING_TOKENS	1024	// max tokens resulting from Cmd_TokenizeString
#define	MAX_TOKEN_CHARS		1024	// max length of an individual token

static	char	com_token[MAX_TOKEN_CHARS];
static	int		com_lines;

const char *COM_GetToken( char **data_p, qboolean crossline )
{
	int		c;
	int		len;
	char *data;

	data = *data_p;
	len = 0;
	com_token[ 0 ] = 0;

	if( !data )
	{
		*data_p = NULL;
		return "";
	}

	// skip whitespace
skipwhite:
	while( ( c = *data ) <= ' ' )
	{
		if( c == '\n' && !crossline )
		{
			*data_p = data;
			return "";
		}
		if( !c )
		{
			*data_p = NULL;
			return "";
		}
		data++;
	}

	// skip // comments
	if( c == '/' && data[ 1 ] == '/' )
	{
		while( *data && *data != '\n' )
			data++;
		goto skipwhite;
	}

	// skip /* comments
	if( c == '/' && data[ 1 ] == '*' )
	{
		data++;
		while( *data )
		{
			if( ( *( data - 1 ) == '*' ) && ( *data == '/' ) )
				break;
			data++;
		}
		while( *data && *data != '\n' )
			data++;
		goto skipwhite;
	}


	// handle quoted strings specially
	if( c == '\"' )
	{
		data++;
		while( 1 )
		{
			c = *data++;
			if( c == '\\' && *data == '\"' )
			{
				if( len < MAX_STRING_CHARS )
				{
					com_token[ len ] = '\"';
					len++;
				}
				data++;
			}
			else if( c == '\"' || !c )
			{
				com_token[ len ] = 0;
				*data_p = data;
				return com_token;
			}
			else if( len < MAX_STRING_CHARS )
			{
				if( c == '\\' && *data == 'n' )
				{
					com_token[ len ] = '\n';
					data++;
				}
				else
				{
					com_token[ len ] = c;
				}
				len++;
				//            com_token[len] = c;
				//				len++;
			}
		}
	}

	// parse a regular word
	do
	{
		if( len < MAX_STRING_CHARS )
		{
			com_token[ len ] = c;
			len++;
		}
		data++;
		c = *data;
	} while( c>32 );

	if( len == MAX_STRING_CHARS )
	{
		//		Com_Printf ("Token exceeded %i chars, discarded.\n", MAX_STRING_CHARS);
		len = 0;
	}
	com_token[ len ] = 0;

	*data_p = data;
	return com_token;
}

const char *COM_Parse( char **data_p )
{
	return COM_GetToken( data_p, 1 );
}

static char *SkipWhitespace( char *data, qboolean *hasNewLines ) {
	unsigned int c;

	while( (c = *data) <= ' ') {
		if( !c ) {
			return NULL;
		}
		if( c == '\n' ) {
			com_lines++;
			*hasNewLines = qtrue;
		}
		data++;
	}

	return data;
}

char *COM_ParseExt( char **data_p, qboolean allowLineBreaks )
{
	int c = 0, len;
	qboolean hasNewLines = qfalse;
	char *data;

	data = *data_p;
	len = 0;
	com_token[ 0 ] = 0;

	// make sure incoming data is valid
	if( !data )
	{
		*data_p = NULL;
		return com_token;
	}

	while( 1 )
	{
		// skip whitespace
		data = SkipWhitespace( data, &hasNewLines );
		if( !data )
		{
			*data_p = NULL;
			return com_token;
		}
		if( hasNewLines && !allowLineBreaks )
		{
			*data_p = data;
			return com_token;
		}

		c = *data;

		// skip double slash comments
		if( c == '/' && data[ 1 ] == '/' )
		{
			while( *data && *data != '\n' )
				data++;
		}
		// skip /* */ comments
		else if( c == '/' && data[ 1 ] == '*' )
		{
			while( *data && ( *data != '*' || data[ 1 ] != '/' ) )
			{
				data++;
			}
			if( *data )
			{
				data += 2;
			}
		}
		else
		{
			break;
		}
	}

	// handle quoted strings
	if( c == '\"' )
	{
		data++;
		while( 1 )
		{
			c = *data++;
			if( c == '\"' || !c )
			{
				com_token[ len ] = 0;
				*data_p = ( char * )data;
				return com_token;
			}
			if( len < MAX_TOKEN_CHARS )
			{
				com_token[ len ] = c;
				len++;
			}
		}
	}

	// parse a regular word
	do
	{
		if( ( len > 0 ) && ( c == '{' || c == '}' ) )
		{
			break;
		}

		data++;
		if( len < MAX_TOKEN_CHARS )
		{
			// handle '\n' correctly
			if( c == '\\' && *data == 'n' )
			{
				com_token[ len ] = '\n';
				data++;
			}
			else
			{
				com_token[ len ] = c;
			}
			len++;

			if( ( len == 1 ) && ( c == '{' || c == '}' ) )
			{
				break;
			}

		}
		c = *data;
		if( c == '\n' )
			com_lines++;
	} while( c>32 );

	if( len == MAX_TOKEN_CHARS )
	{
		//		Com_Printf ("Token exceeded %i chars, discarded.\n", MAX_TOKEN_CHARS);
		len = 0;
	}
	com_token[ len ] = 0;

	*data_p = ( char * )data;
	return com_token;
}

void SkipRestOfLine ( char **data ) {
	char	*p;
	int		c;

	p = *data;
	while ( (c = *p++) != 0 ) {
		if ( c == '\n' ) {
			com_lines++;
			break;
		}
	}

	*data = p;
}

#define Com_Memset memset
#define Com_Memcpy memcpy

#define Com_Allocate malloc
#define Com_Dealloc free

#define Z_Malloc(size) Com_Allocate(size)
#define Z_Free(ptr) Com_Dealloc(ptr)

typedef struct
{
	int		numpoints;
	vec3_t	p[4];		// variable sized
} winding_t;

#if 1
winding_t* AllocWinding( int points )
{
	const void* fp = 0x412090;
	return ((winding_t* (*)(int))fp)(points);
}

void FreeWinding( winding_t* w )
{
	const void* fp = 0x4120e0;
	((void (*)(winding_t*))fp)(w);
}

void ChopWindingInPlace( winding_t** inout, vec3_t normal, vec_t dist, vec_t epsilon )
{
	const void* fp = 0x412b90;
	((void (*)(winding_t**, vec3_t, vec_t, vec_t))fp)(inout, normal, dist, epsilon);
}
#else

#define	MAX_POINTS_ON_WINDING	64

#define	SIDE_FRONT	0
#define	SIDE_BACK	1
#define	SIDE_ON		2
#define	SIDE_CROSS	3

#define	CLIP_EPSILON	0.1f

// you can define on_epsilon in the makefile as tighter
#ifndef	ON_EPSILON
#define	ON_EPSILON	0.1f
#endif

// counters are only bumped when running single threaded,
// because they are an awful coherence problem
int	c_active_windings;
int	c_peak_windings;
int	c_winding_allocs;
int	c_winding_points;

winding_t	*AllocWinding (int points)
{
	winding_t	*w;
	int			s;

	c_winding_allocs++;
	c_winding_points += points;
	c_active_windings++;
	if (c_active_windings > c_peak_windings)
		c_peak_windings = c_active_windings;

	s = sizeof(vec_t)*3*points + sizeof(int);
	w = Z_Malloc (s);
	if( w )
		Com_Memset (w, 0, s); 
	return w;
}

void FreeWinding (winding_t *w)
{
	if (*(unsigned *)w == 0xdeaddead)
		Com_Error (ERR_FATAL, "FreeWinding: freed a freed winding");
	*(unsigned *)w = 0xdeaddead;

	c_active_windings--;
	Z_Free (w);
}


void ChopWindingInPlace (winding_t **inout, vec3_t normal, vec_t dist, vec_t epsilon)
{
	winding_t	*in;
	vec_t	dists[MAX_POINTS_ON_WINDING+4];
	int		sides[MAX_POINTS_ON_WINDING+4];
	int		counts[3];
	static	vec_t	dot;		// VC 4.2 optimizer bug if not static
	int		i, j;
	vec_t	*p1, *p2;
	vec3_t	mid;
	winding_t	*f;
	int		maxpts;

	in = *inout;
	counts[0] = counts[1] = counts[2] = 0;

	// determine sides for each point
	for (i=0 ; i<in->numpoints ; i++)
	{
		dot = DotProduct (in->p[i], normal);
		dot -= dist;
		dists[i] = dot;
		if ((dot + 0.0005) > epsilon)
			sides[i] = SIDE_FRONT;
		else if ((dot - 0.0005) < -epsilon)
			sides[i] = SIDE_BACK;
		else
		{
			sides[i] = SIDE_ON;
		}
		counts[sides[i]]++;
	}
	sides[i] = sides[0];
	dists[i] = dists[0];

	if (!counts[0])
	{
		FreeWinding (in);
		*inout = NULL;
		return;
	}
	if (!counts[1])
		return;		// inout stays the same

	maxpts = in->numpoints+4;	// cant use counts[0]+2 because
								// of fp grouping errors

	f = AllocWinding (maxpts);

	for (i=0 ; i<in->numpoints ; i++)
	{
		p1 = in->p[i];

		if (sides[i] == SIDE_ON)
		{
			VectorCopy (p1, f->p[f->numpoints]);
			f->numpoints++;
			continue;
		}

		if (sides[i] == SIDE_FRONT)
		{
			VectorCopy (p1, f->p[f->numpoints]);
			f->numpoints++;
		}

		if (sides[i+1] == SIDE_ON || sides[i+1] == sides[i])
			continue;

		// generate a split point
		p2 = in->p[(i+1)%in->numpoints];

		dot = dists[i] / (dists[i]-dists[i+1]);
		for (j=0 ; j<3 ; j++)
		{	// avoid round off error when possible
			if (normal[j] == 1)
				mid[j] = dist;
			else if (normal[j] == -1)
				mid[j] = -dist;
			else
				mid[j] = p1[j] + dot*(p2[j]-p1[j]);
		}

		VectorCopy (mid, f->p[f->numpoints]);
		f->numpoints++;
	}

	if (f->numpoints > maxpts)
		Com_Error (ERR_DROP, "ClipWinding: points exceeded estimate");
	if (f->numpoints > MAX_POINTS_ON_WINDING)
		Com_Error (ERR_DROP, "ClipWinding: MAX_POINTS_ON_WINDING");

	FreeWinding (in);
	*inout = f;
}
#endif

void *TIKI_GetSkel(int index)
{
  const void *fp = 0x431ea0;
	return ((void* (*)(int))fp)(index);
}

void *TIKI_GetAnim(int index)
{
	//return skelcache[index].skel;
	//return ri.TIKI_GetAnim( index );
	return ((ri_TIKI_GetAnim)ri_dp[RI_TIKI_GETANIM_OFF])(index);
}

void IN_ChangeResolution()
{
  const void *fp = 0x464000;
  ((void (*)())fp)();
}

void CL_UpdateLoadingScreen( void )
{
  const void *fp = 0x40aed0;
  ((void (*)())fp)();
}

void UI_SetLoadingStage( int num )
{
  const void *fp = 0x4488e0;
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