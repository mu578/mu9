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

// mu9_minmax_element.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_MINMAX_ELEMENT_H
#define MU9_MINMAX_ELEMENT_H 1

MU0_BEGIN_CDECL

#	define mu9_minmax_element1(_Tp, __first, __last, __d_result1, __d_result2)          \
mu0_scope_begin                                                                        \
	_Tp * __mu9_minmax_element1__i__ = __first;                                         \
	_Tp * __mu9_minmax_element1__j__ = __first;                                         \
	_Tp * __mu9_minmax_element1__k__;                                                   \
	if (!(__first == __last || ++__first == __last)) {                                  \
		if (*__first < *__mu9_minmax_element1__i__) {                                    \
			__mu9_minmax_element1__i__ = __first;                                         \
		} else {                                                                         \
			__mu9_minmax_element1__j__ = __first;                                         \
		}                                                                                \
		while (++__first != __last) {                                                    \
			__mu9_minmax_element1__k__ = __first;                                         \
			if (++__first == __last) {                                                    \
				if (*__mu9_minmax_element1__k__ < *__mu9_minmax_element1__i__) {           \
					__mu9_minmax_element1__i__ = __mu9_minmax_element1__k__;                \
				} else if (!(*__mu9_minmax_element1__k__ < *__mu9_minmax_element1__j__)) { \
					__mu9_minmax_element1__j__ = __mu9_minmax_element1__k__;                \
				}                                                                          \
				break;                                                                     \
			} else {                                                                      \
				if (*__first < *__mu9_minmax_element1__k__) {                              \
					if (*__first < *__mu9_minmax_element1__i__) {                           \
						__mu9_minmax_element1__i__ = __first;                                \
					}                                                                       \
					if (!(*__mu9_minmax_element1__k__ < *__mu9_minmax_element1__j__)) {     \
						__mu9_minmax_element1__j__ = __mu9_minmax_element1__k__;             \
					}                                                                       \
				} else {                                                                   \
					if (*__mu9_minmax_element1__k__ < *__mu9_minmax_element1__i__) {        \
						__mu9_minmax_element1__i__ = __mu9_minmax_element1__k__;             \
					}                                                                       \
					if (!(*__first < *__mu9_minmax_element1__j__)) {                        \
						__mu9_minmax_element1__j__ = __first;                                \
					}                                                                       \
				}                                                                          \
			}                                                                             \
		}                                                                                \
	}                                                                                   \
	__d_result1 = __mu9_minmax_element1__i__;                                           \
	__d_result2 = __mu9_minmax_element1__j__;                                           \
mu0_scope_end

#	define mu9_minmax_element2(_Tp, __first, __last, __comp_fn, __d_result1, __d_result2)         \
mu0_scope_begin                                                                                  \
	_Tp * __mu9_minmax_element2__i__ = __first;                                                   \
	_Tp * __mu9_minmax_element2__j__ = __first;                                                   \
	_Tp * __mu9_minmax_element2__k__;                                                             \
	if (!(__first == __last || ++__first == __last)) {                                            \
		if (__comp_fn(*__first, *__mu9_minmax_element2__i__)) {                                    \
			__mu9_minmax_element2__i__ = __first;                                                   \
		} else {                                                                                   \
			__mu9_minmax_element2__j__ = __first;                                                   \
		}                                                                                          \
		while (++__first != __last) {                                                              \
			__mu9_minmax_element2__k__ = __first;                                                   \
			if (++__first == __last) {                                                              \
				if (__comp_fn(*__mu9_minmax_element2__k__, *__mu9_minmax_element2__i__)) {           \
					__mu9_minmax_element2__i__ = __mu9_minmax_element2__k__;                          \
				} else if (!(__comp_fn(*__mu9_minmax_element2__k__, *__mu9_minmax_element2__j__))) { \
					__mu9_minmax_element2__j__ = __mu9_minmax_element2__k__;                          \
				}                                                                                    \
				break;                                                                               \
			} else {                                                                                \
				if (__comp_fn(*__first, *__mu9_minmax_element2__k__)) {                              \
					if (__comp_fn(*__first, *__mu9_minmax_element2__i__)) {                           \
						__mu9_minmax_element2__i__ = __first;                                          \
					}                                                                                 \
					if (!(__comp_fn(*__mu9_minmax_element2__k__, *__mu9_minmax_element2__j__))) {     \
						__mu9_minmax_element2__j__ = __mu9_minmax_element2__k__;                       \
					}                                                                                 \
				} else {                                                                             \
					if (__comp_fn(*__mu9_minmax_element2__k__, *__mu9_minmax_element2__i__)) {        \
						__mu9_minmax_element2__i__ = __mu9_minmax_element2__k__;                       \
					}                                                                                 \
					if (!(__comp_fn(*__first, *__mu9_minmax_element2__j__))) {                        \
						__mu9_minmax_element2__j__ = __first;                                          \
					}                                                                                 \
				}                                                                                    \
			}                                                                                       \
		}                                                                                          \
	}                                                                                             \
	__d_result1 = __mu9_minmax_element2__i__;                                                     \
	__d_result2 = __mu9_minmax_element2__j__;                                                     \
mu0_scope_end

#	define mu9_minmax_element3(_Tp, __first, __last, __sort_fn, __ctx, __d_result1, __d_result2)         \
mu0_scope_begin                                                                                         \
	_Tp * __mu9_minmax_element3__i__ = __first;                                                          \
	_Tp * __mu9_minmax_element3__j__ = __first;                                                          \
	_Tp * __mu9_minmax_element3__k__;                                                                    \
	if (!(__first == __last || ++__first == __last)) {                                                   \
		if (__sort_fn(*__first, *__mu9_minmax_element3__i__, __ctx)) {                                    \
			__mu9_minmax_element3__i__ = __first;                                                          \
		} else {                                                                                          \
			__mu9_minmax_element3__j__ = __first;                                                          \
		}                                                                                                 \
		while (++__first != __last) {                                                                     \
			__mu9_minmax_element3__k__ = __first;                                                          \
			if (++__first == __last) {                                                                     \
				if (__sort_fn(*__mu9_minmax_element3__k__, *__mu9_minmax_element3__i__, __ctx)) {           \
					__mu9_minmax_element3__i__ = __mu9_minmax_element3__k__;                                 \
				} else if (!(__sort_fn(*__mu9_minmax_element3__k__, *__mu9_minmax_element3__j__, __ctx))) { \
					__mu9_minmax_element3__j__ = __mu9_minmax_element3__k__;                                 \
				}                                                                                           \
				break;                                                                                      \
			} else {                                                                                       \
				if (__sort_fn(*__first, *__mu9_minmax_element3__k__)) {                                     \
					if (__sort_fn(*__first, *__mu9_minmax_element3__i__, __ctx)) {                           \
						__mu9_minmax_element3__i__ = __first;                                                 \
					}                                                                                        \
					if (!(__sort_fn(*__mu9_minmax_element3__k__, *__mu9_minmax_element3__j__, __ctx))) {     \
						__mu9_minmax_element3__j__ = __mu9_minmax_element3__k__;                              \
					}                                                                                        \
				} else {                                                                                    \
					if (__sort_fn(*__mu9_minmax_element3__k__, *__mu9_minmax_element3__i__, __ctx)) {        \
						__mu9_minmax_element3__i__ = __mu9_minmax_element3__k__;                              \
					}                                                                                        \
					if (!(__sort_fn(*__first, *__mu9_minmax_element3__j__, __ctx))) {                        \
						__mu9_minmax_element3__j__ = __first;                                                 \
					}                                                                                        \
				}                                                                                           \
			}                                                                                              \
		}                                                                                                 \
	}                                                                                                    \
	__d_result1 = __mu9_minmax_element3__i__;                                                            \
	__d_result2 = __mu9_minmax_element3__j__;                                                            \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MINMAX_ELEMENT_H */

/* EOF */