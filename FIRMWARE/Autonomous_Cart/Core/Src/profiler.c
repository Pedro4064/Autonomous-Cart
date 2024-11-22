#include "profiler.h"
#include "main.h"

char __profiling_status[100];

int _write(int file, char *ptr, int len){
    int DataId;
    for (DataId=0; DataId<len; DataId++){
        ITM_SendChar(*ptr++);
    }
    return len;
}
