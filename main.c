/*
 * File:   main.c
 * Author: philip
 *
 * Created on 14 January 2018, 18:30
 */


#include <xc.h>
#include "config.h"
#include "init_ports.h"
#include "ioc_enable.h"
#include "set_usart.h"
#include "transmit_character.h"
#include "transmit_data.h"
#include <stdio.h>
#include "putch.h"
#include "debounce_a.h"
#include "debounce_b.h"
#include "interrupt isr.h"
#include "init_spi.h"
#include "init_max7219.h"
#include "clock.h"
#include "sev_seg.h"
#include "match_num.h"
#include "segments_off.h"



void main(void) 
{
    init_ports();
    init_spi();
    init_max7219();
    set_usart();
    char ton[] = " 100 step volume control demo\n";
    transmit_character(&ton[0]);
    printf( "audio_project\n");
    count = -1;
    previous_count = 0;
   
    ioc_enable();
    
    while(1)
    {
        /*TENS = 1; //this code creates 'bleed' between active and inactive
        UNITS = 0;  // LED segments
        sev_seg();
        __delay_ms(10);
        
        TENS = 0;
        UNITS = 1;
        sev_seg();
        __delay_ms(10); 
        //segments_off();*/
        
        TENS = 1;       // TENS SS LED is disabled
        UNITS = 1;      // UNITS SS LED is disabled
        segments_off(); // all segments high (off))
        TENS = 0;       // TENS SS LED is enabled
        sev_seg();      //split count into tens and units numbers
                        // if units enabled and tens disabled, lookup units value
        __delay_ms(5);
        
        TENS = 1;
        UNITS = 1;
        segments_off();
        UNITS = 0;
        sev_seg();      //split count into tens and units numbers
                        // if units disabled and tens enabled, lookup tens number
        __delay_ms(5);
        
        
    }   
}
