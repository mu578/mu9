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

// mu9_algorithm.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#ifndef MU9_ALGORITHM_H
#define MU9_ALGORITHM_H 1

#include <mu9/mu9_algorithm/mu9_adjacent_find.h>
#include <mu9/mu9_algorithm/mu9_apply.h>
#include <mu9/mu9_algorithm/mu9_copy.h>
#include <mu9/mu9_algorithm/mu9_count.h>
#include <mu9/mu9_algorithm/mu9_equal.h>
#include <mu9/mu9_algorithm/mu9_fill.h>
#include <mu9/mu9_algorithm/mu9_find.h>
#include <mu9/mu9_algorithm/mu9_for_each.h>
#include <mu9/mu9_algorithm/mu9_iota.h>
#include <mu9/mu9_algorithm/mu9_mismatch.h>
#include <mu9/mu9_algorithm/mu9_partition.h>
#include <mu9/mu9_algorithm/mu9_rotate.h>
#include <mu9/mu9_algorithm/mu9_search.h>
#include <mu9/mu9_algorithm/mu9_swap.h>
#include <mu9/mu9_algorithm/mu9_transform.h>

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first, _Tp &* __last, __unary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_all_of(__first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                 \
	mu9_bool_t __mu9_all_of__x__ = mu9_true;                     \
	for (; __first != __last; ++__first) {                       \
		if (!__unary_pred(*__first)) {                            \
			__mu9_all_of__x__ = mu9_false;                         \
			break;                                                 \
		}                                                         \
	}                                                            \
	__d_result = __mu9_all_of__x__;                              \
mu0_scope_end

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first, _Tp &* __last, __unary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_any_of(__first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                 \
	mu9_bool_t __mu9_any_of__x__ = mu9_false;                    \
	for (; __first != __last; ++__first) {                       \
		if (__unary_pred(*__first)) {                             \
			__mu9_any_of__x__ = mu9_true;                          \
			break;                                                 \
		}                                                         \
	}                                                            \
	__d_result = __mu9_any_of__x__;                              \
mu0_scope_end

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first, _Tp &* __last, __unary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_none_of(__first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                  \
	mu9_bool_t __mu9_none_of__x__ = mu9_true;                     \
	for (; __first != __last; ++__first) {                        \
		if (__unary_pred(*__first)) {                              \
			__mu9_none_of__x__ = mu9_false;                         \
			break;                                                  \
		}                                                          \
	}                                                             \
	__d_result = __mu9_none_of__x__;                              \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ALGORITHM_H */

/* EOF */