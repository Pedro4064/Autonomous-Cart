#include "tim.h"

#ifndef __TELEMETRY_PROCESSING_SYSTEM_H__
#define __TELEMETRY_PROCESSING_SYSTEM_H__

#define MAX_INTERRUPT_CALLBACK 10

typedef void (*TIM_CALLBACK)(TIM_HandleTypeDef*);
typedef TIM_CALLBACK INPUT_CAPTURE_CALLBACK;
typedef void (*EXTI_CALLBACK)(unsigned int);

typedef struct TELEMETRY_DATA{
    float fLineSensorData;
    float fUltrasonicDistanceData;
    float fBatteryChargeData;
    float fLeftMotorRPM;
    float fRightMotorRPM;
    uint32_t uiLineSensorData;
} TelemetryData;

typedef struct TIM_CALLBACK_LOOKUP{
    TIM_HandleTypeDef* htim;
    TIM_CALLBACK xRegisteredCallbacks[MAX_INTERRUPT_CALLBACK];
}TimCallbackLookup;

typedef struct INPUT_CAPTURE_CALLBACK_LOOKUP{
    TIM_HandleTypeDef* htim;
    INPUT_CAPTURE_CALLBACK xRegisteredCallbacks[MAX_INTERRUPT_CALLBACK];
}InputCaptureCallbackLookup;

typedef struct EXTI_CALLBACK_LOOKUP{
    unsigned int uiGpioPin;
    EXTI_CALLBACK xRegisteredCallbacks[MAX_INTERRUPT_CALLBACK];
}ExtiCallbackLookup;

typedef struct TELEMETRY_CALLBACK_ORCHESTRATION{
    TimCallbackLookup TimerInterruptLookup[MAX_INTERRUPT_CALLBACK];
    InputCaptureCallbackLookup InputCaptureLookup[MAX_INTERRUPT_CALLBACK];
    ExtiCallbackLookup GpioInterruptLookup[MAX_INTERRUPT_CALLBACK];
}TelemetryCallbackOrchestration;


void vTelemetrySystemInit(TelemetryData* pTelemetryData);
void vTelemetrySystemSchedulingHandler(TIM_HandleTypeDef* pTIM);
void vTelemetrySystemCaptureHandler(TIM_HandleTypeDef* pTIM);
void vTelemetrySystemExternalEventHandler(unsigned int uiGpioPin);

#endif