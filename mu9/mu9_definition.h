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

// mu9_definition.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#ifndef MU9_DEFINITION_H
#define MU9_DEFINITION_H 1

#	ifndef MU9_HAVE_MU8
#		define MU9_HAVE_MU8 0
#	endif

#	if MU9_HAVE_MU8
#include <mu8/mu8_definition.h>
#	endif

#	if MU9_HAVE_MU8
#		define MU9_BEGIN_CDECL MU8_BEGIN_CDECL
#		define MU9_END_CDECL   MU8_END_CDECL
#	else
#	ifdef __cplusplus
#		define MU9_BEGIN_CDECL extern "C" {
#		define MU9_END_CDECL   }
#	else
#		define MU9_BEGIN_CDECL
#		define MU9_END_CDECL
#	endif
#	endif

MU9_BEGIN_CDECL

#	if MU9_HAVE_MU8
#	define mu9_scope_begin         mu8_scope_begin
#	define mu9_scope_end           mu8_scope_end

#	define mu9_nullptr             mu8_nullptr
#	define mu9_is_nullptr(__x)     mu8_is_nullptr(__x)
#	define mu9_not_nullptr(__x)    mu8_not_nullptr(__x)

#	define m9_cast(_Tp, __x)       m8_cast(_Tp, __x)
#	define m9_const_cast(_Tp, __x) m8_const_cast(_Tp, __x)
#	else
#	define mu9_scope_begin         do     {
#	define mu9_scope_end           break; } while (0)

#	define mu9_nullptr             NULL
#	define mu9_is_nullptr(__x)     ((__x) == NULL ? 1 : 0)
#	define mu9_not_nullptr(__x)    ((__x) != NULL ? 1 : 0)

#	define m9_cast(_Tp, __x)       (_Tp)(__x)
#	define m9_const_cast(_Tp, __x) (const _Tp)(__x)
#	endif

MU9_END_CDECL

#endif /* !MU9_DEFINITION_H */

/* EOF */