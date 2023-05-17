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

// mu9_sample_kurtosis1.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_SAMPLE_KURTOSIS_H
#define MU9_SAMPLE_KURTOSIS_H 1

MU0_BEGIN_CDECL

#	define mu9_sample_kurtosis1(_Tp, _RealFp, __first, __last, __d_result1, __d_result2, __d_result3)                             \
mu0_scope_begin                                                                                                                  \
	_RealFp          __mu9_sample_kurtosis1__m2__ = mu0_const_cast(_RealFp, 0);                                                   \
	_RealFp          __mu9_sample_kurtosis1__m4__ = mu0_const_cast(_RealFp, 0);                                                   \
	_RealFp          __mu9_sample_kurtosis1__v__;                                                                                 \
	_RealFp          __mu9_sample_kurtosis1__m__;                                                                                 \
	_RealFp          __mu9_sample_kurtosis1__s__;                                                                                 \
	mu0_difference_t __mu9_sample_kurtosis1__n__  = mu0_difference(1);                                                            \
	mu9_arithmetic_mean1(_Tp, _RealFp, __first, __last, __mu9_sample_kurtosis1__s__, __mu9_sample_kurtosis1__m__);                \
	while(__first != __last) {                                                                                                    \
		__mu9_sample_kurtosis1__v__  = *__first - __mu9_sample_kurtosis1__m__;                                                     \
		__mu9_sample_kurtosis1__m2__ = __mu9_sample_kurtosis1__m2__ + (__mu9_sample_kurtosis1__v__ * __mu9_sample_kurtosis1__v__); \
		__mu9_sample_kurtosis1__m4__ = __mu9_sample_kurtosis1__m4__ + (                                                            \
			  __mu9_sample_kurtosis1__v__ * __mu9_sample_kurtosis1__v__                                                             \
			* __mu9_sample_kurtosis1__v__ * __mu9_sample_kurtosis1__v__                                                             \
		);                                                                                                                         \
		++__mu9_sample_kurtosis1__n__;                                                                                             \
		++__first;                                                                                                                 \
	}                                                                                                                             \
	if (__mu9_sample_kurtosis1__n__ > mu0_difference(4)) {                                                                        \
		__d_result1 = __mu9_sample_kurtosis1__s__;                                                                                 \
		__d_result2 = __mu9_sample_kurtosis1__m__;                                                                                 \
		__d_result3 = (((__mu9_sample_kurtosis1__n__ - mu0_difference(1)) / ((__mu9_sample_kurtosis1__n__ - mu0_difference(2))     \
			* ( __mu9_sample_kurtosis1__n__ - mu0_difference(3))))                                                                  \
			* ((__mu9_sample_kurtosis1__n__ * (__mu9_sample_kurtosis1__n__ + mu0_difference(1))                                     \
			*   __mu9_sample_kurtosis1__m4__) / (__mu9_sample_kurtosis1__m2__ * __mu9_sample_kurtosis1__m2__) - mu0_difference(3)   \
			*  (__mu9_sample_kurtosis1__n__ - mu0_difference(1)))                                                                   \
		);                                                                                                                         \
	} else {                                                                                                                      \
		__d_result1 = __mu9_sample_kurtosis1__s__;                                                                                 \
		__d_result2 = __mu9_sample_kurtosis1__m__;                                                                                 \
		__d_result3 = mu0_const_cast(_RealFp, 0);                                                                                  \
	}                                                                                                                             \
mu0_scope_end

#	define mu9_sample_kurtosis2(_Tp, _RealFp, __first, __last, __mean_value, __d_result)                                          \
mu0_scope_begin                                                                                                                  \
	_RealFp          __mu9_sample_kurtosis2__m2__ = mu0_const_cast(_RealFp, 0);                                                   \
	_RealFp          __mu9_sample_kurtosis2__m4__ = mu0_const_cast(_RealFp, 0);                                                   \
	_RealFp          __mu9_sample_kurtosis2__v__;                                                                                 \
	_RealFp          __mu9_sample_kurtosis2__m__  = mu0_const_cast(_RealFp, __mean_value);                                        \
	mu0_difference_t __mu9_sample_kurtosis2__n__  = mu0_difference(1);                                                            \
	while(__first != __last) {                                                                                                    \
		__mu9_sample_kurtosis2__v__  = *__first - __mu9_sample_kurtosis2__m__;                                                     \
		__mu9_sample_kurtosis2__m2__ = __mu9_sample_kurtosis2__m2__ + (__mu9_sample_kurtosis2__v__ * __mu9_sample_kurtosis2__v__); \
		__mu9_sample_kurtosis2__m4__ = __mu9_sample_kurtosis2__m4__ + (                                                            \
			  __mu9_sample_kurtosis2__v__ * __mu9_sample_kurtosis2__v__                                                             \
			* __mu9_sample_kurtosis2__v__ * __mu9_sample_kurtosis2__v__                                                             \
		);                                                                                                                         \
		++__mu9_sample_kurtosis2__n__;                                                                                             \
		++__first;                                                                                                                 \
	}                                                                                                                             \
	if (__mu9_sample_kurtosis2__n__ > mu0_difference(4)) {                                                                        \
		__d_result = (((__mu9_sample_kurtosis2__n__ - mu0_difference(1)) / ((__mu9_sample_kurtosis2__n__ - mu0_difference(2))      \
			* ( __mu9_sample_kurtosis2__n__ - mu0_difference(3))))                                                                  \
			* ((__mu9_sample_kurtosis2__n__ * (__mu9_sample_kurtosis2__n__ + mu0_difference(1))                                     \
			*   __mu9_sample_kurtosis2__m4__) / (__mu9_sample_kurtosis2__m2__ * __mu9_sample_kurtosis2__m2__) - mu0_difference(3)   \
			*  (__mu9_sample_kurtosis2__n__ - mu0_difference(1)))                                                                   \
		);                                                                                                                         \
	} else {                                                                                                                      \
		__d_result = mu0_const_cast(_RealFp, 0);                                                                                   \
	}                                                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SAMPLE_KURTOSIS_H */

/* EOF */