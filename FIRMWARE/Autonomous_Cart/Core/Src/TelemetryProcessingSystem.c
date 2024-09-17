#include "TelemetryProcessingSystem.h"
#include "encoderSystem.h"
#include "LineSensorSystem.h"

TelemetryData* pTelemetryData;
TelemetryCallbackOrchestration xCallbackOrchestration = {.TimerInterruptLookup = {
                                                                                    {.htim = &htim4, .xRegisteredCallbacks = {vEncoderSystemExecuteMeasurement}}, 
                                                                                },
                                                          .InputCaptureLookup = {
                                                                                    {.htim = &htim17, .xRegisteredCallbacks = {vEncoderSystemCounterUpdate}},
                                                                                    {.htim = &htim16, .xRegisteredCallbacks = {vEncoderSystemCounterUpdate}}
                                                                                }
                                                        };

void vTelemetrySystemInit(TelemetryData* pTelemetryData){
    vEncoderSystemInit(&(pTelemetryData->fLeftMotorRPM), &(pTelemetryData->fRightMotorRPM));
    vLineSensorSystemInit(&(pTelemetryData->uiLineSensorData));
}

void vTelemetrySystemSchedulingHandler(TIM_HandleTypeDef* pTIM){
    vEncoderSystemExecuteMeasurement();

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

}

