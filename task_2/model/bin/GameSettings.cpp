//
// Created by maxim on 15.10.2022.
//

#include "GameSettings.hpp"
#include <iostream>
#include <set>
#include <utility>

const std::vector<std::pair<int, int>> &GameSettings::getStartCells() const {
  return _startCells;
}

const std::string &GameSettings::getUniverseName() const {
  return _universeName;
}

std::ostream &operator<<(std::ostream &os, const GameSettings &settings) {
  os << "Cells to born: ";
  for (const auto &item : settings._cellsNumberToBorn) {
    os << item << " ";
  }
  os << "\nCells to stay alive: ";
  for (const auto &item : settings._cellsNumberToStayAlive) {
    os << item << " ";
  }
  os << "\nUniverse name: " << settings._universeName;
  os << "\nField size: " << "x: "<<settings._columnSize << " y: " << settings._rowSize;
  os << std::endl;
  return os;
}
void GameSettings::addCellNumberToBorn(int number) {
  _cellsNumberToBorn.insert(number);
}
void GameSettings::addCellNumberToStayAlive(int number) {
  _cellsNumberToStayAlive.insert(number);
}
void GameSettings::addPairOfStartCells(int x, int y) {
  _startCells.emplace_back(x, y);
}
void GameSettings::setUniverseName(std::string name) {
  _universeName = std::move(name);
}
GameSettings::GameSettings(size_t columns, size_t rows)
    : _columnSize(columns), _rowSize(rows), _universeName("default"),
      _startCells() {
}
size_t GameSettings::getRowSize() const { return _rowSize+1; }
void GameSettings::setRowSize(size_t rowSize) { _rowSize = rowSize; }
size_t GameSettings::getColumnSize() const { return _columnSize+1; }
void GameSettings::setColumnSize(size_t columnSize) {
  _columnSize = columnSize;
}
GameSettings::GameSettings(): _columnSize(128), _rowSize(32) {}
const std::set<int> &GameSettings::getCellsNumberToBorn() const {
  return _cellsNumberToBorn;
}
const std::set<int> &GameSettings::getCellsNumberToStayAlive() const {
  return _cellsNumberToStayAlive;
}
