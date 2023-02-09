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

// mu9_shell_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>
#include <mu9/mu9_algorithm/mu9_min_swap.h>

#ifndef MU9_SHELL_SORT_H
#define MU9_SHELL_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_shell_sort1(_Tp, __first, __last)                                                        \
mu0_scope_begin                                                                                        \
	_Tp * __mu9_shell_sort1__i__;                                                                       \
	_Tp * __mu9_shell_sort1__j__;                                                                       \
	const m0_distance_t __mu9_shell_sort1__n__ = mu9_const_distance(_Tp, __first, __last);              \
	const m0_distance_t __mu9_shell_sort1__k__ = m0_const_distance(3);                                  \
			m0_distance_t __mu9_shell_sort1__h__ = m0_distance(1);                                        \
	while ( __mu9_shell_sort1__h__ < __mu9_shell_sort1__n__ / __mu9_shell_sort1__k__ ) {                \
		__mu9_shell_sort1__h__ = __mu9_shell_sort1__k__ * __mu9_shell_sort1__h__ + m0_const_distance(1); \
	}                                                                                                   \
	while (__mu9_shell_sort1__h__ >= m0_const_distance(1)) {                                            \
		__mu9_shell_sort1__i__ = __first + __mu9_shell_sort1__h__;                                       \
		for (; __mu9_shell_sort1__i__ != __last; __mu9_shell_sort1__i__++ ) {                            \
			__mu9_shell_sort1__j__ = __mu9_shell_sort1__i__;                                              \
			for (; (__mu9_shell_sort1__j__ - __first) >= __mu9_shell_sort1__h__                           \
				&& (*__mu9_shell_sort1__j__ < *(__mu9_shell_sort1__j__ - __mu9_shell_sort1__h__));         \
				__mu9_shell_sort1__j__ -= __mu9_shell_sort1__h__                                           \
			) {                                                                                           \
				mu9_swap(*__mu9_shell_sort1__j__, *(__mu9_shell_sort1__j__ - __mu9_shell_sort1__h__));     \
			}                                                                                             \
		}                                                                                                \
		__mu9_shell_sort1__h__ = __mu9_shell_sort1__h__ / __mu9_shell_sort1__k__;                        \
	}                                                                                                   \
mu0_scope_end

#	define mu9_shell_sort2(_Tp, __first, __last, __comp_fn)                                             \
mu0_scope_begin                                                                                        \
	_Tp * __mu9_shell_sort2__i__;                                                                       \
	_Tp * __mu9_shell_sort2__j__;                                                                       \
	const m0_distance_t __mu9_shell_sort2__n__ = mu9_const_distance(_Tp, __first, __last);              \
	const m0_distance_t __mu9_shell_sort2__k__ = m0_const_distance(3);                                  \
			m0_distance_t __mu9_shell_sort2__h__ = m0_distance(1);                                        \
	while ( __mu9_shell_sort2__h__ < __mu9_shell_sort2__n__ / __mu9_shell_sort2__k__ ) {                \
		__mu9_shell_sort2__h__ = __mu9_shell_sort2__k__ * __mu9_shell_sort2__h__ + m0_const_distance(1); \
	}                                                                                                   \
	while (__mu9_shell_sort2__h__ >= m0_const_distance(1)) {                                            \
		__mu9_shell_sort2__i__ = __first + __mu9_shell_sort2__h__;                                       \
		for (; __mu9_shell_sort2__i__ != __last; __mu9_shell_sort2__i__++ ) {                            \
			__mu9_shell_sort2__j__ = __mu9_shell_sort2__i__;                                              \
			for (; (__mu9_shell_sort2__j__ - __first) >= __mu9_shell_sort2__h__                           \
				&& __comp_fn(*__mu9_shell_sort2__j__, *(__mu9_shell_sort2__j__ - __mu9_shell_sort2__h__)); \
				__mu9_shell_sort2__j__ -= __mu9_shell_sort2__h__                                           \
			) {                                                                                           \
				mu9_swap(*__mu9_shell_sort2__j__, *(__mu9_shell_sort2__j__ - __mu9_shell_sort2__h__));     \
			}                                                                                             \
		}                                                                                                \
		__mu9_shell_sort2__h__ = __mu9_shell_sort2__h__ / __mu9_shell_sort2__k__;                        \
	}                                                                                                   \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SHELL_SORT_H */

/* EOF */