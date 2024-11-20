/*
 * buzzer.h
 *
 *  Created on: Nov 20, 2024
 *      Author: njsne
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "tim.h"

 void vBuzzerStop(void);
 void vInitBuzzer(TIM_HandleTypeDef *htim, uint32_t channel);
 void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod, TIM_HandleTypeDef *htim);
 void vBuzzerPlay(void);

#endif /* BUZZER_H_ */
