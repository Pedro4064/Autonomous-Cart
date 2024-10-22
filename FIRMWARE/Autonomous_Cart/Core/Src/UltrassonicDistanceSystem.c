/*
 * UltrassonicDistanceSystem.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ES670 B
 */

#include "UltrassonicDistanceSystem.h"
#include "main.h"
#include "tim.h"

uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
uint8_t Is_First_Captured = 0;  // is the first value captured ?
float Distance  = 0;


#define ECO_TIM htim3
#define ULTRASSONIC_CHANNEL TIM_CHANNEL_1


void vUltrassonicDistanceSystemInit(float pDistanceMeasurement){
	HAL_TIM_IC_Start_IT(&ECO_TIM, ULTRASSONIC_CHANNEL);
}

void vUltrassonicDistanceSystemExecuteMeasurement(TIM_HandleTypeDef *htim){
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
		{
			if (Is_First_Captured==0) // if the first value is not captured
			{
				IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
				Is_First_Captured = 1;  // set the first captured as true
				// Now change the polarity to falling edge
				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
			}

			else if (Is_First_Captured==1)   // if the first is already captured
			{
				IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
				__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

				if (IC_Val2 > IC_Val1)
				{
					Difference = IC_Val2-IC_Val1;
				}

				else if (IC_Val1 > IC_Val2)
				{
					Difference = (0xffff - IC_Val1) + IC_Val2;
				}

				Distance = Difference * .034/2;
				Is_First_Captured = 0; // set it back to false

				// set polarity to rising edge
				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
				__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
			}
		}
}

void vUltrassonicDistanceSystemPulseHandler(){
	HAL_GPIO_WritePin(ULTRASSONIC_TRIGGER_GPIO_Port, ULTRASSONIC_TRIGGER_Pin, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	HAL_Delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(ULTRASSONIC_TRIGGER_GPIO_Port, ULTRASSONIC_TRIGGER_Pin, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&ECO_TIM, TIM_IT_CC1);
}
