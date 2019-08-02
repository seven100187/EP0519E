#include "MKL46Z4.h"

#define TOGE_LED_PIN            (1<<9)
#define SW                      (1<<3)
#define 

void init_led_button()
{
    /* Enable clock for PORTB*/
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
    PORTB->PCR[9] = PORT_PCR_MUX(1);
    PORTB->PCR[3] = PORT_PCR_MUX(1);
    PORTB->PCR[3] |= 0x3; Pull up/down
    /* Set the pins direction to output */
    FPTB->PDDR |= TOGE_LED_PIN;
    /* Set the initial output state to high */
    FPTB->PSOR |= TOGE_LED_PIN;
    FPTB->PDDR &= ~SW;
}
void delay(int i)
{
    int j;
    for(j=0;j<i;j++);
}

int main(void)
{
    init_led_button();
    while(1)
    {
      if(FPTB->PDIR & SW)
      {
      FPTB->PCOR |= TOGE_LED_PIN;
      }
      else
      {
        FPTB->PSOR |= TOGE_LED_PIN;
      }
      
    }
}
