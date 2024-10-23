
#include "stm32g474xx.h"
#include "ControlSystem.h"
#include "TelemetryProcessingSystem.h"
#include "pid.h"

#define MIN(x, y) (x<y)? x : y
#define MAX(x, y) (x<y)? y : x

#define KP_LEFT_MOTOR 2.2392
#define KI_LEFT_MOTOR 1.0543
#define KD_LEF_MOTOR 0

#define KP_RIGHT_MOTOR 4.5774
#define KI_RIGHT_MOTOR 1.2610
#define KD_RIGHT_MOTOR 0

#define THETA_ERROR_4 -0.66597
#define THETA_ERROR_3 -0.40489
#define THETA_ERROR_1 0.40489
#define THETA_ERROR_0 0.66597

MotorCommands pTargetMotorValues;
TelemetryData* pTelemetryValues;
pid_data_type* pLeftPid;
pid_data_type* pRightPid;

void vControlSystemInit(TelemetryData* pTelemetryData){
    
    pTelemetryValues = pTelemetryData;

    vPidInit(pLeftPid, KP_LEFT_MOTOR, KI_LEFT_MOTOR, KD_LEF_MOTOR, 0.01, 100.0);
    vPidInit(pRightPid, KP_RIGHT_MOTOR, KI_RIGHT_MOTOR, KD_RIGHT_MOTOR, 0.01, 100.0);
}

MotorCommands* pControlSystemUpdateMotorCommands(){

    float fLeftMotorThetaError = MIN(THETA_ERROR_4 * pTelemetryValues->uiLineSensorData[4], THETA_ERROR_3 * pTelemetryValues->uiLineSensorData[3]);
    float fRightMotorThetaError = MAX(THETA_ERROR_1 * pTelemetryValues->uiLineSensorData[1], THETA_ERROR_0 * pTelemetryValues->uiLineSensorData[0]);

    pTargetMotorValues.fLeftMotorSpeed = 5 - (-1)*fPidUpdateData(pLeftPid, 0, fLeftMotorThetaError);
    pTargetMotorValues.fRightMotorSpeed = 5 - fPidUpdateData(pRightPid, 0, fRightMotorThetaError);

    return &pTargetMotorValues;
}