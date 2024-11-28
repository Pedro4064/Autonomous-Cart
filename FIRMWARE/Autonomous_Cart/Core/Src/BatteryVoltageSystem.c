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
#define ADC_MAX_READING 3680 // tensão de 12,62V
#define ADC_MIN_READING 2770 // tensão de 10V

float* pBattCharge;
float fRawADCBatt;

void vBatterySystemInit(float *pBatteryCharge){
	HAL_ADCEx_Calibration_Start(&BATTERY_AD, ADC_SINGLE_ENDED);
	pBattCharge = pBatteryCharge;
}

void vBatterySystemComputeMeasurement(){

	fRawADCBatt= xTelemetryData.uiRawAdcSensorData[1] >> 16;

	float voltage = (float)(fRawADCBatt - ADC_MIN_READING) / (ADC_MAX_READING - ADC_MIN_READING) * (12.62 - 10) + 10;

		if (voltage >= 12.6) {
			*(pBattCharge)= 100.0; // Bateria totalmente carregada
	    } else if (voltage >= 12.4) {
	    	*(pBattCharge) = 90.0 + (voltage - 12.4) / 0.2 * 10.0;
	    } else if (voltage >= 12.0) {
	    	*(pBattCharge) = 70.0 + (voltage - 12.0) / 0.4 * 20.0;
	    } else if (voltage >= 11.5) {
	    	*(pBattCharge) = 30.0 + (voltage - 11.5) / 0.5 * 40.0;
	    } else if (voltage >= 11.0) {
	    	*(pBattCharge) = 10.0 + (voltage - 11.0) / 0.5 * 20.0;
	    } else if (voltage >= 10.5) {
	    	*(pBattCharge) = (voltage - 10.5) / 0.5 * 10.0;
	    } else {
	    	*(pBattCharge)= 0.0; // Bateria descarregada
	    }
}


