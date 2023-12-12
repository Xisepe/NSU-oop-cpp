//
// Created by Maxim on 28.12.2022.
//

#include "Factory.hpp"
Converter *Factory::orderConverter(const std::string &name) {
  return ConverterRegistry::getInstance().getConverterInfo(name).create();
}
