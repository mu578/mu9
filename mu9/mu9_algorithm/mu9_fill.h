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

// mu9_fill.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_FILL_H
#define MU9_FILL_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value) : void
//#!
#	define mu9_fill(_Tp, __first, __last, __value) \
mu9_scope_begin                                   \
	while(__first != __last) {                     \
		*__first++ = __value;                       \
	}                                              \
mu9_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __first, _Uint & __n, const _Tp & __value) : void
//#!
#	define mu9_fill_n(_Tp, __first, __n, __value)                                 \
mu9_scope_begin                                                                  \
	mu9_uinteger_t ___mu9_fill_n__i__ = 0;                                        \
	for (; ___mu9_fill_n__i__ < mu9_uinteger(__n); (void) ++___mu9_fill_n__i__) { \
		*__first++ = __value;                                                      \
	}                                                                             \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_FILL_H */

/* EOF */