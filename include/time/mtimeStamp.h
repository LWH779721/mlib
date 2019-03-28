#ifndef __MTIMESTAMP_H__
#define __MTIMESTAMP_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

extern uint64_t mts_get_real_uts();
extern uint64_t mts_get_real_mts();
extern uint64_t ts_after_bootup();

#define mts_uts_differ(start) (mts_get_real_uts() - start)

#ifdef __cplusplus
}
#endif
#endif
