#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "libavutil/rational.h"

#if (_MSC_VER < 1800)  //低于vc2013
#include <float.h>
#include <math.h>
	#if defined(WIN32) 
		//#define __restrict__
		#define inline __inline
		#define isnan _isnan
		#define snprintf _snprintf
		#define round _round
		#define lrint(f) (f>=0?(int32_t)(f+(double)0.5):(int32_t)(f-(double)0.4))
		#define lrintf(f) (f>=0?(int32_t)(f+(float)0.5):(int32_t)(f-(float)0.4))
		#define llrintf(f) (f>=0?(int64_t)(f+(double)0.5):(int64_t)(f-(double)0.4))
		#define llrint(f) (f>=0?(int64_t)(f+(float)0.5):(int64_t)(f-(float)0.4))
		extern double _round(double val);
	#endif
#endif

#if (_MSC_VER < 1600)  //低于vc2010 即 vc2008或者更低 
	#define _C2			1	/* 0 if not 2's complement */
	#define INT64_MIN	(-0x7fffffffffffffff - _C2)
	#define INT64_MAX	0x7fffffffffffffff
	#define UINT64_MAX	0xffffffffffffffffU
#endif

			//MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
			//MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
			//MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
			//MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
			//MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)
			//MSVC++ 8.0  _MSC_VER == 1400 (Visual Studio 2005)
			//MSVC++ 7.1  _MSC_VER == 1310 (Visual Studio 2003)
			//MSVC++ 7.0  _MSC_VER == 1300
			//MSVC++ 6.0  _MSC_VER == 1200
			//MSVC++ 5.0  _MSC_VER == 1100
//extern int __sqrt(int i);
extern AVRational _AVRational(int num, int den);
extern int compat_sqrt(int i);
extern double _log(int i);

#define AV_TIME_BASE_Q   _AVRational(1, AV_TIME_BASE)
#define sqrt compat_sqrt
#define log _log

#ifdef __cplusplus
}
#endif