#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "CollisionSensor.h"
#include "usart.h"
#include "main.h"
#include "tim.h"

#define TASK_SCHEDULER_CLOCK htim4

TelemetryData xTelemetryData;
TelemetryDataPackage xTelemetryDataPackage;

extern flag;
void vMissionSoftwareMain(void){
    // Initialize all subsystems
    vPowerTrainSystemInit();
    vTelemetrySystemInit(&xTelemetryData);

    // Initialize all necessary Mission General Timers
    HAL_TIM_Base_Start_IT(&TASK_SCHEDULER_CLOCK);

    // Main Application Loop
    while (1)
    {
    	if(flag == 0){
        vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, CLOCKWISE);
        vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR,CLOCKWISE);

        vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, 1000);
        vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, 1000);
        HAL_Delay(600000);

    	}
    }
    
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemCaptureHandler(htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemSchedulingHandler(htim);
    xTelemetryDataPackage.xTelemetryDataTable = xTelemetryData;
	HAL_UART_Transmit(&hlpuart1,  &(xTelemetryDataPackage.uiTelemetryDataBuffer), sizeof(xTelemetryDataPackage.uiTelemetryDataBuffer), 1000);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == SW_FRONTAL_Pin)    {
    	vCollisionSensorDetectionHandler();
    }
}
