#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "accendiLed.h"
#include "../avr_common/uart.h" 


void led_on_off(char* led){
	
	printf("Valore led, sono in led_on_off\n");
	printf(led);
	
	 //il pin 13 è il bit 7, pin 12 bit 6, pin 11 bit 5, pin 10 bit 4
	 /* const uint8_t mask1 = (1<<7);		//10000000
	  const uint8_t mask2 = (1<<6);   //01000000
	  const uint8_t mask3 = (1<<5);		//00100000
	  const uint8_t mask4 = (1<<4);		//00010000
	 
	 //setto i pin 13,12,11,10 come output
	 DDRB |= mask1;
	 DDRB |= mask2;
	 DDRB |= mask3;
	 DDRB |= mask4;*/
	 
	
		/* accendo i led */
		if(strncmp(led,"1",strlen("1"))==0){
				if(OCR1CL==0){
					OCR1CL=255;
				}else{
					OCR1CL=0;
				}
		}
		
		if(strncmp(led,"2",strlen("2"))==0){
				if(OCR1BL==0){
					OCR1BL=255;
				}else{
					OCR1BL=0;
				}
		}
		
		if(strncmp(led,"3",strlen("3"))==0){
				if(OCR1AL==0){
					OCR1AL=255;
				}else{
					OCR1AL=0;
				}
		}
		
		if(strncmp(led,"4",strlen("4"))==0){
				if(OCR2A==0){
					OCR2A=255;
				}else{
					OCR2A=0;
				}
		}

}



