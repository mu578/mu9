#
# # -*- coding: utf-8, tab-width: 3 -*-

#                                                           ___                                            #
#                                                          /   \                                           #
#                                            _   _  _   _  \ O /                                           #
#                                           | | | || | | | / _ \                                           #
#                                           | |_| || |_| |( (_) )                                          #
#                                           | ._,_| \___/  \___/                                           #
#                                           | |                                                            #
#                                           |_|                                                            #

# mu9_header.mk
#
# Copyright (C) 2023 mu578. All rights reserved.
#

ifeq ($(strip $(MU9_ROOT_PATH)),)
$(error MU9_ROOT_PATH is not set)
endif

MU9_MODULE_NAME ?= mu9
MU9_MODULE_PATH ?= $(MU9_ROOT_PATH)
LOCAL_CFLAGS    += -I$(MU9_MODULE_PATH)

# EOF