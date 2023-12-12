//
// Created by Maxim on 27.12.2022.
//

#include "ConverterRegistry.hpp"

ConverterRegistry &ConverterRegistry::getInstance() {
  static ConverterRegistry instance;
  return instance;
}
const ConverterInfo &
ConverterRegistry::getConverterInfo(const std::string &name) const {
  if (map.find(name) != map.end()) {
    return map.at(name);
  }
  throw RegistryException("Converter not found: " + name);
}
void ConverterRegistry::registerConverter(const std::string& name,
                                          ConverterInfo converterInfo) {
  if (map.find(name) == map.end()) {
    map.insert({name, converterInfo});
    allDescription+=converterInfo.description;
  } else {
    throw RegistryException("Converter already registered: " + name);
  }
}
const std::string &ConverterRegistry::getAllDescription() const {
  return allDescription;
}
