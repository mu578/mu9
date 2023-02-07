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

MU9_BEGIN_CDECL

#	define mu9_apply1(_Tp, __first1, __last1, __unary_op)                         \
mu9_scope_begin                                                                  \
	_Tp * ___mu9_apply1__d_first__ = __first1;                                    \
	mu9_transform1(_Tp, __first1, __last1, ___mu9_apply1__d_first__, __unary_op); \
mu9_scope_end

#	define mu9_apply2(_Tp, __first1, __last1, __binary_op)                         \
mu9_scope_begin                                                                   \
	_Tp * ___mu9_apply2__d_first__ = __first1;                                     \
	mu9_transform2(_Tp, __first1, __last1, ___mu9_apply2__d_first__, __binary_op); \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_APPLY_H */

/* EOF */