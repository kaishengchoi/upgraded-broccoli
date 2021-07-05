#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the cortex-M4 and HOST(Linux) build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	   <FILE>.o - Builds <FILE>.o object file
#	   <FILE>.i - Generate the preprocessed output of the <FILE>.i
#      <FILE>.asm - Generate assembly output of <FILE>.asm
#      compile-all : Compiles all files, doesn't build
#	   build: Compile all object files and link into a final executable
#	   clean: removes all generated files.
#
# Platform Overrides:
#      CPU -  ARM Cortex Architecture(cortex-m4)
#	   ARCH - ARM Architecture (thumb)
#	   SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m4
PPFS = $(SOURCES:.c=.i)
ASMs = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

ifeq ($(PLATFORM),HOST)

	CC = gcc
	LD = ld
	OBJDUMP = objdump
	SIZE = size

	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGs = -DHOST -MD -MP -DCOURSE1 -DVERBOSE 

else ifeq ($(PLATFORM),MSP432)

	LINKER_FILE = ./msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs

	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size

	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall -Werror -g -O0 -std=c99
	CPPFLAGs = -DMSP432 -MD -MP  -DCOURSE1 -DVERBOSE 

endif

%.i : %.c
	$(CC) -c $< $(INCLUDES) $(CFLAGS) $(CPPFLAGs) -E -o $@

%.asm : %.c
	$(CC) -c $< $(INCLUDES) $(CFLAGS) $(CPPFLAGs) -S -o $@

%.o : %.c
	$(CC) -c $< $(INCLUDES) $(CFLAGS) $(CPPFLAGs) -o $@

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) $(CPPFLAGs) $(LDFLAGS) -o $@
	$(SIZE) $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $< >> $@

.PHONY: build
build: $(TARGET).out

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	rm -f $(PPFS) $(ASMs) $(OBJS) $(DEPS) $(TARGET).asm $(TARGET).out $(TARGET).map
