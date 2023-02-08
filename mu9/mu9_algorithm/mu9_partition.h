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

#include <mu0/mu0_definition.h>

#ifndef MU9_PARTITION_H
#define MU9_PARTITION_H 1

MU0_BEGIN_CDECL

#	define mu9_partition1(_Tp, __first, __last, _Predicate __unary_pred, __d_result)       \
mu9_scope_begin                                                                           \
	_Tp * __mu9_mu9_partition1__i__;                                                       \
	mu9_bool_t __mu9_partition1__x__ = mu9_false;                                          \
	__d_result                       = __first;                                            \
	while (1) {                                                                            \
		if (__first == __last) {                                                            \
			__d_result            = __first;                                                 \
			__mu9_partition1__x__ = mu9_true;                                                \
			break;                                                                           \
		}                                                                                   \
		if (!__unary_pred(*__first)) {                                                      \
			break;                                                                           \
		}                                                                                   \
		++__first;                                                                          \
		__d_resul = __first;                                                                \
	}                                                                                      \
	if (!__mu9_partition1__x__) {                                                          \
		for (__mu9_mu9_partition1__i__ = __first; ++__mu9_mu9_partition1__i__ != __last;) { \
			if (__unary_pred(*__mu9_mu9_partition1__i__)) {                                  \
					mu9_swap(_Tp, *__first, *__mu9_mu9_partition1__i__);                       \
					++__first;                                                                 \
					__d_resul = __first;                                                       \
			}                                                                                \
		}                                                                                   \
	}                                                                                      \
mu9_scope_end

#	define mu9_partition2(_Tp, __first, __last, __unary_pred, __d_result) \
mu9_scope_begin                                                          \
	mu9_bool_t __mu9_partition2__x__ = mu9_false;                         \
	__d_result                       = __first;                           \
	while (1) {                                                           \
		while (1) {                                                        \
				if (__first == __last) {                                     \
					__d_result            = __first;                          \
					__mu9_partition2__x__ = mu9_true;                         \
					break;                                                    \
				}                                                            \
				if (!__unary_pred(*__first)) {                               \
					break;                                                    \
				}                                                            \
				++__first;                                                   \
				__d_resul = __first;                                         \
		}                                                                  \
		if (__mu9_partition2__x__) {                                       \
			break;                                                          \
		}                                                                  \
		do {                                                               \
			if (__first == --__last) {                                      \
				__d_result            = __first;                             \
				__mu9_partition2__x__ = mu9_true;                            \
				break;                                                       \
			}                                                               \
		} while (!__unary_pred(*__last));                                  \
		if (__mu9_partition2__x__) {                                       \
			break;                                                          \
		}                                                                  \
		mu9_swap(_Tp, *__first, *__last);                                  \
		++__first;                                                         \
		__d_result = __first;                                              \
	}                                                                     \
mu9_scope_end

MU0_END_CDECL

#endif /* !MU9_PARTITION_H */

/* EOF */