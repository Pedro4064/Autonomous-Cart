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
unsigned char* pCollisionStatus;
float* pUltrassonicDistance;


void vInitTrajectoryGenSystem(TelemetryData* pTelemetryData){

	pCollisionStatus=&pTelemetryData->ucCollisionStatus;
	pUltrassonicDistance=&pTelemetryData->fUltrasonicDistanceData;
}

void vTrajectoryGenSystem(void){
	//necessario usar o ponteiro para pegar a distancia
	uiUltrassonicDistanceSystemExecuteMeasurement(&htim3);
	if (*pUltrassonicDistance<=10) {
		vBuzzerPlay();
		// necessario parar o robo colocando a flag do collision
	}
	else{
		vBuzzerStop();
	}



}
