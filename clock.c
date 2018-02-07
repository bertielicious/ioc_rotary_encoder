/*
 * File:   clock.c
 * Author: philip
 *
 * Created on 27 January 2018, 15:08
 */


#include <xc.h>
#include "config.h"
#include "clock.h"
void clock(void) 
{
    TENS = 1;
    UNITS = 0;
    __delay_ms(500);
    TENS = 0;
    UNITS = 1;
    __delay_ms(500);
     
}
