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

// mu9_random_sample_n.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>
#include <mu0/mu0_random.h>

#ifndef MU9_RANDOM_SAMPLE_N_H
#define MU9_RANDOM_SAMPLE_N_H 1

MU0_BEGIN_CDECL

#	define mu9_random_sample_n1(_Tp, __first, __last, __d_first, __n, __d_result)                                         \
mu0_scope_begin                                                                                                          \
	const mu0_distance_t __mu9_random_sample_n1__n__ = mu0_const_distance(__n);                                           \
	      mu0_distance_t __mu9_random_sample_n1__q__ = mu9_distance(_Tp, __first, __last);                                \
	      mu0_distance_t __mu9_random_sample_n1__k__ = mu0_min(__mu9_random_sample_n1__n__, __mu9_random_sample_n1__q__); \
 	while (__mu9_random_sample_n1__k__ > mu0_const_distance(0)) {                                                         \
		if ((mu0_const_distance(mu0_random_i64() % __mu9_random_sample_n1__q__)) < __mu9_random_sample_n1__k__) {          \
			*__d_first = *__first;                                                                                          \
			++__d_first;                                                                                                    \
			--__mu9_random_sample_n1__k__;                                                                                  \
		}                                                                                                                  \
		--__mu9_random_sample_n1__q__;                                                                                     \
		++__first;                                                                                                         \
	}                                                                                                                     \
	__d_result = mu9_next_n(_Tp, __d_first, __mu9_random_sample_n1__k__);                                                 \
mu0_scope_end

#	define mu9_random_sample_n2(_Tp, __first, __last, __d_first, __n, __rand_fn, __d_result)                              \
mu0_scope_begin                                                                                                          \
	const mu0_distance_t __mu9_random_sample_n2__n__ = mu0_const_distance(__n);                                           \
	      mu0_distance_t __mu9_random_sample_n2__q__ = mu9_distance(_Tp, __first, __last);                                \
	      mu0_distance_t __mu9_random_sample_n2__k__ = mu0_min(__mu9_random_sample_n2__n__, __mu9_random_sample_n2__q__); \
 	while (__mu9_random_sample_n2__k__ > mu0_const_distance(0)) {                                                         \
		if ((mu0_const_distance(__rand_fn() % __mu9_random_sample_n2__q__)) < __mu9_random_sample_n2__k__) {               \
			*__d_first = *__first;                                                                                          \
			++__d_first;                                                                                                    \
			--__mu9_random_sample_n2__k__;                                                                                  \
		}                                                                                                                  \
		--__mu9_random_sample_n2__q__;                                                                                     \
		++__first;                                                                                                         \
	}                                                                                                                     \
	__d_result = mu9_next_n(_Tp, __d_first, __mu9_random_sample_n2__k__);                                                 \
mu0_scope_end

#	define mu9_random_sample_n3(_Tp, __first, __last, __d_first, __n, __move_op, __d_result)                              \
mu0_scope_begin                                                                                                          \
	const mu0_distance_t __mu9_random_sample_n3__n__ = mu0_const_distance(__n);                                           \
	      mu0_distance_t __mu9_random_sample_n3__q__ = mu9_distance(_Tp, __first, __last);                                \
	      mu0_distance_t __mu9_random_sample_n3__k__ = mu0_min(__mu9_random_sample_n3__n__, __mu9_random_sample_n3__q__); \
 	while (__mu9_random_sample_n3__k__ > mu0_const_distance(0)) {                                                         \
		if ((mu0_const_distance(mu0_random_i64() % __mu9_random_sample_n3__q__)) < __mu9_random_sample_n3__k__) {          \
			__move_op(_Tp, *__d_first, *__first);                                                                           \
			++__d_first;                                                                                                    \
			--__mu9_random_sample_n3__k__;                                                                                  \
		}                                                                                                                  \
		--__mu9_random_sample_n3__q__;                                                                                     \
		++__first;                                                                                                         \
	}                                                                                                                     \
	__d_result = mu9_next_n(_Tp, __d_first, __mu9_random_sample_n3__k__);                                                 \
mu0_scope_end

#	define mu9_random_sample_n4(_Tp, __first, __last, __d_first, __n, __rand_fn, __move_op, __d_result)                   \
mu0_scope_begin                                                                                                          \
	const mu0_distance_t __mu9_random_sample_n4__n__ = mu0_const_distance(__n);                                           \
	      mu0_distance_t __mu9_random_sample_n4__q__ = mu9_distance(_Tp, __first, __last);                                \
	      mu0_distance_t __mu9_random_sample_n4__k__ = mu0_min(__mu9_random_sample_n4__n__, __mu9_random_sample_n4__q__); \
 	while (__mu9_random_sample_n4__k__ > mu0_const_distance(0)) {                                                         \
		if ((mu0_const_distance(__rand_fn() % __mu9_random_sample_n4__q__)) < __mu9_random_sample_n4__k__) {               \
			__move_op(_Tp, *__d_first, *__first);                                                                           \
			++__d_first;                                                                                                    \
			--__mu9_random_sample_n4__k__;                                                                                  \
		}                                                                                                                  \
		--__mu9_random_sample_n4__q__;                                                                                     \
		++__first;                                                                                                         \
	}                                                                                                                     \
	__d_result = mu9_next_n(_Tp, __d_first, __mu9_random_sample_n4__k__);                                                 \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_RANDOM_SAMPLE_N_H */

/* EOF */