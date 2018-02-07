/*
 * File:   load.c
 * Author: philip
 *
 * Created on 27 January 2018, 15:18
 */


#include <xc.h>
#include "config.h"

void load(void) 
{
    CS = 0;
    __delay_ms(1);
    CS = 1;
}
