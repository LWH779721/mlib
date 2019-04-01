#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "util/mbits.h"

int main(int argc, char ** args)
{  

	mbits_arry *arry;

	if (NULL == (arry = mbits_init(2 , 10)))
	{
		printf("failed when arry init\n");
	}

	mbits_dump(arry, 0, 10);
	mbits_set(arry, 1, 3);
	mbits_dump(arry, 0, 10);
	printf("%d \n",mbits_get(arry, 1));

	return 0;
}