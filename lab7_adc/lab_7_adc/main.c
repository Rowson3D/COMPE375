/*
 * lab_7_adc.c
 *
 * Created: 11/11/2021 11:30:16 PM
 * Author : Jarrod
 */ 

#define F_CPU 16000000UL
#define BAUD 9600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>



ISR (ADC_vect)
{
	uint16_t adc_value = ADC;
	OCR2B = ((adc_value * OCR2A )/1024.0);
	//storing in OCR2B for comparing
	
}

ISR(TIMER2_COMPA_vect)
{
	if(OCR2B>0)
	PORTB |= (1<<5); //Turn on led
}

ISR(TIMER2_COMPB_vect)
{
	PORTB &= ~(1<<5); //Turn off led
}

void adc_init(void)
{
	ADMUX |= (1 << REFS0)|(1<<MUX0);  //ADC1 port enabled
	ADCSRA |= (1 << ADEN) | (1 << ADATE) | (1 << ADIE) | (1 << ADPS1) | (1 <<ADPS0)|
	(1<<ADPS2);
	ADCSRB |= (1 << ADTS1) | (1 << ADTS0);
}

void timer0()
{
	
	TCCR0A |=(1<<WGM01); // CTC Mode
	OCR0A = 109; //(6+1)*100 HZ
	TIMSK0 |= (1<<OCIE0A); //timer compare enabled
	TCCR0B |=(1<<CS02)|(1<<CS00); // 1024 prescaler
}

void timer2()
{
	
	TCCR2A |=(1<<WGM21); //Set CTC Mode Timer 2
	OCR2A = 155;//(0+1)*100hz=10ms so 156-1
	TIMSK2 |= (1<<OCIE2A) | (1<< OCIE2B);  //ISR COMPA and COMPB
	TCCR2B |=(1<<CS22) | (1<<CS20); // 1024 pre scaler
}

int main(void)
{
	DDRC = ~(1<<PINC1); //potentiometer input port redid y = pin 1    modulo 7%6=1
	DDRB |= (1<<5);
	
	adc_init();
	
	
	timer0();
	
	timer2();
	
	cli(); //clear global interrupts
	sei(); //enable global interrupts
	
	while(1){}
	
	
}