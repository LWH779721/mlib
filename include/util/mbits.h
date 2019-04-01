/*
* 不定位数值操作
* 操作单元：不定位
*/
#ifndef __MBITS_H__
#define __MBITS_H__

#ifdef _cplusplus
extern "C" {
#endif

/*
*  pos or start begin with 0
*/
#define mbits_count_bytes_need(bit_counts) ((bit_counts + 7) >> 3)
#define mbits_count_byte_index(bit_pos) (bit_pos >> 3)	
#define mbits_count_bit_index_in_byte(bit_pos) (bit_pos & 0x7)	
#define mbits_get_bit(bit_arry, bit_pos) !!(bit_arry[mbits_count_byte_index(bit_pos)] & (1 << mbits_count_bit_index_in_byte(bit_pos)))
#define mbits_set_bit_1(bit_arry, bit_pos) (bit_arry[mbits_count_byte_index(bit_pos)] |= (1 << mbits_count_bit_index_in_byte(bit_pos)))
#define mbits_set_bit_0(bit_arry, bit_pos) (bit_arry[mbits_count_byte_index(bit_pos)] &= ~(1 << mbits_count_bit_index_in_byte(bit_pos)))

typedef struct 
{
	int counts;
	int unit_bits;
    unsigned char buf[];
} mbits_arry;

extern mbits_arry *mbits_init(int unit_bits, int unit_counts);
extern int mbits_get(mbits_arry *arry, int index);
extern int mbits_set(mbits_arry *arry, int index, int data);
extern void mbits_dump(mbits_arry *arry, int start_index, int counts);

#ifdef _cplusplus
}
#endif
#endif