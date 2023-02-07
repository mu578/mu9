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

// mu9_iota.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_IOTA_H
#define MU9_IOTA_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp & __value) : void
//#!
#	define mu9_iota(_Tp, __first, __last, __value)      \
mu9_scope_begin                                        \
	_Tp ___mu9_iota__v__ = m9_const_cast(_Tp, __value); \
	while(__first != __last) {                          \
		*__first++ = ___mu9_iota__v__;                   \
		++__value;                                       \
	}                                                   \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_IOTA_H */

/* EOF */