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

uint32_t uiULTRA;

void vInitTrajectoryGenSystem(void){



}

void vTrajectoryGenSystem(void){
	//necessario usar o ponteiro para pegar a distancia
	uiULTRA = uiUltrassonicDistanceSystemExecuteMeasurement(&htim3);
	if (uiULTRA<=10) {
		vBuzzerPlay();
		// necessario parar o robo colocando a flag do collision
	}
	else{
		vBuzzerStop();
	}



}
