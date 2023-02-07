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

// mu9_count.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_COUNT_H
#define MU9_COUNT_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Dist<return> & __d_result) : void
//#!
#	define mu9_count(_Tp, __first,  __last, __value, __d_result) \
mu9_scope_begin                                                 \
	mu9_difference_t ___mu9_count__c__ = mu9_difference(0);      \
	for (; __first != __last; ++__first) {                       \
		if (*__first == __value) {                                \
			++___mu9_count__c__;                                   \
		}                                                         \
	}                                                            \
	__d_result = ___mu9_count__c__;                              \
mu9_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Dist<return> & __d_result) : void
//#!
#	define mu9_count_not(_Tp, __first,  __last, __value, __d_result) \
mu9_scope_begin                                                     \
	mu9_difference_t ___mu9_count_not__c__ = mu9_difference(0);      \
	for (; __first != __last; ++__first) {                           \
		if (*__first != __value) {                                    \
			++___mu9_count_not__c__;                                   \
		}                                                             \
	}                                                                \
	__d_result = ___mu9_count_not__c__;                              \
mu9_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, __unary_pred, _Dist<return> & __d_result) : void
//#!
#	define mu9_count_if(_Tp, __first,  __last, __unary_pred, __d_result) \
mu9_scope_begin                                                         \
	mu9_difference_t ___mu9_count_if__c__ = mu9_difference(0);           \
	for (; __first != __last; ++__first) {                               \
		if (__unary_pred(*__first)) {                                     \
			++___mu9_count_if__c__;                                        \
		}                                                                 \
	}                                                                    \
	__d_result = ___mu9_count_if__c__;                                   \
mu9_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, __unary_pred, _Dist<return> & __d_result) : void
//#!
#	define mu9_count_if_not(_Tp, __first,  __last, __unary_pred, __d_result) \
mu9_scope_begin                                                             \
	mu9_difference_t ___mu9_count_if_not__c__ = mu9_difference(0);           \
	for (; __first != __last; ++__first) {                                   \
		if (!__unary_pred(*__first)) {                                        \
			++___mu9_count_if_not__c__;                                        \
		}                                                                     \
	}                                                                        \
	__d_result = ___mu9_count_if_not__c__;                                   \
mu9_scope_end

MU9_END_CDECL


#	define ___mu8_math_bootstrap__(_Tp, fn)
	___mu8_ ## fn  ## _ ## _Tp  ## ___

#	define ___mu8_math_bootstrap__(mu8_fp64_t, abs) mu8_absfp64
#	define ___mu8_math_bootstrap__(mu8_fp32_t, abs) mu8_absfp32
#	define ___mu8_math_bootstrap__(mu8_fp16_t, abs) mu8_absfp16

#	define mu8_absfp(_Tp, x) \
	___mu8_math_bootstrap__(_Tp, abs)(x)


#endif /* !MU9_COUNT_H */

/* EOF */