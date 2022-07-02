cmake_minimum_required( VERSION 3.2)

project("cpp-project")

file(GLOB SOURCES "*.cc")
file(GLOB HEADERS "*.h")

include_directories(.)
add_executable(cpp-project ${SOURCES} ${HEADERS})

find_package(benchmark REQUIRED)
target_link_libraries(cpp-project benchmark::benchmark)