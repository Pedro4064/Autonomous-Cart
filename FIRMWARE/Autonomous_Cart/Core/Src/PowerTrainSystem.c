/*
 * powerTrainSystem.c
 *
 *  Created on: Aug 27, 2024
 *      Author: Mariana Rego
 */


#include <tim.h>
#include <PowerTrainSystem.h>

#define MOTOR_TIM htim1
#define MOTOR_RIGHT_CHANNEL TIM_CHANNEL_2
#define MOTOR_LEFT_CHANNEL TIM_CHANNEL_1

#define KP_LEFT_MOTOR 0.01941
#define KI_LEFT_MOTOR 0.1059
#define KD_LEF_MOTOR 0.0

#define KP_RIGHT_MOTOR 0.0219
#define KI_RIGHT_MOTOR 0.145
#define KD_RIGHT_MOTOR 0

MotorCommands xMotorCommands;
pid_data_type xLeftMotorPid;
pid_data_type xRightMotorPid;
static TelemetryData *pTelemetryData;
static float fLeftActuatorEffort;
static float fRightActuatorEffort;

void vPowerTrainSystemInit(TelemetryData *pTelData){
	HAL_TIM_Base_Start(&MOTOR_TIM);

	HAL_TIM_PWM_Start(&MOTOR_TIM, MOTOR_LEFT_CHANNEL);
	HAL_TIM_PWM_Start(&MOTOR_TIM, MOTOR_RIGHT_CHANNEL);



	vPidInit(&xLeftMotorPid, KP_LEFT_MOTOR, KI_LEFT_MOTOR, KD_LEF_MOTOR, 1000, 1, 38.65);
	vPidInit(&xRightMotorPid, KP_RIGHT_MOTOR, KI_RIGHT_MOTOR, KD_RIGHT_MOTOR, 1000, 1, 38.65);

	pTelemetryData = pTelData;

	vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, CLOCKWISE);
	vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR, CLOCKWISE);

}
void vPowerTrainSystemSetMotorDirection(Motor xMotor, MotorSpin xDirection){
	switch (xMotor){
		case LEFT_MOTOR:

			if(xDirection == CLOCKWISE){
				HAL_GPIO_WritePin(LEFT_MOTOR_DIR_IN1_GPIO_Port,LEFT_MOTOR_DIR_IN1_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(LEFT_MOTOR_DIR_IN2_GPIO_Port,LEFT_MOTOR_DIR_IN2_Pin,GPIO_PIN_RESET);

			} if(xDirection == COUNTER_CLOCKWISE){
				HAL_GPIO_WritePin(LEFT_MOTOR_DIR_IN1_GPIO_Port,LEFT_MOTOR_DIR_IN1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEFT_MOTOR_DIR_IN2_GPIO_Port,LEFT_MOTOR_DIR_IN2_Pin,GPIO_PIN_SET);

			} break;

		case RIGHT_MOTOR:

			if(xDirection == CLOCKWISE){
				HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_IN3_GPIO_Port,RIGHT_MOTOR_DIR_IN3_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_IN4_GPIO_Port,RIGHT_MOTOR_DIR_IN4_Pin,GPIO_PIN_RESET);

			} if(xDirection == COUNTER_CLOCKWISE){
				HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_IN3_GPIO_Port,RIGHT_MOTOR_DIR_IN3_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_IN4_GPIO_Port,RIGHT_MOTOR_DIR_IN4_Pin,GPIO_PIN_SET);
			} break;
	}
}
void vPowerTrainSystemSetMotorSpeed(Motor xMotor,double fSpeed){
	switch (xMotor){
		case LEFT_MOTOR:
		 	xMotorCommands.fLeftMotorSpeed = fSpeed;
			break;

		case RIGHT_MOTOR:
		 	xMotorCommands.fRightMotorSpeed = fSpeed;
			break;
	}
}

void vPowerTrainSystemRpmControlUpdate(){

	fLeftActuatorEffort = fPidUpdateData(&xLeftMotorPid, pTelemetryData->fLeftMotorRPM, xMotorCommands.fLeftMotorSpeed);
	fRightActuatorEffort = fPidUpdateData(&xRightMotorPid, pTelemetryData->fRightMotorRPM, xMotorCommands.fRightMotorSpeed);

	__HAL_TIM_SET_COMPARE(&MOTOR_TIM,MOTOR_LEFT_CHANNEL,(fLeftActuatorEffort)*1000);
	// __HAL_TIM_SET_COMPARE(&MOTOR_TIM,MOTOR_LEFT_CHANNEL,xMotorCommands.fLeftMotorSpeed);
	__HAL_TIM_SET_COMPARE(&MOTOR_TIM,MOTOR_RIGHT_CHANNEL,(fRightActuatorEffort)*1000);
	// __HAL_TIM_SET_COMPARE(&MOTOR_TIM,MOTOR_RIGHT_CHANNEL,xMotorCommands.fRightMotorSpeed);

}

