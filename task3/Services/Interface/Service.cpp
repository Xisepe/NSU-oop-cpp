//
// Created by Maxim on 28.12.2022.
//

#include "Service.hpp"

void Service::initialize(Converter* converter,
                         const ConverterConfig* config,
                         const std::vector<std::string>* inputs,
                         WAVFileProcessor* processor) {
  this->converter = converter;
  this->config = config;
  this->inputs = inputs;
  this->processor = processor;
}
