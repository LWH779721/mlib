cmake_minimum_required(VERSION 2.8) 

PROJECT(mlibc_test)

INCLUDE_DIRECTORIES(../include) 

#AUX_SOURCE_DIRECTORY(. MLIBC_TEST)
ADD_EXECUTABLE(example test.c)  
TARGET_LINK_LIBRARIES(example mlibc)

ADD_EXECUTABLE(mlist_test mlist_test.c)  
TARGET_LINK_LIBRARIES(mlist_test mlibc)