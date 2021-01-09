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
 * unit：usecond 
 */
extern uint64_t monotonic_ts();

/*
* 生成http协议中头部的 Date字段，RF1123标准的date 字符串，buf 不为空，长度大于100
*/
extern int getRF1123DateString(char *buf);

#ifdef __cplusplus
}
#endif
#endif
