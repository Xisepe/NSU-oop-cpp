//
// Created by Maxim on 28.12.2022.
//

#include "WAVWriterException.hpp"
WAVWriterException::WAVWriterException(const std::string &message)
    : SoundProcessorException(AppState::WavOutputError,message) {}
