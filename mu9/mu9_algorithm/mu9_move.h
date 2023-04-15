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

// mu9_move.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_MOVE_H
#define MU9_MOVE_H 1

MU0_BEGIN_CDECL

#	define mu9_move(_Tp, __first, __last, __d_first, __move_op)       \
mu0_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		__move_op(_Tp, *__d_first, *__first);                          \
	}                                                                 \
mu0_scope_end

#	define mu9_move_indirect(_Tp, __first, __last, __d_first, __move_op)                                    \
mu0_scope_begin                                                                                            \
	_Tp * __mu9_move_indirect__i__ = __first;                                                               \
	_Tp * __mu9_move_indirect__j__ = __last;                                                                \
	_Tp * __mu9_move_indirect__k__ = __d_first;                                                             \
	mu9_move(_Tp, __mu9_move_indirect__i__, __mu9_move_indirect__j__, __mu9_move_indirect__k__, __move_op); \
	__d_first                      = __mu9_move_indirect_k__;                                               \
mu0_scope_end

#	define mu9_move_if(_Tp, __first, __last, __d_first, __unary_pred, __move_op) \
mu0_scope_begin                                                                 \
	for (; __first != __last; ++__first) {                                       \
		if (__unary_pred(_Tp, *__first)) {                                        \
			__move_op(_Tp, *__d_first, *__first);                                  \
			++__d_first;                                                           \
		}                                                                         \
	}                                                                            \
mu0_scope_end

#	define mu9_move_indirect_if(_Tp, __first, __last, __d_first, __unary_pred, __move_op)                                             \
mu0_scope_begin                                                                                                                      \
	_Tp * __mu9_move_indirect_if__i__ = __first;                                                                                      \
	_Tp * __mu9_move_indirect_if__j__ = __last;                                                                                       \
	_Tp * __mu9_move_indirect_if__k__ = __d_first;                                                                                    \
	mu9_move_if(_Tp, __mu9_move_indirect_if__i__, __mu9_move_indirect_if__j__, __mu9_move_indirect_if__k__, __unary_pred, __move_op); \
	__d_first                         = __mu9_move_indirect_if__k__;                                                                  \
mu0_scope_end

#	define mu9_move_to(_Tp, __first, __last, __d_first, __move_op, __d_result) \
mu0_scope_begin                                                               \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) {          \
		 __move_op(_Tp, *__d_first, *__first);                                  \
	}                                                                          \
	__d_result = __d_first;                                                    \
mu0_scope_end

#	define mu9_move_indirect_to(_Tp, __first, __last, __d_first, __move_op, __d_result)                                                              \
mu0_scope_begin                                                                                                                                     \
	_Tp * __mu9_move_indirect_to__i__ = __first;                                                                                                     \
	_Tp * __mu9_move_indirect_to__j__ = __last;                                                                                                      \
	_Tp * __mu9_move_indirect_to__k__ = __d_first;                                                                                                   \
	_Tp * __mu9_move_indirect_to__r__;                                                                                                               \
	mu9_move_to(_Tp, __mu9_move_indirect_to__i__, __mu9_move_indirect_to__j__, __mu9_move_indirect_to__k__, __move_op, __mu9_move_indirect_to__r__); \
	__d_first                         = __mu9_move_indirect_to__k__;                                                                                 \
	__d_result                        = __mu9_move_indirect_to__r__;                                                                                 \
mu0_scope_end

#	define mu9_move_to_if(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result) \
mu0_scope_begin                                                                                \
	for (; __first != __last; ++__first) {                                                      \
		if (__unary_pred(_Tp, *__first)) {                                                       \
			__move_op(_Tp, *__d_first, *__first);                                                 \
			++__d_first;                                                                          \
		}                                                                                        \
	}                                                                                           \
	__d_result = __d_first;                                                                     \
mu0_scope_end

#	define mu9_move_indirect_to_if(_Tp, __first, __last, __d_first, __unary_pred, __move_op, __d_result)                                                      \
mu0_scope_begin                                                                                                                                              \
	_Tp * __mu9_move_indirect_to_if__i__ = __first;                                                                                                           \
	_Tp * __mu9_move_indirect_to_if__j__ = __last;                                                                                                            \
	_Tp * __mu9_move_indirect_to_if__k__ = __d_first;                                                                                                         \
	_Tp * __mu9_move_indirect_to_if__r__;                                                                                                                     \
	mu9_move_to_if(_Tp, __mu9_move_indirect_to_if__i__, __mu9_move_indirect_to_if__j__, __mu9_move_indirect_to_if__k__, __unary_pred, __move_op, __d_result); \
	__d_first                            = __mu9_move_indirect_to_if__k__;                                                                                    \
	__d_result                           = __mu9_move_indirect_to_if__r__;                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MOVE_H */

/* EOF */