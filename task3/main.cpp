//
// Created by Maxim on 24.12.2022.
//
#include "CommandLineParser.hpp"
#include "ConfigParser.hpp"
#include "IncludeLibs.hpp"
#include "Interface/Service.hpp"
#include "ServiceFactory.hpp"
#include "WAVFileProcessor.hpp"
#include "init_converters.hpp"

int main(int argc, char **argv) {
  CommandLineParser parser;
  try {
    parser.parse(argc, argv);
  } catch (const po::error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return static_cast<int>(AppState::CommandLineParserError);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return static_cast<int>(AppState::Help);
  }

  const auto &inputs = parser.getInput();
  const auto &output = parser.getOutput();
  const auto &config = parser.getConfig();
  const std::string inputPath = "../Assets/Input/";
  const std::string outputPath = "../Assets/Output/";
  const std::string configPath = "../Assets/Config/";

  try {
    WAVFileProcessor *pr =
        new WAVFileProcessor(inputs[0], output, inputPath, outputPath);
    pr->duplicateInput();
    delete pr;
    pr = new WAVFileProcessor(output, outputPath);
    ConfigParser configParser(config, configPath);

    for (const auto &cfg : configParser) {
      Service *pService =
          ServiceFactory::getInstance().orderService(cfg.getName());
      Converter *pConverter = Factory::orderConverter(cfg.getName());
      pService->initialize(pConverter, &cfg, &inputs, pr);
      pService->execute();
    }
  } catch (const ConfigParserException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return static_cast<int>(e.getState());
  } catch (const WAVParserReadException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return static_cast<int>(e.getState());
  } catch (const WAVProcessorWriteException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return static_cast<int>(e.getState());
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << "Wrong input reference" << std::endl;
    return static_cast<int>(AppState::Fail);
  } catch (const ServiceException& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return static_cast<int>(e.getState());
  }

  return static_cast<int>(AppState::Ok);
}