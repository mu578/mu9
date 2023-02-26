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

// mu9_generate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_integer.h>

#ifndef MU9_GENERATEL_H
#define MU9_GENERATEL_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __gen_fn) : void
//#!
#	define mu9_generate(_Tp, __first, __last, __gen_fn) \
mu0_scope_begin                                        \
	while (__first != __last) {                         \
		*__first++ = __gen_fn();                         \
	}                                                   \
mu0_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __first, _Uint & __n, __gen_fn) : void
//#!
#	define mu9_generate_n(_Tp, __first, __n, __value)                                   \
mu0_scope_begin                                                                        \
	mu0_uinteger_t __mu9_generate_n__i__ = 0;                                           \
	for (; __mu9_generate_n__i__ < mu0_uinteger(__n); (void) ++__mu9_generate_n__i__) { \
		*__first++ = __gen_fn();                                                         \
	}                                                                                   \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_GENERATEL_H */

/* EOF */