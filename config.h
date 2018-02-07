/* 
 * File:   config.h
 * Author: Phil Glazzard
 * Date: 14/01/2018
 * Revision history: 0.1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


// PIC16F690 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000      // 4MHz internal clock
#define GRN_LED PORTCbits.RC3   // pin 7
//#define BLU_LED PORTCbits.RC0   // pin 16
#define DT PORTAbits.RA2        // pin 17 - rotary encoder switch output DT
#define CLK PORTCbits.RC5       // pin 5 - rotary encoder switch output CLK
#define hi 1
#define lo 0
typedef unsigned char uchar;
#define NOT_PUSHED 1
#define PUSHED_BOUNCING 2
#define PUSHED_STABLE 3
#define RELEASED_BOUNCING 4
#define a PORTCbits.RC5 //  debounce input a pin 5 rotary encoder pin CLK
#define b PORTAbits.RA2 //  debounce input b pin 17 rotary encoder pin DT
#define led_output_a PORTCbits.RC4    // RED led output active when a is debounced pin 6
#define led_output_b PORTCbits.RC3    // GREEN led output active when a is debounced pin 7
uchar a_status; 
uchar b_status;
volatile int count;     // numerical position value of rotary encoder (0 to 76 in this design)
volatile int previous_count;    
volatile int tens;      // numerical value of tens SS LED value
volatile int units;     // numerical value of units SS LED value

   
#define COUNT_MAX 76    // maximum volume reading on  SS LED's
#define COUNT_MIN 0     // minimum volume reading on SS LED's
//**********************SPI CONSTANTS***********************************************
#define normal_operation_addr 0x0C //normal operation mode hi byte
#define shut_down_data 0x00         // shutdown mode hi byte
#define normal_operation_data 0x01 //normal operation mode lo byte
#define decode_off_addr 0x09 // no BCD decoding needed hi byte
#define decode_off_data 0x00 // no BCD decoding needed lo byte
#define scan_limit_addr 0x0B // display  columns address
#define scan_limit_data 0x01 // display 0 and 1 columns of leds lo byte
#define display_intensity_addr 0x0A // minimum display intensity hi byte
#define display_intensity_data 0x00 // minimum display intensity lo byte
#define no_op_addr 0x00 // No operation address
#define no_op_data 0x0f // No operation data
#define display_test_addr 0x0f  // display test turns all leds on and overides shutdown

//**********************DEFINITIONS OF PORT IN/OUTPUTS************************
//*************SPI pins*******************************************************
#define CS PORTCbits.RC6        // LOAD/ CS pin 8
#define SCK PORTBbits.RB6       // serial clock pin 11
#define SDO PORTCbits.RC7       // serial data out pin 9
//******LED segment/PORT pin definitions*****************************
#define E PORTAbits.RA0     // pin 19 MCU goes to segment E                                
#define D PORTAbits.RA1     // pin 18 MCU goes to segment D          
#define C PORTCbits.RC1     // pin 15 MCU goes to segment C   
#define B PORTCbits.RC2     // pin 14 MCU goes to segment B   
#define A PORTBbits.RB4     // pin 12 MCU goes to segment A   
#define G PORTCbits.RC0     // pin 16 MCU goes to segment G   
#define F PORTAbits.RA4     // pin 3 MCU goes to segment F  

// LED digits enable
#define TENS PORTAbits.RA5      // anode enable for SS LED DISPLAY (TENS))
#define UNITS PORTCbits.RC4     // anode enable for SS LED DISPLAY (UNITS))
