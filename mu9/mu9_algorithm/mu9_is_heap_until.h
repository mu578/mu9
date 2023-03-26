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

// mu9_is_heap_until.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_IS_HEAP_UNTIL_H
#define MU9_IS_HEAP_UNTIL_H 1

MU0_BEGIN_CDECL

#	define mu9_is_heap_until1(_Tp, __first, __last, __d_result)                                               \
mu0_scope_begin                                                                                              \
	mu0_bool_t     __mu9_is_heap_until1__x__ = mu0_false;                                                     \
	mu0_distance_t __mu9_is_heap_until1__l__ = mu9_distance(_Tp, __first, __last);                            \
	_Tp *          __mu9_is_heap_until1__i__;                                                                 \
	_Tp *          __mu9_is_heap_until1__q__ = __first;                                                       \
	mu0_distance_t __mu9_is_heap_until1__j__ = mu0_const_distance(0);                                         \
	mu0_distance_t __mu9_is_heap_until1__c__ = mu0_const_distance(1);                                         \
	while (__mu9_is_heap_until1__c__ < __mu9_is_heap_until1__l__) {                                           \
		__mu9_is_heap_until1__i__ = __first + __mu9_is_heap_until1__c__;                                       \
		if (*__mu9_is_heap_until1__q__ < *__mu9_is_heap_until1__i__) {                                         \
			__d_result                = __mu9_is_heap_until1__i__;                                              \
			__mu9_is_heap_until1__x__ = mu0_true;                                                               \
			break;                                                                                              \
		}                                                                                                      \
		++__mu9_is_heap_until1__c__;                                                                           \
		++__mu9_is_heap_until1__i__;                                                                           \
		if (__mu9_is_heap_until1__c__ == __mu9_is_heap_until1__l__) {                                          \
			__d_result                = __last;                                                                 \
			__mu9_is_heap_until1__x__ = mu0_true;                                                               \
			break;                                                                                              \
		}                                                                                                      \
		if (*__mu9_is_heap_until1__q__ < *__mu9_is_heap_until1__i__) {                                         \
			__d_result                = __mu9_is_heap_until1__i__;                                              \
			__mu9_is_heap_until1__x__ = mu0_true;                                                               \
			break;                                                                                              \
		}                                                                                                      \
		++__mu9_is_heap_until1__j__;                                                                           \
		++__mu9_is_heap_until1__q__;                                                                           \
		__mu9_is_heap_until1__c__ = mu0_const_distance(2) * __mu9_is_heap_until1__j__ + mu0_const_distance(1); \
	}                                                                                                         \
	if (!__mu9_is_heap_until1__x__) {                                                                         \
		__d_result = __last;                                                                                   \
	}                                                                                                         \
mu0_scope_end

#	define mu9_is_heap_until2(_Tp, __first, __last, __comp_fn, __d_result)                                    \
mu0_scope_begin                                                                                              \
	mu0_bool_t     __mu9_is_heap_until2__x__ = mu0_false;                                                     \
	mu0_distance_t __mu9_is_heap_until2__l__ = mu9_distance(_Tp, __first, __last);                            \
	_Tp *          __mu9_is_heap_until2__i__;                                                                 \
	_Tp *          __mu9_is_heap_until2__q__ = __first;                                                       \
	mu0_distance_t __mu9_is_heap_until2__j__ = mu0_const_distance(0);                                         \
	mu0_distance_t __mu9_is_heap_until2__c__ = mu0_const_distance(1);                                         \
	while (__mu9_is_heap_until2__c__ < __mu9_is_heap_until2__l__) {                                           \
		__mu9_is_heap_until2__i__ = __first + __mu9_is_heap_until2__c__;                                       \
		if (__comp_fn(_Tp, *__mu9_is_heap_until2__q__, *__mu9_is_heap_until2__i__)) {                          \
			__d_result                = __mu9_is_heap_until2__i__;                                              \
			__mu9_is_heap_until2__x__ = mu0_true;                                                               \
			break;                                                                                              \
		}                                                                                                      \
		++__mu9_is_heap_until2__c__;                                                                           \
		++__mu9_is_heap_until2__i__;                                                                           \
		if (__mu9_is_heap_until2__c__ == __mu9_is_heap_until2__l__) {                                          \
			__d_result                = __last;                                                                 \
			__mu9_is_heap_until2__x__ = mu0_true;                                                               \
			break;                                                                                              \
		}                                                                                                      \
		if (__comp_fn(_Tp, *__mu9_is_heap_until2__q__, *__mu9_is_heap_until2__i__)) {                          \
			__d_result                = __mu9_is_heap_until2__i__;                                              \
			__mu9_is_heap_until2__x__ = mu0_true;                                                               \
			break;                                                                                              \
		}                                                                                                      \
		++__mu9_is_heap_until2__j__;                                                                           \
		++__mu9_is_heap_until2__q__;                                                                           \
		__mu9_is_heap_until2__c__ = mu0_const_distance(2) * __mu9_is_heap_until2__j__ + mu0_const_distance(1); \
	}                                                                                                         \
	if (!__mu9_is_heap_until2__x__) {                                                                         \
		__d_result = __last;                                                                                   \
	}                                                                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_IS_HEAP_UNTIL_H */

/* EOF */