//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_SERVICE_HPP
#define TASK3_SERVICE_HPP
#include "IncludeLibs.hpp"
#include "Interface/Converter.hpp"
#include "ConverterConfig.hpp"
#include "Factory.hpp"
#include "WAVFileProcessor.hpp"
#include "ConverterConfigUtils.hpp"
#include "WAVParserException/WAVParserReadException/WAVParserReadException.hpp"
#include "WAVParserException/WAVProcessorWriteException/WAVProcessorWriteException.hpp"
#include "ServiceException/ServiceException.hpp"
class Service {
protected:
  Converter* converter;
  const ConverterConfig*config;
  const std::vector<std::string>* inputs;
  WAVFileProcessor* processor;
  virtual bool validateConfig() = 0;
public:
  Service() = default;
  void initialize(
      Converter* converter,
      const ConverterConfig* config,
      const std::vector<std::string>* inputs,
      WAVFileProcessor* processor
      );
  virtual void execute() = 0;
  virtual ~Service() = default;
};

#endif // TASK3_SERVICE_HPP
