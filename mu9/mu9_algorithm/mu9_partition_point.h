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

// mu9_partition_point.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_iterator.h>

#ifndef MU9_PARTITION_POINT_H
#define MU9_PARTITION_POINT_H 1

MU0_BEGIN_CDECL

#	define mu9_partition_point(_Tp, __first, __last, __unary_pred, __d_result)              \
mu0_scope_begin                                                                            \
	_Tp *          __mu9_partition_point__i__;                                              \
	mu0_distance_t __mu9_partition_point__c__ = mu9_distance(_Tp, __first, __last);         \
	mu0_distance_t __mu9_partition_point__n__;                                              \
	while (__mu9_partition_point__c__ != mu0_const_distance(0)) {                           \
		__mu9_partition_point__i__ = __first;                                                \
		__mu9_partition_point__n__ = __mu9_partition_point__c__ / mu0_const_distance(2);     \
		mu9_advance(_Tp, __mu9_partition_point__i__, __mu9_partition_point__n__);            \
		if (__unary_pred(_Tp, *__mu9_partition_point__i__)) {                                \
			__first                     = ++__mu9_partition_point__i__;                       \
			__mu9_partition_point__c__ -= __mu9_partition_point__n__ + mu0_const_distance(1); \
		} else {                                                                             \
			__mu9_partition_point__c__  = __mu9_partition_point__n__;                         \
		}                                                                                    \
	}                                                                                       \
	__d_result = __first;                                                                   \
mu0_scope_end

MU0_END_CDECL

#endif /* !MU9_PARTITION_POINT_H */

/* EOF */