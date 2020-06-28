#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 


#include "dimmerpiu.h"
#include "dimmeruno.h"
#include "dimmerdue.h"
#include "dimmertre.h"
#include "dimmerquattro.h"

 
void dimmerpiu(char* val){
	
		
		if(strncmp(val,"1",strlen("1"))==0){ //pin 13
				if(OCR1CL==255){
						OCR1CL=255;
				}else{
						dimmerunopiu(OCR1CL);
				}
		
		}else if(strncmp(val,"2",strlen("2"))==0){//pin 12
				if(OCR1BL==255){
						OCR1BL=255;
				}else{
						dimmerduepiu(OCR1BL);
				}	
		
		}else if(strncmp(val,"3",strlen("3"))==0){
				if(OCR1AL==255){
						OCR1AL=255;
				}else{
						dimmertrepiu(OCR1AL);
				}
		
		}else if(strncmp(val,"4",strlen("4"))==0){
				if(OCR2A==255){
						OCR2A=255;
				}else{	
						dimmerquattropiu(OCR2A);
				}
		
		}else{
			printf("Nessuno switch valido per il dimmer");
		}


	



} 
