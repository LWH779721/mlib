#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#include "mstdio.h"

int file_save_less_bytes(const char *fname, const char *buffer, int size)
{
    int fd = -1;
    
    if ((fd = open(fname, O_CREAT | O_RDWR, 0644)) < 0)
    {
        println("open file %s failed", fname);
        return -1;
    }
    
    write(fd, buffer, size);
    fsync(fd);
    close(fd);
    
    return 0;
}
