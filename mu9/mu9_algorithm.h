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

#include <mu0/mu0_definition.h>

#ifndef MU9_ALGORITHM_H
#define MU9_ALGORITHM_H 1

#	include <mu9/mu9_algorithm/mu9_adjacent_find.h>
#	include <mu9/mu9_algorithm/mu9_argument_sort.h>
#	include <mu9/mu9_algorithm/mu9_binary_search.h>
#	include <mu9/mu9_algorithm/mu9_bubble_sort.h>
#	include <mu9/mu9_algorithm/mu9_copy_backward.h>
#	include <mu9/mu9_algorithm/mu9_copy.h>
#	include <mu9/mu9_algorithm/mu9_count.h>
#	include <mu9/mu9_algorithm/mu9_equal_range.h>
#	include <mu9/mu9_algorithm/mu9_equal.h>
#	include <mu9/mu9_algorithm/mu9_exist.h>
#	include <mu9/mu9_algorithm/mu9_fill.h>
#	include <mu9/mu9_algorithm/mu9_filter.h>
#	include <mu9/mu9_algorithm/mu9_find.h>
#	include <mu9/mu9_algorithm/mu9_for_each_by.h>
#	include <mu9/mu9_algorithm/mu9_for_each.h>
#	include <mu9/mu9_algorithm/mu9_generate.h>
#	include <mu9/mu9_algorithm/mu9_heap_siftdown.h>
#	include <mu9/mu9_algorithm/mu9_heap_siftup.h>
#	include <mu9/mu9_algorithm/mu9_includes.h>
#	include <mu9/mu9_algorithm/mu9_insertion_sort.h>
#	include <mu9/mu9_algorithm/mu9_is_heap_until.h>
#	include <mu9/mu9_algorithm/mu9_is_sorted_until.h>
#	include <mu9/mu9_algorithm/mu9_is_sorted.h>
#	include <mu9/mu9_algorithm/mu9_lower_bound.h>
#	include <mu9/mu9_algorithm/mu9_make_heap.h>
#	include <mu9/mu9_algorithm/mu9_max_element.h>
#	include <mu9/mu9_algorithm/mu9_merge.h>
#	include <mu9/mu9_algorithm/mu9_min_element.h>
#	include <mu9/mu9_algorithm/mu9_minmax_element.h>
#	include <mu9/mu9_algorithm/mu9_mismatch.h>
#	include <mu9/mu9_algorithm/mu9_move_backward.h>
#	include <mu9/mu9_algorithm/mu9_move.h>
#	include <mu9/mu9_algorithm/mu9_partition_point.h>
#	include <mu9/mu9_algorithm/mu9_partition.h>
#	include <mu9/mu9_algorithm/mu9_random_sample_n.h>
#	include <mu9/mu9_algorithm/mu9_random_sample.h>
#	include <mu9/mu9_algorithm/mu9_random_shuffle.h>
#	include <mu9/mu9_algorithm/mu9_reduce.h>
#	include <mu9/mu9_algorithm/mu9_remove.h>
#	include <mu9/mu9_algorithm/mu9_reverse.h>
#	include <mu9/mu9_algorithm/mu9_rotate.h>
#	include <mu9/mu9_algorithm/mu9_sample.h>
#	include <mu9/mu9_algorithm/mu9_search.h>
#	include <mu9/mu9_algorithm/mu9_selection_sort.h>
#	include <mu9/mu9_algorithm/mu9_set_difference.h>
#	include <mu9/mu9_algorithm/mu9_set_intersection.h>
#	include <mu9/mu9_algorithm/mu9_set_symmetric_difference.h>
#	include <mu9/mu9_algorithm/mu9_set_union.h>
#	include <mu9/mu9_algorithm/mu9_shell_sort.h>
#	include <mu9/mu9_algorithm/mu9_shift_left.h>
#	include <mu9/mu9_algorithm/mu9_shuffle.h>
#	include <mu9/mu9_algorithm/mu9_sort_heap.h>
#	include <mu9/mu9_algorithm/mu9_stable_sort.h>
#	include <mu9/mu9_algorithm/mu9_swap.h>
#	include <mu9/mu9_algorithm/mu9_transform_by.h>
#	include <mu9/mu9_algorithm/mu9_transform_reduce.h>
#	include <mu9/mu9_algorithm/mu9_transform.h>
#	include <mu9/mu9_algorithm/mu9_unique.h>
#	include <mu9/mu9_algorithm/mu9_upper_bound.h>

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first, _Tp &* __last, __unary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_all_of(_Tp, __first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                      \
	mu0_bool_t __mu9_all_of__x__ = mu0_true;                          \
	for (; __first != __last; ++__first) {                            \
		if (!__unary_pred(_Tp, *__first)) {                            \
			__mu9_all_of__x__ = mu0_false;                              \
			break;                                                      \
		}                                                              \
	}                                                                 \
	__d_result = __mu9_all_of__x__;                                   \
mu0_scope_end

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first, _Tp &* __last, __unary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_any_of(_Tp, __first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                      \
	mu0_bool_t __mu9_any_of__x__ = mu0_false;                         \
	for (; __first != __last; ++__first) {                            \
		if (__unary_pred(_Tp, *__first)) {                             \
			__mu9_any_of__x__ = mu0_true;                               \
			break;                                                      \
		}                                                              \
	}                                                                 \
	__d_result = __mu9_any_of__x__;                                   \
mu0_scope_end

//#!
//#! macro<_Tp, _Bool>(_Tp &* __first, _Tp &* __last, __unary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_none_of(_Tp, __first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                       \
	mu0_bool_t __mu9_none_of__x__ = mu0_true;                          \
	for (; __first != __last; ++__first) {                             \
		if (__unary_pred(_Tp, *__first)) {                              \
			__mu9_none_of__x__ = mu0_false;                              \
			break;                                                       \
		}                                                               \
	}                                                                  \
	__d_result = __mu9_none_of__x__;                                   \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ALGORITHM_H */

/* EOF */