#ifndef __KLIST_H__
#define __KLIST_H__

#ifdef __cplusplus
extern "C" {
#endif 

/* =======================
a list util learn from linux kernel
========================= */
#include <stddef.h>

struct klist {
	struct klist *next; 
	struct klist *prev;
};

struct klist_head {
	struct klist list;
	size_t offset;
    unsigned counts;	
};

#define get_offset(type, list) ((size_t)& ((type *)0)->list) 
#define get_ower(ptr, type, head) (type *)((char *)ptr - (head)->offset)


#define klist_init_head(head, type) \
do { \
	(head)->list.next = NULL; \
	(head)->list.prev = NULL; \
	(head)->counts = 0; \
	(head)->offset = get_offset (type, list); \
} while(0)

extern long klist_add(struct klist_head *head, struct klist *prev, struct klist *list) ;

#ifdef __cplusplus
}
#endif
#endif