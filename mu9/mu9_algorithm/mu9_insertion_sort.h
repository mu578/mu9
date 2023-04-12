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

// mu9_insertion_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_rotate.h>
#include <mu9/mu9_algorithm/mu9_swap.h>
#include <mu9/mu9_algorithm/mu9_upper_bound.h>

#ifndef MU9_INSERTION_SORT_H
#define MU9_INSERTION_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_insertion_sort1(_Tp, __first, __last)                                 \
mu0_scope_begin                                                                     \
	_Tp * __mu9_insertion_sort1__i__ = __first;                                      \
	_Tp * __mu9_insertion_sort1__j__;                                                \
	for (; __mu9_insertion_sort1__i__ != __last; __mu9_insertion_sort1__i__++) {     \
		__mu9_insertion_sort1__j__ = __mu9_insertion_sort1__i__;                      \
		for (; __mu9_insertion_sort1__j__ != __first; __mu9_insertion_sort1__j__--) { \
			if (                                                                       \
				   *__mu9_insertion_sort1__j__                                          \
				< *(__mu9_insertion_sort1__j__ - mu0_const_distance(1))                 \
			) {                                                                        \
				mu9_swap(_Tp                                                            \
					,  *__mu9_insertion_sort1__j__                                       \
					, *(__mu9_insertion_sort1__j__ - mu0_const_distance(1))              \
				);                                                                      \
			} else {                                                                   \
				break;                                                                  \
			}                                                                          \
		}                                                                             \
	}                                                                                \
mu0_scope_end

#	define mu9_insertion_sort2(_Tp, __first, __last, __comp_fn)                      \
mu0_scope_begin                                                                     \
	_Tp * __mu9_insertion_sort2__i__ = __first;                                      \
	_Tp * __mu9_insertion_sort2__j__;                                                \
	for (; __mu9_insertion_sort2__i__ != __last; __mu9_insertion_sort2__i__++) {     \
		__mu9_insertion_sort2__j__ = __mu9_insertion_sort2__i__;                      \
		for (; __mu9_insertion_sort2__j__ != __first; __mu9_insertion_sort2__j__--) { \
			if (_comp_fn(_Tp                                                           \
				, *__mu9_insertion_sort2__j__                                           \
				, *(__mu9_insertion_sort2__j__ - mu0_const_distance(1))                 \
			)) {                                                                       \
				mu9_swap(_Tp                                                            \
					,  *__mu9_insertion_sort2__j__                                       \
					, *(__mu9_insertion_sort2__j__ - mu0_const_distance(1))              \
				);                                                                      \
			} else {                                                                   \
				break;                                                                  \
			}                                                                          \
		}                                                                             \
	}                                                                                \
mu0_scope_end

#	define mu9_insertion_sort3(_Tp, __first, __last, __sort_op, __ctx)               \
mu0_scope_begin                                                                     \
	_Tp * __mu9_insertion_sort3__i__ = __first;                                      \
	_Tp * __mu9_insertion_sort3__j__;                                                \
	for (; __mu9_insertion_sort3__i__ != __last; __mu9_insertion_sort3__i__++) {     \
		__mu9_insertion_sort3__j__ = __mu9_insertion_sort3__i__;                      \
		for (; __mu9_insertion_sort3__j__ != __first; __mu9_insertion_sort3__j__--) { \
			if (__sort_op(_Tp                                                          \
				, *__mu9_insertion_sort3__j__                                           \
				, *(__mu9_insertion_sort3__j__ - mu0_const_distance(1))                 \
				, __ctx                                                                 \
			)) {                                                                       \
				mu9_swap(_Tp                                                            \
					,  *__mu9_insertion_sort3__j__                                       \
					, *(__mu9_insertion_sort3__j__ - mu0_const_distance(1))              \
				);                                                                      \
			} else {                                                                   \
				break;                                                                  \
			}                                                                          \
		}                                                                             \
	}                                                                                \
mu0_scope_end

#	define mu9_insertion_sort4(_Tp, __first, __last)                             \
mu0_scope_begin                                                                 \
	_Tp * __mu9_insertion_sort4__i__ = __first;                                  \
	_Tp * __mu9_insertion_sort4__j__;                                            \
	_Tp * __mu9_insertion_sort4__k__;                                            \
	_Tp * __mu9_insertion_sort4__d__;                                            \
	for (; __mu9_insertion_sort4__i__ != __last; ++__mu9_insertion_sort4__i__) { \
		mu9_upper_bound1(_Tp                                                      \
			,  __first                                                             \
			,  __mu9_insertion_sort4__i__                                          \
			, *__mu9_insertion_sort4__i__                                          \
			,  __mu9_insertion_sort4__d__                                          \
		);                                                                        \
		__mu9_insertion_sort4__j__ = __mu9_insertion_sort4__d__;                  \
		__mu9_insertion_sort4__k__ = __mu9_insertion_sort4__i__;                  \
		++__mu9_insertion_sort4__k__;                                             \
		mu9_rotate1(_Tp                                                           \
			, __mu9_insertion_sort4__j__                                           \
			, __mu9_insertion_sort4__i__                                           \
			, __mu9_insertion_sort4__k__                                           \
			, __mu9_insertion_sort4__d__                                           \
		);                                                                        \
	}                                                                            \
mu0_scope_end

#	define mu9_insertion_sort5(_Tp, __first, __last, __comp_fn)                  \
mu0_scope_begin                                                                 \
	_Tp * __mu9_insertion_sort5__i__ = __first;                                  \
	_Tp * __mu9_insertion_sort5__j__;                                            \
	_Tp * __mu9_insertion_sort5__k__;                                            \
	_Tp * __mu9_insertion_sort5__d__;                                            \
	for (; __mu9_insertion_sort5__i__ != __last; ++__mu9_insertion_sort5__i__) { \
		mu9_upper_bound2(_Tp                                                      \
			,  __first                                                             \
			,  __mu9_insertion_sort5__i__                                          \
			, *__mu9_insertion_sort5__i__                                          \
			,  __comp_fn                                                           \
			,  __mu9_insertion_sort5__d__                                          \
		);                                                                        \
		__mu9_insertion_sort5__j__ = __mu9_insertion_sort5__d__;                  \
		__mu9_insertion_sort5__k__ = __mu9_insertion_sort5__i__;                  \
		++__mu9_insertion_sort5__k__;                                             \
		mu9_rotate1(_Tp                                                           \
			, __mu9_insertion_sort5__j__                                           \
			, __mu9_insertion_sort5__i__                                           \
			, __mu9_insertion_sort5__k__                                           \
			, __mu9_insertion_sort5__d__                                           \
		);                                                                        \
	}                                                                            \
mu0_scope_end

#	define mu9_insertion_sort6(_Tp, __first, __last, __sort_op, __ctx)           \
mu0_scope_begin                                                                 \
	_Tp * __mu9_insertion_sort6__i__ = __first;                                  \
	_Tp * __mu9_insertion_sort6__j__;                                            \
	_Tp * __mu9_insertion_sort6__k__;                                            \
	_Tp * __mu9_insertion_sort6__d__;                                            \
	for (; __mu9_insertion_sort6__i__ != __last; ++__mu9_insertion_sort6__i__) { \
		mu9_upper_bound3(_Tp                                                      \
			,  __first                                                             \
			,  __mu9_insertion_sort6__i__                                          \
			, *__mu9_insertion_sort6__i__                                          \
			,  __sort_op                                                           \
			,  __ctx                                                               \
			,  __mu9_insertion_sort6__d__                                          \
		);                                                                        \
		__mu9_insertion_sort6__j__ = __mu9_insertion_sort6__d__;                  \
		__mu9_insertion_sort6__k__ = __mu9_insertion_sort6__i__;                  \
		++__mu9_insertion_sort6__k__;                                             \
		mu9_rotate1(_Tp                                                           \
			, __mu9_insertion_sort6__j__                                           \
			, __mu9_insertion_sort6__i__                                           \
			, __mu9_insertion_sort6__k__                                           \
			, __mu9_insertion_sort6__d__                                           \
		);                                                                        \
	}                                                                            \
mu0_scope_end

#	define mu9_insertion_sort7(_Tp, __first, __last, __swap_op)                  \
mu0_scope_begin                                                                 \
	_Tp * __mu9_insertion_sort7__i__ = __first;                                  \
	_Tp * __mu9_insertion_sort7__j__;                                            \
	_Tp * __mu9_insertion_sort7__k__;                                            \
	_Tp * __mu9_insertion_sort7__d__;                                            \
	for (; __mu9_insertion_sort7__i__ != __last; ++__mu9_insertion_sort7__i__) { \
		mu9_upper_bound1(_Tp                                                      \
			,  __first                                                             \
			,  __mu9_insertion_sort7__i__                                          \
			, *__mu9_insertion_sort7__i__                                          \
			,  __mu9_insertion_sort7__d__                                          \
		);                                                                        \
		__mu9_insertion_sort7__j__ = __mu9_insertion_sort7__d__;                  \
		__mu9_insertion_sort7__k__ = __mu9_insertion_sort7__i__;                  \
		++__mu9_insertion_sort7__k__;                                             \
		mu9_rotate2(_Tp                                                           \
			, __mu9_insertion_sort7__j__                                           \
			, __mu9_insertion_sort7__i__                                           \
			, __mu9_insertion_sort7__k__                                           \
			, __swap_op                                                            \
			, __mu9_insertion_sort7__d__                                           \
		);                                                                        \
	}                                                                            \
mu0_scope_end

#	define mu9_insertion_sort8(_Tp, __first, __last, __comp_fn, __swap_op)       \
mu0_scope_begin                                                                 \
	_Tp * __mu9_insertion_sort8__i__ = __first;                                  \
	_Tp * __mu9_insertion_sort8__j__;                                            \
	_Tp * __mu9_insertion_sort8__k__;                                            \
	_Tp * __mu9_insertion_sort8__d__;                                            \
	for (; __mu9_insertion_sort8__i__ != __last; ++__mu9_insertion_sort8__i__) { \
		mu9_upper_bound2(_Tp                                                      \
			,  __first                                                             \
			,  __mu9_insertion_sort8__i__                                          \
			, *__mu9_insertion_sort8__i__                                          \
			,  __comp_fn                                                           \
			,  __mu9_insertion_sort8__d__                                          \
		);                                                                        \
		__mu9_insertion_sort8__j__ = __mu9_insertion_sort8__d__;                  \
		__mu9_insertion_sort8__k__ = __mu9_insertion_sort8__i__;                  \
		++__mu9_insertion_sort8__k__;                                             \
		mu9_rotate2(_Tp                                                           \
			, __mu9_insertion_sort8__j__                                           \
			, __mu9_insertion_sort8__i__                                           \
			, __mu9_insertion_sort8__k__                                           \
			, __swap_op                                                            \
			, __mu9_insertion_sort8__d__                                           \
		);                                                                        \
	}                                                                            \
mu0_scope_end

#	define mu9_insertion_sort9(_Tp, __first, __last, __sort_op, __ctx, __swap_op) \
mu0_scope_begin                                                                  \
	_Tp * __mu9_insertion_sort9__i__ = __first;                                   \
	_Tp * __mu9_insertion_sort9__j__;                                             \
	_Tp * __mu9_insertion_sort9__k__;                                             \
	_Tp * __mu9_insertion_sort9__d__;                                             \
	for (; __mu9_insertion_sort9__i__ != __last; ++__mu9_insertion_sort9__i__) {  \
		mu9_upper_bound3(_Tp                                                       \
			,  __first                                                              \
			,  __mu9_insertion_sort9__i__                                           \
			, *__mu9_insertion_sort9__i__                                           \
			,  __sort_op                                                            \
			,  __ctx                                                                \
			,  __mu9_insertion_sort9__d__                                           \
		);                                                                         \
		__mu9_insertion_sort9__j__ = __mu9_insertion_sort9__d__;                   \
		__mu9_insertion_sort9__k__ = __mu9_insertion_sort9__i__;                   \
		++__mu9_insertion_sort9__k__;                                              \
		mu9_rotate2(_Tp                                                            \
			, __mu9_insertion_sort9__j__                                            \
			, __mu9_insertion_sort9__i__                                            \
			, __mu9_insertion_sort9__k__                                            \
			, __swap_op                                                             \
			, __mu9_insertion_sort9__d__                                            \
		);                                                                         \
	}                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_INSERTION_SORT_H */

/* EOF */