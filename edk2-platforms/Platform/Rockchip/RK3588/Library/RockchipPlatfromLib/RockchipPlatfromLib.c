/** @file
*
*  Copyright (c) 2021, Rockchip Limited. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Soc.h>

void DebugPrintHex(void *buf, UINT32 width, UINT32 len)
{
	UINT32 i,j;
	UINT8 *p8 = (UINT8 *) buf;
	UINT16 *p16 = (UINT16 *) buf;
	UINT32 *p32 =(UINT32 *) buf;

	j = 0;
	for (i = 0; i < len; i++) {
		if (j == 0)
			DebugPrint(DEBUG_ERROR, "%p + 0x%x:",buf, i * width);

		if (width == 4)
			DebugPrint(DEBUG_ERROR, "0x%08x,", p32[i]);
		else if (width == 2)
			DebugPrint(DEBUG_ERROR, "0x%04x,", p16[i]);
		else
			DebugPrint(DEBUG_ERROR, "0x%02x,", p8[i]);

		if (++j >= (16/width)) {
			j = 0;
			DebugPrint(DEBUG_ERROR, "\n","");
		}
	}
	DebugPrint(DEBUG_ERROR, "\n","");
}

void DwEmmcDxeIoMux(void)
{
  /* sdmmc0 iomux */
}

#define NS_CRU_BASE         0xFD7C0000
#define CRU_CLKSEL_CON59    0x03EC

void
EFIAPI
Rk806SpiIomux(void)
{
  /* io mux */
  //BUS_IOC->GPIO1A_IOMUX_SEL_H = (0xFFFFUL << 16) | 0x8888;
  //BUS_IOC->GPIO1B_IOMUX_SEL_L = (0x000FUL << 16) | 0x0008;
  PMU1_IOC->GPIO0A_IOMUX_SEL_H = (0x0FF0UL << 16) | 0x0110;
  PMU1_IOC->GPIO0B_IOMUX_SEL_L = (0xF0FFUL << 16) | 0x1011;
  MmioWrite32(NS_CRU_BASE + CRU_CLKSEL_CON59, (0x00C0UL << 16) | 0x0080);
}
