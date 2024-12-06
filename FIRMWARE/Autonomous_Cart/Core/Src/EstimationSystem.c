#include "EstimationSystem.h"
#include "math.h"

#define r 0.02
#define L 0.165
#define dT 0.0386535

static TelemetryData* pTelemetryData;
static MotorCommands* pMotComm;
static SystemState* pSystemState;

void vEstimationSystemInit(TelemetryData* pTelemData, MotorCommands* pMotorCommands, SystemState* pSysState){
    pTelemetryData = pTelemData;
    pMotComm = pMotorCommands;
    pSystemState = pSysState;
}

void vEstimationSystemComputeEstimate(){

    // Calculate Theta
    // double dLeftRadSeconds = pTelemetryData->fLeftMotorRPM * 2 * 3.14  / 60;
    // double dRightRadSeconds = pTelemetryData->fRightMotorRPM * 2 * 3.14 / 60;
    static double dLastThetaDot;
    static double dLastVx;
    static double dLastVy;

    double dLeftRadSeconds = pMotComm->fLeftMotorSpeed;
    double dRightRadSeconds =  pMotComm->fRightMotorSpeed;

    double dThetaDot = (r/L)*(dRightRadSeconds - dLeftRadSeconds);
    pSystemState->xStateStruct.dTheta = pSystemState->xStateStruct.dTheta + (dLastThetaDot + dThetaDot)*0.5*dT;
    dLastThetaDot = dThetaDot;

    // Calculate Vx and Vy, and respective positions
    double dVxCurrent = (r/2)*(dRightRadSeconds + dLeftRadSeconds)*cos(pSystemState->xStateStruct.dTheta);
    double dVyCurrent = (r/2)*(dRightRadSeconds + dLeftRadSeconds)*sin(pSystemState->xStateStruct.dTheta);

    pSystemState->xStateStruct.dX = pSystemState->xStateStruct.dX + (dLastVx + dVxCurrent) * 0.5 * dT;
    pSystemState->xStateStruct.dY = pSystemState->xStateStruct.dY + (dLastVy + dVyCurrent) * 0.5 * dT;
    dLastVx = dVxCurrent;
    dLastVy = dVyCurrent;

}