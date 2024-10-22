#ifndef INC_CONTROL_SYSTEM_H_
#define INC_CONTROL_SYSTEM_H_

#include "PowerTrainSystem.h"

typedef struct{
    MotorSpin xLeftMotorSpinDirection;
    MotorSpin xRightMotorSpinDirection;

    float fLeftMotorSpeed;
    float fRightMotorSpeed;
}MotorCommands


#endif 
