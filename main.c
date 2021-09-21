 /******************************************************************************
 *
 * Module: main
 *
 * File Name: main.c
 *
 * Description: Main file
 *
 * Author: Diana Atef George
 *
 *******************************************************************************/

#include "Timer.h"
#include "led.h"
#include "TMU.h"

void ToggleLed(void)
{
	ledToggle(LED0);

}
void ToggleLed2(void)
{
	ledToggle(LED1);

}

int main(void)
{
	led_init(LED0);
	led_init(LED1);
	TMU_Init();
	TMU_Start_Timer(1,ToggleLed,PERIODIC);
	TMU_Start_Timer(2,ToggleLed2,PERIODIC);
    while (1) 
    {
		TMU_Dispatch();
			
    }
}

