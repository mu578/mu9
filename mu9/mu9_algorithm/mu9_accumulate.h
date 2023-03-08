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

// mu9_accumulate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_ACCUMULATE_H
#define MU9_ACCUMULATE_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_accumulate1(_Tp, __first, __last, __init, __d_result) \
mu0_scope_begin                                                     \
	_Tp __mu9_accumulate1__v__ = mu0_const_cast(_Tp, __init);        \
	while (__first != __last) {                                      \
		__mu9_accumulate1__v__ = __mu9_accumulate1__v__ + *__first;   \
		++__first;                                                    \
	}                                                                \
	__d_result = __mu9_accumulate1__v__;                             \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_accumulate2(_Tp, __first, __last, __init, __binary_op, __d_result)  \
mu0_scope_begin                                                                   \
	_Tp __mu9_accumulate2__v__ = mu0_const_cast(_Tp, __init);                      \
	while (__first != __last) {                                                    \
		__mu9_accumulate2__v__ = __binary_op(_Tp, __mu9_accumulate__v__, *__first); \
		++__first;                                                                  \
	}                                                                              \
	__d_result = __mu9_accumulate2__v__;                                           \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, _Tp __init, _Tp<return> & __d_result) : void
//#!
#	define mu9_accumulate3(_Tp, __first1, __last1, __first2, __init, __d_result)      \
mu0_scope_begin                                                                      \
	_Tp __mu9_accumulate3__v__ = mu0_const_cast(_Tp, __init);                         \
	while (__first1 != __last1) {                                                     \
		__mu9_accumulate3__v__ = __mu9_accumulate3__v__ + ((*__first1) + (*__first2)); \
		++__first1;                                                                    \
		++__first2;                                                                    \
	}                                                                                 \
	__d_result = __mu9_accumulate3__v__;                                              \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, _Tp __init, __binary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_accumulate4(_Tp, __first1, __last1, __first2, __init, __binary_op, __d_result)                     \
mu0_scope_begin                                                                                                  \
	_Tp __mu9_accumulate4__v__ = mu0_const_cast(_Tp, __init);                                                     \
	while (__first1 != __last1) {                                                                                 \
		__mu9_accumulate4__v__ = __binary_op(_Tp, __mu9_accumulate4__v__, __binary_op(_Tp, *__first1, *__first2)); \
		++__first1;                                                                                                \
		++__first2;                                                                                                \
	}                                                                                                             \
	__d_result = __mu9_accumulate4__v__;                                                                          \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, _Tp __init, __binary_op1, __binary_op2, _Tp<return> & __d_result) : void
//#!
#	define mu9_accumulate5(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result)        \
mu0_scope_begin                                                                                                    \
	_Tp __mu9_accumulate5__v__ = mu0_const_cast(_Tp, __init);                                                       \
	while (__first1 != __last1) {                                                                                   \
		__mu9_accumulate5__v__ = __binary_op1(_Tp, __mu9_accumulate5__v__, __binary_op1(_Tp, *__first1, *__first2)); \
		++__first1;                                                                                                  \
		++__first2;                                                                                                  \
	}                                                                                                               \
	__d_result = __mu9_accumulate5__v__;                                                                            \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1,  _Tp &* __first2, _Tp __init, __trinary_op, _Tp<return> & __d_result) : void
//#!
#	define mu9_accumulate6(_Tp, __first1, __last1, __first2, __init, __trinary_op, __d_result)   \
mu0_scope_begin                                                                                 \
	_Tp __mu9_accumulate6__v__ = mu0_const_cast(_Tp, __init);                                    \
	while (__first1 != __last1) {                                                                \
		__mu9_accumulate6__v__ = __trinary_op(_Tp, __mu9_accumulate6__v__, *__first1, *__first2); \
		++__first1;                                                                               \
		++__first2;                                                                               \
	}                                                                                            \
	__d_result = __mu9_accumulate6__v__;                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ACCUMULATE_H */

/* EOF */