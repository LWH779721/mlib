cmake_minimum_required(VERSION 2.8) 

PROJECT(mlibc_test)

INCLUDE_DIRECTORIES(../include) 

ADD_EXECUTABLE(example test.c)  
TARGET_LINK_LIBRARIES(example mlibc)

ADD_EXECUTABLE(test_debug test_debug.c)  
TARGET_LINK_LIBRARIES(test_debug mlibc)

ADD_EXECUTABLE(mlist_test mlist_test.c)  
TARGET_LINK_LIBRARIES(mlist_test mlibc)

ADD_EXECUTABLE(test_get_file_size test_get_file_size.c)  
TARGET_LINK_LIBRARIES(test_get_file_size mlibc)

ADD_EXECUTABLE(test_file test_file.c)  
TARGET_LINK_LIBRARIES(test_file mlibc)

ADD_EXECUTABLE(timeStamp_test timeStamp_test.c)  
TARGET_LINK_LIBRARIES(timeStamp_test mlibc)

ADD_EXECUTABLE(test_get_ip_and_mac test_get_ip_and_mac.c)  
TARGET_LINK_LIBRARIES(test_get_ip_and_mac mlibc)
