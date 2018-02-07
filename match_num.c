/*
 * File:   match_num.c
 * Author: philip
 *
 * Created on 30 January 2018, 20:28
 */


#include <xc.h>
#include "match_num.h"
#include "config.h"
void match_num(int digit) 
{
   switch (digit) 
   {
           case 0:          // decoding for num zero
               A = 0;
               B = 0;
               C = 0;
               D = 0;
               E = 0;
               F = 0;
               G = 1;
               break;
           case 1:          // decoding for num zero
               A = 1;
               B = 0;
               C = 0;
               D = 1;
               E = 1;
               F = 1;
               G = 1;
               break;
           case 2:          // decoding for num zero
               A = 0;
               B = 0;
               C = 1;
               D = 0;
               E = 0;
               F = 1;
               G = 0;
               break;
           case 3:          // decoding for num zero
               A = 0;
               B = 0;
               C = 0;
               D = 0;
               E = 1;
               F = 1;
               G = 0;
               break;
          case 4:          // decoding for num zero
               A = 1;
               B = 0;
               C = 0;
               D = 1;
               E = 1;
               F = 0;
               G = 0;
               break;
          case 5:          // decoding for num zero
               A = 0;
               B = 1;
               C = 0;
               D = 0;
               E = 1;
               F = 0;
               G = 0;
               break;
          case 6:          // decoding for num zero
               A = 0;
               B = 1;
               C = 0;
               D = 0;
               E = 0;
               F = 0;
               G = 0;
               break;
          case 7:          // decoding for num zero
               A = 0;
               B = 0;
               C = 0;
               D = 1;
               E = 1;
               F = 1;
               G = 1;
               break;
          case 8:          // decoding for num zero
               A = 0;
               B = 0;
               C = 0;
               D = 0;
               E = 0;
               F = 0;
               G = 0;
               break;
          case 9:          // decoding for num zero
               A = 0;
               B = 0;
               C = 0;
               D = 0;
               E = 1;
               F = 0;
               G = 0;
               break;
           default:          
               A = 1;
               B = 1;
               C = 1;
               D = 1;
               E = 1;
               F = 1;
               G = 1;
               break;
   }                
}
