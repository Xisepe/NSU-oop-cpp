set(libname CSVParser)
add_library(${libname} include/CSVParser.hpp src/CSVParser.cpp)
target_link_libraries(${libname} PUBLIC IncludeLibs Exceptions PrintTuple)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")