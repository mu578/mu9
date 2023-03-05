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

// mu9_adjacent_find.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_ADJACENT_FIND_H
#define MU9_ADJACENT_FIND_H 1

MU0_BEGIN_CDECL

#	define mu9_adjacent_find1(_Tp, __first, __last, __d_result)                              \
mu0_scope_begin                                                                             \
	_Tp * __mu9_adjacent_find1__i__;                                                         \
	mu0_bool_t __mu9_adjacent_find1__x__ = mu0_false;                                        \
	if (__first != __last) {                                                                 \
		__mu9_adjacent_find1__i__ = __first;                                                  \
		++__mu9_adjacent_find1__i__;                                                          \
		for (; __mu9_adjacent_find1__i__ != __last; ++__mu9_adjacent_find1__i__, ++__first) { \
			if (*__first == *__mu9_adjacent_find1__i__) {                                      \
					__d_result                 = __first;                                        \
					__mu9_adjacent_find1__x__ = mu0_true;                                        \
					break;                                                                       \
			}                                                                                  \
		}                                                                                     \
	}                                                                                        \
	if (!__mu9_adjacent_find1__x__) {                                                        \
		__d_result = __last;                                                                  \
	}                                                                                        \
mu0_scope_end

#	define mu9_adjacent_find2(_Tp, __first, __last, __binary_pred, __d_result)               \
mu0_scope_begin                                                                             \
	_Tp * __mu9_adjacent_find2__i__;                                                         \
	mu0_bool_t __mu9_adjacent_find2__x__ = mu0_false;                                        \
	if (__first != __last) {                                                                 \
		__mu9_adjacent_find2__i__ = __first;                                                  \
		++__mu9_adjacent_find2__i__;                                                          \
		for (; __mu9_adjacent_find2__i__ != __last; ++__mu9_adjacent_find2__i__, ++__first) { \
			if (__binary_pred(_Tp, *__first, *__mu9_adjacent_find2__i__)) {                    \
					__d_result                 = __first;                                        \
					__mu9_adjacent_find2__x__ = mu0_true;                                        \
					break;                                                                       \
			}                                                                                  \
		}                                                                                     \
	}                                                                                        \
	if (!__mu9_adjacent_find2__x__) {                                                        \
		__d_result = __last;                                                                  \
	}                                                                                        \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ADJACENT_FIND_H */

/* EOF */