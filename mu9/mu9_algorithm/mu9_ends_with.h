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

// mu9_ends_with.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_ENDS_WITH_H
#define MU9_ENDS_WITH_H 1

MU0_BEGIN_CDECL

#	define mu9_ends_with1(_Tp, __first1, __last1, __first2, __last2, __d_result)               \
mu0_scope_begin                                                                               \
	      mu0_bool_t     __mu9_ends_with1__x__ = mu0_false;                                    \
	const mu0_distance_t __mu9_ends_with1__n__ = mu9_const_distance(_Tp, __first1, __last1);   \
	const mu0_distance_t __mu9_ends_with1__k__ = mu9_const_distance(_Tp, __first2, __last2);   \
	      mu0_distance_t __mu9_ends_with1__m__ = mu0_const_distance(0);                        \
	      _Tp *          __mu9_ends_with1__i__;                                                \
	      _Tp *          __mu9_ends_with1__j__;                                                \
	if (__mu9_ends_with1__n__ && __mu9_ends_with1__k__ >= __mu9_ends_with1__n__) {             \
		__mu9_ends_with1__i__ = __last1;                                                        \
		__mu9_ends_with1__j__ = __last2;                                                        \
		__mu9_ends_with1__x__ = mu0_true;                                                       \
		--__mu9_ends_with1__i__;                                                                \
		--__mu9_ends_with1__j__;                                                                \
		for (; __mu9_ends_with1__m__ < __mu9_ends_with1__n__; (void) __mu9_ends_with1__m__++) { \
			if (!(*__mu9_ends_with1__i__-- == *__mu9_ends_with1__j__--)) {                       \
				__mu9_ends_with1__x__ = mu0_false;                                                \
				break;                                                                            \
			}                                                                                    \
		}                                                                                       \
		__first1 = __mu9_ends_with1__i__;                                                       \
		__first2 = __mu9_ends_with1__j__;                                                       \
	}                                                                                          \
	__d_result = __mu9_ends_with1__x__;                                                        \
mu0_scope_end

#	define mu9_ends_with2(_Tp, __first1, __last1, __first2, __last2, __binary_pred, __d_result) \
mu0_scope_begin                                                                                \
	      mu0_bool_t     __mu9_ends_with2__x__ = mu0_false;                                     \
	const mu0_distance_t __mu9_ends_with2__n__ = mu9_const_distance(_Tp, __first1, __last1);    \
	const mu0_distance_t __mu9_ends_with2__k__ = mu9_const_distance(_Tp, __first2, __last2);    \
	      mu0_distance_t __mu9_ends_with2__m__ = mu0_const_distance(0);                         \
	      _Tp *          __mu9_ends_with2__i__;                                                 \
	      _Tp *          __mu9_ends_with2__j__;                                                 \
	if (__mu9_ends_with2__n__ && __mu9_ends_with2__k__ >= __mu9_ends_with2__n__) {              \
		__mu9_ends_with2__i__ = __last1;                                                         \
		__mu9_ends_with2__j__ = __last2;                                                         \
		__mu9_ends_with2__x__ = mu0_true;                                                        \
		--__mu9_ends_with2__i__;                                                                 \
		--__mu9_ends_with2__j__;                                                                 \
		for (; __mu9_ends_with2__m__ < __mu9_ends_with2__n__; (void) __mu9_ends_with2__m__++) {  \
			if (!__binary_pred(_Tp, *__mu9_ends_with2__i__--, *__mu9_ends_with2__j__--)) {        \
				__mu9_ends_with2__x__ = mu0_false;                                                 \
				break;                                                                             \
			}                                                                                     \
		}                                                                                        \
		__first1 = __mu9_ends_with2__i__;                                                        \
		__first2 = __mu9_ends_with2__j__;                                                        \
	}                                                                                           \
	__d_result = __mu9_ends_with2__x__;                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ENDS_WITH_H */

/* EOF */