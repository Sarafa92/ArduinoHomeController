#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
//#include "../avr_common/uart.h" 

// configuration bits for PWM
// fast PWM, 8 bit, non inverted
// output compare set low
#define TCCRA_MASK (1<<WGM10)|(1<<COM1C1)|(1<<COM1B1)|(1<<COM1A1)
#define TCCRB_MASK ((1<<WGM12)|(1<<CS10)) 

#define TCCRA2_MASK (1<<WGM20)|(1<<COM2A1)|(1<<WGM21)
#define TCCRB2_MASK (0<<WGM22)|(1<<CS20)

void pwm_init(void);

void pwm_init(void){
  //Usiamo timer 1 per porte 13,12,11
  TCCR1A=TCCRA_MASK;
  TCCR1B=TCCRB_MASK;
  //Usiamo timer 2 per la porta 10
  TCCR2A = TCCRA2_MASK;
  TCCR2B = TCCRB2_MASK;
  
  // Imposto i bit delle porte
  const uint8_t mask1=(1<<7);	//porta 13
  const uint8_t mask2=(1<<6);	//porta 12
  const uint8_t mask3=(1<<5); //porta 11
  const uint8_t mask4=(1<<4); //porta 10 
  
 //const uint8_t array[4]={mask1,mask2,mask3,mask4};

  // configuro i pin come output
  DDRB |= mask1; //bit 7
  DDRB |= mask2; //bit 6
  DDRB |= mask3; //bit 5
  DDRB |= mask4; //bit 4
  };
