//
// Created by maxim on 02.10.2022.
//

#include "CellField.h"
#include "CommandLineArgumentParser.hpp"
#include "ConsoleGameView.hpp"
#include "FileException.hpp"
#include "FileGameView.hpp"
#include "GameController.hpp"
#include "InputFileParser.hpp"
#include <memory>
#include <regex>
#include <thread>

/**
 * It is an entry point of game.
 * Game can be started with online and offline mode.
 *
 * Input parameter arguments:
 *
 * -m <number> --mode=<number> (0 for online mode, 1 for offline)
 * -i <number> or --iterations=<number>
 * -f <input> or --filename=<input>
 * -o <output> or --output=<output>
 *
 * ATTENTION
 * All input files have to be placed in ASSETS directory, otherwise error occurs
 * All outputs can be found in ASSETS directory
 * default output is default_output.txt
 * default input is default_input.txt
 *
 * If no arguments passed or no explicit flags of mode in input parameters, game
 * will be started in online mode.
 * If no iterations passed, will be set 1 by default
 * If no input file passed, will be used default_input.txt
 * If no output file passed, will be written in default_output.txt
 *
 * If game is in online mode to control it use available commands. To get more
 * info about commands type help in game. All iterations are displayed in real
 * time.
 *
 * @param argc
 * @param argv
 * @return
 */

void waitCommands(GameController& controller) {
  std::string line;
  while (true) {
    std::getline(std::cin, line);
    if (line == "help") {
      controller.showCommandsInfo();
    } else if (line.find("dump") == 0) {
      try {
        controller.saveInFile(line.substr(5));
      } catch (const std::out_of_range &e) {
        std::cerr << "No path. Try command help." << std::endl;
      }
    } else if (std::regex_match(line,
                                std::regex(R"(tick\s{0,}\d{0,})",
                                           std::regex_constants::ECMAScript))) {
      std::regex regex(R"(tick \d{1,})", std::regex_constants::ECMAScript);
      int iter = 1;
      if (std::regex_match(line, regex)) {
        iter = std::stoi(line.substr(5));
      }
      for (int i = 0; i < iter; ++i) {
        system("clear");
        controller.calculateIterations();
        controller.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
      }
    } else if (line == "exit") {
      std::cout << "Exiting game..." << std::endl;
      break;
    } else {
      std::cerr << "No such command. Try command help." << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
  CommandLineArgumentParser commandLineArgumentParser(argc, argv);
  auto commandLineArguments = commandLineArgumentParser.parse();
  InputFileParser inputParser(commandLineArguments.getInputFilepath());
  GameSettings settings;
  try {
    settings = inputParser.parse();
  } catch (const FileException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  /// here possibly increase size of field in settings
  /// settings.setColumnSize(256);
  /// settings.setRowSize(256);
  GameView *view;
  GameController *controller;
  // online
  if (commandLineArguments.getMode() == 0) {
    view = new ConsoleGameView("X", ".");
    controller = new GameController(&settings, view);
    waitCommands(*controller);
  } else {
    // offline
    view = new FileGameView("X", ".", commandLineArguments.getOutputFilepath());
    controller = new GameController(&settings, view);
    controller->calculateIterations(commandLineArguments.getIterations());
    controller->display();
  }
  delete view;
  delete controller;
}
