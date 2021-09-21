/*
 * Timer.h
 *
 * Created: 11/9/2019 8:11:21 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "Std_Types.h" 
/*#include "Timer_cfg.h" */
#include "Timer_Lcfg.h"

#define OK 1
#define NOT_OK 0
/**
 * 	
 *	This file is a header file that contains prototypes of Timer functions'
 *	prototypes and description.
 */

/*===========================Timer Control===============================*/

/*
 * Description:
 * This function initializes timer with user configuration in Timer_Lcfg 
 * Parameter: Input: user configuration
 *			  Type: pointer to structure 
 *			  Output: void
 * Return : STATUS
 */

uint8 Timer_init(Timer_cfg_s* Timercfg);

/*
 * Description:
 * This function starts certain Timer
 * Parameter: Input: channel number
 *			  Type: uint8 
 *			  Output: void
 * Return : void
 */

void Timer_start(uint8 ch_no);

/*
 * Description:
 * This function stops certain Timer
 * Parameter: Input: channel number
 *			  Type: uint8 
 *			  Output: void
 * Return : void
 */

void Timer_stop(uint8 ch_no);

/*
 * Description:
 * This function sets count in micro sec of a certain timer
 * Parameter: Input: channel number
 *			  Type: uint8 
 *            Input: count
 *			  Type: uint16
 *			  Output: void
 * Return : void
 */

void Timer_set_counter(uint8 ch_no, uint16 count);

/*
 * Description:
 * This function gets status of Timer flag
 * Parameter: Input: channel number
 *			  Type: uint8 
 *			  Output: void
 * Return : flag's status
 */

char Timer_getStatus(uint8 ch);

typedef enum 
{
	NO_CLOCK=0,PRESCALER_1=0x01,PRESCALER_8=0x02,PRESCALER_64=0x03,PRESCALER_256=0x04,PRESCALER_1024=0x05
}PRESCALER;

void SetCallBack(void (*ptr)(void));

#endif /* TIMER_H_ */