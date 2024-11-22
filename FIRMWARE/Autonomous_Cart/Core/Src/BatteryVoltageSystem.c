/*
 * BatteryVoltageSystem.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Mariana Rego
 */
#include "adc.h"
#include "BatteryVoltageSystem.h"
#include "MissionSoftware.h"
#include "profiler.h"

#define BATTERY_AD hadc2

float* pBattCharge;

void vBatterySystemInit(float *pBatteryCharge){
	HAL_ADCEx_Calibration_Start(&BATTERY_AD, ADC_SINGLE_ENDED);
	pBattCharge = pBatteryCharge;
}

void vBatterySystemComputeMeasurement(){
	START_PROFILE_SECTION();
	*(pBattCharge) = xTelemetryData.uiRawAdcSensorData[1] >> 16;
	END_PROFILE_SECTION();
}
