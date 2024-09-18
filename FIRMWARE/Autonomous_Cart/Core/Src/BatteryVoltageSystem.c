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
unsigned int adcValues[2];
extern uint32_t pLineSensorsReadings[5];

void vBatterySystemInit(float *pBatteryCharge){
	HAL_ADCEx_Calibration_Start(&BATTERY_AD, ADC_SINGLE_ENDED);
}

void vBatterySystemComputeMeasurement(){
	//fAdcValue = HAL_ADC_GetValue(&BATTERY_AD);

	// Aguardar a conversão do primeiro canal (IN3)
		adcValues[1] = pLineSensorsReadings[1] >> 16;
		adcValues[0] = pLineSensorsReadings[1] & 0x0000FFFF;

}
