
/**
* uint8_t, uint16_t, uint32_t and uint64_t
* unsigned char, unsigned short, unsigned int and unsigned long long.
**/

#include <stdlib.h>
#include<stdint.h>
#include<math.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

  uint8_t my_char;

  my_char = (uint8_t) data;
  (*ptr) = my_char;
  int32_t x = data;
    if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1; 
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

  int32_t my_int;
  uint8_t ptr_int = *ptr;
  my_int = (int32_t) ptr_int; 
  
  return my_int;
}


