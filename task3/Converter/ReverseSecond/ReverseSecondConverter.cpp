//
// Created by Maxim on 27.12.2022.
//

#include "ReverseSecondConverter.hpp"
const SampleStream &
ReverseSecondConverter::convert(const std::vector<SampleStream> &input) {
  if (!checkInput(input))
    //TODO(ConverterException)
    throw std::invalid_argument("wrong converter input");
  const auto& in = input[0];
  for (int i = 0; i < in.size(); ++i) {
    output[i] = in[i];
  }
  std::reverse(output.begin(), output.end());
  return output;
}
bool ReverseSecondConverter::checkInput(const std::vector<SampleStream> &input) {
  if (input.size() != 1)
    return false;
  return true;
}
