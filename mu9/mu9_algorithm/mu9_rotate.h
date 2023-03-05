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

// mu9_rotate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_copy.h>
#include <mu9/mu9_algorithm/mu9_swap.h>

#ifndef MU9_ROTATE_H
#define MU9_ROTATE_H 1

MU0_BEGIN_CDECL

#	define mu9_rotate1(_Tp, __first, __n_first, __last, __d_result) \
mu0_scope_begin                                                    \
	_Tp * __mu9_rotate1__i__;                                       \
	if (__first == __n_first) {                                     \
		__d_result = (__last);                                       \
	} else if (__n_first == (__last)) {                             \
		__d_result = __first;                                        \
	} else {                                                        \
			__mu9_rotate1__i__ = __n_first;                           \
			while (1) {                                               \
				mu9_swap(_Tp, *__first, *__mu9_rotate1__i__);          \
				++__first;                                             \
				if (++__mu9_rotate1__i__ == __last) {                  \
					break;                                              \
				}                                                      \
				if (__first == __n_first) {                            \
					__n_first = __mu9_rotate1__i__;                     \
				}                                                      \
			}                                                         \
			__d_result = __first;                                     \
			if (__first != __n_first) {                               \
				__mu9_rotate1__i__ = __n_first;                        \
				while (1) {                                            \
					mu9_swap(_Tp, *__first, *__mu9_rotate1__i__);       \
					++__first;                                          \
					if (++__mu9_rotate1__i__ == __last) {               \
							if (__first == __n_first) {                   \
								break;                                     \
							}                                             \
							__mu9_rotate1__i__ = __n_first;               \
					} else if (__first == __n_first) {                  \
							__n_first = __mu9_rotate1__i__;               \
					}                                                   \
				}                                                      \
			}                                                         \
	}                                                               \
mu0_scope_end

#	define mu9_rotate2(_Tp, __first, __n_first, __last, __swap_op, __d_result) \
mu0_scope_begin                                                               \
	_Tp * __mu9_rotate2__i__;                                                  \
	if (__first == __n_first) {                                                \
		__d_result = (__last);                                                  \
	} else if (__n_first == (__last)) {                                        \
		__d_result = __first;                                                   \
	} else {                                                                   \
			__mu9_rotate2__i__ = __n_first;                                      \
			while (1) {                                                          \
				__swap_op(_Tp, *__first, *__mu9_rotate2__i__);                    \
				++__first;                                                        \
				if (++__mu9_rotate2__i__ == __last) {                             \
					break;                                                         \
				}                                                                 \
				if (__first == __n_first) {                                       \
					__n_first = __mu9_rotate2__i__;                                \
				}                                                                 \
			}                                                                    \
			__d_result = __first;                                                \
			if (__first != __n_first) {                                          \
				__mu9_rotate2__i__ = __n_first;                                   \
				while (1) {                                                       \
					__swap_op(_Tp, *__first, *__mu9_rotate2__i__);                 \
					++__first;                                                     \
					if (++__mu9_rotate2__i__ == __last) {                          \
							if (__first == __n_first) {                              \
								break;                                                \
							}                                                        \
							__mu9_rotate2__i__ = __n_first;                          \
					} else if (__first == __n_first) {                             \
							__n_first = __mu9_rotate2__i__;                          \
					}                                                              \
				}                                                                 \
			}                                                                    \
	}                                                                          \
mu0_scope_end

#	define mu9_rotate_copy(_Tp, __first, __n_first, __last, __d_first , __d_result) \
mu0_scope_begin                                                                    \
	_Tp * __mu9_rotate_copy__i__;                                                   \
	mu9_copy(_Tp, __n_first, __last, __d_first);                                    \
	__mu9_rotate_copy__i__ = __d_first;                                             \
	mu9_copy(_Tp, __first, __n_first, __mu9_rotate_copy__i__);                      \
	__d_result             = __mu9_rotate_copy__i__;                                \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_ROTATE_H */

/* EOF */