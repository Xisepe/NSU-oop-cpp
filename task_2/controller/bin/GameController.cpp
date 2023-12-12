//
// Created by maxim on 15.10.2022.
//

#include "GameController.hpp"
#include <iostream>
#include <regex>
#include <thread>

void GameController::display() const {
  _ptr_view->display(*_ptr_fieldMain, *_ptr_settings);
}

void GameController::calculateNewCellField() {
  size_t rows = _ptr_fieldMain->rows();
  size_t columns = _ptr_fieldBack->columns();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      int aliveNeighbors =
          _ptr_logicController->countAliveNeighbors(*_ptr_fieldMain, j, i);
      _ptr_fieldBack->changeCellStateAtPosition(
          j, i,
          _ptr_logicController->calculateNewCellState(
              aliveNeighbors,
              _ptr_fieldMain->getCellAtPosition(j, i).isAlive()));
    }
  }
  _ptr_fieldMain.swap(_ptr_fieldBack);
}

void GameController::showCommandsInfo() const {
  std::cout << GameController::COMMANDS_INFO << std::endl;
}

void GameController::saveInFile(const std::string &filename) const {
  _ptr_view->save(filename, *_ptr_fieldMain, *_ptr_settings);
}

GameController::GameController(const GameSettings *ptrSettings,
                               const GameView *ptrView)
    : _ptr_settings(ptrSettings), _ptr_view(ptrView) {
  _ptr_fieldMain = std::make_shared<CellField>(
      CellField::Builder()
          .withRows(ptrSettings->getRowSize())
          .withColumns(ptrSettings->getColumnSize())
          .withStartCells(ptrSettings->getStartCells())
          .build());
  _ptr_fieldBack = std::make_shared<CellField>(*_ptr_fieldMain);
  _ptr_logicController = std::make_unique<LogicController>(
      ptrSettings->getCellsNumberToBorn(),
      ptrSettings->getCellsNumberToStayAlive());
}
void GameController::calculateIterations(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    calculateNewCellField();
  }
}
