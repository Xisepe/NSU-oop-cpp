//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_LOGICCONTROLLER_HPP
#define TASK_2_LOGICCONTROLLER_HPP

#include "CellField.h"
#include "GameSettings.hpp"
#include <memory>

class LogicController {
private:
  static const std::vector<std::pair<int, int>> _direction;
  std::set<int> _cellsNumberToBorn;
  std::set<int> _cellsNumberToStayAlive;

  bool checkCellNumberToStayAlive(int) const;

  bool checkCellNumberToBorn(int) const;
public:

  int countAliveNeighbors(const CellField &ptrField, size_t x, size_t y) const;
  bool calculateNewCellState(int neighbours, bool isAlive) const;
  LogicController(const std::set<int> &toBorn,
                  const std::set<int> &toStayAlive);
};

#endif // TASK_2_LOGICCONTROLLER_HPP
