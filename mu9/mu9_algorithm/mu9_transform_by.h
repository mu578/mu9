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

// mu9_transform_by.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_integer.h>

#ifndef MU9_TRANSFORM_BY_H
#define MU9_TRANSFORM_BY_H 1

MU0_BEGIN_CDECL

#	define mu9_transform_by1(_Tp, __first, __last, __by, __d_first, __unary_op)                          \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_transform_by1__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_transform_by1__j__;                                                             \
	mu0_distance_t __mu9_transform_by1__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	while (__first != __last) {                                                                          \
		*__d_first++             = __unary_op(_Tp, *__first);                                             \
		__mu9_transform_by1__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_transform_by1__j__ != __mu9_transform_by1__i__; (void) ++__mu9_transform_by1__j__) { \
			if (__first == __last) {                                                                       \
				__mu9_transform_by1__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first;                                                                                     \
		}                                                                                                 \
		if (__mu9_transform_by1__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by2(_Tp, __first, __last, __by, __d_first, __unary_op, __move_op)               \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_transform_by2__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_transform_by2__j__;                                                             \
	mu0_distance_t __mu9_transform_by2__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	while (__first != __last) {                                                                          \
		__move_op(_Tp, *__d_first++, __unary_op(_Tp, *__first));                                          \
		__mu9_transform_by2__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_transform_by2__j__ != __mu9_transform_by2__i__; (void) ++__mu9_transform_by2__j__) { \
			if (__first == __last) {                                                                       \
				__mu9_transform_by2__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first;                                                                                     \
		}                                                                                                 \
		if (__mu9_transform_by2__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by3(_Tp, __first1, __last1, __first2, __by, __d_first, __binary_op)      \
mu0_scope_begin                                                                                  \
	mu0_bool_t     __mu9_transform_by3__x__ = mu0_false;                                          \
	mu0_distance_t __mu9_transform_by3__j__;                                                      \
	mu0_distance_t __mu9_transform_by3__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)   \
		? mu0_const_distance(1)                                                                    \
		: mu0_const_distance(__by)                                                                 \
	);                                                                                            \
	while (__first1 != __last1) {                                                                 \
		*__d_first++             = __binary_op(_Tp, *__first1, *__first2);                         \
		__mu9_transform_by3__j__ = mu0_const_distance(0);                                          \
		for (; __mu9_transform_by3__j__ != __mu9_transform_by3__i__; (void) ++__mu9_transform_by3__j__) { \
			if (__first1 == __last1) {                                                                     \
				__mu9_transform_by3__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first1;                                                                                    \
			++__first2;                                                                                    \
		}                                                                                                 \
		if (__mu9_transform_by3__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by4(_Tp, __first1, __last1, __first2, __by, __d_first, __binary_op, __move_op)  \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_transform_by4__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_transform_by4__j__;                                                             \
	mu0_distance_t __mu9_transform_by4__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	while (__first1 != __last1) {                                                                        \
		__move_op(_Tp, *__d_first++, __binary_op(_Tp, *__first1, *__first2));                             \
		__mu9_transform_by4__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_transform_by4__j__ != __mu9_transform_by4__i__; (void) ++__mu9_transform_by4__j__) { \
			if (__first1 == __last1) {                                                                     \
				__mu9_transform_by4__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first1;                                                                                    \
			++__first2;                                                                                    \
		}                                                                                                 \
		if (__mu9_transform_by4__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by5(_Tp, __first, __last, __arg, __by, __d_first, __binary_op)                  \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_transform_by5__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_transform_by5__j__;                                                             \
	mu0_distance_t __mu9_transform_by5__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	while (__first != __last1) {                                                                         \
		*__d_first++             = __binary_op(_Tp, *__first, __arg);                                     \
		__mu9_transform_by5__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_transform_by5__j__ != __mu9_transform_by5__i__; (void) ++__mu9_transform_by5__j__) { \
			if (__first == __last1) {                                                                      \
				__mu9_transform_by5__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first;                                                                                     \
		}                                                                                                 \
		if (__mu9_transform_by5__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by6(_Tp, __first, __last, __arg, __by, __d_first, __binary_op, __move_op)       \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_transform_by6__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_transform_by6__j__;                                                             \
	mu0_distance_t __mu9_transform_by6__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	while (__first != __last) {                                                                          \
		__move_op(_Tp, *__d_first++, __binary_op(_Tp, *__first, __arg));                                  \
		__mu9_transform_by6__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_transform_by6__j__ != __mu9_transform_by6__i__; (void) ++__mu9_transform_by6__j__) { \
			if (__first == __last) {                                                                       \
				__mu9_transform_by6__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first;                                                                                     \
		}                                                                                                 \
		if (__mu9_transform_by6__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by7(_Tp, __first1, __last1, __first2, __arg, _by, __d_first, __trinary_op)      \
mu0_scope_begin                                                                                         \
	mu0_bool_t     __mu9_transform_by7__x__ = mu0_false;                                                 \
	mu0_distance_t __mu9_transform_by7__j__;                                                             \
	mu0_distance_t __mu9_transform_by7__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)          \
		? mu0_const_distance(1)                                                                           \
		: mu0_const_distance(__by)                                                                        \
	);                                                                                                   \
	while (__first1 != __last1) {                                                                        \
		*__d_first++             = __trinary_op(_Tp, *__first1, *__first2, __arg);                        \
		__mu9_transform_by7__j__ = mu0_const_distance(0);                                                 \
		for (; __mu9_transform_by7__j__ != __mu9_transform_by7__i__; (void) ++__mu9_transform_by7__j__) { \
			if (__first1 == __last1) {                                                                     \
				__mu9_transform_by7__x__ = mu0_true;                                                        \
				break;                                                                                      \
			}                                                                                              \
			++__first1;                                                                                    \
			++__first2;                                                                                    \
		}                                                                                                 \
		if (__mu9_transform_by7__x__) {                                                                   \
			break;                                                                                         \
		}                                                                                                 \
	}                                                                                                    \
mu0_scope_end

#	define mu9_transform_by8(_Tp, __first1, __last1, __first2, __arg, _by, __d_first, __trinary_op, __move_op) \
mu0_scope_begin                                                                                               \
	mu0_bool_t     __mu9_transform_by8__x__ = mu0_false;                                                       \
	mu0_distance_t __mu9_transform_by8__j__;                                                                   \
	mu0_distance_t __mu9_transform_by8__i__ = (mu0_const_distance(__by) < mu0_const_distance(1)                \
		? mu0_const_distance(1)                                                                                 \
		: mu0_const_distance(__by)                                                                              \
	);                                                                                                         \
	while (__first1 != __last1) {                                                                              \
		__move_op(_Tp, *__d_first++, __trinary_op(_Tp, *__first1, *__first2, __arg));                           \
		__mu9_transform_by8__j__ = mu0_const_distance(0);                                                       \
		for (; __mu9_transform_by8__j__ != __mu9_transform_by8__i__; (void) ++__mu9_transform_by8__j__) {       \
			if (__first1 == __last1) {                                                                           \
				__mu9_transform_by8__x__ = mu0_true;                                                              \
				break;                                                                                            \
			}                                                                                                    \
			++__first1;                                                                                          \
			++__first2;                                                                                          \
		}                                                                                                       \
		if (__mu9_transform_by8__x__) {                                                                         \
			break;                                                                                               \
		}                                                                                                       \
	}                                                                                                          \
mu0_scope_end

#	define mu9_transform_by_n1(_Tp, __first, __n, __d_first, __unary_op)                                       \
mu0_scope_begin                                                                                               \
	mu0_bool_t     __mu9_transform_by_n1__x__ = mu0_false;                                                     \
	mu0_distance_t __mu9_transform_by_n1__i__  = mu0_const_distance(0);                                        \
	mu0_distance_t __mu9_transform_by_n1__j__;                                                                 \
	mu0_distance_t __mu9_transform_by_n1__k__ = (mu0_const_distance(__by) < mu0_const_distance(1)              \
		? mu0_const_distance(1)                                                                                 \
		: mu0_const_distance(__by)                                                                              \
	);                                                                                                         \
	for (; __mu9_transform_by_n1__i__ < mu0_const_distance(__n); (void) ++__mu9_transform_by_n1__i__) {        \
		*__d_first++               = __unary_op(_Tp, *__first);                                                 \
		__mu9_transform_by_n1__j__ = mu0_const_distance(0);                                                     \
		for (; __mu9_transform_by_n1__j__ != __mu9_transform_by_n1__k__; (void) ++__mu9_transform_by_n1__j__) { \
			if (__first == __last) {                                                                             \
				__mu9_transform_by_n1__x__ = mu0_true;                                                            \
				break;                                                                                            \
			}                                                                                                    \
			++__first;                                                                                           \
		}                                                                                                       \
		if (__mu9_transform_by_n1__x__) {                                                                       \
			break;                                                                                               \
		}                                                                                                       \
	}                                                                                                          \
mu0_scope_end

#	define mu9_transform_by_n2(_Tp, __first, __n, __d_first, __unary_op, __move_op)                            \
mu0_scope_begin                                                                                               \
	mu0_bool_t     __mu9_transform_by_n2__x__ = mu0_false;                                                     \
	mu0_distance_t __mu9_transform_by_n2__i__  = mu0_const_distance(0);                                        \
	mu0_distance_t __mu9_transform_by_n2__j__;                                                                 \
	mu0_distance_t __mu9_transform_by_n2__k__ = (mu0_const_distance(__by) < mu0_const_distance(1)              \
		? mu0_const_distance(1)                                                                                 \
		: mu0_const_distance(__by)                                                                              \
	);                                                                                                         \
	for (; __mu9_transform_by_n2__i__ < mu0_const_distance(__n); (void) ++__mu9_transform_by_n2__i__) {        \
		__move_op(_Tp, *__d_first++, __unary_op(_Tp, *__first));                                                \
		__mu9_transform_by_n2__j__ = mu0_const_distance(0);                                                     \
		for (; __mu9_transform_by_n2__j__ != __mu9_transform_by_n2__k__; (void) ++__mu9_transform_by_n2__j__) { \
			if (__first == __last) {                                                                             \
				__mu9_transform_by_n2__x__ = mu0_true;                                                            \
				break;                                                                                            \
			}                                                                                                    \
			++__first;                                                                                           \
		}                                                                                                       \
		if (__mu9_transform_by_n2__x__) {                                                                       \
			break;                                                                                               \
		}                                                                                                       \
	}                                                                                                          \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_TRANSFORM_BY_H */

/* EOF */