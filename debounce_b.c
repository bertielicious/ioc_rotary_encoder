/*
 * File:   debounce_b.c
 * Author: philip
 *
 * Created on 11 January 2018, 16:07
 */


#include <xc.h>
#include "debounce_b.h"
#include "config.h"

uchar b_de = 0;
uchar current_state_b = NOT_PUSHED;
uchar debounce_b(void)
{
    if((b == hi) && (current_state_b == NOT_PUSHED))   // current_state NOT_PUSHED
        {                                            // next_state NOT_PUSHED
           led_output_b = lo;
           current_state_b = NOT_PUSHED;
           b_de = 0;
           return b_de;
        }
        else if ((b == lo) && (current_state_b == NOT_PUSHED))   // current_state NOT_PUSHED 
        {                                                           // next_state MAYBE_PUSHED
            current_state_b = PUSHED_BOUNCING;
            led_output_b = lo;
            b_de = 0;
            return b_de;
        }
        if ((b == hi) && (current_state_b == PUSHED_BOUNCING))         // state MAYBE_PUSHED
        {
            current_state_b = NOT_PUSHED;
            led_output_b = lo;
            b_de = 0;
            return b_de;
        }
        else if((b == lo) && (current_state_b == PUSHED_BOUNCING))     // state PUSHED
        {
            current_state_b = PUSHED_STABLE;
            led_output_b = lo;
            b_de = 0;
            return b_de;
        }
        
        if ((b == lo) && (current_state_b == PUSHED_STABLE))
        {
            current_state_b = PUSHED_STABLE;
            led_output_b = hi;
            b_de = 1;
            return b_de;
        }
        else if ((b == hi) && (current_state_b == PUSHED_STABLE))
        {
           current_state_b = RELEASED_BOUNCING;
           led_output_b = lo;
           b_de = 0;
           return b_de;
        }
        if ((b == lo) && (current_state_b == RELEASED_BOUNCING))
        {
            current_state_b = PUSHED_STABLE;
            //current_state_b = NOT_PUSHED;
            led_output_b = lo ;
            b_de = 0;
            return b_de;
        }
        else if ((b == hi) && (current_state_b == RELEASED_BOUNCING))
        {
            current_state_b = NOT_PUSHED;
            led_output_b = lo;
            b_de = 0;
            return b_de;
        }  
}
