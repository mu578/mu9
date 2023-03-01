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

#	define ___mu9_gcd_00___(__a, __b) (((__a >= __b) * ___mu9_gcd_01___(__a, __b) + (__a < __b) * ___mu9_gcd_01___(__b,__a)))
#	define ___mu9_gcd_01___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_02___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_02___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_03___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_03___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_04___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_04___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_05___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_05___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_06___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_06___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_07___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_07___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_09___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_09___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_10___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_10___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_11___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_11___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_12___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_12___(__a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_13___((__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_13___(__a, __b) (__a)

#	define mu9_gcd_static(__a, __b) ((__a && __b) ? ___mu9_gcd_00___(__a, __b) : 0)
#	define mu9_lcm_static(__a, __b) ((__a && __b) ? (((__a) * (__b)) / ___mu9_gcd_00___(__a, __b)) : 0)
#	define mu9_gcd_large(__a, __b)  __mu0_gcd__(__a, __b)
#	define mu9_lcm_large(__a, __b)  __mu0_lcm__(__a, __b)

MU0_END_CDECL

#endif /* !MU9_GCD_LCM_H */

/* EOF */