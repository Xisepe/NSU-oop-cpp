//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_CONVERTERCONFIG_HPP
#define TASK3_CONVERTERCONFIG_HPP
#include "IncludeLibs.hpp"
class ConverterConfig {
private:
  std::string name;
  std::vector<std::string> inputParams;
public:
  ConverterConfig() = default;
  void setName(const std::string &name);
  void addParam(const std::string& param);
  const std::string &getName() const;
  const std::vector<std::string> &getInputParams() const;
  ~ConverterConfig() = default;
};

#endif // TASK3_CONVERTERCONFIG_HPP
