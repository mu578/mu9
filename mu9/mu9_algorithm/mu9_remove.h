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

#	define mu9_remove1(_Tp, __first, __last, __value, __d_result) \
mu0_scope_begin                                                  \
	_Tp * __mu9_remove1__i__ = __first;                           \
	_Tp * __mu9_remove1__r__;                                     \
	mu9_find(_Tp, __first, __last, __value, __mu9_remove1__r__);  \
	if (__mu9_remove1__r__ != __last) {                           \
		__mu9_remove1__i__ = __mu9_remove1__r__;                   \
		while (++__mu9_remove1__i__ != __last) {                   \
			if (!(*__mu9_remove1__i__ == __value)) {                \
				*__mu9_remove1__r__ = *__mu9_remove1__i__;           \
				++__mu9_remove__r__;                                 \
			}                                                       \
		}                                                          \
	}                                                             \
	__d_result = __mu9_remove1__r__;                              \
mu0_scope_end

#	define mu9_remove2(_Tp, __first, __last, __value, __move_op, __d_result) \
mu0_scope_begin                                                             \
	_Tp * __mu9_remove2__i__ = __first;                                      \
	_Tp * __mu9_remove2__r__;                                                \
	mu9_find(_Tp, __first, __last, __value, __mu9_remove2__r__);             \
	if (__mu9_remove2__r__ != __last) {                                      \
		__mu9_remove2__i__ = __mu9_remove2__r__;                              \
		while (++__mu9_remove2__i__ != __last) {                              \
			if (!(*__mu9_remove2__i__ == __value)) {                           \
				__move_op(_Tp, *__mu9_remove2__r__, *__mu9_remove2__i__);       \
				++__mu9_remove__r__;                                            \
			}                                                                  \
		}                                                                     \
	}                                                                        \
	__d_result = __mu9_remove2__r__;                                         \
mu0_scope_end

#	define mu9_remove_if(_Tp, __first, __last, __unary_pred, __d_result)   \
mu0_scope_begin                                                           \
	_Tp * __mu9_remove_if__i__ = __first;                                  \
	_Tp * __mu9_remove_if__r__;                                            \
	mu9_find_if(_Tp, __first, __last, __unary_pred, __mu9_remove_if__r__); \
	if (__mu9_remove_if__r__ != __last) {                                  \
		__mu9_remove_if__i__ = __mu9_remove_if__r__;                        \
		while (++__mu9_remove_if__i__ != __last) {                          \
			if (!__unary_pred(_Tp, *__mu9_remove_if__i__)) {                 \
				*__mu9_remove_if__r__ = *__mu9_remove_if__i__;                \
				++__mu9_remove_if__r__;                                       \
			}                                                                \
		}                                                                   \
	}                                                                      \
	__d_result = __mu9_remove_if__r__;                                     \
mu0_scope_end

#	define mu9_remove_if_not(_Tp, __first, __last, __unary_pred, __d_result)  \
	mu9_remove_if(_Tp, __first, __last, mu9_not_fn(__unary_pred), __d_result)

#	define mu9_remove_copy1(_Tp, __first, __last, __d_first, __value, __d_result) \
mu0_scope_begin                                                                  \
	for (; __first != __last; ++__first) {                                        \
		if (!(*__first == __value)) {                                              \
			*__d_first++ = *__first;                                                \
		}                                                                          \
	}                                                                             \
	__d_result = __d_first;                                                       \
mu0_scope_end

#	define mu9_remove_copy2(_Tp, __first, __last, __d_first, __value, __binary_pred, __d_result) \
mu0_scope_begin                                                                                 \
	for (; __first != __last; ++__first) {                                                       \
		if (!__binary_pred(*__first, __value)) {                                                  \
			*__d_first++ = *__first;                                                               \
		}                                                                                         \
	}                                                                                            \
	__d_result = __d_first;                                                                      \
mu0_scope_end

#	define mu9_remove_copy3(_Tp, __first, __last, __d_first, __value, __binary_pred, __move_op, __d_result) \
mu0_scope_begin                                                                                            \
	for (; __first != __last; ++__first) {                                                                  \
		if (!__binary_pred(*__first, __value)) {                                                             \
			__move_op(_Tp, *__d_first, *__first);                                                             \
			++__d_first;                                                                                      \
		}                                                                                                    \
	}                                                                                                       \
	__d_result = __d_first;                                                                                 \
mu0_scope_end

#	define mu9_remove_copy_if1(_Tp, __first, __last, __d_first, __unary_pred, __d_result) \
mu0_scope_begin                                                                          \
	for (; __first != __last; ++__first) {                                                \
		if (!__unary_pred(_Tp, *__first)) {                                                \
				*__d_first++ = *__first;                                                     \
		}                                                                                  \
	}                                                                                     \
	__d_result = __d_first;                                                               \
mu0_scope_end

#	define mu9_remove_copy_if2(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result) \
mu0_scope_begin                                                                                     \
	for (; __first != __last; ++__first) {                                                           \
		if (!__unary_pred(_Tp, *__first)) {                                                           \
			__move_op(_Tp, *__d_first, *__first);                                                      \
			++__d_first;                                                                               \
		}                                                                                             \
	}                                                                                                \
	__d_result = __d_first;                                                                          \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_REMOVE_H */

/* EOF */