//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_FACTORY_HPP
#define TASK3_FACTORY_HPP
#include "IncludeLibs.hpp"
#include "Interface/Converter.hpp"
#include "ConverterRegistry/ConverterRegistry.hpp"

class Factory {
  public:
    static Converter* orderConverter(const std::string& name);
};

#endif // TASK3_FACTORY_HPP
