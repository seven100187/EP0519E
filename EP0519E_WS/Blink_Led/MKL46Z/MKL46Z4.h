/*
** ###################################################################
**     Processors:          MKL46Z128VLH4
**                          MKL46Z128VLL4
**                          MKL46Z128VMC4
**                          MKL46Z256VLH4
**                          MKL46Z256VLL4
**                          MKL46Z256VMC4
**                          MKL46Z256VMP4
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    KL46P121M48SF4RM, Rev.2, Dec 2012
**     Version:             rev. 3.4, 2014-10-14
**     Build:               b160126
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MKL46Z4
**
**     Copyright (c) 1997 - 2016 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2012-10-16)
**         Initial version.
**     - rev. 2.0 (2012-12-12)
**         Update to reference manual rev. 1.
**     - rev. 2.1 (2013-04-05)
**         Changed start of doxygen comment.
**     - rev. 2.2 (2013-04-12)
**         SystemInit function fixed for clock configuration 1.
**         Name of the interrupt num. 31 updated to reflect proper function.
**     - rev. 2.3 (2013-08-15)
**         Update of I2S register TCR2.
**         Access restriction of some registers fixed.
**     - rev. 3.0 (2014-05-14)
**         Register accessor macros added to the memory map.
**         Symbols for Processor Expert memory map compatibility added to the memory map.
**         Update of SystemInit() and SystemCoreClockUpdate() functions.
**     - rev. 3.1 (2014-07-16)
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         System initialization and startup updated.
**     - rev. 3.2 (2014-07-25)
**         System initialization updated:
**         - Access to the registers unified using CMSIS device data structures.
**     - rev. 3.3 (2014-08-28)
**         Update of system files - default clock configuration changed, fix of OSC initialization.
**         Update of startup files - possibility to override DefaultISR added.
**     - rev. 3.4 (2014-10-14)
**         Renamed interrupt vector LPTimer to LPTMR0
**
** ###################################################################
*/

/*!
 * @file MKL46Z4.h
 * @version 3.4
 * @date 2014-10-14
 * @brief CMSIS Peripheral Access Layer for MKL46Z4
 *
 * CMSIS Peripheral Access Layer for MKL46Z4
 */

#ifndef _MKL46Z4_H_
#define _MKL46Z4_H_                              /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0300U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0004U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete and error interrupt */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete and error interrupt */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete and error interrupt */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete and error interrupt */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt */
  FTFA_IRQn                    = 5,                /**< FTFA command complete and read collision */
  LVD_LVW_IRQn                 = 6,                /**< Low-voltage detect, low-voltage warning */
  LLWU_IRQn                    = 7,                /**< Low Leakage Wakeup */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  I2C1_IRQn                    = 9,                /**< I2C1 interrupt */
  SPI0_IRQn                    = 10,               /**< SPI0 single interrupt vector for all sources */
  SPI1_IRQn                    = 11,               /**< SPI1 single interrupt vector for all sources */
  UART0_IRQn                   = 12,               /**< UART0 status and error */
  UART1_IRQn                   = 13,               /**< UART1 status and error */
  UART2_IRQn                   = 14,               /**< UART2 status and error */
  ADC0_IRQn                    = 15,               /**< ADC0 interrupt */
  CMP0_IRQn                    = 16,               /**< CMP0 interrupt */
  TPM0_IRQn                    = 17,               /**< TPM0 single interrupt vector for all sources */
  TPM1_IRQn                    = 18,               /**< TPM1 single interrupt vector for all sources */
  TPM2_IRQn                    = 19,               /**< TPM2 single interrupt vector for all sources */
  RTC_IRQn                     = 20,               /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 21,               /**< RTC seconds interrupt */
  PIT_IRQn                     = 22,               /**< PIT single interrupt vector for all channels */
  I2S0_IRQn                    = 23,               /**< I2S0 Single interrupt vector for all sources */
  USB0_IRQn                    = 24,               /**< USB0 OTG */
  DAC0_IRQn                    = 25,               /**< DAC0 interrupt */
  TSI0_IRQn                    = 26,               /**< TSI0 interrupt */
  MCG_IRQn                     = 27,               /**< MCG interrupt */
  LPTMR0_IRQn                  = 28,               /**< LPTMR0 interrupt */
  LCD_IRQn                     = 29,               /**< Segment LCD interrupt */
  PORTA_IRQn                   = 30,               /**< PORTA pin detect */
  PORTC_PORTD_IRQn             = 31                /**< Single interrupt vector for PORTC and PORTD pin detect */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_MKL46Z4.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/* Define address for SIM module*/
#define SIM_SCGC5_BASE (0x40048038)
#define SIM_SCGC5 *(uint32_t *)SIM_SCGC5_BASE

#define SIM_SCGC5_PORTA_SHIFT (9)
#define SIM_SCGC5_PORTA_MASK (0x200)
#define SIM_SCGC5_PORTB_SHIFT (10)
#define SIM_SCGC5_PORTB_MASK (0x400)
#define SIM_SCGC5_PORTC_SHIFT (11)
#define SIM_SCGC5_PORTC_MASK (0x800)
#define SIM_SCGC5_PORTD_SHIFT (12)
#define SIM_SCGC5_PORTD_MASK (0x1000)
#define SIM_SCGC5_PORTE_SHIFT (13)
#define SIM_SCGC5_PORTE_MASK (0x2000)


/* Define PORT control register*/
#define PCR_PS_SHIFT (0)
#define PCR_PS_MASK (0x1)
#define PCR_PE_SHIFT (1)
#define PCR_PE_MASK (0x2)
#define PCR_SRE_SHIFT (2)
#define PCR_SRE_MASK (0x4)
#define PCR_PFE_SHIFT (3)
#define PCR_PFE_MASK (0x8)
#define PCR_MUX_SHIFT (8)
#define PCR_MUX_MASK (0x700)
#define PCR_MUX_SET(x) (uint32_t)((x << PCR_MUX_SHIFT) & PCR_MUX_MASK)

#define PORTD_PCR5_BASE (0x4004C014)
#define PORTD_PCR5 *(uint32_t *)PORTD_PCR5_BASE

/* Define GPIO register*/
#define GPIOD_PDOR_BASE (0x400FF0C0)
#define GPIOD_PDOR *(uint32_t *)GPIOD_PDOR_BASE
#define GPIOD_PSOR_BASE (0x400FF0C4)
#define GPIOD_PSOR *(uint32_t *)GPIOD_PSOR_BASE
#define GPIOD_PCOR_BASE (0x400FF0C8)
#define GPIOD_PCOR *(uint32_t *)GPIOD_PCOR_BASE
#define GPIOD_PTOR_BASE (0x400FF0CC)
#define GPIOD_PTOR *(uint32_t *)GPIOD_PTOR_BASE
#define GPIOD_PDIR_BASE (0x400FF0D0)
#define GPIOD_PDIR *(uint32_t *)GPIOD_PDIR_BASE
#define GPIOD_PDDR_BASE (0x400FF0D4)
#define GPIOD_PDDR *(uint32_t *)GPIOD_PDDR_BASE
#endif  /* _MKL46Z4_H_ */

