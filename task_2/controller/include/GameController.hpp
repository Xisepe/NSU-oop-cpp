//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_GAMECONTROLLER_HPP
#define TASK_2_GAMECONTROLLER_HPP

#include "CellField.h"
#include "CommandLineArguments.hpp"
#include "GameSettings.hpp"
#include "GameView.hpp"
#include "LogicController.hpp"
#include <memory>

class GameController {
private:
  constexpr static auto COMMANDS_INFO =
      "****************************************COMMANDS************************"
      "****************\n"
      "* help : print list of commands with explanation                        "
      "               *\n"
      "* tick <n=1> : calculate (default 1) n iterations of Game and print it "
      "on the screen.  *\n"
      "* On the screen will be printed:                                        "
      "               *\n"
      "*                             -rules                                    "
      "               *\n"
      "*                             -name of universe                         "
      "               *\n"
      "*                             -current iteration                        "
      "               *\n"
      "* dump <filename> : save game in file                                   "
      "               *\n"
      "* exit : stop the game                                                  "
      "               *\n"
      "************************************************************************"
      "****************\n";

private:
  const GameSettings *_ptr_settings;
  const GameView *_ptr_view;
  std::shared_ptr<CellField> _ptr_fieldMain;
  std::shared_ptr<CellField> _ptr_fieldBack;
  std::unique_ptr<LogicController> _ptr_logicController;
  void calculateNewCellField();
public:
  GameController(const GameSettings *ptrSettings, const GameView *ptrView);
  void calculateIterations(int iterations = 1);
  void display() const;
  void showCommandsInfo() const;
  void saveInFile(const std::string &filename) const;
};

#endif // TASK_2_GAMECONTROLLER_HPP
