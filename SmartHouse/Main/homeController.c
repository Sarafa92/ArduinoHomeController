#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "eeprom.h"

#include "homeController.h"
#include "../arduino/dimmer/pwm_init.h"
#include "../arduino/dimmer/dimmerpiu.h"
#include "../arduino/dimmer/dimmermeno.h" 
#include "../arduino/onoff/accendiLed.h" 
#include "../avr_common/uart.h" 




volatile uint8_t receive,flag; //non vengono ottimizzate dal compilatore
volatile char sw,op;
uint8_t buf[20];
volatile int namecheck[5] = {0};// per tenere conto se ho scritto già il nome
char nome_temp[32]; //nome max 20 caratteri 
int i,k,indexEEPROM[5] = {0}; //mi mantiene l'inizio di dove iniziare a leggere il nome
char* nome, *bufferNomi; //lo alloco per 100--> 20 char a nome



//******************************ASSEGNO NOME CONTROLLER ****************************************
void setNameController(uint8_t* buf){
 
		nome = prelevaStringa(buf); //Prelevo la stringa dall'input buf ricevuto
			
		if(namecheck[0]==1) return; //se il nome è già stato assegnato ritorna
		
		//SALVO IL NOME SULLA EEPROM
		EEPROM_write(nome,0,20);
		indexEEPROM[0] = 0;   // start->0 end->len nell'elemento 0 dell'array creato
		
		//PROVO A LEGGERE DA EEPROM (test per cutecom)
		/*EEPROM_read(bufferNomi,0,20); 
		USART_putString((uint8_t*)bufferNomi);*/
		
		//setto flag per salvarmi che ho scritto il nome
		namecheck[0] = 1;	
}

//****************************************RESET EEPROM**************************************************
void resetEEPROM(int start){
		memset(nome,0,20);		//setto nome a zero 
		EEPROM_write(nome,start,20); //lo scrivo a partire da start che è l'indice iniziale di dove ho salvato il nome
}

//******************************************PRELEVA_STRINGA************************************************

char* prelevaStringa(uint8_t* buf){
		k=2; //inizializzata poichè le stringhe dal buf iniziano dopo il secondo carattere
	 	for(i=0;i<20;i++){
		  	 			if(buf[k]=='\0'||buf[k]=='\n'||buf[k]=='\r') break;  //controllo il carattere di terminazione
		  				nome_temp[i]=buf[k];
		  				k++;
		}
		
		return nome_temp;
}


/*************************************************SCEGLI OPERAZIONE*************************************************
 						sw --> SWITCH                                                op --> OPERAZIONE
			
						sw = 1 porta 13 pin 7 																			 op = 1  --> Assegnazione nome switch
						sw = 2 porta 12 pin 6 																			 op = 2  --> dimmer più
						sw = 3 porta 11 pin 5 																			 op = 3  --> dimmer meno
						sw = 4 porta 10 pin 4 																			 op = 4  --> on/off
																																				 op = 5  --> reset nome switch	 																																							
*********************************************************************************************************************/

void scegliOperazione(char sw,char op,char* nome){
							
		switch(sw){
					
//#############################################################_SWITCH 1_##############################################################
				
		case '1':
								//---------------------------ASSEGNA NOME--------------------------	
								if(op =='1'){  						
										if(namecheck[1]==1) break; 				//se il valore del nome è già stato assegnato interrompi
										EEPROM_write(nome,20,20);					//SALVO IL NOME SULLA EEPROM
										indexEEPROM[1] = 20;   		 				// start->32 elemento 1 dell'array creato
										namecheck[1] = 1; 								//aggiorno namecheck
										//PROVO A LEGGERE DA EEPROM (test per cutecom)
										/*EEPROM_read(bufferNomi,20,20); 
										USART_putString((uint8_t*)bufferNomi);*/
										
								}else if(op =='2'){ 		
								//-----------------------------DIMMER+-----------------------------		
											dimmerpiu("1");
											
								}else if(op =='3'){ 	
								//-----------------------------DIMMER------------------------------				
											dimmermeno("1");
											
								}else if(op =='4'){ 		
								//-----------------------------ONOFF-------------------------------			
											led_on_off("1");
											
								}else if(op == '5'){		
									//------------------------RESET EEPROM----------------------------			
										resetEEPROM(indexEEPROM[1]); 				//funzione di reset
										namecheck[1] = 0;       						//Setto namecheck per poter riassegnare il nome      
										/*EEPROM_read(bufferNomi,20,20); 
										USART_putString((uint8_t*)bufferNomi);*/
								}
								
								break;
								
								
//#############################################################_SWITCH 2_##############################################################
					
		case '2':
			
								//---------------------------ASSEGNA NOME--------------------------	
								if(op =='1'){  						
										if(namecheck[2]==1) break; 				//se il valore del nome è già stato assegnato interrompi
										EEPROM_write(nome,40,20);					//SALVO IL NOME SULLA EEPROM
										indexEEPROM[2] = 40;   		 				// start->32 elemento 1 dell'array creato
										namecheck[2] = 1; 								//aggiorno namecheck
										//PROVO A LEGGERE DA EEPROM (test per cutecom)
										/*EEPROM_read(bufferNomi,40,20); 
										USART_putString((uint8_t*)bufferNomi);*/
										
								}else if(op =='2'){ 		
								//-----------------------------DIMMER+-----------------------------		
											dimmerpiu("2");
											
								}else if(op =='3'){ 	
								//-----------------------------DIMMER------------------------------				
											dimmermeno("2");
											
								}else if(op =='4'){ 		
								//-----------------------------ONOFF-------------------------------			
											led_on_off("2");
											
								}else if(op == '5'){		
									//------------------------RESET EEPROM----------------------------			
										resetEEPROM(indexEEPROM[2]); 				//funzione di reset
										namecheck[2] = 0;       						//Setto namecheck per poter riassegnare il nome      
										/*EEPROM_read(bufferNomi,40,20); 
										USART_putString((uint8_t*)bufferNomi);*/
								}
								
								break;		
					 
//#############################################################_SWITCH 3_##############################################################
		
		case '3':
		 				
								//---------------------------ASSEGNA NOME--------------------------	
								if(op =='1'){  						
										if(namecheck[3]==1) break; 				//se il valore del nome è già stato assegnato interrompi
										EEPROM_write(nome,60,20);					//SALVO IL NOME SULLA EEPROM
										indexEEPROM[3] = 60;   		 				// start->32 elemento 1 dell'array creato
										namecheck[3] = 1; 								//aggiorno namecheck
										//PROVO A LEGGERE DA EEPROM (test per cutecom)
										/*EEPROM_read(bufferNomi,60,20); 
										USART_putString((uint8_t*)bufferNomi);*/
										
								}else if(op =='2'){ 		
								//-----------------------------DIMMER+-----------------------------		
											dimmerpiu("3");
											
								}else if(op =='3'){ 	
								//-----------------------------DIMMER------------------------------				
											dimmermeno("3");
											
								}else if(op =='4'){ 		
								//-----------------------------ONOFF-------------------------------			
											led_on_off("3");
											
								}else if(op == '5'){		
									//------------------------RESET EEPROM----------------------------			
										resetEEPROM(indexEEPROM[3]); 				//funzione di reset
										namecheck[3] = 0;       						//Setto namecheck per poter riassegnare il nome      
										/*EEPROM_read(bufferNomi,60,20); 
										USART_putString((uint8_t*)bufferNomi);*/
								}
								
								break;
         
				
//#############################################################_SWITCH 4_##############################################################
		
		case '4':
		
       	
								//---------------------------ASSEGNA NOME--------------------------	
								if(op =='1'){  						
										if(namecheck[4]==1) break; 				//se il valore del nome è già stato assegnato interrompi
										EEPROM_write(nome,80,20);					//SALVO IL NOME SULLA EEPROM
										indexEEPROM[4] = 80;   		 				// start->32 elemento 1 dell'array creato
										namecheck[4] = 1; 								//aggiorno namecheck
										//PROVO A LEGGERE DA EEPROM (test per cutecom)
										/*EEPROM_read(bufferNomi,80,20); 
										USART_putString((uint8_t*)bufferNomi);*/
										
								}else if(op =='2'){ 		
								//-----------------------------DIMMER+-----------------------------		
											dimmerpiu("4");
											
								}else if(op =='3'){ 	
								//-----------------------------DIMMER------------------------------				
											dimmermeno("4");
											
								}else if(op =='4'){ 		
								//-----------------------------ONOFF-------------------------------			
											led_on_off("4");
											
								}else if(op == '5'){		
									//------------------------RESET EEPROM----------------------------			
										resetEEPROM(indexEEPROM[4]); 				//funzione di reset
										namecheck[4] = 0;       						//Setto namecheck per poter riassegnare il nome      
										/*EEPROM_read(bufferNomi,80,20); 
										USART_putString((uint8_t*)bufferNomi);*/
								}
								
								break;
		
		default: 
								break;
		}	
}

//************************************************FINE OPERAZIONI*********************************************

  
int main(void) {

	bufferNomi = (char*)malloc(sizeof(char)*100); 					//alloco buffer per contenere i nomi
	
    //Inizializzazioni
   	cli(); //disabilito interruzioni
    UART_init(); //inizializzo la USART
 		pwm_init(); //inizializzo i pwm
 		
   	
		/* abilito interrupt */
    sei();   
    
   while(1){ 
			//se ho ricevuto interrupt
			if(receive){
				 //salvo i valori dei comandi per le operazione in due variabili
				 sw = buf[0];
				 op = buf[1];
				 
				 //Assegno nome al controller
				 if(sw=='0' && op =='0' && namecheck[0]==0){
				 		setNameController(buf);
				 		//USART_putString((uint8_t*)"Fatto!\n");
				 }
				 
				 //Resetto nome al controller
				 else if(sw=='0' && op =='1' && namecheck[0]==1){
				 		resetEEPROM(indexEEPROM[0]);
				 		//EEPROM_read(bufferNomi,0,20); 
				 		namecheck[0] = 0;
				 	//USART_putString((uint8_t*)"Fatto!\n");
				 }
				 
				 /* se l'operazione è quella di assegnare il nome, salvo il nome nell'array nome
					*	e lo taglio fino al valore di terminazione.*/	 
				if(op=='1'){  
		  			nome = prelevaStringa(buf);
	 		  }
				_delay_ms(3);	
				scegliOperazione(sw,op,nome); //funzione per selezionare le operazioni da fare
				
					
				receive = 0; //setto flag delle interruzioni a 0 per poter ricevere altre interrupt
				memset(nome,0,strlen(nome)); //pulisco il buffer nome
				//USART_putString((uint8_t*)"\nFatto!\n");
				
			}
    }
}
//Vettore interrupt
ISR(USART0_RX_vect){
		USART_getString(buf);
		receive = 1;
		//USART_putString((uint8_t*)"Ricevuto interrupt\n");
}



		
			
	
		

	

