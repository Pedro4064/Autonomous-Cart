
#include "stm32g474xx.h"
#include "ControlSystem.h"
#include "TelemetryProcessingSystem.h"
#include "pid.h"

#define MIN(x, y) (x<y)? x : y
#define MAX(x, y) (x<y)? y : x

// #define KP_LEFT_MOTOR 2.2392
// #define KI_LEFT_MOTOR 1.0543
// #define KD_LEF_MOTOR 0


#define KP_RIGHT_MOTOR 4.5774
#define KI_RIGHT_MOTOR 1.2610
#define KD_RIGHT_MOTOR 0

#define KP_LEFT_MOTOR KP_RIGHT_MOTOR
#define KI_LEFT_MOTOR KI_RIGHT_MOTOR
#define KD_LEF_MOTOR 0



#define THETA_ERROR_4 -0.66597
#define THETA_ERROR_3 -0.40489
#define THETA_ERROR_1 0.40489
#define THETA_ERROR_0 0.66597

MotorCommands xTargetMotorValues;
TelemetryData* pTelemetryValues;
pid_data_type xLeftPid;
pid_data_type xRightPid;

void vControlSystemInit(TelemetryData* pTelemetryData){
    
    pTelemetryValues = pTelemetryData;

    vPidInit(&xLeftPid, KP_LEFT_MOTOR, KI_LEFT_MOTOR, KD_LEF_MOTOR, 1000, 20.0);
    vPidInit(&xRightPid, KP_RIGHT_MOTOR, KI_RIGHT_MOTOR, KD_RIGHT_MOTOR, 1000, 20.0);
}

MotorCommands* pControlSystemUpdateMotorCommands(){

    float fLeftMotorThetaError = MIN(THETA_ERROR_4 * pTelemetryValues->uiLineSensorData[4], THETA_ERROR_3 * pTelemetryValues->uiLineSensorData[3]);
    float fRightMotorThetaError = MAX(THETA_ERROR_1 * pTelemetryValues->uiLineSensorData[1], THETA_ERROR_0 * pTelemetryValues->uiLineSensorData[0]);

    xTargetMotorValues.fRightMotorSpeed = 5 - (-1)*fPidUpdateData(&xLeftPid, 0, fLeftMotorThetaError);
    xTargetMotorValues.fLeftMotorSpeed = 5 - fPidUpdateData(&xRightPid, 0, fRightMotorThetaError);

    return &xTargetMotorValues;
}
