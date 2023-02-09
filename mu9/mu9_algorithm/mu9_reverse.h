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

// mu9_reverse.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_REVERSE_H
#define MU9_REVERSE_H 1

MU0_BEGIN_CDECL

#	define mu9_reverse1(_Tp, __first, __last)          \
mu0_scope_begin                                       \
	while (__first != __last && __first != --__last) { \
		mu9_iter_swap(_Tp, __first++, __last);          \
	}                                                  \
mu0_scope_end

#	define mu9_reverse2(_Tp, __first, __last) \
mu0_scope_begin                              \
	while (__first != __last) {               \
		if (__first == --__last) {             \
				break;                           \
		}                                      \
		mu9_iter_swap(_Tp, __first, __last);   \
		++__first;                             \
	}                                         \
mu0_scope_end

#	define mu9_reverse_copy(_Tp, __first1, __last1, __first2, __d_result) \
mu0_scope_begin                                                          \
	for (; __first1 != __last1; ++__first2) {                             \
		*__first2 = *--__last1;                                            \
	}                                                                     \
	__d_result = __first2;                                                \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_REVERSE_H */

/* EOF */