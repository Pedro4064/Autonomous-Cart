// **********************************************//
// File name:        imu.c                       //
// File description: This file implements       //
//                   the accelerometer and 		 //
//					 gyroscope systems 			 //
// Author name:		 Isabelle Miki Ikuno         //
// Creation date:	 05/Set/2024                 //
// Revision date:    19/Set/2024                 //
// **********************************************//

#include "i2c.h"
#include "imu.h"
#include "stm32g474xx.h"

//Registers Address
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define CONFIG_REG 0x1A
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define GYRO_XOUT_H_REG 0x43

//Parameter of MPU6050
#define MPU6050_ADDR 0x68<<1
#define TIME_OUT 100
#define REG_ADDR_SIZE 1 //byte


ImuReadings* pComputedReadings;
typedef ImuReadings RawReadings;
RawReadings xComputeRawReadings;


//Initialize and configure IMU
void vImuInit(ImuReadings* pImuReadings)
{
    uint8_t uiData=0;


    // PWR_MGMT_1 register: turn off sleep mode
    uiData = 0x00;
    HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, PWR_MGMT_1_REG, REG_ADDR_SIZE, &uiData, 1, TIME_OUT);
    pComputedReadings = pImuReadings;

    //Define sampling frequency = 1kHz. It depends if digital filter is disable.
    //uiData = 0x07; //filter disable
    uiData = 0x00; //filter enable
    HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, SMPLRT_DIV_REG, REG_ADDR_SIZE, &uiData, 1, TIME_OUT);

    //Digital filter DLPF_CFG = 3
    uiData = 0x03;
    HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, CONFIG_REG, REG_ADDR_SIZE, &uiData, 1, TIME_OUT);

    //Gyroscope Configuration - Set full scale range to +-250o/s
    uiData = 0x00;
    HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, GYRO_CONFIG_REG, REG_ADDR_SIZE, &uiData, 1, TIME_OUT);

    //Accelerometer Configuration - Set full scale range to +-2g
    uiData = 0x00;
    HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, ACCEL_CONFIG_REG, REG_ADDR_SIZE, &uiData, 1, TIME_OUT);

}


//Save accelerometer and gyroscope data through pImuReadings
void vImuComputeMeasurements()
{

	uint8_t uiData[6];
	//Read gyroscope raw values
	HAL_I2C_Mem_Read(&hi2c2, MPU6050_ADDR, GYRO_XOUT_H_REG , REG_ADDR_SIZE, uiData, 6, TIME_OUT);

		xComputeRawReadings.fGyroX = (float)((int16_t)(uiData[0]<<8 | uiData[1]));
		xComputeRawReadings.fGyroY = (float)((int16_t)(uiData[2]<<8 | uiData[3]));
		xComputeRawReadings.fGyroZ = (float)((int16_t)(uiData[4]<<8 | uiData[5]));

	//Read accelerometer raw values
    HAL_I2C_Mem_Read(&hi2c2, MPU6050_ADDR, ACCEL_XOUT_H_REG , REG_ADDR_SIZE, uiData, 6, TIME_OUT);

    	xComputeRawReadings.fAccelX = (float)((int16_t)(uiData[0]<<8 | uiData[1]));
    	xComputeRawReadings.fAccelY = (float)((int16_t)(uiData[2]<<8 | uiData[3]));
    	xComputeRawReadings.fAccelZ = (float)((int16_t)(uiData[4]<<8 | uiData[5]));

    //Convert gyroscope values to °/s unit
    //Since the full scale range of the gyroscope is set to ±250°/s, the LSB sensitivity is 131 LSB/°/s.
    //Therefore, it is necessary to divide by 131 to obtain the velocity in °/s.
    pComputedReadings->fGyroX = (xComputeRawReadings.fGyroX/131.0)+1.6;
    pComputedReadings->fGyroY = (xComputeRawReadings.fGyroY/131.0)-0.9;
    pComputedReadings->fGyroZ = (xComputeRawReadings.fGyroZ/131.0)-0.1;


    //Convert accelerometer values to g unit
    //Since the full scale range of the accelerometer is set to ±2g, the LSB sensitivity is 16384 LSB/g.
    //Therefore, it is necessary to divide by 16384 to obtain the acceleration in g.
    pComputedReadings->fAccelX = (xComputeRawReadings.fAccelX/16384.0)-0.02;
    pComputedReadings->fAccelY = (xComputeRawReadings.fAccelY/16384.0)+0.02;
    pComputedReadings->fAccelZ = (xComputeRawReadings.fAccelZ/12850.0);

}
