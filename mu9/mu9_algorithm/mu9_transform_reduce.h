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

// mu9_transform_reduce.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_TRANSFORM_REDUCE_H
#define MU9_TRANSFORM_REDUCE_H 1

MU0_BEGIN_CDECL

#	define mu9_transform_reduce1(_Tp, __first1, __last1, __first2, __init, __d_result)            \
mu0_scope_begin                                                                                  \
	_Tp __mu9_transform_reduce1__v__ = mu0_const_cast(_Tp, __init);                               \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                  \
		__mu9_transform_reduce1__v__ = __mu9_transform_reduce1__v__ + ((*__first1) * (*__first2)); \
	}                                                                                             \
	__d_result = __mu9_transform_reduce1__v__;                                                    \
mu0_scope_end

#	define mu9_transform_reduce2(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result)                \
mu0_scope_begin                                                                                                                  \
	_Tp __mu9_transform_reduce2__v__ = mu0_const_cast(_Tp, __init);                                                               \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                                                  \
		__mu9_transform_reduce2__v__ = __binary_op1(_Tp, __mu9_transform_reduce2__v__, __binary_op2((_Tp, *__first1, *__first2))); \
	}                                                                                                                             \
	__d_result = __mu9_transform_reduce2__v__;                                                                                    \
mu0_scope_end

#	define mu9_transform_reduce3(_Tp, __first1, __last1, __first2, __init, __trinary_op, __d_result)         \
mu0_scope_begin                                                                                             \
	_Tp __mu9_transform_reduce3__v__ = mu0_const_cast(_Tp, __init);                                          \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                             \
		__mu9_transform_reduce3__v__ = __trinary_op(_Tp, __mu9_transform_reduce3__v__, *__first1, *__first2); \
	}                                                                                                        \
	__d_result = __mu9_transform_reduce3__v__;                                                               \
mu0_scope_end

#	define mu9_transform_reduce_if1(_Tp, __first1, __last1, __first2, __init, __unary_pred, __d_result)    \
mu0_scope_begin                                                                                           \
	_Tp __mu9_transform_reduce_if1__v__ = mu0_const_cast(_Tp, __init);                                     \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                           \
		if (__unary_pred(_Tp, *__first1)) {                                                                 \
			__mu9_transform_reduce_if1__v__ = __mu9_transform_reduce_if1__v__ + ((*__first1) * (*__first2)); \
		}                                                                                                   \
	}                                                                                                      \
	__d_result = __mu9_transform_reduce_if1__v__;                                                          \
mu0_scope_end

#	define mu9_transform_reduce_if2(_Tp, __first1, __last1, __first2, __init, __binary_pred, __d_result)   \
mu0_scope_begin                                                                                           \
	_Tp __mu9_transform_reduce_if2__v__ = mu0_const_cast(_Tp, __init);                                     \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                           \
		if (__binary_pred(_Tp, *__first1, *__first2)) {                                                     \
			__mu9_transform_reduce_if2__v__ = __mu9_transform_reduce_if2__v__ + ((*__first1) * (*__first2)); \
		}                                                                                                   \
	}                                                                                                      \
	__d_result = __mu9_transform_reduce_if2__v__;                                                          \
mu0_scope_end

#	define mu9_transform_reduce_if3(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __unary_pred, __d_result)        \
mu0_scope_begin                                                                                                                           \
	_Tp __mu9_transform_reduce_if3__v__ = mu0_const_cast(_Tp, __init);                                                                     \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                                                           \
		if (__unary_pred(_Tp, *__first1)) {                                                                                                 \
			__mu9_transform_reduce_if3__v__ = __binary_op1(_Tp, __mu9_transform_reduce_if3__v__, __binary_op2((_Tp, *__first1, *__first2))); \
		}                                                                                                                                   \
	}                                                                                                                                      \
	__d_result = __mu9_transform_reduce_if3__v__;                                                                                          \
mu0_scope_end

#	define mu9_transform_reduce_if4(_Tp, __first1, __last1, __first2, __init, __trinary_op, __unary_pred, __d_result)      \
mu0_scope_begin                                                                                                           \
	_Tp __mu9_transform_reduce_if4__v__ = mu0_const_cast(_Tp, __init);                                                     \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                                           \
		if (__unary_pred(_Tp, *__first1)) {                                                                                 \
			__mu9_transform_reduce_if4__v__ = __trinary_op(_Tp, __mu9_transform_reduce_if4__v__, _Tp, *__first1, *__first2); \
		}                                                                                                                   \
	}                                                                                                                      \
	__d_result = __mu9_transform_reduce_if4__v__;                                                                          \
mu0_scope_end

#	define mu9_transform_reduce_if5(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __binary_pred, __d_result)       \
mu0_scope_begin                                                                                                                           \
	_Tp __mu9_transform_reduce_if5__v__ = mu0_const_cast(_Tp, __init);                                                                     \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                                                           \
		if (__binary_pred(_Tp, *__first1, , *__first2)) {                                                                                   \
			__mu9_transform_reduce_if5__v__ = __binary_op1(_Tp, __mu9_transform_reduce_if5__v__, __binary_op2((_Tp, *__first1, *__first2))); \
		}                                                                                                                                   \
	}                                                                                                                                      \
	__d_result = __mu9_transform_reduce_if5__v__;                                                                                          \
mu0_scope_end

#	define mu9_transform_reduce_if6(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_pred, __d_result)     \
mu0_scope_begin                                                                                                           \
	_Tp __mu9_transform_reduce_if6__v__ = mu0_const_cast(_Tp, __init);                                                     \
	for (; __first1 != __last1; ++__first1, (void) ++__first2) {                                                           \
		if (__binary_pred(_Tp, *__first1, , *__first2)) {                                                                   \
			__mu9_transform_reduce_if6__v__ = __trinary_op(_Tp, __mu9_transform_reduce_if6__v__, _Tp, *__first1, *__first2); \
		}                                                                                                                   \
	}                                                                                                                      \
	__d_result = __mu9_transform_reduce_if6__v__;                                                                          \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_TRANSFORM_REDUCE_H */

/* EOF */