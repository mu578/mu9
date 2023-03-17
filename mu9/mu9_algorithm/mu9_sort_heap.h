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

// mu9_sort_heap.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_functional.h>
#include <mu9/mu9_algorithm/mu9_heap_siftdown.h>

#ifndef MU9_SORT_HEAP_H
#define MU9_SORT_HEAP_H 1

MU0_BEGIN_CDECL

#	define mu9_sort_heap1(_Tp, __first, __last)                                                                                                                 \
mu0_scope_begin                                                                                                                                                \
	mu0_distance_t __mu9_sort_heap1__l__ = mu9_distance(_Tp, __first, __last);                                                                                  \
	_Tp *          __mu9_sort_heap1__i__;                                                                                                                       \
	_Tp *          __mu9_sort_heap1__j__ = __first;                                                                                                             \
	_Tp *          __mu9_sort_heap1__k__ = __last;                                                                                                              \
	for (; __mu9_sort_heap1__l__ > mu0_const_distance(1); --__mu9_sort_heap1__k__, --__mu9_sort_heap1__l__) {                                                   \
		mu9_iter_swap(_Tp, __mu9_sort_heap1__j__, mu9_prev(_Tp, __mu9_sort_heap1__k__));                                                                         \
		__mu9_sort_heap1__i__ = __mu9_sort_heap1__j__;                                                                                                           \
		mu9_heap_siftdown1(_Tp, __mu9_sort_heap1__j__, __mu9_sort_heap1__k__, (__mu9_sort_heap1__l__ - mu0_const_distance(1)), __mu9_sort_heap1__i__, mu9_less); \
	}                                                                                                                                                           \
mu0_scope_end

#	define mu9_sort_heap2(_Tp, __first, __last, __comp_fn)                                                                                                       \
mu0_scope_begin                                                                                                                                                 \
	mu0_distance_t __mu9_sort_heap2__l__ = mu9_distance(_Tp, __first, __last);                                                                                   \
	_Tp *          __mu9_sort_heap2__i__;                                                                                                                        \
	_Tp *          __mu9_sort_heap2__j__ = __first;                                                                                                              \
	_Tp *          __mu9_sort_heap2__k__ = __last;                                                                                                               \
	for (; __mu9_sort_heap2__l__ > mu0_const_distance(1); --__mu9_sort_heap2__k__, --__mu9_sort_heap2__l__) {                                                    \
		mu9_iter_swap(_Tp, __mu9_sort_heap2__j__, mu9_prev(_Tp, __mu9_sort_heap2__k__));                                                                          \
		__mu9_sort_heap2__i__ = __mu9_sort_heap2__j__;                                                                                                            \
		mu9_heap_siftdown1(_Tp, __mu9_sort_heap2__j__, __mu9_sort_heap2__k__, (__mu9_sort_heap2__l__ - mu0_const_distance(1)), __mu9_sort_heap2__i__, __comp_fn); \
	}                                                                                                                                                            \
mu0_scope_end

#	define mu9_sort_heap3(_Tp, __first, __last, __comp_fn, __move_op)                                                                                                       \
mu0_scope_begin                                                                                                                                                            \
	mu0_distance_t __mu9_sort_heap3__l__ = mu9_distance(_Tp, __first, __last);                                                                                              \
	_Tp *          __mu9_sort_heap3__i__;                                                                                                                                   \
	_Tp *          __mu9_sort_heap3__j__ = __first;                                                                                                                         \
	_Tp *          __mu9_sort_heap3__k__ = __last;                                                                                                                          \
	for (; __mu9_sort_heap3__l__ > mu0_const_distance(1); --__mu9_sort_heap3__k__, --__mu9_sort_heap3__l__) {                                                               \
		mu9_iter_swap(_Tp, __mu9_sort_heap3__j__, mu9_prev(_Tp, __mu9_sort_heap3__k__));                                                                                     \
		__mu9_sort_heap3__i__ = __mu9_sort_heap3__j__;                                                                                                                       \
		mu9_heap_siftdown2(_Tp, __mu9_sort_heap3__j__, __mu9_sort_heap3__k__, (__mu9_sort_heap3__l__ - mu0_const_distance(1)), __mu9_sort_heap3__i__, __comp_fn, __move_op); \
	}                                                                                                                                                                       \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SORT_HEAP_H */

/* EOF */