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

// mu9_min_element.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_MIN_ELEMENT_H
#define MU9_MIN_ELEMENT_H 1

MU0_BEGIN_CDECL

#	define mu9_min_element1(_Tp, __first, __last, __d_result) \
mu0_scope_begin                                              \
	_Tp * __mu9_min_element1_i__ = __last;                    \
	if (__first != __last) {                                  \
		__mu9_min_element1_i__ = __first;                      \
		++__first;                                             \
		for (; __first != __last; ++__first) {                 \
			if (*__first < *__mu9_min_element1_i__) {           \
				__mu9_min_element1_i__ = __first;                \
			}                                                   \
		}                                                      \
	}                                                         \
	__d_result = __mu9_min_element1_i__;                      \
mu0_scope_end

#	define mu9_min_element2(_Tp, __first, __last, __comp_fn, __d_result) \
mu0_scope_begin                                                         \
	_Tp * __mu9_min_element2_i__ = __last;                               \
	if (__first != __last) {                                             \
		__mu9_min_element2_i__ = __first;                                 \
		++__first;                                                        \
		for (; __first != __last; ++__first) {                            \
			if (__comp_fn(_Tp, *__first, *__mu9_min_element2_i__)) {       \
				__mu9_min_element2_i__ = __first;                           \
			}                                                              \
		}                                                                 \
	}                                                                    \
	__d_result = __mu9_min_element2_i__;                                 \
mu0_scope_end

#	define mu9_min_element3(_Tp, __first, __last, __sort_op, __ctx, __d_result) \
mu0_scope_begin                                                                \
	_Tp * __mu9_min_element3_i__ = __last;                                      \
	if (__first != __last) {                                                    \
		__mu9_min_element3_i__ = __first;                                        \
		++__first;                                                               \
		for (; __first != __last; ++__first) {                                   \
			if (__sort_op(_Tp, *__first, *__mu9_min_element3_i__, __ctx)) {       \
				__mu9_min_element3_i__ = __first;                                  \
			}                                                                     \
		}                                                                        \
	}                                                                           \
	__d_result = __mu9_min_element3_i__;                                        \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MIN_ELEMENT_H */

/* EOF */