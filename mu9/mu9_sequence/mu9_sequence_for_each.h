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

// mu9_sequence_for_each.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_SEQUENCE_FOR_EACH_H
#define MU9_SEQUENCE_FOR_EACH_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __seq, _Tp<operator> * __next_node, __unary_fn) : void
//#!
#	define mu9_sequence_for_each(_Tp, __seq, __next_node, __unary_fn)     \
mu0_scope_begin                                                          \
	_Tp ** __mu9_sequence_for_each__h__ = &(__seq);                       \
	while (1) {                                                           \
		__unary_fn(Tp, *((*__mu9_sequence_for_each__h__)));                \
		mu9_sequence_next(Tp, *__mu9_sequence_for_each__h__, __next_node); \
		if (mu0_is_nullptr(*__mu9_sequence_for_each__h__)) {               \
			break;                                                          \
		}                                                                  \
	}                                                                     \
mu0_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __seq, _Tp<operator> * __next_node, const _Uint & __n, __unary_fn) : void
//#!
#	define mu9_sequence_for_each_n(_Tp, __seq, __next_node, __n, __unary_fn)                                    \
mu0_scope_begin                                                                                                \
	mu0_distance_t __mu9_sequence_for_each_n__i__ = mu0_const_distance(0);                                      \
	_Tp **         __mu9_sequence_for_each_n__h__ = &(__seq);                                                   \
	for (; __mu9_sequence_for_each_n__i__ < mu0_const_distance(__n); (void) ++__mu9_sequence_for_each_n__i__) { \
		__unary_fn(Tp, *((*__mu9_sequence_for_each_n__h__)));                                                    \
		mu9_sequence_next(Tp, *__mu9_sequence_for_each_n__h__, __next_node);                                     \
		if (mu0_is_nullptr(*__mu9_sequence_for_each_n__h__)) {                                                   \
			break;                                                                                                \
		}                                                                                                        \
	}                                                                                                           \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_FOR_EACH_H */

/* EOF */