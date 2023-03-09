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

#	include <mu9/mu9_algorithm/mu9_accumulate.h>

#ifndef PARALLEL_ACCUMULATE_H
#define PARALLEL_ACCUMULATE_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_accumulate1(_Tp, __first, __last, __init, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate1(_Tp, __first, __last, __init, __d_result)                                              \
mu0_scope_begin                                                                                                           \
	_Tp __mu9_parallel_accumulate1__v__                  = mu0_const_cast(_Tp, __init);                                    \
	_Tp * __mu9_parallel_accumulate1__a__                = __first + mu0_const_distance(0);                                \
	const mu0_distance_t __mu9_parallel_accumulate1__n__ = mu9_const_distance(_Tp, __first, __last);                       \
	      mu0_distance_t __mu9_parallel_accumulate1__i__ = mu0_const_distance(0);                                          \
	__mu0_pragma__(omp parallel for)                                                                                       \
	for (; __mu9_parallel_accumulate1__i__ < __mu9_parallel_accumulate1__n__; ++__mu9_parallel_accumulate1__i__) {         \
		__mu9_accumulate1__v__ = __mu9_accumulate1__v__ + __mu9_parallel_accumulate1__a__[__mu9_parallel_accumulate1__i__]; \
	}                                                                                                                      \
	__d_result = __mu9_accumulate1__v__;                                                                                   \
mu0_scope_end
#	else
#	define mu9_parallel_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_sequencial_accumulate1(_Tp, __first, __last, __init, __d_result)
#	endif

MU0_END_CDECL

#endif /* !PARALLEL_ACCUMULATE_H */

/* EOF */