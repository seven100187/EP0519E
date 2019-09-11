#include <MKL46Z4.h>

#define LED (1<<29)
#define COUNTER (20000 - 1)

uint32_t tick = 0;

void init_uart0_pin()
{
  SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
  PORTA->PCR[1] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTA->PCR[1] |= PORT_PCR_MUX(2);
  
  PORTA->PCR[2] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTA->PCR[2] |= PORT_PCR_MUX(2);
}

void init_uart0()
{
  SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
  SIM->SOPT2 &= ~(uint32_t)SIM_SOPT2_UART0SRC_MASK;
  SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
  SIM->SOPT2 &= ~(uint32_t)SIM_SOPT2_PLLFLLSEL_MASK;
  
  UART0->C1 &= ~(uint32_t)UART0_C1_M_MASK;
  UART0->C4 &= ~(uint32_t)UART0_C4_M10_MASK;
  //UART0->C4 |= UART0_C4_M10_MASK;
  
  UART0->C1 &=(uint32_t)UART0_C1_PT_MASK;
  UART0->C1 &=(uint32_t)UART0_C1_PE_MASK;
  
  UART0->S2 &=(uint32_t)UART0_S2_MSBF_MASK;
  
  UART0->BDH &=(uint32_t)UART0_BDH_SBR_MASK;
  UART0->BDL &=(uint32_t)UART0_BDL_SBR_MASK;
  UART0->BDL |= UART0_BDL_SBR(156);
  
  UART0->C2 |= UART0_C2_TE_MASK;
  UART0->C2 |= UART0_C2_RE_MASK;
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

void putchar(char kt)
{
  while(((UART0->S1 & UART0_S1_TC_MASK) >> UART0_S1_TC_SHIFT)==0);
  
  UART0->D = kt;
}

void putstr(char *str)
{
  while(*str)
  {
    if(*str == '\n')
    {
      putchar('\r');
    }
    putchar(*str++);
  }
}
int main()
{
  FEI_8Mhz();
  init_uart0_pin();
  init_uart0();
  putstr("Chao Cac Ban Lop EP0519E");
  while(1)
  {
  }
}