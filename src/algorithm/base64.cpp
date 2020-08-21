#include "base64.h"

namespace mlib {
namespace base64 { 

const char* Encode::m_item = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
Encode::Encode(char *output)
    : m_step{step_A}
    , m_output{output}
    , m_p{output}{
}

char Encode::encode_value(char value){
    if (value > 63) return '=';
          
    return m_item[value];    
}

int Encode::encode_block(char *in, int len){
    char *p = in;
    char *in_end = in + len;
    char fragment;
    
    switch(m_step){
    while(1){
    case step_A:
        if (p == in_end){
            m_step = step_A;
            return m_p - m_output;
        }
        
        fragment = *p++;
        m_result = (fragment & 0xFC) >> 2;
        *m_p++ = encode_value(m_result);
        m_result = (fragment & 0x03) << 4;    
    case step_B:
        if (p == in_end){
            m_step = step_B;
            return m_p - m_output;
        }
        
        fragment = *p++;
        m_result |= (fragment & 0xF0) >> 4;
        *m_p++ = encode_value(m_result);
        m_result = (fragment & 0x0F) << 2; 
    case step_C:
        if (p == in_end){
            m_step = step_C;
            return m_p - m_output;
        }
        
        fragment = *p++;
        m_result |= (fragment & 0xC0) >> 6;
        *m_p++ = encode_value(m_result);
        
        m_result = (fragment & 0x3F); 
        *m_p++ = encode_value(m_result);
    }
    }
    
    return m_p - m_output;
}

int Encode::encode_block_end(){
    switch(m_step){
    case step_A:
        break;
    case step_B:
        *m_p++ = encode_value(m_result);
        *m_p++ = '=';
        *m_p++ = '=';
        break;
    case step_C:
        *m_p++ = encode_value(m_result);
        *m_p++ = '=';
        break;
    }
    
    return m_p - m_output;
}

}
}