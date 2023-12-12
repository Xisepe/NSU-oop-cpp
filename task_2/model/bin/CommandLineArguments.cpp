//
// Created by maxim on 15.10.2022.
//

#include "CommandLineArguments.hpp"

int CommandLineArguments::getIterations() const { return _iterations; }

void CommandLineArguments::setIterations(int iterations) {
  _iterations = iterations;
}

const std::string &CommandLineArguments::getInputFilepath() const {
  return _inputFilepath;
}

void CommandLineArguments::setInputFilepath(const std::string &inputFilepath) {
  _inputFilepath = inputFilepath;
}

const std::string &CommandLineArguments::getOutputFilepath() const {
  return _outputFilepath;
}

void CommandLineArguments::setOutputFilepath(
    const std::string &outputFilepath) {
  _outputFilepath = outputFilepath;
}

CommandLineArguments::CommandLineArguments(int iterations, std::string input,
                                           std::string output, int mode)
    : _iterations(iterations), _inputFilepath(std::move(input)),
      _outputFilepath(std::move(output)), _mode(mode) {}

CommandLineArguments::CommandLineArguments(const CommandLineArguments &args)
    : _iterations(args._iterations), _inputFilepath(args._inputFilepath),
      _outputFilepath(args._outputFilepath), _mode(args._mode) {}

CommandLineArguments &
CommandLineArguments::operator=(const CommandLineArguments &args) {
  if (this != &args) {
    _iterations = args._iterations;
    _inputFilepath = args._inputFilepath;
    _outputFilepath = args._outputFilepath;
    _mode = args._mode;
  }
  return *this;
}
CommandLineArguments::CommandLineArguments()
    : _iterations(1),
      _mode(0),
      _inputFilepath("default_input.txt"),
      _outputFilepath("default_output.txt") {}
int CommandLineArguments::getMode() const { return _mode; }
void CommandLineArguments::setMode(int mode) { _mode = mode; }
std::ostream &operator<<(std::ostream &os,
                         const CommandLineArguments &arguments) {
  os << "iterations: " << arguments._iterations
     << " inputFilepath: " << arguments._inputFilepath
     << " outputFilepath: " << arguments._outputFilepath
     << " mode: " << arguments._mode;
  return os;
}
