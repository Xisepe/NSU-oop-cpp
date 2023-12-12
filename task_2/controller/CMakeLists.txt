set(CONTROLLER controller)
add_library(
        ${CONTROLLER}
        bin/LogicController.cpp include/LogicController.hpp bin/GameController.cpp include/GameController.hpp)
target_link_libraries(${CONTROLLER} PUBLIC model view)
target_include_directories(${CONTROLLER} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")