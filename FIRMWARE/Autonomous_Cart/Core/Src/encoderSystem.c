/*
 * encoderSystem.c
 *
 *  Created on: Aug 30, 2024
 *      Author: Mariana Rego
 */
#include "encoderSystem.h"
#include "tim.h"

#define LEFT_ENCODER_TIM htim16
#define RIGHT_ENCODER_TIM htim17
#define ENCODER_CHANNEL TIM_CHANNEL_1

//volatile uint32_t contador_encoder = 0;  // Variável global para contar pulsos
uint32_t rpm = 0;                        // Variável para armazenar o RPM
uint32_t tempo_amostragem_ms = 1000;

extern contador_encoder;

static int* pLeftMotorCoun, pRightMotorCount;

//void vEncoderSystemInit(int pLeftMotorCount, int pRightMotorCount) {
void vEncoderSystemInit(void) {
	HAL_TIM_IC_Start_IT(&LEFT_ENCODER_TIM, ENCODER_CHANNEL);
	HAL_TIM_IC_Start_IT(&RIGHT_ENCODER_TIM, ENCODER_CHANNEL);
}
void vEncoderSystemExecuteMeasurement(){

	   // Tempo de amostragem em segundos
	    float tempo_amostragem_s = tempo_amostragem_ms / 1000.0;

	    // Calcula o RPM
	    rpm = (contador_encoder * 60) / (160 * tempo_amostragem_s);

	    // Resetar o contador para a próxima amostragem
	    contador_encoder = 0;
}
