cmake_minimum_required(VERSION 3.1)
project(StrooLang C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(StrooLang ${SRC_FILES})
