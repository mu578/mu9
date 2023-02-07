//
// # -*- coding: utf-8, tab-width: 3 -*-

//             ___//
//            / _ \              //
//              _   _  _   _( (_) |             //
//             | | | || | | |\__, |             //
//             | |_| || |_| |  / /              //
//             | ._,_| \___/  /_///
//             | |//
//             |_|//

// mu9_string.h
//
// Copyright (C) 2023 mu578. All rights reserved.
//

#include <mu9/mu9_definition.h>

#ifndef MU9_STRING_H
#define MU9_STRING_H 1

MU9_BEGIN_CDECL

typedef          char  mu9_char8_t;
typedef unsigned char  mu9_uchar8_t;
typedef signed   char  mu9_schar8_t;

typedef mu9_char8_t  * mu9_vchar8_t;
typedef mu9_uchar8_t * mu9_vuchar8_t;
typedef mu9_schar8_t * mu9_vschar8_t;

typedef mu9_vchar8_t   mu9_string8_t;
typedef mu9_vuchar8_t  mu9_binary8_t;

MU9_END_CDECL

#endif /* !MU9_STRING_H */

/* EOF */