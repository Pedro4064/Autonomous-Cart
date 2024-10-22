
#include "stm32g474xx.h"
#include "ControlSystem.h"
#include "TelemetryProcessingSystem.h"
#include "pid.h"

#define KP_LEFT_MOTOR 0.0137
#define KI_LEFT_MOTOR 5.7902
#define KD_LEF_MOTOR 0

#define KP_RIGHT_MOTOR 0.01234
#define KI_RIGHT_MOTOR 891.0069
#define KD_RIGHT_MOTOR 0


MotorCommands* pTargetMotorValues;
MotorCommands* pMotorCmds;
TelemetryData* pTelemetryValues;
pid_data_type* pPid;

//TelemetryData -> Mensurado
//MotorCommands -> Enviado (entre PID e Modelo)
//TargetValues  -> Desejado 
vControlSystemInit(MotorCommands* pTargetValues, MotorCommands* pMotorCommands, TelemetryData* pTelemetryData){
    
    pTargetMotorValues = pTargetValues;
    pMotorCmds = pMotorCommands;
    pTelemetryValues = pTelemetryData;

    //Motor esquerdo
    vPidInit(pPid, KP_LEFT_MOTOR, KI_LEFT_MOTOR, KD_LEF_MOTOR, 0.01, 100.0)
    vPidInit(pPid, KP_RIGHT_MOTOR, KI_RIGHT_MOTOR, KD_RIGHT_MOTOR, 0.01, 100.0)



    
    vPidInit()

}