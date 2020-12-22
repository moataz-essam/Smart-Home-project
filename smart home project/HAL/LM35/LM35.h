/*
 * LM35.h
 *
 * Created: 10/28/2020 1:50:45 AM
 *  Author: Moataz
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "../../utils/STD_types.h"

uint16 LM35_ReadSample(void);
uint8 LM35_ReadTemp(void);

#endif /* LM35_H_ */