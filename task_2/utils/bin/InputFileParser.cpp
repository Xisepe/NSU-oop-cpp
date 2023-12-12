//
// Created by maxim on 23.10.2022.
//

#include "InputFileParser.hpp"
#include "GameSettings.hpp"
#include "FileExceptionsLib.hpp"
#include <fstream>
#include <regex>
#include <utility>

GameSettings InputFileParser::parse() const {

  std::string line;
  std::ifstream in;
  in.open(_FOLDER + _filename,
          std::ios::in);
  throwCheckStreamState(in);

  GameSettings settings;

  std::getline(in, line);
  evaluateInputFileFormat(checkInputFileFormat(line), in);

  std::getline(in, line);
  evaluateUniverseName(checkUniverseName(line), in);
  settings.setUniverseName(parseName(line));

  std::getline(in, line);
  evaluateBornSurviveRules(checkBornSurviveRules(line), in);
  bool beforeSlash = true;
  for (const auto &c : line) {
    char i = c - '0';
    if ((i >= 0 && i < 10)) {
      if (beforeSlash) {
        settings.addCellNumberToBorn(i);
      } else {
        settings.addCellNumberToStayAlive(i);
      }
    } else if (c == '/') {
      beforeSlash = false;
    }
  }
  while (std::getline(in, line)) {
    evaluatePair(checkPair(line), in);
    int x = std::stoi(line);
    int y = std::stoi(line.substr(line.find(" ")));
    settings.addPairOfStartCells(x, y);
  }
  in.close();
  return settings;
}

InputFileParser::InputFileParser(std::string filename)
    : _filename(std::move(filename)) {}
void InputFileParser::throwCheckStreamState(const std::ifstream &in) const {
  if (!in.is_open()) {
    throw FileOpenException("Cannot open the file: " + _filename);
  }
  if (in.eof()) {
    throw FileException("Empty file");
  }
}

bool InputFileParser::checkInputFileFormat(const std::string &line) const {
  std::regex regex(R"(#Life 1.06\s{0,})",
                   std::regex_constants::ECMAScript);
  return std::regex_match(line, regex);
}
void InputFileParser::evaluateInputFileFormat(bool res,
                                              std::ifstream &in) const {
  if (!res || in.eof()) {
    in.close();
    throw WrongFileFormatException("Wrong file format line");
  }
}
bool InputFileParser::checkBornSurviveRules(const std::string &rule) const {
  std::regex regex(R"(#R B\d{1,10}\/S\d{1,10}\s{0,})",
                   std::regex_constants::ECMAScript);
  return std::regex_match(rule, regex);
}
void InputFileParser::evaluateBornSurviveRules(bool res,
                                               std::ifstream &in) const {
  if (!res || in.eof()) {
    throw WrongFileFormatException("Wrong born/survive rules line");
  }
}
bool InputFileParser::checkUniverseName(const std::string &rule) const {
  std::regex regex(R"(#N .+\s{0,})", std::regex_constants::ECMAScript);
  return std::regex_match(rule, regex);
}
void InputFileParser::evaluateUniverseName(bool res, std::ifstream &in) const {
  if (!res || in.eof()) {
    throw WrongFileFormatException("Wrong universe name line");
  }
}
bool InputFileParser::checkPair(const std::string &line) const {
  std::regex regex(R"(\d+\s\d+\s{0,})", std::regex_constants::ECMAScript);
  return std::regex_match(line, regex);
}
void InputFileParser::evaluatePair(bool res, std::ifstream &in) const {
  if (!res) {
    in.close();
    throw WrongFileFormatException("Wrong coordinates");
  }
}
std::string InputFileParser::parseName(const std::string &line) const {
  return line.substr(3);
}

InputFileParser::InputFileParser() : _filename(_DEFAULT_INPUT_NAME) {}
const std::string &InputFileParser::getFilename() const { return _filename; }
void InputFileParser::setFilename(const std::string &filename) {
  _filename = filename;
}
