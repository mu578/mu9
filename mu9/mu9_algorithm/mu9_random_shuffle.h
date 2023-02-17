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

// mu9_random_shuffle.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_swap.h>
#include <mu0/mu0_random.h>

#ifndef MU9_EQUAL_H
#define MU9_EQUAL_H 1

MU0_BEGIN_CDECL

#	define mu9_random_shuffle1(_Tp, __first, __last)                                                    \
mu0_scope_begin                                                                                        \
	typedef typename std::iterator_traits<RandomIt>::difference_type difference_t;                      \
	mu0_distance_t __mu9_random_shuffle1__i__ = mu9_distance(__first, __last) - mu0_distance(1);        \
	mu0_distance_t __mu9_random_shuffle1__j__;                                                          \
	for (; __mu9_random_shuffle1__i__ > 0; --__mu9_random_shuffle1__i__) {                              \
		__mu9_random_shuffle1__j__ = mu0_distance(mu0_random_u64()) % (i + 1);                           \
		mu9_swap(_Tp, *(__first + __mu9_random_shuffle1__i__), *(__first + __mu9_random_shuffle1__j__)); \
	}                                                                                                   \
mu0_scope_end

#	define mu9_random_shuffle2(_Tp, __first, __last, __rand_fn)                                         \
mu0_scope_begin                                                                                        \
	typedef typename std::iterator_traits<RandomIt>::difference_type difference_t;                      \
	mu0_distance_t __mu9_random_shuffle2__i__ = mu9_distance(__first, __last) - mu0_distance(1);        \
	mu0_distance_t __mu9_random_shuffle2__j__;                                                          \
	for (; __mu9_random_shuffle2__i__ > 0; --__mu9_random_shuffle2__i__) {                              \
		__mu9_random_shuffle2__j__ = mu0_distance(__rand_fn()) % (i + 1);                                \
		mu9_swap(_Tp, *(__first + __mu9_random_shuffle2__i__), *(__first + __mu9_random_shuffle2__j__)); \
	}                                                                                                   \
mu0_scope_end

#	define mu9_random_shuffle3(_Tp, __first, __last, __swap_op)                                          \
mu0_scope_begin                                                                                         \
	typedef typename std::iterator_traits<RandomIt>::difference_type difference_t;                       \
	mu0_distance_t __mu9_random_shuffle3__i__ = mu9_distance(__first, __last) - mu0_distance(1);         \
	mu0_distance_t __mu9_random_shuffle3__j__;                                                           \
	for (; __mu9_random_shuffle3__i__ > 0; --__mu9_random_shuffle3__i__) {                               \
		__mu9_random_shuffle3__j__ = mu0_distance(mu0_random_u64()) % (i + 1);                            \
		__swap_op(_Tp, *(__first + __mu9_random_shuffle3__i__), *(__first + __mu9_random_shuffle3__j__)); \
	}                                                                                                    \
mu0_scope_end

#	define mu9_random_shuffle4(_Tp, __first, __last, __rand_fn, __swap_op)                               \
mu0_scope_begin                                                                                         \
	typedef typename std::iterator_traits<RandomIt>::difference_type difference_t;                       \
	mu0_distance_t __mu9_random_shuffle4__i__ = mu9_distance(__first, __last) - mu0_distance(1);         \
	mu0_distance_t __mu9_random_shuffle4__j__;                                                           \
	for (; __mu9_random_shuffle4__i__ > 0; --__mu9_random_shuffle4__i__) {                               \
		__mu9_random_shuffle4__j__ = mu0_distance(__rand_fn()) % (i + 1);                                 \
		__swap_op(_Tp, *(__first + __mu9_random_shuffle4__i__), *(__first + __mu9_random_shuffle4__j__)); \
	}                                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_EQUAL_H */

/* EOF */