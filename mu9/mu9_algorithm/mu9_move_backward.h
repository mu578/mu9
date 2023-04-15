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

// mu9_move_backward.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_MOVE_BACKWARD_H
#define MU9_MOVE_BACKWARD_H 1

MU0_BEGIN_CDECL

#	define mu9_move_backward(_Tp, __first, __last, __d_last, __move_op) \
mu0_scope_begin                                                        \
	while (__first != __last) {                                         \
		__move_op(_Tp, *(--__d_last), *(--__last));                      \
	}                                                                   \
mu0_scope_end

#	define mu9_move_backward_indirect(_Tp, __first, __last, __d_last, __move_op)                                                 \
mu0_scope_begin                                                                                                                 \
	_Tp * __mu9_backward_indirect__i__ = __first;                                                                                \
	_Tp * __mu9_backward_indirect__j__ = __last;                                                                                 \
	_Tp * __mu9_backward_indirect__k__ = __d_last;                                                                               \
	mu9_move_backward(_Tp, __mu9_backward_indirect__i__, __mu9_backward_indirect__j__, __mu9_backward_indirect__k__, __move_op); \
	__d_last                           = __mu9_backward_indirect_k__;                                                            \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MOVE_BACKWARD_H */

/* EOF */