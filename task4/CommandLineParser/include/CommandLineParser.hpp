//
// Created by Maxim on 26.12.2022.
//

#ifndef LAB4_COMMANDLINEPARSER_HPP
#define LAB4_COMMANDLINEPARSER_HPP

#include "IncludeLibs.hpp"
#include "boost/program_options.hpp"

namespace po = boost::program_options;

class CommandLineParser {
private:
  po::variables_map vm;
  po::options_description description;
  std::string filename = "test.csv";
  char rowDelimiter = '\n';
  char columnDelimiter = ',';
  char shield = '"';
  int skip = 0;
  char convertToChar(const std::string &line);

public:
  CommandLineParser() = delete;
  CommandLineParser(int argc, char **argv);
  const std::string &getFilename() const;
  char getRowDelimiter() const;
  char getColumnDelimiter() const;
  char getShield() const;
  int getSkip() const;
};

#endif // LAB4_COMMANDLINEPARSER_HPP
