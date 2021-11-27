#include <avr/io.h>
#include "ledState.h"

void states(int *adcValue, int *counter){
    switch(*counter){
        case 1:
            TCCR0A |= (1 << COM0A1); // enable OCR0A (PWM non-inverting mode)
            OCR0A = simple_ramp(); // Fade
            break;
        case 2:
            ADCSRA |= (1 << ADSC); //Start the ADC single conversion mode
            OCR0A = *adcValue; //Potentiometer
            break;
        case 3:
            TCCR0A &= ~(1 << COM0A1); // disable OCR0A (PWM non-inverting mode)
            ledBlink(); //Blink
            break;
        case 4:
            //PORTD &= ~(1 << PORTD6);
            PORTD |= (1 << PORTD6); //Turn off led
            break;
        default:
            break;

    }
}