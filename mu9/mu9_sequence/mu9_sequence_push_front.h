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

// mu9_sequence_push_front.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_SEQUENCE_PUSH_FRONT_H
#define MU9_SEQUENCE_PUSH_FRONT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __seq, _Tp<operator> * __node_next, _Tp &* __node) : void
//#!
#	define mu9_sequence_push_front(_Tp, __seq, __node_next, __node)          \
mu0_scope_begin                                                             \
	_Tp ** __mu9_sequence_push_front__h__ = &(__node);                       \
	_Tp ** __mu9_sequence_push_front__f__ = &(__node);                       \
	mu9_sequence_advance(Tp, *__mu9_sequence_push_front__f__, __node_next);  \
	__mu9_sequence_push_front__f__        = &(__seq);                        \
	__seq                                 = *__mu9_sequence_push_front__h__; \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_PUSH_FRONT_H */

/* EOF */