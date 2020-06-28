#include "avr/eeprom.h"
void EEPROM_init(void){

	if(!eeprom_is_ready()) {
		printf("EEPROM non pronta");
		eeprom_busy_wait();
	}
	printf("EEPROM pronta\n");
	
}

void EEPROM_read(char* str, int offset, int size) {
	uint8_t* start = (uint8_t*) offset;
	uint8_t* end = (uint8_t*) (offset + size);
	while(start < end) {
		eeprom_busy_wait();
		*str = eeprom_read_byte(start);
		start++;
		str++;
	}
}

void EEPROM_write(char* str, int offset, int size) {
	uint8_t* start = (uint8_t*) offset;
	uint8_t* end = (uint8_t*) (offset + size);
	while(start < end) {
		eeprom_busy_wait();
		eeprom_write_byte(start, *str);
		start++;
		str++;
	}
}
