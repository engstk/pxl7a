# SPDX-License-Identifier: GPL-2.0
#
# Makefile for GXP driver.
#

GXP_CHIP ?= AMALTHEA
CONFIG_$(GXP_CHIP) ?= m
GCIP_DIR := gcip-kernel-driver/drivers/gcip

obj-$(CONFIG_$(GXP_CHIP)) += gxp.o

gxp-objs += \
		gxp-bpm.o \
		gxp-client.o \
		gxp-core-telemetry.o \
		gxp-debug-dump.o \
		gxp-debugfs.o \
		gxp-dma-fence.o \
		gxp-dma-iommu.o \
		gxp-dmabuf.o \
		gxp-domain-pool.o \
		gxp-doorbell.o \
		gxp-eventfd.o \
		gxp-firmware-data.o \
		gxp-firmware-loader.o \
		gxp-firmware.o \
		gxp-lpm.o \
		gxp-mailbox-manager.o \
		gxp-mailbox.o \
		gxp-mapping.o \
		gxp-mb-notification.o \
		gxp-pm.o \
		gxp-ssmt.o \
		gxp-thermal.o \
		gxp-vd.o

ifeq ($(GXP_CHIP),AMALTHEA)

gxp-objs +=	\
		gsx01-mailbox-driver.o \
		gxp-platform.o \
		gxp-mailbox-impl.o

GMODULE_PATH := $(OUT_DIR)/../google-modules
EDGETPU_CHIP := janeiro

endif

ifeq ($(CONFIG_$(GXP_CHIP)),m)

gxp-objs += \
		$(GCIP_DIR)/gcip-alloc-helper.o \
		$(GCIP_DIR)/gcip-dma-fence.o \
		$(GCIP_DIR)/gcip-domain-pool.o \
		$(GCIP_DIR)/gcip-firmware.o \
		$(GCIP_DIR)/gcip-image-config.o \
		$(GCIP_DIR)/gcip-kci.o \
		$(GCIP_DIR)/gcip-mailbox.o \
		$(GCIP_DIR)/gcip-mem-pool.o \
		$(GCIP_DIR)/gcip-pm.o \
		$(GCIP_DIR)/gcip-telemetry.o \
		$(GCIP_DIR)/gcip-thermal.o

endif

KERNEL_SRC ?= /lib/modules/$(shell uname -r)/build
M ?= $(shell pwd)

# Obtain the current git commit hash for logging on probe
GIT_PATH=$(srctree)
ifeq ($(shell git --git-dir=$(GIT_PATH)/.git rev-parse --is-inside-work-tree),true)
        GIT_REPO_STATE=$(shell (git --git-dir=$(GIT_PATH)/.git --work-tree=$(GIT_PATH) status --porcelain | grep -q .) && echo -dirty)
        ccflags-y       += -DGIT_REPO_TAG=\"$(shell git --git-dir=$(GIT_PATH)/.git rev-parse --short HEAD)$(GIT_REPO_STATE)\"
else
        ccflags-y       += -DGIT_REPO_TAG=\"Not\ a\ git\ repository\"
endif

# If building via make directly, specify target platform by adding
#     "GXP_PLATFORM=<target>"
# With one of the following values:
#     - SILICON
#     - ZEBU
#     - IP_ZEBU
#     - GEM5
# Defaults to building for SILICON if not otherwise specified.
GXP_PLATFORM ?= SILICON

gxp-flags := -DCONFIG_GXP_$(GXP_PLATFORM) -DCONFIG_$(GXP_CHIP)=1 \
	     -I$(M)/include -I$(M)/gcip-kernel-driver/include \
	     -I$(srctree)/$(M)/include \
	     -I$(srctree)/$(src)/gcip-kernel-driver/include \
	     -I$(srctree)/drivers/gxp/include
ccflags-y += $(EXTRA_CFLAGS) $(gxp-flags)

KBUILD_OPTIONS += GXP_CHIP=$(GXP_CHIP) GXP_PLATFORM=$(GXP_PLATFORM)

modules modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) \
	EXTRA_CFLAGS="$(EXTRA_CFLAGS)" $(@)
clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M)/$(GCIP_DIR) $(@)
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) $(@)
