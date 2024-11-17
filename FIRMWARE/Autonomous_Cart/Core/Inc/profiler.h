#include <stdio.h>

#ifndef __PROFILER_H__
#define __PROFILER_H__


#define PROFILING_ON 1

#if PROFILING_ON
    extern  char __profiling_status[100];
    #define START_PROFILE_SECTION() snprintf(__profiling_status, sizeof(__profiling_status), "STARTED:%s", __func__)
    #define END_PROFILE_SECTION() snprintf(__profiling_status, sizeof(__profiling_status), "ENDED:%s", __func__)
#else
    #define START_PROFILE_SECTION() 
    #define END_PROFILE_SECTION() 
#endif

#endif