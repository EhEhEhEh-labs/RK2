cmake_minimum_required(VERSION 3.10)
project(ChainOfResponsibility VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

set(PRINT_VERSION_MAJOR 0)
set(PRINT_VERSION_MINOR 1)
set(PRINT_VERSION_PATCH 0)
set(PRINT_VERSION_TWEAK 0)
set(PRINT_VERSION\${PRINT_VERSION_MAJOR}.${PRINT_VERSION_MINOR}.${PRINT_VERSION_PATCH}.${PRINT_VERSION_TWEAK})
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")

include(CPackConfig.cmake)
