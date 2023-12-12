//
// Created by Maxim on 28.12.2022.
//

#include "ConfigParser.hpp"
ConfigParser::ConfigParser(const std::string &name, const std::string& path) {
  in = std::ifstream(path + name);
  if (!in) {
    throw ConfigParserException("Cannot open config file: " + path + name);
  }
  next();
}
ConfigParser::input_iterator ConfigParser::begin() {
  return input_iterator(this);
}
ConfigParser::input_iterator ConfigParser::end() { return input_iterator(); }
void ConfigParser::next() {
  skipCommentsAndEmptyLines();
  fillConfig();
}
void ConfigParser::skipCommentsAndEmptyLines() {
  std::regex spc("(\\s+)");
  while (line.empty() || line[0] == '#' || std::regex_match(line, spc)) {
    line.clear();
    std::getline(in, line);
    if (!in) {
      throw ConfigParserException("Cannot read from file");
    }
  }
}
void ConfigParser::fillConfig() {
  std::stringstream ss;
  ss << line;
  line.clear();

  ConverterConfig cfg;
  std::string tmp;

  readName(ss,tmp);
  cfg.setName(tmp);

  while (ss) {
    tmp.clear();
    std::getline(ss, tmp, ' ');
    cfg.addParam(tmp);
  }

  config = cfg;
}
void ConfigParser::readName(std::stringstream &ss, std::string &buffer) {
  buffer.clear();
  std::getline(ss, buffer,' ');
}
