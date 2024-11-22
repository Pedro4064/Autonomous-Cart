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
 void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod);
 void vBuzzerPlay(void);

#endif /* BUZZER_H_ */
