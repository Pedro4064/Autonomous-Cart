#include <stdio.h>
#include "main.h"

#ifndef __PROFILER_H__
#define __PROFILER_H__

#define PROFILING_ON 1

static inline void vProfilerInit();
static inline void vProfilerUpdateMicroseconds();

// Store the previous counter value and a cumulative microseconds value for overflow detection
static uint32_t prevDWT = 0;
static uint64_t totalMicroseconds = 0;

// Macro to retrieve the total microseconds since initialization
#define GET_MICROSECONDS() (vProfilerUpdateMicroseconds(), totalMicroseconds)

#if PROFILING_ON
    #define START_PROFILE_SECTION() do{vProfilerUpdateMicroseconds();printf("[%llu us] STARTED:%s\r\n", totalMicroseconds, __func__);} while (0)
    #define END_PROFILE_SECTION() do{printf("[%llu us] ENDED:%s\r\n", GET_MICROSECONDS(), __func__);} while (0)
    int _write(int file, char *ptr, int len);

#else
    #define START_PROFILE_SECTION() 
    #define END_PROFILE_SECTION() 
#endif

inline void vProfilerStartSection(){

}
static inline void vProfilerUpdateMicroseconds(){
        uint32_t currentDWT = DWT->CYCCNT; 
        if (currentDWT < prevDWT) { 
            /* Overflow occurred */ 
            totalMicroseconds += (0xFFFFFFFF - prevDWT + currentDWT + 1) / (HAL_RCC_GetHCLKFreq() / 1000000);
        } 
        else {
            totalMicroseconds += (currentDWT - prevDWT) / (HAL_RCC_GetHCLKFreq() / 1000000); 
        }

        prevDWT = currentDWT;

}

static inline void vProfilerInit(){
        if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)) {
            CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
            DWT->CYCCNT = 0;
            DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
        }
}

#endif