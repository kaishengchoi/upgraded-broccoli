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
 * @brief Header file of week 1 programming assignment
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
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistcs of an input array
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function prints the statistics of an unsigned char array 
 * including minimum, maximum, mean, and median.
 *
 * @param array pointer to the unsigned char array whose statistics are to be printed.
 * @param length the length of the array
 *
 * @return None
 */
void print_statistics(unsigned char* array, int length) ;

/**
 * @brief Prints the array to the screen
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function prints the unsigned char array to screen. 
 *
 * @param array pointer to the unsigned char array which to be printed.
 * @param length the length of the array
 *
 * @return None
 */
void print_array(unsigned char* array, int length) ;

/**
 * @brief Find the median of an input array
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function returns the median of the input array.
 *
 * @param array pointer to the unsigned char array whose median is to be find.
 * @param length the length of the array
 *
 * @return median of the input array in usigned char
 */
unsigned char find_median(unsigned char* array, int length) ;

/**
 * @brief Find the mean of an input array
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function returns the mean of the input array.
 *
 * @param array pointer to the unsigned char array whose mean is to be find.
 * @param length the length of the array
 *
 * @return mean of the input array in usigned char
 */
unsigned char find_mean(unsigned char* array, int length) ;

/**
 * @brief Find the maximun value of an input array
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function returns the maximun value of the input array.
 *
 * @param array pointer to the unsigned char array whose maximun value is to be find.
 * @param length the length of the array
 *
 * @return maximum value of the input array in usigned char
 */
unsigned char find_maximum(unsigned char* array, int length) ;

/**
 * @brief Find the minimum value of an input array
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function returns the minimum value of the input array.
 *
 * @param array pointer to the unsigned char array whose minimum value is to be find.
 * @param length the length of the array
 *
 * @return minimun value of the input array in usigned char
 */
unsigned char find_minimum(unsigned char* array, int length) ;

/**
 * @brief Sort the input array
 *
 * This function takes the inputs of pointer to an unsigned char array and its 
 * length. This function sorts the array from largest to smallest.The zeroth Element 
 * should be the largest value, and the last element (n-1) should be the smallest value.
 *
 * @param array pointer to the unsigned char array which to be sorted.
 * @param length the length of the array
 *
 * @return None
 */
void sort_array(unsigned char* array, int length) ;

#endif /* __STATS_H__ */
