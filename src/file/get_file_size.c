#include <stdio.h>
#include <fcntl.h> 

int get_file_size(char *path)
{
	struct stat filestat;
	
	if (access(path, F_OK) != F_OK)
    {
        printf("file not exist: %s\n", path);
        return -1;   
    }
	
	stat(path, &filestat);
    return filestat.st_size;
}