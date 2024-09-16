#include "tim.h"

#ifndef __TELEMETRY_PROCESSING_SYSTEM_H__
#define __TELEMETRY_PROCESSING_SYSTEM_H__

typedef struct TELEMETRY_DATA{
    float fLineSensorData;
    float fUltrasonicDistanceData;
    float fBatteryChargeData;
    float fLeftMotorCount;
    float fRightMotorCount;
    uint32_t uiLineSensorData;
} TelemetryData;


void vTelemetrySystemInit(TelemetryData* pTelemetryData);
void vTelemetrySystemSchedulingHandler(TIM_HandleTypeDef* pTIM);
void vTelemetrySystemCaptureHandler(TIM_HandleTypeDef* pTIM);
void vTelemetrySystemExternalEventHandler(unsigned int uiGpioPin);

#endif