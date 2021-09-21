/*
 * led.h
 *
 * Created: 10/22/2019 10:43:05 AM
 *  Author: AVE-LAP-025
 */ 


#ifndef LED_H_
#define LED_H_


#include "Dio.h"
#include "ledConfig.h"

void led_init(uint8 led_number);
void allLed_init(void);

void allOn(void);
void allOff(void);

void ledOn(uint8 led);
void ledOff(uint8 led);

void ledToggle(uint8 led);
void ledAllToggle(void);



#endif /* LED_H_ */