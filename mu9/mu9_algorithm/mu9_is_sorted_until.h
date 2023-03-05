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

// mu9_is_sorted_until.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_IS_SORTED_UNTIL_H
#define MU9_IS_SORTED_UNTIL_H 1

MU0_BEGIN_CDECL

#	define mu9_is_sorted_until1(_Tp, __first, __last, __d_result) \
mu0_scope_begin                                                  \
	_Tp * __mu9_is_sorted_until1__i__;                            \
	__d_result = __last;                                          \
	if (__first != __last) {                                      \
		__mu9_is_sorted_until1__i__ = __first;                     \
		while (++__mu9_is_sorted_until1__i__ != __last) {          \
			if (*__mu9_is_sorted_until1__i__ < *__first) {          \
				__d_result = __mu9_is_sorted_until1__i__;            \
				break;                                               \
			}                                                       \
			__first = __mu9_is_sorted_until1__i__;                  \
		}                                                          \
	}                                                             \
mu0_scope_end

#	define mu9_is_sorted_until2(_Tp, __first, __last, __comp_fn, __d_result) \
mu0_scope_begin                                                             \
	_Tp * __mu9_is_sorted_until2__i__;                                       \
	__d_result = __last;                                                     \
	if (__first != __last) {                                                 \
		__mu9_is_sorted_until2__i__ = __first;                                \
		while (++__mu9_is_sorted_until2__i__ != __last) {                     \
			if (_comp_fn(_Tp, *__mu9_is_sorted_until2__i__, *__first)) {       \
				__d_result = __mu9_is_sorted_until2__i__;                       \
				break;                                                          \
			}                                                                  \
			__first = __mu9_is_sorted_until2__i__;                             \
		}                                                                     \
	}                                                                        \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_IS_SORTED_UNTIL_H */

/* EOF */