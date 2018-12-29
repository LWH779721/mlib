#ifndef __MLIST_H__
#define __MLIST_H__

#if defined(__cplusplus)
extern "C" {
#endif

/*
head should defined as
struct
{
	unsigned long   counts;
	struct aaa	*list;
}xxx_head;

node should defined as
struct aaa 
{
    struct
    {
	    struct aaa	*next;
	    struct aaa	*prev;
    }xxx_node;
    .........
};
*/

#define mlist_add(head, item, node)\
do \
{\
    if((head).list)\
    {\
        (item)->node.prev = ((item)->node.next = (head).list)->node.prev;\
        (head).list->node.prev = ((item)->node.prev->node.next = (item));\
    }\
    else\
    {\
        (head).list = ((item)->node.prev = ((item)->node.next = (item)));\
    }\
    ++(head).counts;\
}while (0);

#define mlist_del(head, item, node)\
do \
{\
    if ((item) == (head).list)\
    {\
        if ((head).list->node.next == (head).list)\
        {\
            (head).list = NULL;\
        }\
        else\
        {\
            (item)->node.prev->node.next = ((head).list = (item)->node.next);\
            (head).list->node.prev = (item)->node.prev;\
        }\
    }\
    else\
    {\
        (item)->node.prev->node.next = (item)->node.next;\
        (item)->node.next->node.prev = (item)->node.prev;\
    }\
    --(head).counts;\
} while (0);

#if defined(__cplusplus)
}
#endif
#endif
