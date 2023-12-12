set(libname WAVFileStructure)
add_library(${libname}
        include/WAVHeader.hpp src/WAVHeader.cpp
        include/WAVChunk.hpp src/WAVChunk.cpp
        include/WAVData.hpp include/WAVFileStructure.hpp)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${libname} PUBLIC IncludeLibs)