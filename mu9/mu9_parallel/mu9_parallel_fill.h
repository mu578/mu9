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

// mu9_parallel_fill.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>
#	include <mu9/mu9_iterator.h>
#	include <mu9/mu9_algorithm/mu9_fill.h>

#ifndef MU9_PARALLEL_FILL_H
#define MU9_PARALLEL_FILL_H 1

MU0_BEGIN_CDECL

#	if MU0_HAVE_PARALLELIZE
#	if MU0_HAVE_OPENMP

#	define __mu9_parallel_fill00__(_Tp, __first, __last, __value)                               \
mu0_scope_begin                                                                                \
	const _Tp            __mu9_parallel_fill00__v__ = __value;                                  \
	      _Tp *          __mu9_parallel_fill00__p__ = mu9_begin(_Tp, __first);                  \
	const mu0_distance_t __mu9_parallel_fill00__n__ = mu9_const_distance(_Tp, __first, __last); \
	__mu0_pragma__(omp parallel for simd)                                                       \
	for (                                                                                       \
		  mu0_distance_t __mu9_parallel_fill00__i__ = mu0_const_distance(0)                      \
		;                __mu9_parallel_fill00__i__ < __mu9_parallel_fill00__n__                 \
		;                __mu9_parallel_fill00__i__++                                            \
	) {                                                                                         \
		__mu9_parallel_fill00__p__[__mu9_parallel_fill00__i__] = __mu9_parallel_fill00__v__;     \
	}                                                                                           \
mu0_scope_end

#	define __mu9_parallel_fill_n00__(_Tp, __first, __n, __value)                                  \
mu0_scope_begin                                                                                  \
	const _Tp            __mu9_parallel_fill_n00__v__ = __value;                                  \
	      _Tp *          __mu9_parallel_fill_n00__p__ = mu9_begin(_Tp, __first);                  \
	const mu0_distance_t __mu9_parallel_fill_n00__n__ = mu0_const_distance(__n);                  \
	__mu0_pragma__(omp parallel for simd)                                                         \
	for (                                                                                         \
		  mu0_distance_t __mu9_parallel_fill_n00__i__ = mu0_const_distance(0)                      \
		;                __mu9_parallel_fill_n00__i__ < __mu9_parallel_fill_n00__n__               \
		;                __mu9_parallel_fill_n00__i__++                                            \
	) {                                                                                           \
		__mu9_parallel_fill_n00__p__[__mu9_parallel_fill_n00__i__] = __mu9_parallel_fill_n00__v__; \
	}                                                                                             \
mu0_scope_end

#	endif
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, const _Tp & __value) : void
//#!
#	define mu9_sequencial_fill(_Tp, __first, __last, __value) \
	mu9_fill(_Tp, __first, __last, __value)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, const _Tp & __value) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_fill(_Tp, __first, __last, __value) \
	__mu9_parallel_fill00__(_Tp, __first, __last, , __value)
#	else
#	define mu9_parallel_fill(_Tp, __first, __last, __value) \
	mu9_sequencial_fill(_Tp, __first, __last, __value)
#	endif

//#!
//#! macro<_Tp, _Uint, execution=sequencial>(_Tp &* __first, _Uint & __n, const _Tp & __value) : void
//#!
#	define mu9_sequencial_fill_n(_Tp, __first, __n, __value) \
	mu9_fill_n(_Tp, __first, __n, __value)

//#!
//#! macro<_Tp, _Uint, execution=parallel>(_Tp &* __first, _Uint & __n, const _Tp & __value) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_fill_n(_Tp, __first, __n, __value) \
	__mu9_parallel_fill_n00__(_Tp, __first, __n, __value)
#	else
#	define mu9_parallel_fill_n(_Tp, __first, __n, __value) \
	mu9_sequencial_fill_n(_Tp, __first, __n, __value)
#	endif

MU0_END_CDECL

#endif /* !MU9_PARALLEL_FILL_H */

/* EOF */