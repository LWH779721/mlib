#include <stdio.h>
#include <time.h>

/*
* 生成http协议中头部的 Date字段，RF1123标准的date 字符串，buf 不为空，长度大于100
*/
int getRF1123DateString(char *buf)
{
    time_t now;
	struct tm *tp;
	size_t ret;
	
    time(&now);
    tp = gmtime(&now);
    
    ret = strftime(buf,100,"%a, %d %b %Y %H:%M:%S %Z", tp); 
    printf("%s \n", buf);

    return ret;
}
