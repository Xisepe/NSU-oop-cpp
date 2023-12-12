set(libname CommandLineParser)

add_library(${libname} include/CommandLineParser.hpp src/CommandLineParser.cpp)

find_package(Boost COMPONENTS program_options)
set(BOOST_INCLUDE_LIBRARIES program_options)
set(BOOST_ENABLE_CMAKE ON)
include_directories(${BOOST_INCLUDE_LIBRARIES})

target_link_libraries(${libname} PUBLIC Boost::program_options IncludeLibs Converter)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
