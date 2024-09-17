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
#include "ComSystem.h"

extern UART_HandleTypeDef hlpuart1;
extern unsigned char c;

char cInputArray[100];
unsigned char cOutputArray[10];
int iCounterPosition;



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
void vCommunicationAppendCharacter() {
	if (c != 13) {
		cInputArray[iCounterPosition] = c;
		iCounterPosition ++;
	}
	else{
		cInputArray[iCounterPosition] = '\0';
		iCounterPosition = 0;
		vCommunicationSentToFloat();
	}
}



// ***************************************************** //
// Method name: vCommunicationSentToFloat                //
// Method description: Essa função é responsável por     //
//                  fazer a inversão do número que foi   //
//                  dado pelo usuário, e printar na tela //
//                  do terminal Putty o resultado obtido.//
// Input params: n/a                                     //
// Output params: n/a                                    //
// ***************************************************** //
void vCommunicationSentToFloat(){
	double dResult = atof(cInputArray);
	HAL_UART_Transmit_IT(&hlpuart1,  cInputArray, strlen(cInputArray));
}

void vComSystemInit(pTelemetryData,pStateEstimate,pMotorCommands){

}


void vComSystemSendRobotData(){

}


void vComSystemParseIncomingData(){

}

