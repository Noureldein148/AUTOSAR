/*_______________________________________________
 *                RCC_Privet.h                   *
 *                                               * 
 *             Created on: Nov 1, 2023           *
 *               Author: zaher                   *
 *_______________________________________________*/

#ifndef RCC_PRIVET_H_
#define RCC_PRIVET_H_

#include "type.h"

/* Register Definitions  */
typedef struct {
	volatile u8 RCC_CR_HSION :1;
	volatile u8 RCC_CR_HSIRDY :1;
	volatile u8 :1;
	volatile u8 RCC_CR_HSITRIM :5;
	volatile u8 RCC_CR_HSICAL :8;
	volatile u8 RCC_CR_HSEON :1;
	volatile u8 RCC_CR_HSERDY :1;
	volatile u8 RCC_CR_HSEBYP :1;
	volatile u8 RCC_CR_CSSON :1;
	volatile u8 :4;
	volatile u8 RCC_CR_PLLON :1;
	volatile u8 RCC_CR_PLLRDY :1;
	volatile u8 :6;
} CR;
#define RCC_CR_REG            ((volatile CR*)0x40021000)
//_________________________________________________
typedef struct {
	volatile u8 SW :2;
	volatile u8 SWS :2;
	volatile u8 HPRE :4;
	volatile u8 PPRE1 :3;
	volatile u8 PPRE2 :3;
	volatile u8 ADCPRE :2;
	volatile u8 PLLSRC :1;
	volatile u8 PLLXTPRE :1;
	volatile u8 PLLMUL :4;
	volatile u8 USBPRE :1;
	volatile u8 :1;
	volatile u8 MCO :3;
	volatile u8 :5;
} CFGR;
#define RCC_CFGR_REG          ((volatile CFGR*)0x40021004)
//_________________________________________________________________________________

typedef struct {
	volatile u8 LSIRDYF :1;
	volatile u8 LSERDYF :1;
	volatile u8 HSIRDYF :1;
	volatile u8 HSERDYF :1;
	volatile u8 PLLRDYF :1;
	volatile u8 		:2;
	volatile u8 CSSF 	:1;
	volatile u8 LSIRDYIE :1;
	volatile u8 LSERDYIE :1;
	volatile u8 HSIRDYIE :1;
	volatile u8 HSERDYIE :1;
	volatile u8 PLLRDYIE :1;
	volatile u8 :3;
	volatile u8 LSIRDYC :1;
	volatile u8 LSERDYC :1;
	volatile u8 HSIRDYC :1;
	volatile u8 HSERDYC :1;
	volatile u8 PLLRDYC :1;
	volatile u8 :2;
	volatile u8 CSSC :1;
	volatile u8 :8;
} CIR;
#define RCC_CIR_REG           ((volatile CIR*)0x40021008)

//____________________________________________________________________

//typedef struct {
//	volatile u8 AFIORST :1;
//	volatile u8 :1;
//	volatile u8 IOPARST :1;
//	volatile u8 IOPBRST :1;
//	volatile u8 IOPCARST :1;
//	volatile u8 IOPDRST :1;
//	volatile u8 IOPERST :1;
//	volatile u8 IOPFRST :1;
//	volatile u8 IOPGRST :1;
//	volatile u8 ADC1RST :1;
//	volatile u8 ADC2RST :1;
//	volatile u8 TIM1RST :1;
//	volatile u8 SPL1RST :1;
//	volatile u8 TIM8RST :1;
//	volatile u8 USARTIRST :1;
//	volatile u8 ADC3RST :1;
//	volatile u8 :3;
//	volatile u8 TIM9RST :1;
//	volatile u8 TIM10RST :1;
//	volatile u8 TIM11RST :1;
//	volatile u16 :10;
//} APB2RSTR;
//#define RCC_APB2RSTR_REG      ((volatile APB2RSTR *)0x4002100C)

#define RCC_APB2RSTR_REG      *((volatile u32 *)0x4002100C)

#define    AFIO_RCC         0
#define    GPIOA_RCC        2
#define    GPIOB_RCC        3
#define    GPIOC_RCC        4
#define    GPIOD_RCC        5
#define    GPIOE_RCC        6
#define    GPIOF_RCC        7
#define    GPIOG_RCC        8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21


//__________________________________________________________________________

//typedef struct {
//	volatile u8 TIM2RST :1;
//	volatile u8 TIM3RST :1;
//	volatile u8 TIM4RST :1;
//	volatile u8 TIM5RST :1;
//	volatile u8 TIM6ARST :1;
//	volatile u8 TIM7RST :1;
//	volatile u8 TIM12RST :1;
//	volatile u8 TIM13RST :1;
//	volatile u8 TIM14RST :1;
//	volatile u8 :2;
//	volatile u8 WWDGRST :1;
//	volatile u8 :2;
//	volatile u8 SPI2 :1;
//	volatile u8 SPI3 :1;
//	volatile u8 :1;
//	volatile u8 USART2RST :1;
//	volatile u8 USART3RST :1;
//	volatile u8 USART4RST :1;
//	volatile u8 USART5RST :1;
//	volatile u8 I2C1RST :1;
//	volatile u8 I2C2RST :1;
//	volatile u8 USBRST :1;
//	volatile u8 :1;
//	volatile u8 CANRST :1;
//	volatile u8 :1;
//	volatile u8 BKPRST :1;
//	volatile u8 PWRRST :1;
//	volatile u8 DACRST :1;
//	volatile u8 :2;
//} APB1RSTR;
//#define RCC_APB1RSTR_REG      ((volatile APB1RSTR*)0x40021010)

#define RCC_APB1RSTR_REG      *((volatile u32*)0x40021010)

#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29

//------------------------------------------------------------------------------
//typedef struct {
//	volatile u8 DMA1EN :1;
//	volatile u8 DMA2EN :1;
//	volatile u8 SRAMEN :1;
//	volatile u8 :1;
//	volatile u8 FLITFEN :1;
//	volatile u8 :1;
//	volatile u8 CRCEN :1;
//	volatile u8 :1;
//	volatile u8 FSMCEN :1;
//	volatile u8 :1;
//	volatile u8 SDIOEN :1;
//	volatile u32 :21;
//} AHBENR;
//#define RCC_AHBENR_REG        ((volatile AHBENR*)0x40021014)

#define RCC_AHBENR_REG        *((volatile u32*)0x40021014)

#define    DMA1_RCC         0
#define    DMA2_RCC         1
#define    SRAM_RCC         2
#define    FLITF_RCC        4
#define    CRC_RCC          6
#define    FSMC_RCC         8
#define    SDIO_RCC         10
//---------------------------------------------------------------------------------
//typedef struct {
//	volatile u8 AFIOEN :1;
//	volatile u8 :1;
//	volatile u8 IOPAEN :1;
//	volatile u8 IOPBEN :1;
//	volatile u8 IOPCEN :1;
//	volatile u8 IOPDEN :1;
//	volatile u8 IOPEEN :1;
//	volatile u8 IOPFEN :1;
//	volatile u8 IOPGEN :1;
//	volatile u8 ADC1EN :1;
//	volatile u8 ADC2EN :1;
//	volatile u8 TIM1EN :1;
//	volatile u8 SPI1EN :1;
//	volatile u8 TIM8EN :1;
//	volatile u8 USART1EN :1;
//	volatile u8 ADC3EN :1;
//	volatile u8 :3;
//	volatile u8 TIM5EN :1;
//	volatile u8 TIM10EN :1;
//	volatile u8 TIM11EN :1;
//	volatile u16 :10;
//} APB2ENR;


#define    AFIO_RCC         0
#define    GPIOA_RCC        2
#define    GPIOB_RCC        3
#define    GPIOC_RCC        4
#define    GPIOD_RCC        5
#define    GPIOE_RCC        6
#define    GPIOF_RCC        7
#define    GPIOG_RCC        8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21

#define RCC_APB2ENR_REG       *((volatile u32*)0x40021018)
//----------------------------------------------------------------------
//typedef struct {
//	volatile u8 TIM2EN :1;
//	volatile u8 TIM3EN :1;
//	volatile u8 TIM4EN :1;
//	volatile u8 TIM5EN :1;
//	volatile u8 TIM6EN :1;
//	volatile u8 TIM7EN :1;
//	volatile u8 TIN12EN :1;
//	volatile u8 TIM13EN :1;
//	volatile u8 TIM14EN :1;
//	volatile u8 :2;
//	volatile u8 WWDGEN :1;
//	volatile u8 :2;
//	volatile u8 SPI2EN :1;
//	volatile u8 SPI3EN :1;
//	volatile u8 :1;
//	volatile u8 USART2EN :1;
//	volatile u8 USART3EN :1;
//	volatile u8 USART4EN :1;
//	volatile u8 USART5EN :1;
//	volatile u8 I2C1EN :1;
//	volatile u8 I2C2EN :1;
//	volatile u8 USBEN :1;
//	volatile u8 :1;
//	volatile u8 CANEN :1;
//	volatile u8 :1;
//	volatile u8 BKPEN :1;
//	volatile u8 PWREN :1;
//	volatile u8 DACEN :1;
//	volatile u8 :2;
//} APB1ENR;


#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29
#define RCC_APB1ENR_REG       *((volatile u32*)0x4002101C)
//-------------------------------------------------------------------------------------

typedef struct {
	volatile u8 LSEON :1;
	volatile u8 LESRDY :1;
	volatile u8 LESBYP :1;
	volatile u8 :5;
	volatile u8 RTCSEL :1;
	volatile u8 :5;
	volatile u8 RTCEN :1;
	volatile u8 BDRTC :1;
	volatile u16 :15;
} BDCR;
#define RCC_BDCR_REG          ((volatile BDCR*)0x40021020)
//------------------------------------------------------------------------------
typedef struct {
	volatile u8 LSION :1;
	volatile u8 LSIRDY :1;
	volatile u32 :22;
	volatile u8 RMVF :1;
	volatile u8 :1;
	volatile u8 PINRSTF :1;
	volatile u8 PORRSTF :1;
	volatile u8 SFTRSTF :1;
	volatile u8 IWDGRSTF :1;
	volatile u8 WWDGRSTF :1;
	volatile u8 LPWRRSTF :1;
} CSR;
#define RCC_CSR_REG          ((volatile CSR*)0x40021024)
//--------------------------------------------------------------------------------------------
//config macros

#define ENABLE_PERIPHERAL     1
#define DISABLE_PERIPHERAL    0
#define RESET_PERIPHERAL      2

#define HSI                         1
#define HSE                         2
#define PLL                         3
#define PLL_HSI_DIVIDED_BY_2        4
#define PLL_HSE                     5
#define PLL_HSE_DIVIDED_BY_2        6
#define HSE_BYPASS                  7

#define NO_CLOCK_FACTOR                                    0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                       0b1110

#define DISABLE_CLOCK_SECURITY_SYSTEM              0
#define ENABLE_CLOCK_SECURITY_SYSTEM               1

#define    AHB_BUS       0
#define    APB1_BUS      1
#define    APB2_BUS      2

#endif /* RCC_PRIVET_H_ */
