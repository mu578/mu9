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

// mu9_inclusive_scan.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_INCLUSIVE_SCAN_H
#define MU9_INCLUSIVE_SCAN_H 1

MU0_BEGIN_CDECL

#	define mu9_inclusive_scan1(_Tp, __first, __last, __d_first)                  \
mu0_scope_begin                                                                 \
	_Tp __mu9_inclusive_scan1__v__;                                              \
	if (__first != __last) {                                                     \
		__mu9_inclusive_scan1__v__ = *__first;                                    \
		*__d_first++               = __mu9_inclusive_scan1__v__;                  \
		if (++__first != __last) {                                                \
			for (; __first != __last; ++__first, (void) ++__d_first) {             \
				__mu9_inclusive_scan1__v__ = __mu9_inclusive_scan1__v__ + *__first; \
				*__d_first                 = __mu9_inclusive_scan1__v__;            \
			}                                                                      \
		}                                                                         \
	}                                                                            \
mu0_scope_end

#	define mu9_inclusive_scan2(_Tp, __first, __last, __d_first, __binary_op)                      \
mu0_scope_begin                                                                                  \
	_Tp __mu9_inclusive_scan2__v__;                                                               \
	if (__first != __last) {                                                                      \
		__mu9_inclusive_scan2__v__ = *__first;                                                     \
		*__d_first++               = __mu9_inclusive_scan2__v__;                                   \
		if (++__first != __last) {                                                                 \
			for (; __first != __last; ++__first, (void) ++__d_first) {                              \
				__mu9_inclusive_scan2__v__ = __binary_op(_Tp, __mu9_inclusive_scan2__v__, *__first); \
				*__d_first                 = __mu9_inclusive_scan2__v__;                             \
			}                                                                                       \
		}                                                                                          \
	}                                                                                             \
mu0_scope_end

#	define mu9_inclusive_scan3(_Tp, __first, __last, __d_first, __binary_op, __move_op)                          \
mu0_scope_begin                                                                                                 \
	_Tp __mu9_inclusive_scan3__v__;                                                                              \
	if (__first != __last) {                                                                                     \
		__move_op(_Tp, __mu9_inclusive_scan3__v__, *__first);                                                     \
		__move_op(_Tp, *__d_first++, __mu9_inclusive_scan3__v__);                                                 \
		if (++__first != __last) {                                                                                \
			for (; __first != __last; ++__first, (void) ++__d_first) {                                             \
				__move_op(_Tp, __mu9_inclusive_scan3__v__, __binary_op(_Tp, __mu9_inclusive_scan3__v__, *__first)); \
				__move_op(_Tp, *__d_first, __mu9_inclusive_scan3__v__);                                             \
			}                                                                                                      \
		}                                                                                                         \
	}                                                                                                            \
mu0_scope_end

#	define mu9_inclusive_scan4(_Tp, __first, __last, __d_first, __init)         \
mu0_scope_begin                                                                \
	_Tp __mu9_inclusive_scan4__v__ = __init;                                    \
	for (; __first != __last; ++__first, (void) ++__d_first) {                  \
		__mu9_inclusive_scan4__v__ = _Tp, __mu9_inclusive_scan4__v__ + *__first; \
		*__d_first                 = __mu9_inclusive_scan4__v__;                 \
	}                                                                           \
mu0_scope_end

#	define mu9_inclusive_scan5(_Tp, __first, __last, __d_first, __init, __binary_op)        \
mu0_scope_begin                                                                            \
	_Tp __mu9_inclusive_scan5__v__ = __init;                                                \
	for (; __first != __last; ++__first, (void) ++__d_first) {                              \
		__mu9_inclusive_scan5__v__ = __binary_op(_Tp, __mu9_inclusive_scan5__v__, *__first); \
		*__d_first                 = __mu9_inclusive_scan5__v__;                             \
	}                                                                                       \
mu0_scope_end

#	define mu9_inclusive_scan6(_Tp, __first, __last, __d_first, __init, __binary_op, __move_op)            \
mu0_scope_begin                                                                                           \
	_Tp __mu9_inclusive_scan6__v__;                                                                        \
	__move_op(_Tp, __mu9_inclusive_scan6__v__, __init);                                                    \
	for (; __first != __last; ++__first, (void) ++__d_first) {                                             \
		__move_op(_Tp, __mu9_inclusive_scan6__v__, __binary_op(_Tp, __mu9_inclusive_scan6__v__, *__first)); \
		__move_op(_Tp, *__d_first, __mu9_inclusive_scan6__v__);                                             \
	}                                                                                                      \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_INCLUSIVE_SCAN_H */

/* EOF */