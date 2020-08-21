#include <iostream>
#include "stringHelper/stringHelper.h"

//从bsdiff开源库中学习而来
int stringHelper::LongestSimilarSubstring(string &A, string &B){
    int i, equal = 0, lastEqual = 0, length = 0;
    const char *A_s = A.c_str();
    const char *B_s = B.c_str();
    
    for (i = 0; (i < A.length())&&(i< B.length()); ) {
        if(A_s[i] == B_s[i]) equal++;
        i++;
        
        //在已扫描字符串中，相同的字符比例大于50%，并且随着i增长，比例在增大
        if(equal*2-i>lastEqual*2-length) { lastEqual=equal; length=i; }; 
    }
    
    return length;
}

