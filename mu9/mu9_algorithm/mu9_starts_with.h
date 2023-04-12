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

// mu9_starts_with.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_STARTS_WITH_H
#define MU9_STARTS_WITH_H 1

MU0_BEGIN_CDECL

#	define mu9_starts_with1(_Tp, __first1, __last1, __first2, __last2, __d_result)                 \
mu0_scope_begin                                                                                   \
	      mu0_bool_t     __mu9_mu9_starts_with1__x__ = mu0_false;                                  \
	const mu0_distance_t __mu9_mu9_starts_with1__n__ = mu9_const_distance(_Tp, __first1, __last1); \
	const mu0_distance_t __mu9_mu9_starts_with1__k__ = mu9_const_distance(_Tp, __first2, __last2); \
	if (__mu9_mu9_starts_with1__k__ >= __mu9_mu9_starts_with1__n__) {                              \
		__mu9_mu9_starts_with1__x__ = mu0_true;                                                     \
		while (__first1 != __last1) {                                                               \
			if (!(*__first1++ == *__first2++)) {                                                     \
				__mu9_mu9_starts_with1__x__ = mu0_false;                                              \
				break;                                                                                \
			}                                                                                        \
		}                                                                                           \
	}                                                                                              \
	__d_result = __mu9_mu9_starts_with1__x__;                                                      \
mu0_scope_end

#	define mu9_starts_with2(_Tp, __first1, __last1, __first2, __last2, __binary_pred, __d_result)  \
mu0_scope_begin                                                                                   \
	      mu0_bool_t     __mu9_mu9_starts_with2__x__ = mu0_false;                                  \
	const mu0_distance_t __mu9_mu9_starts_with2__n__ = mu9_const_distance(_Tp, __first1, __last1); \
	const mu0_distance_t __mu9_mu9_starts_with2__k__ = mu9_const_distance(_Tp, __first2, __last2); \
	if (__mu9_mu9_starts_with2__k__ >= __mu9_mu9_starts_with2__n__) {                              \
		__mu9_mu9_starts_with2__x__ = mu0_true;                                                     \
		while (__first1 != __last1) {                                                               \
			if (!__binary_pred(_Tp, *__first1++, *__first2++)) {                                     \
				__mu9_mu9_starts_with2__x__ = mu0_false;                                              \
				break;                                                                                \
			}                                                                                        \
		}                                                                                           \
	}                                                                                              \
	__d_result = __mu9_mu9_starts_with2__x__;                                                      \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_STARTS_WITH_H */

/* EOF */