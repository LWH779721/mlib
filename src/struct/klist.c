#include <stdio.h>

#include "struct/klist.h"

struct test {
	int a;
	struct klist list;
};

long klist_add(struct klist_head *head, struct klist *prev, struct klist *list) 
{
	if (prev) 
	{ 
		list->next = prev->next; 
		list->prev = prev; 
		prev->next->prev = list; 
		prev->next = list; 
		head->counts++; 
	} 
	else 
	{ 
		list->next = head->list.next; 
		list->prev = &(head->list); 
		head->list.next->prev = list; 
		head->list.next = list; 
		head->counts++; 
	} 

	return head->counts;
}
#if 0
int main()
{
	struct klist_head head;
	struct klist *p;
	struct test s = {
		.a = 1,
	}, *q;
	int i;

	klist_init_head(&head, struct test);
    klist_add(&head, NULL, &(s.list));
    /*p = head.list.next;
    for (i = 0; i < head.counts; i++)
    {
    	q = get_ower(p, struct test, &head);
    	printf("q->a : %d",q->a);
    	p = p->next;
    } */

	printf("counts : %d, offset : %d \n", head.counts, head.offset);
}
#endif