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
//#! macro<_Tp>(_Tp &* __head, _Tp<operator> &* __node_next(_Tp &* __node), __unary_fn) : void
//#!
#	define mu9_sequence_for_each(_Tp, __head, __node_next, __unary_fn)          \
mu0_scope_begin                                                                \
	_Tp ** __mu9_sequence_for_each__h__;                                        \
	_Tp *  __mu9_sequence_for_each__c__;                                        \
	if (mu0_not_nullptr(__head)) {                                              \
		__mu9_sequence_for_each__h__ = &(__head);                                \
		while (1) {                                                              \
			__mu9_sequence_for_each__c__ = *__mu9_sequence_for_each__h__;         \
			if (mu0_is_nullptr(__mu9_sequence_for_each__c__)) {                   \
				break;                                                             \
			}                                                                     \
			mu9_sequence_advance(Tp, *__mu9_sequence_for_each__h__, __node_next); \
			__unary_fn(Tp, __mu9_sequence_for_each__c__);                         \
			if (mu0_is_nullptr(*__mu9_sequence_for_each__h__)) {                  \
				break;                                                             \
			}                                                                     \
		}                                                                        \
	}                                                                           \
mu0_scope_end

//#!
//#! macro<_Tp, _Uint>(_Tp &* __head, _Tp<operator> &* __node_next(_Tp &* __node), const _Uint & __n, __unary_fn) : void
//#!
#	define mu9_sequence_for_each_n(_Tp, __head, __node_next, __n, __unary_fn)                                      \
mu0_scope_begin                                                                                                   \
	mu0_distance_t __mu9_sequence_for_each_n__i__;                                                                 \
	_Tp **         __mu9_sequence_for_each_n__h__;                                                                 \
	_Tp *          __mu9_sequence_for_each_n__c__;                                                                 \
	if (mu0_not_nullptr(__head)) {                                                                                 \
		__mu9_sequence_for_each_n__i__ = mu0_const_distance(0);                                                     \
		__mu9_sequence_for_each_n__h__ = &(__head);                                                                 \
		for (; __mu9_sequence_for_each_n__i__ < mu0_const_distance(__n); (void) ++__mu9_sequence_for_each_n__i__) { \
			__mu9_sequence_for_each_n__c__ = *__mu9_sequence_for_each_n__h__;                                        \
			if (mu0_is_nullptr(__mu9_sequence_for_each_n__c__)) {                                                    \
				break;                                                                                                \
			}                                                                                                        \
			mu9_sequence_advance(Tp, *__mu9_sequence_for_each_n__h__, __node_next);                                  \
			__unary_fn(Tp, __mu9_sequence_for_each_n__c__);                                                          \
			if (mu0_is_nullptr(*__mu9_sequence_for_each_n__h__)) {                                                   \
				break;                                                                                                \
			}                                                                                                        \
		}                                                                                                           \
	}                                                                                                              \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_FOR_EACH_H */

/* EOF */