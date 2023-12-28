/*
 * Port_Reg.h
 *
 *  Created on: Nov 19, 2023
 *      Author: admin
 */

#ifndef PORT_REG_H_
#define PORT_REG_H_

typedef struct
{
	volatile uint32 CRL;
	volatile uint32 CRH;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 BRR;
	volatile uint32 LCKR;
}GPIO_t;

//STM32f103
/* GPIO Registers base addresses */
#define MGPIOA         ((volatile GPIO_t*)0x40010800)
#define MGPIOB         ((volatile GPIO_t*)0x40010C00)
#define MGPIOC         ((volatile GPIO_t*)0x40011000)


/*
 * GPIO Register Base Adderess Macro
 *
 * */
/* GPIO Registers base addresses */
//#define GPIO_A_BASE_ADDRESS           0x40004000
//#define GPIO_B_BASE_ADDRESS           0x40005000
//#define GPIO_C_BASE_ADDRESS           0x40006000

#define GPIO_A_BASE_ADDRESS           0x40010800
#define GPIO_B_BASE_ADDRESS           0x40010C00
#define GPIO_C_BASE_ADDRESS           0x40011000






#endif /* PORT_REG_H_ */
