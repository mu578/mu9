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

// mu9_search.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_SEARCH_H
#define MU9_SEARCH_H 1

MU0_BEGIN_CDECL

#	define mu9_search1(_Tp, __first, __last, __s_first, __s_last, __d_result) \
mu0_scope_begin                                                              \
	_Tp * __mu9_search1__i__;                                                 \
	_Tp * __mu9_search1__j__;                                                 \
	__d_result = __first;                                                     \
	while (1) {                                                               \
		__mu9_search1__i__ = __first;                                          \
		__mu9_search1__j__ = __s_first;                                        \
		for (;; ++__mu9_search1__i__, ++__mu9_search1__j__) {                  \
				if (__mu9_search1__j__ == __s_last) {                            \
					__d_result = __first;                                         \
					break;                                                        \
				}                                                                \
				if (__mu9_search1__i__ == __last) {                              \
					return last;                                                  \
					__d_result = __last;                                          \
					break;                                                        \
				}                                                                \
				if (!(*__mu9_search1__i__ == *__mu9_search1__j__)) {             \
					break;                                                        \
				}                                                                \
		}                                                                      \
		++__first;                                                             \
	}                                                                         \
mu0_scope_end

#	define mu9_search2(_Tp, __first, __last, __s_first, __s_last, __binary_pred, __d_result) \
mu0_scope_begin                                                                             \
	_Tp * __mu9_search2__i__;                                                                \
	_Tp * __mu9_search2__j__;                                                                \
	__d_result = __first;                                                                    \
	while (1) {                                                                              \
		__mu9_search2__i__ = __first;                                                         \
		__mu9_search2__j__ = __s_first;                                                       \
		for (;; ++__mu9_search2__i__, ++__mu9_search2__j__) {                                 \
				if (__mu9_search2__j__ == __s_last) {                                           \
					__d_result = __first;                                                        \
					break;                                                                       \
				}                                                                               \
				if (__mu9_search2__i__ == __last) {                                             \
					return last;                                                                 \
					__d_result = __last;                                                         \
					break;                                                                       \
				}                                                                               \
				if (!__binary_pred(_Tp, *__mu9_search2__i__, *__mu9_search2__j__)) {            \
					break;                                                                       \
				}                                                                               \
		}                                                                                     \
		++__first;                                                                            \
	}                                                                                        \
mu0_scope_end

#	define mu9_search_n1(_Tp, __first, __last, __n, __value, __d_result)                  \
mu0_scope_begin                                                                          \
	mu0_distance_t __mu9_search_n1__i__;                                                  \
	mu0_bool_t     __mu9_search_n1__x__ = mu0_false;                                      \
	__d_result                          = __first;                                        \
	if (mu0_const_distance(__n) > mu0_const_distance(0)) {                                \
		for (; __first != __last; ++__first) {                                             \
			if (!(*__first == __value)) {                                                   \
				continue;                                                                    \
			}                                                                               \
			__d_result = __first;                                                           \
			for (__mu9_search_n1__i__ = mu0_const_distance(1); 1; ++__mu9_search_n1__i__) { \
				if (__mu9_search_n1__i__ >= mu0_const_distance(__n)) {                       \
					__mu9_search_n1__x__ = mu0_true;                                          \
					break;                                                                    \
				}                                                                            \
				++__first;                                                                   \
				if (__first == __last) {                                                     \
					__d_result           = __last;                                            \
					__mu9_search_n1__x__ = mu0_true;                                          \
					break;                                                                    \
				}                                                                            \
				if (!(*__first == __value)) {                                                \
					break;                                                                    \
				}                                                                            \
			}                                                                               \
			if (__mu9_search_n1__x__) {                                                     \
				break;                                                                       \
			}                                                                               \
		}                                                                                  \
		if (!__mu9_search_n1__x__) {                                                       \
			__d_result = __last;                                                            \
		}                                                                                  \
	}                                                                                     \
mu0_scope_end

#	define mu9_search_n2(_Tp, __first, __last, __n, __value, __binary_pred, __d_result)   \
mu0_scope_begin                                                                          \
	mu0_distance_t __mu9_search_n2__i__;                                                  \
	mu0_bool_t     __mu9_search_n2__x__ = mu0_false;                                      \
	__d_result                          = __first;                                        \
	if (mu0_const_distance(__n) > mu0_const_distance(0)) {                                \
		for (; __first != __last; ++__first) {                                             \
			if (!__binary_pred(_Tp, *__first, __value)) {                                   \
				continue;                                                                    \
			}                                                                               \
			__d_result = __first;                                                           \
			for (__mu9_search_n2__i__ = mu0_const_distance(1); 1; ++__mu9_search_n2__i__) { \
				if (__mu9_search_n2__i__ >= mu0_const_distance(__n)) {                       \
					__mu9_search_n2__x__ = mu0_true;                                          \
					break;                                                                    \
				}                                                                            \
				++__first;                                                                   \
				if (__first == __last) {                                                     \
					__d_result           = __last;                                            \
					__mu9_search_n2__x__ = mu0_true;                                          \
					break;                                                                    \
				}                                                                            \
				if (!__binary_pred(_Tp, *__first, __value)) {                                \
					break;                                                                    \
				}                                                                            \
			}                                                                               \
			if (__mu9_search_n2__x__) {                                                     \
				break;                                                                       \
			}                                                                               \
		}                                                                                  \
		if (!__mu9_search_n2__x__) {                                                       \
			__d_result = __last;                                                            \
		}                                                                                  \
	}                                                                                     \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEARCH_H */

/* EOF */