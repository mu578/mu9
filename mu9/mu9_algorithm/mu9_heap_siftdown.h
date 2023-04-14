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

// mu9_heap_siftdown.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_HEAP_SIFTDOWN_H
#define MU9_HEAP_SIFTDOWN_H 1

MU0_BEGIN_CDECL

#	define mu9_heap_siftdown1(_Tp, __first, __last, __len, __start, __comp_fn)                                        \
mu0_scope_begin                                                                                                      \
	      _Tp *          __mu9_heap_siftdown1__i__;                                                                   \
	      _Tp            __mu9_heap_siftdown1__v__;                                                                   \
	      mu0_distance_t __mu9_heap_siftdown1__c__ = mu9_const_distance(_Tp, __first, __start);                       \
	const mu0_distance_t __mu9_heap_siftdown1__l__ = mu0_const_distance(__len);                                       \
	      mu0_distance_t __mu9_heap_siftdown1__d__;                                                                   \
	if (!(__mu9_heap_siftdown1__l__ < 2 || (__mu9_heap_siftdown1__l__ - 2) / 2 < __mu9_heap_siftdown1__c__)) {        \
		__mu9_heap_siftdown1__c__ = mu0_const_distance(2) * __mu9_heap_siftdown1__c__ + mu0_const_distance(1);         \
		__mu9_heap_siftdown1__i__ = mu9_next_n(_Tp, __first, __mu9_heap_siftdown1__c__);                               \
		if ((__mu9_heap_siftdown1__c__ + 1) < __mu9_heap_siftdown1__l__ && __comp_fn(_Tp                               \
			, *(__mu9_heap_siftdown1__i__)                                                                              \
			, *(__mu9_heap_siftdown1__i__ + mu0_const_distance(1))                                                      \
		)) { ++__mu9_heap_siftdown1__i__; ++__mu9_heap_siftdown1__c__; }                                               \
		if (!__comp_fn(_Tp, *__mu9_heap_siftdown1__i__, *__start)) {                                                   \
			__mu9_heap_siftdown1__v__ = *__start;                                                                       \
			do {                                                                                                        \
				*__start                  = *__mu9_heap_siftdown1__i__;                                                  \
				__start                   =  __mu9_heap_siftdown1__i__;                                                  \
				__mu9_heap_siftdown1__d__ = (__mu9_heap_siftdown1__l__ - mu0_const_distance(2)) / mu0_const_distance(2); \
				if (__mu9_heap_siftdown1__d__ < __mu9_heap_siftdown1__c__) {                                             \
					break;                                                                                                \
				}                                                                                                        \
				__mu9_heap_siftdown1__c__ = mu0_const_distance(2) * __mu9_heap_siftdown1__c__ + 1;                       \
				__mu9_heap_siftdown1__i__ = mu9_next_n(_Tp, __first, __mu9_heap_siftdown1__c__);                         \
				if ((__mu9_heap_siftdown1__c__ + mu0_const_distance(1)) < __mu9_heap_siftdown1__l__ && __comp_fn(_Tp     \
					, *(__mu9_heap_siftdown1__i__)                                                                        \
					, *(__mu9_heap_siftdown1__i__ + mu0_const_distance(1))                                                \
				)) { ++__mu9_heap_siftdown1__i__; ++__mu9_heap_siftdown1__c__; }                                         \
			} while (!__comp_fn(_Tp, *__mu9_heap_siftdown1__i__, __mu9_heap_siftdown1__v__));                           \
			*__start                  = __mu9_heap_siftdown1__v__;                                                      \
		}                                                                                                              \
	}                                                                                                                 \
mu0_scope_end

#	define mu9_heap_siftdown2(_Tp, __first, __last, __len, __start, __comp_fn, __move_op)                             \
mu0_scope_begin                                                                                                      \
	_Tp *                __mu9_heap_siftdown2__i__;                                                                   \
	_Tp                  __mu9_heap_siftdown2__v__;                                                                   \
	      mu0_distance_t __mu9_heap_siftdown2__c__ = mu9_const_distance(_Tp, __first, __start);                       \
	const mu0_distance_t __mu9_heap_siftdown2__l__ = mu0_const_distance(__len);                                       \
	      mu0_distance_t __mu9_heap_siftdown2__d__;                                                                   \
	if (!(__mu9_heap_siftdown2__l__ < 2 || (__mu9_heap_siftdown2__l__ - 2) / 2 < __mu9_heap_siftdown2__c__)) {        \
		__mu9_heap_siftdown2__c__ = mu0_const_distance(2) * __mu9_heap_siftdown2__c__ + mu0_const_distance(1);         \
		__mu9_heap_siftdown2__i__ = mu9_next_n(_Tp, __first, __mu9_heap_siftdown2__c__);                               \
		if ((__mu9_heap_siftdown2__c__ + 1) < __mu9_heap_siftdown2__l__ && __comp_fn(_Tp                               \
			, *(__mu9_heap_siftdown2__i__)                                                                              \
			, *(__mu9_heap_siftdown2__i__ + mu0_const_distance(1))                                                      \
		)) { ++__mu9_heap_siftdown2__i__; ++__mu9_heap_siftdown2__c__; }                                               \
		if (!__comp_fn(_Tp, *__mu9_heap_siftdown2__i__, *__start)) {                                                   \
			__move_op(_Tp, __mu9_heap_siftdown2__v__, *__start);                                                        \
			do {                                                                                                        \
				__move_op(_Tp, *__start, *__mu9_heap_siftdown2__i__);                                                    \
				__start                   =  __mu9_heap_siftdown2__i__;                                                  \
				__mu9_heap_siftdown2__d__ = (__mu9_heap_siftdown2__l__ - mu0_const_distance(2)) / mu0_const_distance(2); \
				if (__mu9_heap_siftdown2__d__ < __mu9_heap_siftdown2__c__) {                                             \
					break;                                                                                                \
				}                                                                                                        \
				__mu9_heap_siftdown2__c__ = mu0_const_distance(2) * __mu9_heap_siftdown2__c__ + 1;                       \
				__mu9_heap_siftdown2__i__ = mu9_next_n(_Tp, __first + __mu9_heap_siftdown2__c__);                        \
				if ((__mu9_heap_siftdown2__c__ + mu0_const_distance(1)) < __mu9_heap_siftdown2__l__ && __comp_fn(_Tp     \
					, *(__mu9_heap_siftdown2__i__)                                                                        \
					, *(__mu9_heap_siftdown2__i__ + mu0_const_distance(1))                                                \
				)) { ++__mu9_heap_siftdown2__i__; ++__mu9_heap_siftdown2__c__; }                                         \
			} while (!__comp_fn(_Tp, *__mu9_heap_siftdown2__i__, __mu9_heap_siftdown2__v__));                           \
			__move_op(_Tp, *__start, __mu9_heap_siftdown2__v__);                                                        \
		}                                                                                                              \
	}                                                                                                                 \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_HEAP_SIFTDOWN_H */

/* EOF */