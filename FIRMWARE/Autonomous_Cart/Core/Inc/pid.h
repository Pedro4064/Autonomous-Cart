/* ***************************************************************** */
/* File name:        pid.h                                           */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the PID                 */
/* Author name:      julioalvesMS, IagoAF, rBacurau                  */
/* Creation date:    21jun2018                                       */
/* Revision date:    20mai2024                                       */
/* ***************************************************************** */

#ifndef SOURCES_CONTROLLER_PID_H_
#define SOURCES_CONTROLLER_PID_H_

#define UPDATE_RATE_MS      100
#define UPDATE_RATE         (UPDATE_RATE_MS / 1000.0)
#define INTEGRATOR_MAX_SIZE 100

typedef struct pid_data_type {
    float fKp, fKi, fKd;            // PID gains
    float fError_previous;          // Used in the derivative
    float fError_sum;               // Integrator cumulative error
    unsigned short usIntegratorSize; // Integrator window size
    float fOutputSaturation;        // Output saturation
} pid_data_type;

/* ************************************************ */
/* Method name:        vPidInit                     */
/* Method description: Initialize the PID controller*/
/* Input params:       pPid: pointer to pid_data_type
                       fKp, fKi, fKd: PID gains
                       usIntSizeMs: Integrator window size in ms
                       fOutputSaturation: Saturation value for output */
/* Output params:      n/a                          */
/* ************************************************ */
void vPidInit(pid_data_type *pPid, float fKp, float fKi, float fKd, unsigned short usIntSizeMs, float fOutputSaturation);

/* ************************************************** */
/* Method name:        vPidSetIntegratorWindow        */
/* Method description: Set a new value for the        */
/*                     integrator window (in ms)      */
/* Input params:       pPid: pointer to pid_data_type
                       usIntSizeMs: New value (in ms) */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetIntegratorWindow(pid_data_type *pPid, unsigned short usIntSizeMs);

/* ************************************************** */
/* Method name:        usPidGetIntegratorWindow       */
/* Method description: Get the value from the         */
/*                     integrator window (in ms)      */
/* Input params:       pPid: pointer to pid_data_type */
/* Output params:      unsigned short: Value (in ms)  */
/* ************************************************** */
unsigned short usPidGetIntegratorWindow(const pid_data_type *pPid);

/* ************************************************** */
/* Method name:        fPidUpdateData                 */
/* Method description: Update the control output      */
/*                     using the reference and sensor */
/*                     value                          */
/* Input params:       pPid: pointer to pid_data_type
                       fSensorValue: Value read from the sensor
                       fSetValue: Reference value   */
/* Output params:      float: New control effort      */
/* ************************************************** */
float fPidUpdateData(pid_data_type *pPid, float fSensorValue, float fSetValue);

#endif /* SOURCES_CONTROLLER_PID_H_ */
