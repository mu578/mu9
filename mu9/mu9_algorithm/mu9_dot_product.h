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

// mu9_dot_product.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_inner_product.h>

#ifndef MU9_DOT_PRODUCT_H
#define MU9_DOT_PRODUCT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, _Tp<return> & __d_result) : void
//#!
#	define mu9_dot_product1(_Tp, __first1, __last1, __first2, __d_result) \
	mu9_inner_product1(_Tp, __first1, __last1, __first2, 0, __d_result)

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, __binary_op1, __binary_op2<_Tp>, _Tp<return> & __d_result) : void
//#!
#	define mu9_dot_product2(_Tp, __first1, __last1, __first2, __binary_op1, __binary_op2, __d_result) \
	mu9_inner_product2(_Tp, __first1, __last1, __first2, 0, __binary_op1, __binary_op2, __d_result)

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, __trinary_op<_Tp>, _Tp<return> & __d_result) : void
//#!
#	define mu9_dot_product3(_Tp, __first1, __last1, __first2, __trinary_op, __d_result) \
	mu9_inner_product3(_Tp, __first1, __last1, __first2, 0, __trinary_op, __d_result)

MU0_END_CDECL

#endif /* !MU9_DOT_PRODUCT_H */

/* EOF */