#ifndef __MEM_POOL_H__
#define __MEM_POOL_H__

#ifdef __cplusplus
extern "C"{
#endif

/*=======================================
模块设计需要解决的问题：
在做摄像头程序时，视频数据从采集到网络发送出去，中间会经过很多流程，例如，存储，等等，公司的做法是采用视频队列的方式在不同模块传递视频数据，并且采用memcpy视频数据的方式，
产生的问题：视频数据会memcpy很多次，由于视频数据较大，很浪费性能，并且节点销毁free掉这么大内存，容易导致内存碎片。
设计做法：
将视频队列拆分成消息队列和内存池组合，消息队列传递消息，消息数据较小，不需要malloc节点，可以采用memcpy的方式，性能损失较小，内存池存储视频数据，也不需要创建节点
内存池设计：
当前设计为固定大小单元，采用顺序结构的方式
=======================================*/

struct mem_unit
{
	int used;
    unsigned int data_size;
    unsigned char *addr;
};

struct mem_pool
{
	unsigned int unit_size;
	unsigned int unit_counts;
    int cur;
    struct mem_unit unit[0];
    unsigned char memory[0];
}; 

extern struct mem_pool* mem_pool_init(unsigned int unit_size, unsigned int unit_counts);
extern struct mem_unit* mem_pool_get_unit(struct mem_pool *pool);
extern long mem_pool_uinit(struct mem_pool *pool);
extern long mem_pool_dump(struct mem_pool *pool);

static inline int mem_pool_free_unit(struct mem_unit *unit)
{
	unit->used = 0;
	
    return 0;
}

#ifdef __cplusplus
}
#endif
#endif
