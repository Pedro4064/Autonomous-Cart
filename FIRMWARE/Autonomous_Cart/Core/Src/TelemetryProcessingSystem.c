#include "TelemetryProcessingSystem.h"
#include "encoderSystem.h"
#include "LineSensorSystem.h"

TelemetryData* pTelemetryData;

void vTelemetrySystemInit(TelemetryData* pTelemetryData){
    vEncoderSystemInit(&(pTelemetryData->fLeftMotorCount), &(pTelemetryData->fRightMotorCount));
    vLineSensorSystemInit(&(pTelemetryData->uiLineSensorData));
}

void vTelemetrySystemSchedulingHandler(TIM_HandleTypeDef* pTIM){

}

void vTelemetrySystemCaptureHandler(TIM_HandleTypeDef* pTIM){

}

void vTelemetrySystemExternalEventHandler(unsigned int uiGpioPin){

}

