//
// Created by Maxim on 24.12.2022.
//

#ifndef TASK3_CONVERTER_HPP
#define TASK3_CONVERTER_HPP

#include "Sample.hpp"

class Converter {
protected:
  SampleStream output;
  virtual bool checkInput(const std::vector<SampleStream>& input) = 0;
public:
  Converter() = default;
  virtual const SampleStream& convert(const std::vector<SampleStream>& input) = 0;
  virtual ~Converter() = default;
};
#endif // TASK3_CONVERTER_HPP
