/*_______________________________________________
 *                RCC_Prog.c                   *
 *                                               * 
 *             Created on: Nov 1, 2023               *
 *               Author: zaher                 *
 *_______________________________________________*/
#include "RCC_Privet.h"
#include "RCC_CONFIG.h"
#include "RCC_Interface.h"

#include "bit math.h"
#include "type.h"

void RCC_VidInit( void ){

	u32 LOCACL_u32TimeOut = 0;

#if   CLOCK_TYPE == HSI


	/* HSI IS System Clock */
	RCC_CFGR_REG->SW=0B00;


	/*  Enable The HSI Clock */
	RCC_CR_REG->RCC_CR_HSION=0B01;
	/* Checking While The HSI Clock Is Stable */
	while( ( RCC_CR_REG->RCC_CR_HSIRDY== 0 ) && ( LOCACL_u32TimeOut < 100000 ) )
	{
		LOCACL_u32TimeOut++;
	}


#elif CLOCK_TYPE == HSE

	/* Choose Between HSI OR HSE OR PLL */
	/* HSE Selected As A System Clock */
	RCC_CFGR_REG->SW=0B01;
	/*  Enable The HSE Clock */

	RCC_CR_REG->RCC_CR_HSEON=0B01;
	/*  Checking While The HSE Clock Is Stable */
	while( ( RCC_CR_REG->RCC_CR_HSERDY== 0 ) && ( LOCACL_u32TimeOut < 100000 ) ){ LOCACL_u32TimeOut++; }


#elif CLOCK_TYPE == PLL

	/*  Choose Between HSI OR HSE OR PLL */
	/* PLL Selected As A System Clock */
	RCC_CFGR_REG->SW=0B10;


	/* Choosing The Multiplication Factor For PLL */
#if ( CLOCK_FACTOR >= NO_CLOCK_FACTOR ) && ( CLOCK_FACTOR <= PLL_CLOCK_MULTIPLE_BY_16)


	RCC_CFGR_REG->PLLMUL=0B0000;
	RCC_CFGR_REG->PLLMUL=CLOCK_FACTOR;

#endif


#if PLL_SOURCE == PLL_HSI_DIVIDED_BY_2

	/*  Choose PLL Source  HSI/2 OR HSE */
	/* PLL  Source Is HSI Divided By 2 */

	RCC_CFGR_REG->PLLSRC=0;

#elif PLL_SOURCE == PLL_HSE

	/*  Enable The HSE Clock */

	RCC_CR_REG->RCC_CR_HSEON=1;

	/*   PLL Source HSI/2 OR HSE */
	/* PLL  Source Is HSE */
	RCC_CFGR_REG->PLLSRC=0;

	/* IF PLL Source IS HSE  (HSE/2 Or Not)  */
	/* HSE Is Not Divided */

	RCC_CFGR_REG->PLLXTPRE=0;

#elif PLL_SOURCE == PLL_HSE_DIVIDED_BY_2

	/*  Enable The HSE Clock */
	RCC_CR_REG->RCC_CR_HSEON=1;

	/*  Choose PLL Source -> If HSI/2 OR HSE */
	/* PLL Entery Clock Source Is HSE */
	RCC_CFGR_REG->PLLSRC=1;

	/*  IF PLL Source IS HSE  HSE/2 Or Not  */
	/* HSE Is Divided By Two */
	RCC_CFGR_REG->PLLXTPRE=1;


#endif

	/* PLL Clock Enable */

	RCC_CR_REG->RCC_CR_PLLON=1;

	while( ( RCC_CR_REG->RCC_CR_PLLRDY == 0 ) && ( LOCACL_u32TimeOut < 100000 ) ){ LOCACL_u32TimeOut++; }


#elif CLOCK_TYPE == HSE_BYPASS

	/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
	/* HSE Clock Disabled */
	RCC_CR_REG->RCC_CR_HSEON=0;

	/* To Select HSE BYPASS */
	/* HSEBYPASS Clock Enable */

	RCC_CR_REG->RCC_CR_HSEBYP=1;

	/* Choose Between HSI OR HSE OR PLL */
	/* HSE Selected As A System Clock */

	RCC_CFGR_REG->SW=0B01;


	/*  Enable The HSE Clock */
	RCC_CR_REG->RCC_CR_HSEON=1;


	while( ( RCC_CR_REG->RCC_CR_HSERDY == 0 ) && ( LOCACL_u32TimeOut < 100000 ) ){ LOCACL_u32TimeOut++; }



#endif

	/* For Clock Security System */
#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM

	RCC_CR_REG->RCC_CR_CSSON=1;

#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM


	RCC_CR_REG->RCC_CR_CSSON=0;


#endif

}
void RCC_VidEnablePeripheralClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral ){


	switch( Copy_u8PeripheralBus ){

	case AHB_BUS  :
		SET_BIT( RCC_AHBENR_REG  , Copy_u8Peripheral );
		break;
	case APB1_BUS :
		SET_BIT(RCC_APB1ENR_REG, Copy_u8Peripheral );
		break;
	case APB2_BUS :
		SET_BIT( RCC_APB2ENR_REG, Copy_u8Peripheral );
		break;

	}






}
void RCC_VidDisablePeripheralClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral ){

	switch( Copy_u8PeripheralBus ){

	case AHB_BUS  :
		CLEAR_BIT( RCC_AHBENR_REG  , Copy_u8Peripheral );
		break;
	case APB1_BUS :
		CLEAR_BIT(RCC_APB1ENR_REG, Copy_u8Peripheral );
		break;
	case APB2_BUS :
		CLEAR_BIT( RCC_APB2ENR_REG, Copy_u8Peripheral );
		break;

	}


}


