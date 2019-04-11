#include <stdio.h>

#include "struct/double_linked_list.h"

struct list {
    struct {
       struct list *prev;
       struct list *next;
    } node;

    int i;
};

struct head {
    struct list *list;
    unsigned long counts;
} head;

int main()
{
    struct list a = {.i = 1};
    struct list b = {.i = 2};
    struct list *p;

    printf("counts : %lu\n",head.counts);
    mlist_add(head, &a, node);
    printf("counts : %lu\n",head.counts);
    mlist_add(head, &b, node);
    printf("counts : %lu\n",head.counts);
    
    p = head.list; 
    while (p)
    {
        printf("item.i : %d\n", p->i);
        p = p->node.next;
        if (p == head.list) break;
    }
    
    printf("------------------------------\n");
    mlist_del(head, &b, node);
    printf("counts : %lu\n",head.counts);
    
    p = head.list; 
    while (p)
    {
        printf("item.i : %d\n", p->i);
        p = p->node.next;
        if (p == head.list) break;
    }
    
    mlist_del(head, &a, node);
    printf("counts : %lu\n",head.counts);
    
    p = head.list; 
    while (p)
    {
        printf("item.i : %d\n", p->i);
        p = p->node.next;
        if (p == head.list) break;
    }
    
    return 0;
}
