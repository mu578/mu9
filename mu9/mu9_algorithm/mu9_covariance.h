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

// mu9_covariance.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_COVARIANCE_H
#define MU9_COVARIANCE_H 1

MU0_BEGIN_CDECL

#	define mu9_covariance1(_Tp, _Real, __first1, __last1, __first2, __d_result1, __d_result2, __d_result3, __d_result4, __d_result5) \
mu0_scope_begin                                                                                                                     \
	_Real            __mu9_covariance1__mi__;                                                                                        \
	_Real            __mu9_covariance1__mj__;                                                                                        \
	_Real            __mu9_covariance1__v__  = mu0_const_cast(_Real, 0);;                                                            \
	_Real            __mu9_covariance1__wj__;                                                                                        \
	_Tp *            __mu9_covariance1__i__  = __first1;                                                                             \
	_Tp *            __mu9_covariance1__j__  = __first2;                                                                             \
	mu0_difference_t __mu9_covariance1__n__  = mu0_difference(1);                                                                    \
	mu9_arithmetic_mean4(_Tp, _Real                                                                                                  \
		, __mu9_covariance1__i__                                                                                                      \
		, __last1                                                                                                                     \
		, __mu9_covariance1__j__                                                                                                      \
		, __mu9_covariance1__mi__                                                                                                     \
		, __mu9_covariance1__mj__                                                                                                     \
	);                                                                                                                               \
	while(__first1 != __last1) {                                                                                                     \
		__mu9_covariance1__wi__ = *__first1 - __mu9_covariance1__mi__;                                                                \
		__mu9_covariance1__wj__ = *__first2 - __mu9_covariance1__mj__;                                                                \
		__mu9_covariance1__v__  = __mu9_variance1__v__ + (__mu9_covariance1__wi__ * __mu9_covariance1__wj__);                         \
		++__mu9_covariance1__n__                                                                                                      \
		++__first1;                                                                                                                   \
		++__first2;                                                                                                                   \
	}                                                                                                                                \
	__d_result1 = __mu9_covariance1__v__;                                                                                            \
	__d_result2 = __mu9_covariance1__mi__;                                                                                           \
	__d_result3 = __mu9_covariance1__mj__;                                                                                           \
	__d_result4 = __mu9_covariance1__n__ > mu0_difference(1)                                                                         \
		? __mu9_covariance1__v__ / mu0_const_cast(_Real, (__mu9_covariance1__n__ - mu0_const_distance(1)))                            \
		: mu0_const_cast(_Real, 0)                                                                                                    \
	;                                                                                                                                \
	__d_result5 = __mu9_covariance1__n__ > mu0_difference(1)                                                                         \
		? __mu9_covariance1__v__ / mu0_const_cast(_Real, __mu9_covariance1__n__)                                                      \
		: mu0_const_cast(_Real, 0)                                                                                                    \
	;                                                                                                                                \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_COVARIANCE_H */

/* EOF */