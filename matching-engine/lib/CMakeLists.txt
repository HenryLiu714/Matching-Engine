add_library(lib STATIC order.cpp matching-engine.cpp trademessage.pb.cc)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)