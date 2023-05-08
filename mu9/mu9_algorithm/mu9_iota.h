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

#include <mu0/mu0_definition.h>

#ifndef MU9_IOTA_H
#define MU9_IOTA_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp & __value) : void
//#!
#	define mu9_iota1(_Tp, __first, __last, __value)      \
mu0_scope_begin                                         \
	_Tp __mu9_iota1__v__ = mu0_const_cast(_Tp, __value); \
	while (__first != __last) {                          \
		*__first++ = __mu9_iota1__v__;                    \
		++__mu9_iota1__v__;                               \
	}                                                    \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp & __value) : void
//#!
#	define mu9_iota2(_Tp, __first1, __last1, __first2, __value) \
mu0_scope_begin                                                \
	_Tp __mu9_iota2__v__ = mu0_const_cast(_Tp, __value);        \
	while (__first1 != __last1) {                               \
		*__first1++ = __mu9_iota2__v__;                          \
		*__first2++ = __mu9_iota2__v__;                          \
		++__mu9_iota2__v__;                                      \
	}                                                           \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_IOTA_H */

/* EOF */