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

volatile uint8_t play = 0;

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

            if(pot2 > 20)
            {
                play = 1;
                PORTB |= (1 << PB3); //set PB3 output 1
                _delay_ms(25);
                play = 0;
            }else{
                PORTB &= ~(1 << PB3); //set PB3 output 0
            }

        }

    return 0;   /* never reached */
}




//PWM SUSTAIN TIMER freq = 10000 Hz
ISR(TIMER1_COMPA_vect)
{
    if (play > 0)
    {
        snd = (3*5&t>>7)|(t*12&t>>10);
        OCR0A = snd;
        t++;
    }else{
        OCR0A = 0;
    }
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
