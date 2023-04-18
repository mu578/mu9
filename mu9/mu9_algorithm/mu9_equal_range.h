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

// mu9_equal_range.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_lower_bound.h>
#include <mu9/mu9_algorithm/mu9_upper_bound.h>

#ifndef MU9_EQUAL_RANGE_H
#define MU9_EQUAL_RANGE_H 1

MU0_BEGIN_CDECL

#	define mu9_equal_range1(_Tp, __first, __last, __value, __d_result1, __d_result2) \
	mu9_lower_bound1(__Tp, __first, __last, __value, __d_result1);                   \
	mu9_upper_bound1(__Tp, __first, __last, __value, __d_result2)

#	define mu9_equal_range2(_Tp, __first, __last, __value, __comp_fn, __d_result1, __d_result2) \
	mu9_lower_bound2(__Tp, __first, __last, __value, __comp_fn, __d_result1);                   \
	mu9_upper_bound2(__Tp, __first, __last, __value, __comp_fn, __d_result2)

MU0_END_CDECL

#endif /* !MU9_EQUAL_RANGE_H */

/* EOF */