/*_______________________________________________
 *                RCC_CONFIG.h                   *
 *                                               * 
 *             Created on: Nov 1, 2023               *
 *               Author: zaher                 *
 *_______________________________________________*/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
//-----------------------------------------------------------------------------
#define CLOCK_TYPE       HSI
#define PLL_SOURCE       PLL_HSI_DIVIDED_BY_2
//Clock can be :
//1-HSI
//2-HSE
//3-PLL
//*PLL_Source
//	1-PLL_HSI_DIVIDED_BY_2
//	2-PLL_HSE
//	3-PLL_HSE_DIVIDED_BY_2
//4-HSE_BYPASS
//_______________________________________________________________________________



#define CLOCK_FACTOR     NO_CLOCK_FACTOR

//ClockFactor For PLL  :
//0-NO_CLOCK_FACTOR
//1-PLL_CLOCK_MULTIPLE_BY_2
//2-PLL_CLOCK_MULTIPLE_BY_3
//3-PLL_CLOCK_MULTIPLE_BY_4
//4-PLL_CLOCK_MULTIPLE_BY_5
//5-PLL_CLOCK_MULTIPLE_BY_6
//6-PLL_CLOCK_MULTIPLE_BY_7
//7-PLL_CLOCK_MULTIPLE_BY_8
//8-PLL_CLOCK_MULTIPLE_BY_9
//9-PLL_CLOCK_MULTIPLE_BY_10
//10-PLL_CLOCK_MULTIPLE_BY_11
//11-PLL_CLOCK_MULTIPLE_BY_12
//12-PLL_CLOCK_MULTIPLE_BY_13
//13-PLL_CLOCK_MULTIPLE_BY_14
//14-PLL_CLOCK_MULTIPLE_BY_15
//15-PLL_CLOCK_MULTIPLE_BY_16

//____________________________________________________________________________________________-

#define CLOCK_SECURITY_SYSTEM     DISABLE_CLOCK_SECURITY_SYSTEM

//Clock Security System May be
//1-Enable:
//-To Set HSI By H.W When There are Failure In HSE
//-To Set HSI By H.W When Leaving Stop Or Standby
//2-Disable
//The Previouse Feature Does not Happen




#endif /* RCC_CONFIG_H_ */
