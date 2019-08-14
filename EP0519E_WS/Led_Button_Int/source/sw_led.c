#include <MKL46Z4.h>

#define SW1 (1<<3)
#define LED (1<<29)
#define FALLING (10)
#define SW1_PRIORITY (255)

void init_sw()
{
  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
  PORTC->PCR[3] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTC->PCR[3] |= PORT_PCR_MUX(1);
  PORTC->PCR[3] |= PORT_PCR_PE_MASK;
  PORTC->PCR[3] |= PORT_PCR_PS_MASK;
  PORTC->PCR[3] &= ~(uint32_t)(PORT_PCR_IRQC_MASK);
  PORTC->PCR[3] |= PORT_PCR_IRQC(FALLING);
  
  GPIOC->PDDR &= ~(uint32_t)SW1;
}

void init_led()
{
  SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
  PORTE->PCR[29] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTE->PCR[29] |= PORT_PCR_MUX(1);
  GPIOE->PDDR |= (uint32_t)LED;
}

void PORTC_PORTD_Interrupt_init()
{
  NVIC_EnableIRQ(PORTC_PORTD_IRQn);
  NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
  NVIC_SetPriority(PORTC_PORTD_IRQn,SW1_PRIORITY);
}

void PORTC_PORTD_IRQHandler()
{
  PORTC->ISFR |= (uint32_t)SW1;
  GPIOE->PTOR |= (uint32_t)LED; 
}

int main()
{
  init_sw();
  init_led();
  PORTC_PORTD_Interrupt_init();
  while(1);
}