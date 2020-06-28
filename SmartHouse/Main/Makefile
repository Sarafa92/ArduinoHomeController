# AVR makefile stub

# to clean a folder
# from command line
#$> make clean

# to build the folder
#$> make 

# to upload a file
# from command line
# $> make <main_filename>.hex

#
# remember to give yourself the read/write permissions on the
# serial line
# $> sudo addgroup <your username> dialout
# reboot



# !!!!!!!!!!!!!!!! MODIFY HERE !!!!!!!!!!!!!!!! 

# put here the file containing the main routine
# to be uploaded on the avr
# you can add multiple files, they will be all generated

BINS=comunicazione.elf 

# put here the additional .o files you want to generate
# one .c file for each .o should be present
OBJS=../avr_common/uart.o ../arduino/dimmer/dimmerpiu.o ../arduino/dimmer/dimmermeno.o  ../arduino/onoff/accendiLed.o  ../arduino/dimmer/dimmeruno.o ../arduino/dimmer/dimmerdue.o ../arduino/dimmer/dimmertre.o ../arduino/dimmer/dimmerquattro.o       

# put here the additional header files needed for compilation
HEADERS=../avr_common/uart.h ../arduino/dimmer/dimmerpiu.h ../arduino/dimmer/dimmermeno.h  ../arduino/dimmer/pwm_init.h ../arduino/onoff/accendiLed.h ../arduino/dimmer/dimmeruno.h ../arduino/dimmer/dimmerdue.h ../arduino/dimmer/dimmertre.h ../arduino/dimmer/dimmerquattro.h

# the file below contains the actual rules

include ../avr_common/avr.mk 

# !!!!!!!!!!!!!!!! MODIFY HERE !!!!!!!!!!!!!!!! 



