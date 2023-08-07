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

// mu9_for_each_by.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_integer.h>

#ifndef MU9_FOR_EACH_BY_H
#define MU9_FOR_EACH_BY_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Uint & __by, __unary_fn) : void
//#!
#	define mu9_for_each_by(_Tp, __first, __last, __by, __unary_fn)                                 \
mu0_scope_begin                                                                                   \
	mu0_bool_t     __mu9_for_each_by__x__ = mu0_false;                                             \
	mu0_distance_t __mu9_for_each_by__j__;                                                         \
	mu0_distance_t __mu9_for_each_by__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)      \
		? mu0_const_distance(1)                                                                     \
		: mu0_const_distance(__by)                                                                  \
	);                                                                                             \
	while (__first != __last) {                                                                    \
		__unary_fn(Tp, *__first);                                                                   \
		__mu9_for_each_by__j__ = mu0_const_distance(0);                                             \
		for (; __mu9_for_each_by__j__ != __mu9_for_each_by__i__; (void) ++__mu9_for_each_by__j__) { \
			if (__first == __last) {                                                                 \
				__mu9_for_each_by__x__ = mu0_true;                                                    \
				break;                                                                                \
			}                                                                                        \
			++__first;                                                                               \
		}                                                                                           \
		if (__mu9_for_each_by__x__) {                                                               \
			break;                                                                                   \
		}                                                                                           \
	}                                                                                              \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, const _Uint & __by, const _Uint & __n, __unary_fn) : void
//#!
#	define mu9_for_each_by_n(_Tp, __first, __by, __n, __unary_fn)                                        \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_for_each_by_n__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_for_each_by_n__i__ = mu0_const_distance(0);                                     \
	mu0_distance_t __mu9_for_each_by_n__j__;                                                             \
	mu0_distance_t __mu9_for_each_by_n__k__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	for (; __mu9_for_each_by_n__i__ < mu0_const_distance(__n);) {                                        \
		__unary_fn(Tp, *__first);                                                                         \
		__mu9_for_each_by_n__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_for_each_by_n__j__ != __mu9_for_each_by_n__k__; (void) ++__mu9_for_each_by_n__j__) { \
			if (!(__mu9_for_each_by_n__i__ < mu0_const_distance(__n))) {                                   \
				__mu9_for_each_by_n__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__mu9_for_each_by_n__i__;                                                                    \
			++__first;                                                                                     \
		}                                                                                                 \
		if (__mu9_for_each_by_n__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_FOR_EACH_BY_H */

/* EOF */