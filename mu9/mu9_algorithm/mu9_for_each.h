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

#include <mu9/mu9_definition.h>

#ifndef MU9_FOR_EACH_H
#define MU9_FOR_EACH_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_fn) : void
//#!
#	define mu9_for_each(_Tp, __first, __last, __unary_fn) \
mu9_scope_begin                                          \
	for (; __first != __last; ++__first) {                \
		__unary_fn(*__first);                              \
	}                                                     \
mu9_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __first, _Uint & __n, __unary_fn) : void
//#!
#	define mu9_for_each_n(_Tp, __first, __n, __unary_fn)                                             \
mu9_scope_begin                                                                                     \
	mu9_uinteger_t ___mu9_for_each_n__i__ = 0;                                                       \
	for (; ___mu9_for_each_n__i__ < mu9_uinteger(__n); ++__first, (void) ++___mu9_for_each_n__i__) { \
		__unary_fn(*__first);                                                                         \
	}                                                                                                \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_FOR_EACH_H */

/* EOF */