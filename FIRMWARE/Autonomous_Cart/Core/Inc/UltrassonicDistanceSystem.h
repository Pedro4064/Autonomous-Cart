/*
 * UltrassonicDistanceSystem.h
 *
 *  Created on: Oct 22, 2024
 *      Author: ES670 B
 */

#ifndef ULTRASSONICDISTANCESYSTEM_H_
#define ULTRASSONICDISTANCESYSTEM_H_
#include "tim.h"

void vUltrassonicDistanceSystemInit();

void vUltrassonicDistanceSystemExecuteMeasurement(TIM_HandleTypeDef *htim);


#endif /* ULTRASSONICDISTANCESYSTEM_H_ */
