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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Makefile Flags
OBJDIR := output
OBJS=$(SOURCES:.c=.o)

# Platform Overrides & Architecture Specific Flags
#LINKER_FILE CPU ARCH SPECS
######## Compiler Flags and Defines###############

ifeq ($(PLATFORM),MSP432)
 CPU = cortex-m4
 ARCH = arm
 LINKER_FILE = msp432p401r.lds
 CC = arm-none-eabi-gcc
 CFLAGS = -g -Wall -Werror -O0 -std=c99
 LDFLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard \
          -mfpu=fpv4-sp-d16 --specs=nosys.specs \
          -T$(LINKER_FILE) -D$(PLATFORM) -D$(COURSE) -D$(VERBOSE)
 TARGET = MSP432
 COBJD = arm-none-eabi-objdump
endif

ifeq ($(PLATFORM),HOST)
 ARCH = $(shell arch)
 TARGET = DHOST
 CC =gcc
 CFLAGS = -g -Wall -Werror -O0 -std=c99 \
          -D$(PLATFORM) -D$(COURSE) -D$(VERBOSE)
 SOURCES:= ./src/main.c ./src/memory.c ./src/stats.c \
           ./src/course1.c ./src/data.c 
 OBJS=$(SOURCES:.c=.o)
 COBJD = objdump
endif

############# Compile time switch for COURSE1########
#####################################################

####################################################
# Generates an Object directory to place objects in
$(OBJDIR):
	mkdir -p $(OBJDIR)
####################################################

################ General Implementation #############
%.o : %.c
	@echo ===============================
	@echo Generating .o files
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ -c $<
##################################################

################ ASM FIle #############
%.asm : %.c
	@echo ===============================
	@echo Generating ASM files
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ -c $< -S
##################################################

################ ASM FIle for Project.out #############
%.asm : %.out
	@echo ===============================
	@echo Generating ASM files for Project.out
	$(COBJD) -S --disassemble c1m2.out > c1m2.asm
##################################################

################ Process File Implementation #############
%.i : %.c
	@echo ==============================
	@echo Generating .o files
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ -c $< -E
##################################################

################ Compile All Impl #############
.PHONY: compile-all
compile-all:  
	@echo ===============================
	@echo Generating .o files
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -c $(SOURCES)
##################################################

################ MAKE AND BUILD ALL  #############
.PHONY: build
build: all 
.PHONY: all 
all: c1m2.out
c1m2.out: $(OBJS)  
	@echo ==============================
	@echo Building/Making All
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o c1m2.out $(OBJS) -Wl,-Map=c1m2.map
##################################################


################ Compile All Impl #############
.PHONY: clean 
clean:  
	@echo ===============================
	@echo Cleaning the directory 
	rm ./src/*.o *.map ./src/*.i ./src/*.asm *.out 
##################################################



