
 /******************************************************************************
 *
 * Module: TMU Lcfg
 *
 * File Name: TMU_Lcfg.h
 *
 * Description: TMU LINKING CONFIGURATION
 *
 * Author: Diana Atef
 *
 *******************************************************************************/

#ifndef TMU_LCFG_H_
#define TMU_LCFG_H_
#include "Std_Types.h"
typedef struct  
{
	uint8 Resolution ;
	uint8 TimerID;
}TMU_ConfigType_t;

typedef enum
{
	TMU0,TMU2
}TMU_channel;
extern TMU_ConfigType_t TMU_Con;
#endif /* TMU_LCFG_H_ */