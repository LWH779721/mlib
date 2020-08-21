#include "base64.h"
#include <iostream>

using namespace mlib::base64;
using namespace std;

int main(int argc, char **args){
    char a[200] = {0};
    char data[] = "hello";
    char data1[] = "world";
    
    Encode b(a);
    b.encode_block(data, 5);
    b.encode_block(data1, 5);
    b.encode_block_end();
    
    cout << sizeof data << endl;
    cout << a << endl;
    return 0;
}