set(libname Converter)
add_library(${libname} Interface/Converter.hpp Mix/MixConverter.cpp Mix/MixConverter.hpp Mute/MuteConverter.cpp Mute/MuteConverter.hpp ReverseSecond/ReverseSecondConverter.cpp ReverseSecond/ReverseSecondConverter.hpp ConverterInfo/ConverterInfo.hpp ConverterInfo/ConverterInfo.cpp ConverterRegistry/ConverterRegistry.cpp ConverterRegistry/ConverterRegistry.hpp ConverterRegistrator/ConverterRegistrator.cpp ConverterRegistrator/ConverterRegistrator.hpp init_converters.hpp)
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${libname} PUBLIC IncludeLibs Sample Exceptions)
