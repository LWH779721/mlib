#ifndef __MTIMESTAMP_H__
#define __MTIMESTAMP_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

/*
 * get real time stamp 
 */
extern uint64_t realtime_ts();

/*
 * get real gm time stamp 
 */
extern uint64_t realtime_gmts(); 

/* get monotonic time stamp
 * unit：millisecond 
 */
extern uint64_t monotonic_ts();

#ifdef __cplusplus
}
#endif
#endif
