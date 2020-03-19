#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char led_state = 0;
char state;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void toggle_leds() {
  switch (led_state) {
    case 0: 
      led_red_on();
      break;
    case 1: 
      led_green_on();
      break;
    }

    led_state ^= 1;
}

void led_reset() {
  red_on = 0;
  green_on = 0;
}

void led_red_on() {
  red_on = 1;
  green_on = 0;

}

void led_green_on() {
  red_on = 0;
  green_on = 1;
}

void led_init() {
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update() {
<<<<<<< HEAD
  char ledFlags = 0;
  if (blinking_state) {
    ledFlags = redVal[red_on] | greenVal[green_on];
  }
  else {
    ledFlags = greenVal[green_on];
  }
  
  P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
  P1OUT |= ledFlags;		     // set bit for on leds
  led_changed = 0;
}


=======
  if(led_changed){
    if (blinking_state) {
      char ledFlags = redVal[red_on] | greenVal[green_on];
    }
    else {
      char ledFlags = greenVal[green_on];
    }
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
  
}
>>>>>>> fbdffb44244f25acf7d138b7effa3b97add4e6c4
