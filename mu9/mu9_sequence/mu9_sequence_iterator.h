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

// mu9_sequence_iterator.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_integer.h>

#ifndef MU9_SEQUENCE_ITERATOR_H
#define MU9_SEQUENCE_ITERATOR_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __seq, _Tp<operator> &* __seq_next(_Tp &* __head)) : void
//#!
#	define mu9_sequence_advance(Tp, __seq, __seq_next) \
mu0_scope_begin                                       \
	__seq = __seq_next(Tp, __seq);                     \
mu0_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __seq, _Tp<operator> &* __seq_next(_Tp &* __head), _Dist & __n) : void
//#!
#	define mu9_sequence_advance_n(_Tp, __seq, __seq_next, __n)                                            \
mu0_scope_begin                                                                                          \
	mu0_distance_t __mu9_sequence_advance__i__ = mu0_const_distance(0);                                   \
	for (; __mu9_sequence_advance__i__ < mu0_const_distance(__n); (void) ++__mu9_sequence_advance__i__) { \
		mu9_sequence_advance(Tp, __seq, __seq_next);                                                       \
		if (mu0_is_nullptr(__seq)) {                                                                       \
			break;                                                                                          \
		}                                                                                                  \
	}                                                                                                     \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_SEQUENCE_ITERATOR_H */

/* EOF */