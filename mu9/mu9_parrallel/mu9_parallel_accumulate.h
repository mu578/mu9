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

// mu9_parallel_accumulate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>
#	include <mu9/mu9_iterator.h>
#	include <mu9/mu9_algorithm/mu9_accumulate.h>

#ifndef PARALLEL_ACCUMULATE_H
#define PARALLEL_ACCUMULATE_H 1

MU0_BEGIN_CDECL

#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate_b0(_Tp, __ptr, __n, __init, __binary_op, __d_result)                                                   \
mu0_scope_begin                                                                                                                          \
	_Tp            __mu9_parallel_accumulate_b0__v__ = mu0_const_cast(_Tp, __init);                                                       \
	mu0_distance_t __mu9_parallel_accumulate_b0__i__;                                                                                     \
	__mu0_pragma__(omp parallel for reduction(+:__mu9_parallel_accumulate_b0__v__))                                                       \
	for (                                                                                                                                 \
		  __mu9_parallel_accumulate_b0__i__ = mu0_const_distance(0)                                                                        \
		; __mu9_parallel_accumulate_b0__i__ < mu0_const_distance(__n)                                                                      \
		; ++__mu9_parallel_accumulate_b0__i__                                                                                              \
	) {                                                                                                                                   \
		__mu9_parallel_accumulate_b0__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b0__v__, __ptr[__mu9_parallel_accumulate_b0__i__]); \
	}                                                                                                                                     \
	__d_result = __mu9_parallel_accumulate_b0__v__;                                                                                       \
mu0_scope_end

#	define mu9_parallel_accumulate_b1(_Tp, __ptr, __n, __init, __binary_op, __d_result)                                                        \
mu0_scope_begin                                                                                                                               \
	_Tp             __mu9_parallel_accumulate_b1__v__ = mu0_const_cast(_Tp, __init);                                                           \
	 mu0_distance_t __mu9_parallel_accumulate_b1__i__;                                                                                         \
	__mu0_pragma__(omp parallel for reduction(+:__mu9_parallel_accumulate_b1__v__))                                                            \
	for (                                                                                                                                      \
		  __mu9_parallel_accumulate_b1__i__ = mu0_const_distance(0)                                                                             \
		; __mu9_parallel_accumulate_b1__i__ < (mu0_const_distance(__n) - mu0_const_distance(32))                                                \
		; __mu9_parallel_accumulate_b1__i__ += mu0_const_distance(32)                                                                           \
	) {                                                                                                                                        \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__     ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 1 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 2 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 3 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 4 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 5 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 6 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 7 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 8 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 9 ]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 10]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 11]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 12]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 13]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 14]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 15]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 16]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 17]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 18]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 19]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 20]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 21]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 22]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 23]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 24]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 25]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 26]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 27]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 28]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 29]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 30]); \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__ + 31]); \
	}                                                                                                                                          \
	for (; __mu9_parallel_accumulate_b1__i__ < mu0_const_distance(__n); __mu9_parallel_accumulate_b1__i__++) {                                 \
		__mu9_parallel_accumulate_b1__v__ = __binary_op(_Tp, __mu9_parallel_accumulate_b1__v__, __ptr[__mu9_parallel_accumulate_b1__i__]);      \
	}                                                                                                                                          \
	__d_result = __mu9_parallel_accumulate_b1__v__;                                                                                            \
mu0_scope_end
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_accumulate1(_Tp, __first, __last, __init, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate1(_Tp, __first, __last, __init, __d_result)                        \
mu0_scope_begin                                                                                     \
	_Tp *                __mu9_parallel_accumulate1__p__ = mu9_begin(_Tp, __first);                  \
	const mu0_distance_t __mu9_parallel_accumulate1__n__ = mu9_const_distance(_Tp, __first, __last); \
	mu9_parallel_accumulate_b0(_Tp                                                                   \
		, __mu9_parallel_accumulate1__p__                                                             \
		, __mu9_parallel_accumulate1__n__                                                             \
		, __init                                                                                      \
		, mu9_plus                                                                                    \
		, __d_result                                                                                  \
	);                                                                                               \
mu0_scope_end
#	else
#	define mu9_parallel_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_sequencial_accumulate1(_Tp, __first, __last, __init, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result) \
	mu9_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result)           \
mu0_scope_begin                                                                                     \
	_Tp *                __mu9_parallel_accumulate1__p__ = mu9_begin(_Tp, __first);                  \
	const mu0_distance_t __mu9_parallel_accumulate1__n__ = mu9_const_distance(_Tp, __first, __last); \
	mu9_parallel_accumulate_b0(_Tp                                                                   \
		, __mu9_parallel_accumulate1__p__                                                             \
		, __mu9_parallel_accumulate1__n__                                                             \
		, __init                                                                                      \
		, __binary_op                                                                                 \
		, __d_result                                                                                  \
	);                                                                                               \
mu0_scope_end
#	else
#	define mu9_parallel_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result) \
	mu9_sequencial_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result)
#	endif

MU0_END_CDECL

#endif /* !PARALLEL_ACCUMULATE_H */

/* EOF */