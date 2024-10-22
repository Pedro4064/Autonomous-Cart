/*
 * LineSensorSystemInterface.c
 *
 *  Created on: Sep 4, 2024
 *      Author: njsne
 */

#include "LineSensorSystem.h"
#include "MissionSoftware.h"
#include "adc.h"
#include "dma.h"

#define IR1_AD hadc1
#define IR2_AD hadc2
#define IR3_AD hadc3
#define IR4_AD hadc4
#define IR5_AD hadc5

unsigned long (*pLineSensorData)[5];

void vLineSensorSystemInit(unsigned long (*pLineSensorsReadings)[5]){
	pLineSensorData = pLineSensorsReadings;
	HAL_ADCEx_Calibration_Start(&IR1_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR1_AD, &xTelemetryData.uiRawAdcSensorData[0] , 1);

	HAL_ADCEx_Calibration_Start(&IR2_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR2_AD, &xTelemetryData.uiRawAdcSensorData[1] , 2);

	HAL_ADCEx_Calibration_Start(&IR3_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR3_AD, &xTelemetryData.uiRawAdcSensorData[2] , 1);

	HAL_ADCEx_Calibration_Start(&IR4_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR4_AD, &xTelemetryData.uiRawAdcSensorData[3] , 1);

	HAL_ADCEx_Calibration_Start(&IR5_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR5_AD, &xTelemetryData.uiRawAdcSensorData[4] , 1);
}

void vLineSensorSystemProcessMeasurements(){
	(*pLineSensorData)[0] = (xTelemetryData.uiRawAdcSensorData[0]);
	(*pLineSensorData)[1] = (xTelemetryData.uiRawAdcSensorData[1] & 0x0000FFFF);
	(*pLineSensorData)[2] = (xTelemetryData.uiRawAdcSensorData[2]);
	(*pLineSensorData)[3] = xTelemetryData.uiRawAdcSensorData[3];
	(*pLineSensorData)[4] = xTelemetryData.uiRawAdcSensorData[4];

}
