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

// mu9_inner_product.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_INNER_PRODUCT_H
#define MU9_INNER_PRODUCT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_inner_product1(_Tp, __first1, __last1, __first2, __init, __d_result)         \
mu0_scope_begin                                                                            \
	_Tp __mu9_inner_product1__v__ = mu0_const_cast(_Tp, __init);                            \
	while (__first1 != __last1) {                                                           \
		__mu9_inner_product1__v__ = __mu9_inner_product1__v__ + ((*__first1) * (*__first2)); \
		++__first1;                                                                          \
		++__first2;                                                                          \
	}                                                                                       \
	__d_result = __mu9_inner_product1__v__;                                                 \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op1<_Tp>, __binary_op2<_Tp>, _Tp<return> & __d_result) : void
//#!
#	define mu9_inner_product2(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result)           \
mu0_scope_begin                                                                                                          \
	_Tp __mu9_inner_product2__v__ = mu0_const_cast(_Tp, __init);                                                          \
	while (__first1 != __last1) {                                                                                         \
		__mu9_inner_product2__v__ = __binary_op1(_Tp, __mu9_inner_product2__v__, __binary_op2(_Tp, *__first1, *__first2)); \
		++__first1;                                                                                                        \
		++__first2;                                                                                                        \
	}                                                                                                                     \
	__d_result = __mu9_inner_product2__v__;                                                                               \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __trinary_op<_Tp>, _Tp<return> & __d_result) : void
//#!
#	define mu9_inner_product3(_Tp, __first1, __last1, __first2, __init, __trinary_op, __d_result)      \
mu0_scope_begin                                                                                       \
	_Tp __mu9_inner_product3__v__ = mu0_const_cast(_Tp, __init);                                       \
	while (__first1 != __last1) {                                                                      \
		__mu9_inner_product3__v__ = __trinary_op(_Tp, *__first1, *__first2, __mu9_inner_product3__v__); \
		++__first1;                                                                                     \
		++__first2;                                                                                     \
	}                                                                                                  \
	__d_result = __mu9_inner_product3__v__;                                                            \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_INNER_PRODUCT_H */

/* EOF */