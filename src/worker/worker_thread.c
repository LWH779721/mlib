#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "worker/worker.h"

void worker_thread(void *param)
{
    worker *wk = (worker *)param;
    sem_t *sem = &(wk->sem);
    
    while (1)
    {
        sem_wait(sem);
        
        printf("action do\n");
    }
}

worker *worker_init()
{
    worker *wk;
    int ret = 0; 
           
    if (NULL == (wk = malloc(sizeof *wk)))
    {
        printf("failed when malloc\n");
        return NULL;
    }

    ret = sem_init(&(wk->sem), 0, 0);   
    if (ret)
    {
        perror("failed when sem init\n");
        free(wk);
        return NULL;
    }
    
    wk->queue.first = NULL;
    wk->queue.last = NULL;
    
    ret = pthread_create(&(wk->pid), NULL, (void *)worker_thread, (void *)wk);
	if (ret < 0)
	{
		printf("failed when create thread\n");
		goto failed;
	}
         
    return wk;        
failed:
    sem_destroy(&(wk->sem));
    
    free(wk);
    return NULL;
}

int worker_uninit(worker **wk)
{
    sem_destroy(&((*wk)->sem));
    
    free(*wk);
    *wk = NULL;
    return 0;        
}
