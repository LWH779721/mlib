#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "util/mbit.h"
#include "util/mbits.h"

void mbits_dump(mbits_arry *arry, int start_index, int counts)
{
	assert(arry != NULL);
	assert(counts > 0);
	assert(start_index >= 0);
	assert((start_index + counts) <= arry->counts);

	while(counts--)
	{
		printf("%d ", mbits_get(arry, start_index));
		start_index++;	
	}

	printf("\n");
}

int mbits_set(mbits_arry *arry, int index, int data)
{
	int i, bits_start;

	bits_start = index * arry->unit_bits;
	for (i = 0; i < arry->unit_bits; ++i)
	{
		if (mbit_get(data, i))
		{
			mbits_set_bit_1(arry->buf, bits_start);		
		}
		else
		{
			mbits_set_bit_0(arry->buf, bits_start);
		}

		bits_start++;
	}

	return 0;
}

int mbits_get(mbits_arry *arry, int index)
{
	assert(index < arry->counts);

	int data = 0, i, bits_start;

	bits_start = index * arry->unit_bits;
	for (i = 0; i < arry->unit_bits; ++i)
	{
		if (mbits_get_bit(arry->buf, bits_start))
		{
			mbit_set_1(data, i);
		}
		else
		{
			mbit_set_0(data, i);
		}

		bits_start++;
	}

	return data;
}

mbits_arry *mbits_init(int unit_bits, int unit_counts)
{
	assert(unit_bits > 0);
	assert(unit_bits < 32);
	assert(unit_counts > 0);

	int byte_counts;
	mbits_arry *arry;

	byte_counts = mbits_count_bytes_need(unit_bits * unit_counts);
	if (NULL == (arry = malloc(sizeof *arry + byte_counts)))
	{
		printf("failed when malloc\n");
		return NULL;	
	}
    
	arry->counts = unit_counts;
	arry->unit_bits = unit_bits;
	memset(arry->buf, 0, byte_counts);

	return arry;
}