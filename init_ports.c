/*
 * File:   init_ports.c
 * Author: philip
 *
 * Created on 14 January 2018, 18:53
 */


#include <xc.h>
#include "init_ports.h"

void init_ports(void) 
{
    ANSEL = 0x00;   // ADC module off
    ANSELH = 0x00;
    CM1CON0 = 0x00; // Comparators off
    CM2CON0 = 0x00;
    
    TRISAbits.TRISA2 = 1;   //RA2 input pin 17
    TRISCbits.TRISC5 = 1;   // RC5 input pin 5
    TRISCbits.TRISC3 = 0;   // GRN_LED output pin 7
    TRISCbits.TRISC6 = 0;   // CS pin 8
    TRISCbits.TRISC7 = 0;   // serial data out pin 9
    TRISBbits.TRISB6 = 0;   // SCK pin 11
    //RED_LED = 0;
    GRN_LED = 0;
    //BLU_LED = 0;
    // PORT setup for multiplexed LED display
    TRISAbits.TRISA5 = 0;   // output - drives the multiplexing signal for tens digit
    TRISCbits.TRISC4 = 0;   // output - drives the multiplexing signal for units digit
    TRISAbits.TRISA0 = 0;   // output - drives segment e of 7 seg display
    TRISAbits.TRISA1 = 0;   // output - drives segment d
    TRISCbits.TRISC1 = 0;   // output - drives segment c
    TRISCbits.TRISC2 = 0;   // output - drives segment b
    TRISBbits.TRISB4 = 0;   // output - drives segment a
    TRISCbits.TRISC0 = 0;   // output - drives segment g
    TRISAbits.TRISA4 = 0;   // output - drives segment d
    PORTAbits.RA5 = 1;      // tens LED off
    PORTCbits.RC4 = 1;      // units LED off
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTCbits.RC1 = 0;
    PORTCbits.RC2 = 0;
    PORTBbits.RB4 = 0;
    PORTCbits.RC0 = 0;
    PORTAbits.RA4 = 0;
}
