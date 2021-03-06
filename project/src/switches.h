#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p2.0 */
#define SW2 BIT1		/* switch1 is p2.1 */
#define SW3 BIT2		/* switch1 is p2.2 */
#define SW4 BIT3		/* switch1 is p2.3 */

#define SWITCHES (SW1 | SW2 | SW3 | SW4)	
/* all 4 switches from the board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4, switch_state_changed; /* effectively boolean */

#endif // included
