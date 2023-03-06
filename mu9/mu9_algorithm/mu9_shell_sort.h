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
#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_SHELL_SORT_H
#define MU9_SHELL_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_shell_sort1(_Tp, __first, __last)                                                         \
mu0_scope_begin                                                                                         \
	_Tp * __mu9_shell_sort1__i__;                                                                        \
	_Tp * __mu9_shell_sort1__j__;                                                                        \
	const mu0_distance_t __mu9_shell_sort1__n__ = mu9_const_distance(_Tp, __first, __last);              \
	const mu0_distance_t __mu9_shell_sort1__k__ = mu0_const_distance(3);                                 \
			mu0_distance_t __mu9_shell_sort1__h__ = mu0_const_distance(1);                                 \
	while ( __mu9_shell_sort1__h__ < __mu9_shell_sort1__n__ / __mu9_shell_sort1__k__ ) {                 \
		__mu9_shell_sort1__h__ = __mu9_shell_sort1__k__ * __mu9_shell_sort1__h__ + mu0_const_distance(1); \
	}                                                                                                    \
	while (__mu9_shell_sort1__h__ >= mu0_const_distance(1)) {                                            \
		__mu9_shell_sort1__i__ = __first + __mu9_shell_sort1__h__;                                        \
		for (; __mu9_shell_sort1__i__ != __last; __mu9_shell_sort1__i__++ ) {                             \
			__mu9_shell_sort1__j__ = __mu9_shell_sort1__i__;                                               \
			for (; mu9_distance(_Tp, __first, __mu9_shell_sort1__j__) >= __mu9_shell_sort1__h__            \
				&& (*__mu9_shell_sort1__j__ < *(__mu9_shell_sort1__j__ - __mu9_shell_sort1__h__));          \
				__mu9_shell_sort1__j__ -= __mu9_shell_sort1__h__                                            \
			) {                                                                                            \
				mu9_swap(_Tp                                                                                \
					, *__mu9_shell_sort1__j__                                                                \
					, *(__mu9_shell_sort1__j__ - __mu9_shell_sort1__h__)                                     \
				);                                                                                          \
			}                                                                                              \
		}                                                                                                 \
		__mu9_shell_sort1__h__ = __mu9_shell_sort1__h__ / __mu9_shell_sort1__k__;                         \
	}                                                                                                    \
mu0_scope_end

#	define mu9_shell_sort2(_Tp, __first, __last, __comp_fn)                                                 \
mu0_scope_begin                                                                                            \
	_Tp * __mu9_shell_sort2__i__;                                                                           \
	_Tp * __mu9_shell_sort2__j__;                                                                           \
	const mu0_distance_t __mu9_shell_sort2__n__ = mu9_const_distance(_Tp, __first, __last);                 \
	const mu0_distance_t __mu9_shell_sort2__k__ = mu0_const_distance(3);                                    \
			mu0_distance_t __mu9_shell_sort2__h__ = mu0_const_distance(1);                                    \
	while ( __mu9_shell_sort2__h__ < __mu9_shell_sort2__n__ / __mu9_shell_sort2__k__ ) {                    \
		__mu9_shell_sort2__h__ = __mu9_shell_sort2__k__ * __mu9_shell_sort2__h__ + mu0_const_distance(1);    \
	}                                                                                                       \
	while (__mu9_shell_sort2__h__ >= mu0_const_distance(1)) {                                               \
		__mu9_shell_sort2__i__ = __first + __mu9_shell_sort2__h__;                                           \
		for (; __mu9_shell_sort2__i__ != __last; __mu9_shell_sort2__i__++ ) {                                \
			__mu9_shell_sort2__j__ = __mu9_shell_sort2__i__;                                                  \
			for (; mu9_distance(_Tp, __first, __mu9_shell_sort2__j__) >= __mu9_shell_sort2__h__               \
				&& _comp_fn(_Tp, *__mu9_shell_sort2__j__, *(__mu9_shell_sort2__j__ - __mu9_shell_sort2__h__)); \
				__mu9_shell_sort2__j__ -= __mu9_shell_sort2__h__                                               \
			) {                                                                                               \
				mu9_swap(_Tp                                                                                   \
					, *__mu9_shell_sort2__j__                                                                   \
					, *(__mu9_shell_sort2__j__ - __mu9_shell_sort2__h__)                                        \
				);                                                                                             \
			}                                                                                                 \
		}                                                                                                    \
		__mu9_shell_sort2__h__ = __mu9_shell_sort2__h__ / __mu9_shell_sort2__k__;                            \
	}                                                                                                       \
mu0_scope_end

#	define mu9_shell_sort3(_Tp, __first, __last, __sort_op, __ctx)                                                  \
mu0_scope_begin                                                                                                    \
	_Tp * __mu9_shell_sort3__i__;                                                                                   \
	_Tp * __mu9_shell_sort3__j__;                                                                                   \
	const mu0_distance_t __mu9_shell_sort3__n__ = mu9_const_distance(_Tp, __first, __last);                         \
	const mu0_distance_t __mu9_shell_sort3__k__ = mu0_const_distance(3);                                            \
			mu0_distance_t __mu9_shell_sort3__h__ = mu0_const_distance(1);                                            \
	while ( __mu9_shell_sort3__h__ < __mu9_shell_sort3__n__ / __mu9_shell_sort3__k__ ) {                            \
		__mu9_shell_sort3__h__ = __mu9_shell_sort3__k__ * __mu9_shell_sort3__h__ + mu0_const_distance(1);            \
	}                                                                                                               \
	while (__mu9_shell_sort3__h__ >= mu0_const_distance(1)) {                                                       \
		__mu9_shell_sort3__i__ = mu9_next_n(_Tp, __first, __mu9_shell_sort3__h__);                                   \
		for (; __mu9_shell_sort3__i__ != __last; __mu9_shell_sort3__i__++ ) {                                        \
			__mu9_shell_sort3__j__ = __mu9_shell_sort3__i__;                                                          \
			for (; mu9_distance(_Tp, __first, __mu9_shell_sort3__j__) >= __mu9_shell_sort3__h__                       \
				&& __sort_op(_Tp, *__mu9_shell_sort3__j__, *(__mu9_shell_sort3__j__ - __mu9_shell_sort3__h__), __ctx); \
				__mu9_shell_sort3__j__ -= __mu9_shell_sort3__h__                                                       \
			) {                                                                                                       \
				mu9_swap(_Tp                                                                                           \
					, *__mu9_shell_sort3__j__                                                                           \
					, *(__mu9_shell_sort3__j__ - __mu9_shell_sort3__h__)                                                \
				);                                                                                                     \
			}                                                                                                         \
		}                                                                                                            \
		__mu9_shell_sort3__h__ = __mu9_shell_sort3__h__ / __mu9_shell_sort3__k__;                                    \
	}                                                                                                               \
mu0_scope_end

#	define mu9_shell_sort4(_Tp, __first, __last, __swap_op)                                               \
mu0_scope_begin                                                                                          \
	_Tp * __mu9_shell_sort4__i__;                                                                         \
	_Tp * __mu9_shell_sort4__j__;                                                                         \
	const mu0_distance_t __mu9_shell_sort4__n__ = mu9_const_distance(_Tp, __first, __last);               \
	const mu0_distance_t __mu9_shell_sort4__k__ = mu0_const_distance(3);                                  \
			mu0_distance_t __mu9_shell_sort4__h__ = mu0_const_distance(1);                                  \
	while ( __mu9_shell_sort4__h__ < __mu9_shell_sort4__n__ / __mu9_shell_sort4__k__ ) {                  \
		__mu9_shell_sort4__h__ = __mu9_shell_sort4__k__ * __mu9_shell_sort4__h__ + mu0_const_distance(1);  \
	}                                                                                                     \
	while (__mu9_shell_sort4__h__ >= mu0_const_distance(1)) {                                             \
		__mu9_shell_sort4__i__ = __first + __mu9_shell_sort4__h__;                                         \
		for (; __mu9_shell_sort4__i__ != __last; __mu9_shell_sort4__i__++ ) {                              \
			__mu9_shell_sort4__j__ = __mu9_shell_sort4__i__;                                                \
			for (; mu9_distance(_Tp, __first, __mu9_shell_sort4__j__) >= __mu9_shell_sort4__h__             \
				&& (*__mu9_shell_sort4__j__ < *(__mu9_shell_sort4__j__ - __mu9_shell_sort4__h__));           \
				__mu9_shell_sort4__j__ -= __mu9_shell_sort4__h__                                             \
			) {                                                                                             \
				__swap_op(_Tp, *__mu9_shell_sort4__j__, *(__mu9_shell_sort4__j__ - __mu9_shell_sort4__h__)); \
			}                                                                                               \
		}                                                                                                  \
		__mu9_shell_sort4__h__ = __mu9_shell_sort4__h__ / __mu9_shell_sort4__k__;                          \
	}                                                                                                     \
mu0_scope_end

#	define mu9_shell_sort5(_Tp, __first, __last, __comp_fn, __swap_op)                                      \
mu0_scope_begin                                                                                            \
	_Tp * __mu9_shell_sort5__i__;                                                                           \
	_Tp * __mu9_shell_sort5__j__;                                                                           \
	const mu0_distance_t __mu9_shell_sort5__n__ = mu9_const_distance(_Tp, __first, __last);                 \
	const mu0_distance_t __mu9_shell_sort5__k__ = mu0_const_distance(3);                                    \
			mu0_distance_t __mu9_shell_sort5__h__ = mu0_const_distance(1);                                    \
	while ( __mu9_shell_sort5__h__ < __mu9_shell_sort5__n__ / __mu9_shell_sort5__k__ ) {                    \
		__mu9_shell_sort5__h__ = __mu9_shell_sort5__k__ * __mu9_shell_sort5__h__ + mu0_const_distance(1);    \
	}                                                                                                       \
	while (__mu9_shell_sort5__h__ >= mu0_const_distance(1)) {                                               \
		__mu9_shell_sort5__i__ = __first + __mu9_shell_sort5__h__;                                           \
		for (; __mu9_shell_sort5__i__ != __last; __mu9_shell_sort5__i__++ ) {                                \
			__mu9_shell_sort5__j__ = __mu9_shell_sort5__i__;                                                  \
			for (; mu9_distance(_Tp, __first, __mu9_shell_sort5__j__) >= __mu9_shell_sort5__h__               \
				&& _comp_fn(_Tp, *__mu9_shell_sort5__j__, *(__mu9_shell_sort5__j__ - __mu9_shell_sort5__h__)); \
				__mu9_shell_sort5__j__ -= __mu9_shell_sort5__h__                                               \
			) {                                                                                               \
				__swap_op(_Tp, *__mu9_shell_sort5__j__, *(__mu9_shell_sort5__j__ - __mu9_shell_sort5__h__));   \
			}                                                                                                 \
		}                                                                                                    \
		__mu9_shell_sort5__h__ = __mu9_shell_sort5__h__ / __mu9_shell_sort5__k__;                            \
	}                                                                                                       \
mu0_scope_end

#	define mu9_shell_sort6(_Tp, __first, __last, __sort_op, __ctx, __swap_op)                                       \
mu0_scope_begin                                                                                                    \
	_Tp * __mu9_shell_sort6__i__;                                                                                   \
	_Tp * __mu9_shell_sort6__j__;                                                                                   \
	const mu0_distance_t __mu9_shell_sort6__n__ = mu9_const_distance(_Tp, __first, __last);                         \
	const mu0_distance_t __mu9_shell_sort6__k__ = mu0_const_distance(3);                                            \
			mu0_distance_t __mu9_shell_sort6__h__ = mu0_const_distance(1);                                            \
	while ( __mu9_shell_sort6__h__ < __mu9_shell_sort6__n__ / __mu9_shell_sort6__k__ ) {                            \
		__mu9_shell_sort6__h__ = __mu9_shell_sort6__k__ * __mu9_shell_sort6__h__ + mu0_const_distance(1);            \
	}                                                                                                               \
	while (__mu9_shell_sort6__h__ >= mu0_const_distance(1)) {                                                       \
		__mu9_shell_sort6__i__ = mu9_next_n(_Tp, __first, __mu9_shell_sort6__h__);                                   \
		for (; __mu9_shell_sort6__i__ != __last; __mu9_shell_sort6__i__++ ) {                                        \
			__mu9_shell_sort6__j__ = __mu9_shell_sort6__i__;                                                          \
			for (; mu9_distance(_Tp, __first, __mu9_shell_sort6__j__) >= __mu9_shell_sort6__h__                       \
				&& __sort_op(_Tp, *__mu9_shell_sort6__j__, *(__mu9_shell_sort6__j__ - __mu9_shell_sort6__h__), __ctx); \
				__mu9_shell_sort6__j__ -= __mu9_shell_sort6__h__                                                       \
			) {                                                                                                       \
				__swap_op(_Tp, *__mu9_shell_sort6__j__, *(__mu9_shell_sort6__j__ - __mu9_shell_sort6__h__));           \
			}                                                                                                         \
		}                                                                                                            \
		__mu9_shell_sort6__h__ = __mu9_shell_sort6__h__ / __mu9_shell_sort6__k__;                                    \
	}                                                                                                               \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SHELL_SORT_H */

/* EOF */