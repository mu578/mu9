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

// mu9_sequence_pop_back.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_SEQUENCE_POP_BACK_H
#define MU9_SEQUENCE_POP_BACK_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __head, _Tp<operator> &* __node_next(_Tp &* __node), _Tp<result> &* __d_node) : void
//#!
#	define mu9_sequence_pop_back(_Tp, __head, __node_next, __d_node)                                                              \
mu0_scope_begin                                                                                                                  \
	_Tp ** __mu9_sequence_pop_back__h__;                                                                                          \
	if (mu0_not_nullptr(__head)) {                                                                                                \
		__mu9_sequence_pop_back__h__ = &(__head);                                                                                  \
		if (mu0_not_nullptr(__node_next(_Tp, *__mu9_sequence_pop_back__h__))) {                                                    \
			while (                                                                                                                 \
				   mu0_not_nullptr(__node_next(_Tp, *__mu9_sequence_pop_back__h__))                                                  \
				&& mu0_not_nullptr(__node_next(_Tp, __node_next(_Tp, *__mu9_sequence_pop_back__h__)), *__mu9_sequence_pop_back__h__) \
			) {                                                                                                                     \
				*__mu9_sequence_pop_back__h__ = __node_next(_Tp, *__mu9_sequence_pop_back__h__);                                     \
			}                                                                                                                       \
			__d_node                                        = __node_next(_Tp, *__mu9_sequence_pop_back__h__);                      \
			__node_next(_Tp, *__mu9_sequence_pop_back__h__) = mu0_nullptr;                                                          \
			__node_next(_Tp, __d_node)                      = mu0_nullptr;                                                          \
		} else {                                                                                                                   \
			__d_node = *__mu9_sequence_pop_back__h__;                                                                               \
			__head   = mu0_nullptr;                                                                                                 \
		}                                                                                                                          \
	} else {                                                                                                                      \
		__d_node = mu0_nullptr;                                                                                                    \
	}                                                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_POP_BACK_H */

/* EOF */