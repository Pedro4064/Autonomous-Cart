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
#include "ComSystem.h"
#include "light_printf.h"
#include <string.h>
#include "TelemetryProcessingSystem.h"


extern UART_HandleTypeDef huart3;
extern unsigned char c;

#define IDDLE '0'
#define GET '2'
#define READY '1'
#define SET '3'
#define PARAM '4'
#define VALUE '5'

#define MAX_VALUE_LENGHT 249

unsigned char ucUARTState = IDDLE;
unsigned char ucValueCount;
unsigned char cOutput[249],ucC;
extern UART_HandleTypeDef usart3;
extern TelemetryData xTelemetryData;


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
					if('v' == ucByte || 'g' == ucByte || 'm'==ucByte || 'a' == ucByte ||'j' == ucByte){
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
						vCommunicationSMReturnParam(ucParam);
					}
					else if('x' == ucByte|| 'y' == ucByte|| 'z' == ucByte|| 's' == ucByte || 'a' == ucByte || 'm' == ucByte){
						ucParam = ucByte+ucParam;
						break;
					}
					ucUARTState = IDDLE;
					break;
				case VALUE:
					if((ucByte>='0' && ucByte<='9') || '.'==ucByte){
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

void vComSystemInit(pTelemetryData,pStateEstimate,pMotorCommands){
	HAL_UART_Receive_IT(&huart3, &c, 1);
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
				snprintf(cOutput, sizeof(cOutput), "%u\r\n", xTelemetryData->ucCollisionStatus); // Substitua ucCollisionStatus por ucRobotState quando o valor for atualizado
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
	                     "\"distanceCovered\": %.3f, \"robotState\": %u}\r\n",
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
	                     xTelemetryData->ucCollisionStatus); // Substitua por bRobotMode
	            HAL_UART_Transmit_IT(&huart3, (uint8_t*)cOutput, strlen(cOutput));
	            break;
	        }
	        default:
	            break;
	    }
}

