/*_______________________________________________
 *                RCC_Interface.h                   *
 *                                               * 
 *             Created on: Nov 1, 2023               *
 *               Author: zaher                 *
 *_______________________________________________*/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include"RCC_CONFIG.h"
#include"RCC_Privet.h"

void RCC_VidInit( void );

void RCC_VidEnablePeripheralClock ( u8 Copy_u8PeripheralBus  , u8 Copy_u8Peripheral );
void RCC_VidDisablePeripheralClock( u8 Copy_u8PeripheralBus  , u8 Copy_u8Peripheral );

#endif /* RCC_INTERFACE_H_ */
