#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "dimmertre.h"

void dimmertrepiu(uint8_t val){ //85 255/3 -> diviso in 3 intesità.
	
	while(OCR1AL!=(val+85)){
		_delay_ms(10);
		OCR1AL+=1;
	}
}

void dimmertremeno(uint8_t val){

	while(OCR1AL!=(val-85)){
		_delay_ms(10);
		OCR1AL-=1;
	}
	
}
