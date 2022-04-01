/*
 * Lab1_morsecodedecoder.c
 *
 * Return name and redid as Morse code using delay timers
 *
 * Created: 9/3/2021 7:50:13 PM
 * Author : Jarrod
 */ 

#define F_CPU 16000000UL // 16MHz 
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/*------------------------------------------- MORSE CONVERSION ---------------------------------------------*/
	/*
	/* .--- .- .-. .-. --- -.. / .-. --- .-- ... --- -. / ---.. ..--- -.... ....- ..... ...-- ---.. ....- ...-- */
	/*	J	A	R	R	O	D	  R   O   W   S   O   N		8	  2		6	  4     5     3     8     4     3
	/*	
	/*----------------------------------------------------------------------------------------------------------*/	
	/* Toggle Data registry B(5) */
	char s[] = "Jarrod Rowson 826453843\0";
	DDRB |= (1 << DDRB5); // port OUTput init
	
	init_delay();
	
	/* main */
    while (1) 
    {
	morse_code(s);	
    }
}
	/* end of main */


void morse_code(char s[]) // Main conversion
{
	
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'A' || s[i] == 'a')
		{
			dih();
			dah();
		}	else if (s[i] == 'B' || s[i] == 'b')
		{
			dah();
			dih();
			dih();
		}	else if (s[i] == 'C' || s[i] == 'c')
		{
			dah();
			dih();
			dah();
			dih();
		}	else if (s[i] == 'D' || s[i] == 'd')
		{
			dah();
			dih();
			dih();
		}	else if (s[i] == 'E' || s[i] == 'e')
		{
			dih();
		}	else if (s[i] == 'F' || s[i] == 'f')
		{
			dih();
			dih();
			dah();
			dih();
		}	else if (s[i] == 'G' || s[i] == 'g')
		{
			dah();
			dah();
			dih();	
		}	else if (s[i] == 'H' || s[i] == 'h')
		{
			dih();
			dih();
			dih();
			dih();	
		}	else if (s[i] == 'I' || s[i] == 'i')
		{
			dih();
			dih();
		}	else if (s[i] == 'J' || s[i] == 'j')
		{
			dih();
			dah();
			dah();
			dah();
		}	else if (s[i] == 'K' || s[i] == 'k')
		{
			dah();
			dih();
			dah();
		}	else if (s[i] == 'L' || s[i] == 'l')
		{
			dih();
			dah();
			dih();
			dih();
		}	else if (s[i] == 'M' || s[i] == 'm')
		{
			dah();
			dah();
		}	else if (s[i] == 'N' || s[i] == 'n')
		{
			dah();
			dih();
		}	else if (s[i] == 'O' || s[i] == 'o')
		{
			dah();
			dah();
			dah();
		}	else if (s[i] == 'P' || s[i] == 'p')
		{
			dih();
			dah();
			dah();
			dih();
		}	else if (s[i] == 'Q' || s[i] == 'q')
		{
			dah();
			dah();
			dih();
			dah();
		}	else if (s[i] == 'R' || s[i] == 'r')
		{
			dih();
			dah();
			dih();
		}	else if (s[i] == 'S' || s[i] == 's')
		{
			dih();
			dih();
			dih();
		}	else if (s[i] == 'T' || s[i] == 't')
		{
			dah();
		}	else if (s[i] == 'U' || s[i] == 'u')
		{
			dih();
			dih();
			dah();
		}	else if (s[i] == 'V' || s[i] == 'v')
		{
			dih();
			dih();
			dih();
			dah();
		}	else if (s[i] == 'W' || s[i] == 'w')
		{
			dih();
			dah();
			dah();
		}	else if (s[i] == 'X' || s[i] == 'x')
		{
			dah();
			dih();
			dih();
			dah();
		}	else if (s[i] == 'Y' || s[i] == 'y')
		{
			dah();
			dih();
			dah();
			dah();
		}	else if (s[i] == 'Z' || s[i] == 'z')
		{
			dah();
			dah();
			dih();
			dih();
		}	else if (s[i] == '0')
		{
			dah();
			dah();
			dah();
			dah();
			dah();
		}	else if (s[i] == '1')
		{
			dih();
			dah();
			dah();
			dah();
			dah();
		}	else if (s[i] == '2')
		{
			dih();
			dih();
			dah();
			dah();
			dah();
		}	else if (s[i] == '3')
		{
			dih();
			dih();
			dih();
			dah();
			dah();
		}	else if (s[i] == '4')
		{
			dih();
			dih();
			dih();
			dih();
			dah();
		}	else if (s[i] == '5')
		{
			dih();
			dih();
			dih();
			dih();
			dih();
		}	else if (s[i] == '6')
		{
			dah();
			dih();
			dih();
			dih();
			dih();
		}	else if (s[i] == '7')
		{
			dah();
			dah();
			dih();
			dih();
			dih();
		}	else if (s[i] == '8')
		{
			dah();
			dah();
			dah();
			dih();
			dih();
		}	else if (s[i] == '9')
		{
			dah();
			dah();
			dah();
			dah();
			dih();
		}	else if (s[i] == ' ')
		{
			space();
		}
		_delay_ms(600);
		i++;
	}
}

void space() // _
{
	PORTB &= ~(1 << PORTB5);
	_delay_ms(1400);
}

void dih() // .
{
	PORTB |= (1 << PORTB5);
	_delay_ms(200);
	PORTB &= ~(1 << PORTB5);
	_delay_ms(200);
}

void dah() // -
{
	PORTB |= (1 << PORTB5);
	_delay_ms(600);
	PORTB &= ~(1 << PORTB5);
	_delay_ms(200);
}

void init_delay() // Visual representation of start
{
		PORTB |= (1 << PORTB5);
		_delay_ms(100);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(100);
		PORTB |= (1 << PORTB5);
		_delay_ms(100);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(100);
		PORTB |= (1 << PORTB5);
		_delay_ms(100);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(100);
		PORTB |= (1 << PORTB5);
		_delay_ms(100);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(100);
		PORTB |= (1 << PORTB5);
		_delay_ms(100);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(1000);
}


