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

// mu9_reduce.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_REDUCE_H
#define MU9_REDUCE_H 1

MU0_BEGIN_CDECL

#	define mu9_reduce1(_Tp, __first, __last, __init, __d_result) \
mu0_scope_begin                                                 \
	_Tp __mu9_reduce1__v__ = __init;                             \
	for (; __first != __last; ++__first) {                       \
		__mu9_reduce1__v__ = __mu9_reduce1__v__ + *__first;       \
	}                                                            \
	__d_result = __mu9_reduce1__v__;                             \
mu0_scope_end

#	define mu9_reduce2(_Tp, __first, __last, __init, __binary_op, __d_result) \
mu0_scope_begin                                                              \
	_Tp __mu9_reduce2__v__ = __init;                                          \
	for (; __first != __last; ++__first) {                                    \
		__mu9_reduce2__v__ = __binary_op(_Tp, __mu9_reduce2__v__, *__first);   \
	}                                                                         \
	__d_result = __mu9_reduce2__v__;                                          \
mu0_scope_end

#	define mu9_reduce3(_Tp, __first, __last, __init, __unary_op, __d_result) \
mu0_scope_begin                                                             \
	_Tp __mu9_reduce3__v__ = __init;                                         \
	for (; __first != __last; ++__first) {                                   \
		__mu9_reduce3__v__ = __mu9_reduce3__v__ + __unary_op(_Tp, *__first);  \
	}                                                                        \
	__d_result = __mu9_reduce3__v__;                                         \
mu0_scope_end

#	define mu9_reduce4(_Tp, __first, __last, __init, __binary_op, __unary_op, __d_result)    \
mu0_scope_begin                                                                             \
	_Tp __mu9_reduce4__v__ = __init;                                                         \
	for (; __first != __last; ++__first) {                                                   \
		__mu9_reduce4__v__ = __binary_op(_Tp, __mu9_reduce4__v__, __unary_op(_Tp, *__first)); \
	}                                                                                        \
	__d_result = __mu9_reduce4__v__;                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_REDUCE_H */

/* EOF */