#include <stdio.h>

int percent_progress(int delay)
{
	int i;
    
    if (delay == 0)
        delay = 200*1000;          
    
	for (i = 0; i < 100; ++i)
	{
		printf("% 3d",i);
		usleep(delay);
		printf("\b\b\b");
		fflush(stdout);
	}

	return 0;
}
