/*
 * File:   interrupt isr.c
 * Author: philip
 *
 * Created on 14 January 2018, 19:38
 */


#include <xc.h>
#include "config.h"
#include "interrupt isr.h"
#include <stdio.h>
#include "update_leds.h"
#include "sev_seg.h"


void interrupt isr(void) 
{
    uchar clear_port_a = 0;
    if(INTCONbits.INTF == 1)
    {
        if(CLK == hi)       // clockwise movement of the knob
        { 
            count++;
            update_leds();
        }
        else if (CLK == lo) // anti-clockwise movement of the knob
        {
            count--;
            update_leds();
        }
     
    if (count >= COUNT_MAX)
    {
        count = COUNT_MAX;
    }
    if(count <= COUNT_MIN)
    {
        count = COUNT_MIN;
    }
        if((previous_count != count) && (count != COUNT_MAX) && (count != COUNT_MIN))
        {
            printf("volume position = %d\n", count);  // display latest value of count via serial monitor
        }
        
        previous_count = count;    
    }
    clear_port_a = PORTA;
    INTCONbits.INTF = 0;
}