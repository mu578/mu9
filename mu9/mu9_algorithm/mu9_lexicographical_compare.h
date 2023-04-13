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

// mu9_lexicographical_compare.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_LEXICOGRAPHICAL_COMPARE_H
#define MU9_LEXICOGRAPHICAL_COMPARE_H 1

MU0_BEGIN_CDECL

#	define mu9_lexicographical_compare1(_Tp, __first1, __last1, __first2, __last2, __d_result) \
mu0_scope_begin                                                                               \
	mu0_bool_t __mu9_lexicographical_compare1__x__ = mu0_false;                                \
	for (; __first2 != __last2; ++__first1, (void) ++__first2) {                               \
		if (__first1 == __last1 || (*__first1 < *__first2)) {                                   \
			__mu9_lexicographical_compare1__x__ = mu0_true;                                      \
			break;                                                                               \
		}                                                                                       \
		if (*__first2 < *__first1) {                                                            \
			__mu9_lexicographical_compare1__x__ = mu0_false;                                     \
			break;                                                                               \
		}                                                                                       \
	}                                                                                          \
	__d_result = __mu9_lexicographical_compare1__x__;                                          \
mu0_scope_end

#	define mu9_lexicographical_compare2(_Tp, __first1, __last1, __first2, __last2, __comp_fn, __d_result) \
mu0_scope_begin                                                                                          \
	mu0_bool_t __mu9_lexicographical_compare2__x__ = mu0_false;                                           \
	for (; __first2 != __last2; ++__first1, (void) ++__first2) {                                          \
		if (__first1 == __last1 || __comp_fn(_Tp, *__first1, *__first2)) {                                 \
			__mu9_lexicographical_compare2__x__ = mu0_true;                                                 \
			break;                                                                                          \
		}                                                                                                  \
		if (__comp_fn(_Tp, *__first2, *__first1)) {                                                        \
			__mu9_lexicographical_compare2__x__ = mu0_false;                                                \
			break;                                                                                          \
		}                                                                                                  \
	}                                                                                                     \
	__d_result = __mu9_lexicographical_compare2__x__;                                                     \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_LEXICOGRAPHICAL_COMPARE_H */

/* EOF */