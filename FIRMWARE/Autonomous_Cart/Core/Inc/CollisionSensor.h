/*
 * CollisionSensor.h
 *
 *  Created on: Oct 11, 2024
 *      Author: ES670 B
 */

#ifndef COLLISIONSENSOR_H_
#define COLLISIONSENSOR_H_

void vCollisionSensorInit(unsigned char *ucCollisionStatus);
void vCollisionSensorDetectionHandler();
void vCollisionSensorZero();

#endif /* COLLISIONSENSOR_H_ */
