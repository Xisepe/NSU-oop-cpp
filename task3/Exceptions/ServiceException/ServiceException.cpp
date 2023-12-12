//
// Created by Maxim on 29.12.2022.
//

#include "ServiceException.hpp"
ServiceException::ServiceException(const std::string &message)
    : SoundProcessorException(AppState::ServiceError, message) {}
