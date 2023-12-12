//
// Created by maxim on 15.10.2022.
//

#include "LogicController.hpp"

#include "CellField.h"
#include <utility>

const std::vector<std::pair<int, int>> LogicController::_direction = [] {
  std::vector<std::pair<int, int>> vector;
  vector.emplace_back(-1, -1);
  vector.emplace_back(0, -1);
  vector.emplace_back(1, -1);
  vector.emplace_back(-1, 0);
  vector.emplace_back(1, 0);
  vector.emplace_back(-1, 1);
  vector.emplace_back(0, 1);
  vector.emplace_back(1, 1);
  return vector;
}();

int LogicController::countAliveNeighbors(const CellField &ptrField, size_t x,
                                         size_t y) const {
  int res = 0;
  size_t columns = ptrField.columns();
  size_t rows = ptrField.rows();
  x += columns;
  y += rows;
  for (const auto &item : _direction) {
    if (ptrField
            .getCellAtPosition((x + item.first) % columns,
                               (y + item.second) % rows)
            .isAlive()) {
      res++;
    }
  }
  return res;
}

bool LogicController::calculateNewCellState(int neighbours,
                                            bool isAlive) const {
  return isAlive ? checkCellNumberToStayAlive(neighbours)
                 : checkCellNumberToBorn(neighbours);
}

bool LogicController::checkCellNumberToBorn(int val) const {
  return _cellsNumberToBorn.find(val) != _cellsNumberToBorn.end();
}

bool LogicController::checkCellNumberToStayAlive(int val) const {
  return _cellsNumberToStayAlive.find(val) != _cellsNumberToStayAlive.end();
}
LogicController::LogicController(const std::set<int> &toBorn,
                                 const std::set<int> &toStayAlive)
    : _cellsNumberToStayAlive(toStayAlive), _cellsNumberToBorn(toBorn) {}
