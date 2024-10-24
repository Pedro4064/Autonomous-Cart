/* ***************************************************************** */
/* File name:        pid.c                                           */
/* File description: This file has a couple of useful functions to   */
/*                   control the implemented PID controller          */
/* Author name:      julioalvesMS, IagoAF, rBacurau                  */
/* Creation date:    21jun2018                                       */
/* Revision date:    20mai2024                                       */
/* ***************************************************************** */

#include "pid.h"

/* ************************************************ */
/* Method name:        vPidInit                     */
/* Method description: Initialize the PID controller*/
/* Input params:       pPid: pointer to pid_data_type
                       fKp, fKi, fKd: PID gains
                       usIntSizeMs: Integrator window size in ms
                       fOutputSaturation: Saturation value for output */
/* Output params:      n/a                          */
/* ************************************************ */
void vPidInit(pid_data_type *pPid, float fKp, float fKi, float fKd, unsigned short usIntSizeMs, float fOutputSaturation) {
    pPid->fKp = fKp;
    pPid->fKi = fKi;
    pPid->fKd = fKd;
    pPid->fError_previous = 0;
    pPid->fError_sum = 0.0;
    pPid->usIntegratorCount = 0;

    // Saturates Integrator size (up to 10 s)
    if ((usIntSizeMs / UPDATE_RATE_MS) > INTEGRATOR_MAX_SIZE)
        usIntSizeMs = INTEGRATOR_MAX_SIZE * UPDATE_RATE_MS;

    pPid->usIntegratorSize = usIntSizeMs / UPDATE_RATE_MS;
    pPid->fOutputSaturation = fOutputSaturation;
}

/* ************************************************** */
/* Method name:        vPidSetIntegratorWindow        */
/* Method description: Set a new value for the        */
/*                     integrator window (in ms)      */
/* Input params:       pPid: pointer to pid_data_type
                       usIntSizeMs: New value (in ms) */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetIntegratorWindow(pid_data_type *pPid, unsigned short usIntSizeMs) {
    // Saturates Integrator size (up to 10 s)
    if ((usIntSizeMs / UPDATE_RATE_MS) > INTEGRATOR_MAX_SIZE)
        usIntSizeMs = INTEGRATOR_MAX_SIZE * UPDATE_RATE_MS;

    pPid->usIntegratorSize = usIntSizeMs / UPDATE_RATE_MS;
}

/* ************************************************** */
/* Method name:        usPidGetIntegratorWindow       */
/* Method description: Get the value from the         */
/*                     integrator window (in ms)      */
/* Input params:       pPid: pointer to pid_data_type */
/* Output params:      unsigned short: Value (in ms)  */
/* ************************************************** */
unsigned short usPidGetIntegratorWindow(const pid_data_type *pPid) {
    return (pPid->usIntegratorSize * UPDATE_RATE_MS);
}

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
float fPidUpdateData(pid_data_type *pPid, float fSensorValue, float fSetValue) {
    float fError, fDifference, fOut;

    // Proportional error
    fError = fSetValue - fSensorValue;

    // Integral error
    pPid->fError_sum = pPid->fError_sum - pPid->fIntegratorBuffer[pPid->usIntegratorCount] + fError;
    pPid->fIntegratorBuffer[pPid->usIntegratorCount] = fError;

    if (++pPid->usIntegratorCount >= pPid->usIntegratorSize)
        pPid->usIntegratorCount = 0;

    // Derivative error
    fDifference = (fError - pPid->fError_previous);

    // PID output
    fOut = pPid->fKp * fError
         + pPid->fKi * pPid->fError_sum * UPDATE_RATE
         + pPid->fKd * fDifference / UPDATE_RATE;

    pPid->fError_previous = fError;

    // Output Saturation
    if (fOut > pPid->fOutputSaturation)
        fOut = pPid->fOutputSaturation;
    else if (fOut < 0)
        fOut = 0;

    return fOut;
}
