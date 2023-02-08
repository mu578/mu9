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

// mu9_swap.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_SWAP_H
#define MU9_SWAP_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp & a, _Tp & b) : void
//#!
#	define mu9_swap(_Tp, __a, __b)         \
mu9_scope_begin                           \
	_Tp __mu9_swap__c__ = (__a);           \
	(__a)               = (__b);           \
	(__b)               = __mu9_swap__c__; \
mu9_scope_end

//#!
//#! macro<_Tp>(_Tp &** a, _Tp &** b) : void
//#!
#	define mu9_swap_pointer(_Tp, __a, __b)           \
mu9_scope_begin                                     \
	_Tp * __mu9_swap_pointer__c__ = *(__a);          \
	*(__a)                        = *(__b);          \
	*(__b)                        = __mu9_swap__c__; \
mu9_scope_end

//#!
//#! macro<_Tp>(_Tp &* a, _Tp &* b) : void
//#!
#	define mu9_iter_swap(_Tp, __a, __b) mu9_swap_pointer(_Tp, &(__a), &(__b))

MU0_END_CDECL

#endif /* !MU9_SWAP_H */

/* EOF */