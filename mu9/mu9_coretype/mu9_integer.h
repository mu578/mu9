//
// # -*- coding: utf-8, tab-width: 3 -*-

//                                                          ___                                             //
//                                                         / _ \                                            //
//                                            _   _  _   _( (_) |                                           //
//                                           | | | || | | |\__, |                                           //
//                                           | |_| || |_| |  / /                                            //
//                                           | ._,_| \___/  /_/                                             //
//                                           | |                                                            //
//                                           |_|                                                            //

// mu9_integer.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_INTEGER_H
#define MU9_INTEGER_H 1

#	undef  MU9_USE_INT128
#	undef  MU9_HAVE_INT128

#	define MU9_USE_INT128  1
#	define MU9_HAVE_INT128 0

MU9_BEGIN_CDECL

#	if MU9_HAVE_MU8
#include <mu8/mu8_integer.h>
#	else
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#	endif

typedef   ptrdiff_t                     mu9_ptrdiff_t;
typedef   uintmax_t                     mu9_uintmax_t;
typedef   intmax_t                      mu9_sintmax_t;

#	if MU9_USE_INT128
#	if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 8)
__extension__
typedef unsigned __int128               mu9_uint128_t;
#	if MU9_HAVE_MU8
#	define mu9_sint128_t                 mu8_sint128_t
#	else
__extension__
typedef __int128                        mu9_sint128_t;
#	endif
#	elif defined(__clang__) && defined(__is_identifier)
#		if !__is_identifier(__int128_t)
#			undef  MU9_HAVE_INT128
#			define MU9_HAVE_INT128 1
			__extension__
			typedef __uint128_t            mu9_uint128_t;
#			if MU9_HAVE_MU8
#			define mu9_sint128_t           mu8_sint128_t
#			else
			__extension__
			typedef __int128_t             mu9_sint128_t;
#			endif
#		else
			typedef uint64_t               mu9_uint128_t;
#			if MU9_HAVE_MU8
#			define mu9_sint128_t           mu8_sint128_t
#			else
			typedef int64_t                mu9_sint128_t;
#			endif
#		endif
#		else
			typedef uint64_t               mu9_uint128_t;
#			if MU9_HAVE_MU8
#			define mu9_sint128_t           mu8_sint128_t
#			else
			typedef int64_t                mu9_sint128_t;
#			endif
#	endif
#	else
	typedef uint64_t                     mu9_uint128_t;
#	if MU9_HAVE_MU8
#	define mu9_sint128_t                 mu8_sint128_t
#	else
	typedef int64_t                      mu9_sint128_t;
#	endif
#	endif

typedef   uint64_t                      mu9_uint64_t;
#	if MU9_HAVE_MU8
#	define mu9_sint64_t                  mu8_sint64_t
#	else
typedef   int64_t                       mu9_sint64_t;
#	endif

typedef   uint32_t                      mu9_uint32_t;
#	if MU9_HAVE_MU8
#	define mu9_sint32_t                  mu8_sint32_t
#	else
typedef   int32_t                       mu9_sint32_t;
#	endif

typedef   uint16_t                      mu9_uint16_t;
typedef   int16_t                       mu9_sint16_t;

typedef   uint8_t                       mu9_uint8_t;
typedef   int8_t                        mu9_sint8_t;

typedef   bool                          mu9_bool_t;
#	define mu9_true                      true
#	define mu9_false                     false

#	define mu9_uintmax(__x)              mu9_cast(mu9_uintmax_t, __x)
#	define mu9_const_uintmax(__x)        mu9_const_cast(mu9_uinmax_t, __x)

#	define mu9_uint128(__x)              mu9_cast(mu9_uint128_t, __x)
#	define mu9_const_uint128(__x)        mu9_const_cast(mu9_uin128_t, __x)

#	define mu9_uint64(__x)               mu9_cast(mu9_uint64_t, __x)
#	define mu9_const_uint64(__x)         mu9_const_cast(mu9_uint64_t, __x)
#	define mu9_sint64(__x)               mu9_cast(mu9_sint64_t, __x)
#	define mu9_const_sint64(__x)         mu9_const_cast(mu9_sint64_t, __x)

#	define mu9_uint32(__x)               mu9_cast(mu9_uint32_t, __x)
#	define mu9_const_uint32(__x)         mu9_const_cast(mu9_uint32_t, __x)
#	define mu9_sint32(__x)               mu9_cast(mu9_sint32_t, __x)
#	define mu9_const_sint32(__x)         mu9_const_cast(mu9_sint32_t, __x)

#	define mu9_uint16(__x)               mu9_cast(mu9_uint16_t, __x)
#	define mu9_const_uint16(__x)         mu9_const_cast(mu9_uint16_t, __x)
#	define mu9_sint16(__x)               mu9_cast(mu9_sint16_t, __x)
#	define mu9_const_sint16(__x)         mu9_const_cast( mu9_sint16_t, __x)

#	define mu9_uint8(__x)                mu9_cast(mu9_uint8_t, __x)
#	define mu9_const_uint8(__x)          mu9_const_cast(mu9_uint8_t, __x)
#	define mu9_sint8(__x)                mu9_cast(mu9_sint8_t, __x)
#	define mu9_const_sint8(__x)          mu9_const_cast(mu9_sint8_t, __x)

typedef   mu9_uint64_t                  mu9_uinteger_t;

#	define mu9_uinteger(__x)             mu9_cast(mu9_uinteger_t, __x)
#	define mu9_const_uinteger(__x)       mu9_const_cast(mu9_uinteger_t, __x)

typedef   mu9_sint64_t                  mu9_sinteger_t;

#	define mu9_sinteger(__x)             mu9_cast(mu9_ssinteger_t, __x)
#	define mu9_const_sinteger(__x)       mu9_const_cast(mu9_ssinteger_t, __x)

typedef   mu9_ptrdiff_t                 mu9_difference_t;

#	define mu9_difference(__x)           mu9_cast(mu9_difference_t, __x)
#	define mu9_const_difference(__x)     mu9_const_cast(mu9_difference_t, __x)

typedef   mu9_ptrdiff_t                 mu9_distance_t;

#	define mu9_distance(__x)             mu9_cast(mu9_distance_t, __x)
#	define mu9_const_distance(__x)       mu9_const_cast(mu9_distance_t, __x)

typedef   mu9_uint128_t *               mu9_vuint128_t;
typedef   mu9_sint128_t *               mu9_vsint128_t;

typedef   mu9_uint64_t *                mu9_vuint64_t;
typedef   mu9_sint64_t *                mu9_vsint64_t;

typedef   mu9_uint32_t *                mu9_vuint32_t;
typedef   mu9_sint32_t *                mu9_vsint32_t;

typedef   mu9_uint16_t *                mu9_vuint16_t;
typedef   mu9_sint16_t *                mu9_vsint16_t;

typedef   mu9_uint8_t  *                mu9_vuint8_t;
typedef   mu9_sint8_t  *                mu9_vsint8_t;

#	define mu9_vuint128(__x)             mu9_cast(mu9_vuint128_t, __x)
#	define mu9_const_vuint128(__x)       mu9_const_cast(mu9_vuint128_t, __x)
#	define mu9_vsint128(__x)             mu9_cast(mu9_vsint128_t, __x)
#	define mu9_const_vsint128(__x)       mu9_const_cast(mu9_vsint128_t, __x)

#	define mu9_vuint64(__x)              mu9_cast(mu9_vuint64_t, __x)
#	define mu9_const_vuint64(__x)        mu9_const_cast(mu9_vuint64_t, __x)
#	define mu9_vsint64(__x)              mu9_cast(mu9_vsint64_t, __x)
#	define mu9_const_vsint64(__x)        mu9_const_cast(mu9_vsint64_t, __x)

#	define mu9_vuint32(__x)              mu9_cast(mu9_vuint32_t, __x)
#	define mu9_const_vuint32(__x)        mu9_const_cast(mu9_vuint32_t, __x)
#	define mu9_vsint32(__x)              mu9_cast(mu9_vsint32_t, __x)
#	define mu9_const_vsint32(__x)        mu9_const_cast(mu9_vsint32_t, __x)

#	define mu9_vuint16(__x)              mu9_cast(mu9_vuint16_t, __x)
#	define mu9_const_vuint16(__x)        mu9_const_cast(mu9_vuint16_t, __x)
#	define mu9_vsint16(__x)              mu9_cast(mu9_vsint16_t, __x)
#	define mu9_const_vsint16(__x)        mu9_const_cast( mu9_vsint16_t, __x)

#	define mu9_vuint8(__x)               mu9_cast(mu9_vuint8_t, __x)
#	define mu9_const_vuint8(__x)         mu9_const_cast(mu9_vuint8_t, __x)
#	define mu9_vsint8(__x)               mu9_cast(mu9_vsint8_t, __x)
#	define mu9_const_vsint8(__x)         mu9_const_cast(mu9_vsint8_t, __x)

MU9_END_CDECL

#endif /* !MU9_INTEGER_H */

/* EOF */