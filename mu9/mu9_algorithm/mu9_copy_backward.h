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

// mu9_copy_backward.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_COPY_BACKWARD_H
#define MU9_COPY_BACKWARD_H 1

MU0_BEGIN_CDECL

#	define mu9_copy_backward1(Tp, __first, __last, __d_first)                                            \
mu0_scope_begin                                                                                         \
	_Tp * __mu9_copy_backward__i__ = __last;                                                             \
	for (; __first != __mu9_copy_backward__i__; (void) --__mu9_copy_backward__i__, (void) ++__d_first) { \
		*__d_first = *__mu9_copy_backward__i__;                                                           \
	}                                                                                                    \
mu0_scope_end

#	define mu9_copy_backward2(Tp, __first, __last, __d_first, __move_op)                                 \
mu0_scope_begin                                                                                         \
	_Tp * __mu9_copy_backward__i__ = __last;                                                             \
	for (; __first != __mu9_copy_backward__i__; (void) --__mu9_copy_backward__i__, (void) ++__d_first) { \
		__move_op(_Tp, *__d_first, *__mu9_copy_backward__i__);                                            \
	}                                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_COPY_BACKWARD_H */

/* EOF */