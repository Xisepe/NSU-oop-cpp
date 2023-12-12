set(libname Factory)
add_library(${libname} src/Factory.cpp include/Factory.hpp)
target_link_libraries(${libname} PUBLIC IncludeLibs Converter)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")