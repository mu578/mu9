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

#ifndef MU9_FUNCTIONAL_H
#define MU9_FUNCTIONAL_H 1

MU0_BEGIN_CDECL

//#!
//#! macro<>(& __a, & __b) : _Tp
//#!
#	define mu9_plus(___a, __b)                         ((__a) + (__b))
#	define mu9_minus(___a, __b)                        ((__a) - (__b))
#	define mu9_multiplies(___a, __b)                   ((__a) * (__b))
#	define mu9_divides(___a, __b)                      ((__a) / (__b))
#	define mu9_modulus(___a, __b)                      ((__a) % (__b))
#	define mu9_negate(___a)                            -(__a)

//#!
//#! macro<>(& __a, & __b) : bool
//#!
#	define mu9_logical_and(___a, __b)                  ( ((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_and(___a, __b)              (!((__a) && (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_or(___a, __b)                   ( ((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_logical_not_or(___a, __b)               (!((__a) || (__b)) ? mu0_true : mu0_false)
#	define mu9_negate(___a)                            !(__a)

//#!
//#! macro<>(& __a, & __b) : _Tp
//#!
#	define mu9_bit_and(___a, __b)                      ((__a) & (__b))
#	define mu9_bit_or(___a, __b)                       ((__a) | (__b))
#	define mu9_bit_xor(___a, __b)                      ((__a) ^ (__b))
#	define mu9_bit_not(___a)                            ~(__a)

//#!
//#! macro<>(& __a, & __b) : bool
//#!
#	define mu9_less_than(___a, __b)                    (((__a) <  (__b)) ? mu0_true : mu0_false)
#	define mu9_less_than_or_equal(___a, __b)           (((__a) <= (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than(___a, __b)                 (((__a) >  (__b)) ? mu0_true : mu0_false)
#	define mu9_greater_than_or_equal(___a, __b)        (((__a) >= (__b)) ? mu0_true : mu0_false)
#	define mu9_equal_to(___a, __b)                     (((__a) == (__b)) ? mu0_true : mu0_false)
#	define mu9_not_equal_to(___a, __b)                 (((__a) != (__b)) ? mu0_true : mu0_false)
#	define mu9_cmp(___a, __b)                          (mu9_less_than(___a, __b)) ? -1 : (mu9_equal_to(___a, __b) ? 0 : 1)

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
				)                                                                         \
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