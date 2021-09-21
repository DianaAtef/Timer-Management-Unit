/*
 * Timer.c
 *
 * Created: 11/9/2019 8:11:40 PM
 *  Author: AVE-LAP-025
 */ 

/**
 * 	
 *	This file is a source file that contains Timer functions'
 */

#include "Timer_Lcfg.h"
#include "Registers.h"
#include "Timer.h"
#include "interrupt.h"
#include "led.h"

#define F_CPU 8000000

volatile uint8 click=0;
volatile uint8 click2=0;
#define PRESCALER 8

struct {
	volatile Timer_mode g_mode;
	volatile Interrupt_flag g_int;
	volatile uint16 g_count;
	}g_variables;
	
void(*callBackPtr)(void)=NULL;

void SetCallBack(void (*ptr)(void))
{
	callBackPtr=ptr;
}
/*===========================Timer Control===============================*/

/* This function initializes timer */

uint8 Timer_init(Timer_cfg_s* Timercfg)
{

	g_variables.g_mode = Timercfg -> Mode;
	g_variables.g_int = Timercfg -> Int_flag;
	g_variables.g_count = Timercfg -> count;
	
	switch(Timercfg -> Channel)
	{
		case Timer0:
		switch(Timercfg -> Mode)
		{
			case Timer_timer:
			/*Normal*/
			TCCR0 &=~(1<<WGM01)&~(1<<WGM00);
			if(Timercfg->Int_flag==interrupt)
			{
				SREG|=(1<<I);
				TIMSK=(1<<TOIE0);
				return OK;
			}
			break;
			case Timer_counter:
			/*falling edge*/
			TCCR0 &=~(1<<WGM01)&~(1<<WGM00);
			return OK;
			break;
			default:
			return NOT_OK;
			break;
		}
		break;
		
		case Timer2:
		switch(Timercfg -> Mode)
		{
			case Timer_timer:
			TCCR2 &=~(1<<WGM21)&~(1<<WGM20);
			return OK;
			break;
			case Timer_counter:
			/*falling edge*/
			TCCR2 &=~(1<<WGM21)&~(1<<WGM20);
			return OK;
			break;
			default:
			return NOT_OK;
			break;
		}
		
	}
	return OK;
}

/*This function starts certain Timer*/

void Timer_start(uint8 ch_no)
{

	if(ch_no ==0 && g_variables. g_mode==Timer_timer && PRESCALER==1024)
	{
		/* /1024 */
		TCCR0|= (1<<CS02) | (1<<CS00);
	}
	else if(ch_no ==0 && g_variables. g_mode==Timer_timer && PRESCALER==8)
	{
		/* /8 */
		TCCR0|= (1<<CS01);
	}
	else if(ch_no ==0 &&  g_variables.g_mode==Timer_counter)
	{
		
		TCCR0|=(1<<CS01)|(1<<CS02);
	}
	else if(ch_no ==2 && g_variables. g_mode==Timer_timer)
	{
		/* /8 */
		TCCR2|=(1<<CS21);
	}
	
} 

/*This function stops certain Timer*/

void Timer_stop(uint8 ch_no)
{
	if(ch_no==0)
	{
		TCCR0&=~(0x07);
	}
	else if(ch_no==2)
	{
		TCCR2&=~(0x07);
	}
}


#if 0
TIMER0_OVF_Handler(){
click++;
TCNT0=256-g_count;
}
#endif

#if 0
TIMER2_OVF_Handler()
{
	click2++;
}
#endif

ISR(TIMER0_OVF_vect){

	click++;
	TCNT0=256-g_variables.g_count;
	if(click==4)
	{
		click=0;
		callBackPtr();	
	}
	
	

}

/*This function sets count in micro sec of a certain timer*/

void Timer_set_counter(uint8 ch_no, uint16 count)
{
	g_variables.g_count=count;
	if(count<256 && ch_no==0 && PRESCALER==8)
	{
		
		TCNT0=256-count;
	}
	else if(count<256 && ch_no==0 && PRESCALER==1024)
	{
		
		TCNT0=256-(count/64);
	}
	else if(count<256 && ch_no==2 && PRESCALER==8)
	{
		
		TCNT2=256-count;
	}
	
}

/*This function gets status of Timer flag*/

char Timer_getStatus(uint8 ch)
{
	if(ch == 0){
		if(g_variables.g_int == polling){
			if((TIFR&(1<<TOV0)) !=0)
			{
				Timer_stop(0);
				TIFR=(1<<TOV0);
				TCNT0=256-g_variables.g_count;
				return 1;
			}
		}
		else if(g_variables.g_int == interrupt)
		{
			Timer_stop(0);
			SREG |= (1<<I);
			if(click == 1){
				click=0;
				TCNT0=256-g_variables.g_count;
				return 1;
			}
		}
		return 0;
	}
	else if(ch==2)
	{
		if(g_variables.g_int==polling)
		{
			if((TIFR&(1<<TOV2)) !=0)
			{
				Timer_stop(0);
				TIFR=(1<<TOV2);
				TCNT2=256-g_variables.g_count;
				return 1;
			}
		}
		else if(g_variables.g_int==interrupt)
		{
			Timer_stop(0);
			SREG|=(1<<7);
			if(click==1){
				click=0;
				TCNT2=256-(g_variables.g_count);
				return 1;
			}
		}
	}
	return OK;
}
