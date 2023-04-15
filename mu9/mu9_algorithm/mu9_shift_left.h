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

// mu9_shift_left.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>
#include <mu9/mu9_algorithm/mu9_move.h>

#ifndef MU9_SHIFT_LEFT_H
#define MU9_SHIFT_LEFT_H 1

MU0_BEGIN_CDECL

#	define mu9_shift_left1(_Tp, __first, __last, __n, __d_result)                               \
mu0_scope_begin                                                                                \
	mu0_bool_t     __mu9_shift_left1__x__ = mu0_false;                                          \
	_Tp *          __mu9_shift_left1__i__;                                                      \
	mu0_distance_t __mu9_shift_left1__n__ = mu0_const_distance(__n);                            \
	if (__mu9_shift_left1__n__ > mu0_const_distance(0)) {                                       \
		__mu9_shift_left1__i__ = __first;                                                        \
		for (; __mu9_shift_left1__n__ > 0; --__mu9_shift_left1__n__, ++__mu9_shift_left1__i__) { \
			if (__mu9_shift_left1__i__ == __last) {                                               \
				__mu9_shift_left1__x__ = mu0_true;                                                 \
				break;                                                                             \
			}                                                                                     \
		}                                                                                        \
		if (!__mu9_shift_left1__x__) {                                                           \
			mu9_move_indirect(_Tp, __mu9_shift_left1__i__, __last, __first, mu9_assign)           \
		}                                                                                        \
		__d_result = __first;                                                                    \
	} else {                                                                                    \
		__d_result = __last;                                                                     \
	}                                                                                           \
mu0_scope_end

#	define mu9_shift_left2(_Tp, __first, __last, __n, __move_op, __d_result)                    \
mu0_scope_begin                                                                                \
	mu0_bool_t     __mu9_shift_left2__x__ = mu0_false;                                          \
	_Tp *          __mu9_shift_left2__i__;                                                      \
	mu0_distance_t __mu9_shift_left2__n__ = mu0_const_distance(__n);                            \
	if (__mu9_shift_left2__n__ > mu0_const_distance(0)) {                                       \
		__mu9_shift_left2__i__ = __first;                                                        \
		for (; __mu9_shift_left2__n__ > 0; --__mu9_shift_left2__n__, ++__mu9_shift_left2__i__) { \
			if (__mu9_shift_left2__i__ == __last) {                                               \
				__mu9_shift_left2__x__ = mu0_true;                                                 \
				break;                                                                             \
			}                                                                                     \
		}                                                                                        \
		if (!__mu9_shift_left2__x__) {                                                           \
			mu9_move_indirect(_Tp, __mu9_shift_left2__i__, __last, __first, __move_op);           \
		}                                                                                        \
		__d_result = __first;                                                                    \
	} else {                                                                                    \
		__d_result = __last;                                                                     \
	}                                                                                           \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SHIFT_LEFT_H */

/* EOF */