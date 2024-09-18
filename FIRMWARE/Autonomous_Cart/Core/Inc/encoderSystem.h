/*
 * encoderSystem.h
 *
 *  Created on: Aug 30, 2024
 *      Author: Mariana Rego
 */

#ifndef INC_ENCODERSYSTEM_H_
#define INC_ENCODERSYSTEM_H_
#include "tim.h"




//void vEncoderSystemInit(int pLeftMotorCount, int pRightMotorCount);
void vEncoderSystemInit(float *pLeftMotorCount, float *pRightMotorCount);
void vEncoderSystemCounterUpdate(TIM_HandleTypeDef *htim);
void vEncoderSystemExecuteMeasurement();

#endif /* INC_ENCODERSYSTEM_H_ */
