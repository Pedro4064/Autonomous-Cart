#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "arm_math.h"

#ifndef __ESTIMATION_SYSTEM_H__
#define __ESTIMATION_SYSTEM_H__

typedef struct STATE_ESTIMATE{
    float32_t fX;
    float32_t fX_dot;
    float32_t fX_ddot;
    float32_t fY;
    float32_t fY_dot;
    float32_t fY_ddot;
    float32_t fTheta;
    float32_t fTheta_dot
}StateEstimate;

typedef union SYSTEM_STATE{
    StateEstimate xStateStruct;
    float32_t fStateVector[8]
}SystemState;


void vEstimationSystemInit(SystemState* pSystemState, TelemetryData* pTelemetryData, MotorCommands* pMotorCommands);
void vEstimationSystemComputeEstimate();


#endif