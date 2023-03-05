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

// mu9_selection_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_min_element.h>

#ifndef MU9_SELECTION_SORT_H
#define MU9_SELECTION_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_selection_sort1(_Tp, __first, __last)                       \
mu0_scope_begin                                                           \
	_Tp * __mu9_selection_sort1__d__;                                      \
	for (; __first != __last; ++__first) {                                 \
		mu9_min_element1(_Tp, __first, __last, __mu9_selection_sort1__d__); \
		if (*__mu9_selection_sort1__d__ < *__first) {                       \
			mu9_iter_swap(_Tp, __mu9_selection_sort1__d__, __first);         \
		}                                                                   \
	}                                                                      \
mu0_scope_end

#	define mu9_selection_sort2(_Tp, __first, __last, __comp_fn)                       \
mu0_scope_begin                                                                      \
	_Tp * __mu9_selection_sort2__d__;                                                 \
	for (; __first != __last; ++__first) {                                            \
		mu9_min_element2(_Tp, __first, __last, __comp_fn, __mu9_selection_sort2__d__); \
		if (_comp_fn(_Tp, *__mu9_selection_sort2__d__, *__first)) {                    \
			mu9_iter_swap(_Tp, __mu9_selection_sort2__d__, __first);                    \
		}                                                                              \
	}                                                                                 \
mu0_scope_end

#	define mu9_selection_sort3(_Tp, __first, __last, __sort_op, __ctx)                       \
mu0_scope_begin                                                                             \
	_Tp * __mu9_selection_sort3__d__;                                                        \
	for (; __first != __last; ++__first) {                                                   \
		mu9_min_element3(_Tp, __first, __last, __sort_op, __ctx, __mu9_selection_sort3__d__); \
		if (__sort_op(_Tp, *__mu9_selection_sort3__d__, *__first, __ctx)) {                   \
			mu9_iter_swap(_Tp, __mu9_selection_sort3__d__, __first);                           \
		}                                                                                     \
	}                                                                                        \
mu0_scope_end

#	define mu9_selection_sort4(_Tp, __first, __last)                       \
mu0_scope_begin                                                           \
	_Tp * __mu9_selection_sort4__d__;                                      \
	for (; __first != __last; ++__first) {                                 \
		mu9_min_element1(_Tp, __first, __last, __mu9_selection_sort4__d__); \
		mu9_iter_swap(_Tp, __mu9_selection_sort4__d__, __first);            \
	}                                                                      \
mu0_scope_end

#	define mu9_selection_sort5(_Tp, __first, __last, __comp_fn)                       \
mu0_scope_begin                                                                      \
	_Tp * __mu9_selection_sort5__d__;                                                 \
	for (; __first != __last; ++__first) {                                            \
		mu9_min_element2(_Tp, __first, __last, __comp_fn, __mu9_selection_sort5__d__); \
		mu9_iter_swap(_Tp, __mu9_selection_sort5__d__, __first);                       \
	}                                                                                 \
mu0_scope_end

#	define mu9_selection_sort6(_Tp, __first, __last, __sort_op, __ctx)                       \
mu0_scope_begin                                                                             \
	_Tp * __mu9_selection_sort6__d__;                                                        \
	for (; __first != __last; ++__first) {                                                   \
		mu9_min_element3(_Tp, __first, __last, __sort_op, __ctx, __mu9_selection_sort6__d__); \
		mu9_iter_swap(_Tp, __mu9_selection_sort6__d__, __first);                              \
	}                                                                                        \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SELECTION_SORT_H */

/* EOF */