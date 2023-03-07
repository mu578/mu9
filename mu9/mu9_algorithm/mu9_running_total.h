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

// mu9_running_total.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_partial_sum.h>

#ifndef MU9_RUNNING_TOTAL_H
#define MU9_RUNNING_TOTAL_H 1

MU0_BEGIN_CDECL

#	define mu9_running_total(_Tp, __first, __last, __d_first)   \
mu0_scope_begin                                                \
	mu9_partial_sum2(_Tp, __first, __last, __d_first, mu9_plus); \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_RUNNING_TOTAL_H */

/* EOF */