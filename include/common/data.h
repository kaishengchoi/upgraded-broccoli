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
 * @file data.h
 * @brief Convertion between integer and ASCII
 *
 * This header file provides an abstraction of converting between integer and
 * ASCII string.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Convert integer to ASCII string
 *
 * Convert data from a standard integer type into an ASCII string
 *
 * @param data Number to be converted
 * @param ptr Pointer to stored the converted string
 * @param base Base number that data will be converted to
 *
 * @return Number of digits of converted base number.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert ASCII string to integer
 *
 * Convert data back from an ASCII represented string into an integer type.
 *
 * @param ptr Pointer to ASCII string to be converted to integer
 * @param digits Number of digits of inputed ASCII string
 * @param base Base number of ASCII string
 *
 * @return Converted signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */