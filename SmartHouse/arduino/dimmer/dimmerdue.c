#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "dimmerdue.h"

void dimmerduepiu(uint8_t val){
	while(OCR1BL!=(val+85)){
		_delay_ms(10);
		OCR1BL+=1;
	}
}

void dimmerduemeno(uint8_t val){
	while(OCR1BL!=(val-85)){
		_delay_ms(10);
		OCR1BL-=1;
	}
}
