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

// mu9_make_heap.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_functional.h>
#include <mu9/mu9_algorithm/mu9_heap_siftdown.h>

#ifndef MU9_MAKE_HEAP_H
#define MU9_MAKE_HEAP_H 1

MU0_BEGIN_CDECL

#	define mu9_make_heap1(_Tp, __first, __last)                                                                                       \
mu0_scope_begin                                                                                                                      \
	const mu0_distance_t __mu9_make_heap1__l__ = mu9_distance(_Tp, __first, __last);                                                  \
	      mu0_distance_t __mu9_make_heap1__i__ = (__mu9_make_heap1__l__ - mu0_const_distance(2)) / mu0_const_distance(2);             \
	if (__mu9_make_heap1__l__ > mu0_const_distance(1)) {                                                                              \
		for (; __mu9_make_heap1__i__ >= 0; --__mu9_make_heap1__i__) {                                                                  \
			mu9_heap_siftdown1(_Tp, __first, __last, __mu9_make_heap1__l__, mu9_next_n(_Tp, __first, __mu9_make_heap1__i__), mu9_less); \
		}                                                                                                                              \
	}                                                                                                                                 \
mu0_scope_end

#	define mu9_make_heap2(_Tp, __first, __last, __comp_fn)                                                                             \
mu0_scope_begin                                                                                                                       \
	const mu0_distance_t __mu9_make_heap2__l__ = mu9_distance(_Tp, __first, __last);                                                   \
	      mu0_distance_t __mu9_make_heap2__i__ = (__mu9_make_heap2__l__ - mu0_const_distance(2)) / mu0_const_distance(2);              \
	if (__mu9_make_heap2__l__ > mu0_const_distance(1)) {                                                                               \
		for (; __mu9_make_heap2__i__ >= 0; --__mu9_make_heap2__i__) {                                                                   \
			mu9_heap_siftdown1(_Tp, __first, __last, __mu9_make_heap2__l__, mu9_next_n(_Tp, __first, __mu9_make_heap2__i__), __comp_fn); \
		}                                                                                                                               \
	}                                                                                                                                  \
mu0_scope_end

#	define mu9_make_heap3(_Tp, __first, __last, __comp_fn, __move_op)                                                                             \
mu0_scope_begin                                                                                                                                  \
	const mu0_distance_t __mu9_make_heap3__l__ = mu9_distance(_Tp, __first, __last);                                                              \
	      mu0_distance_t __mu9_make_heap3__i__ = (__mu9_make_heap3__l__ - mu0_const_distance(2)) / mu0_const_distance(2);                         \
	if (__mu9_make_heap3__l__ > mu0_const_distance(1)) {                                                                                          \
		for (; __mu9_make_heap3__i__ >= 0; --__mu9_make_heap3__i__) {                                                                              \
			mu9_heap_siftdown2(_Tp, __first, __last, __mu9_make_heap3__l__, mu9_next_n(_Tp, __first, __mu9_make_heap3__i__), __comp_fn, __move_op); \
		}                                                                                                                                          \
	}                                                                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MAKE_HEAP_H */

/* EOF */