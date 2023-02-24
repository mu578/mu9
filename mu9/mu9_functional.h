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
//#! macro<>(& __a, & __b) : _Tp
//#!
#	define mu9_plus(__a, __b)                         ((__a) + (__b))
#	define mu9_minus(__a, __b)                        ((__a) - (__b))
#	define mu9_multiplies(__a, __b)                   ((__a) * (__b))
#	define mu9_divides(__a, __b)                      ((__a) / (__b))
#	define mu9_modulus(__a, __b)                      ((__a) % (__b))
#	define mu9_negate(__a)                            -(__a)

//#!
//#! macro<_Tp>(_Tp& __a, _Tp& __b) : _Tp
//#!
#	define mu9_add(_Tp, __a, __b)                     mu9_plus(__a, __b)
#	define mu9_sub(_Tp, __a, __b)                     mu9_minus(__a, __b)
#	define mu9_mul(_Tp, __a, __b)                     mu9_multiplies(__a, __b)
#	define mu9_div(_Tp, __a, __b)                     mu9_divides(__a, __b)
#	define mu9_mod(_Tp, __a, __b)                     mu9_modulus(__a, __b)
#	define mu9_neg(_Tp, __a)                          mu9_negate(__a)
#	define mu9_mad(_Tp, __a, __b, __c)                mu9_plus(__c, mu9_multiplies(__a, __b))

//#!
//#! macro<>(& __a, & __b) : bool
//#!
#	define mu9_logical_and(__a, __b)                  ( ((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_and(__a, __b)              (!((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_or(__a, __b)                   ( ((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_or(__a, __b)               (!((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_negate(__a)                            !(__a)

//#!
//#! macro<>(& __a, & __b) : _Tp
//#!
#	define mu9_bit_and(__a, __b)                      ((__a) & (__b))
#	define mu9_bit_or(__a, __b)                       ((__a) | (__b))
#	define mu9_bit_xor(__a, __b)                      ((__a) ^ (__b))
#	define mu9_bit_not(__a)                            ~(__a)

//#!
//#! macro<>(& __a, & __b) : bool
//#!
#	define mu9_less_than(__a, __b)                    (((__a) <  (__b)) ? mu0_true : mu0_false)
#	define mu9_less_than_or_equal(__a, __b)           (((__a) <= (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than(__a, __b)                 (((__a) >  (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than_or_equal(__a, __b)        (((__a) >= (__b)) ? mu0_true : mu0_false)
#	define mu9_equal_to(__a, __b)                     (((__a) == (__b)) ? mu0_true : mu0_false)
#	define mu9_not_equal_to(__a, __b)                 (((__a) != (__b)) ? mu0_true : mu0_false)

//#!
//#! macro<>(& __a, & __b) : int
//#!
#	define mu9_compare(__a, __b)                      (mu9_less_than(__a, __b)) ? -1 : (mu9_equal_to(__a, __b) ? 0 : 1)

//#!
//#! macro<_Tp>(_Tp& __a, _Tp& __b) : bool
//#!
#	define mu9_lt(_Tp, __a, __b)                      mu9_less_than(__a, __b)
#	define mu9_le(_Tp, __a, __b)                      mu9_less_than_or_equal(__a, __b)
#	define mu9_gt(_Tp, (__a, __b)                     mu9_greater_than(__a, __b)
#	define mu9_ge(_Tp, __a, __b)                      mu9_greater_than_or_equal(__a, __b)
#	define mu9_eq(_Tp, __a, __b)                      mu9_equal_to(__a, __b)
#	define mu9_ne(_Tp, __a, __b)                      mu9_not_equal_to(__a, __b)

//#!
//#! macro<_Tp>(_Tp& __a, _Tp& __b) : int
//#!
#	define mu9_cp(_Tp, __a, __b)                      mu9_compare(__a, __b)

//#!
//#! macro<_Tp1, _Tp2, __binary_pred>(_Tp1 & __a, _Tp2 & __b, __binary_pred) : bool
//#!
#	define mu9_cmp_to(_Tp1, _Tp2, __a, __b, __binary_pred)                             \
		(__binary_pred(mu0_const_cast(_Tp1, __a), mu0_const_cast(_Tp1, __b))            \
			? edomu_true                                                                 \
			: (__binary_pred(mu0_const_cast(_Tp2, __a), mu0_const_cast(_Tp2, __b))       \
				? edomu_true                                                              \
				: (__binary_pred(mu0_const_cast(_Tp2, __a), mu0_const_cast(_Tp1, __b))    \
					? edomu_true                                                           \
					: (__binary_pred(mu0_const_cast(_Tp1, __a), mu0_const_cast(_Tp2, __b)) \
							? edomu_true                                                     \
							: edomu_false                                                    \
						)                                                                   \
					)                                                                      \
			)                                                                            \
		)

//#!
//#! macro<_Tp1, _Tp2>(_Tp1 & __a, _Tp2 & __b) : bool
//#!
#	define mu9_cmp_equal(_Tp1, _Tp2, __a, __b)         (mu9_cmp_to(_Tp1, _Tp2, __a, __b, mu9_equal_to))
#	define mu9_cmp_not_equal(_Tp1, _Tp2, __a, __b)     (!mu9_cmp_equal(_Tp1, _Tp2, __a, __b))
#	define mu9_cmp_less(_Tp1, _Tp2, __a, __b)          (mu9_cmp_to(_Tp1, _Tp2, __a, __b, mu9_less_than))
#	define mu9_cmp_greater(_Tp1, _Tp2, __a, __b)       (mu9_cmp_less(_Tp2, _Tp1, __b, __a))
#	define mu9_cmp_less_equal(_Tp1, _Tp2, __a, __b)    (!mu9_cmp_greater(_Tp1, _Tp2, __a, __b))
#	define mu9_cmp_greater_equal(_Tp1, _Tp2, __a, __b) (!cmp_less(_Tp1, _Tp2, __a, __b))

MU0_END_CDECL

#endif /* !MU9_FUNCTIONAL_H */

/* EOF */