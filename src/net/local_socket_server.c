#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <errno.h>

extern int errno;

int local_socket_server(const char *fname)
{
    struct sockaddr_un server_addr = {0};
    int sd = 0, res = -1;
    
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, fname);
    unlink(fname);

    sd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (-1 == sd)
    {
        perror(strerror(errno));
        return -1;
    }

    res = bind(sd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_un));
    if (res)
    {
        perror(strerror(errno));
        close(sd);
        return -1;
    } 

    return sd;    
}

int local_socket_server_send(int socket_fd, const char *dst_fname, char *buffer, int len)
{
    struct sockaddr_un server_addr = {0};
    int ret;
    
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, dst_fname);
    
	ret = sendto(socket_fd,
                  buffer,
                  len,
                  0,
                  (struct sockaddr *)&server_addr,
                  sizeof(struct sockaddr_un));
	if (ret < 0) {
        printf("send fail!\n");
        return -1;
    }
    
    return 0;    
}
