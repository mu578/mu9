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

// mu9_inner_accumulate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_INNER_ACCUMULATE_H
#define MU9_INNER_ACCUMULATE_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp __init, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	define mu9_inner_accumulate1(_Tp, __first1, __last1, __init, __d_result1, __d_result2)        \
mu0_scope_begin                                                                                  \
	_Tp __mu9_inner_accumulate1__s__ = mu0_const_cast(_Tp, __init);                               \
	_Tp __mu9_inner_accumulate1__q__ = mu0_const_cast(_Tp, __init);                               \
	while (__first1 != __last1) {                                                                 \
		__mu9_inner_accumulate1__s__ = __mu9_inner_accumulate1__s__ +  (*__first1);                \
		__mu9_inner_accumulate1__q__ = __mu9_inner_accumulate1__q__ + ((*__first1) * (*__first1)); \
		++__first1;                                                                                \
	}                                                                                             \
	__d_result1 = __mu9_inner_accumulate1__s__;                                                   \
	__d_result2 = __mu9_inner_accumulate1__q__;                                                   \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp __init, __binary_op1, __binary_op2, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	define mu9_inner_accumulate2(_Tp, __first1, __last1, __init, __binary_op1, __binary_op2, __d_result1, __d_result2)          \
mu0_scope_begin                                                                                                                \
	_Tp __mu9_inner_accumulate2__s__ = mu0_const_cast(_Tp, __init);                                                             \
	_Tp __mu9_inner_accumulate2__q__ = mu0_const_cast(_Tp, __init);                                                             \
	while (__first1 != __last1) {                                                                                               \
		__mu9_inner_accumulate2__s__ = __binary_op1(_Tp, __mu9_inner_accumulate2__s__, *__first1);                               \
		__mu9_inner_accumulate2__q__ = __binary_op1(_Tp, __mu9_inner_accumulate2__q__, __binary_op2(_Tp, *__first1, *__first1)); \
		++__first1;                                                                                                              \
	}                                                                                                                           \
	__d_result1 = __mu9_inner_accumulate2__s__;                                                                                 \
	__d_result2 = __mu9_inner_accumulate2__q__;                                                                                 \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp __init, __binary_op, __trinary_op, _Tp<return> & __d_result1, _Tp<return> & __d_result2) : void
//#!
#	define mu9_inner_accumulate3(_Tp, __first1, __last1, __init, __binary_op, __trinary_op, __d_result1, __d_result2) \
mu0_scope_begin                                                                                                      \
	_Tp __mu9_inner_accumulate3__s__ = mu0_const_cast(_Tp, __init);                                                   \
	_Tp __mu9_inner_accumulate3__q__ = mu0_const_cast(_Tp, __init);                                                   \
	while (__first1 != __last1) {                                                                                     \
		__mu9_inner_accumulate3__s__ = __binary_op(_Tp, __mu9_inner_accumulate3__s__, *__first1);                      \
		__mu9_inner_accumulate3__q__ = __trinary_op(_Tp, *__first1, *__first1, __mu9_inner_accumulate3__q__);          \
		++__first1;                                                                                                    \
	}                                                                                                                 \
	__d_result1 = __mu9_inner_accumulate3__s__;                                                                       \
	__d_result2 = __mu9_inner_accumulate3__q__;                                                                       \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, _Tp<return> & __d_result1, _Tp<return> & __d_result2, _Tp<return> & __d_result3) : void
//#!
#	define mu9_inner_accumulate4(_Tp, __first1, __last1, __first2, __init, __d_result1, __d_result2, __d_result3) \
mu0_scope_begin                                                                                                  \
	_Tp __mu9_inner_accumulate4__s__ = mu0_const_cast(_Tp, __init);                                               \
	_Tp __mu9_inner_accumulate4__w__ = mu0_const_cast(_Tp, __init);                                               \
	_Tp __mu9_inner_accumulate4__q__ = mu0_const_cast(_Tp, __init);                                               \
	while (__first1 != __last1) {                                                                                 \
		__mu9_inner_accumulate4__s__ = __mu9_inner_accumulate4__s__ +  (*__first1);                                \
		__mu9_inner_accumulate4__w__ = __mu9_inner_accumulate4__w__ +  (*__first2);                                \
		__mu9_inner_accumulate4__q__ = __mu9_inner_accumulate4__q__ + ((*__first1) * (*__first2));                 \
		++__first1;                                                                                                \
		++__first2;                                                                                                \
	}                                                                                                             \
	__d_result1 = __mu9_inner_accumulate4__s__;                                                                   \
	__d_result1 = __mu9_inner_accumulate4__w__;                                                                   \
	__d_result3 = __mu9_inner_accumulate4__q__;                                                                   \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op1, __binary_op2, _Tp<return> & __d_result1, _Tp<return> & __d_result2, _Tp<return> & __d_result3) : void
//#!
#	define mu9_inner_accumulate5(_Tp, __first1, __last1, __first2, __init, __binary_op1, __binary_op2, __d_result1, __d_result2, __d_result3) \
mu0_scope_begin                                                                                                                              \
	_Tp __mu9_inner_accumulate5__s__ = mu0_const_cast(_Tp, __init);                                                                           \
	_Tp __mu9_inner_accumulate5__w__ = mu0_const_cast(_Tp, __init);                                                                           \
	_Tp __mu9_inner_accumulate5__q__ = mu0_const_cast(_Tp, __init);                                                                           \
	while (__first1 != __last1) {                                                                                                             \
		__mu9_inner_accumulate5__s__ = __binary_op1(_Tp, __mu9_inner_accumulate5__s__, *__first1);                                             \
		__mu9_inner_accumulate5__w__ = __binary_op1(_Tp, __mu9_inner_accumulate5__w__, *__first2);                                             \
		__mu9_inner_accumulate5__q__ = __binary_op1(_Tp, __mu9_inner_accumulate5__q__, __binary_op2(_Tp, *__first1, *__first2));               \
		++__first1;                                                                                                                            \
		++__first2;                                                                                                                            \
	}                                                                                                                                         \
	__d_result1 = __mu9_inner_accumulate5__s__;                                                                                               \
	__d_result1 = __mu9_inner_accumulate5__w__;                                                                                               \
	__d_result3 = __mu9_inner_accumulate5__q__;                                                                                               \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first1, _Tp &* __last1, _Tp &* __first2, _Tp __init, __binary_op, __trinary_op, _Tp<return> & __d_result1, _Tp<return> & __d_result2, _Tp<return> & __d_result3) : void
//#!
#	define mu9_inner_accumulate6(_Tp, __first1, __last1, __first2, __init, __binary_op, __trinary_op, __d_result1, __d_result2, __d_result3) \
mu0_scope_begin                                                                                                                             \
	_Tp __mu9_inner_accumulate6__s__ = mu0_const_cast(_Tp, __init);                                                                          \
	_Tp __mu9_inner_accumulate6__w__ = mu0_const_cast(_Tp, __init);                                                                          \
	_Tp __mu9_inner_accumulate6__q__ = mu0_const_cast(_Tp, __init);                                                                          \
	while (__first1 != __last1) {                                                                                                            \
		__mu9_inner_accumulate6__s__ = __binary_op(_Tp, __mu9_inner_accumulate6__s__, *__first1);                                             \
		__mu9_inner_accumulate6__w__ = __binary_op(_Tp, __mu9_inner_accumulate6__w__, *__first2);                                             \
		__mu9_inner_accumulate6__q__ = __trinary_op(_Tp, *__first1, *__first2, __mu9_inner_accumulate6__q__);                                 \
		++__first1;                                                                                                                           \
		++__first2;                                                                                                                           \
	}                                                                                                                                        \
	__d_result1 = __mu9_inner_accumulate6__s__;                                                                                              \
	__d_result1 = __mu9_inner_accumulate6__w__;                                                                                              \
	__d_result3 = __mu9_inner_accumulate6__q__;                                                                                              \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_INNER_ACCUMULATE_H */

/* EOF */