cmake_minimum_required(VERSION 3.10)
project(ChainOfResponsibility)

add_library(CoR STATIC CoR.cpp)

add_executable(main main.cpp)

target_link_libraries(main CoR)



enable_testing()
add_subdirectory(third-party/gtest)
add_executable(test_app tests/tests.cpp)
target_include_directories(test_app
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  
)
target_compile_options(test_app PRIVATE --coverage)
target_link_libraries(test_app CoR  gtest_main gmock_main --coverage)

include(CPackConfig.cmake)
