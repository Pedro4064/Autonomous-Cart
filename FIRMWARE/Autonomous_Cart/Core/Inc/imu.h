// **********************************************//
// File name:        imu.h      			     //
// File description: This file defines           //
//                   the imu system	(gyroscope   //
//					 accelerometer).			 //
// Author name:		 Isabelle Miki Ikuno         //
// Creation date:	 05/Set/2024                 //
// Revision date:    19/Set/2024                 //
// **********************************************//
#ifndef INC_IMU_H_
#define INC_IMU_H_

	typedef struct{
		float fAccelX;
		float fAccelY;
		float fAccelZ;
		float fGyroX;
		float fGyroY;
		float fGyroZ;
	}ImuReadings;


// ********************************************************** //
// Method name:        vImuInit                               //
// Method description: Initialize  and  configure  IMU.  It   //
//                     defines  sampling frequency, digital   //
//                     filter  and  scale  of  range of the   //
//                     accelerometer and gyroscope            //
// Input params:       pImuReadings                           //
//                        pointer     of    imu    parameters //
//                        (accelerometer and gyroscope axis)  //
// Output params:      void                                   //
//                        N/A                                 //
// ********************************************************** //
	void vImuInit(ImuReadings* pImuReadings);
	
// ********************************************************** //
// Method name:        vImuComputeMeasurements                //
// Method description: Read,  process and calibrate imu raw   //
//                     values.                                //
// Input params:       void                                   //
//                        N/A                                 //
// Output params:      void                                   //
//                        N/A                                 //
// ********************************************************** //
	void vImuComputeMeasurements(void);

#endif /* INC_IMU_H_ */
