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

// mu9_stable_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_insertion_sort.h>

#ifndef MU9_STABLE_SORT_H
#define MU9_STABLE_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_stable_sort1(_Tp, __first, __last) \
	mu9_insertion_sort4(_Tp, __first, __last)

#	define mu9_stable_sort2(_Tp, __first, __last, __comp_fn) \
	mu9_insertion_sort5(_Tp, __first, __last, __comp_fn)

#	define mu9_stable_sort3(_Tp, __first, __last, __sort_op, __ctx) \
	mu9_insertion_sort6(_Tp, __first, __last, __sort_op, __ctx)

#	define mu9_stable_sort4(_Tp, __first, __last, __swap_op) \
	mu9_insertion_sort7(_Tp, __first, __last)

#	define mu9_stable_sort5(_Tp, __first, __last, __comp_fn, __swap_op) \
	mu9_insertion_sort8(_Tp, __first, __last, __comp_fn)

#	define mu9_stable_sort6(_Tp, __first, __last, __sort_op, __ctx, __swap_op) \
	mu9_insertion_sort9(_Tp, __first, __last, __sort_op, __ctx)

MU0_END_CDECL

#endif /* !MU9_STABLE_SORT_H */

/* EOF */