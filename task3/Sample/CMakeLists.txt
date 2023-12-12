set(libname Sample)
add_library(${libname} include/Sample.hpp src/Sample.cpp)
target_link_libraries(${libname} PUBLIC IncludeLibs WAVFileStructure)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
