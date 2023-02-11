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

#include <mu9/functional.h>
#include <mu9/mu9_algorithm/mu9_iota.h>
#include <mu9/mu9_algorithm/mu9_shell_sort.h>

#ifndef MU9_ARGUMENT_SORT_H
#define MU9_ARGUMENT_SORT_H 1

MU0_BEGIN_CDECL

#	define mu9_argument_sort(_Tp, _UInt, __first, __last, __start, __s_first) \
mu0_scope_begin                                                              \
	_UInt * __mu9_argument_sort__i__ = __first;                               \
	_UInt * __mu9_argument_sort__j__ = __last;                                \
	_Tp   * __mu9_argument_sort__k__ = __s_first;                             \
	mu9_iota(_UInt                                                            \
		, __mu9_argument_sort__i__                                             \
		, __mu9_argument_sort__j__                                             \
		, __start                                                              \
	);                                                                        \
	mu9_shell_sort3(_UInt                                                     \
		, __first                                                              \
		, __last                                                               \
		, mu9_sort_ascending                                                   \
		, __mu9_argument_sort__k__                                             \
	);
mu0_scope_end

#	define mu9_argument_sort_n(_Tp, _UInt, __first, __start, __s_first, __n)                \
mu0_scope_begin                                                                            \
	_UInt * __mu9_argument_sort_n__l__ = __first + m0_const_distance(__n);                  \
	mu9_argument_sort(_Tp, _UInt, __first, __start, __mu9_argument_sort_n__l__, __s_first); \
mu0_scope_end

#endif /* !MU9_ARGUMENT_SORT_H */

/* EOF */