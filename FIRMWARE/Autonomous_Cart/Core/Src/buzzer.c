/*
 * buzzer.c
 *
 *  Created on: Nov 20, 2024
 *      Author: njsne
 */


#include "tim.h"
#define BUZZER_TIM htim8
#define BUZZER_CHANNEL TIM_CHANNEL_1

uint32_t xTimerValueBuzzer;
TIM_HandleTypeDef xBuzzerTim;
uint32_t xBuzzerChannel;


void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod){
	//xTimerValueBuzzer = xBuzzerTim.Instance->ARR;
	BUZZER_TIM.Instance->PSC = (10000/usFrequency)-1;

	BUZZER_TIM.Instance->CCR1 = 0;
    htim8.Instance->ARR = usPeriod*100;

}

void vBuzzerPlay(void){
	BUZZER_TIM.Instance->CCR1 = 0.5*(BUZZER_TIM.Instance->ARR);
	HAL_TIM_PWM_Start(&BUZZER_TIM, BUZZER_CHANNEL);
	HAL_TIM_Base_Start_IT(&htim8);

}
void vBuzzerStop(void){
	BUZZER_TIM.Instance->CCR1 = 0.5*(BUZZER_TIM.Instance->ARR);
	HAL_TIM_PWM_Stop(&BUZZER_TIM, BUZZER_CHANNEL);
	HAL_TIM_Base_Stop_IT(&htim8);

}
