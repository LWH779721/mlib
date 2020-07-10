#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

uint64_t realtime_ts()
{
    struct timeval current = {0};
    
    gettimeofday(&current, NULL);
    return (((uint64_t)current.tv_sec * 1000) + ((uint64_t)current.tv_usec/ 1000));
}

uint64_t realtime_gmts()
{
    struct timeval current = {0};
    struct timezone tz = {0};
    
    gettimeofday(&current, &tz);
    return ((((uint64_t)current.tv_sec + (tz.tz_minuteswest * 60)) * 1000) + ((uint64_t)current.tv_usec / 1000));
}
