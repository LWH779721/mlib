/*
*  Byte operate util
*  bit pos start with 0
*/
#ifndef __BYTEUTIL_H__
#define __BYTEUTIL_H__

typedef unsigned char byte;

namespace mlib {

class ByteUtil{
public:
    //set pos bit to 0
    static byte clear(byte data, int pos){
        data &= ~(1 << pos);
        return data;
    }
    
    static byte clear(byte data, int pos, int len);
    
    //set pos bit to 1
    static byte mark(byte data, int pos){
        data |= (1 << pos);
        return data;
    }
    
    static byte mark(byte data, int pos, int len);
    
    //将字节dst位置pos长度len的值设置为字节src的0位长度为len的值，例如：将dst从第2位开始长度2的值设置成3
    static byte set(byte dst, int pos, int len, byte src);
    
    //get pos bit value
    static byte get(byte data, int pos){
        return !!(data & (1 << pos));
    } 
    
    static byte get(byte data, int pos, int len);
    
    static void dump(byte data);
    
private:
    //创建一个从0位开始长度为len的位值为1的flag，例如：0111, 011111,以上都为2进制。
    static byte createFlag(int len);    
};
};

#endif