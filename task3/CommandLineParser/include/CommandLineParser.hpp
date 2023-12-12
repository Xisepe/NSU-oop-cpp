//
// Created by Maxim on 24.12.2022.
//

#ifndef TASK3_COMMANDLINEPARSER_HPP
#define TASK3_COMMANDLINEPARSER_HPP

#include "IncludeLibs.hpp"
#include "boost/program_options.hpp"
#include "ConverterRegistry/ConverterRegistry.hpp"

namespace po = boost::program_options;

class CommandLineParser {
public:
  CommandLineParser();
  void parse(int argc, char** argv);
  size_t getInputSize() const;
  const std::string& getInputFile(size_t index) const;
  const std::string &getOutput() const;
  const std::string &getConfig() const;
  const std::string &getDynamicHelpMessage() const;
  const po::variables_map &getVm() const;
  const std::vector<std::string> &getInput() const;

private:
  std::vector<std::string> input;
  std::string output;
  std::string config;
  std::string dynamicHelpMessage;
  po::options_description description;
  po::variables_map vm;
};

#endif // TASK3_COMMANDLINEPARSER_HPP
