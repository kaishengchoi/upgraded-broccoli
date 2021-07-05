/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Implementation file of week 1 programming assignment
 *
 * A simple application that performs statistical analytics on a dataset. This 
 * programs consists a couple of functions that can analyze an arrat of unsigned 
 * char data items anf report analytics on the maximum, minimun, mean, and median 
 * of dataset.
 *
 * @author KaiShengChoi (Derrick)
 * @date 11 March 2021
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/**
 * @brief Swaps the value between 2 variable
 *
 * This function takes the inputs of pointer to 2 unsigned char variable.
 * This function Swap the value between 2  unsigned char variable.
 *
 * @param p pointer to the unsigned char variable
 * @param q pointer to the unsigned char variable
 *
 * @return None
 */
void swap(unsigned char *p, unsigned char *q);

/* Add other Implementation File Code Here */

void print_statistics(unsigned char* array, int length) {
  
  print_array(array, length);
  PRINTF ("Median : %d\r\n", find_median(array, length));
  PRINTF ("Mean : %d\r\n", find_mean(array, length));
  PRINTF ("Maximum : %d\r\n", find_maximum(array, length));
  PRINTF ("Minimum : %d\r\n", find_minimum(array, length));

}

void print_array(unsigned char* array, int length){
#ifdef VERBOSE
  for ( int i = 0 ; i < length ; i++ ) {
    PRINTF("index %d : %d\t", i, array[i]);
    if ( (i+1)%8 == 0 )
      PRINTF("\r\n");
  }
#endif
}

unsigned char find_median (unsigned char* array, int length) {
  
  sort_array(array, length);

  if ( length%2 == 0 )
    return (array[(length-1)/2] + array[length/2])/2;
  else
    return array[length/2];

}

unsigned char find_mean (unsigned char* array, int length) {
  int sum = 0;
  for( int i = 0; i < length; i++ )
    sum += array[i];

  return (unsigned char)(sum/length);

}

unsigned char find_maximum (unsigned char* array, int length) {
  unsigned char temp = array[0];
  for( int i = 1; i < length ; i++ ) 
    if (array[i] > temp)
      temp = array[i];
  return temp;
}

unsigned char find_minimum(unsigned char* array, int length) {
  unsigned char temp = array[0];
  for( int i = 1; i < length ; i++ ) 
    if (array[i] < temp)
      temp = array[i];
  return temp;
}

void sort_array(unsigned char* array, int length) {
  for( int i = 0; i < length-1 ; i++ ) {
    for( int j = 0; j < length-i-1 ; j++ ) {
        if ( array[j] > array[j+1] )
          swap( &array[j], &array[j+1] );
    }
  }
}

void swap(unsigned char *p, unsigned char *q) {
  unsigned char temp;
  temp = *p; 
  *p = *q; 
  *q = temp;
}