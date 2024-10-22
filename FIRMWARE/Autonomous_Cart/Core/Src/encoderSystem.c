/*
 * encoderSystem.c
 *
 *  Created on: Aug 30, 2024
 *      Author: Mariana Rego
 */
#include "encoderSystem.h"
#include "tim.h"

#define LEFT_ENCODER_TIM htim16
#define RIGHT_ENCODER_TIM htim17
#define ENCODER_CHANNEL TIM_CHANNEL_1

//volatile uint32_t contador_encoder = 0;  // Variável global para contar pulsos

static float fTimeSample = 0.08;


static float* pLeftMotorRPM;
static float* pRightMotorRPM;

static unsigned long int uiRightMotorPulseCounter, uiLeftMotorPulseCounter;


void vEncoderSystemInit(float *leftMotorCount, float *rightMotorCount) {

	pLeftMotorRPM = leftMotorCount;
	pRightMotorRPM = rightMotorCount;

	HAL_TIM_IC_Start_IT(&LEFT_ENCODER_TIM, ENCODER_CHANNEL);
	HAL_TIM_IC_Start_IT(&RIGHT_ENCODER_TIM, ENCODER_CHANNEL);


}
void vEncoderSystemCounterUpdate(TIM_HandleTypeDef *htim){

    if (htim->Instance == TIM17) {

    	uiRightMotorPulseCounter++;

    }else if (htim->Instance == TIM16) {

    	uiLeftMotorPulseCounter++;
    }
}

void vEncoderSystemExecuteMeasurement(){
	    // Calcula o RPM
		*pRightMotorRPM = (uiRightMotorPulseCounter * 60.0) / (160.0 * fTimeSample);
	    *pLeftMotorRPM = (uiLeftMotorPulseCounter * 60.0) / (160.0 * fTimeSample);
	    // Resetar o contador para a próxima amostragem
	    uiRightMotorPulseCounter = 0;
	    uiLeftMotorPulseCounter = 0;
}
