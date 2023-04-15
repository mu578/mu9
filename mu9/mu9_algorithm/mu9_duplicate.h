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

// mu9_duplicate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_move.h>

#ifndef MU9_DUPLICATE_H
#define MU9_DUPLICATE_H 1

MU0_BEGIN_CDECL

#	define mu9_duplicate(_Tp, __first, __last, __d_first, __dup_op)  \
	mu9_move(_Tp, __first, __last, __d_first, __dup_op)

#	define mu9_duplicate_if(_Tp, __first, __last, __d_first, __unary_pred, __dup_op) \
	mu9_move_if(_Tp, __first, __last, __d_first, __unary_pred, __dup_op)

#	define mu9_duplicate_to(_Tp, __first, __last, __d_first, __dup_op, __d_result) \
	mu9_move_to(_Tp, __first, __last, __d_first, __unary_pred, __dup_op)

#	define mu9_duplicate_to_if(_Tp, __first, __last, __d_first, __unary_pred, __dup_op, __d_result) \
	mu9_move_to_if(_Tp, __first, __last, __d_first, __unary_pred, __dup_op, __d_result)

MU0_END_CDECL

#endif /* !MU9_DUPLICATE_H */

/* EOF */