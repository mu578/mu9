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

// mu9_lower_bound.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_LOWER_BOUND_H
#define MU9_LOWER_BOUND_H 1

MU0_BEGIN_CDECL

#	define mu9_lower_bound1(_Tp, __first, __last, __value, __d_result)                   \
mu0_scope_begin                                                                         \
	_Tp * __mu9_lower_bound1__i__;                                                       \
	mu0_distance_t __mu9_lower_bound1__c__= mu9_distance(_Tp, __first, __last);          \
	mu0_distance_t __mu9_lower_bound1__n__;                                              \
	while (__mu9_lower_bound1__c__ > mu0_const_distance(0)) {                            \
		__mu9_lower_bound1__i__ = __first;                                                \
		__mu9_lower_bound1__n__ = __mu9_lower_bound1__c__ / mu0_const_distance(2);        \
		mu9_advance_n(_Tp, __mu9_lower_bound1__i__, __mu9_lower_bound1__n__);             \
		if (*__mu9_lower_bound1__i__ < __value) {                                         \
				__first                  = ++__mu9_lower_bound1__i__;                       \
				__mu9_lower_bound1__c__ -= __mu9_lower_bound1__n__ + mu0_const_distance(1); \
		} else {                                                                          \
				__mu9_lower_bound1__c__  = __mu9_lower_bound1__n__;                         \
		}                                                                                 \
	}                                                                                    \
	__d_result = __first;                                                                \
mu0_scope_end

#	define mu9_lower_bound2(_Tp, __first, __last, __value, __comp_fn, __d_result)        \
mu0_scope_begin                                                                         \
	_Tp * __mu9_lower_bound2__i__;                                                       \
	mu0_distance_t __mu9_lower_bound2__c__= mu9_distance(_Tp, __first, __last);          \
	mu0_distance_t __mu9_lower_bound2__n__;                                              \
	while (__mu9_lower_bound2__c__ > mu0_const_distance(0)) {                            \
		__mu9_lower_bound2__i__ = __first;                                                \
		__mu9_lower_bound2__n__ = __mu9_lower_bound2__c__ / mu0_const_distance(2);        \
		mu9_advance_n(_Tp, __mu9_lower_bound2__i__, __mu9_lower_bound2__n__);             \
		if (__comp_fn(*__mu9_lower_bound2__i__, __value)) {                               \
				__first                  = ++__mu9_lower_bound2__i__;                       \
				__mu9_lower_bound2__c__ -= __mu9_lower_bound2__n__ + mu0_const_distance(1); \
		} else {                                                                          \
				__mu9_lower_bound2__c__  = __mu9_lower_bound2__n__;                         \
		}                                                                                 \
	}                                                                                    \
	__d_result = __first;                                                                \
mu0_scope_end

#	define mu9_lower_bound3(_Tp, __first, __last, __value, __comp_op, __d_result)        \
mu0_scope_begin                                                                         \
	_Tp * __mu9_lower_bound3__i__;                                                       \
	mu0_distance_t __mu9_lower_bound3__c__= mu9_distance(_Tp, __first, __last);          \
	mu0_distance_t __mu9_lower_bound3__n__;                                              \
	while (__mu9_lower_bound3__c__ > mu0_const_distance(0)) {                            \
		__mu9_lower_bound3__i__ = __first;                                                \
		__mu9_lower_bound3__n__ = __mu9_lower_bound3__c__ / mu0_const_distance(2);        \
		mu9_advance_n(_Tp, __mu9_lower_bound3__i__, __mu9_lower_bound3__n__);             \
		if (__comp_op(_Tp, *__mu9_lower_bound3__i__, __value)) {                          \
				__first                  = ++__mu9_lower_bound3__i__;                       \
				__mu9_lower_bound3__c__ -= __mu9_lower_bound3__n__ + mu0_const_distance(1); \
		} else {                                                                          \
				__mu9_lower_bound3__c__  = __mu9_lower_bound3__n__;                         \
		}                                                                                 \
	}                                                                                    \
	__d_result = __first;                                                                \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_LOWER_BOUND_H */

/* EOF */