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

// mu9_parallel_shell_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>
#	include <mu9/mu9_iterator.h>
#	include <mu9/mu9_algorithm/mu9_shell_sort.h>

#ifndef MU9_PARALLEL_SHELL_SORT_H
#define MU9_PARALLEL_SHELL_SORT_H 1

MU0_BEGIN_CDECL

#	if MU0_HAVE_PARALLELIZE

#	define mu9_parallel_shell_sort00(_Tp, __first, __last, __comp_fn)                                                                       \
mu0_scope_begin                                                                                                                            \
	_Tp *                __mu9_parallel_shell_sort00__p__ = mu9_begin(_Tp, __first);                                                        \
	const mu0_distance_t __mu9_parallel_shell_sort00__n__ = mu9_const_distance(_Tp, __first, __last);                                       \
	__mu0_pragma__(omp parallel)                                                                                                            \
	{                                                                                                                                       \
		mu0_difference_t __mu9_parallel_shell_sort00__x__ = __mu9_parallel_shell_sort00__n__ / mu0_const_difference(2);                      \
		while (__mu9_parallel_shell_sort00__x__) {                                                                                           \
			__mu0_pragma__(omp for)                                                                                                           \
			for (                                                                                                                             \
				  mu0_distance_t __mu9_parallel_shell_sort00__i__ = mu0_const_distance(0)                                                      \
				; __mu9_parallel_shell_sort00__i__ < (__mu9_parallel_shell_sort00__n__ - __mu9_parallel_shell_sort00__x__)                     \
				; __mu9_parallel_shell_sort00__i__++                                                                                           \
			) {                                                                                                                               \
				mu0_distance_t __mu9_parallel_shell_sort00__j__ = __mu9_parallel_shell_sort00__i__;                                            \
				for (                                                                                                                          \
					  mu0_distance_t __mu9_parallel_shell_sort00__j__ = __mu9_parallel_shell_sort00__i__                                        \
					; __mu9_parallel_shell_sort00__j__ >= mu0_const_distance(0) && !__comp_fn(_Tp                                               \
						, __mu9_parallel_shell_sort00__p__[__mu9_parallel_shell_sort00__j__]                                                     \
						, __mu9_parallel_shell_sort00__p__[__mu9_parallel_shell_sort00__j__ + __mu9_parallel_shell_sort00__x__]                  \
					)                                                                                                                           \
					; __mu9_parallel_shell_sort00__j__--                                                                                        \
				) {                                                                                                                            \
					mu9_iter_swap(_Tp                                                                                                           \
						, mu9_next_n(_Tp, __mu9_parallel_shell_sort00__p__, __mu9_parallel_shell_sort00__j__)                                    \
						, mu9_next_n(_Tp, __mu9_parallel_shell_sort00__p__, __mu9_parallel_shell_sort00__j__ + __mu9_parallel_shell_sort00__x__) \
					);                                                                                                                          \
				}                                                                                                                              \
			}                                                                                                                                 \
			__mu9_parallel_shell_sort00__x__ /= mu0_const_difference(2);                                                                      \
		}                                                                                                                                    \
	}                                                                                                                                       \
mu0_scope_end

#	define mu9_parallel_shell_sort01(_Tp, __first, __last, __sort_op, __ctx)                                                                \
mu0_scope_begin                                                                                                                            \
	_Tp *                __mu9_parallel_shell_sort01__p__ = mu9_begin(_Tp, __first);                                                        \
	const mu0_distance_t __mu9_parallel_shell_sort01__n__ = mu9_const_distance(_Tp, __first, __last);                                       \
	__mu0_pragma__(omp parallel)                                                                                                            \
	{                                                                                                                                       \
		mu0_difference_t __mu9_parallel_shell_sort01__x__ = __mu9_parallel_shell_sort01__n__ / mu0_const_difference(2);                      \
		while (__mu9_parallel_shell_sort01__x__) {                                                                                           \
			__mu0_pragma__(omp for)                                                                                                           \
			for (                                                                                                                             \
				  mu0_distance_t __mu9_parallel_shell_sort01__i__ = mu0_const_distance(0)                                                      \
				; __mu9_parallel_shell_sort01__i__ < (__mu9_parallel_shell_sort01__n__ - __mu9_parallel_shell_sort01__x__)                     \
				; __mu9_parallel_shell_sort01__i__++                                                                                           \
			) {                                                                                                                               \
				mu0_distance_t __mu9_parallel_shell_sort01__j__ = __mu9_parallel_shell_sort01__i__;                                            \
				for (                                                                                                                          \
					  mu0_distance_t __mu9_parallel_shell_sort01__j__ = __mu9_parallel_shell_sort01__i__                                        \
					; __mu9_parallel_shell_sort01__j__ >= mu0_const_distance(0) && !__sort_op(_Tp                                               \
						, __mu9_parallel_shell_sort01__p__[__mu9_parallel_shell_sort01__j__]                                                     \
						, __mu9_parallel_shell_sort01__p__[__mu9_parallel_shell_sort01__j__ + __mu9_parallel_shell_sort01__x__]                  \
						, __ctx                                                                                                                  \
					)                                                                                                                           \
					; __mu9_parallel_shell_sort01__j__--                                                                                        \
				) {                                                                                                                            \
					mu9_iter_swap(_Tp                                                                                                           \
						, mu9_next_n(_Tp, __mu9_parallel_shell_sort01__p__, __mu9_parallel_shell_sort01__j__)                                    \
						, mu9_next_n(_Tp, __mu9_parallel_shell_sort01__p__, __mu9_parallel_shell_sort01__j__ + __mu9_parallel_shell_sort01__x__) \
					);                                                                                                                          \
				}                                                                                                                              \
			}                                                                                                                                 \
			__mu9_parallel_shell_sort01__x__ /= mu0_const_difference(2);                                                                      \
		}                                                                                                                                    \
	}                                                                                                                                       \
mu0_scope_end

#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last) : void
//#!
#	define mu9_sequencial_shell_sort1(_Tp, __first, __last) \
	mu9_shell_sort1(_Tp, __first, __last)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_shell_sort1(_Tp, __first, __last) \
	mu9_parallel_shell_sort00(_Tp, __first, __last,  mu9_less)
#	else
#	define mu9_parallel_shell_sort1(_Tp, __first, __last) \
	mu9_sequencial_shell_sort1(_Tp, __first, __last)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, __comp_fn) : void
//#!
#	define mu9_sequencial_shell_sort2(_Tp, __first, __last, __comp_fn) \
	mu9_shell_sort2(_Tp, __first, __last, __comp_fn)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, __comp_fn) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_shell_sort2(_Tp, __first, __last, __comp_fn) \
	mu9_parallel_shell_sort00(_Tp, __first, __last,  __comp_fn)
#	else
#	define mu9_parallel_shell_sort2(_Tp, __first, __last, __comp_fn) \
	mu9_sequencial_shell_sort2(_Tp, __first, __last, __comp_fn)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, __sort_op, __ctx) : void
//#!
#	define mu9_sequencial_shell_sort3(_Tp, __first, __last, __sort_op, __ctx) \
	mu9_shell_sort3(_Tp, __first, __last, __sort_op, __ctx)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, __sort_op, __ctx) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_shell_sort3(_Tp, __first, __last, __sort_op, __ctx) \
	mu9_parallel_shell_sort01(_Tp, __first, __last, __sort_op, __ctx)
#	else
#	define mu9_parallel_shell_sort3(_Tp, __first, __last, __sort_op, __ctx) \
	mu9_sequencial_shell_sort3(_Tp, __first, __last, __sort_op, __ctx)
#	endif

MU0_END_CDECL

#endif /* !MU9_PARALLEL_SHELL_SORT_H */

/* EOF */