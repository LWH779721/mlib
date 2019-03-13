#ifndef __MNET_H__
#define __MNET_H__

#ifdef __cplusplus
extern "C"{
#endif

/*
* 判断是否可连接
*/
extern int check_connectable(char *ipaddr, int port, int timeout);
extern int switch_to_noblock(int fd);
extern int local_socket_server(const char *fname);
extern int local_socket_server_send(int socket_fd, const char *dst_fname, char *buffer, int len);

#ifdef __cplusplus
}
#endif
#endif