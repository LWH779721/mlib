#include <stdio.h>

#include "worker/worker.h"

int main(int argc, char **args)
{
    worker *w = NULL;
    char buf[1024];
    
    if (NULL == (w = worker_init()))    
    {
        printf("failed when init worker\n");
        return -1;
    }
    
	while (1)
	{
		fgets(buf, 1023, stdin);
		if (strstr(buf, "do") != NULL)
		{
			sem_post(&(w->sem));
		}
	}	

	return 0;
}