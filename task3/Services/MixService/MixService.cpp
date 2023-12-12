//
// Created by Maxim on 29.12.2022.
//

#include "MixService.hpp"
void MixService::execute() {
  if (!validateConfig()) {
    throw ServiceException("Invalid converter configuration");
  }

  processor->resetToDataStart();
  int numberOfInput = ConverterConfigUtils::getNumberFromInputStreamReference(
      config->getInputParams()[0]);
  int endSecond = ConverterConfigUtils::getSecond(config->getInputParams()[1]);
  if (numberOfInput == -1) {
    throw ServiceException(
        "Wrong converter config. Cannot parse number of input");
  }
  WAVFileProcessor mix(inputs->at(numberOfInput - 1), "../Assets/Input/");
  auto mixIter = mix.begin();
  processor->skipTo(endSecond + 1);
  for (auto it = processor->begin(); it != processor->end(); ++it) {
    if (mixIter == mix.end()) {
      break;
    }
    const auto &ssOutput = converter->convert({*it, *mixIter});
    processor->overwriteAfterRead(&ssOutput);
    ++mixIter;
  }
}
bool MixService::validateConfig() {
  const auto &inputParams = config->getInputParams();
  if (inputParams.size() < 2) {
    return false;
  }
  if (!ConverterConfigUtils::isInputStreamReference(inputParams[0])) {
    return false;
  }
  if (!ConverterConfigUtils::isSecond(inputParams[1])) {
    return false;
  }
  return true;
}
