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
#define TIMCLOCK 170000000



//volatile uint32_t contador_encoder = 0;  // Variável global para contar pulsos

static float fTimeSample = 0.03865;


static float* pLeftMotorRPM;
static float* pRightMotorRPM;

static unsigned int uiLeftEncoderOverflowCount;
static unsigned int uiRightEncoderOverflowCount;

static unsigned long int uiRightMotorPulseCounter, uiLeftMotorPulseCounter, potato;


void vEncoderSystemInit(float *leftMotorCount, float *rightMotorCount) {

	pLeftMotorRPM = leftMotorCount;
	pRightMotorRPM = rightMotorCount;

	HAL_TIM_IC_Start_IT(&LEFT_ENCODER_TIM, ENCODER_CHANNEL);
	HAL_TIM_IC_Start_IT(&RIGHT_ENCODER_TIM, ENCODER_CHANNEL);


}

void vEncoderSystemHandleCounterOverflow(TIM_HandleTypeDef *htim){
	uiLeftEncoderOverflowCount = (htim->Instance == LEFT_ENCODER_TIM.Instance)? uiLeftEncoderOverflowCount+1 : uiLeftEncoderOverflowCount;
	uiRightEncoderOverflowCount = (htim->Instance == RIGHT_ENCODER_TIM.Instance)? uiRightEncoderOverflowCount+1 : uiRightEncoderOverflowCount;
}

void vEncoderSystemCounterUpdate(TIM_HandleTypeDef *htim){

    static uint8_t cFirstCaptureRight = 1; // Flag to track first capture
    static uint32_t uiRightCounterRisingEdge;
    static uint32_t uiRightCounterFallingEdge;
    static uint32_t uiRightGap;
    static uint8_t cFirstCaptureLeft = 1;
    static uint32_t uiLeftCounterRisingEdge;
    static uint32_t uiLeftCounterFallingEdge;
    static uint32_t uiLeftGap;
    
    // Constants for RPM calculation
    const uint32_t PPR = 160;    // Pulses per Revolution
    const uint32_t TIMER_CLOCK = 72000000; // Timer clock frequency (e.g., 72 MHz)
    
    if (htim->Instance == RIGHT_ENCODER_TIM.Instance) {  // Check if it's the right encoder timer

        if (cFirstCaptureRight) {
            // First capture (rising edge)
            // uiRightCounterRisingEdge = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            uiRightCounterRisingEdge = 0;
            __HAL_TIM_SET_COUNTER(htim, 0);
            cFirstCaptureRight = 0;
        } else {
            // Second capture (falling edge or next rising edge)
            uiRightCounterFallingEdge = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            
            // Calculate the time difference between two captures (in timer ticks)
            if (uiRightCounterFallingEdge >= uiRightCounterRisingEdge) {
                uiRightGap = (uiRightCounterFallingEdge - uiRightCounterRisingEdge) + 10000*uiRightEncoderOverflowCount;
            } else {
                // Timer overflow scenario
                uiRightGap = (htim->Init.Period - uiRightCounterRisingEdge) + uiRightCounterFallingEdge + 10000*uiRightEncoderOverflowCount;
            }
            
            // Reset the counter for the next measurement
            __HAL_TIM_SET_COUNTER(htim, 0);

            // Calculate time difference in microseconds (us)
            float timeInSeconds = ((float)uiRightGap / (TIMER_CLOCK / (htim->Init.Prescaler + 1)));

            // Calculate RPM: (1 / time per pulse) * 60 (for minutes) / PPR (pulses per revolution)
            if (timeInSeconds > 0) {
                *pRightMotorRPM = (1.0f / (timeInSeconds * PPR)) * 60.0f;
            } else {
                *pRightMotorRPM = 0; // Avoid division by zero
            }

            // Set flag back to indicate next capture is the first one
            cFirstCaptureRight = 1;
			uiRightEncoderOverflowCount = 0;
        }
    }
    if (htim->Instance == LEFT_ENCODER_TIM.Instance) {  // Check if it's the Left encoder timer

            if (cFirstCaptureLeft) {
                // First capture (rising edge)
                // uiRightCounterRisingEdge = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
                uiLeftCounterRisingEdge = 0;
                __HAL_TIM_SET_COUNTER(htim, 0);
                cFirstCaptureLeft=0;
            } else {
                // Second capture (falling edge or next rising edge)
                uiLeftCounterFallingEdge = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);

                // Calculate the time difference between two captures (in timer ticks)
                if (uiLeftCounterFallingEdge >= uiLeftCounterRisingEdge) {
                    uiLeftGap = (uiLeftCounterFallingEdge - uiLeftCounterRisingEdge) + 10000*uiLeftEncoderOverflowCount;
                } else {
                    // Timer overflow scenario
                    uiLeftGap = (htim->Init.Period - uiLeftCounterRisingEdge) + uiLeftCounterFallingEdge + 10000*uiLeftEncoderOverflowCount;
                }

                // Reset the counter for the next measurement
                __HAL_TIM_SET_COUNTER(htim, 0);

                // Calculate time difference in microseconds (us)
                float timeInSeconds = ((float)uiLeftGap / (TIMER_CLOCK / (htim->Init.Prescaler + 1)));

                // Calculate RPM: (1 / time per pulse) * 60 (for minutes) / PPR (pulses per revolution)
                if (timeInSeconds > 0) {
                    *pLeftMotorRPM = (1.0f / (timeInSeconds * PPR)) * 60.0f;
                } else {
                    *pLeftMotorRPM = 0; // Avoid division by zero
                }

                // Set flag back to indicate next capture is the first one
                cFirstCaptureLeft = 1;
    			uiLeftEncoderOverflowCount = 0;
            }
        }

}


void vEncoderSystemExecuteMeasurement(){
	    // Calcula o RPM
		//subtrair valor do anterior
		// *pRightMotorRPM = ((uiRightMotorPulseCounter*10000 + uiRightCount) * 60.0) / (160.0 * fTimeSample);
	    // *pLeftMotorRPM = ((uiLeftMotorPulseCounter*10000 + uiLeftCount) * 60.0) / (160.0 * fTimeSample);
	    // // Resetar o contador para a próxima amostragem
	    // uiRightMotorPulseCounter = 0;
	    // uiLeftMotorPulseCounter = 0;

	    // uiPreviousRightCount = RIGHT_ENCODER_TIM.Instance->CNT;
	    // uiPreviousLeftCount = LEFT_ENCODER_TIM.Instance->CNT;

	    // uiPreviousPulseRightCount = uiRightMotorPulseCounter;
	    // uiPreviousPulseLeftCount = uiLeftMotorPulseCounter;
}
