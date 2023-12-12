set(libname AppState)
add_library(${libname} include/AppState.hpp src/AppState.cpp)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
