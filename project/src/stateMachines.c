#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "soundEngine.h"
#include "buzzer.h"

char state = 1;

char blinking_state; /* either blinking slow (1) or really fast (0) */

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;

short song_state;

/* the function below was translated to assembly */
/*
void state_advance() {

  switch(state) {
  case 0:
    blinking_state = 1;
    toggle_leds();
    song_state = 0;
    break;

  case 1:
    blinking_state = 0; // 0 == dimming lights 
    toggle_red();
    song_state = 0;
    break;
    
  case 2:
    blinking_state = 0; // 0 == dimming lights 
    toggle_green();
    song_state = 0;
    break;

  case 3:
    blinking_state = 1;
    toggle_leds();
    play_song();
    break;
  }

  led_changed = 1;
  led_update();
}

*/
