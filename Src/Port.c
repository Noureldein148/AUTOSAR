/*
 * Port.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Nour El Dein Hany
 */

#include"Port.h"
#include"Det.h"
#include"MACROS.h"
//#include"RCC_INTERFACE.h"



#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

//static const Port_ConfigType* Port_ConfigPtr = NULL_PTR;
static const Port_ConfigType* glb_port_ptr = NULL_PTR;     // Global Pointer
//static  Port_ConfigType* Port_ConfigPtr = NULL_PTR;
static uint8 Port_Status = Port_NOT_INITIALIZED;

/****************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
****************************/
void Port_Init(const Port_ConfigType* ConfigPtr )
{

//	MRCC_VidEnablePeripheralClock(APB2_BUS, ADC1_RCC);
//	MRCC_VidEnablePeripheralClock(APB2_BUS, ADC2_RCC);
//	MRCC_VidEnablePeripheralClock(APB2_BUS, ADC3_RCC);
//	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
//	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOB_RCC);

//#if (PORT_DEV_ERROR_DETECT == STD_ON)
//	/* check if the input configuration pointer is not a NULL_PTR */
//	if (NULL_PTR == ConfigPtr)
//	{
//		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_PARAM_CONFIG);
//	}
//	else
//#endif

	Port_Status = Port_INITIALIZED;
	glb_port_ptr = ConfigPtr;  // making global pointer to be accessible through all files

	volatile uint32 *gpioCRL = NULL_PTR;
	volatile uint32 *gpioCRH = NULL_PTR;
	uint32 baseAddress = 0;
	/*****************************************************************************************/
	/*************************** Looping through all the Pins *********************************/
	for(Port_PinType i = 0 ; i < NUM_OF_PINS ; i++ )
	{

	PORT_PIN_t Pin = glb_port_ptr[i].PORT_GPIO_pin;
	uint8 Pin2 =	 glb_port_ptr[i].PORT_GPIO_pin;
	/*
	 * Range of Pin : 0-> 15 Used in CRH
	 * Range of Pin2: 0-> 7  Used in CRL
	 * */
		if (Pin2 <= 7) /******************/
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
		}
		else if (Pin2>7 && Pin2 <= 15)
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
			Pin2-=8;
		}

		else if (Pin2 > 15 && Pin2 <= 23) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 16; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		else if (Pin2 > 23 && Pin2 <= 31) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 24; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		gpioCRL = (volatile uint32 *) (baseAddress);
		gpioCRH = (volatile uint32 *) (baseAddress + 0x04); // Offset for CRH register

		/*******************************************************************/
		Port_PinMode_T Mode = glb_port_ptr[i].PORT_pinMode;
		uint8 Dir = glb_port_ptr[i].pinDir;
		if (Pin <= 7)
		{
			switch(Dir)
			{
			case PORT_PIN_IN:
				 if(Mode == GPIO_PIN_ADC_MODE)
				 {
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_ANALOG << (Pin2 * 4)); // Set mode bits
				 }
				 else  // GPIO Or Alternative Function
				 {
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			case PORT_PIN_OUT:
				 if(Mode == GPIO_PIN_DIO_MODE)
				 {	 // Enable Peripheral Clock
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
				 }
				 else  // Alternative Function
				 {
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (OUTPUT_50MHZ_AF_PP << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			}
		}
		else if(Pin >7 && Pin<=15)
		{
			switch(Dir)
			{
			case PORT_PIN_IN:
				 if(Mode == GPIO_PIN_ADC_MODE)
				 {
					 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (INPUT_ANALOG << (Pin2 * 4)); // Set mode bits
				 }
				 else  // GPIO Or Alternative Function
				 {	 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			case PORT_PIN_OUT:
				 if(Mode == GPIO_PIN_DIO_MODE)
				 {	 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
				 }
				 else  // Alternative Function
				 {
					 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (OUTPUT_50MHZ_AF_PP << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			}
		}

		/*****************************************************************************
		************Init Level of Pin **********************************************/

		uint8 PORT_port = glb_port_ptr[i].PORT_GPIO_port;
		uint8 InitLevel = glb_port_ptr[i].pin_level_init_val;
		if(PORT_port == GPIO_PORTA)
		{
			if(InitLevel == STD_LOW)
			{
				CLR_BIT(MGPIOA->ODR ,Pin );
				//SET_BIT(MGPIOA->BRR , Pin);
			}
			else if(InitLevel == STD_HIGH)
			{
				SET_BIT( MGPIOA->ODR , Pin);
				//SET_BIT(MGPIOA->BSRR , Pin);
			}
			else
			{	//Error
			}
		}
		else if(PORT_port== GPIO_PORTB)
		{
			if(InitLevel== STD_LOW)
			{
				CLR_BIT(MGPIOB->ODR ,Pin );
				//SET_BIT(MGPIOB->BRR , Pin);
			}
			else if(InitLevel == STD_HIGH)
			{
				SET_BIT( MGPIOB->ODR , Pin);
				//SET_BIT(MGPIOB->BSRR , Pin);
			}
			else
			{	//Error
			}

		}

		else
		{
			//error
		}
	}
}


/****************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
****************************/
#if PORT_SET_PIN_DIRECTION_API == STD_ON
void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType Direction)
{

//#if (PORT_DEV_ERROR_DETECT == STD_ON)
//      /* Check if the Driver is initialized before using this function */
//	if (Port_NOT_INITIALIZED == Port_Status)
//	{
//	    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIR_SID, PORT_E_UNINIT );
//	}
//	else
//	{
//		/* Do Nothing */
//	}
//	/* Check if the used Port pin ID is within the valid range */
//	if (Pin >= NUM_OF_PINS)
//	{
//	    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIR_SID, PORT_E_PARAM_PIN );
//	}
//	else
//	{
//		/* Do Nothing  */
//	}
///* Check if the Port pin ID is not cofiuared as changeable */
//	if (PORT_SET_PIN_DIRECTION_API == (STD_OFF))
//	{
//	    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE );
//	}
//	else
//	{
//		/* Do Nothing  */
//	}
//#endif

	volatile uint32 *gpioCRL = NULL_PTR;
	volatile uint32 *gpioCRH = NULL_PTR;
	uint32 baseAddress = 0;

	PORT_PIN_t Pin = pin;
	uint8 Pin2 =	 pin;
	/*
	 * Range of Pin : 0-> 15 Used in ODR
	 * Range of Pin2: 0-> 7  Used in CRL & CRH Mode Configuration
	 * */
		if (Pin2 <= 7) /******************/
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
		}
		else if (Pin2>7 && Pin2 <= 15)
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
			Pin2-=8;
		}

		else if (Pin2 > 15 && Pin2 <= 23) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 16; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		else if (Pin2 > 23 && Pin2 <= 31) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 24; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		gpioCRL = (volatile uint32 *) (baseAddress);
		gpioCRH = (volatile uint32 *) (baseAddress + 0x04); // Offset for CRH register
		/**********************************************************************************/
		/**********************************************************************************/
		uint8 Dir = Direction;
		if (Pin <= 7)
		{
			switch(Dir)
			{
			case PORT_PIN_IN:
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
					 break;
			case PORT_PIN_OUT:
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
					 break;
			}
		}
		else if(Pin >7 && Pin<=15)
		{
			switch(Dir)
			{
			case PORT_PIN_IN:

				 	 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
					 break;

			case PORT_PIN_OUT:
					 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
					 break;
			}
		}
}
#endif

/****************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
****************************/
void Port_RefreshPortDirection( void )
{
//	#if (PORT_DEV_ERROR_DETECT == STD_ON)
//		 /* Check if the Driver is initialized before using this function */
//		if (Port_Status == Port_NOT_INITIALIZED)
//		{
//			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIR_SID, PORT_E_UNINIT );
//		}
//		else
//		{
//			/* Do Nothing */
//		}
//	#endif

	Port_Status = Port_INITIALIZED;


	volatile uint32 *gpioCRL = NULL_PTR;
	volatile uint32 *gpioCRH = NULL_PTR;
	uint32 baseAddress = 0;
	/*****************************************************************************************/
	/*************************** Looping through all the Pins *********************************/
	for(Port_PinType i = 0 ; i < NUM_OF_PINS ; i++ )
	{

	PORT_PIN_t Pin = Port_Configuration[i].PORT_GPIO_pin;
	uint8 Pin2 =	 Port_Configuration[i].PORT_GPIO_pin;
	/*
	 * Range of Pin : 0-> 15 Used in CRH
	 * Range of Pin2: 0-> 7  Used in CRL
	 * */
		if (Pin2 <= 7) /******************/
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
		}
		else if (Pin2>7 && Pin2 <= 15)
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
			Pin2-=8;
		}

		else if (Pin2 > 15 && Pin2 <= 23) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 16; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		else if (Pin2 > 23 && Pin2 <= 31) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 24; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		gpioCRL = (volatile uint32 *) (baseAddress);
		gpioCRH = (volatile uint32 *) (baseAddress + 0x04); // Offset for CRH register

		/*******************************************************************/
		Port_PinMode_T Mode = Port_Configuration[i].PORT_pinMode;
		uint8 Dir = Port_Configuration[i].pinDir;
		if (Pin <= 7)
		{
			switch(Dir)
			{
			case PORT_PIN_IN:
				 if(Mode == GPIO_PIN_ADC_MODE)
				 {
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_ANALOG << (Pin2 * 4)); // Set mode bits
				 }
				 else  // GPIO Or Alternative Function
				 {
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			case PORT_PIN_OUT:
				 if(Mode == GPIO_PIN_DIO_MODE)
				 {	 // Enable Peripheral Clock
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
				 }
				 else  // Alternative Function
				 {
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (OUTPUT_50MHZ_AF_PP << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			}
		}
		else if(Pin >7 && Pin<=15)
		{
			switch(Dir)
			{
			case PORT_PIN_IN:
				 if(Mode == GPIO_PIN_ADC_MODE)
				 {
					 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (INPUT_ANALOG << (Pin2 * 4)); // Set mode bits
				 }
				 else  // GPIO Or Alternative Function
				 {	 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			case PORT_PIN_OUT:
				 if(Mode == GPIO_PIN_DIO_MODE)
				 {	 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
				 }
				 else  // Alternative Function
				 {
					 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (OUTPUT_50MHZ_AF_PP << (Pin2 * 4)); // Set mode bits
				 }

				 break;
			}
		}


	}
}

/****************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
****************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType pin, Port_PinModeType mode )
{
	Port_Status = Port_INITIALIZED;
	volatile uint32 *gpioCRL = NULL_PTR;
	volatile uint32 *gpioCRH = NULL_PTR;
	uint32 baseAddress = 0;


	PORT_PIN_t Pin = pin;
	uint8 Pin2 =	 pin;
	/*
	 * Range of Pin : 0-> 15 Used in CRH
	 * Range of Pin2: 0-> 7  Used in CRL
	 * */
		if (Pin2 <= 7) /******************/
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
		}
		else if (Pin2>7 && Pin2 <= 15)
		{
			baseAddress = GPIO_A_BASE_ADDRESS;
			Pin2-=8;
		}

		else if (Pin2 > 15 && Pin2 <= 23) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 16; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		else if (Pin2 > 23 && Pin2 <= 31) {
			baseAddress = GPIO_B_BASE_ADDRESS;
			Pin2 -= 24; // Adjust pin number to match the GPIOB pin numbering
			Pin-=16;
		}

		gpioCRL = (volatile uint32 *) (baseAddress);
		gpioCRH = (volatile uint32 *) (baseAddress + 0x04); // Offset for CRH register

		/*******************************************************************/
		Port_PinMode_T Mode = mode;

		if (Pin <= 7)
		{
			switch(Mode)
			{
			case GPIO_PIN_ADC_MODE:

					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_ANALOG << (Pin2 * 4)); // Set mode bits
					 break;

			case GPIO_PIN_DIO_OUTPUT_MODE:
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
					 break;

			case GPIO_PIN_DIO_INPUT_MODE:
					 *gpioCRL &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRL |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
					 break;
			}
		}
		else if(Pin >7 && Pin<=15)
		{
			switch(Mode)
			{
			case GPIO_PIN_ADC_MODE:

					 *gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
					 *gpioCRH |= (INPUT_ANALOG << (Pin2 * 4)); // Set mode bits
					 break;
			case GPIO_PIN_DIO_OUTPUT_MODE:
				*gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
				*gpioCRH |= (OUTPUT_50MHZ_PP << (Pin2 * 4)); // Set mode bits
				break;

			case GPIO_PIN_DIO_INPUT_MODE:
				*gpioCRH &= ~(0b1111 << (Pin2 * 4)); // Clear corresponding bits
				*gpioCRH |= (INPUT_FLOATING << (Pin2 * 4)); // Set mode bits
				break;
			}
		}



}
#endif

/****************************
* Service Name: Port_GetVersionInfo
* Sevice ID: 0x03
* Sync/Async: Synchronous
* Reentrancy: non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Returns the version information of this module. .
****************************/
#if (PORT_VERSION_INFO_API == STD_ON)
	void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
	{
		#if (PORT_DEV_ERROR_DETECT == STD_ON)
				/* check if the input configuration pointer is not a NULL_PTR */
			if (NULL_PTR == versioninfo)
			{
				Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID ,
										PORT_E_PARAM_POINTER);
			}
			else
				{
					/* Do Nothing */
				}

				/* Check if the Driver is initialized before using this function */
			if (Port_NOT_INITIALIZED == Port_Status)
			{
				Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT );
			}
			else
			{
				/* Do Nothing */
			}
		  #endif
			/* Copy the vendor Id */
		    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		    /* Copy the module Id */
		    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		    /* Copy Software Major Version */
		    versioninfo->sw_major_version = (uint8)Port_SW_MAJOR_VERSION;
		    /* Copy Software Minor Version */
		    versioninfo->sw_minor_version = (uint8)Port_SW_MINOR_VERSION;
		    /* Copy Software Patch Version */
		    versioninfo->sw_patch_version = (uint8)Port_SW_PATCH_VERSION;
	}
#endif
