#ifndef __MFILE_H__
#define __MFILE_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

extern int mfile_touch(char *fname);
extern int mfile_rm(char *fname);
extern int mkblocks_file(char *fname, uint32_t size); //生成 固定大小的文件

extern int file_save_less_bytes(const char *fname, void *buffer, int size);
extern int file_load_less_bytes(const char *fname, const char *buffer, int size);

extern int get_file_size(char *path);

#ifdef __cplusplus
}
#endif
#endif