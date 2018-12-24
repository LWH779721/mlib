cmake_minimum_required(VERSION 2.8) 

PROJECT(mlibc_test)

INCLUDE_DIRECTORIES(../include) 

AUX_SOURCE_DIRECTORY(. MLIBC_TEST)

ADD_EXECUTABLE(example ${MLIBC_TEST})  
TARGET_LINK_LIBRARIES(example mlibc)
