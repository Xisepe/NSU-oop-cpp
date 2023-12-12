//
// Created by Maxim on 28.12.2022.
//

#include "WAVParserReadException.hpp"
WAVParserReadException::WAVParserReadException(const std::string &what_arg)
    : SoundProcessorException(AppState::WavFileInputError,what_arg) {
}
