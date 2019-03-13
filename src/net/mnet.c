#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h> 

extern int errno;

int mnet_send(int fd, unsigned char *buf, unsigned int len)
{
    int ret;
    unsigned char *sendptr;

    sendptr = buf;
    while (len > 0)
    {
        ret = send(fd, sendptr, len , 0);
        if (ret < 0)
        {
            if (errno == EAGAIN)
            {
                continue;
            }
            else if (errno == EPIPE)
            {
                return -1;
            }
        }
        
        len -= ret;
        sendptr += ret;
    }

    return 0;
}

int mnet_recv(int fd, unsigned char *buf, unsigned int len)
{
    int ret;
    unsigned char *readptr;

    readptr = buf;
    while (len > 0)
    {
        ret = recv(fd, readptr, len , 0);
        if (ret < 0)
        {
            if (errno == EAGAIN)
            {
                continue;
            }
            else if (errno == EPIPE)
            {
                return -1;
            }
        }
        else if (ret == 0)
        {
            return -1;
        }
        
        len -= ret;
        readptr += ret;
    }

    return 0;
}

