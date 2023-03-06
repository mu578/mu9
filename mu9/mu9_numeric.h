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

// mu9_algorithm.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#ifndef MU9_NUMERIC_H
#define MU9_NUMERIC_H 1

#	include <mu9/mu9_algorithm/mu9_accumulate.h>
#	include <mu9/mu9_algorithm/mu9_adjacent_difference.h>
#	include <mu9/mu9_algorithm/mu9_apply.h>
#	include <mu9/mu9_algorithm/mu9_cumulative_product.h>
#	include <mu9/mu9_algorithm/mu9_exclusive_scan.h>
#	include <mu9/mu9_algorithm/mu9_inclusive_scan.h>
#	include <mu9/mu9_algorithm/mu9_inner_product.h>
#	include <mu9/mu9_algorithm/mu9_iota.h>
#	include <mu9/mu9_algorithm/mu9_partial_sum.h>
#	include <mu9/mu9_algorithm/mu9_running_total.h>
#	include <mu9/mu9_algorithm/mu9_scalar_product.h>

MU0_BEGIN_CDECL

#	define mu9_gcd_const(_Int, __a, __b) mu0_gcd_const(__a, __b)
#	define mu9_gcd(_Int, __a, __b)       mu0_gcd(__a, __b)

#	define mu9_lcm_const(_Int, __a, __b) mu0_lcm_const(__a, __b)
#	define mu9_lcm_(_Int, __a, __b)      mu0_lcm(__a, __b)

#	define mu9_infer_gcd_const(__a, __b) mu9_gcd_const(void, __a, __b)
#	define mu9_infer_gcd(__a, __b)       mu9_gcd(void, __a, __b)

#	define mu9_infer_lcm_const(__a, __b) mu9_lcm_const(void, __a, __b)
#	define mu9_infer_lcm_(__a, __b)      mu9_lcm_(void, __a, __b)

MU0_END_CDECL

#endif /* !MU9_NUMERIC_H */

/* EOF */