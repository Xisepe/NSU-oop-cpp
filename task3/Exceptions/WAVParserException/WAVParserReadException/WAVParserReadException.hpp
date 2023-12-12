//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_WAVPARSERREADEXCEPTION_HPP
#define TASK3_WAVPARSERREADEXCEPTION_HPP
#include "include/SoundProcessorException.hpp"
#include "AppState.hpp"
class WAVParserReadException: public SoundProcessorException {
public:
  WAVParserReadException() = delete;
  WAVParserReadException(const std::string& what_arg);
};

#endif // TASK3_WAVPARSERREADEXCEPTION_HPP
