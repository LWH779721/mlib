#ifndef __MDEBUG_H__
#define __MDEBUG_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <inttypes.h>
#include <stdint.h>
#include <assert.h>

/*
* usage:
*    DEBUG({
*       printf("test\n");    
*    })
*/
#ifdef _DEBUG_
#define DEBUG(code) code
#else
#define DEBUG(code) 
#endif

/* get time use
 * usage:
 *    timer_start();
 *    .....
 *    timer_stop();
 */
#define timer_start()\
    uint64_t start_time = monotonic_ts();

#define timer_stop()\
do{\
    uint64_t end_time = monotonic_ts();\
    printf("time use: %"PRIu64"\n", end_time - start_time);\
} while(0);

#define timing(code)\
do{\
	uint64_t start, end;\
	start = monotonic_ts();\
	code\
    end = monotonic_ts();\
	printf("time use: %"PRIu64"\n", end - start);\
}while(0);

#define timing_tag()\
do{\
    static uint64_t old_ts = 0;\
    uint64_t new_ts = monotonic_ts();\
    if (old_ts)\
        printf("time use: %"PRIu64"\n", new_ts - old_ts);\
    old_ts = new_ts;\
}while(0);

/* file:ByteDump.c */
#define DUMPSPERLINE    8
extern void hexdump(const unsigned char *buffer, int size);
extern void octdump(const unsigned char *buffer, int size);
extern void bitdump(const unsigned char *buffer, int size);

#ifdef __cplusplus
}
#endif
#endif