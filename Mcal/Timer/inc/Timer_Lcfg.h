/*
 * Timer_Lcfg.h
 *
 * Created: 11/9/2019 8:13:14 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef TIMER_LCFG_H_
#define TIMER_LCFG_H_

#include "Std_Types.h"

/************************************************************************/
/*				 Enum for defining Timer Mode                           */ 
/************************************************************************/

typedef enum  
{
	Timer_timer,Timer_counter
}Timer_mode;

/************************************************************************/
/*				 Enum for defining Timer Channel                        */
/************************************************************************/

typedef enum 
{
	Timer0,Timer2
}Timer_channel;

/************************************************************************/
/*		    Enum for defining Timer Mode (interrupt or polling)         */
/************************************************************************/

typedef enum 
{
	polling,interrupt
}Interrupt_flag ;

/************************************************************************/
/*				 Structure Declaration for the Timer                    */
/************************************************************************/

typedef struct 
{
	Timer_channel Channel;
	Timer_mode Mode;
	uint8 count;
	Interrupt_flag Int_flag;
	uint16 frequency;
}Timer_cfg_s;

/*for the higher layer*/

extern Timer_cfg_s user_timer;



#endif /* TIMER_LCFG_H_ */