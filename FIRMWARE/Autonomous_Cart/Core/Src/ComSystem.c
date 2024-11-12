// ********************************************** //
// File name: communication.c                     //
// File description: Esse arquivo contém todas as //
//                    funções que foram feitas    //
//                    para o recebimento de dados //
//                    através do Putty, calculos e//
//                    o retorno de novos dados.   //
// Author name: Nisio José Soares Neto e Luis     //
//              Paulo Siqueira Silva.             //
// Creation date: 19abr2024                       //
// Revision date: 26abr2024                       //
// ********************************************** //
#include "stm32g4xx_hal.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ComSystem.h"
#include "light_printf.h"
#include <string.h>
#include "TelemetryProcessingSystem.h"
#include "PowerTrainSystem.h"
#include "ControlSystem.h"
#include "tim.h"
#include "MissionSoftware.h"


extern UART_HandleTypeDef huart3;
extern unsigned char c;

#define IDDLE '0'
#define GET '2'
#define READY '1'
#define SET '3'
#define PARAM '4'
#define VALUE '5'
#define MOTOR_PID_SCHEDULER_CLOCK htim2 //! Change. Also remember to change PID library to account for different TS
#define PATH_PID_SCHEDULER_CLOCK  htim4 //! Change. Also remember to change PID library to account for different TS



#define MAX_VALUE_LENGHT 300

unsigned char ucUARTState = IDDLE;
unsigned char ucValueCount ;

unsigned char cOutput[MAX_VALUE_LENGHT],ucC;
extern UART_HandleTypeDef huart3;
extern TelemetryData xTelemetryData;
float fVelocityTarget;
extern bRobotMode;

void vCommunicationSMProcessByteCommunication(unsigned char ucByte){
	static unsigned char ucParam;
	static unsigned char ucValue[MAX_VALUE_LENGHT+1];
	if('#' == ucByte){
		ucUARTState = READY;
	}
	else{
		if(IDDLE != ucUARTState){
			switch(ucUARTState){
				case READY:
					switch(ucByte){
						case 'g':
							ucUARTState = GET;
							break;
						case 's':
							ucUARTState = SET;
							break;
						default:
							ucUARTState = IDDLE;
					}
					for(int i = 0; i<MAX_VALUE_LENGHT; i++){
						ucValue[i] = '\0';
					}
					break;
				case GET:
					if('u'==ucByte ||'b' == ucByte ||'a' == ucByte ||'g' == ucByte ||'l' == ucByte||'v' == ucByte||'d' == ucByte||'s' == ucByte||'j' == ucByte){
						ucParam = ucByte;
						ucUARTState = PARAM;
					}
					else{
						ucUARTState = IDDLE;
					}
					break;
				case SET:
					if('v' == ucByte || 'r' == ucByte || 'm'==ucByte || 'l' == ucByte ||'j' == ucByte){
						ucParam = ucByte;
						ucValueCount = 0;
						ucUARTState = VALUE;
					}
					else{
						ucUARTState = IDDLE;

					}
					break;
				case PARAM:
					if(';' == ucByte){
						vCommunicationSMReturnParam(ucParam, &xTelemetryData);
					}
					else if('x' == ucByte|| 'y' == ucByte|| 'z' == ucByte|| 's' == ucByte || 'a' == ucByte || 'm' == ucByte){
						ucParam = ucByte+ucParam;
						break;
					}
					ucUARTState = IDDLE;
					break;
				case VALUE:
					if(ucByte!=';'){
						if(ucValueCount<MAX_VALUE_LENGHT){
							ucValue[ucValueCount++] = ucByte;
						}
					}
					else{
						if(';'==ucByte){
							ucValue[ucValueCount] = '\0';
							vCommunicationSMSetParam(ucParam, ucValue);
						}
						ucUARTState = IDDLE;
					}
					break;
			}
		}
	}
}


// ***************************************************** //
// Method name: vCommunicationAppendCharacter            //
// Method description: Essa função coloca cada um dos    //
//                  caracteres que o usuário deu como    //
//                  entrada em um vetor. Já transformando//
//                  na entrada '.' em ','. Depois de     //
//                  armazenar, verifica se o número tem  //
//                  mais de 4 casas decimais, se sim,    //
//                  deixa apenas 3.                      //
// Input params: n/a                                     //
// Output params: n/a                                    //
// ***************************************************** //
/*void vCommunicationAppendCharacter() {
	if (c != 13) {
		cInputArray[iCounterPosition] = c;
		iCounterPosition ++;
	}
	else{
		cInputArray[iCounterPosition] = '\0';
		iCounterPosition = 0;
		vCommunicationSentToFloat();
	}
}*/



// ***************************************************** //
// Method name: vCommunicationSentToFloat                //
// Method description: Essa função é responsável por     //
//                  fazer a inversão do número que foi   //
//                  dado pelo usuário, e printar na tela //
//                  do terminal Putty o resultado obtido.//
// Input params: n/a                                     //
// Output params: n/a                                    //
// ***************************************************** //
/*void vCommunicationSentToFloat(){
	double dResult = atof(cInputArray);
	HAL_UART_Transmit_IT(&huart3,  cInputArray, strlen(cInputArray));
}*/

void vComSystemInit(){
	HAL_UART_Receive_IT(&huart3, &c, 1);
	//HAL_UART_Transmit_IT(&huart3, &c, 1);
	// precisamos atribuir uma variavel ponteiro para telemetry data, state estimate
	// e pMotorCommands. Em linhas gerais toda base é de recebimento e envio.
}


void vComSystemSendRobotData(){
	// aqui precisamos enviar as informações modificadas em uma codificação especifica
	// ver parametro de comunicação bluetooth.
}


void vComSystemParseIncomingData(){
	// aqui precisamos receber as informações modificadas em uma codificação especifica
	// ver parametro de comunicação bluetooth.

}

void vCommunicationSMReturnParam(unsigned char ucParam, TelemetryData *xTelemetryData){
	switch(ucParam){
	        case 'u': // #gu;
	            snprintf(cOutput, sizeof(cOutput), "%.3f\r\n", xTelemetryData->fUltrasonicDistanceData);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case 'b': // #gb;
	            snprintf(cOutput, sizeof(cOutput), "%.0f\r\n", xTelemetryData->fBatteryChargeData);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case ('a' + 'x'): // #gax;
	            snprintf(cOutput, sizeof(cOutput), "%.2f\r\n", xTelemetryData->xImuReadings.fAccelX);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case ('a' + 'y'): // #gay;
	            snprintf(cOutput, sizeof(cOutput), "%.2f\r\n", xTelemetryData->xImuReadings.fAccelY);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case ('a' + 'z'): // #gaz;
	            snprintf(cOutput, sizeof(cOutput), "%.2f\r\n", xTelemetryData->xImuReadings.fAccelZ);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case ('g' + 'x'): // #ggx;
	            snprintf(cOutput, sizeof(cOutput), "%.2f\r\n", xTelemetryData->xImuReadings.fGyroX);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case ('g' + 'y'): // #ggy;
	            snprintf(cOutput, sizeof(cOutput), "%.2f\r\n", xTelemetryData->xImuReadings.fGyroY);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        case ('v' + 'a'): // #gva (Velocidade atual)
				snprintf(cOutput, sizeof(cOutput), "%.3f\r\n", xTelemetryData->fLeftMotorRPM); // Substitua fLeftMotorRPM por fVelocityActual quando o valor for atualizado
				HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
				break;
			case ('v' + 'm'): // #gvm (Velocidade média)
				snprintf(cOutput, sizeof(cOutput), "%.3f\r\n", xTelemetryData->fRightMotorRPM); // Substitua fRightMotorRPM por fVelocityAverage quando o valor for atualizado
				HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
				break;
			case ('g' + 'd'): // #gd (Distância percorrida)
				snprintf(cOutput, sizeof(cOutput), "%.3f\r\n", xTelemetryData->fLineSensorData); // Substitua fLineSensorData por fDistanceCovered quando o valor for atualizado
				HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
				break;
			case 's': // #gs (Modo do robô)
				snprintf(cOutput, sizeof(cOutput), "%u\r\n", xTelemetryData->fBatteryChargeData); // Substitua ucCollisionStatus por ucRobotState quando o valor for atualizado
				HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
				break;
	        case 'l': // #gls;
	            snprintf(cOutput, sizeof(cOutput), "%lu,%lu,%lu,%lu,%lu\r\n",
	                xTelemetryData->uiLineSensorData[0], xTelemetryData->uiLineSensorData[1],
	                xTelemetryData->uiLineSensorData[2], xTelemetryData->uiLineSensorData[3],
	                xTelemetryData->uiLineSensorData[4]);
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        // Caso para JSON #gj
	        case 'j': { // #gj (JSON com todos os dados)
	            snprintf(cOutput, sizeof(cOutput),
	                     "{\"ultrasonicDistance\": %.3f, \"batteryCharge\": %.0f, "
	                     "\"acceleration\": {\"x\": %.2f, \"y\": %.2f, \"z\": %.2f}, "
	                     "\"gyro\": {\"x\": %.2f, \"y\": %.2f}, "
	                     "\"lineSensorData\": [%lu,%lu,%lu,%lu,%lu], "
	                     "\"velocity\": {\"actual\": %.3f, \"average\": %.3f}, "
	                     "\"distanceCovered\": %.3f, \"robotState\": %u};",
	                     xTelemetryData->fUltrasonicDistanceData,
	                     xTelemetryData->fBatteryChargeData,
	                     xTelemetryData->xImuReadings.fAccelX, xTelemetryData->xImuReadings.fAccelY,
	                     xTelemetryData->xImuReadings.fAccelZ, xTelemetryData->xImuReadings.fGyroX,
	                     xTelemetryData->xImuReadings.fGyroY,
	                     xTelemetryData->uiLineSensorData[0], xTelemetryData->uiLineSensorData[1],
	                     xTelemetryData->uiLineSensorData[2], xTelemetryData->uiLineSensorData[3],
	                     xTelemetryData->uiLineSensorData[4],
	                     xTelemetryData->fLeftMotorRPM, // Substitua por fVelocityActual
	                     xTelemetryData->fRightMotorRPM, // Substitua por fVelocityAverage
	                     xTelemetryData->fLineSensorData, // Substitua por fDistanceCovered
	                     bRobotMode); // Substitua por bRobotMode
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        }
	        default:
	            break;
	    }
}

void vCommunicationSMSetParam(unsigned char ucParam, unsigned char *ucValue){
    switch(ucParam){
        case 'v':  // Define o valor de fVelocityTarget (velocidade alvo)
            fVelocityTarget = atof(ucValue); // Converte string para float
            break;

        case 'l':  // Define o valor de fLeftMotorSpeed (rotação do motor esquerdo)
        	if(atof(ucValue) > 0 && bRobotMode == 1){
        		vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, CLOCKWISE);
        		vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, abs(atof(ucValue)));
        	}
        	else if(atof(ucValue) < 0 && bRobotMode ==1){
        		vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, COUNTER_CLOCKWISE);
				vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, abs(atof(ucValue)));
        	}else if(bRobotMode ==1){
        		vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, abs(atof(ucValue)));
        	}
            break;

        case 'm':  // Define o valor de bRobotMode (modo do robô)
            if(ucValue[0] == '0'){
                bRobotMode = 0; // Modo automático
                //HAL_TIM_Base_Start_IT(&MOTOR_PID_SCHEDULER_CLOCK);
                //HAL_TIM_Base_Start_IT(&PATH_PID_SCHEDULER_CLOCK);
            }
            else if(ucValue[0] == '1'){
                bRobotMode = 1; // Modo manual
                //HAL_TIM_Base_Stop_IT(&MOTOR_PID_SCHEDULER_CLOCK);
                //HAL_TIM_Base_Stop_IT(&PATH_PID_SCHEDULER_CLOCK);
            }
            break;

        case 'r':  // Define o valor de fRightMotorSpeed (rotação do motor direito)
        	if(atof(ucValue) > 0 && bRobotMode ==1){
				vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR, CLOCKWISE);
				vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, abs(atof(ucValue)));
			}
			else if(atof(ucValue) < 0 && bRobotMode == 1){
				vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR, COUNTER_CLOCKWISE);
				vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, abs(atof(ucValue)));
			}else if(bRobotMode ==1){
				vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, abs(atof(ucValue)));
			}
            break;

        case 'j':  // Processa o JSON
            // Função para processar a string JSON recebida
            //vParseJsonSetValues(ucValue); //
            break;
        default:
            // Caso o parâmetro não seja reconhecido, pode-se tratar o erro aqui
            break;
    }
}

void vParseJsonSetValues(unsigned char *ucJsonString) {
    // Variáveis temporárias para armazenar valores intermediários
    char buffer[16];  // Buffer para armazenar valores temporários como strings
    float value;      // Variável para armazenar valores numéricos
    int mode;         // Variável para armazenar o valor do modo do robô

    // Procurar e processar o valor de "velocityTarget"
    char *ptr = strstr((const char*)ucJsonString, "\"velocityTarget\":");
    if (ptr != NULL) {
        sscanf(ptr, "\"velocityTarget\":%[^,}]", buffer);
        value = atof(buffer);
        fVelocityTarget = value;  // Atribui o valor à variável correspondente
    }

    // Procurar e processar o valor de "rightMotorSpeed"
    ptr = strstr((const char*)ucJsonString, "\"rightMotorSpeed\":");
    if (ptr != NULL) {
        sscanf(ptr, "\"rightMotorSpeed\":%[^,}]", buffer);
        value = atof(buffer);
        if (value >= 0) {
            //vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR, CLOCKWISE);
        } else {
            //vPowerTrainSystemSetMotorDirection(RIGHT_MOTOR, COUNTER_CLOCKWISE);
        }
        //vPowerTrainSystemSetMotorSpeed(RIGHT_MOTOR, abs(value));
    }

    // Procurar e processar o valor de "leftMotorSpeed"
    ptr = strstr((const char*)ucJsonString, "\"leftMotorSpeed\":");
    if (ptr != NULL) {
        sscanf(ptr, "\"leftMotorSpeed\":%[^,}]", buffer);
        value = atof(buffer);
        if (value >= 0) {
            //vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, CLOCKWISE);
        } else {
            //vPowerTrainSystemSetMotorDirection(LEFT_MOTOR, COUNTER_CLOCKWISE);
        }
        //vPowerTrainSystemSetMotorSpeed(LEFT_MOTOR, abs(value));
    }

    // Procurar e processar o valor de "robotMode"
    ptr = strstr((const char*)ucJsonString, "\"robotMode\":");
    if (ptr != NULL) {
        sscanf(ptr, "\"robotMode\":%d", &mode);
        bRobotMode = mode;  // Atribui o valor do modo à variável correspondente
    }
}
