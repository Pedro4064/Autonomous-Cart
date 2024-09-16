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
uint32_t rpm_d = 0;// Variável para armazenar o RPM
uint32_t rpm_e = 0;

uint32_t tempo_amostragem_s = 1;

extern contador_encoder;
extern contador_encoder2;

static int* pLeftMotorCoun, pRightMotorCount;

//void vEncoderSystemInit(int pLeftMotorCount, int pRightMotorCount) {
void vEncoderSystemInit(void) {
	HAL_TIM_IC_Start_IT(&LEFT_ENCODER_TIM, ENCODER_CHANNEL);
	HAL_TIM_IC_Start_IT(&RIGHT_ENCODER_TIM, ENCODER_CHANNEL);
}
void vEncoderSystemExecuteMeasurement(){

	   // Tempo de amostragem em segundos
	    //float tempo_amostragem_s = tempo_amostragem_ms / 1000.0;

	    // Calcula o RPM
	    //motor 80:1 e sao duas pas logo para uma rotacao temos 160 do encoder
	    rpm_d = (contador_encoder * 60) / (160 * tempo_amostragem_s);
	    rpm_e = (contador_encoder2 * 60) / (160 * tempo_amostragem_s);
	    // Resetar o contador para a próxima amostragem
	    contador_encoder = 0;
	    contador_encoder2 = 0;
}
