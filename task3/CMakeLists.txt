cmake_minimum_required(VERSION 3.16.3)
project(task3)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME SoundProcessor)
set(CMAKE_CXX_FLAGS "-O3")
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(IncludeLibs)
add_subdirectory(WAV)
add_subdirectory(test)
add_subdirectory(CommandLineParser)
add_subdirectory(Sample)
add_subdirectory(Converter)
add_subdirectory(AppState)
add_subdirectory(Exceptions)
add_subdirectory(Factory)
add_subdirectory(Config)
add_subdirectory(Services)
target_link_libraries(${PROJECT_NAME} PUBLIC
        IncludeLibs
        WAVFileStructure
        WAVFileProcessor
        Converter
        ConfigParser
        Factory
        CommandLineParser
        Services
        ServiceFactory
        )