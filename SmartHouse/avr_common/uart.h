#pragma once

void printf_init(void);

void UART_init(void);

void USART_Transmit(uint8_t carattere);

uint8_t  USART_Receive(void);

uint8_t USART_getString(uint8_t *buf);

void USART_putString(uint8_t *buf);

void flush(void);
