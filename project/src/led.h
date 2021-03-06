#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern char blinking_state;
extern char led_state;
extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void toggle_red();
void toggle_green();

void toggle_leds();
void led_init();
void led_update();

void led_red_on();
void led_green_on();
void led_reset();

#endif // included
