/**
 * @file <stats.h> 
 * @brief <File with function definations for stats.c >
 *
 * <Stats is nothing but a program that returns the details and analysis performed on an Array>
 *
 * @author <SOHAM JANI>
 * @date <17 April 2017 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_statistics(unsigned char *array, int size);

/**
 * @brief < A function that prints the statistics of an array including minimum, maximum, mean, and median.>
 *
 * <Add Extended Description Here>
 *
 * @param <array> <is a pointer to the test array>
 * @param <size> <size of the array>
 * @return <Returns nothing> <Prints the stats using printf>
 */

void print_array(unsigned char *array, int length);
/*
 * @brief <Given an array of data and a length, prints the array to the screen>
 * @param <array> <pointer to the test array>
 * @return <none> 
*/

int find_median(unsigned char *array, int length);
/*
 * @brief < Given an array of data and a length, returns the median value>
*/

int find_mean(unsigned char *array, int length);
/*
 * Given an array of data and a length, returns the mean
*/

int find_maximum(unsigned char *array, int length);
/* 
 *  Given an array of data and a length, returns the maximum
*/

int find_minimum(unsigned char *array, int length);
/* 
 * Given an array of data and a length, returns the minimum
*/

unsigned char* sort_array(unsigned char *array, int length);
/* 
 * Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
*/


#endif /* __STATS_H__ */
