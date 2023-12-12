//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_CONFIGPARSEREXCEPTION_HPP
#define TASK3_CONFIGPARSEREXCEPTION_HPP
#include "include/SoundProcessorException.hpp"
class ConfigParserException: public SoundProcessorException {
public:
  ConfigParserException() = delete;
  ConfigParserException(const std::string& msg);
};

#endif // TASK3_CONFIGPARSEREXCEPTION_HPP
