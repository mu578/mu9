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

// mu9_find.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_FIND_H
#define MU9_FIND_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find(_Tp, __first, __last, __value, __d_result) \
mu9_scope_begin                                               \
	mu9_bool_t ___mu9_find__x__ = mu9_false;                   \
	for (; __first != __last; ++__first) {                     \
		if (*__first == __value) {                              \
			__d_result       = __first;                          \
			___mu9_find__x__ = mu9_true;                         \
			break;                                               \
		}                                                       \
	}                                                          \
	if (!___mu9_find__x__) {                                   \
		__d_result = __last;                                    \
	}                                                          \
mu9_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_pred, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_if(_Tp, __first, __last, __unary_pred, __d_result) \
mu9_scope_begin                                                       \
	mu9_bool_t ___mu9_find_if__x__ = mu9_false;                        \
	for (; __first != __last; ++__first) {                             \
		 if (__unary_pred(*__first)) {                                  \
			__d_result          = __first;                               \
			___mu9_find_if__x__ = mu9_true;                              \
			break;                                                       \
		}                                                               \
	}                                                                  \
	if (!___mu9_find_if__x__) {                                        \
		__d_result = __last;                                            \
	}                                                                  \
mu9_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_pred, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_if_not(_Tp, __first, __last, __unary_pred, __d_result) \
mu9_scope_begin                                                           \
	mu9_bool_t ___mu9_find_if_not__x__ = mu9_false;                        \
	for (; __first != __last; ++__first) {                                 \
		 if (!__unary_pred(*__first)) {                                     \
			__d_result              = __first;                               \
			___mu9_find_if_not__x__ = mu9_true;                              \
			break;                                                           \
		}                                                                   \
	}                                                                      \
	if (!___mu9_find_if_not__x__) {                                        \
		__d_result = __last;                                                \
	}                                                                      \
mu9_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp &* __s_first, _Tp &* __s_last, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_first_of1(_Tp, __first, __last, __s_first, __s_last, __d_result)  \
mu9_scope_begin                                                                      \
	mu9_bool_t ___mu9_find_first_of1__x__ = mu9_false;                                \
	_Tp * ___mu9_find_first_of1__i__;                                                 \
	for (; __first != __last && !___mu9_find_first_of1__x__; ++__first) {             \
		___mu9_find_first_of1__i__ = s_first;                                          \
		for (; ___mu9_find_first_of1__i__ != __s_last; ++___mu9_find_first_of1__i__) { \
			if (*__first == *___mu9_find_first_of1__i__) {                              \
				__d_result                 = __first;                                    \
				___mu9_find_first_of1__x__ = mu9_true;                                   \
				break;                                                                   \
			}                                                                           \
		}                                                                              \
	}                                                                                 \
	if (!___mu9_find_first_of1__x__) {                                                \
		__d_result = __last;                                                           \
	}                                                                                 \
mu9_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp &* __s_first, _Tp &* __s_last, __binary_pred, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_first_of2(_Tp, __first, __last, __s_first, __s_last, __binary_pred, __d_result) \
mu9_scope_begin                                                                                    \
	mu9_bool_t ___mu9_find_first_of2__x__ = mu9_false;                                              \
	_Tp * ___mu9_find_first_of2__i__;                                                               \
	for (; __first != __last && !___mu9_find_first_of2__x__; ++__first) {                           \
		___mu9_find_first_of2__i__ = s_first;                                                        \
		for (; ___mu9_find_first_of2__i__ != __s_last; ++___mu9_find_first_of2__i__) {               \
			if (p(*__first, *___mu9_find_first_of2__i__)) {                                           \
				__d_result                 = __first;                                                  \
				___mu9_find_first_of2__x__ = mu9_true;                                                 \
				break;                                                                                 \
			}                                                                                         \
		}                                                                                            \
	}                                                                                               \
	if (!___mu9_find_first_of2__x__) {                                                              \
		__d_result = __last;                                                                         \
	}                                                                                               \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_FIND_H */

/* EOF */