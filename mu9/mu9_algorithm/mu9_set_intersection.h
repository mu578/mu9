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

// mu9_set_intersection.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_SET_INTERSECTION_H
#define MU9_SET_INTERSECTION_H 1

MU0_BEGIN_CDECL

#	define mu9_set_intersection1(_Tp, __first1, __last1, __first2, __last2, __d_first) \
mu0_scope_begin                                                                       \
	while (__first1 != __last1 && __first2 != __last2) {                               \
		if (*__first1 < *__first2) {                                                    \
			++__first1;                                                                  \
		} else {                                                                        \
			if (!(*__first2 < *__first1)) {                                              \
				*__d_first++ = *__first1++;                                               \
			}                                                                            \
			++__first2;                                                                  \
		}                                                                               \
	}                                                                                  \
mu0_scope_end

#	define mu9_set_intersection2(_Tp, __first1, __last1, __first2, __last2, __d_first, __comp_fn) \
mu0_scope_begin                                                                                  \
	while (__first1 != __last1 && __first2 != __last2) {                                          \
		if (__comp_fn(*__first1, *__first2)) {                                                     \
			++__first1;                                                                             \
		} else {                                                                                   \
			if (!__comp_fn(*__first2, *__first1)) {                                                 \
				*__d_first++ = *__first1++;                                                          \
			}                                                                                       \
			++__first2;                                                                             \
		}                                                                                          \
	}                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SET_INTERSECTION_H */

/* EOF */