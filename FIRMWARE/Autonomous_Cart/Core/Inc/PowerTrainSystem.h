/*
 * PowerTrainSystem.h
 *
 *  Created on: Aug 27, 2024
 *      Author: Mariana Rego
 */

#ifndef INC_POWERTRAINSYSTEM_H_
#define INC_POWERTRAINSYSTEM_H_

typedef enum {
	rightMotor = 1,
	leftMotor = 2
} Motor;

typedef enum {

} MotorSpin;

void vPowerTrainSystemInit();
void vPowerTrainSystemSetMotorDirection(Motor xMotor, MotorSpin xDirection);
void vPowerTrainSystemSetMotorspeed(Motor xMotor,double fSpeed);

#endif /* INC_POWERTRAINSYSTEM_H_ */
