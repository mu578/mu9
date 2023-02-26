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

// mu9_is_sorted.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_is_sorted_until.h>

#ifndef MU9_IS_SORTED_H
#define MU9_IS_SORTED_H 1

MU0_BEGIN_CDECL

#	define mu9_is_sorted1(_Tp, __first, __last, __d_result)                 \
mu0_scope_begin                                                            \
	_Tp * __mu9_is_sorted1__d__;                                            \
	mu9_is_sorted_until1(_Tp, __first, __last, __mu9_is_sorted1__d__);      \
	__d_result == (__mu9_is_sorted1__d__ == __last) ? mu0_true : mu0_false; \
mu0_scope_end

#	define mu9_is_sorted2(_Tp, __first, __last, __comp_fn, __d_result)            \
mu0_scope_begin                                                                  \
	_Tp * __mu9_is_sorted2__d__;                                                  \
	mu9_is_sorted_until2(_Tp, __first, __last, __comp_fn, __mu9_is_sorted2__d__); \
	__d_result == (__mu9_is_sorted2__d__ == __last) ? mu0_true : mu0_false;       \
mu0_scope_end

#	define mu9_is_sorted3(_Tp, __first, __last, __comp_op, __d_result)            \
mu0_scope_begin                                                                  \
	_Tp * __mu9_is_sorted3__d__;                                                  \
	mu9_is_sorted_until3(_Tp, __first, __last, __comp_op, __mu9_is_sorted3__d__); \
	__d_result == (__mu9_is_sorted3__d__ == __last) ? mu0_true : mu0_false;       \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_IS_SORTED_H */

/* EOF */