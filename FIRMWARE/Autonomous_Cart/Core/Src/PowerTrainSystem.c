/*
 * powerTrainSystem.c
 *
 *  Created on: Aug 27, 2024
 *      Author: Mariana Rego
 */


#include <powerTrainSystem.h>
#include <tim.h>

#define MOTOR_TIM htim1
#define MOTOR_RIGHT_CHANNEL TIM_CHANNEL_2
#define MOTOR_LEFT_CHANNEL TIM_CHANNEL_1

void vPowerTrainSystemInit(){
	HAL_TIM_Base_Start(&MOTOR_TIM);

	HAL_TIM_PWM_Start(&MOTOR_TIM, MOTOR_LEFT_CHANNEL);
	HAL_TIM_PWM_Start(&MOTOR_TIM, MOTOR_RIGHT_CHANNEL);
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
			__HAL_TIM_SET_COMPARE(&MOTOR_TIM,MOTOR_LEFT_CHANNEL,fSpeed);
			break;

		case RIGHT_MOTOR:
			__HAL_TIM_SET_COMPARE(&MOTOR_TIM,MOTOR_RIGHT_CHANNEL,fSpeed);
			break;
	}
}

