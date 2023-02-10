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

// mu9_argument_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_algorithm/mu9_iota.h>
#include <mu9/mu9_algorithm/mu9_shell_sort.h>

#ifndef MU9_ARGUMENT_SORT_H
#define MU9_ARGUMENT_SORT_H 1

MU0_BEGIN_CDECL

#	define __mu9_argument_sort_compare__(__a,  __b, __ctx) \
	mu9_less_than(                                         \
		  __ctx[mu0_uinteger(__a)]                          \
		, __ctx[mu0_uinteger(__b)]                          \
	)

#	define mu9_argument_sort(_UInt, __first, __last, __s_first) \
mu0_scope_begin                                                \
	_UInt * __mu9_argument_sort__i__ = __first;                 \
	_UInt * __mu9_argument_sort__j__ = __last;                  \
	_UInt * __mu9_argument_sort__k__ = __s_first;               \
	mu9_iota(_UInt                                              \
		, __mu9_argument_sort__i__                               \
		, __mu9_argument_sort__j__                               \
		, 0                                                      \
	);                                                          \
	mu9_shell_sort3(_UInt                                       \
		, __first                                                \
		, __last                                                 \
		, __mu9_argument_sort_compare__                          \
		, __mu9_argument_sort__k__                               \
	);
mu0_scope_end

#	define mu9_argument_sort_n(_UInt, __first, __s_first, __n)                \
mu0_scope_begin                                                              \
	_UInt * __mu9_argument_sort_n__l__ = __first + m0_const_distance(__n);    \
	mu9_argument_sort(_UInt, __first, __mu9_argument_sort_n__l__, __s_first); \
mu0_scope_end

#endif /* !MU9_ARGUMENT_SORT_H */

/* EOF */