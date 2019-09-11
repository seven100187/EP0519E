#include <MKL46Z4.h>
#include <stdlib.h>
#define LED1 (1<<29)
#define LED2 (1<<5)
#define COUNTER (8000 - 1)
#define MAX 10
uint32_t tick = 0;

typedef struct
{
  uint32_t LOADVAL;
  uint32_t CURRENTVAL;
  void (*callback)(void);
}sw_timer;

sw_timer gsw_timer[MAX];

void init_sw_timer()
{
  uint32_t i;
  for(i=0;i<MAX;i++){
    gsw_timer[i].LOADVAL = 0;
    gsw_timer[i].CURRENTVAL = 0;
    gsw_timer[i].callback = NULL;
  }
}

void add_sw_timer(sw_timer * sw)
{
  uint32_t i=0;
  while(gsw_timer[i].callback != NULL)
  {
    i++;
  }
  gsw_timer[i].LOADVAL = sw->LOADVAL;
  gsw_timer[i].CURRENTVAL = sw->LOADVAL;
  gsw_timer[i].callback = sw->callback;
}

void remove_sw_timer(uint32_t index)
{
    gsw_timer[index].LOADVAL = 0;
    gsw_timer[index].CURRENTVAL = 0;
    gsw_timer[index].callback = NULL;
}

void init_led()
{
  SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
  PORTE->PCR[29] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTE->PCR[29] |= PORT_PCR_MUX(1);
  GPIOE->PDDR |= (uint32_t)LED1;
  
  PORTD->PCR[5] &= ~(uint32_t)(PORT_PCR_MUX_MASK);
  PORTD->PCR[5] |= PORT_PCR_MUX(1);
  GPIOD->PDDR |= (uint32_t)LED2;
}

void blink_led1()
{
  GPIOE->PTOR |= (uint32_t)LED1;
}

void blink_led2()
{
  GPIOD->PTOR |= (uint32_t)LED2;
}
void init_pit()
{
  SIM->SCGC6 |= (uint32_t)SIM_SCGC6_PIT_MASK;
  
  PIT->CHANNEL[0].LDVAL = (uint32_t)COUNTER;
  PIT->CHANNEL[0].TCTRL |= (uint32_t)(1<<1);
  PIT->CHANNEL[0].TCTRL |= (uint32_t)(1<<0);
  PIT->MCR &= ~(uint32_t)(1<<1); 
}

void PIT_Interrupt_setup()
{
  NVIC_ClearPendingIRQ(PIT_IRQn);
  NVIC_SetPriority(PIT_IRQn,0);
  NVIC_EnableIRQ(PIT_IRQn);
}

void PIT_IRQHandler()
{
  PIT->CHANNEL[0].TFLG |= (uint32_t)(1<<0);
  tick++;
  uint32_t i;
  for(i=0;i<MAX;i++)
  {
    if(gsw_timer[i].callback != NULL)
    {
      gsw_timer[i].CURRENTVAL--; 
      if(gsw_timer[i].CURRENTVAL == 0)
      {
        gsw_timer[i].CURRENTVAL = gsw_timer[i].LOADVAL;
        gsw_timer[i].callback();
      }
    }
  }
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
  SIM->CLKDIV1 |= (uint32_t)SIM_CLKDIV1_OUTDIV1(0);
  SIM->CLKDIV1 |= (uint32_t)SIM_CLKDIV1_OUTDIV4(2);
}

int main()
{
  sw_timer sw1_timer;
  sw_timer sw2_timer;
  
  FEI_8Mhz();
  init_led();
  init_pit();
  PIT_Interrupt_setup();
  
  sw1_timer.LOADVAL = 500;
  sw1_timer.callback = blink_led1;
  
  sw2_timer.LOADVAL = 2000;
  sw2_timer.callback = blink_led2;
  
  add_sw_timer(&sw1_timer);
  add_sw_timer(&sw2_timer);
  while(1);
}