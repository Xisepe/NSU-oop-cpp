//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_CONVERTERREGISTRY_HPP
#define TASK3_CONVERTERREGISTRY_HPP
#include "ConverterInfo/ConverterInfo.hpp"
#include "IncludeLibs.hpp"
#include "RegistryException/RegistryException.hpp"

class ConverterRegistry {
private:
  std::unordered_map<std::string, ConverterInfo> map;
  std::string allDescription;
  ConverterRegistry() = default;
public:
  static ConverterRegistry& getInstance();
  const ConverterInfo& getConverterInfo(const std::string& name) const;
  const std::string& getAllDescription() const;
  void registerConverter(const std::string& name, ConverterInfo converterInfo);
};

#endif // TASK3_CONVERTERREGISTRY_HPP
