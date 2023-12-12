set(libname ConverterConfigUtils)
add_library(${libname} src/ConverterConfigUtils.cpp include/ConverterConfigUtils.hpp)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${libname} PUBLIC IncludeLibs)