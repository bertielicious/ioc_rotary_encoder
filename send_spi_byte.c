/*
 * File:   send_spi_byte.c
 * Author: philip
 *
 * Created on 27 January 2018, 16:21
 */


#include <xc.h>
#include "config.h"
void send_spi_byte(uchar addr, uchar data) 
{
   SSPBUF = addr;       // send 8 bit address MSB first
   while(!SSPSTATbits.BF)   // send data until buffer is full
   {
       ;
   }
   SSPBUF = data;       // send 8 bit address MSB first
   while(!SSPSTATbits.BF)   // send data until buffer is full
   {
       ;
   }
}
