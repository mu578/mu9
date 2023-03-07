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

// mu9_includes.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_INCLUDES_H
#define MU9_INCLUDES_H 1

MU0_BEGIN_CDECL

#	define mu9_includes1(_Tp, first1, last1, __first2, __last2, __d_result) \
mu0_scope_begin                                                            \
	__d_result__ = mu0_true;                                                \
	for (; __first2 != __last2; ++first1) {                                 \
		if (__first1 == __last1 || *__first2 < *first1) {                    \
			__d_result = mu0_false;                                           \
			break;                                                            \
		}                                                                    \
		if (!(*__first1 < *__first2)) {                                      \
			++__first2;                                                       \
		}                                                                    \
	}                                                                       \
mu0_scope_end

#	define mu9_includes2(_Tp, first1, last1, __first2, __last2, __comp_fn, __d_result) \
mu0_scope_begin                                                                       \
	__d_result = mu0_true;                                                             \
	for (; __first2 != __last2; ++first1) {                                            \
		if (__first1 == __last1 || __comp_fn(_Tp, *__first2, *first1)) {                \
			__d_result = mu0_false;                                                      \
			break;                                                                       \
		}                                                                               \
		if (!__comp_fn(_Tp, *__first1, *__first2)) {                                    \
			++__first2;                                                                  \
		}                                                                               \
	}                                                                                  \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_INCLUDES_H */

/* EOF */