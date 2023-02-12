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

define walk-dir-recursive
	$(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk-dir-recursive, $(e)))
endef

define walk-dir
	$(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(e))
endef

ifeq ($(strip $(MU9_ROOT_PATH)),)
$(error MU9_ROOT_PATH is not set)
endif

MU9_MODULE_NAME  ?= mu9
MU9_MODULE_PATH  ?= $(MU9_ROOT_PATH)
MU9_SOURCE_FILES ?= $(call walk-dir-recursive, $(MU9_MODULE_PATH)/source)
MU9_FILTER_FILES ?= $(filter %.c, $(MU9_SOURCE_FILES))

LOCAL_SRC_FILES += $(MU9_FILTER_FILES)
LOCAL_CFLAGS    += -I$(MU9_MODULE_PATH)

# EOF