/*
 * Copyright (C) 2016 Freescale Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef _SRC_H
#define _SRC_H

/* Source Reset Control: General Purpose Register 1 */
#define SRC_GPR1                                (src_base + 0x100)
#define SRC_GPR1_ARMPLL_SRC_SEL_OFFSET          (27)
#define SRC_GPR1_ENETPLL_SRC_SEL_OFFSET         (28)
#define SRC_GPR1_DDRPLL_SRC_SEL_OFFSET          (29)
#define SRC_GPR1_PERIPHPLL_SRC_SEL_OFFSET       (30)
#define SRC_GPR1_VIDEOPLL_SRC_SEL_OFFSET        (31)
#define SRC_GPR1_XPLL_SRC_SEL_SIZE              (1)

#endif
