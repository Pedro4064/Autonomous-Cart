#include "EstimationSystem.h"
#include "math.h"

#define r 0.02
#define L 0.165
#define dT 0.077486

static TelemetryData* pTelemetryData;
static MotorCommands* pMotComm;
static SystemState* pSystemState;

void vEstimationSystemInit(TelemetryData* pTelemData, MotorCommands* pMotorCommands, SystemState* pSysState){
    pTelemetryData = pTelemData;
    pMotComm = pMotorCommands;
    pSystemState = pSysState;
}

void vEstimationSystemComputeEstimate(){

    static double dForwardVelocity;

    // Calculate Theta
    pSystemState->xStateStruct.dTheta = pSystemState->xStateStruct.dTheta + pTelemetryData->xImuReadings.fGyroZ * dT;

    // Calculate Vx and Vy, and respective positions
    dForwardVelocity = dForwardVelocity + pTelemetryData->xImuReadings.fAccelY * dT;

    double dVxCurrent = dForwardVelocity*cos(pSystemState->xStateStruct.dTheta);
    double dVyCurrent = dForwardVelocity*sin(pSystemState->xStateStruct.dTheta);

    pSystemState->xStateStruct.dX = pSystemState->xStateStruct.dX + dVxCurrent * dT;
    pSystemState->xStateStruct.dY = pSystemState->xStateStruct.dY + dVyCurrent * dT;

}