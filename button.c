#include <stdio.h>
#include <avr/pgmspace.h>
#include "button.h"

uint8_t state = 0;
uint8_t laststate = 0;

void button_init(){
    DDRB &= ~(1 << PORTB4); //input
}

void button(int *counter){
    if(PINB & (1 << PORTB4)){
        state = 1;
    }
    else if(!(PINB & (1 << PORTB4))){
        state = 0;
    }

    if(state == 1 && laststate == 0){
        printf_P(PSTR("pushed\r\n"));
        
    }
    else if(state == 0 && laststate == 1){
        *counter += 1;
        if(*counter > 4){
            *counter = 1;
        }
        printf_P(PSTR("released\r\n"));
        printf_P(PSTR("%d\n"),*counter);
        
    }
    laststate = state;
}


