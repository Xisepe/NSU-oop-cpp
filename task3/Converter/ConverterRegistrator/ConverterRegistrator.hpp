//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_CONVERTERREGISTRATOR_HPP
#define TASK3_CONVERTERREGISTRATOR_HPP
#include "ConverterInfo/ConverterInfo.hpp"
#include "ConverterRegistry/ConverterRegistry.hpp"
#include "IncludeLibs.hpp"

namespace ConverterRegistrations {

template <class T> class ConverterRegistrator {
public:
  ConverterRegistrator() = default;
  ConverterRegistrator(const std::string &name,
                       const std::string &description) {
    ConverterRegistry::getInstance().registerConverter(
        name,
        {description, []() { return static_cast<Converter *>(new T()); }});
  }
};

} // namespace ConverterRegistrations

#endif // TASK3_CONVERTERREGISTRATOR_HPP
