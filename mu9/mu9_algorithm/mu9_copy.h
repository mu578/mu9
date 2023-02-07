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

// mu9_copy.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_COPY_H
#define MU9_COPY_H 1

MU9_BEGIN_CDECL

#	define mu9_copy(_Tp, __first, __last, __d_first)                  \
mu9_scope_begin                                                      \
	for (; __first != __last; (void) ++__first, (void) ++__d_first) { \
		*__d_first = *__first;                                         \
	}                                                                 \
mu9_scope_end

#	define mu9_copy_if(_Tp, __first, __last, __d_first, __unary_pred) \
mu9_scope_begin                                                      \
	for (; __first != __last; ++__first) {                            \
		if (__unary_pred(*__first)) {                                  \
			*__d_first = *__first;                                      \
			++__d_first;                                                \
		}                                                              \
	}                                                                 \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_COPY_H */

/* EOF */