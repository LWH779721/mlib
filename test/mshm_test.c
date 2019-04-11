#include <stdio.h>
#include <stdlib.h>

#include "sys/mshm.h"

int main(int argc, char ** args)
{
	struct mshm *p;
	int running = 1;

	if (NULL == (p = mshm_init(1234)))
	{
		printf("err when mshm init\n");
		return -1;
	}
    
    if (argc <= 1)
    {
        printf("err when param invail\n");
        mshm_destory(p, 0);	
		return -1;    
    }
        
	if (strcmp(args[1], "write") == 0)
	{
		char buf[bufsize];

		while (running)
		{              	
			printf("writen:");
			scanf("%s",buf);
		
			if (strcmp(buf, "end") == 0)
			{
				printf("end\n");
				running = 0;
			}

			mshm_write(p, buf);
		}

		mshm_destory(p, 1);
	}
	else if (strcmp(args[1], "read") == 0)
	{
		while (running)
		{
			mshm_read(p);
		
			if (strcmp(p->data->buf, "end") == 0)
			{
				printf("end\n");
				running = 0;
			}
		}

		mshm_destory(p, 0);		
	}

	return 0;
}
