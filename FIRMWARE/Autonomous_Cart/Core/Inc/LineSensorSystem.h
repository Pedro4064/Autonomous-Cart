/*
 * LineSensorSystemInterface.h
 *
 *  Created on: Sep 4, 2024
 *      Author: njsne
 */

#ifndef LINESENSORSYSTEMINTERFACE_H_
#define LINESENSORSYSTEMINTERFACE_H_

void vLineSensorSystemInit(unsigned long (*pLineSensorsReadings)[5]);
void vLineSensorSystemProcessMeasurements();

#endif /* LINESENSORSYSTEMINTERFACE_H_ */
