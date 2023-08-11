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

// mu9_for_each.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_integer.h>

#ifndef MU9_FOR_EACH_H
#define MU9_FOR_EACH_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_fn) : void
//#!
#	define mu9_for_each1(_Tp, __first, __last, __unary_fn) \
mu0_scope_begin                                           \
	for (; __first != __last; ++__first) {                 \
		__unary_fn(Tp, *__first);                           \
	}                                                      \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __seq, _Tp<operator> * __seq_node, __seq_next, __unary_fn) : void
//#!
#	define mu9_for_each2(_Tp, __seq, __seq_node, __seq_next, __unary_fn) \
mu0_scope_begin                                                         \
	while (!mu0_is_nullptr(__seq)) {                                     \
		__unary_fn(Tp, *__seq);                                           \
		__seq_next(Tp, __seq, __seq_node);                                \
	}                                                                    \
mu0_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __first, const _Uint & __n, __unary_fn) : void
//#!
#	define mu9_for_each_n1(_Tp, __first, __n, __unary_fn)                                                  \
mu0_scope_begin                                                                                           \
	mu0_distance_t __mu9_for_each_n1__i__ = mu0_const_distance(0);                                         \
	for (; __mu9_for_each_n1__i__ < mu0_const_distance(__n); ++__first, (void) ++__mu9_for_each_n1__i__) { \
		__unary_fn(Tp, *__first);                                                                           \
	}                                                                                                      \
mu0_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __seq, _Tp<operator> * __seq_node, __seq_next, const _Uint & __n, __unary_fn) : void
//#!
#	define mu9_for_each_n2(_Tp, __seq, __seq_node, __seq_next, __n, __unary_fn)                 \
mu0_scope_begin                                                                                \
	mu0_distance_t __mu9_for_each_n2__i__ = mu0_const_distance(0);                              \
	for (; __mu9_for_each_n2__i__ < mu0_const_distance(__n); (void) ++__mu9_for_each_n2__i__) { \
		__unary_fn(Tp, *__seq);                                                                  \
		__seq_next(Tp, __seq, __seq_node);                                                       \
		if (mu0_is_nullptr(__seq)) {                                                             \
			break;                                                                                \
		}                                                                                        \
	}                                                                                           \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_FOR_EACH_H */

/* EOF */