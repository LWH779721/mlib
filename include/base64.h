#ifndef BASE64_H
#define BASE64_H

namespace mlib {
namespace base64 {
 
class Encode{
public:
    Encode(char *output);
    
    int encode_block(char *in, int);
    int encode_block_end();
private:    
    char encode_value(char value);
    
private:
    static const char* m_item;
    
    enum step {
        step_A, 
        step_B, 
        step_C
    };
    
    step m_step;
    char m_result;
    char *m_output, *m_p;
};


}
}

#endif /* BASE64_CENCODE_H */