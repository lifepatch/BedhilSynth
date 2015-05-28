# BedhilSynth

Kode dan skematik untuk karya Lifepatch di ArtJog 2015

![stepseq](https://raw.githubusercontent.com/8BitMixtape/sequencer_lib/master/examples/8BitMixtapeSequencer/breadboard_bb.png)

## Install

1. Install Arduino-tiny core from https://code.google.com/p/arduino-tiny or https://github.com/TCWORLD/ATTinyCore
2. From Arduino Ide choose Tools > Boards > **ATtiny85 @ 16Mhz (internal PLL; 4.3 V BOD)**
3. Tools > Burn Bootloader
4. Upload Sketch




## Pin Configuration

``` c
// ATTINY85 BedhilLaserSynth pin
//
//                               +-\/-+
//  Ain0           (D  5)  PB5  1|    |8   VCC
//  laser out PB3  (D  3)  PB3  2|    |7   PB2  (D  2)  Piezo Input / pot2
//  Pot1           (D  4)  PB4  3|    |6   PB1  (D  1)        Laser Output
//                         GND  4|    |5   PB0  (D  0)        pwm0 ====> OCR0A / sound output
//                               +----+
//
//  Clock Frequency 16 Mhz PLL Internal
//  Timer1 running @ 8 Khz for sound output
//  PWM @ PB0 - OCR0A
//                            +----+                            +----+
```