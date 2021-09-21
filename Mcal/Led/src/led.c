/*
 * led.c
 *
 * Created: 10/22/2019 10:43:15 AM
 *  Author: AVE-LAP-025
 */ 
#include "led.h"

//LED0 , LED1, LED2, LED3

void led_init(uint8 led_number){
	gpioPinDirection(LED_PORT,led_number,OUTPUT);
}

void allLed_init(void){
	gpioUpperNibbleDirection(LED_PORT,OUTPUT);
}

void allOn(void){
	gpioUpperNibbleWrite(LED_PORT,HIGH);
}

void allOff(void){
	gpioUpperNibbleWrite(LED_PORT,LOW);
}

void ledOn(uint8 led){
	gpioPinWrite(LED_PORT, led, HIGH);
}
void ledOff(uint8 led){
	gpioPinWrite(LED_PORT, led, LOW);
}
void ledToggle(uint8 led){
	gpioPinToggle(LED_PORT,led);
}

void ledAllToggle(void){
	gpioUpperNibbleToggle(LED_PORT);
}

