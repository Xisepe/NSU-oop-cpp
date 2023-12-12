//
// Created by Maxim on 27.12.2022.
//

#include "MixConverter.hpp"
const SampleStream& MixConverter::convert(const std::vector<SampleStream> &input) {
  if (!checkInput(input))
    //TODO(ConverterException)
    throw std::invalid_argument("Wrong converter input");
  const auto& i0 = input[0];
  const auto& i1 = input[1];
  for (int i = 0; i < i0.size(); ++i) {
    output[i] = (i0[i] + i1[i])/2;
  }
  return output;
}
bool MixConverter::checkInput(const std::vector<SampleStream> &input) {
  if (input.size() != 2) {
    return false;
  }
  if (input[0].size() != input[1].size())
    return false;
  return true;
}

