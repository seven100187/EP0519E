#include <MKL46Z4.h>

#define LED (1<<29)
#define COUNTER (20000 - 1)

uint32_t tick = 0;

void init_led()
{
  SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
  PORTE->PCR[29] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTE->PCR[29] |= PORT_PCR_MUX(1);
  GPIOE->PDDR |= (uint32_t)LED;
}

void init_systick()
{
  SysTick->LOAD = COUNTER;
  SysTick->VAL = 0;
  SysTick->CTRL |= (uint32_t)(SysTick_CTRL_TICKINT_Msk|SysTick_CTRL_CLKSOURCE_Msk|SysTick_CTRL_ENABLE_Msk);
}

void SysTick_Handler()
{
  SysTick->CTRL;
  tick++;
}

void delay_ms(uint32_t time)
{
  uint32_t tick_current;
  tick_current = tick;
  while(tick - tick_current < time);
}

void FEI_8Mhz()
{
  MCG->C1 &= ~(uint32_t)MCG_C1_CLKS_MASK;
  MCG->C1 |= (uint32_t)MCG_C1_IREFS_MASK;
  MCG->C6 &= ~(uint32_t)MCG_C6_PLLS_MASK;
  
  MCG->C4 |= (uint32_t)MCG_C4_DMX32_MASK;
  MCG->C4 &= ~(uint32_t)MCG_C4_DRST_DRS_MASK;
  
  SIM->CLKDIV1 &= ~(uint32_t)SIM_CLKDIV1_OUTDIV1_MASK;
  SIM->CLKDIV1 |= (uint32_t)SIM_CLKDIV1_OUTDIV1(2);
}

void FEE_8Mhz()
{
  MCG->C1 &= ~(uint32_t)MCG_C1_CLKS_MASK;
  MCG->C1 |= (uint32_t)MCG_C1_IREFS_MASK;
  MCG->C6 &= ~(uint32_t)MCG_C6_PLLS_MASK;
  
  MCG->C4 |= (uint32_t)MCG_C4_DMX32_MASK;
  MCG->C4 &= ~(uint32_t)MCG_C4_DRST_DRS_MASK;
  
  SIM->CLKDIV1 &= ~(uint32_t)SIM_CLKDIV1_OUTDIV1_MASK;
  SIM->CLKDIV1 |= (uint32_t)SIM_CLKDIV1_OUTDIV1(2);
}

void FEI_to_FBE()
{
  MCG->C1 &= ~(uint32_t)MCG_C1_CLKS_MASK;
  MCG->C1 |= (uint32_t)MCG_C1_CLKS(2);
  
  MCG->C1 &= ~(uint32_t)MCG_C1_IREFS_MASK;
  
  MCG->C2 |= (uint32_t)MCG_C2_RANGE0(2);
  
  MCG->C1 &= ~(uint32_t)MCG_C1_FRDIV_MASK;
  MCG->C1 |= (uint32_t)MCG_C1_FRDIV(3);
  
  MCG->C4 &= ~(uint32_t)MCG_C4_DMX32_MASK;
  MCG->C4 &= ~(uint32_t)MCG_C4_DRST_DRS_MASK;
  
  MCG->C6 &= ~(uint32_t)MCG_C6_PLLS_MASK;
  MCG->C2 &= ~(uint32_t)MCG_C2_LP_MASK;
  
  SIM->CLKDIV1 &= ~(uint32_t)SIM_CLKDIV1_OUTDIV1_MASK;
  SIM->CLKDIV1 |= (uint32_t)SIM_CLKDIV1_OUTDIV1(0);
}

void FBE_to_PBE()
{  
  MCG->C5 &=~(uint32_t)MCG_C5_PRDIV0_MASK;
  MCG->C5 |= (uint32_t)MCG_C5_PRDIV0(4);
  
  MCG->C6 &= ~(uint32_t)MCG_C6_VDIV0_MASK;
  
  MCG->C6 &= ~(uint32_t)MCG_C6_PLLS_MASK;
  MCG->C6 |= (uint32_t)MCG_C6_PLLS_MASK;
  
  MCG->C2 &= ~(uint32_t)MCG_C2_LP_MASK;
}

void FBE_to_PEE()
{
  MCG->C1 &= ~(uint32_t)MCG_C1_CLKS_MASK;
  SIM->CLKDIV1 &= ~(uint32_t)SIM_CLKDIV1_OUTDIV1_MASK;
  SIM->CLKDIV1 |= (uint32_t)SIM_CLKDIV1_OUTDIV1(0);
}


int main()
{
  init_led();
  init_systick();
  FEI_to_FBE();
  
  delay_ms(500);
  //FBE_to_PBE();
  //FBE_to_PEE();
  while(1)
  {
    GPIOE->PTOR |= (uint32_t)LED;
    delay_ms(500);
  }
}