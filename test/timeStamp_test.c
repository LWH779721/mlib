#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "time/mtimeStamp.h"

int main(int argc, char **args)
{
    uint64_t ts;
    
    ts = ts_after_bootup();
    printf("ts: %"PRIu64"\n", ts);
    
    return 0;
}