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

// mu9_equal.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_EQUAL_H
#define MU9_EQUAL_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, _Bool<return> & __d_result) : void
//#!
#	define mu9_equal1(_Tp, __first1, __last1,  __first2, __d_result) \
mu9_scope_begin                                                     \
	mu9_bool_t ___mu9_equal1__x__ = m9_true;                         \
	for (; __first1 != __last1; ++__first1, ++__first2) {            \
		if (!(*__first1 == *__first2)) {                              \
			___mu9_equal1__x__ = m9_false;                             \
			break;                                                     \
		}                                                             \
	}                                                                \
	__d_result = ___mu9_equal1__x__;                                 \
mu9_scope_end

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, __binary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_equal2(_Tp, __first1, __last1,  __first2, __binary_pred, __d_result) \
mu9_scope_begin                                                                    \
	mu9_bool_t ___mu9_equal2__x__ = m9_true;                                        \
	for (; __first1 != __last1; ++__first1, ++__first2) {                           \
		if (!__binary_pred(*__first1, *__first2)) {                                 \
			___mu9_equal2__x__ = m9_false;                                           \
			break;                                                                   \
		}                                                                           \
	}                                                                              \
	__d_result = ___mu9_equal2__x__;                                               \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_EQUAL_H */

/* EOF */