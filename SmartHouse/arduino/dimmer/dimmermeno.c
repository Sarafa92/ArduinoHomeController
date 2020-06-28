#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 


#include "dimmermeno.h"
#include "dimmeruno.h"
#include "dimmerdue.h"
#include "dimmertre.h"
#include "dimmerquattro.h"


 
void dimmermeno(char* val){

		if(strncmp(val,"1",strlen("1"))==0){ //pin 13
				if(OCR1CL==0){
					OCR1CL=0;
				}else{
						dimmerunomeno(OCR1CL);
				}
		
		}else if(strncmp(val,"2",strlen("2"))==0){
				if(OCR1BL==0){
						OCR1BL=0;
				}else{
						dimmerduemeno(OCR1BL);
				}
		}else if(strncmp(val,"3",strlen("3"))==0){
				if(OCR1AL==0){
						OCR1AL=0;
				}else{
						dimmertremeno(OCR1AL);
				}
		
		}else if(strncmp(val,"4",strlen("4"))==0){
				if(OCR2A==0){
						OCR2A=0;
				}else{
					dimmerquattromeno(OCR2A);
				}
		
		}else{
			printf("Nessuno switch valido per il dimmer");
		}


	



} 







