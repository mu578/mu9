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

// mu9_parallel_accumulate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#	include <mu9/mu9_functional.h>
#	include <mu9/mu9_iterator.h>
#	include <mu9/mu9_algorithm/mu9_accumulate.h>

#ifndef MU9_PARALLEL_ACCUMULATE_H
#define MU9_PARALLEL_ACCUMULATE_H 1

MU0_BEGIN_CDECL

#	if MU0_HAVE_PARALLELIZE
#	if MU0_HAVE_OPENMP

#	define mu9_parallel_accumulate00(_Tp, __first, __last, __init, __d_result)                        \
mu0_scope_begin                                                                                      \
	_Tp                  __mu9_parallel_accumulate00__v__ = mu0_const_cast(_Tp, __init);              \
	_Tp *                __mu9_parallel_accumulate00__p__ = mu9_begin(_Tp, __first);                  \
	const mu0_distance_t __mu9_parallel_accumulate00__n__ = mu9_const_distance(_Tp, __first, __last); \
	__mu0_pragma__(omp parallel for simd reduction(+:__mu9_parallel_accumulate00__v__))               \
	for (                                                                                             \
		  mu0_distance_t __mu9_parallel_accumulate00__i__ = mu0_const_distance(0)                      \
		;                __mu9_parallel_accumulate00__i__ < __mu9_parallel_accumulate00__n__           \
		;                __mu9_parallel_accumulate00__i__++                                            \
	) {                                                                                               \
		__mu9_parallel_accumulate00__v__ = __mu9_parallel_accumulate00__v__                            \
			+ __mu9_parallel_accumulate00__p__[__mu9_parallel_accumulate00__i__];                       \
	}                                                                                                 \
	__d_result = __mu9_parallel_accumulate00__v__;                                                    \
mu0_scope_end

#	define mu9_parallel_accumulate01(_Tp, __first, __last, __init, __binary_op, __d_result)           \
mu0_scope_begin                                                                                      \
	_Tp                  __mu9_parallel_accumulate01__v__ = mu0_const_cast(_Tp, __init);              \
	_Tp *                __mu9_parallel_accumulate01__p__ = mu9_begin(_Tp, __first);                  \
	const mu0_distance_t __mu9_parallel_accumulate01__n__ = mu9_const_distance(_Tp, __first, __last); \
	__mu0_pragma__(omp parallel)                                                                      \
	{                                                                                                 \
		_Tp __mu9_parallel_accumulate01__w__ = ___mu0_arithmetic_initialize__(_Tp, 0);                 \
		__mu0_pragma__(omp for simd)                                                                   \
		for (                                                                                          \
			  mu0_distance_t __mu9_parallel_accumulate01__i__ = mu0_const_distance(0)                   \
			;                __mu9_parallel_accumulate01__i__ < __mu9_parallel_accumulate01__n__        \
			;                __mu9_parallel_accumulate01__i__++                                         \
		) {                                                                                            \
			__mu9_parallel_accumulate01__w__ = __binary_op(_Tp                                          \
				, __mu9_parallel_accumulate01__w__                                                       \
				, __mu9_parallel_accumulate01__p__[__mu9_parallel_accumulate01__i__]                     \
			);                                                                                          \
		}                                                                                              \
		__mu0_pragma__(omp critical)                                                                   \
		{                                                                                              \
			__mu9_parallel_accumulate01__v__ = __binary_op(_Tp                                          \
				, __mu9_parallel_accumulate01__v__                                                       \
				, __mu9_parallel_accumulate01__w__                                                       \
			);                                                                                          \
		}                                                                                              \
	}                                                                                                 \
	__d_result = __mu9_parallel_accumulate01__v__;                                                    \
mu0_scope_end

#	define mu9_parallel_accumulate02(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result) \
mu0_scope_begin                                                                                          \
	_Tp                  __mu9_parallel_accumulate02__v__ = mu0_const_cast(_Tp, __init);                  \
	_Tp *                __mu9_parallel_accumulate02__p__ = mu9_begin(_Tp, __first);                      \
	const mu0_distance_t __mu9_parallel_accumulate02__n__ = mu9_const_distance(_Tp, __first, __last);     \
	__mu0_pragma__(omp parallel)                                                                          \
	{                                                                                                     \
		_Tp __mu9_parallel_accumulate02__w__ = __mu0_arithmetic_initialize__(_Tp, 0);                      \
		__mu0_pragma__(omp for simd)                                                                       \
		for (                                                                                              \
			  mu0_distance_t __mu9_parallel_accumulate02__i__ = mu0_const_distance(0)                       \
			;                __mu9_parallel_accumulate02__i__ < __mu9_parallel_accumulate02__n__            \
			;                __mu9_parallel_accumulate02__i__++                                             \
		) {                                                                                                \
			__mu9_parallel_accumulate02__w__ = __trinary_op(_Tp                                             \
				, __mu9_parallel_accumulate02__w__                                                           \
				, __mu9_parallel_accumulate02__p__[__mu9_parallel_accumulate02__i__]                         \
				, __mu9_parallel_accumulate02__p__[__mu9_parallel_accumulate02__i__]                         \
			);                                                                                              \
		}                                                                                                  \
		__mu0_pragma__(omp critical)                                                                       \
		{                                                                                                  \
			__mu9_parallel_accumulate02__v__ = __binary_op(_TP                                              \
				, __mu9_parallel_accumulate02__v__                                                           \
				, __mu9_parallel_accumulate02__w__                                                           \
			);                                                                                              \
		}                                                                                                  \
	}                                                                                                     \
	__d_result = __mu9_parallel_accumulate02__v__;                                                        \
mu0_scope_end

#	define mu9_parallel_accumulate03(_Tp, __first1, __last1, __first2, __init, __d_result)              \
mu0_scope_begin                                                                                        \
	_Tp                  __mu9_parallel_accumulate03__v__ = mu0_const_cast(_Tp, __init);                \
	_Tp *                __mu9_parallel_accumulate03__x__ = mu9_begin(_Tp, __first1);                   \
	_Tp *                __mu9_parallel_accumulate03__y__ = mu9_begin(_Tp, __first2);                   \
	const mu0_distance_t __mu9_parallel_accumulate03__n__ = mu9_const_distance(_Tp, __first1, __last1); \
	__mu0_pragma__(omp parallel for simd reduction(+:__mu9_parallel_accumulate03__v__))                 \
	for (                                                                                               \
		  mu0_distance_t __mu9_parallel_accumulate03__i__ = mu0_const_distance(0)                        \
		;                __mu9_parallel_accumulate03__i__ < __mu9_parallel_accumulate03__n__             \
		;                __mu9_parallel_accumulate03__i__++                                              \
	) {                                                                                                 \
		__mu9_parallel_accumulate03__v__ = (__mu9_parallel_accumulate03__v__ + (                         \
			  __mu9_parallel_accumulate03__x__[__mu9_parallel_accumulate03__i__]                          \
			+ __mu9_parallel_accumulate03__y__[__mu9_parallel_accumulate03__i__]                          \
		));                                                                                              \
	}                                                                                                   \
	__d_result = __mu9_parallel_accumulate03__v__;                                                      \
mu0_scope_end

#	define mu9_parallel_accumulate04(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result) \
mu0_scope_begin                                                                                        \
	_Tp                  __mu9_parallel_accumulate04__v__ = mu0_const_cast(_Tp, __init);                \
	_Tp *                __mu9_parallel_accumulate04__x__ = mu9_begin(_Tp, __first1);                   \
	_Tp *                __mu9_parallel_accumulate04__y__ = mu9_begin(_Tp, __first2);                   \
	const mu0_distance_t __mu9_parallel_accumulate04__n__ = mu9_const_distance(_Tp, __first1, __last1); \
	__mu0_pragma__(omp parallel)                                                                        \
	{                                                                                                   \
		_Tp __mu9_parallel_accumulate04__w__ = __mu0_arithmetic_initialize__(_Tp, 0);                    \
		__mu0_pragma__(omp for simd)                                                                     \
		for (                                                                                            \
			  mu0_distance_t __mu9_parallel_accumulate04__i__ = mu0_const_distance(0)                     \
			;                __mu9_parallel_accumulate04__i__ < __mu9_parallel_accumulate04__n__          \
			;                __mu9_parallel_accumulate04__i__++                                           \
		) {                                                                                              \
			__mu9_parallel_accumulate04__w__ = __binary_op(_Tp                                            \
				, __mu9_parallel_accumulate04__w__                                                         \
				, __binary_op(_Tp                                                                          \
					, __mu9_parallel_accumulate04__x__[__mu9_parallel_accumulate04__i__]                    \
					, __mu9_parallel_accumulate04__y__[__mu9_parallel_accumulate04__i__]                    \
			));                                                                                           \
		}                                                                                                \
		__mu0_pragma__(omp critical)                                                                     \
		{                                                                                                \
			__mu9_parallel_accumulate04__v__ = __binary_op(_Tp                                            \
				, __mu9_parallel_accumulate04__v__                                                         \
				, __mu9_parallel_accumulate04__w__                                                         \
			);                                                                                            \
		}                                                                                                \
	}                                                                                                   \
	__d_result = __mu9_parallel_accumulate04__v__;                                                      \
mu0_scope_end

#	define mu9_parallel_accumulate05(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result) \
mu0_scope_begin                                                                                                       \
	_Tp                  __mu9_parallel_accumulate05__v__ = mu0_const_cast(_Tp, __init);                               \
	_Tp *                __mu9_parallel_accumulate05__x__ = mu9_begin(_Tp, __first1);                                  \
	_Tp *                __mu9_parallel_accumulate05__y__ = mu9_begin(_Tp, __first2);                                  \
	const mu0_distance_t __mu9_parallel_accumulate05__n__ = mu9_const_distance(_Tp, __first1, __last1);                \
	__mu0_pragma__(omp parallel)                                                                                       \
	{                                                                                                                  \
		_Tp __mu9_parallel_accumulate05__w__ = __mu0_arithmetic_initialize__(_Tp, 0);                                   \
		__mu0_pragma__(omp for simd)                                                                                    \
		for (                                                                                                           \
			  mu0_distance_t __mu9_parallel_accumulate05__i__ = mu0_const_distance(0)                                    \
			;                __mu9_parallel_accumulate05__i__ < __mu9_parallel_accumulate05__n__                         \
			;                __mu9_parallel_accumulate05__i__++                                                          \
		) {                                                                                                             \
			__mu9_parallel_accumulate05__w__ = __binary_op1(_Tp                                                          \
				, __mu9_parallel_accumulate05__w__                                                                        \
				, __binary_op2(_Tp                                                                                        \
					, __mu9_parallel_accumulate05__x__[__mu9_parallel_accumulate05__i__]                                   \
					, __mu9_parallel_accumulate05__y__[__mu9_parallel_accumulate05__i__]                                   \
			));                                                                                                          \
		}                                                                                                               \
		__mu0_pragma__(omp critical)                                                                                    \
		{                                                                                                               \
			__mu9_parallel_accumulate05__v__ = __binary_op1(_Tp                                                          \
				, __mu9_parallel_accumulate05__v__                                                                        \
				, __mu9_parallel_accumulate05__w__                                                                        \
			);                                                                                                           \
		}                                                                                                               \
	}                                                                                                                  \
	__d_result = __mu9_parallel_accumulate05__v__;                                                                     \
mu0_scope_end

#	define mu9_parallel_accumulate06(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_op, __d_result) \
mu0_scope_begin                                                                                                      \
	_Tp                  __mu9_parallel_accumulate06__v__ = mu0_const_cast(_Tp, __init);                              \
	_Tp *                __mu9_parallel_accumulate06__x__ = mu9_begin(_Tp, __first1);                                 \
	_Tp *                __mu9_parallel_accumulate06__y__ = mu9_begin(_Tp, __first2);                                 \
	const mu0_distance_t __mu9_parallel_accumulate06__n__ = mu9_const_distance(_Tp, __first1, __last1);               \
	__mu0_pragma__(omp parallel)                                                                                      \
	{                                                                                                                 \
		_Tp __mu9_parallel_accumulate06__w__ = __mu0_arithmetic_initialize__(_Tp, 0);                                  \
		__mu0_pragma__(omp for simd)                                                                                   \
		for (                                                                                                          \
			  mu0_distance_t __mu9_parallel_accumulate06__i__ = mu0_const_distance(0)                                   \
			;                __mu9_parallel_accumulate06__i__ < __mu9_parallel_accumulate06__n__                        \
			;                __mu9_parallel_accumulate06__i__++                                                         \
		) {                                                                                                            \
			__mu9_parallel_accumulate06__w__ = __trinary_op(_Tp                                                         \
				, __mu9_parallel_accumulate06__w__                                                                       \
				, __mu9_parallel_accumulate06__x__[__mu9_parallel_accumulate06__i__]                                     \
				, __mu9_parallel_accumulate06__y__[__mu9_parallel_accumulate06__i__]                                     \
			);                                                                                                          \
		}                                                                                                              \
		__mu0_pragma__(omp critical)                                                                                   \
		{                                                                                                              \
			__mu9_parallel_accumulate06__v__ = __binary_op(_Tp                                                          \
				, __mu9_parallel_accumulate06__v__                                                                       \
				, __mu9_parallel_accumulate06__w__                                                                       \
			);                                                                                                          \
		}                                                                                                              \
	}                                                                                                                 \
	__d_result = __mu9_parallel_accumulate06__v__;                                                                    \
mu0_scope_end

#	endif
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_accumulate1(_Tp, __first, __last, __init, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_parallel_accumulate00(_Tp, __first, __last, , __init, __d_result)
#	else
#	define mu9_parallel_accumulate1(_Tp, __first, __last, __init, __d_result) \
	mu9_sequencial_accumulate1(_Tp, __first, __last, __init, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result) \
	mu9_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result) \
	mu9_parallel_accumulate01(_Tp, __first, __last, , __init, __binary_op, __d_result)
#	else
#	define mu9_parallel_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result) \
	mu9_sequencial_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first, _Tp &* __last, _Tp __init, __trinary_op, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate3(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result) \
	mu9_accumulate3(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first, _Tp &* __last, _Tp __init, __trinary_op, __binary_op, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate3(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result) \
	mu9_parallel_accumulate02(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result)
#	else
#	define mu9_parallel_accumulate3(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result) \
	mu9_sequencial_accumulate3(_Tp, __first, __last, __init, __trinary_op, __binary_op, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate4(_Tp, __first1, __last1, __first2, __init, __d_result) \
	mu9_accumulate4(_Tp, __first1, __last1, __first2, __init, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate4(_Tp, __first1, __last1, __first2, __init, __d_result) \
	mu9_parallel_accumulate03(_Tp, __first1, __last1, __first2, __init, __d_result)
#	else
#	define mu9_parallel_accumulate4(_Tp, __first1, __last1, __first2, __init, __d_result) \
	mu9_sequencial_accumulate4(_Tp, __first1, __last1, __first2, __init, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate5(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result) \
	mu9_accumulate5(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate5(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result) \
	mu9_parallel_accumulate04(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result)
#	else
#	define mu9_parallel_accumulate5(_Tp, __first1, __last1, __first2, __binary_op, __init, __d_result) \
	mu9_sequencial_accumulate5(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result)
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op1, , __binary_op2, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate6(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result) \
	mu9_accumulate6(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op1, , __binary_op2, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate6(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result) \
	mu9_parallel_accumulate05(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result) 
#	else
#	define mu9_parallel_accumulate6(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result) \
	mu9_sequencial_accumulate6(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result) 
#	endif

//#!
//#! macro<_Tp, execution=sequencial>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __trinary_op, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_sequencial_accumulate7(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_op, __d_result) \
	mu9_accumulate7(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_op, __d_result)

//#!
//#! macro<_Tp, execution=parallel>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __trinary_op, __binary_op, _Tp<return> & __d_result) : void
//#!
#	if MU0_HAVE_PARALLELIZE
#	define mu9_parallel_accumulate7(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_op, __d_result) \
	mu9_parallel_accumulate06(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_op, __d_result)
#	else
#	define mu9_parallel_accumulate7(_Tp, __first1, __last1, __first2, __trinary_op, __binary_op, __init, __d_result) \
	mu9_sequencial_accumulate7(_Tp, __first1, __last1, __first2, __init, __trinary_op, __binary_op, __d_result)
#	endif

MU0_END_CDECL

#endif /* !MU9_PARALLEL_ACCUMULATE_H */

/* EOF */