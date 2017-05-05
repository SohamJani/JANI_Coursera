/**
 * @file <stats.c> 
 * @brief <Does some array computation >
 *
 * <Will need verbose input to decide what to print>
 *
 * @author <Soham Jani >
 * @date <Add date >
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
/*
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

   Other Variable Declarations Go Here 

   Statistics and Printing Functions Go Here 
  print_array(test,SIZE);
  print_statistics(test, SIZE);
  printf("\nEnd of output.....\n");
  return 0;
}
*/


/* Add other Implementation File Code Here */

void print_statistics(unsigned char *array, int size)
{
  printf("This is the Statistics function-- \n");
  printf("  The mean is: %d \n",find_mean(array, size));
  printf("  The median is: %d \n ",find_median(array, size));
  printf(" The Maximum is: %d \n",find_maximum(array,size));
  printf("  The Minimum is: %d \n",find_minimum(array,size));  
}

void print_array(unsigned char *array, int length)
{
  printf("\n The array is: ");
  for(int i=0; i<length; i++)
  {
   printf("%d ",array[i]);
  }
  printf("\n");
}

int find_median(unsigned char *array, int length)
{
 //Data at the centre
  unsigned char *new_ar;
  new_ar = sort_array(array, length); 
  int median = (new_ar[(length/2)-1]+new_ar[(length/2)+1-1])/2;
  return median; 
}

int find_mean(unsigned char *array, int length)
{
  int sum=0;
  for(int i=0; i<length; i++)
  {
   sum += array[i];
  }
  return sum/length;
}

int find_maximum(unsigned char *array, int length)
{
  int temp = 0;
  for(int i=0; i<length; i++)
  {
    if(array[i]>temp)
    {
      temp=array[i];
    }
  }
  return temp;
}

int find_minimum(unsigned char *array, int length)
{
  int temp = array[0];
  for(int i=0; i<length; i++)
  {
    if(array[i]<temp)
    {
      temp=array[i];
    }
  }
  return temp;

}

unsigned char* sort_array(unsigned char *array, int length)
{
  unsigned char *number; 
  number = array;
  int n = length;
  int a;
      for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (number[i] < number[j])
            {
                a =  number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
  return number;
}




