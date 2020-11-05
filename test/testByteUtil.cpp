#include <iostream>
#include <gtest/gtest.h>

#include "util/ByteUtil.h"

using namespace mlib;

TEST(ByteUtil, clear){
    byte a = 0x8;
    
    ASSERT_EQ(0x0, ByteUtil::clear(a, 3));
}

TEST(ByteUtil, mark){
    byte a = 0x8;
    
    ASSERT_EQ(0xc, ByteUtil::mark(a, 2));
}

TEST(ByteUtil, get){
    byte a = 0x8;
    
    ASSERT_EQ(0x1, ByteUtil::get(a, 3));
}

TEST(ByteUtil, getBits){
    byte a = 0xC;
    
    ASSERT_EQ(0x3, ByteUtil::get(a, 2, 2));
}

TEST(ByteUtil, set){
    byte a = 0xC;
    
    a = ByteUtil::set(a, 0, 2, 0x3);
    ByteUtil::dump(a);
        
    ASSERT_EQ(0xF, a);
}

TEST(ByteUtil, dump){
    byte a = 0x8;
    
    ByteUtil::dump(a);
}

int main(int argc,char **args){
    testing::InitGoogleTest(&argc, args);
    return RUN_ALL_TESTS();
}
