#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>


//definisco il baudrate, la velocità di trasmissione dati sulla seriale. 
#define BAUD 19600
#define MYUBRR (F_CPU/16/BAUD-1)

int usart_putchar_printf(char var, FILE *stream);

static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, _FDEV_SETUP_WRITE);
//Inizializzo la UART
void UART_init(void){
  //setto baudRate
	  UBRR0H = (uint8_t)(MYUBRR>>8);
  	  UBRR0L = (uint8_t)MYUBRR;

  //imposto il numero di bit di dati in un frame (bit 1 e 2) a 8 bit 
 	  UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); 
  //attivo i pin di trasmissione e ricezione sulla seriale TX e RX
  	  UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);   
}
	
void USART_Transmit( uint8_t data ){
	//mi metto in attesa che il buffer di trasmissione sia vuoto
	while ( !( UCSR0A & (1<<UDRE0)) );
	//inserisco nel registro UDR il valore trasmesso
	UDR0 = data;
}  

uint8_t USART_Receive( void ){
	//Mi metto in attesa della ricezione dei dati
	while ( !(UCSR0A & (1<<RXC0)) );
	//Ritorno il valore ricevuto dal buffer
	return UDR0;
}

// leggo la stringa fino al valore di terminazione 0 \n o \r
// ritorno il numero di bit
uint8_t UART_getString(uint8_t* buf){
  uint8_t* b0=buf; 
  while(1){
    uint8_t c=USART_Receive();
    *buf=c;
    ++buf;
    //se c==0 la stringa è terminata
    if (c==0)
      return buf-b0;
    //se c==/n o c==/r è terminata la stringa a capo
    if(c=='\n'||c=='\r'){
      *buf=0;
      ++buf;
      return buf-b0;
    }
  }
}

void UART_putString(uint8_t* buf){
  while(*buf){
    USART_Transmit(*buf);
    ++buf;
  }
}

// this function is called by printf as a stream handler
int usart_putchar_printf(char var, FILE *stream) {
    // translate \n to \r for br@y++ terminal
    if (var == '\n') USART_Transmit('\r');
    USART_Transmit((uint8_t)var);
    return 0;
}


void printf_init(void){
  stdout = &mystdout;
  
  // fire up the usart
  UART_init ();
}



