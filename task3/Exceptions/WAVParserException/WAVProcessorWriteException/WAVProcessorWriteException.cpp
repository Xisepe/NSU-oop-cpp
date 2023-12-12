//
// Created by Maxim on 28.12.2022.
//

#include "WAVProcessorWriteException.hpp"
WAVProcessorWriteException::WAVProcessorWriteException(const std::string &what_arg)
    : SoundProcessorException(AppState::ParserOutputError,what_arg) {
}
