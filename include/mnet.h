#ifndef __MNET_H__
#define __MNET_H__

#ifdef __cplusplus
extern "C"{
#endif

extern int mnet_check_connectble(char *ipaddr, int port, int timeout);
extern int mnet_setnoblock(int fd);

#ifdef __cplusplus
}
#endif
#endif