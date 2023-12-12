//
// Created by Maxim on 28.12.2022.
//

#include "ConverterConfig.hpp"
const std::string &ConverterConfig::getName() const { return name; }
const std::vector<std::string> &ConverterConfig::getInputParams() const {
  return inputParams;
}
void ConverterConfig::setName(const std::string &name) {
  ConverterConfig::name = name;
}
void ConverterConfig::addParam(const std::string &param) {
  inputParams.push_back(param);
}

