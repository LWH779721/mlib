#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#include "sys/mshm.h"

struct mshm *mshm_init(key_t key)
{
	struct mshm *p;

	if (NULL == (p = malloc(sizeof *p)))
	{
		printf("failed when malloc\n");
		return NULL;
	}

	p->key = key;
	if (-1 == (p->shmid = shmget(p->key, sizeof(struct mshm_data), IPC_CREAT | 0666)))
	{
		printf("shm get err\n");
		goto fail;
	}

	if (NULL == (p->data = (struct mshm_data *)shmat(p->shmid, 0, 0)))
	{
		printf("shm at err\n");
		goto fail;
	}

	return p;
fail:
	if (p->shmid 
	    && shmctl(p->shmid, IPC_RMID, 0) == -1)  
    {  
    	fprintf(stderr, "shmctl(IPC_RMID) failed\n"); 
	}

	free(p);
	return NULL;	
}

int mshm_destory(struct mshm *p, int del)
{
	if (shmdt(p->data) == -1)
	{
		printf("shm dt err\n");
		return -1;
	}

	if (del
		&& shmctl(p->shmid, IPC_RMID, 0) == -1)  
    {  
    	fprintf(stderr, "shmctl(IPC_RMID) failed\n");  
    	return -1;  
	} 

	return 0;	
}

int mshm_write(struct mshm *p, char *buf)
{
	while(p->data->writen)
	{
		sleep(1);
		printf("waiting....\n");
	}

	printf("writen:");
	memcpy(p->data->buf, buf , bufsize);
	p->data->writen = 1;
	return 0;	
}

int mshm_read(struct mshm *p)
{
	while(p->data->writen == 0)
	{
		sleep(1);
	}	

	printf("read:%s\n",p->data->buf);
	p->data->writen = 0;
	return 0;	
}
