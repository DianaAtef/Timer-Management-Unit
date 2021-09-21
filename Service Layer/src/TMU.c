 /******************************************************************************
 *
 * Module: TMU Module
 *
 * File Name: TMU.c
 *
 * Description: Src file for TMU module
 *
 * Author: Diana Atef George
 *
 *******************************************************************************/

/****************************************
 *                Includes              *
 ****************************************/

#include "TMU.h"
#include "Timer_Lcfg.h"
#include "TMU_Lcfg.h"
#include "Timer.h"
#include "Registers.h"

/****************************************
*             Macros Define             *
*****************************************/

#define MAX_NUMBER_OF_REQUESTS 5

/****************************************
*             Global Variable          *
*****************************************/

gTmu_t gastr_TmuRequests[MAX_NUMBER_OF_REQUESTS];

uint8 gArrayIndex=0;

/************************************************************************/
/*			 	       TMU functions' Implementation	                */
/************************************************************************/

/**********************************************************************************************
* Function Name: TMU_Tick
*
* Parameters (in): None
*
* Parameters (in/out): None
*
* Parameters (out): None
*
* Description: Function to calculate the time that has passed (in ms) for each job since running  
*
************************************************************************************************/

void TMU_Tick(void)
{

	for(int index=0;index<gArrayIndex;index++)
	{
		if(gastr_TmuRequests[index].status!=paused && gastr_TmuRequests[index].clicks < gastr_TmuRequests[index].JobDelay )
		{
			gastr_TmuRequests[index].clicks++;
		}
		else
		{
			/*Do Nothing*/
		}
	}

}

/************************************************************************************
* Function Name: TMU_Init
*
* Parameters (in): None
*
* Parameters (in/out): None
*
* Parameters (out): None
*
* Return value: EnmTMUError_t
*
* Description: Function to initialize TMU
*
************************************************************************************/

EnmTMUError_t TMU_Init(void) 
{
	Timer_init(&user_timer);
	Timer_start(TMU_Con.TimerID);
	SetCallBack(TMU_Tick);
	return TMU_OK;
}

/************************************************************************************
* Function Name: TMU_Start_Timer
*
* Parameters (in):
* 	name        : void (*ptr)(void)
* 	type        : ptr to function 
* 	Description	: to call back function in main 
*
* 	name        : type
* 	type        : uint8 
* 	Description	: type either one shot or periodic
* Parameters (in/out): None
*
* Parameters (out): None
*
* Return value: EnmTMUError_t
*	Description	: return status from function (TMU_OK/TMU_NOK).
*
* Description: function to create task and set its variables 
*
************************************************************************************/

EnmTMUError_t TMU_Start_Timer(uint16 Delay,void (*ptr)(void),uint8 type)
{
	if(gArrayIndex>MAX_NUMBER_OF_REQUESTS-1)
	{
		return TMU_NOK;
	}
	gastr_TmuRequests[gArrayIndex].clicks=0;
	gastr_TmuRequests[gArrayIndex].JobDelay=Delay;
	gastr_TmuRequests[gArrayIndex].status=running;
	gastr_TmuRequests[gArrayIndex].shotOrPeriodic=type;
	gastr_TmuRequests[gArrayIndex].JobcallBackPtr=ptr;
	gastr_TmuRequests[gArrayIndex].ID=gArrayIndex;
	gArrayIndex++;

	return TMU_OK;
}

/************************************************************************************
* Function Name: TMU_Stop_Timer
*
* Parameters (in):
* 	name        : JobID
* 	type        : uint8 
* 	Description	: Job ID required to be stopped 
*
* Parameters (out): None
*
* Return value: EnmTMUError_t
*	Description	: return status from function (TMU_OK/TMU_NOK).
*
* Description: function to stop a certain job
*
************************************************************************************/

EnmTMUError_t TMU_Stop_Timer(uint8 JobID)
{
	if(JobID>(gArrayIndex-1))
	{
		return TMU_NOK;
	}
	
	if(gastr_TmuRequests[JobID].status==paused)
	{
		return TMU_NOK;
	}
	
	else
	{
		gastr_TmuRequests[JobID].status=paused;
		gastr_TmuRequests[JobID].clicks=0;
		return TMU_OK;
	}

}

/************************************************************************************
* Function Name: TMU_DeInit
*
* Parameters (in):None
*
* Parameters (out): None
*
* Return value: EnmTMUError_t
*	Description	: return status from function (TMU_OK/TMU_NOK).
*
* Description: function to De-initialize the TMU and stop all tasks
*
************************************************************************************/

EnmTMUError_t TMU_DeInit(void)
{
	Timer_stop(TMU_Con.TimerID);
	for(int index=0;index<gArrayIndex;index++)
	{
		gastr_TmuRequests[index].clicks=0;
	}
	return TMU_OK;
}

/************************************************************************************************************
* Function Name: TMU_Dispatch
*
* Parameters (in): None
*
* Parameters (in/out): None
*
* Parameters (out): None
*
* Return value: None
*
* Description: function for the dispatcher to check if the job delay time has passed and call function in main
*
*************************************************************************************************************/

void TMU_Dispatch(void)
{

	for(int index=0;index<gArrayIndex;index++)
	{
		if(gastr_TmuRequests[index].clicks==gastr_TmuRequests[index].JobDelay)
		{
			gastr_TmuRequests[index].clicks=0;
			gastr_TmuRequests[index].JobcallBackPtr();
			
			if(gastr_TmuRequests[index].shotOrPeriodic==SHOT)
			{
				gastr_TmuRequests[index].status=paused;
			}

		}
		else
		{
			/*Do nothing */
		}
	}


}