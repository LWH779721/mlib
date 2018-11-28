#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

uint64_t ts_after_bootup()
{
    uint64_t timestamp;
    struct timespec monoto;
    
    clock_gettime(CLOCK_MONOTONIC, &monoto); 
    timestamp = (uint64_t)monoto.tv_sec * 1000 * 1000 * 1000 + (uint64_t)monoto.tv_nsec; 
    
    return timestamp;
}
