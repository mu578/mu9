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

// mu9_bubble_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_BUBBLE_SORT_H
#define MU9_BUBBLE_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_bubble_sort1(_Tp, __first, __last)                                                              \
mu0_scope_begin                                                                                               \
	_Tp *      __mu9_bubble_sort1__j__;                                                                        \
	_Tp *      __mu9_bubble_sort1__k__;                                                                        \
	mu0_bool_t __mu9_bubble_sort1__x__ = mu0_false;                                                            \
	if (__first != __last) {                                                                                   \
		while (!__mu9_bubble_sort1__x__) {                                                                      \
				__mu9_bubble_sort1__x__ = mu0_true;                                                               \
				__mu9_bubble_sort1__j__ = __first;                                                                \
				__mu9_bubble_sort1__k__ = __mu9_bubble_sort1__j__++;                                              \
				for (; __mu9_bubble_sort1__j__ != __last; ++__mu9_bubble_sort1__k__, ++__mu9_bubble_sort1__j__) { \
					if (*__mu9_bubble_sort1__j__ < *__mu9_bubble_sort1__k__) {                                     \
						mu9_iter_swap(_Tp, __mu9_bubble_sort1__j__, __mu9_bubble_sort1__k__);                       \
						__mu9_bubble_sort1__x__ = mu0_false;                                                        \
					}                                                                                              \
				}                                                                                                 \
				--__last;                                                                                         \
		}                                                                                                       \
	}                                                                                                          \
mu0_scope_end

#	define mu9_bubble_sort2(_Tp, __first, __last, __comp_fn)                                                   \
mu0_scope_begin                                                                                               \
	_Tp *       __mu9_bubble_sort2__j__;                                                                       \
	_Tp *       __mu9_bubble_sort2__k__;                                                                       \
	mu0_bool_t __mu9_bubble_sort2__x__ = mu0_false;                                                            \
	if (__first != __last) {                                                                                   \
		while (!__mu9_bubble_sort2__x__) {                                                                      \
				__mu9_bubble_sort2__x__ = mu0_true;                                                               \
				__mu9_bubble_sort2__j__ = __first;                                                                \
				__mu9_bubble_sort2__k__ = __mu9_bubble_sort2__j__++;                                              \
				for (; __mu9_bubble_sort2__j__ != __last; ++__mu9_bubble_sort2__k__, ++__mu9_bubble_sort2__j__) { \
					if (_comp_fn(_Tp, *__mu9_bubble_sort2__j__, *__mu9_bubble_sort2__k__)) {                       \
						mu9_iter_swap(_Tp, __mu9_bubble_sort2__j__, __mu9_bubble_sort2__k__);                       \
						__mu9_bubble_sort2__x__ = mu0_false;                                                        \
					}                                                                                              \
				}                                                                                                 \
				--__last;                                                                                         \
		}                                                                                                       \
	}                                                                                                          \
mu0_scope_end

#	define mu9_bubble_sort3(_Tp, __first, __last, __sort_op, __ctx)                                            \
mu0_scope_begin                                                                                               \
	_Tp *      __mu9_bubble_sort3__j__;                                                                        \
	_Tp *      __mu9_bubble_sort3__k__;                                                                        \
	mu0_bool_t __mu9_bubble_sort3__x__ = mu0_false;                                                            \
	if (__first != __last) {                                                                                   \
		while (!__mu9_bubble_sort3__x__) {                                                                      \
				__mu9_bubble_sort3__x__ = mu0_true;                                                               \
				__mu9_bubble_sort3__j__ = __first;                                                                \
				__mu9_bubble_sort3__k__ = __mu9_bubble_sort3__j__++;                                              \
				for (; __mu9_bubble_sort3__j__ != __last; ++__mu9_bubble_sort3__k__, ++__mu9_bubble_sort3__j__) { \
					if (__sort_op(_Tp, *__mu9_bubble_sort3__j__, *__mu9_bubble_sort3__k__, __ctx)) {               \
						mu9_iter_swap(_Tp, __mu9_bubble_sort3__j__, __mu9_bubble_sort3__k__);                       \
						__mu9_bubble_sort3__x__ = mu0_false;                                                        \
					}                                                                                              \
				}                                                                                                 \
				--__last;                                                                                         \
		}                                                                                                       \
	}                                                                                                          \
mu0_scope_end

#	define mu9_bubble_sort4(_Tp, __first, __last)                                             \
mu0_scope_begin                                                                              \
	_Tp * __mu9_bubble_sort4__i__ = __first;                                                  \
	_Tp * __mu9_bubble_sort4__j__;                                                            \
	for (; __mu9_bubble_sort4__i__ != __last; ++__mu9_bubble_sort4__i__) {                    \
			__mu9_bubble_sort4__j__ = __first;                                                  \
		for (; __mu9_bubble_sort4__j__ < __mu9_bubble_sort4__j__; ++__mu9_bubble_sort4__j__) { \
			if (*__mu9_bubble_sort4__i__ < *__mu9_bubble_sort4__j__) {                          \
				mu9_iter_swap(_Tp, __mu9_bubble_sort4__i__, __mu9_bubble_sort4__j__);            \
			}                                                                                   \
		}                                                                                      \
	}                                                                                         \
mu0_scope_end

#	define mu9_bubble_sort5(_Tp, __first, __last, __comp_fn)                                  \
mu0_scope_begin                                                                              \
	_Tp * __mu9_bubble_sort5__i__ = __first;                                                  \
	_Tp * __mu9_bubble_sort5__j__;                                                            \
	for (; __mu9_bubble_sort5__i__ != __last; ++__mu9_bubble_sort5__i__) {                    \
			__mu9_bubble_sort5__j__ = __first;                                                  \
		for (; __mu9_bubble_sort5__j__ < __mu9_bubble_sort5__j__; ++__mu9_bubble_sort5__j__) { \
			if (_comp_fn(_Tp, *__mu9_bubble_sort5__i__, *__mu9_bubble_sort5__j__)) {            \
				mu9_iter_swap(_Tp, __mu9_bubble_sort4__i__, __mu9_bubble_sort5__j__);            \
			}                                                                                   \
		}                                                                                      \
	}                                                                                         \
mu0_scope_end

#	define mu9_bubble_sort6(_Tp, __first, __last, __sort_op, __ctx)                           \
mu0_scope_begin                                                                              \
	_Tp * __mu9_bubble_sort6__i__ = __first;                                                  \
	_Tp * __mu9_bubble_sort6__j__;                                                            \
	for (; __mu9_bubble_sort6__i__ != __last; ++__mu9_bubble_sort6__i__) {                    \
			__mu9_bubble_sort6__j__ = __first;                                                  \
		for (; __mu9_bubble_sort6__j__ < __mu9_bubble_sort6__j__; ++__mu9_bubble_sort6__j__) { \
			if (__sort_op(_Tp, *__mu9_bubble_sort6__i__, *__mu9_bubble_sort6__j__, __ctx)) {    \
				mu9_iter_swap(_Tp, __mu9_bubble_sort4__i__, __mu9_bubble_sort6__j__);            \
			}                                                                                   \
		}                                                                                      \
	}                                                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_BUBBLE_SORT_H */

/* EOF */