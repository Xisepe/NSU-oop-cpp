set(libname Exceptions)
add_library(${libname} include/CSVParserException.hpp src/CSVExceptions.cpp src/CSVParserException.cpp include/CSVExceptions.hpp)
target_link_libraries(${libname} PUBLIC IncludeLibs AppState)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")