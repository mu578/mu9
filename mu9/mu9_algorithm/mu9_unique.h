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

// mu9_unique.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_UNIQUE_H
#define MU9_UNIQUE_H 1

MU0_BEGIN_CDECL

#	define mu9_unique1(_Tp, __first, __last, __d_result)                               \
mu0_scope_begin                                                                       \
	_Tp * __mu9_unique1__i__ = __last;                                                 \
	if (__first != __mu9_unique1__i__) {                                               \
		__mu9_unique1__i__ = __first;                                                   \
		while (++__first != __last) {                                                   \
			if (!(*__mu9_unique1__i__ == *__first) && ++__mu9_unique1__i__ != __first) { \
				*__mu9_unique1__i__ = *__first;                                           \
			}                                                                            \
		}                                                                               \
		++__mu9_unique1__i__;                                                           \
	}                                                                                  \
	__d_result = __mu9_unique1__i__;                                                   \
mu0_scope_end

#	define mu9_unique2(_Tp, __first, __last, __d_result, __binary_pred)                                \
mu0_scope_begin                                                                                       \
	_Tp * __mu9_unique2__i__ = __last;                                                                 \
	if (__first != __mu9_unique2__i__) {                                                               \
		__mu9_unique2__i__ = __first;                                                                   \
		while (++__first != __last) {                                                                   \
			if (!__binary_pred(_Tp, *__mu9_unique2__i__, *__first) && ++__mu9_unique2__i__ != __first) { \
				*__mu9_unique2__i__ = *__first;                                                           \
			}                                                                                            \
		}                                                                                               \
		++__mu9_unique2__i__;                                                                           \
	}                                                                                                  \
	__d_result = __mu9_unique2__i__;                                                                   \
mu0_scope_end

#endif /* !MU9_UNIQUE_H */

/* EOF */