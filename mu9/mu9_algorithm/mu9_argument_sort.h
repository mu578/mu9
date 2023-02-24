//
// # -*- coding: utf-8, tab-width: 3 -*-

//                                                          ___                                             //
//                                                         / _\                                            //
//                                            _   _  _   _( (_) |                                           //
//                                           | | | || | | |\__, |                                           //
//                                           | |_| || |_| |  / /                                            //
//                                           | ._,_|\___/  /_/                                             //
//                                           | |                                                            //
//                                           |_|                                                            //

// mu9_argument_sort.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_functional.h>
#include <mu9/mu9_algorithm/mu9_iota.h>
#include <mu9/mu9_algorithm/mu9_shell_sort.h>

#ifndef MU9_ARGUMENT_SORT_H
#define MU9_ARGUMENT_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_argument_sort_ascending(_UInt, __i1,  __i2, __ctx) \
	mu9_lt(_UInt                                                  \
		, __ctx[__i1]                                              \
		, __ctx[__i2]                                              \
	)

#	define mu9_argument_sort_descending(_Tp, __i1,  __i2, __ctx) \
	mu9_gt(_UInt                                                 \
		, __ctx[__i1]                                             \
		, __ctx[__i2]                                             \
	)

#	define mu9_argument_sort1(_UInt, __first, __last, __start, __s_first) \
mu0_scope_begin                                                          \
	_UInt * __mu9_argument_sort1__i__ = __first;                          \
	mu9_iota(_UInt                                                        \
		, __mu9_argument_sort1__i__                                        \
		, __last                                                           \
		, __start                                                          \
	);                                                                    \
	mu9_shell_sort3(_UInt                                                 \
		, __first                                                          \
		, __last                                                           \
		, mu9_argument_sort_ascending                                      \
		, __s_first                                                        \
	);                                                                    \
mu0_scope_end

#	define mu9_argument_sort2(_UInt, __first, __last, __start, __s_first, __sort_op) \
mu0_scope_begin                                                                     \
	_UInt * __mu9_argument_sort2__i__ = __first;                                     \
	mu9_iota(_UInt                                                                   \
		, __mu9_argument_sort2__i__                                                   \
		, __last                                                                      \
		, __start                                                                     \
	);                                                                               \
	mu9_shell_sort3(_UInt                                                            \
		, __first                                                                     \
		, __last                                                                      \
		, __sort_op                                                                   \
		, __s_first                                                                   \
	);                                                                               \
mu0_scope_end

#	define mu9_argument_sort_n1(_UInt, __first, __start, __s_first, __n)                 \
mu0_scope_begin                                                                         \
	_UInt * __mu9_argument_sort_n1__i__ = __first + mu0_const_distance(__n);             \
	mu9_argument_sort1(_UInt, __first, __mu9_argument_sort_n1__i__, __start, __s_first); \
mu0_scope_end

#	define mu9_argument_sort_n2(_UInt, __first, __start, __s_first, __n, __sort_op)                 \
mu0_scope_begin                                                                                    \
	_UInt * __mu9_argument_sort_n2__i__ = __first + mu0_const_distance(__n);                        \
	mu9_argument_sort2(_UInt, __first, __mu9_argument_sort_n2__i__, __start, __s_first, __sort_op); \
mu0_scope_end

#endif /* !MU9_ARGUMENT_SORT_H */

/* EOF */