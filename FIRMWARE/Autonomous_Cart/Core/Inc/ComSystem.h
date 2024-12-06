/*
 * communication.h
 *
 *  Created on: Aug 30, 2024
 *      Author: njsne
 */

#ifndef INC_COMMUNICATION_H_
#define INC_COMMUNICATION_H_

#include "TelemetryProcessingSystem.h"
#include "EstimationSystem.h"


// ***************************************************** //
// Method name: HAL_UART_RxCpltCallback                  //
// Method description: Essa função é chamada pela própria//
//                    UART no momento em que ocorre uma  //
//                    entrada no terminal Putty.         //
// Input params: UART_HandleTypeDef * huart              //
// Output params: n/a                                    //
// ***************************************************** //
void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart);


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
void vCommunicationAppendCharacter();


// ***************************************************** //
// Method name: vCommunicationSentToFloat                //
// Method description: Essa função é responsável por     //
//                  fazer a inversão do número que foi   //
//                  dado pelo usuário, e printar na tela //
//                  do terminal Putty o resultado obtido.//
// Input params: n/a                                     //
// Output params: n/a                                    //
// ***************************************************** //
void vCommunicationSentToFloat();


void vComSystemInit(StateEstimate* pSysState);

void vComSystemSendRobotData();

void vComSystemParseIncomingData();

void vCommunicationSMProcessByteCommunication(unsigned char ucByte);

void vCommunicationSMReturnParam(unsigned char ucParam, TelemetryData *xTelemetryData);

void vCommunicationSMSetParam(unsigned char ucParam, unsigned char *ucValue);

void vParseJsonSetValues(unsigned char *ucJsonString);

#endif /* INC_COMMUNICATION_H_ */
