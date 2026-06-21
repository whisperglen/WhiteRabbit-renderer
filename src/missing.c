
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <math.h>
#include <intrin.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include "qtypes.h"

size_t Q_vsnprintf(char* str, size_t size, const char* format, va_list ap)
{
	int retval;

	retval = _vsnprintf(str, size, format, ap);

	if (retval < 0 || retval == size)
	{
		// Microsoft doesn't adhere to the C99 standard of vsnprintf,
		// which states that the return value must be the number of
		// bytes written if the output string had sufficient length.
		//
		// Obviously we cannot determine that value from Microsoft's
		// implementation, so we have no choice but to return size.

		str[size - 1] = '\0';
		return size;
	}

	return retval;
}

int Q_stricmpn( const char *s1, const char *s2, size_t n ) {
	int		c1, c2;

	if ( s1 == NULL ) {
		if ( s2 == NULL )
			return 0;
		else
			return -1;
	}
	else if ( s2==NULL )
		return 1;



	do {
		c1 = *s1++;
		c2 = *s2++;

		if (!n--) {
			return 0;		// strings are equal until end point
		}

		if (c1 != c2) {
			if (c1 >= 'a' && c1 <= 'z') {
				c1 -= ('a' - 'A');
			}
			if (c2 >= 'a' && c2 <= 'z') {
				c2 -= ('a' - 'A');
			}
			if (c1 != c2) {
				return c1 < c2 ? -1 : 1;
			}
		}
	} while (c1);

	return 0;		// strings are equal
}

int Q_stricmp (const char *s1, const char *s2) {
	return (s1 && s2) ? Q_stricmpn (s1, s2, 99999) : -1;
}

/*
=============
Q_strncpyz

Safe strncpy that ensures a trailing zero
=============
*/
void Q_strncpyz( char *dest, const char *src, size_t destsize ) {
	if ( !dest ) {
		Com_Error( ERR_FATAL, "Q_strncpyz: NULL dest" );
	}

	if ( !src ) {
		Com_Error( ERR_FATAL, "Q_strncpyz: NULL src" );
	}

	if ( destsize < 1 ) {
		Com_Error( ERR_FATAL, "Q_strncpyz: destsize < 1" );
	}

	if ( dest == src ) {
		return;
	}

	strncpy( dest, src, destsize - 1 );
	dest[ destsize - 1 ] = 0;
}

char *Q_strlwr( char *s1 ) {
	char	*s;

	s = s1;
	while ( *s ) {
		*s = tolower(*s);
		s++;
	}
	return s1;
}

const char *va( const char *format, ... )
{
	va_list		argptr;
	static char		string[ 2 ][ 16384 ];	// in case va is called by nested functions
	static int		index = 0;
	char	*buf;

	buf = string[ index & 1 ];
	index++;

	va_start( argptr, format );
	Q_vsnprintf( buf, sizeof(*string), format, argptr );
	va_end( argptr );

	return buf;
}

const char *COM_SkipPath (const char *pathname)
{
	const char	*last;

	last = pathname;
	while (*pathname)
	{
		if (*pathname=='/' || *pathname=='\\')
			last = pathname+1;
		pathname++;
	}
	return last;
}

size_t QDECL Com_sprintf( char *dest, size_t size, const char *fmt, ...) {
	size_t		len;
	va_list		argptr;

	va_start(argptr, fmt);
	len = Q_vsnprintf(dest, size, fmt, argptr);
	va_end(argptr);

	if (len >= size)
		Com_Printf("Com_sprintf: Output length %zd too short, require %zd bytes.\n", size, len + 1);

	return len;
}

void COM_StripExtension(const char* in, char* out) {
	while (*in && *in != '.') {
		*out++ = *in++;
	}
	*out = 0;
}

ID_INLINE float Q_rsqrt(float number)
{
	__m128 number_f;
	float ret;

	if (number == 0.f)
		return 1.f / FLT_MIN;

	number_f = _mm_set_ss(number);

	number_f = _mm_rsqrt_ss(number_f);

	_mm_store_ss(&ret, number_f);
	return ret;
}

vec_t VectorLength( const vec3_t v ) {
	return (vec_t)sqrt (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

void VectorRotate( vec3_t in, vec3_t matrix[3], vec3_t out )
{
	out[0] = DotProduct( in, matrix[0] );
	out[1] = DotProduct( in, matrix[1] );
	out[2] = DotProduct( in, matrix[2] );
}

vec_t VectorNormalize( vec3_t v ) {
	// NOTE: TTimo - Apple G4 altivec source uses double?
	float	length, ilength;

	length = v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
	if (length > FLT_EPSILON) {
		length = sqrtf(length);

		ilength = 1 / length;
		v[0] *= ilength;
		v[1] *= ilength;
		v[2] *= ilength;
	}

	return length;
}

// fast vector normalize routine that does not check to make sure
// that length != 0, nor does it return length, uses rsqrt approximation
void VectorNormalizeFast( vec3_t v )
{
	float ilength;

	ilength = Q_rsqrt( DotProduct( v, v ) );

	v[0] *= ilength;
	v[1] *= ilength;
	v[2] *= ilength;
}

vec_t VectorNormalize2( const vec3_t v, vec3_t out ) {
	float	length, ilength;

	length = v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
	length = sqrtf (length);

	if (length)
	{
		ilength = 1/length;
		out[0] = v[0]*ilength;
		out[1] = v[1]*ilength;
		out[2] = v[2]*ilength;
	} else {
		VectorClear( out );
	}

	return length;
}

void VectorInverse( vec3_t v ){
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}

void CrossProduct( const vec3_t v1, const vec3_t v2, vec3_t cross ) {
	cross[0] = v1[1]*v2[2] - v1[2]*v2[1];
	cross[1] = v1[2]*v2[0] - v1[0]*v2[2];
	cross[2] = v1[0]*v2[1] - v1[1]*v2[0];
}

void MatrixMultiply( const float in1[ 3 ][ 3 ], const float in2[ 3 ][ 3 ], float out[ 3 ][ 3 ] ) {
	out[ 0 ][ 0 ] = in1[ 0 ][ 0 ] * in2[ 0 ][ 0 ] + in1[ 0 ][ 1 ] * in2[ 1 ][ 0 ] +
		in1[ 0 ][ 2 ] * in2[ 2 ][ 0 ];
	out[ 0 ][ 1 ] = in1[ 0 ][ 0 ] * in2[ 0 ][ 1 ] + in1[ 0 ][ 1 ] * in2[ 1 ][ 1 ] +
		in1[ 0 ][ 2 ] * in2[ 2 ][ 1 ];
	out[ 0 ][ 2 ] = in1[ 0 ][ 0 ] * in2[ 0 ][ 2 ] + in1[ 0 ][ 1 ] * in2[ 1 ][ 2 ] +
		in1[ 0 ][ 2 ] * in2[ 2 ][ 2 ];
	out[ 1 ][ 0 ] = in1[ 1 ][ 0 ] * in2[ 0 ][ 0 ] + in1[ 1 ][ 1 ] * in2[ 1 ][ 0 ] +
		in1[ 1 ][ 2 ] * in2[ 2 ][ 0 ];
	out[ 1 ][ 1 ] = in1[ 1 ][ 0 ] * in2[ 0 ][ 1 ] + in1[ 1 ][ 1 ] * in2[ 1 ][ 1 ] +
		in1[ 1 ][ 2 ] * in2[ 2 ][ 1 ];
	out[ 1 ][ 2 ] = in1[ 1 ][ 0 ] * in2[ 0 ][ 2 ] + in1[ 1 ][ 1 ] * in2[ 1 ][ 2 ] +
		in1[ 1 ][ 2 ] * in2[ 2 ][ 2 ];
	out[ 2 ][ 0 ] = in1[ 2 ][ 0 ] * in2[ 0 ][ 0 ] + in1[ 2 ][ 1 ] * in2[ 1 ][ 0 ] +
		in1[ 2 ][ 2 ] * in2[ 2 ][ 0 ];
	out[ 2 ][ 1 ] = in1[ 2 ][ 0 ] * in2[ 0 ][ 1 ] + in1[ 2 ][ 1 ] * in2[ 1 ][ 1 ] +
		in1[ 2 ][ 2 ] * in2[ 2 ][ 1 ];
	out[ 2 ][ 2 ] = in1[ 2 ][ 0 ] * in2[ 0 ][ 2 ] + in1[ 2 ][ 1 ] * in2[ 1 ][ 2 ] +
		in1[ 2 ][ 2 ] * in2[ 2 ][ 2 ];
}

void Matrix3x3Multiply( const float in1[ 3 ][ 3 ], const float in2[ 3 ][ 3 ], float out[ 3 ][ 3 ] ) {
	out[ 0 ][ 0 ] = in1[ 0 ][ 0 ] * in2[ 0 ][ 0 ] + in1[ 0 ][ 1 ] * in2[ 1 ][ 0 ] +
		in1[ 0 ][ 2 ] * in2[ 2 ][ 0 ];
	out[ 0 ][ 1 ] = in1[ 0 ][ 0 ] * in2[ 0 ][ 1 ] + in1[ 0 ][ 1 ] * in2[ 1 ][ 1 ] +
		in1[ 0 ][ 2 ] * in2[ 2 ][ 1 ];
	out[ 0 ][ 2 ] = in1[ 0 ][ 0 ] * in2[ 0 ][ 2 ] + in1[ 0 ][ 1 ] * in2[ 1 ][ 2 ] +
		in1[ 0 ][ 2 ] * in2[ 2 ][ 2 ];
	out[ 1 ][ 0 ] = in1[ 1 ][ 0 ] * in2[ 0 ][ 0 ] + in1[ 1 ][ 1 ] * in2[ 1 ][ 0 ] +
		in1[ 1 ][ 2 ] * in2[ 2 ][ 0 ];
	out[ 1 ][ 1 ] = in1[ 1 ][ 0 ] * in2[ 0 ][ 1 ] + in1[ 1 ][ 1 ] * in2[ 1 ][ 1 ] +
		in1[ 1 ][ 2 ] * in2[ 2 ][ 1 ];
	out[ 1 ][ 2 ] = in1[ 1 ][ 0 ] * in2[ 0 ][ 2 ] + in1[ 1 ][ 1 ] * in2[ 1 ][ 2 ] +
		in1[ 1 ][ 2 ] * in2[ 2 ][ 2 ];
	out[ 2 ][ 0 ] = in1[ 2 ][ 0 ] * in2[ 0 ][ 0 ] + in1[ 2 ][ 1 ] * in2[ 1 ][ 0 ] +
		in1[ 2 ][ 2 ] * in2[ 2 ][ 0 ];
	out[ 2 ][ 1 ] = in1[ 2 ][ 0 ] * in2[ 0 ][ 1 ] + in1[ 2 ][ 1 ] * in2[ 1 ][ 1 ] +
		in1[ 2 ][ 2 ] * in2[ 2 ][ 1 ];
	out[ 2 ][ 2 ] = in1[ 2 ][ 0 ] * in2[ 0 ][ 2 ] + in1[ 2 ][ 1 ] * in2[ 1 ][ 2 ] +
		in1[ 2 ][ 2 ] * in2[ 2 ][ 2 ];
}

void TransposeMatrix( float in[ 3 ][ 3 ], float out[ 3 ][ 3 ] )
{
	out[ 0 ][ 0 ] = in[ 0 ][ 0 ];
	out[ 0 ][ 1 ] = in[ 1 ][ 0 ];
	out[ 0 ][ 2 ] = in[ 2 ][ 0 ];
	out[ 1 ][ 0 ] = in[ 0 ][ 1 ];
	out[ 1 ][ 1 ] = in[ 1 ][ 1 ];
	out[ 1 ][ 2 ] = in[ 2 ][ 1 ];
	out[ 2 ][ 0 ] = in[ 0 ][ 2 ];
	out[ 2 ][ 1 ] = in[ 1 ][ 2 ];
	out[ 2 ][ 2 ] = in[ 2 ][ 2 ];
}

void MatrixTransformVector
(
	const vec3_t in,
	const float mat[ 3 ][ 3 ],
	vec3_t out
)
{
	out[ 0 ] = ( in[ 0 ] * mat[ 0 ][ 0 ] ) + ( in[ 1 ] * mat[ 1 ][ 0 ] ) + ( in[ 2 ] * mat[ 2 ][ 0 ] );
	out[ 1 ] = ( in[ 0 ] * mat[ 0 ][ 1 ] ) + ( in[ 1 ] * mat[ 1 ][ 1 ] ) + ( in[ 2 ] * mat[ 2 ][ 1 ] );
	out[ 2 ] = ( in[ 0 ] * mat[ 0 ][ 2 ] ) + ( in[ 1 ] * mat[ 1 ][ 2 ] ) + ( in[ 2 ] * mat[ 2 ][ 2 ] );
}

void MakeNormalVectors( const vec3_t forward, vec3_t right, vec3_t up) {
	float		d;

	// this rotate and negate guarantees a vector
	// not colinear with the original
	right[1] = -forward[0];
	right[2] = forward[1];
	right[0] = forward[2];

	d = DotProduct (right, forward);
	VectorMA (right, -d, forward, right);
	VectorNormalize (right);
	CrossProduct (right, forward, up);
}

void AngleVectors( const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up ) {
	float		angle;
	static float		sr, sp, sy, cr, cp, cy;
	// static to help MS compiler fp bugs

	angle = angles[ YAW ] * ( M_PI * 2 / 360 );
	sy = sin( angle );
	cy = cos( angle );
	angle = angles[ PITCH ] * ( M_PI * 2 / 360 );
	sp = sin( angle );
	cp = cos( angle );

	if( forward )
	{
		forward[ 0 ] = cp*cy;
		forward[ 1 ] = cp*sy;
		forward[ 2 ] = -sp;
	}
	if ( right || up )
	{
		angle = angles[ ROLL ] * ( M_PI * 2 / 360 );
		sr = sin( angle );
		cr = cos( angle );

		if ( right )
		{
			right[ 0 ] = ( -1 * sr * sp * cy + -1 * cr * -sy );
			right[ 1 ] = ( -1 * sr * sp * sy + -1 * cr * cy );
			right[ 2 ] = -1 * sr * cp;
		}
		if ( up )
		{
			up[ 0 ] = ( cr * sp * cy + -sr * -sy );
			up[ 1 ] = ( cr * sp * sy + -sr * cy );
			up[ 2 ] = cr * cp;
		}
	}
}

void AnglesToAxis( const vec3_t angles, vec3_t axis[3] ) {
	float		angle;
	static float		sr, sp, sy, cr, cp, cy;
	// static to help MS compiler fp bugs

	angle = angles[ YAW ] * ( M_PI * 2 / 360 );
	sy = sin( angle );
	cy = cos( angle );
	angle = angles[ PITCH ] * ( M_PI * 2 / 360 );
	sp = sin( angle );
	cp = cos( angle );
	angle = angles[ ROLL ] * ( M_PI * 2 / 360 );
	sr = sin( angle );
	cr = cos( angle );

	axis[ 0 ][ 0 ] = cp*cy;
	axis[ 0 ][ 1 ] = cp*sy;
	axis[ 0 ][ 2 ] = -sp;

	axis[ 1 ][ 0 ] = ( sr*sp*cy + cr*-sy );
	axis[ 1 ][ 1 ] = ( sr*sp*sy + cr*cy );
	axis[ 1 ][ 2 ] = sr*cp;

	axis[ 2 ][ 0 ] = ( cr*sp*cy + -sr*-sy );
	axis[ 2 ][ 1 ] = ( cr*sp*sy + -sr*cy );
	axis[ 2 ][ 2 ] = cr*cp;
}

void AxisClear( vec3_t axis[3] ) {
	axis[0][0] = 1;
	axis[0][1] = 0;
	axis[0][2] = 0;
	axis[1][0] = 0;
	axis[1][1] = 1;
	axis[1][2] = 0;
	axis[2][0] = 0;
	axis[2][1] = 0;
	axis[2][2] = 1;
}

void AxisCopy( const vec3_t in[3], vec3_t out[3] ) {
	VectorCopy( in[0], out[0] );
	VectorCopy( in[1], out[1] );
	VectorCopy( in[2], out[2] );
}

void vectoangles( const vec3_t value1, vec3_t angles ) {
	float	forward;
	float	yaw, pitch;

	if ( value1[1] == 0 && value1[0] == 0 ) {
		yaw = 0;
		if ( value1[2] > 0 ) {
			pitch = 90;
		}
		else {
			pitch = 270;
		}
	}
	else {
		//if ( value1[0] ) {
		yaw = ( atan2 ( value1[1], value1[0] ) * 180 / M_PI );
		//}
		//else if ( value1[1] > 0 ) {
		//	yaw = 90;
		//}
		//else {
		//	yaw = 270;
		//}
		if ( yaw < 0 ) {
			yaw += 360;
		}

		forward = sqrt ( value1[0]*value1[0] + value1[1]*value1[1] );
		pitch = ( atan2(value1[2], forward) * 180 / M_PI );
		if ( pitch < 0 ) {
			pitch += 360;
		}
	}

	angles[PITCH] = -pitch;
	angles[YAW] = yaw;
	angles[ROLL] = 0;
}

void ProjectPointOnPlane( vec3_t dst, const vec3_t p, const vec3_t normal )
{
	float d;
	vec3_t n;
	float inv_denom;

	inv_denom = 1.0f / DotProduct( normal, normal );

	d = DotProduct( normal, p ) * inv_denom;

	n[0] = normal[0] * inv_denom;
	n[1] = normal[1] * inv_denom;
	n[2] = normal[2] * inv_denom;

	dst[0] = p[0] - d * n[0];
	dst[1] = p[1] - d * n[1];
	dst[2] = p[2] - d * n[2];
}

/*
** assumes "src" is normalized
*/
void PerpendicularVector( vec3_t dst, const vec3_t src )
{
	int	pos;
	int i;
	float minelem = 1.0F;
	vec3_t tempvec;

	/*
	** find the smallest magnitude axially aligned vector
	*/
	for ( pos = 0, i = 0; i < 3; i++ )
	{
		if ( fabsf( src[i] ) < minelem )
		{
			pos = i;
			minelem = fabsf( src[i] );
		}
	}
	tempvec[0] = tempvec[1] = tempvec[2] = 0.0F;
	tempvec[pos] = 1.0F;

	/*
	** project the point onto the plane defined by src
	*/
	ProjectPointOnPlane( dst, tempvec, src );

	/*
	** normalize the result
	*/
	VectorNormalize( dst );
}

/*
===============
RotatePointAroundVector

This is not implemented very well...
===============
*/
void RotatePointAroundVector( vec3_t dst, const vec3_t dir, const vec3_t point,
	float degrees ) {
	float	m[3][3];
	float	im[3][3];
	float	zrot[3][3];
	float	tmpmat[3][3];
	float	rot[3][3];
	int	i;
	vec3_t vr, vup, vf;
	float	rad;

	vf[0] = dir[0];
	vf[1] = dir[1];
	vf[2] = dir[2];

	PerpendicularVector( vr, dir );
	CrossProduct( vr, vf, vup );

	m[0][0] = vr[0];
	m[1][0] = vr[1];
	m[2][0] = vr[2];

	m[0][1] = vup[0];
	m[1][1] = vup[1];
	m[2][1] = vup[2];

	m[0][2] = vf[0];
	m[1][2] = vf[1];
	m[2][2] = vf[2];

	memcpy( im, m, sizeof( im ) );

	im[0][1] = m[1][0];
	im[0][2] = m[2][0];
	im[1][0] = m[0][1];
	im[1][2] = m[2][1];
	im[2][0] = m[0][2];
	im[2][1] = m[1][2];

	memset( zrot, 0, sizeof( zrot ) );
	zrot[0][0] = zrot[1][1] = zrot[2][2] = 1.0F;

	rad = DEG2RAD( degrees );
	zrot[0][0] = cos( rad );
	zrot[0][1] = sin( rad );
	zrot[1][0] = -sin( rad );
	zrot[1][1] = cos( rad );

	Matrix3x3Multiply( m, zrot, tmpmat );
	Matrix3x3Multiply( tmpmat, im, rot );

	for ( i = 0; i < 3; i++ ) {
		dst[i] = rot[i][0] * point[0] + rot[i][1] * point[1] + rot[i][2] * point[2];
	}
}

void AddPointToBounds( const vec3_t v, vec3_t mins, vec3_t maxs ) {
	if( v[ 0 ] < mins[ 0 ] ) {
		mins[ 0 ] = v[ 0 ];
	}
	if( v[ 0 ] > maxs[ 0 ] ) {
		maxs[ 0 ] = v[ 0 ];
	}

	if( v[ 1 ] < mins[ 1 ] ) {
		mins[ 1 ] = v[ 1 ];
	}
	if( v[ 1 ] > maxs[ 1 ] ) {
		maxs[ 1 ] = v[ 1 ];
	}

	if( v[ 2 ] < mins[ 2 ] ) {
		mins[ 2 ] = v[ 2 ];
	}
	if( v[ 2 ] > maxs[ 2 ] ) {
		maxs[ 2 ] = v[ 2 ];
	}
}

// plane types are used to speed some tests
// 0-2 are axial planes
#define	PLANE_X			0
#define	PLANE_Y			1
#define	PLANE_Z			2
#define	PLANE_NON_AXIAL	3
#define PLANE_NON_PLANAR 4


/*
=================
PlaneTypeForNormal
=================
*/

//#define PlaneTypeForNormal(x) (x[0] == 1.0 ? PLANE_X : (x[1] == 1.0 ? PLANE_Y : (x[2] == 1.0 ? PLANE_Z : PLANE_NON_AXIAL) ) )
int PlaneTypeForNormal(vec3_t normal)
{
	if(normal[0] == 1.0)
		return PLANE_X;

	if(normal[1] == 1.0)
		return PLANE_Y;

	if(normal[2] == 1.0)
		return PLANE_Z;

	if(normal[0] == 0.0 && normal[1] == 0.0 && normal[2] == 0.0)
		return PLANE_NON_PLANAR;

	return PLANE_NON_AXIAL;
}

/*
=====================
PlaneFromPoints

Returns false if the triangle is degenrate.
The normal will point out of the clock for clockwise ordered points
=====================
*/
qboolean PlaneFromPoints( vec4_t plane, const vec3_t a, const vec3_t b, const vec3_t c ) {
	vec3_t	d1, d2;

	VectorSubtract( b, a, d1 );
	VectorSubtract( c, a, d2 );
	CrossProduct( d2, d1, plane );
	if ( VectorNormalize( plane ) == 0 ) {
		return qfalse;
	}

	plane[3] = DotProduct( a, plane );
	return qtrue;
}


#define BOUNDS_CLEAR_VALUE 99999

void ClearBounds( vec3_t mins, vec3_t maxs ) {
	mins[ 0 ] = mins[ 1 ] = mins[ 2 ] = BOUNDS_CLEAR_VALUE;
	maxs[ 0 ] = maxs[ 1 ] = maxs[ 2 ] = -BOUNDS_CLEAR_VALUE;
}

float RadiusFromBounds( const vec3_t mins, const vec3_t maxs ) {
	int		i;
	vec3_t	corner;
	float	a, b;

	for (i=0 ; i<3 ; i++) {
		a = fabs( mins[i] );
		b = fabs( maxs[i] );
		corner[i] = a > b ? a : b;
	}

	return VectorLength (corner);
}

int BoxOnPlaneSide (const vec3_t emins, const vec3_t emaxs, struct cplane_s *p)
{
	float	dist1, dist2;
	int		sides;

	// fast axial cases
	if (p->type < 3)
	{
		if (p->dist <= emins[p->type])
			return 1;
		if (p->dist > emaxs[p->type])
			return 2;
		return 3;
	}

	// general case
	switch (p->signbits)
	{
	case 0:
		dist1 = p->normal[0]*emaxs[0] + p->normal[1]*emaxs[1] + p->normal[2]*emaxs[2];
		dist2 = p->normal[0]*emins[0] + p->normal[1]*emins[1] + p->normal[2]*emins[2];
		break;
	case 1:
		dist1 = p->normal[0]*emins[0] + p->normal[1]*emaxs[1] + p->normal[2]*emaxs[2];
		dist2 = p->normal[0]*emaxs[0] + p->normal[1]*emins[1] + p->normal[2]*emins[2];
		break;
	case 2:
		dist1 = p->normal[0]*emaxs[0] + p->normal[1]*emins[1] + p->normal[2]*emaxs[2];
		dist2 = p->normal[0]*emins[0] + p->normal[1]*emaxs[1] + p->normal[2]*emins[2];
		break;
	case 3:
		dist1 = p->normal[0]*emins[0] + p->normal[1]*emins[1] + p->normal[2]*emaxs[2];
		dist2 = p->normal[0]*emaxs[0] + p->normal[1]*emaxs[1] + p->normal[2]*emins[2];
		break;
	case 4:
		dist1 = p->normal[0]*emaxs[0] + p->normal[1]*emaxs[1] + p->normal[2]*emins[2];
		dist2 = p->normal[0]*emins[0] + p->normal[1]*emins[1] + p->normal[2]*emaxs[2];
		break;
	case 5:
		dist1 = p->normal[0]*emins[0] + p->normal[1]*emaxs[1] + p->normal[2]*emins[2];
		dist2 = p->normal[0]*emaxs[0] + p->normal[1]*emins[1] + p->normal[2]*emaxs[2];
		break;
	case 6:
		dist1 = p->normal[0]*emaxs[0] + p->normal[1]*emins[1] + p->normal[2]*emins[2];
		dist2 = p->normal[0]*emins[0] + p->normal[1]*emaxs[1] + p->normal[2]*emaxs[2];
		break;
	case 7:
		dist1 = p->normal[0]*emins[0] + p->normal[1]*emins[1] + p->normal[2]*emins[2];
		dist2 = p->normal[0]*emaxs[0] + p->normal[1]*emaxs[1] + p->normal[2]*emaxs[2];
		break;
	default:
		dist1 = dist2 = 0;		// shut up compiler
		break;
	}

	sides = 0;
	if (dist1 >= p->dist)
		sides = 1;
	if (dist2 < p->dist)
		sides |= 2;

	return sides;
}


#define X 0
#define Y 1
#define Z 2
#define W 3

#ifndef FLT_EPSILON
#define FLT_EPSILON 1.19209290E-07F
#endif

#define DELTA 1e-6

void SlerpQuaternion
(
	float from[4],
	float to[4],
	float t,
	float res[4]
)
{
	float		to1[4];
	double	omega, cosom, sinom, scale0, scale1;

	cosom = (double)from[X] * to[X] + (double)from[Y] * to[Y] + (double)from[Z] * to[Z] + (double)from[W] * to[W];
	if (cosom < 0.0)
	{
		cosom = -cosom;
		to1[X] = -to[X];
		to1[Y] = -to[Y];
		to1[Z] = -to[Z];
		to1[W] = -to[W];
	}
	else if
		(
			(from[X] == to[X]) &&
			(from[Y] == to[Y]) &&
			(from[Z] == to[Z]) &&
			(from[W] == to[W])
			)
	{
		// equal case, early exit
		res[X] = to[X];
		res[Y] = to[Y];
		res[Z] = to[Z];
		res[W] = to[W];
		return;
	}
	else
	{
		to1[X] = to[X];
		to1[Y] = to[Y];
		to1[Z] = to[Z];
		to1[W] = to[W];
	}

	if ((1.0 - cosom) > DELTA)
	{
		omega = acos(cosom);
		sinom = sin(omega);
		scale0 = sin((1.0 - t) * omega) / sinom;
		scale1 = sin(t * omega) / sinom;
	}
	else
	{
		scale0 = 1.0 - t;
		scale1 = t;
	}

	res[X] = scale0 * from[X] + scale1 * to1[X];
	res[Y] = scale0 * from[Y] + scale1 * to1[Y];
	res[Z] = scale0 * from[Z] + scale1 * to1[Z];
	res[W] = scale0 * from[W] + scale1 * to1[W];
}

void QuatToMat
(
	const float q[ 4 ],
	float m[ 3 ][ 3 ]
)
{
	float wx, wy, wz;
	float xx, yy, yz;
	float xy, xz, zz;
	float x2, y2, z2;

	x2 = q[ X ] + q[ X ];
	y2 = q[ Y ] + q[ Y ];
	z2 = q[ Z ] + q[ Z ];

	xx = q[ X ] * x2;
	xy = q[ X ] * y2;
	xz = q[ X ] * z2;

	yy = q[ Y ] * y2;
	yz = q[ Y ] * z2;
	zz = q[ Z ] * z2;

	wx = q[ W ] * x2;
	wy = q[ W ] * y2;
	wz = q[ W ] * z2;

	m[ 0 ][ 0 ] = 1.0 - ( yy + zz );
	m[ 0 ][ 1 ] = xy - wz;
	m[ 0 ][ 2 ] = xz + wy;

	m[ 1 ][ 0 ] = xy + wz;
	m[ 1 ][ 1 ] = 1.0 - ( xx + zz );
	m[ 1 ][ 2 ] = yz - wx;

	m[ 2 ][ 0 ] = xz - wy;
	m[ 2 ][ 1 ] = yz + wx;
	m[ 2 ][ 2 ] = 1.0 - ( xx + yy );
}

float NormalizeColor( const vec3_t in, vec3_t out ) {
	float	max;

	max = in[0];
	if ( in[1] > max ) {
		max = in[1];
	}
	if ( in[2] > max ) {
		max = in[2];
	}

	if ( !max ) {
		VectorClear( out );
	} else {
		out[0] = in[0] / max;
		out[1] = in[1] / max;
		out[2] = in[2] / max;
	}
	return max;
}

unsigned ColorBytes3 (float r, float g, float b) {
	unsigned	i;

	( (byte *)&i )[0] = r * 255;
	( (byte *)&i )[1] = g * 255;
	( (byte *)&i )[2] = b * 255;

	return i;
}

unsigned ColorBytes4 (float r, float g, float b, float a) {
	unsigned	i;

	( (byte *)&i )[0] = r * 255;
	( (byte *)&i )[1] = g * 255;
	( (byte *)&i )[2] = b * 255;
	( (byte *)&i )[3] = a * 255;

	return i;
}

void SetPlaneSignbits (cplane_t *out) {
	int	bits, j;

	// for fast box on planeside test
	bits = 0;
	for (j=0 ; j<3 ; j++) {
		if (out->normal[j] < 0) {
			bits |= 1<<j;
		}
	}
	out->signbits = bits;
}