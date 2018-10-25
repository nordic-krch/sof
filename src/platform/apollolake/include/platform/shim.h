/*
 * Copyright (c) 2016, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the Intel Corporation nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 *         Keyon Jie <yang.jie@linux.intel.com>
 */

#ifndef __PLATFORM_SHIM_H__
#define __PLATFORM_SHIM_H__

#include <platform/memory.h>

#ifndef ASSEMBLY
#include <stdint.h>
#endif

/* DSP IPC for Host Registers */
#define IPC_DIPCT		0x00
#define IPC_DIPCTE		0x04
#define IPC_DIPCI		0x08
#define IPC_DIPCIE		0x0c
#define IPC_DIPCCTL		0x10

/* DIPCT */
#define IPC_DIPCT_BUSY		(1 << 31)
#define IPC_DIPCT_MSG_MASK	0x7FFFFFFF

/* DIPCTE */
#define IPC_DIPCTE_MSG_MASK	0x3FFFFFFF

/* DIPCI */
#define IPC_DIPCI_BUSY		(1 << 31)
#define IPC_DIPCI_MSG_MASK	0x7FFFFFFF

/* DIPCIE */
#define IPC_DIPCIE_DONE		(1 << 30)
#define IPC_DIPCIE_MSG_MASK	0x3FFFFFFF

/* DIPCCTL */
#define IPC_DIPCCTL_IPCIDIE	(1 << 1)
#define IPC_DIPCCTL_IPCTBIE	(1 << 0)

#define IPC_DSP_OFFSET		0x10

/* DSP IPC for intra DSP communication */
#define IPC_IDCTFC(x)		(0x0 + x * IPC_DSP_OFFSET)
#define IPC_IDCTEFC(x)		(0x4 + x * IPC_DSP_OFFSET)
#define IPC_IDCITC(x)		(0x8 + x * IPC_DSP_OFFSET)
#define IPC_IDCIETC(x)		(0xc + x * IPC_DSP_OFFSET)
#define IPC_IDCCTL		0x50

/* IDCTFC */
#define IPC_IDCTFC_BUSY		(1 << 31)
#define IPC_IDCTFC_MSG_MASK	0x7FFFFFFF

/* IDCTEFC */
#define IPC_IDCTEFC_MSG_MASK	0x3FFFFFFF

/* IDCITC */
#define IPC_IDCITC_BUSY		(1 << 31)
#define IPC_IDCITC_MSG_MASK	0x7FFFFFFF

/* IDCIETC */
#define IPC_IDCIETC_DONE	(1 << 30)
#define IPC_IDCIETC_MSG_MASK	0x3FFFFFFF

/* IDCCTL */
#define IPC_IDCCTL_IDCIDIE(x)	(0x100 << (x))
#define IPC_IDCCTL_IDCTBIE(x)	(0x1 << (x))

#define IRQ_CPU_OFFSET	0x40

#define REG_IRQ_IL2MSD(xcpu)	(0x0 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL2MCD(xcpu)	(0x4 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL2MD(xcpu)	(0x8 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL2SD(xcpu)	(0xc + (xcpu * IRQ_CPU_OFFSET))

/* all mask valid bits */
#define REG_IRQ_IL2MD_ALL	0x03F181F0

#define REG_IRQ_IL3MSD(xcpu)	(0x10 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL3MCD(xcpu)	(0x14 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL3MD(xcpu)	(0x18 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL3SD(xcpu)	(0x1c + (xcpu * IRQ_CPU_OFFSET))

/* all mask valid bits */
#define REG_IRQ_IL3MD_ALL	0x807F81FF

#define REG_IRQ_IL4MSD(xcpu)	(0x20 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL4MCD(xcpu)	(0x24 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL4MD(xcpu)	(0x28 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL4SD(xcpu)	(0x2c + (xcpu * IRQ_CPU_OFFSET))

/* all mask valid bits */
#define REG_IRQ_IL4MD_ALL	0x807F81FF

#define REG_IRQ_IL5MSD(xcpu)	(0x30 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL5MCD(xcpu)	(0x34 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL5MD(xcpu)	(0x38 + (xcpu * IRQ_CPU_OFFSET))
#define REG_IRQ_IL5SD(xcpu)	(0x3c + (xcpu * IRQ_CPU_OFFSET))

/* all mask valid bits */
#define REG_IRQ_IL5MD_ALL	0xFFFFC0CF

#define REG_IRQ_IL2RSD		0x100
#define REG_IRQ_IL3RSD		0x104
#define REG_IRQ_IL4RSD		0x108
#define REG_IRQ_IL5RSD		0x10c

#define REG_IRQ_LVL5_LP_GPDMA0_MASK		(0xff << 16)
#define REG_IRQ_LVL5_LP_GPDMA1_MASK		(0xff << 24)

/* DSP Shim Registers */
#define SHIM_DSPWC		0x20 /* DSP Wall Clock */
#define SHIM_DSPWCTCS		0x28 /* DSP Wall Clock Timer Control & Status */
#define SHIM_DSPWCT0C		0x30 /* DSP Wall Clock Timer 0 Compare */
#define SHIM_DSPWCT1C		0x38 /* DSP Wall Clock Timer 1 Compare */

#define SHIM_DSPWCTCS_T1T	(0x1 << 5) /* Timer 1 triggered */
#define SHIM_DSPWCTCS_T0T	(0x1 << 4) /* Timer 0 triggered */
#define SHIM_DSPWCTCS_T1A	(0x1 << 1) /* Timer 1 armed */
#define SHIM_DSPWCTCS_T0A	(0x1 << 0) /* Timer 0 armed */

/** \brief Clock control */
#define SHIM_CLKCTL		0x78

/** \brief Clock status */
#define SHIM_CLKSTS		0x7C

/** \brief Request Audio PLL Clock */
#define SHIM_CLKCTL_RAPLLC	BIT(31)

/** \brief Request XTAL Oscillator Clock */
#define SHIM_CLKCTL_RXOSCC	BIT(30)

/** \brief Request Fast RING Oscillator Clock */
#define SHIM_CLKCTL_RFROSCC	BIT(29)

/** \brief LP GPDMA Force Dynamic Clock Gating bits, 0: enable */
#define SHIM_CLKCTL_LPGPDMAFDCGB(x)	BIT(26 + x)

/** \brief DMIC Force Dynamic Clock Gating */
#define SHIM_CLKCTL_DMICFDCGB           BIT(24)

/** \brief I2S Force Dynamic Clock Gating */
#define SHIM_CLKCTL_I2SFDCGB(x)		BIT(20 + x)

/** \brief I2S Extension Force Dynamic Clock Gating */
#define SHIM_CLKCTL_I2SEFDCGB(x)	BIT(18 + x)

/** \brief Tensilica Core Prevent Local Clock Gating */
#define SHIM_CLKCTL_TCPLCG_EN(x)	BIT(16 + x)
#define SHIM_CLKCTL_TCPLCG_DIS(x)	0

/** \brief Core clock PLL divisor */
#define SHIM_CLKCTL_DPCS_MASK(x)	(0x3 << (8 + x * 2))
#define SHIM_CLKCTL_DPCS_DIV1(x)	(0x0 << (8 + x * 2))
#define SHIM_CLKCTL_DPCS_DIV2(x)	(0x1 << (8 + x * 2))
#define SHIM_CLKCTL_DPCS_DIV4(x)	(0x3 << (8 + x * 2))

/** \brief Tensilica Core Prevent Audio PLL Shutdown */
#define SHIM_CLKCTL_TCPAPLLS_EN		BIT(7)
#define SHIM_CLKCTL_TCPAPLLS_DIS	0

/** \brief LP domain clock select, 0: PLL, 1: oscillator */
#define SHIM_CLKCTL_LDCS_XTAL	BIT(5)
#define SHIM_CLKCTL_LDCS_PLL	0

/** \brief HP domain clock select */
#define SHIM_CLKCTL_HDCS	BIT(4)
#define SHIM_CLKCTL_HDCS_XTAL	BIT(4)
#define SHIM_CLKCTL_HDCS_PLL	0

/** \brief LP domain oscillator clock select select, 0: XTAL, 1: Fast RING */
#define SHIM_CLKCTL_LDOCS	BIT(3)

/** \brief HP domain oscillator clock select select, 0: XTAL, 1: Fast RING */
#define SHIM_CLKCTL_HDOCS	BIT(2)

/** \brief LP memory clock PLL divisor, 0: div by 2, 1: div by 4 */
#define SHIM_CLKCTL_LPMPCS_DIV4	BIT(1)
#define SHIM_CLKCTL_LPMPCS_DIV2	0

/** \brief HP memory clock PLL divisor, 0: div by 2, 1: div by 4 */
#define SHIM_CLKCTL_HPMPCS_DIV4	BIT(0)
#define SHIM_CLKCTL_HPMPCS_DIV2	0

#define SHIM_PWRCTL		0x90
#define SHIM_PWRSTS		0x92
#define SHIM_LPSCTL		0x94

/* HP & LP SRAM Power Gating */
#define SHIM_HSPGCTL		0x80
#define SHIM_LSPGCTL		0x84
#define SHIM_SPSREQ		    0xa0

#define SHIM_SPSREQ_RVNNP	(0x1 << 0)

/** \brief LDO Control */
#define SHIM_LDOCTL		0xA4

#define SHIM_LDOCTL_HP_SRAM_MASK	(3 << 0)
#define SHIM_LDOCTL_LP_SRAM_MASK	(3 << 2)
#define SHIM_LDOCTL_HP_SRAM_LDO_ON	(3 << 0)
#define SHIM_LDOCTL_LP_SRAM_LDO_ON	(3 << 2)
#define SHIM_LDOCTL_HP_SRAM_LDO_BYPASS	BIT(0)
#define SHIM_LDOCTL_LP_SRAM_LDO_BYPASS	BIT(2)
#define SHIM_LDOCTL_HP_SRAM_LDO_OFF	(0 << 0)
#define SHIM_LDOCTL_LP_SRAM_LDO_OFF	(0 << 2)

#define SHIM_HSPGISTS		0xb0
#define SHIM_LSPGISTS		0xb4


#define SHIM_LPSCTL_FDSPRUN	(0X1 << 9)
#define SHIM_LPSCTL_FDMARUN	(0X1 << 8)

#define SHIM_L2_MECS		(SHIM_BASE + 0xd0)

#define SHIM_LPGPDMAC(x)	(0x1110 + (2 * x))
#define SHIM_LPGPDMAC_CTLOSEL	(1 << 15)
#define SHIM_LPGPDMAC_CHOSEL	(0xFF)

#define SHIM_DSPIOPO		0x1118
#define SHIM_DSPIOPO_DMICOSEL	(1 << 0)
#define SHIM_DSPIOPO_I2SOSEL	(0x3F << 8)

#define SHIM_GENO		0x111C
#define SHIM_GENO_SHIMOSEL	(1 << 0)
#define SHIM_GENO_MDIVOSEL	(1 << 1)
#define SHIM_GENO_DIOPTOSEL	(1 << 2)

#define SHIM_L2_CACHE_CTRL	(SHIM_BASE + 0x500)
#define SHIM_L2_PREF_CFG	(SHIM_BASE + 0x508)
#define SHIM_L2_CACHE_PREF	(SHIM_BASE + 0x510)

#define SHIM_SVCFG			0xF4
#define SHIM_SVCFG_FORCE_L1_EXIT	(0x1 << 1)


/* host windows */
#define DMWBA(x)		(HOST_WIN_BASE(x) + 0x0)
#define DMWLO(x)		(HOST_WIN_BASE(x) + 0x4)

#define DMWBA_ENABLE		(1 << 0)
#define DMWBA_READONLY		(1 << 1)

#ifndef ASSEMBLY

static inline uint32_t shim_read(uint32_t reg)
{
	return *((volatile uint32_t*)(SHIM_BASE + reg));
}

static inline void shim_write(uint32_t reg, uint32_t val)
{
	*((volatile uint32_t*)(SHIM_BASE + reg)) = val;
}

static inline uint64_t shim_read64(uint32_t reg)
{
	return *((volatile uint64_t*)(SHIM_BASE + reg));
}

static inline void shim_write64(uint32_t reg, uint64_t val)
{
	*((volatile uint64_t*)(SHIM_BASE + reg)) = val;
}

static inline uint32_t sw_reg_read(uint32_t reg)
{
	return *((volatile uint32_t*)((SRAM_SW_REG_BASE -
		SRAM_ALIAS_OFFSET) + reg));
}

static inline void sw_reg_write(uint32_t reg, uint32_t val)
{
	*((volatile uint32_t*)((SRAM_SW_REG_BASE -
		SRAM_ALIAS_OFFSET) + reg)) = val;
}

static inline uint32_t mn_reg_read(uint32_t reg)
{
	return *((volatile uint32_t*)(MN_BASE + reg));
}

static inline void mn_reg_write(uint32_t reg, uint32_t val)
{
	*((volatile uint32_t*)(MN_BASE + reg)) = val;
}

static inline uint32_t irq_read(uint32_t reg)
{
	return *((volatile uint32_t*)(IRQ_BASE + reg));
}

static inline void irq_write(uint32_t reg, uint32_t val)
{
	*((volatile uint32_t*)(IRQ_BASE + reg)) = val;
}

static inline uint32_t ipc_read(uint32_t reg)
{
	return *((volatile uint32_t*)(IPC_HOST_BASE + reg));
}

static inline void ipc_write(uint32_t reg, uint32_t val)
{
	*((volatile uint32_t*)(IPC_HOST_BASE + reg)) = val;
}

static inline uint32_t idc_read(uint32_t reg, uint32_t core_id)
{
	return *((volatile uint32_t*)(IPC_DSP_BASE(core_id) + reg));
}

static inline void idc_write(uint32_t reg, uint32_t core_id, uint32_t val)
{
	*((volatile uint32_t*)(IPC_DSP_BASE(core_id) + reg)) = val;
}
#endif

#endif
