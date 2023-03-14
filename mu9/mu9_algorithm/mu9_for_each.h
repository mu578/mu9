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
#	define mu9_for_each(_Tp, __first, __last, __unary_fn) \
mu0_scope_begin                                          \
	for (; __first != __last; ++__first) {                \
		__unary_fn(*__first);                              \
	}                                                     \
mu0_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __first, _Uint & __n, __unary_fn) : void
//#!
#	define mu9_for_each_n(_Tp, __first, __n, __unary_fn)                                                 \
mu0_scope_begin                                                                                         \
	mu0_distance_t __mu9_for_each_n__i__ = mu0_const_distance(0);                                        \
	for (; __mu9_for_each_n__i__ < mu0_const_distance(__n); ++__first, (void) ++__mu9_for_each_n__i__) { \
		__unary_fn(*__first);                                                                             \
	}                                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_FOR_EACH_H */

/* EOF */