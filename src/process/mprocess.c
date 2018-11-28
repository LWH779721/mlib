#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include "mprocess.h"

int proc_list()
{
    DIR *proc;
    struct dirent *ptr;
    uint32_t pid = 0;
    char cmd[200];
    
    proc = opendir("/proc/");
    while((ptr = readdir(proc)))
    {
        pid = atoi(ptr->d_name);
        if (pid != 0)
        {
            cmd[0] = 0;
            get_process_cmdline(pid, cmd);
            printf("pid: %d, cmdline: %s\n", pid, cmd);
        }
    }
    
    return 0;
}
