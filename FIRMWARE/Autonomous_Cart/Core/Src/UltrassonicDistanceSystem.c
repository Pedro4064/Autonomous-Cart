/*
 * UltrassonicDistanceSystem.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ES670 B
 */

#include "UltrassonicDistanceSystem.h"
#include "main.h"
#include "tim.h"

uint32_t uiInputCaptureValue1 = 0; // recebe o primeiro valor do Input Capture
uint32_t uiInputCaptureValue2 = 0; // recebe o segundo valor do Input Capture
uint32_t uiDifference = 0;
uint8_t uiFirstCaptured = 0;       // verifica se e`a primeira captura do input capture
float uiDistance  = 0;
float* pUltrassonicDistance;

#define ECO_TIM htim3
#define ULTRASSONIC_CHANNEL TIM_CHANNEL_1


void vUltrassonicDistanceSystemInit(float *fUltrasonicDistanceData){
	pUltrassonicDistance = fUltrasonicDistanceData;
	HAL_TIM_PWM_Start(&htim20, ULTRASSONIC_CHANNEL);
	htim20.Instance->CCR1 = 8;  // O PWM ficara alto por aproximadamente 12.24 us e baixo pelo restante do período de 100 ms
	HAL_TIM_IC_Start_IT(&ECO_TIM, ULTRASSONIC_CHANNEL);

}

void uiUltrassonicDistanceSystemExecuteMeasurement(TIM_HandleTypeDef *htim){
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			if (uiFirstCaptured==0) // caso o primeiro valor do input capture nao tenha sido pego
			{
				uiInputCaptureValue1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // le o primeiro valor do input capture
				uiFirstCaptured = 1;  // muda para verdadeiro
				// Para mudar a polaridade para falling edge:
				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
			}

			else if (uiFirstCaptured==1)   // caso ja tenha sido captado uma vez
			{
				uiInputCaptureValue2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // le o segundo valor do input capture
				__HAL_TIM_SET_COUNTER(htim, 0);  // reseta o counter

				if (uiInputCaptureValue2 > uiInputCaptureValue1)
				{
					uiDifference = uiInputCaptureValue2-uiInputCaptureValue1;
				}

				else if (uiInputCaptureValue1 > uiInputCaptureValue2)
				{
					uiDifference = (0xffff - uiInputCaptureValue1) + uiInputCaptureValue2;
				}
				// multiplica a diferenca por 1.5 que e'o tempo em microsegundos de cada contagem
				// divide o valor por 58.772us que e'o que leva 1 cm para refletir a onda
				uiDistance = uiDifference * 1.5/(58.772);
				uiFirstCaptured = 0; // set it back to false



				// set polarity to rising edge
				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
				//__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
				//HAL_TIM_PWM_Stop(&htim20, ULTRASSONIC_CHANNEL);
				HAL_TIM_PWM_Start(&htim20, ULTRASSONIC_CHANNEL);

			}

		}
	*pUltrassonicDistance = uiDistance;

//necessario mudar para o ponteiro
}

