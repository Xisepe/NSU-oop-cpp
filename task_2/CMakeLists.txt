cmake_minimum_required(VERSION 3.13)
project(task_2)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME ConwaysGameOfLife)
set(ASSETS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ASSETS")
add_compile_options(-O3)
add_subdirectory(exceptions)
add_subdirectory(utils)
add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(controller)
add_subdirectory(app)
add_subdirectory(test)

