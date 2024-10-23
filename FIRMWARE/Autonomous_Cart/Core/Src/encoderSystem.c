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

static float fTimeSample = 0.03865;


static float* pLeftMotorRPM;
static float* pRightMotorRPM;

static unsigned long int uiRightMotorPulseCounter, uiLeftMotorPulseCounter, potato;


void vEncoderSystemInit(float *leftMotorCount, float *rightMotorCount) {

	pLeftMotorRPM = leftMotorCount;
	pRightMotorRPM = rightMotorCount;

	HAL_TIM_IC_Start_IT(&LEFT_ENCODER_TIM, ENCODER_CHANNEL);
	HAL_TIM_IC_Start_IT(&RIGHT_ENCODER_TIM, ENCODER_CHANNEL);


}
void vEncoderSystemCounterUpdate(TIM_HandleTypeDef *htim){

    if (htim->Instance == TIM17) {

    	uiRightMotorPulseCounter++;
    	potato++;

    }else if (htim->Instance == TIM16) {

    	uiLeftMotorPulseCounter++;
    }
}

void vEncoderSystemExecuteMeasurement(){
	static unsigned long uiPreviousRightCount;
	static unsigned long uiPreviousLeftCount;

	static unsigned long uiPreviousPulseRightCount;
	static unsigned long uiPreviousPulseLeftCount;

	unsigned long uiRightCount = (uiPreviousPulseRightCount == uiRightMotorPulseCounter)? (RIGHT_ENCODER_TIM.Instance->CNT - uiPreviousRightCount):(RIGHT_ENCODER_TIM.Instance->CNT);
	unsigned long uiLeftCount = (uiPreviousPulseLeftCount == uiLeftMotorPulseCounter)? (LEFT_ENCODER_TIM.Instance->CNT - uiPreviousLeftCount):(LEFT_ENCODER_TIM.Instance->CNT);

	    // Calcula o RPM
		//subtrair valor do anterior
		*pRightMotorRPM = ((uiRightMotorPulseCounter*10000 + uiRightCount) * 60.0) / (160.0 * fTimeSample);
	    *pLeftMotorRPM = ((uiLeftMotorPulseCounter*10000 + uiLeftCount) * 60.0) / (160.0 * fTimeSample);
	    // Resetar o contador para a próxima amostragem
	    uiRightMotorPulseCounter = 0;
	    uiLeftMotorPulseCounter = 0;

	    uiPreviousRightCount = RIGHT_ENCODER_TIM.Instance->CNT;
	    uiPreviousLeftCount = LEFT_ENCODER_TIM.Instance->CNT;

	    uiPreviousPulseRightCount = uiRightMotorPulseCounter;
	    uiPreviousPulseLeftCount = uiLeftMotorPulseCounter;
}
