/*
* bit operate util
*
* author:lwh
*
*/
#ifndef __MBIT_H__
#define __MBIT_H__

#ifdef _Cplusplus
extern "C" {
#endif

/*
*  pos or start begin with 0
*/
#define mbit_set_1(num, pos) ((num) |= (1 << pos))
#define mbit_set_0(num, pos) ((num) &= (~(1 << pos)))
#define mbit_get(num, pos) !!((num) & (1 << pos))

extern void mbit_dump(long num, int start, int len);

#ifdef _Cplusplus
}
#endif

#endif