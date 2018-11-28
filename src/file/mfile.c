#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include "mmath.h"

int mfile_touch(char *fname)
{
    int fd;
    
    if (NULL == fname)
    {
        printf("tag name is null"); 
        return -1;
    }
    
    if (access(fname, F_OK) == F_OK)
    {
        return 0;        
    }
    
    if ((fd = open(fname, O_CREAT | O_TRUNC | O_WRONLY, S_IREAD)) <= 0)
    {
        printf("create file tag failed"); 
        return -1;    
    }
    
    close(fd);
    if (access(fname, F_OK) != F_OK)
    {
        return -1;        
    }
    
    return 0;
}

int mfile_rm(char *fname)
{
    if (NULL == fname)
    {
        printf("tag name is null"); 
        return -1;
    }
    
    if (access(fname, F_OK) != F_OK)
    {
        return 0;        
    } 
    
    return unlink(fname); 
}

int mkblocks_file(char *fname, uint32_t size)
{
	FILE *fp = NULL;
	char a = 1;
	
	if (NULL == (fp = fopen(fname, "wb+")))
	{
		printf("failed when open file\n");
		return -1;
	}
	
    size = mmath_extend_to_blocks(size);
	fseek(fp, size - 1, SEEK_SET);
	fwrite(&a, 1, 1, fp);
	
	fclose(fp);
	return 0;
}