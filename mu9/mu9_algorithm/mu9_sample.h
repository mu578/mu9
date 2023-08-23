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

// mu9_sample.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>
#include <mu0/mu0_random.h>

#ifndef MU9_SAMPLE_H
#define MU9_SAMPLE_H 1

MU0_BEGIN_CDECL

#	define mu9_sample1(_Tp, __first, __last, __d_first, __n)                                    \
mu0_scope_begin                                                                                \
	mu0_distance_t __mu9_sample1__k__ = mu9_const_distance(_Tp, __first, __last);               \
	mu0_distance_t __mu9_sample1__i__ = mu0_min(mu0_const_distance(__n), __mu9_sample1__k__);   \
	mu0_distance_t __mu9_sample1__d__;                                                          \
	for (; __mu9_sample1__i__ != mu0_const_distance(0); ++__first) {                            \
		__mu9_sample1__d__ = mu0_const_distance(mu0_random_ranged_i64(0, --__mu9_sample1__k__)); \
		if (__mu9_sample1__d__ < __mu9_sample1__i__) {                                           \
			*__d_first++ = *__first;                                                              \
			--__mu9_sample1__i__;                                                                 \
		}                                                                                        \
	}                                                                                           \
mu0_scope_end

#	define mu9_sample2(_Tp, __first, __last, __d_first, __n, __urbg_fn)                       \
mu0_scope_begin                                                                              \
	mu0_distance_t __mu9_sample2__k__ = mu9_const_distance(_Tp, __first, __last);             \
	mu0_distance_t __mu9_sample2__i__ = mu0_min(mu0_const_distance(__n), __mu9_sample2__k__); \
	mu0_distance_t __mu9_sample2__d__;                                                        \
	for (; __mu9_sample2__i__ != mu0_const_distance(0); ++__first) {                          \
		__mu9_sample2__d__ = mu0_const_distance(__urbg_fn(0, --__mu9_sample2__k__));           \
		if (__mu9_sample2__d__ < __mu9_sample2__i__) {                                         \
			*__d_first++ = *__first;                                                            \
			--__mu9_sample2__i__;                                                               \
		}                                                                                      \
	}                                                                                         \
mu0_scope_end

#	define mu9_sample3(_Tp, __first, __last, __d_first, __n, __move_op)                         \
mu0_scope_begin                                                                                \
	mu0_distance_t __mu9_sample3__k__ = mu9_const_distance(_Tp, __first, __last);               \
	mu0_distance_t __mu9_sample3__i__ = mu0_min(mu0_const_distance(__n), __mu9_sample3__k__);   \
	mu0_distance_t __mu9_sample3__d__;                                                          \
	for (; __mu9_sample3__i__ != mu0_const_distance(0); ++__first) {                            \
		__mu9_sample3__d__ = mu0_const_distance(mu0_random_ranged_i64(0, --__mu9_sample3__k__)); \
		if (__mu9_sample3__d__ < __mu9_sample3__i__) {                                           \
			__move_op(_Tp, *__d_first++, *__first);                                               \
			--__mu9_sample3__i__;                                                                 \
		}                                                                                        \
	}                                                                                           \
mu0_scope_end

#	define mu9_sample4(_Tp, __first, __last, __d_first, __n, __urbg_fn, __move_op)            \
mu0_scope_begin                                                                              \
	mu0_distance_t __mu9_sample4__k__ = mu9_const_distance(_Tp, __first, __last);             \
	mu0_distance_t __mu9_sample4__i__ = mu0_min(mu0_const_distance(__n), __mu9_sample4__k__); \
	mu0_distance_t __mu9_sample4__d__;                                                        \
	for (; __mu9_sample4__i__ != mu0_const_distance(0); ++__first) {                          \
		__mu9_sample4__d__ = mu0_const_distance(__urbg_fn(0, --__mu9_sample4__k__));           \
		if (__mu9_sample4__d__ < __mu9_sample4__i__) {                                         \
			__move_op(_Tp, *__d_first++, *__first);                                             \
			--__mu9_sample4__i__;                                                               \
		}                                                                                      \
	}                                                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SAMPLE_H */

/* EOF */