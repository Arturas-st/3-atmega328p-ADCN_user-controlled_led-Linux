#include <avr/io.h>
#include "led.h"
#include <stdbool.h> 

uint8_t light = 0;
bool lightfade = true;
int ledCount = 0;



void LED_init() {
	DDRD |= (1 << PORTD6); // PWM, DELUPPGIFT 2, man kan dra sladd från pin 11 till pin 6 på skölden
	
}

uint8_t simple_ramp() {
	if (light <= 255 && lightfade == true) {
        light++;
    }
    else if (light <= 255 && lightfade == false) {
        light--;
    }
    if (light == 255) {
        lightfade = false;
    }
    else if (light == 0) {
        lightfade = true;
    }
    return light;
}

void ledBlink(){
    ledCount++;
    if(ledCount == 100){ // led flashes every one second
        PORTD ^= (1 << PORTD6);
        ledCount = 0;
    }
}
