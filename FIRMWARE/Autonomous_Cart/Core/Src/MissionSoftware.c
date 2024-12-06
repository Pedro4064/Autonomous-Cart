#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "CollisionSensor.h"
#include "ControlSystem.h"
#include "usart.h"
#include "main.h"
#include "tim.h"
#include "UltrassonicDistanceSystem.h"

#include "TrajectoryGenSystem.h"

#include "EstimationSystem.h"
#include "ComSystem.h"
#include "Profiler.h"


#define TASK_SCHEDULER_CLOCK htim4
#define MOTOR_PID_SCHEDULER_CLOCK htim2 //! Change. Also remember to change PID library to account for different TS
#define PATH_PID_SCHEDULER_CLOCK  htim4 //! Change. Also remember to change PID library to account for different TS

TelemetryData xTelemetryData;
TelemetryDataPackage xTelemetryDataPackage;
StateEstimate xSystemState;
static MotorCommands xMotorCommands;
unsigned char c;
int iFlagCollision,iFlagUS, iCountEnd;
extern flag, bRobotMode;

void vMissionSoftwareMain(void){

    vProfilerInit();
    xSystemState.states = vEstimationSystemInit(&xTelemetryData, &xMotorCommands);

    // Initialize all subsystems

    vTelemetrySystemInit(&xTelemetryData);
    vPowerTrainSystemInit(&xTelemetryData);
    vControlSystemInit(&xTelemetryData, &xMotorCommands);
    vComSystemInit();

    // Initialize all necessary Mission General Timers
    HAL_TIM_Base_Start_IT(&TASK_SCHEDULER_CLOCK);
    HAL_TIM_Base_Start_IT(&MOTOR_PID_SCHEDULER_CLOCK);
    vBuzzerConfig(500,100);

    // Main Application Loop
    while (1)
    {
    	vTrajectoryGenSystem();
    }
    
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    vTelemetrySystemCaptureHandler(htim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	iFlagCollision = xTelemetryData.ucCollisionStatus;
	iFlagUS = xTelemetryData.ucUltrassonicStatus;
    vTelemetrySystemSchedulingHandler(htim);

    if(htim->Instance == PATH_PID_SCHEDULER_CLOCK.Instance){

      if(bRobotMode != 1 && iFlagUS!=1 && iFlagCollision !=1 && iCountEnd<13){
    	  vControlSystemUpdateMotorCommands();
      	  vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, (xMotorCommands.fLeftMotorSpeed)*(60.0f/(2.0f*3.1415)));
      	  vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR,(xMotorCommands.fRightMotorSpeed)*(60.0f/(2.0f*3.1415)));
      }
      else if(bRobotMode == 1 ){
    	  vControlSystemUpdateMotorCommands();
      }
      else if (iFlagCollision==1 ||iFlagUS ==1 ){
    	  vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, 0);
    	  vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR,0);
      }

    }
    if(htim->Instance == MOTOR_PID_SCHEDULER_CLOCK.Instance){

        vPowerTrainSystemRpmControlUpdate();
        if((xTelemetryData.uiLineSensorData[0]==1)&&(xTelemetryData.uiLineSensorData[1]==1)&&(xTelemetryData.uiLineSensorData[2]==1)&&(xTelemetryData.uiLineSensorData[3]==1)&&(xTelemetryData.uiLineSensorData[4]==1)){
            iCountEnd++;

        }else{
            iCountEnd=0;
        }
        if(iCountEnd >= 13 && bRobotMode !=1 && iFlagCollision!=1 && iFlagUS!=1 ){
            vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, 0);
            vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR,0);
        }

        vEstimationSystemComputeEstimate();
    }

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == SW_FRONTAL_Pin)    {
    	vCollisionSensorDetectionHandler();


    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart-> Instance == USART3){
		HAL_UART_Receive_IT(&huart3, &c, 1);
		//HAL_UART_Transmit_IT(&huart3, &c, 1);
		vCommunicationSMProcessByteCommunication(c);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart-> Instance == USART3){
		HAL_UART_Receive_IT(&huart3, &c, 1);
	}
}
