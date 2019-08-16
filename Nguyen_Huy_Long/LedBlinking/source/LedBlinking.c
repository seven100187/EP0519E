#include "MKL46Z4.h"


#define DELAY_CNT           (1000000)
#define RED_LED_PIN         (1 << 29)
#define GREEN_LED_PIN       (1 << 5)


void initLed();
void delay();


int main(void)
{
    initLed();
    while (1)
    {
        delay();
        /* Toggle Red Led */
        FPTE->PTOR |= RED_LED_PIN;
        /* Toggle Green Led */
        FPTD->PTOR |= GREEN_LED_PIN;
    }
}


void initLed()
{
   //Enable clock PORT E
  SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
  //set GPIO
  PORTE->PCR[29] |= PORT_PCR_MUX(1);
  //GPIO
  GPIOE->PDDR |=RED_LED_PIN; // output
  GPIOE->PSOR |=RED_LED_PIN;
}


void delay()
{
    uint32_t i;
    for (i = 0; i < DELAY_CNT; i++)
    {
        __asm("nop");
    }
}

