#include <stdio.h>
#include "main.h"

#ifndef __PROFILER_H__
#define __PROFILER_H__


#define PROFILING_ON 1

#if PROFILING_ON
    #define START_PROFILE_SECTION() printf("[%lu ms] STARTED:%s\r\n", HAL_GetTick(), __func__)
    #define END_PROFILE_SECTION() printf("[%lu ms] ENDED:%s\r\n", HAL_GetTick(), __func__)
    int _write(int file, char *ptr, int len);

#else
    #define START_PROFILE_SECTION() 
    #define END_PROFILE_SECTION() 
#endif

#endif
