set(libname PrintTuple)
add_library(${libname} include/PrintTuple.hpp src/PrintTuple.cpp)
target_link_libraries(${libname} IncludeLibs)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")