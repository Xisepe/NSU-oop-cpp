//
// Created by Maxim on 26.12.2022.
//

#include "CommandLineParser.hpp"
char CommandLineParser::getRowDelimiter() const { return rowDelimiter; }
char CommandLineParser::getColumnDelimiter() const { return columnDelimiter; }
char CommandLineParser::getShield() const { return shield; }
int CommandLineParser::getSkip() const { return skip; }
CommandLineParser::CommandLineParser(int argc, char **argv) {
  std::string r, c, s;
  description.add_options()("help, h", "Options description")(
      "filename, f", po::value<std::string>(&filename), "--filename=filename")(
      "skip, S", po::value<int>(&skip), "--skip=numberOfLinesToScip")(
      "row, r", po::value<std::string>(&r), "--row=rowDelimiter")(
      "column, c", po::value<std::string>(&c), "--column=columnDelimiter")(
      "shield, s", po::value<std::string>(&s), "--shield=shieldSymbol");
  po::store(po::parse_command_line(argc, argv, description), vm);
  po::notify(vm);
  if (vm.count("help")) {
    std::cout << description;
    throw std::invalid_argument("--help");
  }
  if (!r.empty()) {
    rowDelimiter = convertToChar(r);
  }
  if (!c.empty()) {
    columnDelimiter = convertToChar(c);
  }
  if (!s.empty()) {
    shield = convertToChar(s);
  }
}
char CommandLineParser::convertToChar(const std::string &line) {
  if (line.size() == 1) {
    return line[0];
  } else if (line == "\t")
    return '\t';
  else if (line == "\n")
    return '\n';
  else if (line == "\v")
    return '\v';
  else if (line == "\r")
    return '\r';
  else if (line == "\f")
    return '\f';
  return '-';
}
const std::string &CommandLineParser::getFilename() const { return filename; }
