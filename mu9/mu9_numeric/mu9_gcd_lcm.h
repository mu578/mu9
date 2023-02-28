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

// mu9_gcd.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_GCD_H
#define MU9_GCD_H 1

MU0_BEGIN_CDECL

#	define ___mu9_gcd_00___(_Tp, __a, __b) (((__a >= __b) * ___mu9_gcd_01___(_Tp, __a, __b) + (__a < __b) * ___mu9_gcd_01___(_Tp, __b,__a)))
#	define ___mu9_gcd_01___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_02___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_02___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_03___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_03___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_04___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_04___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_05___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_05___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_06___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_06___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_07___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_07___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_09___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_09___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_10___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_10___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_11___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_11___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_12___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_12___(_Tp, __a, __b) ((((!(__b))) * (__a)) + (!!(__b)) * ___mu9_gcd_13___(_Tp, (__b), (__a) % ((__b) + !(__b))))
#	define ___mu9_gcd_13___(_Tp, __a, __b) (__a)

#	define mu9_gcd(_Tp, __a, __b) ((__a && __b) ? ___mu9_gcd_00___(_Tp, __a, __b) : 0)
#	define mu9_lcm(_Tp, __a, __b) ((__a && __b) ? (((__a) * (__b)) / ___mu9_gcd_00___(_Tp, __a, __b)) : 0)

MU0_END_CDECL

#endif /* !MU9_GCD_H */

/* EOF */