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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdlib.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t * temp_dst = dst;
  if (src <= dst && (src + length - 1) >= dst) {
    temp_dst += (length - 1);
    src += (length - 1);
    for (int i = 0; i < length; i++)
      *(temp_dst--) = *(src--);
  } else {
    for (int i = 0; i < length; i++)
      *(temp_dst++) = *(src++);
  }
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t * temp_dst = dst;
  for (int i = 0; i < length; i++)
    *(temp_dst++) = *(src++);
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  uint8_t * temp_src = src;
  for (int i = 0; i < length; i++)
    *(temp_src++) = value;
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  size_t j = (size_t)(length/2);
  uint8_t * head_src = src;
  uint8_t * end_src = src + length - 1;
  uint8_t temp;
  for (int i = 0; i < j; i++){
    temp = *head_src;
    *(head_src++) = *end_src;
    *(end_src--) = temp;
  }
  return src;
}

int32_t * reserve_words(size_t length) {
  return (int32_t *) malloc(length * sizeof(int32_t));
}

void free_words(uint32_t * src){
  free(src);
}
