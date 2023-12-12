set(EXCEPT exceptions)
add_library(
        ${EXCEPT}
        include/FileOpenException.hpp
        include/FileException.hpp
        include/WrongFileFormatException.hpp
        include/FileExceptionsLib.hpp include/InputArgumentException.h)
target_include_directories(${EXCEPT} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties(${EXCEPT} PROPERTIES LINKER_LANGUAGE CXX)