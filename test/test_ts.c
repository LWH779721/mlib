#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "time/mtimestamp.h"

int main(int argc, char **args)
{
    uint64_t ts;
    
    ts = monotonic_ts();
    printf("ts: %"PRIu64"\n", ts);
    
    ts = realtime_ts();
    printf("ts: %"PRIu64"\n", ts);
    
    ts = realtime_gmts();
    printf("ts: %"PRIu64"\n", ts);
    
    return 0;
}