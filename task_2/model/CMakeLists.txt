set(MODEL model)
add_library(
        ${MODEL}
        include/Cell.hpp
        bin/Cell.cpp
        bin/CellField.cpp include/CellField.h bin/GameSettings.cpp include/GameSettings.hpp bin/CommandLineArguments.cpp include/CommandLineArguments.hpp)
target_include_directories(${MODEL} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")