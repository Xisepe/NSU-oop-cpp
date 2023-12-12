set(UTILS utils)
add_library(
        ${UTILS}
        include/Parser.hpp
        include/CommandLineArgumentParser.hpp
        bin/CommandLineArgumentParser.cpp
        bin/InputFileParser.cpp include/InputFileParser.hpp)
target_include_directories(${UTILS} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${UTILS} PRIVATE exceptions model)