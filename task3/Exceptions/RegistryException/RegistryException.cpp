//
// Created by Maxim on 28.12.2022.
//

#include "RegistryException.hpp"
RegistryException::RegistryException(const std::string &msg)
    : SoundProcessorException(AppState::RegistrationError,msg) {}
