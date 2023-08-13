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

// mu9_sequence_at_index.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_SEQUENCE_AT_INDEX_H
#define MU9_SEQUENCE_AT_INDEX_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Uint>(_Tp &* __seq, _Tp<operator> * __node_next, const _Uint & __i, _Tp<result> &* __d_node) : void
//#!
#	define mu9_sequence_at_index(_Tp, __seq, __node_next, __i, __d_node)                                       \
mu0_scope_begin                                                                                               \
	mu0_distance_t __mu9_sequence_at_index__i__;                                                               \
	_Tp **         __mu9_sequence_at_index__h__;                                                               \
	if (!mu0_is_nullptr(__seq)) {                                                                              \
		__mu9_sequence_at_index__i__ = mu0_const_distance(0);                                                   \
		__mu9_sequence_at_index__h__ = &(__seq);                                                                \
		for (; __mu9_sequence_at_index__i__ < mu0_const_distance(__i); (void) ++__mu9_sequence_at_index__i__) { \
			mu9_sequence_advance(Tp, *__mu9_sequence_at_index__h__, __node_next);                                \
			if (mu0_is_nullptr(*__mu9_sequence_at_index__h__)) {                                                 \
				break;                                                                                            \
			}                                                                                                    \
		}                                                                                                       \
		__d_node = *__mu9_sequence_at_index__h__;                                                               \
	} else {                                                                                                   \
		__d_node = mu0_nullptr;                                                                                 \
	}                                                                                                          \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_AT_INDEX_H */

/* EOF */