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

// mu9_heap_siftup.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_HEAP_SIFTUP_H
#define MU9_HEAP_SIFTUP_H 1

MU0_BEGIN_CDECL

#	define mu9_heap_siftup1(_Tp, __first, __last, __len, __comp_fn)                                               \
mu0_scope_begin                                                                                                  \
	_Tp *          __mu9_heap_siftup1__i__;                                                                       \
	_Tp            __mu9_heap_siftup1__v__;                                                                       \
	mu0_distance_t __mu9_heap_siftup1__c__ = mu0_const_distance(__len);                                           \
	if (__mu9_heap_siftup1__c__ > mu0_const_distance(1)) {                                                        \
		__mu9_heap_siftup1__c__ = (__mu9_heap_siftup1__c__ - mu0_const_distance(2)) / mu0_const_distance(2);       \
		__mu9_heap_siftup1__i__ = mu9_next_n(__first, __mu9_heap_siftup1__c__);                                    \
		if (__comp_fn(_Tp, *__mu9_heap_siftup1__i__, *--__last)) {                                                 \
			__mu9_heap_siftup1__v__ = *__last;                                                                      \
			do {                                                                                                    \
				*__last                 = *__mu9_heap_siftup1__i__;                                                  \
				__last                  = __mu9_heap_siftup1__i__;                                                   \
				if (__mu9_heap_siftup1__c__ == mu0_const_distance(0)) {                                              \
					break;                                                                                            \
				}                                                                                                    \
				__mu9_heap_siftup1__c__ = (__mu9_heap_siftup1__c__ - mu0_const_distance(1)) / mu0_const_distance(2); \
				__mu9_heap_siftup1__i__ = mu9_next_n(__first, __mu9_heap_siftup1__c__);                              \
			} while (__comp_fn(_Tp, *__mu9_heap_siftup1__i__, __mu9_heap_siftup1__v__));                            \
			*__last = __mu9_heap_siftup1__v__;                                                                      \
		}                                                                                                          \
	}                                                                                                             \
mu0_scope_end

#	define mu9_heap_siftup2(_Tp, __first, __last, __len, __comp_fn, __move_op)                                    \
mu0_scope_begin                                                                                                  \
	_Tp *          __mu9_heap_siftup2__i__;                                                                       \
	_Tp            __mu9_heap_siftup2__v__;                                                                       \
	mu0_distance_t __mu9_heap_siftup2__c__ = mu0_const_distance(__len);                                           \
	if (__mu9_heap_siftup2__c__ > mu0_const_distance(1)) {                                                        \
		__mu9_heap_siftup2__c__ = (__mu9_heap_siftup2__c__ - mu0_const_distance(2)) / mu0_const_distance(2);       \
		__mu9_heap_siftup2__i__ = mu9_next_n(__first, __mu9_heap_siftup2__c__);                                    \
		if (__comp_fn(_Tp, *__mu9_heap_siftup2__i__, *--__last)) {                                                 \
			__move_op(_Tp, __mu9_heap_siftup2__v__, *__last);                                                       \
			do {                                                                                                    \
				__move_op(_Tp, *__last, *__mu9_heap_siftup2__i__);                                                   \
				__last                  = __mu9_heap_siftup2__i__;                                                   \
				if (__mu9_heap_siftup2__c__ == mu0_const_distance(0)) {                                              \
					break;                                                                                            \
				}                                                                                                    \
				__mu9_heap_siftup2__c__ = (__mu9_heap_siftup2__c__ - mu0_const_distance(1)) / mu0_const_distance(2); \
				__mu9_heap_siftup2__i__ = mu9_next_n(__first, __mu9_heap_siftup2__c__);                              \
			} while (__comp_fn(_Tp, *__mu9_heap_siftup2__i__, __mu9_heap_siftup2__v__));                            \
			__move_op(_Tp, *__last, __mu9_heap_siftup2__v__);                                                       \
		}                                                                                                          \
	}                                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_HEAP_SIFTUP_H */

/* EOF */