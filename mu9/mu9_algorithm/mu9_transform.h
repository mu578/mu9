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

// mu9_transform.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_TRANSFORM_H
#define MU9_TRANSFORM_H 1

MU0_BEGIN_CDECL

#	define mu9_transform1(_Tp, __first, __last, __d_first, __unary_op) \
mu0_scope_begin                                                       \
	while (__first != __last) {                                        \
		*__d_first++ = __unary_op(_Tp, *__first++);                     \
	}                                                                  \
mu0_scope_end

#	define mu9_transform2(_Tp, __first, __last, __d_first, __unary_op, __move_op) \
mu0_scope_begin                                                                  \
	while (__first != __last) {                                                   \
		__move_op(_Tp, *__d_first++, __unary_op(_Tp, *__first++));                 \
	}                                                                             \
mu0_scope_end

#	define mu9_transform3(_Tp, __first1, __last1, __first2, __d_first, __binary_op) \
mu0_scope_begin                                                                    \
	while (__first1 != __last1) {                                                   \
		*__d_first++ = __binary_op(_Tp, *__first1++, *__first2++);                   \
	}                                                                               \
mu0_scope_end

#	define mu9_transform4(_Tp, __first1, __last1, __first2, __d_first, __binary_op, __move_op) \
mu0_scope_begin                                                                               \
	while (__first1 != __last1) {                                                              \
		__move_op(_Tp, *__d_first++, __binary_op(_Tp, *__first1++, *__first2++));               \
	}                                                                                          \
mu0_scope_end

#	define mu9_transform5(_Tp, __first, __last, __arg, __d_first, __binary_op) \
mu0_scope_begin                                                               \
	while (__first != __last) {                                                \
		*__d_first++ = __binary_op(_Tp, *__first++, __arg);                     \
	}                                                                          \
mu0_scope_end

#	define mu9_transform6(_Tp, __first, __last, __arg, __d_first, __binary_op, __move_op) \
mu0_scope_begin                                                                          \
	while (__first != __last) {                                                           \
		__move_op(_Tp, *__d_first++, __binary_op(_Tp, *__first++, __arg));                 \
	}                                                                                     \
mu0_scope_end

#	define mu9_transform7(_Tp, __first1, __last1, __first2, __arg, __d_first, __trinary_op) \
mu0_scope_begin                                                                            \
	while (__first1 != __last1) {                                                           \
		*__d_first++ = __trinary_op(_Tp, *__first1++, *__first2++, __arg);                   \
	}                                                                                       \
mu0_scope_end

#	define mu9_transform8(_Tp, __first1, __last1, __first2, __arg, __d_first, __trinary_op, __move_op) \
mu0_scope_begin                                                                                       \
	while (__first1 != __last1) {                                                                      \
		__move_op(_Tp, *__d_first++, __trinary_op(_Tp, *__first1++, *__first2++, __arg));               \
	}                                                                                                  \
mu0_scope_end

#	define mu9_transform_n1(_Tp, __first, __n, __d_first, __unary_op)                             \
mu0_scope_begin                                                                                  \
	mu0_distance_t __mu9_transform_n1__i__ = mu0_const_distance(0);                               \
	for (; __mu9_transform_n1__i__ < mu0_const_distance(__n); (void) ++__mu9_transform_n1__i__) { \
		*__d_first++ = __unary_op(_Tp, *__first++);                                               \
	}                                                                                             \
mu0_scope_end

#	define mu9_transform_n2(_Tp, __first, __n, __d_first, __unary_op, __move_op)                  \
mu0_scope_begin                                                                                  \
	mu0_distance_t __mu9_transform_n2__i__ = mu0_const_distance(0);                               \
	for (; __mu9_transform_n2__i__ < mu0_const_distance(__n); (void) ++__mu9_transform_n2__i__) { \
		__move_op(_Tp, *__d_first++, __unary_op(_Tp, *__first++));                                 \
	}                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_TRANSFORM_H */

/* EOF */