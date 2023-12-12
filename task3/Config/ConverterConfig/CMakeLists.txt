set(libname ConverterConfig)
add_library(${libname} src/ConverterConfig.cpp include/ConverterConfig.hpp)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${libname} PUBLIC IncludeLibs)