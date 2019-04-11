#include <stdio.h>
#include <sys/sem.h>
#include <pthread.h>
#include <string.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *arry;
};

static int sem_id;

void action(void *p)
{
	struct sembuf sem_b = {
		.sem_num = 0,
		.sem_op = -1,
		.sem_flg = SEM_UNDO,
	};
	
	while (1)
	{
		if (semop(sem_id, &sem_b, 1) == -1)
		{
			printf("p err\n");
			continue;
		}
		
		printf("action do\n");
	}
}
#if 0
int main(int argc, char **args)
{
	int ret = -1;
	union semun s; 

	sem_id = semget((key_t)1234, 1, 0666|IPC_CREAT);
	if (sem_id < 0)
	{
		printf("sem_get failed \n");
		return -1;
	}
	
	s.val = 0;
	ret = semctl(sem_id, 0, SETVAL, s);
	if (ret == -1)
	{
		printf("faile when init\n");
		return -1;
	}
	
	pthread_t p;
	ret = pthread_create(&p, NULL, (void *)action, NULL);
	if (ret < 0)
	{
		printf("failed when create thread\n");
		return -1;
	}
	
	char buf[1024];
	struct sembuf sem_b = {
		.sem_num = 0,
		.sem_op = 8,
		.sem_flg = SEM_UNDO,
	};
	while (1)
	{
		fgets(buf, 1023, stdin);
		if (strstr(buf, "do") != NULL)
		{
			if (semop(sem_id, &sem_b, 1) == -1)
			{
				printf("failed when v \n");
				continue;
			}
		}
	}	

	return 0;
}
#endif
