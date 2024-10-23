#ifndef INC_CONTROL_SYSTEM_H_
#define INC_CONTROL_SYSTEM_H_

#include "PowerTrainSystem.h"

void vControlSystemInit(TelemetryData* pTelemetryData);
MotorCommands* pControlSystemUpdateMotorCommands();


#endif 
