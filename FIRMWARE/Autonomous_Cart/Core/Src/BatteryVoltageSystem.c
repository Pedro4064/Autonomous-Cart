/*
 * BatteryVoltageSystem.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Mariana Rego
 */
#include "adc.h"
#include "BatteryVoltageSystem.h"
#include "MissionSoftware.h"

#define BATTERY_AD hadc2

float* pBattCharge;

void vBatterySystemInit(float *pBatteryCharge){
	HAL_ADCEx_Calibration_Start(&BATTERY_AD, ADC_SINGLE_ENDED);
	pBattCharge = pBatteryCharge;
}

void vBatterySystemComputeMeasurement(){

	*(pBattCharge) = xTelemetryData.uiRawAdcSensorData[1] >> 16;

}
