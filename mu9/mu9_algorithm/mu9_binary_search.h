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

// mu9_binary_search.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_lower_bound.h>

#ifndef MU9_BINARY_SEARCH_H
#define MU9_BINARY_SEARCH_H 1

MU0_BEGIN_CDECL

#	define mu9_binary_search1(_Tp, __first, __last, __value, __d_result)            \
mu0_scope_begin                                                                    \
	_Tp * __mu9_lower_bound1__d__;                                                  \
	mu9_lower_bound1(__Tp, __first, __last, __value, __mu9_lower_bound1__d__);      \
	__d_result = (                                                                  \
		(__mu9_lower_bound1__d__ != __last && !(__value < *__mu9_lower_bound1__d__)) \
			? mu0_true                                                                \
			: mu0_false                                                               \
	);                                                                              \
mu0_scope_end

#	define mu9_binary_search2(_Tp, __first, __last, __value, __comp_fn, __d_result)                    \
mu0_scope_begin                                                                                       \
	_Tp * __mu9_lower_bound2__d__;                                                                     \
	mu9_lower_bound2(__Tp, __first, __last, __value, __comp_fn, __mu9_lower_bound2__d__);              \
	__d_result = ((__mu9_lower_bound2__d__ != __last && !__comp_fn(__value, *__mu9_lower_bound2__d__)) \
		? mu0_true                                                                                      \
		: mu0_false                                                                                     \
	);                                                                                                 \
mu0_scope_end

#	define mu9_binary_search3(_Tp, __first, __last, __value, __comp_op, __arg, __d_result)                         \
mu0_scope_begin                                                                                                   \
	_Tp * __mu9_lower_bound2__d__;                                                                                 \
	mu9_lower_bound3(__Tp, __first, __last, __value, __comp_op, __arg, __mu9_lower_bound2__d__);                   \
	__d_result = ((__mu9_lower_bound2__d__ != __last && !__comp_op(_Tp, __value, *__mu9_lower_bound2__d__, __arg)) \
		? mu0_true                                                                                                  \
		: mu0_false                                                                                                 \
	);                                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_BINARY_SEARCH_H */

/* EOF */