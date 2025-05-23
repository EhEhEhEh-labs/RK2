cmake_minimum_required(VERSION 3.10)
project(ChainOfResponsibility)

add_library(CoR STATIC CoR.cpp)

add_executable(main main.cpp)

target_link_libraries(main CoR)
