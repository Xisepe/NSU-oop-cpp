set(libname WAVFileProcessor)
add_library(${libname} include/WAVFileProcessor.hpp src/WAVFileProcessor.cpp)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${libname} PUBLIC IncludeLibs WAVFileStructure Sample Exceptions)