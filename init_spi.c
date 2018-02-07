/*
 * File:   init_spi.c
 * Author: philip
 *
 * Created on 27 January 2018, 16:37
 */


#include <xc.h>
#include "config.h"

void init_spi(void) 
{
    SSPCONbits.SSPM = 0001;
    SSPCONbits.CKP = 0;
    SSPCONbits.SSPEN = 1;
    SSPCONbits.SSPOV = 0;
    SSPCONbits.WCOL = 0;
    SSPSTATbits.CKE = 1;
    SSPSTATbits.SMP = 1;
    CS = 1;
}
