#include <stdio.h>
#include <stdlib.h>

#include "struct/AVLTree.h"

int main(int argc, char **args)
{
    AVL *root = NULL, *item;
    unsigned int id[] = {11, 23, 434, 54, 65, 44, 55, 63, 22, 43, 90, 2, 33, 110};
    int i;
    
    for (i = 0; i < sizeof(id)/sizeof(int); i++)
    {
        item = find_or_insert(&root, id[i]);
        printf("%p\n", item);
    }
    
	printf("----------------\n");
	item = find(root, 90);
	if (item)
	{
		printf("%p\n", item);
	}
	
    printf("----------------\n");
    midOrderTraversal(root);
	
	printf("----------------\n");
	item = delete(&root, 65);
	if (item)
	{
		printf("%p\n", item);
	}
	midOrderTraversal(root);
	
    return 0;
}
