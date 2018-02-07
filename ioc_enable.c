/*
 * File:   ioc_enable.c
 * Author: philip
 *
 * Created on 14 January 2018, 19:17
 */


#include <xc.h>
#include "config.h"
void ioc_enable(void) 
{
    INTCONbits.GIE = 1;
    INTCONbits.INTE = 1;
    OPTION_REGbits.INTEDG = 0;  //interrupt of falling edge of 
}
