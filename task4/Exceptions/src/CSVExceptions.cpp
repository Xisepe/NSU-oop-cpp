//
// Created by Maxim on 25.12.2022.
//
#include "CSVExceptions.hpp"

ReadException::ReadException(size_t row, size_t column)
    : CSVParserException(
          AppState::ReadError, row, column,
          "Error occurred while reading file.\nProbable causes:\n-Empty "
          "file\n-File is smaller than skipped lines\n-Wrong number of columns\n") {}
WrongDataException::WrongDataException(size_t row, size_t column)
    : CSVParserException(AppState::WrongData, row, column,
                         "Error occurred while processing data in "
                         "line.\nProbable causes:\n-Wrong data format") {}
