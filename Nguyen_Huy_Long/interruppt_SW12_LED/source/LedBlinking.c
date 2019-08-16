#include "MKL46Z4.h"

#define RED_LED (1<<29)
#define SW1 (1<<3)
#define SW2 (1<<12) // PORTC
#define ALT1 (1)
#define Falling (10)
#define DELAY_CNT (1000000)
#define ISW1 (0x8)
#define ISW2 (0x1000)

void init_Led()
{
  //delete byte clock and enable clock gate
 
  //delete byte clock and enable clock gate
  SIM->SCGC5 &= ~(SIM_SCGC5_PORTE_MASK);
  SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
  
  //delete byte PORTE(ALT GPIO) and set ALT GPIO
  PORTE->PCR[29] &= ~(PORT_PCR_MUX_MASK);
  PORTE->PCR[29] |= PORT_PCR_MUX(1);
  
  //GPIO output and set output
  GPIOE->PDDR |= (uint32_t)RED_LED;
  GPIOE->PCOR |= (uint32_t)RED_LED;
  
  
}
void init_SW2()
{
   //delete byte clock and enable clock gate
  SIM->SCGC5 &= ~(SIM_SCGC5_PORTC_MASK);
  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
  
  //delete byte PORTE(ALT GPIO) and set ALT GPIO
  PORTC->PCR[12] &= ~(PORT_PCR_MUX_MASK);
  PORTC->PCR[12] |= PORT_PCR_MUX(1);
    PORTC->PCR[12] |= PORT_PCR_PE_MASK;
  PORTC->PCR[12] |= PORT_PCR_PS_MASK;
  //GPIO input
  GPIOC->PDDR &= ~(SW2);
  //IRQC (set interrupt DMA/request )
  PORTC->PCR[12] |= PORT_PCR_IRQC(9);
}
void init_SW1()
{
  //delete byte clock and enable clock gate
  SIM->SCGC5 &= ~(SIM_SCGC5_PORTC_MASK);
  SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
  
  //delete byte PORTE(ALT GPIO) and set ALT GPIO
  PORTC->PCR[3] &= ~(PORT_PCR_MUX_MASK);
  PORTC->PCR[3] |= PORT_PCR_MUX(1);
    PORTC->PCR[3] |= PORT_PCR_PE_MASK;
  PORTC->PCR[3] |= PORT_PCR_PS_MASK;
  //GPIO input
  GPIOC->PDDR &= ~(SW1);
  //IRQC (set interrupt DMA/request )
  PORTC->PCR[3] |= PORT_PCR_IRQC(9);
  
  
}

void delay()
{
    uint32_t i;
    for (i = 0; i < DELAY_CNT; i++)
    {
        __asm("nop");
    }
}



//method core Handler (PORTC_PORTD_IRQ)
void PORTC_PORTD_IRQHandler()
{
  
 if(PORTC->ISFR ==ISW1)
 {
   PORTC->ISFR |=SW1;
   GPIOE->PSOR |=RED_LED;
 }
 if(PORTC->ISFR==ISW2)
 {
   PORTC->ISFR |=SW2;
   GPIOE->PCOR |=RED_LED;
 }

 /*PORTC->ISFR |=SW1;
 GPIOE->PSOR |=RED_LED;
  */
}


//method interrupt in handler mode
void PORTC_PORTD_interrupt_SW1()
{
  //NVIC_ISER enable interrupt
   //parameter MKL46Z4.h  ->IRQn
   NVIC_EnableIRQ(PORTC_PORTD_IRQn);
   
  NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
  
  //NVIC_Priority
  NVIC_SetPriority(PORTC_PORTD_IRQn,255);

}

int main()
{
  init_Led();
  init_SW1();
  init_SW2();
  PORTC_PORTD_interrupt_SW1();
  while(1);
  
  
}







