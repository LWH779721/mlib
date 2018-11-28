#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#include "mstdio.h"

int file_load_less_bytes(const char *fname, const char *buffer, int size)
{
    int fd = -1;
    
    if ((fd = open(fname, O_RDONLY)) < 0)
    {
        println("open file %s failed", fname);
        return -1;
    }
    
    read(fd, buffer, size);
    close(fd);
    
    return 0;
}
