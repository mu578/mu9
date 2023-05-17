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

// mu9_median.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>
#include <mu9/mu9_algorithm/mu9_insertion_sort.h>

#ifndef MU9_MEDIAN_H
#define MU9_MEDIAN_H 1

MU0_BEGIN_CDECL

#	define mu9_median1(_Tp, _RealFp, __first, __last, __d_result)                                           \
mu0_scope_begin                                                                                            \
	      _RealFp        __mu9_median1__v__ = mu0_const_cast(_RealFp, 0);                                   \
	      _Tp            __mu9_median1__w__ = mu0_const_cast(_Tp, 0);                                       \
	const mu0_distance_t __mu9_median1__n__ = mu9_const_distance(_Tp, __first, __last);                     \
	      mu0_distance_t __mu9_median1__k__;                                                                \
	      _Tp *          __mu9_median1__i__ = __first;                                                      \
	mu9_insertion_sort1(_Tp, __first, __last);                                                              \
	if (__mu9_median1__n__ % mu0_const_distance(2) == mu0_const_distance(0)) {                              \
		__mu9_median1__k__ =  __mu9_median1__n__ / mu0_const_distance(2) - mu0_const_distance(1);            \
		__mu9_median1__w__ = *mu9_next_n(_Tp, __mu9_median1__i__, __mu9_median1__k__);                       \
		__mu9_median1__k__ =  __mu9_median1__n__ / mu0_const_distance(2);                                    \
		__mu9_median1__w__ =  __mu9_median1__w__ + *mu9_next_n(_Tp, __mu9_median1__i__, __mu9_median1__k__); \
		__mu9_median1__v__ =  __mu9_median1__w__ / mu0_const_cast(_RealFp, 2);                               \
	} else {                                                                                                \
		__mu9_median1__k__ =  __mu9_median1__n__ / mu0_const_distance(2);                                    \
		__mu9_median1__w__ = *mu9_next_n(_Tp, __mu9_median1__i__, __mu9_median1__k__);                       \
		__mu9_median1__v__ =  mu0_const_cast(_RealFp, __mu9_median1__w__);                                   \
	}                                                                                                       \
	__d_result = __mu9_median1__v__;                                                                        \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MEDIAN_H */

/* EOF */