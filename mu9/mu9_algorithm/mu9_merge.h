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

// mu9_merge.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_duplicate.h>
#include <mu9/mu9_algorithm/mu9_copy.h>

#ifndef MU9_MERGE_H
#define MU9_MERGE_H 1

MU0_BEGIN_CDECL

#	define mu9_merge1(_Tp, __first1, __last1, __first2, __last2, __d_first, __d_result) \
mu0_scope_begin                                                                        \
	mu9_bool_t __mu9_merge1__x__ = mu0_false;                                           \
	for (; __first1 != __last1; ++__d_first) {                                          \
		if (__first2 == __last2) {                                                       \
			mu9_copy(_Tp, __first1, __last1, __d_first);                                  \
			__d_result        = __d_first;                                                \
			__mu9_merge1__x__ = mu0_true;                                                 \
			break;                                                                        \
		}                                                                                \
		if (*__first2 < *__first1) {                                                     \
			*__d_first = *__first2;                                                       \
			++__first2;                                                                   \
		} else {                                                                         \
			*__d_first = *__first1;                                                       \
			++__first1;                                                                   \
		}                                                                                \
	}                                                                                   \
	if !(__mu9_merge1__x__) {                                                           \
		mu9_copy(_Tp, __first2, __last2, __d_first);                                     \
		__d_result = __d_first;                                                          \
	}                                                                                   \
mu0_scope_end

#	define mu9_merge2(_Tp, __first1, __last1, __first2, __last2, __d_first, __comp_fn, __d_result) \
mu0_scope_begin                                                                                   \
	mu9_bool_t __mu9_merge2__x__ = mu0_false;                                                      \
	for (; __first1 != __last1; ++__d_first) {                                                     \
		if (__first2 == __last2) {                                                                  \
			mu9_copy(_Tp, __first1, __last1, __d_first);                                             \
			__d_result        = __d_first;                                                           \
			__mu9_merge2__x__ = mu0_true;                                                            \
			break;                                                                                   \
		}                                                                                           \
		if (__comp_fn(*__first2, *__first1)) {                                                      \
			*__d_first = *__first2;                                                                  \
			++__first2;                                                                              \
		} else {                                                                                    \
			*__d_first = *__first1;                                                                  \
			++__first1;                                                                              \
		}                                                                                           \
	}                                                                                              \
	if !(__mu9_merge2__x__) {                                                                      \
		mu9_copy(_Tp, __first2, __last2, __d_first);                                                \
		__d_result = __d_first;                                                                     \
	}                                                                                              \
mu0_scope_end

#	define mu9_merge3(_Tp, __first1, __last1, __first2, __last2, __d_first, __comp_fn, __copy_op, __d_result) \
mu0_scope_begin                                                                                              \
	mu9_bool_t __mu9_merge3__x__ = mu0_false;                                                                 \
	for (; __first1 != __last1; ++__d_first) {                                                                \
		if (__first2 == __last2) {                                                                             \
			mu9_duplicate(_Tp, __first1, __last1, __d_first, __copy_op);                                        \
			__d_result        = __d_first;                                                                      \
			__mu9_merge3__x__ = mu0_true;                                                                       \
			break;                                                                                              \
		}                                                                                                      \
		if (__comp_fn(*__first2, *__first1)) {                                                                 \
			*__d_first = __copy_op(*__first2);                                                                  \
			++__first2;                                                                                         \
		} else {                                                                                               \
			*__d_first = __copy_op(*__first1);                                                                  \
			++__first1;                                                                                         \
		}                                                                                                      \
	}                                                                                                         \
	if !(__mu9_merge3__x__) {                                                                                 \
		mu9_duplicate(_Tp, __first2, __last2, __d_first, __copy_op);                                           \
		__d_result = __d_first;                                                                                \
	}                                                                                                         \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_MERGE_H */

/* EOF */