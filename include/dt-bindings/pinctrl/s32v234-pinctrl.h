/*
 * Copyright 2015-2016 by Freescale Semiconductor
 * Copyright 2016-2017 NXP
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __DT_BINDINGS_S32V234_PINCTRL_H__
#define __DT_BINDINGS_S32V234_PINCTRL_H__

/*
 * Use to set PAD control
 */
#define PAD_CTL_DCYLE_TRIM_OFS      (22)
#define PAD_CTL_DCYLE_TRIM_NONE     (0 << PAD_CTL_DCYLE_TRIM_OFS)
#define PAD_CTL_DCYLE_TRIM_LEFT     (1 << PAD_CTL_DCYLE_TRIM_OFS)
#define PAD_CTL_DCYLE_TRIM_RIGHT    (2 << PAD_CTL_DCYLE_TRIM_OFS)

#define PAD_CTL_OBE         (1 << 21)
#define PAD_CTL_ODE         (1 << 20)
#define PAD_CTL_IBE         (1 << 19)
#define PAD_CTL_HYS         (1 << 18)
#define PAD_CTL_INV         (1 << 17)
#define PAD_CTL_PKE         (1 << 16)

#define PAD_CTL_SRE_OFS             (14)
#define PAD_CTL_SRE_LOW_50HZ        (0 << PAD_CTL_SRE_OFS)
#define PAD_CTL_SRE_LOW_100MHZ      (1 << PAD_CTL_SRE_OFS)
/* The manual reports the same value for SRE = 01 and SRE = 10 */
#define PAD_CTL_SRE_HIGH_100MHZ     (2 << PAD_CTL_SRE_OFS)
#define PAD_CTL_SRE_HIGH_200MHZ     (3 << PAD_CTL_SRE_OFS)

#define PAD_CTL_PUE             (1 << 13)

#define PAD_CTL_PUS_OFS         (11)
#define PAD_CTL_PUS_100K_DOWN   (0 << PAD_CTL_PUS_OFS)
#define PAD_CTL_PUS_50K_UP      (1 << PAD_CTL_PUS_OFS)
#define PAD_CTL_PUS_100K_UP     (2 << PAD_CTL_PUS_OFS)
#define PAD_CTL_PUS_33K_UP      (3 << PAD_CTL_PUS_OFS)
#define PAD_CTL_PUS_MASK        (3 << PAD_CTL_PUS_OFS)

#define PAD_CTL_DSE_OFS         (8)
#define PAD_CTL_DSE_OUT_DISABLE (0 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_240         (1 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_120         (2 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_80          (3 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_60          (4 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_48          (5 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_40          (6 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_34          (7 << PAD_CTL_DSE_OFS)
#define PAD_CTL_DSE_MASK        (7 << PAD_CTL_DSE_OFS)

#define PAD_CTL_CRPOINT_TRIM    (3 << 6)

#define PAD_CTL_SMC             (1 << 5)

#define PAD_CTL_MUX_MODE_ALT0   (0)
#define PAD_CTL_MUX_MODE_ALT1   (1)
#define PAD_CTL_MUX_MODE_ALT2   (2)
#define PAD_CTL_MUX_MODE_ALT3   (3)
#define PAD_CTL_MUX_MODE_ALT4   (4)
#define PAD_CTL_MUX_MODE_ALT5   (5)
#define PAD_CTL_MUX_MODE_ALT6   (6)
#define PAD_CTL_MUX_MODE_ALT7   (7)
#define PAD_CTL_MUX_MODE_MASK   (0xF)


/* UART configuration */
#define PAD_CTL_UART_TX         (PAD_CTL_OBE | PAD_CTL_PUS_100K_UP | PAD_CTL_DSE_60 |\
                                PAD_CTL_SRE_LOW_100MHZ | PAD_CTL_MUX_MODE_ALT1)
#define PAD_CTL_UART_RX_MSCR    (PAD_CTL_PUE | PAD_CTL_IBE | PAD_CTL_DCYLE_TRIM_RIGHT)
#define PAD_CTL_UART_RX_IMCR    (PAD_CTL_MUX_MODE_ALT2)

/* CAN0 configuration */
#define PAD_CTL_CAN_FD0_TX      (PAD_CTL_OBE | PAD_CTL_PUS_50K_UP | PAD_CTL_PUE |\
								PAD_CTL_DSE_34 | PAD_CTL_MUX_MODE_ALT1)
#define PAD_CTL_CAN_FD0_RX_MSCR (PAD_CTL_PUE | PAD_CTL_IBE | PAD_CTL_PUS_50K_UP)
#define PAD_CTL_CAN_FD0_RX_IMCR (PAD_CTL_MUX_MODE_ALT2)

/* CAN1 configuration */
#define PAD_CTL_CAN_FD1_TX      (PAD_CTL_OBE | PAD_CTL_PUS_50K_UP | PAD_CTL_PUE |\
								PAD_CTL_DSE_34 | PAD_CTL_MUX_MODE_ALT1)
#define PAD_CTL_CAN_FD1_RX_MSCR (PAD_CTL_PUE | PAD_CTL_IBE | PAD_CTL_PUS_50K_UP)
#define PAD_CTL_CAN_FD1_RX_IMCR (PAD_CTL_MUX_MODE_ALT3)

/* USDHC configuration  */
#define PAD_CTL_USDHC_BASE      (PAD_CTL_SRE_HIGH_200MHZ | PAD_CTL_OBE | \
                                PAD_CTL_DSE_34 | PAD_CTL_PKE |  \
                                PAD_CTL_IBE | PAD_CTL_PUS_100K_UP | PAD_CTL_PUE)
#define PAD_CTL_USDHC_CMD       (PAD_CTL_USDHC_BASE | PAD_CTL_MUX_MODE_ALT1)
#define PAD_CTL_USDHC_CLK       (PAD_CTL_USDHC_BASE | PAD_CTL_MUX_MODE_ALT2)
#define PAD_CTL_USDHC_DAT0_3    (PAD_CTL_USDHC_BASE | PAD_CTL_MUX_MODE_ALT2)
#define PAD_CTL_USDHC_DAT4_7    (PAD_CTL_USDHC_BASE | PAD_CTL_MUX_MODE_ALT3)

/* QSPI configuration  */
#define PAD_CTL_QSPI_BASE         (PAD_CTL_SRE_HIGH_200MHZ | PAD_CTL_OBE | \
                                  PAD_CTL_DSE_34 | PAD_CTL_IBE)
#define PAD_CTL_QSPI_CLK_BASE     (PAD_CTL_SRE_HIGH_200MHZ | PAD_CTL_DSE_34 | \
                                  PAD_CTL_PUS_100K_UP | PAD_CTL_OBE)
#define PAD_CTL_QSPI_CK2_MUX      PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_A_SCK_MUX    PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_B_SCK_MUX    PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_A_CS0_MUX    PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_B_CS0_MUX    PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_A_CS1_MUX    PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_B_CS1_MUX    PAD_CTL_MUX_MODE_ALT1
#define PAD_CTL_QSPI_A_DQS        (PAD_CTL_SRE_HIGH_200MHZ | PAD_CTL_IBE | \
                                  PAD_CTL_PUS_100K_DOWN | PAD_CTL_PUE | \
                                  PAD_CTL_PKE)
#define PAD_CTL_QSPI_A_DATA0_3    (PAD_CTL_QSPI_BASE | PAD_CTL_MUX_MODE_ALT1)
#define PAD_CTL_QSPI_A_DATA4_7    (PAD_CTL_QSPI_BASE | PAD_CTL_MUX_MODE_ALT2)
#define PAD_CTL_QSPI_B_DATA0_3    (PAD_CTL_QSPI_BASE | PAD_CTL_MUX_MODE_ALT1)

/* EIRQ configuration */
#define PAD_CTL_EIRQ            (PAD_CTL_MUX_MODE_ALT2 | PAD_CTL_IBE | \
				 PAD_CTL_PKE | PAD_CTL_PUS_100K_DOWN)

/* I2C0 - Serial Data Input */
#define PAD_CTL_I2C0_MSCR_SDA   (PAD_CTL_MUX_MODE_ALT2 | PAD_CTL_OBE | PAD_CTL_IBE | \
                                PAD_CTL_ODE | PAD_CTL_DSE_34)
#define PAD_CTL_I2C0_IMCR_SDA   (PAD_CTL_MUX_MODE_ALT3)

/* I2C0 - Serial Clock Input */
#define  PAD_CTL_I2C0_MSCR_SCLK (PAD_CTL_MUX_MODE_ALT2 | PAD_CTL_OBE | PAD_CTL_IBE | \
                                PAD_CTL_ODE | PAD_CTL_DSE_34)
#define PAD_CTL_I2C0_IMCR_SCLK  (PAD_CTL_MUX_MODE_ALT3)

/* I2C1 - Serial Data Input */
#define  PAD_CTL_I2C1_MSCR_SDA  (PAD_CTL_MUX_MODE_ALT2 | PAD_CTL_OBE | PAD_CTL_IBE | \
                                PAD_CTL_ODE | PAD_CTL_DSE_34)
#define PAD_CTL_I2C1_IMCR_SDA   (PAD_CTL_MUX_MODE_ALT3)

/* I2C1 - Serial Clock Input */
#define  PAD_CTL_I2C1_MSCR_SCLK (PAD_CTL_MUX_MODE_ALT2 | PAD_CTL_OBE | PAD_CTL_IBE | \
                                PAD_CTL_ODE | PAD_CTL_DSE_34)
#define PAD_CTL_I2C1_IMCR_SCLK  (PAD_CTL_MUX_MODE_ALT3)

/* I2C2 - Serial Data Input */
#define  PAD_CTL_I2C2_MSCR_SDA  (PAD_CTL_MUX_MODE_ALT1 | PAD_CTL_OBE | PAD_CTL_IBE | \
                                PAD_CTL_ODE | PAD_CTL_DSE_34)
#define PAD_CTL_I2C2_IMCR_SDA   (PAD_CTL_MUX_MODE_ALT2)

/* I2C2 - Serial Clock Input */
#define  PAD_CTL_I2C2_MSCR_SCLK (PAD_CTL_MUX_MODE_ALT1 | PAD_CTL_OBE | PAD_CTL_IBE | \
                                PAD_CTL_ODE | PAD_CTL_DSE_34)
#define PAD_CTL_I2C2_IMCR_SCLK  (PAD_CTL_MUX_MODE_ALT2)

/* ENET CFG1 = 0x203701 */
#define PAD_CTL_ENET_CFG1       (PAD_CTL_DSE_34 | PAD_CTL_PUS_100K_UP | PAD_CTL_PUE | \
                                PAD_CTL_OBE | PAD_CTL_MUX_MODE_ALT1)

/* ENET CFG2 = 0x20c701 */
#define PAD_CTL_ENET_CFG2       (PAD_CTL_DSE_34 | PAD_CTL_SRE_HIGH_200MHZ | \
                                PAD_CTL_OBE | PAD_CTL_MUX_MODE_ALT1)

/* ENET CFG3 = 0x28c701 */
#define PAD_CTL_ENET_CFG3       (PAD_CTL_DSE_34 | PAD_CTL_SRE_HIGH_200MHZ | \
                                PAD_CTL_OBE | PAD_CTL_IBE | PAD_CTL_MUX_MODE_ALT1)

/* ENET CFG7 = 0x8c700 */
#define PAD_CTL_ENET_CFG4       (PAD_CTL_DSE_34 | PAD_CTL_SRE_HIGH_200MHZ | PAD_CTL_IBE)

/* DCU CFG = 0x20C101 */
#define PAD_CTL_DCU_CFG		(PAD_CTL_DSE_80 | PAD_CTL_SRE_HIGH_200MHZ | \
				PAD_CTL_OBE | PAD_CTL_IBE | \
				PAD_CTL_MUX_MODE_ALT1)

#define PAD_CTL_DCU_CLK_CFG_DSE_DISABLE	(PAD_CTL_SRE_HIGH_200MHZ | \
					PAD_CTL_OBE | PAD_CTL_IBE | \
					PAD_CTL_MUX_MODE_ALT1)

/* VIU IMCR = 0x00000002 */
#define PAD_CTL_VIU_CFG		(PAD_CTL_MUX_MODE_ALT2)

/* VIU MSCR = 0x00000002 */
#define PAD_CTL_VIU_IBE		(PAD_CTL_IBE)

/* SPI 0-3 */
#define PAD_CTL_SPI_MSCR_CSx	 \
				(PAD_CTL_OBE | PAD_CTL_PUS_100K_UP | \
				 PAD_CTL_DSE_34 | PAD_CTL_PUE)

#define PAD_CTL_SPI_MSCR_SCK   (PAD_CTL_OBE | \
				PAD_CTL_DSE_34 | \
				PAD_CTL_MUX_MODE_ALT1)

#define PAD_CTL_SPI_MSCR_SOUT	(PAD_CTL_OBE | PAD_CTL_DSE_34 |\
				 PAD_CTL_MUX_MODE_ALT1)

#define PAD_CTL_SPI_MSCR_SIN	(PAD_CTL_PUE | PAD_CTL_IBE | \
				 PAD_CTL_PUS_50K_UP)

#define PAD_CTL_SPI_IMCR_SIN	(PAD_CTL_MUX_MODE_ALT2)

/* Format of pins: MSCR_IDX PAD_CONFIGURATION If you know the IMCR_IDX
 * instead of MSCR_IDX, add 512 to it as the Reference Manual states.
 */

/* UART configuration */
#define S32V234_PAD_PA12__UART0_TXD_OUT     12  PAD_CTL_UART_TX
#define S32V234_PAD_PA11__UART0_RXD_IN      712 PAD_CTL_UART_RX_IMCR

#define S32V234_PAD_PA14__UART1_TXD_OUT     14  PAD_CTL_UART_TX
#define S32V234_PAD_PA13__UART1_RXD_IN      714 PAD_CTL_UART_RX_IMCR

/* CAN0 configuration */
#define S32V234_PAD_PA2__CAN_FD0_TXD        2   PAD_CTL_CAN_FD0_TX
#define S32V234_PAD_PA3__CAN_FD0_RXD_OUT    3   PAD_CTL_CAN_FD0_RX_MSCR
#define S32V234_PAD_PA3__CAN_FD0_RXD_IN     700 PAD_CTL_CAN_FD0_RX_IMCR

/* CAN1 configuration */
#define S32V234_PAD_PA4__CAN_FD1_TXD        4  PAD_CTL_CAN_FD1_TX
#define S32V234_PAD_PA5__CAN_FD1_RXD_OUT    5  PAD_CTL_CAN_FD1_RX_MSCR
#define S32V234_PAD_PA5__CAN_FD1_RXD_IN     701 PAD_CTL_CAN_FD1_RX_IMCR

/* uSDHC configuration */
#define S32V234_PAD_PK6__USDHC_CLK_OUT      150 PAD_CTL_USDHC_CLK
#define S32V234_PAD_PK6__USDHC_CLK_IN       902 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PK7__USDHC_CMD_OUT      151 PAD_CTL_USDHC_CMD
#define S32V234_PAD_PK7__USDHC_CMD_IN       901 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PK8__USDHC_DAT0_OUT     152 PAD_CTL_USDHC_DAT0_3
#define S32V234_PAD_PK8__USDHC_DAT0_IN      903 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PK9__USDHC_DAT1_OUT     153 PAD_CTL_USDHC_DAT0_3
#define S32V234_PAD_PK9__USDHC_DAT1_IN      904 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PK10__USDHC_DAT2_OUT    154 PAD_CTL_USDHC_DAT0_3
#define S32V234_PAD_PK10__USDHC_DAT2_IN     905 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PK11__USDHC_DAT3_OUT    155 PAD_CTL_USDHC_DAT0_3
#define S32V234_PAD_PK11__USDHC_DAT3_IN     906 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PK15__USDHC_DAT4_OUT    159 PAD_CTL_USDHC_DAT4_7
#define S32V234_PAD_PK15__USDHC_DAT4_IN     907 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PL0__USDHC_DAT5_OUT     160 PAD_CTL_USDHC_DAT4_7
#define S32V234_PAD_PL0__USDHC_DAT5_IN      908 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PL1__USDHC_DAT6_OUT     161 PAD_CTL_USDHC_DAT4_7
#define S32V234_PAD_PL1__USDHC_DAT6_IN      909 PAD_CTL_MUX_MODE_ALT3

#define S32V234_PAD_PL2__USDHC_DAT7_OUT     162 PAD_CTL_USDHC_DAT4_7
#define S32V234_PAD_PL2__USDHC_DAT7_IN      910 PAD_CTL_MUX_MODE_ALT3

/* QSPI configuration */
#define S32V234_PAD_PK7__QSPI_A_DQS         819 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK14__QSPI_B_DQS        828 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PK8__QSPI_A_DATA0_IN    820 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK8__QSPI_A_DATA0_OUT   152 PAD_CTL_QSPI_A_DATA0_3

#define S32V234_PAD_PK9__QSPI_A_DATA1_IN    821 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK9__QSPI_A_DATA1_OUT   153 PAD_CTL_QSPI_A_DATA0_3

#define S32V234_PAD_PK10__QSPI_A_DATA2_IN   822 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK10__QSPI_A_DATA2_OUT  154 PAD_CTL_QSPI_A_DATA0_3

#define S32V234_PAD_PK11__QSPI_A_DATA3_IN   823 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK11__QSPI_A_DATA3_OUT  155 PAD_CTL_QSPI_A_DATA0_3

#define S32V234_PAD_PK15__QSPI_A_DATA4_IN   824 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK15__QSPI_A_DATA4_OUT  159 PAD_CTL_QSPI_A_DATA4_7

#define S32V234_PAD_PL0__QSPI_A_DATA5_IN    825 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PL0__QSPI_A_DATA5_OUT   160 PAD_CTL_QSPI_A_DATA4_7

#define S32V234_PAD_PL1__QSPI_A_DATA6_IN    826 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PL1__QSPI_A_DATA6_OUT   161 PAD_CTL_QSPI_A_DATA4_7

#define S32V234_PAD_PL2__QSPI_A_DATA7_IN    827 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PL2__QSPI_A_DATA7_OUT   162 PAD_CTL_QSPI_A_DATA4_7

#define S32V234_PAD_PK15__QSPI_B_DATA0_IN   829 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PK15__QSPI_B_DATA0_OUT  159 PAD_CTL_QSPI_B_DATA0_3

#define S32V234_PAD_PL0__QSPI_B_DATA1_IN    830 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PL0__QSPI_B_DATA1_OUT   160 PAD_CTL_QSPI_B_DATA0_3

#define S32V234_PAD_PL1__QSPI_B_DATA2_IN    831 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PL1__QSPI_B_DATA2_OUT   161 PAD_CTL_QSPI_B_DATA0_3

#define S32V234_PAD_PL2__QSPI_B_DATA3_IN    832 PAD_CTL_MUX_MODE_ALT2
#define S32V234_PAD_PL2__QSPI_B_DATA3_OUT   162 PAD_CTL_QSPI_B_DATA0_3

#define S32V234_PAD_PF12__QSPI_A_CS1        92  (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_A_CS1_MUX)
#define S32V234_PAD_PF13__QSPI_B_CS1        93  (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_B_CS1_MUX)

#define S32V234_PAD_PK5__QSPI_A_CS0         149 (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_A_CS0_MUX)
#define S32V234_PAD_PK6__QSPI_A_SCK         150 (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_A_SCK_MUX)

#define S32V234_PAD_PK12__QSPI_B_CS0        156 (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_B_CS0_MUX)
#define S32V234_PAD_PK13__QSPI_B_SCK        157 (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_B_SCK_MUX)

#define S32V234_PAD_PK13__QSPI_CK2          157 (PAD_CTL_QSPI_CLK_BASE | PAD_CTL_QSPI_CK2_MUX)

/* I2C configuration */
#define S32V234_PAD_PG3__I2C0_DATA_OUT      99  PAD_CTL_I2C0_MSCR_SDA
#define S32V234_PAD_PG3__I2C0_DATA_IN       781 PAD_CTL_I2C0_IMCR_SDA

#define S32V234_PAD_PG4__I2C0_SCLK_OUT      100 PAD_CTL_I2C0_MSCR_SCLK
#define S32V234_PAD_PG4__I2C0_SCLK_IN       780 PAD_CTL_I2C0_IMCR_SCLK

#define S32V234_PAD_PG5__I2C1_DATA_OUT      101 PAD_CTL_I2C1_MSCR_SDA
#define S32V234_PAD_PG5__I2C1_DATA_IN       783 PAD_CTL_I2C1_IMCR_SDA

#define S32V234_PAD_PG6__I2C1_SCLK_OUT      102 PAD_CTL_I2C1_MSCR_SCLK
#define S32V234_PAD_PG6__I2C1_SCLK_IN       782 PAD_CTL_I2C1_IMCR_SCLK

#define S32V234_PAD_PB3__I2C2_DATA_OUT      19  PAD_CTL_I2C2_MSCR_SDA
#define S32V234_PAD_PB3__I2C2_DATA_IN       785 PAD_CTL_I2C2_IMCR_SDA

#define S32V234_PAD_PB4__I2C2_SCLK_OUT      20  PAD_CTL_I2C2_MSCR_SCLK
#define S32V234_PAD_PB4__I2C2_SCLK_IN       784 PAD_CTL_I2C2_IMCR_SCLK

/* ENET configuration */
#define S32V234_PAD_PC13__MDC               45  PAD_CTL_ENET_CFG2

#define S32V234_PAD_PC14__MDIO_OUT          46  PAD_CTL_ENET_CFG3
#define S32v234_PAD_PC14__MDIO_IN           981 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PC15__TXCLK_OUT         47  PAD_CTL_ENET_CFG1
#define S32V234_PAD_PC15__TXCLK_IN          978 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD0__RXCLK_OUT          48  PAD_CTL_ENET_CFG4
#define S32V234_PAD_PD0__RXCLK_IN           979 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD1__RX_D0_OUT          49  PAD_CTL_ENET_CFG4
#define S32V234_PAD_PD1__RX_D0_IN           974 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD2__RX_D1_OUT          50  PAD_CTL_ENET_CFG4
#define S32V234_PAD_PD2__RX_D1_IN           975 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD3__RX_D2_OUT          51  PAD_CTL_ENET_CFG4
#define S32V234_PAD_PD3__RX_D2_IN           976 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD4__RX_D3_OUT          52  PAD_CTL_ENET_CFG4
#define S32V234_PAD_PD4__RX_D3_IN           977 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD4__RX_DV_OUT          53  PAD_CTL_ENET_CFG4
#define S32V234_PAD_PD4__RX_DV_IN           973 PAD_CTL_MUX_MODE_ALT2

#define S32V234_PAD_PD7__TX_D0_OUT          55  PAD_CTL_ENET_CFG2
#define S32V234_PAD_PD8__TX_D1_OUT          56  PAD_CTL_ENET_CFG2
#define S32V234_PAD_PD9__TX_D2_OUT          57  PAD_CTL_ENET_CFG2
#define S32V234_PAD_PD10__TX_D3_OUT         58  PAD_CTL_ENET_CFG2
#define S32V234_PAD_PD11__TX_EN_OUT         59  PAD_CTL_ENET_CFG2

/* 2D ACE DCU */
#define S32V234_PAD_PH8__DCU_HSYNC_C1		120	PAD_CTL_DCU_CFG
#define S32V234_PAD_PH9__DCU_VSYNC_C2		121	PAD_CTL_DCU_CFG
#define S32V234_PAD_PH10__DCU_DE_C3			122	PAD_CTL_DCU_CFG

#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_DISABLE	124	PAD_CTL_DCU_CLK_CFG_DSE_DISABLE
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_240		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_240)
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_120		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_120)
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_80		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_80)
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_60		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_60)
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_48		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_48)
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_40		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_40)
#define S32V234_PAD_PH12__DCU_PCLK_D1_DSE_34		124	(PAD_CTL_DCU_CLK_CFG_DSE_DISABLE | PAD_CTL_DSE_34)

#define S32V234_PAD_PH13__DCU_R0_D2			125	PAD_CTL_DCU_CFG
#define S32V234_PAD_PH14__DCU_R1_D3			126	PAD_CTL_DCU_CFG
#define S32V234_PAD_PH15__DCU_R2_D4			127	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ0__DCU_R3_D5			128	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ1__DCU_R4_D6			129	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ2__DCU_R5_D7			130	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ3__DCU_R6_D8			131	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ4__DCU_R7_D9			132	PAD_CTL_DCU_CFG

#define S32V234_PAD_PJ5__DCU_G0_D10			133	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ6__DCU_G1_D11			134	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ7__DCU_G2_D12			135	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ8__DCU_G3_D13			136	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ9__DCU_G4_D14			137	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ10__DCU_G5_D15		138	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ11__DCU_G6_D16		139	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ12__DCU_G7_D17		140	PAD_CTL_DCU_CFG

#define S32V234_PAD_PJ13__DCU_B0_D18		141	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ14__DCU_B1_D19		142	PAD_CTL_DCU_CFG
#define S32V234_PAD_PJ15__DCU_B2_D20		143	PAD_CTL_DCU_CFG
#define S32V234_PAD_PK0__DCU_B3_D21			144	PAD_CTL_DCU_CFG
#define S32V234_PAD_PK1__DCU_B4_D22			145	PAD_CTL_DCU_CFG
#define S32V234_PAD_PK2__DCU_B5_D23			146	PAD_CTL_DCU_CFG
#define S32V234_PAD_PK3__DCU_B6_D24			147	PAD_CTL_DCU_CFG
#define S32V234_PAD_PK4__DCU_B7_D25			148	PAD_CTL_DCU_CFG

/* VIULite0 */

#define S32V234_PAD_PD13__VIU0_EN			61	PAD_CTL_VIU_IBE
#define S32V234_PAD_PD13__VIU0_PCLK			624	PAD_CTL_VIU_CFG
#define S32V234_PAD_PD14__VIU0_EN			62	PAD_CTL_VIU_IBE
#define S32V234_PAD_PD14__VIU0_HSYNC		622	PAD_CTL_VIU_CFG
#define S32V234_PAD_PD15__VIU0_EN			63	PAD_CTL_VIU_IBE
#define S32V234_PAD_PD15__VIU0_VSYNC		623	PAD_CTL_VIU_CFG

#define S32V234_PAD_PF3__VIU_EN				83	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF3__VIU0_D4			629	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF4__VIU_EN				84	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF4__VIU0_D5			630	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF5__VIU_EN				85	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF5__VIU0_D6			631	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF6__VIU_EN				86	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF6__VIU0_D7			632	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE0__VIU0_EN			64	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE0__VIU0_D8			633	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE1__VIU0_EN			65	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE1__VIU0_D9			634	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE2__VIU0_EN			66	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE2__VIU0_D10			635	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE3__VIU0_EN			67	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE3__VIU0_D11			636	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE4__VIU0_EN			68	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE4__VIU0_D12			637	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE5__VIU0_EN			69	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE5__VIU0_D13			638	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE6__VIU0_EN			70	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE6__VIU0_D14			639	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE7__VIU0_EN			71	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE7__VIU0_D15			640	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE8__VIU0_EN			72	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE8__VIU0_D16			641	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE9__VIU0_EN			73	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE9__VIU0_D17			642	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE10__VIU0_EN			74	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE10__VIU0_D18			643	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE11__VIU0_EN			75	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE11__VIU0_D19			644	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE12__VIU0_EN			76	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE12__VIU0_D20			645	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE13__VIU0_EN			77	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE13__VIU0_D21			646	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE14__VIU0_EN			78	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE14__VIU0_D22			647	PAD_CTL_VIU_CFG
#define S32V234_PAD_PE15__VIU0_EN			79	PAD_CTL_VIU_IBE
#define S32V234_PAD_PE15__VIU0_D23			648	PAD_CTL_VIU_CFG

/* VIULite1 */

#define S32V234_PAD_PF0__VIU1_EN			80	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF0__VIU1_PCLK			659	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF1__VIU1_EN			81	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF1__VIU1_HSYNC			657	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF2__VIU1_EN			82	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF2__VIU1_VSYNC			658	PAD_CTL_VIU_CFG

#define S32V234_PAD_PF3__VIU_EN				83	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF3__VIU1_D8			668	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF4__VIU_EN				84	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF4__VIU1_D9			669	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF5__VIU_EN				85	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF5__VIU1_D10			670	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF6__VIU_EN				86	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF6__VIU1_D11			671	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF7__VIU1_EN			87	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF7__VIU1_D12			672	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF8__VIU1_EN			88	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF8__VIU1_D13			673	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF9__VIU1_EN			89	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF9__VIU1_D14			674	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF10__VIU1_EN			90	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF10__VIU1_D15			675	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF11__VIU1_EN			91	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF11__VIU1_D16			676	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF12__VIU1_EN			92	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF12__VIU1_D17			677	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF13__VIU1_EN			93	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF13__VIU1_D18			678	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF14__VIU1_EN			94	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF14__VIU1_D19			679	PAD_CTL_VIU_CFG
#define S32V234_PAD_PF15__VIU1_EN			95	PAD_CTL_VIU_IBE
#define S32V234_PAD_PF15__VIU1_D20			680	PAD_CTL_VIU_CFG
#define S32V234_PAD_PG0__VIU1_EN			96	PAD_CTL_VIU_IBE
#define S32V234_PAD_PG0__VIU1_D21			681	PAD_CTL_VIU_CFG
#define S32V234_PAD_PG1__VIU1_EN			97	PAD_CTL_VIU_IBE
#define S32V234_PAD_PG1__VIU1_D22			682	PAD_CTL_VIU_CFG
#define S32V234_PAD_PG2__VIU1_EN			98	PAD_CTL_VIU_IBE
#define S32V234_PAD_PG2__VIU1_D23			683	PAD_CTL_VIU_CFG

/* SPI 0-3 */
#define S32V234_PAD_PB6__SPI0_SOUT_OUT		22	PAD_CTL_SPI_MSCR_SOUT
#define S32V234_PAD_PB7__SPI0_SIN_OUT		23	PAD_CTL_SPI_MSCR_SIN
#define S32V234_PAD_PB7__SPI0_SIN_IN		800	PAD_CTL_SPI_IMCR_SIN
#define S32V234_PAD_PB5__SPI0_SCK_OUT		21	PAD_CTL_SPI_MSCR_SCK
#define S32V234_PAD_PB8__SPI0_CS0_OUT		24	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT1)
#define S32V234_PAD_PC0__SPI0_CS4_OUT		32	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT3)
#define S32V234_PAD_PC1__SPI0_CS5_OUT		33	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT3)
#define S32V234_PAD_PC2__SPI0_CS6_OUT		34	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT3)
#define S32V234_PAD_PC3__SPI0_CS7_OUT		35	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT2)

#define S32V234_PAD_PB10__SPI1_SOUT_OUT		26	PAD_CTL_SPI_MSCR_SOUT
#define S32V234_PAD_PB11__SPI1_SIN_OUT		27	PAD_CTL_SPI_MSCR_SIN
#define S32V234_PAD_PB11__SPI1_SIN_IN		803	PAD_CTL_SPI_IMCR_SIN
#define S32V234_PAD_PB9__SPI1_SCK_OUT		25	PAD_CTL_SPI_MSCR_SCK
#define S32V234_PAD_PB12__SPI1_CS0_OUT		28	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT1)

#define S32V234_PAD_PB14__SPI2_SOUT_OUT		30	PAD_CTL_SPI_MSCR_SOUT
#define S32V234_PAD_PB15__SPI2_SIN_OUT		31	PAD_CTL_SPI_MSCR_SIN
#define S32V234_PAD_PB15__SPI2_SIN_IN		806	PAD_CTL_SPI_IMCR_SIN
#define S32V234_PAD_P13__SPI2_SCK_OUT		29	PAD_CTL_SPI_MSCR_SCK
#define S32V234_PAD_PC0__SPI2_CS0_OUT		32	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT1)

#define S32V234_PAD_PC2__SPI3_SOUT_OUT		34	PAD_CTL_SPI_MSCR_SOUT
#define S32V234_PAD_PC3__SPI3_SIN_OUT		35	PAD_CTL_SPI_MSCR_SIN
#define S32V234_PAD_PC3__SPI3_SIN_IN		809	PAD_CTL_SPI_IMCR_SIN
#define S32V234_PAD_PC1__SPI3_SCK_OUT		33	PAD_CTL_SPI_MSCR_SCK
#define S32V234_PAD_PC4__SPI3_CS0_OUT		36	(PAD_CTL_SPI_MSCR_CSx | PAD_CTL_MUX_MODE_ALT1)

/* SIUL2 GPIOs */
#define S32V234_PAD_PA0__SIUL_GPIO0	0	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA1__SIUL_GPIO1	1	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA2__SIUL_GPIO2	2	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA3__SIUL_GPIO3	3	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA4__SIUL_GPIO4	4	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA5__SIUL_GPIO5	5	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA6__SIUL_GPIO6	6	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA7__SIUL_GPIO7	7	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA8__SIUL_GPIO8	8	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA9__SIUL_GPIO9	9	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA10__SIUL_GPIO10	10	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA11__SIUL_GPIO11	11	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA12__SIUL_GPIO12	12	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA13__SIUL_GPIO13	13	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA14__SIUL_GPIO14	14	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PA15__SIUL_GPIO15	15	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB0__SIUL_GPIO16	16	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB1__SIUL_GPIO17	17	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB2__SIUL_GPIO18	18	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB3__SIUL_GPIO19	19	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB4__SIUL_GPIO20	20	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB5__SIUL_GPIO21	21	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB6__SIUL_GPIO22	22	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB7__SIUL_GPIO23	23	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB8__SIUL_GPIO24	24	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB9__SIUL_GPIO25	25	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB10__SIUL_GPIO26	26	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB11__SIUL_GPIO27	27	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB12__SIUL_GPIO28	28	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB13__SIUL_GPIO29	29	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB14__SIUL_GPIO30	30	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PB15__SIUL_GPIO31	31	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC0__SIUL_GPIO32	32	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC1__SIUL_GPIO33	33	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC2__SIUL_GPIO34	34	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC3__SIUL_GPIO35	35	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC4__SIUL_GPIO36	36	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC5__SIUL_GPIO37	37	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC6__SIUL_GPIO38	38	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC7__SIUL_GPIO39	39	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC8__SIUL_GPIO40	40	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC9__SIUL_GPIO41	41	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC10__SIUL_GPIO42	42	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC11__SIUL_GPIO43	43	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC12__SIUL_GPIO44	44	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC13__SIUL_GPIO45	45	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC14__SIUL_GPIO46	46	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PC15__SIUL_GPIO47	47	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD0__SIUL_GPIO48	48	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD1__SIUL_GPIO49	49	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD2__SIUL_GPIO50	50	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD3__SIUL_GPIO51	51	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD4__SIUL_GPIO52	52	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD5__SIUL_GPIO53	53	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD6__SIUL_GPIO54	54	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD7__SIUL_GPIO55	55	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD8__SIUL_GPIO56	56	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD9__SIUL_GPIO57	57	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD10__SIUL_GPIO58	58	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD11__SIUL_GPIO59	59	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD12__SIUL_GPIO60	60	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD13__SIUL_GPIO61	61	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD14__SIUL_GPIO62	62	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PD15__SIUL_GPIO63	63	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE0__SIUL_GPIO64	64	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE1__SIUL_GPIO65	65	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE2__SIUL_GPIO66	66	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE3__SIUL_GPIO67	67	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE4__SIUL_GPIO68	68	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE5__SIUL_GPIO69	69	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE6__SIUL_GPIO70	70	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE7__SIUL_GPIO71	71	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE8__SIUL_GPIO72	72	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE9__SIUL_GPIO73	73	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE10__SIUL_GPIO74	74	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE11__SIUL_GPIO75	75	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE12__SIUL_GPIO76	76	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE13__SIUL_GPIO77	77	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE14__SIUL_GPIO78	78	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PE15__SIUL_GPIO79	79	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF0__SIUL_GPIO80	80	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF1__SIUL_GPIO81	81	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF2__SIUL_GPIO82	82	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF3__SIUL_GPIO83	83	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF4__SIUL_GPIO84	84	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF5__SIUL_GPIO85	85	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF6__SIUL_GPIO86	86	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF7__SIUL_GPIO87	87	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF8__SIUL_GPIO88	88	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF9__SIUL_GPIO89	89	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF10__SIUL_GPIO90	90	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF11__SIUL_GPIO91	91	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF12__SIUL_GPIO92	92	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF13__SIUL_GPIO93	93	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF14__SIUL_GPIO94	94	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PF15__SIUL_GPIO95	95	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG0__SIUL_GPIO96	96	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG1__SIUL_GPIO97	97	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG2__SIUL_GPIO98	98	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG3__SIUL_GPIO99	99	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG4__SIUL_GPIO100	100	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG5__SIUL_GPIO101	101	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG6__SIUL_GPIO102	102	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG7__SIUL_GPIO103	103	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG8__SIUL_GPIO104	104	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG9__SIUL_GPIO105	105	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG10__SIUL_GPIO106	106	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG11__SIUL_GPIO107	107	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG12__SIUL_GPIO108	108	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG13__SIUL_GPIO109	109	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG14__SIUL_GPIO110	110	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PG15__SIUL_GPIO111	111	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH0__SIUL_GPIO112	112	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH1__SIUL_GPIO113	113	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH2__SIUL_GPIO114	114	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH3__SIUL_GPIO115	115	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH4__SIUL_GPIO116	116	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH5__SIUL_GPIO117	117	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH6__SIUL_GPIO118	118	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH7__SIUL_GPIO119	119	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH8__SIUL_GPIO120	120	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH9__SIUL_GPIO121	121	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH10__SIUL_GPIO122	122	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH11__SIUL_GPIO123	123	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH12__SIUL_GPIO124	124	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH13__SIUL_GPIO125	125	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH14__SIUL_GPIO126	126	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PH15__SIUL_GPIO127	127	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ0__SIUL_GPIO128	128	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ1__SIUL_GPIO129	129	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ2__SIUL_GPIO130	130	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ3__SIUL_GPIO131	131	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ4__SIUL_GPIO132	132	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ5__SIUL_GPIO133	133	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ6__SIUL_GPIO134	134	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ7__SIUL_GPIO135	135	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ8__SIUL_GPIO136	136	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ9__SIUL_GPIO137	137	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ10__SIUL_GPIO138	138	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ11__SIUL_GPIO139	139	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ12__SIUL_GPIO140	140	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ13__SIUL_GPIO141	141	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ14__SIUL_GPIO142	142	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PJ15__SIUL_GPIO143	143	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK0__SIUL_GPIO144	144	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK1__SIUL_GPIO145	145	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK2__SIUL_GPIO146	146	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK3__SIUL_GPIO147	147	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK4__SIUL_GPIO148	148	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK5__SIUL_GPIO149	149	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK6__SIUL_GPIO150	150	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK7__SIUL_GPIO151	151	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK8__SIUL_GPIO152	152	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK9__SIUL_GPIO153	153	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK10__SIUL_GPIO154	154	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK11__SIUL_GPIO155	155	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK12__SIUL_GPIO156	156	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK13__SIUL_GPIO157	157	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK14__SIUL_GPIO158	158	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PK15__SIUL_GPIO159	159	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PL0__SIUL_GPIO160	160	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PL1__SIUL_GPIO161	161	PAD_CTL_MUX_MODE_ALT0
#define S32V234_PAD_PL2__SIUL_GPIO162	162	PAD_CTL_MUX_MODE_ALT0


/* SIUL2 EIRQ pins */
#define S32V234_PAD_PA0__SIUL_EIRQ0	590	PAD_CTL_EIRQ
#define S32V234_PAD_PA1__SIUL_EIRQ1	591	PAD_CTL_EIRQ
#define S32V234_PAD_PA2__SIUL_EIRQ2	592	PAD_CTL_EIRQ
#define S32V234_PAD_PA3__SIUL_EIRQ3	593	PAD_CTL_EIRQ
#define S32V234_PAD_PA4__SIUL_EIRQ4	594	PAD_CTL_EIRQ
#define S32V234_PAD_PA5__SIUL_EIRQ5	595	PAD_CTL_EIRQ
#define S32V234_PAD_PA6__SIUL_EIRQ6	596	PAD_CTL_EIRQ
#define S32V234_PAD_PA7__SIUL_EIRQ7	597	PAD_CTL_EIRQ
#define S32V234_PAD_PA8__SIUL_EIRQ8	598	PAD_CTL_EIRQ
#define S32V234_PAD_PA9__SIUL_EIRQ9	599	PAD_CTL_EIRQ
#define S32V234_PAD_PA10__SIUL_EIRQ10	600	PAD_CTL_EIRQ
#define S32V234_PAD_PA11__SIUL_EIRQ11	601	PAD_CTL_EIRQ
#define S32V234_PAD_PA12__SIUL_EIRQ12	602	PAD_CTL_EIRQ
#define S32V234_PAD_PA13__SIUL_EIRQ13	603	PAD_CTL_EIRQ
#define S32V234_PAD_PA14__SIUL_EIRQ14	604	PAD_CTL_EIRQ
#define S32V234_PAD_PA15__SIUL_EIRQ15	605	PAD_CTL_EIRQ
#define S32V234_PAD_PB0__SIUL_EIRQ16	606	PAD_CTL_EIRQ
#define S32V234_PAD_PB1__SIUL_EIRQ17	607	PAD_CTL_EIRQ
#define S32V234_PAD_PB2__SIUL_EIRQ18	608	PAD_CTL_EIRQ
#define S32V234_PAD_PB3__SIUL_EIRQ19	609	PAD_CTL_EIRQ
#define S32V234_PAD_PB4__SIUL_EIRQ20	610	PAD_CTL_EIRQ
#define S32V234_PAD_PB5__SIUL_EIRQ21	611	PAD_CTL_EIRQ
#define S32V234_PAD_PB6__SIUL_EIRQ22	612	PAD_CTL_EIRQ
#define S32V234_PAD_PB7__SIUL_EIRQ23	613	PAD_CTL_EIRQ
#define S32V234_PAD_PB8__SIUL_EIRQ24	614	PAD_CTL_EIRQ
#define S32V234_PAD_PB9__SIUL_EIRQ25	615	PAD_CTL_EIRQ
#define S32V234_PAD_PB10__SIUL_EIRQ26	616	PAD_CTL_EIRQ
#define S32V234_PAD_PB11__SIUL_EIRQ27	617	PAD_CTL_EIRQ
#define S32V234_PAD_PB12__SIUL_EIRQ28	618	PAD_CTL_EIRQ
#define S32V234_PAD_PB13__SIUL_EIRQ29	619	PAD_CTL_EIRQ
#define S32V234_PAD_PB14__SIUL_EIRQ30	620	PAD_CTL_EIRQ
#define S32V234_PAD_PB15__SIUL_EIRQ31	621	PAD_CTL_EIRQ

#endif /* __DT_BINDINGS_S32V234_PINCTRL_H__ */
