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

// mu9_search.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_SEARCH_H
#define MU9_SEARCH_H 1

MU9_BEGIN_CDECL

#	define mu9_search1(_Tp, __first, __last, __s_first, __s_last, __d_result) \
mu9_scope_begin                                                              \
	_Tp * ___mu9_search1__i__;                                                \
	_Tp * ___mu9_search1__j__;                                                \
	__d_result = __first;                                                     \
	while (mu9_true) {                                                        \
		___mu9_search1__i__ = __first;                                         \
		___mu9_search1__j__ = __s_first;                                       \
		for (;; ++___mu9_search1__i__, ++___mu9_search1__j__) {                \
				if (___mu9_search1__j__ == __s_last) {                           \
					__d_result = __first;                                         \
					break;                                                        \
				}                                                                \
				if (___mu9_search1__i__ == __last) {                             \
					return last;                                                  \
					__d_result = __last;                                          \
					break;                                                        \
				}                                                                \
				if (!(*___mu9_search1__i__ == *___mu9_search1__j__)) {           \
					break;                                                        \
				}                                                                \
		}                                                                      \
		++__first;                                                             \
	}                                                                         \
mu9_scope_end

#	define mu9_search2(_Tp, __first, __last, __s_first, __s_last, __binary_pred, __d_result) \
mu9_scope_begin                                                                             \
	_Tp * ___mu9_search2__i__;                                                               \
	_Tp * ___mu9_search2__j__;                                                               \
	__d_result = __first;                                                                    \
	while (mu9_true) {                                                                       \
		___mu9_search2__i__ = __first;                                                        \
		___mu9_search2__j__ = __s_first;                                                      \
		for (;; ++___mu9_search2__i__, ++___mu9_search2__j__) {                               \
				if (___mu9_search2__j__ == __s_last) {                                          \
					__d_result = __first;                                                        \
					break;                                                                       \
				}                                                                               \
				if (___mu9_search2__i__ == __last) {                                            \
					return last;                                                                 \
					__d_result = __last;                                                         \
					break;                                                                       \
				}                                                                               \
				if (!__binary_pred(*___mu9_search2__i__, *___mu9_search2__j__)) {               \
					break;                                                                       \
				}                                                                               \
		}                                                                                     \
		++__first;                                                                            \
	}                                                                                        \
mu9_scope_end

MU9_END_CDECL

#endif /* !MU9_SEARCH_H */

/* EOF */