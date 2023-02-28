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

// mu9_exclusive_scan.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_EXCLUSIVE_SCAN_H
#define MU9_EXCLUSIVE_SCAN_H 1

MU0_BEGIN_CDECL

#	define mu9_exclusive_scan1(_Tp, __first, __last, __d_first, __init, __binary_op) \
mu0_scope_begin                                                                     \
	_Tp __mu9_exclusive_scan1__v__;                                                  \
	_Tp __mu9_exclusive_scan1__w__;                                                  \
	if (__first != __last) {                                                         \
		__mu9_exclusive_scan1__v__ = __init;                                          \
		__mu9_exclusive_scan1__w__ = __mu9_exclusive_scan1__v__ + *__first;           \
		while (1) {                                                                   \
			*__d_first = __mu9_exclusive_scan1__v__;                                   \
			++__d_first;                                                               \
			++__first;                                                                 \
			if (__first != __last) {                                                   \
				__mu9_exclusive_scan1__v__ = __mu9_exclusive_scan1__w__;                \
				__mu9_exclusive_scan1__w__ = __mu9_exclusive_scan1__v__ + *__first;     \
			} else {                                                                   \
				break;                                                                  \
			}                                                                          \
		}                                                                             \
	}                                                                                \
mu0_scope_end

#	define mu9_exclusive_scan2(_Tp, __first, __last, __d_first, __init, __binary_op)              \
mu0_scope_begin                                                                                  \
	_Tp __mu9_exclusive_scan2__v__;                                                               \
	_Tp __mu9_exclusive_scan2__w__;                                                               \
	if (__first != __last) {                                                                      \
		__mu9_exclusive_scan2__v__ = __init;                                                       \
		__mu9_exclusive_scan2__w__ = __binary_op(_Tp, __mu9_exclusive_scan2__v__, *__first);       \
		while (1) {                                                                                \
			*__d_first = __mu9_exclusive_scan2__v__;                                                \
			++__d_first;                                                                            \
			++__first;                                                                              \
			if (__first != __last) {                                                                \
				__mu9_exclusive_scan2__v__ = __mu9_exclusive_scan2__w__;                             \
				__mu9_exclusive_scan2__w__ = __binary_op(_Tp, __mu9_exclusive_scan2__v__, *__first); \
			} else {                                                                                \
				break;                                                                               \
			}                                                                                       \
		}                                                                                          \
	}                                                                                             \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_EXCLUSIVE_SCAN_H */

/* EOF */