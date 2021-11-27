#include <avr/io.h>
#include "adc.h"

void adc_init(){
	ADMUX = 0x00;
	ADCSRA |= (1<<ADSC); //single conversion mode
	ADMUX |= (1 << REFS0); // select the voltage reference for the ADC, Vcc
	ADMUX |= (1 << ADLAR); // left adjust the result.
	ADCSRA |= (1 << ADEN); // enables the ADC
	ADCSRA |= (1 << ADIE); //activate Interrupt
	ADCSRA |= (1 << ADPS1)|(1 << ADPS0); //prescaler 8


}

uint8_t readADC(){
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	while( ADCSRA & (1<<ADSC) ){ // wait until ADC conversion is complete
		return ADCH; //return calculated ADC value
	}

}
	

	 
