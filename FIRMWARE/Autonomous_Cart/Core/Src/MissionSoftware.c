#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "CollisionSensor.h"
#include "ControlSystem.h"
#include "usart.h"
#include "main.h"
#include "tim.h"
#include "UltrassonicDistanceSystem.h"
#include "ComSystem.h"

#define TASK_SCHEDULER_CLOCK htim4
#define MOTOR_PID_SCHEDULER_CLOCK htim2 //! Change. Also remember to change PID library to account for different TS
#define PATH_PID_SCHEDULER_CLOCK  htim4 //! Change. Also remember to change PID library to account for different TS

TelemetryData xTelemetryData;
TelemetryDataPackage xTelemetryDataPackage;
static MotorCommands* pMotorCommands;
unsigned char c;

extern flag;
void vMissionSoftwareMain(void){

    // Initialize all subsystems
    vTelemetrySystemInit(&xTelemetryData);
    vPowerTrainSystemInit(&xTelemetryData);
    vControlSystemInit(&xTelemetryData);
    vComSystemInit();
    // Initialize all necessary Mission General Timers
    HAL_TIM_Base_Start_IT(&TASK_SCHEDULER_CLOCK);
    HAL_TIM_Base_Start_IT(&MOTOR_PID_SCHEDULER_CLOCK);


    // Main Application Loop
    while (1)
    {
//    	if(flag == 0){
//       vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, CLOCKWISE);
//       vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR,CLOCKWISE);
//
//        vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, 1000);
//        vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, 1000);
//        HAL_Delay(600000);
//
//    	}

    }
    
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemCaptureHandler(htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

    vTelemetrySystemSchedulingHandler(htim);

    if(htim->Instance == PATH_PID_SCHEDULER_CLOCK.Instance){
//        pMotorCommands = pControlSystemUpdateMotorCommands();
//        vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, pMotorCommands->fLeftMotorSpeed);
//        vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, pMotorCommands->fRightMotorSpeed);
    }
    if(htim->Instance == MOTOR_PID_SCHEDULER_CLOCK.Instance){
        vPowerTrainSystemRpmControlUpdate();
    }

    // After All mission critical interrupts were handled, package the telemetry data and send it over uart
    xTelemetryDataPackage.xTelemetryDataTable = xTelemetryData;
	HAL_UART_Transmit(&huart3,  &(xTelemetryDataPackage.uiTelemetryDataBuffer), sizeof(xTelemetryDataPackage.uiTelemetryDataBuffer), 1000);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == SW_FRONTAL_Pin)    {
    	vCollisionSensorDetectionHandler();
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart-> Instance == USART3){
		HAL_UART_Receive_IT(&huart3, &c, 1);
		HAL_UART_Transmit_IT(&huart3, &c, 1);
		//vCommunicationSMProcessByteCommunication(c);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart-> Instance == USART3){
		HAL_UART_Receive_IT(&huart3, &c, 1);
	}
}
