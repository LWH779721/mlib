#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h> 

extern int errno;

int mnet_setnoblock(int fd)
{
    int opts;
    
    opts = fcntl(fd, F_GETFL);
    if (opts < 0) {
        perror("fcntl(F_GETFL)");
        return -1;
    }
    
    opts = (opts | O_NONBLOCK);
    if (fcntl(fd, F_SETFL, opts) < 0) {
        perror("fcntl(F_SETFL)");
        return -1;
    } 
    
    return 0;       
}

int mnet_check_connectble(char *ipaddr, int port, int timeout)
{
    struct sockaddr_in remote = {0};
    struct timeval timeo = {3, 0};
    socklen_t len;
    int client, ret = -1;
    
    if (0 > (client = socket(AF_INET, SOCK_STREAM, 0)))
	{
		printf("create socker err\n");
		return -1;
	} 
	
	if (timeout)
	{
	    timeo.tv_sec = timeout;    
	}
	
	setsockopt(client, SOL_SOCKET, SO_SNDTIMEO, &timeo, sizeof timeo);     

	remote.sin_family = AF_INET;
	remote.sin_port = htons(port);
    remote.sin_addr.s_addr = inet_addr(ipaddr);
	len = sizeof(remote);

	if (0 > connect(client,(struct sockaddr *)&remote, len))
	{	
	    perror("connect err");
		goto fail_label;
	}
	
	ret = 0;
fail_label:
    close(client);	
	return ret;
}

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

