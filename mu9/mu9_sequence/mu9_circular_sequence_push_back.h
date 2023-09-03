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

// mu9_circular_sequence_push_back.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_CIRCULAR_SEQUENCE_PUSH_BACK_H
#define MU9_CIRCULAR_SEQUENCE_PUSH_BACK_H 1

MU0_BEGIN_CDECL

#	define mu9_circular_sequence_push_back(_Tp, __head, __tail, __node_next, __node) \
mu0_scope_begin                                                                     \
	if (mu0_not_nullptr(__node)) {                                                   \
		__node_next(Tp, __node) = mu0_nullptr;                                        \
		if (mu0_not_nullptr(__head)) {                                                \
			__head = __tail = __node;                                                  \
		} else {                                                                      \
			__node_next(Tp, __tail) = __node;                                          \
			__tail                  = __node;                                          \
		}                                                                             \
	}                                                                                \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_CIRCULAR_SEQUENCE_PUSH_BACK_H */

/* EOF */