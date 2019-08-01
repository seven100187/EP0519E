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
**     Build:               b151217
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright (c) 2015 Freescale Semiconductor, Inc.
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
 * @file MKL46Z4
 * @version 3.4
 * @date 2014-10-14
 * @brief Device specific configuration file for MKL46Z4 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"



/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit (void) {

  /* Watchdog disable */
#if (DISABLE_WDOG)
  /* SIM_COPC: COPT=0,COPCLKS=0,COPW=0 */
  SIM_COPC = (uint32_t)0x00u;
#endif /* (DISABLE_WDOG) */

}
