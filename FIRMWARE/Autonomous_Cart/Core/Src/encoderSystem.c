/*
 * encoderSystem.c
 *
 *  Created on: Aug 30, 2024
 *      Author: Mariana Rego
 */
#include "encoderSystem.h"
#include "tim.h"

#define LEFT_ENCODER_TIM htim16
//#define RIGHT_ENCODER_TIM htim17
#define INTERNAL_CLOCK htim4
#define ENCODER_CHANNEL 1

static int* pLeftMotorCoun, pRightMotorCount;

void vEncoderSystemInit(int pLeftMotorCount, int pRightMotorCount) {
	INTERNAL_CLOCK.Instance->ARR = 10000;
	HAL_TIM_Base_Start_IT(&LEFT_ENCODER_TIM);
//	HAL_TIM_Base_Start_IT(&RIGHT_ENCODER_TIM);
	HAL_TIM_Base_Start_IT(&INTERNAL_CLOCK);
}
void vEncoderSystemExecuteMeasurement(){

}
