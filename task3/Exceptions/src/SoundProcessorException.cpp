//
// Created by Maxim on 28.12.2022.
//

#include "include/SoundProcessorException.hpp"
SoundProcessorException::SoundProcessorException(AppState state, const std::string &msg): std::runtime_error(msg) {
  this->state = state;
}
AppState SoundProcessorException::getState() const { return AppState::Ok; }
