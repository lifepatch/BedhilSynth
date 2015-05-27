/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "hardware_setup.h"


volatile unsigned long T_START = 40000;

volatile uint8_t slower_interval = 0;

volatile uint8_t current_song_index  = 0;

volatile unsigned long t; // long

volatile uint8_t snd; // 0...255



int main(void)
{
    //setup avr hardware
    //pots, adc, pwm, timer
    hw_init();

    //based on https://www.tty1.net/blog/2008/avr-gcc-optimisations_en.html
    for(;;)
        {

//         PORTB ^= (1 << PB1);
//         _delay_ms(500);

            if(pot1 > 20)
            {
                PORTB |= (1 << PB1); //set PB1 output 1
                _delay_ms(500);
            }else{

                PORTB &= ~(1 << PB1); //set PB1 output 0
            }

        }

    return 0;   /* never reached */
}




//PWM SUSTAIN TIMER freq = 10000 Hz
ISR(TIMER1_COMPA_vect)
{

    OCR0A = pot1;
}


//COMPB will be executed after COMPA
ISR(TIMER1_COMPB_vect)
{

//    ++slower_interval;

//    if (slower_interval> 100)
//        {
//            btn_debounce();
//            slower_interval = 0;
//        }
}
