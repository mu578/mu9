#
# # -*- coding: utf-8, tab-width: 3 -*-

#                                                          ___                                             #
#                                                         / _ \                                            #
#                                            _   _  _   _( (_) |                                           #
#                                           | | | || | | |\__, |                                           #
#                                           | |_| || |_| |  / /                                            #
#                                           | ._,_| \___/  /_/                                             #
#                                           | |                                                            #
#                                           |_|                                                            #

# mu9_source.mk
#
# Copyright (C) 2023 mu578. All rights reserved.
#

ifeq ($(strip $(MU9_ROOT_PATH)),)
$(error MU9_ROOT_PATH is not set)
endif

LOCAL_SRC_FILES += $(call filter-dir-recursive, %.c, $(MU9_ROOT_PATH)/source)
LOCAL_CFLAGS    += -I$(MU9_ROOT_PATH)

# EOF