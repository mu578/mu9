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

// mu9_sequence_insert_at.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_sequence/mu9_sequence_iterator.h>

#ifndef MU9_SEQUENCE_INSERT_AT_H
#define MU9_SEQUENCE_INSERT_AT_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Uint>(_Tp &* __head, _Tp<operator> &* __node_next(_Tp &* __node), const _Uint & __i, _Tp &* __node, _Bool<return> & __d_result) : void
//#!
#	define mu9_sequence_insert_at(_Tp, __head, __node_next, __i, __node, __d_result)                                   \
mu0_scope_begin                                                                                                       \
	const mu0_distance_t __mu9_sequence_insert_at__k__ = mu0_const_distance(__i) - mu0_const_distance(1);              \
	      mu0_distance_t __mu9_sequence_insert_at__i__ = mu0_const_distance(0);                                        \
	      mu0_bool_t     __mu9_sequence_insert_at__x__ = mu0_false;                                                    \
	      _Tp **         __mu9_sequence_insert_at__h__;                                                                \
	      _Tp **         __mu9_sequence_insert_at__f__;                                                                \
	if (mu0_is_nullptr(__head)) {                                                                                      \
		__head                  = __node;                                                                               \
		__node_next(Tp, __node) = mu0_nullptr;                                                                          \
		__d_result              = mu0_true;                                                                             \
	} else if (__mu9_sequence_insert_at__k__ <= mu0_const_distance(0)) {                                               \
		__mu9_sequence_insert_at__h__ = &(__head);                                                                      \
		__mu9_sequence_insert_at__f__ = &(__head);                                                                      \
		mu9_sequence_advance(Tp, *__mu9_sequence_insert_at__f__, __node_next);                                          \
		__mu9_sequence_insert_at__f__ = &(__head);                                                                      \
		__head                        = *__mu9_sequence_insert_at__h__;                                                 \
		__d_result                    = mu0_true;                                                                       \
	} else if (__mu9_sequence_insert_at__k__ >= mu0_const_distance(1)) {                                               \
		__d_result                    = mu0_false;                                                                      \
		__mu9_sequence_insert_at__h__ = &(__head);                                                                      \
		__mu9_sequence_insert_at__f__ = &(__head);                                                                      \
		for (; __mu9_sequence_insert_at__i__ < __mu9_sequence_insert_at__k__; (void) ++__mu9_sequence_insert_at__i__) { \
			mu9_sequence_advance(Tp, *__mu9_sequence_insert_at__f__, __node_next);                                       \
			if (mu0_is_nullptr(*__mu9_sequence_insert_at__f__)) {                                                        \
				__mu9_sequence_insert_at__x__ = mu0_true;                                                                 \
				break;                                                                                                    \
			}                                                                                                            \
		}                                                                                                               \
		if (!__mu9_sequence_insert_at__x__) {                                                                           \
			__node_next(Tp, __node)                         = *__mu9_sequence_insert_at__f__;                            \
			__node_next(Tp, *__mu9_sequence_insert_at__f__) = __node;                                                    \
			__head                                          = *__mu9_sequence_insert_at__h__;                            \
			__d_result                                      = mu0_true;                                                  \
		} else {                                                                                                        \
			*mu9_sequence_insert_at__f__ = __node;                                                                       \
			__node_next(Tp, __node)      = mu0_nullptr;                                                                  \
			__head                       = *__mu9_sequence_insert_at__h__;                                               \
			__d_result                   = mu0_true;                                                                     \
		}                                                                                                               \
	} else {                                                                                                           \
		__d_result = mu0_false;                                                                                         \
	}                                                                                                                  \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_INSERT_AT_H */

/* EOF */