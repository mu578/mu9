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

// mu9_gcd_lcm.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_GCD_LCM_H
#define MU9_GCD_LCM_H 1

MU0_BEGIN_CDECL

#	define mu9_gcd_const(_Int, __a, __b) __mu0_inline_gcd_const__(_Int, __a, __b)
#	define mu9_lcm_const(_Int, __a, __b) __mu0_inline_lcm_const__(_Int, __a, __b)
#	define mu9_gcd(_Int, __a, __b)       __mu0_inline_gcd__(_Int, __a, __b)
#	define mu9_lcm(_Int, __a, __b)       __mu0_inline_lcm__(_Int, __a, __b)

MU0_END_CDECL

#endif /* !MU9_GCD_LCM_H */

/* EOF */