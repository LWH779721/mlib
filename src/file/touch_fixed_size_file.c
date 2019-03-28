#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

int touch_fixed_size_file(const char *fname, uint32_t size)
{
	FILE *fp = NULL;
	char a = 1;
	
	if (NULL == (fp = fopen(fname, "wb+")))
	{
		printf("failed when open file\n");
		return -1;
	}
	
	fseek(fp, size - 1, SEEK_SET);
	fwrite(&a, 1, 1, fp);
	
	fclose(fp);
	return 0;
}