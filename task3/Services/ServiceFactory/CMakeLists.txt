set(libname ServiceFactory)
add_library(${libname} src/ServiceFactory.cpp include/ServiceFactory.hpp)
target_link_libraries(${libname} PUBLIC IncludeLibs Services)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")