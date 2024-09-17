/*
 * BatteryVoltageSystem.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Mariana Rego
 */
#include "adc.h"
#include "BatteryVoltageSystem.h"

#define BATTERY_AD hadc2

uint32_t fAdcValue;
uint32_t *pAdcValue = &fAdcValue;
float fTempValue;
unsigned long int adcValues[2];

void vBatterySystemInit(float *pBatteryCharge){
	HAL_ADCEx_Calibration_Start(&BATTERY_AD, ADC_SINGLE_ENDED);
}

void vBatterySystemComputeMeasurement(){
	//fAdcValue = HAL_ADC_GetValue(&BATTERY_AD);

	// Aguardar a conversão do primeiro canal (IN3)

	    adcValues[0] = HAL_ADC_GetValue(&hadc2);

	    // Ler o valor convertido do canal IN4 (Rank 2)
	    adcValues[1] = HAL_ADC_GetValue(&hadc2);

}
