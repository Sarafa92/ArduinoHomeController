#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "dimmeruno.h"


void dimmerunopiu(uint8_t val){

	while(OCR1CL!=(val+85)){
		_delay_ms(10);
		OCR1CL+=1;
	}
	
}

void dimmerunomeno(uint8_t val){
	
	while(OCR1CL!=(val-85)){
		_delay_ms(10);
		OCR1CL-=1;
	}
	
}
