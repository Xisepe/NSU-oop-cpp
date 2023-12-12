//
// Created by maxim on 15.10.2022.
//
#include "CellField.h"
#include "GameSettings.hpp"
#include <iostream>
#include <stdexcept>

void CellField::changeCellStateAtPosition(size_t x, size_t y, bool state) {
  try {
    CellField::_field.at(y).at(x).setAlive(state);
  } catch (const std::out_of_range &e) {
    std::cerr << "Out of range error: " << e.what() << std::endl;
  }
}

const Cell &CellField::getCellAtPosition(size_t x, size_t y) const {
  return _field.at(y).at(x);
}

size_t CellField::rows() const { return _field.size(); }
size_t CellField::columns() const { return _field.at(0).size(); }

CellField::CellField(const CellField &cellField) noexcept {
  _field = cellField._field;
}

CellField &CellField::operator=(const CellField &cellField) {
  if (this != &cellField) {
    _field = cellField._field;
  }
  return *this;
}
