set(libname IncludeLibs)
add_library(${libname}
        include/IncludeLibs.hpp
        src/IncludeLibs.cpp)
target_include_directories(${libname} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")