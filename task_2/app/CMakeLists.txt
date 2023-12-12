add_executable(${PROJECT_NAME} EntryPoint.cpp ../../task3/main.cpp)

target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        utils
        model
        view
        controller
        exceptions
)
file(COPY ${ASSETS_PATH} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})