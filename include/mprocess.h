#ifndef __MPROCESS_H__
#define __MPROCESS_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

extern int get_process_cmdline(uint32_t pid, char *cmdline);
extern int get_pid_by_name(const char *pname);

#ifdef __cplusplus
}
#endif
#endif
