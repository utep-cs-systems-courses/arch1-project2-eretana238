#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4, switch_state_changed; /* effectively boolean */

char state;

static char 
switch_update_interrupt_sense() {
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init() { /* setup switch */ 
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down1 = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_down2 = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  switch_state_down3 = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  switch_state_down4 = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */

  /* updates states based on which switch is pressed */
  state = (p2val & SW1) ? state : 1;
  state = (p2val & SW2) ? state : 2;
  state = (p2val & SW3) ? state : 3;
  state = (p2val & SW4) ? state : 4;
  
  if(state != 4)
    buzzer_set_period(0); /* resets buzzer if another state is selected */
  

  switch_state_changed = 1;
  led_update();
}

