//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_CONVERTERINFO_HPP
#define TASK3_CONVERTERINFO_HPP
#include "Interface/Converter.hpp"
struct ConverterInfo{
  using CreateMethod = std::function<Converter*()>;
  std::string description;
  CreateMethod create;
};
#endif // TASK3_CONVERTERINFO_HPP
