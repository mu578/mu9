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

// mu9_remove.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_find.h>

#ifndef MU9_REMOVE_H
#define MU9_REMOVE_H 1

MU0_BEGIN_CDECL

#	define mu9_remove(_Tp, __first, __last, __value, __d_result) \
mu0_scope_begin                                                 \
	_Tp * __mu9_remove__i__ = __first;                           \
	_Tp * __mu9_remove__r__;                                     \
	mu9_find(_Tp, __first, __last, __value, __mu9_remove__r__);  \
	if (__mu9_remove__r__ != __last) {                           \
		__mu9_remove__i__ = __mu9_remove__r__;                    \
		while (++__mu9_remove__i__ != __last) {                   \
			if (!(*__mu9_remove__i__ == __value)) {                \
					*__mu9_remove__r__ = *__mu9_remove__i__;         \
					++__mu9_remove__r__;                             \
			}                                                      \
		}                                                         \
	}                                                            \
	__d_result = __mu9_remove__r__;                              \
mu0_scope_end

#	define mu9_remove_if1(_Tp, __first, __last, __unary_pred, __d_result)   \
mu0_scope_begin                                                            \
	_Tp * __mu9_remove_if1__i__ = __first;                                  \
	_Tp * __mu9_remove_if1_r__;                                             \
	mu9_find_if1(_Tp, __first, __last, __unary_pred, __mu9_remove_if1_r__); \
	if (__mu9_remove_if1_r__ != __last) {                                   \
		__mu9_remove_if1__i__ = __mu9_remove_if1_r__;                        \
		while (++__mu9_remove_if1__i__ != __last) {                          \
			if (!__unary_pred(*__mu9_remove_if1__i__)) {                      \
					*__mu9_remove_if1_r__ = *__mu9_remove_if1__i__;             \
					++__mu9_remove_if1_r__;                                     \
			}                                                                 \
		}                                                                    \
	}                                                                       \
	__d_result = __mu9_remove_if1_r__;                                      \
mu0_scope_end

#	define mu9_remove_if2(_Tp, __first, __last, __unary_op, __d_result)     \
mu0_scope_begin                                                            \
	_Tp * __mu9_remove_if1__i__ = __first;                                  \
	_Tp * __mu9_remove_if1_r__;                                             \
	mu9_find_if2(_Tp, __first, __last, __unary_pred, __mu9_remove_if1_r__); \
	if (__mu9_remove_if1_r__ != __last) {                                   \
		__mu9_remove_if1__i__ = __mu9_remove_if1_r__;                        \
		while (++__mu9_remove_if1__i__ != __last) {                          \
			if (!__unary_op(_Tp, *__mu9_remove_if1__i__)) {                   \
					*__mu9_remove_if1_r__ = *__mu9_remove_if1__i__;             \
					++__mu9_remove_if1_r__;                                     \
			}                                                                 \
		}                                                                    \
	}                                                                       \
	__d_result = __mu9_remove_if1_r__;                                      \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_REMOVE_H */

/* EOF */