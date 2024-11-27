/*
 * CollisionSensor.c
 *
 *  Created on: Oct 11, 2024
 *      Author: ES670 B
 */
#include "CollisionSensor.h"
#include "PowerTrainSystem.h"
#include "TelemetryProcessingSystem.h"

unsigned char* pCollisionStatus;
//verificar se está correto na Bu

void vCollisionSensorInit(unsigned char *ucCollisionStatus){
//receber o ponteiro do collision struct e defino como zero
	pCollisionStatus = ucCollisionStatus;
	//ucCollisionStatus=0;
}
void vCollisionSensorDetectionHandler(){

	*pCollisionStatus=1;


}
void vCollisionSensorZero(){

	*pCollisionStatus=0;


}
