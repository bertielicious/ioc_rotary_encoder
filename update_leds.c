/*
 * File:   update_leds.c
 * Author: philip
 * This function takes the value of count from isr() and assigns it's value to 1 of 16
 * led's (a sixteen led bargraph), which would be positioned in a circle around the volume control
 * Created on 27 January 2018, 17:48
 */


#include <xc.h>
#include "config.h"
#include "send_spi_byte.h"
#include <stdio.h>
#include "putch.h"
void update_leds(void) 
{
    int step = 0;
    step = count;
    //switch (step - 1)
    
    if(0<= step && step <6)
    {
                CS = 0;
                send_spi_byte(0x01, 0x01);// turn on led 1 (address 0x01)
                CS = 1;
                CS = 0;
                send_spi_byte(0x02, 0x00);  // turn off led 9 (address 0x02))
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(6<= step && step < 11)
    { 
                CS = 0;
                send_spi_byte(0x01, 0x02 + 0x01);
                CS = 1;
                printf("step = %d\n", step);
    }   
    else if(10< step  && step < 16) 
    {
                CS = 0;
                send_spi_byte(0x01, 0x04 + 0x03);
                CS = 1;
                printf("step = %d\n", step);
    }    
    else if(15 < step && step < 21) 
    { 
                CS = 0;
                send_spi_byte(0x01, 0x08 +0x07);
                CS = 1;
                printf("step = %d\n", step);
    }   
    else if(20 < step && step < 26) 
    { 
                CS = 0;
                send_spi_byte(0x01, 0x10 + 0x0f);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(25 < step && step  < 31) 
    {
                CS = 0;
                send_spi_byte(0x01, 0x20 + 0x1f);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(30 < step && step < 36) 
    { 
                CS = 0;
                send_spi_byte(0x01, 0x40 + 0x3f);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(35 < step && step < 41) 
    {
                CS = 0;
                send_spi_byte(0x01, 0x80 + 0x7f);
                CS = 1;
                CS = 0;
                send_spi_byte(0x02, 0x00);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(40< step && step < 46) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x01);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(45< step && step < 51) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x03);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(50 < step && step < 56) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x07);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
    }
    else if(55< step && step < 61) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x0f);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
     }
    else if(60< step && step < 66) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x1f);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
     }
    else if(65< step && step < 71) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x3f);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
     }
    else if(70< step && step < 76) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0x7f);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
     }
    else   if(75< step && step < 81) 
    { 
                CS = 0;
                send_spi_byte(0x02, 0xff);
                CS = 1;
                CS = 0;
                send_spi_byte(0x01, 0xff);
                CS = 1;
                printf("step = %d\n", step);
    }           
}
