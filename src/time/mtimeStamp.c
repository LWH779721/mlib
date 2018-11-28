#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

uint64_t mts_get_real_uts()
{
    uint64_t timestamp;
    struct timeval current;
    
    gettimeofday(&current, NULL);
    timestamp = (uint64_t)current.tv_sec * 1000 * 1000 + (uint64_t)current.tv_usec;
   
    return timestamp;
}

uint64_t mts_get_real_mts()
{
    uint64_t timestamp;
    struct timeval current;
    
    gettimeofday(&current, NULL);
    timestamp = (uint64_t)current.tv_sec * 1000 + (uint64_t)current.tv_usec / 1000;
   
    return timestamp;
}
