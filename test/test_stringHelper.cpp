#include <iostream>
#include "stringHelper/stringHelper.h"

int main(int argc,char **args){
    string a("abvcdrefkghijklsassasas");
    string b("abhcdgefmghijklsaswewascsc");
    
    int c = stringHelper::LongestSimilarSubstring(a, b);
    cout << c << endl;
    
    return 0;
}
