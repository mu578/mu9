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

#include <mu8/mu8_functional.h>

#ifndef MU9_FUNCTIONAL_H
#define MU9_FUNCTIONAL_H 1

MU0_BEGIN_CDECL

//#!
//#! macro{{binary_operation}}<_Tp>(_Tp & __a, _Tp & __b) : _Tp
//#!
#	define mu9_plus(_Tp, __a, __b)                   ((__a) + (__b))
#	define mu9_minus(_Tp, __a, __b)                  ((__a) - (__b))
#	define mu9_multiplies(_Tp, __a, __b)             ((__a) * (__b))
#	define mu9_divides(_Tp, __a, __b)                ((__a) / (__b))

//#!
//#! macro{{binary_operation}}<_Tp>(_Tp & __a, _Tp & __b) : _Tp
//#!
#	define mu9_modulus(_Tp, __a, __b)                ((__a) % (__b))

//#!
//#! macro{{unary_operation}}<_Tp>(_Tp & __x) : _Tp
//#!
#	define mu9_negate(_Tp, __x)                      -(__x)

//#!
//#! macro{{unary_operation}}<_Tp>(_Tp __x) : _Tp
//#!
#	define mu9_initialize(_Tp, __x)                  mu8_ini(_Tp, __x)

//#!
//#! macro{{binary_operation}}<_Tp>(_Tp & __a, _Tp & __b) : _Tp
//#!
#	define mu9_addition(_Tp, __a, __b)               mu8_add(_Tp, __a, __b)
#	define mu9_subtraction(_Tp, __a, __b)            mu8_sub(_Tp, __a, __b)
#	define mu9_multiplication(_Tp, __a, __b)         mu8_mul(_Tp, __a, __b)
#	define mu9_division(_Tp, __a, __b)               mu8_div(_Tp, __a, __b)

//#!
//#! macro{{trinary_operation}}<_Tp>(_Tp & __c, _Tp & __a, _Tp & __b) : _Tp
//#!
#	define mu9_multiply_accumulate(_Tp, __c, __a, __b) \
	mu9_addition(_Tp, __c, mu9_multiplication(_Tp, __a, __b))

//#!
//#! macro{{unary_operation}}<_Tp>(const _Tp & __x) : _Tp
//#!
#	define mu9_twice(_Tp, __x) \
	mu9_addition(_Tp, __x, __x)

#	define mu9_square(_Tp, __x) \
	mu9_multiplication(_Tp, __x, __x)

#	define mu9_cube(_Tp, __x) \
	mu9_multiplication(_Tp, __x, mu9_square(_Tp, __x))

#	define mu9_biquadrate(_Tp, __x) \
	mu9_multiplication(_Tp, __x, mu9_cube(_Tp, __x))

//#!
//#! macro{{binary_operation}}<_Tp>(const _Tp & __c, const _Tp & __a) : _Tp
//#!
#	define mu9_square_accumulate(_Tp, __c, __a) \
	mu9_multiply_accumulate(_Tp, __c, __a, __a)

//#!
//#! macro{{binary_predicate}}<_Tp>(const _Tp & __a, const _Tp & __b) : bool
//#!
#	define mu9_logical_and(_Tp, __a, __b)            ( ((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_and(_Tp, __a, __b)        (!((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_or(_Tp, __a, __b)             ( ((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_or(_Tp, __a, __b)         (!((__a) || (__b)) ? mu0_true : mu0_false)

//#!
//#! macro{{unary_predicate}}<_Tp>(const _Tp & __x) : bool
//#!
#	define mu9_logical_not(_Tp, __x)                 !(__x)

//#!
//#! macro{{binary_operation}}<_Tp>(const _Tp & __a, const _Tp & __b) : _Tp
//#!
#	define mu9_bit_and(_Tp, __a, __b)                ((__a) & (__b))
#	define mu9_bit_or(_Tp, __a, __b)                 ((__a) | (__b))
#	define mu9_bit_xor(_Tp, __a, __b)                ((__a) ^ (__b))

//#!
//#! macro{{unary_operation}}<_Tp>(const _Tp & __x) : _Tp
//#!
#	define mu9_bit_not(_Tp, __x)                     ~(__x)

//#!
//#! macro{{binary_predicate}}<_Tp>(const _Tp & __a, const _Tp & __b) : bool
//#!
#	define mu9_less_than(_Tp, __a, __b)              (((__a) <  (__b)) ? mu0_true : mu0_false)
#	define mu9_less_than_or_equal(_Tp, __a, __b)     (((__a) <= (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than(_Tp, __a, __b)           (((__a) >  (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than_or_equal(_Tp, __a, __b)  (((__a) >= (__b)) ? mu0_true : mu0_false)
#	define mu9_equal_to(_Tp, __a, __b)               (((__a) == (__b)) ? mu0_true : mu0_false)
#	define mu9_not_equal_to(_Tp, __a, __b)           (((__a) != (__b)) ? mu0_true : mu0_false)

//#!
//#! macro{{binary_predicate}}<_Tp>(const _Tp & __a, const _Tp & __b) : bool
//#!
#	define mu9_less(_Tp, __a, __b)                   mu8_lt(_Tp, __a, __b)
#	define mu9_greater(_Tp, __a, __b)                mu8_le(_Tp, __a, __b)
#	define mu9_less_equal(_Tp, __a, __b)             mu8_gt(_Tp, __a, __b)
#	define mu9_greater_equal(_Tp, __a, __b)          mu8_ge(_Tp, __a, __b)
#	define mu9_equal(_Tp, __a, __b)                  mu8_eq(_Tp, __a, __b)

#	define mu9_not_fn(__fn)                         !__fn

//#!
//#! macro<_Tp>(_Tp & __a, _Tp & __b) : lvalue
//#!
#	define mu9_assign(_Tp, __a, __b)                 __a = __b

//#!
//#! macro<_Tp>(_Tp & __a, _Tp __x) : lvalue
//#!
#	define mu9_assign_initialize(_Tp, __a, __x)      __a = mu9_initialize(_Tp, __x)

MU0_END_CDECL

#endif /* !MU9_FUNCTIONAL_H */

/* EOF */