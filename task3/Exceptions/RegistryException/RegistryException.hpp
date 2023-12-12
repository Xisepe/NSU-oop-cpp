//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_REGISTRYEXCEPTION_HPP
#define TASK3_REGISTRYEXCEPTION_HPP
#include "include/SoundProcessorException.hpp"
class RegistryException: public SoundProcessorException {
public:
  RegistryException() =delete;
  RegistryException(const std::string& msg);
};

#endif // TASK3_REGISTRYEXCEPTION_HPP
