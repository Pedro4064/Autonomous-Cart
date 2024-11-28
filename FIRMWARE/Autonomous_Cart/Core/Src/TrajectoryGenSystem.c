/*
 * TrajectoryGenSystem.c
 *
 *  Created on: Nov 22, 2024
 *      Author: Mariana Rego
 */

#include "TrajectoryGenSystem.h"
#include "buzzer.h"
#include "UltrassonicDistanceSystem.h"
#include "CollisionSensor.h"
#include "TelemetryProcessingSystem.h"

//declarar os ponteiros
unsigned char* pCollision;
unsigned char* pUSCollision;
float* pUltrassonic;


void vInitTrajectoryGenSystem(TelemetryData* pTelemetryData){

	pCollision=&pTelemetryData->ucCollisionStatus;
	pUSCollision=&pTelemetryData->ucUltrassonicStatus;
	pUltrassonic=&pTelemetryData->fUltrasonicDistanceData;
}

void vTrajectoryGenSystem(void){
	//necessario usar o ponteiro para pegar a distancia
	uiUltrassonicDistanceSystemExecuteMeasurement(&htim3);
	if (*pUltrassonic<=10 && *pUltrassonic!=0 ) {
		vBuzzerPlay();
		*pUSCollision = 1;
		// necessario parar o robo colocando a flag do collision
	}
	else{
		*pUSCollision = 0;
		vBuzzerStop();
	}
}


