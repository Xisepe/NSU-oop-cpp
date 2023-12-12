//
// Created by Maxim on 25.10.2022.
//

#ifndef TASK_2_WRONGFILEFORMATEXCEPTION_HPP
#define TASK_2_WRONGFILEFORMATEXCEPTION_HPP
#include "FileException.hpp"
class WrongFileFormatException: public FileException {
public:
  explicit WrongFileFormatException(std::string msg) : FileException(std::move(msg)) {}
};

#endif // TASK_2_WRONGFILEFORMATEXCEPTION_HPP
