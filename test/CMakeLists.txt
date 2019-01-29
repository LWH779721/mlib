cmake_minimum_required(VERSION 2.8) 

PROJECT(mlibc_test)

INCLUDE_DIRECTORIES(../include) 

#AUX_SOURCE_DIRECTORY(. MLIBC_TEST)
ADD_EXECUTABLE(example test.c)  
TARGET_LINK_LIBRARIES(example mlibc)

ADD_EXECUTABLE(mlist_test mlist_test.c)  
TARGET_LINK_LIBRARIES(mlist_test mlibc)

ADD_EXECUTABLE(test_get_file_size test_get_file_size.c)  
TARGET_LINK_LIBRARIES(test_get_file_size mlibc)