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

// mu9_random_sample.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_random_sample_n.h>

#ifndef MU9_RANDOM_SAMPLE_H
#define MU9_RANDOM_SAMPLE_H 1

MU0_BEGIN_CDECL

#	define mu9_random_sample1(_Tp, __first, __last, __d_first, __d_last, __d_result) \
	mu9_random_sample_n1(_Tp, __first, __last, __d_first, (__d_last - __d_first), __d_result)

#	define mu9_random_sample2(_Tp, __first, __last, __d_first, __d_last, __rand_fn, __d_result) \
	mu9_random_sample_n2(_Tp, __first, __last, __d_first, (__d_last - __d_first), __rand_fn, __d_result)

#	define mu9_random_sample3(_Tp, __first, __last, __d_first, __d_last, __move_op, __d_result) \
	mu9_random_sample_n3(_Tp, __first, __last, __d_first, (__d_last - __d_first), __move_op, __d_result)

#	define mu9_random_sample4(_Tp, __first, __last, __d_first, __d_last, __rand_fn, __move_op, __d_result) \
	mu9_random_sample_n4(_Tp, __first, __last, __d_first, (__d_last - __d_first), __rand_fn, __move_op, __d_result)

MU0_END_CDECL

#endif /* !MU9_RANDOM_SAMPLE_H */

/* EOF */