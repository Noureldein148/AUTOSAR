/*
 * main.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Nour
 */
#include"type.h"

#include"RCC_Interface.h"
#include"Port.h"


void main(void)
{
	RCC_VidInit();
	RCC_VidEnablePeripheralClock(APB2_BUS , GPIOA_RCC);
	RCC_VidEnablePeripheralClock(APB2_BUS , GPIOB_RCC);

	Port_Init( &Port_Configuration);
	Port_PinType PPin = 0;

	Port_SetPinDirection(PPin , PORT_PIN_IN);
	Port_RefreshPortDirection();
	Port_SetPinMode(PPin ,GPIO_PIN_DIO_INPUT_MODE );
	while(1)
	{
	}
}
