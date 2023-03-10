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

// mu9_copy.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_COPY_H
#define MU9_COPY_H 1

MU0_BEGIN_CDECL

#	define mu9_copy(_Tp, __first, __last, __d_first)                  \
mu0_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		*__d_first = *__first;                                         \
	}                                                                 \
mu0_scope_end


#	define mu9_copy_backward(Tp, __first, __last, __d_first)                                             \
mu0_scope_begin                                                                                         \
	_Tp * __mu9_copy_backward__i__ = __last;                                                             \
	for (; __first != __mu9_copy_backward__i__; (void) --__mu9_copy_backward__i__, (void) ++__d_first) { \
		*__d_first = *__mu9_copy_backward__i__;                                                           \
	}                                                                                                    \
mu0_scope_end

#	define mu9_copy_if(_Tp, __first, __last, __d_first, __unary_pred) \
mu0_scope_begin                                                      \
	for (; __first != __last; ++__first) {                            \
		if (__unary_pred(_Tp, *__first)) {                             \
			*__d_first = *__first;                                      \
			++__d_first;                                                \
		}                                                              \
	}                                                                 \
mu0_scope_end

#	define mu9_copy_if_not(_Tp, __first, __last, __d_first, __unary_pred) \
mu0_scope_begin                                                          \
	for (; __first != __last; ++__first) {                                \
		if (!__unary_pred(_Tp, *__first)) {                                \
			*__d_first = *__first;                                          \
			++__d_first;                                                    \
		}                                                                  \
	}                                                                     \
mu0_scope_end

#	define mu9_copy_to(_Tp, __first, __last, __d_first, __d_result)   \
mu0_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		*__d_first = *__first;                                         \
	}                                                                 \
	__d_result = __d_first;                                           \
mu0_scope_end

#	define mu9_copy_to_if(_Tp, __first, __last, __d_first, __unary_pred, __d_result) \
mu0_scope_begin                                                                     \
	for (; __first != __last; ++__first) {                                           \
		if (__unary_pred(_Tp, *__first)) {                                            \
			*__d_first = *__first;                                                     \
			++__d_first;                                                               \
		}                                                                             \
	}                                                                                \
	__d_result = __d_first;                                                          \
mu0_scope_end

#	define mu9_copy_to_if_not(_Tp, __first, __last, __d_first, __unary_pred, __d_result) \
mu0_scope_begin                                                                         \
	for (; __first != __last; ++__first) {                                               \
		if (!__unary_pred(_Tp, *__first)) {                                               \
			*__d_first = *__first;                                                         \
			++__d_first;                                                                   \
		}                                                                                 \
	}                                                                                    \
	__d_result = __d_first;                                                              \
mu0_scope_end

#	define mu9_filter(_Tp, __first1, __last1, __first2, __last2, __unary_pred, __d_result) \
mu0_scope_begin                                                                           \
	_Tp * __mu9_filter__i__ = __first2;                                                    \
	for (; __first1 != __last1 && __first2 != __last2; ++__first1) {                       \
		if (__unary_pred(_Tp, *__first)) {                                                  \
			*__first2 = *__first;                                                            \
			++__first2;                                                                      \
		}                                                                                   \
	}                                                                                      \
	__d_result = mu9_const_distance(_Tp, __mu9_filter__i__, __first2);                     \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_COPY_H */

/* EOF */