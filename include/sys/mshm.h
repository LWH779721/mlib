#ifndef __MSHM_H__
#define __MSHM_H__

#define bufsize 16

struct mshm_data 
{
	int writen;
	char buf[bufsize];	
};

struct mshm
{
	int shmid;
	key_t key;
	struct mshm_data *data;		
};

extern struct mshm *mshm_init(key_t key);
extern int mshm_write(struct mshm *p, char *buf);
extern int mshm_read(struct mshm *p);
extern int mshm_destory(struct mshm *p, int del);
#endif 
