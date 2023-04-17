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

#include <mu9/mu9_algorithm/mu9_search.h>

#ifndef MU9_FIND_H
#define MU9_FIND_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, const _Tp & __value, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find(_Tp, __first, __last, __value, __d_result) \
mu0_scope_begin                                               \
	mu0_bool_t __mu9_find__x__ = mu0_false;                    \
	for (; __first != __last; ++__first) {                     \
		if (*__first == __value) {                              \
			__d_result      = __first;                           \
			__mu9_find__x__ = mu0_true;                          \
			break;                                               \
		}                                                       \
	}                                                          \
	if (!__mu9_find__x__) {                                    \
		__d_result = __last;                                    \
	}                                                          \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_pred, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_if(_Tp, __first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                       \
	mu0_bool_t __mu9_find_if__x__ = mu0_false;                         \
	for (; __first != __last; ++__first) {                             \
		 if (__unary_pred(_Tp, *__first)) {                             \
			__d_result         = __first;                                \
			__mu9_find_if__x__ = mu0_true;                               \
			break;                                                       \
		}                                                               \
	}                                                                  \
	if (!__mu9_find_if__x__) {                                         \
		__d_result = __last;                                            \
	}                                                                  \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, __unary_pred, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_if_not(_Tp, __first, __last, __unary_pred, __d_result) \
mu0_scope_begin                                                           \
	mu0_bool_t __mu9_find_if_not__x__ = mu0_false;                         \
	for (; __first != __last; ++__first) {                                 \
		 if (!__unary_pred(_Tp, *__first)) {                                \
			__d_result             = __first;                                \
			__mu9_find_if_not__x__ = mu0_true;                               \
			break;                                                           \
		}                                                                   \
	}                                                                      \
	if (!__mu9_find_if_not__x__) {                                         \
		__d_result = __last;                                                \
	}                                                                      \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp &* __s_first, _Tp &* __s_last, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_first_of1(_Tp, __first, __last, __s_first, __s_last, __d_result) \
mu0_scope_begin                                                                     \
	mu0_bool_t __mu9_find_first_of1__x__ = mu0_false;                                \
	_Tp *      __mu9_find_first_of1__i__;                                            \
	for (; __first != __last && !__mu9_find_first_of1__x__; ++__first) {             \
		__mu9_find_first_of1__i__ = __s_first;                                        \
		for (; __mu9_find_first_of1__i__ != __s_last; ++__mu9_find_first_of1__i__) {  \
			if (*__first == *__mu9_find_first_of1__i__) {                              \
				__d_result                = __first;                                    \
				__mu9_find_first_of1__x__ = mu0_true;                                   \
				break;                                                                  \
			}                                                                          \
		}                                                                             \
	}                                                                                \
	if (!__mu9_find_first_of1__x__) {                                                \
		__d_result = __last;                                                          \
	}                                                                                \
mu0_scope_end

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, _Tp &* __s_first, _Tp &* __s_last, __binary_pred, _Tp<return> &* __d_result) : void
//#!
#	define mu9_find_first_of2(_Tp, __first, __last, __s_first, __s_last, __binary_pred, __d_result) \
mu0_scope_begin                                                                                    \
	mu0_bool_t __mu9_find_first_of2__x__ = mu0_false;                                               \
	_Tp *      __mu9_find_first_of2__i__;                                                           \
	for (; __first != __last && !__mu9_find_first_of2__x__; ++__first) {                            \
		__mu9_find_first_of2__i__ = __s_first;                                                       \
		for (; __mu9_find_first_of2__i__ != __s_last; ++__mu9_find_first_of2__i__) {                 \
			if (__binary_pred(_Tp,  *__first, *__mu9_find_first_of2__i__)) {                          \
				__d_result                = __first;                                                   \
				__mu9_find_first_of2__x__ = mu0_true;                                                  \
				break;                                                                                 \
			}                                                                                         \
		}                                                                                            \
	}                                                                                               \
	if (!__mu9_find_first_of2__x__) {                                                               \
		__d_result = __last;                                                                         \
	}                                                                                               \
mu0_scope_end

#	define mu9_find_end1(__first, __last, __s_first, __s_last, __d_result)             \
mu0_scope_begin                                                                       \
	_Tp * __mu9_find_end1_i__ = __last;                                                \
	_Tp * __mu9_find_end1_j__;                                                         \
	if (!(__s_first == __s_last)) {                                                    \
		while (1) {                                                                     \
			mu9_search1(_Tp, __first, __last, __s_first, __s_last, __mu9_find_end1_j__); \
			if (__mu9_find_end1_j__ == __last) {                                         \
				break;                                                                    \
			} else {                                                                     \
				__mu9_find_end1_i__ = __mu9_find_end1_j__;                                \
				__first             = __mu9_find_end1_i__;                                \
				++__first;                                                                \
			}                                                                            \
		}                                                                               \
	}                                                                                  \
	__d_result = __mu9_find_end1_i__;                                                  \
mu0_scope_end

#	define mu9_find_end2(__first, __last, __s_first, __s_last, __binary_pred, __d_result)             \
mu0_scope_begin                                                                                      \
	_Tp * __mu9_find_end2_i__ = __last;                                                               \
	_Tp * __mu9_find_end2_j__;                                                                        \
	if (!(__s_first == __s_last)) {                                                                   \
		while (1) {                                                                                    \
			mu9_search2(_Tp, __first, __last, __s_first, __s_last, __binary_pred, __mu9_find_end2_j__); \
			if (__mu9_find_end2_j__ == __last) {                                                        \
				break;                                                                                   \
			} else {                                                                                    \
				__mu9_find_end2_i__ = __mu9_find_end2_j__;                                               \
				__first             = __mu9_find_end2_i__;                                               \
				++__first;                                                                               \
			}                                                                                           \
		}                                                                                              \
	}                                                                                                 \
	__d_result = __mu9_find_end2_i__;                                                                 \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_FIND_H */

/* EOF */