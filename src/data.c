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
 * @file data.c
 * @brief Convertion between integer and ASCII
 *
 * This implementation file provides an abstraction of converting between integer
 * and ASCII string. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "data.h"
#include "memory.h"
#include <stdbool.h>
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    
    int length = 1;
    uint8_t * temp_ptr = ptr;
    uint32_t temp = (uint32_t)((data < 0) ? data*(-1): data);
    *(temp_ptr++) = 0;  

    do {
        uint8_t rem = temp % base;
        *(temp_ptr++) = (rem > 9)? (rem + 65): (rem + 48);
        temp /= base;
        length++;
    } while (temp != 0);

    if (data < 0){
        *(temp_ptr++) = 45;
        length++;
    }
    
    my_reverse(ptr, length);

    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

    int32_t data = 0;
    uint8_t temp = 0;
    bool isSigned = false;

    for (int i = 0; i < digits-1; i++) {
        temp = *(ptr++);
        data *= base;
        if (temp == 45) {
            isSigned = true;
        } else if (temp != 0) {
            data += (temp-((temp >= 65)?65:48));
        }
    }

    if (isSigned) data *= -1;

    return data;
}