set(VIEW view)
add_library(
        ${VIEW}
        include/GameView.hpp
        bin/ConsoleGameView.cpp include/ConsoleGameView.hpp bin/FileGameView.cpp include/FileGameView.hpp bin/GameView.cpp)
target_link_libraries(${VIEW} PUBLIC model)
target_include_directories(${VIEW} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

