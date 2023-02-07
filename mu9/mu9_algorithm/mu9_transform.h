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

// mu9_transform.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_TRANSFORM_H
#define MU9_TRANSFORM_H 1

MU0_BEGIN_CDECL

#	define mu9_transform1(_Tp, __first1, __last1, __d_first, __unary_op) \
mu9_scope_begin                                                         \
	while(__first1 != __last1) {                                         \
		*__d_first++ = __unary_op(*__first1++);                           \
	}                                                                    \
mu9_scope_end

#	define mu9_transform2(_Tp, __first1, __last1, __first2, __d_first, __binary_op) \
mu9_scope_begin                                                                    \
	while(__first1 != __last1) {                                                    \
		*__d_first++ = __binary_op(*__first1++, *__first2++);                        \
	}                                                                               \
mu9_scope_end

MU0_END_CDECL

#endif /* !MU9_TRANSFORM_H */

/* EOF */