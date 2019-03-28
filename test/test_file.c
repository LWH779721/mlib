#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "mfile.h"
#include "mdebug.h"

int main(int argc, char **args)
{
    timing({
	printf("%s\n", __FILE__);
    
    struct stat buf;
    stat(args[1], &buf);
    printf("/etc/hosts file size = %ld\n", buf.st_blocks);
    printf("/etc/hosts file size = %ld\n", buf.st_blksize);
	});
    
	file_save_less_bytes("a.txt", "MTK8516-6789", strlen("MTK8516-6789"));  
	
    return 0;
}