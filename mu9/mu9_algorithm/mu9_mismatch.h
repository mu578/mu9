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

// mu9_mismatch.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_MISMATCH_H
#define MU9_MISMATCH_H 1

MU0_BEGIN_CDECL

#	define mu9_mismatch1(_Tp, __first1, __last1, __first2, __d_result1, __d_result2) \
mu0_scope_begin                                                                     \
	while (__first1 != __last1 && *__first1 == *__first2) {                          \
		++__first1, ++__first2;                                                       \
	}                                                                                \
	__d_result1 = __first1;                                                          \
	__d_result2 = __first2;                                                          \
mu0_scope_end

#	define mu9_mismatch2(_Tp, __first1, __last1, __first2, __binary_pred, __d_result1, __d_result2) \
mu0_scope_begin                                                                                    \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                    \
		if (!__binary_pred(*__first1, *__first2)) {                                                  \
			break;                                                                                    \
		}                                                                                            \
	}                                                                                               \
	__d_result1 = __first1;                                                                         \
	__d_result2 = __first2;                                                                         \
mu0_scope_end

#	define mu9_mismatch3(_Tp, __first1, __last1, __first2, __last2, __d_result1, __d_result2) \
mu0_scope_begin                                                                              \
	while (__first1 != __last1 && __first2 != __last2 && *__first1 == *__first2) {            \
		++__first1, ++__first2;                                                                \
	}                                                                                         \
	__d_result1 = __first1;                                                                   \
	__d_result2 = __first2;                                                                   \
mu0_scope_end

#	define mu9_mismatch4(_Tp, __first1, __last1, __first2, __last2, __binary_pred, __d_result1, __d_result2) \
mu0_scope_begin                                                                                             \
	while (__first1 != __last1 && __first2 != __last2 && __binary_predp(*__first1, *__first2)) {             \
		++__first1, ++__first2;                                                                               \
	}                                                                                                        \
	__d_result1 = __first1;                                                                                  \
	__d_result2 = __first2;                                                                                  \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MISMATCH_H */

/* EOF */