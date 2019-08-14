#include "MKL46Z4.h"
void delay()
{
  uint32_t i;
  for(i=0;i<1000000;i++);
}
int main(void)
{
    SIM_SCGC5 &=~SIM_SCGC5_PORTD_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
    
    PORTD_PCR5 &=~PCR_MUX_MASK;
    PORTD_PCR5 |= (uint32_t)((1 << PCR_MUX_SHIFT) & PCR_MUX_MASK);
    /*PORTD_PCR5 |= PCR_MUX_SET(x) */
    GPIOD_PDDR |= (uint32_t)(1 << 5);
    while (1)
    {
      GPIOD_PSOR |= (1<<5);
      delay();
      GPIOD_PCOR |= (1<<5);
      delay();
    }
}

