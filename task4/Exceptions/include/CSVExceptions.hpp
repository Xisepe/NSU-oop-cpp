//
// Created by Maxim on 25.12.2022.
//

#ifndef LAB4_CSVEXCEPTIONS_HPP
#define LAB4_CSVEXCEPTIONS_HPP
#include "CSVParserException.hpp"

class ReadException: public CSVParserException{
public:
  ReadException() = delete;
  ReadException(size_t row, size_t column);
};

class WrongDataException: public CSVParserException{
public:
  WrongDataException() = delete;
  WrongDataException(size_t row, size_t column);
};
#endif // LAB4_CSVEXCEPTIONS_HPP
