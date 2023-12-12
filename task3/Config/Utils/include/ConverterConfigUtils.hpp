//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_CONVERTERCONFIGUTILS_HPP
#define TASK3_CONVERTERCONFIGUTILS_HPP

#include "IncludeLibs.hpp"
#include "regex"

class ConverterConfigUtils {
public:
  static bool isInputStreamReference(const std::string& str);
  static bool isSecond(const std::string& str);
  static int getNumberFromInputStreamReference(const std::string& str);
  static int getSecond(const std::string& str);
};

#endif // TASK3_CONVERTERCONFIGUTILS_HPP
