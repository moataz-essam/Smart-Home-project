/*
 * BitMath.h
 *
 * Created: 9/15/2020 10:26:22 PM
 *  Author: Moataz
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

/***configure single bit***/
#define SET_BIT(u8reg,Pin)	(u8reg |= (1<<Pin))
#define CLR_BIT(u8reg,Pin)	(u8reg &=~(1<<Pin))
#define TOGGLE_BIT(u8reg,Pin)	(u8reg ^= (1<<Pin))

/***configure port***/
#define SET_PORT(u8reg)		(u8reg |= 0xFF)
#define CLR_PORT(u8reg)		(u8reg &= 0x00)
#define TOGGLE_PORT(u8reg)	(u8reg ^= 0xFF)

/***configure first 4 pins in the port***/
#define SET_LOW_NIB(u8reg)		(u8reg |= 0x0F)
#define CLR_LOW_NIB(u8reg)		(u8reg &= 0xF0)
#define TOGGLE_LOW_NIB(u8reg)		(u8reg ^= 0x0F)

/***configure second 4 pins in the port***/
#define SET_HIGH_NIB(u8reg)		(u8reg |= 0xF0)
#define CLR_HIGH_NIB(u8reg)		(u8reg &= 0x0F)
#define TOGGLE_HIGH_NIB(u8reg)	(u8reg ^= 0xF0)

/***reading value of single bit***/
#define GET_BIT(u8reg,Pin)	(u8reg & (0x01<<Pin))

/***reading value of 4 bits(low nibble & high nibble)***/
#define GET_LOW_NIB(u8reg)	(u8reg & 0X0F)
#define GET_HIGH_NIB(u8reg)	(u8reg & (0X0F<<4))

#endif /* BITMATH_H_ */