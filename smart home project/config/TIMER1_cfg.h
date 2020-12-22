/*
 * TIMER1_cfg.h
 *
 * Created: 12/21/2020 6:45:43 PM
 *  Author: Moataz
 */ 


#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

////////////////////////////////////////////////////////////////////
/*
 * Choose mode from following list:-
 *
 * TIMER1_MODE_NORMAL
 * TIMER0_MODE_PHASE_CORRECT
 * TIMER0_MODE_CTC
 * TIMER0_MODE_FAST_PWM
 * */
#define TIMER1_MODE_SELECTED		TIMER1_MODE_NORMAL
//////////////////////////////////////////////////////////////////////
/*
 * Choose compare mode from following list:-
 *
 * //compare modes if mode selected is fast PWM
 * CMP_MODE_NON_INVERT
 * CMP_MODE_INVERT
 
 //compare modes if the selected mode is phase correct PWM
 * CMP_MODE_ClrUp_SetDown
 * CMP_MODE_SetUp_ClrDown
 
 //compare mode if mode selected is normal mode or CTC
 * CMP_MODE_TOGGLE_OC0
 * CMP_MODE_CLR_OC0
 * CMP_MODE_SET_OC0
 * */
#define CMP_MODE_SELECTED				CMP_MODE_TOGGLE_OC0
//////////////////////////////////////////////////////////////////////////
#define TIMER1_PRELOADED_COUNTER				(0)
//////////////////////////////////////////////////////////////////////////
#define TIMER1_PointOfCompare					(255)
//////////////////////////////////////////////////////////////////////////
/*
 * Choose prescaler clock from following list:-
 *
 * TIMER1_PRESCALER_1
 * TIMER1_PRESCALER_8
 * TIMER1_PRESCALER_64
 * TIMER1_PRESCALER_256
 * TIMER1_PRESCALER_1024
 * TIMER1_ExtClock_FALLING
 * TIMER1_ExtClock_RISING
 * */
#define TIMER1_PRESCALER_SELECTED		TIMER1_PRESCALER_256
////////////////////////////////////////////////////////////////////////////

#endif /* TIMER1_CFG_H_ */