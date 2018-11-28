#ifndef __MSTDIO_H__
#define __MSTDIO_H__

#ifdef __cplusplus
extern "C"{
#endif

#define println(format, arg...) printf(format"\n", ##arg)

#ifdef __cplusplus
}
#endif
#endif
