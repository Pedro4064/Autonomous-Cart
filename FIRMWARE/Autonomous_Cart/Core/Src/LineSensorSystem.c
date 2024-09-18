/*
 * LineSensorSystemInterface.c
 *
 *  Created on: Sep 4, 2024
 *      Author: njsne
 */

#include "LineSensorSystem.h"
#include "adc.h"
#include "dma.h"

#define IR1_AD hadc1
#define IR2_AD hadc2
#define IR3_AD hadc3
#define IR4_AD hadc4
#define IR5_AD hadc5

extern uint32_t uiAdcValue;
// adcValues[0] = pLineSensorsReadings[1] & 0x0000FFFF;

void vLineSensorSystemInit(uint32_t *pLineSensorsReadings){
	HAL_ADCEx_Calibration_Start(&IR1_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR1_AD, &pLineSensorsReadings[0] , 1);

	HAL_ADCEx_Calibration_Start(&IR2_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR2_AD, &pLineSensorsReadings[1] , 2);

	HAL_ADCEx_Calibration_Start(&IR3_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR3_AD, &pLineSensorsReadings[2] , 1);

	HAL_ADCEx_Calibration_Start(&IR4_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR4_AD, &pLineSensorsReadings[3] , 1);

	HAL_ADCEx_Calibration_Start(&IR5_AD, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&IR5_AD, &pLineSensorsReadings[4] , 1);
}
