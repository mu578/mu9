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

// mu9_partial_sum.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_PARTIAL_SUM_H
#define MU9_PARTIAL_SUM_H 1

MU0_BEGIN_CDECL

#	define mu9_partial_sum1(_Tp, __first, __last, __d_first)             \
mu0_scope_begin                                                         \
	_Tp __mu9_partial_sum1__v__;                                         \
	if (__first != __last) {                                             \
		__mu9_partial_sum1__v__ = *__first;                               \
		*__d_first              = __mu9_partial_sum1__v__;                \
		while (++__first != __last) {                                     \
			__mu9_partial_sum1__v__ = s__mu9_partial_sum1__v__ + *__first; \
			*++__d_first            = __mu9_partial_sum1__v__;             \
		}                                                                 \
		++__d_first;                                                      \
	}                                                                    \
mu0_scope_end

#	define mu9_partial_sum2(_Tp, __first, __last, __d_first, __binary_op)                \
mu0_scope_begin                                                                         \
	_Tp __mu9_partial_sum2__v__;                                                         \
	if (__first != __last) {                                                             \
		__mu9_partial_sum2__v__ = *__first;                                               \
		*__d_first              = __mu9_partial_sum2__v__;                                \
		while (++__first != __last) {                                                     \
			__mu9_partial_sum2__v__ = __binary_op(_Tp, __mu9_partial_sum2__v__, *__first); \
			*++__d_first            = __mu9_partial_sum2__v__;                             \
		}                                                                                 \
		++__d_first;                                                                      \
	}                                                                                    \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_PARTIAL_SUM_H */

/* EOF */