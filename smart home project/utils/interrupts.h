/*
 * interrupts.h
 *
 * Created: 9/18/2020 1:08:51 PM
 *  Author: Moataz
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#define SREG			*((volatile uint8*)0x5F)

#define EXINT0				   		__vector_1
#define EXINT1						__vector_2
#define EXINT2				   		__vector_3
#define TIMER2_COMP					__vector_4
#define TIMER2_OVF					__vector_5
#define TIMER1_CAPT					__vector_6
#define TIMER1_COMPA				__vector_7
#define TIMER1_COMPB				__vector_8
#define TIMER1_OVF					__vector_9
#define TIMER0_COMP					__vector_10
#define TIMER0_OVF					__vector_11
#define SPI_STC						__vector_12
#define USART_RXC					__vector_13
#define USART_UDRE					__vector_14
#define USART_TXC					__vector_15
#define ADC_COMPLETE				__vector_16

#define ISR(vector)				   	void vector(void) __attribute__((signal,used));\
void vector(void)


#define GLOBAL_INT_EN		SET_BIT(SREG,BIT7)
#define GLOBAL_INT_DIS		CLR_BIT(SREG,BIT7)

#endif /* INTERRUPTS_H_ */