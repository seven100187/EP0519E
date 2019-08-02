#include "MKL46Z4.h"


#define DELAY_CNT           (1000000)
#define RED_LED_PIN         (1 << 29)
#define GREEN_LED_PIN       (1 << 5)


void initLed();
void delay();


int main(void)
{
    initLed();
}


void initLed()
{
  SIM_SCGC5 &= ~SIM_SCGC5_PORTA_MASK;
  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
  
  PORTA_PCR_2 &= PORTA_PCR_2_MUX_MASK;
  PORTA_PCR_2 |= PORTA_PCR_2_MUX(1);
  
  *GPIOA_PDDR |= (uint32_t)RED_LED_PIN;
  *GPIOA_PSOR |= (uint32_t)RED_LED_PIN;
  *GPIOA_PDDR |= (uint32_t)RED_LED_PIN;
  *GPIOA_PSOR |= (uint32_t)RED_LED_PIN;  
}

void delay()
{
    uint32_t i;
    for (i = 0; i < DELAY_CNT; i++)
    {
        __asm("nop");
    }
}

