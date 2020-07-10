#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

uint64_t monotonic_ts()
{
    struct timespec ts = {0};
    
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (((uint64_t)ts.tv_sec * 1000) + ((uint64_t)ts.tv_nsec /1000/1000)); 
}
