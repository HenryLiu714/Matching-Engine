cmake_minimum_required(VERSION 3.15)

project(MyProject VERSION 1.0
                  DESCRIPTION "Very nice project"
                  LANGUAGES CXX)

file(GLOB_RECURSE SRC_FILES lib/*.cpp)
add_executable(exchange src/main.cpp ${SRC_FILES})
target_include_directories(exchange PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)