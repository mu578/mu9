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

// mu9_parallel_max_element.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>
#	include <mu9/mu9_iterator.h>
#	include <mu9/mu9_algorithm/mu9_max_element.h>

#ifndef MU9_PARALLEL_MAX_ELEMENT_H
#define MU9_PARALLEL_MAX_ELEMENT_H 1

MU0_BEGIN_CDECL

#	if MU0_HAVE_PARALLELIZE
#	if MU0_HAVE_OPENMP

#	define mu9_parallel_max_element00(_Tp, __first, __last, __comp_fn, __d_result)                                                          \
mu0_scope_begin                                                                                                                            \
	      _Tp            __mu9_parallel_max_element00__v__ = *__first;                                                                      \
	      _Tp *          __mu9_parallel_max_element00__p__ = mu9_begin(_Tp, __first);                                                       \
	const mu0_distance_t __mu9_parallel_max_element00__n__ = mu9_const_distance(_Tp, __first, __last);                                      \
	      mu0_distance_t __mu9_parallel_max_element00__k__ = mu0_const_distance(0);                                                         \
	if (__first != __last) {                                                                                                                \
		__mu0_pragma__(omp parallel)                                                                                                         \
		{                                                                                                                                    \
			mu0_distance_t __mu9_parallel_max_element00__j__ = __mu9_parallel_max_element00__k__;                                             \
			_Tp            __mu9_parallel_max_element00__w__ = __mu9_parallel_max_element00__v__;                                             \
			__mu0_pragma__(omp for nowait)                                                                                                    \
			for (                                                                                                                             \
				  mu0_distance_t __mu9_parallel_max_element00__i__ = mu0_const_distance(1)                                                     \
				;                __mu9_parallel_max_element00__i__ < __mu9_parallel_max_element00__n__                                         \
				;                __mu9_parallel_max_element00__i__++                                                                           \
			) {                                                                                                                               \
				if (__comp_fn(_Tp, __mu9_parallel_max_element00__w__, __mu9_parallel_max_element00__p__[__mu9_parallel_max_element00__i__])) { \
						__mu9_parallel_max_element00__w__ = __mu9_parallel_max_element00__p__[__mu9_parallel_max_element00__i__];                \
						__mu9_parallel_max_element00__j__ = __mu9_parallel_max_element00__i__;                                                   \
				}                                                                                                                              \
			}                                                                                                                                 \
			__mu0_pragma__(omp critical)                                                                                                      \
			{                                                                                                                                 \
				if (__comp_fn(_Tp, __mu9_parallel_max_element00__v__, __mu9_parallel_max_element00__w__)) {                                    \
						__mu9_parallel_max_element00__v__ = __mu9_parallel_max_element00__w__;                                                   \
						__mu9_parallel_max_element00__k__ = __mu9_parallel_max_element00__j__;                                                   \
				}                                                                                                                              \
			}                                                                                                                                 \
		}                                                                                                                                    \
		__first    = mu9_next_n(_Tp, __mu9_parallel_max_element00__p__, __mu9_parallel_max_element00__k__);                                  \
		__d_result = __first;                                                                                                                \
	} else {                                                                                                                                \
		__d_result = __last;                                                                                                                 \
	}                                                                                                                                       \
mu0_scope_end

#	endif
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_max_element1(_Tp, __first, __last, __d_result) \
	mu9_max_element1(_Tp, __first, __last, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_max_element1(_Tp, __first, __last, __d_result) \
	mu9_parallel_max_element00(_Tp, __first, __last, mu9_less, __d_result)
#	else
#	define mu9_parallel_max_element1(_Tp, __first, __last, __d_result) \
	mu9_sequencial_max_element1(_Tp, __first, __last, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, __comp_fn, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_max_element2(_Tp, __first, __last, __comp_fn, __d_result) \
	mu9_max_element2(_Tp, __first, __last, __comp_fn, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, __comp_fn, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_max_element2(_Tp, __first, __last, __comp_fn, __d_result) \
	mu9_parallel_max_element00(_Tp, __first, __last, __comp_fn, __d_result)
#	else
#	define mu9_parallel_max_element2(_Tp, __first, __last, __comp_fn, __d_result) \
	mu9_sequencial_max_element2(_Tp, __first, __last, __comp_fn, __d_result)
#	endif

MU0_END_CDECL

#endif /* !MU9_PARALLEL_MAX_ELEMENT_H */

/* EOF */