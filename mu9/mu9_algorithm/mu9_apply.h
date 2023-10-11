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

// mu9_apply.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_transform.h>

#ifndef MU9_APPLY_H
#define MU9_APPLY_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_op) : void
//#!
#	define mu9_apply1(_Tp, __first, __last, __unary_op)                        \
mu0_scope_begin                                                               \
	_Tp * __mu9_apply1__d_first__ = __first;                                   \
	mu9_transform1(_Tp, __first, __last, __mu9_apply1__d_first__, __unary_op); \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __binary_op) : void
//#!
#	define mu9_apply2(_Tp, __first, __last, __binary_op)                        \
mu0_scope_begin                                                                \
	_Tp * __mu9_apply2__d_first__ = __first;                                    \
	mu9_transform2(_Tp, __first, __last, __mu9_apply2__d_first__, __binary_op); \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_APPLY_H */

/* EOF */