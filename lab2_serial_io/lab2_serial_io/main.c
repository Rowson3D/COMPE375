/*
 * lab2_serial_io.c
 *
 * Created: 9/10/2021 4:21:54 PM
 * Author : Jarrod
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define BAUDRATE ((F_CPU) / (BAUD * 16UL)-1)


void usart_init(void)
{
	UCSR0B |= (1 << TXEN0); // enable tx
	UCSR0C |= (1 << UCSZ00)|(1 << UCSZ01); // 8bit data format
	UBRR0L = BAUDRATE; // baud rate
	UBRR0H = (BAUDRATE >> 8); // shift right 8 bits
}

int main(void)
{
	unsigned char data[] = "826453843\n\r";
	int i = 0;
	usart_init();
	while (1)
	{
		i = 0;
		while (data[i] != 0)
		{
			while (!(UCSR0A & (1 << UDRE0)));
			{
				UDR0 = data[i];
				i++;
			}
		}
	}
}