//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_SERVICEEXCEPTION_HPP
#define TASK3_SERVICEEXCEPTION_HPP
#include "include/SoundProcessorException.hpp"
class ServiceException: public SoundProcessorException{
public:
  ServiceException() = delete;
  ServiceException(const std::string& message);
};

#endif // TASK3_SERVICEEXCEPTION_HPP
