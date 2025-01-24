add_library(lib STATIC trade.cpp matching-engine.cpp)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)