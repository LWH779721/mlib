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

ADD_EXECUTABLE(test_file2 test_file.cpp)  
TARGET_LINK_LIBRARIES(test_file2 mlibc)

ADD_EXECUTABLE(test_ts test_ts.c)  
TARGET_LINK_LIBRARIES(test_ts mlibc)

ADD_EXECUTABLE(test_get_ip_and_mac test_get_ip_and_mac.c)  
TARGET_LINK_LIBRARIES(test_get_ip_and_mac mlibc)

ADD_EXECUTABLE(test_mbits test_mbits.c)  
TARGET_LINK_LIBRARIES(test_mbits mlibc)

ADD_EXECUTABLE(test_AVLTree test_AVLTree.c)  
TARGET_LINK_LIBRARIES(test_AVLTree mlibc)

ADD_EXECUTABLE(test_muart test_muart.c)  
TARGET_LINK_LIBRARIES(test_muart mlibc)

ADD_EXECUTABLE(test_mem_pool test_mem_pool.c)  
TARGET_LINK_LIBRARIES(test_mem_pool mlibc)

ADD_EXECUTABLE(mshm_test mshm_test.c)  
TARGET_LINK_LIBRARIES(mshm_test mlibc)

ADD_EXECUTABLE(test_worker test_worker.c)  
TARGET_LINK_LIBRARIES(test_worker mlibc)

ADD_EXECUTABLE(test_cks test_cks.c)  
TARGET_LINK_LIBRARIES(test_cks mlibc)

#ADD_EXECUTABLE(test_timer test_timer.c)  
#TARGET_LINK_LIBRARIES(test_timer mlibc)
