/*
 * powerTrainSystem.h
 *
 *  Created on: Aug 27, 2024
 *      Author: Mariana Rego
 */

#ifndef INC_POWERTRAINSYSTEM_H_
#define INC_POWERTRAINSYSTEM_H_

#include "pid.h"

typedef enum {
	RIGHT_MOTOR = 1,
	LEFT_MOTOR = 0
} Motor;

typedef enum {
	CLOCKWISE = 0,
	COUNTER_CLOCKWISE = 1
} MotorSpin;

typedef struct{
	MotorSpin xLeftMotorSpinDirection;
	MotorSpin xRightMotorSpinDirection;
	float fLeftMotorSpeed;
	float fRightMotorSpeed;
} MotorCommands;

void vPowerTrainSystemInit();
void vPowerTrainSystemSetMotorDirection(Motor xMotor, MotorSpin xDirection);
void vPowerTrainSystemSetMotorSpeed(Motor xMotor,double fSpeed);
void vPowerTrainSystemRpmControlUpdate(float fLeftRpmReading, float fRightRpmReading);

#endif /* INC_POWERTRAINSYSTEM_H_ */
