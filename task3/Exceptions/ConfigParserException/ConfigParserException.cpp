//
// Created by Maxim on 28.12.2022.
//

#include "ConfigParserException.hpp"
ConfigParserException::ConfigParserException(const std::string &msg)
    : SoundProcessorException(AppState::ConfigParserError,msg) {}
