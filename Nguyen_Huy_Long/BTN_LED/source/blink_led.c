#include "MKL46Z4.h"


#define RED_LED_PIN (1<<29) // chan 29 , can 1 bit de xac dinh input or output->output
#define BTN_PIN (0<<3) //input

void initLed()
{
  SIM_SCGC5 = SIM_SCGC5  & (~SIM_SCGC5_PORTE_MASK);
  SIM_SCGC5 = SIM_SCGC5 | SIM_SCGC5_PORTE_MASK;
  
  PORTE_PCR_29 = PORTE_PCR_29 & (~PORT_PCR_MUX_MASK);
  PORTE_PCR_29 |= PORT_PCR_MUX(ALT1);

  GPIOE_PDDR |= RED_LED_PIN ;
  GPIOE_PDOR |= RED_LED_PIN;
  
}

void initButton()
{
  SIM_SCGC5 &= ~SIM_SCGC5_PORTC_MASK;
  SIM_SCGC5 |=(SIM_SCGC5_PORTC_MASK);
    
  PORTC_PCR_3 &= (~PORT_PCR_MUX_MASK);
  PORTC_PCR_3 |= PORT_PCR_MUX(ALT1);
  
  PORTC_PCR_3 &=(~PORT_PCR_PE_MASK);
  PORTC_PCR_3 |=PORT_PCR_PE_MASK;
  PORTC_PCR_3 &=(~PORT_PCR_PS_MASK);
  PORTC_PCR_3 |=PORT_PCR_PS_MASK;
  
  //PDDR (pin 3 ==0 -> input)
  //PDIR (set while)
  
  
  
}




void delay()
{
  int i;
  for(i=0;i<=500000;i++);
}



int main(void)
{  
   
    initButton();
    initLed();
    if((GPIOC_PDIR & 0x8)==1)
    {
      GPIOE_PSOR |= RED_LED_PIN;
    }
    else
    {
       GPIOE_PCOR |= RED_LED_PIN;
    }
}

