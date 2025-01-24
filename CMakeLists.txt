cmake_minimum_required(VERSION 3.15)

project(MyProject VERSION 1.0
                  DESCRIPTION "Very nice project"
                  LANGUAGES CXX)

add_subdirectory(lib)

file(GLOB_RECURSE SRC_FILES lib/*.cpp)
add_executable(exchange src/main.cpp ${SRC_FILES})
target_link_libraries(exchange PUBLIC lib)