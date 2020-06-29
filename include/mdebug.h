#ifndef __MDEBUG_H__
#define __MDEBUG_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <inttypes.h>
#include <stdint.h>
/*
* ex. DEBUG({
*           printf("test\n");    
*       })
*/
#ifdef _DEBUG_
#define DEBUG(code) code
#else
#define DEBUG(code) 
#endif

#define timing(code)\
do{\
	uint64_t start, end;\
	start = mts_get_real_uts();\
	code\
    end = mts_get_real_uts();\
	printf("time use: %"PRIu64"\n", end - start);\
}while(0);

#define timing_tag()\
do{\
    static uint64_t old_ts = 0;\
    uint64_t new_ts = mts_get_real_uts();\
    if (old_ts)\
        printf("time use: %"PRIu64"\n", new_ts - old_ts);\
    old_ts = new_ts;\
}while(0);

/* from file ByteDump.c */

#define DUMPSPERLINE    8
extern void hexdump(const unsigned char *buffer, int size);
extern void octdump(const unsigned char *buffer, int size);
extern void bitdump(const unsigned char *buffer, int size);

#ifdef __cplusplus
}
#endif
#endif