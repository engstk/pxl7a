/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Amalthea CSR definitions.
 *
 * Copyright (C) 2021-2022 Google LLC
 */

#ifndef __AMALTHEA_CSRS_H__
#define __AMALTHEA_CSRS_H__

#define GXP_REG_DOORBELLS_SET_WRITEMASK 0x1
#define GXP_REG_DOORBELLS_CLEAR_WRITEMASK 0x1

#define GXP_CMU_OFFSET 0x200000
#define GXP_CMU_SIZE 0x1000

enum gxp_csrs {
	GXP_REG_LPM_VERSION = 0x40000,
	GXP_REG_AURORA_REVISION = 0x80000,
	GXP_REG_COMMON_INT_POL_0 = 0x81000,
	GXP_REG_COMMON_INT_POL_1 = 0x81004,
	GXP_REG_DEDICATED_INT_POL = 0x81008,
	GXP_REG_RAW_EXT_INT = 0x82000,
	GXP_REG_CORE_PD = 0x82800,
	GXP_REG_GLOBAL_COUNTER_LOW = 0x83000,
	GXP_REG_GLOBAL_COUNTER_HIGH = 0x83004,
	GXP_REG_WDOG_CONTROL = 0x86000,
	GXP_REG_WDOG_VALUE = 0x86008,
	GXP_REG_TIMER_COMPARATOR = 0x90000,
	GXP_REG_TIMER_CONTROL = 0x90004,
	GXP_REG_TIMER_VALUE = 0x90008,
	GXP_REG_DOORBELL_0_STATUS = 0xC0000,
	GXP_REG_DOORBELL_0_SET = 0xC0004,
	GXP_REG_DOORBELL_0_CLEAR = 0xC0008,
	GXP_REG_DOORBELL_1_STATUS = 0xC1000,
	GXP_REG_DOORBELL_1_SET = 0xC1004,
	GXP_REG_DOORBELL_1_CLEAR = 0xC1008,
	GXP_REG_CORE_0_INST_BPM = 0x200000,
	GXP_REG_CORE_1_INST_BPM = 0x210000,
	GXP_REG_CORE_2_INST_BPM = 0x220000,
	GXP_REG_CORE_3_INST_BPM = 0x230000,
};

#define GXP_REG_COMMON_INT_MASK_0_DOORBELLS_MASK 0xFFFFFFFF
#define GXP_REG_ETM_PWRCTL_CORE_RESET_SHIFT	16

/* helpers for calculating core CSRs offsets */
#define GXP_CORE_0_BASE GXP_REG_CORE_0_INST_BPM
#define GXP_CORE_SIZE (GXP_REG_CORE_1_INST_BPM - GXP_REG_CORE_0_INST_BPM)
#define GXP_CORE_REG(core, off) (GXP_CORE_0_BASE + GXP_CORE_SIZE * core + off)

/* Per core CSRs. @core should be in region 0 ~ GXP_NUM_CORES-1 */
#define GXP_CORE_REG_INST_BPM(core) GXP_CORE_REG(core, 0x0)
#define GXP_CORE_REG_PROFILING_CONDITION(core) GXP_CORE_REG(core, 0x4000)
#define GXP_CORE_REG_PROCESSOR_ID(core) GXP_CORE_REG(core, 0x4004)
#define GXP_CORE_REG_ALT_RESET_VECTOR(core) GXP_CORE_REG(core, 0x4008)
#define GXP_CORE_REG_COMMON_INT_MASK_0(core) GXP_CORE_REG(core, 0x4010)
#define GXP_CORE_REG_COMMON_INT_MASK_1(core) GXP_CORE_REG(core, 0x4014)
#define GXP_CORE_REG_DEDICATED_INT_MASK(core) GXP_CORE_REG(core, 0x401C)
#define GXP_CORE_REG_ETM_PWRCTL(core) GXP_CORE_REG(core, 0xB020)

#define SYNC_BARRIER_SHADOW_OFFSET 0x800

#define CORE_PD_BASE(_x_)	((_x_) << 2)
#define CORE_PD_COUNT		4

#define TIMER_BASE(_x_)		((_x_) << 12)
#define TIMER_COMPARATOR_OFFSET	0x0
#define TIMER_CONTROL_OFFSET	0x4
#define TIMER_VALUE_OFFSET	0x8
#define TIMER_COUNT		8

/* CMU offset */
#define PLL_CON0_PLL_AUR 0x100
#define PLL_CON0_NOC_USER 0x610

#endif /* __AMALTHEA_CSRS_H__ */