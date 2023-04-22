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

// mu9_contains.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_CONTAINS_H
#define MU9_CONTAINS_H 1

MU0_BEGIN_CDECL

#	define mu9_contains1(_Tp, __first1, __last1, __first2, __last2, __d_result1, __d_result2) \
mu0_scope_begin                                                                              \
	mu0_bool_t __mu9_contains1__x__ = mu0_false;                                              \
	_Tp *      __mu9_contains1__i__;                                                          \
	_Tp *      __mu9_contains1__j__;                                                          \
	if (__first1 == __last1) {                                                                \
		__d_result1 = __first2;                                                                \
	} else {                                                                                  \
		__mu9_contains1__j__ = __first1;                                                       \
		for (; __first2 != __last2; ++__first2) {                                              \
			if (*__first2 != *__mu9_contains1__j__) {                                           \
				continue;                                                                        \
			}                                                                                   \
			__mu9_contains1__i__ = __first2;                                                    \
			while (1) {                                                                         \
				if (__mu9_contains1__j__ == __last1) {                                           \
					__mu9_contains1__x__ = mu0_true;                                              \
					__d_result1          = __first2;                                              \
					break;                                                                        \
				}                                                                                \
				if (*__mu9_contains1__i__++ != *__mu9_contains1__j__++) {                        \
					break;                                                                        \
				}                                                                                \
			}                                                                                   \
			if (__mu9_contains1__x__) {                                                         \
				break;                                                                           \
			}                                                                                   \
			__mu9_contains1__j__ = __first1;                                                    \
		}                                                                                      \
		if (!__mu9_contains1__x__) {                                                           \
			__d_result1 = __last2;                                                              \
		}                                                                                      \
	}                                                                                         \
	__d_result2 = __mu9_contains1__x__;                                                       \
mu0_scope_end

#	define mu9_contains2(_Tp, __first1, __last1, __first2, __last2, __binary_pred, __d_result1, __d_result2) \
mu0_scope_begin                                                                                             \
	mu0_bool_t __mu9_contains2__x__ = mu0_false;                                                             \
	_Tp *      __mu9_contains2__i__;                                                                         \
	_Tp *      __mu9_contains2__j__;                                                                         \
	if (__first1 == __last1) {                                                                               \
		__d_result1 = __first2;                                                                               \
	} else {                                                                                                 \
		__mu9_contains2__j__ = __first1;                                                                      \
		for (; __first2 != __last2; ++__first2) {                                                             \
			if (!__binary_pred(_Tp, *__first2, *__mu9_contains2__j__)) {                                       \
				continue;                                                                                       \
			}                                                                                                  \
			__mu9_contains2__i__ = __first2;                                                                   \
			while (1) {                                                                                        \
				if (__mu9_contains2__j__ == __last1) {                                                          \
					__mu9_contains2__x__ = mu0_true;                                                             \
					__d_result1          = __first2;                                                             \
					break;                                                                                       \
				}                                                                                               \
				if (!__binary_pred(_Tp, *__mu9_contains2__i__++, *__mu9_contains2__j__++)) {                    \
					break;                                                                                       \
				}                                                                                               \
			}                                                                                                  \
			if (__mu9_contains2__x__) {                                                                        \
				break;                                                                                          \
			}                                                                                                  \
			__mu9_contains2__j__ = __first1;                                                                   \
		}                                                                                                     \
		if (!__mu9_contains2__x__) {                                                                          \
			__d_result1 = __last2;                                                                             \
		}                                                                                                     \
	}                                                                                                        \
	__d_result2 = __mu9_contains2__x__;                                                                      \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_CONTAINS_H */

/* EOF */