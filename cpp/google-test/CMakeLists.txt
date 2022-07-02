cmake_minimum_required(VERSION 3.6)
project("cpp-gtest")

set(CMAKE_CXX_STANDARD 17)
enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

file(GLOB SOURCES "*.cc")
file(GLOB HEADERS "*.h")

include_directories(.)

add_executable(cpp-gtest ${SOURCES} ${HEADERS} )

target_link_libraries(cpp-gtest  GTest::gtest GTest::gtest_main )

