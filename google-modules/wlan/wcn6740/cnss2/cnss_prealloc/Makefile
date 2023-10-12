# SPDX-License-Identifier: GPL-2.0-only

ifeq ($(CONFIG_CNSS_OUT_OF_TREE),y)
ccflags-y += -I$(srctree)/$(src)/../inc
endif
obj-$(CONFIG_WCNSS_MEM_PRE_ALLOC) += cnss_prealloc.o
