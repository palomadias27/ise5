#include "LCD.h"

LCD::LCD(volatile uint8_t* port, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) {

	LCD_PORT = port;
	if (LCD_PORT == &PORTB)
		LCD_DDR = &DDRB;
	if (LCD_PORT == &PORTC)
		LCD_DDR = &DDRC;
	if (LCD_PORT == &PORTD)
		LCD_DDR = &DDRD;

	RS = rs;
	EN = en;
	D4 = d4;
	D5 = d5;
	D6 = d6;
	D7 = d7;

	*LCD_DDR |= 1 << RS | 1 << EN | 1 << D4 | 1 << D5 | 1 << D6 | 1 << D7;

	send(0x00);
	_delay_ms(20);
	cmd(0x03);
	_delay_ms(5);
	cmd(0x03);
	_delay_ms(11);
	cmd(0x03);
	cmd(0x02);
	cmd(0x02);
	cmd(0x08);
	cmd(0x00);
	cmd(0x0C);
	cmd(0x00);
	cmd(0x06);
}

void LCD::send (uint8_t byte) {

	if(byte & 1)
		*LCD_PORT |= 1 << D4;
	else
		*LCD_PORT &= ~(1 << D4);

	if(byte & 2)
		*LCD_PORT |= 1 << D5;
	else
		*LCD_PORT &= ~(1 << D5);

	if(byte & 4)
		*LCD_PORT |= 1 << D6;
	else
		*LCD_PORT &= ~(1 << D6);

	if(byte & 8)
		*LCD_PORT |= 1 << D7;
	else
		*LCD_PORT &= ~(1 << D7);
}

void LCD::cmd (uint8_t byte) {

	*LCD_PORT &= ~(1 << RS);
	send(byte);
	*LCD_PORT |= 1 << EN;
	_delay_ms(4);
	*LCD_PORT &= ~(1 << EN);
}

void LCD::clear(void) {

	cmd(0);
	cmd(1);
	_delay_ms(4);
}

void LCD::setXY (uint8_t x, uint8_t y) {

	char aux = 0, high, low;
	if(x == 1) {
		aux = 0x80 + y - 1;
	}
	else if (x == 2) {
		aux = 0xC0 + y - 1;
	}
	high = aux >> 4;
	low = aux & 0x0F;
	cmd(low);
	cmd(high);
}

void LCD::putC(char ch) {

	char nibbleLow, nibbleHigh;

	nibbleLow = ch & 0x0F;
	nibbleHigh = ch & 0xF0;
	*LCD_PORT |= 1 << RS;
	send(nibbleHigh>>4);      	//Transfer high nibble
	*LCD_PORT |= 1 << EN;
	_delay_us(40);
	*LCD_PORT &= ~(1 << EN);
	send(nibbleLow);				//Transfer lower nibble
	*LCD_PORT |= 1 << EN;
	_delay_us(40);
	*LCD_PORT &= ~(1 << EN);
}

void LCD::print(const char* str) {

	while (*str) {
		putC(*str);
		str++;
	}
}

void LCD::print(int32_t int32_) {

	char word[20];
	print(ltoa(int32_,word,10));
}

void LCD::print(uint32_t int32_) {

	char word[10];
	print(ultoa(int32_,word,10));
}

void LCD::print(double float_) {

	char word[10];
	dtostrf(float_,3,2,word);
	print(word);
}

