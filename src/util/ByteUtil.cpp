#include <iostream>
#include <stdio.h>

#include "util/ByteUtil.h"

namespace mlib {
    
byte ByteUtil::clear(byte data, int pos, int len){
    byte tmp = createFlag(len);
    
    data &= ~(tmp << pos);
    return data;
}

byte ByteUtil::mark(byte data, int pos, int len){
    byte tmp = createFlag(len);
    
    data |= (tmp << pos);
    return data;
}

byte ByteUtil::set(byte dst, int pos, int len, byte src){
    int i;
    byte tmp;
    
    for (i = 0; i < len; i++){
        tmp = get(src, i);
        if (tmp == 0){
            dst = clear(dst, pos + i);
        } else {
            dst = mark(dst, pos + i);
        }
    }
    
    return dst;
}

byte ByteUtil::get(byte data, int pos, int len){
    byte tmp = createFlag(len);
    
    return tmp&(data >> pos);
}

void ByteUtil::dump(byte data){      
    byte tmp = 0x80;
    byte len = 8;
    
    while (len--){
    	printf("%d ", !!(data & tmp));
        tmp >>= 1; 	
    } 

    printf("\n");
}

byte ByteUtil::createFlag(int len){
    byte tmp = 0, flag = 1;
    int i;
    
    for (i = 0; i < len; i++){
       tmp |= flag; 
       flag <<= 1;
    }
    
    return tmp;
}    

}
