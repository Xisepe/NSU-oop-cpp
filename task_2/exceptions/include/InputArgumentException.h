//
// Created by Maxim on 29.10.2022.
//

#ifndef TASK_2_INPUTARGUMENTEXCEPTION_H
#define TASK_2_INPUTARGUMENTEXCEPTION_H
#include <iostream>
#include <utility>

class InputArgumentException: public std::exception {
protected:
  std::string _msg;

public:
  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return _msg.c_str();
  }
  InputArgumentException(std::string msg) : _msg(std::move(msg)) {}
  InputArgumentException() : _msg("Wrong argument") {}
};
#endif // TASK_2_INPUTARGUMENTEXCEPTION_H
