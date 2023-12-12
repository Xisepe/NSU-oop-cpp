//
// Created by Maxim on 24.12.2022.
//

#include "CommandLineParser.hpp"
CommandLineParser::CommandLineParser() {
  dynamicHelpMessage = ConverterRegistry::getInstance().getAllDescription();
  description.add_options()
      ("help, h", "Options description")
          ("input, i", po::value<std::vector<std::string>>(&input)->multitoken(), "--input=input1...")
              ("config, c", po::value<std::string>(&config), "--config=config")
                  ("output, o", po::value<std::string>(&output), "--output=output");
}
void CommandLineParser::parse(int argc, char**argv) {
  po::store(po::parse_command_line(argc,argv,description), vm);
  po::notify(vm);
  if (vm.count("help")) {
    std::cout << dynamicHelpMessage;
    std::cout << description;
    throw std::invalid_argument("--help invocation");
  }
}
const std::string &CommandLineParser::getOutput() const { return output; }
const std::string &CommandLineParser::getConfig() const { return config; }
const std::string &CommandLineParser::getDynamicHelpMessage() const {
  return dynamicHelpMessage;
}
const po::variables_map &CommandLineParser::getVm() const { return vm; }
size_t CommandLineParser::getInputSize() const {
    return input.size();
}
const std::string &CommandLineParser::getInputFile(size_t index) const {
    return input[index];
}
const std::vector<std::string> &CommandLineParser::getInput() const {
  return input;
}
