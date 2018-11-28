#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int get_process_cmdline(uint32_t pid, char *cmdline)
{
    FILE *fp = NULL;
    char buf[200];
    
    sprintf(buf, "/proc/%u/cmdline", pid);
    if (NULL == (fp = fopen(buf, "r")))
    {
        return -1;        
    }
    
    fread(cmdline, sizeof(char), 200, fp);
    fclose(fp);
    return 0;
}