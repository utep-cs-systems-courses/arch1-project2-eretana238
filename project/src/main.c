//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

int main(void) {
  /* setup master oscillator, CPU & peripheral clocks */
  configureClocks();		
  
  switch_init();
  
  led_init();
  /* check state here?? */

  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
