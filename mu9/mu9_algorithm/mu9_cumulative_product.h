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

// mu9_cumulative_product.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>

#ifndef MU9_CUMULATIVE_PRODUCT_H
#define MU9_CUMULATIVE_PRODUCT_H 1

MU0_BEGIN_CDECL

#	define mu9_cumulative_product(_Tp, __first, __last, __d_result) \
	mu9_accumulate2(_Tp, __first, __last, mu9_initialize(_Tp, 1), mu9_multiplication, __d_result)

MU0_END_CDECL

#endif /* !MU9_CUMULATIVE_PRODUCT_H */

/* EOF */