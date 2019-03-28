#ifndef __MFILE_H__
#define __MFILE_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include "mmath.h"

#define enlarge_file_size_to_blocks(size)  mmath_extend_to_blocks(size) 

static inline int touch_file(const char *fname)
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
	return 0;
}

static inline int rm_file(const char *fname)
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

extern int touch_fixed_size_file(const char *fname, uint32_t size);

extern int file_save_less_bytes(const char *fname, void *buffer, int size);
extern int file_load_less_bytes(const char *fname, const char *buffer, int size);

extern int get_file_size(char *path);

#ifdef __cplusplus
}
#endif
#endif