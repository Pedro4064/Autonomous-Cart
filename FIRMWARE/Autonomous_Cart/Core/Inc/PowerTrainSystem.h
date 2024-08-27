/*
 * powerTrainSystem.h
 *
 *  Created on: Aug 27, 2024
 *      Author: Mariana Rego
 */

#ifndef INC_POWERTRAINSYSTEM_H_
#define INC_POWERTRAINSYSTEM_H_

typedef enum {
	RIGHT_MOTOR = 1,
	LEFT_MOTOR = 0
} Motor;

typedef enum {
	CLOCKWISE = 0,
	COUNTER_CLOCKWISE = 1
} MotorSpin;

void vPowerTrainSystemInit();
void vPowerTrainSystemSetMotorDirection(Motor xMotor, MotorSpin xDirection);
void vPowerTrainSystemSetMotorSpeed(Motor xMotor,double fSpeed);

#endif /* INC_POWERTRAINSYSTEM_H_ */
