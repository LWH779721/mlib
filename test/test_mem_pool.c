#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util/mem_pool.h"

int main(int argc, char ** args)
{
    struct mem_pool *pool;
    struct mem_unit *unit;
	
    if (NULL == (pool = mem_pool_init(200*1024, 7)))
    {
        printf("failed when mem pool init");
        return -1;
    }
    
    mem_pool_dump(pool);
	printf("==============================\n");
	unit = mem_pool_get_unit(pool);
	if (NULL != unit)
	{
		memcpy(unit->addr, "test", 4);
		unit->data_size = 4;
	}

    mem_pool_dump(pool);
	printf("==============================\n");
	mem_pool_free_unit(unit);
	mem_pool_dump(pool);
    mem_pool_uinit(pool);

    return 0;
}