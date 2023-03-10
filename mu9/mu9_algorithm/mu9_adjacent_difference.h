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

// mu9_adjacent_difference.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_ADJACENT_DIFFERENCE_H
#define MU9_ADJACENT_DIFFERENCE_H 1

MU0_BEGIN_CDECL

#	define mu9_adjacent_difference1(_Tp, __first, __last, __d_first)                                           \
mu0_scope_begin                                                                                               \
	_Tp __mu9_adjacent_difference1__v__;                                                                       \
	_Tp __mu9_adjacent_difference1__w__;                                                                       \
	if (__first != __last) {                                                                                   \
		__mu9_adjacent_difference1__v__ = *__first;                                                             \
		*__d_first                      = __mu9_adjacent_difference1__v__;                                      \
		while (++__first != __last) {                                                                           \
		__mu9_adjacent_difference1__w__    = *__first;                                                          \
			*++__d_first                    = __mu9_adjacent_difference1__w__ - __mu9_adjacent_difference1__v__; \
			__mu9_adjacent_difference1__v__ = __mu9_adjacent_difference1__w__;                                   \
		}                                                                                                       \
		++__d_first;                                                                                            \
	}                                                                                                          \
mu0_scope_end

#	define mu9_adjacent_difference2(_Tp, __first, __last, __d_first, __binary_op) \
mu0_scope_begin                                                                  \
	_Tp __mu9_adjacent_difference2__v__;                                          \
	_Tp __mu9_adjacent_difference2__w__;                                          \
	if (__first != __last) {                                                      \
		__mu9_adjacent_difference2__v__ = *__first;                                \
		*__d_first                      = __mu9_adjacent_difference2__v__;         \
		while (++__first != __last) {                                              \
		__mu9_adjacent_difference2__w__    = *__first;                             \
			*++__d_first                    = __binary_op(_Tp                       \
				, __mu9_adjacent_difference2__w__                                    \
				, __mu9_adjacent_difference2__v__                                    \
			);                                                                      \
			__mu9_adjacent_difference2__v__ = __mu9_adjacent_difference2__w__;      \
		}                                                                          \
		++__d_first;                                                               \
	}                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ADJACENT_DIFFERENCE_H */

/* EOF */