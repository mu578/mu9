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

// mu9_functional.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_definition.h>

#ifndef MU9_FUNCTIONAL_H
#define MU9_FUNCTIONAL_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp>(_Tp& __a, _Tp& __b) : _Tp
//#!
#	define mu9_plus(_Tp, __a, __b)                   ((__a) + (__b))
#	define mu9_minus(_Tp, __a, __b)                  ((__a) - (__b))
#	define mu9_multiplies(_Tp, __a, __b)             ((__a) * (__b))
#	define mu9_divides(_Tp, __a, __b)                ((__a) / (__b))
#	define mu9_modulus(_Tp, __a, __b)                ((__a) % (__b))
#	define mu9_negate(_Tp, __a)                      -(__a)

//#!
//#! macro<_Tp>((_Tp& __c, _Tp& __a, _Tp& __b) : _Tp
//#!
#	define mu9_multiply_accumulate(_Tp, __c, __a, __b) \
	mu9_plus(_Tp, __c, mu9_multiplies(_Tp, __a, __b))

//#!
//#! macro<_Tp>(& __a, & __b) : bool
//#!
#	define mu9_logical_and(_Tp, __a, __b)            (((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_and(_Tp, __a, __b)        (!((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_or(_Tp, __a, __b)             ( ((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_or(_Tp, __a, __b)         (!((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not(_Tp, __a)                 !(__a)

//#!
//#! macro<_Tp>(& __a, & __b) : _Tp
//#!
#	define mu9_bit_and(_Tp, __a, __b)                ((__a) & (__b))
#	define mu9_bit_or(_Tp, __a, __b)                 ((__a) | (__b))
#	define mu9_bit_xor(_Tp, __a, __b)                ((__a) ^ (__b))
#	define mu9_bit_not(_Tp, __a)                     ~(__a)

//#!
//#! macro<_Tp>(& __a, & __b) : bool
//#!
#	define mu9_less_than(_Tp, __a, __b)              (((__a) <  (__b)) ? mu0_true : mu0_false)
#	define mu9_less_than_or_equal(_Tp, __a, __b)     (((__a) <= (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than(_Tp, __a, __b)           (((__a) >  (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than_or_equal(_Tp, __a, __b)  (((__a) >= (__b)) ? mu0_true : mu0_false)
#	define mu9_equal_to(_Tp, __a, __b)               (((__a) == (__b)) ? mu0_true : mu0_false)
#	define mu9_not_equal_to(_Tp, __a, __b)           (((__a) != (__b)) ? mu0_true : mu0_false)

#	define mu9_less(_Tp, __a, __b)                   mu9_less_than(_Tp, __a, __b)
#	define mu9_greater(_Tp, __a, __b)                mu9_greater_than(_Tp, __a, __b)
#	define mu9_less_equal(_Tp, __a, __b)             mu9_less_than_or_equal(_Tp, __a, __b)
#	define mu9_greater_equal(_Tp, __a, __b)          mu9_greater_than_or_equal(_Tp, __a, __b)

#	define mu9_not_fn(__fn) \
	!__fn


MU0_END_CDECL

#endif /* !MU9_FUNCTIONAL_H */

/* EOF */