/*
 * File:   init_max7219.c
 * Author: philip
 *
 * Created on 27 January 2018, 16:14
 */


#include <xc.h>
#include "config.h"
#include "send_spi_byte.h"
void init_max7219(void) 
{
    CS = 0;
    send_spi_byte (normal_operation_addr, shut_down_data);
    CS = 1;
    
    CS = 0;
    send_spi_byte (display_intensity_addr, display_intensity_data);
    CS = 1;
    
    CS = 0;
    send_spi_byte (decode_off_addr, decode_off_data);
    CS = 1;
    
    CS = 0;
    send_spi_byte (display_test_addr, shut_down_data);
    CS = 1;
    
    CS = 0;
    send_spi_byte (scan_limit_addr, scan_limit_data);
    CS = 1;
    
    CS = 0;
    send_spi_byte (normal_operation_addr, normal_operation_data);
    CS = 1;
}
