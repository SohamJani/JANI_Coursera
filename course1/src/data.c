
/**
* uint8_t, uint16_t, uint32_t and uint64_t
* unsigned char, unsigned short, unsigned int and unsigned long long.
**/

#include<stdint.h>
#include <stdlib.h>
#include<math.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

  uint8_t my_char;

  my_char = (uint8_t) data;
  (*ptr) = my_char;
  uint8_t length = (uint8_t) (floor(log10(abs(data))) + 1); 
  return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

  int32_t my_int;
  uint8_t ptr_int = *ptr;
  my_int = (int32_t) ptr_int; 
  
  return my_int;
}


