//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_WAVWRITEREXCEPTION_HPP
#define TASK3_WAVWRITEREXCEPTION_HPP
#include "include/SoundProcessorException.hpp"
class WAVWriterException:public SoundProcessorException {
public:
  WAVWriterException()=delete;
  WAVWriterException(const std::string& message);
};

#endif // TASK3_WAVWRITEREXCEPTION_HPP
