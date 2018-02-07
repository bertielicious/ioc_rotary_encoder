/*
 * File:   sev_seg.c
 * Author: philip
 *  this function takes the count value, splits it into tens and units, and decodes tens and units to allow
 * display on two seven segment displays
 * Created on 30 January 2018, 15:37
 */


#include <xc.h>
#include "config.h"
#include "match_num.h"
void sev_seg(void) 
{
    //tens = 7;
    //units = 3;
    tens = count/10;
    units = count%10; 
    if(UNITS == 1 && TENS == 0)
    {
    match_num(tens);
    }
    if(UNITS == 0 && TENS == 1)
    {
    match_num(units);
    }
    
    
}
