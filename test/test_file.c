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
    
	touch_file("b.txt");
	touch_file("c.txt");
	file_save_less_bytes("a.txt", "MTK8516-6789", strlen("MTK8516-6789"));  
	rm_file("b.txt");
	
	touch_fixed_size_file("d.txt", 1000);
	touch_fixed_size_file("e.txt", enlarge_file_size_to_blocks(1000));
	
    return 0;
}