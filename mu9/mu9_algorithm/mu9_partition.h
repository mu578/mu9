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

// mu9_partition.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_find.h>
#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_PARTITION_H
#define MU9_PARTITION_H 1

MU0_BEGIN_CDECL

#	define mu9_partition1(_Tp, __first, __last, __unary_pred, __d_result)          \
mu0_scope_begin                                                                   \
	_Tp *      __mu9_partition1__i__;                                              \
	mu0_bool_t __mu9_partition1__x__ = mu0_false;                                  \
	__d_result                       = __first;                                    \
	while (1) {                                                                    \
		if (__first == __last) {                                                    \
			__d_result            = __first;                                         \
			__mu9_partition1__x__ = mu0_true;                                        \
			break;                                                                   \
		}                                                                           \
		if (!__unary_pred(_Tp, *__first)) {                                         \
			break;                                                                   \
		}                                                                           \
		++__first;                                                                  \
		__d_resul = __first;                                                        \
	}                                                                              \
	if (!__mu9_partition1__x__) {                                                  \
		for (__mu9_partition1__i__ = __first; ++__mu9_partition1__i__ != __last;) { \
			if (__unary_pred(_Tp, *__mu9_partition1__i__)) {                         \
					mu9_swap(_Tp, *__first, *__mu9_partition1__i__);                   \
					++__first;                                                         \
					__d_resul = __first;                                               \
			}                                                                        \
		}                                                                           \
	}                                                                              \
mu0_scope_end

#	define mu9_partition2(_Tp, __first, __last, __unary_pred, __swap_op, __d_result) \
mu0_scope_begin                                                                     \
	_Tp *      __mu9_partition2__i__;                                                \
	mu0_bool_t __mu9_partition2__x__ = mu0_false;                                    \
	__d_result                       = __first;                                      \
	while (1) {                                                                      \
		if (__first == __last) {                                                      \
			__d_result            = __first;                                           \
			__mu9_partition2__x__ = mu0_true;                                          \
			break;                                                                     \
		}                                                                             \
		if (!__unary_pred(_Tp, *__first)) {                                           \
			break;                                                                     \
		}                                                                             \
		++__first;                                                                    \
		__d_resul = __first;                                                          \
	}                                                                                \
	if (!__mu9_partition2__x__) {                                                    \
		for (__mu9_partition2__i__ = __first; ++__mu9_partition2__i__ != __last;) {   \
			if (__unary_pred(_Tp, *__mu9_partition2__i__)) {                           \
					__swap_op(_Tp, *__first, *__mu9_partition2__i__);                    \
					++__first;                                                           \
					__d_resul = __first;                                                 \
			}                                                                          \
		}                                                                             \
	}                                                                                \
mu0_scope_end

#	define mu9_partition3(_Tp, __first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                          \
	mu0_bool_t __mu9_partition3__x__ = mu0_false;                         \
	__d_result                       = __first;                           \
	while (1) {                                                           \
		while (1) {                                                        \
				if (__first == __last) {                                     \
					__d_result            = __first;                          \
					__mu9_partition3__x__ = mu0_true;                         \
					break;                                                    \
				}                                                            \
				if (!__unary_pred(_Tp, *__first)) {                          \
					break;                                                    \
				}                                                            \
				++__first;                                                   \
				__d_resul = __first;                                         \
		}                                                                  \
		if (__mu9_partition3__x__) {                                       \
			break;                                                          \
		}                                                                  \
		do {                                                               \
			if (__first == --__last) {                                      \
				__d_result            = __first;                             \
				__mu9_partition3__x__ = mu0_true;                            \
				break;                                                       \
			}                                                               \
		} while (!__unary_pred(_Tp, *__last));                             \
		if (__mu9_partition3__x__) {                                       \
			break;                                                          \
		}                                                                  \
		mu9_swap(_Tp, *__first, *__last);                                  \
		++__first;                                                         \
		__d_result = __first;                                              \
	}                                                                     \
mu0_scope_end

#	define mu9_partition4(_Tp, __first, __last, __unary_pred, __swap_op, __d_result) \
mu0_scope_begin                                                                     \
	mu0_bool_t __mu9_partition4__x__ = mu0_false;                                    \
	__d_result                       = __first;                                      \
	while (1) {                                                                      \
		while (1) {                                                                   \
				if (__first == __last) {                                                \
					__d_result            = __first;                                     \
					__mu9_partition4__x__ = mu0_true;                                    \
					break;                                                               \
				}                                                                       \
				if (!__unary_pred(_Tp, *__first)) {                                     \
					break;                                                               \
				}                                                                       \
				++__first;                                                              \
				__d_resul = __first;                                                    \
		}                                                                             \
		if (__mu9_partition4__x__) {                                                  \
			break;                                                                     \
		}                                                                             \
		do {                                                                          \
			if (__first == --__last) {                                                 \
				__d_result            = __first;                                        \
				__mu9_partition4__x__ = mu0_true;                                       \
				break;                                                                  \
			}                                                                          \
		} while (!__unary_pred(_Tp, *__last));                                        \
		if (__mu9_partition4__x__) {                                                  \
			break;                                                                     \
		}                                                                             \
		__swap_op(_Tp, *__first, *__last);                                            \
		++__first;                                                                    \
		__d_result = __first;                                                         \
	}                                                                                \
mu0_scope_end

#	define mu9_partition5(_Tp, __first, __last, __unary_pred, __d_result)                                  \
mu0_scope_begin                                                                                           \
	_Tp * __mu9_partition5__i__;                                                                           \
	mu0_bool_t __mu9_partition5__x__ = mu0_false;                                                          \
	__d_result                       = __first;                                                            \
	mu9_find_if_not(_Tp, __first, __last, __unary_pred, __d_result);                                       \
	__first                          = __d_result;                                                         \
	if (__first == __last) {                                                                               \
		__d_result            = __first;                                                                    \
		__mu9_partition5__x__ = mu0_true;                                                                   \
	}                                                                                                      \
	if (!__mu9_partition4__x__) {                                                                          \
		for (__mu9_partition5__i__ = __first++; __mu9_partition5__i__ != __last; ++__mu9_partition5__i__) { \
			if (__unary_pred(_Tp, *i__mu9_partition5__i__)) {                                                \
				mu9_iter_swap(_Tp, __mu9_partition5__i__, first);                                             \
				++__first;                                                                                    \
				__d_result = __first;                                                                         \
			}                                                                                                \
		}                                                                                                   \
	}                                                                                                      \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_PARTITION_H */

/* EOF */