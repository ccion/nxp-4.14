/*
 * Copyright 2018 NXP
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/of_address.h>
#include <linux/clk.h>
#include <dt-bindings/clock/s32gen1-clock.h>

#include "clk.h"
#include "mc_cgm.h"

static void __iomem *mc_cgm0_base;
static void *armpll;
static void *periphpll;
static void *ddrpll;
static void *accelpll;
static void *aurorapll;
static void *armdfs;
static void *periphdfs;

DEFINE_SPINLOCK(s32gen1_lock);

/* sources for multiplexer clocks, this is used multiple times */
PNAME(osc_sels) = {"firc", "fxosc", };
static u32 osc_mux_ids[] = {
	PLLDIG_PLLCLKMUX_REFCLKSEL_SET_FIRC,
	PLLDIG_PLLCLKMUX_REFCLKSEL_SET_XOSC,
};

PNAME(lin_sels) = {"firc", "fxosc", "periphpll_phi3", };
static u32 lin_mux_idx[] = {
	MC_CGM_MUXn_CSC_SEL_FIRC, MC_CGM_MUXn_CSC_SEL_FXOSC,
	MC_CGM_MUXn_CSC_SEL_PERIPH_PLL_PHI3,
};

PNAME(dspi_sels) = {"firc", "periphpll_phi7", };
static u32 dspi_mux_idx[] = {
	MC_CGM_MUXn_CSC_SEL_FIRC, MC_CGM_MUXn_CSC_SEL_PERIPH_PLL_PHI7,
};

PNAME(xbar_sels) = {"firc", "armpll_dfs1", };
static u32 xbar_mux_idx[] = {
	MC_CGM_MUXn_CSC_SEL_FIRC,
	MC_CGM_MUXn_CSC_SEL_ARM_PLL_DFS1,
};

static struct clk *clk[S32GEN1_CLK_END];
static struct clk_onecell_data clk_data;

static u32 share_count_linflex0gate, share_count_linflex1gate,
	   share_count_linflex2gate;

static void __init s32gen1_clocks_init(struct device_node *clocking_node)
{
	struct device_node *np;
	u32 armpll_pllodiv[] = {
		ARM_PLLDIG_PLLODIV0, ARM_PLLDIG_PLLODIV1
	};
	u32 periphpll_pllodiv[] = {
		PERIPH_PLLDIG_PLLODIV0, PERIPH_PLLDIG_PLLODIV1,
		PERIPH_PLLDIG_PLLODIV2, PERIPH_PLLDIG_PLLODIV3,
		PERIPH_PLLDIG_PLLODIV4, PERIPH_PLLDIG_PLLODIV5,
		PERIPH_PLLDIG_PLLODIV6
	};
	u32 ddrpll_pllodiv[] = { DDR_PLLDIG_PLLODIV0 };
	u32 accelpll_pllodiv[] = {
		ACCEL_PLLDIG_PLLODIV0, ACCEL_PLLDIG_PLLODIV1
	};
	u32 aurorapll_pllodiv[] = { AURORA_PLLDIG_PLLODIV0 };

	clk[S32GEN1_CLK_DUMMY] = s32_clk_fixed("dummy", 0);
	clk[S32GEN1_CLK_FXOSC] = s32_obtain_fixed_clock("fxosc", 0);
	clk[S32GEN1_CLK_FIRC] = s32_obtain_fixed_clock("firc", 0);

	np = clocking_node;
	armpll = of_iomap(np, 0);
	if (WARN_ON(!armpll))
		return;

	periphpll = of_iomap(np, 1);
	if (WARN_ON(!periphpll))
		return;

	accelpll = of_iomap(np, 2);
	if (WARN_ON(!accelpll))
		return;

	ddrpll = of_iomap(np, 3);
	if (WARN_ON(!ddrpll))
		return;

	aurorapll = of_iomap(np, 4);
	if (WARN_ON(!accelpll))
		return;

	armdfs = of_iomap(np, 5);
	if (WARN_ON(!accelpll))
		return;

	periphdfs = of_iomap(np, 6);
	if (WARN_ON(!accelpll))
		return;

	np = of_find_compatible_node(NULL, NULL, "fsl,s32gen1-mc_cgm0");
	mc_cgm0_base = of_iomap(np, 0);
	if (WARN_ON(!mc_cgm0_base))
		return;

	clk[S32GEN1_CLK_ARMPLL_SRC_SEL] = s32_clk_mux_table("armpll_sel",
		PLLDIG_PLLCLKMUX(armpll),
		PLLDIG_PLLCLKMUX_REFCLKSEL_OFFSET,
		PLLDIG_PLLCLKMUX_REFCLKSEL_SIZE,
		osc_sels, ARRAY_SIZE(osc_sels), osc_mux_ids, &s32gen1_lock);

	clk[S32GEN1_CLK_PERIPHPLL_SRC_SEL] = s32_clk_mux_table("periphpll_sel",
		PLLDIG_PLLCLKMUX(periphpll),
		PLLDIG_PLLCLKMUX_REFCLKSEL_OFFSET,
		PLLDIG_PLLCLKMUX_REFCLKSEL_SIZE,
		osc_sels, ARRAY_SIZE(osc_sels), osc_mux_ids, &s32gen1_lock);

	clk[S32GEN1_CLK_DDRPLL_SRC_SEL] = s32_clk_mux_table("ddrpll_sel",
		PLLDIG_PLLCLKMUX(ddrpll),
		PLLDIG_PLLCLKMUX_REFCLKSEL_OFFSET,
		PLLDIG_PLLCLKMUX_REFCLKSEL_SIZE,
		osc_sels, ARRAY_SIZE(osc_sels), osc_mux_ids, &s32gen1_lock);

	clk[S32GEN1_CLK_ACCELPLL_SRC_SEL] = s32_clk_mux_table("accelpll_sel",
		PLLDIG_PLLCLKMUX(accelpll),
		PLLDIG_PLLCLKMUX_REFCLKSEL_OFFSET,
		PLLDIG_PLLCLKMUX_REFCLKSEL_SIZE,
		osc_sels, ARRAY_SIZE(osc_sels), osc_mux_ids, &s32gen1_lock);

	clk[S32GEN1_CLK_AURORAPLL_SRC_SEL] = s32_clk_mux_table("aurorapll_sel",
		PLLDIG_PLLCLKMUX(aurorapll),
		PLLDIG_PLLCLKMUX_REFCLKSEL_OFFSET,
		PLLDIG_PLLCLKMUX_REFCLKSEL_SIZE,
		osc_sels, ARRAY_SIZE(osc_sels), osc_mux_ids, &s32gen1_lock);

	/* ARM_PLL */
	clk[S32GEN1_CLK_ARMPLL_VCO] = s32gen1_clk_plldig(S32GEN1_PLLDIG_ARM,
		"armpll_vco", "armpll_sel", armpll,
		ARMPLL_PLLDIG_PLLDV_MFI, ARMPLL_PLLDIG_PLLDV_MFN,
		armpll_pllodiv, ARMPLL_PHI_Nr);

	clk[S32GEN1_CLK_ARMPLL_PHI0] = s32gen1_clk_plldig_phi(
		S32GEN1_PLLDIG_ARM, "armpll_phi0", "armpll_vco", armpll, 0);

	clk[S32GEN1_CLK_ARMPLL_PHI1] = s32gen1_clk_plldig_phi(
		S32GEN1_PLLDIG_ARM, "armpll_phi1", "armpll_vco", armpll, 1);

	clk[S32GEN1_CLK_ARMPLL_DFS1] = s32gen1_clk_dfs(S32GEN1_PLLDIG_ARM,
		 "armpll_dfs1", "armpll_vco",
		 armdfs, 1);

	clk[S32GEN1_CLK_ARMPLL_DFS2] = s32gen1_clk_dfs(S32GEN1_PLLDIG_ARM,
		 "armpll_dfs2", "armpll_vco",
		 armdfs, 2);

	clk[S32GEN1_CLK_ARMPLL_DFS3] = s32gen1_clk_dfs(S32GEN1_PLLDIG_ARM,
		 "armpll_dfs3", "armpll_vco",
		 armdfs, 3);

	clk[S32GEN1_CLK_ARMPLL_DFS4] = s32gen1_clk_dfs(S32GEN1_PLLDIG_ARM,
		 "armpll_dfs4", "armpll_vco",
		 armdfs, 4);

	clk[S32GEN1_CLK_ARMPLL_DFS5] = s32gen1_clk_dfs(S32GEN1_PLLDIG_ARM,
		 "armpll_dfs5", "armpll_vco",
		 armdfs, 5);

	clk[S32GEN1_CLK_ARMPLL_DFS6] = s32gen1_clk_dfs(S32GEN1_PLLDIG_ARM,
		 "armpll_dfs6", "armpll_vco",
		 armdfs, 6);

	/* XBAR CLKS */
	clk[S32GEN1_CLK_XBAR] = s32_clk_mux_table("xbar",
		CGM_MUXn_CSC(mc_cgm0_base, 0),
		MC_CGM_MUXn_CSC_SELCTL_OFFSET,
		MC_CGM_MUXn_CSC_SELCTL_SIZE,
		xbar_sels, ARRAY_SIZE(xbar_sels), xbar_mux_idx, &s32gen1_lock);

	clk[S32GEN1_CLK_XBAR_DIV2] = s32_clk_fixed_factor("xbar_div2",
		"xbar", 1, 2);
	clk[S32GEN1_CLK_XBAR_DIV3] = s32_clk_fixed_factor("xbar_div3",
		"xbar", 1, 3);
	clk[S32GEN1_CLK_XBAR_DIV4] = s32_clk_fixed_factor("xbar_div4",
		"xbar", 1, 4);
	clk[S32GEN1_CLK_SBSW] = s32_clk_fixed_factor("sbsw",
		"xbar", 1, 6);

	/* PERIPH_PLL */
	clk[S32GEN1_CLK_PERIPHPLL_VCO] = s32gen1_clk_plldig(
		S32GEN1_PLLDIG_PERIPH, "periphpll_vco", "periphpll_sel",
		periphpll, PERIPHPLL_PLLDIG_PLLDV_MFI,
		PERIPHPLL_PLLDIG_PLLDV_MFN, periphpll_pllodiv,
		PERIPHPLL_PHI_Nr);

	clk[S32GEN1_CLK_PERIPHPLL_PHI0] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi0", "periphpll_vco",
		periphpll, 0);

	clk[S32GEN1_CLK_PERIPHPLL_PHI1] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi1", "periphpll_vco",
		periphpll, 1);

	clk[S32GEN1_CLK_PERIPHPLL_PHI2] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi2", "periphpll_vco",
		periphpll, 2);

	clk[S32GEN1_CLK_PERIPHPLL_PHI3] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi3", "periphpll_vco",
		periphpll, 3);

	clk[S32GEN1_CLK_PERIPHPLL_PHI4] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi4", "periphpll_vco",
		periphpll, 4);

	clk[S32GEN1_CLK_PERIPHPLL_PHI5] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi5", "periphpll_vco",
		periphpll, 5);

	clk[S32GEN1_CLK_PERIPHPLL_PHI6] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi6", "periphpll_vco",
		periphpll, 6);

	clk[S32GEN1_CLK_PERIPHPLL_PHI7] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_PERIPH,
		"periphpll_phi7", "periphpll_vco",
		periphpll, 7);

	clk[S32GEN1_CLK_PERIPHPLL_DFS1] = s32gen1_clk_dfs(S32GEN1_PLLDIG_PERIPH,
		 "periphll_dfs1", "periphpll_vco",
		 periphdfs, 1);

	clk[S32GEN1_CLK_PERIPHPLL_DFS2] = s32gen1_clk_dfs(S32GEN1_PLLDIG_PERIPH,
		 "periphll_dfs2", "periphpll_vco",
		 periphdfs, 2);

	clk[S32GEN1_CLK_PERIPHPLL_DFS3] = s32gen1_clk_dfs(S32GEN1_PLLDIG_PERIPH,
		 "periphll_dfs3", "periphpll_vco",
		 periphdfs, 3);

	clk[S32GEN1_CLK_PERIPHPLL_DFS4] = s32gen1_clk_dfs(S32GEN1_PLLDIG_PERIPH,
		 "periphll_dfs4", "periphpll_vco",
		 periphdfs, 4);

	clk[S32GEN1_CLK_PERIPHPLL_DFS5] = s32gen1_clk_dfs(S32GEN1_PLLDIG_PERIPH,
		 "periphll_dfs5", "periphpll_vco",
		 periphdfs, 5);

	clk[S32GEN1_CLK_PERIPHPLL_DFS6] = s32gen1_clk_dfs(S32GEN1_PLLDIG_PERIPH,
		 "periphll_dfs6", "periphpll_vco",
		 periphdfs, 6);

	/* Lin Clock */
	clk[S32GEN1_CLK_LIN_BAUD] = s32_clk_mux_table("lin_baud",
		CGM_MUXn_CSC(mc_cgm0_base, 8),
		MC_CGM_MUXn_CSC_SELCTL_OFFSET,
		MC_CGM_MUXn_CSC_SELCTL_SIZE,
		lin_sels, ARRAY_SIZE(lin_sels), lin_mux_idx, &s32gen1_lock);

	clk[S32GEN1_CLK_LIN] = s32_clk_fixed_factor("lin",
		"lin_baud", 1, 2);

	clk[S32GEN1_CLK_LIN0_BAUD]  = s32gen1_clk_gate2_shared("lin0_baud",
		"lin_baud", NULL, 0, 0, 1,
		&share_count_linflex0gate, &s32gen1_lock);
	clk[S32GEN1_CLK_LIN0] = s32gen1_clk_gate2_shared("lin0",
		"lin", NULL, 0, 0, 1,
		&share_count_linflex0gate, &s32gen1_lock);
	clk[S32GEN1_CLK_LIN1_BAUD]  = s32gen1_clk_gate2_shared("lin1_baud",
		"lin_baud", NULL, 0, 0, 1,
		&share_count_linflex1gate, &s32gen1_lock);
	clk[S32GEN1_CLK_LIN1] = s32gen1_clk_gate2_shared("lin1",
		"lin", NULL, 0, 0, 1,
		&share_count_linflex1gate, &s32gen1_lock);
	clk[S32GEN1_CLK_LIN2_BAUD]  = s32gen1_clk_gate2_shared("lin2_baud",
		"lin_baud", NULL, 0, 0, 1,
		&share_count_linflex2gate, &s32gen1_lock);
	clk[S32GEN1_CLK_LIN2] = s32gen1_clk_gate2_shared("lin2",
		"lin", NULL, 0, 0, 1,
		&share_count_linflex2gate, &s32gen1_lock);

	/* DSPI Clock */
	clk[S32GEN1_CLK_DSPI] = s32_clk_mux_table("spi_sel",
		CGM_MUXn_CSC(mc_cgm0_base, 16),
		MC_CGM_MUXn_CSC_SELCTL_OFFSET,
		MC_CGM_MUXn_CSC_SELCTL_SIZE,
		dspi_sels, ARRAY_SIZE(dspi_sels), dspi_mux_idx, &s32gen1_lock);

	clk[S32GEN1_CLK_SPI0]  = s32gen1_clk_gate2("spi0",
		"spi_sel", NULL, 0, 0, 1, &s32gen1_lock);
	clk[S32GEN1_CLK_SPI1]  = s32gen1_clk_gate2("spi1",
		"spi_sel", NULL, 0, 0, 1, &s32gen1_lock);
	clk[S32GEN1_CLK_SPI2]  = s32gen1_clk_gate2("spi2",
		"spi_sel", NULL, 0, 0, 1, &s32gen1_lock);
	clk[S32GEN1_CLK_SPI3]  = s32gen1_clk_gate2("spi3",
		"spi_sel", NULL, 0, 0, 1, &s32gen1_lock);
	clk[S32GEN1_CLK_SPI4]  = s32gen1_clk_gate2("spi4",
		"spi_sel", NULL, 0, 0, 1, &s32gen1_lock);
	clk[S32GEN1_CLK_SPI5]  = s32gen1_clk_gate2("spi5",
		"spi_sel", NULL, 0, 0, 1, &s32gen1_lock);

	/* DDR_PLL */
	clk[S32GEN1_CLK_DDRPLL_VCO] = s32gen1_clk_plldig(S32GEN1_PLLDIG_DDR,
		"ddrpll_vco", "ddrpll_sel", ddrpll,
		DDRPLL_PLLDIG_PLLDV_MFI, DDRPLL_PLLDIG_PLLDV_MFN,
		ddrpll_pllodiv, DDRPLL_PHI_Nr);

	clk[S32GEN1_CLK_DDRPLL_PHI0] = s32gen1_clk_plldig_phi(
		S32GEN1_PLLDIG_DDR, "ddrpll_phi0", "ddrpll_vco", ddrpll, 0);

	/* ACCEL_PLL */
	clk[S32GEN1_CLK_ACCELPLL_VCO] = s32gen1_clk_plldig(S32GEN1_PLLDIG_ACCEL,
		"accelpll_vco", "accelpll_sel", accelpll,
		ACCELPLL_PLLDIG_PLLDV_MFI, ACCELPLL_PLLDIG_PLLDV_MFN,
		accelpll_pllodiv, ACCELPLL_PHI_Nr);

	clk[S32GEN1_CLK_ACCELPLL_PHI0] = s32gen1_clk_plldig_phi(
		S32GEN1_PLLDIG_ACCEL, "accelpll_phi0", "accelpll_vco",
		accelpll, 0);

	clk[S32GEN1_CLK_ACCELPLL_PHI1] = s32gen1_clk_plldig_phi(
		S32GEN1_PLLDIG_ACCEL, "accelpll_phi1", "accelpll_vco",
		accelpll, 1);

	/* AURORA_PLL */
	clk[S32GEN1_CLK_AURORAPLL_VCO] = s32gen1_clk_plldig(
		S32GEN1_PLLDIG_AURORA, "aurorapll_vco", "aurorapll_sel",
		aurorapll, AURORAPLL_PLLDIG_PLLDV_MFI,
		AURORAPLL_PLLDIG_PLLDV_MFN,
		aurorapll_pllodiv, AURORAPLL_PHI_Nr);

	clk[S32GEN1_CLK_AURORAPLL_PHI0] =
		s32gen1_clk_plldig_phi(S32GEN1_PLLDIG_AURORA,
		"aurorapll_phi0", "aurorapll_vco",
		aurorapll, 0);

	/* Add the clocks to provider list */
	clk_data.clks = clk;
	clk_data.clk_num = ARRAY_SIZE(clk);
	of_clk_add_provider(clocking_node, of_clk_src_onecell_get, &clk_data);
}

static void __init s32v344_clocks_init(struct device_node *mc_cgm0_node)
{
	s32gen1_clocks_init(mc_cgm0_node);
}

static void __init s32g275_clocks_init(struct device_node *mc_cgm0_node)
{
	s32gen1_clocks_init(mc_cgm0_node);
}

static void __init s32r45x_clocks_init(struct device_node *mc_cgm0_node)
{
	s32gen1_clocks_init(mc_cgm0_node);
}

CLK_OF_DECLARE(S32V344, "fsl,s32v344-clocking", s32v344_clocks_init);
CLK_OF_DECLARE(S32G275, "fsl,s32g275-clocking", s32g275_clocks_init);
CLK_OF_DECLARE(S32R45X, "fsl,s32r45x-clocking", s32r45x_clocks_init);
