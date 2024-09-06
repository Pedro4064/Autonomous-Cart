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

/*
// ***************************************************** //
// Method name: HAL_UART_RxCpltCallback                  //
// Method description: Essa função é chamada pela própria//
//                    UART no momento em que ocorre uma  //
//                    entrada no terminal Putty.         //
// Input params: UART_HandleTypeDef * huart              //
// Output params: n/a                                    //
// ***************************************************** //
void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart) {
	if (huart == &hlpuart1) {
		// enter = 13
		HAL_UART_Receive_IT(&hlpuart1, &c, 1);
		vCommunicationAppendCharacter();
	}
}
*/

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
		if(c == 44){
			c = 46; //transforma a virgula em ponto
		}
		cInputArray[iCounterPosition] = c;
		iCounterPosition ++;
	}
	else{
		cInputArray[iCounterPosition] = '\0';
		for(int i = 0; i < iCounterPosition; i++){
			if (cInputArray[i] == 46){ //46 é a virgula
				if (i + 3 <= iCounterPosition){
					cInputArray[i + 4] = '\0';
				}
			}
		}
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
	if (dResult >= -1000 && dResult <= 1000){
		dResult = 1 / dResult;
		int iterator = 0;
		for(double i = 1000; i >= 0.001; i = i/10){
			int iResult = dResult / i;
			cOutputArray[iterator] = iResult + 48;
			iterator++;
			dResult = dResult - (iResult)*i;
			if(i == 1){
				c =44;
				cOutputArray[iterator] = c;
				iterator++;
			}
		}
	}
    cOutputArray[8] = 13;
	HAL_UART_Transmit_IT(&hlpuart1,  cOutputArray, 9);
}

vComSystemInit(pTelemetryData,pStateEstimate,pMotorCommands){

}


vComSystemSendRobotData(){

}


vComSystemParseIncomingData(){

}

