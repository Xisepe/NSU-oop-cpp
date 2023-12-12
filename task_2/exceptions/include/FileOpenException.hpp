//
// Created by Maxim on 25.10.2022.
//

#ifndef TASK_2_FILEOPENEXCEPTION_HPP
#define TASK_2_FILEOPENEXCEPTION_HPP
#include "FileException.hpp"
class FileOpenException : public FileException {
public:
  FileOpenException(std::string msg) : FileException(std::move(msg)) {}
};
#endif // TASK_2_FILEOPENEXCEPTION_HPP
