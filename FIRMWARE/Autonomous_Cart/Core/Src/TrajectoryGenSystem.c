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
float* pUltrassonic;


void vInitTrajectoryGenSystem(TelemetryData* pTelemetryData){

	pCollision=&pTelemetryData->ucCollisionStatus;
	pUltrassonic=&pTelemetryData->fUltrasonicDistanceData;
}

void vTrajectoryGenSystem(void){
	//necessario usar o ponteiro para pegar a distancia
	uiUltrassonicDistanceSystemExecuteMeasurement(&htim3);
	if (*pUltrassonic<=10 && *pUltrassonic!=0 ) {
		vBuzzerPlay();
		*pCollision = 1;
		// necessario parar o robo colocando a flag do collision
	}
	else{
		vBuzzerStop();
	}



}
