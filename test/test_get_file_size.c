#include <stdio.h>

#include "mfile.h"

int main(int argc, char **args)
{
	int size = -1;
	
	size = get_file_size(args[1]);
	if (size >= 0)
	{
		printf("file size: %d\n", size);
	}
	
	return 0;
}