//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_GAMESETTINGS_HPP
#define TASK_2_GAMESETTINGS_HPP

#include <ostream>
#include <set>
#include <string>
#include <vector>

class GameSettings {
private:
  std::set<int> _cellsNumberToBorn;
  std::set<int> _cellsNumberToStayAlive;
  std::vector<std::pair<int, int>> _startCells;
  size_t _rowSize;
  size_t _columnSize;
  std::string _universeName;

public:
  GameSettings();
  GameSettings(size_t columns, size_t rows);
  size_t getRowSize() const;
  void setRowSize(size_t rowSize);
  size_t getColumnSize() const;
  void setColumnSize(size_t columnSize);

  void addCellNumberToBorn(int);

  void addCellNumberToStayAlive(int);

  void addPairOfStartCells(int, int);

  void setUniverseName(std::string);

  const std::set<int> &getCellsNumberToBorn() const;
  const std::set<int> &getCellsNumberToStayAlive() const;

  const std::vector<std::pair<int, int>> &getStartCells() const;

  const std::string &getUniverseName() const;

  friend std::ostream &operator<<(std::ostream &os,
                                  const GameSettings &settings);
};

#endif // TASK_2_GAMESETTINGS_HPP
