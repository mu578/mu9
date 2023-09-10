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

// mu9_bidirectional_sequence_insert_before.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_BIDIRECTIONAL_SEQUENCE_INSERT_BEFORE_H
#define MU9_BIDIRECTIONAL_SEQUENCE_INSERT_BEFORE_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Uint>( _Tp &* __head, _Tp &* __tail,  _Tp &* __cursor, _Tp<operator> &* __node_prev(_Tp &* __node), _Tp<operator> &* __node_next(_Tp &* __node), _Tp &* __node, _Bool<return> & __d_result) : void
//#!
#	define mu9_bidirectional_sequence_insert_before(_Tp, __head, __tail, __cursor, __node_prev, __node_next, __node, __d_result) \
mu0_scope_begin                                                                                                                 \
	if (mu0_not_nullptr(__cursor) && mu0_not_nullptr(__node)) {                                                                  \
		__node_prev(Tp, __node)   = __node_prev(Tp, __cursor);                                                                    \
		__node_prev(Tp, __cursor) = __node;                                                                                       \
		__node_next(Tp, __node)   = __cursor;                                                                                     \
		if (mu0_not_nullptr(__node_prev(Tp, __node))) {                                                                           \
			__node_next(Tp, __node_prev(Tp, __node)) = __node;                                                                     \
			__d_result                               = mu0_true;                                                                   \
		} else if (mu0_is_nullptr(__head)) {                                                                                      \
			__head      = __node;                                                                                                  \
			__d_result  = mu0_true;                                                                                                \
		}                                                                                                                         \
	} else {                                                                                                                     \
		__d_result  = mu0_false;                                                                                                  \
	}                                                                                                                            \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_BIDIRECTIONAL_SEQUENCE_INSERT_BEFORE_H */

/* EOF */