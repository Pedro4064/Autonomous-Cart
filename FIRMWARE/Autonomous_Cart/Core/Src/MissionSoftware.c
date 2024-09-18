#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "main.h"
#include "tim.h"

#define TASK_SCHEDULER_CLOCK htim4

TelemetryData xTelemetryData;


void vMissionSoftwareMain(void){
    // Initialize all subsystems
    vPowerTrainSystemInit();
    vTelemetrySystemInit(&xTelemetryData);

    // Initialize all necessary Mission General Timers
    HAL_TIM_Base_Start_IT(&TASK_SCHEDULER_CLOCK);

    // Main Application Loop
    while (1)
    {
        vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, CLOCKWISE);
        vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR,CLOCKWISE);

        vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, 1000);
        vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, 1000);
        HAL_Delay(60000);
        vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, 0);
        vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR , 0);
        HAL_Delay(10000);

    }
    
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemCaptureHandler(htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemSchedulingHandler(htim);
}