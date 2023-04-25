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
mu0_scope_begin                           \
	_Tp __mu9_swap__c__ = (__a);           \
	(__a)               = (__b);           \
	(__b)               = __mu9_swap__c__; \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp & a, _Tp & b, __move_op) : void
//#!
#	define mu9_swap_move(_Tp, __a, __b, __move_op) \
mu0_scope_begin                                   \
	_Tp __mu9_swap_move__c__;                      \
	__move_op(_Tp, __mu9_swap_move__c__, __a);     \
	__move_op(_Tp, __a, __b);                      \
	__move_op(_Tp, __b, __mu9_swap_move__c__);     \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* a, _Tp &* b) : void
//#!
#	define mu9_swap_value(_Tp, __a, __b)         \
mu0_scope_begin                                 \
	_Tp __mu9_swap_value__c__ = *(__a);          \
	*(__a)                    = *(__b);          \
	*(__b)                    = __mu9_swap__c__; \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* a, _Tp &* b, __move_op) : void
//#!
#	define mu9_swap_move_value(_Tp, __a, __b, __move_op) \
mu0_scope_begin                                         \
	_Tp __mu9_swap_move_value__c__;                      \
	__move_op(_Tp, __mu9_swap_move_value__c__, *__a);    \
	__move_op(_Tp, *__a, *__b);                          \
	__move_op(_Tp, *__b, __mu9_swap_move_value__c__);    \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &** a, _Tp &** b) : void
//#!
#	define mu9_swap_pointer(_Tp, __a, __b)           \
mu0_scope_begin                                     \
	_Tp * __mu9_swap_pointer__c__ = *(__a);          \
	*(__a)                        = *(__b);          \
	*(__b)                        = __mu9_swap__c__; \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* a, _Tp &* b) : void
//#!
#	define mu9_iter_swap(_Tp, __a, __b) mu9_swap_value(_Tp, __a, __b)

//#!
//#! macro<_Tp>(_Tp &* a, _Tp &* b, __move_op) : void
//#!
#	define mu9_iter_swap_move(_Tp, __a, __b, __move_op) mu9_swap_move_value(_Tp, __a, __b, __move_op)

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2 __first2, _Tp<return> &* __d_result) : void
//#!
#	define mu9_swap_ranges(_Tp, __first1, __last1, __first2, __d_result) \
mu0_scope_begin                                                         \
	for (; __first1 != __last1; ++__first1, ++__first2) {                \
		mu9_iter_swap(_Tp, __first1, __first2);                           \
	}                                                                    \
	__d_result = __first2;                                               \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2 __first2, __move_op, _Tp<return> &* __d_result) : void
//#!
#	define mu9_swap_move_ranges(_Tp, __first1, __last1, __first2, __move_op, __d_result) \
mu0_scope_begin                                                                         \
	for (; __first1 != __last1; ++__first1, ++__first2) {                                \
		mu9_iter_swap_move(_Tp, __first1, __first2, __move_op);                           \
	}                                                                                    \
	__d_result = __first2;                                                               \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SWAP_H */

/* EOF */