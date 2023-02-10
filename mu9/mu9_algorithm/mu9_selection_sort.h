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

#include <mu9/mu9_iterator.h>
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
		mu9_min_element2(_Tp, __first, __last, __comp_fn, __mu9_selection_sort2__d__);  \
		if (__comp_fn(*__mu9_selection_sort2__d__, *__first)) {                        \
			mu9_iter_swap(_Tp, __mu9_selection_sort2__d__, __first);                    \
		}                                                                              \
	}                                                                                 \
mu0_scope_end

#	define mu9_selection_sort3(_Tp, __first, __last, __comp_fn, __ctx)                       \
mu0_scope_begin                                                                             \
	_Tp * __mu9_selection_sort3__d__;                                                        \
	for (; __first != __last; ++__first) {                                                   \
		mu9_min_element3(_Tp, __first, __last, __comp_fn, __ctx, __mu9_selection_sort3__d__); \
		if (__comp_fn(*__mu9_selection_sort3__d__, *__first, __ctx)) {                        \
			mu9_iter_swap(_Tp, __mu9_selection_sort3__d__, __first);                           \
		}                                                                                     \
	}                                                                                        \
mu0_scope_end

#	define mu9_selection_sort4(_Tp, __first, __last)                                \
mu0_scope_begin                                                                    \
	_Tp * __mu9_selection_sort4__i__ = __first;                                     \
	_Tp * __mu9_selection_sort4__j__;                                               \
	_Tp * __mu9_selection_sort4__k__;                                               \
	for (; __mu9_selection_sort4__i__ != __last; __mu9_selection_sort4__i__++) {    \
		__mu9_selection_sort4__k__ = __mu9_selection_sort4__i__;                     \
		__mu9_selection_sort4__j__ = mu9_advance(__mu9_selection_sort4__i__);        \
		for (; __mu9_selection_sort4__j__ != __last; __mu9_selection_sort4__j__++) { \
			if (*__mu9_selection_sort4__j__ < *__mu9_selection_sort4__k__) {          \
				__mu9_selection_sort4__k__ = __mu9_selection_sort4__j__;               \
			}                                                                         \
			mu9_swap(_Tp, *__mu9_selection_sort4__k__, *__mu9_selection_sort4__i__);  \
		}                                                                            \
	}                                                                               \
mu0_scope_end

#	define mu9_selection_sort5(_Tp, __first, __last, __comp_fn)                      \
mu0_scope_begin                                                                     \
	_Tp * __mu9_selection_sort5__i__ = __first;                                      \
	_Tp * __mu9_selection_sort5__j__;                                                \
	_Tp * __mu9_selection_sort5__k__;                                                \
	for (; __mu9_selection_sort5__i__ != __last; __mu9_selection_sort5__i__++) {     \
		__mu9_selection_sort5__k__ = __mu9_selection_sort5__i__;                      \
		__mu9_selection_sort5__j__ = mu9_advance(__mu9_selection_sort5__i__);         \
		for (; __mu9_selection_sort5__j__ != __last; __mu9_selection_sort5__j__++) {  \
			if (__comp_fn(*__mu9_selection_sort5__j__, *__mu9_selection_sort5__k__)) { \
				__mu9_selection_sort5__k__ = __mu9_selection_sort5__j__;                \
			}                                                                          \
			mu9_swap(_Tp, *__mu9_selection_sort5__k__, *__mu9_selection_sort5__i__);   \
		}                                                                             \
	}                                                                                \
mu0_scope_end

#	define mu9_selection_sort6(_Tp, __first, __last, __comp_fn, __ctx)                      \
mu0_scope_begin                                                                            \
	_Tp * __mu9_selection_sort6__i__ = __first;                                             \
	_Tp * __mu9_selection_sort6__j__;                                                       \
	_Tp * __mu9_selection_sort6__k__;                                                       \
	for (; __mu9_selection_sort6__i__ != __last; __mu9_selection_sort6__i__++) {            \
		__mu9_selection_sort6__k__ = __mu9_selection_sort6__i__;                             \
		__mu9_selection_sort6__j__ = mu9_advance(__mu9_selection_sort6__i__);                \
		for (; __mu9_selection_sort6__j__ != __last; __mu9_selection_sort6__j__++) {         \
			if (__comp_fn(*__mu9_selection_sort6__j__, *__mu9_selection_sort6__k__, __ctx)) { \
				__mu9_selection_sort6__k__ = __mu9_selection_sort6__j__;                       \
			}                                                                                 \
			mu9_swap(_Tp, *__mu9_selection_sort6__k__, *__mu9_selection_sort6__i__);          \
		}                                                                                    \
	}                                                                                       \
mu0_scope_end

#	define mu9_selection_sort7(_Tp, __first, __last)                       \
mu0_scope_begin                                                           \
	_Tp * __mu9_selection_sort7__d__;                                      \
	for (; __first != __last; ++__first) {                                 \
		mu9_min_element1(_Tp, __first, __last, __mu9_selection_sort7__d__); \
		mu9_iter_swap(_Tp, __mu9_selection_sort7__d__, __first);            \
	}                                                                      \
mu0_scope_end

#	define mu9_selection_sort8(_Tp, __first, __last, __comp_fn)                       \
mu0_scope_begin                                                                      \
	_Tp * __mu9_selection_sort8__d__;                                                 \
	for (; __first != __last; ++__first) {                                            \
		mu9_min_element2(_Tp, __first, __last, __comp_fn, __mu9_selection_sort8__d__); \
		mu9_iter_swap(_Tp, __mu9_selection_sort8__d__, __first);                       \
	}                                                                                 \
mu0_scope_end

#	define mu9_selection_sort9(_Tp, __first, __last, __comp_fn)                              \
mu0_scope_begin                                                                             \
	_Tp * __mu9_selection_sort9__d__;                                                        \
	for (; __first != __last; ++__first) {                                                   \
		mu9_min_element3(_Tp, __first, __last, __comp_fn, __ctx, __mu9_selection_sort9__d__); \
		mu9_iter_swap(_Tp, __mu9_selection_sort9__d__, __first);                              \
	}                                                                                        \
mu0_scope_end


MU0_END_CDECL

#endif /* !MU9_SELECTION_SORT_H */

/* EOF */