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

// mu9_bidirectional_sequence_pop_front.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_BIDIRECTIONAL_SEQUENCE_POP_FRONT_H
#define MU9_BIDIRECTIONAL_SEQUENCE_POP_FRONT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __head, _Tp &* __tail, _Tp<operator> &* __node_prev(_Tp &* __node), _Tp<operator> &* __node_next(_Tp &* __node), _Tp<result> &* __d_node) : void
//#!
#	define mu9_bidirectional_sequence_pop_front(_Tp, __head, __tail, __node_prev, __node_next, __d_node) \
mu0_scope_begin                                                                                         \
	if(mu0_not_nullptr(__tail)) {                                                                        \
		__d_node = __head;                                                                                \
		if(__head == __tail) {                                                                            \
			__head = __tail = mu0_nullptr;                                                                 \
		} else {                                                                                          \
			__head                  = __node_next(Tp, __head);                                             \
			__node_prev(Tp, __head) = mu0_nullptr;                                                         \
		}                                                                                                 \
		__node_prev(Tp, __d_node) = mu0_nullptr;                                                          \
		__node_next(Tp, __d_node) = mu0_nullptr;                                                          \
	} else {                                                                                             \
		 __d_node = mu0_nullptr;                                                                          \
	}                                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_BIDIRECTIONAL_SEQUENCE_POP_FRONT_H */

/* EOF */