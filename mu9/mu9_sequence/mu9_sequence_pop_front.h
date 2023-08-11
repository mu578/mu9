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

// mu9_sequence_pop_front.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_SEQUENCE_POP_FRONT_H
#define MU9_SEQUENCE_POP_FRONT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __seq, _Tp<operator> * __next_node, _Tp<result> &* __d_node) : void
//#!
#	define mu9_sequence_pop_front(_Tp, __seq, __next_node, __d_node)       \
mu0_scope_begin                                                           \
	_Tp ** __mu9_sequence_pop_front__h__ = &(__seq);                       \
	_Tp ** __mu9_sequence_pop_front__f__ = &(__seq);                       \
	__seq_next(Tp, *__mu9_sequence_pop_front__h__, __next_node);           \
	__d_node                             = *__mu9_sequence_pop_front__f__; \
	__seq                                = *__mu9_sequence_pop_front__h__; \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_POP_FRONT_H */

/* EOF */