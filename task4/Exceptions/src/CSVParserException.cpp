//
// Created by Maxim on 25.12.2022.
//
#include "CSVParserException.hpp"
CSVParserException::CSVParserException(AppState state, size_t row,
                                       size_t column, const std::string &msg)
    : std::runtime_error(buildMsg(row, column, msg)) {
  this->state = state;
}
std::string CSVParserException::buildMsg(size_t row, size_t column,
                                         const std::string &msg) {
  return msg + "\n" + "Row: " + std::to_string(row) + "\n" +
         "Column: " + std::to_string(column);
}
AppState CSVParserException::getState() const { return state; }
