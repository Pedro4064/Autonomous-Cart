#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "arm_math.h"

#ifndef __ESTIMATION_SYSTEM_H__
#define __ESTIMATION_SYSTEM_H__

#define NUM_STATES 8

typedef struct STATE_ESTIMATE{
    double dX;
    double dY;
    double dTheta;
}StateEstimate;

typedef union SYSTEM_STATE{
    StateEstimate xStateStruct;
    float64_t fStateVector[8];
}SystemState;


void vEstimationSystemInit(TelemetryData* pTelemData, MotorCommands* pMotorCommands, SystemState* pSysState);
void vEstimationSystemComputeEstimate();


#endif