//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_SOUNDPROCESSOREXCEPTION_HPP
#define TASK3_SOUNDPROCESSOREXCEPTION_HPP
#include "AppState.hpp"
#include "IncludeLibs.hpp"
class SoundProcessorException : public std::runtime_error{
public:
  SoundProcessorException() = delete;
  SoundProcessorException(AppState state, const std::string& msg);
  AppState getState() const;
protected:
  AppState state;
};


#endif // TASK3_SOUNDPROCESSOREXCEPTION_HPP
