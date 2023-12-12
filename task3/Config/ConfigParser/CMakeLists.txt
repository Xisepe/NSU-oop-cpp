set(libname ConfigParser)
add_library(${libname} src/ConfigParser.cpp include/ConfigParser.hpp)
target_link_libraries(${libname} PUBLIC IncludeLibs Exceptions ConverterConfig)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")