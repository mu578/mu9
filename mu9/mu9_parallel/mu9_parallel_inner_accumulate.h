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

// mu9_parallel_inner_accumulate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>
#	include <mu9/mu9_iterator.h>
#	include <mu9/mu9_algorithm/mu9_inner_accumulate.h>

#ifndef MU9_PARALLEL_INNER_ACCUMULATE_H
#define MU9_PARALLEL_INNER_ACCUMULATE_H 1

MU0_BEGIN_CDECL

#	if MU0_HAVE_PARALLELIZE
#	if MU0_HAVE_OPENMP

#	define mu9_parallel_inner_accumulate00(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2)                          \
mu0_scope_begin                                                                                                                      \
	_Tp                  __mu9_parallel_inner_accumulate00__s__ = mu0_const_cast(_Tp, __init1);                                       \
	_Tp                  __mu9_parallel_inner_accumulate00__q__ = mu0_const_cast(_Tp, __init2);                                       \
	_Tp *                __mu9_parallel_inner_accumulate00__p__ = mu9_begin(_Tp, __first);                                            \
	const mu0_distance_t __mu9_parallel_inner_accumulate00__n__ = mu9_const_distance(_Tp, __first, __last);                           \
	__mu0_pragma__(omp parallel for simd reduction(+:__mu9_parallel_inner_accumulate00__s__, __mu9_parallel_inner_accumulate00__q__)) \
	for (                                                                                                                             \
		  mu0_distance_t __mu9_parallel_inner_accumulate00__i__ = mu0_const_distance(0)                                                \
		;                __mu9_parallel_inner_accumulate00__i__ < __mu9_parallel_inner_accumulate00__n__                               \
		;                __mu9_parallel_inner_accumulate00__i__++                                                                      \
	) {                                                                                                                               \
		__mu9_parallel_inner_accumulate00__s__ = __mu9_parallel_inner_accumulate00__s__ +                                              \
			__mu9_parallel_inner_accumulate00__p__[__mu9_parallel_inner_accumulate00__i__];                                             \
		__mu9_parallel_inner_accumulate00__q__ = __mu9_parallel_inner_accumulate00__q__ +                                              \
			(	  __mu9_parallel_inner_accumulate00__p__[__mu9_parallel_inner_accumulate00__i__]                                         \
				* __mu9_parallel_inner_accumulate00__p__[__mu9_parallel_inner_accumulate00__i__]                                         \
			);                                                                                                                          \
	}                                                                                                                                 \
	__d_result1 = __mu9_parallel_inner_accumulate00__s__;                                                                             \
	__d_result2 = __mu9_parallel_inner_accumulate00__q__;                                                                             \
mu0_scope_end

#	define mu9_parallel_inner_accumulate01(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2) \
mu0_scope_begin                                                                                                                         \
	_Tp                  __mu9_parallel_inner_accumulate01__s__ = mu0_const_cast(_Tp, __init1);                                          \
	_Tp                  __mu9_parallel_inner_accumulate01__q__ = mu0_const_cast(_Tp, __init2);                                          \
	_Tp *                __mu9_parallel_inner_accumulate01__p__ = mu9_begin(_Tp, __first);                                               \
	const mu0_distance_t __mu9_parallel_inner_accumulate01__n__ = mu9_const_distance(_Tp, __first, __last);                              \
	__mu0_pragma__(omp parallel)                                                                                                         \
	{                                                                                                                                    \
		_Tp __mu9_parallel_inner_accumulate01__v__ = mu0_const_cast(_Tp, { 0 });                                                          \
		_Tp __mu9_parallel_inner_accumulate01__w__ = mu0_const_cast(_Tp, { 0 });                                                          \
		__mu0_pragma__(omp for simd)                                                                                                      \
		for (                                                                                                                             \
			  mu0_distance_t __mu9_parallel_inner_accumulate01__i__ = mu0_const_distance(0)                                                \
			;                __mu9_parallel_inner_accumulate01__i__ < __mu9_parallel_inner_accumulate01__n__                               \
			;                __mu9_parallel_inner_accumulate01__i__++                                                                      \
		) {                                                                                                                               \
			__mu9_parallel_inner_accumulate01__v__ = __binary_op1(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate01__v__                                                                                    \
				, __mu9_parallel_inner_accumulate01__p__[__mu9_parallel_inner_accumulate01__i__];                                           \
			);                                                                                                                             \
			__mu9_parallel_inner_accumulate01__w__ = __binary_op1(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate01__w__                                                                                    \
				, __binary_op2(_Tp                                                                                                          \
					, __mu9_parallel_inner_accumulate01__p__[__mu9_parallel_inner_accumulate01__i__]                                         \
					, __mu9_parallel_inner_accumulate01__p__[__mu9_parallel_inner_accumulate01__i__]                                         \
			));                                                                                                                            \
		}                                                                                                                                 \
		__mu0_pragma__(omp critical)                                                                                                      \
		{                                                                                                                                 \
			__mu9_parallel_inner_accumulate01__s__ = __binary_op1(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate01__s__                                                                                    \
				, __mu9_parallel_inner_accumulate01__v__                                                                                    \
			);                                                                                                                             \
			__mu9_parallel_inner_accumulate01__q__ = __binary_op1(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate01__q__                                                                                    \
				, __mu9_parallel_inner_accumulate01__w__                                                                                    \
			);                                                                                                                             \
		}                                                                                                                                 \
	}                                                                                                                                    \
	__d_result1 = __mu9_parallel_inner_accumulate01__s__;                                                                                \
	__d_result2 = __mu9_parallel_inner_accumulate01__q__;                                                                                \
mu0_scope_end

#	define mu9_parallel_inner_accumulate02(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2) \
mu0_scope_begin                                                                                                                        \
	_Tp                  __mu9_parallel_inner_accumulate02__s__ = mu0_const_cast(_Tp, __init1);                                         \
	_Tp                  __mu9_parallel_inner_accumulate02__q__ = mu0_const_cast(_Tp, __init2);                                         \
	_Tp *                __mu9_parallel_inner_accumulate02__p__ = mu9_begin(_Tp, __first);                                              \
	const mu0_distance_t __mu9_parallel_inner_accumulate02__n__ = mu9_const_distance(_Tp, __first, __last);                             \
	__mu0_pragma__(omp parallel)                                                                                                        \
	{                                                                                                                                   \
		_Tp __mu9_parallel_inner_accumulate02__v__ = mu0_const_cast(_Tp, { 0 });                                                         \
		_Tp __mu9_parallel_inner_accumulate02__w__ = mu0_const_cast(_Tp, { 0 });                                                         \
		__mu0_pragma__(omp for simd)                                                                                                     \
		for (                                                                                                                            \
			  mu0_distance_t __mu9_parallel_inner_accumulate02__i__ = mu0_const_distance(0)                                               \
			;                __mu9_parallel_inner_accumulate02__i__ < __mu9_parallel_inner_accumulate02__n__                              \
			;                __mu9_parallel_inner_accumulate02__i__++                                                                     \
		) {                                                                                                                              \
			__mu9_parallel_inner_accumulate02__v__ = __binary_op(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate02__v__                                                                                   \
				, __mu9_parallel_inner_accumulate02__p__[__mu9_parallel_inner_accumulate02__i__];                                          \
			);                                                                                                                            \
			__mu9_parallel_inner_accumulate02__w__ = __trinary_op(_Tp                                                                     \
				, __mu9_parallel_inner_accumulate02__p__[__mu9_parallel_inner_accumulate02__i__]                                           \
				, __mu9_parallel_inner_accumulate02__p__[__mu9_parallel_inner_accumulate02__i__]                                           \
				, __mu9_parallel_inner_accumulate02__w__                                                                                   \
			);                                                                                                                            \
		}                                                                                                                                \
		__mu0_pragma__(omp critical)                                                                                                     \
		{                                                                                                                                \
			__mu9_parallel_inner_accumulate02__s__ = __binary_op(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate02__s__                                                                                   \
				, __mu9_parallel_inner_accumulate02__v__                                                                                   \
			);                                                                                                                            \
			__mu9_parallel_inner_accumulate02__q__ = __binary_op(_Tp                                                                      \
				, __mu9_parallel_inner_accumulate02__q__                                                                                   \
				, __mu9_parallel_inner_accumulate02__w__                                                                                   \
			);                                                                                                                            \
		}                                                                                                                                \
	}                                                                                                                                   \
	__d_result1 = __mu9_parallel_inner_accumulate02__s__;                                                                               \
	__d_result2 = __mu9_parallel_inner_accumulate02__q__;                                                                               \
mu0_scope_end

#	endif
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init1, _Tp __init2, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	define mu9_sequencial_inner_accumulate1(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2) \
	mu9_inner_accumulate1(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2) 

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init1, _Tp __init2, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_inner_accumulate1(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2) \
	mu9_sequencial_inner_accumulate00(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2)
#	else
#	define mu9_parallel_inner_accumulate1(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2) \
	mu9_sequencial_inner_accumulate1(_Tp, __first, __last, __init1, __init2, __d_result1, __d_result2)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init1, _Tp __init2, __binary_op1, __binary_op2, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	define mu9_sequencial__inner_accumulate2(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2) \
	mu9_inner_accumulate2(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init1, _Tp __init2, __binary_op1, __binary_op2, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_inner_accumulate2(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2) \
	mu9_sequencial__inner_accumulate01(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2)
#	else
#	define mu9_parallel_inner_accumulate2(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2) \
	mu9_sequencial__inner_accumulate2(_Tp, __first, __last, __init1, __init2, __binary_op1, __binary_op2, __d_result1, __d_result2)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init1, _Tp __init2, __binary_op, __trinary_op, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	define mu9_sequencial_inner_accumulate3(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2) \
	mu9_inner_accumulate3(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init1, _Tp __init2, __binary_op, __trinary_op, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_inner_accumulate3(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2) \
	mu9_parallel_inner_accumulate02(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2)
#	else
#	define mu9_parallel_inner_accumulate3(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2) \
	mu9_sequencial_inner_accumulate3(_Tp, __first, __last, __init1, __init2, __binary_op, __trinary_op, __d_result1, __d_result2)
#	endif

MU0_END_CDECL

#endif /* !MU9_PARALLEL_INNER_ACCUMULATE_H */

/* EOF */