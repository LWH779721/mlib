#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mmath.h"
#include "util/mem_pool.h"

struct mem_pool* mem_pool_init(unsigned int unit_size, unsigned int unit_counts)
{
    struct mem_pool *p = NULL;
    int i;
	
    if (NULL == (p = malloc((sizeof *p) + (sizeof(struct mem_unit) + unit_size) * unit_counts)))
    {
        printf("err when malloc pool\n");
        return NULL;
    }
    
	p->unit_size = unit_size;
	p->unit_counts = enlarge_to_pow2(unit_counts);
	p->cur = 0;
    
    for (i = 0; i < p->unit_counts; i++)
	{
        p->unit[i].used = 0;
        p->unit[i].addr = p->memory + sizeof(struct mem_unit)*p->unit_counts + i * unit_size;
    }

    return p;
}

struct mem_unit* mem_pool_get_unit(struct mem_pool *pool)
{   
	int i = 0;
	struct mem_unit *unit = NULL;
	
	while (i++ < pool->unit_counts)
	{	
		if (pool->unit[pool->cur].used == 0)
		{
			pool->unit[pool->cur].used = 1;
			unit = &pool->unit[pool->cur];
			pool->cur = (pool->cur + 1)&(pool->unit_counts - 1);
			break;
		}
		
		pool->cur = (pool->cur + 1)&(pool->unit_counts - 1);
	}
            
    return unit;
}

long mem_pool_uinit(struct mem_pool *pool)
{
    if (pool)
    {
        free(pool);
    }
    
    return 0;
}

long mem_pool_dump(struct mem_pool *pool)
{
    int i;
    
    printf("unit_size : %d, unit_counts : %d\n", pool->unit_size, pool->unit_counts);
    printf("unit cur : %d\n", pool->cur);
	
    for (i = 0; i < pool->unit_counts; ++i)
    {
		printf("unit[%d] : %d\n", i, pool->unit[i].used);
		printf("unit used size : %d\n", pool->unit[i].data_size);
		printf("unit addr : %p\n", pool->unit[i].addr); 
    }
    
    return 0;
}
