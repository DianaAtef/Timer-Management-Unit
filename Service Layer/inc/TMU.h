 /******************************************************************************
 *
 * Module: TMU Module
 *
 * File Name: TMU.h
 *
 * Description: Header file for TMU module
 *
 * Author: Diana Atef George
 *
 *******************************************************************************/

/*****************************************************
*                      Header guardians              *
******************************************************/

#ifndef TMU_H_
#define TMU_H_

#include "Timer_Lcfg.h"


/************************************************************************/
/*			 	       TMU functions' prototypes	                    */
/************************************************************************/

/*****************************************************
*                      Typedefs                      *
******************************************************/

/*return function status*/
 
typedef char EnmTMUError_t;

/*Job status to know if the function is running or not (if paused then do not increase the number of clicks)*/
typedef enum {
	paused, running
}JobStatus;

/*structure of a job*/

typedef struct
{
	
	uint16 JobDelay;
	void(*JobcallBackPtr)(void);
	uint8 shotOrPeriodic;
	uint16 clicks;
	uint8 status;
	uint8 ID;
	
}gTmu_t;

#define TMU_OK    1
#define TMU_NOK   0
#define SHOT      0
#define PERIODIC  1

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

/*to initialize TMU and start Timer*/
EnmTMUError_t TMU_Init(void) ;

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


EnmTMUError_t TMU_Start_Timer(uint16 JobDelay,void (*ptr)(void),uint8 shotOrPeriodic);

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


EnmTMUError_t TMU_Stop_Timer(uint8 JobID);

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

EnmTMUError_t TMU_DeInit(void);

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

void TMU_Dispatch(void);





#endif /* TMU_H_ */