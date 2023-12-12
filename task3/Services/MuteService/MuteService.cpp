//
// Created by Maxim on 29.12.2022.
//

#include "MuteService.hpp"
void MuteService::execute() {
  if (!validateConfig()) {
    throw ServiceException("Invalid converter configuration");
  }

  processor->resetToDataStart();
  int startSecond =
      ConverterConfigUtils::getSecond(config->getInputParams()[0]);
  int endSecond = ConverterConfigUtils::getSecond(config->getInputParams()[1]);
  processor->skipTo(startSecond + 1);
  for (auto it = processor->begin();
       it != processor->end() && startSecond <= endSecond;
       ++it, startSecond++) {
    const auto &ssOutput = converter->convert({*it});
    processor->overwriteAfterRead(&ssOutput);
  }
}
bool MuteService::validateConfig() {
  const auto &inputParams = config->getInputParams();
  if (inputParams.size() < 2) {
    return false;
  }
  if (!ConverterConfigUtils::isSecond(inputParams[0])) {
    return false;
  }
  if (!ConverterConfigUtils::isSecond(inputParams[1])) {
    return false;
  }
  return true;
}
