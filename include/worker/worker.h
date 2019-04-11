#ifndef __WORKER_H__
#define __WORKER_H__

#if defined(__cplusplus) 
extern "C" {
#endif

#include <pthread.h> 
#include <semaphore.h>

typedef void (*work_action)(void *);

typedef struct __work{
    void *param;
    work_action action;
    struct __work *next;
} work;

typedef struct {
    work *first;
    work *last;
} work_queue;

typedef struct {
    sem_t sem;
    work_queue queue; 
    pthread_t pid;
} worker; 

#if defined(__cplusplus) 
}
#endif
#endif