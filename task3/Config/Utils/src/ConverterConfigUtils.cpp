//
// Created by Maxim on 29.12.2022.
//

#include "ConverterConfigUtils.hpp"

bool ConverterConfigUtils::isInputStreamReference(const std::string& str) {
  std::regex r("(\\$\\d{1,9})");
  return std::regex_match(str,r);
}
bool ConverterConfigUtils::isSecond(const std::string& str) {
  std::regex r("(\\d{1,9})\\s?");
  return std::regex_match(str,r);
}
int ConverterConfigUtils::getNumberFromInputStreamReference(
    const std::string &str) {
  try{
    return std::stoi(str.substr(1));
  }catch (const std::invalid_argument& e) {
    return -1;
  }
}
int ConverterConfigUtils::getSecond(const std::string &str) {
  try{
    return std::stoi(str);
  } catch (const std::invalid_argument& e) {
    return -1;
  }
}
