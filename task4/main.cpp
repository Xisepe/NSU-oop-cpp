//
// Created by Maxim on 24.12.2022.
//

#include "CSVParser.hpp"
#include "CommandLineParser.hpp"
#include "PrintTuple.hpp"

int main(int argc, char **argv) {
  std::string path = "../Data/";
  try {
    CommandLineParser commandLineParser(argc, argv);
    std::ifstream in(path + commandLineParser.getFilename());
    CSVParser<std::string, int, double> parser(
        &in, commandLineParser.getSkip(), commandLineParser.getRowDelimiter(),
        commandLineParser.getColumnDelimiter(), commandLineParser.getShield());
    for (const auto &t : parser) {
      std::cout << t << "\n";
    }
  } catch (const CSVParserException &e) {
    std::cerr << e.what();
    return static_cast<int>(e.getState());
  } catch (const std::invalid_argument &e) {
    if (std::string(e.what()) == "--help") {
      return static_cast<int>(AppState::Help);
    } else {
      std::cerr << e.what();
      return static_cast<int>(AppState::Fail);
    }
  }

  return 0;
}
