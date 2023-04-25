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

// mu9_search_first.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_SEARCH_FIRST_H
#define MU9_SEARCH_FIRST_H 1

MU0_BEGIN_CDECL

#	define mu9_search_first1(_Tp, __first1, __last1, __first2, __last2, __d_result) \
mu0_scope_begin                                                                    \
	mu0_bool_t __mu9_search_first1__x__ = mu0_false;                                \
	_Tp *      __mu9_search_first1__i__ = __first2;                                 \
	_Tp *      __mu9_search_first1__k__;                                            \
	for (; __mu9_search_first1__i__ != __last2; ++__mu9_search_first1__i__) {       \
		__mu9_search_first1__k__ = __first1;                                         \
		for (; __mu9_search_first1__k__ != __last1; ++__mu9_search_first1__k__) {    \
			if (*__mu9_search_first1__i__ == *__mu9_search_first1__k__) {             \
				__mu9_search_first1__x__ = mu0_true;                                   \
				break;                                                                 \
			}                                                                         \
		}                                                                            \
		if (__mu9_search_first1__x__) {                                              \
			break;                                                                    \
		}                                                                            \
	}                                                                               \
	__d_result = __mu9_search_first1__x__ ? __mu9_search_first1__i__ : __last2;     \
mu0_scope_end

#	define mu9_search_first2(_Tp, __first1, __last1, __first2, __last2, __binary_pred, __d_result) \
mu0_scope_begin                                                                                   \
	mu0_bool_t __mu9_search_first2__x__ = mu0_false;                                               \
	_Tp *      __mu9_search_first2__i__ = __first2;                                                \
	_Tp *      __mu9_search_first2__k__;                                                           \
	for (; __mu9_search_first2__i__ != __last2; ++__mu9_search_first2__i__) {                      \
		__mu9_search_first2__k__ = __first1;                                                        \
		for (; __mu9_search_first2__k__ != __last1; ++__mu9_search_first2__k__) {                   \
			if (__binary_pred(_Tp, *__mu9_search_first2__i__, *__mu9_search_first2__k__)) {          \
				__mu9_search_first2__x__ = mu0_true;                                                  \
				break;                                                                                \
			}                                                                                        \
		}                                                                                           \
		if (__mu9_search_first2__x__) {                                                             \
			break;                                                                                   \
		}                                                                                           \
	}                                                                                              \
	__d_result = __mu9_search_first2__x__ ? __mu9_search_first2__i__ : __last2;                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEARCH_FIRST_H */

/* EOF */