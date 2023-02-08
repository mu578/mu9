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

#include <mu0/mu0_integer.h>

#ifndef MU9_COUNT_H
#define MU9_COUNT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Dist<return> & __d_result) : void
//#!
#	define mu9_count(_Tp, __first,  __last, __value, __d_result) \
mu9_scope_begin                                                 \
	mu0_difference_t __mu9_count__c__ = mu0_difference(0);       \
	for (; __first != __last; ++__first) {                       \
		if (*__first == __value) {                                \
			++__mu9_count__c__;                                    \
		}                                                         \
	}                                                            \
	__d_result = __mu9_count__c__;                               \
mu9_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Dist<return> & __d_result) : void
//#!
#	define mu9_count_not(_Tp, __first,  __last, __value, __d_result) \
mu9_scope_begin                                                     \
	mu0_difference_t __mu9_count_not__c__ = mu0_difference(0);       \
	for (; __first != __last; ++__first) {                           \
		if (*__first != __value) {                                    \
			++__mu9_count_not__c__;                                    \
		}                                                             \
	}                                                                \
	__d_result = __mu9_count_not__c__;                               \
mu9_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, __unary_pred, _Dist<return> & __d_result) : void
//#!
#	define mu9_count_if(_Tp, __first,  __last, __unary_pred, __d_result) \
mu9_scope_begin                                                         \
	mu0_difference_t __mu9_count_if__c__ = mu0_difference(0);            \
	for (; __first != __last; ++__first) {                               \
		if (__unary_pred(*__first)) {                                     \
			++__mu9_count_if__c__;                                         \
		}                                                                 \
	}                                                                    \
	__d_result = __mu9_count_if__c__;                                    \
mu9_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __first, _Tp &* __last, __unary_pred, _Dist<return> & __d_result) : void
//#!
#	define mu9_count_if_not(_Tp, __first,  __last, __unary_pred, __d_result) \
mu9_scope_begin                                                             \
	mu0_difference_t __mu9_count_if_not__c__ = mu0_difference(0);            \
	for (; __first != __last; ++__first) {                                   \
		if (!__unary_pred(*__first)) {                                        \
			++__mu9_count_if_not__c__;                                         \
		}                                                                     \
	}                                                                        \
	__d_result = __mu9_count_if_not__c__;                                    \
mu9_scope_end

MU0_END_CDECL

#endif /* !MU9_COUNT_H */

/* EOF */