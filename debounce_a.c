/*
 * File:   debounce_a.c
 * Author: philip
 *
 * Created on 10 January 2018, 18:40
 */


#include <xc.h>
#include "debounce_a.h"
#include "config.h"
uchar a_de = 0;
uchar current_state = NOT_PUSHED;
uchar debounce_a(void)
{
    if((a == hi) && (current_state == NOT_PUSHED))   // current_state NOT_PUSHED
        {                                                       // next_state NOT_PUSHED
           led_output_a = lo;
           current_state = NOT_PUSHED;
           a_de = 0;
           return a_de;
        }
        else if ((a == lo) && (current_state == NOT_PUSHED))   // current_state NOT_PUSHED 
        {                                                           // next_state MAYBE_PUSHED
            current_state = PUSHED_BOUNCING;
            led_output_a = lo;
            a_de = 0;
            return a_de;
        }
        if ((a == hi) && (current_state == PUSHED_BOUNCING))         // state MAYBE_PUSHED
        {
            current_state = NOT_PUSHED;
            led_output_a = lo;
            a_de = 0;
            return a_de;
        }
        else if((a == lo) && (current_state == PUSHED_BOUNCING))     // state PUSHED
        {
            current_state = PUSHED_STABLE;
            led_output_a = lo;
            a_de = 0;
            return a_de;
        }

        if ((a == lo) && (current_state == PUSHED_STABLE))
        {
            current_state = PUSHED_STABLE;
            led_output_a = hi;
            a_de = 1;
            return a_de;
        }
        else if ((a == hi) && (current_state == PUSHED_STABLE))
        {
           current_state = RELEASED_BOUNCING;
           led_output_a = lo;
           a_de = 0;
           return a_de;
        }
        if ((a == lo) && (current_state == RELEASED_BOUNCING))
        {
            current_state = PUSHED_STABLE;
            //current_state = NOT_PUSHED;
            led_output_a = lo ;
            a_de = 0;
            return a_de;
        }
        else if ((a == hi) && (current_state == RELEASED_BOUNCING))
        {
            current_state = NOT_PUSHED;
            led_output_a = lo;
            a_de = 0;
            return a_de;
        }  
}
