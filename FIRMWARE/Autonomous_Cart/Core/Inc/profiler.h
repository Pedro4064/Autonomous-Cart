#ifndef __PROFILER_H__
#define __PROFILER_H__

#include <stdint.h>
#include <stdio.h>

/*
    If no time stamp is being displayed, make sure you are using the c standard library rather than the reduced one, since
    the reduced has no support for displaying long long variables:
    https://community.st.com/t5/stm32cubeide-mcus/where-can-i-change-the-runtime-library-in-stm32cubeidev1-00/td-p/327232
*/

// Enable profiling
#define PROFILING_ON 0

#if PROFILING_ON
    #define START_PROFILE_SECTION() startProfileSection(__func__)
    #define END_PROFILE_SECTION() endProfileSection(__func__)
#else
    #define START_PROFILE_SECTION()
    #define END_PROFILE_SECTION()
#endif

// Global variables for microsecond tracking (extern declaration)
extern uint32_t prevDWT;
extern volatile uint64_t totalMicroseconds;
extern char __profiling_status[100];

// Function declarations
void vProfilerInit(void);
uint64_t getMicroseconds(void);
void startProfileSection(const char* functionName);
void endProfileSection(const char* functionName);

#endif
