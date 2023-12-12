//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_CELLFIELD_H
#define TASK_2_CELLFIELD_H

#include "Cell.hpp"
#include "GameSettings.hpp"
#include <iostream>
#include <vector>

class CellField {
private:
  std::vector<std::vector<Cell>> _field;
  CellField(std::vector<std::vector<Cell>> &field) noexcept : _field(field){};

public:
  class Builder {
  private:
    size_t _rows;
    size_t _columns;
    std::vector<std::pair<int, int>> _startCells;

  public:
    Builder() : _rows(128), _columns(32){};
    Builder& withRows(size_t rows) {
      _rows = rows;
      return *this;
    }
    Builder& withColumns(size_t columns) {
      _columns = columns;
      return *this;
    }
    Builder& withStartCells(const std::vector<std::pair<int, int>> &startCells) {
      _startCells = startCells;
      return *this;
    }
    CellField build() {
      std::vector<std::vector<Cell>> field(_rows,
                                           std::vector<Cell>(_columns, false));
      for (const auto &[x, y] : _startCells) {
        if (y < _rows && x < _columns) {
          field[y][x].setAlive(true);
        } else {
          std::cerr << "x: " << x << " y: " << y << " out of predefined size: "
                    << "x: " << _columns << " y: " << _rows << std::endl;
        }
      }
      return {field};
    }
  };
  CellField(const CellField &cellField) noexcept;
  const Cell &getCellAtPosition(size_t x, size_t y) const;
  size_t rows() const;
  size_t columns() const;
  void changeCellStateAtPosition(size_t x, size_t y, bool state);
  CellField &operator=(const CellField &cellField);
};

#endif // TASK_2_CELLFIELD_H
