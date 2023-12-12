//
// Created by Maxim on 27.12.2022.
//

#include "MuteConverter.hpp"
const SampleStream &MuteConverter::convert(const std::vector<SampleStream> &input) {
  std::fill(output.begin(), output.end(),0);
  return output;
}
bool MuteConverter::checkInput(const std::vector<SampleStream> &input) {
  return true;
}
