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

#include <mu9/mu9_definition.h>

#ifndef MU9_FUNCTIONAL_H
#define MU9_FUNCTIONAL_H 1

MU9_BEGIN_CDECL

//#!
//#! macro<>(& __a, & __b) : _Tp
//#!
#	define mu9_plus(_Tp, __a, __b)                  ((__a) + (__b))
#	define mu9_minus(_Tp, __a, __b)                 ((__a) - (__b))
#	define mu9_multiplies(_Tp, __a, __b)            ((__a) * (__b))
#	define mu9_divides(_Tp, __a, __b)               ((__a) / (__b))
#	define mu9_modulus(_Tp, __a, __b)               ((__a) % (__b))
#	define mu9_negate(_Tp, __a)                     -(__a)

//#!
//#! macro<>(& __a, & __b) : bool
//#!
#	define mu9_logical_and(_Tp, __a, __b)           ( ((__a) && (__b)) ? mu9_true : mu9_false)
#	define mu9_logical_not_and(_Tp, __a, __b)       (!((__a) && (__b)) ? mu9_true : mu9_false)
#	define mu9_logical_or(_Tp, __a, __b)            ( ((__a) || (__b)) ? mu9_true : mu9_false)
#	define mu9_logical_not_or(_Tp, __a, __b)        (!((__a) || (__b)) ? mu9_true : mu9_false)
#	define mu9_negate(_Tp, __a)                     !(__a)

//#!
//#! macro<>(& __a, & __b) : _Tp
//#!
#	define mu9_bit_and(_Tp, __a, __b)               ((__a) & (__b))
#	define mu9_bit_or(_Tp, __a, __b)                ((__a) | (__b))
#	define mu9_bit_xor(_Tp, __a, __b)               ((__a) ^ (__b))
#	define mu9_bit_not(_Tp, __a)                     ~(__a)

//#!
//#! macro<>(& __a, & __b) : bool
//#!
#	define mu9_less_than(_Tp, __a, __b)             (((__a) <  (__b)) ? mu9_true : mu9_false)
#	define mu9_less_than_or_equal(_Tp, __a, __b)    (((__a) <= (__b)) ? mu9_true : mu9_false)
#	define mu9_greater_than(_Tp, __a, __b)          (((__a) >  (__b)) ? mu9_true : mu9_false)
#	define mu9_greater_than_or_equal(_Tp, __a, __b) (((__a) >= (__b)) ? mu9_true : mu9_false)
#	define mu9_equal_to(_Tp, __a, __b)              (((__a) == (__b)) ? mu9_true : mu9_false)
#	define mu9_not_equal_to(_Tp, __a, __b)          (((__a) != (__b)) ? mu9_true : mu9_false)

//#!
//#! macro<_Tp1, _Tp2, __binary_pred>(_Tp1 & __a, _Tp2 & __b, __binary_pred) : bool
//#!
#	define mu9_cmp_to(_Tp1, _Tp2, __a, __b, __binary_pred)                           \
		(__binary_pred(m9_const_cast(_Tp1, __a), m9_const_cast(_Tp1, __b))            \
			? edomu_true                                                               \
			: (__binary_pred(m9_const_cast(_Tp2, __a), m9_const_cast(_Tp2, __b))       \
				? edomu_true                                                            \
				: (__binary_pred(m9_const_cast(_Tp2, __a), m9_const_cast(_Tp1, __b))    \
					? edomu_true                                                         \
					: (__binary_pred(m9_const_cast(_Tp1, __a), m9_const_cast(_Tp2, __b)) \
							? edomu_true                                                   \
							: edomu_false                                                  \
						)                                                                 \
					)                                                                    \
				)                                                                       \
			)                                                                          \
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

MU9_END_CDECL

#endif /* !MU9_FUNCTIONAL_H */

/* EOF */