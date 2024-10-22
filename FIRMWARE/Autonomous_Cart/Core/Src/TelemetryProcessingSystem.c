#include "TelemetryProcessingSystem.h"
#include "BatteryVoltageSystem.h"
#include "LineSensorSystem.h"
#include "imu.h"
#include "encoderSystem.h"
#include "UltrassonicDistanceSystem.h"

TelemetryData* pTelemetryData;
TelemetryCallbackOrchestration xCallbackOrchestration = {.TimerInterruptLookup = {
                                                                                    {.htim = &htim4, .xRegisteredCallbacks = {vEncoderSystemExecuteMeasurement}},
																					{.htim = &htim3, .xRegisteredCallbacks = {vUltrassonicDistanceSystemExecuteMeasurement}},
                                                                                    {.htim = &htim4, .xRegisteredCallbacks = {vBatterySystemComputeMeasurement}}, 
                                                                                    {.htim = &htim4, .xRegisteredCallbacks = {vImuComputeMeasurements}}, 
                                                                                    {.htim = &htim4, .xRegisteredCallbacks = {vLineSensorSystemProcessMeasurements}}, 
                                                                                },
                                                          .InputCaptureLookup = {
                                                                                    {.htim = &htim17, .xRegisteredCallbacks = {vEncoderSystemCounterUpdate}},
                                                                                    {.htim = &htim16, .xRegisteredCallbacks = {vEncoderSystemCounterUpdate}}
                                                                                }
                                                        };

void vTelemetrySystemInit(TelemetryData* pTelemetryData){
    vEncoderSystemInit(&(pTelemetryData->fLeftMotorRPM), &(pTelemetryData->fRightMotorRPM));
    vLineSensorSystemInit(pTelemetryData->uiLineSensorData);
    vBatterySystemInit(&(pTelemetryData->fBatteryChargeData));
    vImuInit(&(pTelemetryData->xImuReadings));
}

void vTelemetrySystemSchedulingHandler(TIM_HandleTypeDef* pTIM){


    // Iterate over all timer entries
    for (int iSchedulerEntryIndex = 0; iSchedulerEntryIndex < MAX_INTERRUPT_CALLBACK; iSchedulerEntryIndex++){

        // Check if it is initialized by checking the htim pointer default value
        TimCallbackLookup xSchedulerEntry = xCallbackOrchestration.TimerInterruptLookup[iSchedulerEntryIndex];
        if (xSchedulerEntry.htim == NULL)
            continue;
        if (xSchedulerEntry.htim->Instance != pTIM->Instance)
            continue;

        // If the htim associated with the entry is the one that generated the interrupt, iterate over all callbacks
        for (int iCallbackIndex = 0; iCallbackIndex < MAX_INTERRUPT_CALLBACK; iCallbackIndex++){

            // Check if a callback was assigned by verifying that the function pointer is not null
            INPUT_CAPTURE_CALLBACK pCallbackPointer = xSchedulerEntry.xRegisteredCallbacks[iCallbackIndex];
            if(pCallbackPointer == NULL)
                break;
            else 
                (*pCallbackPointer)(pTIM);
        }
            
        
    }
    

}

void vTelemetrySystemCaptureHandler(TIM_HandleTypeDef* pTIM){

    // Iterate over all input capture entries
    for (int iInputCaptureEntryIndex = 0; iInputCaptureEntryIndex < MAX_INTERRUPT_CALLBACK; iInputCaptureEntryIndex++){

        // Check if it is initialized by checking the htim pointer default value
        InputCaptureCallbackLookup xInputCaptureEntry = xCallbackOrchestration.InputCaptureLookup[iInputCaptureEntryIndex];
        if (xInputCaptureEntry.htim == NULL)
            continue;
        if (xInputCaptureEntry.htim->Instance != pTIM->Instance)
            continue;

        // If the htim associated with the entry is the one that generated the interrupt, iterate over all callbacks
        for (int iCallbackIndex = 0; iCallbackIndex < MAX_INTERRUPT_CALLBACK; iCallbackIndex++){

            // Check if a callback was assigned by verifying that the function pointer is not null
            INPUT_CAPTURE_CALLBACK pCallbackPointer = xInputCaptureEntry.xRegisteredCallbacks[iCallbackIndex];
            if(pCallbackPointer == NULL)
                break;
            else 
                (*pCallbackPointer)(pTIM);
        }
            
        
    }
    

}

void vTelemetrySystemExternalEventHandler(unsigned int uiGpioPin){

    // Iterate over all Exti interrupt entries
    for (int iExtiEntryIndex = 0; iExtiEntryIndex < MAX_INTERRUPT_CALLBACK; iExtiEntryIndex++){

        // Check if it is initialized by checking the gpio pin default value
        ExtiCallbackLookup xExtiEntry = xCallbackOrchestration.GpioInterruptLookup[iExtiEntryIndex];
        if (xExtiEntry.uiGpioPin == 0)
            continue;
        if (xExtiEntry.uiGpioPin != uiGpioPin)
            continue;

        // If the htim associated with the entry is the one that generated the interrupt, iterate over all callbacks
        for (int iCallbackIndex = 0; iCallbackIndex < MAX_INTERRUPT_CALLBACK; iCallbackIndex++){

            // Check if a callback was assigned by verifying that the function pointer is not null
            EXTI_CALLBACK pCallbackPointer = xExtiEntry.xRegisteredCallbacks[iCallbackIndex];
            if(pCallbackPointer == NULL)
                break;
            else 
                (*pCallbackPointer)(uiGpioPin);
        }
            
        
    }
    


}

