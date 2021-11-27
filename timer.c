#include <avr/io.h>

#include "timer.h"

void timer2_init(void){
	//TCCR2A |= (1 << COM2A0);  //Sets PORTB3/OC2A to toggle on timer, Toggle OC2A on Compare Match.
	//First we reset the control register to make sure we start with everything disabled
	//TCCR2A = 0; //reset entire TCCR2A to 0
	//TCCR2B = 0; //reset entire TCCR2B to 0
	TCCR2A |= (1 << WGM21); //Sets timer CTC mode, sets automatically to 0 when ocr valuea is reached
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); //prescaler 1024
	TIMSK2 |= (1 << OCIE2A); //  enable Compare Match A interrupt
	OCR2A = 157;  // 1/(16MHz/1024) * 157 = 10ms
	//TCNT2 = 0; // sets the timer back to 0 (TCNT2 stores the counter value)
	
}

void timerPWM_init(){
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1); //Set Fast PWM mode, Clear OC0A on Compare Match, set OC0A at BOTTOM (non-inverting mode)
	TCCR0B |= (1 << CS01) | (1 << CS00);  //sets prescaler to 64
	
	// PWM-frekvens = Fw = Fcpu/(256 * N) = 16MHz/(256 * 64) = 976.560Hz
}
