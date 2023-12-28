/*
 * bit_math.h
 *
 * Created: 10/20/2023 11:07:14 AM
 *  Author: zaher
 *  description :Bit_Math Lib
 */ 

#ifndef bit_math_H_
#define bit_math_H_

#define SET_BIT(REG,BITNUM)    (REG |= ( 1 << BITNUM))
#define CLEAR_BIT(REG,BITNUM)  (REG &= ~( 1 << BITNUM))
#define TOGG_BIT(REG,BITNUM)   (REG ^= ( 1 << BITNUM))
#define GET_BIT(REG,BITNUM)    ((REG >> BITNUM) & (1))
#define SET_BYTE(BYTE,VALUE)      BYTE = VALUE

#endif /* bit_math.h */
