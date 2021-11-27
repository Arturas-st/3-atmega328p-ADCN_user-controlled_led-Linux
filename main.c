#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"
#include "ledState.h"

volatile uint8_t adcValue = 0;
//volatile int startState = 0;
int counter = 0;



//Triggered at completion of ADC conversion.
ISR(ADC_vect){
	adcValue = readADC();

}

//Triggered at compare match.
ISR(TIMER2_COMPA_vect){
	button(&counter);
	states(&adcValue, &counter);
}

void main (void) {
	//cli();
	uart_init();
	LED_init();
	button_init();
	adc_init();
	timerPWM_init();
	timer2_init();
	sei(); //switches interrupts on
	
	while (1) {
		
    }

}

