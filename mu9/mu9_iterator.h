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

// mu9_iterator.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu0/mu0_integer.h>

#ifndef MU9_ITERATOR_H
#define MU9_ITERATOR_H 1

#	include <mu9/mu9_algorithm/mu9_swap.h>

MU0_BEGIN_CDECL

//#!
//#! macro<_Tp, _Dist>(_Tp &* __ptr, _Dist & __n) : _Tp *
//#!
#	define mu9_iterator_set(_Tp, __ptr, __n)                        (mu0_cast(_Tp *, __ptr) + (mu0_const_distance(__n)))

//#!
//#! macro<_Tp, _Dist>(const _Tp &* __ptr, _Dist & __n) : const _Tp *
//#!
#	define mu9_const_iterator_set(_Tp, __ptr, __n)                  (mu0_const_cast(_Tp *, __ptr) + (mu0_const_distance(__n)))

//#!
//#! macro<_Tp>(_Tp &* __ptr) : _Tp *
//#!
#	define mu9_iterator_begin(_Tp, __ptr)                           mu9_iterator_set(_Tp, __ptr, 0)

//#!
//#! macro<_Tp>(const _Tp &* __ptr) : const _Tp *
//#!
#	define mu9_const_iterator_begin(_Tp, __ptr)                     mu9_const_iterator_set(_Tp, __ptr, 0)

//#!
//#! macro<_Tp, _Dist>(_Tp &* __ptr, _Dist & __n) : _Tp *
//#!
#	define mu9_iterator_end(_Tp, __ptr, __n)                        mu9_iterator_set(_Tp, __ptr, __n)

//#!
//#! macro<_Tp, _Dist>(const _Tp &* __ptr, _Dist & __n) : const _Tp *
//#!
#	define mu9_const_iterator_end(_Tp, __ptr, __n)                  mu9_const_iterator_set(_Tp, __ptr, __n)

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last) : ptrdiff
//#!
#	define mu9_iterator_distance(_Tp, __first, __last)              mu0_difference((mu0_const_cast(_Tp *, __last) - mu0_const_cast(_Tp *, __first)))

//#!
//#! macro<_Tp>(_Tp &* __first, _Tp &* __last, , _Diff<return> & __d) : void
//#!
#	define mu9_iterator_difference(_Tp, __first, __last, __d)                   \
mu0_scope_begin                                                                \
	_Tp *            __mu9_iterator_difference__i__ = mu0_cast(_Tp *, __first); \
	_Tp *            __mu9_iterator_difference__j__ = mu0_cast(_Tp *, __last);  \
	mu0_difference_t __mu9_iterator_difference__n__ = mu0_const_difference(0);  \
	while (__mu9_iterator_difference__i__ != __mu9_iterator_difference__j__) {  \
		++__mu9_iterator_difference__i__;                                        \
		++__mu9_iterator_difference__n__;                                        \
	}                                                                           \
	__d = __mu9_iterator_difference__n__;                                       \
mu0_scope_end

#	define mu9_const_iterator_difference(_Tp, __first, __last, __d) mu9_iterator_difference(_Tp, __first, __last, __d) 

//#!
//#! macro<_Tp>(const _Tp &* __first, const _Tp &* __last) : ptrdiff
//#!
#	define mu9_const_iterator_distance(_Tp, __first, __last)        mu0_const_difference((mu0_const_cast(_Tp *, __last) - mu0_const_cast(_Tp *, __first)))

//#!
//#! macro<_Tp, _Dist>(_Tp &* __it, _Dist & __n) : void
//#!
#	define mu9_iterator_advance_n(_Tp, __it, __n) \
mu0_scope_begin                                  \
	(__it) += mu0_const_distance(__n);            \
mu0_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __it, _Dist & __n = +1) : void
//#!
#	define mu9_iterator_advance(_Tp, __it)                          mu9_iterator_advance_n(_Tp, __it, +1);
#	define mu9_iterator_forward(_Tp, __it)                          mu9_iterator_advance(_Tp, __it);

//#!
//#! macro<_Tp, _Dist>(_Tp &* __it, _Dist & __n = -1) : void
//#!
#	define mu9_iterator_backward(_Tp, __it)                         mu9_iterator_advance_n(_Tp, __it, -1);

//#!
//#! macro<_Tp, _Dist>(_Tp &* __it, _Dist & __n = +1) : _Tp *
//#!
#	define mu9_iterator_next_n(_Tp, __it, __n)                      ((__it) + mu0_const_distance(__n))
#	define mu9_iterator_next(_Tp, __it)                             ((__it) + mu0_const_distance(1)) 

#	define mu9_iterator_assign(_Tp, __it, __i1, __value) \
mu0_scope_begin                                         \
	(*((__it) + (__i1)) = __value);                      \
mu0_scope_end

#	define mu9_iterator_access(_Tp, __it, __i1)                     (*((__it) + (__i1)))

#	define mu9_iterator_switch(_Tp, __it, __i1, __i2)    \
mu0_scope_begin                                         \
	_Tp __mu9_iterator_switch__a__ = *((__it) + (__i1)); \
	_Tp __mu9_iterator_switch__b__ = *((__it) + (__i2)); \
	mu9_swap(_Tp                                         \
		, __mu9_iterator_switch__a__                      \
		, __mu9_iterator_switch__b__                      \
	);                                                   \
mu0_scope_end

//#!
//#! macro<_Tp, _Dist>(_Tp &* __it, _Dist & __n = -1) : _Tp *
//#!
#	define mu9_iterator_prev_n(_Tp, __it, __n)                      ((__it) + mu0_const_distance((__n) < 0 ? (__n) : -(__n)))
#	define mu9_iterator_prev(_Tp, __it)                             ((__it) + mu0_const_distance(-1))

#	define mu9_distance(_Tp, __first, __last)                       mu9_iterator_distance(_Tp, __first, __last)
#	define mu9_const_distance(_Tp, __first, __last)                 mu9_const_iterator_distance(_Tp, __first, __last)

#	define mu9_difference(_Tp, __first, __last, __d)                mu9_iterator_difference(_Tp, __first, __last, __d)
#	define mu9_const_difference(_Tp, __first, __last, __d)          mu9_const_iterator_difference(_Tp, __first, __last, __d)

#	define mu9_advance_n(_Tp, __it, __n)                            mu9_iterator_advance_n(_Tp, __it, __n)
#	define mu9_advance(_Tp, __it)                                   mu9_iterator_advance(_Tp, __it)

#	define mu9_next_n(_Tp, __it, __n)                               mu9_iterator_next_n(_Tp, __it, __n)
#	define mu9_next(_Tp, __it)                                      mu9_iterator_next(_Tp, __it)
#	define mu9_prev_n(_Tp, __it, __n)                               mu9_iterator_prev_n(_Tp, __it, __n)
#	define mu9_prev(_Tp, __it)                                      mu9_iterator_prev(_Tp, __it)

#	define mu9_begin(_Tp, __it)                                     mu9_iterator_begin(_Tp, __it)
#	define mu9_begin_n(_Tp, __it, __n)                              mu9_iterator_set(_Tp, __it, __n)
#	define mu9_end(_Tp, __it, __n)                                  mu9_iterator_end(_Tp, __it, __n)

#	define mu9_const_begin(_Tp, __it)                               mu9_const_iterator_begin(_Tp, __it)
#	define mu9_const_begin_n(_Tp, __it, __n)                        mu9_const_iterator_set(_Tp, __it, __n)
#	define mu9_const_end(_Tp, __it, __n)                            mu9_const_iterator_end(_Tp, __it, __n)

MU0_END_CDECL

#endif /* !MU9_ITERATOR_H */

/* EOF */