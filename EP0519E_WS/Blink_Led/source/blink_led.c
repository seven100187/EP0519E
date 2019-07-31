#include "MKL46Z4.h"


#define DELAY_CNT           (1000000)
#define RED_LED_PIN         (1 << 29)
#define GREEN_LED_PIN       (1 << 5)


void initLed()
{
  SIM_SCGC5 &= ~SIM_SCGC5_PORTE_MASK;
  SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
  
  PORTE_PCR_29 &= PORTE_PCR_29_MUX_MASK;
  PORTE_PCR_29 |= PORTE_PCR_29_MUX(1);
  
  *GPIOE_PDDR |= (uint32_t)RED_LED_PIN;
  *GPIOE_PSOR |= (uint32_t)RED_LED_PIN;
  
}



void delay()
{
  int i;
  for(i=0;i<=500000;i++);
}



int main(void)
{
    initLed();

    while (1)
    {
        *GPIOE_PTOR |= (uint32_t)RED_LED_PIN;
        delay();
    }
}

