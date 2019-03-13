#include <stdio.h>
#include <fcntl.h> 
#include <string.h>

extern int errno;

/*
* 将 fd 设置为非阻塞
*/
int switch_to_noblock(int fd)
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
