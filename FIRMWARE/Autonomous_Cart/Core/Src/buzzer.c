/*
 * buzzer.c
 *
 *  Created on: Nov 20, 2024
 *      Author: njsne
 */


#include "tim.h"

uint32_t xTimerValueBuzzer;
TIM_HandleTypeDef xBuzzerTim;
uint32_t xBuzzerChannel;

void vInitBuzzer(TIM_HandleTypeDef *htim, uint32_t channel){
	xBuzzerTim = *htim;
	xBuzzerChannel = channel;

}

void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod, TIM_HandleTypeDef *htim){
	//xTimerValueBuzzer = xBuzzerTim.Instance->ARR;
	xBuzzerTim.Instance->PSC = (10000/usFrequency)-1;

	xBuzzerTim.Instance->CCR1 = 0;
   htim5.Instance->ARR = usPeriod*100;

}

void vBuzzerPlay(void){
	xBuzzerTim.Instance->CCR1 = 0.5*(xBuzzerTim.Instance->ARR);
	HAL_TIM_PWM_Start(&xBuzzerTim, xBuzzerChannel);
	HAL_TIM_Base_Start_IT(&htim5);

}
void vBuzzerStop(void){
	xBuzzerTim.Instance->CCR1 = 0.5*(xBuzzerTim.Instance->ARR);
	HAL_TIM_PWM_Stop(&xBuzzerTim, xBuzzerChannel);
	HAL_TIM_Base_Stop_IT(&htim5);

}
