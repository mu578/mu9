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

// mu9_arithmetic_mean.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_ARITHMETIC_MEAN_H
#define MU9_ARITHMETIC_MEAN_H 1

MU0_BEGIN_CDECL

#	define mu9_arithmetic_mean1(_Tp, _RealFp, __first, __last, __d_result1, __d_result2)              \
mu0_scope_begin                                                                                      \
	_Tp              __mu9_arithmetic_mean1__s__ = mu0_const_cast(_Tp, 0);                            \
	mu0_difference_t __mu9_arithmetic_mean1__n__ = mu0_difference(1);                                 \
	while (__first != __last) {                                                                       \
		__mu9_arithmetic_mean1__s__ = __mu9_arithmetic_mean1__s__ + *__first;                          \
		++__mu9_arithmetic_mean1__n__;                                                                 \
		++__first;                                                                                     \
	}                                                                                                 \
	__d_result1 = __mu9_arithmetic_mean1__s__;                                                        \
	__d_result2 = __mu9_arithmetic_mean1__s__ / mu0_const_cast(_RealFp, __mu9_arithmetic_mean1__n__); \
mu0_scope_end

#	define mu9_arithmetic_mean2(_Tp, _RealFp, __first, __last, __d_result)            \
mu0_scope_begin                                                                      \
	_RealFp          __mu9_arithmetic_mean2__m__ = mu0_const_cast(_RealFp, 0);        \
	mu0_difference_t __mu9_arithmetic_mean2__c__ = mu0_difference(1);                 \
	while (__first != __last) {                                                       \
		__mu9_arithmetic_mean2__m__ = __mu9_arithmetic_mean2__m__                      \
			+ ((*__first - __mu9_arithmetic_mean2__m__) / __mu9_arithmetic_mean2__c__); \
		++__mu9_arithmetic_mean2__c__;                                                 \
		++__first;                                                                     \
	}                                                                                 \
	__d_result = __mu9_arithmetic_mean2__m__;                                         \
mu0_scope_end

#	define mu9_arithmetic_mean3(_Tp, _RealFp, __first1, __last1, __first2, __d_result1, __d_result2, __d_result3, __d_result4) \
mu0_scope_begin                                                                                                               \
	_Tp              __mu9_arithmetic_mean3__si__ = mu0_const_cast(_Tp, 0);                                                    \
	_Tp              __mu9_arithmetic_mean3__sj__ = mu0_const_cast(_Tp, 0);                                                    \
	mu0_difference_t __mu9_arithmetic_mean3__n__  = mu0_difference(1);                                                         \
	while (__first1 != __last1) {                                                                                              \
		__mu9_arithmetic_mean3__si__ = __mu9_arithmetic_mean3__si__ + *__first1;                                                \
		__mu9_arithmetic_mean3__sj__ = __mu9_arithmetic_mean3__sj__ + *__first2;                                                \
		++__mu9_arithmetic_mean3__n__;                                                                                          \
		++__first1;                                                                                                             \
		++__first2;                                                                                                             \
	}                                                                                                                          \
	__d_result1 = __mu9_arithmetic_mean3__si__;                                                                                \
	__d_result2 = __mu9_arithmetic_mean3__sj__;                                                                                \
	__d_result3 = __mu9_arithmetic_mean3__si__ / mu0_const_cast(_RealFp, __mu9_arithmetic_mean3__n__);                         \
	__d_result4 = __mu9_arithmetic_mean3__sj__ / mu0_const_cast(_RealFp, __mu9_arithmetic_mean3__n__);                         \
mu0_scope_end

#	define mu9_arithmetic_mean4(_Tp, _RealFp, __first1, __last1, __first2, __d_result1, __d_result2) \
mu0_scope_begin                                                                                     \
	_RealFp          __mu9_arithmetic_mean4__mi__ = mu0_const_cast(_RealFp, 0);                      \
	_RealFp          __mu9_arithmetic_mean4__mj__ = mu0_const_cast(_RealFp, 0);                      \
	mu0_difference_t __mu9_arithmetic_mean4__c__  = mu0_difference(1);                               \
	while (__first1 != __last1) {                                                                    \
		__mu9_arithmetic_mean4__mi__ = __mu9_arithmetic_mean4__mi__                                   \
			+ ((*__first1 - __mu9_arithmetic_mean4__mi__) / __mu9_arithmetic_mean4__c__);              \
		__mu9_arithmetic_mean4__mj__ = __mu9_arithmetic_mean4__mj__                                   \
			+ ((*__first2 - __mu9_arithmetic_mean4__mj__) / __mu9_arithmetic_mean4__c__);              \
		++__mu9_arithmetic_mean4__c__;                                                                \
		++__first1;                                                                                   \
		++__first2;                                                                                   \
	}                                                                                                \
	__d_result1 = __mu9_arithmetic_mean4__mi__;                                                      \
	__d_result2 = __mu9_arithmetic_mean4__mj__;                                                      \
mu0_scope_end

#	define mu9_arithmetic_mean5(_Tp, _RealFp, __first1, __last1, __first2, __first3, __d_result1, __d_result2, __d_result3) \
mu0_scope_begin                                                                                                            \
	_RealFp          __mu9_arithmetic_mean5__mi__ = mu0_const_cast(_RealFp, 0);                                             \
	_RealFp          __mu9_arithmetic_mean5__mj__ = mu0_const_cast(_RealFp, 0);                                             \
	_RealFp          __mu9_arithmetic_mean5__mk__ = mu0_const_cast(_RealFp, 0);                                             \
	mu0_difference_t __mu9_arithmetic_mean5__c__  = mu0_difference(1);                                                      \
	while (__first1 != __last1) {                                                                                           \
		__mu9_arithmetic_mean5__mi__ = __mu9_arithmetic_mean5__mi__                                                          \
			+ ((*__first1 - __mu9_arithmetic_mean5__mi__) / __mu9_arithmetic_mean5__c__);                                     \
		__mu9_arithmetic_mean5__mj__ = __mu9_arithmetic_mean5__mj__                                                          \
			+ ((*__first2 - __mu9_arithmetic_mean5__mj__) / __mu9_arithmetic_mean5__c__);                                     \
		__mu9_arithmetic_mean5__mk__ = __mu9_arithmetic_mean5__mk__                                                          \
			+ ((*__first3 - __mu9_arithmetic_mean5__mk__) / __mu9_arithmetic_mean5__c__);                                     \
		++__mu9_arithmetic_mean5__c__;                                                                                       \
		++__first1;                                                                                                          \
		++__first2;                                                                                                          \
		++__first3;                                                                                                          \
	}                                                                                                                       \
	__d_result1 = __mu9_arithmetic_mean5__mi__;                                                                             \
	__d_result2 = __mu9_arithmetic_mean5__mj__;                                                                             \
	__d_result3 = __mu9_arithmetic_mean5__mk__;                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ARITHMETIC_MEAN_H */

/* EOF */