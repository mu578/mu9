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

// mu9_bidirectional_sequence_push_back.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_BIDIRECTIONAL_SEQUENCE_PUSH_BACK_H
#define MU9_BIDIRECTIONAL_SEQUENCE_PUSH_BACK_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __head, _Tp &* __tail, _Tp<operator> &* __node_prev(_Tp &* __node), _Tp<operator> &* __node_next(_Tp &* __node), _Tp &* __node) : void
//#!
#	define mu9_bidirectional_sequence_push_back(_Tp, __head, __tail, __node_prev, __node_next, __node) \
mu0_scope_begin                                                                                       \
	if(mu0_is_nullptr(__head)) {                                                                       \
		__node_next(Tp, __node) = mu0_nullptr;                                                          \
		__node_prev(Tp, __node) = mu0_nullptr;                                                          \
		__head                  = __tail = __node;                                                      \
	} else {                                                                                           \
		__node_next(Tp, __node) = mu0_nullptr;                                                          \
		__node_next(Tp, __tail) = __node;                                                               \
		__node_prev(Tp, __node) = __tail;                                                               \
		__tail                  = __node_next(Tp, __tail);                                              \
	}                                                                                                  \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_BIDIRECTIONAL_SEQUENCE_PUSH_BACK_H */

/* EOF */