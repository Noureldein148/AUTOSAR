/*
 * Port.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Nour El Dein  Hany
 */

#ifndef PORT_H_
#define PORT_H_
#include"Platform_Types.h"
#include"Port_Reg.h"

// Non AutoSAR File
#include"compiler.h"


//* for Example ID = 1000 :) */
#define PORT_VENDOR_ID  (1000U)

#define PORT_MODULE_ID  (124U) //

#define PORT_INSTANCE_ID (0U) //??
/*
 * Module Version 1.0.0
 */
#define Port_SW_MAJOR_VERSION           (1U)
#define Port_SW_MINOR_VERSION           (0U)
#define Port_SW_PATCH_VERSION           (0U)


/*
 * AutoSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION (4U)
#define PORT_AR_RELEASE_MINOR_VERSION (0U)
#define PORT_AR_RELEASE_PATCH_VERSION (3U)

/*
 * PORT STATUS
 */
#define Port_INITIALIZED               (1U)
#define Port_NOT_INITIALIZED           (0U)

/* Standard AUTOSAR types */
#include"Std_Types.h"

/*
 *
 */
/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif



#define NUM_OF_PINS	32
/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_OFF)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

#define PORT_SET_PIN_MODE_API       	    (STD_ON)


// PP : push pull , OD: Open Drain , AF: alternative function

#define OUTPUT_10MHZ_PP      0b0001
#define OUTPUT_10MHZ_OD      0b0101
#define OUTPUT_10MHZ_AF_PP   0b1001
#define OUTPUT_10MHZ_AF_OD   0b1101

#define OUTPUT_2MHZ_PP       0b0010
#define OUTPUT_2MHZ_OD       0b0110
#define OUTPUT_2MHZ_AF_PP    0b1010
#define OUTPUT_2MHZ_AF_OD    0b1110

#define OUTPUT_50MHZ_PP      0b0011
#define OUTPUT_50MHZ_OD      0b0111
#define OUTPUT_50MHZ_AF_PP   0b1011
#define OUTPUT_50MHZ_AF_OD   0b1111

#define INPUT_ANALOG        0b0000
#define INPUT_FLOATING      0b0100
#define INPUT_PULL_UP_DOWN  0b1000





#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5
#define GPIO_PORTG 6

#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

typedef enum
{
	PORT_PIN_0 ,
	PORT_PIN_1 ,
	PORT_PIN_2 ,
	PORT_PIN_3 ,
	PORT_PIN_4 ,
	PORT_PIN_5 ,
	PORT_PIN_6 ,
	PORT_PIN_7 ,
	PORT_PIN_8 ,
	PORT_PIN_9 ,
	PORT_PIN_10,
	PORT_PIN_11,
	PORT_PIN_12,
	PORT_PIN_13,
	PORT_PIN_14,
	PORT_PIN_15,
	PORT_PIN_16,
	PORT_PIN_17,
	PORT_PIN_18,
	PORT_PIN_19,
	PORT_PIN_20,
	PORT_PIN_21,
	PORT_PIN_22,
	PORT_PIN_23,
	PORT_PIN_24,
	PORT_PIN_25,
	PORT_PIN_26,
	PORT_PIN_27,
	PORT_PIN_28,
	PORT_PIN_29,
	PORT_PIN_30,
	PORT_PIN_31,
	PORT_PIN_32,
	PORT_PIN_33,
	PORT_PIN_34

}PORT_PIN_t;


typedef enum
{
	GPIO_PIN_DIO_MODE ,
	GPIO_PIN_ADC_MODE ,
	GPIO_PIN_I2C_MODE ,
	GPIO_PIN_SPI_MODE ,
	GPIO_PIN_CAN_MODE ,
	GPIO_PIN_USB_MODE ,
	GPIO_PIN_UART_MODE ,
	GPIO_PIN_TIM_MODE ,
	GPIO_PIN_DIO_INPUT_MODE ,
	GPIO_PIN_DIO_OUTPUT_MODE

}Port_PinMode_T;


/************************************* Service IDs****************************************/
/*****************************************************************************************/

#define PORT_INIT_SID 						(uint8)0X00
#define PORT_SET_PIN_DIR_SID				(uint8)0X01
#define PORT_REFRESH_PORT_DIR_SID			(uint8)0x02
#define PORT_GET_VERSION_INFO_SID 			(uint8)0x03
#define PORT_SET_PIN_MODE_SID				(uint8)0x04

/*
 * DEM
 */

/***************************** Errors***************************/
/*Invalid Port Pin ID requested	*/
#define PORT_E_PARAM_PIN 					(uint8)0x0A
/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE 		(uint8)0x0B

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG				 	(uint8)0x0C

/* API Port_SetPinMode service called when Port Pin Mode passed not valid */
#define PORT_E_PARAM_INVALID_MODE 			(uint8)0x0D

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE 			(uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT 						(uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER 				(uint8)0x10

typedef uint8 Port_PinModeType;
typedef uint8 Port_PinType ;
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef struct
{
	uint8 PORT_GPIO_port;
	PORT_PIN_t PORT_GPIO_pin;
	//PORT_PIN_t PORT_GPIO_pin;
	Port_PinDirectionType 	pinDir;			/*PORT_PIN_IN , PORT_PIN_OUT*/

	Port_PinMode_T	PORT_pinMode;	         	/*ADC,SPI,..*/
	uint8 pin_level_init_val;				/* 	HIGH or LOW			*/
	uint8 pin_dir_changeable;			  	/* STD_ON,STD_OFF 		*/
	uint8 pin_mode_changeable;				/* STD_ON,STD_OFF 		*/

	}Port_ConfigType; // to be made an array off




/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr );
//const Port_ConfigType* ConfigPtr

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
	void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
	void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif


/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif
/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sevice ID: 0x02
* Sync/Async: Synchronous
* Reentrancy: non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to refresh the direction of all configured ports to the configured direction.
************************************************************************************/
void Port_RefreshPortDirection( void );

/**************************** External Variables********************/
/* Extern PB structures to be used by Port and other modules */
extern  const Port_ConfigType Port_Configuration[];


#endif /* PORT_H_ */
