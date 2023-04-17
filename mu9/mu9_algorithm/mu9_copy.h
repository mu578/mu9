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

// mu9_copy.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_move.h>

#ifndef MU9_COPY_H
#define MU9_COPY_H 1

MU0_BEGIN_CDECL

#	define mu9_copy1(_Tp, __first, __last, __d_first)                 \
mu0_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		*__d_first = *__first;                                         \
	}                                                                 \
mu0_scope_end

#	define mu9_copy2(_Tp, __first, __last, __d_first, __move_op) \
	mu9_move(_Tp, __first, __last, __d_first, __move_op)

#	define mu9_copy_if1(_Tp, __first, __last, __d_first, __unary_pred) \
mu0_scope_begin                                                       \
	for (; __first != __last; ++__first) {                             \
		if (__unary_pred(_Tp, *__first)) {                              \
			*__d_first = *__first;                                       \
			++__d_first;                                                 \
		}                                                               \
	}                                                                  \
mu0_scope_end

#	define mu9_copy_if2(_Tp, __first, __last, __d_first, __unary_pred, __move_op) \
	mu9_move_if(_Tp, __first, __last, __d_first, __unary_pred, __move_op)

#	define mu9_copy_if_not1(_Tp, __first, __last, __d_first, __unary_pred) \
mu0_scope_begin                                                           \
	for (; __first != __last; ++__first) {                                 \
		if (!__unary_pred(_Tp, *__first)) {                                 \
			*__d_first = *__first;                                           \
			++__d_first;                                                     \
		}                                                                   \
	}                                                                      \
mu0_scope_end

#	define mu9_copy_if_not2(_Tp, __first, __last, __d_first, __unary_pred, __move_op) \
	mu9_move_if_not(_Tp, __first, __last, __d_first, __unary_pred, __move_op) 

#	define mu9_copy_to1(_Tp, __first, __last, __d_first, __d_result)  \
mu0_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		*__d_first = *__first;                                         \
	}                                                                 \
	__d_result = __d_first;                                           \
mu0_scope_end

#	define mu9_copy_to2(_Tp, __first, __last, __d_first, __move_op, __d_result) \
	mu9_move_to(_Tp, __first, __last, __d_first, __move_op, __d_result)

#	define mu9_copy_to_if1(_Tp, __first, __last, __d_first, __unary_pred, __d_result) \
mu0_scope_begin                                                                      \
	for (; __first != __last; ++__first) {                                            \
		if (__unary_pred(_Tp, *__first)) {                                             \
			*__d_first = *__first;                                                      \
			++__d_first;                                                                \
		}                                                                              \
	}                                                                                 \
	__d_result = __d_first;                                                           \
mu0_scope_end

#	define mu9_copy_to_if2(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result) \
	mu9_move_to_if(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result)

#	define mu9_copy_to_if_not1(_Tp, __first, __last, __d_first, __unary_pred, __d_result) \
mu0_scope_begin                                                                          \
	for (; __first != __last; ++__first) {                                                \
		if (!__unary_pred(_Tp, *__first)) {                                                \
			*__d_first = *__first;                                                          \
			++__d_first;                                                                    \
		}                                                                                  \
	}                                                                                     \
	__d_result = __d_first;                                                               \
mu0_scope_end

#	define mu9_copy_to_if_not2(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result) \
	mu9_move_to_if_not(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result)

MU0_END_CDECL

#endif /* !MU9_COPY_H */

/* EOF */