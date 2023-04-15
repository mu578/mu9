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

// mu9_filter.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_FILTER_H
#define MU9_FILTER_H 1

MU0_BEGIN_CDECL

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

#endif /* !MU9_FILTER_H */

/* EOF */