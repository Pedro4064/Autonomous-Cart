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
	uiULTRA = uiUltrassonicDistanceSystemExecuteMeasurement(&htim3);
	if (uiULTRA<=10) {
		vBuzzerPlay();
	}
	else{
		vBuzzerStop();
	}


}
