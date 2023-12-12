//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_WAVPROCESSORWRITEEXCEPTION_HPP
#define TASK3_WAVPROCESSORWRITEEXCEPTION_HPP
#include "AppState.hpp"
#include "include/SoundProcessorException.hpp"
class WAVProcessorWriteException: public SoundProcessorException {
public:
  WAVProcessorWriteException() = delete;
  WAVProcessorWriteException(const std::string& what_arg);
};
#endif // TASK3_WAVPROCESSORWRITEEXCEPTION_HPP
