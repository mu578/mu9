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

// mu9_exist.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_EXIST_H
#define MU9_EXIST_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Bool<return> & __d_result) : void
//#!
#	define mu9_exist1(_Tp, __first, __last, __value, __d_result) \
mu0_scope_begin                                                 \
	mu0_bool_t __mu9_exist1__x__ = mu0_false;                    \
	for (; __first != __last; ++__first) {                       \
		if (*__first == __value) {                                \
			__mu9_exist1__x__ = mu0_true;                          \
			break;                                                 \
		}                                                         \
	}                                                            \
	__d_result = __mu9_exist1__x__;                              \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value, __binary_pred, _Bool<return> & __d_result) : void
//#!
#	define mu9_exist2(_Tp, __first, __last, __value, __binary_pred, __d_result) \
mu0_scope_begin                                                                \
	mu0_bool_t __mu9_exist2__x__ = mu0_false;                                   \
	for (; __first != __last; ++__first) {                                      \
		 if (__binary_pred(_Tp, *__first, __value)) {                            \
			__mu9_exist2__x__ = mu0_true;                                         \
			break;                                                                \
		}                                                                        \
	}                                                                           \
	__d_result = __mu9_exist2__x__;                                             \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Bool<return> & __d_result1, _Tp<return> &* __d_result2) : void
//#!
#	define mu9_exist3(_Tp, __first, __last, __value, __d_result1, __d_result2) \
mu0_scope_begin                                                               \
	mu0_bool_t __mu9_exist3__x__ = mu0_false;                                  \
	for (; __first != __last; ++__first) {                                     \
		if (*__first == __value) {                                              \
			__mu9_exist3__x__ = mu0_true;                                        \
			break;                                                               \
		}                                                                       \
	}                                                                          \
	__d_result1 =  __mu9_exist3__x__;                                          \
	__d_result2 = !__mu9_exist3__x__ ? __last : __first;                       \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Bool<return> & __d_result1, _Tp<return> &* __d_result2) : void
//#!
#	define mu9_exist4(_Tp, __first, __last, __value, __binary_pred, __d_result1, __d_result2) \
mu0_scope_begin                                                                              \
	mu0_bool_t __mu9_exist4__x__ = mu0_false;                                                 \
	for (; __first != __last; ++__first) {                                                    \
		if (__binary_pred(_Tp, *__first, __value)) {                                           \
			__mu9_exist4__x__ = mu0_true;                                                       \
			break;                                                                              \
		}                                                                                      \
	}                                                                                         \
	__d_result1 =  __mu9_exist4__x__;                                                         \
	__d_result2 = !__mu9_exist4__x__ ? __last : __first;                                      \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_EXIST_H */

/* EOF */