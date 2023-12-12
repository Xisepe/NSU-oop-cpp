//
// Created by Maxim on 25.10.2022.
//

#ifndef TASK_2_FILEEXCEPTION_HPP
#define TASK_2_FILEEXCEPTION_HPP
#include <iostream>
#include <utility>

class FileException : public std::exception {
protected:
  std::string _msg;

public:
  FileException(std::string msg) : _msg(std::move(msg)) {}
  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return _msg.c_str();
  }
};

#endif // TASK_2_FILEEXCEPTION_HPP
