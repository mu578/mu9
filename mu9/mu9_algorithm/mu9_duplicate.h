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

// mu9_duplicate.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_DUPLICATE_ELEMENT_H
#define MU9_DUPLICATE_ELEMENT_H 1

MU0_BEGIN_CDECL

#	define mu9_duplicate(_Tp, __first, __last, __d_first, __copy_op)  \
mu0_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		*__d_first = __copy_op(*__first);                              \
	}                                                                 \
mu0_scope_end

#	define mu9_duplicate_if(_Tp, __first, __last, __d_first, __unary_pred, __copy_op) \
mu0_scope_begin                                                                      \
	for (; __first != __last; ++__first) {                                            \
		if (__unary_pred(*__first)) {                                                  \
			*__d_first = __copy_op(*__first);                                           \
			++__d_first;                                                                \
		}                                                                              \
	}                                                                                 \
mu0_scope_end

#	define mu9_duplicate_to(_Tp, __first, __last, __d_first, __copy_op, __dresult) \
mu0_scope_begin                                                                   \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) {              \
		*__d_first = __copy_op(*__first);                                           \
	}                                                                              \
	__dresult = __d_first;                                                         \
mu0_scope_end

#	define mu9_duplicate_to_if(_Tp, __first, __last, __d_first, __unary_pred, __copy_op, __dresult) \
mu0_scope_begin                                                                                    \
	for (; __first != __last; ++__first) {                                                          \
		if (__unary_pred(*__first)) {                                                                \
			*__d_first = __copy_op(*__first);                                                         \
			++__d_first;                                                                              \
		}                                                                                            \
	}                                                                                               \
	__dresult = __d_first;                                                                          \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_DUPLICATE_ELEMENT_H */

/* EOF */