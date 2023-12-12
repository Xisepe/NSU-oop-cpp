//
// Created by Maxim on 25.12.2022.
//

#ifndef LAB4_CSVPARSEREXCEPTION_HPP
#define LAB4_CSVPARSEREXCEPTION_HPP
#include "IncludeLibs.hpp"
#include "AppState.hpp"
class CSVParserException: public std::runtime_error{
public:
  CSVParserException() = delete;
  CSVParserException(AppState state,size_t row, size_t column, const std::string& msg);
  AppState getState() const;

protected:
  static std::string buildMsg(size_t row, size_t column, const std::string& msg);
  AppState state;
};
#endif // LAB4_CSVPARSEREXCEPTION_HPP
