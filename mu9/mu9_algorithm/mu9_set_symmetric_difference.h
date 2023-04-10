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

// mu9_set_symmetric_difference.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_copy.h>

#ifndef MU9_SET_SYMMETRIC_DIFFERENCE_H
#define MU9_SET_SYMMETRIC_DIFFERENCE_H 1

MU0_BEGIN_CDECL

#	define mu9_set_symmetric_difference1(_Tp, __first1, __last1, __first2, __last2, __d_first) \
mu0_scope_begin                                                                               \
	mu0_bool_t __mu9_set_symmetric_difference1__x__ = mu0_false;                               \
	while (__first1 != __last1) {                                                              \
		if (__first2 == __last2) {                                                              \
			mu9_copy(_Tp, __first1, __last1, __d_first);                                         \
			__mu9_set_symmetric_difference1__x__ = mu0_true;                                     \
			break;                                                                               \
		}                                                                                       \
		if (*__first1 < *__first2) {                                                            \
			*__d_first++ = *__first1++;                                                          \
		} else {                                                                                \
			if (*__first2 < *__first1) {                                                         \
				*__d_first++ = *__first2;                                                         \
			} else {                                                                             \
				++__first1;                                                                       \
			}                                                                                    \
			++__first2;                                                                          \
		}                                                                                       \
	}                                                                                          \
	if (!__mu9_set_symmetric_difference1__x__) {                                               \
		mu9_copy(_Tp, __first2, __last2, __d_first);                                            \
	}                                                                                          \
mu0_scope_end

#	define mu9_set_symmetric_difference2(_Tp, __first1, __last1, __first2, __last2, __d_first, __comp_fn) \
mu0_scope_begin                                                                                          \
	mu0_bool_t __mu9_set_symmetric_difference2__x__ = mu0_false;                                          \
	while (__first1 != __last1) {                                                                         \
		if (__first2 == __last2) {                                                                         \
			mu9_copy(_Tp, __first1, __last1, __d_first);                                                    \
			__mu9_set_symmetric_difference2__x__ = mu0_true;                                                \
			break;                                                                                          \
		}                                                                                                  \
		if (__comp_fn(_Tp, *__first1, *__first2)) {                                                        \
			*__d_first++ = *__first1++;                                                                     \
		} else {                                                                                           \
			if (__comp_fn(_Tp, *__first2, *__first1)) {                                                     \
				*__d_first++ = *__first2;                                                                    \
			} else {                                                                                        \
				++__first1;                                                                                  \
			}                                                                                               \
			++__first2;                                                                                     \
		}                                                                                                  \
	}                                                                                                     \
	if (!__mu9_set_symmetric_difference2__x__) {                                                          \
		mu9_copy(_Tp, __first2, __last2, __d_first);                                                       \
	}                                                                                                     \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SET_SYMMETRIC_DIFFERENCE_H */

/* EOF */