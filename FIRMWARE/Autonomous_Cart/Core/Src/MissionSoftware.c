#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "CollisionSensor.h"
#include "ControlSystem.h"
#include "usart.h"
#include "main.h"
#include "tim.h"
#include "UltrassonicDistanceSystem.h"

#define TASK_SCHEDULER_CLOCK htim4
#define MOTOR_PID_SCHEDULER_CLOCK htim4 //! Change. Also remember to change PID library to account for different TS
#define PATH_PID_SCHEDULER_CLOCK  htim4 //! Change. Also remember to change PID library to account for different TS

TelemetryData xTelemetryData;
TelemetryDataPackage xTelemetryDataPackage;

extern flag;
void vMissionSoftwareMain(void){

    // Initialize all subsystems
    vTelemetrySystemInit(&xTelemetryData);
    vPowerTrainSystemInit(&xTelemetryData);
    vControlSystemInit(&xTelemetryData);

    // Initialize all necessary Mission General Timers
    HAL_TIM_Base_Start_IT(&TASK_SCHEDULER_CLOCK);

    // Main Application Loop
    while (1)
    {
    	vUltrassonicDistanceSystemPulseHandler();
    	HAL_Delay(1);

    }
    
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemCaptureHandler(htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

    vTelemetrySystemSchedulingHandler(htim);

    if(htim->Instance == PATH_PID_SCHEDULER_CLOCK.Instance){
        MotorCommands* pMotorCommands = pControlSystemUpdateMotorCommands();
        vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, pMotorCommands->fLeftMotorSpeed);
        vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, pMotorCommands->fRightMotorSpeed);
    }
    else if(htim->Instance == MOTOR_PID_SCHEDULER_CLOCK.Instance){
        vPowerTrainSystemRpmControlUpdate();
    }

    // After All mission critical interrupts were handled, package the telemetry data and send it over uart
    xTelemetryDataPackage.xTelemetryDataTable = xTelemetryData;
	HAL_UART_Transmit(&hlpuart1,  &(xTelemetryDataPackage.uiTelemetryDataBuffer), sizeof(xTelemetryDataPackage.uiTelemetryDataBuffer), 1000);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == SW_FRONTAL_Pin)    {
    	vCollisionSensorDetectionHandler();
    }
}
