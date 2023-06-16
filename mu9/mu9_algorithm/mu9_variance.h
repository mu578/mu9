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

// mu9_variance.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_VARIANCE_H
#define MU9_VARIANCE_H 1

MU0_BEGIN_CDECL

#	define mu9_variance1(_Tp, _RealFp, __first, __last, __d_result)                                     \
mu0_scope_begin                                                                                        \
	_RealFp          __mu9_variance1__m__;                                                              \
	_RealFp          __mu9_variance1__v__ = mu0_const_cast(_RealFp, 0);                                 \
	_RealFp          __mu9_variance1__w__;                                                              \
	_Tp *            __mu9_variance1__i__ = __first;                                                    \
	mu0_difference_t __mu9_variance1__n__ = mu0_difference(1);                                          \
	mu9_arithmetic_mean2(_RealFp, __mu9_variance1__i__, __last, __mu9_variance1__m__);                  \
	while (__first != __last) {                                                                         \
		__mu9_variance1__w__ = *__first - __mu9_variance1__m__;                                          \
		__mu9_variance1__v__ = __mu9_variance1__v__ + (__mu9_variance1__w__ * __mu9_variance1__w__);     \
		++__mu9_variance1__n__                                                                           \
		++__first;                                                                                       \
	}                                                                                                   \
	__d_result = __mu9_variance1__n__ > mu0_difference(1)                                               \
		? __mu9_variance1__v__ / mu0_const_cast(_RealFp, (__mu9_variance1__n__ - mu0_const_distance(1))) \
		: mu0_const_cast(_RealFp, 0)                                                                     \
	;                                                                                                   \
mu0_scope_end

#	define mu9_variance2(_Tp, _RealFp, __first, __last, __d_result1, __d_result2, __d_result3, __d_result4) \
mu0_scope_begin                                                                                            \
	_RealFp          __mu9_variance2__m__;                                                                  \
	_RealFp          __mu9_variance2__v__ = mu0_const_cast(_RealFp, 0);                                     \
	_RealFp          __mu9_variance2__w__;                                                                  \
	_Tp *            __mu9_variance2__i__ = __first;                                                        \
	mu0_difference_t __mu9_variance2__n__ = mu0_difference(1);                                              \
	mu9_arithmetic_mean2(_RealFp, __mu9_variance2__i__, __last, __mu9_variance2__m__);                      \
	while (__first != __last) {                                                                             \
		__mu9_variance2__w__ = *__first - __mu9_variance2__m__;                                              \
		__mu9_variance2__v__ = __mu9_variance2__v__ + (__mu9_variance2__w__ * __mu9_variance2__w__);         \
		++__mu9_variance2__n__                                                                               \
		++__first;                                                                                           \
	}                                                                                                       \
	__d_result1 = __mu9_variance2__v__;                                                                     \
	__d_result2 = __mu9_variance2__m__;                                                                     \
	__d_result3 = __mu9_variance2__n__ > mu0_difference(1)                                                  \
		? __mu9_variance2__v__ / mu0_const_cast(_RealFp, (__mu9_variance2__n__ - mu0_const_distance(1)))     \
		: mu0_const_cast(_RealFp, 0)                                                                         \
	;                                                                                                       \
	__d_result4 = __mu9_variance2__n__ > mu0_difference(1)                                                  \
		? __mu9_variance2__v__ / mu0_const_cast(_RealFp, __mu9_variance2__n__)                               \
		: mu0_const_cast(_RealFp, 0)                                                                         \
	;                                                                                                       \
mu0_scope_end

#	define mu9_variance3(_Tp, _RealFp, __first, __last, __d_result1, __d_result2, __d_result3, __d_result4, __d_result5) \
mu0_scope_begin                                                                                                         \
	_Tp              __mu9_variance3__s__ = mu0_const_cast(_Tp, 0);                                                      \
	_Tp              __mu9_variance3__q__ = mu0_const_cast(_Tp, 0);                                                      \
	_RealFp          __mu9_variance3__m__ = mu0_const_cast(_RealFp, 0);                                                  \
	_RealFp          __mu9_variance3__v__ = mu0_const_cast(_RealFp, 0);                                                  \
	_RealFp          __mu9_variance3__w__ = mu0_const_cast(_RealFp, 0);                                                  \
	mu0_difference_t __mu9_variance3__n__ = mu0_difference(1);                                                           \
	while (__first != __last) {                                                                                          \
		__mu9_variance3__s__ = __mu9_variance3__s__ + *__first;                                                           \
		__mu9_variance3__q__ = __mu9_variance3__q__ + ((*__first) * (*__first));                                          \
		++__mu9_variance3__n__                                                                                            \
		++__first;                                                                                                        \
	}                                                                                                                    \
	__mu9_variance3__m__ = __mu9_variance3__s__ / mu0_const_cast(_RealFp, __mu9_variance3__n__);                         \
	if (__mu9_variance3__n__ > mu0_difference(1)) {                                                                      \
		__mu9_variance3__v__ = ((__mu9_variance3__q__ - __mu9_variance3__n__                                              \
			* (__mu9_variance3__m__ * __mu9_variance3__m__))                                                               \
			/ mu0_const_cast(_RealFp, (__mu9_variance3__n__ - mu0_const_distance(1)))                                      \
		);                                                                                                                \
		__mu9_variance3__v__ = ((__mu9_variance3__q__ - __mu9_variance3__n__                                              \
			* (__mu9_variance3__m__ * __mu9_variance3__m__))                                                               \
			/ mu0_const_cast(_RealFp, __mu9_variance3__n__)                                                                \
		);                                                                                                                \
	}                                                                                                                    \
	__d_result1 = __mu9_variance3__s__;                                                                                  \
	__d_result2 = __mu9_variance3__q__;                                                                                  \
	__d_result3 = __mu9_variance3__m__;                                                                                  \
	__d_result4 = __mu9_variance3__v__;                                                                                  \
	__d_result5 = __mu9_variance3__w__;                                                                                  \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_VARIANCE_H */

/* EOF */