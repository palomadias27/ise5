#ifndef	_LCD_H_
#define _LCD_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

class LCD {

	public:

		LCD(volatile uint8_t* port, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
		void send	(uint8_t byte);
		void cmd	(uint8_t byte);
		void clear	(void);
		void setXY	(uint8_t x, uint8_t y);
		void putC	(char ch);
		void print 	(const char* str);
		void print (int32_t int32_);
		void print	(uint32_t int32_);
		void print	(double float_);

	private:

		volatile uint8_t* LCD_DDR;
		volatile uint8_t* LCD_PORT;
		uint8_t RS;
		uint8_t EN;
		uint8_t D4;
		uint8_t D5;
		uint8_t D6;
		uint8_t D7;
};


#endif /* _LCD_H_ */
