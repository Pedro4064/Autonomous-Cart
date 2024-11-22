#include "profiler.h"
#include "main.h"

// Global variable definitions
volatile uint64_t totalMicroseconds = 0;
uint32_t prevDWT = 0;
char __profiling_status[100];

// Function to initialize the microseconds timer
void vProfilerInit(void) {
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}

// Function to update microseconds with overflow handling
void updateMicroseconds(void) {
    uint32_t currentDWT = DWT->CYCCNT;
    uint32_t clockFreq = HAL_RCC_GetHCLKFreq(); // System core clock frequency

    if (currentDWT < prevDWT) { // Overflow detected
        totalMicroseconds += (0xFFFFFFFF - prevDWT + currentDWT + 1) / (clockFreq / 1000000);
    } else {
        totalMicroseconds += (currentDWT - prevDWT) / (clockFreq / 1000000);
    }
    prevDWT = currentDWT;
}

// Function to get total elapsed time in microseconds
uint64_t getMicroseconds(void) {
    updateMicroseconds();
    return totalMicroseconds;
}

// Function to start profiling a section
void startProfileSection(const char* functionName) {
    updateMicroseconds();
    printf("[%llu us] STARTED: %s\r\n",totalMicroseconds, functionName);
}

// Function to end profiling a section
void endProfileSection(const char* functionName) {
    updateMicroseconds();
    printf("[%llu us] ENDED: %s\r\n",totalMicroseconds, functionName);
}


int _write(int file, char *ptr, int len){
    int DataId;
    for (DataId=0; DataId<len; DataId++){
        ITM_SendChar(*ptr++);
    }
    return len;
}
